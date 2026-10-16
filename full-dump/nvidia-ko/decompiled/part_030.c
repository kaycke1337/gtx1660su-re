// ===== 002fd3c0 dceclientStateDestroy_IMPL =====

void dceclientStateDestroy_IMPL(void)

{
  nvDbg_Printf("src/kernel/gpu/dce_client/dce_client.c",0x74,"dceclientStateDestroy_IMPL",1,
               "NVRM: Destroy DCE Client State Called\n");
  return;
}


// ===== 002fd3f0 dceclientDeinitRpcInfra_IMPL =====

void dceclientDeinitRpcInfra_IMPL(long param_1)

{
  nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0xa4,"dceclientDeinitRpcInfra_IMPL",1,
               "NVRM: Free RPC Infra Called\n");
  osTegraDceUnregisterIpcClient(*(undefined4 *)(param_1 + 0x170));
  osTegraDceUnregisterIpcClient(*(undefined4 *)(param_1 + 0x174));
  if (*(long *)(param_1 + 0x168) != 0) {
    portMemFree(*(undefined8 *)(*(long *)(param_1 + 0x168) + 0x4d8));
    portMemFree(*(undefined8 *)(param_1 + 0x168));
    *(undefined8 *)(param_1 + 0x168) = 0;
  }
  return;
}


// ===== 002fd480 dceclientInitRpcInfra_IMPL =====

int dceclientInitRpcInfra_IMPL(undefined8 param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  
  nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x46,"dceclientInitRpcInfra_IMPL",1,
               "NVRM: Init RPC Infra Called\n");
  lVar2 = initRpcObject(param_1);
  *(long *)(param_2 + 0x168) = lVar2;
  if (lVar2 == 0) {
    nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x4b,"dceclientInitRpcInfra_IMPL",4,
                 "NVRM: initRpcObject failed\n");
    return 0x1a;
  }
  *(undefined4 *)(lVar2 + 0x4f0) = 0x1000;
  lVar2 = *(long *)(param_2 + 0x168);
  uVar3 = portMemAllocNonPaged(0x1000);
  *(undefined8 *)(lVar2 + 0x4d8) = uVar3;
  if (*(long *)(*(long *)(param_2 + 0x168) + 0x4d8) != 0) {
    *(undefined4 *)(param_2 + 0x170) = 0;
    iVar1 = osTegraDceRegisterIpcClient(0,0,param_2 + 0x170);
    if (iVar1 == 0) {
      nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",100,"dceclientInitRpcInfra_IMPL",1,
                   "NVRM: Registered dce ipc client DCE_CLIENT_RM_IPC_TYPE_SYNC handle: 0x%x\n",
                   *(undefined4 *)(param_2 + 0x170));
      *(undefined4 *)(param_2 + 0x174) = 0;
      iVar1 = osTegraDceRegisterIpcClient(1,param_1,param_2 + 0x174);
      if (iVar1 == 0) {
        nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x72,"dceclientInitRpcInfra_IMPL",
                     1,"NVRM: Register dce ipc client DCE_CLIENT_RM_IPC_TYPE_EVENT: 0x%x\n",
                     *(undefined4 *)(param_2 + 0x174));
        return 0;
      }
      nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x6e,"dceclientInitRpcInfra_IMPL",4,
                   "NVRM: Register dce ipc client failed for DCE_CLIENT_RM_IPC_TYPE_EVENT error 0x%x\n"
                   ,iVar1);
    }
    else {
      nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x5f,"dceclientInitRpcInfra_IMPL",4,
                   "NVRM: Register dce ipc client failed for DCE_CLIENT_RM_IPC_TYPE_SYNC error 0x%x\n"
                   ,iVar1);
    }
    dceclientDeinitRpcInfra_IMPL(param_2);
    return iVar1;
  }
  nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x54,"dceclientInitRpcInfra_IMPL",4,
               "NVRM: Cannot allocate memory for message_buffer\n");
  return 0;
}


// ===== 002fd6b0 dceclientSendRpc_IMPL =====

ulong dceclientSendRpc_IMPL(long param_1,long param_2,undefined4 param_3)

{
  undefined4 uVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar1 = *(undefined4 *)(param_1 + 0x170);
  nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0xbe,"dceclientSendRpc_IMPL",1,
               "NVRM: Send RPC Called, clientid used 0x%x\n",uVar1);
  uVar3 = 0;
  if (param_2 != 0) {
    uVar2 = osTegraDceClientIpcSendRecv(uVar1,param_2,param_3);
    uVar3 = uVar2 & 0xffffffff;
    if ((int)uVar2 != 0) {
      nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0xc5,"dceclientSendRpc_IMPL",4,
                   "NVRM: Send RPC failed for clientId %u error %u\n",uVar1,uVar2);
      return uVar2 & 0xffffffff;
    }
  }
  return uVar3;
}


// ===== 002fd770 _dceRpcIssueAndWait.isra.0 =====

int _dceRpcIssueAndWait_isra_0(long param_1)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  
  lVar4 = gpuGetRpc();
  iVar5 = 0x1f;
  puVar1 = *(undefined4 **)(lVar4 + 0x4d8);
  if (puVar1 != (undefined4 *)0x0) {
    uVar2 = *(undefined8 *)(param_1 + 0x1bb0);
    nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0xfe,"_dceclientrmPrintHdr",1,
                 "NVRM: NVRM_RPC_DCE : [msg-buf:0x%p] header_version = 0x%x signature = 0x%x length = 0x%x function = 0x%x rpc_result = 0x%x\n"
                 ,puVar1,*puVar1,puVar1[1],puVar1[2],puVar1[3],puVar1[4]);
    iVar3 = dceclientSendRpc_IMPL(uVar2,puVar1,puVar1[2]);
    iVar5 = 0;
    if (iVar3 != 0) {
      nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x11d,"_dceRpcIssueAndWait",4,
                   "NVRM: NVRM_RPC_DCE: Error while issuing RPC [0x%x]\n");
      return iVar3;
    }
  }
  return iVar5;
}


// ===== 002fd850 dceclientHandleAsyncRpcCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void dceclientHandleAsyncRpcCallback
               (undefined8 param_1,int param_2,undefined8 param_3,long param_4,long param_5)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  char *pcVar5;
  long local_30 [2];
  
  nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x12f,"dceclientHandleAsyncRpcCallback",
               1,"NVRM: dceclientHandleAsyncRpcCallback called\n");
  uVar3 = 0x135;
  pcVar5 = "interfaceType == DCE_CLIENT_RM_IPC_TYPE_EVENT";
  if (param_2 == 1) {
    if ((param_5 != 0) && (param_4 != 0)) {
      iVar2 = *(int *)(param_4 + 0xc);
      if (iVar2 == 0x1007) {
        uVar3 = 0x16c;
        if (*(long *)(param_5 + 0x1b80) != 0) {
          kdispInvokeRgLineCallback_KERNEL
                    (*(long *)(param_5 + 0x1b80),*(undefined4 *)(param_4 + 0x20),
                     *(undefined4 *)(param_4 + 0x24),0);
          return;
        }
      }
      else {
        if (iVar2 != 0x1011) {
          if (iVar2 == 0x1003) {
            if (*(char *)(param_4 + 0x3c) != '\0') {
              gpuNotifySubDeviceEvent_IMPL
                        (param_5,*(undefined4 *)(param_4 + 0x28),param_4 + 0x3d,
                         *(undefined4 *)(param_4 + 0x38),0,0);
              return;
            }
            local_30[0] = 0;
            cVar1 = CliGetEventInfo(*(undefined4 *)(param_4 + 0x20),*(undefined4 *)(param_4 + 0x24),
                                    local_30);
            if (cVar1 == '\0') {
              nvAssertFailedNoLog("CliGetEventInfo(rpc_params->hClient, rpc_params->hEvent, &pEvent)"
                                  ,"src/kernel/gpu/dce_client/dce_client_rpc.c",0x14f);
            }
            else if ((*(long *)(local_30[0] + 0xd8) == 0) ||
                    (lVar4 = *(long *)(*(long *)(local_30[0] + 0xd8) + 0xa8), lVar4 == 0)) {
              nvAssertFailedNoLog("pNotifyList != NULL","src/kernel/gpu/dce_client/dce_client_rpc.c"
                                  ,0x155);
            }
            else {
              do {
                if (*(int *)(lVar4 + 4) == *(int *)(param_4 + 0x24)) {
                  iVar2 = osNotifyEvent(param_5,lVar4,0,*(undefined4 *)(param_4 + 0x2c),
                                        *(undefined4 *)(param_4 + 0x34));
                  if (iVar2 == 0) {
                    return;
                  }
                  nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x15f,
                               "dceclientHandleAsyncRpcCallback",4,
                               "NVRM: osNotifyEvent failed with status: %x\n",iVar2);
                  return;
                }
                lVar4 = *(long *)(lVar4 + 0x40);
              } while (lVar4 != 0);
              nvAssertFailedNoLog("pNotifyEvent != NULL",
                                  "src/kernel/gpu/dce_client/dce_client_rpc.c",0x163);
            }
            return;
          }
          nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x180,
                       "dceclientHandleAsyncRpcCallback",4,"NVRM: Unexpected RPC function 0x%x\n");
          uVar3 = 0x181;
          pcVar5 = "Unexpected RPC function";
          goto LAB_002fd9e9;
        }
        lVar4 = *(long *)(param_5 + 0x1b80);
        if (lVar4 != 0) {
          (**(code **)(lVar4 + 0x1d0))
                    (lVar4,*(undefined1 *)(param_4 + 0x20),*(undefined4 *)(param_4 + 0x24),
                     *(undefined4 *)(param_4 + 0x28));
          return;
        }
        uVar3 = 0x176;
      }
      nvCheckFailedNoLog(4,"pKernelDisplay != NULL","src/kernel/gpu/dce_client/dce_client_rpc.c",
                         uVar3);
      return;
    }
    uVar3 = 0x136;
    pcVar5 = "pGpu != NULL && data != NULL";
  }
LAB_002fd9e9:
  nvAssertFailedNoLog(pcVar5,"src/kernel/gpu/dce_client/dce_client_rpc.c",uVar3);
  return;
}


// ===== 002fdb30 rpcRmApiControl_dce =====

int rpcRmApiControl_dce(long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined8 param_5,int param_6)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  int iVar7;
  
  lVar1 = *(long *)(param_1 + 0xe0);
  lVar4 = gpuGetRpc(lVar1);
  nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x198,"rpcRmApiControl_dce",1,
               "NVRM: NVRM_RPC_DCE : Prepare and send RmApiControl RPC [cmd:0x%x]\n",param_4);
  if (lVar1 == 0) {
    iVar3 = 0x40;
    nvAssertFailedNoLog("pGpu != NULL","src/kernel/gpu/dce_client/dce_client_rpc.c",0x19a);
  }
  else {
    lVar2 = *(long *)(lVar4 + 0x4d8);
    iVar3 = rpcWriteCommonHeader(lVar1,lVar4,0x4c,param_6 + 0x28);
    if (iVar3 == 0) {
      *(undefined4 *)(lVar2 + 0x28) = param_4;
      *(int *)(lVar2 + 0x30) = param_6;
      *(undefined4 *)(lVar2 + 0x20) = param_2;
      *(undefined4 *)(lVar2 + 0x24) = param_3;
      portMemCopy(lVar2 + 0x48,param_6,param_5,param_6);
      iVar3 = _dceRpcIssueAndWait_isra_0(*(undefined8 *)(param_1 + 0xe0));
      if (iVar3 == 0) {
        iVar3 = *(int *)(*(long *)(lVar4 + 0x4d8) + 0x10);
        if (iVar3 == 0) {
          nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x1be,"rpcRmApiControl_dce",1,
                       "NVRM: NVRM_RPC_DCE: RPC for GSP RM Control Successful\n");
        }
        else {
          if (iVar3 == 0x56) {
            uVar5 = nvstatusToString(0x56);
            uVar6 = 1;
            iVar7 = 0x56;
          }
          else {
            uVar5 = nvstatusToString(iVar3);
            uVar6 = 4;
            iVar7 = iVar3;
          }
          nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x1b8,"rpcRmApiControl_dce",
                       uVar6,"NVRM: NVRM_RPC_DCE: Failed RM ctrl call cmd:0x%x result 0x%x: %s\n",
                       param_4,iVar7,uVar5);
        }
        portMemCopy(param_5,param_6,lVar2 + 0x48,param_6);
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x1a5,"rpcRmApiControl_dce",4,
                   "NVRM: NVRM_RPC_DCE: Writing RPC Header Failed [0x%x]\n",iVar3);
    }
  }
  return iVar3;
}


// ===== 002fdd40 rpcRmApiAlloc_dce =====

int rpcRmApiAlloc_dce(long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5,long param_6)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  char local_3d;
  int local_3c [3];
  
  lVar1 = *(long *)(param_1 + 0xe0);
  lVar4 = gpuGetRpc(lVar1);
  nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x1db,"rpcRmApiAlloc_dce",1,
               "NVRM: NVRM_RPC_DCE: Prepare and send RmApiAlloc RPC\n");
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pGpu != NULL","src/kernel/gpu/dce_client/dce_client_rpc.c",0x1dd);
    return 0x40;
  }
  lVar2 = *(long *)(lVar4 + 0x4d8);
  iVar3 = rmapiGetClassAllocParamSize(local_3c,param_6,&local_3d,param_5);
  if (iVar3 != 0) {
    nvAssertOkFailedNoLog
              (iVar3,"rmapiGetClassAllocParamSize(&paramsSize, pAllocParams, &bNullAllowed, hClass)"
               ,"src/kernel/gpu/dce_client/dce_client_rpc.c",0x1e2);
    return iVar3;
  }
  if (param_6 == 0) {
    if (local_3d == '\0') {
      nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x1e8,"rpcRmApiAlloc_dce",4,
                   "NVRM: NVRM_RPC_DCE: NULL allocation params not allowed for class 0x%x\n",param_5
                  );
      return 0x1f;
    }
    iVar3 = rpcWriteCommonHeader(lVar1,lVar4,0x67,local_3c[0] + 0x20);
    if (iVar3 != 0) goto LAB_002fdf10;
    *(undefined4 *)(lVar2 + 0x20) = param_2;
    *(undefined4 *)(lVar2 + 0x24) = param_3;
    *(undefined4 *)(lVar2 + 0x28) = param_4;
    *(undefined4 *)(lVar2 + 0x2c) = param_5;
    iVar3 = 0;
  }
  else {
    iVar3 = rpcWriteCommonHeader(lVar1,lVar4,0x67,local_3c[0] + 0x20);
    if (iVar3 != 0) {
LAB_002fdf10:
      nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",499,"rpcRmApiAlloc_dce",4,
                   "NVRM: NVRM_RPC_DCE: Writing RPC Header Failed [0x%x]\n",iVar3);
      return iVar3;
    }
    *(undefined4 *)(lVar2 + 0x20) = param_2;
    *(undefined4 *)(lVar2 + 0x24) = param_3;
    *(undefined4 *)(lVar2 + 0x28) = param_4;
    *(undefined4 *)(lVar2 + 0x2c) = param_5;
    iVar3 = local_3c[0];
  }
  *(int *)(lVar2 + 0x34) = iVar3;
  portMemCopy(lVar2 + 0x40,iVar3,param_6,local_3c[0]);
  iVar3 = _dceRpcIssueAndWait_isra_0(*(undefined8 *)(param_1 + 0xe0));
  if (iVar3 == 0) {
    iVar3 = *(int *)(*(long *)(lVar4 + 0x4d8) + 0x10);
    if (iVar3 != 0) {
      uVar5 = nvstatusToString(iVar3);
      nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x207,"rpcRmApiAlloc_dce",4,
                   "NVRM: NVRM_RPC_DCE: Failed RM Alloc Object 0x%x result 0x%x: %s\n",param_5,iVar3
                   ,uVar5);
    }
    if (local_3c[0] != 0) {
      portMemCopy(param_6,local_3c[0],lVar2 + 0x40,*(undefined4 *)(lVar2 + 0x34));
    }
    nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x212,"rpcRmApiAlloc_dce",1,
                 "NVRM: NVRM_RPC_DCE: RPC for GSP RM Alloc Successful\n");
  }
  return iVar3;
}


// ===== 002fe030 rpcRmApiFree_dce =====

int rpcRmApiFree_dce(long param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  
  lVar1 = *(long *)(param_1 + 0xe0);
  lVar4 = gpuGetRpc(lVar1);
  nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x221,"rpcRmApiFree_dce",1,
               "NVRM: NVRM_RPC_DCE Free RPC Called for hClient: 0x%x\n",param_2);
  if (lVar1 == 0) {
    iVar3 = 0x40;
    nvAssertFailedNoLog("pGpu != NULL","src/kernel/gpu/dce_client/dce_client_rpc.c",0x224);
  }
  else {
    lVar2 = *(long *)(lVar4 + 0x4d8);
    iVar3 = rpcWriteCommonHeader(lVar1,lVar4,10,0x10);
    if (iVar3 == 0) {
      *(undefined4 *)(lVar2 + 0x20) = param_2;
      *(undefined4 *)(lVar2 + 0x24) = 0;
      *(undefined4 *)(lVar2 + 0x28) = param_3;
      iVar3 = _dceRpcIssueAndWait_isra_0(*(undefined8 *)(param_1 + 0xe0));
      if (iVar3 == 0) {
        iVar3 = *(int *)(*(long *)(lVar4 + 0x4d8) + 0x10);
        if (iVar3 != 0) {
          nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x23f,"rpcRmApiFree_dce",4,
                       "NVRM: NVRM_RPC_DCE: Failed RM Free Object result 0x%x:\n",iVar3);
        }
        nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x242,"rpcRmApiFree_dce",1,
                     "NVRM: NVRM_RPC_DCE: RPC for Free Successful\n");
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x22e,"rpcRmApiFree_dce",4,
                   "NVRM: NVRM_RPC_DCE: Writing RPC Header Failed [0x%x]\n",iVar3);
    }
  }
  return iVar3;
}


// ===== 002fe1e0 rpcRmApiDupObject_dce =====

int rpcRmApiDupObject_dce
              (long param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
              undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  
  lVar1 = *(long *)(param_1 + 0xe0);
  lVar4 = gpuGetRpc(lVar1);
  nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x25a,"rpcRmApiDupObject_dce",1,
               "NVRM: NVRM_RPC_DCE Dup Object RPC Called for hClient: 0x%x\n",param_2);
  if (lVar1 == 0) {
    iVar3 = 0x40;
    nvAssertFailedNoLog("pGpu != NULL","src/kernel/gpu/dce_client/dce_client_rpc.c",0x25d);
  }
  else {
    lVar2 = *(long *)(lVar4 + 0x4d8);
    iVar3 = rpcWriteCommonHeader(lVar1,lVar4,0x15,0x1c);
    if (iVar3 == 0) {
      *(undefined4 *)(lVar2 + 0x20) = param_2;
      *(undefined4 *)(lVar2 + 0x24) = param_3;
      *(undefined4 *)(lVar2 + 0x28) = *param_4;
      *(undefined4 *)(lVar2 + 0x2c) = param_5;
      *(undefined4 *)(lVar2 + 0x30) = param_6;
      *(undefined4 *)(lVar2 + 0x34) = param_7;
      iVar3 = _dceRpcIssueAndWait_isra_0(*(undefined8 *)(param_1 + 0xe0));
      if (iVar3 == 0) {
        iVar3 = *(int *)(*(long *)(lVar4 + 0x4d8) + 0x10);
        if (iVar3 != 0) {
          nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x27b,"rpcRmApiDupObject_dce",4,
                       "NVRM: NVRM_RPC_DCE: Failed RM Dup Object result 0x%x:\n",iVar3);
        }
        nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x27e,"rpcRmApiDupObject_dce",1,
                     "NVRM: NVRM_RPC_DCE: RPC for DUP OBJECT Successful\n");
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x267,"rpcRmApiDupObject_dce",4,
                   "NVRM: NVRM_RPC_DCE: Writing RPC Header Failed [0x%x]\n",iVar3);
    }
  }
  return iVar3;
}


// ===== 002fe3b0 rpcDceRmInit_dce =====

int rpcDceRmInit_dce(long param_1,char param_2)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c [3];
  
  lVar6 = *(long *)(param_1 + 0xe0);
  lVar5 = gpuGetRpc(lVar6);
  local_44 = 0;
  lVar2 = *(long *)(lVar6 + 0x1bb0);
  local_40 = 0;
  local_3c[0] = 0;
  if (param_2 == '\0') {
    nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x296,"rpcDceRmInit_dce",1,
                 "NVRM: NVRM_RPC_DCE RPC to trigger %s called\n","RmShutdownAdapter");
    lVar7 = *(long *)(lVar5 + 0x4d8);
    iVar3 = rpcWriteCommonHeader(lVar6,lVar5,0xa8,0x14);
    if (iVar3 != 0) goto LAB_002fe570;
  }
  else {
    nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x296,"rpcDceRmInit_dce",1,
                 "NVRM: NVRM_RPC_DCE RPC to trigger %s called\n","RmInitAdapter");
    lVar7 = *(long *)(lVar5 + 0x4d8);
    iVar3 = rpcWriteCommonHeader(lVar6,lVar5,0xa8,0x14);
    if (iVar3 != 0) {
LAB_002fe570:
      nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x2a3,"rpcDceRmInit_dce",4,
                   "NVRM: NVRM_RPC_DCE: Writing RPC Header Failed [0x%x]\n",iVar3);
      return iVar3;
    }
    iVar3 = osTegraSocGetDispClockRates(*(undefined8 *)(lVar6 + 0x4e0),&local_44,&local_40,local_3c)
    ;
    if (iVar3 != 0) {
      nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x2ac,"rpcDceRmInit_dce",1,
                   "NVRM: NVRM_RPC_DCE: Retrieving disp clocks max rate Failed [0x%x]\n",iVar3);
    }
  }
  *(char *)(lVar7 + 0x20) = param_2;
  *(undefined4 *)(lVar7 + 0x28) = local_44;
  *(undefined4 *)(lVar7 + 0x2c) = local_40;
  *(undefined4 *)(lVar7 + 0x30) = local_3c[0];
  iVar3 = _dceRpcIssueAndWait_isra_0(*(undefined8 *)(param_1 + 0xe0));
  if (iVar3 == 0) {
    iVar3 = *(int *)(*(long *)(lVar5 + 0x4d8) + 0x10);
    if (iVar3 != 0) {
      nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x2be,"rpcDceRmInit_dce",4,
                   "NVRM: NVRM_RPC_DCE: Failed RM init/deinit result 0x%x:\n",iVar3);
    }
    *(undefined4 *)(lVar2 + 0x178) = *(undefined4 *)(lVar7 + 0x24);
    if (param_2 != '\0') {
      lVar6 = portMemAllocNonPaged(0x408);
      if (lVar6 == 0) {
        nvAssertOkFailedNoLog
                  (0x51,"pGbvParams != NULL","src/kernel/gpu/dce_client/dce_client_rpc.c",0x2c7);
        iVar3 = 0x51;
      }
      else {
        uVar1 = *(undefined4 *)(lVar2 + 0x178);
        iVar3 = rpcRmApiControl_dce(param_1,uVar1,uVar1,0x13e,lVar6,0x408);
        if (iVar3 == 0) {
          iVar4 = portStringCompare("595.71.05",lVar6,10);
          if (iVar4 != 0) {
            nvDbg_Printf("src/kernel/gpu/dce_client/dce_client_rpc.c",0x2d0,"rpcDceRmInit_dce",3,
                         "NVRM: Possibly incompatible DCE RM version! CPU RM: %s DCE RM: %s\n",
                         "595.71.05",lVar6);
          }
        }
        else {
          nvAssertOkFailedNoLog(iVar3,"status","src/kernel/gpu/dce_client/dce_client_rpc.c",0x2cb);
        }
        portMemFree(lVar6);
      }
    }
  }
  return iVar3;
}


// ===== 002fe700 dceclientDceRmInit_IMPL =====

ulong dceclientDceRmInit_IMPL(long param_1,undefined8 param_2,char param_3)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  int local_1c;
  
  local_1c = 0;
  if ((param_3 == '\0') ||
     (uVar1 = rmGpuGroupLockAcquire(*(undefined4 *)(param_1 + 0x7a4),0,0,0x400000,&local_1c),
     uVar1 == 0)) {
    lVar2 = gpuGetRpc(param_1);
    uVar3 = 0x1a;
    if (lVar2 != 0) {
      uVar3 = rpcDceRmInit_dce(param_1 + 0x3b58,param_3);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (uVar1,
               "rmGpuGroupLockAcquire(pGpu->gpuInstance, GPU_LOCK_GRP_SUBDEVICE, GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_INIT, &gpusLockedMask)"
               ,"src/kernel/gpu/dce_client/dce_client_rpc.c",0x8b);
    uVar3 = (ulong)uVar1;
  }
  if (local_1c != 0) {
    rmGpuGroupLockRelease(local_1c,0);
    return uVar3 & 0xffffffff;
  }
  return uVar3;
}


// ===== 002fe7c0 _Class5080DelDeferredApi =====

undefined4 _Class5080DelDeferredApi(long param_1,undefined4 param_2)

{
  long lVar1;
  int iVar2;
  long *local_30 [2];
  
  iVar2 = btreeSearch(param_2,local_30,*(undefined8 *)(param_1 + 0x1e8));
  if (iVar2 == 0) {
    lVar1 = *local_30[0];
    iVar2 = btreeSearch(param_2,local_30,*(undefined8 *)(param_1 + 0x1e8));
    if ((iVar2 == 0) && (iVar2 = btreeUnlink(local_30[0],param_1 + 0x1e8), iVar2 == 0)) {
      if (((*(byte *)(*(long *)(lVar1 + 0x48) + 8) & 2) != 0) &&
         ((*(uint *)(lVar1 + 0x3c) & 3) == 1)) {
        *(int *)(param_1 + 0x1f0) = *(int *)(param_1 + 0x1f0) + -1;
      }
      portMemFree(lVar1);
      return 0;
    }
  }
  return 0xffff;
}


// ===== 002fe88b _class5080DeferredApiV2.cold =====

void _class5080DeferredApiV2_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002fe8a0 _class5080DeferredApiV2 =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _class5080DeferredApiV2
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  code *pcVar5;
  undefined4 uVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  long lVar11;
  ulong uVar12;
  undefined8 uVar13;
  undefined4 local_268;
  undefined4 local_264;
  long local_260;
  undefined8 *local_258;
  undefined8 local_250;
  undefined8 local_248;
  undefined8 local_240;
  undefined8 local_238;
  undefined8 local_230;
  undefined8 local_228;
  ulong local_220;
  undefined8 local_218;
  undefined8 local_210;
  undefined1 *local_208;
  long local_200;
  undefined8 local_1f8;
  undefined8 *local_1e8;
  undefined8 local_1e0;
  undefined8 local_1d8;
  undefined8 local_1d0;
  undefined8 local_1c8;
  long **local_1c0;
  long *local_198;
  undefined4 local_190;
  uint local_18c;
  long local_188;
  undefined4 local_180;
  undefined8 local_178;
  undefined4 local_160;
  undefined4 uStack_15c;
  undefined8 local_158;
  undefined8 local_150;
  undefined8 local_148;
  undefined8 *local_140;
  long **local_138;
  undefined1 local_12f;
  long *local_120 [30];
  
  lVar11 = __nvoc_dynamicCast(param_2,__nvoc_class_def_DeferredApiObject);
  iVar8 = btreeSearch(param_4,local_120,*(undefined8 *)(lVar11 + 0x1e8));
  if (iVar8 != 0) {
    return 0x25;
  }
  lVar1 = *local_120[0];
  lVar2 = *(long *)(lVar1 + 0x48);
  uVar9 = *(uint *)(lVar2 + 4);
  if (uVar9 == 0x20801208) {
    uVar6 = 0x18;
LAB_002fea20:
    local_180 = uVar6;
    uVar12 = 0;
    do {
      uVar9 = (int)uVar12 + 0x20;
      *(undefined8 *)((long)local_120 + uVar12) = 0;
      *(undefined8 *)((long)local_120 + uVar12 + 8) = 0;
      *(undefined8 *)((long)local_120 + uVar12 + 0x10) = 0;
      *(undefined8 *)((long)local_120 + uVar12 + 0x18) = 0;
      uVar12 = (ulong)uVar9;
    } while (uVar9 < 0xe0);
    *(undefined8 *)((long)local_120 + (ulong)uVar9) = 0;
    local_248 = 0;
    local_240 = 0;
    local_238 = 0;
    local_230 = 0;
    local_228 = 0;
    local_220 = 0;
    local_218 = 0;
    local_210 = 0;
    local_264 = 0;
    lVar3 = **(long **)(*(long *)(lVar11 + 0x1a8) + 0x48);
    local_250 = 0;
    uVar13 = *(undefined8 *)(*(long *)(lVar11 + 0x1c0) + 0xe8);
    portMemSet(&local_198,0,0x78);
    local_198 = (long *)CONCAT44(local_198._4_4_,*(undefined4 *)(lVar3 + 0x48));
    local_190 = *(undefined4 *)(lVar2 + 4);
    local_188 = lVar2 + 0x18;
    local_160 = *(undefined4 *)(lVar1 + 0x40);
    local_220 = local_220 | 6;
    local_138 = local_120;
    local_140 = &local_248;
    uStack_15c = 1;
    local_12f = 1;
    local_18c = 2;
    local_178 = param_1;
    cVar7 = osIsRaisedIRQL();
    if ((cVar7 != '\0') || (cVar7 = hypervisorIsVgxHyper_IMPL(), cVar7 != '\0')) {
      local_18c = local_18c | 1;
    }
    iVar8 = subdeviceGetByDeviceAndGpu_IMPL(lVar3,uVar13,param_1,&local_260);
    if (iVar8 == 0) {
      uVar13 = 0;
      if (local_260 != 0) {
        uVar13 = *(undefined8 *)(local_260 + 0x140);
      }
      iVar8 = resControlLookup_IMPL(uVar13,&local_198,&local_258);
      if (iVar8 == 0) {
        if (local_258 == (undefined8 *)0x0) {
          nvAssertFailedNoLog("pEntry != NULL","src/kernel/gpu/deferred_api.c",0x260);
        }
        serverControl_InitCookie(local_258,local_120);
        portMemSet(&local_208,0,0x70);
        if (local_260 == 0) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)invalidInstructionException();
          (*pcVar5)();
        }
        local_1f8 = *(undefined8 *)(*(long *)(local_260 + 0x140) + 0x48);
        local_208 = g_resServ;
        local_1e0 = CONCAT44(uStack_15c,local_160);
        local_1d8 = local_158;
        local_1d0 = local_150;
        local_1c8 = local_148;
        local_1c0 = &local_198;
        local_1e8 = local_140;
        local_200 = lVar3;
        iVar8 = resservSwapTlsCallContext(&local_250,&local_208);
        if (iVar8 == 0) {
          iVar8 = serverControl_Prologue(g_resServ,&local_198,&local_268,&local_264);
          if (iVar8 == 0) {
            if (*(int *)((long)local_258 + 0x14) == 0) {
              iVar8 = (*(code *)*local_258)(local_260);
            }
            else {
              iVar8 = (*(code *)*local_258)(local_260,local_188);
            }
          }
          iVar10 = resservRestoreTlsCallContext(local_250);
          if (iVar10 != 0) {
            nvAssertOkFailedNoLog
                      (iVar10,"resservRestoreTlsCallContext(pOldContext)",
                       "src/kernel/gpu/deferred_api.c",0x289,iVar8);
          }
          iVar8 = serverControl_Epilogue(g_resServ,&local_198,local_268,&local_264,iVar8);
          *(uint *)(lVar1 + 0x3c) = *(uint *)(lVar1 + 0x3c) | 1;
          uVar9 = *(uint *)(lVar2 + 8);
          goto joined_r0x002fed75;
        }
        nvAssertOkFailedNoLog
                  (iVar8,"resservSwapTlsCallContext(&pOldContext, &callContext)",
                   "src/kernel/gpu/deferred_api.c",0x274);
      }
    }
  }
  else {
    if (uVar9 < 0x20801209) {
      if (uVar9 == 0x2080012d) {
        uVar6 = 0x38;
      }
      else if (uVar9 < 0x2080012e) {
        if (uVar9 == 0x2080012b) {
          uVar6 = 0x230;
        }
        else {
          uVar6 = 0x14;
          if (uVar9 != 0x2080012c) goto LAB_002fe960;
        }
      }
      else {
        uVar6 = 0x20;
        if (uVar9 != 0x20801116) {
LAB_002fe960:
          nvDbg_Printf("src/kernel/gpu/deferred_api.c",0x223,"_class5080DeferredApiV2",4,
                       "NVRM: Unknown or Unimplemented Command %x\n");
          nvAssertFailedNoLog(&DAT_00d0b410,"src/kernel/gpu/deferred_api.c",0x225);
          iVar8 = 0x1f;
          goto LAB_002fe9b0;
        }
      }
      goto LAB_002fea20;
    }
    if (uVar9 == 0x20801211) {
      uVar6 = 0x70;
      goto LAB_002fea20;
    }
    if (uVar9 != 0x20802502) {
      uVar6 = 0x28;
      if (uVar9 != 0x20801209) goto LAB_002fe960;
      goto LAB_002fea20;
    }
    iVar8 = serverGetClientUnderLock(g_resServ,*(undefined4 *)(lVar2 + 0xc),&local_248);
    if (iVar8 == 0) {
      iVar8 = subdeviceGetByHandle_IMPL(local_248,*(undefined4 *)(lVar2 + 0x10),&local_208);
      if (iVar8 == 0) {
        local_198 = (long *)0x0;
        uVar13 = *(undefined8 *)(*(long *)(local_208 + 0x158) + 0xe0);
        if (*(long *)(local_208 + 0x338) == 0) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)invalidInstructionException();
          (*pcVar5)();
        }
        iVar8 = vaspaceGetByHandleOrDeviceDefault_IMPL
                          (local_248,
                           *(undefined4 *)
                            (*(long *)(*(long *)(*(long *)(local_208 + 0x338) + 0x110) + 0x48) +
                            0x10),*(undefined4 *)(lVar2 + 0x24),&local_198);
        if ((iVar8 == 0) &&
           ((**(code **)(*local_198 + 0xe0))(local_198,uVar13,0), *(int *)(lVar11 + 0x1f0) != 0)) {
          btreeEnumStart(0,local_120,*(undefined8 *)(lVar11 + 0x1e8));
          while ((local_120[0] != (long *)0x0 && (*(int *)(lVar11 + 0x1f0) != 0))) {
            lVar3 = *local_120[0];
            lVar4 = *(long *)(lVar3 + 0x48);
            if (((*(byte *)(lVar4 + 8) & 2) == 0) || ((*(uint *)(lVar3 + 0x3c) & 3) != 1)) {
              btreeEnumNext(local_120,*(undefined8 *)(lVar11 + 0x1e8));
            }
            else {
              *(uint *)(lVar3 + 0x3c) = *(uint *)(lVar3 + 0x3c) | 2;
              *(int *)(lVar11 + 0x1f0) = *(int *)(lVar11 + 0x1f0) + -1;
              btreeEnumNext(local_120,*(undefined8 *)(lVar11 + 0x1e8));
              if ((*(byte *)(lVar4 + 8) & 1) == 0) {
                _Class5080DelDeferredApi(lVar11,*(undefined4 *)(lVar3 + 0x38));
              }
            }
          }
        }
      }
      else {
        nvDbg_Printf("src/kernel/gpu/deferred_api.c",0x1f5,"_class5080DeferredApiV2",4,
                     "NVRM: Unable to find target gpu from hClient(%x), hDevice(%x)\n",
                     *(undefined4 *)(lVar2 + 0xc),*(undefined4 *)(lVar2 + 0x10));
      }
    }
  }
LAB_002fe9b0:
  *(uint *)(lVar1 + 0x3c) = *(uint *)(lVar1 + 0x3c) | 1;
  uVar9 = *(uint *)(lVar2 + 8);
joined_r0x002fed75:
  if ((uVar9 & 1) != 0) {
    return iVar8;
  }
  if ((uVar9 & 2) != 0) {
    *(int *)(lVar11 + 0x1f0) = *(int *)(lVar11 + 0x1f0) + 1;
    return iVar8;
  }
  _Class5080DelDeferredApi(lVar11,param_4);
  return iVar8;
}


// ===== 002ff115 _Class5080AddDeferredApi.constprop.0.cold =====

void _Class5080AddDeferredApi_constprop_0_cold(void)

{
  code *pcVar1;
  undefined8 unaff_RBX;
  long unaff_RBP;
  undefined8 unaff_R13;
  
  *(undefined8 *)(unaff_RBP + -0x28) = unaff_RBX;
  *(undefined8 *)(unaff_RBP + -0x18) = unaff_R13;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002ff130 _Class5080AddDeferredApi.constprop.0 =====

ulong _Class5080AddDeferredApi_constprop_0(long param_1,ulong param_2,undefined8 param_3)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  undefined1 local_40 [16];
  
  param_2 = param_2 & 0xffffffff;
  lVar4 = resservGetTlsCallContext();
  if (param_1 != 0) {
    if (lVar4 == 0) {
      nvAssertFailedNoLog("pCallContext != NULL","src/kernel/gpu/deferred_api.c",0x49);
      uVar6 = 0x40;
    }
    else {
      cVar2 = serverutilValidateNewResourceHandle
                        (*(undefined4 *)(**(long **)(*(long *)(param_1 + 0x1a8) + 0x48) + 0x48),
                         param_2);
      if ((cVar2 == '\0') ||
         (iVar3 = btreeSearch(param_2,local_40,*(undefined8 *)(param_1 + 0x1e8)), iVar3 == 0)) {
        uVar6 = 0x33;
      }
      else {
        lVar5 = portMemAllocNonPaged(0x298);
        if (lVar5 == 0) {
          uVar6 = 0x51;
        }
        else {
          *(ulong *)(lVar5 + 8) = param_2;
          *(long *)(lVar5 + 0x48) = lVar5 + 0x50;
          *(ulong *)(lVar5 + 0x10) = param_2;
          *(long *)lVar5 = lVar5;
          *(ulong *)(lVar5 + 0x38) = param_2;
          *(undefined4 *)(lVar5 + 0x40) = *(undefined4 *)(lVar4 + 0x28);
          portMemCopy(lVar5 + 0x50,0x248,param_3,0x248);
          uVar6 = btreeInsert(lVar5,param_1 + 0x1e8);
          if ((int)uVar6 != 0) {
            portMemFree(lVar5);
            uVar6 = uVar6 & 0xffffffff;
          }
        }
      }
    }
    return uVar6;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002ff26b defapiConstruct_IMPL.cold =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void defapiConstruct_IMPL_cold(void)

{
  code *pcVar1;
  
  _DAT_0000018c = 0;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002ff280 defapiConstruct_IMPL =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 defapiConstruct_IMPL(long param_1,undefined8 param_2,long param_3)

{
  code *pcVar1;
  
  if ((*(char **)(param_3 + 0x40) != (char *)0x0) && (**(char **)(param_3 + 0x40) != '\0')) {
    if (param_1 == 0) {
      _DAT_0000018c = 0;
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    *(undefined4 *)(*(long *)(param_1 + 0x1d8) + 0x18c) = 1;
    *(undefined1 *)(*(long *)(param_1 + 0x1d8) + 400) = 1;
  }
  return 0;
}


// ===== 002ff2c0 defapiDestruct_IMPL =====

void defapiDestruct_IMPL(long param_1)

{
  long lVar1;
  long *local_20;
  
  btreeEnumStart(0,&local_20,*(undefined8 *)(param_1 + 0x1e8));
  while (local_20 != (long *)0x0) {
    lVar1 = *local_20;
    btreeEnumNext(&local_20,*(undefined8 *)(param_1 + 0x1e8));
    _Class5080DelDeferredApi(param_1,*(undefined4 *)(lVar1 + 0x38));
  }
  return;
}


// ===== 002ff340 defapiCtrlCmdDeferredApi_IMPL =====

undefined8 defapiCtrlCmdDeferredApi_IMPL(long param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  
  if (*(char *)(*(long *)(*(long *)(param_1 + 0x1c0) + 0xe0) + 0x908) != '\0') {
    return 0;
  }
  uVar1 = _Class5080AddDeferredApi_constprop_0(param_1,*param_2,param_2);
  return uVar1;
}


// ===== 002ff370 defapiCtrlCmdDeferredApiV2_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong defapiCtrlCmdDeferredApiV2_IMPL(long param_1,long param_2)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  char *pcVar4;
  undefined8 uVar5;
  undefined8 local_18;
  long local_10;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x1c0) + 0xe0);
  if (*(char *)(lVar1 + 0x908) != '\0') {
    return 0;
  }
  if ((*(char *)(lVar1 + 0x909) != '\0') && (*(int *)(param_2 + 4) == 0x20801116)) {
    local_18 = 0;
    local_10 = 0;
    uVar3 = serverGetClientUnderLock(g_resServ,*(undefined4 *)(param_2 + 0x18),&local_18);
    if ((int)uVar3 != 0) {
      uVar5 = 0x164;
      pcVar4 = "serverGetClientUnderLock(&g_resServ, pParams->hClient, &pClient)";
      goto LAB_002ff4d4;
    }
    uVar3 = clientGetResourceRef_IMPL(local_18,*(undefined4 *)(param_2 + 0x20),&local_10);
    if ((int)uVar3 != 0) {
      uVar5 = 0x167;
      pcVar4 = "clientGetResourceRef(pClient, pParams->hUserdMemory, &pResourceRef)";
      goto LAB_002ff4d4;
    }
    if (*(long *)(local_10 + 0x18) == 0) {
      nvCheckFailedNoLog(4,"pResourceRef->pParentRef != NULL","src/kernel/gpu/deferred_api.c",0x16a)
      ;
      return 0x36;
    }
    uVar3 = memRegisterWithGsp_IMPL
                      (lVar1,local_18,*(undefined4 *)(*(long *)(local_10 + 0x18) + 0x10),
                       *(undefined4 *)(local_10 + 0x10));
    if ((int)uVar3 != 0) {
      uVar5 = 0x172;
      pcVar4 = 
      "memRegisterWithGsp(pGpu, pClient, pResourceRef->pParentRef->hResource, pResourceRef->hResource)"
      ;
      goto LAB_002ff4d4;
    }
  }
  plVar2 = *(long **)(*(long *)(param_1 + 0x1a8) + 0x48);
  uVar3 = (**(code **)(lVar1 + 0x3b90))
                    (lVar1 + 0x3b58,*(undefined4 *)(*plVar2 + 0x48),(int)plVar2[2],0x50800104,
                     param_2,0x248);
  if ((int)uVar3 == 0) {
    return uVar3;
  }
  uVar5 = 0x184;
  pcVar4 = 
  "pRmApi->Control(pRmApi, RES_GET_CLIENT_HANDLE(pDeferredApiObj), RES_GET_HANDLE(pDeferredApiObj), NV5080_CTRL_CMD_DEFERRED_API_INTERNAL, pDeferredApi, sizeof(*pDeferredApi))"
  ;
LAB_002ff4d4:
  nvCheckOkFailedNoLog(4,uVar3 & 0xffffffff,pcVar4,"src/kernel/gpu/deferred_api.c",uVar5);
  return uVar3 & 0xffffffff;
}


// ===== 002ff540 defapiCtrlCmdDeferredApiInternal_IMPL =====

void defapiCtrlCmdDeferredApiInternal_IMPL(undefined8 param_1,undefined4 *param_2)

{
  _Class5080AddDeferredApi_constprop_0(param_1,*param_2,param_2);
  return;
}


// ===== 002ff550 defapiCtrlCmdRemoveApi_IMPL =====

undefined8 defapiCtrlCmdRemoveApi_IMPL(long param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  
  if (*(char *)(*(long *)(*(long *)(param_1 + 0x1c0) + 0xe0) + 0x908) != '\0') {
    return 0;
  }
  uVar1 = _Class5080DelDeferredApi(param_1,*param_2);
  return uVar1;
}


// ===== 002ff580 defapiGetSwMethods_IMPL =====

undefined8 defapiGetSwMethods_IMPL(undefined8 param_1,undefined8 *param_2,undefined4 *param_3)

{
  *param_2 = Nv50DeferredApi;
  *param_3 = 2;
  return 0;
}


// ===== 002ff5a0 defapiIsSwMethodStalling_IMPL =====

undefined8 defapiIsSwMethodStalling_IMPL(long param_1,undefined4 param_2)

{
  int iVar1;
  long *local_10;
  
  iVar1 = btreeSearch(param_2,&local_10,*(undefined8 *)(param_1 + 0x1e8));
  if (iVar1 != 0) {
    return 1;
  }
  return CONCAT71((int7)((ulong)*(long *)(*local_10 + 0x48) >> 8),
                  *(int *)(*(long *)(*local_10 + 0x48) + 4) != 0x20801116);
}


// ===== 002ff5f0 _deviceTeardown.isra.0 =====

void _deviceTeardown_isra_0(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  long lVar5;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  deviceRemoveFromClientShare_IMPL();
  iVar4 = deviceKPerfCudaLimitCliDisable(param_1,lVar1);
  if (iVar4 != 0) {
    nvDbg_Printf("src/kernel/gpu/device.c",0x1de,"_deviceTeardown",4,
                 "NVRM: Disable of Cuda limit activation failed");
  }
  lVar2 = *(long *)(param_2 + 8);
  uVar3 = *(undefined8 *)(g_pSys + 0x218);
  lVar5 = __nvoc_dynamicCast(lVar2,__nvoc_class_def_RmClient);
  if ((*(int *)(lVar2 + 0x4c) == 0) && (*(char *)(lVar1 + 0x497) != '\0')) {
    gpuacctStopGpuAccounting_IMPL
              (uVar3,*(undefined4 *)(lVar1 + 0x7a4),*(undefined4 *)(lVar5 + 0x118),
               *(undefined4 *)(lVar5 + 0x11c));
    return;
  }
  return;
}


// ===== 002ff6c0 deviceDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

void deviceDestruct_IMPL(long param_1)

{
  undefined4 uVar1;
  long lVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  long lVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  bool bVar9;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  long local_b0;
  undefined8 local_a8;
  long local_90;
  long local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  undefined8 local_40;
  
  uVar8 = 0;
  if (param_1 != 0) {
    uVar8 = *(undefined8 *)(param_1 + 0x110);
  }
  resGetFreeParams_IMPL(uVar8,&local_90,&local_88);
  uVar1 = *(undefined4 *)(*(long *)(local_90 + 8) + 0x48);
  nvDbg_Printf("src/kernel/gpu/device.c",0xd4,"deviceDestruct_IMPL",1,"NVRM:     type: device\n");
  _deviceTeardown_isra_0(param_1,local_90);
  lVar2 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  if (lVar2 == 0) {
    return;
  }
  if (*(char *)(lVar2 + 0x908) == '\0') {
    if ((*(char *)(lVar2 + 0x909) == '\0') && (*(char *)(lVar2 + 0x90a) == '\0')) {
      return;
    }
    local_f0 = *(undefined8 *)(local_90 + 8);
    uVar7 = *(undefined4 *)(*(long *)(local_90 + 0x10) + 0x10);
    bVar9 = false;
  }
  else {
    bVar9 = *(char *)(lVar2 + 0x4a4e) == '\0';
    local_f0 = *(undefined8 *)(local_90 + 8);
    uVar7 = *(undefined4 *)(*(long *)(local_90 + 0x10) + 0x10);
  }
  lVar6 = gpuGetRpc(lVar2);
  if (lVar6 == 0) {
    nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/device.c",0xf6);
    iVar5 = 0x1a;
  }
  else {
    if ((*(char *)(lVar2 + 0x909) == '\0') && (*(char *)(lVar2 + 0x90a) == '\0')) {
      iVar5 = (**(code **)(lVar6 + 0xf0))(lVar2,lVar6,uVar1,uVar1,uVar7,*(code **)(lVar6 + 0xf0));
    }
    else {
      iVar5 = (**(code **)(lVar2 + 0x3b70))(lVar2 + 0x3b58,uVar1,uVar7);
    }
    if (iVar5 == 0) {
      clientRefIter(&local_e8,local_f0,0,&DAT_00e0ac20,0,1);
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
        cVar4 = clientRefIterNext(local_60,&local_80);
        bVar3 = false;
        if (cVar4 == '\0') break;
        lVar6 = __nvoc_dynamicCast(*(undefined8 *)(local_48 + 8),__nvoc_class_def_Device);
      } while ((param_1 == lVar6) ||
              (bVar3 = (bool)(*(long *)(*(long *)(lVar6 + 0x128) + 0xe0) == lVar2 | bVar9), !bVar3))
      ;
      clientRefIter(&local_e8,local_f0,0,0x4adc81,0,1);
      local_80 = local_e8;
      local_78 = local_e0;
      local_70 = local_d8;
      local_68 = local_d0;
      local_60 = local_c8;
      local_58 = local_c0;
      local_50 = local_b8;
      local_48 = local_b0;
      local_40 = local_a8;
      while (cVar4 = clientRefIterNext(local_60,&local_80), cVar4 != '\0') {
        lVar6 = __nvoc_dynamicCast(*(undefined8 *)(local_48 + 8),
                                   __nvoc_class_def_KernelSMDebuggerSession);
        if (lVar6 != 0) {
          if (*(char *)(lVar2 + 0x4a4e) == '\0') {
            return;
          }
          if (lVar2 == *(long *)(*(long *)(lVar6 + 0x158) + 0xe0)) {
            return;
          }
        }
      }
      if (bVar3) {
        return;
      }
      lVar6 = gpuGetRpc(lVar2);
      if (lVar6 != 0) {
        if ((*(char *)(lVar2 + 0x909) == '\0') && (*(char *)(lVar2 + 0x90a) == '\0')) {
          (**(code **)(lVar6 + 0xf0))(lVar2,lVar6,uVar1,0,uVar1,*(code **)(lVar6 + 0xf0));
          return;
        }
        (**(code **)(lVar2 + 0x3b70))(lVar2 + 0x3b58,uVar1,uVar1);
        return;
      }
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/device.c",0x120);
      return;
    }
  }
  *(int *)(local_88 + 0x30) = iVar5;
  return;
}


// ===== 002ffaf5 deviceControl_IMPL.cold =====

void deviceControl_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002ffb00 deviceControl_IMPL =====

undefined8 deviceControl_IMPL(long param_1,undefined8 param_2,int *param_3)

{
  long *plVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  plVar1 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
  if (*param_3 == *(int *)(*plVar1 + 0x48)) {
    if (param_3[1] == (int)plVar1[2]) {
      if (param_3[7] == *(int *)(plVar1[3] + 0x10)) {
        *(undefined8 *)(param_3 + 10) = *(undefined8 *)(*(long *)(param_1 + 0x128) + 0xd8);
        uVar3 = gpuresControl_IMPL(*(undefined8 *)(param_1 + 0x128));
        return uVar3;
      }
      nvAssertFailedNoLog("pParams->hParent == RES_GET_PARENT_HANDLE(pDevice)",
                          "src/kernel/gpu/device.c",0x135);
    }
    else {
      nvAssertFailedNoLog("pParams->hObject == RES_GET_HANDLE(pDevice)","src/kernel/gpu/device.c",
                          0x134);
    }
  }
  else {
    nvAssertFailedNoLog("pParams->hClient == RES_GET_CLIENT_HANDLE(pDevice)",
                        "src/kernel/gpu/device.c",0x133);
  }
  return 0x40;
}


// ===== 002ffbc0 deviceInternalControlForward_IMPL =====

void deviceInternalControlForward_IMPL(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x128);
  }
  gpuresInternalControlForward_IMPL(uVar1);
  return;
}


// ===== 002ffbe0 deviceGetByHandle_IMPL =====

int deviceGetByHandle_IMPL(undefined8 param_1,undefined8 param_2,long *param_3)

{
  int iVar1;
  long lVar2;
  long local_20;
  
  *param_3 = 0;
  iVar1 = clientGetResourceRef_IMPL(param_1,param_2,&local_20);
  if (iVar1 == 0) {
    lVar2 = __nvoc_dynamicCast(*(undefined8 *)(local_20 + 8),__nvoc_class_def_Device);
    *param_3 = lVar2;
    if (lVar2 == 0) {
      iVar1 = 0x33;
    }
  }
  return iVar1;
}


// ===== 002ffc40 deviceGetByInstance_IMPL =====

undefined8 deviceGetByInstance_IMPL(undefined8 param_1,int param_2,long *param_3)

{
  char cVar1;
  long lVar2;
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
  
  *param_3 = 0;
  clientRefIter(&local_b8,param_1,0,&DAT_00e0ac20,0,1);
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
    cVar1 = clientRefIterNext(local_40,&local_60);
    if (cVar1 == '\0') {
      return 0x57;
    }
    lVar2 = __nvoc_dynamicCast(*(undefined8 *)(local_28 + 8),__nvoc_class_def_Device);
  } while ((lVar2 == 0) || (*(int *)(lVar2 + 0x180) != param_2));
  *param_3 = lVar2;
  return 0;
}


// ===== 002ffd40 deviceConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int deviceConstruct_IMPL(long param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint *puVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  ulong uVar14;
  uint uVar15;
  undefined8 uVar16;
  undefined8 local_130;
  ulong local_120;
  uint local_114;
  undefined8 local_100;
  uint local_f8;
  uint local_f4;
  long local_e8;
  uint local_e0;
  uint local_dc;
  ulong local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined4 local_b0;
  int local_ac [2];
  undefined8 auStack_a4 [9];
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar1 = *(undefined4 *)(param_3 + 0xc);
  puVar3 = *(uint **)(param_3 + 0x40);
  lVar10 = sysGetOs_IMPL(g_pSys);
  if (puVar3 == (uint *)0x0) {
    uVar15 = 0;
    local_120 = 0;
    local_100 = 0;
    local_f8 = 0;
    uVar8 = *(int *)(param_3 + 0xc) - 0x80;
    local_f4 = 0;
    uVar2 = 0;
    local_114 = 0;
    uVar14 = 0;
  }
  else {
    uVar2 = puVar3[1];
    uVar15 = puVar3[4];
    uVar8 = *puVar3;
    local_f4 = puVar3[2];
    local_f8 = puVar3[3];
    local_100 = *(undefined8 *)(puVar3 + 6);
    local_114 = puVar3[0xc];
    if ((uVar15 & 0x800) == 0) {
      local_120 = 0;
      uVar14 = 0;
    }
    else {
      local_120 = *(ulong *)(puVar3 + 8);
      uVar14 = *(ulong *)(puVar3 + 10);
      if (uVar14 < local_120) {
        return 0x1f;
      }
      if (uVar14 == 0) {
        return 0x1f;
      }
    }
  }
  iVar5 = gpumgrIsDeviceInstanceValid(uVar8);
  if (iVar5 != 0) {
    return 0x22;
  }
  cVar4 = gpumgrIsDeviceEnabled(uVar8);
  if (cVar4 != '\0') {
    local_130 = 0;
    if (param_1 != 0) {
      local_130 = *(undefined8 *)(param_1 + 0x128);
    }
    if (uVar8 < 0x20) {
      uVar6 = gpumgrGetPrimaryForDevice(uVar8);
      lVar11 = gpumgrGetGpu(uVar6);
      if (lVar11 == 0) {
        return 0x40;
      }
      iVar5 = deviceGetByInstance_IMPL(*(undefined8 *)(param_2 + 8),uVar8,&local_b0);
      if ((iVar5 != 0) || (*(char *)(lVar11 + 0x908) == '\0')) {
        *(uint *)(param_1 + 0x180) = uVar8;
        *(undefined8 *)(param_1 + 0x1d8) = 0;
        *(uint *)(param_1 + 0x1ac) = local_f4;
        *(uint *)(param_1 + 0x1b0) = local_f8;
        *(uint *)(param_1 + 0x1d0) = local_114;
        gpuresSetGpu_IMPL(local_130,lVar11,1);
        if ((*(char *)(lVar11 + 0x4913) != '\0') &&
           ((*(char *)(lVar11 + 0x4922) != '\0' && (uVar2 == 0)))) {
          uVar2 = *(uint *)(lVar11 + 0x3b18);
        }
        iVar7 = deviceSetClientShare_IMPL(param_1,uVar2,local_100,local_120,uVar14,uVar15);
        if (iVar7 != 0) {
          deviceRemoveFromClientShare_IMPL(param_1);
          return iVar7;
        }
        uVar16 = *(undefined8 *)(g_pSys + 0x218);
        lVar13 = *(long *)(param_2 + 8);
        lVar12 = __nvoc_dynamicCast(lVar13,__nvoc_class_def_RmClient);
        if (((*(char *)(lVar11 + 0x497) != '\0') && (*(int *)(lVar13 + 0x4c) == 0)) &&
           (iVar7 = gpuacctStartGpuAccounting_IMPL
                              (uVar16,*(undefined4 *)(lVar11 + 0x7a4),
                               *(undefined4 *)(lVar12 + 0x118),*(undefined4 *)(lVar12 + 0x11c)),
           iVar7 != 0)) {
          nvAssertFailedNoLog(&DAT_00d0b74b,"src/kernel/gpu/device.c",0x1b0);
          nvDbg_Printf("src/kernel/gpu/device.c",0x1b1,"_deviceInit",4,
                       "NVRM: gpuacctStartGpuAccounting() failed for procId : %d and SubProcessID : %d. Ignoring the failure and continuing.\n"
                       ,*(undefined4 *)(lVar12 + 0x118));
        }
        if (((uVar15 & 0x4000) != 0) && ((uVar15 & 0x2000) == 0)) {
          nvAssertFailedNoLog("allocFlags & NV_DEVICE_ALLOCATION_FLAGS_HOST_VGPU_DEVICE",
                              "src/kernel/gpu/device.c",0x1bb);
          return 0x1f;
        }
        lVar11 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
        if ((*(uint *)(param_2 + 0x28) < 2) && (cVar4 = osIsGpuAccessible(lVar11), cVar4 == '\0')) {
          _deviceTeardown_isra_0(param_1,param_2);
          return 0x1b;
        }
        if ((*(char *)(lVar10 + 0x4b) != '\0') && (*(char *)(lVar11 + 0x44f) != '\0')) {
          _deviceTeardown_isra_0(param_1,param_2);
          return 0x10;
        }
        if ((*(long *)(lVar11 + 0x1c18) != 0) &&
           (cVar4 = krcTestAllowAlloc_IMPL(lVar11,*(long *)(lVar11 + 0x1c18),2), cVar4 == '\0')) {
          _deviceTeardown_isra_0(param_1,param_2);
          return 0xffff;
        }
        if (((*(char *)(lVar11 + 0x908) == '\0') && (*(char *)(lVar11 + 0x909) == '\0')) &&
           (*(char *)(lVar11 + 0x90a) == '\0')) {
          return 0;
        }
        lVar10 = gpuGetRpc(lVar11);
        if (lVar10 != 0) {
          local_b0 = *(undefined4 *)(param_3 + 4);
          if ((*(char *)(lVar11 + 0x909) == '\0') && (*(char *)(lVar11 + 0x90a) == '\0')) {
            iVar5 = (**(code **)(lVar10 + 0x80))
                              (lVar11,lVar10,local_b0,*(undefined4 *)(param_3 + 8),
                               *(undefined4 *)(param_1 + 0x1a8),local_f4,local_f8,uVar1,
                               (ulong)uVar15 & 0xffffffffffff9fff,local_100,local_114);
            return iVar5;
          }
          local_58 = 0;
          uVar8 = 0;
          local_50 = 0;
          local_48 = 0;
          local_40 = 0;
          do {
            uVar14 = (ulong)uVar8;
            uVar8 = uVar8 + 0x20;
            *(undefined8 *)((long)local_ac + uVar14) = 0;
            *(undefined8 *)((long)auStack_a4 + uVar14) = 0;
            *(undefined8 *)((long)auStack_a4 + uVar14 + 8) = 0;
            *(undefined8 *)((long)auStack_a4 + uVar14 + 0x10) = 0;
          } while (uVar8 < 0x60);
          cVar4 = rmcfg_IsT234DorBetter(lVar11);
          if (cVar4 == '\0') {
            lVar10 = serverutilGetClientUnderLock(*(undefined4 *)(param_3 + 4));
            if (lVar10 == 0) {
              nvAssertFailedNoLog(&DAT_00d0b74b,"src/kernel/gpu/device.c",0xb8);
            }
            else {
              lVar13 = resservGetTlsCallContext();
              if (lVar13 == 0) {
                nvAssertFailedNoLog("pCallContext != NULL","src/kernel/gpu/device.c",0xb8);
                return 0x40;
              }
              if (*(uint *)(lVar13 + 0x28) < 2) {
                iVar7 = *(int *)(lVar10 + 0x118);
                local_ac[0] = iVar7;
                iVar9 = osGetCurrentProcess();
                if (iVar7 != iVar9) {
                  nvAssertFailedNoLog("root_alloc_params.processID == osGetCurrentProcess()",
                                      "src/kernel/gpu/device.c",0xb8);
                }
                local_40 = *(undefined8 *)(lVar10 + 0x198);
              }
              else {
                local_ac[0] = -1;
              }
            }
          }
          if (iVar5 != 0) {
            uVar16 = 0x78;
            iVar5 = (**(code **)(lVar11 + 0x3b60))
                              (lVar11 + 0x3b58,*(undefined4 *)(param_3 + 4),0,0,0,&local_b0);
            if (iVar5 != 0) {
              nvAssertFailedNoLog(&DAT_00d0b74b,"src/kernel/gpu/device.c",0xb8,uVar16);
              return iVar5;
            }
          }
          local_e8 = (ulong)*(uint *)(param_1 + 0x1a8) << 0x20;
          local_e0 = local_f4;
          local_c8 = 0;
          local_dc = local_f8;
          local_c0 = 0;
          local_d0 = local_100;
          local_b8 = 0;
          local_d8 = (ulong)uVar15 & 0xffffffffffff9fff;
          iVar5 = (**(code **)(lVar11 + 0x3b60))
                            (lVar11 + 0x3b58,*(undefined4 *)(param_3 + 4),
                             *(undefined4 *)(param_3 + 4),*(undefined4 *)(param_3 + 8),uVar1,
                             &local_e8,0x38);
          return iVar5;
        }
        nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/device.c",0xb8);
      }
      return 0x1a;
    }
  }
  return 0x1f;
}


// ===== 00300560 deviceGetByGpu_IMPL =====

undefined8 deviceGetByGpu_IMPL(undefined8 param_1,long param_2,char param_3,long *param_4)

{
  undefined8 uVar1;
  
  uVar1 = deviceGetByInstance_IMPL(param_1,*(undefined4 *)(param_2 + 0x7b4),param_4);
  if ((int)uVar1 == 0) {
    if ((param_3 != '\0') || (*(long *)(*(long *)(*param_4 + 0x128) + 0xe0) == param_2)) {
      return uVar1;
    }
    *param_4 = 0;
  }
  return 0x57;
}


// ===== 003005d0 CliSetGpuContext =====

int CliSetGpuContext(undefined4 param_1,undefined4 param_2,undefined8 *param_3,undefined8 *param_4)

{
  int iVar1;
  long lVar2;
  undefined8 local_38;
  long local_30 [2];
  
  if (param_4 != (undefined8 *)0x0) {
    *param_4 = 0;
  }
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = 0;
  }
  iVar1 = serverGetClientUnderLock(g_resServ,param_1,&local_38);
  if (iVar1 == 0) {
    iVar1 = clientGetResourceRef_IMPL(local_38,param_2,local_30);
    if (iVar1 == 0) {
      lVar2 = __nvoc_dynamicCast(*(undefined8 *)(local_30[0] + 8),__nvoc_class_def_Device);
      if (lVar2 == 0) {
        iVar1 = 0x33;
      }
      else {
        if (param_3 != (undefined8 *)0x0) {
          *param_3 = *(undefined8 *)(*(long *)(lVar2 + 0x128) + 0xe0);
        }
        if (param_4 != (undefined8 *)0x0) {
          *param_4 = *(undefined8 *)(*(long *)(lVar2 + 0x128) + 0xd8);
          return 0;
        }
      }
    }
  }
  return iVar1;
}


// ===== 003006b0 CliGetGpuFromContext =====

undefined8 CliGetGpuFromContext(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 local_10;
  
  iVar1 = gpuGetByRef(param_1,param_2,&local_10);
  uVar2 = 0;
  if (iVar1 == 0) {
    uVar2 = local_10;
  }
  return uVar2;
}


// ===== 003006e0 CliGetGpuFromHandle =====

undefined8 CliGetGpuFromHandle(undefined4 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 local_28;
  undefined8 local_20;
  
  iVar1 = serverGetClientUnderLock(g_resServ,param_1,&local_28);
  if (iVar1 == 0) {
    iVar1 = gpuGetByHandle(local_28,param_2,param_3,&local_20);
    if (iVar1 == 0) {
      return local_20;
    }
  }
  return 0;
}


// ===== 00300740 deviceCtrlCmdGpuGetClasslist_IMPL =====

undefined8 deviceCtrlCmdGpuGetClasslist_IMPL(long param_1,long param_2)

{
  char cVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0);
  cVar1 = rmapiLockIsOwner();
  if (cVar1 != '\0') {
    uVar2 = gpuGetClassList_IMPL(uVar2,param_2,*(undefined8 *)(param_2 + 8),0xb33b1500);
    return uVar2;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/device_ctrl.c",0x40);
  return 0x2f;
}


// ===== 003007b0 deviceCtrlCmdGpuGetClasslistV2_IMPL =====

undefined8 deviceCtrlCmdGpuGetClasslistV2_IMPL(long param_1,undefined4 *param_2)

{
  char cVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0);
  cVar1 = rmapiLockIsOwner();
  if (cVar1 != '\0') {
    *param_2 = 200;
    uVar2 = gpuGetClassList_IMPL(uVar2,param_2,param_2 + 1,0xb33b1500);
    return uVar2;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/device_ctrl.c",0x56);
  return 0x2f;
}


// ===== 00300830 deviceCtrlCmdGpuGetNumSubdevices_IMPL =====

undefined8 deviceCtrlCmdGpuGetNumSubdevices_IMPL(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 1;
  return 0;
}


// ===== 00300840 deviceCtrlCmdGpuModifyGpuSwStatePersistence_IMPL =====

undefined8 deviceCtrlCmdGpuModifyGpuSwStatePersistence_IMPL(long param_1,int *param_2)

{
  uint uVar1;
  long lVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  char cVar7;
  undefined4 local_2c [3];
  
  if (*param_2 == 0) {
    cVar7 = '\x01';
  }
  else {
    if (*param_2 != 1) {
      return 0x1f;
    }
    cVar7 = '\0';
  }
  lVar2 = *(long *)(g_pSys + 0x1e0);
  uVar3 = gpumgrGetGpuMask(*(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0));
  local_2c[0] = 0;
  while (lVar6 = gpumgrGetNextGpu(uVar3,local_2c), lVar6 != 0) {
    uVar1 = *(uint *)(lVar2 + 0x964);
    uVar4 = 1 << ((byte)*(undefined4 *)(lVar6 + 0x7a4) & 0x1f);
    uVar5 = ~uVar4 & uVar1;
    if (cVar7 != '\0') {
      uVar5 = uVar1 | uVar4;
    }
    *(uint *)(lVar2 + 0x964) = uVar5;
    *(char *)(lVar6 + 0x453) = cVar7;
    osModifyGpuSwStatePersistence(*(undefined8 *)(lVar6 + 0x4e0),cVar7);
  }
  return 0;
}


// ===== 00300920 deviceCtrlCmdGpuQueryGpuSwStatePersistence_IMPL =====

undefined8 deviceCtrlCmdGpuQueryGpuSwStatePersistence_IMPL(long param_1,uint *param_2)

{
  *param_2 = (uint)(*(char *)(*(long *)(*(long *)(param_1 + 0x128) + 0xe0) + 0x453) == '\0');
  return 0;
}


// ===== 00300950 deviceCtrlCmdGpuGetVirtualizationMode_IMPL =====

undefined8 deviceCtrlCmdGpuGetVirtualizationMode_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  undefined1 uVar2;
  char cVar3;
  undefined4 uVar4;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  if (lVar1 == 0) {
    return 0x1f;
  }
  uVar2 = os_is_grid_supported();
  uVar4 = 2;
  *(undefined1 *)(param_2 + 1) = uVar2;
  if ((*(char *)(lVar1 + 0x908) == '\0') && (uVar4 = 1, *(char *)(lVar1 + 0x4912) == '\0')) {
    cVar3 = hypervisorIsVgxHyper_IMPL();
    if ((cVar3 != '\0') && (*(char *)(lVar1 + 0x491d) != '\0')) {
      uVar4 = 3;
      if ((*(char *)(lVar1 + 0x4a3) != '\0') || (uVar4 = 4, *(char *)(lVar1 + 0x4a4) != '\0'))
      goto LAB_00300997;
      nvDbg_Printf("src/kernel/gpu/device_ctrl.c",0xef,"deviceCtrlCmdGpuGetVirtualizationMode_IMPL",
                   4,"NVRM: invalid virtualization Mode: %x. Returning NONE!\n");
    }
    uVar4 = 0;
  }
LAB_00300997:
  *param_2 = uVar4;
  nvDbg_Printf("src/kernel/gpu/device_ctrl.c",0xfd,"deviceCtrlCmdGpuGetVirtualizationMode_IMPL",1,
               "NVRM: Virtualization Mode: %x\n");
  return 0;
}


// ===== 00300a60 deviceCtrlCmdGpuVirtualizationSwitchToVga_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

undefined8 deviceCtrlCmdGpuVirtualizationSwitchToVga_IMPL(long param_1)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  if (lVar1 == 0) {
    return 0x1f;
  }
  lVar2 = gpuGetRpc(lVar1);
  if (lVar2 != 0) {
    uVar3 = (**(code **)(lVar2 + 0x298))(lVar1,lVar2,*(code **)(lVar2 + 0x298));
    return uVar3;
  }
  return 0;
}


// ===== 00300ac0 deviceCtrlCmdGpuGetSriovCaps_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 deviceCtrlCmdGpuGetSriovCaps_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  char cVar2;
  undefined8 uVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  cVar2 = rmapiLockIsOwner();
  if (cVar2 != '\0') {
    cVar2 = rmGpuLockIsOwner();
    if (cVar2 != '\0') {
      uVar3 = (**(code **)(lVar1 + 0x310))(lVar1,param_2);
      return uVar3;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()","src/kernel/gpu/device_ctrl.c",
                      0x12d);
  return 0x2f;
}


// ===== 00300b2a deviceCtrlCmdGpuGetFindSubDeviceHandle_IMPL.cold =====

void deviceCtrlCmdGpuGetFindSubDeviceHandle_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00300b40 deviceCtrlCmdGpuGetFindSubDeviceHandle_IMPL =====

void deviceCtrlCmdGpuGetFindSubDeviceHandle_IMPL(long param_1,undefined4 *param_2)

{
  undefined8 *puVar1;
  code *pcVar2;
  int iVar3;
  long local_20 [2];
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  puVar1 = *(undefined8 **)(*(long *)(param_1 + 0x110) + 0x48);
  iVar3 = subdeviceGetByInstance_IMPL(*puVar1,*(undefined4 *)(puVar1 + 2),*param_2,local_20);
  if (iVar3 == 0) {
    if (local_20[0] == 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
    param_2[1] = *(undefined4 *)(*(long *)(*(long *)(local_20[0] + 0x140) + 0x48) + 0x10);
  }
  return;
}


// ===== 00300ba0 deviceCtrlCmdGpuSetVgpuHeterogeneousMode_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int deviceCtrlCmdGpuSetVgpuHeterogeneousMode_IMPL(long param_1,char *param_2)

{
  long lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  long lVar4;
  char cVar5;
  int iVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  undefined2 *puVar11;
  undefined2 *puVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  undefined2 *local_60;
  char local_45;
  uint local_44;
  long local_40 [2];
  
  lVar14 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  if (lVar14 == 0) {
    nvCheckFailedNoLog(4,"pGpu != NULL","src/kernel/gpu/device_ctrl.c",0x161);
    return 0x1f;
  }
  lVar4 = *(long *)(g_pSys + 0x1f8);
  cVar5 = kvgpumgrIsMigTimeslicingModeEnabled(lVar14);
  if (((cVar5 == '\0') && (*(long *)(lVar14 + 0x1bc0) != 0)) &&
     (cVar5 = kmigmgrIsMIGEnabled_IMPL(lVar14), cVar5 != '\0')) {
    nvDbg_Printf("src/kernel/gpu/device_ctrl.c",0x164,
                 "deviceCtrlCmdGpuSetVgpuHeterogeneousMode_IMPL",4,
                 "NVRM: Call not supported with SMC enabled\n");
    return 0x56;
  }
  iVar6 = kvgpumgrGetPgpuIndex(lVar4,*(undefined4 *)(lVar14 + 0x7ac),&local_44);
  if (iVar6 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar6,"kvgpumgrGetPgpuIndex(pKernelVgpuMgr, pGpu->gpuId, &pgpuIndex)",
               "src/kernel/gpu/device_ctrl.c",0x168);
    return iVar6;
  }
  uVar7 = (ulong)local_44;
  lVar8 = uVar7 * 0xbbb80;
  lVar13 = lVar4 + 0x48 + lVar8;
  if (*(long *)(lVar14 + 0x1bc0) != 0) {
    cVar5 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar14);
    if (cVar5 != '\0') {
      local_60 = (undefined2 *)
                 kvgpuMgrGetVgpuPlacementInfo(lVar14,lVar13,*(undefined4 *)(param_2 + 4));
      if (local_60 == (undefined2 *)0x0) {
        nvCheckFailedNoLog(4,"pKernelVgpuTypePlacementInfo != NULL","src/kernel/gpu/device_ctrl.c",
                           0x16e);
        return 0x57;
      }
      goto LAB_00300c91;
    }
    if ((*(long *)(lVar14 + 0x1bc0) != 0) &&
       (cVar5 = kmigmgrIsMIGEnabled_IMPL(lVar14), cVar5 != '\0')) {
      nvDbg_Printf("src/kernel/gpu/device_ctrl.c",0x172,
                   "deviceCtrlCmdGpuSetVgpuHeterogeneousMode_IMPL",4,
                   "NVRM: No Graphic Instance created\n");
      return 0x56;
    }
  }
  local_60 = (undefined2 *)(lVar4 + 0x5a88 + lVar8);
LAB_00300c91:
  if (*(char *)(lVar4 + 0xbb839 + uVar7 * 0xbbb80) == '\0') {
    nvDbg_Printf("src/kernel/gpu/device_ctrl.c",0x17c,
                 "deviceCtrlCmdGpuSetVgpuHeterogeneousMode_IMPL",4,
                 "NVRM: GPU does not support heterogenenous vGPU mode\n");
    return 0x56;
  }
  if ((*(long *)(lVar14 + 0x1bc0) == 0) ||
     (cVar5 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar14), cVar5 == '\0')) {
    iVar6 = osIsVgpuVfioPresent();
    if (iVar6 == 0) {
      iVar6 = *(int *)(lVar4 + 0xbb83c + uVar7 * 0xbbb80);
    }
    else {
      iVar6 = *(int *)(lVar4 + 0x24c + uVar7 * 0xbbb80);
    }
  }
  else {
    iVar6 = *(int *)(lVar4 + 8 + ((ulong)*(uint *)(param_2 + 4) + 0x2eed4 + uVar7 * 0x2eee0) * 4);
  }
  if (iVar6 != 0) {
    nvDbg_Printf("src/kernel/gpu/device_ctrl.c",0x18e,
                 "deviceCtrlCmdGpuSetVgpuHeterogeneousMode_IMPL",4,
                 "NVRM: Failed to set heterogeneous vGPU mode as vGPU instance is active\n");
    return 0x17;
  }
  kvgpumgrSetVgpuType(lVar14,lVar13,0,*(undefined4 *)(param_2 + 4));
  if (*(char *)(lVar14 + 0x909) != '\0') {
    local_45 = *param_2;
    if ((*(long *)(lVar14 + 0x1bc0) == 0) ||
       (cVar5 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar14), cVar5 == '\0')) {
      uVar2 = *(undefined4 *)(lVar14 + 0x3b34);
      uVar3 = *(undefined4 *)(lVar14 + 0x3b3c);
    }
    else {
      iVar6 = kmigmgrGetGPUInstanceInfo_IMPL
                        (lVar14,*(undefined8 *)(lVar14 + 0x1bc0),*(undefined4 *)(param_2 + 4),
                         local_40);
      if (iVar6 != 0) {
        nvAssertOkFailedNoLog
                  (iVar6,
                   "kmigmgrGetGPUInstanceInfo(pGpu, pKernelMIGManager, pParams->gpuInstanceId, &pKernelMIGGpuInstance)"
                   ,"src/kernel/gpu/device_ctrl.c",0x1a3);
        return iVar6;
      }
      uVar2 = *(undefined4 *)(local_40[0] + 0x9c0);
      uVar3 = *(undefined4 *)(local_40[0] + 0x9c8);
    }
    iVar6 = (**(code **)(lVar14 + 0x3b90))(lVar14 + 0x3b58,uVar2,uVar3,0x2080400e,&local_45,1);
    if (iVar6 != 0) {
      nvDbg_Printf("src/kernel/gpu/device_ctrl.c",0x1b9,
                   "deviceCtrlCmdGpuSetVgpuHeterogeneousMode_IMPL",4,
                   "NVRM: Failed to set heterogeneous vGPU mode in GSP RM. status: 0x%x\n",iVar6);
      return iVar6;
    }
  }
  if (((*(long *)(lVar14 + 0x1bc0) == 0) ||
      (cVar5 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar14), cVar5 == '\0')) ||
     (cVar5 = kvgpumgrIsMigTimeslicingModeEnabled(lVar14), cVar5 == '\0')) {
    *(char *)(lVar14 + 0x4a5) = *param_2;
  }
  else {
    iVar6 = kvgpuMgrSetHeterogeneousModePerGI(lVar14,*(undefined4 *)(param_2 + 4),*param_2);
    if (iVar6 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar6,
                 "kvgpuMgrSetHeterogeneousModePerGI(pGpu, pParams->gpuInstanceId, pParams->bHeterogeneousMode)"
                 ,"src/kernel/gpu/device_ctrl.c",0x1c0);
      return iVar6;
    }
  }
  if ((*param_2 != '\0') && (lVar13 = uVar7 * 0xbbb80 + lVar4, *(int *)(lVar13 + 0x250) != 0)) {
    lVar15 = 0;
    puVar12 = local_60;
    do {
      lVar10 = *(long *)(lVar4 + lVar8 + 0x280 + lVar15 * 8);
      if (lVar10 != 0) {
        if (*(short *)(lVar10 + 0x30c) != 0) {
          lVar9 = 0;
          puVar11 = puVar12;
          do {
            lVar1 = lVar9 * 8;
            lVar9 = lVar9 + 1;
            *puVar11 = *(undefined2 *)(lVar10 + 0x18c + lVar1);
            puVar11 = puVar11 + 0xc;
          } while ((uint)lVar9 < (uint)*(ushort *)(lVar10 + 0x30c));
        }
        bitVectorClrAll_IMPL(local_60 + 0x12204,0x200);
      }
      lVar15 = lVar15 + 1;
      puVar12 = puVar12 + 0x244;
    } while ((uint)lVar15 < *(uint *)(lVar13 + 0x250));
  }
  iVar6 = kvgpumgrCheckHomogeneousPlacementSupported(lVar14,*(undefined4 *)(param_2 + 4));
  if (iVar6 == 0) {
    lVar14 = uVar7 * 0xbbb80 + lVar4;
    if (*(int *)(lVar14 + 0x250) != 0) {
      lVar13 = 0;
      puVar12 = local_60;
      do {
        lVar15 = *(long *)(lVar4 + lVar8 + 0x280 + lVar13 * 8);
        if ((lVar15 != 0) && (*(short *)(lVar15 + 0x30e) != 0)) {
          lVar10 = 0;
          puVar11 = puVar12;
          do {
            lVar9 = lVar10 * 8;
            lVar10 = lVar10 + 1;
            *puVar11 = *(undefined2 *)(lVar15 + 400 + lVar9);
            puVar11 = puVar11 + 0xc;
          } while ((uint)lVar10 < (uint)*(ushort *)(lVar15 + 0x30e));
        }
        lVar13 = lVar13 + 1;
        puVar12 = puVar12 + 0x244;
      } while ((uint)lVar13 < *(uint *)(lVar14 + 0x250));
    }
    bitVectorClrAll_IMPL(local_60 + 0x12204,0x200);
    return 0;
  }
  return 0;
}


// ===== 00301220 deviceCtrlCmdGpuGetVgpuHeterogeneousMode_IMPL =====

ulong deviceCtrlCmdGpuGetVgpuHeterogeneousMode_IMPL(long param_1,undefined1 *param_2)

{
  long lVar1;
  char cVar2;
  ulong uVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  if (lVar1 != 0) {
    if ((*(long *)(lVar1 + 0x1bc0) == 0) ||
       (cVar2 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar1), cVar2 == '\0')) {
      *param_2 = *(undefined1 *)(lVar1 + 0x4a5);
      uVar3 = 0;
    }
    else {
      cVar2 = kvgpumgrIsMigTimeslicingModeEnabled(lVar1);
      if (cVar2 == '\0') {
        *param_2 = 0;
        uVar3 = 0x56;
      }
      else {
        uVar3 = kvgpuMgrGetHeterogeneousMode(lVar1,*(undefined4 *)(param_2 + 4),param_2);
        if ((int)uVar3 != 0) {
          nvCheckOkFailedNoLog
                    (4,uVar3 & 0xffffffff,
                     "kvgpuMgrGetHeterogeneousMode(pGpu, pParams->gpuInstanceId, &pParams->bHeterogeneousMode)"
                     ,"src/kernel/gpu/device_ctrl.c",0x216);
          uVar3 = uVar3 & 0xffffffff;
        }
      }
    }
    return uVar3;
  }
  nvCheckFailedNoLog(4,"pGpu != NULL","src/kernel/gpu/device_ctrl.c",0x211);
  return 0x1f;
}


// ===== 00301320 deviceCtrlCmdGpuGetSparseTextureComputeMode_IMPL =====

undefined8 deviceCtrlCmdGpuGetSparseTextureComputeMode_IMPL(long param_1,long param_2)

{
  char cVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0);
  cVar1 = rmapiLockIsOwner();
  if (cVar1 != '\0') {
    uVar2 = gpuGetSparseTextureComputeMode_IMPL(uVar2,param_2,param_2 + 4,param_2 + 8);
    return uVar2;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/device_ctrl.c",0x244);
  return 0x2f;
}


// ===== 00301390 deviceCtrlCmdGpuSetSparseTextureComputeMode_IMPL =====

undefined8 deviceCtrlCmdGpuSetSparseTextureComputeMode_IMPL(long param_1,undefined4 *param_2)

{
  char cVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0);
  cVar1 = rmapiLockIsOwner();
  if (cVar1 != '\0') {
    uVar2 = gpuSetSparseTextureComputeMode_IMPL(uVar2,*param_2);
    return uVar2;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/device_ctrl.c",0x268);
  return 0x2f;
}


// ===== 003013f0 deviceCtrlCmdGpuGetVgxCaps_IMPL =====

undefined8 deviceCtrlCmdGpuGetVgxCaps_IMPL(long param_1,undefined1 *param_2)

{
  *param_2 = *(undefined1 *)(*(long *)(*(long *)(param_1 + 0x128) + 0xe0) + 0x4a2c);
  return 0;
}


// ===== 00301410 deviceCtrlCmdGpuGetBrandCaps_VF =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int deviceCtrlCmdGpuGetBrandCaps_VF(long param_1)

{
  long lVar1;
  undefined4 *puVar2;
  int iVar3;
  long lVar4;
  ulong extraout_RDX;
  ulong uVar5;
  ulong extraout_RDX_00;
  undefined4 local_1c;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  iVar3 = 0x56;
  if (*(char *)(lVar1 + 0x4a4e) != '\0') {
    lVar4 = resservGetTlsCallContext();
    local_1c = 0;
    puVar2 = *(undefined4 **)(lVar4 + 0x48);
    iVar3 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar1 + 0x7a4),1,2,0x80000,&local_1c);
    if (iVar3 == 0) {
      lVar4 = gpuGetRpc(lVar1);
      if (lVar4 == 0) {
        nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/device_ctrl.c",0x2a8);
        iVar3 = 0x1a;
        uVar5 = extraout_RDX_00;
      }
      else {
        uVar5 = (ulong)(uint)puVar2[6];
        if ((*(char *)(lVar1 + 0x909) == '\0') && (*(char *)(lVar1 + 0x90a) == '\0')) {
          iVar3 = rpcDmaControl_wrapper
                            (lVar1,lVar4,*puVar2,puVar2[1],puVar2[2],*(undefined8 *)(puVar2 + 4));
        }
        else {
          iVar3 = (**(code **)(lVar1 + 0x3b90))(lVar1 + 0x3b58);
          uVar5 = extraout_RDX;
        }
      }
      rmGpuGroupLockRelease(local_1c,0,uVar5);
      return iVar3;
    }
    nvAssertOkFailedNoLog
              (iVar3,
               "rmGpuGroupLockAcquire(pGpu->gpuInstance, GPU_LOCK_GRP_DEVICE, GPU_LOCK_FLAGS_SAFE_LOCK_UPGRADE, RM_LOCK_MODULES_GPU, &gpuMask)"
               ,"src/kernel/gpu/device_ctrl.c",0x2a1);
  }
  return iVar3;
}


// ===== 00301570 deviceInitClientShare.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong deviceInitClientShare_isra_0(long param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  uint uVar5;
  long lVar6;
  long lVar7;
  long local_50;
  undefined8 local_48;
  long local_40 [2];
  
  local_40[0] = 0;
  uVar4 = *(undefined8 *)(g_pSys + 0x230);
  lVar6 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  uVar1 = gpumgrGetGpuMask(lVar6);
  *(undefined8 *)(param_1 + 0x1a0) = 0;
  if (param_2 == 0) {
    uVar4 = gpumgrGetGpuGrpFromGpu(lVar6);
    uVar5 = gpugrpGetGlobalVASpace_IMPL(uVar4,local_40);
    if (uVar5 != 0) {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/device_share.c",0x79);
      return (ulong)uVar5;
    }
    vaspaceIncRefCnt_IMPL(local_40[0]);
    goto LAB_003017cd;
  }
  if (param_2 != *(int *)(**(long **)(*(long *)(param_1 + 0x110) + 0x48) + 0x48)) {
    uVar3 = serverGetClientUnderLock(g_resServ,param_2,&local_48);
    if ((int)uVar3 != 0) {
      return uVar3;
    }
    uVar3 = deviceGetByInstance_IMPL(local_48,*(undefined4 *)(param_1 + 0x180),&local_50);
    if ((int)uVar3 != 0) {
      return uVar3;
    }
    lVar6 = *(long *)(local_50 + 0x1a0);
    if (lVar6 == 0) {
      uVar3 = deviceInitClientShare_isra_0
                        (local_50,*(undefined4 *)(local_50 + 0x1a8),
                         *(undefined4 *)(local_50 + 0x1b4));
      if ((int)uVar3 != 0) {
        return uVar3;
      }
      lVar6 = *(long *)(local_50 + 0x1a0);
    }
    local_40[0] = lVar6;
    vaspaceIncRefCnt_IMPL();
    goto LAB_003017cd;
  }
  uVar5 = (param_3 & 0x100) << 10;
  if ((param_3 & 2) != 0) {
    uVar5 = uVar5 | 0x10;
  }
  if ((param_3 & 4) != 0) {
    uVar5 = uVar5 | 0x20;
  }
  lVar7 = 0;
  if ((param_3 & 8) != 0) {
    lVar7 = *(long *)(param_1 + 0x1c8) + -1;
  }
  if ((~param_3 & 0x600) == 0) {
    return 0x1f;
  }
  if ((param_3 & 0x800) == 0) {
    if (*(long *)(param_1 + 0x1b8) != 0) {
      nvAssertFailedNoLog("!pDevice->vaStartInternal","src/kernel/gpu/device_share.c",0xb7);
    }
    if (*(long *)(param_1 + 0x1c0) != 0) {
      nvAssertFailedNoLog("!pDevice->vaLimitInternal","src/kernel/gpu/device_share.c",0xb8);
    }
  }
  else {
    uVar5 = uVar5 | 8;
    if (*(long *)(param_1 + 0x1b8) == 0) {
      nvAssertFailedNoLog("pDevice->vaStartInternal","src/kernel/gpu/device_share.c",0xb2);
    }
    if (*(long *)(param_1 + 0x1c0) == 0) {
      nvAssertFailedNoLog("pDevice->vaLimitInternal","src/kernel/gpu/device_share.c",0xb3);
    }
  }
  if (*(long *)(lVar6 + 0x1b98) == 0) {
    if (*(char *)(lVar6 + 0x45a) == '\0') {
LAB_00301880:
      nvAssertFailedNoLog(&DAT_00d0bd9f,"src/kernel/gpu/device_share.c",0xc1);
      return 0x57;
    }
LAB_00301863:
    iVar2 = 0xf2;
  }
  else {
    iVar2 = (**(code **)(*(long *)(lVar6 + 0x1b98) + 0x1a0))();
    if ((*(long *)(lVar6 + 0x1b98) == 0) && (*(char *)(lVar6 + 0x45a) != '\0')) goto LAB_00301863;
    if (iVar2 == 0) goto LAB_00301880;
  }
  if ((*(char *)(lVar6 + 0x4922) == '\0') || (*(char *)(lVar6 + 0x908) == '\0')) {
    uVar5 = uVar5 | 0x84000000;
  }
  else {
    uVar5 = uVar5 | 0x4000000;
  }
  if (((*(char *)(*(long *)(lVar6 + 0x1b78) + 0x434) != '\0') &&
      (*(char *)(*(long *)(lVar6 + 0x1b78) + 0x436) != '\0')) && ((param_3 & 0x1000) != 0)) {
    uVar5 = uVar5 | 0x4000;
  }
  if ((param_3 & 0x8000) != 0) {
    uVar5 = uVar5 | 0x40;
  }
  uVar5 = vmmCreateVaspace_IMPL
                    (uVar4,iVar2,0,uVar1,0,lVar7,*(undefined8 *)(param_1 + 0x1b8),
                     *(undefined8 *)(param_1 + 0x1c0),0,uVar5,local_40);
  if (uVar5 != 0) {
    nvAssertFailedNoLog(&DAT_00d0bd9f,"src/kernel/gpu/device_share.c",0xf7);
    return (ulong)uVar5;
  }
LAB_003017cd:
  *(long *)(param_1 + 0x1a0) = local_40[0];
  return 0;
}


// ===== 003019a0 deviceSetClientShare_IMPL =====

undefined8
deviceSetClientShare_IMPL
          (long param_1,undefined4 param_2,long param_3,undefined8 param_4,undefined8 param_5,
          uint param_6)

{
  *(undefined8 *)(param_1 + 0x1a0) = 0;
  *(undefined4 *)(param_1 + 0x1a8) = param_2;
  *(uint *)(param_1 + 0x1b4) = param_6;
  *(long *)(param_1 + 0x1c8) = param_3;
  if ((param_6 & 0x800) != 0) {
    *(undefined8 *)(param_1 + 0x1b8) = param_4;
    *(undefined8 *)(param_1 + 0x1c0) = param_5;
  }
  if (((param_6 & 8) != 0) && (param_3 == 0)) {
    return 0x1f;
  }
  return 0;
}


// ===== 00301a00 deviceRemoveFromClientShare_IMPL =====

void deviceRemoveFromClientShare_IMPL(long param_1)

{
  if (*(long *)(param_1 + 0x1a0) != 0) {
    vmmDestroyVaspace_IMPL(*(undefined8 *)(g_pSys + 0x230));
    *(undefined8 *)(param_1 + 0x1a0) = 0;
    return;
  }
  return;
}


// ===== 00301a50 deviceGetDefaultVASpace_IMPL =====

undefined8 deviceGetDefaultVASpace_IMPL(long param_1,long *param_2)

{
  undefined8 uVar1;
  
  if (*(long *)(param_1 + 0x1a0) != 0) {
    *param_2 = *(long *)(param_1 + 0x1a0);
    return 0;
  }
  uVar1 = deviceInitClientShare_isra_0
                    (param_1,*(undefined4 *)(param_1 + 0x1a8),*(undefined4 *)(param_1 + 0x1b4));
  *param_2 = *(long *)(param_1 + 0x1a0);
  return uVar1;
}


// ===== 00301aa5 deviceSetDefaultVASpace_IMPL.cold =====

void deviceSetDefaultVASpace_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00301ab0 deviceSetDefaultVASpace_IMPL =====

undefined8 deviceSetDefaultVASpace_IMPL(long param_1,int param_2)

{
  long *plVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long local_30 [2];
  
  if (param_2 == 0) {
    return 0x1f;
  }
  if (param_1 != 0) {
    plVar1 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
    iVar3 = serverutilGetResourceRefWithParent
                      (*(undefined4 *)(*plVar1 + 0x48),(int)plVar1[2],param_2,"A RTXA6000-4C",
                       local_30);
    if (iVar3 == 0) {
      lVar4 = __nvoc_dynamicCast(*(undefined8 *)(local_30[0] + 8),__nvoc_class_def_VaSpaceApi);
      if (*(long *)(param_1 + 0x1a0) == 0) {
        *(undefined8 *)(param_1 + 0x1a0) = *(undefined8 *)(lVar4 + 0x138);
        vaspaceIncRefCnt_IMPL();
        return 0;
      }
      nvDbg_Printf("src/kernel/gpu/device_share.c",0x179,"deviceSetDefaultVASpace_IMPL",4,
                   "NVRM: device already has an Associated VASPace\n");
    }
    else {
      nvDbg_Printf("src/kernel/gpu/device_share.c",0x170,"deviceSetDefaultVASpace_IMPL",4,
                   "NVRM: Invalid object handle 0x%x pEntry %p\n",param_2,0);
    }
    return 0x33;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)invalidInstructionException();
  (*pcVar2)();
}


// ===== 00301be0 kdispComputeDpModeSettings_v02_04 =====

undefined8 kdispComputeDpModeSettings_v02_04(void)

{
  uint uVar1;
  uint uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  int iVar9;
  uint *in_RCX;
  ulong uVar10;
  ulong uVar11;
  undefined4 *in_R8;
  uint uVar12;
  uint uVar13;
  ulong local_48;
  
  if (*(char *)((long)in_RCX + 0x11) == '\0') {
    local_48 = 1;
    uVar12 = 1;
  }
  else {
    local_48 = 0x10;
    uVar12 = 0x10;
  }
  uVar5 = in_RCX[0xf];
  uVar1 = in_RCX[0xe];
  uVar2 = in_RCX[2];
  uVar13 = uVar1 - uVar5;
  *(undefined1 *)(in_R8 + 10) = *(undefined1 *)((long)in_RCX + 0xd);
  uVar8 = in_RCX[1];
  if (*(char *)((long)in_RCX + 0x11) == '\0') {
    if (uVar8 == 0) {
      if (*in_RCX == 0) goto LAB_00301f46;
      uVar11 = (ulong)*in_RCX * 0x641475e40;
    }
    else {
      uVar11 = (ulong)uVar8 * 0x47e3056b;
    }
    uVar11 = uVar11 / 1000 & 0xffffffff;
LAB_00301f3d:
    if ((int)uVar11 == 0) goto LAB_00301f46;
LAB_00301c6f:
    if (((in_RCX[2] != 0) && (*(long *)(in_RCX + 10) != 0)) ||
       ((nvDbg_Printf("src/kernel/gpu/disp/arch/v02/kern_disp_0204.c",0x55,
                      "kdispComputeDpModeSettings_v02_04",4,
                      "NVRM: One of linkFreq (%d Hz), pDpmodesetData->laneCount (%d Hz) or PClkFreq (%lld Hz) came in as zero. Report issue to client (DD)\n"
                      ,uVar11,in_RCX[2],*(long *)(in_RCX + 10)), in_RCX[2] != 0 &&
        (*(long *)(in_RCX + 10) != 0)))) goto LAB_00301cf4;
  }
  else {
    if (uVar8 == 0) {
      if (*in_RCX != 0) {
        uVar11 = (ulong)(*in_RCX * 0x18fa0b0);
        goto LAB_00301f3d;
      }
    }
    else {
      uVar10 = ((ulong)uVar8 * 0x7021039) / 100;
      uVar11 = uVar10 & 0xffffffff;
      if ((int)uVar10 != 0) goto LAB_00301c6f;
    }
LAB_00301f46:
    uVar11 = 0;
    nvDbg_Printf("src/kernel/gpu/disp/arch/v02/kern_disp_0204.c",0x55,
                 "kdispComputeDpModeSettings_v02_04",4,
                 "NVRM: One of linkFreq (%d Hz), pDpmodesetData->laneCount (%d Hz) or PClkFreq (%lld Hz) came in as zero. Report issue to client (DD)\n"
                 ,0,in_RCX[2],*(undefined8 *)(in_RCX + 10));
  }
  nvAssertFailedNoLog("linkFreqHz && pDpmodesetData->laneCount && pDpmodesetData->PClkFreqHz",
                      "src/kernel/gpu/disp/arch/v02/kern_disp_0204.c",0x5a);
LAB_00301cf4:
  *in_R8 = 0x40;
  uVar10 = ((*(long *)(in_RCX + 10) * (ulong)in_RCX[0xc] * 100000) / local_48) /
           (in_RCX[2] * uVar11 * 8);
  uVar8 = (int)(((((100000 - uVar10) * uVar10 & 0x3ffffffffffffff) << 1) / 0xc35 +
                (((ulong)in_RCX[0xc] * 100000) / (ulong)(uVar12 * uVar2 * 8)) * 2) / 100000) + 8;
  in_R8[1] = uVar8;
  if (uVar8 < 0x28) {
    if (uVar8 < 0x16) {
      in_R8[1] = 0x16;
    }
    else {
      uVar6 = (in_RCX[0xc] * uVar13) / (in_RCX[2] * uVar12 * 8);
      if (uVar6 < uVar8) {
        nvDbg_Printf("src/kernel/gpu/disp/arch/v02/kern_disp_0204.c",0x84,
                     "kdispComputeDpModeSettings_v02_04",4,
                     "NVRM: \n\t\twatermark greater than number of symbols in the line\n");
        in_R8[1] = uVar6;
      }
    }
  }
  else {
    in_R8[1] = 0x27;
  }
  if (*(char *)((long)in_RCX + 0xe) == '\0') {
    if (*(char *)((long)in_RCX + 0xd) == '\0') {
      iVar9 = uVar2 * 0x18;
    }
    else {
      iVar9 = uVar2 * 0x30;
    }
    iVar9 = iVar9 + 0x60;
    if (uVar13 % uVar2 != 0) {
      iVar9 = iVar9 + ((uVar2 - uVar13 % uVar2) * in_RCX[0xc]) / uVar12;
    }
    auVar3._8_8_ = 0;
    auVar3._0_8_ = uVar11;
    auVar4._8_8_ = 0;
    auVar4._0_8_ = (long)(int)((ulong)((long)iVar9 * 100000) / (ulong)(uVar2 * 8)) *
                   *(long *)(in_RCX + 10);
    uVar12 = SUB164((auVar4 / auVar3 >> 5 & (undefined1  [16])0x7ffffffffffffff) /
                    (undefined1  [16])0xc35,0) + 0xc;
    if (uVar13 < 0x3c) {
      nvAssertFailedNoLog("hActive >= 60","src/kernel/gpu/disp/arch/v02/kern_disp_0204.c",0xab);
    }
  }
  else {
    uVar8 = 0xa0;
    if ((uVar13 & 3) != 0) {
      uVar8 = ((4 - (uVar13 & 3)) * in_RCX[0xc]) / uVar12 + 0xb8 & 0xffffffe0;
    }
    uVar10 = (ulong)in_RCX[0xc] / (ulong)uVar12;
    uVar12 = (uint)((uVar8 + 0x1f + (int)uVar10) / uVar10);
  }
  iVar9 = uVar5 - uVar1;
  uVar5 = in_RCX[0xd] + iVar9;
  if (uVar5 < uVar12) {
    nvAssertFailedNoLog("(pDpmodesetData->SetRasterSizeWidth - hActive) >= minHBlank",
                        "src/kernel/gpu/disp/arch/v02/kern_disp_0204.c",0xaf);
    uVar5 = iVar9 + in_RCX[0xd];
  }
  iVar9 = 9;
  if (uVar2 != 1) {
    iVar9 = (uint)(uVar2 == 2) * 3 + 3;
  }
  iVar9 = ((int)(((uVar5 - uVar12) * uVar11) / *(ulong *)(in_RCX + 10)) + -4) - iVar9;
  if (iVar9 < 0) {
    iVar9 = 0;
  }
  in_R8[2] = iVar9;
  iVar9 = 0;
  if (0x27 < uVar13) {
    iVar9 = 0x27;
    if (uVar2 != 1) {
      iVar9 = (uint)(uVar2 == 2) * 9 + 0xc;
    }
    iVar9 = ((int)(((uVar13 - 0x28) * uVar11) / *(ulong *)(in_RCX + 10)) + -1) - iVar9;
    if (iVar9 < 0) {
      iVar9 = 0;
    }
  }
  in_R8[3] = iVar9;
  nvDbg_Printf("src/kernel/gpu/disp/arch/v02/kern_disp_0204.c",0xcc,
               "kdispComputeDpModeSettings_v02_04",1,"NVRM: Minimum HBlank required is %d\n");
  pcVar7 = "NV_FALSE";
  if (*(char *)((long)in_RCX + 0x11) != '\0') {
    pcVar7 = "NV_TRUE";
  }
  nvDbg_Printf("src/kernel/gpu/disp/arch/v02/kern_disp_0204.c",0xcf,
               "kdispComputeDpModeSettings_v02_04",4,
               "NVRM: \n\t\t[IN]: PixelClockHz:%lld PixelDepth:%d LinkBw:%d LaneCount:%d TuSize: %d DSCEnable:%s\n\t\t[OUT]:WaterMark:%d\n\t\t[OUT]:VBlankSymbols:%d HBlankSymbols:%d\n"
               ,*(undefined8 *)(in_RCX + 10),in_RCX[0xc],uVar11,in_RCX[2],*in_R8,pcVar7,in_R8[1],
               in_R8[3],in_R8[2]);
  return 0;
}


// ===== 00302150 kdispComputeLsrMinTimeValue_v02_07 =====

undefined8 kdispComputeLsrMinTimeValue_v02_07(void)

{
  int in_ECX;
  int *in_R8;
  
  *in_R8 = in_ECX * 1000;
  return 0;
}


// ===== 00302160 kdispGetRgScanLock_v02_01 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kdispGetRgScanLock_v02_01
                (long param_1,long param_2,uint param_3,long param_4,uint param_5,
                undefined1 *param_6,undefined4 *param_7,undefined1 *param_8,undefined4 *param_9)

{
  ulong uVar1;
  undefined1 local_38 [4];
  undefined1 local_34 [4];
  undefined1 local_30 [8];
  undefined8 local_28;
  undefined8 local_20;
  
  if (param_6 == (undefined1 *)0x0) {
    return 0x1f;
  }
  if ((((param_7 == (undefined4 *)0x0) || (param_8 == (undefined1 *)0x0)) ||
      (param_9 == (undefined4 *)0x0)) ||
     ((*(uint *)(param_2 + 0x360) <= param_3 ||
      ((*(uint *)(param_2 + 0x360) <= param_5 && (param_4 != 0)))))) {
    return 0x1f;
  }
  uVar1 = gpumgrGetGpuLockAndDrPorts(param_1,param_4,local_38,local_34);
  if ((int)uVar1 != 0) {
    return uVar1;
  }
  local_28 = 0;
  local_20 = 0;
  uVar1 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800adc,local_30,0x18);
  if ((int)uVar1 == 0) {
    *param_6 = (undefined1)local_28;
    *param_7 = local_28._4_4_;
    *param_8 = (undefined1)local_20;
    *param_9 = local_20._4_4_;
    return uVar1;
  }
  nvAssertOkFailedNoLog
            (uVar1 & 0xffffffff,
             "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_DISP_PINSETS_TO_LOCKPINS, &params, sizeof(params))"
             ,"src/kernel/gpu/disp/arch/v02/kern_disp_0207.c",100);
  return uVar1 & 0xffffffff;
}


// ===== 003022b0 _kdispHandleAwakenChnMask =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _kdispHandleAwakenChnMask
               (long param_1,long param_2,uint param_3,int param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  byte bVar5;
  ulong uVar6;
  uint uVar7;
  uint uVar8;
  uint local_44;
  long local_40 [2];
  
  local_44 = 0;
  if (param_4 == 6) {
    uVar7 = 0;
    bVar5 = 0;
    uVar8 = param_3;
    do {
      uVar3 = 1 << (bVar5 & 0x1f);
      if ((uVar3 & uVar8) != 0) {
        uVar7 = uVar7 | uVar3;
        uVar8 = uVar8 & ~uVar3;
        if (uVar8 == 0) goto code_r0x00302426;
      }
      bVar5 = bVar5 + 1;
    } while( true );
  }
  if ((param_3 & 1) != 0) {
    regWrite032(param_1 + 0x3a18,0,0,0x61185c,1,param_5);
  }
LAB_003022ed:
  uVar8 = 0;
  do {
    if ((param_3 >> (uVar8 & 0x1f) & 1) != 0) {
      iVar2 = (**(code **)(param_2 + 400))(param_2,param_4,uVar8,&local_44);
      if (iVar2 != 0) {
        return;
      }
      if (*(long *)(param_2 + 0x3a8) == 0) {
        nvAssertFailedNoLog("pKernelDisplay->pClientChannelTable != NULL",
                            "src/kernel/gpu/disp/arch/v03/kern_disp_0300.c",0x2a7);
        return;
      }
      uVar6 = (ulong)local_44;
      puVar1 = (undefined8 *)(*(long *)(param_2 + 0x3a8) + uVar6 * 0x18);
      if (*(char *)(puVar1 + 2) != '\0') {
        iVar2 = dispchnGetByHandle_IMPL(*puVar1,*(undefined4 *)(puVar1 + 1),local_40);
        if (iVar2 == 0) {
          uVar4 = 0;
          if (local_40[0] != 0) {
            uVar4 = *(undefined8 *)(local_40[0] + 0x160);
          }
          uVar4 = inotifyGetNotificationList_IMPL(uVar4);
          notifyEvents(param_1,uVar4,0,0,0,0,1);
          param_3 = param_3 & ~(1 << ((byte)uVar8 & 0x1f));
          if (param_3 == 0) {
            return;
          }
          goto LAB_00302360;
        }
        uVar6 = (ulong)local_44;
      }
      nvDbg_Printf("src/kernel/gpu/disp/arch/v03/kern_disp_0300.c",0x2c1,"_kdispHandleAwakenChnMask"
                   ,4,"NVRM: seeing an awaken in channel %d without an associated awaken event\n",
                   uVar6);
      param_3 = param_3 & ~(1 << ((byte)uVar8 & 0x1f));
      if (param_3 == 0) {
        return;
      }
    }
LAB_00302360:
    uVar8 = uVar8 + 1;
  } while( true );
code_r0x00302426:
  if (uVar7 != 0) {
    regWrite032(param_1 + 0x3a18,0,0,0x611858,uVar7,param_5);
  }
  goto LAB_003022ed;
}


// ===== 003024b0 kdispGetChannelNum_v03_00 =====

undefined8 kdispGetChannelNum_v03_00(long param_1,uint param_2,uint param_3,int *param_4)

{
  uint *puVar1;
  byte bVar2;
  
  if (param_4 == (int *)0x0) {
    return 0x1f;
  }
  puVar1 = *(uint **)(param_1 + 0x2c8);
  if (puVar1 == (uint *)0x0) {
    nvAssertFailedNoLog("pStaticInfo != NULL","src/kernel/gpu/disp/arch/v03/kern_disp_0300.c",0x3d);
    return 0x40;
  }
  bVar2 = (byte)param_3;
  if (param_2 == 5) {
    if (0x1f < param_3) {
      return 0x1f;
    }
    if ((puVar1[1] & 1 << (bVar2 & 0x1f)) == 0) {
      return 0x56;
    }
    *param_4 = param_3 + 0x21;
  }
  else if (param_2 < 6) {
    if (param_2 == 0) {
      if (7 < param_3) {
        return 0x1f;
      }
      if ((0xffffffffU >> ((~bVar2 & 0x1f) + bVar2 & 0x1f) & *puVar1 >> (bVar2 & 0x1f)) != 1) {
        return 0x56;
      }
      *param_4 = param_3 + 0x49;
      return 0;
    }
    if (param_2 != 3) {
LAB_00302518:
      nvDbg_Printf("src/kernel/gpu/disp/arch/v03/kern_disp_0300.c",0x7c,"kdispGetChannelNum_v03_00",
                   4,"NVRM: Unknown channel class %x\n",param_2);
      return 0x21;
    }
    *param_4 = 0;
  }
  else if (param_2 == 6) {
    if (0x1f < param_3) {
      return 0x1f;
    }
    if ((puVar1[1] & 1 << (bVar2 & 0x1f)) == 0) {
      return 0x56;
    }
    *param_4 = param_3 + 1;
  }
  else {
    if (param_2 != 7) goto LAB_00302518;
    *param_4 = 0x7f;
  }
  return 0;
}


// ===== 00302620 kdispGetDisplayCapsBaseAndSize_v03_00 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kdispGetDisplayCapsBaseAndSize_v03_00
               (undefined8 param_1,long param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  
  if (param_3 != (int *)0x0) {
    iVar1 = (**(code **)(param_2 + 0x188))();
    *param_3 = iVar1 + 0x640000;
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 0x1000;
    }
    return;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0x1000;
    return;
  }
  return;
}


// ===== 00302680 kdispGetDisplaySfUserBaseAndSize_v03_00 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kdispGetDisplaySfUserBaseAndSize_v03_00
               (undefined8 param_1,long param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  
  if (param_3 != (int *)0x0) {
    iVar1 = (**(code **)(param_2 + 0x188))();
    *param_3 = iVar1 + 0x6f0000;
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 0x1000;
    }
    return;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0x1000;
    return;
  }
  return;
}


// ===== 003026e0 kdispGetDisplayChannelUserBaseAndSize_v03_00 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kdispGetDisplayChannelUserBaseAndSize_v03_00
                (undefined8 param_1,long param_2,uint param_3,undefined4 param_4,int *param_5,
                undefined4 *param_6)

{
  ulong uVar1;
  int iVar2;
  uint local_2c [3];
  
  if (param_5 == (int *)0x0) {
    return 0x1f;
  }
  uVar1 = (**(code **)(param_2 + 400))(param_2,param_3,param_4,local_2c);
  if ((int)uVar1 == 0) {
    if (0x50 < local_2c[0]) {
      nvAssertFailedNoLog("dispChannelNum < NV_UDISP_FE_CHN_ASSY_BASEADR__SIZE_1",
                          "src/kernel/gpu/disp/arch/v03/kern_disp_0300.c",0xe2);
      uVar1 = uVar1 & 0xffffffff;
    }
    iVar2 = (local_2c[0] + 0x68f) * 0x1000;
    if (local_2c[0] == 0) {
      iVar2 = 0x680000;
    }
    *param_5 = iVar2;
    if (param_6 != (undefined4 *)0x0) {
      if (param_3 == 3) {
        *param_6 = 0x10000;
      }
      else {
        if (param_3 < 4) {
          if (param_3 != 0) {
            return uVar1;
          }
        }
        else if (1 < param_3 - 5) {
          return uVar1;
        }
        *param_6 = 0x1000;
      }
    }
  }
  return uVar1;
}


// ===== 003027c0 kdispSelectClass_v03_00_KERNEL =====

undefined8 kdispSelectClass_v03_00_KERNEL(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  char cVar1;
  
  cVar1 = gpuIsClassSupported_IMPL(param_1,param_3);
  if (cVar1 != '\0') {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/disp/arch/v03/kern_disp_0300.c",0x117,
               "kdispSelectClass_v03_00_KERNEL",4,"NVRM: class %x not supported\n",param_3);
  return 0x22;
}


// ===== 00302820 kdispReadRgLineCountAndFrameCount_v03_00_KERNEL =====

undefined4
kdispReadRgLineCountAndFrameCount_v03_00_KERNEL
          (long param_1,long param_2,uint param_3,uint *param_4,uint *param_5)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    nvAssertFailedNoLog("pKernelDisplay != NULL","generated/g_kern_disp_nvoc.h",0x4f9);
  }
  uVar2 = 0x1f;
  if (param_3 < *(uint *)(param_2 + 0x360)) {
    uVar1 = regRead032(param_1 + 0x3a18,0,0,param_3 * 0x800 + 0x616330,0);
    *param_4 = uVar1 & 0xffff;
    uVar2 = 0;
    *param_5 = uVar1 >> 0x10;
  }
  return uVar2;
}


// ===== 003028c0 kdispRestoreOriginalLsrMinTime_v03_00 =====

void kdispRestoreOriginalLsrMinTime_v03_00
               (long param_1,undefined8 param_2,undefined8 param_3,uint param_4)

{
  uint uVar1;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,0x61206c,0);
  regWrite032(param_1 + 0x3a18,0,0,0x61206c,param_4 & 0xffffff | uVar1 & 0xff000000,0);
  return;
}


// ===== 00302920 kdispSetSwapBarrierLsrMinTime_v03_00 =====

void kdispSetSwapBarrierLsrMinTime_v03_00
               (long param_1,undefined8 param_2,undefined8 param_3,uint *param_4,uint param_5)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = regRead032(param_1 + 0x3a18,0,0,0x61206c,0);
  *param_4 = uVar2 & 0xffffff;
  uVar1 = param_5 & 0xffffff | uVar2 & 0xff000000;
  if (param_5 == 0) {
    uVar1 = uVar2 & 0xff000000 | 0x3ff;
  }
  regWrite032(param_1 + 0x3a18,0,0,0x61206c,uVar1,0);
  return;
}


// ===== 003029a0 kheadGetLoadVCounter_v03_00 =====

void kheadGetLoadVCounter_v03_00(long param_1,long param_2)

{
  regRead032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x140) * 0x800 + 0x61611c,0);
  return;
}


// ===== 003029d0 kdispGetPBTargetAperture_v03_00 =====

char kdispGetPBTargetAperture_v03_00(undefined8 param_1,undefined8 param_2,int param_3,int param_4)

{
  if ((param_3 == 1) && (param_4 != 0)) {
    return '\x03';
  }
  return (param_3 == 1) + '\x01';
}


// ===== 00302a00 kheadReadPendingRgLineIntr_v03_00 =====

uint kheadReadPendingRgLineIntr_v03_00(long param_1,long param_2,undefined8 param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = regRead032(param_1 + 0x3a18,0,0,0x611ec0,param_3);
  bVar2 = (byte)*(int *)(param_2 + 0x140);
  bVar1 = bVar2 & 0x1f;
  if ((0xffffffffU >> ((~bVar2 & 0x1f) + bVar1 & 0x1f) & uVar3 >> bVar1) != 1) {
    return 0 >> bVar1;
  }
  uVar4 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x140) * 4 + 0x611c00,param_3);
  uVar3 = (uVar4 & 0x20) << 4;
  if ((uVar4 & 0x40) != 0) {
    uVar3 = uVar3 | 0x400;
  }
  return uVar3;
}


// ===== 00302ab0 kheadResetRgLineIntrMask_v03_00 =====

void kheadResetRgLineIntrMask_v03_00(long param_1,long param_2,ulong param_3,undefined8 param_4)

{
  uint uVar1;
  
  uVar1 = (uint)(param_3 >> 4) & 0x20;
  if ((param_3 & 0x400) != 0) {
    uVar1 = uVar1 | 0x40;
  }
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x140) * 4 + 0x611800,uVar1,param_4);
  return;
}


// ===== 00302af0 kheadReadPendingVblank_v03_00 =====

uint kheadReadPendingVblank_v03_00(long param_1,long param_2,uint *param_3,undefined8 param_4)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_3 == (uint *)0x0) {
    uVar4 = regRead032(param_1 + 0x3a18,0,0,0x611ec0,param_4);
  }
  else {
    uVar4 = *param_3;
  }
  bVar2 = (byte)*(int *)(param_2 + 0x140);
  bVar1 = bVar2 & 0x1f;
  if ((0xffffffffU >> ((~bVar2 & 0x1f) + bVar1 & 0x1f) & uVar4 >> bVar1) != 1) {
    return 0 >> bVar1;
  }
  uVar3 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x140) * 4 + 0x611c00,param_4);
  uVar4 = uVar3 >> 1;
  if (*(char *)(param_2 + 0x144) == '\x01') {
    uVar4 = uVar3 >> 2;
  }
  return uVar4 & 1;
}


// ===== 00302bc0 kheadResetPendingLastData_v03_00 =====

void kheadResetPendingLastData_v03_00(long param_1,long param_2,undefined8 param_3)

{
  regRead032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x140) * 4 + 0x611800,param_3);
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x140) * 4 + 0x611800,2,param_3);
  return;
}


// ===== 00302c40 kdispReadAwakenChannelNumMask_v03_00 =====

undefined8
kdispReadAwakenChannelNumMask_v03_00(long param_1,undefined8 param_2,uint *param_3,int param_4)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  uint uVar6;
  
  if (param_3 == (uint *)0x0) {
    nvAssertFailedNoLog("pAwakenChannelNumMask","src/kernel/gpu/disp/arch/v03/kern_disp_0300.c",
                        0x22c);
    return 0x1f;
  }
  if (param_4 == 3) {
    uVar3 = regRead032(param_1 + 0x3a18,0,0,0x61185c);
    uVar3 = uVar3 & 1;
  }
  else {
    if (param_4 != 6) {
      nvDbg_Printf("src/kernel/gpu/disp/arch/v03/kern_disp_0300.c",0x249,
                   "kdispReadAwakenChannelNumMask_v03_00",4,"NVRM: invalid channel class passed\n");
      uVar5 = 0x1f;
      uVar3 = 0;
      goto LAB_00302cf4;
    }
    uVar2 = regRead032(param_1 + 0x3a18,0,0,0x611858);
    iVar4 = 0;
    uVar3 = 0;
    do {
      bVar1 = (byte)iVar4;
      uVar6 = 0xffffffffU >> ((bVar1 ^ 0x1f) + bVar1 & 0x1f) & uVar2 >> (bVar1 & 0x1f);
      if (uVar6 == 1) {
        uVar3 = uVar6 << (bVar1 & 0x1f) | uVar3;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != 0x20);
  }
  uVar5 = 0;
LAB_00302cf4:
  *param_3 = uVar3;
  return uVar5;
}


// ===== 00302d80 kdispServiceAwakenIntr_v03_00 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kdispServiceAwakenIntr_v03_00(long param_1,long param_2,undefined8 param_3)

{
  ulong uVar1;
  int local_30;
  int local_2c [3];
  
  local_30 = 0;
  local_2c[0] = 0;
  uVar1 = regRead032(param_1 + 0x3a18,0,0,0x611c30,param_3);
  if ((uVar1 & 0x100) != 0) {
    (**(code **)(param_2 + 0x218))(param_1,param_2,&local_30,6,param_3);
    if (local_30 == 0) {
      (**(code **)(param_2 + 0x218))(param_1,param_2,local_2c,3,param_3);
      if (local_2c[0] == 0) {
        nvAssertFailedNoLog("bAwakenIntrPending","src/kernel/gpu/disp/arch/v03/kern_disp_0300.c",
                            0x2ec);
        return local_30;
      }
    }
    else {
      _kdispHandleAwakenChnMask(param_1,param_2,local_30,6,param_3);
      (**(code **)(param_2 + 0x218))(param_1,param_2,local_2c,3,param_3);
      if (local_2c[0] == 0) {
        return local_30;
      }
    }
    _kdispHandleAwakenChnMask(param_1,param_2,local_2c[0],3,param_3);
  }
  return local_30;
}


// ===== 00302ea0 _kdispGetChnStatusRegs.constprop.0 =====

undefined8 _kdispGetChnStatusRegs_constprop_0(uint param_1,uint param_2,int *param_3)

{
  if (param_1 == 5) {
    if (param_2 < 0x20) {
      *param_3 = param_2 * 4 + 0x6106e4;
      return 0;
    }
  }
  else if (param_1 < 6) {
    if (param_1 == 0) {
      if (param_2 < 8) {
        *param_3 = param_2 * 4 + 0x610784;
        return 0;
      }
    }
    else {
      if (param_1 != 3) {
        return 0x1f;
      }
      *param_3 = 0x610630;
    }
  }
  else {
    if (param_1 != 6) {
      return 0x1f;
    }
    if (param_2 < 0x20) {
      *param_3 = param_2 * 4 + 0x610664;
      return 0;
    }
  }
  return 0;
}


// ===== 00302f20 kdispIsChannelAllocatedHw_v03_00 =====

uint kdispIsChannelAllocatedHw_v03_00
               (long param_1,undefined8 param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  param_1 = param_1 + 0x3a18;
  uVar1 = (uint)param_4;
  if (param_3 == 5) {
    iVar3 = uVar1 * 4 + 0x610564;
LAB_00302f74:
    iVar2 = 0;
    if (uVar1 < 0x20) {
      iVar2 = iVar3;
    }
    uVar1 = regRead032(param_1,0,0,iVar2,0);
    return uVar1 & 1;
  }
  if (param_3 < 6) {
    if (param_3 == 0) {
      iVar3 = 0;
      if (uVar1 < 8) {
        iVar3 = uVar1 * 4 + 0x610604;
      }
      uVar1 = regRead032(param_1,0,0,iVar3,0);
      return uVar1 & 1;
    }
    param_5 = 0;
    param_4 = 0x6104e0;
    if (param_3 == 3) {
      uVar1 = regRead032(param_1,0,0);
      return uVar1 & 1;
    }
  }
  else if (param_3 == 6) {
    iVar3 = uVar1 * 4 + 0x6104e4;
    goto LAB_00302f74;
  }
  nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/disp/arch/v03/kern_disp_channel_0300.c",0x95
                      ,param_4,param_5);
  regRead032(param_1,0,0,0,0);
  return 0;
}


// ===== 00303010 kdispSetChannelTrashAndAbortAccel_v03_00 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kdispSetChannelTrashAndAbortAccel_v03_00
               (long param_1,long param_2,uint param_3,uint param_4,char param_5)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if (param_3 == 5) {
    iVar4 = 0;
    if (param_4 < 0x20) {
      iVar4 = param_4 * 4 + 0x610564;
    }
    uVar2 = regRead032(param_1 + 0x3a18,0,0,iVar4,0);
    uVar3 = uVar2 & 0xffff97ff | 0x10;
    if (param_5 != '\0') {
      uVar3 = uVar2 & 0xffff97ff | 0x4010;
    }
    regWrite032(param_1 + 0x3a18,0,0,iVar4,uVar3,0);
    return;
  }
  if (5 < param_3) {
    if (param_3 == 6) {
      lVar1 = param_1 + 0x3a18;
      iVar4 = 0;
      if (param_4 < 0x20) {
        iVar4 = param_4 * 4 + 0x6104e4;
      }
      uVar3 = regRead032(lVar1,0,0,iVar4,0);
      if (param_5 == '\0') {
        regWrite032(lVar1,0,0,iVar4,uVar3 & 0xffff903f | 0x10,0);
        return;
      }
      regWrite032(lVar1,0,0,iVar4,uVar3 & 0xffff903f | 0x4010,0);
      (**(code **)(param_2 + 0x268))(param_1,param_2,param_4,6,iVar4);
      return;
    }
LAB_00303140:
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/disp/arch/v03/kern_disp_channel_0300.c",
                        0xc1);
    return;
  }
  if (param_3 == 0) {
    iVar4 = 0;
    if (param_4 < 8) {
      iVar4 = param_4 * 4 + 0x610604;
    }
    uVar2 = regRead032(param_1 + 0x3a18,0,0,iVar4,0);
    uVar3 = uVar2 & 0xffff97ef | 0x4000;
    if (param_5 == '\0') {
      uVar3 = uVar2 & 0xffff97ef;
    }
  }
  else {
    if (param_3 != 3) goto LAB_00303140;
    uVar2 = regRead032(param_1 + 0x3a18,0,0,0x6104e0,0);
    iVar4 = 0x6104e0;
    uVar3 = uVar2 & 0xffff15ff | 0x10;
    if (param_5 != '\0') {
      uVar3 = uVar2 & 0xffff15ff | 0x4010;
    }
  }
  regWrite032(param_1 + 0x3a18,0,0,iVar4,uVar3,0);
  return;
}


// ===== 00303240 kdispIsChannelIdle_v03_00 =====

undefined8
kdispIsChannelIdle_v03_00(long param_1,undefined8 param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_54;
  undefined1 local_50 [32];
  
  local_54 = 0;
  iVar2 = _kdispGetChnStatusRegs_constprop_0(param_3,param_4,&local_54);
  if (iVar2 == 0) {
    timeoutSet(param_1 + 0x1af0,local_50,10,0);
    uVar1 = local_54;
    uVar3 = regRead032(param_1 + 0x3a18,0,0,local_54,0);
    if (param_3 < 7) {
      while( true ) {
        if (param_3 < 5) {
          if (param_3 == 0) {
            uVar4 = 0x10;
            uVar3 = uVar3 >> 0x10 & 7;
          }
          else {
            if (param_3 != 3) {
              return 0;
            }
            uVar4 = 0x800;
            uVar3 = uVar3 >> 0x10 & 0x1f;
          }
        }
        else {
          uVar4 = 0x10;
          uVar3 = uVar3 >> 0x10 & 0xf;
        }
        iVar2 = timeoutCheck(param_1 + 0x1af0,local_50,0x13b);
        if (iVar2 == 0x65) break;
        osSpinLoop();
        if ((uVar4 >> uVar3 & 1) != 0) {
          return 1;
        }
        uVar3 = regRead032(param_1 + 0x3a18,0,0,uVar1,0);
      }
      nvDbg_Printf("src/kernel/gpu/disp/arch/v03/kern_disp_channel_0300.c",0x13d,
                   "kdispIsChannelIdle_v03_00",4,"NVRM: timeout! current Channel state = 0x%x\n",
                   uVar3);
    }
  }
  else {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/disp/arch/v03/kern_disp_channel_0300.c",
                        0x118);
  }
  return 0;
}


// ===== 003033e0 kdispApplyChannelConnectDisconnect_v03_00 =====

void kdispApplyChannelConnectDisconnect_v03_00
               (long param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  long lVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 local_54;
  undefined1 local_50 [32];
  
  lVar1 = param_1 + 0x3a18;
  uVar3 = regRead032(lVar1,0,0,param_5,0);
  local_54 = 0;
  iVar4 = _kdispGetChnStatusRegs_constprop_0(param_4,param_3,&local_54);
  if (iVar4 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/disp/arch/v03/kern_disp_channel_0300.c",
                        0x15a);
  }
  param_1 = param_1 + 0x1af0;
  timeoutSet(param_1,local_50,10,0);
  uVar2 = local_54;
  do {
    iVar5 = regRead032(lVar1,0,0,uVar2,0);
    if (-1 < iVar5) goto LAB_0030349e;
    iVar5 = timeoutCheck(param_1,local_50,0x167);
    if (iVar5 == 0x65) {
      iVar4 = 0x65;
      nvDbg_Printf("src/kernel/gpu/disp/arch/v03/kern_disp_channel_0300.c",0x169,
                   "kdispApplyChannelConnectDisconnect_v03_00",4,
                   "NVRM: timeout waiting for METHOD_EXEC to IDLE\n");
      goto LAB_0030349e;
    }
    osSpinLoop();
  } while (iVar4 == 0);
  iVar4 = 0x1f;
LAB_0030349e:
  regWrite032(lVar1,0,0,param_5,uVar3 & 0xfffffffd,0);
  timeoutSet(param_1,local_50,10,0);
  do {
    uVar6 = regRead032(lVar1,0,0,uVar2,0);
    if ((uVar6 & 0xf0000) == 0x10000) break;
    iVar5 = timeoutCheck(param_1,local_50,0x181);
    if (iVar5 == 0x65) {
      nvDbg_Printf("src/kernel/gpu/disp/arch/v03/kern_disp_channel_0300.c",0x183,
                   "kdispApplyChannelConnectDisconnect_v03_00",4,
                   "NVRM: timeout waiting for channel state to UNCONNECTED\n");
      break;
    }
    osSpinLoop();
  } while (iVar4 == 0);
  regWrite032(lVar1,0,0,param_5,uVar3 | 2,0);
  return;
}


// ===== 003035e0 kdispGetVgaWorkspaceBase_v04_00 =====

bool kdispGetVgaWorkspaceBase_v04_00(long param_1,undefined8 param_2,ulong *param_3)

{
  ulong uVar1;
  bool bVar2;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,0x625f04,0);
  bVar2 = (uVar1 & 8) != 0;
  if (bVar2) {
    *param_3 = (ulong)(uint)((int)(uVar1 >> 8) << 0x10);
  }
  return bVar2;
}


// ===== 00303630 kdispDetectSliLink_v04_00 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kdispDetectSliLink_v04_00(long param_1,long param_2,long param_3,uint param_4,uint param_5)

{
  long lVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  byte local_71;
  uint local_70;
  uint uStack_6c;
  int local_50;
  int local_4c;
  uint local_48;
  uint uStack_44;
  uint uStack_40;
  uint local_3c;
  
  if (*(long *)(param_2 + 0x1b80) != param_1) {
    nvAssertFailedNoLog("pKernelDisplay == GPU_GET_KERNEL_DISPLAY(pParentGpu)",
                        "src/kernel/gpu/disp/arch/v04/kern_disp_0400.c",0xab);
  }
  if (((param_4 == 0) || (param_5 == 0)) ||
     ((param_4 - 1 & param_4) != 0 || (param_5 - 1 & param_5) != 0)) {
    return 0x1f;
  }
  local_50 = 0;
  local_4c = 0;
  if (((*(char *)(param_2 + 0x909) != '\0') &&
      (cVar7 = rmDeviceGpuLockIsOwner(*(undefined4 *)(param_2 + 0x7a4)), cVar7 == '\0')) &&
     (iVar8 = rmGpuGroupLockAcquire(*(undefined4 *)(param_2 + 0x7a4),0,0,0x8002,&local_50),
     iVar8 != 0)) {
    nvAssertOkFailedNoLog
              (iVar8,
               "rmGpuGroupLockAcquire(pParentGpu->gpuInstance, GPU_LOCK_GRP_SUBDEVICE, GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_RPC, &parentGpuLockMask)"
               ,"src/kernel/gpu/disp/arch/v04/kern_disp_0400.c",0xc0);
    goto LAB_0030375d;
  }
  if (((*(char *)(param_3 + 0x909) != '\0') &&
      (cVar7 = rmDeviceGpuLockIsOwner(*(undefined4 *)(param_3 + 0x7a4)), cVar7 == '\0')) &&
     (iVar8 = rmGpuGroupLockAcquire(*(undefined4 *)(param_3 + 0x7a4),0,0,0x8002,&local_4c),
     iVar8 != 0)) {
    nvAssertOkFailedNoLog
              (iVar8,
               "rmGpuGroupLockAcquire(pChildGpu->gpuInstance, GPU_LOCK_GRP_SUBDEVICE, GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_RPC, &childGpuLockMask)"
               ,"src/kernel/gpu/disp/arch/v04/kern_disp_0400.c",199);
    goto LAB_0030375d;
  }
  lVar1 = param_2 + 0x3b58;
  uStack_44 = 0;
  uStack_40 = 0;
  local_3c = 0;
  local_48 = param_4;
  iVar8 = (**(code **)(param_2 + 0x3b90))
                    (lVar1,*(undefined4 *)(param_2 + 0x3b34),*(undefined4 *)(param_2 + 0x3b3c),
                     0x20800ade,&local_48,0x10);
  uVar6 = local_3c;
  uVar4 = uStack_40;
  uVar3 = uStack_44;
  if (iVar8 != 0) {
    nvCheckOkFailedNoLog
              (1,iVar8,
               "setSliLinkGpioSwControl(pParentGpu, parentPinSet, &parentGpioFunction, &parentGpioPin, &parentGpioDirection)"
               ,"src/kernel/gpu/disp/arch/v04/kern_disp_0400.c",0xce);
    goto LAB_0030375d;
  }
  lVar2 = param_3 + 0x3b58;
  uStack_44 = 0;
  uStack_40 = 0;
  local_3c = 0;
  local_48 = param_5;
  iVar8 = (**(code **)(param_3 + 0x3b90))
                    (lVar2,*(undefined4 *)(param_3 + 0x3b34),*(undefined4 *)(param_3 + 0x3b3c),
                     0x20800ade,&local_48,0x10);
  uVar5 = uStack_40;
  if (iVar8 == 0) {
    local_70 = uStack_44;
    uStack_6c = uStack_40;
    local_48 = uVar4;
    uStack_44 = 0;
    local_71 = (byte)local_3c;
    iVar8 = (**(code **)(param_2 + 0x3b90))
                      (lVar1,*(undefined4 *)(param_2 + 0x3b34),*(undefined4 *)(param_2 + 0x3b3c),
                       0x20802300,&local_48,8);
    if (iVar8 == 0) {
      local_48 = uVar5;
      uStack_44 = 1;
      iVar8 = (**(code **)(param_3 + 0x3b90))
                        (lVar2,*(undefined4 *)(param_3 + 0x3b34),*(undefined4 *)(param_3 + 0x3b3c),
                         0x20802300,&local_48,8);
      if (iVar8 == 0) {
        local_48 = uVar4;
        uStack_44 = 1;
        iVar8 = (**(code **)(param_2 + 0x3b90))
                          (lVar1,*(undefined4 *)(param_2 + 0x3b34),*(undefined4 *)(param_2 + 0x3b3c)
                           ,0x20802301,&local_48,8);
        if (iVar8 == 0) {
          uStack_44 = 0;
          local_48 = uVar5;
          iVar8 = (**(code **)(param_3 + 0x3b90))
                            (lVar2,*(undefined4 *)(param_3 + 0x3b34),
                             *(undefined4 *)(param_3 + 0x3b3c),0x20802302,&local_48,8);
          if (iVar8 == 0) {
            if (uStack_44 == 1) {
              local_48 = uVar4;
              uStack_44 = 0;
              iVar8 = (**(code **)(param_2 + 0x3b90))
                                (lVar1,*(undefined4 *)(param_2 + 0x3b34),
                                 *(undefined4 *)(param_2 + 0x3b3c),0x20802301,&local_48,8);
              if (iVar8 == 0) {
                uStack_44 = 0;
                local_48 = uVar5;
                iVar8 = (**(code **)(param_3 + 0x3b90))
                                  (lVar2,*(undefined4 *)(param_3 + 0x3b34),
                                   *(undefined4 *)(param_3 + 0x3b3c),0x20802302,&local_48,8);
                if (iVar8 == 0) {
                  if (uStack_44 == 0) {
                    local_48 = uVar4;
                    uStack_44 = 1;
                    iVar8 = (**(code **)(param_2 + 0x3b90))
                                      (lVar1,*(undefined4 *)(param_2 + 0x3b34),
                                       *(undefined4 *)(param_2 + 0x3b3c),0x20802300,&local_48,8);
                    if (iVar8 == 0) {
                      uStack_44 = 0;
                      local_48 = uVar5;
                      iVar8 = (**(code **)(param_3 + 0x3b90))
                                        (lVar2,*(undefined4 *)(param_3 + 0x3b34),
                                         *(undefined4 *)(param_3 + 0x3b3c),0x20802300,&local_48,8);
                      if (iVar8 == 0) {
                        local_48 = uVar5;
                        uStack_44 = 1;
                        iVar8 = (**(code **)(param_3 + 0x3b90))
                                          (lVar2,*(undefined4 *)(param_3 + 0x3b34),
                                           *(undefined4 *)(param_3 + 0x3b3c),0x20802301,&local_48,8)
                        ;
                        if (iVar8 == 0) {
                          uStack_44 = 0;
                          local_48 = uVar4;
                          iVar8 = (**(code **)(param_2 + 0x3b90))
                                            (lVar1,*(undefined4 *)(param_2 + 0x3b34),
                                             *(undefined4 *)(param_2 + 0x3b3c),0x20802302,&local_48,
                                             8);
                          if (iVar8 == 0) {
                            if (uStack_44 == 1) {
                              local_48 = uVar5;
                              uStack_44 = 0;
                              iVar8 = (**(code **)(param_3 + 0x3b90))
                                                (lVar2,*(undefined4 *)(param_3 + 0x3b34),
                                                 *(undefined4 *)(param_3 + 0x3b3c),0x20802301,
                                                 &local_48,8);
                              if (iVar8 == 0) {
                                uStack_44 = 0;
                                local_48 = uVar4;
                                iVar9 = (**(code **)(param_2 + 0x3b90))
                                                  (lVar1,*(undefined4 *)(param_2 + 0x3b34),
                                                   *(undefined4 *)(param_2 + 0x3b3c),0x20802302,
                                                   &local_48,8);
                                if (iVar9 == 0) {
                                  iVar8 = 0;
                                  if (uStack_44 != 0) {
                                    nvAssertFailedNoLog("value == 0",
                                                                                                                
                                                  "src/kernel/gpu/disp/arch/v04/kern_disp_0400.c",
                                                  0xf0);
                                    iVar8 = iVar9;
                                  }
                                }
                                else {
                                  nvAssertOkFailedNoLog
                                            (iVar9,
                                             "readGpioInput(pParentGpu, parentGpioPin, &value)",
                                             "src/kernel/gpu/disp/arch/v04/kern_disp_0400.c",0xef);
                                  iVar8 = iVar9;
                                }
                              }
                              else {
                                nvAssertOkFailedNoLog
                                          (iVar8,"programGpioOutput(pChildGpu, childGpioPin, 0)",
                                           "src/kernel/gpu/disp/arch/v04/kern_disp_0400.c",0xee);
                              }
                            }
                            else {
                              nvAssertFailedNoLog("value == 1",
                                                  "src/kernel/gpu/disp/arch/v04/kern_disp_0400.c",
                                                  0xec);
                            }
                          }
                          else {
                            nvAssertOkFailedNoLog
                                      (iVar8,"readGpioInput(pParentGpu, parentGpioPin, &value)",
                                       "src/kernel/gpu/disp/arch/v04/kern_disp_0400.c",0xeb);
                          }
                        }
                        else {
                          nvAssertOkFailedNoLog
                                    (iVar8,"programGpioOutput(pChildGpu, childGpioPin, 1)",
                                     "src/kernel/gpu/disp/arch/v04/kern_disp_0400.c",0xea);
                        }
                      }
                      else {
                        nvAssertOkFailedNoLog
                                  (iVar8,"programGpioDirection(pChildGpu, childGpioPin, NV_FALSE)",
                                   "src/kernel/gpu/disp/arch/v04/kern_disp_0400.c",0xe7);
                      }
                    }
                    else {
                      nvAssertOkFailedNoLog
                                (iVar8,"programGpioDirection(pParentGpu, parentGpioPin, NV_TRUE)",
                                 "src/kernel/gpu/disp/arch/v04/kern_disp_0400.c",0xe6);
                    }
                  }
                  else {
                    nvAssertFailedNoLog("value == 0","src/kernel/gpu/disp/arch/v04/kern_disp_0400.c"
                                        ,0xe3);
                  }
                }
                else {
                  nvAssertOkFailedNoLog
                            (iVar8,"readGpioInput(pChildGpu, childGpioPin, &value)",
                             "src/kernel/gpu/disp/arch/v04/kern_disp_0400.c",0xe2);
                }
              }
              else {
                nvAssertOkFailedNoLog
                          (iVar8,"programGpioOutput(pParentGpu, parentGpioPin, 0)",
                           "src/kernel/gpu/disp/arch/v04/kern_disp_0400.c",0xe1);
              }
            }
            else {
              nvAssertFailedNoLog("value == 1","src/kernel/gpu/disp/arch/v04/kern_disp_0400.c",0xdf)
              ;
            }
          }
          else {
            nvAssertOkFailedNoLog
                      (iVar8,"readGpioInput(pChildGpu, childGpioPin, &value)",
                       "src/kernel/gpu/disp/arch/v04/kern_disp_0400.c",0xde);
          }
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar8,"programGpioOutput(pParentGpu, parentGpioPin, 1)",
                     "src/kernel/gpu/disp/arch/v04/kern_disp_0400.c",0xdd);
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar8,"programGpioDirection(pChildGpu, childGpioPin, NV_TRUE)",
                   "src/kernel/gpu/disp/arch/v04/kern_disp_0400.c",0xda);
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar8,"programGpioDirection(pParentGpu, parentGpioPin, NV_FALSE)",
                 "src/kernel/gpu/disp/arch/v04/kern_disp_0400.c",0xd9);
    }
    if (uVar4 != 0xff) goto LAB_00303847;
  }
  else {
    nvCheckOkFailedNoLog
              (1,iVar8,
               "setSliLinkGpioSwControl(pChildGpu, childPinSet, &childGpioFunction, &childGpioPin, &childGpioDirection)"
               ,"src/kernel/gpu/disp/arch/v04/kern_disp_0400.c",0xd2);
    if (uVar4 == 0xff) goto LAB_0030375d;
    local_71 = 0;
    local_70 = 0;
    uStack_6c = 0xff;
LAB_00303847:
    local_48 = uVar4;
    uStack_44 = uVar6 & 0xff;
    iVar9 = (**(code **)(param_2 + 0x3b90))
                      (lVar1,*(undefined4 *)(param_2 + 0x3b34),*(undefined4 *)(param_2 + 0x3b3c),
                       0x20802300,&local_48,8);
    if (iVar9 != 0) {
      nvAssertOkFailedNoLog
                (iVar9,"programGpioDirection(pParentGpu, parentGpioPin, parentGpioDirection)",
                 "src/kernel/gpu/disp/arch/v04/kern_disp_0400.c",0xf9);
    }
    local_48 = uVar3;
    uStack_44 = uVar4;
    iVar9 = (**(code **)(param_2 + 0x3b90))
                      (lVar1,*(undefined4 *)(param_2 + 0x3b34),*(undefined4 *)(param_2 + 0x3b3c),
                       0x20802303,&local_48,8);
    if (iVar9 != 0) {
      nvAssertOkFailedNoLog
                (iVar9,"activateHwFunction(pParentGpu, parentGpioPin, parentGpioFunction)",
                 "src/kernel/gpu/disp/arch/v04/kern_disp_0400.c",0xfb);
    }
  }
  if (uStack_6c != 0xff) {
    uStack_44 = (uint)local_71;
    local_48 = uStack_6c;
    iVar9 = (**(code **)(param_3 + 0x3b90))
                      (lVar2,*(undefined4 *)(param_3 + 0x3b34),*(undefined4 *)(param_3 + 0x3b3c),
                       0x20802300,&local_48,8);
    if (iVar9 != 0) {
      nvAssertOkFailedNoLog
                (iVar9,"programGpioDirection(pChildGpu, childGpioPin, childGpioDirection)",
                 "src/kernel/gpu/disp/arch/v04/kern_disp_0400.c",0x100);
    }
    local_48 = local_70;
    uStack_44 = uStack_6c;
    iVar9 = (**(code **)(param_3 + 0x3b90))
                      (lVar2,*(undefined4 *)(param_3 + 0x3b34),*(undefined4 *)(param_3 + 0x3b3c),
                       0x20802303,&local_48,8);
    if (iVar9 != 0) {
      nvAssertOkFailedNoLog
                (iVar9,"activateHwFunction(pChildGpu, childGpioPin, childGpioFunction)",
                 "src/kernel/gpu/disp/arch/v04/kern_disp_0400.c",0x102);
    }
  }
LAB_0030375d:
  if (local_50 != 0) {
    rmGpuGroupLockRelease(local_50,0);
  }
  if (local_4c != 0) {
    rmGpuGroupLockRelease(local_4c,0);
  }
  return iVar8;
}


// ===== 00304020 kdispReadPendingWinSemIntr_v04_01 =====

uint kdispReadPendingWinSemIntr_v04_01
               (long param_1,undefined8 param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  
  if (param_4 != (uint *)0x0) {
    return *param_4 >> 9 & 1;
  }
  uVar1 = regRead032(param_1 + 0x3a18,0,0,0x611c30,param_3);
  return uVar1 >> 9 & 1;
}


// ===== 00304070 __pfx_kdispHandleWinSemEvt_v04_01 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong __pfx_kdispHandleWinSemEvt_v04_01(long param_1,long param_2,undefined8 param_3)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  uint uVar6;
  uint uVar7;
  uint auStack_3c [3];
  
  auStack_3c[0] = 0;
  uVar5 = (**(code **)(param_2 + 0x230))();
  if (((char)uVar5 != '\0') &&
     (uVar5 = regRead032(param_1 + 0x3a18,0,0,0x611a00,param_3), (uVar5 & 0x4000000) != 0)) {
    uVar3 = regRead032(param_1 + 0x3a18,0,0,0x611868,param_3);
    bVar2 = false;
    iVar4 = 0;
    uVar7 = auStack_3c[0];
    do {
      bVar1 = (byte)iVar4;
      uVar6 = 0xffffffffU >> ((bVar1 ^ 0x1f) + bVar1 & 0x1f) & uVar3 >> (bVar1 & 0x1f);
      if (uVar6 == 1) {
        bVar2 = true;
        uVar7 = uVar6 << (bVar1 & 0x1f) | uVar7;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != 0x20);
    if (bVar2) {
      auStack_3c[0] = uVar7;
    }
    osDispService(0x611868,auStack_3c[0]);
    regWrite032(param_1 + 0x3a18,0,0,0x611868,auStack_3c[0],param_3);
    kdispNotifyEvent_IMPL(param_1,param_2,2,auStack_3c,4,0);
    return 0;
  }
  return uVar5;
}


// ===== 00304080 kdispHandleWinSemEvt_v04_01 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kdispHandleWinSemEvt_v04_01(long param_1,long param_2,undefined8 param_3)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  uint uVar6;
  uint uVar7;
  uint local_3c [3];
  
  local_3c[0] = 0;
  uVar5 = (**(code **)(param_2 + 0x230))();
  if (((char)uVar5 != '\0') &&
     (uVar5 = regRead032(param_1 + 0x3a18,0,0,0x611a00,param_3), (uVar5 & 0x4000000) != 0)) {
    uVar3 = regRead032(param_1 + 0x3a18,0,0,0x611868,param_3);
    bVar2 = false;
    iVar4 = 0;
    uVar7 = local_3c[0];
    do {
      bVar1 = (byte)iVar4;
      uVar6 = 0xffffffffU >> ((bVar1 ^ 0x1f) + bVar1 & 0x1f) & uVar3 >> (bVar1 & 0x1f);
      if (uVar6 == 1) {
        bVar2 = true;
        uVar7 = uVar6 << (bVar1 & 0x1f) | uVar7;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != 0x20);
    if (bVar2) {
      local_3c[0] = uVar7;
    }
    osDispService(0x611868,local_3c[0]);
    regWrite032(param_1 + 0x3a18,0,0,0x611868,local_3c[0],param_3);
    kdispNotifyEvent_IMPL(param_1,param_2,2,local_3c,4,0);
    return 0;
  }
  return uVar5;
}


// ===== 003041f0 kdispGetBaseOffset_v04_02 =====

undefined8 kdispGetBaseOffset_v04_02(void)

{
  return 0xff9f0000;
}


// ===== 00304200 kdispArbAndAllocDisplayBandwidth_v04_02 =====

int kdispArbAndAllocDisplayBandwidth_v04_02
              (long param_1,undefined8 param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  ulong uVar6;
  undefined4 uVar7;
  
  if (param_3 == 0) {
    nvDbg_Printf("src/kernel/gpu/disp/arch/v04/kern_disp_0402.c",0x59,
                 "kdispArbAndAllocDisplayBandwidth_v04_02",1,
                 "NVRM: %s requests ISO BW = %u KBPS, floor BW = %u KBPS\n",&DAT_00d0cc3a,param_4);
    if (DAT_0054d308 < (uint)param_4) {
      nvAssertFailedNoLog("minRequiredIsoBandwidthKBPS <= clientBwValues[DISPLAY_ICC_BW_CLIENT_EXT].minRequiredIsoBandwidthKBPS"
                          ,"src/kernel/gpu/disp/arch/v04/kern_disp_0402.c",0x6f);
    }
  }
  else {
    if (param_3 != 1) {
      nvDbg_Printf("src/kernel/gpu/disp/arch/v04/kern_disp_0402.c",0x59,
                   "kdispArbAndAllocDisplayBandwidth_v04_02",1,
                   "NVRM: %s requests ISO BW = %u KBPS, floor BW = %u KBPS\n","Unknown client",
                   param_4,param_5);
      nvDbg_Printf("src/kernel/gpu/disp/arch/v04/kern_disp_0402.c",0x61,
                   "kdispArbAndAllocDisplayBandwidth_v04_02",4,"NVRM: Bad iccBwClient value (%u)\n",
                   param_3);
      nvAssertFailedNoLog("NV_FALSE","src/kernel/gpu/disp/arch/v04/kern_disp_0402.c",0x62);
      return 0x3b;
    }
    nvDbg_Printf("src/kernel/gpu/disp/arch/v04/kern_disp_0402.c",0x59,
                 "kdispArbAndAllocDisplayBandwidth_v04_02",1,
                 "NVRM: %s requests ISO BW = %u KBPS, floor BW = %u KBPS\n","Ext client",param_4,
                 param_5);
  }
  (&DAT_0054d304)[(ulong)param_3 * 2] = (int)param_5;
  uVar2 = DAT_0054d30c;
  (&clientBwValues_2)[(ulong)param_3 * 2] = (uint)param_4;
  uVar1 = DAT_0054d308;
  if (DAT_0054d308 < clientBwValues_2) {
    uVar1 = clientBwValues_2;
  }
  if (uVar2 < DAT_0054d304) {
    uVar2 = DAT_0054d304;
  }
  uVar5 = (ulong)uVar2;
  if ((uVar1 != oldArbBwValues_1) || (iVar3 = 0, uVar2 != DAT_0054d2fc)) {
    uVar6 = uVar5;
    nvDbg_Printf("src/kernel/gpu/disp/arch/v04/kern_disp_0402.c",0x84,
                 "kdispArbAndAllocDisplayBandwidth_v04_02",1,
                 "NVRM: Sending request to icc_set_bw: ISO BW = %u KBPS, floor BW = %u KBPS\n",uVar1
                 ,uVar5);
    uVar7 = (undefined4)(uVar6 >> 0x20);
    iVar3 = osTegraAllocateDisplayBandwidth(*(undefined8 *)(param_1 + 0x4e0),uVar1,uVar5);
    uVar4 = nvstatusToString(iVar3);
    nvDbg_Printf("src/kernel/gpu/disp/arch/v04/kern_disp_0402.c",0x8b,
                 "kdispArbAndAllocDisplayBandwidth_v04_02",1,
                 "NVRM: Allocation request returns:  %s (0x%08X)\n",uVar4,CONCAT44(uVar7,iVar3));
    if (iVar3 == 0) {
      oldArbBwValues_1 = uVar1;
      DAT_0054d2fc = uVar2;
    }
  }
  return iVar3;
}


// ===== 00304440 kdispGetUefiDisplayBandwidth_v04_02 =====

int kdispGetUefiDisplayBandwidth_v04_02
              (long param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  
  iVar1 = osTegraSocGetImpUefiData(*(undefined8 *)(param_1 + 0x4e0),param_3,param_4);
  if (iVar1 == 0) {
    nvDbg_Printf("src/kernel/gpu/disp/arch/v04/kern_disp_0402.c",0xaf,
                 "kdispGetUefiDisplayBandwidth_v04_02",1,
                 "NVRM: UEFI has set ISO BW = %u KBPS, floor BW = %u KBPS",*param_3,*param_4);
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/disp/arch/v04/kern_disp_0402.c",0xb3,
               "kdispGetUefiDisplayBandwidth_v04_02",4,
               "NVRM: Unable to retrieve UEFI set ISO BW and floor BW");
  return iVar1;
}


// ===== 003044f0 kheadVsyncNotificationOverRgVblankIntr_v04_04 =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

void kheadVsyncNotificationOverRgVblankIntr_v04_04(undefined8 param_1,long param_2)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_2 + 0x148);
  if (((*(char *)(param_2 + 0x144) != '\0') && (puVar1 != (undefined8 *)0x0)) &&
     ((code *)*puVar1 != (code *)0x0)) {
    (*(code *)*puVar1)(param_1,puVar1[1],*(undefined4 *)((long)puVar1 + 0x14),
                       *(undefined4 *)(puVar1 + 3),*(undefined4 *)(puVar1 + 7));
    return;
  }
  return;
}


// ===== 00304530 _getDpAudioSymbolMST =====

ulong _getDpAudioSymbolMST(int param_1,uint param_2,char param_3)

{
  long lVar1;
  int iVar2;
  
  if (param_1 == 2) {
    param_2 = param_2 >> 1;
    lVar1 = 1;
  }
  else {
    lVar1 = 2;
  }
  if (param_3 == '\0') {
    iVar2 = (int)(lVar1 * 5 + 5U >> 2) + 2;
  }
  else {
    iVar2 = (int)lVar1 * 5 + 4;
  }
  return (ulong)(((param_2 / 1000 + 1) * (param_2 % 1000) +
                 (1000 - param_2 % 1000) * (param_2 / 1000)) * iVar2 + 999) / 1000;
}


// ===== 003045d0 kheadGetLoadVCounter_v05_01 =====

void kheadGetLoadVCounter_v05_01(long param_1,long param_2)

{
  regRead032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x140) * 0x800 + 0x616320,0);
  return;
}


// ===== 00304600 kdispGetPBTargetAperture_v05_01 =====

bool kdispGetPBTargetAperture_v05_01(long param_1)

{
  return *(char *)(param_1 + 0x4b3) != '\0';
}


// ===== 00304620 kdispIntrRetrigger_v05_01 =====

void kdispIntrRetrigger_v05_01(long param_1,undefined8 param_2,int param_3,undefined8 param_4)

{
  regWrite032(param_1 + 0x3a18,0,0,param_3 * 4 + 0x611f30,1,param_4);
  return;
}


// ===== 00304650 kdispComputeDpModeSettings_v05_01 =====

undefined8
kdispComputeDpModeSettings_v05_01
          (long param_1,undefined8 param_2,int param_3,uint *param_4,undefined4 *param_5)

{
  undefined1 uVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 uVar4;
  ulong uVar5;
  ulong uVar6;
  int iVar7;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  long lVar13;
  uint uVar14;
  uint uVar15;
  long lVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  char cVar20;
  ulong uVar21;
  undefined4 *puVar22;
  uint uVar23;
  ulong uVar24;
  uint local_58;
  int local_50;
  uint uVar8;
  
  cVar20 = *(char *)((long)param_4 + 0x11);
  uVar17 = param_4[0xe] - param_4[0xf];
  uVar23 = (param_4[0xf] + param_4[0xd]) - param_4[0xe];
  uVar1 = *(undefined1 *)((long)param_4 + 0xd);
  iVar18 = (-(uint)((char)param_4[3] == '\0') & 0xffffffe8) + 0x20;
  if (param_4[1] == 0) {
    uVar24 = (ulong)*param_4 * 270000000;
    *(undefined1 *)(param_5 + 10) = uVar1;
    uVar12 = (-(uint)(cVar20 == '\0') & 0xfffffff1) + 0x10;
    if (uVar24 != 0) {
      uVar10 = param_4[2];
      goto joined_r0x00304bef;
    }
LAB_003046e0:
    nvAssertFailedNoLog("linkFreqHz && pDpModesetData->laneCount && pDpModesetData->PClkFreqHz",
                        "src/kernel/gpu/disp/arch/v05/kern_disp_0501.c",0x1d9);
  }
  else {
    uVar24 = (ulong)param_4[1] * 10000000;
    if (cVar20 == '\0') {
      *(undefined1 *)(param_5 + 10) = uVar1;
      uVar10 = param_4[2];
      uVar12 = 1;
    }
    else {
      uVar12 = 0x10;
      *(undefined1 *)(param_5 + 10) = uVar1;
      uVar10 = param_4[2];
    }
joined_r0x00304bef:
    if ((uVar10 == 0) || (*(long *)(param_4 + 10) == 0)) goto LAB_003046e0;
  }
  *param_5 = 0x40;
  param_5[3] = 0;
  *(undefined8 *)(param_5 + 5) = 0;
  if (*(char *)((long)param_4 + 0x11) == '\0') {
    uVar3 = 0;
    uVar10 = 0;
    uVar15 = 0;
  }
  else {
    uVar15 = param_4[5];
    if (param_4[5] == 0) {
      uVar15 = 4;
    }
    uVar3 = ((uVar15 - 1) + param_4[0xd]) / uVar15;
    uVar10 = ((uVar12 * 8 - 1) + uVar3 * param_4[0xc]) / (uVar12 * 8);
  }
  uVar5 = (ulong)param_4[1];
  if ((char)param_4[3] == '\0') {
    if (*(char *)((long)param_4 + 0xf) == '\0') {
      lVar16 = uVar5 * 0x97ac20;
    }
    else {
      lVar16 = uVar5 * 9700000;
    }
    uVar5 = (ulong)(lVar16 << 3) / 0x50;
  }
  else {
    uVar5 = (uVar5 * 0x166132ce00) / 80000;
  }
  *(ulong *)(param_5 + 8) = param_4[2] * uVar5 * 8;
  uVar14 = param_4[0xc];
  if (*(char *)((long)param_4 + 0xe) == '\0') {
    if (*(char *)((long)param_4 + 0x11) == '\0') {
      if ((char)param_4[4] == '\0') {
        if ((char)param_4[3] == '\0') {
          uVar8 = param_4[2];
          local_50 = 7;
          local_58 = 8;
          iVar7 = uVar8 * 8;
        }
        else {
LAB_00304f28:
          local_50 = 0x1f;
          iVar7 = 0x80;
          uVar8 = 4;
          local_58 = 0x20;
        }
        uVar14 = ((uVar17 - 1) +
                 (((((uVar17 - 1) + uVar8) / uVar8) * uVar14 + local_50) / local_58) * iVar7 * 0x100
                 ) / uVar17;
      }
      else {
        if ((char)param_4[3] != '\0') goto LAB_00304f28;
        uVar14 = uVar14 << 8;
      }
    }
    else {
      uVar14 = uVar14 << 4;
    }
  }
  *(ulong *)(param_5 + 0xc) = (ulong)uVar14;
  if ((char)param_4[3] != '\0') {
    iVar7 = 0x18000;
LAB_00304c25:
    param_5[4] = ((uVar14 - 1) + iVar7) / uVar14;
    if (*(char *)((long)param_4 + 0xe) == '\0') {
      uVar17 = iVar18 * uVar12 * 4;
    }
    else {
      uVar17 = iVar18 * 0x400;
    }
    uVar17 = (param_4[0xc] * uVar23) / uVar17;
    param_5[2] = uVar17;
    iVar18 = uVar17 - 6;
    if ((char)param_4[3] != '\0') {
      iVar18 = uVar17 - 2;
    }
    param_5[2] = iVar18;
    if (param_4[0x10] != 0) {
      puVar22 = param_5;
      uVar4 = _getDpAudioSymbolMST
                        (2,((*(long *)(param_4 + 10) * 1000 - 1U) +
                           (ulong)param_4[0x10] * (ulong)param_4[0xd]) /
                           (ulong)(*(long *)(param_4 + 10) * 1000),(char)param_4[3]);
      puVar22[5] = uVar4;
    }
    if (param_4[0x11] != 0) {
      uVar4 = _getDpAudioSymbolMST
                        (8,((*(long *)(param_4 + 10) * 1000 - 1U) +
                           (ulong)param_4[0x11] * (ulong)param_4[0xd]) /
                           (ulong)(*(long *)(param_4 + 10) * 1000),(char)param_4[3]);
      param_5[6] = uVar4;
    }
    return 0;
  }
  iVar7 = 0xa000;
  if (*(char *)((long)param_4 + 0xe) != '\0') goto LAB_00304c25;
  uVar14 = param_4[2];
  uVar8 = param_4[0xc];
  iVar18 = uVar14 * 0x40 + 0x60;
  if (*(char *)((long)param_4 + 0x11) == '\0') {
    uVar10 = (iVar18 - uVar17 * uVar8) +
             ((((uVar17 - 1) + uVar14) / uVar14) * uVar8 * 0x100 + 0x7ff >> 0xb) * uVar14 * 8;
  }
  else {
    uVar9 = (uVar14 - 1) + uVar10;
    uVar10 = (uVar10 * 8 - (uVar3 * uVar8) / uVar12) * uVar15 + iVar18 + uVar14 * 8 +
             ((uVar9 - uVar9 % uVar14) - uVar10) * 8;
  }
  uVar5 = uVar14 * uVar24 * 8000;
  param_5[4] = (int)(((uVar5 - 1) + (ulong)uVar10 * *(long *)(param_4 + 10) * 0x274c) / uVar5);
  if (param_4[0x10] != 0) {
    uVar10 = param_4[2];
    if (uVar10 == 1) {
      iVar18 = 0xc;
      iVar19 = 0x14;
      iVar7 = 0x1e;
    }
    else if (uVar10 == 2) {
      iVar19 = 10;
      iVar7 = 0x10;
      iVar18 = 2;
    }
    else {
      iVar18 = 2;
      if (uVar10 == 4) {
        iVar19 = 5;
        iVar7 = 9;
      }
      else {
        iVar19 = 0;
        iVar7 = 0;
      }
    }
    uVar10 = (int)(((*(ulong *)(param_4 + 10) - 1) + (ulong)param_4[0x10] * (ulong)param_4[0xd]) /
                  *(ulong *)(param_4 + 10)) + 1999;
    iVar11 = 0;
    if (1999 < uVar10) {
      iVar11 = (uVar10 / 2000 - 1) * iVar19 + iVar18 + iVar7;
    }
    param_5[5] = iVar11;
  }
  if (param_4[0x11] != 0) {
    uVar10 = param_4[2];
    if (uVar10 == 1) {
      iVar18 = 0xc;
      iVar19 = 0x28;
      iVar7 = 0x32;
    }
    else if (uVar10 == 2) {
      iVar19 = 0x14;
      iVar7 = 0x1a;
      iVar18 = 2;
    }
    else {
      iVar18 = 2;
      if (uVar10 == 4) {
        iVar19 = 10;
        iVar7 = 0xe;
      }
      else {
        iVar19 = 0;
        iVar7 = 0;
      }
    }
    uVar10 = (int)(((*(ulong *)(param_4 + 10) - 1) + (ulong)param_4[0x11] * (ulong)param_4[0xd]) /
                  *(ulong *)(param_4 + 10)) + 999;
    iVar11 = 0;
    if (999 < uVar10) {
      iVar11 = (uVar10 / 1000 - 1) * iVar19 + iVar18 + iVar7;
    }
    param_5[6] = iVar11;
  }
  param_5[2] = 0;
  uVar5 = *(ulong *)(param_4 + 10);
  uVar10 = param_4[0xd];
  uVar2 = regRead032(param_1 + 0x3a18,0,0,param_3 * 4 + 0x6405e8,0);
  uVar15 = 1;
  if (param_4[0x12] == 3) {
    uVar10 = uVar10 >> 1;
    uVar15 = 2;
  }
  uVar3 = (uint)(byte)((ushort)uVar2 >> 8);
  if ((uVar10 & 3) == 0) {
    uVar6 = uVar5 / (uVar15 * 4);
    uVar21 = (ulong)(uVar3 * 1000000);
    if (uVar21 < uVar6) {
      uVar10 = 4;
      uVar3 = uVar15 * 8;
      uVar15 = uVar15 * 4;
    }
    else {
LAB_00304f57:
      uVar3 = uVar15 * 2;
      uVar6 = uVar5 / uVar3;
      if (uVar21 < uVar6) {
        uVar14 = uVar15 * 4;
        uVar10 = 2;
        uVar15 = uVar3;
        uVar3 = uVar14;
      }
      else {
        uVar10 = 1;
        uVar6 = uVar5 / uVar15;
      }
    }
  }
  else {
    uVar10 = uVar10 & 1;
    if (uVar10 == 0) {
      uVar21 = (ulong)(uVar3 * 1000000);
      goto LAB_00304f57;
    }
    uVar6 = uVar5 / uVar15;
    uVar3 = uVar15 * 2;
  }
  iVar18 = uVar23 - param_5[4];
  if ((uint)(byte)uVar2 * 10000000 < uVar6) {
    if (*(char *)((long)param_4 + 0x11) == '\0') {
      iVar7 = uVar3 + uVar15;
      lVar16 = (ulong)(uint)(iVar18 - iVar7) << 6;
    }
    else {
      uVar14 = param_4[0xc];
      uVar8 = uVar3;
      if (uVar14 < 0x11) {
        uVar8 = uVar3 * 2;
        uVar15 = uVar3;
      }
      iVar7 = uVar8 + uVar15;
      lVar16 = (ulong)(uint)(iVar18 - iVar7) << 6;
LAB_00304a0b:
      lVar16 = lVar16 - (ulong)(uVar12 * uVar10 * 0x800) / (ulong)uVar14;
    }
  }
  else {
    iVar7 = uVar3 + uVar15;
    lVar16 = (ulong)(uint)(iVar18 - iVar7) << 6;
    if (*(char *)((long)param_4 + 0x11) != '\0') {
      uVar14 = param_4[0xc];
      goto LAB_00304a0b;
    }
  }
  uVar12 = param_4[2];
  uVar5 = (lVar16 * uVar24 * 0x3e2) / (ulong)(*(long *)(param_4 + 10) * 640000);
  if (*(char *)((long)param_4 + 0xf) == '\0') {
LAB_00304a8e:
    uVar10 = param_4[0x11];
    lVar16 = uVar5 - 7;
    if (uVar12 == 4) {
      lVar13 = (-(ulong)(uVar10 == 0) & 0xfffffffffffffffb) + 0x11;
    }
    else {
      if (uVar12 != 2) goto LAB_00304aaa;
      lVar13 = (-(ulong)(uVar10 == 0) & 0xfffffffffffffff6) + 0x1d;
    }
  }
  else {
    uVar21 = *(long *)(param_4 + 10) * 10000;
    uVar23 = (int)(((uVar21 - 1) + uVar23 * uVar24 * 0x3e2) / uVar21) - 1;
    if (uVar12 != 1) {
      uVar10 = uVar23 & 0xff;
      if (6 < uVar10) {
        uVar10 = 6;
      }
      uVar5 = uVar5 - (uVar10 + 1 + (uVar23 >> 8) * 6);
      goto LAB_00304a8e;
    }
    uVar12 = uVar23 & 0x1ff;
    if (0xc < uVar12) {
      uVar12 = 0xc;
    }
    uVar10 = param_4[0x11];
    lVar16 = (uVar5 - (uVar12 + 1 + (uVar23 >> 9) * 0xc)) + -7;
LAB_00304aaa:
    lVar13 = (-(ulong)(uVar10 == 0) & 0xffffffffffffffec) + 0x3f;
  }
  if (lVar16 < lVar13) {
    lVar16 = lVar13;
  }
  param_5[2] = (int)lVar16;
  uVar5 = *(ulong *)(param_4 + 10);
  uVar23 = param_4[2];
  iVar18 = (int)(((ulong)(uVar17 - iVar7) * uVar24 * 0x3e2) / (uVar5 * 1000)) -
           (int)(0x24 / (ulong)uVar23);
  if (*(char *)((long)param_4 + 0xf) == '\0') {
    iVar18 = iVar18 + -6;
    if (0 < iVar18) goto LAB_00304b58;
    cVar20 = *(char *)((long)param_4 + 0x11);
    uVar17 = param_4[0xc];
    uVar12 = (uint)((uVar5 & 0xffffffff) / 1000);
    iVar18 = (int)(8 / (ulong)uVar23);
LAB_00304e8c:
    iVar7 = 3 - iVar18;
    lVar16 = (ulong)uVar17 * (ulong)uVar12;
    if (cVar20 != '\0') {
      uVar23 = uVar23 << 4;
    }
    lVar13 = 1000;
  }
  else {
    iVar19 = iVar18 + -4;
    iVar7 = iVar19 % 0x100;
    if (6 < iVar7) {
      iVar7 = 6;
    }
    iVar11 = iVar18 + 0xfb;
    if (-1 < iVar19) {
      iVar11 = iVar19;
    }
    iVar18 = (iVar18 - (iVar7 + 1 + (iVar11 >> 8) * 6)) + -6;
    if (iVar18 < 1) {
      cVar20 = *(char *)((long)param_4 + 0x11);
      uVar17 = param_4[0xc];
      uVar5 = (uVar5 & 0xffffffff) / 1000;
      iVar18 = (int)(8 / (ulong)uVar23);
    }
    else {
LAB_00304b58:
      param_5[3] = iVar18;
      uVar23 = param_4[2];
      cVar20 = *(char *)((long)param_4 + 0x11);
      uVar17 = param_4[0xc];
      uVar5 = (ulong)param_4[10] / 1000;
      uVar12 = (uint)uVar5;
      iVar18 = (int)(8 / (ulong)uVar23);
      if (*(char *)((long)param_4 + 0xf) == '\0') goto LAB_00304e8c;
    }
    lVar16 = uVar5 * uVar17;
    if (uVar23 == 1) {
      iVar7 = 0x12;
      if (cVar20 != '\0') {
        uVar23 = 0x10;
      }
      lVar13 = 0x400;
    }
    else if (cVar20 == '\0') {
      iVar7 = 0xd;
      lVar13 = 0x400;
    }
    else {
      uVar23 = uVar23 << 4;
      iVar7 = 0xd;
      lVar13 = 0x400;
    }
  }
  iVar19 = (int)((lVar13 * lVar16) / (long)(ulong)((int)(uVar24 / 1000000) * uVar23 * 800));
  param_5[1] = iVar18 + 3 +
               (int)(((1000 - iVar19) * iVar19 + ((uVar23 * 8 - 1) + uVar17 * 0xb71b) / (uVar23 * 8)
                     ) * 1000 + 0xee6b27 + iVar7 * iVar19 * 0x3d09) / 0xee6b28;
  return 0;
}


// ===== 003050e0 kheadGetCrashLockCounterV_v05_01 =====

uint kheadGetCrashLockCounterV_v05_01(long param_1,long param_2)

{
  uint uVar1;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x140) * 0x800 + 0x616484,0);
  return uVar1 >> 0x10;
}


// ===== 00305110 dispcapConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

undefined8 dispcapConstruct_IMPL(long param_1)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1b80);
  pcVar3 = *(code **)(lVar2 + 0x198);
  (*pcVar3)(lVar1,lVar2,param_1 + 0x138,param_1 + 0x13c,pcVar3);
  return 0;
}


// ===== 00305150 dispcapGetRegBaseOffsetAndSize_IMPL =====

undefined8
dispcapGetRegBaseOffsetAndSize_IMPL
          (long param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4)

{
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(param_1 + 0x138);
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = *(undefined4 *)(param_1 + 0x13c);
  }
  return 0;
}


// ===== 00305180 dispchnGetRegBaseOffsetAndSize_IMPL =====

undefined8
dispchnGetRegBaseOffsetAndSize_IMPL
          (long param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4)

{
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(param_1 + 0x198);
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = *(undefined4 *)(param_1 + 0x19c);
  }
  return 0;
}


// ===== 003051b0 dispchnSetRegBaseOffsetAndSize_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void dispchnSetRegBaseOffsetAndSize_IMPL(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x1b80);
  (**(code **)(lVar1 + 0x1a8))
            (param_2,lVar1,*(undefined4 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x184),
             param_1 + 0x198,param_1 + 0x19c);
  iVar2 = (**(code **)(lVar1 + 0x188))(param_2,lVar1);
  *(int *)(param_1 + 0x198) = *(int *)(param_1 + 0x198) + iVar2;
  return;
}


// ===== 00305220 kdispMapDispChannel_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kdispMapDispChannel_IMPL(undefined8 param_1,long param_2)

{
  long lVar1;
  undefined4 uVar2;
  long *plVar3;
  ulong uVar4;
  
  lVar1 = *(long *)(*(long *)(param_2 + 0x158) + 0xe0);
  plVar3 = (long *)__nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_2 + 0x140) + 0x48),
                                      __nvoc_class_def_RmClient);
  uVar2 = (**(code **)(*plVar3 + 0xd8))(plVar3);
  uVar4 = osMapGPU(lVar1,uVar2,*(undefined4 *)(param_2 + 0x198),*(undefined4 *)(param_2 + 0x19c),3,
                   param_2 + 0x188,param_2 + 400);
  if ((int)uVar4 == 0) {
    return uVar4 & 0xffffffff;
  }
  nvDbg_Printf("src/kernel/gpu/disp/disp_channel.c",0x1c7,"kdispMapDispChannel_IMPL",4,
               "NVRM: disp channel[0x%x] mapping failed. Return status = 0x%x\n",
               *(undefined4 *)(param_2 + 0x184),uVar4);
  plVar3 = *(long **)(*(long *)(param_2 + 0x140) + 0x48);
  (**(code **)(lVar1 + 0x3b70))(lVar1 + 0x3b58,*(undefined4 *)(*plVar3 + 0x48),(int)plVar3[2]);
  return uVar4 & 0xffffffff;
}


// ===== 00305320 kdispUnbindUnmapDispChannel_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

void kdispUnbindUnmapDispChannel_IMPL(undefined8 param_1,long param_2)

{
  long lVar1;
  undefined4 uVar2;
  long *plVar3;
  
  lVar1 = *(long *)(*(long *)(param_2 + 0x158) + 0xe0);
  plVar3 = (long *)__nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_2 + 0x140) + 0x48),
                                      __nvoc_class_def_RmClient);
  uVar2 = (**(code **)(*plVar3 + 0xd8))(plVar3);
  instmemUnbindDispChannelContextDmas_IMPL
            (lVar1,*(undefined8 *)(*(long *)(lVar1 + 0x1b80) + 0x280),param_2);
  osUnmapGPU(*(undefined8 *)(lVar1 + 0x4e0),uVar2,*(undefined8 *)(param_2 + 0x188),
             *(undefined4 *)(param_2 + 0x19c),*(undefined8 *)(param_2 + 400));
  return;
}


// ===== 003053b9 dispchnDestruct_IMPL.cold =====

void dispchnDestruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003053d0 dispchnDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void dispchnDestruct_IMPL(long param_1)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  code *pcVar4;
  char cVar5;
  int iVar6;
  long lVar7;
  ulong uVar8;
  long *plVar9;
  long lVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  ulong local_128;
  undefined8 local_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  long local_f0;
  undefined8 local_e8;
  long local_d0;
  ulong local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  long local_90;
  undefined8 local_88;
  ulong local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  undefined8 local_40;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1b80);
  lVar7 = rmapiGetInterface(4);
  if ((*(int *)(param_1 + 0x180) == 3) && (*(char *)(lVar2 + 0x2d0) != '\0')) {
    cVar5 = gpuIsGpuFullPower_IMPL(lVar1);
    if (cVar5 == '\0') {
      nvAssertFailedNoLog("gpuIsGpuFullPower(pGpu)","src/kernel/gpu/disp/disp_channel.c",0x20b);
    }
    for (plVar9 = (long *)serverutilGetFirstClientUnderLock(); plVar9 != (long *)0x0;
        plVar9 = (long *)serverutilGetNextClientUnderLock(plVar9)) {
      uVar12 = 0;
      if (*plVar9 != 0) {
        uVar12 = *(undefined8 *)(*plVar9 + 0x100);
      }
      clientRefIter(&local_128,uVar12,0,&DAT_00e0ac20,0,1);
      local_c8 = local_128;
      local_c0 = local_120;
      local_b8 = local_118;
      local_b0 = local_110;
      local_a8 = local_108;
      local_a0 = local_100;
      local_98 = local_f8;
      local_90 = local_f0;
      local_88 = local_e8;
LAB_003055c0:
      cVar5 = clientRefIterNext(local_a8,&local_c8);
      if (cVar5 != '\0') {
        lVar10 = __nvoc_dynamicCast(*(undefined8 *)(local_90 + 8),__nvoc_class_def_Device);
        if ((lVar1 == *(long *)(*(long *)(lVar10 + 0x128) + 0xe0)) &&
           (iVar6 = dispobjGetByDevice_IMPL(uVar12,lVar10,&local_d0), iVar6 == 0)) {
          if (local_d0 == 0) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)invalidInstructionException();
            (*pcVar4)();
          }
          uVar11 = 0;
          lVar10 = *(long *)(*(long *)(local_d0 + 0x188) + 0x48);
          do {
            clientRefIter(&local_128,uVar12,lVar10,0xbd2ff3,uVar11,0);
            local_80 = local_128;
            local_78 = local_120;
            local_70 = local_118;
            local_68 = local_110;
            local_60 = local_108;
            local_58 = local_100;
            local_50 = local_f8;
            local_48 = local_f0;
            local_40 = local_e8;
            while( true ) {
              do {
                cVar5 = clientRefIterNext(local_60,&local_80);
                if (cVar5 == '\0') goto LAB_003055c0;
                lVar10 = __nvoc_dynamicCast(*(undefined8 *)(local_48 + 8),
                                            __nvoc_class_def_DispChannel);
              } while (*(int *)(lVar10 + 0x180) == 3);
              plVar3 = *(long **)(*(long *)(lVar10 + 0x140) + 0x48);
              iVar6 = (**(code **)(lVar7 + 0x18))
                                (lVar7,*(undefined4 *)(*plVar3 + 0x48),(int)plVar3[2]);
              if (iVar6 == 0) break;
              nvDbg_Printf("src/kernel/gpu/disp/disp_channel.c",0x23c,"dispchnDestruct_IMPL",4);
            }
            clientRefIter(&local_128,uVar12,0,&DAT_00e0ac20,0,1);
            local_c8 = local_128;
            local_90 = local_f0;
            uVar11 = 1;
            local_c0 = local_120;
            local_b8 = local_118;
            local_b0 = local_110;
            local_a8 = local_108;
            local_a0 = local_100;
            local_98 = local_f8;
            local_88 = local_e8;
            lVar10 = local_f0;
          } while( true );
        }
        goto LAB_003055c0;
      }
    }
  }
  if (*(long *)(lVar2 + 0x3a8) != 0) {
    iVar6 = (**(code **)(lVar2 + 400))
                      (lVar2,*(undefined4 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x184),
                       &local_80);
    if (iVar6 == 0) {
      uVar8 = local_80 & 0xffffffff;
      *(undefined8 *)(*(long *)(lVar2 + 0x3a8) + uVar8 * 0x18) = 0;
      *(undefined4 *)(*(long *)(lVar2 + 0x3a8) + 8 + uVar8 * 0x18) = 0;
      *(undefined1 *)(*(long *)(lVar2 + 0x3a8) + 0x10 + uVar8 * 0x18) = 0;
    }
    else {
      nvDbg_Printf("src/kernel/gpu/disp/disp_channel.c",0x251,"dispchnDestruct_IMPL",3,
                   "NVRM: Failed to reset clientChannelTable!\n");
    }
  }
  kdispUnbindUnmapDispChannel_IMPL(lVar2,param_1);
  return;
}


// ===== 00305860 dispchnpioConstruct_IMPL =====

undefined8 dispchnpioConstruct_IMPL(void)

{
  return 0;
}


// ===== 00305870 dispchndmaConstruct_IMPL =====

undefined8 dispchndmaConstruct_IMPL(void)

{
  return 0;
}


// ===== 00305880 dispchnGetByHandle_IMPL =====

int dispchnGetByHandle_IMPL(undefined8 param_1,undefined8 param_2,long *param_3)

{
  int iVar1;
  long lVar2;
  long local_20;
  
  *param_3 = 0;
  iVar1 = clientGetResourceRef_IMPL(param_1,param_2,&local_20);
  if (iVar1 == 0) {
    lVar2 = __nvoc_dynamicCast(*(undefined8 *)(local_20 + 8),__nvoc_class_def_DispChannel);
    *param_3 = lVar2;
    if (lVar2 == 0) {
      iVar1 = 0x33;
    }
  }
  return iVar1;
}


// ===== 003058d6 dispchnBindCtx_IMPL.cold =====

void dispchnBindCtx_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003058e0 dispchnBindCtx_IMPL =====

ulong dispchnBindCtx_IMPL(long param_1,long param_2,undefined4 param_3)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  long local_20;
  
  if (param_2 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  uVar2 = clientGetResourceRef_IMPL
                    (**(undefined8 **)(*(long *)(param_2 + 0xe8) + 0x48),param_3,&local_20);
  if (uVar2 == 0) {
    lVar3 = __nvoc_dynamicCast(*(undefined8 *)(local_20 + 8),__nvoc_class_def_DispChannel);
    if (lVar3 != 0) {
      if (*(long *)(param_2 + 0x260) != *(long *)(*(long *)(lVar3 + 0x158) + 0xe8)) {
        nvCheckFailedNoLog(4,"pContextDma->pDevice == GPU_RES_GET_DEVICE(pDispChannel)",
                           "src/kernel/gpu/disp/disp_channel.c",0x2a5);
        return 0x26;
      }
      if (*(int *)(*(long *)(param_2 + 0x210) + 0x60) != 0) {
        nvDbg_Printf("src/kernel/gpu/disp/disp_channel.c",0x2b2,"dispchnBindCtx_IMPL",4,
                     "NVRM: ISO ctx dmas must be 4K aligned. PteAdjust = 0x%x\n");
        return 0x37;
      }
      uVar4 = instmemBindContextDma_IMPL
                        (param_1,*(undefined8 *)(*(long *)(param_1 + 0x1b80) + 0x280),param_2,lVar3)
      ;
      return uVar4;
    }
    uVar2 = 0x33;
  }
  nvCheckOkFailedNoLog
            (4,uVar2,"dispchnGetByHandle(pClient, hChannel, &pDispChannel)",
             "src/kernel/gpu/disp/disp_channel.c",0x2a1);
  return (ulong)uVar2;
}


// ===== 00305a1c dispchnUnbindCtx_IMPL.cold =====

void dispchnUnbindCtx_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00305a30 dispchnUnbindCtx_IMPL =====

int dispchnUnbindCtx_IMPL(long param_1,long param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  long local_20;
  
  if (param_2 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  iVar2 = clientGetResourceRef_IMPL
                    (**(undefined8 **)(*(long *)(param_2 + 0xe8) + 0x48),param_3,&local_20);
  if (iVar2 == 0) {
    lVar3 = __nvoc_dynamicCast(*(undefined8 *)(local_20 + 8),__nvoc_class_def_DispChannel);
    if (lVar3 != 0) {
      if (*(long *)(param_2 + 0x260) == *(long *)(*(long *)(lVar3 + 0x158) + 0xe8)) {
        iVar2 = instmemUnbindContextDma_IMPL
                          (param_1,*(undefined8 *)(*(long *)(param_1 + 0x1b80) + 0x280),param_2,
                           lVar3);
        iVar2 = (uint)(iVar2 != 0) << 6;
      }
      else {
        nvCheckFailedNoLog(4,"pContextDma->pDevice == GPU_RES_GET_DEVICE(pDispChannel)",
                           "src/kernel/gpu/disp/disp_channel.c",0x2db);
        iVar2 = 0x26;
      }
      return iVar2;
    }
    iVar2 = 0x33;
  }
  nvCheckOkFailedNoLog
            (4,iVar2,"dispchnGetByHandle(pClient, hChannel, &pDispChannel)",
             "src/kernel/gpu/disp/disp_channel.c",0x2d7);
  return iVar2;
}


// ===== 00305b30 dispchnUnbindCtxFromAllChannels_IMPL =====

void dispchnUnbindCtxFromAllChannels_IMPL(long param_1,undefined8 param_2)

{
  instmemUnbindContextDmaFromAllChannels_IMPL
            (param_1,*(undefined8 *)(*(long *)(param_1 + 0x1b80) + 0x280),param_2);
  return;
}


// ===== 00305b4a kdispSetPushBufferParamsToPhysical_IMPL.cold =====

void kdispSetPushBufferParamsToPhysical_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00305b60 kdispSetPushBufferParamsToPhysical_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kdispSetPushBufferParamsToPhysical_IMPL
              (long param_1,long param_2,long param_3,undefined4 param_4,long param_5,
              undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
              undefined4 param_10)

{
  code *pcVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  long local_80;
  undefined1 local_74 [4];
  ulong local_70;
  undefined8 local_68;
  ulong local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_80 = param_5;
  if (param_3 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  uVar5 = **(undefined8 **)(*(long *)(param_3 + 0x140) + 0x48);
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  iVar3 = (**(code **)(param_2 + 400))(param_2,param_8,param_7,local_74);
  if (iVar3 != 0) {
    return iVar3;
  }
  local_50 = CONCAT44(local_50._4_4_,param_7);
  local_40 = CONCAT44(local_40._4_4_,param_10);
  uVar2 = 0;
  local_58._4_4_ = param_6;
  if (*(char *)(param_3 + 0x1a0) != '\0') {
    iVar3 = ctxdmaGetByHandle_IMPL(uVar5,param_4,&local_80);
    if (iVar3 != 0) {
      nvDbg_Printf("src/kernel/gpu/disp/disp_channel.c",0x33d,
                   "kdispSetPushBufferParamsToPhysical_IMPL",4,
                   "NVRM: disp channel[0x%x] didn\'t have valid ctxdma 0x%x\n",param_7,param_4);
      return iVar3;
    }
    local_60 = *(ulong *)(local_80 + 0x130);
    iVar3 = memdescGetAddressSpace(*(undefined8 *)(local_80 + 0x210));
    local_70 = CONCAT44(local_70._4_4_,iVar3);
    if (1 < iVar3 - 1U) {
      return 0xffff;
    }
    uVar5 = memdescGetMemDescFromGpu(*(undefined8 *)(local_80 + 0x210),param_1);
    local_68 = memdescGetPhysAddr(uVar5,1,0);
    local_58._0_4_ = *(undefined4 *)(local_80 + 0x124);
    uVar4 = (**(code **)(param_2 + 0x220))(param_1,param_2,local_70 & 0xffffffff);
    if (local_60 < (1 << ((char)param_9 + 0xcU & 0x1f)) - 1) {
      return 0x1f;
    }
    local_48 = CONCAT44(param_9,uVar4);
    uVar2 = 1;
  }
  local_50._0_5_ = CONCAT14(uVar2,(undefined4)local_50);
  (**(code **)(param_1 + 0x3b90))
            (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),*(undefined4 *)(param_1 + 0x3b3c),
             0x20800a58,&local_70,0x38);
  return 0;
}


// ===== 00305d80 dispchnConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int dispchnConstruct_IMPL(long param_1,undefined8 param_2,long param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  long lVar4;
  long lVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  char cVar8;
  undefined4 uVar9;
  int iVar10;
  long lVar11;
  ulong uVar12;
  undefined4 uVar13;
  undefined4 local_68;
  int local_64;
  int local_40;
  uint local_3c [3];
  
  puVar3 = *(undefined4 **)(param_3 + 0x40);
  lVar4 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar5 = *(long *)(lVar4 + 0x1b80);
  lVar11 = __nvoc_dynamicCast(*(undefined8 *)
                               (*(long *)(*(long *)(*(long *)(param_1 + 0x140) + 0x48) + 0x18) + 8),
                              __nvoc_class_def_DispObject);
  uVar1 = *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x140) + 0x48) + 0x11c);
  uVar9 = gpumgrSetCurrentGpuInstance(*(undefined4 *)(lVar4 + 0x7a4));
  if (lVar11 == 0) {
    nvAssertOkFailedNoLog(0x33,"pDispObject != NULL","src/kernel/gpu/disp/disp_channel.c",0x8a);
    iVar10 = 0x33;
  }
  else if (**(int **)(param_3 + 0x38) == 0) {
    iVar10 = 0x1b;
    nvDbg_Printf("src/kernel/gpu/disp/disp_channel.c",0x8e,"dispchnConstruct_IMPL",4,
                 "NVRM: Failure allocating display class 0x%08x: Only root(admin)/kernel clients are allowed\n"
                 ,*(undefined4 *)(param_3 + 0xc));
    osAssertFailed();
  }
  else {
    cVar8 = gpuIsClassSupported_IMPL
                      (lVar4,*(undefined4 *)(*(long *)(*(long *)(param_1 + 0x140) + 0x48) + 0x11c));
    if (cVar8 == '\0') {
      iVar10 = 0x22;
      nvDbg_Printf("src/kernel/gpu/disp/disp_channel.c",0xa4,"dispchnConstruct_IMPL",4,
                   "NVRM: Unsupported class in\n");
    }
    else {
      *(long *)(param_1 + 0x178) = lVar11;
      *(bool *)(param_1 + 0x1a0) = param_4 != 0;
      uVar2 = *puVar3;
      local_64 = puVar3[1];
      if (param_4 != 0) {
        uVar13 = puVar3[7];
        if (puVar3[2] != 0) {
          nvDbg_Printf("src/kernel/gpu/disp/disp_channel.c",0x56,"dispchnParseAllocParams",3,
                       "NVRM: Error notifier parameter is not used in Display channel allocation.\n"
                      );
        }
        local_68 = puVar3[8];
      }
      else {
        local_68 = 0;
        uVar13 = 0;
        if (local_64 != 0) {
          nvDbg_Printf("src/kernel/gpu/disp/disp_channel.c",0x65,"dispchnParseAllocParams",3,
                       "NVRM: Error notifier parameter is not used in Display channel allocation.\n"
                      );
          local_64 = 0;
        }
      }
      iVar10 = kdispGetIntChnClsForHwCls_IMPL
                         (lVar5,*(undefined4 *)
                                 (*(long *)(*(long *)(param_1 + 0x140) + 0x48) + 0x11c),&local_40);
      if (iVar10 == 0) {
        if (local_40 == 7) {
          *(undefined4 *)(param_1 + 0x180) = 7;
          *(undefined4 *)(param_1 + 0x184) = uVar2;
        }
        else {
          cVar8 = gpuIsGpuFullPower_IMPL(lVar4);
          if (((cVar8 == '\0') && (*(char *)(lVar4 + 0x444) == '\0')) ||
             (cVar8 = gpuCheckSysmemAccess_IMPL(lVar4), cVar8 == '\0')) {
            return 0x11;
          }
          iVar10 = kdispSetPushBufferParamsToPhysical_IMPL
                             (lVar4,lVar5,param_1,local_64,0,uVar1,uVar2,local_40,uVar13,local_68);
          if (iVar10 == 0) {
            *(ulong *)(param_1 + 0x180) = CONCAT44(uVar2,local_40);
            dispchnSetRegBaseOffsetAndSize_IMPL(param_1,lVar4);
            iVar10 = kdispMapDispChannel_IMPL(lVar5,param_1);
            if (*(char *)(param_1 + 0x1a0) == '\0') {
              *(undefined8 *)(puVar3 + 2) = *(undefined8 *)(param_1 + 0x188);
            }
            else {
              *(undefined8 *)(puVar3 + 4) = *(undefined8 *)(param_1 + 0x188);
            }
            if ((iVar10 == 0) && (*(long *)(lVar5 + 0x3a8) != 0)) {
              puVar6 = *(undefined8 **)(*(long *)(param_1 + 0x140) + 0x48);
              uVar7 = *puVar6;
              uVar1 = *(undefined4 *)(puVar6 + 2);
              iVar10 = (**(code **)(lVar5 + 400))(lVar5,local_40,uVar2,local_3c);
              if (iVar10 == 0) {
                uVar12 = (ulong)local_3c[0];
                *(undefined8 *)(*(long *)(lVar5 + 0x3a8) + uVar12 * 0x18) = uVar7;
                *(undefined4 *)(*(long *)(lVar5 + 0x3a8) + 8 + uVar12 * 0x18) = uVar1;
                *(undefined1 *)(*(long *)(lVar5 + 0x3a8) + 0x10 + uVar12 * 0x18) = 1;
                nvDbg_Printf("src/kernel/gpu/disp/disp_channel.c",0x10e,"dispchnConstruct_IMPL",1,
                             "NVRM: Mapped hclient: %p hchannel: 0x%x channleNum: 0x%x\n",uVar7,
                             uVar1);
              }
              else {
                nvDbg_Printf("src/kernel/gpu/disp/disp_channel.c",0x106,"dispchnConstruct_IMPL",4,
                             "NVRM: kdispGetChannelNum_HAL failed!\n");
              }
            }
          }
        }
      }
    }
  }
  gpumgrSetCurrentGpuInstance(uVar9);
  return iVar10;
}


// ===== 003061a0 dispchnGrabChannel_IMPL =====

undefined8
dispchnGrabChannel_IMPL
          (long param_1,undefined8 param_2,int param_3,undefined4 param_4,int param_5,int *param_6)

{
  int iVar1;
  int iVar2;
  long lVar3;
  char cVar4;
  undefined8 uVar5;
  long lVar6;
  int iVar7;
  int local_58;
  int local_54;
  undefined4 local_3c [3];
  
  lVar6 = *(long *)(*(long *)(param_1 + 0x140) + 0x48);
  if (*(int *)(*(long *)(lVar6 + 0x18) + 0x10) == param_3) {
    lVar3 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
    uVar5 = *(undefined8 *)(lVar3 + 0x1b80);
    iVar1 = *param_6;
    iVar7 = param_6[1];
    if (*(char *)(param_1 + 0x1a0) == '\0') {
      local_58 = 0;
      local_54 = 0;
      if (iVar7 != 0) {
        nvDbg_Printf("src/kernel/gpu/disp/disp_channel.c",0x65,"dispchnParseAllocParams",3,
                     "NVRM: Error notifier parameter is not used in Display channel allocation.\n");
        iVar7 = 0;
        lVar6 = *(long *)(*(long *)(param_1 + 0x140) + 0x48);
      }
      iVar2 = *(int *)(lVar6 + 0x11c);
    }
    else {
      local_54 = param_6[7];
      if (param_6[2] != 0) {
        nvDbg_Printf("src/kernel/gpu/disp/disp_channel.c",0x56,"dispchnParseAllocParams",3,
                     "NVRM: Error notifier parameter is not used in Display channel allocation.\n");
        lVar6 = *(long *)(*(long *)(param_1 + 0x140) + 0x48);
      }
      local_58 = param_6[8];
      iVar2 = *(int *)(lVar6 + 0x11c);
    }
    if ((iVar2 == param_5) && (*(int *)(param_1 + 0x184) == iVar1)) {
      kdispGetIntChnClsForHwCls_IMPL(uVar5,param_5,local_3c);
      cVar4 = gpuIsGpuFullPower_IMPL(lVar3);
      if (((cVar4 == '\0') && (*(char *)(lVar3 + 0x444) == '\0')) ||
         (cVar4 = gpuCheckSysmemAccess_IMPL(lVar3), cVar4 == '\0')) {
        uVar5 = 0x11;
      }
      else {
        uVar5 = kdispSetPushBufferParamsToPhysical_IMPL
                          (lVar3,uVar5,param_1,iVar7,0,param_5,iVar1,local_3c[0],local_54,local_58);
        if ((int)uVar5 == 0) {
          if (*(char *)(param_1 + 0x1a0) == '\0') {
            *(undefined8 *)(param_6 + 2) = *(undefined8 *)(param_1 + 0x188);
          }
          else {
            *(undefined8 *)(param_6 + 4) = *(undefined8 *)(param_1 + 0x188);
          }
        }
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/disp/disp_channel.c",0x151,"dispchnGrabChannel_IMPL",4,
                   "NVRM: Information supplied for handle 0x%x doesn\'t match that in RM\'s client DB\n"
                   ,param_4);
      uVar5 = 0x33;
    }
    return uVar5;
  }
  nvDbg_Printf("src/kernel/gpu/disp/disp_channel.c",0x139,"dispchnGrabChannel_IMPL",4,
               "NVRM: disp channel grab failed because of bad display parent 0x%x\n",param_3);
  return 0x36;
}


// ===== 0030642a dispcmnCtrlCmdSpecificSetAcpiIdMapping_IMPL.cold =====

void dispcmnCtrlCmdSpecificSetAcpiIdMapping_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00306440 dispcmnCtrlCmdSpecificSetAcpiIdMapping_IMPL =====

ulong dispcmnCtrlCmdSpecificSetAcpiIdMapping_IMPL(long param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined8 uVar3;
  code *pcVar4;
  ulong uVar5;
  long lVar6;
  int iVar7;
  undefined8 local_40 [2];
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  puVar1 = param_2 + 0x40;
  iVar7 = 0;
  lVar6 = *(long *)(param_1 + 0x1b0);
  local_40[0] = *(undefined8 *)(lVar6 + 0x118);
  uVar3 = *(undefined8 *)(g_pSys + 0x210);
  while( true ) {
    uVar5 = dispapiSetUnicastAndSynchronize_KERNEL
                      (lVar6,*(undefined8 *)(lVar6 + 0x120),local_40,0,*param_2);
    if ((int)uVar5 != 0) {
      return uVar5;
    }
    uVar2 = param_2[2];
    if ((uVar2 != 0) && ((uVar2 - 1 & uVar2) == 0)) {
      pfmUpdateAcpiIdMapping_IMPL(uVar3,local_40[0],param_2[1],uVar2,param_2[3],iVar7);
      uVar5 = uVar5 & 0xffffffff;
      iVar7 = iVar7 + 1;
    }
    param_2 = param_2 + 4;
    if (param_2 == puVar1) break;
    lVar6 = *(long *)(param_1 + 0x1b0);
  }
  return uVar5;
}


// ===== 00306500 dispcmnCtrlCmdSystemAcpiSubsystemActivated_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int dispcmnCtrlCmdSystemAcpiSubsystemActivated_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  long local_20 [2];
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  lVar1 = *(long *)(param_1 + 0x1b0);
  lVar2 = *(long *)(lVar1 + 0x118);
  local_20[0] = lVar2;
  iVar4 = dispapiSetUnicastAndSynchronize_KERNEL
                    (lVar1,*(undefined8 *)(lVar1 + 0x120),local_20,0,*param_2);
  if (iVar4 == 0) {
    *(undefined1 *)(*(long *)(local_20[0] + 0x1b48) + 0x48) = 0;
    iVar5 = (**(code **)(lVar2 + 0x3b90))
                      (lVar2 + 0x3b58,*(undefined4 *)(local_20[0] + 0x3b34),
                       *(undefined4 *)(local_20[0] + 0x3b3c),0x20800af0,0,0);
    iVar4 = 0;
    if (iVar5 != 0) {
      nvDbg_Printf("src/kernel/gpu/disp/disp_common_ctrl_acpi.c",0x88,
                   "dispcmnCtrlCmdSystemAcpiSubsystemActivated_IMPL",1,
                   "NVRM: ERROR: NV0073_CTRL_SYSTEM_ACPI_SUBSYSTEM_ACTIVATED control call failed. Should be rmapi ctrl call which is failed"
                  );
      return iVar5;
    }
  }
  return iVar4;
}


// ===== 003065da dispcmnCtrlCmdSystemExecuteAcpiMethod_IMPL.cold =====

void dispcmnCtrlCmdSystemExecuteAcpiMethod_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003065f0 dispcmnCtrlCmdSystemExecuteAcpiMethod_IMPL =====

uint dispcmnCtrlCmdSystemExecuteAcpiMethod_IMPL(long param_1,uint *param_2)

{
  ushort uVar1;
  uint uVar2;
  long lVar3;
  code *pcVar4;
  uint uVar5;
  long lVar6;
  undefined8 uVar7;
  ushort uVar8;
  ushort local_46;
  undefined4 local_44;
  undefined4 local_40;
  uint local_3c [3];
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  local_46 = (ushort)param_2[8];
  uVar2 = *param_2;
  local_44 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x1b0) + 0x118);
  local_40 = 0;
  uVar1 = (ushort)param_2[4];
  uVar7 = *(undefined8 *)(g_pSys + 0x210);
  if (((local_46 == 0) || (*(long *)(param_2 + 2) == 0)) || (*(long *)(param_2 + 6) == 0)) {
    nvDbg_Printf("src/kernel/gpu/disp/disp_common_ctrl_acpi.c",0xb9,
                 "dispcmnCtrlCmdSystemExecuteAcpiMethod_IMPL",4,
                 "NVRM: ERROR: NV0073_CTRL_CMD_SYSTEM_EXECUTE_ACPI_METHOD: Parameter validation failed: outDataSize=%d  inDataSize=%ud  method = %ud\n"
                 ,local_46,(uint)uVar1,uVar2);
    return 0x1f;
  }
  uVar5 = (uint)local_46;
  if (local_46 < uVar1) {
    uVar5 = (uint)uVar1;
  }
  uVar8 = (ushort)uVar5;
  lVar6 = portMemAllocNonPaged(uVar5);
  if (lVar6 == 0) {
    uVar5 = 0x51;
    nvDbg_Printf("src/kernel/gpu/disp/disp_common_ctrl_acpi.c",0xc6,
                 "dispcmnCtrlCmdSystemExecuteAcpiMethod_IMPL",4,
                 "NVRM: ERROR: NV0073_CTRL_CMD_SYSTEM_EXECUTE_ACPI_METHOD: mem alloc failed\n");
    goto LAB_00306a90;
  }
  if (uVar1 != 0) {
    portMemCopy(lVar6,uVar1,*(undefined8 *)(param_2 + 2),uVar1);
  }
  if (uVar2 == 0x1d) {
    uVar5 = osCallACPI_DSM(lVar3,2,4,lVar6,&local_46);
    goto LAB_00306a30;
  }
  if (uVar2 < 0x1e) {
    if (uVar2 == 0xf) {
      uVar5 = osCallACPI_DSM(lVar3,1,4,lVar6,&local_46);
LAB_00306a30:
      if (uVar5 == 0) goto LAB_00306a3d;
    }
    else {
      if (0xf < uVar2) {
        if (uVar2 == 0x16) {
          uVar5 = osCallACPI_DSM(lVar3,1,0xb,lVar6,&local_46);
        }
        else if (uVar2 < 0x17) {
          if (uVar2 == 0x13) {
            uVar5 = osCallACPI_DSM(lVar3,1,8,lVar6,&local_46);
          }
          else if (uVar2 < 0x14) {
            if (uVar2 == 0x11) {
              uVar7 = 6;
              if (*(char *)(lVar3 + 0x4ab) == '\0') {
LAB_00306da4:
                uVar5 = osCallACPI_DSM(lVar3,1,uVar7,lVar6,&local_46);
              }
              else {
                uVar5 = osCallACPI_DSM(lVar3,2,6,lVar6,&local_46);
              }
            }
            else if (uVar2 == 0x12) {
              uVar5 = osCallACPI_DSM(lVar3,1,7,lVar6,&local_46);
            }
            else {
              uVar7 = 5;
              if (*(char *)(lVar3 + 0x4ab) == '\0') goto LAB_00306da4;
              uVar5 = osCallACPI_DSM(lVar3,2,5,lVar6,&local_46);
            }
          }
          else if (uVar2 == 0x14) {
            uVar5 = osCallACPI_DSM(lVar3,1,9,lVar6,&local_46);
          }
          else {
            uVar5 = osCallACPI_DSM(lVar3,1,10,lVar6,&local_46);
          }
        }
        else if (uVar2 == 0x1a) {
          uVar5 = osCallACPI_DSM(lVar3,2,0,lVar6,&local_46);
        }
        else if (uVar2 < 0x1b) {
          if (uVar2 == 0x18) {
            uVar5 = osCallACPI_DSM(lVar3,1,0xd,lVar6,&local_46);
          }
          else if (uVar2 == 0x19) {
            if (uVar8 < 4) goto LAB_00306ae0;
            portMemCopy(&local_44,4,lVar6,4);
            local_46 = 4;
            uVar5 = osCallACPI_NVHG_DCS(lVar3,local_44,lVar6);
          }
          else {
            uVar5 = osCallACPI_DSM(lVar3,1,0xc,lVar6,&local_46);
          }
        }
        else if (uVar2 == 0x1b) {
          uVar5 = osCallACPI_DSM(lVar3,2,0x18,lVar6,&local_46);
        }
        else {
          uVar5 = osCallACPI_DSM(lVar3,2,0x10,lVar6,&local_46);
        }
        goto LAB_00306a30;
      }
      if (uVar2 == 8) {
        if (uVar8 < 8) goto LAB_00306ae0;
        portMemCopy(&local_44,4,lVar6 + 4,4);
        local_44 = pfmFindAcpiId_IMPL(uVar7,lVar3,local_40);
        local_46 = 4;
        uVar5 = osCallACPI_NVHG_DOS(lVar3,local_44,lVar6);
        goto LAB_00306a30;
      }
      if (8 < uVar2) {
        if (uVar2 == 0xc) {
          uVar5 = osCallACPI_DSM(lVar3,1,1,lVar6,&local_46);
        }
        else if (uVar2 < 0xd) {
          if (uVar2 == 10) {
            local_3c[0] = uVar5;
            uVar5 = osCallACPI_DOD(lVar3,lVar6,local_3c);
            local_46 = (ushort)local_3c[0];
          }
          else if (uVar2 == 0xb) {
            uVar5 = osCallACPI_DSM(lVar3,1,0,lVar6,&local_46);
          }
          else {
            if ((uVar8 < 8) || (uVar5 < *(uint *)(lVar6 + 4))) goto LAB_00306ae0;
            local_46 = (ushort)*(uint *)(lVar6 + 4);
            uVar5 = osCallACPI_NVHG_ROM(lVar3,lVar6,lVar6);
          }
        }
        else if (uVar2 == 0xd) {
          uVar5 = osCallACPI_DSM(lVar3,1,2,lVar6,&local_46);
        }
        else {
          uVar5 = osCallACPI_DSM(lVar3,1,3,lVar6,&local_46);
        }
        goto LAB_00306a30;
      }
      if (uVar2 == 5) {
        if (uVar8 < 4) goto LAB_00306ae0;
        local_46 = 4;
        uVar5 = osCallACPI_NVHG_GPUSTA(lVar3,lVar6);
        goto LAB_00306a30;
      }
      if (uVar2 < 6) {
        if (uVar2 == 3) {
          if (3 < uVar8) {
            local_46 = 4;
            uVar5 = osCallACPI_NVHG_GPUON(lVar3,lVar6);
            goto LAB_00306a30;
          }
        }
        else if (uVar2 == 4) {
          if (3 < uVar8) {
            local_46 = 4;
            uVar5 = osCallACPI_NVHG_GPUOFF(lVar3,lVar6);
            goto LAB_00306a30;
          }
        }
        else {
          if (uVar2 != 2) goto LAB_00306f94;
          if (4 < uVar8) {
            portMemCopy(&local_40,4,lVar6 + 1,4);
            local_44 = pfmFindAcpiId_IMPL(uVar7,lVar3,local_40);
            local_46 = 4;
            uVar5 = osCallACPI_MXMX(lVar3,local_44,lVar6);
            goto LAB_00306a30;
          }
        }
      }
      else if (uVar2 == 6) {
        if (7 < uVar8) {
          portMemCopy(&local_44,4,lVar6 + 4,4);
          local_46 = 4;
          uVar5 = osCallACPI_NVHG_MXDS(lVar3,local_44,lVar6);
          goto LAB_00306a30;
        }
      }
      else if (7 < uVar8) {
        portMemCopy(&local_44,4,lVar6 + 4,4);
        local_44 = pfmFindAcpiId_IMPL(uVar7,lVar3,local_40);
        local_46 = 4;
        uVar5 = osCallACPI_NVHG_MXMX(lVar3,local_44,lVar6);
        goto LAB_00306a30;
      }
LAB_00306ae0:
      uVar5 = 0x1f;
    }
LAB_00306ae6:
    nvDbg_Printf("src/kernel/gpu/disp/disp_common_ctrl_acpi.c",0x2eb,
                 "dispcmnCtrlCmdSystemExecuteAcpiMethod_IMPL",1,
                 "NVRM: ERROR: NV0073_CTRL_CMD_SYSTEM_EXECUTE_ACPI_METHOD: Execution failed for method: 0x%x, status=0x%x\n"
                 ,uVar2,uVar5);
    param_2[5] = uVar5;
  }
  else {
    if (uVar2 == 0x2f) {
      uVar5 = osCallACPI_DSM(lVar3,*(undefined4 *)(lVar3 + 0x21ec),*(undefined4 *)(lVar3 + 0x220c),
                             lVar6,&local_46);
      goto LAB_00306a30;
    }
    if (uVar2 < 0x30) {
      if (uVar2 == 0x24) {
        uVar7 = 0x10;
        goto LAB_00306da4;
      }
      if (uVar2 < 0x25) {
        if (uVar2 == 0x21) {
          uVar5 = osCallACPI_DSM(lVar3,2,0x12,lVar6,&local_46);
        }
        else if (uVar2 < 0x22) {
          if (uVar2 == 0x1f) {
            uVar5 = osCallACPI_DSM(lVar3,2,6,lVar6,&local_46);
          }
          else {
            if (uVar2 == 0x20) {
              uVar5 = 0x56;
              nvAssertFailed(&DAT_00d0d52f,"generated/g_kern_disp_nvoc.h",0x46f);
              goto LAB_00306ae6;
            }
            uVar5 = osCallACPI_DSM(lVar3,2,5,lVar6,&local_46);
          }
        }
        else if (uVar2 == 0x22) {
          uVar5 = osCallACPI_DSM(lVar3,1,0xe,lVar6,&local_46);
        }
        else {
          uVar5 = osCallACPI_DSM(lVar3,1,0xf,lVar6,&local_46);
        }
      }
      else if (uVar2 == 0x2c) {
        uVar5 = osCallACPI_DSM(lVar3,*(undefined4 *)(lVar3 + 0x21dc),*(undefined4 *)(lVar3 + 0x21fc)
                               ,lVar6,&local_46);
      }
      else if (uVar2 < 0x2d) {
        if (uVar2 == 0x2a) {
          uVar5 = osCallACPI_DSM(lVar3,*(undefined4 *)(lVar3 + 0x21d4),
                                 *(undefined4 *)(lVar3 + 0x21f4),lVar6,&local_46);
        }
        else if (uVar2 == 0x2b) {
          uVar5 = osCallACPI_DSM(lVar3,*(undefined4 *)(lVar3 + 0x21d8),
                                 *(undefined4 *)(lVar3 + 0x21f8),lVar6,&local_46);
        }
        else {
          if (uVar2 != 0x25) goto LAB_00306f94;
          uVar5 = osCallACPI_DSM(lVar3,1,0x11,lVar6,&local_46);
        }
      }
      else if (uVar2 == 0x2d) {
        uVar5 = osCallACPI_DSM(lVar3,*(undefined4 *)(lVar3 + 0x21e0),*(undefined4 *)(lVar3 + 0x2200)
                               ,lVar6,&local_46);
      }
      else {
        uVar5 = osCallACPI_DSM(lVar3,*(undefined4 *)(lVar3 + 0x21e4),*(undefined4 *)(lVar3 + 0x2204)
                               ,lVar6,&local_46);
      }
      goto LAB_00306a30;
    }
    if (uVar2 == 0x3a) {
      uVar5 = osCallACPI_DSM(lVar3,*(undefined4 *)(lVar3 + 0x21f0),*(undefined4 *)(lVar3 + 0x2210),
                             lVar6,&local_46);
      goto LAB_00306a30;
    }
    if (0x3a < uVar2) {
      if (uVar2 == 0x3e) {
        if (uVar8 < 8) goto LAB_00306ae0;
        portMemCopy(&local_44,4,lVar6 + 4,4);
        local_46 = 4;
        uVar5 = osCallACPI_MXID(lVar3,local_44,lVar6);
      }
      else {
        if (uVar2 < 0x3f) {
          if (uVar2 == 0x3c) {
            if (7 < uVar8) {
              portMemCopy(&local_44,4,lVar6 + 4,4);
              local_46 = 4;
              uVar5 = osCallACPI_MXDS(lVar3,local_44,lVar6);
              goto LAB_00306a30;
            }
          }
          else {
            if (uVar2 != 0x3d) goto LAB_00306f94;
            if (7 < uVar8) {
              portMemCopy(&local_44,4,lVar6 + 4,4);
              uVar5 = osCallACPI_MXDM(lVar3,local_44,lVar6);
              local_46 = 4;
              goto LAB_00306a30;
            }
          }
          goto LAB_00306ae0;
        }
        if (uVar2 == 0x3f) {
          if (uVar8 < 8) goto LAB_00306ae0;
          portMemCopy(&local_44,4,lVar6 + 4,4);
          uVar5 = osCallACPI_LRST(lVar3,local_44,lVar6);
          local_46 = 4;
        }
        else {
          if (uVar2 != 0x40) {
LAB_00306f94:
            uVar5 = 0x1f;
            nvDbg_Printf("src/kernel/gpu/disp/disp_common_ctrl_acpi.c",0x2e0,
                         "dispcmnCtrlCmdSystemExecuteAcpiMethod_IMPL",4,
                         "NVRM: ERROR: NV0073_CTRL_CMD_SYSTEM_EXECUTE_ACPI_METHOD: Unrecognized Api Code: 0x%x\n"
                         ,uVar2);
            goto LAB_00306a90;
          }
          uVar5 = 0x1f;
          if (uVar8 < 8) goto LAB_00306ae6;
          portMemCopy(&local_44,4,lVar6 + 4,4);
          local_3c[0] = (uint)local_46;
          uVar5 = osCallACPI_DDC(lVar3,local_44,lVar6,local_3c,1);
          local_46 = (ushort)local_3c[0];
        }
      }
      goto LAB_00306a30;
    }
    if (uVar2 == 0x37) {
      uVar5 = osCallACPI_DSM(lVar3,3,0,lVar6,&local_46);
      goto LAB_00306a30;
    }
    if (0x37 < uVar2) {
      if (uVar2 == 0x38) {
        uVar5 = osCallACPI_DSM(lVar3,3,1,lVar6,&local_46);
      }
      else {
        uVar5 = osCallACPI_DSM(lVar3,3,4,lVar6,&local_46);
      }
      goto LAB_00306a30;
    }
    if (uVar2 == 0x33) {
      uVar5 = osCallACPI_OPTM_GPUON(lVar3);
      goto LAB_00306a30;
    }
    if (uVar2 == 0x36) {
      uVar5 = osCallACPI_DSM(lVar3,*(undefined4 *)(lVar3 + 0x21e8),*(undefined4 *)(lVar3 + 0x2208),
                             lVar6,&local_46);
      goto LAB_00306a30;
    }
    if (uVar2 != 0x31) goto LAB_00306f94;
    if (3 < local_46) {
      local_46 = 4;
      portMemCopy(lVar6,4,lVar3 + 0x2214,4);
    }
LAB_00306a3d:
    if ((ushort)param_2[8] < local_46) {
      uVar5 = 2;
      nvDbg_Printf("src/kernel/gpu/disp/disp_common_ctrl_acpi.c",0x2fb,
                   "dispcmnCtrlCmdSystemExecuteAcpiMethod_IMPL",4,
                   "NVRM: ERROR: NV0073_CTRL_CMD_SYSTEM_EXECUTE_ACPI_METHOD: output buffer is smaller then expected!\n"
                  );
    }
    else {
      *(ushort *)(param_2 + 8) = local_46;
      uVar5 = 0;
      portMemCopy(*(undefined8 *)(param_2 + 6),local_46,lVar6,local_46);
    }
  }
LAB_00306a90:
  portMemFree(lVar6);
  return uVar5;
}


// ===== 00307480 dispcmnCtrlCmdDfpSwitchDispMux_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int dispcmnCtrlCmdDfpSwitchDispMux_IMPL(long param_1,undefined4 *param_2)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  long *plVar4;
  code *pcVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint local_24;
  long local_20;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)invalidInstructionException();
    (*pcVar5)();
  }
  lVar2 = *(long *)(param_1 + 0x1b0);
  local_20 = *(long *)(lVar2 + 0x118);
  iVar6 = dispapiSetUnicastAndSynchronize_KERNEL
                    (lVar2,*(undefined8 *)(lVar2 + 0x120),&local_20,0,*param_2);
  lVar2 = local_20;
  if (iVar6 != 0) {
    return iVar6;
  }
  if (local_20 == 0) {
    return 0;
  }
  uVar1 = param_2[1];
  if ((uVar1 == 0) || ((uVar1 - 1 & uVar1) != 0)) {
    iVar6 = 0x1f;
LAB_0030767e:
    nvDbg_Printf("src/kernel/gpu/disp/disp_common_ctrl_acpi.c",0x386,
                 "dispcmnCtrlCmdDfpSwitchDispMux_IMPL",4,"NVRM: Invalid arguments 0x%x\n");
  }
  else {
    lVar3 = *(long *)(*(long *)(local_20 + 0x1b80) + 0x2c8);
    if (*(char *)(lVar3 + 0x1c) == '\0') {
      if (*(char *)(lVar3 + 0x1d) == '\0') {
        iVar6 = 0x56;
        goto LAB_0030767e;
      }
    }
    else if ((*(uint *)(lVar3 + 0x18) & uVar1) == 0) {
      uVar1 = param_2[2];
      local_24 = 0;
      iVar6 = pfmFindAcpiId_IMPL(*(undefined8 *)(g_pSys + 0x210),local_20);
      if (iVar6 == 0) {
        iVar6 = 0xffff;
      }
      else {
        uVar8 = local_24 & 0xfffffff0;
        local_24 = local_24 & 0xffffffe0 | 1;
        if ((uVar1 & 1) == 0) {
          local_24 = uVar8 | 0x11;
        }
        iVar6 = osCallACPI_MXDS(lVar2,iVar6,&local_24);
        if (iVar6 == 0) {
          return 0;
        }
        nvDbg_Printf("src/kernel/gpu/disp/disp_common_ctrl_acpi.c",0x335,"_dispDfpSwitchExternalMux"
                     ,4,"NVRM: osCallACPI_MXDS failed 0x%x\n");
      }
      nvDbg_Printf("src/kernel/gpu/disp/disp_common_ctrl_acpi.c",0x397,
                   "dispcmnCtrlCmdDfpSwitchDispMux_IMPL",4,"NVRM: external mux switch failed 0x%x\n"
                  );
      return iVar6;
    }
    plVar4 = *(long **)(*(long *)(param_1 + 0x188) + 0x48);
    iVar7 = (**(code **)(local_20 + 0x3b90))
                      (local_20 + 0x3b58,*(undefined4 *)(*plVar4 + 0x48),(int)plVar4[2],0x730460,
                       param_2,0x14);
    iVar6 = 0;
    if (iVar7 != 0) {
      nvDbg_Printf("src/kernel/gpu/disp/disp_common_ctrl_acpi.c",0x3a4,
                   "dispcmnCtrlCmdDfpSwitchDispMux_IMPL",4,"NVRM: internal mux switch failed 0x%x\n"
                  );
      return iVar7;
    }
  }
  return iVar6;
}


// ===== 003076e0 dispcmnCtrlCmdDfpGetDispMuxStatus_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int dispcmnCtrlCmdDfpGetDispMuxStatus_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  long *plVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  uint local_24;
  long local_20;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  iVar4 = dispapiSetUnicastAndSynchronize_KERNEL
                    (*(long *)(param_1 + 0x1b0),*(undefined8 *)(*(long *)(param_1 + 0x1b0) + 0x120),
                     &local_20,0,*param_2);
  if (iVar4 != 0) {
    return iVar4;
  }
  if (local_20 == 0) {
    return 0;
  }
  uVar7 = param_2[1];
  if ((uVar7 == 0) || ((uVar7 - 1 & uVar7) != 0)) {
    iVar4 = 0x1f;
LAB_00307816:
    nvDbg_Printf("src/kernel/gpu/disp/disp_common_ctrl_acpi.c",0x40e,
                 "dispcmnCtrlCmdDfpGetDispMuxStatus_IMPL",4,"NVRM: Invalid arguments 0x%x\n");
  }
  else {
    lVar1 = *(long *)(*(long *)(local_20 + 0x1b80) + 0x2c8);
    if (*(char *)(lVar1 + 0x1c) == '\0') {
      if (*(char *)(lVar1 + 0x1d) == '\0') {
        iVar4 = 0x56;
        goto LAB_00307816;
      }
    }
    else if ((*(uint *)(lVar1 + 0x18) & uVar7) == 0) {
      local_24 = 0;
      iVar4 = pfmFindAcpiId_IMPL(*(undefined8 *)(g_pSys + 0x210),local_20,uVar7);
      if (iVar4 == 0) {
        nvDbg_Printf("src/kernel/gpu/disp/disp_common_ctrl_acpi.c",0x3bd,
                     "_dispDfpGetExternalMuxStatus",4,"NVRM: acpiId not found for displayId 0x%x\n",
                     uVar7);
        iVar5 = 0xffff;
      }
      else {
        iVar5 = osCallACPI_MXDS(local_20,iVar4,&local_24);
        if (iVar5 == 0) {
          piVar6 = (int *)(local_20 + 0x2274);
          uVar7 = 0;
          if (*(uint *)(local_20 + 0x2270) != 0) {
            do {
              if (iVar4 == *piVar6) {
                iVar5 = *(int *)(local_20 + 0x227c + (ulong)uVar7 * 0xc);
                if (iVar5 == 0) {
                  param_2[2] = param_2[2] & 0xffffffe0 | local_24 & 3 |
                               (*(uint *)(local_20 + 0x2278 + (ulong)uVar7 * 0xc) & 7) << 2;
                  return 0;
                }
                goto LAB_00307976;
              }
              uVar7 = uVar7 + 1;
              piVar6 = piVar6 + 3;
            } while (uVar7 != *(uint *)(local_20 + 0x2270));
          }
          iVar5 = 0xffff;
LAB_00307976:
          nvDbg_Printf("src/kernel/gpu/disp/disp_common_ctrl_acpi.c",0x3d6,
                       "_dispDfpGetExternalMuxStatus",4,
                       "NVRM: ACPI lookup to get mux mode failed.\n");
        }
        else {
          nvDbg_Printf("src/kernel/gpu/disp/disp_common_ctrl_acpi.c",0x3c5,
                       "_dispDfpGetExternalMuxStatus",4,"NVRM: ACPI call to get mux state failed.\n"
                      );
        }
      }
      nvDbg_Printf("src/kernel/gpu/disp/disp_common_ctrl_acpi.c",0x41a,
                   "dispcmnCtrlCmdDfpGetDispMuxStatus_IMPL",4,
                   "NVRM: failed to get external mux status\n");
      return iVar5;
    }
    plVar2 = *(long **)(*(long *)(param_1 + 0x188) + 0x48);
    iVar4 = (**(code **)(local_20 + 0x3b90))
                      (local_20 + 0x3b58,*(undefined4 *)(*plVar2 + 0x48),(int)plVar2[2],0x730404,
                       param_2,0xc);
    if (iVar4 != 0) {
      nvDbg_Printf("src/kernel/gpu/disp/disp_common_ctrl_acpi.c",0x427,
                   "dispcmnCtrlCmdDfpGetDispMuxStatus_IMPL",4,
                   "NVRM: failed to get internal mux status\n");
    }
  }
  return iVar4;
}


// ===== 003079d9 _kheadCheckVblankCountCallback.cold =====

void _kheadCheckVblankCountCallback_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003079f0 _kheadCheckVblankCountCallback =====

undefined8 _kheadCheckVblankCountCallback(long param_1,undefined8 param_2,uint param_3)

{
  int *piVar1;
  long lVar2;
  code *pcVar3;
  
  if (param_3 < 8) {
    lVar2 = *(long *)(*(long *)(param_1 + 0x1b80) + 0x288 + (ulong)param_3 * 8);
    portSyncSpinlockAcquire(*(undefined8 *)(lVar2 + 0x138));
    piVar1 = (int *)(lVar2 + 0x130);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      *(uint *)(lVar2 + 0x114) = *(uint *)(lVar2 + 0x114) & 0xfffffffb;
    }
    portSyncSpinlockRelease(*(undefined8 *)(lVar2 + 0x138));
    return 0;
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)invalidInstructionException();
  (*pcVar3)();
}


// ===== 00307a47 dispcmnCtrlCmdSystemGetHotplugUnplugState_IMPL.cold =====

void dispcmnCtrlCmdSystemGetHotplugUnplugState_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00307a60 dispcmnCtrlCmdSystemGetHotplugUnplugState_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int dispcmnCtrlCmdSystemGetHotplugUnplugState_IMPL(long param_1,long param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  code *pcVar6;
  int iVar7;
  long *plVar8;
  undefined8 uVar9;
  long local_40 [2];
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)invalidInstructionException();
    (*pcVar6)();
  }
  plVar8 = *(long **)(*(long *)(param_1 + 0x188) + 0x48);
  uVar1 = *(undefined4 *)(plVar8[3] + 0x10);
  lVar4 = *(long *)(*(long *)(param_1 + 0x1b0) + 0x118);
  iVar7 = (**(code **)(lVar4 + 0x3b90))
                    (lVar4 + 0x3b58,*(undefined4 *)(*plVar8 + 0x48),(int)plVar8[2],0x730401,param_2,
                     0x10);
  uVar5 = *(ulong *)(param_2 + 8);
  iVar2 = *(int *)(param_2 + 8);
  iVar3 = *(int *)(param_2 + 0xc);
  *(undefined8 *)(param_2 + 8) = 0;
  if (iVar7 == 0) {
    if ((iVar2 != 0 || iVar3 != 0) &&
       (plVar8 = (long *)serverutilGetFirstClientUnderLock(), plVar8 != (long *)0x0)) {
      do {
        uVar9 = 0;
        if (*plVar8 != 0) {
          uVar9 = *(undefined8 *)(*plVar8 + 0x100);
        }
        dispcmnGetByDevice_IMPL(uVar9,uVar1,local_40);
        if (local_40[0] != 0) {
          *(ulong *)(local_40[0] + 0x1c0) =
               ~(CONCAT44(iVar2,iVar3) & *(ulong *)(local_40[0] + 0x1c0)) & uVar5 |
               *(ulong *)(local_40[0] + 0x1c0);
        }
        plVar8 = (long *)serverutilGetNextClientUnderLock(plVar8);
      } while (plVar8 != (long *)0x0);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 0x1c0);
    *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_1 + 0x1c4);
    *(undefined8 *)(param_1 + 0x1c0) = 0;
  }
  return iVar7;
}


// ===== 00307bc0 dispcmnCtrlCmdSystemAllocateDisplayBandwidth_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void dispcmnCtrlCmdSystemAllocateDisplayBandwidth_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  long *plVar2;
  code *pcVar3;
  int iVar4;
  long local_20;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  iVar4 = dispapiSetUnicastAndSynchronize_KERNEL
                    (*(long *)(param_1 + 0x1b0),*(undefined8 *)(*(long *)(param_1 + 0x1b0) + 0x120),
                     &local_20,0,*param_2);
  if (iVar4 == 0) {
    iVar4 = dispapiValidateRmctrlPriv_IMPL(local_20);
    if (iVar4 == 0) {
      lVar1 = *(long *)(local_20 + 0x1b80);
      if (*(char *)(lVar1 + 0x278) != '\0') {
        (**(code **)(lVar1 + 0x1b8))(local_20,lVar1,1,param_2[1],param_2[2]);
        return;
      }
      plVar2 = *(long **)(*(long *)(param_1 + 0x188) + 0x48);
      lVar1 = *(long *)(*(long *)(param_1 + 0x1b0) + 0x118);
      (**(code **)(lVar1 + 0x3b90))
                (lVar1 + 0x3b58,*(undefined4 *)(*plVar2 + 0x48),(int)plVar2[2],0x730157,param_2,0xc)
      ;
      return;
    }
  }
  return;
}


// ===== 00307cc0 dispcmnCtrlCmdSystemQueryUefiDisplayBandwidth_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void dispcmnCtrlCmdSystemQueryUefiDisplayBandwidth_IMPL(long param_1,undefined4 *param_2)

{
  code *pcVar1;
  int iVar2;
  long local_20 [2];
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  iVar2 = dispapiSetUnicastAndSynchronize_KERNEL
                    (*(long *)(param_1 + 0x1b0),*(undefined8 *)(*(long *)(param_1 + 0x1b0) + 0x120),
                     local_20,0,*param_2);
  if (iVar2 == 0) {
    iVar2 = dispapiValidateRmctrlPriv_IMPL(local_20[0]);
    if (iVar2 == 0) {
      (**(code **)(*(long *)(local_20[0] + 0x1b80) + 0x1c0))
                (local_20[0],*(long *)(local_20[0] + 0x1b80),param_2 + 1,param_2 + 2);
      return;
    }
  }
  return;
}


// ===== 00307d50 dispcmnCtrlCmdSystemGetVblankEnable_IMPL =====

int dispcmnCtrlCmdSystemGetVblankEnable_IMPL(long param_1,undefined4 *param_2)

{
  code *pcVar1;
  int iVar2;
  long local_20 [2];
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  iVar2 = dispapiSetUnicastAndSynchronize_KERNEL
                    (*(long *)(param_1 + 0x1b0),*(undefined8 *)(*(long *)(param_1 + 0x1b0) + 0x120),
                     local_20,0,*param_2);
  if (iVar2 != 0) {
    return iVar2;
  }
  if (((uint)param_2[1] < 8) &&
     (*(long *)(*(long *)(local_20[0] + 0x1b80) + 0x288 + (ulong)(uint)param_2[1] * 8) != 0)) {
    iVar2 = kheadReadVblankIntrState_IMPL();
    *(bool *)(param_2 + 2) = iVar2 != 0;
    return 0;
  }
  nvAssertFailedNoLog("pKernelHead != NULL","src/kernel/gpu/disp/disp_common_kern_ctrl_minimal.c",
                      0xf2);
  return 0x1f;
}


// ===== 00307e00 dispcmnCtrlCmdDpGenerateFakeInterrupt_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int dispcmnCtrlCmdDpGenerateFakeInterrupt_IMPL(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  long lVar2;
  long *plVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  undefined4 local_54;
  long local_50;
  undefined4 local_44;
  undefined4 local_40;
  uint local_3c;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  lVar2 = *(long *)(param_1 + 0x1b0);
  uVar1 = param_2[1];
  iVar6 = param_2[2];
  local_50 = *(long *)(lVar2 + 0x118);
  iVar5 = dispapiSetUnicastAndSynchronize_KERNEL
                    (lVar2,*(undefined8 *)(lVar2 + 0x120),&local_50,0,*param_2);
  lVar2 = local_50;
  if (iVar5 != 0) {
    return iVar5;
  }
  if (param_2[1] == 0) {
    nvAssertFailedNoLog("pParams->displayId","src/kernel/gpu/disp/disp_common_kern_ctrl_minimal.c",
                        0x112);
  }
  else if (local_50 == 0) {
    nvAssertFailedNoLog(&DAT_00d0d84b,"src/kernel/gpu/disp/disp_common_kern_ctrl_minimal.c",0x113);
  }
  else {
    if (iVar6 == 0) {
      local_54 = uVar1;
      portMemSet(&local_44,0,0xc);
      plVar3 = *(long **)(*(long *)(param_1 + 0x188) + 0x48);
      iVar6 = (**(code **)(lVar2 + 0x3b90))
                        (lVar2 + 0x3b58,*(undefined4 *)(*plVar3 + 0x48),(int)plVar3[2],0x731361,
                         &local_44,0xc);
      if ((local_3c & 1) != 0 || iVar6 != 0) {
        gpuNotifySubDeviceEvent_IMPL(local_50,7,&local_54,4,0,0);
        return 0;
      }
      return 0xffff;
    }
    if (iVar6 - 1U < 2) {
      portMemSet(&local_44,0,8);
      if (iVar6 == 1) {
        local_40 = 0;
      }
      else {
        local_40 = uVar1;
        uVar1 = 0;
      }
      local_44 = uVar1;
      gpuNotifySubDeviceEvent_IMPL(local_50,1,&local_44,8,0,0);
      return 0;
    }
  }
  return 0x1f;
}


// ===== 00307fc0 dispcmnCtrlCmdVRRSetRgLineActive_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong dispcmnCtrlCmdVRRSetRgLineActive_IMPL(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  long lVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  code *pcVar6;
  uint uVar7;
  ulong uVar8;
  long local_40 [2];
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)invalidInstructionException();
    (*pcVar6)();
  }
  lVar2 = *(long *)(param_1 + 0x1b0);
  plVar3 = *(long **)(*(long *)(param_1 + 0x188) + 0x48);
  lVar4 = *(long *)(lVar2 + 0x118);
  lVar5 = *plVar3;
  uVar1 = *(undefined4 *)(plVar3[3] + 0x10);
  local_40[0] = lVar4;
  uVar8 = dispapiSetUnicastAndSynchronize_KERNEL
                    (lVar2,*(undefined8 *)(lVar2 + 0x120),local_40,0,*param_2);
  if ((int)uVar8 == 0) {
    if ((*(char *)(param_2 + 1) != '\0') &&
       (uVar7 = memRegisterWithGsp_IMPL(local_40[0],lVar5,uVar1,param_2[6]), uVar7 != 0)) {
      nvCheckOkFailedNoLog
                (4,uVar7,"memRegisterWithGsp(pGpu, pClient, hParent, pParams->hMemory)",
                 "src/kernel/gpu/disp/disp_common_kern_ctrl_minimal.c",0x170);
      return (ulong)uVar7;
    }
    uVar8 = (**(code **)(lVar4 + 0x3b90))
                      (lVar4 + 0x3b58,*(undefined4 *)(lVar5 + 0x48),
                       *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x188) + 0x48) + 0x10),0x730402
                       ,param_2,0x1c);
  }
  return uVar8;
}


// ===== 003080ba dispcmnCtrlCmdSystemGetVblankCounter_IMPL.cold =====

void dispcmnCtrlCmdSystemGetVblankCounter_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003080d0 dispcmnCtrlCmdSystemGetVblankCounter_IMPL =====

int dispcmnCtrlCmdSystemGetVblankCounter_IMPL(long param_1,long param_2)

{
  char cVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  code *pcVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 local_3c;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)invalidInstructionException();
    (*pcVar5)();
  }
  lVar2 = *(long *)(*(long *)(param_1 + 0x1b0) + 0x118);
  lVar3 = *(long *)(lVar2 + 0x1b80);
  iVar6 = rmGpuLocksGetOwnedMask();
  if (iVar6 == 0) {
    if ((*(uint *)(param_2 + 4) < 8) &&
       (lVar4 = *(long *)(lVar3 + 0x288 + (ulong)*(uint *)(param_2 + 4) * 8), lVar4 != 0)) {
      if (*(char *)(lVar2 + 0x909) == '\0') {
        local_3c = 0x24;
      }
      else {
        local_3c = 0x10000024;
        if (*(long *)(lVar3 + 0x380) == 0) {
          nvDbg_Printf("src/kernel/gpu/disp/disp_common_kern_ctrl_minimal.c",0x1b2,
                       "dispcmnCtrlCmdSystemGetVblankCounter_IMPL",4,
                       "NVRM: no memory allocated for vblank count\n");
          return 0x56;
        }
      }
      portSyncSpinlockAcquire(*(undefined8 *)(lVar4 + 0x138));
      if (*(int *)(lVar4 + 0x130) == 0) {
        portSyncSpinlockRelease(*(undefined8 *)(lVar4 + 0x138));
        iVar6 = rmDeviceGpuLocksAcquire(lVar2,0,0x40001);
        if (iVar6 != 0) {
          nvAssertOkFailedNoLog
                    (iVar6,
                     "rmDeviceGpuLocksAcquire(pGpu, GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_DISP)",
                     "src/kernel/gpu/disp/disp_common_kern_ctrl_minimal.c",0x1ce);
          return iVar6;
        }
        *(undefined4 *)(lVar4 + 0x130) = 300;
        *(code **)(lVar4 + 0xe0) = _kheadCheckVblankCountCallback;
        *(undefined4 *)(lVar4 + 0xf4) = *(undefined4 *)(lVar4 + 0x140);
        *(undefined8 *)(lVar4 + 0xe8) = 0;
        *(undefined1 *)(lVar4 + 0xf0) = 0;
        *(undefined4 *)(lVar4 + 0xf8) = 0;
        *(undefined4 *)(lVar4 + 0x118) = 0;
        *(undefined1 *)(lVar4 + 0x129) = 1;
        *(undefined4 *)(lVar4 + 0x114) = local_3c;
        kheadAddVblankCallback_IMPL(lVar2,lVar4,lVar4 + 0xe0);
        rmDeviceGpuLocksRelease(lVar2,0,0);
        cVar1 = *(char *)(lVar2 + 0x909);
      }
      else {
        *(undefined4 *)(lVar4 + 0x130) = 300;
        portSyncSpinlockRelease(*(undefined8 *)(lVar4 + 0x138));
        cVar1 = *(char *)(lVar2 + 0x909);
      }
      iVar6 = 0;
      if (cVar1 == '\0') {
        *(undefined4 *)(param_2 + 0xc) = 0x56;
      }
      else if (*(char *)(param_2 + 8) == '\0') {
        *(undefined4 *)(param_2 + 0xc) =
             *(undefined4 *)(*(long *)(lVar3 + 0x380) + (ulong)*(uint *)(lVar4 + 0x140) * 4);
      }
      else {
        uVar7 = kheadGetVblankLowLatencyCounter_IMPL(lVar4);
        *(undefined4 *)(param_2 + 0xc) = uVar7;
      }
    }
    else {
      iVar6 = 0x1f;
      nvDbg_Printf("src/kernel/gpu/disp/disp_common_kern_ctrl_minimal.c",0x1a9,
                   "dispcmnCtrlCmdSystemGetVblankCounter_IMPL",4,"NVRM: invalid head number!\n");
    }
  }
  else {
    nvCheckFailedNoLog(4,"rmGpuLocksGetOwnedMask() == 0",
                       "src/kernel/gpu/disp/disp_common_kern_ctrl_minimal.c",0x1a4);
    iVar6 = 0x2f;
  }
  return iVar6;
}


// ===== 00308360 dispcmnCtrlCmdCalculateDpImp_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 dispcmnCtrlCmdCalculateDpImp_IMPL(long param_1,undefined4 *param_2)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  undefined8 uVar4;
  long local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  uint local_98;
  undefined4 uStack_94;
  uint local_90;
  uint local_8c;
  uint local_88;
  ulong local_80;
  long local_70;
  undefined1 local_68 [4];
  int local_64;
  uint local_60;
  undefined4 local_5c;
  undefined1 local_58;
  char local_57;
  undefined4 local_54;
  undefined8 local_50;
  undefined4 local_48;
  undefined4 local_44;
  long local_40;
  undefined4 local_38;
  int iStack_34;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  
  local_a8 = 0;
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  uVar4 = dispapiSetUnicastAndSynchronize_KERNEL
                    (*(long *)(param_1 + 0x1b0),*(undefined8 *)(*(long *)(param_1 + 0x1b0) + 0x120),
                     &local_a8,0,*param_2);
  if ((int)uVar4 != 0) {
    return uVar4;
  }
  uVar1 = param_2[1];
  if (uVar1 == 0) {
    return 0x1f;
  }
  if ((uVar1 - 1 & uVar1) != 0) {
    return 0x1f;
  }
  lVar2 = *(long *)(local_a8 + 0x1b80);
  portMemSet(local_68,0,0x50);
  portMemSet(&local_a0,0,0x38);
  local_64 = param_2[3];
  local_60 = param_2[4];
  local_58 = *(undefined1 *)(param_2 + 6);
  local_5c = CONCAT22(*(undefined2 *)((long)param_2 + 0x16),
                      *(ushort *)(param_2 + 5) << 8 | *(ushort *)(param_2 + 5) >> 8);
  if ((local_64 != 0xa2 && local_64 != 0x21c) && (local_64 != 0x32a)) {
    if (local_64 - 0xd8U < 0x37) {
      if ((0xffbffffbf7fffffeU >> ((ulong)(local_64 - 0xd8U) & 0x3f) & 1) != 0) goto LAB_00308458;
    }
    else if ((((local_64 != 0x144 && local_64 != 0x1b0) && (local_64 != 0x2a3)) &&
             ((local_64 != 500 && local_64 != 1000) && local_64 != 0x546)) && (local_64 != 2000))
    goto LAB_00308458;
  }
  if (((local_60 - 4 & 0xfffffffb) != 0) && (2 < local_60)) {
LAB_00308458:
    nvAssertFailedNoLog("(IS_VALID_DP2_X_LINKBW(dpModesetData.dp2LinkBw) && IS_VALID_LANECOUNT(dpModesetData.laneCount))"
                        ,"src/kernel/gpu/disp/disp_common_kern_ctrl_minimal.c",0x22c);
    return 0x1f;
  }
  iStack_34 = param_2[7];
  local_20 = param_2[0x12];
  local_30 = *(undefined8 *)(param_2 + 0xb);
  local_40 = (ulong)(uint)param_2[0x10] * 1000;
  local_28 = *(undefined8 *)(param_2 + 0xe);
  local_38 = param_2[0xd];
  local_57 = *(char *)(param_2 + 0x13);
  if (local_57 != '\0') {
    local_54 = param_2[0x14];
    local_50 = *(undefined8 *)(param_2 + 0x15);
    local_48 = param_2[0x18];
    local_44 = local_48;
  }
  *(undefined1 *)(param_2 + 0x1f) = 1;
  uVar4 = (**(code **)(lVar2 + 0x248))(local_a8,lVar2,param_2[2],local_68,&local_a0);
  if ((int)uVar4 != 0) {
    *(undefined1 *)(param_2 + 0x1f) = 0;
    return uVar4;
  }
  param_2[0x1a] = local_a0;
  param_2[0x1e] = (int)local_70;
  param_2[0x19] = local_9c;
  *(ulong *)(param_2 + 0x1c) = CONCAT44(uStack_94,local_98);
  param_2[0x1b] = local_90;
  if (local_90 <= (uint)((iStack_34 + local_30._4_4_) - (int)local_30)) {
    if (local_88 < local_8c) {
      local_88 = local_8c;
    }
    if ((local_88 <= local_98) && ((ulong)(local_40 * local_70) < local_80 << 8)) goto LAB_00308561;
  }
  *(undefined1 *)(param_2 + 0x1f) = 0;
LAB_00308561:
  if ((local_5c & 0xff00ff) == 0) {
    if ((local_57 != '\0') && ((ulong)(local_70 * local_40) < (local_80 & 0xffffffffffffff) << 2)) {
      *(undefined1 *)(param_2 + 0x1f) = 0;
    }
    return 0;
  }
  return uVar4;
}


// ===== 00308660 dispcmnCtrlCmdDpRetrieveDpRingBuffer_IMPL =====

undefined8 dispcmnCtrlCmdDpRetrieveDpRingBuffer_IMPL(undefined8 param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = rcdbCreateRingBuffer_IMPL
                    (*(undefined8 *)(g_pSys + 0x228),*(undefined1 *)(param_2 + 1),
                     *(undefined4 *)((long)param_2 + 0xc));
  *param_2 = uVar1;
  return 0;
}


// ===== 003086a0 dispcmnCtrlCmdSystemGetLoadVCounterInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int dispcmnCtrlCmdSystemGetLoadVCounterInfo_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  long local_20 [2];
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  iVar3 = dispapiSetUnicastAndSynchronize_KERNEL
                    (*(long *)(param_1 + 0x1b0),*(undefined8 *)(*(long *)(param_1 + 0x1b0) + 0x120),
                     local_20,0,*param_2);
  if (iVar3 == 0) {
    iVar3 = dispapiValidateRmctrlPriv_IMPL(local_20[0]);
    if (iVar3 == 0) {
      if ((uint)param_2[1] < 8) {
        lVar1 = *(long *)(*(long *)(local_20[0] + 0x1b80) + 0x288 + (ulong)(uint)param_2[1] * 8);
        if (lVar1 != 0) {
          uVar4 = (**(code **)(lVar1 + 0x80))();
          param_2[2] = uVar4;
          nvDbg_Printf("src/kernel/gpu/disp/disp_common_kern_ctrl_minimal.c",0x2ba,
                       "dispcmnCtrlCmdSystemGetLoadVCounterInfo_IMPL",1,
                       "NVRM: LoadV Counter value fetched from register is : %x\n",uVar4);
          return 0;
        }
        nvAssertFailedNoLog("pKernelHead != NULL",
                            "src/kernel/gpu/disp/disp_common_kern_ctrl_minimal.c",0x2b7);
      }
      iVar3 = 0x1f;
    }
  }
  return iVar3;
}


// ===== 003087a0 dispcmnCtrlCmdSystemGetCrashLockCounterInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int dispcmnCtrlCmdSystemGetCrashLockCounterInfo_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  long local_20 [2];
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  iVar3 = dispapiSetUnicastAndSynchronize_KERNEL
                    (*(long *)(param_1 + 0x1b0),*(undefined8 *)(*(long *)(param_1 + 0x1b0) + 0x120),
                     local_20,0,*param_2);
  if (iVar3 != 0) {
    return iVar3;
  }
  if ((uint)param_2[1] < 8) {
    lVar1 = *(long *)(*(long *)(local_20[0] + 0x1b80) + 0x288 + (ulong)(uint)param_2[1] * 8);
    if (lVar1 != 0) {
      uVar4 = (**(code **)(lVar1 + 0x88))();
      param_2[2] = uVar4;
      nvDbg_Printf("src/kernel/gpu/disp/disp_common_kern_ctrl_minimal.c",0x2ef,
                   "dispcmnCtrlCmdSystemGetCrashLockCounterInfo_IMPL",1,
                   "NVRM: Crash Lock Counter value fetched from register is : %x\n",uVar4);
      return 0;
    }
    nvAssertFailedNoLog("pKernelHead != NULL","src/kernel/gpu/disp/disp_common_kern_ctrl_minimal.c",
                        0x2eb);
  }
  return 0x1f;
}


// ===== 00308887 nvdispapiCtrlCmdGetRgConnectedLockpinStateless_IMPL.cold =====

void nvdispapiCtrlCmdGetRgConnectedLockpinStateless_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003088a0 nvdispapiCtrlCmdGetRgConnectedLockpinStateless_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong nvdispapiCtrlCmdGetRgConnectedLockpinStateless_IMPL(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  char local_42;
  char local_41;
  int local_40;
  int local_3c;
  long local_38;
  long local_30;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  lVar1 = *(long *)(*(long *)(param_1 + 0x200) + 0x118);
  lVar2 = *(long *)(lVar1 + 0x1b80);
  if (*(uint *)(lVar2 + 0x360) <= *(uint *)(param_2 + 4)) {
    nvAssertFailedNoLog("pParams->head < pKernelDisplay->numHeads",
                        "src/kernel/gpu/disp/disp_object_kern_ctrl_minimal.c",0x6d);
    return 0x1f;
  }
  uVar4 = serverutilGetResourceRef
                    (*(undefined4 *)(**(long **)(*(long *)(param_1 + 0x1d8) + 0x48) + 0x48),
                     *(undefined4 *)(param_2 + 8),&local_38);
  if (uVar4 == 0) {
    if (*(long *)(local_38 + 0x18) == 0) {
      nvAssertFailedNoLog("pPeerDisplayRef->pParentRef != NULL",
                          "src/kernel/gpu/disp/disp_object_kern_ctrl_minimal.c",0x71);
      uVar6 = 0x40;
    }
    else {
      lVar5 = __nvoc_dynamicCast(*(undefined8 *)(local_38 + 8),__nvoc_class_def_DispCommon);
      if ((lVar5 == 0) &&
         (lVar5 = __nvoc_dynamicCast(*(undefined8 *)(local_38 + 8),__nvoc_class_def_NvDispApi),
         lVar5 == 0)) {
        nvAssertFailedNoLog("(dynamicCast(pPeerDisplayRef->pResource, DispCommon) != NULL || dynamicCast(pPeerDisplayRef->pResource, NvDispApi) != NULL)"
                            ,"src/kernel/gpu/disp/disp_object_kern_ctrl_minimal.c",0x72);
        return 0x31;
      }
      uVar4 = subdeviceGetByInstance_IMPL
                        (**(undefined8 **)(*(long *)(param_1 + 0x1d8) + 0x48),
                         *(undefined4 *)(*(long *)(local_38 + 0x18) + 0x10),
                         *(undefined4 *)(param_2 + 0xc),&local_30);
      if (uVar4 == 0) {
        lVar5 = *(long *)(*(long *)(local_30 + 0x158) + 0xe0);
        if (lVar5 == 0) {
          nvAssertFailedNoLog("pPeerGpu != NULL",
                              "src/kernel/gpu/disp/disp_object_kern_ctrl_minimal.c",0x7b);
        }
        else {
          if (*(uint *)(param_2 + 0x10) < *(uint *)(*(long *)(lVar5 + 0x1b80) + 0x360)) {
            *(undefined8 *)(param_2 + 0x14) = 0;
            uVar6 = (**(code **)(lVar2 + 0x208))
                              (lVar1,lVar2,*(undefined4 *)(param_2 + 4),lVar5,
                               *(uint *)(param_2 + 0x10),&local_42,&local_40,&local_41,&local_3c);
            if ((int)uVar6 != 0) {
              nvAssertOkFailedNoLog
                        (uVar6 & 0xffffffff,"status",
                         "src/kernel/gpu/disp/disp_object_kern_ctrl_minimal.c",0x38);
              return uVar6 & 0xffffffff;
            }
            uVar4 = *(uint *)(param_2 + 0x14) & 0xfffffffe;
            if (local_42 != '\0') {
              uVar4 = local_40 * 2 & 6U | *(uint *)(param_2 + 0x14) & 0xfffffff9 | 1;
            }
            *(uint *)(param_2 + 0x14) = uVar4;
            if (local_41 != '\0') {
              *(uint *)(param_2 + 0x18) =
                   local_3c * 2 & 6U | *(uint *)(param_2 + 0x18) & 0xfffffff9 | 1;
              return uVar6;
            }
            *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfffffffe;
            return uVar6;
          }
          nvAssertFailedNoLog("pParams->peer.head < GPU_GET_KERNEL_DISPLAY(pPeerGpu)->numHeads",
                              "src/kernel/gpu/disp/disp_object_kern_ctrl_minimal.c",0x7c);
        }
        return 0x1f;
      }
      nvAssertOkFailedNoLog
                (uVar4,
                 "subdeviceGetByInstance(RES_GET_CLIENT(pNvDispApi), pPeerDisplayRef->pParentRef->hResource, pParams->peer.subdeviceIndex, &pPeerSubdevice)"
                 ,"src/kernel/gpu/disp/disp_object_kern_ctrl_minimal.c",0x77);
      uVar6 = (ulong)uVar4;
    }
  }
  else {
    nvAssertOkFailedNoLog
              (uVar4,"serverutilGetResourceRef(hClient, pParams->peer.hDisplay, &pPeerDisplayRef)",
               "src/kernel/gpu/disp/disp_object_kern_ctrl_minimal.c",0x70);
    uVar6 = (ulong)uVar4;
  }
  return uVar6;
}


// ===== 00308b8d nvdispapiCtrlCmdChannelCancelFlip_IMPL.cold =====

void nvdispapiCtrlCmdChannelCancelFlip_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00308ba0 nvdispapiCtrlCmdChannelCancelFlip_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int nvdispapiCtrlCmdChannelCancelFlip_IMPL(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  code *pcVar4;
  char cVar5;
  int iVar6;
  int local_40;
  uint local_3c [3];
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  local_40 = 8;
  local_3c[0] = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x200) + 0x118);
  lVar3 = *(long *)(lVar2 + 0x1b80);
  iVar1 = *(int *)(**(long **)(*(long *)(param_1 + 0x1d8) + 0x48) + 0x48);
  if (param_2 == 0) {
    iVar6 = 0x1f;
    nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/disp/disp_object_kern_ctrl_minimal.c",0x90
                       );
  }
  else {
    iVar6 = kdispGetIntChnClsForHwCls_IMPL(lVar3,*(undefined4 *)(param_2 + 4),&local_40);
    if (iVar6 == 0) {
      iVar6 = (**(code **)(lVar3 + 400))(lVar3,local_40,*(undefined4 *)(param_2 + 8),local_3c);
      if (iVar6 == 0) {
        if (*(char *)(*(long *)(lVar3 + 0x3a8) + (ulong)local_3c[0] * 0x18 + 0x10) == '\x01') {
          cVar5 = (**(code **)(lVar3 + 0x270))(lVar2,lVar3,local_40,*(undefined4 *)(param_2 + 8));
          if (cVar5 != '\0') {
            if ((local_40 == 3) &&
               (*(int *)(*(long *)(*(long *)(lVar3 + 0x3a8) + (ulong)local_3c[0] * 0x18) + 0x48) !=
                iVar1)) {
              nvAssertFailedNoLog(&DAT_00d0dd48,
                                  "src/kernel/gpu/disp/disp_object_kern_ctrl_minimal.c",0xb1);
              return 0x39;
            }
            (**(code **)(lVar3 + 600))(lVar2,lVar3,local_40,*(undefined4 *)(param_2 + 8),1);
            cVar5 = (**(code **)(lVar3 + 0x260))(lVar2,lVar3,local_40,*(undefined4 *)(param_2 + 8));
            if (cVar5 == '\0') {
              nvDbg_Printf("src/kernel/gpu/disp/disp_object_kern_ctrl_minimal.c",0xba,
                           "nvdispapiCtrlCmdChannelCancelFlip_IMPL",3,
                           "NVRM: disp channel not in idle state! %u %u\n",local_40,
                           *(undefined4 *)(param_2 + 8));
              nvAssertFailedNoLog(&DAT_00d0dd48,
                                  "src/kernel/gpu/disp/disp_object_kern_ctrl_minimal.c",0xbb);
            }
            (**(code **)(lVar3 + 600))(lVar2,lVar3,local_40,*(undefined4 *)(param_2 + 8),0);
            return 0;
          }
          nvDbg_Printf("src/kernel/gpu/disp/disp_object_kern_ctrl_minimal.c",0xa7,
                       "nvdispapiCtrlCmdChannelCancelFlip_IMPL",3,
                       "NVRM: disp Channel not allocated by HW yet!\n");
        }
        else {
          nvDbg_Printf("src/kernel/gpu/disp/disp_object_kern_ctrl_minimal.c",0x9f,
                       "nvdispapiCtrlCmdChannelCancelFlip_IMPL",3,
                       "NVRM: disp Channel not allocated by RM yet!\n");
        }
      }
      iVar6 = 0x21;
    }
  }
  return iVar6;
}


// ===== 00308e20 _dispapiNotifierInit.constprop.0 =====

undefined8 _dispapiNotifierInit_constprop_0(long param_1,uint param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  ulong uVar3;
  long *plVar4;
  long *plVar5;
  
  *(uint *)(param_1 + 0x170) = param_2;
  plVar5 = (long *)(param_1 + 0x130);
  while( true ) {
    puVar2 = (undefined4 *)portMemAllocNonPaged((ulong)param_2 * 4);
    *plVar5 = (long)puVar2;
    plVar4 = (long *)(param_1 + 0x130);
    if (puVar2 == (undefined4 *)0x0) {
      do {
        plVar5 = plVar4 + 1;
        portMemFree(*plVar4);
        *plVar4 = 0;
        plVar4 = plVar5;
      } while (plVar5 != (long *)(param_1 + 0x170));
      return 0x1a;
    }
    if ((*(int *)(param_1 + 0x170) != 0) && (*puVar2 = 0, 1 < *(uint *)(param_1 + 0x170))) {
      uVar3 = 1;
      do {
        uVar1 = (int)uVar3 + 1;
        *(undefined4 *)(*plVar5 + uVar3 * 4) = 0;
        uVar3 = (ulong)uVar1;
      } while (uVar1 < *(uint *)(param_1 + 0x170));
    }
    plVar5 = plVar5 + 1;
    if (plVar5 == (long *)(param_1 + 0x170)) break;
    param_2 = *(uint *)(param_1 + 0x170);
  }
  return 0;
}


// ===== 00308f10 dispapiConstruct_IMPL =====

int dispapiConstruct_IMPL(long param_1,long param_2,long param_3)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 local_39;
  undefined1 local_38 [8];
  long local_30 [2];
  
  uVar3 = *(undefined8 *)(param_2 + 0x10);
  cVar1 = rmapiLockIsOwner();
  if (cVar1 != '\0') {
    iVar2 = gpuGetByRef(uVar3,&local_39,local_30);
    if (iVar2 == 0) {
      if (local_30[0] == 0) {
        iVar2 = 0x40;
        nvAssertFailedNoLog("pGpu != NULL","src/kernel/gpu/disp/disp_objs.c",0x4b);
      }
      else if ((*(char *)(local_30[0] + 0x45a) == '\0') || (**(int **)(param_3 + 0x38) != 0)) {
        iVar2 = gpuGetClassByClassId_IMPL(local_30[0],*(undefined4 *)(param_3 + 0xc),local_38);
        if (iVar2 == 0) {
          if (*(long *)(local_30[0] + 0x1b80) == 0) {
            iVar2 = 0x56;
          }
          else {
            *(undefined8 *)(param_1 + 0x130) = 0;
            *(undefined8 *)(param_1 + 0x138) = 0;
            *(undefined8 *)(param_1 + 0x140) = 0;
            *(undefined8 *)(param_1 + 0x148) = 0;
            *(undefined8 *)(param_1 + 0x150) = 0;
            *(undefined8 *)(param_1 + 0x158) = 0;
            *(undefined8 *)(param_1 + 0x160) = 0;
            *(undefined8 *)(param_1 + 0x168) = 0;
            *(undefined8 *)(param_1 + 0x118) = 0;
            uVar3 = gpumgrGetGpuGrpFromGpu();
            *(undefined8 *)(param_1 + 0x120) = uVar3;
            *(undefined1 *)(param_1 + 0x128) = local_39;
            iVar2 = 0;
          }
        }
        else {
          iVar2 = 0x22;
          nvDbg_Printf("src/kernel/gpu/disp/disp_objs.c",0x5b,"dispapiConstruct_IMPL",3,
                       "NVRM: bad class 0x%x\n",*(undefined4 *)(param_3 + 0xc));
        }
      }
      else {
        iVar2 = 0x1b;
        nvDbg_Printf("src/kernel/gpu/disp/disp_objs.c",0x50,"dispapiConstruct_IMPL",4,
                     "NVRM: Failure allocating display class 0x%08x: Only root(admin)/kernel clients are allowed\n"
                     ,*(undefined4 *)(param_3 + 0xc));
      }
    }
    return iVar2;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/disp/disp_objs.c",0x43);
  return 0x2f;
}


// ===== 00309110 dispapiDestruct_IMPL =====

void dispapiDestruct_IMPL(long param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar1 = (undefined8 *)(param_1 + 0x130);
  do {
    puVar2 = puVar1 + 1;
    portMemFree(*puVar1);
    *puVar1 = 0;
    puVar1 = puVar2;
  } while (puVar2 != (undefined8 *)(param_1 + 0x170));
  return;
}


// ===== 0030914e dispobjConstructHal_IMPL.cold =====

void dispobjConstructHal_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00309160 dispobjConstructHal_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong dispobjConstructHal_IMPL(long param_1,long param_2)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  uVar6 = 0;
  if (param_1 != 0) {
    uVar6 = *(undefined8 *)(param_1 + 0x1b0);
  }
  lVar3 = __nvoc_dynamicCast(*(undefined8 *)(*(long *)(*(long *)(param_2 + 0x10) + 0x18) + 8),
                             __nvoc_class_def_Device);
  if (lVar3 != 0) {
    lVar3 = *(long *)(*(long *)(lVar3 + 0x128) + 0xe0);
    uVar2 = (**(code **)(*(long *)(lVar3 + 0x1b80) + 0x180))
                      (lVar3,*(long *)(lVar3 + 0x1b80),
                       *(undefined4 *)(*(long *)(param_2 + 0x10) + 0x11c));
    if (uVar2 == 0) {
      lVar3 = __nvoc_dynamicCast(uVar6,__nvoc_class_def_NvDispApi);
      uVar7 = 3;
      if (lVar3 == 0) {
        uVar7 = 1;
      }
      uVar4 = _dispapiNotifierInit_constprop_0(uVar6,uVar7);
      return uVar4;
    }
    lVar5 = gpumgrGetParentGPU(lVar3);
    if (lVar3 != lVar5) {
      nvAssertFailedNoLog("gpumgrIsParentGPU(pGpu)","src/kernel/gpu/disp/disp_objs.c",0xc6);
    }
    return (ulong)uVar2;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00309260 dispobjConstruct_IMPL =====

undefined8 dispobjConstruct_IMPL(long param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  
  *(undefined4 *)(param_1 + 0x1c0) = 0;
  if (**(int **)(param_3 + 0x38) != 0) {
    uVar1 = dispobjConstructHal_IMPL();
    return uVar1;
  }
  nvDbg_Printf("src/kernel/gpu/disp/disp_objs.c",0xeb,"dispobjConstruct_IMPL",4,
               "NVRM: Failure allocating display class 0x%08x: Only root(admin)/kernel clients are allowed\n"
               ,*(undefined4 *)(param_3 + 0xc));
  osAssertFailed();
  return 0x1b;
}


// ===== 003092ba dispobjGetByDevice_IMPL.cold =====

void dispobjGetByDevice_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003092d0 dispobjGetByDevice_IMPL =====

int dispobjGetByDevice_IMPL(undefined8 param_1,long param_2,long *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  long local_20;
  
  if (param_2 != 0) {
    iVar2 = refFindChildOfType(*(undefined8 *)(*(long *)(param_2 + 0x110) + 0x48),0x999839,0,
                               &local_20);
    if (iVar2 == 0) {
      lVar3 = __nvoc_dynamicCast(*(undefined8 *)(local_20 + 8),__nvoc_class_def_DispObject);
      *param_3 = lVar3;
      if (lVar3 == 0) {
        iVar2 = 0x33;
      }
    }
    return iVar2;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00309340 dispapiSetUnicastAndSynchronize_KERNEL =====

long dispapiSetUnicastAndSynchronize_KERNEL
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4,
               undefined4 param_5)

{
  long lVar1;
  
  lVar1 = gpugrpGetGpuFromSubDeviceInstance_IMPL(param_2,param_5);
  if ((int)lVar1 == 0) {
    lVar1 = (ulong)(param_4 != 0) << 6;
  }
  return lVar1;
}


// ===== 00309370 dispapiControl_Prologue_IMPL.cold =====

void dispapiControl_Prologue_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00309380 dispapiControl_Prologue_IMPL =====

undefined8 dispapiControl_Prologue_IMPL(long param_1,long param_2,long param_3)

{
  code *pcVar1;
  long lVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  long lVar5;
  
  lVar5 = 0;
  if (param_1 != 0) {
    lVar5 = *(long *)(param_1 + 0xf8);
  }
  lVar2 = __nvoc_dynamicCast(param_1,__nvoc_class_def_DispCommon);
  if (lVar2 != 0) {
    lVar2 = __nvoc_dynamicCast(*(undefined8 *)(*(long *)(*(long *)(param_2 + 0x10) + 0x18) + 8),
                               __nvoc_class_def_Device);
    if (lVar2 == 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    lVar2 = *(long *)(lVar2 + 0x128);
    *(undefined4 *)(lVar5 + 0xa0) = *(undefined4 *)(*(long *)(lVar2 + 0xe0) + 0x7a4);
    uVar3 = *(undefined8 *)(lVar2 + 0xe0);
LAB_003093ff:
    *(undefined8 *)(param_1 + 0x118) = uVar3;
    uVar3 = rmresControl_Prologue_IMPL(lVar5,param_2,param_3);
    return uVar3;
  }
  lVar2 = __nvoc_dynamicCast(param_1,__nvoc_class_def_NvDispApi);
  if (lVar2 == 0) {
    __nvoc_dynamicCast(param_1,__nvoc_class_def_DispSwObj);
    puVar4 = *(undefined4 **)(param_3 + 0x10);
  }
  else {
    puVar4 = *(undefined4 **)(param_3 + 0x10);
  }
  if ((puVar4 == (undefined4 *)0x0) || (*(uint *)(param_3 + 0x18) < 4)) {
    uVar3 = 0x3a;
  }
  else {
    uVar3 = gpugrpGetGpuFromSubDeviceInstance_IMPL
                      (*(undefined8 *)(param_3 + 0x28),*puVar4,param_3 + 0x20);
    if ((int)uVar3 == 0) {
      *(undefined4 *)(lVar5 + 0xa0) = *(undefined4 *)(*(long *)(param_3 + 0x20) + 0x7a4);
      uVar3 = *(undefined8 *)(param_3 + 0x20);
      goto LAB_003093ff;
    }
  }
  return uVar3;
}


// ===== 00309495 dispapiControl_Epilogue_IMPL.cold =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void dispapiControl_Epilogue_IMPL_cold(void)

{
  code *pcVar1;
  
  _DAT_000000a0 = 0;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003094a0 dispapiControl_Epilogue_IMPL =====

void dispapiControl_Epilogue_IMPL(long param_1)

{
  long lVar1;
  
  if (param_1 == 0) {
    lVar1 = __nvoc_dynamicCast(0,__nvoc_class_def_DispCommon);
    if (lVar1 == 0) {
      dispapiControl_Epilogue_IMPL_cold();
      return;
    }
  }
  else {
    lVar1 = __nvoc_dynamicCast(param_1,__nvoc_class_def_DispCommon);
    if (lVar1 == 0) {
      *(undefined4 *)(*(long *)(param_1 + 0xf8) + 0xa0) = 0xffffffff;
    }
  }
  *(undefined8 *)(param_1 + 0x118) = 0;
  return;
}


// ===== 00309509 dispapiControl_IMPL.cold =====

void dispapiControl_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00309520 dispapiControl_IMPL =====

undefined4 dispapiControl_IMPL(long param_1,long param_2,long param_3)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  long lVar6;
  
  lVar6 = __nvoc_dynamicCast(*(undefined8 *)(*(long *)(*(long *)(param_2 + 0x10) + 0x18) + 8),
                             __nvoc_class_def_Device);
  if (lVar6 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  lVar6 = *(long *)(lVar6 + 0x128);
  lVar1 = *(long *)(param_3 + 0x70);
  lVar2 = *(long *)(lVar6 + 0xe0);
  uVar4 = gpumgrSetCurrentGpuInstance(*(undefined4 *)(lVar2 + 0x7a4));
  if (param_1 != 0) {
    nvDbg_Printf("src/kernel/gpu/disp/disp_objs.c",0x1c3,"dispapiControl_IMPL",1,
                 "NVRM: class: 0x%x cmd 0x%x\n",
                 *(undefined4 *)(*(long *)(*(long *)(param_1 + 0xe8) + 0x48) + 0x11c),
                 *(undefined4 *)(lVar1 + 8));
    *(long *)(lVar1 + 0x20) = lVar2;
    *(undefined8 *)(lVar1 + 0x28) = *(undefined8 *)(lVar6 + 0xd8);
    lVar6 = *(long *)(lVar2 + 0x1c20);
    if (lVar6 == 0) {
      uVar5 = resControl_IMPL(*(undefined8 *)(param_1 + 0xe8),param_2,param_3);
    }
    else {
      bitVectorClrAll_IMPL(lVar6 + 0x1528,0xb4,0x309584);
      bitVectorSet_IMPL(lVar6 + 0x1528,0xb4,0x54);
      bitVectorSet_IMPL(lVar6 + 0x1528,0xb4,2);
      bitVectorSet_IMPL(lVar6 + 0x1528,0xb4,4);
      uVar5 = resControl_IMPL(*(undefined8 *)(param_1 + 0xe8),param_2,param_3);
      bitVectorClrAll_IMPL(lVar6 + 0x1528,0xb4);
    }
    gpumgrSetCurrentGpuInstance(uVar4);
    return uVar5;
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)invalidInstructionException();
  (*pcVar3)();
}


// ===== 003096c0 dispswobjConstruct_IMPL =====

undefined8 dispswobjConstruct_IMPL(void)

{
  return 0;
}


// ===== 003096d0 dispcmnConstruct_IMPL =====

void dispcmnConstruct_IMPL(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x1b0);
  }
  *(undefined8 *)(param_1 + 0x1c0) = 0;
  _dispapiNotifierInit_constprop_0(uVar1,6);
  return;
}


// ===== 003096fa dispcmnGetByDevice_IMPL.cold =====

void dispcmnGetByDevice_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00309710 dispcmnGetByDevice_IMPL =====

void dispcmnGetByDevice_IMPL(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  long local_28;
  long local_20 [2];
  
  *param_3 = 0;
  iVar2 = deviceGetByHandle_IMPL(param_1,param_2,&local_28);
  if (iVar2 == 0) {
    if (local_28 == 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    iVar2 = refFindChildOfType(*(undefined8 *)(*(long *)(local_28 + 0x110) + 0x48),0x41f4f2,0,
                               local_20);
    if (iVar2 == 0) {
      uVar3 = __nvoc_dynamicCast(*(undefined8 *)(local_20[0] + 8),__nvoc_class_def_DispCommon);
      *param_3 = uVar3;
    }
  }
  return;
}


// ===== 00309780 nvdispapiConstruct_IMPL =====

undefined8 nvdispapiConstruct_IMPL(void)

{
  return 0;
}


// ===== 00309790 dispapiValidateRmctrlPriv_IMPL =====

byte dispapiValidateRmctrlPriv_IMPL(long param_1)

{
  char cVar1;
  long lVar2;
  
  cVar1 = *(char *)(param_1 + 0x45a);
  lVar2 = resservGetTlsCallContext();
  if (lVar2 != 0) {
    return -(*(uint *)(lVar2 + 0x28) < (cVar1 == '\0') + 1) & 0x1b;
  }
  nvAssertFailedNoLog("pCallContext != NULL","src/kernel/gpu/disp/disp_objs.c",0x2cc);
  return 0x40;
}


// ===== 00309800 dispsfConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

undefined8 dispsfConstruct_IMPL(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1b80);
  if (lVar2 != 0) {
    (**(code **)(lVar2 + 0x1a0))
              (lVar1,lVar2,param_1 + 0x138,param_1 + 0x13c,*(code **)(lVar2 + 0x1a0));
    return 0;
  }
  nvCheckFailedNoLog(4,"pKernelDisplay != NULL","src/kernel/gpu/disp/disp_sf_user.c",0x32);
  return 0x56;
}


// ===== 00309870 dispsfGetRegBaseOffsetAndSize_IMPL =====

undefined8
dispsfGetRegBaseOffsetAndSize_IMPL
          (long param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4)

{
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(param_1 + 0x138);
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = *(undefined4 *)(param_1 + 0x13c);
  }
  return 0;
}


// ===== 003098a0 kheadGetDisplayInitialized_KERNEL =====

bool kheadGetDisplayInitialized_KERNEL(long param_1,long param_2)

{
  byte extraout_AH;
  
  regRead032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x140) * 0x800 + 0x612078,0);
  return (extraout_AH & 3) != 0;
}


// ===== 003098e0 kheadReadVblankIntrEnable_KERNEL_v04_00 =====

uint kheadReadVblankIntrEnable_KERNEL_v04_00(long param_1,long param_2)

{
  uint uVar1;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x140) * 4 + 0x611d80,0);
  return uVar1 >> 1 & 1;
}


// ===== 00309910 kheadWriteVblankIntrEnable_KERNEL_v04_00 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kheadWriteVblankIntrEnable_KERNEL_v04_00(long param_1,long param_2,char param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x140) * 4 + 0x611d80,0);
  (**(code **)(param_2 + 0x70))(param_1,param_2,0);
  uVar1 = uVar2 | 2;
  if (param_3 == '\0') {
    uVar1 = uVar2 & 0xfffffffd;
  }
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x140) * 4 + 0x611d80,uVar1,0);
  return;
}


// ===== 003099b0 __pfx_kheadReadPendingRgSemIntr_v04_01 =====

void __pfx_kheadReadPendingRgSemIntr_v04_01
               (long param_1,long param_2,uint *param_3,undefined8 param_4,uint *param_5)

{
  uint uVar1;
  int iVar2;
  
  if (param_5 != (uint *)0x0) {
    uVar1 = *param_5;
    iVar2 = 0;
    do {
      if ((uVar1 >> (iVar2 + 0x10U & 0x1f) & 1) != 0) {
        *param_3 = *param_3 | 0x8000 << ((byte)iVar2 & 0x1f);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != 6);
    return;
  }
  uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x140) * 4 + 0x611c00,param_4);
  iVar2 = 0;
  do {
    if ((uVar1 >> (iVar2 + 0x10U & 0x1f) & 1) != 0) {
      *param_3 = *param_3 | 0x8000 << ((byte)iVar2 & 0x1f);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 6);
  return;
}


// ===== 003099c0 kheadReadPendingRgSemIntr_v04_01 =====

void kheadReadPendingRgSemIntr_v04_01
               (long param_1,long param_2,uint *param_3,undefined8 param_4,uint *param_5)

{
  uint uVar1;
  int iVar2;
  
  if (param_5 != (uint *)0x0) {
    uVar1 = *param_5;
    iVar2 = 0;
    do {
      if ((uVar1 >> (iVar2 + 0x10U & 0x1f) & 1) != 0) {
        *param_3 = *param_3 | 0x8000 << ((byte)iVar2 & 0x1f);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != 6);
    return;
  }
  uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x140) * 4 + 0x611c00,param_4);
  iVar2 = 0;
  do {
    if ((uVar1 >> (iVar2 + 0x10U & 0x1f) & 1) != 0) {
      *param_3 = *param_3 | 0x8000 << ((byte)iVar2 & 0x1f);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 6);
  return;
}


// ===== 00309a60 kheadHandleRgSemIntr_v04_01 =====

undefined8 kheadHandleRgSemIntr_v04_01(long param_1,long param_2,uint *param_3,undefined8 param_4)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined8 uStack_78;
  uint *puStack_70;
  undefined8 local_40 [2];
  
  uVar1 = *(undefined8 *)(param_1 + 0x1b80);
  local_40[0] = 0;
  uStack_78 = uVar1;
  puStack_70 = param_3;
  iVar2 = 0;
  do {
    while( true ) {
      uVar4 = 0x8000 << ((byte)iVar2 & 0x1f);
      if ((*param_3 & uVar4) != 0) break;
      iVar2 = iVar2 + 1;
      if (iVar2 == 6) {
        return uStack_78;
      }
    }
    iVar3 = 1 << ((byte)iVar2 + 0x10 & 0x1f);
    osDispService(*(int *)(param_2 + 0x140) * 4 + 0x611800,iVar3,puStack_70);
    puStack_70 = (uint *)0x309b2f;
    regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x140) * 4 + 0x611800,iVar3,param_4);
    *param_3 = *param_3 & ~uVar4;
    uStack_78 = 0;
    iVar3 = iVar2 + 1;
    local_40[0] = CONCAT44(iVar2,*(undefined4 *)(param_2 + 0x140));
    kdispNotifyEvent_IMPL(param_1,uVar1,1,local_40,8,0);
    iVar2 = iVar3;
  } while (iVar3 != 6);
  return 0;
}


// ===== 00309b90 kheadReadVblankIntrEnable_KERNEL_v05_02 =====

uint kheadReadVblankIntrEnable_KERNEL_v05_02(long param_1,long param_2)

{
  uint uVar1;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x140) * 4 + 0x611ef0,0);
  return uVar1 >> 1 & 1;
}


// ===== 00309bc0 kheadWriteVblankIntrEnable_KERNEL_v05_02 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kheadWriteVblankIntrEnable_KERNEL_v05_02(long param_1,long param_2,char param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x140) * 4 + 0x611ef0,0);
  (**(code **)(param_2 + 0x70))(param_1,param_2,0);
  uVar1 = uVar2 | 2;
  if (param_3 == '\0') {
    uVar1 = uVar2 & 0xfffffffd;
  }
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x140) * 4 + 0x611ef0,uVar1,0);
  return;
}


// ===== 00309c60 kheadConstruct_IMPL =====

undefined8 kheadConstruct_IMPL(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  *(undefined4 *)(param_1 + 0x134) = 0;
  uVar1 = portMemAllocatorGetGlobalNonPaged();
  lVar2 = portSyncSpinlockCreate(uVar1);
  *(long *)(param_1 + 0x138) = lVar2;
  if (lVar2 != 0) {
    return 0;
  }
  nvAssertFailedNoLog("pKernelHead->Vblank.pSpinlock != NULL",
                      "src/kernel/gpu/disp/head/kernel_head.c",0x23);
  return 0x1a;
}


// ===== 00309cd0 kheadDestruct_IMPL =====

void kheadDestruct_IMPL(long param_1)

{
  if (*(long *)(param_1 + 0x138) != 0) {
    portSyncSpinlockDestroy(*(long *)(param_1 + 0x138));
    *(undefined8 *)(param_1 + 0x138) = 0;
    return;
  }
  return;
}


// ===== 00309d10 kheadGetVblankTotalCounter_IMPL =====

undefined4 kheadGetVblankTotalCounter_IMPL(long param_1)

{
  return *(undefined4 *)(param_1 + 0xc0);
}


// ===== 00309d20 kheadSetVblankTotalCounter_IMPL =====

void kheadSetVblankTotalCounter_IMPL(long param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc0) = param_2;
  return;
}


// ===== 00309d30 kheadGetVblankLowLatencyCounter_IMPL =====

undefined4 kheadGetVblankLowLatencyCounter_IMPL(long param_1)

{
  return *(undefined4 *)(param_1 + 0xc4);
}


// ===== 00309d40 kheadSetVblankLowLatencyCounter_IMPL =====

void kheadSetVblankLowLatencyCounter_IMPL(long param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc4) = param_2;
  return;
}


// ===== 00309d50 kheadCheckVblankCallbacksQueued_IMPL =====

uint kheadCheckVblankCallbacksQueued_IMPL(long param_1,long param_2,uint param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  ulong local_30 [2];
  
  tmrGetCurrentTime_IMPL(*(undefined8 *)(param_1 + 0x1b88),local_30);
  if (param_4 == (uint *)0x0) {
    uVar2 = param_3 & 2;
    if (*(long *)(param_2 + 0xd0) == 0) {
      uVar2 = 0;
    }
  }
  else {
    *param_4 = 0;
    lVar3 = *(long *)(param_2 + 0xd0);
    if (lVar3 == 0) {
      lVar3 = *(long *)(param_2 + 0xd8);
      if (lVar3 == 0) {
        return 0;
      }
      if ((param_3 & 4) == 0) {
        return param_3 & 4;
      }
      uVar2 = 4;
      goto LAB_00309e1a;
    }
    uVar2 = param_3 & 2;
    if ((param_3 & 2) != 0) {
      iVar1 = *(int *)(param_2 + 0xc4);
      do {
        if ((*(uint *)(lVar3 + 0x34) & 0x10) == 0) {
          if ((((param_3 & 1) != 0) || ((~*(uint *)(lVar3 + 0x34) & 0x24) == 0)) ||
             (*(int *)(lVar3 + 0x1c) == iVar1 + 1)) goto LAB_00309de4;
LAB_00309dc9:
          lVar3 = *(long *)(lVar3 + 0x40);
        }
        else {
          if (local_30[0] < *(ulong *)(lVar3 + 0x28)) goto LAB_00309dc9;
LAB_00309de4:
          *param_4 = *param_4 | 2;
          lVar3 = *(long *)(lVar3 + 0x40);
        }
      } while ((lVar3 != 0) && ((*param_4 & 2) == 0));
      uVar2 = 2;
    }
  }
  lVar3 = *(long *)(param_2 + 0xd8);
  if ((lVar3 == 0) || ((param_3 & 4) == 0)) {
    return uVar2 & param_3;
  }
  uVar2 = (uVar2 | 4) & param_3;
  if (param_4 == (uint *)0x0) {
    return uVar2;
  }
LAB_00309e1a:
  iVar1 = *(int *)(param_2 + 200);
  do {
    if ((*(uint *)(lVar3 + 0x34) & 0x10) == 0) {
      if ((((param_3 & 1) != 0) || ((~*(uint *)(lVar3 + 0x34) & 0x24) == 0)) ||
         (*(int *)(lVar3 + 0x1c) == iVar1 + 1)) goto LAB_00309e5e;
LAB_00309e42:
      lVar3 = *(long *)(lVar3 + 0x40);
    }
    else {
      if (local_30[0] < *(ulong *)(lVar3 + 0x28)) goto LAB_00309e42;
LAB_00309e5e:
      *param_4 = *param_4 | 4;
      lVar3 = *(long *)(lVar3 + 0x40);
    }
    if ((lVar3 == 0) || ((*param_4 & 4) != 0)) {
      return uVar2;
    }
  } while( true );
}


// ===== 00309ed0 kheadReadVblankIntrState_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint kheadReadVblankIntrState_IMPL(undefined8 param_1,long param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
  cVar1 = (**(code **)(param_2 + 0x50))();
  if ((cVar1 != '\0') && (cVar1 = (**(code **)(param_2 + 0x58))(param_1,param_2), cVar1 != '\0')) {
    if (*(int *)(param_2 + 0x134) == 2) {
      return 2;
    }
    *(undefined4 *)(param_2 + 0x134) = 2;
    return 2;
  }
  uVar2 = *(uint *)(param_2 + 0x134);
  if ((uVar2 & 0xfffffffd) == 0) {
    cVar1 = (**(code **)(param_2 + 0x58))(param_1,param_2);
    uVar2 = (uint)(cVar1 != '\0');
    uVar3 = (uint)(cVar1 != '\0');
    if (*(uint *)(param_2 + 0x134) != uVar3) {
      *(uint *)(param_2 + 0x134) = uVar3;
      return uVar2;
    }
  }
  else if (uVar2 == 1) {
    cVar1 = (**(code **)(param_2 + 0x58))(param_1,param_2);
    if (cVar1 == '\0') {
      *(undefined4 *)(param_2 + 0x134) = 0;
      uVar2 = 0;
    }
    else {
      uVar2 = *(uint *)(param_2 + 0x134);
    }
  }
  return uVar2;
}


// ===== 00309fa0 kheadWriteVblankIntrState_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kheadWriteVblankIntrState_IMPL(undefined8 param_1,long param_2,uint param_3)

{
  uint uVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  if (2 < param_3) {
    uVar1 = *(uint *)(param_2 + 0x140);
    nvDbg_Printf("src/kernel/gpu/disp/head/kernel_head.c",0x140,"kheadWriteVblankIntrState_IMPL",4,
                 "NVRM: Unknown state %x requested on head %d.\n");
    return (ulong)uVar1;
  }
  uVar1 = *(uint *)(param_2 + 0x134);
  uVar2 = (ulong)uVar1;
  if (param_3 == 1) {
    if (uVar1 != 2) {
      *(undefined4 *)(param_2 + 0x134) = 1;
      return uVar2;
    }
    uVar3 = 0;
  }
  else if (param_3 == 2) {
    uVar3 = 1;
    if (uVar1 == 2) {
      return uVar2;
    }
  }
  else {
    if (uVar1 != 2) {
      *(undefined4 *)(param_2 + 0x134) = 0;
      return uVar2;
    }
    param_3 = 0;
    uVar3 = 0;
  }
  *(uint *)(param_2 + 0x134) = param_3;
  uVar2 = (**(code **)(param_2 + 0x60))(param_1,param_2,uVar3);
  return uVar2;
}


// ===== 0030a060 kheadProcessRgLineCallbacks_KERNEL =====

void kheadProcessRgLineCallbacks_KERNEL
               (long param_1,undefined8 param_2,undefined4 param_3,uint *param_4,uint *param_5,
               undefined1 param_6)

{
  undefined8 uVar1;
  uint uVar2;
  long lVar3;
  undefined4 local_40;
  undefined4 uStack_3c;
  
  lVar3 = 0;
  uVar1 = *(undefined8 *)(param_1 + 0x1b80);
  local_40 = 0x200;
  uVar2 = *param_4 & 0x200;
  while( true ) {
    if (uVar2 != 0) {
      kdispInvokeRgLineCallback_KERNEL(uVar1,param_3,lVar3,param_6);
      *param_5 = *param_5 | local_40;
    }
    if (lVar3 == 1) break;
    lVar3 = 1;
    uStack_3c = 0x400;
    uVar2 = *param_4 & 0x400;
    local_40 = uStack_3c;
  }
  return;
}


// ===== 0030a100 instmemGetSize_v03_00 =====

void instmemGetSize_v03_00
               (undefined8 param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4)

{
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0x10000;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0x2000;
  }
  return;
}


// ===== 0030a120 instmemGetHashTableBaseAddr_v03_00 =====

undefined8 instmemGetHashTableBaseAddr_v03_00(void)

{
  return 0;
}


// ===== 0030a130 instmemIsValid_v03_00 =====

bool instmemIsValid_v03_00(undefined8 param_1,undefined8 param_2,int param_3)

{
  return param_3 * 0x20 - 0x2000U < 0xdfff;
}


// ===== 0030a150 instmemHashFunc_v03_00 =====

undefined8
instmemHashFunc_v03_00
          (undefined8 param_1,undefined8 param_2,uint param_3,uint param_4,uint param_5,
          uint *param_6)

{
  if (param_6 != (uint *)0x0) {
    *param_6 = ((param_5 & 0xf) << 6 | param_3 >> 8 & 0x3f) ^
               ((param_3 & 0xff) << 2 | param_4 >> 0x1e) ^ param_5 >> 4 & 7 ^
               (param_4 >> 10 ^ param_4 >> 0x14 ^ param_4) & 0x3ff;
    return 0;
  }
  nvAssertFailedNoLog("pResult","src/kernel/gpu/disp/inst_mem/arch/v03/disp_inst_mem_0300.c",0x68);
  return 0x1f;
}


// ===== 0030a1e0 instmemGenerateHashTableData_v03_00 =====

uint instmemGenerateHashTableData_v03_00
               (undefined8 param_1,undefined8 param_2,uint param_3,uint param_4,int param_5)

{
  return (param_4 & 0x7ff) << 0xe | param_3 & 0x3fff | param_5 << 0x19;
}


// ===== 0030a200 instmemCommitContextDma_v03_00 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 instmemCommitContextDma_v03_00(long param_1,long param_2,long param_3)

{
  long lVar1;
  char cVar2;
  ushort uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined8 uVar7;
  long lVar8;
  uint *puVar9;
  long lVar10;
  uint uVar11;
  undefined8 local_58;
  ulong local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar7 = memdescGetMemDescFromGpu(*(undefined8 *)(param_3 + 0x210),param_1);
  local_58 = 0;
  lVar1 = *(long *)(param_1 + 0x1b78);
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  uVar4 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
  uVar4 = *(int *)(param_3 + 0x218 + (ulong)uVar4 * 4) << 4;
  if (uVar4 == 0) {
    nvAssertFailedNoLog("instoffset","src/kernel/gpu/disp/inst_mem/arch/v03/disp_inst_mem_0300.c",
                        0xa6);
    return 0x31;
  }
  lVar8 = memdescGetPhysAddr(uVar7,1,0);
  lVar10 = *(long *)(param_3 + 0x130);
  uVar3 = *(ushort *)(param_3 + 0x11e) & 3;
  if (uVar3 == 1) {
    uVar11 = 0x100000;
LAB_0030a30a:
    if (*(char *)(param_3 + 0x120) == '\0') {
      uVar11 = uVar11 | 4;
    }
    uVar6 = memdescGetAddressSpace(uVar7);
    if (uVar6 == 2) {
LAB_0030a3a0:
      uVar6 = uVar11 | 1;
    }
    else {
      if ((uVar6 & 0xfffffffd) != 1) {
        uVar5 = memdescGetAddressSpace(uVar7);
        nvDbg_Printf("src/kernel/gpu/disp/inst_mem/arch/v03/disp_inst_mem_0300.c",0xf2,
                     "instmemCommitContextDma_v03_00",4,"NVRM: Invalid address space: %d\n",uVar5);
        goto LAB_0030a366;
      }
      if ((*(char *)(param_1 + 0x45a) != '\0') || (*(char *)(param_1 + 0x4b2) != '\0'))
      goto LAB_0030a3a0;
      uVar6 = uVar11 | 3;
      if (*(int *)(param_3 + 0x124) == 0) {
        uVar6 = uVar11 | 2;
      }
    }
    local_58 = *(undefined8 *)(param_2 + 0xa0);
    local_50 = (ulong)uVar4;
    puVar9 = (uint *)memmgrMemBeginTransfer_IMPL(lVar1,&local_58,0x14,2);
    if (puVar9 == (uint *)0x0) {
      uVar7 = 0x1a;
    }
    else {
      *puVar9 = uVar6;
      lVar10 = lVar10 + lVar8;
      puVar9[1] = (uint)((ulong)lVar8 >> 8);
      puVar9[2] = (uint)((ulong)lVar8 >> 0x28);
      puVar9[3] = (uint)((ulong)lVar10 >> 8);
      puVar9[4] = (uint)((ulong)lVar10 >> 0x28);
      memmgrMemEndTransfer_IMPL(lVar1,&local_58,0x14,2);
      uVar7 = 0;
    }
  }
  else {
    if (uVar3 == 2) {
      uVar11 = 0;
      goto LAB_0030a30a;
    }
    if ((*(ushort *)(param_3 + 0x11e) & 3) != 0) {
      nvDbg_Printf("src/kernel/gpu/disp/inst_mem/arch/v03/disp_inst_mem_0300.c",0xc4,
                   "instmemCommitContextDma_v03_00",4,"NVRM: Unexpected PTE_KIND value\n");
      return 0x40;
    }
    uVar5 = memdescGetPteKindForGpu(uVar7,param_1);
    cVar2 = (**(code **)(lVar1 + 0x2a8))(lVar1,0);
    if (cVar2 == '\0') {
      cVar2 = memmgrIsSurfaceBlockLinear_TU102(lVar1,*(undefined8 *)(param_3 + 0x208),uVar5);
      uVar11 = (uint)(cVar2 != '\0') << 0x14;
      goto LAB_0030a30a;
    }
LAB_0030a366:
    uVar7 = 0x1f;
  }
  return uVar7;
}


// ===== 0030a4d0 instmemUpdateContextDma_v03_00 =====

undefined8
instmemUpdateContextDma_v03_00
          (long param_1,long param_2,long param_3,undefined8 *param_4,undefined8 *param_5,
          int param_6,int param_7)

{
  undefined8 uVar1;
  uint uVar2;
  uint *puVar3;
  undefined8 uVar4;
  undefined8 local_58;
  ulong local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar4 = *(undefined8 *)(param_1 + 0x1b78);
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  if (param_6 == 0) {
    uVar2 = gpumgrGetSubDeviceInstanceFromGpu();
    uVar2 = *(int *)(param_3 + 0x218 + (ulong)uVar2 * 4) << 4;
    if (uVar2 == 0) {
      nvAssertFailedNoLog("instoffset","src/kernel/gpu/disp/inst_mem/arch/v03/disp_inst_mem_0300.c",
                          0x132);
    }
    local_58 = *(undefined8 *)(param_2 + 0xa0);
    local_50 = (ulong)uVar2;
    puVar3 = (uint *)memmgrMemBeginTransfer_IMPL(uVar4,&local_58,0x14,6);
    if (puVar3 == (uint *)0x0) {
      uVar4 = 0x1a;
    }
    else {
      if (param_4 != (undefined8 *)0x0) {
        uVar1 = *param_4;
        puVar3[1] = (uint)((ulong)uVar1 >> 8);
        puVar3[2] = (uint)((ulong)uVar1 >> 0x28);
      }
      if (param_5 != (undefined8 *)0x0) {
        uVar1 = *param_5;
        puVar3[3] = (uint)((ulong)uVar1 >> 8);
        puVar3[4] = (uint)((ulong)uVar1 >> 0x28);
      }
      if (param_7 != 0) {
        uVar2 = *puVar3 & 0xffefffff;
        if (param_7 == 2) {
          uVar2 = *puVar3 | 0x100000;
        }
        *puVar3 = uVar2;
      }
      memmgrMemEndTransfer_IMPL(uVar4,&local_58,0x14,6);
      uVar4 = 0;
    }
    return uVar4;
  }
  return 0x1f;
}


// ===== 0030a660 _instmemClearHashEntry =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _instmemClearHashEntry(long param_1,long param_2,uint param_3)

{
  undefined8 uVar1;
  int iVar2;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  ulong local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  uVar1 = *(undefined8 *)(param_1 + 0x1b78);
  local_28 = 0;
  local_20 = 0;
  *(undefined8 *)(*(long *)(param_2 + 0xb8) + (ulong)param_3 * 0x10) = 0;
  local_40 = 0;
  *(undefined8 *)(*(long *)(param_2 + 0xb8) + 8 + (ulong)param_3 * 0x10) = 0;
  local_30 = (ulong)(*(int *)(param_2 + 0xb4) + param_3 * 8);
  local_38 = *(undefined8 *)(param_2 + 0xa0);
  local_3c = (**(code **)(param_2 + 0x60))(param_1,param_2,0,0,0);
  iVar2 = memmgrMemWrite_IMPL(uVar1,&local_38,&local_40,8,0);
  if (iVar2 == 0) {
    return;
  }
  nvAssertOkFailedNoLog
            (iVar2,
             "memmgrMemWrite(pMemoryManager, &dest, &entry, sizeof(entry), TRANSFER_FLAGS_NONE)",
             "src/kernel/gpu/disp/inst_mem/disp_inst_mem.c",0x23d);
  return;
}


// ===== 0030a720 instmemDestroy.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void instmemDestroy_isra_0(long param_1)

{
  memdescDestroy(*(undefined8 *)(param_1 + 0xa0));
  *(undefined8 *)(param_1 + 0xa0) = 0;
  memdescFree(*(undefined8 *)(param_1 + 0x98));
  memdescDestroy(*(undefined8 *)(param_1 + 0x98));
  *(undefined8 *)(param_1 + 0x98) = 0;
  if (*(undefined8 **)(param_1 + 0xc0) != (undefined8 *)0x0) {
    (*(code *)**(undefined8 **)(param_1 + 0xc0))();
    portMemFree(*(undefined8 *)(param_1 + 0xc0));
    *(undefined8 *)(param_1 + 0xc0) = 0;
  }
  portMemFree(*(undefined8 *)(param_1 + 0xb8));
  *(undefined8 *)(param_1 + 0xb8) = 0;
  return;
}


// ===== 0030a7b0 instmemConstruct_IMPL =====

undefined8 instmemConstruct_IMPL(long param_1)

{
  *(undefined8 *)(param_1 + 0xa8) = 0;
  *(undefined8 *)(param_1 + 0x98) = 0;
  *(undefined8 *)(param_1 + 0xa0) = 0;
  *(undefined8 *)(param_1 + 0xb8) = 0;
  *(undefined8 *)(param_1 + 0xc0) = 0;
  return 0;
}


// ===== 0030a7f0 instmemDestruct_IMPL =====

void instmemDestruct_IMPL(void)

{
  return;
}


// ===== 0030a800 instmemStateInitLocked_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

int instmemStateInitLocked_IMPL(long param_1,long param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  ulong uVar6;
  char cVar7;
  char *pcVar8;
  uint uVar9;
  undefined8 uVar10;
  uint uVar11;
  int local_64;
  uint local_60 [2];
  undefined8 local_58;
  ulong local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar1 = *(undefined4 *)(param_1 + 0x3b34);
  uVar2 = *(undefined4 *)(param_1 + 0x3b3c);
  (**(code **)(param_2 + 0x48))(param_1,param_2,&local_64,local_60);
  *(uint *)(param_2 + 0xb0) = local_60[0] >> 3;
  uVar4 = (**(code **)(param_2 + 0x50))(param_1,param_2);
  *(undefined4 *)(param_2 + 0xb4) = uVar4;
  lVar5 = portMemAllocNonPaged((ulong)*(uint *)(param_2 + 0xb0) << 4);
  *(long *)(param_2 + 0xb8) = lVar5;
  if (lVar5 == 0) {
    nvDbg_Printf("src/kernel/gpu/disp/inst_mem/disp_inst_mem.c",0xbd,"instmemInitHashTable",4,
                 "NVRM: Unable to allocate hash table.\n");
    nvCheckOkFailedNoLog
              (4,0x51,"instmemInitHashTable(pGpu, pInstMem, hashTableSize)",
               "src/kernel/gpu/disp/inst_mem/disp_inst_mem.c",0x179);
  }
  else {
    portMemSet(lVar5,0,(ulong)*(uint *)(param_2 + 0xb0) << 4);
    iVar3 = local_64;
    lVar5 = portMemAllocNonPaged(0xd8);
    *(long *)(param_2 + 0xc0) = lVar5;
    if (lVar5 == 0) {
      nvDbg_Printf("src/kernel/gpu/disp/inst_mem/disp_inst_mem.c",0x78,"instmemInitBitmap",4,
                   "NVRM: Unable to allocate instance memory heap manager.\n");
    }
    else {
      portMemSet(lVar5,0,0xd8);
      uVar11 = local_60[0] >> 4;
      uVar6 = (ulong)uVar11;
      uVar9 = iVar3 - local_60[0] >> 4 & 0xfffffff8;
      nvDbg_Printf("src/kernel/gpu/disp/inst_mem/disp_inst_mem.c",0x7e,"instmemInitBitmap",1,
                   "NVRM: FB Free Size       = 0x%x\n",iVar3 - local_60[0]);
      nvDbg_Printf("src/kernel/gpu/disp/inst_mem/disp_inst_mem.c",0x7f,"instmemInitBitmap",1,
                   "NVRM: FB Free Inst Base  = 0x%x\n",uVar6);
      nvDbg_Printf("src/kernel/gpu/disp/inst_mem/disp_inst_mem.c",0x80,"instmemInitBitmap",1,
                   "NVRM: FB Free Inst Max   = 0x%x\n",uVar9 + uVar11);
      constructObjEHeap(*(undefined8 *)(param_2 + 0xc0),uVar6,uVar9 + 1 + uVar11,0,
                        *(int *)(param_2 + 0xb0) + 1);
      local_58 = 1;
      local_60[1] = 0x10;
      local_50 = uVar6;
      uVar6 = (**(code **)(*(long *)(param_2 + 0xc0) + 8))
                        (*(long *)(param_2 + 0xc0),0x696e7374,local_60 + 1,&local_50,&local_58,1,1,0
                         ,0,0);
      if ((int)uVar6 == 0) {
        if (*(char *)(param_1 + 0x45a) == '\0') {
          lVar5 = *(long *)(param_1 + 0x1b78);
          if (*(char *)(param_1 + 0x909) == '\0') {
            iVar3 = *(int *)(param_2 + 0x80);
            uVar6 = (ulong)*(uint *)(param_2 + 0x84);
            cVar7 = '\0';
            if (iVar3 == 1) goto LAB_0030ab3e;
            local_64 = *(int *)(param_2 + 0x90);
          }
          else {
            *(int *)(param_2 + 0x90) = local_64;
            iVar3 = 2;
            *(undefined8 *)(param_2 + 0x88) = 0;
            *(undefined8 *)(param_2 + 0x80) = 0x200000002;
            uVar6 = 2;
          }
          iVar3 = memdescCreate(param_2 + 0xa0,param_1,local_64,0x10000,1,iVar3,uVar6,0x4000000000);
          if (iVar3 != 0) {
            nvCheckOkFailedNoLog
                      (4,iVar3,
                       "memdescCreate(&pInstMem->pInstMemDesc, pGpu, pInstMem->instMemSize, DISP_INST_MEM_ALIGN, NV_TRUE, pInstMem->instMemAddrSpace, pInstMem->instMemAttr, MEMDESC_FLAGS_MEMORY_TYPE_DISPLAY_NISO)"
                       ,"src/kernel/gpu/disp/inst_mem/disp_inst_mem.c",0x106,uVar6);
            goto LAB_0030ac0c;
          }
          memdescDescribe(*(undefined8 *)(param_2 + 0xa0),2,
                          *(long *)(param_2 + 0x88) + *(long *)(lVar5 + 0x490),
                          *(undefined4 *)(param_2 + 0x90));
LAB_0030aa83:
          uVar4 = memdescGetAddressSpace(*(undefined8 *)(param_2 + 0xa0));
          local_40 = CONCAT44(*(undefined4 *)(*(long *)(param_2 + 0xa0) + 0x74),uVar4);
          local_50 = memdescGetPhysAddr(*(long *)(param_2 + 0xa0),1,0);
          local_48 = *(undefined8 *)(*(long *)(param_2 + 0xa0) + 0x30);
          iVar3 = (**(code **)(param_1 + 0x3b90))
                            (param_1 + 0x3b58,uVar1,uVar2,0x20800a49,&local_50,0x18);
          if (iVar3 == 0) {
            return 0;
          }
          uVar10 = 0x188;
          pcVar8 = 
          "pRmApi->Control(pRmApi, hClient, hSubdevice, NV2080_CTRL_CMD_INTERNAL_DISPLAY_WRITE_INST_MEM, &ctrlParams, sizeof(ctrlParams))"
          ;
        }
        else {
          *(undefined8 *)(param_2 + 0x80) = 1;
          *(undefined8 *)(param_2 + 0x88) = 0;
          *(int *)(param_2 + 0x90) = local_64;
          cVar7 = *(char *)(param_1 + 0x45a);
LAB_0030ab3e:
          iVar3 = memdescCreate(param_2 + 0x98,param_1,local_64 + 0xf000,0x10000,cVar7 == '\0',1,
                                uVar6,0x4000000000);
          if (iVar3 == 0) {
            *(undefined4 *)(*(long *)(param_2 + 0x98) + 0x9c) = 100;
            iVar3 = memdescAlloc(*(undefined8 *)(param_2 + 0x98),uVar6);
            if (iVar3 == 0) {
              lVar5 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0x98),1,0);
              iVar3 = memdescCreateSubMem(param_2 + 0xa0,*(undefined8 *)(param_2 + 0x98),param_1,
                                          (lVar5 + 0xffffU & 0xffffffffffff0000) - lVar5,local_64);
              if (iVar3 == 0) goto LAB_0030aa83;
              nvCheckOkFailedNoLog
                        (4,iVar3,
                         "memdescCreateSubMem(&pInstMem->pInstMemDesc, pInstMem->pAllocedInstMemDesc, pGpu, offset, instMemSize)"
                         ,"src/kernel/gpu/disp/inst_mem/disp_inst_mem.c",0x13f);
            }
            else {
              nvCheckOkFailedNoLog
                        (4,iVar3,"status","src/kernel/gpu/disp/inst_mem/disp_inst_mem.c",0x139);
            }
          }
          else {
            nvCheckOkFailedNoLog
                      (4,iVar3,
                       "memdescCreate(&pInstMem->pAllocedInstMemDesc, pGpu, instMemSize + (DISP_INST_MEM_ALIGN - RM_PAGE_SIZE), DISP_INST_MEM_ALIGN, bContig, pInstMem->instMemAddrSpace, pInstMem->instMemAttr, MEMDESC_FLAGS_MEMORY_TYPE_DISPLAY_NISO)"
                       ,"src/kernel/gpu/disp/inst_mem/disp_inst_mem.c",0x12e);
          }
LAB_0030ac0c:
          uVar10 = 0x17f;
          pcVar8 = "instmemInitMemDesc(pGpu, pInstMem, instMemSize)";
        }
        nvCheckOkFailedNoLog(4,iVar3,pcVar8,"src/kernel/gpu/disp/inst_mem/disp_inst_mem.c",uVar10);
        goto LAB_0030aca7;
      }
      nvDbg_Printf("src/kernel/gpu/disp/inst_mem/disp_inst_mem.c",0xa2,"instmemInitBitmap",4,
                   "NVRM: eheapAlloc failed for instance memory heap manager.\n");
    }
    nvCheckOkFailedNoLog
              (4,0x51,"instmemInitBitmap(pGpu, pInstMem, instMemSize, hashTableSize)",
               "src/kernel/gpu/disp/inst_mem/disp_inst_mem.c",0x17c);
  }
  iVar3 = 0x51;
LAB_0030aca7:
  instmemDestroy_isra_0(param_2);
  return iVar3;
}


// ===== 0030adf0 instmemStateDestroy_IMPL =====

void instmemStateDestroy_IMPL(undefined8 param_1,undefined8 param_2)

{
  instmemDestroy_isra_0(param_2);
  return;
}


// ===== 0030ae00 instmemStateLoad_IMPL =====

byte instmemStateLoad_IMPL(undefined8 param_1,long param_2)

{
  long lVar1;
  
  if (*(int *)(param_2 + 0x80) != 1) {
    return 0;
  }
  lVar1 = memdescMapInternal(param_1,*(undefined8 *)(param_2 + 0xa0),8);
  *(long *)(param_2 + 0xa8) = lVar1;
  return -(lVar1 == 0) & 0x51;
}


// ===== 0030ae50 instmemStateUnload_IMPL =====

undefined8 instmemStateUnload_IMPL(undefined8 param_1,long param_2)

{
  if (*(long *)(param_2 + 0xa8) != 0) {
    memdescUnmapInternal(param_1,*(undefined8 *)(param_2 + 0xa0),0);
    *(undefined8 *)(param_2 + 0xa8) = 0;
    return 0;
  }
  return 0;
}


// ===== 0030ae93 instmemBindContextDma_IMPL.cold =====

void instmemBindContextDma_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0030aec0 instmemBindContextDma_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int instmemBindContextDma_IMPL(long param_1,long param_2,long param_3,long param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  code *pcVar4;
  long lVar5;
  char cVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  long *plVar11;
  uint uVar12;
  uint uVar13;
  long lVar14;
  undefined4 local_68;
  uint local_64;
  undefined8 local_60;
  undefined8 local_58;
  ulong local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar7 = gpumgrGetSubDeviceInstanceFromGpu();
  local_58 = (ulong)local_58._4_4_ << 0x20;
  iVar10 = (**(code **)(*(long *)(param_1 + 0x1b80) + 400))
                     (*(long *)(param_1 + 0x1b80),*(undefined4 *)(param_4 + 0x180),
                      *(undefined4 *)(param_4 + 0x184),&local_60);
  if (iVar10 == 0) {
    if (param_3 == 0) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)invalidInstructionException();
      (*pcVar4)();
    }
    plVar11 = *(long **)(*(long *)(param_3 + 0xe8) + 0x48);
    (**(code **)(param_2 + 0x68))
              (param_1,param_2,*(undefined4 *)(*plVar11 + 0x48),(int)plVar11[2],
               local_60 & 0xffffffff,&local_58);
  }
  uVar12 = *(uint *)(param_2 + 0xb0);
  if ((uVar12 - 1 & uVar12) != 0) {
    nvAssertFailedNoLog("!(pInstMem->nHashTableEntries & (pInstMem->nHashTableEntries - 1))",
                        "src/kernel/gpu/disp/inst_mem/disp_inst_mem.c",0x2f7);
    uVar12 = *(uint *)(param_2 + 0xb0);
  }
  if ((uint)local_58 < (uint)local_58 + uVar12) {
    uVar13 = (uint)local_58;
    do {
      plVar11 = (long *)((ulong)(uVar12 - 1 & uVar13) * 0x10 + *(long *)(param_2 + 0xb8));
      if ((param_4 == plVar11[1]) && (param_3 == *plVar11)) {
        if (param_3 != 0) {
          nvDbg_Printf("src/kernel/gpu/disp/inst_mem/disp_inst_mem.c",0x31e,
                       "instmemBindContextDma_IMPL",4,
                       "NVRM: The ctx dma (0x%x) has already been bound\n",
                       *(undefined4 *)(*(long *)(*(long *)(param_3 + 0xe8) + 0x48) + 0x10));
          return 99;
        }
                    /* WARNING: Does not return */
        pcVar4 = (code *)invalidInstructionException();
        (*pcVar4)();
      }
      uVar13 = uVar13 + 1;
    } while (uVar13 < (uint)local_58 + uVar12);
  }
  lVar1 = param_3 + (ulong)uVar7 * 4;
  if (*(int *)(lVar1 + 0x238) == 0) {
    local_60 = 2;
    local_64 = 0;
    *(undefined4 *)(lVar1 + 0x218) = 0;
    iVar10 = (**(code **)(*(long *)(param_2 + 0xc0) + 8))
                       (*(long *)(param_2 + 0xc0),0x696e7374,&local_64,&local_58,&local_60,2,2,0,0,0
                       );
    if (iVar10 != 0) {
      nvDbg_Printf("src/kernel/gpu/disp/inst_mem/disp_inst_mem.c",0x32a,"instmemBindContextDma_IMPL"
                   ,4,"NVRM: Failed to alloc space in disp inst mem for ctx dma 0x%x\n",
                   *(undefined4 *)(*(long *)(*(long *)(param_3 + 0xe8) + 0x48) + 0x10));
      return 0x51;
    }
    *(int *)(lVar1 + 0x218) = (int)local_58;
    iVar10 = (**(code **)(param_2 + 0x70))(param_1,param_2,param_3);
    if (iVar10 == 0) goto LAB_0030b079;
    nvDbg_Printf("src/kernel/gpu/disp/inst_mem/disp_inst_mem.c",0x334,"instmemBindContextDma_IMPL",4
                 ,"NVRM: Failed to commit ctx dma (0x%x) to inst mem\n",
                 *(undefined4 *)(*(long *)(*(long *)(param_3 + 0xe8) + 0x48) + 0x10));
    iVar2 = *(int *)(lVar1 + 0x218);
    if (iVar2 == 0) goto LAB_0030b2b1;
    lVar5 = *(long *)(param_2 + 0xc0);
  }
  else {
LAB_0030b079:
    uVar7 = *(uint *)(lVar1 + 0x218);
    uVar3 = *(undefined8 *)(param_1 + 0x1b78);
    plVar11 = *(long **)(*(long *)(param_3 + 0xe8) + 0x48);
    lVar5 = plVar11[2];
    uVar9 = *(undefined4 *)(*plVar11 + 0x48);
    local_58 = 0;
    local_50 = 0;
    local_48 = 0;
    local_40 = 0;
    iVar10 = (**(code **)(*(long *)(param_1 + 0x1b80) + 400))
                       (*(long *)(param_1 + 0x1b80),*(undefined4 *)(param_4 + 0x180),
                        *(undefined4 *)(param_4 + 0x184),&local_68);
    if (iVar10 == 0) {
      (**(code **)(param_2 + 0x68))
                (param_1,param_2,uVar9,
                 *(undefined4 *)(*(long *)(*(long *)(param_3 + 0xe8) + 0x48) + 0x10),local_68,
                 &local_64);
      uVar7 = uVar7 >> 1;
      if (uVar7 == 0) {
        nvDbg_Printf("src/kernel/gpu/disp/inst_mem/disp_inst_mem.c",0x280,"_instmemAddHashEntry",4,
                     "NVRM: Instance pointer is invalid!!\n");
        iVar10 = 0xffff;
      }
      else {
        cVar6 = (**(code **)(param_2 + 0x58))(param_1,param_2,uVar7);
        if (cVar6 == '\0') {
          nvAssertFailedNoLog("instmemIsValid_HAL(pGpu, pInstMem, offset)",
                              "src/kernel/gpu/disp/inst_mem/disp_inst_mem.c",0x288);
        }
        uVar12 = *(uint *)(param_2 + 0xb0);
        if (uVar12 <= local_64) {
          nvAssertFailedNoLog("hash < pInstMem->nHashTableEntries",
                              "src/kernel/gpu/disp/inst_mem/disp_inst_mem.c",0x28b);
          uVar12 = *(uint *)(param_2 + 0xb0);
        }
        if ((uVar12 - 1 & uVar12) != 0) {
          nvAssertFailedNoLog("!(pInstMem->nHashTableEntries & (pInstMem->nHashTableEntries - 1))",
                              "src/kernel/gpu/disp/inst_mem/disp_inst_mem.c",0x2ae);
          uVar12 = *(uint *)(param_2 + 0xb0);
        }
        if (local_64 < local_64 + uVar12) {
          uVar8 = local_64;
          do {
            uVar13 = uVar12 - 1 & uVar8;
            lVar14 = (ulong)uVar13 * 0x10;
            plVar11 = (long *)(*(long *)(param_2 + 0xb8) + lVar14);
            if (*plVar11 == 0) goto LAB_0030b1c1;
            uVar8 = uVar8 + 1;
          } while (uVar8 < local_64 + uVar12);
        }
        else {
          lVar14 = (ulong)local_64 * 0x10;
          plVar11 = (long *)(*(long *)(param_2 + 0xb8) + lVar14);
          uVar13 = local_64;
          if (*plVar11 == 0) {
LAB_0030b1c1:
            iVar10 = *(int *)(param_2 + 0xb4);
            *plVar11 = param_3;
            local_50 = (ulong)(iVar10 + uVar13 * 8);
            *(long *)(*(long *)(param_2 + 0xb8) + 8 + lVar14) = param_4;
            local_58 = *(long *)(param_2 + 0xa0);
            local_60 = CONCAT44(local_60._4_4_,(int)lVar5);
            uVar9 = (**(code **)(param_2 + 0x60))(param_1,param_2,uVar9,uVar7,local_68);
            local_60 = CONCAT44(uVar9,(undefined4)local_60);
            iVar10 = memmgrMemWrite_IMPL(uVar3,&local_58,&local_60,8,0);
            if (iVar10 == 0) {
              *(int *)(lVar1 + 0x238) = *(int *)(lVar1 + 0x238) + 1;
              return 0;
            }
            nvAssertOkFailedNoLog
                      (iVar10,
                       "memmgrMemWrite(pMemoryManager, &dest, &entry, sizeof(entry), TRANSFER_FLAGS_NONE)"
                       ,"src/kernel/gpu/disp/inst_mem/disp_inst_mem.c",0x2d4);
            goto LAB_0030b27c;
          }
        }
        nvDbg_Printf("src/kernel/gpu/disp/inst_mem/disp_inst_mem.c",700,"_instmemAddHashEntry",4,
                     "NVRM: Display Hash table is FULL!!\n");
        iVar10 = 0x67;
      }
    }
LAB_0030b27c:
    if (*(int *)(lVar1 + 0x238) != 0) {
      return iVar10;
    }
    iVar2 = *(int *)(lVar1 + 0x218);
    if (iVar2 == 0) goto LAB_0030b2b1;
    lVar5 = *(long *)(param_2 + 0xc0);
  }
  if (lVar5 != 0) {
    (**(code **)(lVar5 + 0x10))(lVar5,iVar2);
  }
LAB_0030b2b1:
  *(undefined4 *)(lVar1 + 0x218) = 0;
  return iVar10;
}


// ===== 0030b470 _instmemRemoveReference =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _instmemRemoveReference(undefined8 param_1,long param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = gpumgrGetSubDeviceInstanceFromGpu();
  param_3 = param_3 + (ulong)uVar1 * 4;
  iVar2 = *(int *)(param_3 + 0x238);
  if (iVar2 == 0) {
    nvAssertFailedNoLog("pContextDma->InstRefCount[gpuSubDevInst]",
                        "src/kernel/gpu/disp/inst_mem/disp_inst_mem.c",0x365);
    iVar2 = *(int *)(param_3 + 0x238);
    if (iVar2 == 0) {
      return;
    }
  }
  *(int *)(param_3 + 0x238) = iVar2 + -1;
  if (iVar2 + -1 == 0) {
    if ((*(int *)(param_3 + 0x218) != 0) && (*(long *)(param_2 + 0xc0) != 0)) {
      (**(code **)(*(long *)(param_2 + 0xc0) + 0x10))();
    }
    *(undefined4 *)(param_3 + 0x218) = 0;
  }
  return;
}


// ===== 0030b500 instmemUnbindContextDma_IMPL =====

undefined8 instmemUnbindContextDma_IMPL(undefined8 param_1,long param_2,long param_3,long param_4)

{
  long *plVar1;
  int iVar2;
  
  if (*(int *)(param_2 + 0xb0) != 0) {
    plVar1 = *(long **)(param_2 + 0xb8);
    iVar2 = 0;
    do {
      if ((param_3 == *plVar1) && (param_4 == plVar1[1])) {
        _instmemClearHashEntry();
        _instmemRemoveReference(param_1,param_2,param_3);
        return 0;
      }
      iVar2 = iVar2 + 1;
      plVar1 = plVar1 + 2;
    } while (iVar2 != *(int *)(param_2 + 0xb0));
  }
  return 0x40;
}


// ===== 0030b580 instmemUnbindContextDmaFromAllChannels_IMPL =====

void instmemUnbindContextDmaFromAllChannels_IMPL(undefined8 param_1,long param_2,long param_3)

{
  ulong uVar1;
  ulong uVar2;
  
  if (*(int *)(param_2 + 0xb0) == 0) {
    return;
  }
  uVar2 = 0;
  do {
    while (*(long *)(uVar2 * 0x10 + *(long *)(param_2 + 0xb8)) == param_3) {
      uVar1 = uVar2 & 0xffffffff;
      uVar2 = uVar2 + 1;
      _instmemClearHashEntry(param_1,param_2,uVar1);
      _instmemRemoveReference(param_1,param_2,param_3);
      if (*(uint *)(param_2 + 0xb0) <= (uint)uVar2) {
        return;
      }
    }
    uVar2 = uVar2 + 1;
  } while ((uint)uVar2 < *(uint *)(param_2 + 0xb0));
  return;
}


// ===== 0030b640 instmemUnbindDispChannelContextDmas_IMPL =====

void instmemUnbindDispChannelContextDmas_IMPL(undefined8 param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  ulong uVar3;
  
  if (*(int *)(param_2 + 0xb0) == 0) {
    return;
  }
  uVar3 = 0;
  do {
    while (puVar2 = (undefined8 *)(uVar3 * 0x10 + *(long *)(param_2 + 0xb8)), puVar2[1] == param_3)
    {
      uVar1 = *puVar2;
      _instmemClearHashEntry(param_1,param_2,uVar3 & 0xffffffff);
      uVar3 = uVar3 + 1;
      _instmemRemoveReference(param_1,param_2,uVar1);
      if (*(uint *)(param_2 + 0xb0) <= (uint)uVar3) {
        return;
      }
    }
    uVar3 = uVar3 + 1;
  } while ((uint)uVar3 < *(uint *)(param_2 + 0xb0));
  return;
}


// ===== 0030b6f0 kdispConstructEngine_IMPL =====

int kdispConstructEngine_IMPL(long param_1,long param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  int local_40;
  undefined4 uStack_3c;
  
  if (((*(char *)(param_1 + 0x908) == '\0') && (*(char *)(param_1 + 0x909) == '\0')) &&
     (*(char *)(param_1 + 0x90a) == '\0')) {
    nvAssertFailedNoLog("IS_VIRTUAL(pGpu) || IS_FW_CLIENT(pGpu) || RMCFG_MODULE_DISP",
                        "src/kernel/gpu/disp/kern_disp.c",0x73);
  }
  iVar1 = 0x56;
  if (*(char *)(param_2 + 0x50) == '\0') {
    *(undefined8 *)(param_2 + 0x280) = 0;
    iVar1 = __nvoc_objCreate_DisplayInstanceMemory(&local_40,param_2,0);
    if (iVar1 == 0) {
      lVar3 = 0;
      *(ulong *)(param_2 + 0x280) = CONCAT44(uStack_3c,local_40);
      do {
        iVar1 = __nvoc_objCreate_KernelHead(&local_40,param_2,0);
        if (iVar1 != 0) break;
        *(long *)(param_2 + 0x288 + lVar3 * 8) = CONCAT44(uStack_3c,local_40);
        *(int *)(CONCAT44(uStack_3c,local_40) + 0x140) = (int)lVar3;
        lVar3 = lVar3 + 1;
      } while (lVar3 != 8);
      *(undefined8 *)(param_2 + 0x398) = 0;
      LOCK();
      *(undefined4 *)(param_2 + 0x38c) = 0;
      UNLOCK();
      iVar2 = osReadRegistryDword(param_1,"RMInternalPanelDisconnected",&local_40);
      *(bool *)(param_2 + 0x27b) = iVar2 == 0 && local_40 == 1;
      iVar2 = osReadRegistryDword(param_1,"RmEnableAggressiveVblank",&local_40);
      if ((iVar2 == 0) && (local_40 == 1)) {
        *(undefined1 *)(param_2 + 0x27d) = 1;
      }
    }
  }
  return iVar1;
}


// ===== 0030b860 kdispDestruct_IMPL =====

void kdispDestruct_IMPL(long param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  __nvoc_objDelete(*(undefined8 *)(param_1 + 0x280));
  *(undefined8 *)(param_1 + 0x280) = 0;
  puVar1 = (undefined8 *)(param_1 + 0x288);
  do {
    puVar2 = puVar1 + 1;
    __nvoc_objDelete(*puVar1);
    *puVar1 = 0;
    puVar1 = puVar2;
  } while (puVar2 != (undefined8 *)(param_1 + 0x2c8));
  portMemFree(*(undefined8 *)(param_1 + 0x398));
  *(undefined8 *)(param_1 + 0x398) = 0;
  return;
}


// ===== 0030b8e0 kdispAllocateCommonHandle_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kdispAllocateCommonHandle_IMPL(undefined8 param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c [3];
  
  local_2c[0] = 0;
  lVar2 = rmapiGetInterface(4);
  iVar1 = rmapiutilAllocClientAndDeviceHandles(lVar2,param_1,&local_38,&local_34,&local_30);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(lVar2 + 0x10))(lVar2,local_38,local_34,local_2c,0x73,0,0,0,0,lVar2 + 0xb8);
    if (iVar1 == 0) {
      *(ulong *)(param_2 + 0x370) = CONCAT44(local_2c[0],local_30);
      *(ulong *)(param_2 + 0x368) = CONCAT44(local_34,local_38);
    }
    else {
      nvAssertFailedNoLog("rmStatus == NV_OK","src/kernel/gpu/disp/kern_disp.c",0x114);
    }
    return 0;
  }
  nvAssertFailedNoLog("rmStatus == NV_OK","src/kernel/gpu/disp/kern_disp.c",0x10f);
  return 0;
}


// ===== 0030b9e0 kdispDestroyCommonHandle_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kdispDestroyCommonHandle_IMPL(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = rmapiGetInterface(4);
  iVar1 = (**(code **)(lVar2 + 0x20))
                    (lVar2,*(undefined4 *)(param_1 + 0x368),*(undefined4 *)(param_1 + 0x374),0,
                     lVar2 + 0xb8);
  if (iVar1 != 0) {
    nvAssertFailedNoLog("rmStatus == NV_OK","src/kernel/gpu/disp/kern_disp.c",0x12a);
  }
  rmapiutilFreeClientAndDeviceHandles(lVar2,param_1 + 0x368,param_1 + 0x36c,param_1 + 0x370);
  *(undefined8 *)(param_1 + 0x368) = 0;
  *(undefined8 *)(param_1 + 0x370) = 0;
  return;
}


// ===== 0030ba80 kdispStatePreInitLocked_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kdispStatePreInitLocked_IMPL(long param_1,undefined8 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  undefined4 local_3c [3];
  
  iVar4 = 0x56;
  uVar1 = *(undefined4 *)(param_1 + 0x3b34);
  uVar2 = *(undefined4 *)(param_1 + 0x3b3c);
  cVar3 = (**(code **)(param_1 + 0x2b8))();
  if (cVar3 != '\0') {
    iVar4 = (**(code **)(param_1 + 0x3b90))(param_1 + 0x3b58,uVar1,uVar2,0x20800a4b,local_3c,4);
    if (iVar4 == 0) {
      iVar4 = gpuInitDispIpHal_IMPL(param_1,local_3c[0]);
      kdispAllocateCommonHandle_IMPL(param_1,param_2);
    }
    else {
      nvDbg_Printf("src/kernel/gpu/disp/kern_disp.c",0x148,"kdispStatePreInitLocked_IMPL",3,
                   "NVRM: Failed to read display IP version (FUSE disabled), status=0x%x\n",iVar4);
    }
  }
  return iVar4;
}


// ===== 0030bb50 kdispInitBrightcStateLoad_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 kdispInitBrightcStateLoad_IMPL(long param_1,long param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  cVar1 = (**(code **)(param_1 + 0x410))();
  puVar3 = (undefined4 *)portMemAllocNonPaged(0x1008);
  if (puVar3 != (undefined4 *)0x0) {
    portMemSet(puVar3,0,0x1008);
    *puVar3 = 0x56;
    if ((((param_2 != 0) && (*(int *)(*(long *)(param_2 + 0x2c8) + 0x14) != 0)) && (cVar1 == '\0'))
       && (*(char *)(param_2 + 0x27b) == '\0')) {
      *(undefined2 *)(puVar3 + 1) = 0x1000;
      uVar2 = osCallACPI_DSM(param_1,0xd,0x206,(long)puVar3 + 6,puVar3 + 1);
      *puVar3 = uVar2;
    }
    uVar2 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20800ac6,puVar3,0x1008);
    portMemFree(puVar3);
    return uVar2;
  }
  nvDbg_Printf("src/kernel/gpu/disp/kern_disp.c",0x167,"kdispInitBrightcStateLoad_IMPL",4,
               "NVRM: Could not allocate memory for pBrightcInfo\n");
  return 0x51;
}


// ===== 0030bca0 kdispSetupAcpiEdid_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 kdispSetupAcpiEdid_IMPL(long param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint *puVar5;
  long lVar6;
  
  puVar4 = (uint *)portMemAllocNonPaged(0x20c4);
  if (puVar4 == (uint *)0x0) {
    nvDbg_Printf("src/kernel/gpu/disp/kern_disp.c",0x192,"kdispSetupAcpiEdid_IMPL",4,
                 "NVRM: Could not allocate memory for pEdidParams\n");
    return 0x51;
  }
  portMemSet(puVar4,0,0x20c4);
  uVar1 = *(uint *)(param_1 + 0x2220) >> 2;
  *puVar4 = uVar1;
  if (uVar1 != 0) {
    lVar6 = 0;
    puVar5 = puVar4 + 3;
    do {
      *puVar5 = 0x200;
      uVar2 = osCallACPI_DDC(param_1,*(undefined4 *)(param_1 + 0x2224 + lVar6 * 4),puVar5 + 1,puVar5
                             ,1);
      uVar1 = *(uint *)(param_1 + 0x2224 + lVar6 * 4);
      lVar6 = lVar6 + 1;
      puVar5[-2] = uVar2;
      puVar5[-1] = uVar1;
      puVar5 = puVar5 + 0x83;
    } while ((uint)lVar6 < *puVar4);
  }
  uVar3 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800adf,puVar4,0x20c4);
  portMemFree(puVar4);
  return uVar3;
}


// ===== 0030bdd0 kdispStateInitLocked_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kdispStateInitLocked_IMPL(long param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  lVar3 = portMemAllocNonPaged(0x24);
  if (lVar3 == 0) {
    nvDbg_Printf("src/kernel/gpu/disp/kern_disp.c",0x1b7,"kdispStateInitLocked_IMPL",4,
                 "NVRM: Could not allocate KernelDisplayStaticInfo\n");
    portMemFree(0);
LAB_0030c04d:
    iVar2 = 0x51;
    goto LAB_0030bfa1;
  }
  portMemSet(lVar3,0,0x24);
  iVar2 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800a01,lVar3,0x24);
  if (iVar2 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar2,
               "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_DISPLAY_GET_STATIC_INFO, pStaticInfo, sizeof(*pStaticInfo))"
               ,"src/kernel/gpu/disp/kern_disp.c",0x1bd);
    portMemFree(lVar3);
    goto LAB_0030bfa1;
  }
  *(long *)(param_2 + 0x2c8) = lVar3;
  *(undefined4 *)(param_2 + 0x360) = *(undefined4 *)(lVar3 + 0xc);
  uVar1 = *(uint *)(lVar3 + 0x20);
  *(uint *)(param_2 + 0x3a0) = uVar1;
  lVar3 = portMemAllocNonPaged((ulong)uVar1 * 0x18);
  *(long *)(param_2 + 0x3a8) = lVar3;
  if (lVar3 == 0) {
    nvDbg_Printf("src/kernel/gpu/disp/kern_disp.c",0x1cd,"kdispStateInitLocked_IMPL",4,
                 "NVRM: Could not allocate clientChannelTable\n");
    portMemFree(0);
    goto LAB_0030c04d;
  }
  iVar2 = (**(code **)(param_2 + 0x1e0))(param_1,param_2);
  if (iVar2 == 0) {
    iVar2 = (**(code **)(param_2 + 0x1e8))(param_1,param_2);
    if (iVar2 == 0) {
      if (*(long *)(param_2 + 0x280) == 0) {
LAB_0030befb:
        *(undefined4 *)(param_1 + 0x7f0) = 0x10;
        iVar2 = *(int *)(*(long *)(param_2 + 0x2c8) + 0x10);
        if (iVar2 == 0x10) {
          nvDbg_Printf("src/kernel/gpu/disp/kern_disp.c",0x1ef,"kdispStateInitLocked_IMPL",1,
                       "NVRM: Error in getting valid I2Cport for Extdevice or extdevice doesn\'t exist\n"
                      );
        }
        else {
          *(int *)(param_1 + 0x7f0) = iVar2;
          iVar2 = (**(code **)(param_1 + 0x2e0))(param_1);
          if (iVar2 != 0) {
            nvDbg_Printf("src/kernel/gpu/disp/kern_disp.c",0x1f7,"kdispStateInitLocked_IMPL",1,
                         "NVRM: gpuExtdevConstruct() failed or not supported\n");
          }
        }
        iVar2 = (**(code **)(param_2 + 0x1b0))(param_2);
        if (iVar2 == 0) {
          portMemFree(0);
          return 0;
        }
        uVar6 = 0x1fc;
        pcVar4 = "kdispImportImpData_HAL(pKernelDisplay)";
      }
      else {
        iVar2 = instmemStateInitLocked_IMPL(param_1);
        uVar6 = 0x1e4;
        pcVar4 = "instmemStateInitLocked(pGpu, pKernelDisplay->pInst)";
        if (iVar2 == 0) goto LAB_0030befb;
      }
      nvCheckOkFailedNoLog(4,iVar2,pcVar4,"src/kernel/gpu/disp/kern_disp.c",uVar6);
      portMemFree(0);
      goto LAB_0030bfa1;
    }
    pcVar4 = "NVRM: rmapi control call for acpi child device init failed\n";
    uVar6 = 3;
    uVar5 = 0x1de;
  }
  else {
    pcVar4 = "NVRM: rmapi control call for brightc state load failed\n";
    uVar6 = 4;
    uVar5 = 0x1d6;
  }
  nvDbg_Printf("src/kernel/gpu/disp/kern_disp.c",uVar5,"kdispStateInitLocked_IMPL",uVar6,pcVar4);
  portMemFree(0);
LAB_0030bfa1:
  portMemFree(*(undefined8 *)(param_2 + 0x3a8));
  *(undefined8 *)(param_2 + 0x3a8) = 0;
  return iVar2;
}


// ===== 0030c140 kdispStateDestroy_IMPL =====

void kdispStateDestroy_IMPL(undefined8 param_1,long param_2)

{
  extdevDestroy();
  if (*(long *)(param_2 + 0x280) != 0) {
    instmemStateDestroy_IMPL(param_1);
  }
  portMemFree(*(undefined8 *)(param_2 + 0x3a8));
  *(undefined8 *)(param_2 + 0x3a8) = 0;
  portMemFree(*(undefined8 *)(param_2 + 0x2c8));
  *(undefined8 *)(param_2 + 0x2c8) = 0;
  kdispDestroyCommonHandle_IMPL(param_2);
  return;
}


// ===== 0030c1b0 kdispFreeSharedMem_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kdispFreeSharedMem_IMPL(long param_1,long param_2)

{
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  local_28 = 0;
  local_20 = 0;
  if (*(long *)(param_2 + 0x380) != 0) {
    (**(code **)(param_1 + 0x3b90))
              (param_1 + 0x3b58,*(undefined4 *)(param_2 + 0x368),*(undefined4 *)(param_2 + 0x374),
               0x730151,&local_40,0x28);
    memdescUnmapInternal(param_1,*(undefined8 *)(param_2 + 0x378),0);
    *(undefined8 *)(param_2 + 0x380) = 0;
  }
  if (*(long *)(param_2 + 0x378) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(param_2 + 0x378));
    *(undefined8 *)(param_2 + 0x378) = 0;
  }
  return;
}


// ===== 0030c280 kdispAllocateSharedMem_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kdispAllocateSharedMem_IMPL(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  int iVar3;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  if (*(long *)(param_2 + 0x380) != 0) {
    nvAssertFailedNoLog("pKernelDisplay->pSharedData == NULL","src/kernel/gpu/disp/kern_disp.c",
                        0x22d);
    return 0x40;
  }
  iVar3 = 1;
  if (*(char *)(param_1 + 0x44d) == '\0') {
    iVar3 = (*(char *)(param_1 + 1099) == '\0') + 1;
  }
  iVar1 = memdescCreate(param_2 + 0x378,param_1,0x20,0x1000,1,iVar3,1);
  if (iVar1 == 0) {
    iVar1 = memdescAlloc(*(undefined8 *)(param_2 + 0x378));
    if (iVar1 == 0) {
      lVar2 = memdescMapInternal(param_1,*(undefined8 *)(param_2 + 0x378),0);
      if (lVar2 == 0) {
        nvDbg_Printf("src/kernel/gpu/disp/kern_disp.c",0x24c,"kdispAllocateSharedMem_IMPL",4,
                     "NVRM: failed to map memory!\n");
      }
      else {
        *(long *)(param_2 + 0x380) = lVar2;
        local_50 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0x378),1,0);
        local_30._0_5_ = CONCAT14(1,(undefined4)local_30);
        local_40 = *(undefined8 *)(*(long *)(param_2 + 0x378) + 0x28);
        local_48 = 0x20;
        local_38 = CONCAT44(1,iVar3);
        iVar1 = (**(code **)(param_1 + 0x3b90))
                          (param_1 + 0x3b58,*(undefined4 *)(param_2 + 0x368),
                           *(undefined4 *)(param_2 + 0x374),0x730151,&local_50,0x28);
        if (iVar1 == 0) {
          return 0;
        }
        nvDbg_Printf("src/kernel/gpu/disp/kern_disp.c",0x25e,"kdispAllocateSharedMem_IMPL",4,
                     "NVRM: NV0073_CTRL_CMD_SYSTEM_MAP_SHARED_DATA RM control failed!\n");
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/disp/kern_disp.c",0x245,"kdispAllocateSharedMem_IMPL",4,
                   "NVRM: failed to allocate memory from FB!\n");
    }
    kdispFreeSharedMem_IMPL(param_1,param_2);
    return iVar1;
  }
  nvDbg_Printf("src/kernel/gpu/disp/kern_disp.c",0x23e,"kdispAllocateSharedMem_IMPL",4,
               "NVRM: failed to create memdesc from FB!\n");
  return iVar1;
}


// ===== 0030c510 kdispStateLoad_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 kdispStateLoad_IMPL(undefined8 param_1,long param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(long *)(param_2 + 0x280) != 0) {
    uVar1 = instmemStateLoad_IMPL();
  }
  (**(code **)(param_2 + 0x228))(param_1,param_2);
  return uVar1;
}


// ===== 0030c560 kdispStateUnload_IMPL =====

undefined4 kdispStateUnload_IMPL(undefined8 param_1,long param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(long *)(param_2 + 0x280) != 0) {
    uVar1 = instmemStateUnload_IMPL();
  }
  kdispFreeSharedMem_IMPL(param_1,param_2);
  return uVar1;
}


// ===== 0030c5b0 kdispImportImpData_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kdispImportImpData_IMPL(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  undefined1 local_214 [500];
  
  uVar6 = 0;
  if (param_1 != 0) {
    uVar6 = *(undefined8 *)(param_1 + 0x160);
  }
  lVar4 = gpuEngineGetGpu(uVar6);
  uVar1 = *(undefined4 *)(lVar4 + 0x3b34);
  uVar2 = *(undefined4 *)(lVar4 + 0x3b3c);
  uVar3 = osTegraSocGetImpImportData(lVar4,local_214);
  nvDbg_Printf("src/kernel/gpu/disp/kern_disp.c",0x2c0,"kdispImportImpData_IMPL",1,
               "NVRM: osTegraSocGetImpImportData returned nvStatus = 0x%08X\n",uVar3);
  uVar5 = (**(code **)(lVar4 + 0x3b90))(lVar4 + 0x3b58,uVar1,uVar2,0x20800a54,local_214,0x1ec);
  if ((int)uVar5 == 0) {
    return uVar5;
  }
  nvAssertOkFailedNoLog
            (uVar5 & 0xffffffff,
             "pRmApi->Control(pRmApi, hClient, hSubdevice, NV2080_CTRL_CMD_INTERNAL_DISPLAY_SET_IMP_INIT_INFO, &params, sizeof(params))"
             ,"src/kernel/gpu/disp/kern_disp.c",0x2cb);
  return uVar5 & 0xffffffff;
}


// ===== 0030c6a0 kdispGetIntChnClsForHwCls_IMPL =====

undefined8 kdispGetIntChnClsForHwCls_IMPL(undefined8 param_1,uint param_2,undefined4 *param_3)

{
  if (param_3 == (undefined4 *)0x0) {
    return 0x1f;
  }
  if (param_2 != 0xc97a) {
    if (param_2 < 0xc97b) {
      if (param_2 != 0xc67e) {
        if (0xc67e < param_2) {
          if (param_2 != 0xc77d) {
            if (param_2 == 0xc77f) {
              *param_3 = 7;
              return 0;
            }
            goto LAB_0030c796;
          }
          goto LAB_0030c804;
        }
        if (param_2 != 0xc57e) {
          if (param_2 < 0xc57f) {
            if (param_2 == 0xc57b) {
LAB_0030c740:
              *param_3 = 5;
              return 0;
            }
            if (param_2 == 0xc57d) goto LAB_0030c804;
            if (param_2 != 0xc57a) goto LAB_0030c796;
          }
          else {
            if (param_2 == 0xc67b) goto LAB_0030c740;
            if (param_2 == 0xc67d) goto LAB_0030c804;
            if (param_2 != 0xc67a) goto LAB_0030c796;
          }
          goto LAB_0030c6fb;
        }
      }
LAB_0030c7e0:
      *param_3 = 6;
      return 0;
    }
    if (param_2 != 0xcb7a) {
      if (param_2 < 0xcb7b) {
        if (param_2 != 0xca7a) {
          if (param_2 < 0xca7b) {
            if (param_2 == 0xc97d) {
LAB_0030c804:
              *param_3 = 3;
              return 0;
            }
            if (param_2 == 0xc97e) goto LAB_0030c7e0;
            if (param_2 == 0xc97b) goto LAB_0030c740;
          }
          else {
            if (param_2 == 0xca7d) goto LAB_0030c804;
            if (param_2 == 0xca7e) goto LAB_0030c7e0;
            if (param_2 == 0xca7b) goto LAB_0030c740;
          }
LAB_0030c796:
          nvDbg_Printf("src/kernel/gpu/disp/kern_disp.c",0x30d,"kdispGetIntChnClsForHwCls_IMPL",4,
                       "NVRM: Unknown channel class %x\n",param_2);
          return 0x1f;
        }
      }
      else if (param_2 != 0xcc7a) {
        if (param_2 < 0xcc7b) {
          if (param_2 == 0xcb7d) goto LAB_0030c804;
          if (param_2 == 0xcb7e) goto LAB_0030c7e0;
          if (param_2 == 0xcb7b) goto LAB_0030c740;
        }
        else {
          if (param_2 == 0xcc7d) goto LAB_0030c804;
          if (param_2 == 0xcc7e) goto LAB_0030c7e0;
          if (param_2 == 0xcc7b) goto LAB_0030c740;
        }
        goto LAB_0030c796;
      }
    }
  }
LAB_0030c6fb:
  *param_3 = 0;
  return 0;
}


// ===== 0030c870 kdispNotifyEvent_IMPL =====

void kdispNotifyEvent_IMPL
               (long param_1,undefined8 param_2,uint param_3,undefined8 param_4,undefined4 param_5)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  undefined1 local_68 [40];
  undefined8 local_40;
  
  serverutilShareIter(local_68,"");
  do {
    cVar2 = serverutilShareIterNext(local_68);
    while( true ) {
      if (cVar2 == '\0') {
        return;
      }
      lVar4 = __nvoc_dynamicCast(local_40,__nvoc_class_def_NotifShare);
      if ((((lVar4 == 0) || (lVar4 = *(long *)(lVar4 + 0x98), lVar4 == 0)) ||
          (lVar5 = __nvoc_dynamicCast(lVar4,__nvoc_class_def_DispObject), lVar5 == 0)) ||
         (lVar6 = __nvoc_dynamicCast(*(undefined8 *)
                                      (*(long *)(*(long *)(*(long *)(lVar5 + 0x188) + 0x48) + 0x18)
                                      + 8),__nvoc_class_def_Device),
         *(long *)(*(long *)(lVar6 + 0x128) + 0xe0) != param_1)) break;
      lVar5 = *(long *)(lVar5 + 0x1b0);
      uVar3 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
      lVar5 = *(long *)(lVar5 + 0x130 + (ulong)uVar3 * 8);
      if (((lVar5 == 0) || (lVar4 = inotifyGetNotificationList_IMPL(lVar4), lVar4 == 0)) ||
         ((piVar1 = (int *)(lVar5 + (ulong)param_3 * 4), *piVar1 == 0 ||
          (osEventNotification(param_1,lVar4,param_3 | 0x10000000,param_4,param_5), *piVar1 != 1))))
      break;
      *piVar1 = 0;
      cVar2 = serverutilShareIterNext(local_68);
    }
  } while( true );
}


// ===== 0030c9b0 kdispAcquireLowLatencyLockConditional =====

undefined8 kdispAcquireLowLatencyLockConditional(uint *param_1)

{
  uint uVar1;
  ulong uVar2;
  
  uVar2 = 0;
  LOCK();
  uVar1 = *param_1;
  if (uVar1 == 0) {
    *param_1 = 1;
  }
  else {
    uVar2 = (ulong)uVar1;
  }
  UNLOCK();
  return CONCAT71((int7)(uVar2 >> 8),uVar1 == 0);
}


// ===== 0030c9d0 kdispReleaseLowLatencyLock =====

int kdispReleaseLowLatencyLock(int *param_1)

{
  int iVar1;
  
  LOCK();
  iVar1 = *param_1;
  if (iVar1 == 1) {
    *param_1 = 0;
    iVar1 = 1;
  }
  UNLOCK();
  return iVar1;
}


// ===== 0030c9e0 kdispSetupVBlank_IMPL =====

undefined8
kdispSetupVBlank_IMPL
          (undefined8 param_1,long param_2,long param_3,undefined8 param_4,undefined8 param_5,
          uint param_6,undefined8 param_7)

{
  int *piVar1;
  byte bVar2;
  ulong uVar3;
  long lVar4;
  bool bVar5;
  
  lVar4 = *(long *)(param_2 + 0x398);
  if (param_3 == 0) {
    bVar2 = (byte)param_6 & 0x1f;
    *(uint *)(param_2 + 0x390) =
         *(uint *)(param_2 + 0x390) & (-2 << bVar2 | 0xfffffffeU >> 0x20 - bVar2);
  }
  if (lVar4 == 0) {
    lVar4 = portMemAllocNonPaged((ulong)*(uint *)(param_2 + 0x360) * 0x28);
    if (lVar4 == 0) {
      return 0x1a;
    }
    portMemSet(lVar4,0,(ulong)*(uint *)(param_2 + 0x360) * 0x28);
  }
  piVar1 = (int *)(param_2 + 0x38c);
  LOCK();
  bVar5 = *piVar1 == 0;
  if (bVar5) {
    *piVar1 = 1;
  }
  UNLOCK();
  while (!bVar5) {
    osSpinLoop();
    LOCK();
    bVar5 = *piVar1 == 0;
    if (bVar5) {
      *piVar1 = 1;
    }
    UNLOCK();
  }
  uVar3 = (ulong)param_6;
  *(long *)(param_2 + 0x398) = lVar4;
  *(long *)(lVar4 + uVar3 * 0x28) = param_3;
  *(undefined8 *)(*(long *)(param_2 + 0x398) + 8 + uVar3 * 0x28) = param_4;
  *(undefined8 *)(*(long *)(param_2 + 0x398) + 0x10 + uVar3 * 0x28) = param_5;
  *(undefined8 *)(*(long *)(param_2 + 0x398) + 0x20 + uVar3 * 0x28) = param_7;
  if (param_3 != 0) {
    *(uint *)(param_2 + 0x390) = *(uint *)(param_2 + 0x390) | 1 << ((byte)param_6 & 0x1f);
  }
  LOCK();
  if (*piVar1 == 1) {
    *piVar1 = 0;
  }
  UNLOCK();
  return 0;
}


// ===== 0030cb62 kdispOptimizePerFrameOsCallbacks_IMPL.cold =====

void kdispOptimizePerFrameOsCallbacks_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0030cb70 kdispOptimizePerFrameOsCallbacks_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Function: __x86_indirect_thunk_r11 replaced with injection: x86_indirect_thunk_r11 */

undefined4
kdispOptimizePerFrameOsCallbacks_IMPL
          (long param_1,long param_2,char param_3,undefined8 param_4,uint *param_5,long param_6)

{
  undefined8 *puVar1;
  long lVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  bool bVar6;
  char cVar7;
  undefined1 uVar8;
  uint uVar9;
  ulong uVar10;
  uint local_5c;
  uint local_54;
  uint local_40;
  int local_3c [3];
  
  lVar2 = *(long *)(param_1 + 0x1c20);
  local_40 = 0;
  *param_5 = 0;
  if (param_2 == 0) {
    nvAssertFailedNoLog("pKernelDisplay","src/kernel/gpu/disp/kern_disp.c",0x41a);
    return 0x1f;
  }
  if ((param_6 == 0) || (cVar7 = bitVectorTest_IMPL(param_6,0xb4,0xb1), cVar7 == '\0')) {
    (**(code **)(param_2 + 0x238))(param_1,param_2,param_4);
    (**(code **)(param_2 + 0x250))(param_1,param_2,param_4);
    if (*(int *)(param_2 + 0x360) == 0) {
      *param_5 = 0;
      return 0;
    }
    local_5c = *(uint *)(param_2 + 0x364);
    bVar6 = false;
  }
  else {
    (**(code **)(lVar2 + 0x1d0))(param_1,lVar2,*(undefined4 *)(lVar2 + 0x36c),param_4);
    (**(code **)(param_2 + 0x238))(param_1,param_2,param_4);
    (**(code **)(param_2 + 0x250))(param_1,param_2,param_4);
    if (*(int *)(param_2 + 0x360) == 0) {
      *param_5 = 0;
      goto LAB_0030cdb1;
    }
    local_5c = *(uint *)(param_2 + 0x364);
    bVar6 = true;
  }
  local_54 = 0;
  uVar10 = 0;
  do {
    while( true ) {
      if (uVar10 == 8) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)invalidInstructionException();
        (*pcVar3)();
      }
      lVar2 = *(long *)(param_2 + 0x288 + uVar10 * 8);
      local_40 = (**(code **)(lVar2 + 0x90))(param_1,lVar2,param_4);
      if (local_40 != 0) {
        local_3c[0] = 0;
        uVar8 = osIsISR();
        (**(code **)(lVar2 + 0xa8))(param_1,lVar2,uVar10 & 0xffffffff,&local_40,local_3c,uVar8);
        if (local_3c[0] != 0) {
          (**(code **)(lVar2 + 0xa0))(param_1,lVar2,local_3c[0],param_4);
        }
      }
      cVar7 = (**(code **)(lVar2 + 0x78))(param_1,lVar2,0,param_4);
      if (cVar7 != '\0') break;
      if ((local_40 & 1) != 0) goto LAB_0030cd1d;
LAB_0030ccb4:
      uVar10 = uVar10 + 1;
      if (*(uint *)(param_2 + 0x360) <= (uint)uVar10) goto LAB_0030cda0;
    }
    local_40 = local_40 | 1;
LAB_0030cd1d:
    uVar9 = 1 << ((byte)uVar10 & 0x1f);
    local_54 = local_54 | uVar9;
    if (param_3 == '\x01') {
      if (bVar6) {
        (**(code **)(lVar2 + 0x48))(param_1,lVar2,param_4);
      }
      else {
        (**(code **)(lVar2 + 0x70))(param_1,lVar2,param_4);
      }
    }
    if (*(long *)(param_2 + 0x398) == 0) goto LAB_0030ccb4;
    puVar1 = (undefined8 *)(*(long *)(param_2 + 0x398) + uVar10 * 0x28);
    pcVar3 = (code *)*puVar1;
    if (pcVar3 == (code *)0x0) goto LAB_0030ccb4;
    uVar4 = puVar1[1];
    uVar5 = puVar1[2];
    lVar2 = puVar1[4];
    if ((lVar2 != 0) && ((local_5c & uVar9) == 0)) {
      *(int *)(lVar2 + 0x1c) = *(int *)(lVar2 + 0x1c) + 1;
    }
    if (*(char *)(lVar2 + 0x49) == '\0') goto LAB_0030ccb4;
    (*pcVar3)(uVar4,uVar5);
    uVar10 = uVar10 + 1;
  } while ((uint)uVar10 < *(uint *)(param_2 + 0x360));
LAB_0030cda0:
  *param_5 = local_54;
  if (!bVar6) {
    return 0;
  }
LAB_0030cdb1:
  (**(code **)(param_2 + 0x240))(param_1,param_2,1,param_4);
  return 0;
}


// ===== 0030ced0 kdispHandleAggressiveVblank_IMPL =====

void kdispHandleAggressiveVblank_IMPL
               (undefined8 param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  uint local_1c [3];
  
  *(undefined4 *)(param_2 + 0x358) = 0;
  iVar1 = kdispOptimizePerFrameOsCallbacks_IMPL(param_1,param_2,1,param_3,local_1c,param_4);
  if (iVar1 != 0) {
    nvAssertFailedNoLog("rmStatus == NV_OK","src/kernel/gpu/disp/kern_disp.c",0x4ab);
  }
  if (local_1c[0] != 0) {
    *(uint *)(param_2 + 0x364) = *(uint *)(param_2 + 0x364) | local_1c[0];
  }
  return;
}


// ===== 0030cf40 kdispSetWarPurgeSatellitesOnCoreFree_IMPL =====

void kdispSetWarPurgeSatellitesOnCoreFree_IMPL(long param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x2d0) = param_2;
  return;
}


// ===== 0030cf50 kdispRegisterRgLineCallback_IMPL =====

undefined8
kdispRegisterRgLineCallback_IMPL(long param_1,long param_2,uint param_3,uint param_4,char param_5)

{
  long lVar1;
  long lVar2;
  
  if (param_3 < 8) {
    if (param_4 < 2) {
      lVar1 = (ulong)param_4 + 0x5a + (ulong)param_3 * 2;
      lVar2 = *(long *)(param_1 + 8 + lVar1 * 8);
      if (param_5 == '\0') {
        if (lVar2 != param_2) goto LAB_0030cfa0;
        *(undefined8 *)(param_1 + 8 + lVar1 * 8) = 0;
      }
      else {
        if (lVar2 != 0) {
LAB_0030cfa0:
          nvAssertFailedNoLog("Invalid KernelDisplay state for RgLineCallback",
                              "src/kernel/gpu/disp/kern_disp.c",0x51b);
          return 0x40;
        }
        *(long *)(param_1 + 8 + lVar1 * 8) = param_2;
      }
      return 0;
    }
    nvAssertFailedNoLog("rgIntrLine < MAX_RG_LINE_CALLBACKS_PER_HEAD",
                        "src/kernel/gpu/disp/kern_disp.c",0x505);
  }
  else {
    nvAssertFailedNoLog("head < OBJ_MAX_HEADS","src/kernel/gpu/disp/kern_disp.c",0x504);
  }
  return 0x1f;
}


// ===== 0030d000 kdispInvokeRgLineCallback_KERNEL =====

void kdispInvokeRgLineCallback_KERNEL(long param_1,uint param_2,uint param_3,undefined1 param_4)

{
  long lVar1;
  
  if (7 < param_2) {
    nvAssertFailedNoLog("head < OBJ_MAX_HEADS","src/kernel/gpu/disp/kern_disp.c",0x52b);
    return;
  }
  if (param_3 < 2) {
    lVar1 = *(long *)(param_1 + 8 + ((ulong)param_3 + 0x5a + (ulong)param_2 * 2) * 8);
    if (lVar1 != 0) {
      rglcbInvoke_IMPL(lVar1,param_4);
      return;
    }
    nvDbg_Printf("src/kernel/gpu/disp/kern_disp.c",0x540,"kdispInvokeRgLineCallback_KERNEL",3,
                 "NVRM: got RgLineCallback invocation for null callback\n");
    return;
  }
  nvAssertFailedNoLog("rgIntrLine < MAX_RG_LINE_CALLBACKS_PER_HEAD",
                      "src/kernel/gpu/disp/kern_disp.c",0x52c);
  return;
}


// ===== 0030d098 kdispReadPendingVblank_IMPL.cold =====

void kdispReadPendingVblank_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0030d0b0 kdispReadPendingVblank_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint kdispReadPendingVblank_IMPL(undefined8 param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  uint uVar4;
  long lVar5;
  uint uVar6;
  
  if (param_2 == 0) {
    nvAssertFailedNoLog("pKernelDisplay != NULL","generated/g_kern_disp_nvoc.h",0x4f9);
  }
  uVar4 = 0;
  lVar5 = 0;
  uVar6 = 0;
  if (*(int *)(param_2 + 0x360) != 0) {
    do {
      if (lVar5 == 8) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar1 = *(long *)(param_2 + 0x288 + lVar5 * 8);
      cVar3 = (**(code **)(lVar1 + 0x78))(param_1,lVar1,0,param_3);
      if (cVar3 != '\0') {
        uVar6 = uVar6 | 1 << ((byte)uVar4 & 0x1f);
      }
      lVar5 = lVar5 + 1;
      uVar4 = (uint)lVar5;
    } while (uVar4 < *(uint *)(param_2 + 0x360));
  }
  return uVar6;
}


// ===== 0030d154 kdispServiceLowLatencyIntrs_KERNEL.cold =====

void kdispServiceLowLatencyIntrs_KERNEL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0030d180 kdispServiceLowLatencyIntrs_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

void kdispServiceLowLatencyIntrs_KERNEL
               (long param_1,long param_2,uint param_3,uint param_4,undefined8 param_5,uint *param_6
               ,long param_7)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  undefined1 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  ulong uVar15;
  long lVar16;
  char local_79;
  uint local_70;
  uint local_6c;
  uint local_60;
  int local_40;
  int local_3c [3];
  
  uVar13 = *(uint *)(param_2 + 0x364);
  lVar1 = *(long *)(param_1 + 0x1c20);
  if (param_6 != (uint *)0x0) {
    *param_6 = 0;
  }
  local_79 = '\0';
  if ((param_7 != 0) && (local_79 = bitVectorTest_IMPL(param_7,0xb4,0xb1), local_79 != '\0')) {
    (**(code **)(lVar1 + 0x1d0))(param_1,lVar1,*(undefined4 *)(lVar1 + 0x36c),param_5);
    local_79 = '\x01';
  }
  (**(code **)(param_2 + 0x238))(param_1,param_2,param_5);
  (**(code **)(param_2 + 0x250))(param_1,param_2,param_5);
  if (*(int *)(param_2 + 0x360) != 0) {
    uVar15 = 0;
    do {
      while( true ) {
        if (uVar15 == 8) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)invalidInstructionException();
          (*pcVar3)();
        }
        lVar16 = *(long *)(param_2 + 0x288 + uVar15 * 8);
        local_40 = (**(code **)(lVar16 + 0x90))(param_1,lVar16,param_5);
        if (local_40 != 0) break;
LAB_0030d238:
        uVar5 = *(uint *)(param_2 + 0x360);
        uVar15 = uVar15 + 1;
        if (uVar5 <= (uint)uVar15) goto LAB_0030d2e0;
      }
      local_3c[0] = 0;
      uVar4 = osIsISR();
      (**(code **)(lVar16 + 0xa8))(param_1,lVar16,uVar15 & 0xffffffff,&local_40,local_3c,uVar4);
      if (local_3c[0] == 0) goto LAB_0030d238;
      (**(code **)(lVar16 + 0xa0))(param_1,lVar16,local_3c[0],param_5);
      uVar5 = *(uint *)(param_2 + 0x360);
      uVar15 = uVar15 + 1;
    } while ((uint)uVar15 < uVar5);
LAB_0030d2e0:
    if (uVar5 != 0) {
      lVar16 = 0;
      do {
        local_3c[0] = 0;
        if (lVar16 == 8) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)invalidInstructionException();
          (*pcVar3)();
        }
        lVar2 = *(long *)(param_2 + 0x288 + lVar16 * 8);
        (**(code **)(lVar2 + 0xb0))(param_1,lVar2,local_3c,param_5,0);
        if (local_3c[0] != 0) {
          (**(code **)(lVar2 + 0xb8))(param_1,lVar2,local_3c,param_5);
        }
        lVar16 = lVar16 + 1;
      } while ((uint)lVar16 < *(uint *)(param_2 + 0x360));
    }
  }
  uVar5 = param_4 | 6;
  if ((param_4 & 6) != 0) {
    uVar5 = param_4;
  }
  uVar12 = 0xffffffff;
  if (param_3 != 0) {
    uVar12 = param_3;
  }
  local_60 = uVar5 & 1;
  if ((uVar5 & 1) == 0) {
    uVar8 = kdispReadPendingVblank_IMPL(param_1,param_2,param_5);
    *(undefined4 *)(param_2 + 0x364) = 0;
    uVar8 = uVar13 | uVar8;
    if (uVar8 == 0) goto LAB_0030d613;
  }
  else {
    *(undefined4 *)(param_2 + 0x364) = 0;
    uVar8 = uVar12;
  }
  uVar11 = 0;
  uVar14 = 0;
  local_70 = 0;
  local_6c = 0;
  do {
    uVar10 = 0;
    uVar9 = uVar8;
    if (7 < uVar14) goto LAB_0030d405;
    while( true ) {
      uVar10 = *(undefined8 *)(param_2 + 0x288 + (ulong)uVar14 * 8);
      uVar8 = uVar9;
LAB_0030d405:
      uVar9 = 1 << ((byte)uVar14 & 0x1f);
      if ((uVar12 & uVar8 & ~uVar11 & uVar9) != 0) {
        uVar11 = uVar11 | uVar9;
        uVar9 = kheadCheckVblankCallbacksQueued_IMPL(param_1,uVar10,uVar5,0);
        local_6c = local_6c | uVar9;
        iVar6 = kheadCheckVblankCallbacksQueued_IMPL(param_1,uVar10,uVar5 & 0x17 ^ 6,0);
        local_70 = local_70 | (uint)(iVar6 != 0) << ((byte)uVar14 & 0x1f);
      }
      if (local_60 != 0) break;
      uVar9 = kdispReadPendingVblank_IMPL(param_1,param_2,param_5);
      uVar9 = uVar13 | uVar9;
      if (uVar9 == uVar8) break;
      uVar7 = *(uint *)(param_2 + 0x360);
      if (uVar7 == 0) {
        uVar13 = uVar5 & 0x10;
        if ((uVar5 & 0x10) != 0) {
          *(uint *)(param_2 + 0x358) = uVar9;
          uVar13 = 0x10;
        }
        goto LAB_0030d590;
      }
      uVar8 = uVar11;
      if (uVar11 == uVar9) goto LAB_0030d4de;
      uVar14 = 0;
    }
    uVar7 = *(uint *)(param_2 + 0x360);
    uVar14 = uVar14 + 1;
  } while ((uVar14 < uVar7) && (uVar11 != uVar8));
LAB_0030d4de:
  uVar9 = uVar8;
  uVar13 = uVar5 & 0x10;
  if ((uVar5 & 0x10) != 0) {
    *(uint *)(param_2 + 0x358) = uVar9;
    uVar13 = 0x10;
  }
  if (uVar7 != 0) {
    uVar15 = 0;
    do {
      uVar12 = 1 << ((byte)uVar15 & 0x1f) & uVar9;
      if (uVar12 != 0) {
        if ((uint)uVar15 < 8) {
          uVar10 = *(undefined8 *)(param_2 + 0x288 + uVar15 * 8);
        }
        else {
          uVar10 = 0;
        }
        kheadGetVblankTotalCounter_IMPL(uVar10);
        kheadSetVblankTotalCounter_IMPL(uVar10);
        if (((uVar5 & 2) != 0) &&
           (((uVar5 & 0x20) == 0 || ((~*(uint *)(param_2 + 0x358) & uVar12) != 0)))) {
          kheadGetVblankLowLatencyCounter_IMPL(uVar10);
          kheadSetVblankLowLatencyCounter_IMPL(uVar10);
        }
      }
      uVar12 = (uint)uVar15 + 1;
      uVar15 = (ulong)uVar12;
    } while (uVar12 < *(uint *)(param_2 + 0x360));
  }
LAB_0030d590:
  if (local_6c == 0) {
    if ((((*(char *)(param_1 + 0x909) != '\0') || (*(char *)(param_1 + 0x90a) != '\0')) ||
        (*(char *)(param_2 + 0x27a) != '\0')) && (lVar16 = 0, *(int *)(param_2 + 0x360) != 0)) {
      while( true ) {
        lVar2 = *(long *)(param_2 + 0x288 + lVar16 * 8);
        lVar16 = lVar16 + 1;
        (**(code **)(lVar2 + 0x48))(param_1,lVar2,param_5);
        if (*(uint *)(param_2 + 0x360) <= (uint)lVar16) break;
        if (lVar16 == 8) {
          kdispServiceLowLatencyIntrs_KERNEL_cold();
          return;
        }
      }
    }
  }
  else {
    uVar15 = 0;
    if (*(int *)(param_2 + 0x360) != 0) {
      do {
        uVar12 = (uint)uVar15;
        if (uVar12 < 8) {
          lVar16 = *(long *)(param_2 + 0x288 + uVar15 * 8);
        }
        else {
          lVar16 = 0;
        }
        if ((uVar9 >> (uVar12 & 0x1f) & 1) != 0) {
          (**(code **)(lVar16 + 0x68))(param_1,lVar16,uVar5);
        }
        uVar8 = *(uint *)(param_2 + 0x360);
        uVar15 = (ulong)(uVar12 + 1);
      } while (uVar12 + 1 < uVar8);
      if (*(char *)(param_2 + 0x27a) == '\0') {
        if ((local_70 == 0) || (uVar13 == 0)) {
          uVar15 = 0;
          if (uVar8 != 0) {
            do {
              uVar13 = (uint)uVar15;
              if (uVar13 < 8) {
                lVar16 = *(long *)(param_2 + 0x288 + uVar15 * 8);
              }
              else {
                lVar16 = 0;
              }
              if (((~local_70 & uVar9) >> (uVar13 & 0x1f) & 1) != 0) {
                (**(code **)(lVar16 + 0x48))(param_1,lVar16,param_5);
              }
              uVar15 = (ulong)(uVar13 + 1);
            } while (uVar13 + 1 < *(uint *)(param_2 + 0x360));
          }
        }
        else if (uVar8 != 0) {
          uVar15 = 0;
          do {
            if ((uint)uVar15 < 8) {
              lVar16 = *(long *)(param_2 + 0x288 + uVar15 * 8);
            }
            else {
              lVar16 = 0;
            }
            if ((*(char *)(param_1 + 0x909) != '\0') || (*(char *)(param_1 + 0x90a) != '\0')) {
              (**(code **)(lVar16 + 0x48))(param_1,lVar16,param_5);
            }
            uVar13 = (uint)uVar15 + 1;
            uVar15 = (ulong)uVar13;
          } while (uVar13 < *(uint *)(param_2 + 0x360));
        }
      }
      else if (uVar8 != 0) {
        uVar13 = 0;
        do {
          if (uVar13 < 8) {
            lVar16 = *(long *)(param_2 + 0x288 + (ulong)uVar13 * 8);
          }
          else {
            lVar16 = 0;
          }
          if ((uVar9 >> (uVar13 & 0x1f) & 1) != 0) {
            (**(code **)(lVar16 + 0x48))(param_1,lVar16,param_5);
          }
          uVar13 = uVar13 + 1;
        } while (uVar13 < *(uint *)(param_2 + 0x360));
      }
    }
    if (param_6 != (uint *)0x0) {
      *param_6 = uVar9;
    }
  }
LAB_0030d613:
  if (local_79 != '\0') {
    (**(code **)(param_2 + 0x240))(param_1,param_2,1,param_5);
    intrReenableIntrMask_IMPL(param_1,lVar1);
  }
  return;
}


// ===== 0030d880 kdispApplyAggressiveVblankHandlingWar_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kdispApplyAggressiveVblankHandlingWar_IMPL(long param_1,long param_2)

{
  uint *puVar1;
  ulong uVar2;
  bool bVar3;
  undefined1 local_30 [24];
  
  uVar2 = rmGpuLockIsOwner();
  if ((char)uVar2 == '\0') {
    return uVar2;
  }
  (**(code **)(*(long *)(param_1 + 0x1c20) + 0x228))(param_1,*(long *)(param_1 + 0x1c20),local_30,0)
  ;
  if (*(char *)(param_2 + 0x27a) != '\0') {
    uVar2 = bitVectorTest_IMPL(local_30,0xb4,0xb1);
    if ((char)uVar2 != '\0') goto LAB_0030d8df;
    if (*(char *)(param_2 + 0x27a) != '\0') {
      return uVar2;
    }
  }
  uVar2 = bitVectorTest_IMPL(local_30,0xb4,2);
  if ((char)uVar2 == '\0') {
    return uVar2;
  }
LAB_0030d8df:
  puVar1 = (uint *)(param_2 + 0x38c);
  LOCK();
  bVar3 = *puVar1 == 0;
  if (bVar3) {
    *puVar1 = 1;
  }
  UNLOCK();
  while (!bVar3) {
    osSpinLoop();
    LOCK();
    bVar3 = *puVar1 == 0;
    if (bVar3) {
      *puVar1 = 1;
    }
    UNLOCK();
  }
  if (*(char *)(param_2 + 0x27d) == '\0') {
    kdispServiceLowLatencyIntrs_KERNEL(param_1,param_2,0,6,0,0,local_30);
  }
  else {
    kdispHandleAggressiveVblank_IMPL(param_1,param_2,0,local_30);
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


// ===== 0030d9b0 kdispRegisterIntrService_IMPL =====

void kdispRegisterIntrService_IMPL(undefined8 param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  
  if (*(long *)(param_3 + 0x30) != 0) {
    nvAssertFailedNoLog("pRecords[engineIdx].pInterruptService == NULL",
                        "src/kernel/gpu/disp/kern_disp.c",0x6df);
  }
  if (param_2 == 0) {
    *(undefined8 *)(param_3 + 0x30) = 0;
    uVar1 = 0;
    if (*(long *)(param_3 + 0x1098) != 0) {
      nvAssertFailedNoLog("pRecords[engineIdx].pInterruptService == NULL",
                          "src/kernel/gpu/disp/kern_disp.c",0x6e3);
      uVar1 = 0;
    }
  }
  else {
    *(undefined8 *)(param_3 + 0x30) = *(undefined8 *)(param_2 + 0x170);
    if (*(long *)(param_3 + 0x1098) != 0) {
      nvAssertFailedNoLog("pRecords[engineIdx].pInterruptService == NULL",
                          "src/kernel/gpu/disp/kern_disp.c",0x6e3);
    }
    uVar1 = *(undefined8 *)(param_2 + 0x170);
  }
  *(undefined8 *)(param_3 + 0x1098) = uVar1;
  return;
}


// ===== 0030da90 kdispServiceInterrupt_KERNEL =====

undefined8 kdispServiceInterrupt_KERNEL(undefined8 param_1,long param_2,short *param_3)

{
  int *piVar1;
  bool bVar2;
  undefined1 local_40 [24];
  
  if (param_3 != (short *)0x0) {
    if ((*param_3 == 2) || (*param_3 == 0xb1)) {
      piVar1 = (int *)(param_2 + 0x38c);
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
      bitVectorClrAll_IMPL(local_40,0xb4);
      bitVectorSet_IMPL(local_40,0xb4,*param_3);
      kdispServiceLowLatencyIntrs_KERNEL(param_1,param_2,0,2,0,0,local_40);
      LOCK();
      if (*piVar1 == 1) {
        *piVar1 = 0;
      }
      UNLOCK();
    }
    else {
      nvAssertFailedNoLog("pParams->engineIdx == MC_ENGINE_IDX_DISP || pParams->engineIdx == MC_ENGINE_IDX_DISP_LOW"
                          ,"src/kernel/gpu/disp/kern_disp.c",0x6f7);
    }
    return 0;
  }
  nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/disp/kern_disp.c",0x6f6);
  return 0;
}


// ===== 0030dbc0 kdispInvokeDisplayModesetCallback_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kdispInvokeDisplayModesetCallback_KERNEL
               (long param_1,char param_2,ulong param_3,undefined4 param_4)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  
  pcVar3 = "start";
  if (param_2 == '\0') {
    pcVar3 = "end";
  }
  nvDbg_Printf("src/kernel/gpu/disp/kern_disp.c",0x72b,"kdispInvokeDisplayModesetCallback_KERNEL",1,
               "NVRM: Kernel RM received \"%s of modeset\" notification (minRequiredIsoBandwidthKBPS = %u, minRequiredFloorBandwidthKBPS = %u)\n"
               ,pcVar3,param_3);
  uVar2 = 0;
  if (param_1 != 0) {
    uVar2 = *(undefined8 *)(param_1 + 0x160);
  }
  uVar2 = gpuEngineGetGpu(uVar2);
  iVar1 = (**(code **)(param_1 + 0x1b8))(uVar2,param_1,0,param_3 & 0xffffffff,param_4);
  if (iVar1 == 0) {
    return;
  }
  nvAssertOkFailedNoLog(iVar1,"status","src/kernel/gpu/disp/kern_disp.c",0x73d);
  return;
}


// ===== 0030dc7c _registerRgLineCallback.cold =====

void _registerRgLineCallback_cold(void)

{
  code *pcVar1;
  long unaff_RBP;
  undefined8 unaff_R13;
  
  *(undefined8 *)(unaff_RBP + -8) = unaff_R13;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0030dc90 _registerRgLineCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong _registerRgLineCallback(long param_1,char param_2)

{
  undefined4 uVar1;
  long lVar2;
  code *pcVar3;
  uint uVar4;
  ulong uVar5;
  long local_40;
  undefined8 local_38;
  undefined4 local_30;
  char local_2c;
  
  local_40 = 0;
  if (*(long *)(param_1 + 0x148) == 0) {
    nvDbg_Printf("src/kernel/gpu/disp/rg_line_callback/rg_line_callback.c",0x31,
                 "_registerRgLineCallback",4,
                 "NVRM: Trying to register/un-register a NULL RG line callback\n");
    return 0x1f;
  }
  if (*(long *)(param_1 + 0x160) == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  lVar2 = *(long *)(*(long *)(param_1 + 0x160) + 0x1b0);
  uVar5 = dispapiSetUnicastAndSynchronize_KERNEL
                    (lVar2,*(undefined8 *)(lVar2 + 0x120),&local_40,0,
                     *(undefined4 *)(param_1 + 0x138));
  if ((int)uVar5 != 0) {
    return uVar5;
  }
  lVar2 = *(long *)(local_40 + 0x1b80);
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pKernelDisplay != NULL",
                        "src/kernel/gpu/disp/rg_line_callback/rg_line_callback.c",0x3f);
  }
  local_38 = *(undefined8 *)(param_1 + 0x13c);
  local_30 = *(undefined4 *)(param_1 + 0x158);
  local_2c = param_2;
  uVar4 = (**(code **)(local_40 + 0x3b90))
                    (local_40 + 0x3b58,*(undefined4 *)(local_40 + 0x3b34),
                     *(undefined4 *)(local_40 + 0x3b3c),0x20800a4d,&local_38,0x10);
  if (uVar4 == 0) {
    if (param_2 == '\0') {
      uVar1 = *(undefined4 *)(param_1 + 0x158);
    }
    else {
      *(undefined4 *)(param_1 + 0x158) = local_30;
      uVar1 = local_30;
    }
    uVar5 = kdispRegisterRgLineCallback_IMPL
                      (lVar2,param_1,*(undefined4 *)(param_1 + 0x13c),uVar1,param_2);
    return uVar5;
  }
  nvCheckOkFailedNoLog
            (4,uVar4,"status","src/kernel/gpu/disp/rg_line_callback/rg_line_callback.c",0x4d);
  return (ulong)uVar4;
}


// ===== 0030de40 rglcbConstruct_IMPL =====

void rglcbConstruct_IMPL(long param_1,long param_2,long param_3)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  
  puVar1 = *(undefined4 **)(param_3 + 0x40);
  *(undefined4 *)(param_1 + 0x138) = *puVar1;
  *(undefined4 *)(param_1 + 0x13c) = puVar1[1];
  *(undefined4 *)(param_1 + 0x140) = puVar1[2];
  *(undefined8 *)(param_1 + 0x148) = *(undefined8 *)(puVar1 + 4);
  uVar2 = *(undefined8 *)(puVar1 + 6);
  *(undefined4 *)(param_1 + 0x158) = 0xffffffff;
  *(undefined8 *)(param_1 + 0x150) = uVar2;
  uVar2 = __nvoc_dynamicCast(*(undefined8 *)(*(long *)(*(long *)(param_2 + 0x10) + 0x18) + 8),
                             __nvoc_class_def_DispCommon);
  *(undefined8 *)(param_1 + 0x160) = uVar2;
  _registerRgLineCallback(param_1,1);
  return;
}


// ===== 0030dec0 rglcbDestruct_IMPL =====

void rglcbDestruct_IMPL(undefined8 param_1)

{
  _registerRgLineCallback(param_1,0);
  return;
}


// ===== 0030ded0 rglcbInvoke_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void rglcbInvoke_IMPL(long param_1,undefined1 param_2)

{
  (**(code **)(param_1 + 0x148))
            (*(undefined4 *)(param_1 + 0x158),*(undefined8 *)(param_1 + 0x150),param_2);
  return;
}


// ===== 0030df00 kheadAddVblankCallback_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kheadAddVblankCallback_IMPL(undefined8 param_1,long param_2,long *param_3)

{
  uint uVar1;
  long *plVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  long *plVar7;
  long *plVar8;
  long *plVar9;
  uint uVar10;
  long lVar11;
  
  uVar5 = *(uint *)((long)param_3 + 0x34);
  if ((uVar5 & 0x200) == 0) {
    if ((uVar5 & 0x10000000) != 0) goto LAB_0030df39;
    uVar1 = *(uint *)(param_2 + 200);
    plVar2 = *(long **)(param_2 + 0xd8);
  }
  else {
    uVar5 = uVar5 | 0x10000084;
    *(uint *)((long)param_3 + 0x34) = uVar5;
LAB_0030df39:
    uVar1 = *(uint *)(param_2 + 0xc4);
    plVar2 = *(long **)(param_2 + 0xd0);
  }
  if (((uVar5 & 1) != 0) && (*(uint *)((long)param_3 + 0x1c) <= uVar1)) {
    nvAssertFailedNoLog("!(pCallback->Flags & VBLANK_CALLBACK_FLAG_SPECIFIED_VBLANK_COUNT) || (pCallback->VBlankCount > Count)"
                        ,"src/kernel/gpu/disp/vblank_callback/vblank.c",0x4c);
  }
  nvDbg_Printf("src/kernel/gpu/disp/vblank_callback/vblank.c",0x4f,"kheadAddVblankCallback_IMPL",1,
               "NVRM: headAddVblankCallback: pGpu=%p cb=%p\n",param_1,param_3);
  nvDbg_Printf("src/kernel/gpu/disp/vblank_callback/vblank.c",0x51,"kheadAddVblankCallback_IMPL",1,
               "NVRM:     cbproc=%p cbobj=%p p1=0x%x p2=0x%x count=0x%x flags=0x%x offset=0x%x\n",
               *param_3,param_3[1],*(undefined4 *)((long)param_3 + 0x14),(int)param_3[3],
               *(undefined4 *)((long)param_3 + 0x1c),*(undefined4 *)((long)param_3 + 0x34),
               (int)param_3[4]);
  iVar6 = kheadReadVblankIntrState_IMPL(param_1,param_2);
  if (iVar6 == 0) {
    if ((*(byte *)((long)param_3 + 0x34) & 4) == 0) {
      if (*param_3 == 0) {
        return;
      }
      nvDbg_Printf("src/kernel/gpu/disp/vblank_callback/vblank.c",0xd6,"kheadAddVblankCallback_IMPL"
                   ,1,"NVRM: headAddVblankCallback: immediate invocation\n");
      *(undefined1 *)(param_3 + 9) = 1;
      *(uint *)((long)param_3 + 0x1c) = uVar1;
      if (*(int *)((long)param_3 + 0x34) < 0) {
        lVar11 = 0;
        param_1 = 0;
      }
      else {
        lVar11 = param_3[1];
      }
      (*(code *)*param_3)(param_1,lVar11,*(undefined4 *)((long)param_3 + 0x14),(int)param_3[3],
                          (int)param_3[7]);
      return;
    }
    bVar4 = false;
  }
  else {
    bVar4 = true;
  }
  bVar3 = true;
  plVar9 = plVar2;
  if (plVar2 == (long *)0x0) {
LAB_0030e058:
    if (param_3[8] != 0) {
      nvAssertFailedNoLog("pCallback->Next == NULL","src/kernel/gpu/disp/vblank_callback/vblank.c",
                          0x77);
    }
    uVar5 = *(uint *)((long)param_3 + 0x34);
    if ((uVar5 & 1) == 0) {
      uVar10 = 0xffffffff;
      if ((uVar5 & 0x10) == 0) {
        if ((uVar5 & 0x40) == 0) {
          uVar10 = uVar1 + 1;
          *(uint *)((long)param_3 + 0x1c) = uVar10;
        }
        else {
          uVar10 = uVar1 + (int)param_3[4];
          *(uint *)((long)param_3 + 0x1c) = uVar10;
          if ((uVar5 & 4) != 0) {
            uVar5 = uVar5 & 0xffffffbf | 1;
            *(uint *)((long)param_3 + 0x34) = uVar5;
          }
        }
      }
    }
    else {
      uVar10 = *(uint *)((long)param_3 + 0x1c);
    }
    plVar9 = (long *)0x0;
    if ((uVar5 & 0x80) == 0) {
      plVar7 = plVar2;
      if (plVar2 != (long *)0x0) {
        do {
          plVar8 = plVar7;
          plVar7 = plVar8;
          if (uVar10 < *(uint *)((long)plVar8 + 0x1c)) goto joined_r0x0030e2f7;
          plVar7 = (long *)plVar8[8];
          plVar9 = plVar8;
        } while ((long *)plVar8[8] != (long *)0x0);
LAB_0030e270:
        plVar7 = (long *)0x0;
        goto LAB_0030e272;
      }
    }
    else {
      plVar7 = plVar2;
      if (plVar2 != (long *)0x0) {
        do {
          plVar8 = plVar7;
          plVar7 = plVar8;
          if (uVar10 <= *(uint *)((long)plVar8 + 0x1c)) goto joined_r0x0030e2f7;
          plVar7 = (long *)plVar8[8];
          plVar9 = plVar8;
        } while ((long *)plVar8[8] != (long *)0x0);
        goto LAB_0030e270;
      }
    }
LAB_0030e0c1:
    param_3[8] = (long)plVar2;
    if ((uVar5 & 0x10000000) != 0) {
      *(long **)(param_2 + 0xd0) = param_3;
      if (!bVar4) {
        return;
      }
      goto LAB_0030e0f0;
    }
    *(long **)(param_2 + 0xd8) = param_3;
  }
  else {
    do {
      while (param_3 != plVar9) {
        plVar9 = (long *)plVar9[8];
        if (plVar9 == (long *)0x0) goto LAB_0030e050;
      }
      nvDbg_Printf("src/kernel/gpu/disp/vblank_callback/vblank.c",0x6a,"kheadAddVblankCallback_IMPL"
                   ,1,"NVRM: headAddVblankCallback: VblankCallback already on the Callback List\n");
      plVar9 = (long *)plVar9[8];
      bVar3 = false;
    } while (plVar9 != (long *)0x0);
LAB_0030e050:
    if (bVar3) goto LAB_0030e058;
    nvDbg_Printf("src/kernel/gpu/disp/vblank_callback/vblank.c",0xcd,"kheadAddVblankCallback_IMPL",1
                 ,
                 "NVRM: VBlankCallback discarded in dacCRTCAddVblankCallback to avoid infinite loop\n"
                );
  }
  goto LAB_0030e22e;
joined_r0x0030e2f7:
  plVar8 = plVar9;
  if (plVar8 == (long *)0x0) goto LAB_0030e0c1;
LAB_0030e272:
  plVar8[8] = (long)param_3;
  param_3[8] = (long)plVar7;
LAB_0030e22e:
  if (!bVar4) {
    return;
  }
  if ((*(long *)(param_2 + 0xd0) == 0) && (*(long *)(param_2 + 0xd8) == 0)) {
    return;
  }
LAB_0030e0f0:
  iVar6 = kheadReadVblankIntrState_IMPL(param_1,param_2);
  if (iVar6 == 2) {
    return;
  }
  kheadWriteVblankIntrState_IMPL(param_1,param_2,2);
  nvDbg_Printf("src/kernel/gpu/disp/vblank_callback/vblank.c",0x100,"kheadAddVblankCallback_IMPL",1,
               "NVRM: headAddVblankCallback: Changed vblank stat to ENABLED\n");
  return;
}


// ===== 0030e350 kheadPauseVblankCbNotifications_IMPL =====

void kheadPauseVblankCbNotifications_IMPL(undefined8 param_1,long param_2,long param_3)

{
  long lVar1;
  
  lVar1 = *(long *)(param_2 + 0xd8);
  if ((*(byte *)(param_3 + 0x37) & 0x10) != 0) {
    lVar1 = *(long *)(param_2 + 0xd0);
  }
  while( true ) {
    if (lVar1 == 0) {
      kheadWriteVblankIntrState_IMPL(param_1,param_2,1);
      return;
    }
    if (*(char *)(lVar1 + 0x49) == '\x01') break;
    lVar1 = *(long *)(lVar1 + 0x40);
  }
  return;
}


// ===== 0030e3a0 kheadDeleteVblankCallback_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kheadDeleteVblankCallback_IMPL(undefined8 param_1,long param_2,undefined8 *param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  char cVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  bool bVar6;
  
  bVar6 = (*(byte *)((long)param_3 + 0x37) & 0x10) != 0;
  puVar4 = *(undefined8 **)(param_2 + 0xd8);
  if (bVar6) {
    puVar4 = *(undefined8 **)(param_2 + 0xd0);
  }
  uVar2 = *(undefined4 *)(param_2 + 200);
  if (bVar6) {
    uVar2 = *(undefined4 *)(param_2 + 0xc4);
  }
  cVar3 = (**(code **)(param_2 + 0x50))();
  if (cVar3 != '\0') {
    kheadWriteVblankIntrState_IMPL(param_1,param_2,1);
  }
  if (puVar4 == param_3) {
    if ((*(byte *)((long)param_3 + 0x37) & 0x10) == 0) {
      *(undefined8 *)(param_2 + 0xd8) = param_3[8];
    }
    else {
      *(undefined8 *)(param_2 + 0xd0) = param_3[8];
    }
    pcVar1 = (code *)*param_3;
    if ((pcVar1 != (code *)0x0) && ((*(uint *)((long)param_3 + 0x34) & 2) != 0)) {
      *(undefined4 *)((long)param_3 + 0x1c) = uVar2;
      if ((int)*(uint *)((long)param_3 + 0x34) < 0) {
        (*pcVar1)(0,0,*(undefined4 *)((long)param_3 + 0x14),*(undefined4 *)(param_3 + 3),
                  *(undefined4 *)(param_3 + 7));
      }
      else {
        (*pcVar1)(param_1,param_3[1],*(undefined4 *)((long)param_3 + 0x14),
                  *(undefined4 *)(param_3 + 3),*(undefined4 *)(param_3 + 7));
      }
    }
  }
  else {
    do {
      puVar5 = puVar4;
      if (puVar5 == (undefined8 *)0x0) goto LAB_0030e411;
      puVar4 = (undefined8 *)puVar5[8];
    } while ((undefined8 *)puVar5[8] != param_3);
    pcVar1 = (code *)*param_3;
    if ((pcVar1 != (code *)0x0) && ((*(uint *)((long)param_3 + 0x34) & 2) != 0)) {
      *(undefined4 *)((long)param_3 + 0x1c) = uVar2;
      if ((int)*(uint *)((long)param_3 + 0x34) < 0) {
        (*pcVar1)(0,0,*(undefined4 *)((long)param_3 + 0x14),*(undefined4 *)(param_3 + 3),
                  *(undefined4 *)(param_3 + 7));
      }
      else {
        (*pcVar1)(param_1,param_3[1],*(undefined4 *)((long)param_3 + 0x14),
                  *(undefined4 *)(param_3 + 3),*(undefined4 *)(param_3 + 7));
      }
    }
    puVar5[8] = param_3[8];
  }
LAB_0030e411:
  param_3[8] = 0;
  if (((*(long *)(param_2 + 0xd0) != 0) || (*(long *)(param_2 + 0xd8) != 0)) && (cVar3 != '\0')) {
    kheadWriteVblankIntrState_IMPL(param_1,param_2,2);
    return;
  }
  return;
}


// ===== 0030e5a0 kheadProcessVblankCallbacks_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kheadProcessVblankCallbacks_IMPL(long param_1,long param_2,uint param_3)

{
  undefined8 uVar1;
  long *plVar2;
  code *pcVar3;
  long lVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  long *plVar8;
  long *plVar9;
  uint local_50;
  ulong local_40 [2];
  
  uVar1 = *(undefined8 *)(param_1 + 0x1b88);
  uVar7 = param_3 | 6;
  if ((param_3 & 6) != 0) {
    uVar7 = param_3;
  }
  local_40[0] = 0;
  if ((uVar7 & 2) == 0) {
    local_50 = uVar7 & 4;
    bVar5 = false;
    goto LAB_0030e69e;
  }
  local_50 = uVar7 & 0xfffffffd;
  if (*(long **)(param_2 + 0xd0) == (long *)0x0) {
    bVar5 = false;
    local_50 = uVar7 & 4;
    goto LAB_0030e69e;
  }
  iVar6 = *(int *)(param_2 + 0xc4);
  plVar8 = (long *)(param_2 + 0xd0);
  bVar5 = false;
  plVar9 = *(long **)(param_2 + 0xd0);
  do {
    plVar2 = (long *)plVar9[8];
    uVar7 = *(uint *)((long)plVar9 + 0x34);
    if ((uVar7 & 0x10) == 0) {
      if ((*(int *)((long)plVar9 + 0x1c) == iVar6) || (*(int *)((long)plVar9 + 0x1c) + 1 == iVar6))
      {
        pcVar3 = (code *)*plVar9;
        *(int *)((long)plVar9 + 0x1c) = iVar6;
        if (pcVar3 != (code *)0x0) {
          if ((int)uVar7 < 0) {
            (*pcVar3)(0,0,*(undefined4 *)((long)plVar9 + 0x14),(int)plVar9[3],(int)plVar9[7]);
            uVar7 = *(uint *)((long)plVar9 + 0x34);
            bVar5 = true;
          }
          else {
            (*pcVar3)(param_1,plVar9[1],*(undefined4 *)((long)plVar9 + 0x14),(int)plVar9[3],
                      (int)plVar9[7]);
            uVar7 = *(uint *)((long)plVar9 + 0x34);
            bVar5 = true;
          }
        }
        if ((uVar7 & 4) == 0) {
          plVar9[8] = 0;
          *plVar8 = (long)plVar2;
          goto joined_r0x0030e66c;
        }
        if ((uVar7 & 0x40) == 0) {
          if ((uVar7 & 1) == 0) {
            *(int *)((long)plVar9 + 0x1c) = iVar6 + 1;
          }
        }
        else {
          *(uint *)((long)plVar9 + 0x34) = uVar7 & 0xffffffbf | 1;
          *(int *)((long)plVar9 + 0x1c) = (int)plVar9[4] + iVar6;
        }
      }
LAB_0030e68f:
      plVar8 = plVar9 + 8;
    }
    else {
      if ((local_40[0] < (ulong)plVar9[5]) &&
         (tmrGetCurrentTime_IMPL(uVar1,local_40), local_40[0] < (ulong)plVar9[5]))
      goto LAB_0030e68f;
      plVar9[8] = 0;
      *plVar8 = (long)plVar2;
      if (*plVar9 == 0) {
        nvAssertFailedNoLog("pCallback->Proc","src/kernel/gpu/disp/vblank_callback/vblank.c",0x214);
      }
      if ((*(long **)(param_2 + 0x148) != plVar9) && (*(char *)(param_2 + 0x144) == '\0')) {
        (*(code *)*plVar9)(param_1,plVar9[1],*(undefined4 *)((long)plVar9 + 0x14),(int)plVar9[3],
                           (int)plVar9[7]);
      }
      bVar5 = true;
    }
joined_r0x0030e66c:
    plVar9 = plVar2;
    if (plVar2 == (long *)0x0) {
      local_50 = local_50 & 4;
LAB_0030e69e:
      if ((local_50 == 0) || (plVar9 = *(long **)(param_2 + 0xd8), plVar9 == (long *)0x0)) {
        if (bVar5) {
          osQueueDpc(param_1);
          lVar4 = *(long *)(param_2 + 0xd0);
        }
        else {
          lVar4 = *(long *)(param_2 + 0xd0);
        }
        if (((lVar4 == 0) && (*(long *)(param_2 + 0xd8) == 0)) &&
           (iVar6 = kheadReadVblankIntrState_IMPL(param_1,param_2), iVar6 == 2)) {
          kheadWriteVblankIntrState_IMPL(param_1,param_2,1);
          nvDbg_Printf("src/kernel/gpu/disp/vblank_callback/vblank.c",0x2a1,
                       "kheadProcessVblankCallbacks_IMPL",1,
                       "NVRM: Changed vblank state on head %d to AVAILABLE\n",
                       *(undefined4 *)(param_2 + 0x140));
        }
        return;
      }
      local_50 = 0;
      iVar6 = *(int *)(param_2 + 200);
      plVar8 = (long *)(param_2 + 0xd8);
    }
  } while( true );
}


// ===== 0030e870 _vblankCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _vblankCallback(undefined8 param_1,long param_2)

{
  if (*(char *)(param_2 + 0x181) != '\0') {
    (**(code **)(param_2 + 0x188))(*(undefined8 *)(param_2 + 400),*(undefined8 *)(param_2 + 0x198));
    return 0;
  }
  return 0;
}


// ===== 0030e8b0 vblcbConstruct_IMPL =====

undefined1  [16] vblcbConstruct_IMPL(long param_1,undefined8 param_2,ulong param_3)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  undefined8 *puVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 extraout_RDX;
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  lVar4 = *(long *)(lVar3 + 0x1b80);
  if (lVar4 == 0) {
    auVar11._8_8_ = param_3;
    auVar11._0_8_ = 0x56;
    return auVar11;
  }
  puVar5 = *(undefined8 **)(param_3 + 0x40);
  uVar2 = *(uint *)(puVar5 + 1);
  if (uVar2 < 8) {
    param_3 = (ulong)uVar2;
    lVar6 = *(long *)(lVar4 + 0x288 + param_3 * 8);
    if (lVar6 != 0) {
      lVar1 = param_1 + 0x138;
      *(uint *)(param_1 + 0x1a0) = uVar2;
      *(undefined8 *)(param_1 + 0x188) = *puVar5;
      *(undefined8 *)(param_1 + 400) = puVar5[2];
      uVar7 = puVar5[3];
      *(code **)(param_1 + 0x138) = _vblankCallback;
      *(undefined8 *)(param_1 + 0x198) = uVar7;
      *(undefined8 *)(param_1 + 0x168) = 0x1000002400000000;
      *(long *)(param_1 + 0x140) = param_1;
      *(undefined1 *)(param_1 + 0x148) = 0;
      *(undefined8 *)(param_1 + 0x14c) = 0;
      *(undefined8 *)(param_1 + 0x154) = 0;
      *(undefined8 *)(param_1 + 0x160) = 0;
      *(undefined4 *)(param_1 + 0x170) = 0;
      *(undefined1 *)(param_1 + 0x181) = 1;
      *(undefined8 *)(param_1 + 0x178) = 0;
      *(long *)(lVar6 + 0x148) = lVar1;
      kheadAddVblankCallback_IMPL(lVar3,lVar6,lVar1);
      auVar8._0_8_ = kdispSetupVBlank_IMPL
                               (lVar3,lVar4,*puVar5,puVar5[2],puVar5[3],*(undefined4 *)(puVar5 + 1))
      ;
      if ((int)auVar8._0_8_ != 0) {
        kheadDeleteVblankCallback_IMPL(lVar3,lVar6,lVar1,0x30e9bf);
        auVar10._0_8_ = auVar8._0_8_ & 0xffffffff;
        auVar10._8_8_ = extraout_RDX;
        return auVar10;
      }
      auVar8._8_8_ = lVar1;
      return auVar8;
    }
  }
  auVar9._8_8_ = param_3;
  auVar9._0_8_ = 0x1f;
  return auVar9;
}


// ===== 0030ea5f vblcbDestruct_IMPL.cold =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vblcbDestruct_IMPL_cold(void)

{
  code *pcVar1;
  
  _DAT_00000148 = 0;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0030ea70 vblcbDestruct_IMPL =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vblcbDestruct_IMPL(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  code *pcVar4;
  undefined8 uStack_30;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1b80);
  if (*(uint *)(param_1 + 0x1a0) < 8) {
    lVar3 = *(long *)(lVar2 + 0x288 + (ulong)*(uint *)(param_1 + 0x1a0) * 8);
    *(undefined8 *)(lVar3 + 0x148) = 0;
    kdispSetupVBlank_IMPL(lVar1,lVar2,0,0,0,*(undefined4 *)(param_1 + 0x1a0),0);
    kheadDeleteVblankCallback_IMPL(lVar1,lVar3,param_1 + 0x138,uStack_30);
    return;
  }
  _DAT_00000148 = 0;
                    /* WARNING: Does not return */
  pcVar4 = (code *)invalidInstructionException();
  (*pcVar4)();
}


// ===== 0030eb00 vblcbCtrlSetVBlankNotification_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 vblcbCtrlSetVBlankNotification_IMPL(long param_1,char *param_2)

{
  long lVar1;
  char cVar2;
  long lVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  if (*(uint *)(param_1 + 0x1a0) < 8) {
    lVar3 = *(long *)(*(long *)(lVar1 + 0x1b80) + 0x288 + (ulong)*(uint *)(param_1 + 0x1a0) * 8);
  }
  else {
    lVar3 = 0;
  }
  if (*(long *)(param_1 + 0x138) == 0) {
    return 0x1f;
  }
  if (*param_2 == '\0') {
    *(undefined1 *)(param_1 + 0x181) = 0;
    kheadPauseVblankCbNotifications_IMPL(lVar1,lVar3,param_1 + 0x138);
    return 0;
  }
  *(undefined1 *)(param_1 + 0x181) = 1;
  cVar2 = (**(code **)(lVar3 + 0x50))(lVar1,lVar3);
  if (cVar2 != '\0') {
    return 0;
  }
  kheadWriteVblankIntrState_IMPL(lVar1,lVar3,2);
  return 0;
}


// ===== 0030ebd0 engstateStatePreInitUnlocked_IMPL =====

undefined8 engstateStatePreInitUnlocked_IMPL(void)

{
  return 0;
}


// ===== 0030ebe0 engstateStateInitUnlocked_IMPL =====

undefined8 engstateStateInitUnlocked_IMPL(void)

{
  return 0;
}


// ===== 0030ebf0 engstateConstructBase_IMPL =====

undefined8 engstateConstructBase_IMPL(long param_1,undefined8 param_2,uint param_3)

{
  long lVar1;
  
  *(undefined8 *)(param_1 + 0x50) = param_2;
  *(uint *)(param_1 + 0x4c) = param_3;
  *(undefined4 *)(param_1 + 0x58) = 0;
  if (*(char *)(param_1 + 0x48) == '\0') {
    lVar1 = __nvoc_objGetClassInfo();
    nvDbgSnprintf(param_1 + 0xe0,100,"%s:%d",*(undefined8 *)(lVar1 + 0x10),param_3 & 0xff);
    return 0;
  }
  return 0x56;
}


// ===== 0030ec60 engstateLogStateTransitionPre_IMPL =====

void engstateLogStateTransitionPre_IMPL(long param_1,uint param_2,ulong *param_3)

{
  ulong local_38 [5];
  
  if (param_2 < 0xb) {
    portMemSet(param_1 + 0x5c + (ulong)param_2 * 0xc,0,0xc);
    portMemSet(param_3,0,0x18);
    osGetPerformanceCounter(param_3 + 2);
    local_38[0] = 0;
    local_38[1] = 0;
    local_38[2] = 0;
    local_38[3] = 0;
    portMemExTrackingGetActiveStats(0,local_38);
    *param_3 = local_38[0] & 0xffffffff;
    param_3[1] = local_38[2];
    return;
  }
  nvAssertFailedNoLog("targetState < ENGSTATE_STATE_COUNT","src/kernel/gpu/eng_state.c",0x3d);
  return;
}


// ===== 0030ed00 engstateLogStateTransitionPost_IMPL =====

undefined1  [16] engstateLogStateTransitionPost_IMPL(long param_1,uint param_2,int *param_3)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  undefined1 auVar4 [16];
  long local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  char *local_80 [4];
  char *local_60;
  undefined *local_58;
  char *local_50;
  char *local_48;
  char *local_40;
  char *local_38;
  char *local_30;
  
  if (param_2 < 0xb) {
    osGetPerformanceCounter(&local_a8);
    local_80[0] = "Undefined";
    local_80[1] = "Construct";
    local_80[2] = "Pre-Init";
    lVar1 = param_1 + (ulong)param_2 * 0xc;
    local_80[3] = "Init";
    uVar3 = (ulong)(local_a8 - *(long *)(param_3 + 4)) / 1000;
    local_60 = "Pre-Load";
    *(int *)(lVar1 + 100) = (int)uVar3;
    local_58 = &DAT_00d0f55e;
    local_50 = "Post-Load";
    local_48 = "Pre-Unload";
    local_40 = "Unload";
    local_38 = "Post-Unload";
    local_30 = "Destroy";
    nvDbg_Printf("src/kernel/gpu/eng_state.c",0x70,"engstateLogStateTransitionPost_IMPL",1,
                 "NVRM: Engine %s state change: %s -> %s, took %uus\n",param_1 + 0xe0,
                 local_80[*(uint *)(param_1 + 0x58)],local_80[param_2],uVar3);
    local_a0 = 0;
    local_98 = 0;
    local_90 = 0;
    local_88 = 0;
    portMemExTrackingGetActiveStats(0,&local_a0);
    *(int *)(lVar1 + 0x5c) = (int)local_a0 - *param_3;
    uVar2 = (int)local_90 - param_3[2];
    uVar3 = (ulong)uVar2;
    *(uint *)(lVar1 + 0x60) = uVar2;
    nvDbg_Printf("src/kernel/gpu/eng_state.c",0x85,"engstateLogStateTransitionPost_IMPL",1,
                 "NVRM:     Memory usage change: %d allocations, %d bytes\n");
    *(uint *)(param_1 + 0x58) = param_2;
    auVar4._8_8_ = 0x30ee31;
    auVar4._0_8_ = uVar3;
    return auVar4;
  }
  auVar4 = nvAssertFailedNoLog("targetState < ENGSTATE_STATE_COUNT","src/kernel/gpu/eng_state.c",
                               0x5a);
  return auVar4;
}


// ===== 0030eeb0 engstateGetName_IMPL =====

long engstateGetName_IMPL(long param_1)

{
  return param_1 + 0xe0;
}


// ===== 0030eec0 engstateConstructEngine_IMPL =====

undefined8 engstateConstructEngine_IMPL(void)

{
  return 0;
}


// ===== 0030eed0 engstateDestruct_IMPL =====

void engstateDestruct_IMPL(void)

{
  return;
}


// ===== 0030eee0 engstateInitMissing_IMPL =====

void engstateInitMissing_IMPL(void)

{
  return;
}


// ===== 0030eef0 engstateStatePreInit_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong engstateStatePreInit_IMPL(undefined8 param_1,long *param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  
  cVar1 = rmGpuLockIsOwner();
  if (cVar1 == '\0') {
    nvAssertFailedNoLog("rmGpuLockIsOwner()","src/kernel/gpu/eng_state.c",0xc6);
    return 0x2f;
  }
  lVar4 = *param_2;
  if (*(code **)(lVar4 + 0x48) != engstateStatePreInitUnlocked_IMPL) {
    rmGpuLocksRelease(0,0);
    uVar2 = (**(code **)(*param_2 + 0x48))(param_1,param_2);
    uVar3 = rmGpuLocksAcquire(0,0x400000);
    if ((uVar2 != 0) || (uVar2 = uVar3, uVar3 != 0)) {
      return (ulong)uVar2;
    }
    lVar4 = *param_2;
  }
  uVar5 = (**(code **)(lVar4 + 0x40))(param_1,param_2);
  return uVar5;
}


// ===== 0030efb0 engstateStatePreInitLocked_IMPL =====

undefined8 engstateStatePreInitLocked_IMPL(void)

{
  return 0;
}


// ===== 0030efc0 engstateStateInit_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong engstateStateInit_IMPL(undefined8 param_1,long *param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  
  cVar1 = rmGpuLockIsOwner();
  if (cVar1 == '\0') {
    nvAssertFailedNoLog("rmGpuLockIsOwner()","src/kernel/gpu/eng_state.c",0xf6);
    return 0x2f;
  }
  lVar4 = *param_2;
  if (*(code **)(lVar4 + 0x58) != engstateStateInitUnlocked_IMPL) {
    rmGpuLocksRelease(0,0);
    uVar2 = (**(code **)(*param_2 + 0x58))(param_1,param_2);
    uVar3 = rmGpuLocksAcquire(0,0x400000);
    if ((uVar2 != 0) || (uVar2 = uVar3, uVar3 != 0)) {
      return (ulong)uVar2;
    }
    lVar4 = *param_2;
  }
  uVar5 = (**(code **)(lVar4 + 0x50))(param_1,param_2);
  return uVar5;
}


// ===== 0030f080 engstateStateInitLocked_IMPL =====

undefined8 engstateStateInitLocked_IMPL(void)

{
  return 0;
}


// ===== 0030f090 engstateStatePreLoad_IMPL =====

undefined8 engstateStatePreLoad_IMPL(void)

{
  return 0;
}


// ===== 0030f0a0 engstateStateLoad_IMPL =====

undefined8 engstateStateLoad_IMPL(void)

{
  return 0;
}


// ===== 0030f0b0 engstateStatePostLoad_IMPL =====

undefined8 engstateStatePostLoad_IMPL(void)

{
  return 0;
}


// ===== 0030f0c0 engstateStateUnload_IMPL =====

undefined8 engstateStateUnload_IMPL(void)

{
  return 0;
}


// ===== 0030f0d0 engstateStatePreUnload_IMPL =====

undefined8 engstateStatePreUnload_IMPL(void)

{
  return 0;
}


// ===== 0030f0e0 engstateStatePostUnload_IMPL =====

undefined8 engstateStatePostUnload_IMPL(void)

{
  return 0;
}


// ===== 0030f0f0 engstateStateDestroy_IMPL =====

void engstateStateDestroy_IMPL(void)

{
  return;
}


// ===== 0030f100 engstateIsPresent_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void engstateIsPresent_IMPL(long param_1,long param_2)

{
  (**(code **)(param_1 + 200))(param_1,*(undefined4 *)(param_2 + 0x4c));
  return;
}


// ===== 0030f120 gsyncmgrIsFirmwareGPUMismatch_GB100 =====

undefined4 gsyncmgrIsFirmwareGPUMismatch_GB100(undefined8 param_1,long param_2)

{
  long lVar1;
  
  if (param_2 == 0) {
    nvAssertFailedNoLog("pGsync != NULL",
                        "src/kernel/gpu/external_device/arch/blackwell/kern_gsync_gb100.c",0x26);
  }
  else {
    lVar1 = *(long *)(param_2 + 0x40);
    if (lVar1 == 0) {
      nvAssertFailedNoLog("pExtDev != NULL",
                          "src/kernel/gpu/external_device/arch/blackwell/kern_gsync_gb100.c",0x28);
    }
    else if (*(int *)(lVar1 + 0x1c) == 0x2061) {
      return CONCAT31((int3)*(int *)(lVar1 + 0x20),
                      ((uint)*(byte *)(lVar1 + 0x24) | *(int *)(lVar1 + 0x20) << 8) < 0x300);
    }
  }
  return 1;
}


// ===== 0030f1b0 gpuExtdevConstruct_GK104 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gpuExtdevConstruct_GK104(long param_1)

{
  char cVar1;
  long lVar2;
  long *local_20 [2];
  
  local_20[0] = (long *)0x0;
  local_20[0] = (long *)portMemAllocNonPaged(0x640);
  if (local_20[0] == (long *)0x0) {
    nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_external_device_gk104.c",0x35,
                 "gpuExtdevConstruct_GK104",4,"NVRM: Out of memory.\n");
    return 0x51;
  }
  if (*(char *)(param_1 + 0x446) == '\0') {
    portMemSet(local_20[0],0,0x640);
    lVar2 = extdevConstruct_P2060(param_1,local_20[0]);
    if (lVar2 != 0) {
      cVar1 = (**(code **)(*local_20[0] + 0x48))(param_1);
      if ((cVar1 != '\0') && (cVar1 = (**(code **)*local_20[0])(param_1), cVar1 != '\0')) {
        nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_external_device_gk104.c",0x4a,
                     "gpuExtdevConstruct_GK104",1,"NVRM: EXTDEV: device is connecting\n");
        cVar1 = (**(code **)(*local_20[0] + 0x18))(param_1,local_20);
        if ((cVar1 != '\0') && (cVar1 = (**(code **)(*local_20[0] + 8))(param_1), cVar1 != '\0')) {
          return 0;
        }
      }
      (**(code **)(*local_20[0] + 0x10))(param_1);
    }
  }
  portMemFree(local_20[0]);
  *(undefined4 *)(param_1 + 0x7f0) = 0x10;
  return 0;
}


// ===== 0030f300 extdevSaveI2cHandles_P2060 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 extdevSaveI2cHandles_P2060(long param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 *puVar3;
  ulong uVar4;
  int *piVar5;
  ulong unaff_RBX;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c [3];
  
  puVar3 = (undefined8 *)rmapiGetInterface(4);
  local_2c[0] = 0;
  iVar2 = 0xffff;
  piVar5 = (int *)(param_2 + 0x5d0);
  uVar4 = 0;
  do {
    if (*piVar5 == 0) {
      iVar2 = 0;
      unaff_RBX = uVar4;
    }
    uVar1 = (int)uVar4 + 1;
    uVar4 = (ulong)uVar1;
    piVar5 = piVar5 + 5;
  } while (uVar1 != 4);
  if (iVar2 == 0) {
    iVar2 = rmapiutilAllocClientAndDeviceHandles(puVar3,param_1,&local_38,&local_34,&local_30);
    if (iVar2 == 0) {
      iVar2 = (*(code *)*puVar3)(puVar3,local_38,local_30,local_2c,0x402c,0,0);
      if (iVar2 == 0) {
        *(undefined4 *)(param_2 + 0x5c0 + unaff_RBX * 0x14) = local_38;
        *(undefined4 *)(param_2 + 0x5c4 + unaff_RBX * 0x14) = local_34;
        *(undefined4 *)(param_2 + 0x5c8 + unaff_RBX * 0x14) = local_30;
        *(undefined4 *)(param_2 + 0x5cc + unaff_RBX * 0x14) = local_2c[0];
        *(undefined4 *)(param_2 + 0x5d0 + unaff_RBX * 0x14) = *(undefined4 *)(param_1 + 0x7ac);
        return 1;
      }
      nvAssertFailedNoLog("rmStatus == NV_OK",
                          "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x164,
                          0x30f375);
    }
    else {
      nvAssertFailedNoLog("rmStatus == NV_OK",
                          "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x15f);
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x159,
                 "extdevSaveI2cHandles_P2060",4,"NVRM: Maximum number of GPUs have been attached\n")
    ;
  }
  return 0;
}


// ===== 0030f480 gsyncReadFrameRate_P2060 =====

uint gsyncReadFrameRate_P2060(undefined8 param_1,undefined8 param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  byte local_2b;
  byte local_2a;
  byte local_29;
  
  uVar1 = readregu008_extdeviceTargeted(param_1,param_2,0x10,&local_2b);
  uVar2 = readregu008_extdeviceTargeted(param_1,param_2,0x11,&local_2a);
  uVar3 = readregu008_extdeviceTargeted(param_1,param_2,0x12,&local_29);
  uVar3 = uVar1 | uVar2 | uVar3;
  if (uVar3 == 0) {
    uVar1 = (uint)local_29 << 0x10 | (uint)local_2a << 8 | (uint)local_2b;
    iVar4 = 0;
    if (uVar1 != 0) {
      uVar1 = uVar1 + 2;
      iVar4 = (((uint)((int)(160000000 % (ulong)uVar1) << 0xb) / uVar1 + 5 +
               (int)(160000000 / (ulong)uVar1) * 0x800) / 10) * 10;
    }
    *param_3 = iVar4;
  }
  return uVar3;
}


// ===== 0030f540 gsyncReadHouseSyncFrameRate_P2060 =====

uint gsyncReadHouseSyncFrameRate_P2060(undefined8 param_1,undefined8 param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  byte local_2b;
  byte local_2a;
  byte local_29;
  
  uVar1 = readregu008_extdeviceTargeted(param_1,param_2,0x20,&local_2b);
  uVar2 = readregu008_extdeviceTargeted(param_1,param_2,0x21,&local_2a);
  uVar3 = readregu008_extdeviceTargeted(param_1,param_2,0x22,&local_29);
  uVar3 = uVar1 | uVar2 | uVar3;
  if (uVar3 == 0) {
    uVar1 = (uint)local_29 << 0x10 | (uint)local_2a << 8 | (uint)local_2b;
    iVar4 = 0;
    if (uVar1 != 0) {
      uVar1 = uVar1 + 2;
      iVar4 = (((uint)((int)(160000000 % (ulong)uVar1) << 0xb) / uVar1 + 5 +
               (int)(160000000 / (ulong)uVar1) * 0x800) / 10) * 10;
    }
    *param_3 = iVar4;
  }
  return uVar3;
}


// ===== 0030f600 gsyncResetFrameCountData_P2060 =====

uint gsyncResetFrameCountData_P2060(undefined8 param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  byte local_19 [9];
  
  if (param_2 != 0) {
    *(undefined8 *)(param_2 + 0x1b8) = 0x400000000;
    *(undefined8 *)(param_2 + 0x198) = 0;
    *(undefined8 *)(param_2 + 0x1a0) = 0;
    *(undefined8 *)(param_2 + 0x1b0) = 0;
    *(undefined8 *)(param_2 + 0x1c0) = 4;
    *(undefined2 *)(param_2 + 0x1c8) = 0;
    *(undefined1 *)(param_2 + 0x1ca) = 0;
    uVar1 = readregu008_extdeviceTargeted(param_1,param_2,5,local_19);
    local_19[0] = local_19[0] & 0xfb;
    uVar2 = writeregu008_extdeviceTargeted(param_1,param_2,5,local_19[0]);
    return uVar2 | uVar1;
  }
  return 0x1f;
}


// ===== 0030f6b0 gsyncDisableFrameLockInterrupt_P2060 =====

uint gsyncDisableFrameLockInterrupt_P2060(long param_1)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  int *piVar5;
  byte local_39 [9];
  
  piVar5 = (int *)(param_1 + 0x390);
  uVar1 = 0;
  iVar4 = 0;
  do {
    if (*piVar5 != -1) {
      lVar3 = gpumgrGetGpuFromId();
      if (lVar3 == 0) {
        nvAssertFailedNoLog("pTmpGpu",
                            "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x12a3);
      }
      uVar1 = readregu008_extdeviceTargeted(lVar3,param_1,5,local_39);
      local_39[0] = local_39[0] & 0xee;
      uVar2 = writeregu008_extdeviceTargeted(lVar3,param_1,5,local_39[0]);
      uVar1 = uVar1 | uVar2;
      nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x12ae,
                   "gsyncDisableFrameLockInterrupt_P2060",1,"NVRM: P2060[%d] disabled interrupt\n",
                   iVar4);
    }
    iVar4 = iVar4 + 1;
    piVar5 = piVar5 + 0x29;
  } while (iVar4 != 4);
  return uVar1;
}


// ===== 0030f790 gsyncCancelWatchdog_P2060 =====

void gsyncCancelWatchdog_P2060(long param_1)

{
  long lVar1;
  ulong uVar2;
  
  uVar2 = 0;
  *(undefined4 *)(param_1 + 0x170) = 0;
  do {
    if (*(int *)(param_1 + 0x390 + uVar2 * 0xa4) != -1) {
      lVar1 = gpumgrGetGpuFromId();
      if (lVar1 == 0) {
        nvAssertFailedNoLog("pTempGpu",
                            "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x1259);
      }
      nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x125b,
                   "gsyncCancelWatchdog_P2060",1,"NVRM: P2060[%d] extdevCancelWatchdog.\n",
                   uVar2 & 0xffffffff);
      extdevCancelWatchdog(lVar1,param_1);
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 != 4);
  return;
}


// ===== 0030f840 extdevGetDevice_P2060 =====

undefined8 extdevGetDevice_P2060(long param_1,long param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  byte local_19 [9];
  
  if (*(char *)(param_1 + 0x446) != '\0') {
    return 0;
  }
  if (*(char *)(param_1 + 0x490e) != '\0') {
    return 0;
  }
  iVar2 = readregu008_extdevice(param_1,param_2,7,local_19);
  bVar1 = local_19[0];
  if (iVar2 == 0) {
    if (local_19[0] >> 4 == 5) {
      uVar3 = 0x2060;
    }
    else {
      uVar3 = 0x2061;
      if (local_19[0] >> 4 != 4) {
        return 0;
      }
    }
    iVar2 = readregu008_extdevice(param_1,param_2,0x17,local_19);
    if (iVar2 == 0) {
      *(byte *)(param_2 + 0x18) = bVar1;
      *(byte *)(param_2 + 0x24) = local_19[0];
      *(undefined4 *)(param_2 + 0x1c) = uVar3;
      *(uint *)(param_2 + 0x20) = bVar1 & 0xf;
      return 1;
    }
  }
  return 0;
}


// ===== 0030f910 gsyncIsP2060MasterBoard =====

byte gsyncIsP2060MasterBoard(long param_1,long param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  int *piVar5;
  byte local_9;
  
  if (param_1 != 0) {
    piVar5 = (int *)(param_2 + 0x390);
    uVar4 = 0;
    do {
      if (*piVar5 == *(int *)(param_1 + 0x7ac)) {
        if (*(char *)(param_2 + 0x394 + uVar4 * 0xa4) != '\0') {
          iVar3 = readregu008_extdeviceTargeted(param_1,param_2,3,&local_9);
          bVar1 = 0;
          if (iVar3 == 0) {
            bVar1 = local_9 & 1;
          }
          return bVar1;
        }
        return 0;
      }
      uVar2 = (int)uVar4 + 1;
      uVar4 = (ulong)uVar2;
      piVar5 = piVar5 + 0x29;
    } while (uVar2 != 4);
  }
  return 0;
}


// ===== 0030f980 gsyncProgramFramelockEnable_P2060 =====

void gsyncProgramFramelockEnable_P2060(undefined8 param_1,long param_2,uint param_3,char param_4)

{
  undefined4 uVar1;
  ulong uVar2;
  int iVar3;
  undefined8 uStack_30;
  
  uVar2 = (ulong)param_3;
  if (param_4 != '\0') {
    nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x119a,
                 "gsyncProgramFramelockEnable_P2060",1,
                 "NVRM: P2060[%d]:%s snapshot reset to _SYNC_LOSS_TRUE _VCXO_NOT_SERVO _STEREO_NOLOCK\n"
                 ,uVar2,&DAT_00d0f88d);
    *(undefined4 *)(param_2 + 0x2d0 + uVar2 * 0x18) = 7;
    *(undefined8 *)(param_2 + 0x2e0 + uVar2 * 0x18) = 0;
    *(undefined8 *)(param_2 + 0x2d8 + uVar2 * 0x18) = 0;
    param_2 = param_2 + uVar2 * 0xa4;
    *(undefined4 *)(param_2 + 0x3d0) = 0;
    iVar3 = 1 << ((byte)param_3 & 0x1f);
    uVar1 = gsyncGetGsyncInstance(param_1,uStack_30);
    gsyncSignalServiceRequested(uVar1,iVar3,param_3);
    *(int *)(param_2 + 0x3cc) = iVar3;
    return;
  }
  nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x119a,
               "gsyncProgramFramelockEnable_P2060",1,
               "NVRM: P2060[%d]:%s snapshot reset to _SYNC_LOSS_TRUE _VCXO_NOT_SERVO _STEREO_NOLOCK\n"
               ,uVar2,&DAT_00d0f890);
  *(undefined4 *)(param_2 + 0x2d0 + uVar2 * 0x18) = 7;
  *(undefined8 *)(param_2 + 0x2e0 + uVar2 * 0x18) = 0;
  *(undefined8 *)(param_2 + 0x2d8 + uVar2 * 0x18) = 0;
  *(undefined4 *)(param_2 + 0x3d0 + uVar2 * 0xa4) = 0;
  return;
}


// ===== 0030fad0 gsyncReadSlaves_P2060 =====

uint gsyncReadSlaves_P2060(long param_1,long param_2)

{
  uint *puVar1;
  long lVar2;
  uint uVar3;
  ulong uVar4;
  uint *puVar5;
  int *piVar6;
  uint uVar7;
  uint local_48 [10];
  
  lVar2 = *(long *)(param_1 + 0x1b80);
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pKernelDisplay != NULL","generated/g_kern_disp_nvoc.h",0x4f9);
  }
  uVar7 = *(uint *)(lVar2 + 0x360);
  extdevGetBoundHeadsAndDisplayIds(param_1,local_48);
  piVar6 = (int *)(param_2 + 0x390);
  uVar4 = 0;
  do {
    if (*piVar6 == *(int *)(param_1 + 0x7ac)) {
      if (uVar7 == 0) {
        return 0;
      }
      puVar5 = local_48;
      piVar6 = (int *)(param_2 + 0x330 + uVar4 * 0xa4);
      puVar1 = puVar5 + uVar7;
      uVar7 = 0;
      do {
        if ((*piVar6 == 0) && ((piVar6[8] != 0 || (piVar6[0x10] != 0)))) {
          uVar7 = uVar7 | *puVar5;
        }
        puVar5 = puVar5 + 1;
        piVar6 = piVar6 + 1;
      } while (puVar5 != puVar1);
      return uVar7;
    }
    uVar3 = (int)uVar4 + 1;
    uVar4 = (ulong)uVar3;
    piVar6 = piVar6 + 0x29;
  } while (uVar3 != 4);
  return 0;
}


// ===== 0030fbc0 gsyncGpuStereoHeadSync.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void gsyncGpuStereoHeadSync_isra_0(long param_1,uint param_2,long param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  long lVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined4 *puVar8;
  undefined8 local_58 [2];
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined4 local_28;
  
  lVar4 = *(long *)(param_1 + 0x1b80);
  uVar1 = *(undefined4 *)(param_1 + 0x3b3c);
  uVar2 = *(undefined4 *)(param_1 + 0x3b34);
  if (lVar4 == 0) {
    nvAssertFailedNoLog("pKernelDisplay != NULL","generated/g_kern_disp_nvoc.h",0x4f9);
  }
  uVar3 = *(uint *)(lVar4 + 0x360);
  local_58[0] = 0;
  local_58[1] = 0;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  if (uVar3 != 0) {
    puVar6 = local_58;
    puVar8 = (undefined4 *)(param_3 + 0x330 + (ulong)param_2 * 0xa4);
    do {
      puVar7 = (undefined8 *)((long)puVar6 + 4);
      *(undefined4 *)puVar6 = puVar8[8];
      *(undefined4 *)(puVar6 + 2) = puVar8[0x10];
      *(undefined4 *)(puVar6 + 4) = *puVar8;
      puVar6 = puVar7;
      puVar8 = puVar8 + 1;
    } while (puVar7 != (undefined8 *)((long)local_58 + (ulong)uVar3 * 4));
  }
  local_28 = param_4;
  iVar5 = (**(code **)(param_1 + 0x3b90))(param_1 + 0x3b58,uVar2,uVar1,0x20800ac1,local_58,0x34);
  if (iVar5 == 0) {
    return;
  }
  nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xd99,
               "gsyncGpuStereoHeadSync",4,"NVRM: Stereo headsync failed\n");
  return;
}


// ===== 0030fd30 gsyncIsOnlyFrameLockMaster_P2060 =====

uint gsyncIsOnlyFrameLockMaster_P2060(long param_1)

{
  int *piVar1;
  uint uVar2;
  long lVar3;
  uint uVar4;
  long lVar5;
  
  lVar5 = 0;
  uVar4 = 0;
  do {
    if (*(int *)(param_1 + 0x390 + lVar5 * 4) != -1) {
      lVar3 = gpumgrGetGpuFromId();
      if (lVar3 == 0) {
        nvAssertFailedNoLog(&DAT_00d0f8e6,
                            "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x136c);
        return 0;
      }
      lVar3 = *(long *)(lVar3 + 0x1b80);
      if (lVar3 == 0) {
        nvAssertFailedNoLog("pKernelDisplay != NULL","generated/g_kern_disp_nvoc.h",0x4f9);
      }
      uVar2 = *(uint *)(lVar3 + 0x360);
      if (uVar2 != 0) {
        lVar3 = param_1 + lVar5 * 4;
        do {
          if (*(int *)(lVar3 + 0x350) != 0) {
            return 0;
          }
          if (*(int *)(lVar3 + 0x370) != 0) {
            return 0;
          }
          piVar1 = (int *)(lVar3 + 0x330);
          lVar3 = lVar3 + 4;
          uVar4 = uVar4 | CONCAT31((int3)((uint)*piVar1 >> 8),*piVar1 != 0);
        } while (lVar3 != param_1 + ((ulong)uVar2 + lVar5) * 4);
      }
    }
    lVar5 = lVar5 + 0x29;
    if (lVar5 == 0xa4) {
      return uVar4;
    }
  } while( true );
}


// ===== 0030fe30 extdevDestroy_P2060 =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

void extdevDestroy_P2060(long param_1,long param_2)

{
  uint uVar1;
  undefined8 uVar2;
  byte bVar3;
  undefined8 uVar4;
  int *piVar5;
  ulong uVar6;
  int iVar7;
  uint uVar8;
  ulong uVar9;
  long lVar10;
  long lVar11;
  
  uVar4 = rmapiGetInterface(4);
  lVar10 = *(long *)(param_1 + 0x1b80);
  if (lVar10 == 0) {
    nvAssertFailedNoLog("pKernelDisplay != NULL","generated/g_kern_disp_nvoc.h",0x4f9);
  }
  piVar5 = (int *)(param_2 + 0x390);
  uVar9 = 0;
  while (*piVar5 != *(int *)(param_1 + 0x7ac)) {
    uVar8 = (int)uVar9 + 1;
    uVar9 = (ulong)uVar8;
    piVar5 = piVar5 + 0x29;
    if (uVar8 == 4) goto LAB_0030fe8c;
  }
  uVar8 = *(uint *)(lVar10 + 0x360);
  uVar1 = *(uint *)(param_1 + 0x7a4);
  uVar2 = *(undefined8 *)(param_1 + 0x1b88);
  *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + -1;
  bVar3 = (byte)uVar1 & 0x1f;
  *(uint *)(param_2 + 0x168) =
       *(uint *)(param_2 + 0x168) & (-2 << bVar3 | 0xfffffffeU >> 0x20 - bVar3);
  lVar11 = param_2 + (ulong)uVar1 * 8;
  tmrEventDestroy_IMPL(uVar2,*(undefined8 *)(lVar11 + 0x1d0));
  *(undefined8 *)(lVar11 + 0x1d0) = 0;
  tmrEventDestroy_IMPL(uVar2);
  *(undefined8 *)(lVar11 + 0x30) = 0;
  if ((*(char *)(param_2 + 0x394 + uVar9 * 0xa4) != '\0') && (*(int *)(param_2 + 8) == 0)) {
    *(undefined4 *)(param_2 + 0x16c) = 0;
    writeregu008_extdeviceTargeted(param_1,param_2,4,0x10);
  }
  lVar11 = uVar9 * 0xa4 + param_2;
  if (*(char *)(lVar11 + 0x3b8) == '\x01') {
    if (uVar8 != 0) {
      uVar6 = 0;
      do {
        (**(code **)(lVar10 + 0x1f0))
                  (param_1,lVar10,uVar6 & 0xffffffff,*(undefined4 *)(lVar11 + 0x398 + uVar6 * 4),
                   lVar11,*(code **)(lVar10 + 0x1f0));
        uVar6 = uVar6 + 1;
      } while (uVar6 != uVar8);
    }
    *(undefined1 *)(param_2 + 0x3b8 + uVar9 * 0xa4) = 0;
  }
  gsyncRemoveGpu(param_1);
  iVar7 = 0xffff;
  *(undefined4 *)(param_2 + 0x390 + uVar9 * 0xa4) = 0xffffffff;
  *(undefined1 *)(param_2 + 0x394 + uVar9 * 0xa4) = 0;
  uVar6 = 0;
  *(undefined2 *)(param_1 + 0x4ac) = 0;
  piVar5 = (int *)(param_2 + 0x5d0);
  do {
    if (*(int *)(param_1 + 0x7ac) == *piVar5) {
      iVar7 = 0;
      uVar9 = uVar6;
    }
    uVar8 = (int)uVar6 + 1;
    uVar6 = (ulong)uVar8;
    piVar5 = piVar5 + 5;
  } while (uVar8 != 4);
  if (iVar7 == 0) {
    lVar10 = uVar9 * 0x14;
    rmapiutilFreeClientAndDeviceHandles
              (uVar4,param_2 + 0x5c0 + lVar10,param_2 + 0x5c4 + lVar10,param_2 + 0x5c8 + lVar10);
    *(undefined8 *)(param_2 + 0x5c0 + lVar10) = 0;
    *(undefined8 *)(param_2 + 0x5c8 + lVar10) = 0;
    *(undefined4 *)(param_2 + 0x5d0 + lVar10) = 0;
  }
  else {
    nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x34f,
                 "extdevDestroy_P2060",4,
                 "NVRM: Couldn\'t find saved GPU entry, check saved i2chandles. \n");
  }
LAB_0030fe8c:
  if (*(int *)(param_2 + 8) == 0) {
    extdevDestroy_Base(param_1,param_2);
    return;
  }
  return;
}


// ===== 00310100 GpuIsP2060Master =====

bool GpuIsP2060Master(long param_1,long param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  int *piVar5;
  byte local_19 [9];
  
  if (param_1 != 0) {
    piVar5 = (int *)(param_2 + 0x390);
    uVar4 = 0;
    do {
      if (*piVar5 == *(int *)(param_1 + 0x7ac)) {
        if (*(char *)(param_2 + 0x394 + uVar4 * 0xa4) == '\0') {
          return false;
        }
        iVar3 = readregu008_extdeviceTargeted(param_1,param_2,1,local_19);
        bVar1 = local_19[0];
        if ((iVar3 == 0) &&
           (iVar3 = readregu008_extdeviceTargeted(param_1,param_2,3,local_19), iVar3 == 0)) {
          return (local_19[0] >> 4 & 3) == bVar1 >> 6;
        }
        return false;
      }
      uVar2 = (int)uVar4 + 1;
      uVar4 = (ulong)uVar2;
      piVar5 = piVar5 + 0x29;
    } while (uVar2 != 4);
  }
  return false;
}


// ===== 003101c0 gsyncReadMaster_P2060 =====

uint gsyncReadMaster_P2060(long param_1,long param_2)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  long lVar4;
  int *piVar5;
  uint uVar6;
  uint local_48 [10];
  
  lVar4 = *(long *)(param_1 + 0x1b80);
  if (lVar4 == 0) {
    nvAssertFailedNoLog("pKernelDisplay != NULL","generated/g_kern_disp_nvoc.h",0x4f9);
  }
  uVar1 = *(uint *)(lVar4 + 0x360);
  extdevGetBoundHeadsAndDisplayIds(param_1,local_48);
  piVar5 = (int *)(param_2 + 0x390);
  uVar3 = 0;
  while (*piVar5 != *(int *)(param_1 + 0x7ac)) {
    uVar3 = uVar3 + 1;
    piVar5 = piVar5 + 0x29;
    if (uVar3 == 4) {
      return 0;
    }
  }
  uVar6 = 0;
  if (uVar1 != 0) {
    lVar4 = 0;
    uVar6 = 0;
    do {
      if (*(int *)((ulong)uVar3 * 0xa4 + param_2 + 0x330 + lVar4) != 0) {
        uVar6 = uVar6 | *(uint *)((long)local_48 + lVar4);
      }
      lVar4 = lVar4 + 4;
    } while (lVar4 != (ulong)uVar1 << 2);
  }
  cVar2 = gsyncIsP2060MasterBoard(param_1,param_2);
  if ((cVar2 != '\0') && (cVar2 = GpuIsP2060Master(param_1,param_2), cVar2 != '\0')) {
    if (uVar6 == 0) {
      uVar6 = 0xffffffff;
    }
    return uVar6;
  }
  return 0;
}


// ===== 003102e0 gsyncIsFrameLockMaster_P2060 =====

undefined8 gsyncIsFrameLockMaster_P2060(long param_1)

{
  int iVar1;
  long lVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_1 + 0x390);
  do {
    if (*piVar3 != -1) {
      lVar2 = gpumgrGetGpuFromId();
      if (lVar2 == 0) {
        nvAssertFailedNoLog("pTmpGpu",
                            "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x1330);
      }
      iVar1 = gsyncReadMaster_P2060(lVar2,param_1);
      if (iVar1 != 0) {
        return 1;
      }
    }
    piVar3 = piVar3 + 0x29;
    if (piVar3 == (int *)(param_1 + 0x620)) {
      return 0;
    }
  } while( true );
}


// ===== 00310370 gsyncIsFrameLocked_P2060 =====

undefined8 gsyncIsFrameLocked_P2060(long param_1)

{
  int iVar1;
  long lVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_1 + 0x390);
  do {
    if (*piVar3 != -1) {
      lVar2 = gpumgrGetGpuFromId();
      if (lVar2 == 0) {
        nvAssertFailedNoLog("pTmpGpu",
                            "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x134c);
      }
      iVar1 = gsyncReadMaster_P2060(lVar2,param_1);
      if (iVar1 != 0) {
        return 1;
      }
      iVar1 = gsyncReadSlaves_P2060(lVar2,param_1);
      if (iVar1 != 0) {
        return 1;
      }
    }
    piVar3 = piVar3 + 0x29;
    if (piVar3 == (int *)(param_1 + 0x620)) {
      return 0;
    }
  } while( true );
}


// ===== 00310410 gsyncUpdateGsyncStatusSnapshot_P2060 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gsyncUpdateGsyncStatusSnapshot_P2060(undefined8 param_1,long param_2)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  undefined4 uVar6;
  long lVar7;
  long lVar8;
  byte bVar9;
  int iVar10;
  int *piVar11;
  ulong uVar12;
  uint *puVar13;
  uint *puVar14;
  uint uVar15;
  int *piVar16;
  uint *puVar17;
  byte local_49;
  uint local_48 [6];
  
  local_49 = 0;
  cVar3 = gsyncIsFrameLocked_P2060(param_2);
  if (cVar3 != '\0') {
    puVar14 = (uint *)(param_2 + 0x2d0);
    piVar16 = (int *)(param_2 + 0x390);
    iVar10 = 0;
    puVar17 = local_48;
    piVar11 = piVar16;
    puVar13 = puVar14;
    do {
      iVar5 = *piVar11;
      *puVar17 = 0;
      if (iVar5 != -1) {
        lVar7 = gpumgrGetGpuFromId();
        if (lVar7 == 0) {
          nvAssertFailedNoLog("pIfaceGpu",
                              "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xdc6)
          ;
        }
        iVar5 = readregu008_extdeviceTargeted(lVar7,param_2,0,&local_49);
        bVar2 = local_49;
        if (iVar5 != 0) {
          return 0xffff;
        }
        uVar15 = (uint)local_49;
        uVar1 = *puVar13;
        bVar4 = local_49 & 3;
        bVar9 = (byte)iVar10;
        if (bVar4 == 3) {
          if ((local_49 & 4) == 0) {
            if (piVar11[0x10] == 0) {
              nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xdd8,
                           "gsyncUpdateGsyncStatusSnapshot_P2060",1,
                           "NVRM: P2060[%d] is local master => GAINED SYNC\n",iVar10);
              piVar11[0x10] = 1;
            }
            nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xe2a,
                         "gsyncUpdateGsyncStatusSnapshot_P2060",1,
                         "NVRM: Update P2060[%d] settled from 0x%x ( ",iVar10,uVar1);
            nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xe2d,
                         "gsyncUpdateGsyncStatusSnapshot_P2060",1,") to 0x%x ( ",uVar15);
            nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xe2f,
                         "gsyncUpdateGsyncStatusSnapshot_P2060",1,&DAT_00d0f974);
            *puVar13 = uVar15;
            if (((uVar1 ^ uVar15) & 7) != 0) {
LAB_00310850:
              *puVar17 = 1 << (bVar9 + 4 & 0x1f);
            }
          }
          else {
            piVar11[0x10] = 0;
            puVar13[2] = 0;
            puVar13[3] = 0;
            nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xe2a,
                         "gsyncUpdateGsyncStatusSnapshot_P2060",1,
                         "NVRM: Update P2060[%d] settled from 0x%x ( ",iVar10);
            nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xe2d,
                         "gsyncUpdateGsyncStatusSnapshot_P2060",1,") to 0x%x ( ",uVar15);
            nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xe2f,
                         "gsyncUpdateGsyncStatusSnapshot_P2060",1,&DAT_00d0f974);
            *puVar13 = uVar15;
            if (((uVar1 ^ uVar15) & 7) != 0) {
LAB_00310a58:
              *puVar17 = 1 << (bVar9 & 0x1f);
            }
          }
LAB_0031085d:
          if (((uVar1 ^ uVar15) & 0x40) != 0) {
            if ((bVar2 & 0x40) == 0) {
              *puVar17 = *puVar17 | 1 << (iVar10 + 8U & 0x1f);
            }
            else {
              *puVar17 = *puVar17 | 1 << (iVar10 + 0xcU & 0x1f);
            }
          }
        }
        else {
          if (piVar11[0x10] == 0) {
            if (bVar4 == 2) {
              lVar8 = (**(code **)(*(long *)(lVar7 + 0x1b88) + 0x1a0))();
              if (*(long *)(puVar13 + 2) == 0) {
                *(long *)(puVar13 + 2) = lVar8;
                nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xdf9,
                             "gsyncUpdateGsyncStatusSnapshot_P2060",1,
                             "NVRM: P2060[%d] snapshot timeDiff is %d ms\n",iVar10,0);
              }
              else {
                uVar12 = lVar8 - *(long *)(puVar13 + 2);
                nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xdf9,
                             "gsyncUpdateGsyncStatusSnapshot_P2060",1,
                             "NVRM: P2060[%d] snapshot timeDiff is %d ms\n",iVar10,uVar12 / 1000000)
                ;
                if (4999999999 < uVar12) {
                  nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xe04
                               ,"gsyncUpdateGsyncStatusSnapshot_P2060",1,
                               "NVRM: P2060[%d] GAINED SYNC\n",iVar10);
                  piVar11[0x10] = 1;
                  if ((bVar2 & 0x10) != 0) {
                    gsyncGpuStereoHeadSync_isra_0(lVar7,iVar10,param_2,uVar15);
                    puVar13[4] = 0;
                    puVar13[5] = 0;
                  }
                  goto LAB_003107a0;
                }
              }
              goto LAB_00310590;
            }
          }
          else if (bVar4 == 2) {
LAB_003107a0:
            nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xe2a,
                         "gsyncUpdateGsyncStatusSnapshot_P2060",1,
                         "NVRM: Update P2060[%d] settled from 0x%x ( ",iVar10,uVar1);
            nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xe2d,
                         "gsyncUpdateGsyncStatusSnapshot_P2060",1,") to 0x%x ( ",uVar15);
            nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xe2f,
                         "gsyncUpdateGsyncStatusSnapshot_P2060",1,&DAT_00d0f974);
            *puVar13 = uVar15;
            if (((uVar1 ^ uVar15) & 7) != 0) {
              if ((bVar2 & 4) != 0) goto LAB_00310a58;
              goto LAB_00310850;
            }
            goto LAB_0031085d;
          }
          piVar11[0x10] = 0;
          puVar13[2] = 0;
          puVar13[3] = 0;
          nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xe2a,
                       "gsyncUpdateGsyncStatusSnapshot_P2060",1,
                       "NVRM: Update P2060[%d] settled from 0x%x ( ",iVar10,uVar1);
          nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xe2d,
                       "gsyncUpdateGsyncStatusSnapshot_P2060",1,") to 0x%x ( ",uVar15);
          nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xe2f,
                       "gsyncUpdateGsyncStatusSnapshot_P2060",1,&DAT_00d0f974);
          *puVar13 = uVar15;
          if (((uVar15 ^ uVar1) & 7) != 0) {
            *puVar17 = 1 << (bVar9 & 0x1f);
          }
        }
      }
LAB_00310590:
      iVar10 = iVar10 + 1;
      puVar17 = puVar17 + 1;
      piVar11 = piVar11 + 0x29;
      puVar13 = puVar13 + 6;
    } while (iVar10 != 4);
    uVar12 = 0;
    do {
      if ((piVar16[0x10] != 0) && ((*puVar14 & 0x10) != 0)) {
        lVar7 = gpumgrGetGpuFromId(*piVar16);
        if (lVar7 == 0) {
          nvAssertFailedNoLog("pIfaceGpu",
                              "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xe70)
          ;
        }
        lVar8 = (**(code **)(*(long *)(lVar7 + 0x1b88) + 0x1a0))(lVar7);
        if (*(long *)(puVar14 + 4) == 0) {
LAB_0031097d:
          *(long *)(puVar14 + 4) = lVar8;
        }
        else if (4999 < (uint)((ulong)(lVar8 - *(long *)(puVar14 + 4)) / 1000000)) {
          gsyncGpuStereoHeadSync_isra_0(lVar7,uVar12 & 0xffffffff,param_2,*puVar14);
          goto LAB_0031097d;
        }
        if ((*puVar14 & 0x40) == 0) {
          local_48[uVar12] = local_48[uVar12] | 1 << ((char)uVar12 + 8U & 0x1f);
        }
      }
      uVar12 = uVar12 + 1;
      piVar16 = piVar16 + 0x29;
      puVar14 = puVar14 + 6;
    } while (uVar12 != 4);
    uVar12 = 0;
    puVar17 = (uint *)(param_2 + 0x3cc);
    do {
      uVar1 = local_48[uVar12];
      if ((uVar1 != 0) && (uVar1 != *puVar17)) {
        nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xe90,
                     "gsyncUpdateGsyncStatusSnapshot_P2060",1,"NVRM: Event P2060[%d]: 0x%x (",
                     uVar12 & 0xffffffff,uVar1);
        nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xe93,
                     "gsyncUpdateGsyncStatusSnapshot_P2060",1,&DAT_00d0f974);
        uVar6 = gsyncGetGsyncInstance(param_1);
        gsyncSignalServiceRequested(uVar6,uVar1,uVar12 & 0xffffffff);
        *puVar17 = uVar1;
      }
      uVar12 = uVar12 + 1;
      puVar17 = puVar17 + 0x29;
    } while (uVar12 != 4);
  }
  return 0;
}


// ===== 00310bf0 _extdevService =====

void _extdevService(undefined8 param_1,byte *param_2)

{
  long lVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  long lVar5;
  byte bVar6;
  char cVar7;
  int iVar8;
  undefined4 uVar9;
  long lVar10;
  int *piVar11;
  uint uVar12;
  ulong uVar13;
  undefined8 uVar14;
  char *pcVar15;
  uint auStack_48 [6];
  
  lVar10 = gpumgrGetGpu();
  lVar5 = *(long *)(param_2 + 8);
  bVar2 = *param_2;
  bVar3 = param_2[2];
  bVar4 = param_2[1];
  iVar8 = gsyncUpdateGsyncStatusSnapshot_P2060(lVar10,lVar5);
  if (iVar8 == 0) {
    uVar13 = 0;
    piVar11 = (int *)(lVar5 + 0x390);
    do {
      if (*piVar11 == *(int *)(lVar10 + 0x7ac)) {
        auStack_48[uVar13] = 0;
        bVar6 = (byte)uVar13;
        if (bVar2 != 0) {
          uVar12 = 0;
          if ((bVar2 & 1) != 0) {
            uVar12 = 1 << (bVar6 & 0x1f);
            auStack_48[uVar13] = uVar12;
          }
          if ((bVar2 & 2) == 0) {
            if ((bVar2 & 4) == 0) {
              if ((bVar2 & 8) == 0) {
                if (uVar12 != 0) goto LAB_00310d10;
                goto LAB_00310d80;
              }
            }
            else {
LAB_00310ef8:
              uVar12 = uVar12 | 0x20000;
              auStack_48[uVar13] = uVar12;
              if ((bVar2 & 8) == 0) goto LAB_00310d10;
            }
LAB_00310ea0:
            uVar12 = uVar12 | 0x80000;
            auStack_48[uVar13] = uVar12;
          }
          else {
            uVar12 = uVar12 | 1 << (bVar6 + 8 & 0x1f);
            auStack_48[uVar13] = uVar12;
            if ((bVar2 & 4) != 0) goto LAB_00310ef8;
            if ((bVar2 & 8) != 0) goto LAB_00310ea0;
          }
LAB_00310d10:
          extdevScheduleWatchdog(lVar10,lVar5);
          cVar7 = gsyncIsOnlyFrameLockMaster_P2060(lVar5);
          if (cVar7 == '\0') {
            *(undefined4 *)(lVar5 + 0x170) = 0x3c;
          }
          if (*(uint *)(lVar5 + 0x3cc + uVar13 * 0xa4) != uVar12) {
            uVar9 = gsyncGetGsyncInstance(lVar10);
            gsyncSignalServiceRequested(uVar9,uVar12,uVar13);
            *(uint *)(lVar5 + 0x3cc + uVar13 * 0xa4) = uVar12;
          }
        }
LAB_00310d80:
        if (bVar4 == 0) goto LAB_00310e00;
        uVar12 = auStack_48[uVar13];
        if ((bVar4 & 1) != 0) {
          uVar12 = auStack_48[uVar13] | 1 << ((int)uVar13 + 4U & 0x1f);
        }
        if ((bVar4 & 2) == 0) {
          if ((bVar4 & 4) == 0) {
            if ((bVar4 & 8) == 0) {
              if (uVar12 == 0) goto LAB_00310e00;
              goto LAB_00310dc0;
            }
          }
          else {
LAB_00310f10:
            uVar12 = uVar12 | 0x10000;
            if ((bVar4 & 8) == 0) goto LAB_00310dc0;
          }
LAB_00310e60:
          uVar12 = uVar12 | 0x40000;
        }
        else {
          uVar12 = uVar12 | 1 << (bVar6 + 0xc & 0x1f);
          if ((bVar4 & 4) != 0) goto LAB_00310f10;
          if ((bVar4 & 8) != 0) goto LAB_00310e60;
        }
LAB_00310dc0:
        lVar1 = lVar5 + uVar13 * 0xa4;
        if (*(uint *)(lVar1 + 0x3cc) != uVar12) {
          uVar9 = gsyncGetGsyncInstance(lVar10);
          gsyncSignalServiceRequested(uVar9,uVar12,uVar13);
          *(uint *)(lVar1 + 0x3cc) = uVar12;
        }
LAB_00310e00:
        if (bVar3 != 0) {
          if ((bVar3 & 1) != 0) {
            *(undefined1 *)(lVar5 + 0x1c8) = 1;
            iVar8 = gsyncResetFrameCountData_P2060(lVar10,lVar5);
            if (iVar8 == 0) {
              *(undefined1 *)(lVar5 + 0x1c9) = 1;
            }
          }
          if ((bVar3 & 4) != 0) {
            gsyncUpdateGsyncStatusSnapshot_P2060(lVar10,lVar5);
            return;
          }
        }
        return;
      }
      uVar12 = (int)uVar13 + 1;
      uVar13 = (ulong)uVar12;
      piVar11 = piVar11 + 0x29;
    } while (uVar12 != 4);
    pcVar15 = "NVRM: Cannot get P2060 Gpu location for serving interrupt.\n";
    uVar14 = 0x3b9;
  }
  else {
    pcVar15 = "NVRM: Couldn\'t raad the register status physical RMs.\n";
    uVar14 = 0x3b2;
  }
  nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",uVar14,
               "_extdevService",4,pcVar15);
  return;
}


// ===== 00310f30 extdevService_P2060 =====

void extdevService_P2060(long param_1,undefined8 param_2,undefined1 param_3,undefined1 param_4,
                        undefined1 param_5,char param_6)

{
  int iVar1;
  undefined8 *puVar2;
  undefined1 local_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  undefined5 uStack_15;
  undefined8 local_10;
  
  if (param_6 == '\0') {
    return;
  }
  if (*(char *)(param_1 + 0x909) != '\0') {
    puVar2 = (undefined8 *)portMemAllocNonPaged(0x10);
    if (puVar2 == (undefined8 *)0x0) {
      nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x38f,
                   "extdevService_P2060",4,"NVRM: Memalloc failed\n");
    }
    else {
      *puVar2 = CONCAT53(uStack_15,CONCAT12(param_5,CONCAT11(param_4,param_3)));
      puVar2[1] = param_2;
      local_18 = param_3;
      uStack_17 = param_4;
      uStack_16 = param_5;
      local_10 = param_2;
    }
    iVar1 = osQueueWorkItem(param_1,_extdevService,puVar2,0x100);
    if (iVar1 == 0) {
      return;
    }
    portMemFree(puVar2);
    return;
  }
  local_18 = param_3;
  uStack_17 = param_4;
  uStack_16 = param_5;
  local_10 = param_2;
  _extdevService(*(undefined4 *)(param_1 + 0x7a4),&local_18);
  return;
}


// ===== 00311050 gsyncReadHouseSignalPresent_P2060 =====

undefined8 gsyncReadHouseSignalPresent_P2060(long param_1,long param_2,char param_3,uint *param_4)

{
  uint uVar1;
  ulong uVar2;
  undefined8 uVar3;
  int *piVar4;
  int *piVar5;
  byte local_19 [9];
  
  piVar5 = (int *)(param_2 + 0x390);
  uVar2 = 0;
  piVar4 = piVar5;
  do {
    if (*piVar4 == *(int *)(param_1 + 0x7ac)) {
      if ((param_3 != '\0') && ((*(byte *)(param_2 + 0x2d0 + uVar2 * 0x18) & 4) != 0)) {
        uVar3 = gsyncUpdateGsyncStatusSnapshot_P2060();
        if ((int)uVar3 != 0) {
          return 0xffff;
        }
        uVar2 = 0;
        while (*piVar5 != *(int *)(param_1 + 0x7ac)) {
          uVar1 = (int)uVar2 + 1;
          uVar2 = (ulong)uVar1;
          piVar5 = piVar5 + 0x29;
          if (uVar1 == 4) {
            return uVar3;
          }
        }
        if ((*(byte *)(param_2 + 0x2d0 + uVar2 * 0x18) & 4) != 0) {
          *param_4 = 0;
          return uVar3;
        }
        return 0;
      }
      break;
    }
    uVar1 = (int)uVar2 + 1;
    uVar2 = (ulong)uVar1;
    piVar4 = piVar4 + 0x29;
  } while (uVar1 != 4);
  uVar3 = readregu008_extdeviceTargeted(param_1,param_2,1,local_19);
  if ((int)uVar3 == 0) {
    *param_4 = (uint)((local_19[0] & 0x30) != 0);
  }
  return uVar3;
}


// ===== 00311130 extdevWatchdog_P2060 =====

ulong extdevWatchdog_P2060(long param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  long lVar6;
  long lVar7;
  byte *pbVar8;
  ulong uVar9;
  long lVar10;
  long lVar11;
  long local_60;
  uint local_50;
  byte local_3a;
  byte local_39 [9];
  
  lVar7 = *(long *)(param_1 + 0x1b80);
  if (lVar7 == 0) {
    nvAssertFailedNoLog("pKernelDisplay != NULL","generated/g_kern_disp_nvoc.h",0x4f9);
  }
  uVar1 = *(uint *)(lVar7 + 0x360);
  if (*(int *)(param_3 + 0x170) != 0) {
    *(int *)(param_3 + 0x170) = *(int *)(param_3 + 0x170) + -1;
  }
  piVar5 = (int *)(param_3 + 0x390);
  do {
    if (*piVar5 != -1) {
      local_60 = gpumgrGetGpuFromId();
      if (local_60 != 0) goto LAB_003111c6;
      nvAssertFailedNoLog("pTmpGpu","src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",
                          0x1216);
      break;
    }
    piVar5 = piVar5 + 0x29;
  } while (piVar5 != (int *)(param_3 + 0x620));
  nvAssertFailedNoLog(&DAT_00d0f8e6,"src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",
                      0x44a);
  local_60 = 0;
LAB_003111c6:
  extdevScheduleWatchdog(local_60,param_3);
  iVar3 = gsyncUpdateGsyncStatusSnapshot_P2060(local_60,param_3);
  cVar2 = gsyncIsFrameLocked_P2060(param_3);
  if (cVar2 == '\0') {
    gsyncCancelWatchdog_P2060(param_3);
    uVar9 = gsyncDisableFrameLockInterrupt_P2060(param_3);
    return uVar9;
  }
  pbVar8 = (byte *)(param_3 + 0x2d0);
  lVar11 = param_3 + (ulong)uVar1 * 4;
  lVar10 = param_3;
  do {
    if (*(int *)(lVar10 + 0x390) != -1) {
      lVar6 = gpumgrGetGpuFromId();
      if (lVar6 == 0) {
        nvAssertFailedNoLog("pTmpGpu",
                            "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x461);
      }
      iVar4 = readregu008_extdeviceTargeted(lVar6,param_3,0,local_39);
      lVar6 = lVar10;
      if (uVar1 != 0) {
        do {
          if ((*(int *)(lVar6 + 0x350) != 0) || (*(int *)(lVar6 + 0x370) != 0)) {
            if ((*(int *)(lVar10 + 0x3d0) == 0) ||
               (((*pbVar8 & 0x40) == 0 && (iVar4 == 0 && (local_39[0] & 0x30) != 0)))) {
              local_50 = 0xffff;
              goto LAB_00311259;
            }
            break;
          }
          lVar6 = lVar6 + 4;
        } while (lVar6 != lVar11);
      }
    }
    lVar10 = lVar10 + 0xa4;
    lVar11 = lVar11 + 0xa4;
    pbVar8 = pbVar8 + 0x18;
  } while (lVar10 != param_3 + 0x290);
  if (iVar3 == 0) {
    local_50 = 0;
    if ((*(char *)(lVar7 + 0x35c) == '\0') || (*(int *)(param_3 + 0x170) != 0)) goto LAB_00311259;
    uVar9 = 0;
    nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x480,
                 "extdevWatchdog_P2060",1,"NVRM: P2060[%d] extdevCancelWatchdog.\n",4);
    extdevCancelWatchdog(local_60,param_3);
    do {
      if (*(int *)(param_3 + 0x390 + uVar9 * 0xa4) != -1) {
        lVar7 = gpumgrGetGpuFromId();
        if (lVar7 == 0) {
          nvAssertFailedNoLog("pTmpGpu",
                              "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x1277
                             );
        }
        iVar3 = gsyncReadMaster_P2060(lVar7,param_3);
        if ((iVar3 != 0) || (iVar3 = gsyncReadSlaves_P2060(lVar7,param_3), iVar3 != 0)) {
          readregu008_extdeviceTargeted(lVar7,param_3,5,&local_3a);
          iVar3 = readregu008_extdeviceTargeted(lVar7,param_3,0,local_39);
          if ((iVar3 == 0) && ((local_39[0] & 0x30) != 0)) {
            local_3a = local_3a | 1;
          }
          local_3a = local_3a | 0x10;
          writeregu008_extdeviceTargeted(lVar7,param_3,5,local_3a);
          nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x1287,
                       "gsyncEnableFramelockInterrupt_P2060",1,"NVRM: P2060[%d] enabled interrupt\n"
                       ,uVar9 & 0xffffffff);
        }
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 != 4);
  }
  local_50 = 0;
LAB_00311259:
  return (ulong)local_50;
}


// ===== 003114e0 GpuIsConnectedToMasterViaBridge =====

undefined8 GpuIsConnectedToMasterViaBridge(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  long lVar3;
  int *piVar4;
  undefined8 uVar5;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_30 [4];
  undefined1 local_2c [12];
  
  gpumgrGetGpuAttachInfo(0,&local_38);
  local_34 = 0;
LAB_00311510:
  do {
    do {
      lVar3 = gpumgrGetNextGpu(local_38,&local_34);
      if (lVar3 == 0) {
        return 0;
      }
    } while ((lVar3 == param_1) ||
            (iVar2 = gpumgrGetGpuLockAndDrPorts(param_1,lVar3,local_30,local_2c), iVar2 != 0));
    piVar4 = (int *)(param_2 + 0x390);
    iVar2 = *piVar4;
    while (iVar2 != *(int *)(lVar3 + 0x7ac)) {
      piVar4 = piVar4 + 0x29;
      if (piVar4 == (int *)(param_2 + 0x620)) goto LAB_00311510;
      iVar2 = *piVar4;
    }
    cVar1 = gsyncIsP2060MasterBoard(lVar3,param_2);
    if ((cVar1 != '\0') && (uVar5 = GpuIsP2060Master(lVar3,param_2), (char)uVar5 != '\0')) {
      return uVar5;
    }
  } while( true );
}


// ===== 003115a0 gsyncUpdateFrameCount_P2060 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint gsyncUpdateFrameCount_P2060(long param_1,long param_2)

{
  int *piVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  long lVar8;
  int *piVar9;
  int iVar10;
  undefined8 uVar11;
  int iVar12;
  uint local_6c;
  byte local_64;
  byte local_63;
  byte local_62;
  byte local_61;
  uint local_60;
  int local_5c;
  undefined8 local_58;
  undefined1 local_50 [32];
  
  lVar8 = *(long *)(param_2 + 0x1b80);
  local_58 = 0;
  if (lVar8 == 0) {
    nvAssertFailedNoLog("pKernelDisplay != NULL","generated/g_kern_disp_nvoc.h",0x4f9);
  }
  uVar3 = *(uint *)(lVar8 + 0x360);
  piVar7 = (int *)(param_1 + 0x330);
  uVar4 = 0;
  iVar10 = 0;
LAB_003115e1:
  do {
    if (piVar7[0x18] != -1) {
      piVar9 = piVar7;
      if (uVar3 == 0) {
        iVar10 = iVar10 + 1;
        uVar4 = 0;
        piVar7 = piVar7 + 0x29;
        if (iVar10 == 4) break;
        goto LAB_003115e1;
      }
      do {
        while( true ) {
          uVar4 = 0;
          piVar7 = piVar9;
          do {
            if (((*piVar7 != 0) || (piVar7[8] != 0)) || (piVar7[0x10] != 0)) {
              *(int *)(param_1 + 0x1bc) = iVar10;
              *(uint *)(param_1 + 0x1c0) = uVar4;
              goto joined_r0x0031163a;
            }
            uVar4 = uVar4 + 1;
            piVar7 = piVar7 + 1;
          } while (uVar4 != uVar3);
          if (iVar10 == 3) {
            return 0xffff;
          }
          if (piVar9[0x41] == -1) break;
          iVar10 = iVar10 + 1;
          piVar9 = piVar9 + 0x29;
        }
        iVar10 = iVar10 + 2;
        if (iVar10 == 4) goto joined_r0x0031163a;
        piVar7 = piVar9 + 0x52;
        piVar1 = piVar9 + 0x6a;
        piVar9 = piVar7;
      } while (*piVar1 != -1);
    }
    iVar10 = iVar10 + 1;
    piVar7 = piVar7 + 0x29;
  } while (iVar10 != 4);
joined_r0x0031163a:
  if (uVar4 == uVar3) {
    return 0xffff;
  }
  lVar8 = gpumgrGetGpuFromId(*(undefined4 *)
                              (param_1 + 0x390 + (ulong)*(uint *)(param_1 + 0x1bc) * 0xa4));
  if (lVar8 == 0) {
    nvAssertFailedNoLog(&DAT_00d0f8e6,
                        "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x1464);
  }
  else {
    lVar2 = *(long *)(lVar8 + 0x1b80);
    if (lVar2 == 0) {
      nvAssertFailedNoLog("pKernelDisplay != NULL",
                          "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x146c);
    }
    else {
      if (uVar4 < *(uint *)(lVar2 + 0x360)) {
        local_58._0_4_ = uVar4;
        uVar4 = (**(code **)(lVar8 + 0x3b90))
                          (lVar8 + 0x3b58,*(undefined4 *)(lVar8 + 0x3b34),
                           *(undefined4 *)(lVar8 + 0x3b3c),0x20800ac4,&local_58,8);
        uVar3 = local_58._4_4_;
        if (uVar4 != 0) {
          return uVar4;
        }
        *(uint *)(param_1 + 0x1c4) = local_58._4_4_;
        local_6c = (**(code **)(lVar2 + 0x1d8))
                             (lVar8,lVar2,*(undefined4 *)(param_1 + 0x1c0),&local_60);
        if (local_6c == 0) {
          uVar4 = (uVar3 * 7) / 10;
          if ((local_60 < uVar4) && (uVar3 / 0x14 < local_60)) {
LAB_0031173c:
            uVar3 = readregu008_extdeviceTargeted(lVar8,param_1,0xd,&local_64);
            uVar4 = readregu008_extdeviceTargeted(lVar8,param_1,0xe,&local_63);
            uVar5 = readregu008_extdeviceTargeted(lVar8,param_1,0xf,&local_62);
            uVar5 = uVar3 | uVar4 | uVar5;
            if (uVar5 != 0) {
              return uVar5;
            }
            *(int *)(param_1 + 0x198) = local_5c;
            uVar3 = (uint)local_62 << 0x10 | (uint)local_63 << 8 | (uint)local_64;
            if (uVar3 < 0xffff00) {
              iVar12 = 0;
              uVar4 = 0x80;
              uVar5 = 0x100;
              while( true ) {
                while( true ) {
                  uVar6 = uVar4;
                  iVar10 = uVar6 * 0x10000;
                  if (uVar3 < uVar6 * 0xffff) break;
                  uVar4 = uVar6;
                  if ((uVar3 < uVar6 * 0xffff + 0xffff) ||
                     (iVar10 = uVar5 * 0x10000, uVar4 = uVar5, uVar5 * 0xffff <= uVar3))
                  goto LAB_003117f6;
                  iVar12 = uVar6 + 1;
                  uVar4 = iVar12 + uVar5 >> 1;
                }
                if (uVar3 <= (uint)(iVar12 * 0xffff)) break;
                uVar4 = uVar6 + iVar12 >> 1;
                uVar5 = uVar6;
              }
              iVar10 = 0;
              uVar4 = 0;
            }
            else {
              iVar10 = 0x1000000;
              uVar4 = 0x100;
            }
LAB_003117f6:
            *(uint *)(param_1 + 0x1a4) = uVar4;
            *(uint *)(param_1 + 0x1a0) = uVar3;
            *(undefined4 *)(param_1 + 0x19c) = 0;
            *(uint *)(param_1 + 0x1b8) = (uVar3 - local_5c) - iVar10;
            uVar3 = 0;
            if (*(char *)(param_1 + 0x1c9) != '\0') {
              *(undefined1 *)(param_1 + 0x1c9) = 0;
              uVar3 = readregu008_extdeviceTargeted(lVar8,param_1,5,&local_61);
              if (uVar3 == 0) {
                local_61 = local_61 | 4;
                uVar3 = writeregu008_extdeviceTargeted(lVar8,param_1,5,local_61);
              }
            }
            if (*(char *)(param_1 + 0x1c8) != '\0') {
              iVar10 = tmrEventScheduleRel_IMPL
                                 (*(undefined8 *)(lVar8 + 0x1b88),
                                  *(undefined8 *)
                                   (param_1 + 0x1d0 + (ulong)*(uint *)(lVar8 + 0x7a4) * 8),
                                  1000000000);
              if (iVar10 == 0) {
                *(undefined1 *)(param_1 + 0x1c8) = 0;
                return uVar3;
              }
              return uVar3;
            }
            return uVar3;
          }
          timeoutSet(lVar8 + 0x1af0,local_50,*(int *)(param_1 + 0x1a8) * 1000,0);
          do {
            if ((local_60 < uVar4) && (uVar3 / 0x14 < local_60)) goto LAB_0031173c;
            iVar10 = timeoutCheck(lVar8 + 0x1af0,local_50,0x149c);
            if (iVar10 == 0x65) {
              if ((uVar3 * 7) / 10 <= local_60) {
                return 0x65;
              }
              if (local_60 <= uVar3 / 0x14) {
                return 0x65;
              }
              goto LAB_0031173c;
            }
            local_6c = (**(code **)(lVar2 + 0x1d8))
                                 (lVar8,lVar2,*(undefined4 *)(param_1 + 0x1c0),&local_60);
          } while (local_6c == 0);
          uVar11 = 0x14a2;
        }
        else {
          uVar11 = 0x1487;
        }
        nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",uVar11,
                     "gsyncUpdateFrameCount_P2060",4,"NVRM: Failed to read RG_DPCA.\n");
        return local_6c;
      }
      nvAssertFailedNoLog("head < kdispGetNumHeads(pKernelDisplay)",
                          "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x146d);
    }
  }
  return 0x26;
}


// ===== 00311b30 gsyncFrameCountTimerService_P2060 =====

undefined8 gsyncFrameCountTimerService_P2060(undefined8 param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = gsyncmgrGetGsync();
  if ((lVar1 != 0) && (*(long *)(lVar1 + 0x40) != 0)) {
    uVar2 = gsyncUpdateFrameCount_P2060(*(long *)(lVar1 + 0x40),param_1);
    return uVar2;
  }
  nvAssertFailedNoLog("(pGsync && pGsync->pExtDev)",
                      "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x13e2);
  return 0x26;
}


// ===== 00311b90 gsyncSetLsrMinTime.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

void gsyncSetLsrMinTime_isra_0(long param_1,long param_2,int param_3)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  ulong uVar5;
  byte bVar6;
  ulong uVar8;
  undefined4 local_40;
  undefined4 local_3c [3];
  ulong uVar7;
  
  iVar4 = readregu008_extdeviceTargeted(param_1,param_2,1,local_3c);
  if (iVar4 == 0) {
    bVar6 = (byte)local_3c[0] >> 6;
    uVar7 = (ulong)bVar6;
    if (param_3 == 0) {
      if (*(char *)(param_2 + 0x3b8 + uVar7 * 0xa4) != '\x01') {
        return;
      }
      lVar3 = *(long *)(param_1 + 0x1b80);
      if (lVar3 == 0) {
        nvAssertFailedNoLog("pKernelDisplay != NULL","generated/g_kern_disp_nvoc.h",0x4f9);
      }
      uVar2 = *(uint *)(lVar3 + 0x360);
      if (uVar2 != 0) {
        uVar8 = 0;
        do {
          uVar5 = uVar8 & 0xffffffff;
          lVar1 = uVar8 * 4;
          uVar8 = uVar8 + 1;
          (**(code **)(lVar3 + 0x1f0))
                    (param_1,lVar3,uVar5,
                     *(undefined4 *)((ulong)bVar6 * 0xa4 + param_2 + 0x398 + lVar1),
                     *(code **)(lVar3 + 0x1f0));
        } while (uVar2 != uVar8);
      }
      *(undefined1 *)(param_2 + 0x3b8 + uVar7 * 0xa4) = 0;
    }
    else {
      if (*(int *)(param_2 + 0x180) == 0) {
        *(undefined4 *)(param_2 + 0x180) = 0xfa;
        local_3c[0] = 0;
        iVar4 = osReadRegistryDword(param_1,"TSwapRdyHiLsrMinTime",local_3c);
        if (iVar4 == 0) {
          *(undefined4 *)(param_2 + 0x180) = local_3c[0];
        }
      }
      if (*(char *)(param_2 + 0x3b8 + uVar7 * 0xa4) != '\0') {
        return;
      }
      lVar3 = *(long *)(param_1 + 0x1b80);
      if (lVar3 == 0) {
        nvAssertFailedNoLog("pKernelDisplay != NULL","generated/g_kern_disp_nvoc.h",0x4f9);
      }
      uVar2 = *(uint *)(lVar3 + 0x360);
      if (uVar2 != 0) {
        uVar8 = 0;
        do {
          while (iVar4 = (**(code **)(lVar3 + 0x1f8))
                                   (param_1,lVar3,uVar8 & 0xffffffff,
                                    *(undefined4 *)(param_2 + 0x180),&local_40), iVar4 == 0) {
            (**(code **)(lVar3 + 0x200))(param_1,lVar3,uVar8 & 0xffffffff,local_3c,local_40);
            *(undefined4 *)(param_2 + (ulong)bVar6 * 0xa4 + 0x398 + uVar8 * 4) = local_3c[0];
            uVar8 = uVar8 + 1;
            if (uVar8 == uVar2) goto LAB_00311ce9;
          }
          uVar8 = uVar8 + 1;
          nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xcb9,
                       "gsyncSetLsrMinTime",4,
                       "NVRM: Error occured while computing LSR_MIN_TIME for Swap Barrier\n");
          nvAssertFailedNoLog(&DAT_00d0fb48,
                              "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xcbb)
          ;
        } while (uVar8 != uVar2);
      }
LAB_00311ce9:
      *(undefined1 *)(param_2 + 0x3b8 + uVar7 * 0xa4) = 1;
    }
  }
  return;
}


// ===== 00311e60 gsyncAttachExternalDevice_P2060 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gsyncAttachExternalDevice_P2060(long param_1,long *param_2)

{
  uint uVar1;
  undefined8 uVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  int *piVar6;
  long lVar7;
  long *plVar8;
  long *plVar9;
  ulong uVar10;
  long lVar11;
  long *plVar12;
  int iVar13;
  uint uVar14;
  uint local_6c;
  uint local_68;
  byte local_3a;
  byte local_39 [9];
  
  uVar14 = 0;
  iVar13 = 0;
  local_3a = 0;
  lVar7 = *(long *)(g_pSys + 0x1e8);
  local_39[0] = 0;
  uVar2 = *(undefined8 *)(param_1 + 0x1b88);
  uVar1 = *(uint *)(param_1 + 0x7a4);
  lVar11 = *param_2;
  do {
    iVar5 = readregu008_extdeviceTargeted(param_1,lVar11,iVar13 + 0x18U & 0xff,local_39);
    if (iVar5 != 0) {
      nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x219,
                   "gsyncAttachExternalDevice_P2060",4,"NVRM: failed to read P2060 device Id.\n");
      return 0;
    }
    cVar3 = (char)iVar13;
    iVar13 = iVar13 + 1;
    uVar14 = uVar14 | (uint)local_39[0] << (cVar3 * '\b' & 0x1fU);
  } while (iVar13 != 4);
  if (uVar14 != 0) {
    uVar10 = 0;
    piVar6 = (int *)(lVar7 + 0x54);
    do {
      if (((*piVar6 != 0) && (*(long *)(piVar6 + 0xf) != 0)) &&
         (*(uint *)(*(long *)(piVar6 + 0xf) + 0x16c) == uVar14)) {
        gpumgrGetGpuFromId(*(undefined4 *)(lVar7 + 0x5c + (uVar10 & 0xffffffff) * 0x178));
        lVar7 = gsyncmgrGetGsync();
        if ((lVar7 == 0) || (plVar12 = *(long **)(lVar7 + 0x40), plVar12 == (long *)0x0)) {
          nvAssertFailedNoLog(&DAT_00d0fb48,
                              "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x26a)
          ;
          return 0;
        }
        plVar9 = (long *)*param_2;
        if (plVar12 == plVar9) {
          nvAssertFailedNoLog("pGsync->pExtDev != *ppExtdevs",
                              "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x26e)
          ;
          plVar9 = (long *)*param_2;
          plVar12 = *(long **)(lVar7 + 0x40);
        }
        plVar8 = plVar12 + 0xba;
        iVar13 = 0xffff;
        uVar14 = 0;
        do {
          if ((int)*plVar8 == 0) {
            iVar13 = 0;
            local_68 = uVar14;
          }
          uVar14 = uVar14 + 1;
          plVar8 = (long *)((long)plVar8 + 0x14);
        } while (uVar14 != 4);
        if (iVar13 != 0) {
          nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x276,
                       "gsyncAttachExternalDevice_P2060",4,
                       "NVRM: Failed to free index for new GPU entry. \n");
          return 0;
        }
        uVar14 = 0;
        iVar13 = 0xffff;
        plVar8 = plVar9 + 0xba;
        do {
          if (*(int *)(param_1 + 0x7ac) == (int)*plVar8) {
            local_6c = uVar14;
            iVar13 = 0;
          }
          uVar14 = uVar14 + 1;
          plVar8 = (long *)((long)plVar8 + 0x14);
        } while (uVar14 != 4);
        if (iVar13 != 0) {
          nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x27d,
                       "gsyncAttachExternalDevice_P2060",4,
                       "NVRM: Couldn\'t find saved GPU entry, check extdevSaveI2cHandles. \n");
          return 0;
        }
        *(undefined4 *)((long)plVar12 + (ulong)local_68 * 0x14 + 0x5d0) =
             *(undefined4 *)((long)plVar9 + (ulong)local_6c * 0x14 + 0x5d0);
        *(undefined4 *)((long)plVar12 + (ulong)local_68 * 0x14 + 0x5c0) =
             *(undefined4 *)((long)plVar9 + (ulong)local_6c * 0x14 + 0x5c0);
        *(undefined4 *)((long)plVar12 + (ulong)local_68 * 0x14 + 0x5c4) =
             *(undefined4 *)((long)plVar9 + (ulong)local_6c * 0x14 + 0x5c4);
        *(undefined4 *)((long)plVar12 + (ulong)local_68 * 0x14 + 0x5c8) =
             *(undefined4 *)((long)plVar9 + (ulong)local_6c * 0x14 + 0x5c8);
        *(undefined4 *)((long)plVar12 + (ulong)local_68 * 0x14 + 0x5cc) =
             *(undefined4 *)((long)plVar9 + (ulong)local_6c * 0x14 + 0x5cc);
        (**(code **)(*plVar9 + 0x10))(param_1,*param_2);
        portMemFree(*param_2);
        lVar7 = *(long *)(lVar7 + 0x40);
        *param_2 = lVar7;
        goto LAB_00312037;
      }
      uVar10 = uVar10 + 1;
      piVar6 = piVar6 + 0x5e;
    } while (uVar10 != 4);
    if (*(char *)(param_1 + 0x4912) != '\0') {
      iVar13 = readregu008_extdeviceTargeted(param_1,*param_2,3,&local_3a);
      bVar4 = local_3a;
      if (iVar13 != 0) {
        nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x23f,
                     "gsyncAttachExternalDevice_P2060",4,"NVRM: Failed to read Ctrl data.\n");
        return 0;
      }
      iVar13 = readregu008_extdeviceTargeted(param_1,*param_2,1,local_39);
      if (iVar13 != 0) {
        nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x249,
                     "gsyncAttachExternalDevice_P2060",4,
                     "NVRM: Failed to get connector index for Gpu.\n");
        return 0;
      }
      if (((bVar4 & 1) != 0) && ((local_3a >> 4 & 3) != local_39[0] >> 6)) {
        lVar7 = *param_2;
        goto LAB_00312037;
      }
    }
    iVar13 = 0;
    uVar14 = 0;
    writeregu008_extdeviceTargeted(param_1,*param_2,4,0x10);
    osDelay(5);
    lVar7 = *param_2;
    local_39[0] = 0;
    do {
      cVar3 = (char)iVar13;
      iVar5 = readregu008_extdeviceTargeted(param_1,lVar7,cVar3 + '\x18',local_39);
      if (iVar5 != 0) goto LAB_00311fae;
      iVar13 = iVar13 + 1;
      uVar14 = uVar14 | (uint)local_39[0] << (cVar3 * '\b' & 0x1fU);
    } while (iVar13 != 4);
    if (uVar14 != 0) {
LAB_00311fae:
      nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x25d,
                   "gsyncAttachExternalDevice_P2060",4,
                   "NVRM: failed to read P2060 device Id after reset.\n");
      return 0;
    }
  }
  lVar7 = *param_2;
  uVar14 = *(uint *)(param_1 + 0x7ac);
  iVar13 = 0;
  lVar11 = lVar7;
  while( true ) {
    iVar5 = writeregu008_extdeviceTargeted
                      (param_1,lVar11,iVar13 + 0x18U & 0xff,
                       uVar14 >> ((char)iVar13 * '\b' & 0x1fU) & 0xff);
    if (iVar5 != 0) {
      nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x29f,
                   "gsyncAttachExternalDevice_P2060",4,"NVRM: failed to update P2060 device Id.\n");
      return 0;
    }
    iVar13 = iVar13 + 1;
    if (iVar13 == 4) break;
    lVar11 = *param_2;
  }
  *(uint *)(lVar7 + 0x16c) = uVar14;
LAB_00312037:
  iVar13 = readregu008_extdeviceTargeted(param_1,lVar7,1,local_39);
  bVar4 = local_39[0];
  if (iVar13 != 0) {
    nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x2a9,
                 "gsyncAttachExternalDevice_P2060",4,"NVRM: failed to find P2060 connector.\n");
    return 0;
  }
  lVar11 = (ulong)uVar1 * 8 + 0x30;
  iVar13 = tmrEventCreate_IMPL(uVar2,lVar7 + lVar11,extdevServiceWatchdog,lVar7,0);
  if (iVar13 == 0) {
    iVar13 = tmrEventCreate_IMPL(uVar2,lVar7 + 0x1a0 + lVar11,gsyncFrameCountTimerService_P2060,
                                 lVar7,0);
    if (iVar13 == 0) {
      bVar4 = bVar4 >> 6;
      *(int *)(*param_2 + 8) = *(int *)(*param_2 + 8) + 1;
      *(uint *)(lVar7 + 0x168) =
           *(uint *)(lVar7 + 0x168) | 1 << ((byte)*(undefined4 *)(param_1 + 0x7a4) & 0x1f);
      *(undefined4 *)(lVar7 + 0x390 + (ulong)bVar4 * 0xa4) = *(undefined4 *)(param_1 + 0x7ac);
      *(undefined1 *)(lVar7 + 0x394 + (ulong)bVar4 * 0xa4) = 1;
      iVar13 = gsyncAttachGpu(*param_2,param_1,bVar4 + 1,0,*(undefined4 *)(*param_2 + 0x1c));
      if (iVar13 == 0) {
        if (*(int *)(lVar7 + 0x1c) == 0x2061) {
          *(undefined1 *)(param_1 + 0x4ad) = 1;
        }
        else {
          if (*(int *)(lVar7 + 0x1c) != 0x2060) {
            nvAssertFailedNoLog("pThis->ExternalDevice.deviceId == DAC_EXTERNAL_DEVICE_P2060",
                                "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",
                                0x2ee);
          }
          *(undefined1 *)(param_1 + 0x4ac) = 1;
        }
        if (*(char *)(lVar7 + 0x174) != '\0') {
          return 1;
        }
        lVar11 = *param_2;
        local_39[0] = 0;
        readregu008_extdeviceTargeted(param_1,lVar11,5,local_39);
        local_39[0] = local_39[0] | 0x28;
        iVar13 = writeregu008_extdeviceTargeted(param_1,lVar11,5,local_39[0]);
        if (iVar13 == 0) {
          *(undefined1 *)(lVar7 + 0x174) = 1;
          *(uint *)(lVar7 + 0x178) = (uint)bVar4;
          return 1;
        }
        nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x2f7,
                     "gsyncAttachExternalDevice_P2060",4,
                     "NVRM: Failed to enable non-framelock interrupts on gsync GPU.\n");
      }
      else {
        nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x2e4,
                     "gsyncAttachExternalDevice_P2060",4,
                     "NVRM: failed to attach P2060 gsync to gpu.\n");
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x2cd,
                   "gsyncAttachExternalDevice_P2060",4,
                   "NVRM: failed to create P2060 frame count timer event.\n");
    }
    lVar7 = lVar7 + (ulong)uVar1 * 8;
    tmrEventDestroy_IMPL(uVar2,*(undefined8 *)(lVar7 + 0x1d0));
    *(undefined8 *)(lVar7 + 0x1d0) = 0;
    tmrEventDestroy_IMPL(uVar2,*(undefined8 *)(lVar7 + 0x30));
    *(undefined8 *)(lVar7 + 0x30) = 0;
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x2c2,
               "gsyncAttachExternalDevice_P2060",4,
               "NVRM: failed to create P2060 watchdog timer event.\n");
  return 0;
}


// ===== 00312600 gsyncProgramSlaves_P2060.isra.0 =====

int gsyncProgramSlaves_P2060_isra_0
              (long param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  long lVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  ulong uVar10;
  byte bVar11;
  uint *puVar12;
  long lVar13;
  bool bVar14;
  byte local_5b;
  byte local_5a;
  byte local_59;
  uint local_58 [10];
  
  lVar13 = *(long *)(param_1 + 0x1b80);
  local_5b = 0;
  local_5a = 0;
  if (lVar13 == 0) {
    nvAssertFailedNoLog("pKernelDisplay != NULL","generated/g_kern_disp_nvoc.h",0x4f9);
  }
  uVar1 = *(uint *)(lVar13 + 0x360);
  uVar9 = 0;
  extdevGetBoundHeadsAndDisplayIds(param_1,local_58);
  piVar5 = (int *)(param_2 + 0x390);
  while (*piVar5 != *(int *)(param_1 + 0x7ac)) {
    uVar9 = uVar9 + 1;
    piVar5 = piVar5 + 0x29;
    if (uVar9 == 4) {
      nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xac1,
                   "gsyncProgramSlaves_P2060",4,
                   "NVRM: Failed to get Gpu location. Can not program Slave.\n");
      return 0xffff;
    }
  }
  iVar4 = readregu008_extdeviceTargeted(param_1,param_2,3,&local_5b);
  bVar2 = local_5b;
  if (iVar4 != 0) {
    nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xaca,
                 "gsyncProgramSlaves_P2060",4,
                 "NVRM: Failed to read ctrl register. Can not program slave.\n");
    return iVar4;
  }
  bVar14 = param_3 != 0;
  uVar10 = CONCAT71((int7)((ulong)param_5 >> 8),bVar14);
  bVar11 = bVar14 & local_5b >> 7;
  if (bVar11 == 0) {
    uVar8 = local_5b & 1 ^ 1;
    bVar11 = (byte)uVar8;
    if ((bVar14) && (bVar11 != 0)) goto LAB_003126fb;
    if (((local_5b & (byte)~local_5b >> 7) != 0) && (bVar14)) goto LAB_003127a5;
    uVar8 = uVar8 | local_5b >> 7;
    if (param_3 != 0) goto LAB_0031280a;
    if (uVar1 != 0) goto LAB_00312873;
LAB_003129f5:
    cVar3 = gsyncIsFrameLocked_P2060(param_2);
    if (cVar3 == '\0') {
      gsyncDisableFrameLockInterrupt_P2060(param_2);
      uVar1 = *(uint *)(param_2 + 0x1bc);
    }
    else {
      uVar1 = *(uint *)(param_2 + 0x1bc);
    }
    if (uVar9 != uVar1) {
      return 0;
    }
  }
  else {
    if ((char)(local_5b & 1) == '\0') {
LAB_003126fb:
      iVar4 = readregu008_extdeviceTargeted(param_1,param_2,1,&local_59);
      if (iVar4 != 0) {
        nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xafc,
                     "gsyncProgramSlaves_P2060",4,
                     "NVRM: Failed to get connector index for Gpu. Can not program slave.\n");
        return iVar4;
      }
      bVar11 = local_5b & 0xcf;
      bVar7 = (local_59 >> 6) << 4;
      local_5b = bVar11 | bVar7;
      iVar4 = writeregu008_extdeviceTargeted(param_1,param_2,3,bVar11 | bVar7);
      uVar10 = (ulong)bVar14;
      if (iVar4 != 0) {
        nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xb07,
                     "gsyncProgramSlaves_P2060",4,
                     "NVRM: Failed to write SYNC_SRC. Can not program slave.\n");
        return iVar4;
      }
      bVar11 = (byte)~bVar2 >> 7 & bVar2;
      if (bVar11 != 0) {
LAB_003127a5:
        bVar14 = SUB81(uVar10,0);
        iVar4 = readregu008_extdeviceTargeted(param_1,param_2,5,&local_5a);
        if (iVar4 != 0) {
          nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xb17,
                       "gsyncProgramSlaves_P2060",4,
                       "NVRM: Failed to read ctrl3 register. Can not program slave.\n");
          return iVar4;
        }
        goto LAB_003127d7;
      }
      uVar8 = 1;
    }
    else {
      iVar4 = readregu008_extdeviceTargeted(param_1,param_2,5,&local_5a);
      if (iVar4 != 0) {
        nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xae4,
                     "gsyncProgramSlaves_P2060",4,
                     "NVRM: Failed to read ctrl3 register. Can not program slave.\n");
        return iVar4;
      }
LAB_003127d7:
      local_5a = local_5a | 0x80;
      writeregu008_extdeviceTargeted(param_1,param_2,5,local_5a);
      uVar10 = (ulong)bVar14;
      uVar8 = (uint)bVar11;
    }
LAB_0031280a:
    if (uVar1 != 0) {
      lVar13 = (ulong)uVar9 * 0xa4 + param_2;
      do {
        *(undefined4 *)(lVar13 + 0x350) = 0;
        lVar6 = lVar13 + 4;
        *(undefined4 *)(lVar13 + 0x370) = 0;
        lVar13 = lVar6;
      } while (lVar6 != param_2 + ((ulong)uVar9 * 0x29 + (ulong)uVar1) * 4);
LAB_00312873:
      puVar12 = (uint *)(param_2 + 0x350 + (ulong)uVar9 * 0xa4);
      lVar13 = 0;
      do {
        if (((local_58[lVar13] & param_3) != 0) || (param_3 == 0)) {
          *puVar12 = (uint)(byte)((byte)uVar10 & (byte)uVar8);
          puVar12[8] = (uVar8 ^ 1) & (uint)uVar10;
          gsyncProgramFramelockEnable_P2060(param_1,param_2,uVar9,uVar10 & 0xff);
        }
        lVar13 = lVar13 + 1;
        puVar12 = puVar12 + 1;
      } while ((uint)lVar13 < uVar1);
      if (param_3 == 0) goto LAB_003129f5;
    }
    if (*(uint *)(param_2 + 0x1bc) != uVar9) {
      return 0;
    }
    if ((local_58[*(uint *)(param_2 + 0x1c0)] & param_3) != 0) {
      return 0;
    }
  }
  if (*(int *)(param_2 + 0x390 + (ulong)uVar9 * 0xa4) == -1) {
    return 0;
  }
  iVar4 = gsyncResetFrameCountData_P2060(param_1,param_2);
  return iVar4;
}


// ===== 00312b00 extdevConstruct_P2060 =====

long * extdevConstruct_P2060(long param_1,long *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  long lVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  
  lVar3 = *(long *)(param_1 + 0x1b80);
  if (lVar3 == 0) {
    nvAssertFailedNoLog("pKernelDisplay != NULL","generated/g_kern_disp_nvoc.h",0x4f9);
  }
  uVar1 = *(uint *)(lVar3 + 0x360);
  lVar3 = extdevConstruct_Base(param_1,param_2);
  plVar7 = (long *)0x0;
  if (lVar3 != 0) {
    *(code **)(*param_2 + 0x10) = extdevDestroy_P2060;
    *(code **)(*param_2 + 0x18) = gsyncAttachExternalDevice_P2060;
    *(code **)*param_2 = extdevGetDevice_P2060;
    *(code **)(*param_2 + 8) = extdevInit_P2060;
    *(code **)(*param_2 + 0x38) = extdevService_P2060;
    *(code **)(*param_2 + 0x40) = extdevWatchdog_P2060;
    *(code **)(*param_2 + 0x48) = extdevSaveI2cHandles_P2060;
    *(undefined1 *)((long)param_2 + 0xc) = 0x20;
    uVar2 = *(undefined4 *)(param_1 + 0x7f0);
    *(undefined4 *)((long)param_2 + 0x14) = 4;
    *(undefined4 *)(param_2 + 2) = uVar2;
    param_2[0x37] = 0x400000000;
    param_2[0x2d] = 0;
    *(undefined4 *)(param_2 + 0x2e) = 0;
    *(undefined1 *)((long)param_2 + 0x174) = 0;
    param_2[0x2f] = 0;
    *(undefined4 *)(param_2 + 0x30) = 0;
    param_2[0x33] = 0;
    param_2[0x34] = 0;
    param_2[0x36] = 0;
    param_2[0x38] = 4;
    *(undefined1 *)((long)param_2 + 0x1ca) = 0;
    *(undefined2 *)(param_2 + 0x39) = 0;
    plVar7 = (long *)((long)param_2 + (ulong)uVar1 * 4);
    plVar5 = param_2;
    plVar8 = param_2 + 0xb8;
    do {
      *(undefined4 *)(plVar5 + 0x72) = 0xffffffff;
      *(undefined1 *)((long)plVar5 + 0x394) = 0;
      *(undefined1 *)((long)plVar5 + 0x3c4) = 0;
      *(undefined1 *)(plVar5 + 0x77) = 0;
      plVar6 = plVar5;
      if (uVar1 != 0) {
        do {
          *(undefined4 *)(plVar6 + 0x66) = 0;
          plVar4 = (long *)((long)plVar6 + 4);
          *(undefined4 *)(plVar6 + 0x6a) = 0;
          *(undefined4 *)(plVar6 + 0x6e) = 0;
          plVar6 = plVar4;
        } while (plVar7 != plVar4);
      }
      *(undefined4 *)((long)plVar5 + 0x3cc) = 0;
      plVar6 = (long *)((long)plVar5 + 0xa4);
      plVar7 = (long *)((long)plVar7 + 0xa4);
      *(undefined4 *)(plVar5 + 0x7a) = 0;
      *(undefined4 *)plVar8 = 0;
      *(undefined4 *)((long)plVar8 + 4) = 0;
      *(undefined4 *)(plVar8 + 1) = 0;
      *(undefined4 *)((long)plVar8 + 0xc) = 0;
      *(undefined4 *)(plVar8 + 2) = 0;
      plVar5 = plVar6;
      plVar8 = (long *)((long)plVar8 + 0x14);
    } while (plVar6 != param_2 + 0x52);
    param_2[0xc2] = -1;
    param_2[0xc3] = -1;
    *(undefined4 *)(param_2 + 0xc4) = 0;
    *(undefined1 *)((long)param_2 + 0x624) = 0;
    param_2[0xc5] = -1;
    param_2[0xc6] = -1;
    *(undefined4 *)(param_2 + 199) = 0;
    *(undefined1 *)((long)param_2 + 0x63c) = 0;
    plVar7 = param_2;
  }
  return plVar7;
}


// ===== 00312d80 i2c_extdeviceHelper =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4
i2c_extdeviceHelper(long param_1,long param_2,undefined1 param_3,undefined1 param_4,
                   undefined1 *param_5,char param_6)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  long lVar4;
  undefined1 *puVar5;
  int iVar6;
  int *piVar7;
  ulong unaff_R15;
  
  lVar4 = rmapiGetInterface(4);
  puVar5 = (undefined1 *)portMemAllocNonPaged(0x60);
  if (puVar5 == (undefined1 *)0x0) {
    return 0x51;
  }
  piVar7 = (int *)(param_2 + 0x5d0);
  iVar6 = 0xffff;
  uVar2 = 0;
  do {
    unaff_R15 = unaff_R15 & 0xffffffff;
    if (*(int *)(param_1 + 0x7ac) == *piVar7) {
      unaff_R15 = (ulong)uVar2;
      iVar6 = 0;
    }
    uVar2 = uVar2 + 1;
    piVar7 = piVar7 + 5;
  } while (uVar2 != 4);
  if (iVar6 != 0) {
    nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x189,
                 "i2c_extdeviceHelper",4,
                 "NVRM: Couldn\'t find saved GPU entry, check saved i2chandles. \n");
    return 0xffff;
  }
  portMemSet(puVar5,0,0x60);
  *(undefined4 *)(puVar5 + 0xc) = 4;
  *puVar5 = param_3;
  bVar1 = *(byte *)(param_2 + 0xc);
  puVar5[0x10] = param_6;
  *(ushort *)(puVar5 + 8) = (ushort)bVar1;
  puVar5[0x11] = param_4;
  if (param_6 == '\0') {
    uVar3 = (**(code **)(lVar4 + 0x38))
                      (lVar4,*(undefined4 *)(param_2 + 0x5c0 + unaff_R15 * 0x14),
                       *(undefined4 *)(param_2 + 0x5cc + unaff_R15 * 0x14),0x402c0105,puVar5,0x60);
    *param_5 = puVar5[0x12];
  }
  else {
    puVar5[0x12] = *param_5;
    uVar3 = (**(code **)(lVar4 + 0x38))
                      (lVar4,*(undefined4 *)(param_2 + 0x5c0 + unaff_R15 * 0x14),
                       *(undefined4 *)(param_2 + 0x5cc + unaff_R15 * 0x14),0x402c0105,puVar5,0x60);
  }
  portMemFree(puVar5);
  return uVar3;
}


// ===== 00312f50 gsyncOptimizeTimingParameters_P2060 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int gsyncOptimizeTimingParameters_P2060(long param_1,undefined8 *param_2)

{
  int iVar1;
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
  
  local_78 = *param_2;
  local_70 = param_2[1];
  local_68 = param_2[2];
  local_60 = param_2[3];
  local_58 = param_2[4];
  local_50 = param_2[5];
  local_48 = param_2[6];
  local_40 = param_2[7];
  local_38 = param_2[8];
  local_30 = param_2[9];
  local_28 = param_2[10];
  local_20 = param_2[0xb];
  iVar1 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800abf,&local_78,0x60);
  if (iVar1 == 0) {
    *param_2 = local_78;
    param_2[1] = local_70;
    param_2[2] = local_68;
    param_2[3] = local_60;
    param_2[4] = local_58;
    param_2[5] = local_50;
    param_2[6] = local_48;
    param_2[7] = local_40;
    param_2[8] = local_38;
    param_2[9] = local_30;
    param_2[10] = local_28;
    param_2[0xb] = local_20;
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x5e4,
               "gsyncOptimizeTimingParameters_P2060",4,
               "NVRM: OptimizeTimingParameters control call has failed! \n");
  return iVar1;
}


// ===== 00313090 gsyncSetStereoLockMode_P2060 =====

void gsyncSetStereoLockMode_P2060(undefined8 param_1,undefined8 param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  byte local_29 [9];
  
  iVar2 = readregu008_extdeviceTargeted(param_1,param_2,6,local_29);
  if (iVar2 == 0) {
    bVar1 = local_29[0] | 8;
    local_29[0] = local_29[0] & 0xf7;
    if (param_3 != 0) {
      local_29[0] = bVar1;
    }
    writeregu008_extdeviceTargeted(param_1,param_2,6,local_29[0]);
  }
  return;
}


// ===== 003130f0 gsyncGetStereoLockMode_P2060 =====

void gsyncGetStereoLockMode_P2060(undefined8 param_1,undefined8 param_2,uint *param_3)

{
  int iVar1;
  byte local_19 [9];
  
  iVar1 = readregu008_extdeviceTargeted(param_1,param_2,6,local_19);
  if (iVar1 == 0) {
    *param_3 = local_19[0] >> 3 & 1;
  }
  return;
}


// ===== 00313130 gsyncSetVideoMode_P2060 =====

undefined8 gsyncSetVideoMode_P2060(void)

{
  return 0;
}


// ===== 00313140 gsyncGetVideoMode_P2060 =====

undefined8 gsyncGetVideoMode_P2060(long param_1,long param_2,uint *param_3)

{
  undefined8 uVar1;
  byte bVar2;
  uint uVar3;
  byte local_19;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog(&DAT_00d0f8e6,
                        "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x656);
    return 0xffff;
  }
  uVar1 = readregu008_extdeviceTargeted(param_1,param_2,1,&local_19);
  if ((int)uVar1 == 0) {
    bVar2 = local_19 >> 4 & 3;
    if (bVar2 != 2) {
      *param_3 = (uint)bVar2;
      *(uint *)(param_2 + 0x134) = (uint)bVar2;
      return uVar1;
    }
    *param_3 = 4;
    uVar3 = 4;
  }
  else {
    uVar3 = *param_3;
  }
  *(uint *)(param_2 + 0x134) = uVar3;
  return uVar1;
}


// ===== 003131f0 gsyncGetEmitTestSignal_P2060 =====

int gsyncGetEmitTestSignal_P2060(undefined8 param_1,long param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  byte local_19;
  
  iVar1 = readregu008_extdeviceTargeted(param_1,param_2,3,&local_19);
  if (iVar1 == 0) {
    uVar2 = local_19 >> 3 & 1;
    *param_3 = uVar2;
  }
  else {
    uVar2 = *param_3;
  }
  *(uint *)(param_2 + 0x158) = uVar2;
  return iVar1;
}


// ===== 00313240 gsyncGetUseHouse_P2060 =====

int gsyncGetUseHouse_P2060(undefined8 param_1,long param_2,uint *param_3)

{
  int iVar1;
  byte local_19;
  
  iVar1 = readregu008_extdeviceTargeted(param_1,param_2,3,&local_19);
  if (iVar1 == 0) {
    *param_3 = (uint)(local_19 >> 7);
    *(uint *)(param_2 + 0x14c) = (uint)(local_19 >> 7);
  }
  return iVar1;
}


// ===== 00313290 gsyncGetSyncPolarity_P2060 =====

int gsyncGetSyncPolarity_P2060(undefined8 param_1,long param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  byte local_19;
  
  iVar1 = readregu008_extdeviceTargeted(param_1,param_2,3,&local_19);
  if (iVar1 == 0) {
    uVar2 = local_19 >> 1 & 3;
    *param_3 = uVar2;
  }
  else {
    uVar2 = *param_3;
  }
  *(uint *)(param_2 + 0x138) = uVar2;
  return iVar1;
}


// ===== 003132e0 gsyncSetNSync_P2060 =====

void gsyncSetNSync_P2060(undefined8 param_1,long param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  byte local_29 [9];
  
  *(uint *)(param_2 + 0x144) = param_3;
  iVar1 = readregu008_extdeviceTargeted(param_1,param_2,0xc,local_29);
  if (iVar1 != 0) {
    return;
  }
  uVar2 = local_29[0] & 0xfffffff8 | param_3 & 7;
  local_29[0] = (byte)uVar2;
  writeregu008_extdeviceTargeted(param_1,param_2,0xc,uVar2);
  return;
}


// ===== 00313350 gsyncGetNSync_P2060 =====

int gsyncGetNSync_P2060(undefined8 param_1,long param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  byte local_19;
  
  iVar1 = readregu008_extdeviceTargeted(param_1,param_2,0xc,&local_19);
  if (iVar1 == 0) {
    uVar2 = local_19 & 7;
    *param_3 = uVar2;
  }
  else {
    uVar2 = *param_3;
  }
  *(uint *)(param_2 + 0x144) = uVar2;
  return iVar1;
}


// ===== 003133a0 gsyncSetSyncSkew_P2060 =====

uint gsyncSetSyncSkew_P2060(undefined8 param_1,long param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  
  *(uint *)(param_2 + 0x140) = param_3;
  if (*(int *)(param_2 + 0x1c) != 0x2061) {
    if (*(int *)(param_2 + 0x1c) != 0x2060) {
      nvAssertFailedNoLog("pExtdev->deviceId == DAC_EXTERNAL_DEVICE_P2060",
                          "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x152a);
    }
    if (*(uint *)(param_2 + 0x20) < 3) {
      if (1 < param_3) {
        return 0x56;
      }
      uVar3 = 0;
      goto LAB_00313404;
    }
  }
  uVar3 = (undefined1)(param_3 >> 8);
LAB_00313404:
  uVar1 = writeregu008_extdeviceTargeted(param_1,param_2,8,(char)param_3);
  uVar2 = writeregu008_extdeviceTargeted(param_1,param_2,9,uVar3);
  return uVar2 | uVar1;
}


// ===== 00313470 gsyncGetSyncSkew_P2060 =====

void gsyncGetSyncSkew_P2060(undefined8 param_1,long param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined2 local_2a;
  
  iVar1 = readregu008_extdeviceTargeted(param_1,param_2,8,&local_2a);
  iVar2 = readregu008_extdeviceTargeted(param_1,param_2,9,(long)&local_2a + 1);
  if (iVar2 == 0 && iVar1 == 0) {
    uVar3 = (uint)local_2a;
    *param_3 = uVar3;
  }
  else {
    uVar3 = *param_3;
  }
  *(uint *)(param_2 + 0x140) = uVar3;
  return;
}


// ===== 003134f0 gsyncSetSyncStartDelay_P2060 =====

uint gsyncSetSyncStartDelay_P2060(undefined8 param_1,long param_2,ulong param_3)

{
  uint uVar1;
  uint uVar2;
  
  *(int *)(param_2 + 0x13c) = (int)param_3;
  uVar1 = writeregu008_extdeviceTargeted(param_1,param_2,10,param_3 & 0xff);
  uVar2 = writeregu008_extdeviceTargeted(param_1,param_2,0xb,(param_3 & 0xffffffff) >> 8 & 0xff);
  return uVar2 | uVar1;
}


// ===== 00313540 gsyncGetSyncStartDelay_P2060 =====

void gsyncGetSyncStartDelay_P2060(undefined8 param_1,long param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined2 local_2a;
  
  iVar1 = readregu008_extdeviceTargeted(param_1,param_2,10,&local_2a);
  iVar2 = readregu008_extdeviceTargeted(param_1,param_2,0xb,(long)&local_2a + 1);
  if (iVar2 == 0 && iVar1 == 0) {
    uVar3 = (uint)local_2a;
    *param_3 = uVar3;
  }
  else {
    uVar3 = *param_3;
  }
  *(uint *)(param_2 + 0x13c) = uVar3;
  return;
}


// ===== 003135c0 gsyncSetMosaic_P2060 =====

undefined8 gsyncSetMosaic_P2060(undefined8 param_1,long param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  byte bVar5;
  undefined1 uVar6;
  long lVar7;
  char *pcVar8;
  long lVar9;
  ulong uVar10;
  byte local_39 [9];
  
  uVar1 = *(uint *)(param_3 + 0x18);
  if (1 < uVar1) {
    nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xce8,
                 "gsyncSetMosaic_P2060",4,
                 "NVRM: mosaicGroup equaling/extending NV_P2060_MAX_MOSAIC_GROUPS.\n");
    return 0x1f;
  }
  if (3 < *(uint *)(param_3 + 0x14)) {
    nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xcef,
                 "gsyncSetMosaic_P2060",4,
                 "NVRM: mosaic slaveGpuCount extending NV_P2060_MAX_MOSAIC_SLAVES.\n");
    return 0x1f;
  }
  uVar10 = (ulong)uVar1;
  lVar7 = param_2 + uVar10 * 0x18;
  if (*(char *)(param_3 + 0x1c) == '\0') {
    if (*(char *)(lVar7 + 0x624) == '\0') {
      pcVar8 = "NVRM: trying to disable mosaicGroup which is not enabled.\n";
      uVar4 = 0xd3c;
LAB_00313840:
      nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",uVar4,
                   "gsyncSetMosaic_P2060",4,pcVar8);
      return 0x1f;
    }
    uVar6 = 0;
    if (*(int *)(lVar7 + 0x620) != 0) {
      lVar9 = 0;
      do {
        lVar3 = gpumgrGetGpuFromId(*(undefined4 *)
                                    ((ulong)(-uVar1 & 0x18) + param_2 + 0x614 + lVar9 * 4));
        if (lVar3 == 0) {
          nvAssertFailedNoLog("pTempGpu",
                              "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xd44)
          ;
          return 0xffff;
        }
        iVar2 = writeregu008_extdeviceTargeted(lVar3,param_2,0x23,0);
        if (iVar2 != 0) {
          nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xd4a,
                       "gsyncSetMosaic_P2060",4,
                       "NVRM: Failed to write P2060 mosaic slave register.\n");
          return 0xffff;
        }
        lVar9 = lVar9 + 1;
        gsyncSetLsrMinTime_isra_0(lVar3,param_2,*(undefined1 *)(param_3 + 0x1c));
      } while ((uint)lVar9 < *(uint *)(lVar7 + 0x620));
      uVar6 = *(undefined1 *)(param_3 + 0x1c);
    }
    gsyncSetLsrMinTime_isra_0(param_1,param_2,uVar6);
    uVar4 = writeregu008_extdeviceTargeted(param_1,param_2,0x23,0);
    if ((int)uVar4 == 0) {
      lVar7 = uVar10 * 0x18;
      *(undefined8 *)(param_2 + 0x610 + lVar7) = 0xffffffffffffffff;
      *(undefined8 *)(param_2 + 0x618 + lVar7) = 0xffffffffffffffff;
      *(undefined4 *)(param_2 + 0x620 + lVar7) = 0;
      *(undefined1 *)(param_2 + 0x624 + lVar7) = 0;
      return uVar4;
    }
    nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xd59,
                 "gsyncSetMosaic_P2060",4,"NVRM: Failed to write P2060 mosaic Source register.\n");
  }
  else {
    if (*(char *)(lVar7 + 0x624) != '\0') {
      pcVar8 = "NVRM: trying to enable mosaicGroup which is already enabled.\n";
      uVar4 = 0xcfb;
      goto LAB_00313840;
    }
    iVar2 = readregu008_extdeviceTargeted(param_1,param_2,1,local_39);
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_3 + 0x14);
      bVar5 = local_39[0] >> 6;
      *(int *)(lVar7 + 0x620) = iVar2;
      *(undefined4 *)(lVar7 + 0x610) = *(undefined4 *)(param_2 + 0x390 + (ulong)bVar5 * 0xa4);
      if (iVar2 != 0) {
        lVar7 = 0;
        do {
          *(undefined4 *)((ulong)(-uVar1 & 0x18) + param_2 + 0x614 + lVar7 * 4) =
               *(undefined4 *)(param_3 + 4 + lVar7 * 4);
          lVar9 = gpumgrGetGpuFromId();
          if (lVar9 == 0) {
            nvAssertFailedNoLog("pTempGpu",
                                "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",
                                0xd0e);
            return 0xffff;
          }
          iVar2 = writeregu008_extdeviceTargeted
                            (lVar9,param_2,0x23,uVar1 * 4 & 0xff | (uint)bVar5 | 8);
          if (iVar2 != 0) {
            nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xd1a,
                         "gsyncSetMosaic_P2060",4,
                         "NVRM: Failed to write P2060 mosaic slave register.\n");
            return 0xffff;
          }
          lVar7 = lVar7 + 1;
          gsyncSetLsrMinTime_isra_0(lVar9,param_2,*(undefined1 *)(param_3 + 0x1c));
        } while ((uint)lVar7 < *(uint *)(param_2 + 0x620 + uVar10 * 0x18));
      }
      gsyncSetLsrMinTime_isra_0(param_1,param_2,*(undefined1 *)(param_3 + 0x1c));
      uVar4 = writeregu008_extdeviceTargeted(param_1,param_2,0x23,(char)uVar1 * '\x04' | bVar5 | 8);
      if ((int)uVar4 == 0) {
        *(undefined1 *)(param_2 + 0x624 + uVar10 * 0x18) = 1;
        return uVar4;
      }
      nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xd2f,
                   "gsyncSetMosaic_P2060",4,"NVRM: Failed to write P2060 mosaic Source register.\n")
      ;
    }
  }
  return 0xffff;
}


// ===== 00313a50 gsyncRefSignal_P2060 =====

undefined8
gsyncRefSignal_P2060
          (undefined8 param_1,undefined8 param_2,int param_3,uint param_4,char param_5,
          undefined4 *param_6)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 local_40;
  uint local_3c [3];
  
  local_3c[0] = 0;
  if (param_5 == '\0') {
    return 0;
  }
  iVar1 = gsyncReadMaster_P2060();
  if (param_3 == 0) {
    return 0;
  }
  if (param_3 == 1) {
    if (param_4 < 2) {
      uVar2 = gsyncReadFrameRate_P2060(param_1,param_2,&local_40);
      if ((int)uVar2 != 0) {
        return uVar2;
      }
      uVar2 = readregu008_extdeviceTargeted(param_1,param_2,1,local_3c);
      if ((int)uVar2 != 0) {
        return uVar2;
      }
      if (((uint)(param_4 != 0) != (local_3c[0] & 1)) ||
         ((uint)(param_4 == 0) != (local_3c[0] >> 1 & 1))) {
LAB_00313b20:
        *param_6 = 0;
        return uVar2;
      }
      if (iVar1 != 0) {
LAB_00313b90:
        *param_6 = 0xffffffff;
        return 0;
      }
    }
    else {
      if (param_4 != 2) goto LAB_00313b00;
      uVar2 = gsyncReadHouseSignalPresent_P2060(param_1,param_2,0,local_3c);
      if ((local_3c[0] == 0) || ((int)uVar2 != 0)) goto LAB_00313b20;
      uVar2 = gsyncReadHouseSyncFrameRate_P2060(param_1,param_2,&local_40);
      if ((int)uVar2 != 0) {
        return uVar2;
      }
      if (iVar1 == 0) goto LAB_00313b90;
    }
    *param_6 = local_40;
  }
  else {
LAB_00313b00:
    uVar2 = 0xffff;
  }
  return uVar2;
}


// ===== 00313bc0 gsyncRefSlaves_P2060 =====

undefined8
gsyncRefSlaves_P2060
          (undefined8 param_1,long param_2,uint param_3,undefined4 *param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  long lVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  
  lVar2 = *(long *)(param_2 + 0x40);
  if (param_3 == 2) {
    *(undefined4 *)(lVar2 + 0x154) = *param_4;
    *(undefined4 *)(lVar2 + 0x160) = *param_5;
    uVar4 = gsyncProgramSlaves_P2060_isra_0(param_1,*(undefined8 *)(param_2 + 0x40));
    return uVar4;
  }
  if (1 < param_3) {
    return 0;
  }
  uVar1 = *(undefined4 *)(lVar2 + 0x160);
  uVar3 = gsyncReadSlaves_P2060();
  if (param_3 == 1) {
    *(undefined4 *)(lVar2 + 0x154) = uVar3;
  }
  *param_4 = uVar3;
  *param_5 = uVar1;
  return 0;
}


// ===== 00313c50 gsyncGetCplStatus_P2060 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong gsyncGetCplStatus_P2060(long param_1,long param_2,uint param_3,uint *param_4)

{
  int iVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ulong uVar9;
  long lVar10;
  long lVar11;
  undefined8 uVar12;
  int *piVar13;
  int *piVar14;
  int iVar15;
  long lVar16;
  bool bVar17;
  byte local_31;
  uint local_30;
  uint local_2c;
  
  *param_4 = 0;
  if (param_3 == 6) {
    uVar9 = gsyncReadHouseSignalPresent_P2060(param_1,param_2,0);
    return uVar9;
  }
  if (param_3 < 7) {
    if (param_3 == 3) {
      return 0;
    }
    if (3 < param_3) {
      if (param_3 == 4) {
        piVar13 = (int *)(param_2 + 0x390);
        uVar9 = 0;
        do {
          if (*piVar13 == *(int *)(param_1 + 0x7ac)) {
            *param_4 = *(uint *)(param_2 + 0x3d0 + uVar9 * 0xa4);
            return 0;
          }
          uVar5 = (int)uVar9 + 1;
          uVar9 = (ulong)uVar5;
          piVar13 = piVar13 + 0x29;
        } while (uVar5 != 4);
        nvAssertOkFailedNoLog
                  (0xffff,"GetP2060GpuLocation(pGpu, pThis, &iface)",
                   "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x927);
      }
      else {
        piVar13 = (int *)(param_2 + 0x390);
        uVar9 = 0;
        piVar14 = piVar13;
        do {
          if (*piVar14 == *(int *)(param_1 + 0x7ac)) {
            if (*(int *)(param_2 + 0x3d0 + uVar9 * 0xa4) == 0) {
              return 0;
            }
            uVar9 = 0;
            goto LAB_0031444b;
          }
          uVar5 = (int)uVar9 + 1;
          uVar9 = (ulong)uVar5;
          piVar14 = piVar14 + 0x29;
        } while (uVar5 != 4);
      }
      return 0xffff;
    }
    if (param_3 == 1) {
      uVar5 = gsyncReadHouseSignalPresent_P2060(param_1,param_2,0);
      if (uVar5 != 0) {
        return (ulong)uVar5;
      }
      if (*param_4 != 0) {
        uVar9 = gsyncReadHouseSyncFrameRate_P2060(param_1,param_2,param_4);
        return uVar9;
      }
      return 0;
    }
    if (param_3 != 2) {
      uVar9 = gsyncReadFrameRate_P2060(param_1,param_2,param_4);
      return uVar9;
    }
    lVar11 = *(long *)(param_1 + 0x1b80);
    if (lVar11 == 0) {
      nvAssertFailedNoLog("pKernelDisplay != NULL","generated/g_kern_disp_nvoc.h",0x4f9);
    }
    uVar5 = *(uint *)(lVar11 + 0x360);
    *param_4 = 0;
    cVar2 = gsyncIsFrameLocked_P2060(param_2);
    uVar9 = (ulong)uVar5;
    if (cVar2 == '\0') {
      uVar5 = readregu008_extdeviceTargeted(param_1,param_2,0,&local_2c);
      uVar12 = 0x882;
      uVar9 = (ulong)uVar5;
      if (uVar5 == 0) {
LAB_003142bc:
        *param_4 = ~(uint)((byte)local_2c >> 2) & 1;
        return uVar9;
      }
    }
    else {
      piVar13 = (int *)(param_2 + 0x390);
      uVar4 = 0;
      while (*piVar13 != *(int *)(param_1 + 0x7ac)) {
        uVar4 = uVar4 + 1;
        piVar13 = piVar13 + 0x29;
        if (uVar4 == 4) {
          nvAssertOkFailedNoLog
                    (0xffff,"GetP2060GpuLocation(pGpu, pThis, &iface)",
                     "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x88a);
          return 0xffff;
        }
      }
      if (uVar5 == 0) {
        return 0;
      }
      lVar11 = (ulong)uVar4 * 0xa4 + param_2;
      while( true ) {
        if (*(int *)(lVar11 + 0x370) != 0) {
          lVar11 = param_2 + uVar9 * 4;
          do {
            lVar16 = lVar11 + uVar9 * -4;
            do {
              if (*(int *)(lVar16 + 0x330) != 0) {
                if (*(int *)(lVar16 + 0x350) == 0) {
                  *param_4 = 1;
                }
                else {
                  uVar5 = gsyncReadHouseSignalPresent_P2060(param_1,param_2,1,param_4);
                  if (uVar5 != 0) {
                    nvAssertOkFailedNoLog
                              (uVar5,
                               "gsyncReadHouseSignalPresent_P2060(pGpu, pExtDev, NV_TRUE, pVal)",
                               "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x8a3
                              );
                    return (ulong)uVar5;
                  }
                }
              }
              lVar16 = lVar16 + 4;
            } while (lVar16 != lVar11);
            lVar11 = lVar11 + 0xa4;
          } while (lVar11 != param_2 + 0x290 + uVar9 * 4);
          return 0;
        }
        if (*(int *)(lVar11 + 0x330) != 0) {
          if (*(int *)(lVar11 + 0x350) != 0) {
            uVar5 = gsyncReadHouseSignalPresent_P2060(param_1,param_2,1,param_4);
            if (uVar5 != 0) {
              nvAssertOkFailedNoLog
                        (uVar5,"gsyncReadHouseSignalPresent_P2060(pGpu, pExtDev, NV_TRUE, pVal)",
                         "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x8b6);
              return (ulong)uVar5;
            }
            return 0;
          }
          goto LAB_003143e2;
        }
        if (*(int *)(lVar11 + 0x350) != 0) break;
        lVar11 = lVar11 + 4;
        if (lVar11 == param_2 + ((ulong)uVar4 * 0x29 + uVar9) * 4) {
          return 0;
        }
      }
      uVar5 = readregu008_extdeviceTargeted(param_1,param_2,0,&local_2c);
      uVar9 = (ulong)uVar5;
      if (uVar5 == 0) goto LAB_003142bc;
      uVar12 = 0x8c9;
    }
    nvAssertOkFailedNoLog
              (uVar9,
               "readregu008_extdeviceTargeted(pGpu, pExtDev, (NvU8)NV_P2060_STATUS, &regStatus)",
               "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",uVar12);
    return uVar9;
  }
  if (param_3 == 9) {
    uVar5 = readregu008_extdeviceTargeted(param_1,param_2,1,&local_2c);
    if (uVar5 == 0) {
      *param_4 = local_2c >> 2 & 1;
      return 0;
    }
    return (ulong)uVar5;
  }
  if (param_3 < 10) {
    if (param_3 == 7) {
      uVar5 = readregu008_extdeviceTargeted(param_1,param_2,1,&local_2c);
      if (uVar5 == 0) {
        *param_4 = ~(local_2c & 0xff) & 1;
        return 0;
      }
      return (ulong)uVar5;
    }
    uVar5 = readregu008_extdeviceTargeted(param_1,param_2,1,&local_2c);
    if (uVar5 == 0) {
      *param_4 = ~(local_2c >> 1 & 0x7f) & 1;
      return 0;
    }
    return (ulong)uVar5;
  }
  if (param_3 == 10) {
    uVar5 = readregu008_extdeviceTargeted(param_1,param_2,1,&local_2c);
    if (uVar5 == 0) {
      *param_4 = local_2c >> 3 & 1;
      return 0;
    }
    return (ulong)uVar5;
  }
  if (param_3 != 0xb) {
    return 0xffff;
  }
  bVar17 = false;
  iVar15 = 0;
  lVar11 = param_2;
  do {
    if (bVar17) goto LAB_00313de0;
    lVar16 = 1;
    do {
      if ((*(int *)(lVar11 + 0x32c + lVar16 * 4) != 0) ||
         (*(int *)(lVar11 + 0x34c + lVar16 * 4) != 0)) goto LAB_00313de0;
      iVar1 = *(int *)(lVar11 + 0x36c + lVar16 * 4);
      bVar17 = lVar16 != 8;
      lVar16 = lVar16 + 1;
    } while (bVar17 && iVar1 == 0);
    bVar17 = iVar1 != 0;
    iVar15 = iVar15 + 1;
    lVar11 = lVar11 + 0xa4;
  } while ((iVar15 != 4) && (iVar1 == 0));
  if (iVar1 == 0) {
    nvCheckFailedNoLog(1,"isFramelocked",
                       "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x4d2);
    return 0x40;
  }
LAB_00313de0:
  lVar16 = 0;
  lVar11 = *(long *)(param_1 + 0x1b88);
  if (((*(uint *)(param_2 + 0x1bc) == 4) ||
      (lVar16 = gpumgrGetGpuFromId(*(undefined4 *)
                                    (param_2 + 0x390 + (ulong)*(uint *)(param_2 + 0x1bc) * 0xa4)),
      lVar16 == 0)) ||
     (lVar10 = (**(code **)(*(long *)(lVar16 + 0x1b88) + 0x1a0))(lVar16), lVar10 == 0)) {
    lVar10 = (**(code **)(lVar11 + 0x1a0))(param_1,lVar11);
  }
  piVar13 = (int *)(param_2 + 0x390);
  uVar9 = 0;
  do {
    if (*piVar13 == *(int *)(param_1 + 0x7ac)) {
      if ((*(byte *)(param_2 + 0x2d0 + uVar9 * 0x18) & 4) != 0) {
        *param_4 = *(uint *)(param_2 + 0x1a0);
        *(long *)(param_2 + 0x1b0) = lVar10;
        goto LAB_00313f90;
      }
      break;
    }
    uVar5 = (int)uVar9 + 1;
    uVar9 = (ulong)uVar5;
    piVar13 = piVar13 + 0x29;
  } while (uVar5 != 4);
  if (((ulong)(lVar10 - *(long *)(param_2 + 0x1b0)) < 0x2540be401) &&
     (*(long *)(param_2 + 0x1b0) != 0)) {
    if (lVar16 == 0) {
      nvAssertFailedNoLog("pTmpGpu","src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",
                          0x538);
      return 0x26;
    }
    uVar5 = (**(code **)(*(long *)(lVar16 + 0x1b80) + 0x1d8))
                      (lVar16,*(long *)(lVar16 + 0x1b80),*(undefined4 *)(param_2 + 0x1c0),&local_30,
                       &local_2c);
    if (uVar5 != 0) {
      nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x541,
                   "gsyncReadUniversalFrameCount_P2060",4,"NVRM: Failed to read RG_DPCA.\n");
      return (ulong)uVar5;
    }
    uVar5 = *(uint *)(param_2 + 0x198);
    iVar15 = *(int *)(param_2 + 0x1a4);
    if ((uVar5 != local_2c) &&
       (*(ulong *)(param_2 + 0x198) = CONCAT44(uVar5,local_2c), local_2c < uVar5)) {
      iVar15 = iVar15 + 1;
      *(int *)(param_2 + 0x1a4) = iVar15;
    }
    uVar5 = local_2c + *(int *)(param_2 + 0x1b8) + iVar15 * 0x10000 +
            (uint)(*(uint *)(param_2 + 0x1c4) < local_30);
    *(uint *)(param_2 + 0x1a0) = uVar5;
    *param_4 = uVar5;
LAB_00313f6c:
    *(long *)(param_2 + 0x1b0) = lVar10;
    if (((*(char *)(param_2 + 0x1ca) == '\0') && (0xfffc17 < *(uint *)(param_2 + 0x1a0))) &&
       (cVar2 = gsyncIsOnlyFrameLockMaster_P2060(param_2), cVar2 != '\0')) {
      uVar5 = readregu008_extdeviceTargeted(param_1,param_2,5,&local_31);
      local_31 = local_31 | 4;
      uVar4 = writeregu008_extdeviceTargeted(param_1,param_2,5,local_31);
      *(undefined1 *)(param_2 + 0x1ca) = 1;
      if ((uVar5 | uVar4) == 0) {
        uVar9 = 0;
      }
      else {
        uVar8 = gsyncResetFrameCountData_P2060(param_1,param_2);
        uVar9 = (ulong)(uVar5 | uVar4 | uVar8);
      }
    }
    else {
LAB_00313f90:
      uVar9 = 0;
    }
  }
  else {
    if (*(uint *)(param_2 + 0x160) < 10) {
      nvCheckFailedNoLog(1,"pThis->RefreshRate >= 10",
                         "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x500);
      return 0x40;
    }
    *(undefined1 *)(param_2 + 0x1c8) = 1;
    uVar9 = (ulong)*(uint *)(param_2 + 0x160) / 10;
    *(int *)(param_2 + 0x1a8) = (int)(1000000000 / uVar9);
    uVar5 = gsyncUpdateFrameCount_P2060(param_2,param_1,1000000000 % uVar9);
    *param_4 = *(uint *)(param_2 + 0x1a0);
    cVar2 = gsyncIsFrameLockMaster_P2060(param_2);
    if (cVar2 == '\0') {
      uVar4 = writeregu008_extdeviceTargeted(param_1,param_2,0x1d,1);
      uVar8 = writeregu008_extdeviceTargeted(param_1,param_2,0x1e,0);
      uVar6 = writeregu008_extdeviceTargeted(param_1,param_2,0x1f,0);
      uVar7 = readregu008_extdeviceTargeted(param_1,param_2,5,&local_2c);
      uVar5 = uVar4 | uVar8 | uVar5 | uVar6 | uVar7;
      if (uVar5 == 0) {
        bVar3 = (byte)local_2c | 4;
        local_2c = local_2c | 4;
        uVar5 = writeregu008_extdeviceTargeted(param_1,param_2,5,bVar3);
        goto LAB_00313f5f;
      }
    }
    else {
LAB_00313f5f:
      if (uVar5 == 0) goto LAB_00313f6c;
    }
    uVar4 = gsyncResetFrameCountData_P2060(param_1,param_2);
    uVar9 = (ulong)(uVar5 | uVar4);
  }
  return uVar9;
  while( true ) {
    uVar5 = (int)uVar9 + 1;
    uVar9 = (ulong)uVar5;
    piVar13 = piVar13 + 0x29;
    if (uVar5 == 4) break;
LAB_0031444b:
    if (*(int *)(param_1 + 0x7ac) == *piVar13) {
      uVar5 = *(uint *)(param_2 + 0x2d0 + uVar9 * 0x18);
      if ((uVar5 & 0x30) != 0) {
        *param_4 = uVar5 >> 6 & 1;
        return 0;
      }
      break;
    }
  }
LAB_003143e2:
  *param_4 = 1;
  return 0;
}


// ===== 003146d0 gsyncSetWatchdog_P2060 =====

undefined4 gsyncSetWatchdog_P2060(long param_1,long param_2,int param_3)

{
  char cVar1;
  int *piVar2;
  long lVar3;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    nvAssertFailedNoLog("pGpu && pP2060",
                        "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x100d);
    return 0x26;
  }
  if (param_3 == 0) {
    return 0;
  }
  gsyncCancelWatchdog_P2060(param_2);
  piVar2 = (int *)(param_2 + 0x390);
  do {
    if (*piVar2 != -1) {
      lVar3 = gpumgrGetGpuFromId();
      if (lVar3 == 0) {
        nvAssertFailedNoLog("pTmpGpu",
                            "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x1216);
      }
      goto LAB_0031472a;
    }
    piVar2 = piVar2 + 0x29;
  } while (piVar2 != (int *)(param_2 + 0x620));
  lVar3 = 0;
LAB_0031472a:
  extdevScheduleWatchdog(lVar3,param_2);
  cVar1 = gsyncIsOnlyFrameLockMaster_P2060(param_2);
  if (cVar1 == '\0') {
    *(undefined4 *)(param_2 + 0x170) = 0x3c;
  }
  return 0;
}


// ===== 003147b0 gsyncGetRevision_P2060 =====

undefined8 gsyncGetRevision_P2060(long param_1,long param_2,uint *param_3)

{
  byte bVar1;
  uint uVar2;
  long lVar3;
  undefined1 uVar4;
  char cVar5;
  long lVar6;
  uint uVar7;
  long lVar8;
  
  lVar8 = g_pSys;
  if (param_1 == 0) {
    nvAssertFailedNoLog("pGpu != NULL",
                        "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x102f);
    return 0x3b;
  }
  if (param_2 == 0) {
    nvAssertFailedNoLog("pGsync != NULL",
                        "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x1030);
    return 0x3b;
  }
  lVar3 = *(long *)(param_2 + 0x40);
  if (lVar3 == 0) {
    nvAssertFailedNoLog("pExtDev != NULL",
                        "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x1032);
    return 0x3b;
  }
  uVar7 = *(uint *)(lVar3 + 0x1c);
  uVar2 = *(uint *)(lVar3 + 0x20);
  portMemSet(param_3,0,0x34);
  bVar1 = *(byte *)(lVar3 + 0x18);
  param_3[1] = uVar7;
  param_3[4] = uVar2;
  *param_3 = (uint)bVar1;
  param_3[5] = (uint)*(byte *)(lVar3 + 0x24);
  if ((uVar2 == 9) || (1 < uVar7 - 0x2060)) {
    param_3[1] = 0;
    return 0;
  }
  param_3[6] = 2;
  if (*(char *)(lVar8 + 0x81) == '\0') {
    if (*(int *)(param_2 + 4) == 0) {
      uVar7 = 0x32100002;
      uVar4 = 0;
    }
    else {
      lVar8 = 0;
      do {
        lVar6 = gpumgrGetGpuFromId(*(undefined4 *)(param_2 + 0xc + lVar8 * 0xc));
        if (lVar6 == 0) {
          nvAssertFailedNoLog("pOtherGpu != NULL",
                              "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x155a
                             );
          uVar4 = 1;
          uVar7 = param_3[6] | 0x32100000;
          goto LAB_00314889;
        }
        cVar5 = gsyncmgrIsFirmwareGPUMismatch_STATIC_DISPATCH(lVar6,param_2);
        if (cVar5 != '\0') {
          uVar4 = 1;
          uVar7 = param_3[6] | 0x32100000;
          goto LAB_00314889;
        }
        lVar8 = lVar8 + 1;
      } while ((uint)lVar8 < *(uint *)(param_2 + 4));
      uVar7 = param_3[6] | 0x32100000;
      uVar4 = 0;
    }
  }
  else {
    uVar7 = 0x32100002;
    uVar4 = 0;
  }
LAB_00314889:
  *(undefined1 *)(param_3 + 3) = uVar4;
  param_3[7] = *(uint *)(lVar3 + 0x18c);
  uVar2 = *(uint *)(lVar3 + 0x188);
  param_3[0xb] = 7;
  param_3[8] = uVar2;
  param_3[9] = 0xffff;
  param_3[10] = 0x1e78;
  param_3[6] = uVar7;
  if (*(int *)(lVar3 + 0x1c) != 0x2061) {
    if (*(int *)(lVar3 + 0x1c) == 0x2060) {
      if (5 < *(uint *)(lVar3 + 0x20)) {
        return 0;
      }
    }
    else {
      nvAssertFailedNoLog("pExtdev->deviceId == DAC_EXTERNAL_DEVICE_P2060",
                          "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x1543);
      if (5 < *(uint *)(lVar3 + 0x20)) {
        if (*(int *)(lVar3 + 0x1c) != 0x2061) {
          return 0;
        }
        goto LAB_00314910;
      }
    }
    param_3[6] = param_3[6] | 0x10;
    if (*(int *)(lVar3 + 0x1c) != 0x2061) {
      return 0;
    }
  }
  if (*(uint *)(lVar3 + 0x20) < 3) {
    if (*(uint *)(lVar3 + 0x20) != 2) {
      return 0;
    }
    if (*(byte *)(lVar3 + 0x24) < 4) {
      return 0;
    }
  }
LAB_00314910:
  param_3[6] = param_3[6] | 0x20;
  param_3[0xc] = 8;
  return 0;
}


// ===== 00314a70 __pfx_gsyncRefSwapBarrier_P2060 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

ulong __pfx_gsyncRefSwapBarrier_P2060(long param_1,long param_2,uint param_3,byte *param_4)

{
  long lVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  ulong uVar7;
  long lVar8;
  int *piVar9;
  uint uVar10;
  ulong uVar11;
  ulong uVar12;
  byte bStack_41;
  undefined4 uStack_40;
  uint auStack_3c [3];
  
  if (param_3 < 2) {
    piVar9 = (int *)(param_2 + 0x390);
    uVar10 = 0;
    piVar6 = piVar9;
    do {
      if (*piVar6 == *(int *)(param_1 + 0x7ac)) {
        cVar3 = gsyncIsP2060MasterBoard(param_1,param_2);
        if (((cVar3 != '\0') && (cVar3 = GpuIsP2060Master(param_1,param_2), cVar3 != '\0')) ||
           ((cVar3 = GpuIsConnectedToMasterViaBridge(param_1,param_2), cVar3 != '\0' &&
            (((cVar3 = gpumgrGetGpuBridgeType(), cVar3 == '\0' ||
              (*(ushort *)(param_1 + 0x7f6) - 0x2230 < 2)) ||
             (*(ushort *)(param_1 + 0x7f6) == 0x2233)))))) {
          *param_4 = *(byte *)(param_2 + 0x3c8 + (ulong)uVar10 * 0xa4);
          return 0;
        }
        uVar7 = 0;
        while (*piVar9 != *(int *)(param_1 + 0x7ac)) {
          uVar10 = (int)uVar7 + 1;
          uVar7 = (ulong)uVar10;
          piVar9 = piVar9 + 0x29;
          if (uVar10 == 4) {
            return 0;
          }
        }
        if (*(char *)(param_2 + 0x394 + uVar7 * 0xa4) == '\0') {
          return 0;
        }
        auStack_3c[0] = auStack_3c[0] & 0xffffff00;
        uVar10 = readregu008_extdeviceTargeted(param_1,param_2,4,auStack_3c);
        if (uVar10 == 0) {
          *param_4 = (byte)auStack_3c[0] >> 5 & 1;
          return 0;
        }
        return (ulong)uVar10;
      }
      uVar10 = uVar10 + 1;
      piVar6 = piVar6 + 0x29;
    } while (uVar10 != 4);
  }
  else {
    if (param_3 != 2) {
      return 0;
    }
    bStack_41 = 0;
    piVar9 = (int *)(param_2 + 0x390);
    bVar2 = *param_4;
    uVar10 = 0;
    piVar6 = piVar9;
    do {
      if (*piVar6 == *(int *)(param_1 + 0x7ac)) {
        uVar7 = 0;
        piVar6 = piVar9;
        goto LAB_00314bc0;
      }
      uVar10 = uVar10 + 1;
      piVar6 = piVar6 + 0x29;
    } while (uVar10 != 4);
  }
  return 0xffff;
  while( true ) {
    uVar4 = (int)uVar7 + 1;
    uVar7 = (ulong)uVar4;
    piVar6 = piVar6 + 0x29;
    if (uVar4 == 4) break;
LAB_00314bc0:
    if (*(int *)(param_1 + 0x7ac) == *piVar6) {
      if (*(char *)(param_2 + 0x394 + uVar7 * 0xa4) != '\0') {
        uVar4 = readregu008_extdeviceTargeted(param_1,param_2,4,&bStack_41);
        if (uVar4 != 0) {
          return (ulong)uVar4;
        }
        if (7 < *(uint *)(param_2 + 0x20)) {
          return 0x40;
        }
      }
      break;
    }
  }
  uVar7 = (ulong)uVar10;
  lVar8 = uVar7 * 0xa4 + param_2;
  if (bVar2 == *(byte *)(lVar8 + 0x3c8)) {
    return 0;
  }
  if (bVar2 == 0) {
    bStack_41 = bStack_41 & 0xdf;
    if (*(char *)(lVar8 + 0x3b8) == '\x01') {
      lVar8 = *(long *)(param_1 + 0x1b80);
      if (lVar8 == 0) {
        nvAssertFailedNoLog("pKernelDisplay != NULL","generated/g_kern_disp_nvoc.h",0x4f9);
      }
      uVar10 = *(uint *)(lVar8 + 0x360);
      if (uVar10 != 0) {
        uVar12 = 0;
        do {
          uVar11 = uVar12 & 0xffffffff;
          lVar1 = uVar12 * 4;
          uVar12 = uVar12 + 1;
          (**(code **)(lVar8 + 0x1f0))
                    (param_1,lVar8,uVar11,*(undefined4 *)(param_2 + uVar7 * 0xa4 + 0x398 + lVar1),
                     *(code **)(lVar8 + 0x1f0));
        } while (uVar10 != uVar12);
      }
      *(undefined1 *)(param_2 + 0x3b8 + uVar7 * 0xa4) = 0;
    }
    if ((*(char *)(param_2 + 0x3c9 + uVar7 * 0xa4) == '\0') && (*(int *)(param_2 + 0x1c) != 0x2061))
    {
      if (*(int *)(param_2 + 0x1c) != 0x2060) {
        nvAssertFailedNoLog("pExtdev->deviceId == DAC_EXTERNAL_DEVICE_P2060",
                            "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x1543);
      }
      if (((*(uint *)(param_2 + 0x20) < 6) &&
          (cVar3 = gsyncIsP2060MasterBoard(param_1,param_2), cVar3 != '\0')) &&
         (cVar3 = GpuIsP2060Master(param_1,param_2), cVar3 != '\0')) {
        *(undefined1 *)(param_2 + 0x3c8 + uVar7 * 0xa4) = 0;
        return 0;
      }
    }
    uVar12 = 0;
  }
  else {
    bStack_41 = bStack_41 | 0x20;
    if (*(int *)(param_2 + 0x180) == 0) {
      *(undefined4 *)(param_2 + 0x180) = 0xfa;
      auStack_3c[0] = 0;
      iVar5 = osReadRegistryDword(param_1,"TSwapRdyHiLsrMinTime",auStack_3c);
      if (iVar5 == 0) {
        *(uint *)(param_2 + 0x180) = auStack_3c[0];
        uVar10 = auStack_3c[0];
      }
      else {
        uVar10 = *(uint *)(param_2 + 0x180);
      }
      if (uVar10 == 0) {
        nvAssertFailedNoLog("pThis->tSwapRdyHiLsrMinTime != 0",
                            "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xbd1);
      }
    }
    uVar12 = 0;
    if (*(char *)(param_2 + 0x3b8 + uVar7 * 0xa4) == '\0') {
      lVar8 = *(long *)(param_1 + 0x1b80);
      if (lVar8 == 0) {
        nvAssertFailedNoLog("pKernelDisplay != NULL","generated/g_kern_disp_nvoc.h",0x4f9);
      }
      uVar12 = (ulong)*(uint *)(lVar8 + 0x360);
      if (*(uint *)(lVar8 + 0x360) != 0) {
        uVar11 = 0;
        do {
          uVar10 = (**(code **)(lVar8 + 0x1f8))
                             (param_1,lVar8,uVar11 & 0xffffffff,*(undefined4 *)(param_2 + 0x180),
                              &uStack_40);
          if (uVar10 == 0) {
            (**(code **)(lVar8 + 0x200))(param_1,lVar8,uVar11 & 0xffffffff,auStack_3c,uStack_40);
            *(uint *)(uVar7 * 0xa4 + param_2 + 0x398 + uVar11 * 4) = auStack_3c[0];
          }
          else {
            nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xbe7,
                         "gsyncProgramSwapBarrier_P2060",4,
                         "NVRM: Error occured while computing LSR_MIN_TIME for Swap Barrier\n");
            nvAssertFailedNoLog(&DAT_00d0fb48,
                                "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",
                                0xbe9);
          }
          uVar11 = uVar11 + 1;
        } while (uVar12 != uVar11);
        uVar12 = (ulong)uVar10;
      }
      *(undefined1 *)(param_2 + 0x3b8 + uVar7 * 0xa4) = 1;
    }
    if ((*(char *)(param_2 + 0x3c9 + uVar7 * 0xa4) == '\0') && (*(int *)(param_2 + 0x1c) != 0x2061))
    {
      if (*(int *)(param_2 + 0x1c) != 0x2060) {
        nvAssertFailedNoLog("pExtdev->deviceId == DAC_EXTERNAL_DEVICE_P2060",
                            "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x1543);
      }
      if (((*(uint *)(param_2 + 0x20) < 6) &&
          (cVar3 = gsyncIsP2060MasterBoard(param_1,param_2), cVar3 != '\0')) &&
         (cVar3 = GpuIsP2060Master(param_1,param_2), cVar3 != '\0')) {
        *(byte *)(param_2 + 0x3c8 + uVar7 * 0xa4) = bVar2;
        return 0;
      }
    }
    cVar3 = GpuIsConnectedToMasterViaBridge(param_1,param_2);
    if ((cVar3 != '\0') &&
       (((cVar3 = gpumgrGetGpuBridgeType(), cVar3 == '\0' ||
         (*(ushort *)(param_1 + 0x7f6) - 0x2230 < 2)) || (*(ushort *)(param_1 + 0x7f6) == 0x2233))))
    {
      *(byte *)(param_2 + 0x3c8 + uVar7 * 0xa4) = bVar2;
      return uVar12;
    }
  }
  uVar11 = 0;
  *(byte *)(param_2 + 0x3c8 + uVar7 * 0xa4) = bVar2;
  do {
    if (*piVar9 == *(int *)(param_1 + 0x7ac)) {
      if (*(char *)(param_2 + 0x394 + uVar11 * 0xa4) != '\0') {
        uVar10 = writeregu008_extdeviceTargeted(param_1,param_2,4,bStack_41);
        return (ulong)uVar10;
      }
      return uVar12;
    }
    uVar10 = (int)uVar11 + 1;
    uVar11 = (ulong)uVar10;
    piVar9 = piVar9 + 0x29;
  } while (uVar10 != 4);
  return uVar12;
}


// ===== 00314a80 gsyncRefSwapBarrier_P2060 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

ulong gsyncRefSwapBarrier_P2060(long param_1,long param_2,uint param_3,byte *param_4)

{
  long lVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  ulong uVar7;
  long lVar8;
  int *piVar9;
  uint uVar10;
  ulong uVar11;
  ulong uVar12;
  byte local_41;
  undefined4 local_40;
  uint local_3c [3];
  
  if (param_3 < 2) {
    piVar9 = (int *)(param_2 + 0x390);
    uVar10 = 0;
    piVar6 = piVar9;
    do {
      if (*piVar6 == *(int *)(param_1 + 0x7ac)) {
        cVar3 = gsyncIsP2060MasterBoard(param_1,param_2);
        if (((cVar3 != '\0') && (cVar3 = GpuIsP2060Master(param_1,param_2), cVar3 != '\0')) ||
           ((cVar3 = GpuIsConnectedToMasterViaBridge(param_1,param_2), cVar3 != '\0' &&
            (((cVar3 = gpumgrGetGpuBridgeType(), cVar3 == '\0' ||
              (*(ushort *)(param_1 + 0x7f6) - 0x2230 < 2)) ||
             (*(ushort *)(param_1 + 0x7f6) == 0x2233)))))) {
          *param_4 = *(byte *)(param_2 + 0x3c8 + (ulong)uVar10 * 0xa4);
          return 0;
        }
        uVar7 = 0;
        while (*piVar9 != *(int *)(param_1 + 0x7ac)) {
          uVar10 = (int)uVar7 + 1;
          uVar7 = (ulong)uVar10;
          piVar9 = piVar9 + 0x29;
          if (uVar10 == 4) {
            return 0;
          }
        }
        if (*(char *)(param_2 + 0x394 + uVar7 * 0xa4) == '\0') {
          return 0;
        }
        local_3c[0] = local_3c[0] & 0xffffff00;
        uVar10 = readregu008_extdeviceTargeted(param_1,param_2,4,local_3c);
        if (uVar10 == 0) {
          *param_4 = (byte)local_3c[0] >> 5 & 1;
          return 0;
        }
        return (ulong)uVar10;
      }
      uVar10 = uVar10 + 1;
      piVar6 = piVar6 + 0x29;
    } while (uVar10 != 4);
  }
  else {
    if (param_3 != 2) {
      return 0;
    }
    local_41 = 0;
    piVar9 = (int *)(param_2 + 0x390);
    bVar2 = *param_4;
    uVar10 = 0;
    piVar6 = piVar9;
    do {
      if (*piVar6 == *(int *)(param_1 + 0x7ac)) {
        uVar7 = 0;
        piVar6 = piVar9;
        goto LAB_00314bc0;
      }
      uVar10 = uVar10 + 1;
      piVar6 = piVar6 + 0x29;
    } while (uVar10 != 4);
  }
  return 0xffff;
  while( true ) {
    uVar4 = (int)uVar7 + 1;
    uVar7 = (ulong)uVar4;
    piVar6 = piVar6 + 0x29;
    if (uVar4 == 4) break;
LAB_00314bc0:
    if (*(int *)(param_1 + 0x7ac) == *piVar6) {
      if (*(char *)(param_2 + 0x394 + uVar7 * 0xa4) != '\0') {
        uVar4 = readregu008_extdeviceTargeted(param_1,param_2,4,&local_41);
        if (uVar4 != 0) {
          return (ulong)uVar4;
        }
        if (7 < *(uint *)(param_2 + 0x20)) {
          return 0x40;
        }
      }
      break;
    }
  }
  uVar7 = (ulong)uVar10;
  lVar8 = uVar7 * 0xa4 + param_2;
  if (bVar2 == *(byte *)(lVar8 + 0x3c8)) {
    return 0;
  }
  if (bVar2 == 0) {
    local_41 = local_41 & 0xdf;
    if (*(char *)(lVar8 + 0x3b8) == '\x01') {
      lVar8 = *(long *)(param_1 + 0x1b80);
      if (lVar8 == 0) {
        nvAssertFailedNoLog("pKernelDisplay != NULL","generated/g_kern_disp_nvoc.h",0x4f9);
      }
      uVar10 = *(uint *)(lVar8 + 0x360);
      if (uVar10 != 0) {
        uVar12 = 0;
        do {
          uVar11 = uVar12 & 0xffffffff;
          lVar1 = uVar12 * 4;
          uVar12 = uVar12 + 1;
          (**(code **)(lVar8 + 0x1f0))
                    (param_1,lVar8,uVar11,*(undefined4 *)(param_2 + uVar7 * 0xa4 + 0x398 + lVar1),
                     *(code **)(lVar8 + 0x1f0));
        } while (uVar10 != uVar12);
      }
      *(undefined1 *)(param_2 + 0x3b8 + uVar7 * 0xa4) = 0;
    }
    if ((*(char *)(param_2 + 0x3c9 + uVar7 * 0xa4) == '\0') && (*(int *)(param_2 + 0x1c) != 0x2061))
    {
      if (*(int *)(param_2 + 0x1c) != 0x2060) {
        nvAssertFailedNoLog("pExtdev->deviceId == DAC_EXTERNAL_DEVICE_P2060",
                            "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x1543);
      }
      if (((*(uint *)(param_2 + 0x20) < 6) &&
          (cVar3 = gsyncIsP2060MasterBoard(param_1,param_2), cVar3 != '\0')) &&
         (cVar3 = GpuIsP2060Master(param_1,param_2), cVar3 != '\0')) {
        *(undefined1 *)(param_2 + 0x3c8 + uVar7 * 0xa4) = 0;
        return 0;
      }
    }
    uVar12 = 0;
  }
  else {
    local_41 = local_41 | 0x20;
    if (*(int *)(param_2 + 0x180) == 0) {
      *(undefined4 *)(param_2 + 0x180) = 0xfa;
      local_3c[0] = 0;
      iVar5 = osReadRegistryDword(param_1,"TSwapRdyHiLsrMinTime",local_3c);
      if (iVar5 == 0) {
        *(uint *)(param_2 + 0x180) = local_3c[0];
        uVar10 = local_3c[0];
      }
      else {
        uVar10 = *(uint *)(param_2 + 0x180);
      }
      if (uVar10 == 0) {
        nvAssertFailedNoLog("pThis->tSwapRdyHiLsrMinTime != 0",
                            "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xbd1);
      }
    }
    uVar12 = 0;
    if (*(char *)(param_2 + 0x3b8 + uVar7 * 0xa4) == '\0') {
      lVar8 = *(long *)(param_1 + 0x1b80);
      if (lVar8 == 0) {
        nvAssertFailedNoLog("pKernelDisplay != NULL","generated/g_kern_disp_nvoc.h",0x4f9);
      }
      uVar12 = (ulong)*(uint *)(lVar8 + 0x360);
      if (*(uint *)(lVar8 + 0x360) != 0) {
        uVar11 = 0;
        do {
          uVar10 = (**(code **)(lVar8 + 0x1f8))
                             (param_1,lVar8,uVar11 & 0xffffffff,*(undefined4 *)(param_2 + 0x180),
                              &local_40);
          if (uVar10 == 0) {
            (**(code **)(lVar8 + 0x200))(param_1,lVar8,uVar11 & 0xffffffff,local_3c,local_40);
            *(uint *)(uVar7 * 0xa4 + param_2 + 0x398 + uVar11 * 4) = local_3c[0];
          }
          else {
            nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xbe7,
                         "gsyncProgramSwapBarrier_P2060",4,
                         "NVRM: Error occured while computing LSR_MIN_TIME for Swap Barrier\n");
            nvAssertFailedNoLog(&DAT_00d0fb48,
                                "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",
                                0xbe9);
          }
          uVar11 = uVar11 + 1;
        } while (uVar12 != uVar11);
        uVar12 = (ulong)uVar10;
      }
      *(undefined1 *)(param_2 + 0x3b8 + uVar7 * 0xa4) = 1;
    }
    if ((*(char *)(param_2 + 0x3c9 + uVar7 * 0xa4) == '\0') && (*(int *)(param_2 + 0x1c) != 0x2061))
    {
      if (*(int *)(param_2 + 0x1c) != 0x2060) {
        nvAssertFailedNoLog("pExtdev->deviceId == DAC_EXTERNAL_DEVICE_P2060",
                            "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x1543);
      }
      if (((*(uint *)(param_2 + 0x20) < 6) &&
          (cVar3 = gsyncIsP2060MasterBoard(param_1,param_2), cVar3 != '\0')) &&
         (cVar3 = GpuIsP2060Master(param_1,param_2), cVar3 != '\0')) {
        *(byte *)(param_2 + 0x3c8 + uVar7 * 0xa4) = bVar2;
        return 0;
      }
    }
    cVar3 = GpuIsConnectedToMasterViaBridge(param_1,param_2);
    if ((cVar3 != '\0') &&
       (((cVar3 = gpumgrGetGpuBridgeType(), cVar3 == '\0' ||
         (*(ushort *)(param_1 + 0x7f6) - 0x2230 < 2)) || (*(ushort *)(param_1 + 0x7f6) == 0x2233))))
    {
      *(byte *)(param_2 + 0x3c8 + uVar7 * 0xa4) = bVar2;
      return uVar12;
    }
  }
  uVar11 = 0;
  *(byte *)(param_2 + 0x3c8 + uVar7 * 0xa4) = bVar2;
  do {
    if (*piVar9 == *(int *)(param_1 + 0x7ac)) {
      if (*(char *)(param_2 + 0x394 + uVar11 * 0xa4) != '\0') {
        uVar10 = writeregu008_extdeviceTargeted(param_1,param_2,4,local_41);
        return (ulong)uVar10;
      }
      return uVar12;
    }
    uVar10 = (int)uVar11 + 1;
    uVar11 = (ulong)uVar10;
    piVar9 = piVar9 + 0x29;
  } while (uVar10 != 4);
  return uVar12;
}


// ===== 003152e0 gsyncConfigFlashGsync_P2060 =====

int gsyncConfigFlashGsync_P2060(undefined8 param_1,long param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  long lVar3;
  int *piVar4;
  undefined8 uVar5;
  char *pcVar6;
  byte local_29;
  
  if (param_3 == 0) {
    if (*(char *)(param_2 + 0x174) != '\0') {
LAB_00315364:
      piVar4 = (int *)(param_2 + 0x390);
      do {
        if (*piVar4 != -1) {
          lVar3 = gpumgrGetGpuFromId();
          if (lVar3 == 0) {
            nvAssertFailedNoLog("pTmpGpu",
                                "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",
                                0x10df);
          }
          local_29 = 0;
          iVar2 = readregu008_extdeviceTargeted(lVar3,param_2,6,&local_29);
          if (iVar2 != 0) {
LAB_003153bb:
            nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x10e4,
                         "gsyncConfigFlashGsync_P2060",4,
                         "NVRM: Failed to Program External Stereo Polarity for GPU.\n");
            return iVar2;
          }
          local_29 = local_29 | 0x20;
          iVar2 = writeregu008_extdeviceTargeted(lVar3,param_2,6,local_29);
          if (iVar2 != 0) goto LAB_003153bb;
        }
        piVar4 = piVar4 + 0x29;
        if (piVar4 == (int *)(param_2 + 0x620)) {
          return 0;
        }
      } while( true );
    }
    iVar2 = readregu008_extdeviceTargeted(param_1,param_2,1,&local_29);
    bVar1 = local_29;
    if (iVar2 == 0) {
      local_29 = 0;
      readregu008_extdeviceTargeted(param_1,param_2,5,&local_29);
      local_29 = local_29 | 0x28;
      iVar2 = writeregu008_extdeviceTargeted(param_1,param_2,5,local_29);
      if (iVar2 == 0) {
        *(undefined1 *)(param_2 + 0x174) = 1;
        *(uint *)(param_2 + 0x178) = (uint)(bVar1 >> 6);
        goto LAB_00315364;
      }
      pcVar6 = "NVRM: Failed to enable non-framelock interrupts on gsync GPU.\n";
      uVar5 = 0x10d0;
LAB_0031559e:
      nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",uVar5,
                   "gsyncConfigFlashGsync_P2060",4,pcVar6);
    }
    else {
      nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x10c8,
                   "gsyncConfigFlashGsync_P2060",4,
                   "NVRM: failed to find P2060 connector of the GPU.\n");
    }
  }
  else {
    if (*(char *)(param_2 + 0x174) != '\0') {
      piVar4 = (int *)(param_2 + 0x390);
      iVar2 = 0;
      do {
        if ((*piVar4 != -1) && (*(int *)(param_2 + 0x178) == iVar2)) {
          lVar3 = gpumgrGetGpuFromId();
          if (lVar3 == 0) {
            nvAssertFailedNoLog("pTmpGpu",
                                "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",
                                0x10b2);
          }
          local_29 = 0;
          readregu008_extdeviceTargeted(lVar3,param_2,5,&local_29);
          local_29 = local_29 & 0xd7;
          iVar2 = writeregu008_extdeviceTargeted(lVar3,param_2,5,local_29);
          if (iVar2 != 0) {
            pcVar6 = "NVRM: Failed to disable non-framelock interrupts on gsync GPU.\n";
            uVar5 = 0x10b7;
            goto LAB_0031559e;
          }
          break;
        }
        iVar2 = iVar2 + 1;
        piVar4 = piVar4 + 0x29;
      } while (iVar2 != 4);
      *(undefined1 *)(param_2 + 0x174) = 0;
    }
    iVar2 = 0;
  }
  return iVar2;
}


// ===== 00315600 gsyncGpuCanBeMaster_P2060 =====

undefined4 gsyncGpuCanBeMaster_P2060(long param_1,long param_2)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  
  uVar2 = gsyncIsP2060MasterBoard();
  if ((char)uVar2 == '\0') {
    return 1;
  }
  piVar7 = (int *)(param_2 + 0x390);
  iVar5 = 0;
  piVar3 = piVar7;
  while (*piVar3 != *(int *)(param_1 + 0x7ac)) {
    iVar5 = iVar5 + 1;
    piVar3 = piVar3 + 0x29;
    if (iVar5 == 4) {
      return 0;
    }
  }
  iVar6 = 0;
  do {
    if ((iVar6 != iVar5) && (*piVar7 != -1)) {
      lVar4 = gpumgrGetGpuFromId();
      if (lVar4 == 0) {
        nvAssertFailedNoLog("pTempGpu",
                            "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x11fc);
      }
      cVar1 = GpuIsP2060Master(lVar4,param_2);
      if (cVar1 != '\0') {
        return 0;
      }
    }
    iVar6 = iVar6 + 1;
    piVar7 = piVar7 + 0x29;
    if (iVar6 == 4) {
      return uVar2;
    }
  } while( true );
}


// ===== 00315700 gsyncRefMaster_P2060 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint gsyncRefMaster_P2060
               (long param_1,long param_2,uint param_3,uint *param_4,undefined4 *param_5,
               char param_6,char param_7)

{
  undefined4 uVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  long lVar11;
  int *piVar12;
  long lVar13;
  byte bVar14;
  uint uVar15;
  long lVar16;
  long lVar17;
  uint *puVar18;
  undefined8 uVar19;
  char *pcVar20;
  uint uVar21;
  int *piVar22;
  bool bVar23;
  uint local_98;
  byte local_69;
  undefined1 local_68 [4];
  undefined1 local_64 [4];
  undefined8 local_60;
  uint local_58 [10];
  
  lVar17 = *(long *)(param_2 + 0x40);
  if (param_3 == 2) {
    if (param_6 == '\0') {
      uVar7 = *param_4;
      *(uint *)(lVar17 + 0x150) = uVar7;
    }
    else {
      uVar7 = *(uint *)(lVar17 + 0x150);
    }
    *(undefined4 *)(lVar17 + 0x160) = *param_5;
    if ((uVar7 == 0) || (cVar5 = gsyncGpuCanBeMaster_P2060(param_1,lVar17), cVar5 != '\0')) {
      lVar16 = lVar17 + 0x30;
      do {
        if (*(char *)(lVar17 + 0x624) != '\0') {
          lVar13 = 0;
          do {
            lVar11 = gpumgrGetGpuFromId(*(undefined4 *)(lVar17 + 0x614 + lVar13 * 4));
            if (lVar11 == 0) {
              nvAssertFailedNoLog("pTempGpu",
                                  "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",
                                  0x11c5);
            }
            if (param_1 == lVar11) {
              nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xf40,
                           "gsyncRefMaster_P2060",1,
                           "NVRM: P2060 GPU is mosaic timing slave. Can not set Framelock Master.\n"
                          );
              goto LAB_00315a16;
            }
            lVar13 = lVar13 + 1;
          } while (lVar13 != 3);
        }
        lVar17 = lVar17 + 0x18;
      } while (lVar17 != lVar16);
      bVar23 = uVar7 != 0;
      local_69 = 0;
      lVar17 = *(long *)(param_1 + 0x1b80);
      if (lVar17 == 0) {
        nvAssertFailedNoLog("pKernelDisplay != NULL","generated/g_kern_disp_nvoc.h",0x4f9);
      }
      uVar2 = *(uint *)(lVar17 + 0x360);
      lVar17 = *(long *)(param_2 + 0x40);
      if ((param_6 == '\0') || (!bVar23)) {
        extdevGetBoundHeadsAndDisplayIds(param_1,local_58);
        uVar21 = 0;
        piVar22 = (int *)(lVar17 + 0x390);
        piVar12 = piVar22;
        do {
          if (*piVar12 == *(int *)(param_1 + 0x7ac)) {
            local_98 = readregu008_extdeviceTargeted(param_1,lVar17,3,&local_69);
            bVar3 = local_69;
            if (local_98 != 0) {
              pcVar20 = "NVRM: Failed to read Ctrl data. Can not program Master.\n";
              uVar19 = 0x96c;
              goto LAB_00315c89;
            }
            uVar8 = readregu008_extdeviceTargeted(param_1,lVar17,1,&local_60);
            bVar4 = local_69;
            if (uVar8 != 0) {
              nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x97a,
                           "gsyncProgramMaster_P2060",4,
                           "NVRM: Failed to get connector index for Gpu. Can not program Master.\n")
              ;
              return uVar8;
            }
            if ((*(char *)(param_1 + 0x4912) != '\0') &&
               (((local_69 >> 4 & 3) != (byte)local_60 >> 6 & local_69 & 1) != 0)) {
              return 0;
            }
            uVar8 = (uint)CONCAT71((int7)((ulong)param_1 >> 8),bVar23);
            if (bVar23 == (bool)(local_69 & 1)) goto LAB_00315d06;
            if (*(int *)(lVar17 + 0x20) == 9) {
              nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x992,
                           "gsyncProgramMaster_P2060",4,
                           "NVRM: Failed to read NV_P2060_FPGA. Can not program Master.\n");
              return 0;
            }
            if (uVar7 == 0) {
              if ((bVar3 & 8) == 0) {
                local_98 = 0;
              }
              else {
                local_69 = local_69 & 0xf7;
                local_98 = writeregu008_extdeviceTargeted(param_1,lVar17,3,local_69);
                osDelay(0x1e);
              }
              local_69 = local_69 & 0xfe;
              uVar9 = writeregu008_extdeviceTargeted(param_1,lVar17,3,local_69);
              local_98 = local_98 | uVar9;
              if (local_98 == 0) {
                osDelay(200);
                cVar5 = *(char *)(lVar17 + 0x3c9 + (ulong)uVar21 * 0xa4);
                *(undefined1 *)(lVar17 + 0x3c9 + (ulong)uVar21 * 0xa4) = 0;
                if ((cVar5 == '\0') && (iVar10 = *(int *)(lVar17 + 0x1c), iVar10 != 0x2061)) {
LAB_0031620a:
                  if (iVar10 != 0x2060) {
                    nvAssertFailedNoLog("pExtdev->deviceId == DAC_EXTERNAL_DEVICE_P2060",
                                        "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c"
                                        ,0x1543);
                  }
                  if (*(uint *)(lVar17 + 0x20) < 6) {
                    local_60 = local_60 & 0xffffffffffffff00;
                    local_98 = readregu008_extdeviceTargeted(param_1,lVar17,4,&local_60);
                    if (local_98 == 0) {
                      uVar15 = uVar8 << 5;
                      uVar9 = (uint)(byte)local_60;
                      local_60 = CONCAT71(local_60._1_7_,(byte)(uVar9 & 0xffffffdf) | (byte)uVar15);
                      local_98 = writeregu008_extdeviceTargeted
                                           (param_1,lVar17,4,uVar9 & 0xffffffdf | uVar15 & 0xff);
                      if (local_98 == 0) goto LAB_00315d06;
                    }
                    pcVar20 = "NVRM: Failed to update SwapRdyEnable. Can not program Master.\n";
                    uVar19 = 0x9ea;
                    goto LAB_00315c89;
                  }
LAB_00315d06:
                  if (uVar2 == 0) goto LAB_00315de9;
                }
                else if (uVar2 == 0) goto LAB_0031604f;
LAB_00315d12:
                lVar16 = 0;
                puVar18 = (uint *)(lVar17 + 0x330 + (ulong)uVar21 * 0xa4);
                do {
                  if (((local_58[lVar16] & uVar7) == 0) && ((uVar7 == 0 & bVar4) == 0)) {
                    *puVar18 = 0;
                  }
                  else {
                    *puVar18 = (uint)bVar23;
                    puVar18[8] = bVar3 >> 7 & uVar8;
                    gsyncProgramFramelockEnable_P2060(param_1,lVar17,(ulong)uVar21);
                  }
                  lVar16 = lVar16 + 1;
                  puVar18 = puVar18 + 1;
                } while ((uint)lVar16 < uVar2);
LAB_00315de9:
                if (uVar7 == 0) {
LAB_0031604f:
                  cVar5 = gsyncIsFrameLocked_P2060(lVar17);
                  if (cVar5 == '\0') {
                    gsyncDisableFrameLockInterrupt_P2060(lVar17);
                  }
                }
LAB_00315df2:
                local_60 = 0;
                uVar8 = 0;
                uVar9 = 0;
                do {
                  if ((uVar21 != uVar8) && (*piVar22 != -1)) {
                    lVar16 = gpumgrGetGpuFromId();
                    if (lVar16 == 0) {
                      nvAssertFailedNoLog("pOtherGpu",
                                          "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c"
                                          ,0xa2b);
                    }
                    iVar10 = gpumgrGetGpuLockAndDrPorts(param_1,lVar16,local_68,local_64);
                    if (iVar10 == 0) {
                      local_60._0_2_ = CONCAT11((char)piVar22[0xd],bVar23);
                      local_60 = CONCAT44(piVar22[0xb],(undefined4)local_60);
                      uVar9 = (**(code **)(lVar16 + 0x3b90))
                                        (lVar16 + 0x3b58,*(undefined4 *)(lVar16 + 0x3b34),
                                         *(undefined4 *)(lVar16 + 0x3b3c),0x20800aca,&local_60,8);
                      if (uVar9 == 0) {
                        if (uVar7 == 0) {
                          if ((char)piVar22[0xd] != '\0') {
                            *(undefined1 *)(piVar22 + 0xd) = 0;
                          }
                        }
                        else if ((char)piVar22[0xd] == '\0') {
                          *(undefined1 *)(piVar22 + 0xd) = 1;
                          piVar22[0xb] = local_60._4_4_;
                        }
                      }
                      else {
                        nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c"
                                     ,0xa46,"gsyncProgramMaster_P2060",4,
                                     "NVRM: Extdev control call to save/restore GPIO direction is failed!\n"
                                    );
                      }
                      iVar10 = gsyncReadSlaves_P2060(lVar16,lVar17);
                      if ((iVar10 != 0) &&
                         (uVar9 = gsyncProgramSlaves_P2060_isra_0
                                            (lVar16,*(undefined8 *)(param_2 + 0x40),iVar10),
                         uVar9 != 0)) {
                        nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c"
                                     ,0xa5b,"gsyncProgramMaster_P2060",4,
                                     "NVRM: Failed to program SLI slaves. Can not program Master.\n"
                                    );
                        return uVar9;
                      }
                    }
                  }
                  uVar8 = uVar8 + 1;
                  piVar22 = piVar22 + 0x29;
                } while (uVar8 != 4);
                if (uVar7 != 0) {
                  return uVar9;
                }
                if (3 < *(uint *)(lVar17 + 0x1bc)) {
                  return uVar9;
                }
                if (uVar2 <= *(uint *)(lVar17 + 0x1c0)) {
                  return uVar9;
                }
                uVar7 = gsyncResetFrameCountData_P2060(param_1,lVar17);
                return uVar9 | uVar7;
              }
            }
            else {
              bVar6 = ((byte)local_60 >> 6) << 4;
              bVar14 = local_69 & 0xcf;
              local_69 = bVar6 | bVar14;
              local_98 = writeregu008_extdeviceTargeted(param_1,lVar17,3,bVar6 | bVar14);
              if (local_98 != 0) {
                pcVar20 = "NVRM: Failed to write SYNC_SRC. Can not program Master.\n";
                uVar19 = 0x9aa;
                goto LAB_00315c89;
              }
              if ((bVar3 & 8) != 0) {
                local_69 = local_69 & 0xf7;
              }
              local_69 = local_69 | 1;
              local_98 = writeregu008_extdeviceTargeted(param_1,lVar17,3,local_69);
              if (local_98 == 0) {
                osDelay(200);
                *(char *)(lVar17 + 0x3c9 + (ulong)uVar21 * 0xa4) = param_7;
                if ((param_7 == '\0') && (iVar10 = *(int *)(lVar17 + 0x1c), iVar10 != 0x2061))
                goto LAB_0031620a;
                if (uVar2 != 0) goto LAB_00315d12;
                goto LAB_00315df2;
              }
            }
            pcVar20 = "NVRM: Failed to write I_AM_MSTR. Can not program Master.\n";
            uVar19 = 0x9c7;
LAB_00315c89:
            nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",uVar19,
                         "gsyncProgramMaster_P2060",4,pcVar20);
            return local_98;
          }
          uVar21 = uVar21 + 1;
          piVar12 = piVar12 + 0x29;
        } while (uVar21 != 4);
        nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x962,
                     "gsyncProgramMaster_P2060",4,
                     "NVRM: Failed to get Gpu location. Can not program Master.\n");
        uVar7 = 0xffff;
      }
      else {
        lVar13 = (ulong)uVar2 * 4;
        lVar16 = lVar13 + lVar17;
        lVar13 = lVar17 + 0x290 + lVar13;
        if (uVar2 != 0) {
          do {
            lVar17 = lVar16 + (ulong)uVar2 * -4;
            do {
              lVar11 = lVar17;
              if (*(int *)(lVar11 + 0x330) != 0) {
                *(undefined4 *)(lVar11 + 0x330) = 0;
                *(undefined4 *)(lVar11 + 0x350) = 0;
                *(undefined4 *)(lVar11 + 0x370) = 0;
              }
              lVar17 = lVar11 + 4;
            } while (lVar11 + 4 != lVar16);
            lVar16 = lVar11 + 0xa8;
          } while (lVar16 != lVar13);
          return 0;
        }
        do {
          lVar16 = lVar16 + 0xa4;
          uVar7 = 0;
        } while (lVar16 != lVar13);
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0xf3a,
                   "gsyncRefMaster_P2060",1,"NVRM: P2060 GPU can not be Framelock Master.\n");
LAB_00315a16:
      uVar7 = 0xffff;
    }
  }
  else {
    if (param_3 < 2) {
      uVar1 = *(undefined4 *)(lVar17 + 0x160);
      uVar7 = gsyncReadMaster_P2060(param_1,lVar17);
      if (param_3 == 1) {
        *(uint *)(lVar17 + 0x150) = uVar7;
      }
      *param_4 = uVar7;
      *param_5 = uVar1;
    }
    uVar7 = 0;
  }
  return uVar7;
}


// ===== 00316300 GetP2060MasterableGpu.isra.0 =====

long GetP2060MasterableGpu_isra_0(long param_1)

{
  char cVar1;
  long lVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_1 + 0x390);
  do {
    if (*piVar3 != -1) {
      lVar2 = gpumgrGetGpuFromId();
      if (lVar2 == 0) {
        nvAssertFailedNoLog("tempGpu",
                            "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x114d);
      }
      cVar1 = gsyncGpuCanBeMaster_P2060(lVar2,param_1);
      if (cVar1 != '\0') {
        return lVar2;
      }
    }
    piVar3 = piVar3 + 0x29;
    if (piVar3 == (int *)(param_1 + 0x620)) {
      return 0;
    }
  } while( true );
}


// ===== 00316380 gsyncSetSyncPolarity_P2060 =====

int gsyncSetSyncPolarity_P2060(undefined8 param_1,long param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  long lVar3;
  uint uVar4;
  byte local_29 [9];
  
  *(uint *)(param_2 + 0x138) = param_3;
  lVar3 = GetP2060MasterableGpu_isra_0(param_2);
  if (lVar3 == 0) {
    nvAssertFailedNoLog(&DAT_00d0f8e6,
                        "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x750);
    return 0xffff;
  }
  iVar1 = readregu008_extdeviceTargeted(lVar3,param_2,3,local_29);
  if ((iVar1 == 0) && (param_3 != (local_29[0] >> 1 & 3))) {
    uVar4 = param_3 * 2 & 6 | local_29[0] & 0xfffffff9;
    local_29[0] = (byte)uVar4;
    iVar2 = writeregu008_extdeviceTargeted(lVar3,param_2,3,uVar4);
    iVar1 = 100;
    if (9999 < *(uint *)(param_2 + 0x160)) {
      uVar4 = (uint)(1000 / ((ulong)*(uint *)(param_2 + 0x160) / 10000));
      if (uVar4 < 10) {
        uVar4 = 10;
      }
      iVar1 = uVar4 * 10;
    }
    osDelay(iVar1);
    return iVar2;
  }
  return iVar1;
}


// ===== 003164a0 extdevInit_P2060 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined1 extdevInit_P2060(long param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  byte bVar6;
  int *piVar7;
  undefined1 local_39;
  undefined1 local_38 [4];
  undefined4 local_34;
  undefined4 local_30;
  uint local_2c [3];
  
  lVar4 = g_pSys;
  piVar7 = (int *)(param_2 + 0x390);
  uVar3 = 0;
  while (*piVar7 != *(int *)(param_1 + 0x7ac)) {
    uVar1 = (int)uVar3 + 1;
    uVar3 = (ulong)uVar1;
    piVar7 = piVar7 + 0x29;
    if (uVar1 == 4) {
      return 0;
    }
  }
  if (*(char *)(param_2 + 0x394 + uVar3 * 0xa4) == '\0') {
    return 0;
  }
  local_2c[0] = local_2c[0] & 0xffffff00;
  iVar2 = readregu008_extdeviceTargeted(param_1,param_2,6,local_2c);
  if (iVar2 == 0) {
    bVar6 = (byte)local_2c[0] | 0x20;
    local_2c[0] = local_2c[0] | 0x20;
    iVar2 = writeregu008_extdeviceTargeted(param_1,param_2,6,bVar6);
    if (iVar2 == 0) {
      iVar2 = osReadRegistryDword(param_1,"QuadroSyncFirmwareRevisionCheckDisable",local_2c);
      if ((iVar2 == 0) && (local_2c[0] == 1)) {
        *(undefined1 *)(lVar4 + 0x81) = 1;
      }
      iVar2 = gsyncSetSyncPolarity_P2060(param_1,param_2,1);
      if (iVar2 == 0) {
        gpumgrGetGpuAttachInfo(local_38,&local_34);
        local_30 = 0;
        while (lVar4 = gpumgrGetNextGpu(local_34,&local_30), lVar4 != 0) {
          lVar5 = gsyncmgrGetGsync(lVar4);
          if ((lVar5 != 0) && (*(long *)(lVar5 + 0x40) != 0)) {
            local_39 = param_1 == lVar4;
            lVar5 = *(long *)(lVar4 + 0x1b80);
            iVar2 = (**(code **)(lVar4 + 0x3b90))
                              (lVar4 + 0x3b58,*(undefined4 *)(lVar4 + 0x3b34),
                               *(undefined4 *)(lVar4 + 0x3b3c),0x20800abe,&local_39,1);
            if (iVar2 == 0) {
              *(undefined1 *)(lVar5 + 0x35c) = 1;
            }
            else {
              nvDbg_Printf("src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x10e,
                           "_externalDeviceInit_P2060",4,
                           "NVRM: Extdev GPIO interrupt enable failed\n");
            }
          }
        }
        return 1;
      }
    }
  }
  return 0;
}


// ===== 00316670 gsyncSetUseHouse_P2060 =====

undefined8 gsyncSetUseHouse_P2060(undefined8 param_1,long param_2,int param_3)

{
  long lVar1;
  undefined8 uVar2;
  uint uVar3;
  byte local_29 [9];
  
  *(int *)(param_2 + 0x14c) = param_3;
  lVar1 = GetP2060MasterableGpu_isra_0(param_2);
  if (lVar1 == 0) {
    nvAssertFailedNoLog(&DAT_00d0f8e6,
                        "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x719);
    return 0xffff;
  }
  uVar2 = readregu008_extdeviceTargeted(lVar1,param_2,3,local_29);
  if ((int)uVar2 != 0) {
    return uVar2;
  }
  uVar3 = (uint)local_29[0];
  local_29[0] = (byte)(uVar3 & 0x7f) | (byte)(param_3 << 7);
  uVar2 = writeregu008_extdeviceTargeted(lVar1,param_2,3,uVar3 & 0x7f | param_3 << 7 & 0xffU);
  return uVar2;
}


// ===== 00316730 gsyncGetInterlaceMode_P2060 =====

undefined8 gsyncGetInterlaceMode_P2060(undefined8 param_1,long param_2,uint *param_3)

{
  long lVar1;
  undefined8 uVar2;
  uint uVar3;
  byte local_19;
  
  lVar1 = GetP2060MasterableGpu_isra_0(param_2);
  if (lVar1 != 0) {
    uVar2 = readregu008_extdeviceTargeted(lVar1,param_2,3,&local_19);
    if ((int)uVar2 == 0) {
      uVar3 = local_19 >> 6 & 1;
      *param_3 = uVar3;
    }
    else {
      uVar3 = *param_3;
    }
    *(uint *)(param_2 + 0x15c) = uVar3;
    return uVar2;
  }
  nvAssertFailedNoLog(&DAT_00d0f8e6,"src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",
                      0x6fa);
  return 0xffff;
}


// ===== 003167c0 gsyncSetInterlaceMode_P2060 =====

undefined8 gsyncSetInterlaceMode_P2060(undefined8 param_1,long param_2,uint param_3)

{
  long lVar1;
  undefined8 uVar2;
  uint uVar3;
  byte local_29 [9];
  
  *(uint *)(param_2 + 0x15c) = param_3;
  lVar1 = GetP2060MasterableGpu_isra_0(param_2);
  if (lVar1 == 0) {
    nvAssertFailedNoLog(&DAT_00d0f8e6,
                        "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x6e0);
    return 0xffff;
  }
  uVar2 = readregu008_extdeviceTargeted(lVar1,param_2,3,local_29);
  if ((int)uVar2 != 0) {
    return uVar2;
  }
  uVar3 = local_29[0] & 0xffffffbf | (param_3 & 1) << 6;
  local_29[0] = (byte)uVar3;
  uVar2 = writeregu008_extdeviceTargeted(lVar1,param_2,3,uVar3);
  return uVar2;
}


// ===== 00316890 gsyncSetEmitTestSignal_P2060 =====

uint gsyncSetEmitTestSignal_P2060(undefined8 param_1,long param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  int iVar5;
  byte local_29;
  
  uVar2 = 0x26;
  *(int *)(param_2 + 0x158) = param_3;
  cVar1 = gsyncIsFrameLockMaster_P2060(param_2);
  if (cVar1 != '\0') {
    lVar4 = GetP2060MasterableGpu_isra_0(param_2);
    if (lVar4 == 0) {
      uVar2 = 0xffff;
      nvAssertFailedNoLog(&DAT_00d0f8e6,
                          "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x67f);
    }
    else {
      uVar2 = readregu008_extdeviceTargeted(lVar4,param_2,3,&local_29);
      if (param_3 == 0) {
        *(undefined1 *)(param_2 + 0x1c8) = 1;
        local_29 = local_29 & 0xf7;
        uVar3 = gsyncResetFrameCountData_P2060(lVar4,param_2);
        uVar2 = uVar2 | uVar3;
      }
      else {
        local_29 = local_29 | 8;
      }
      uVar3 = writeregu008_extdeviceTargeted(lVar4,param_2,3,local_29);
      uVar2 = uVar2 | uVar3;
      if (*(uint *)(param_2 + 0x160) - 10000 < 10000000) {
        uVar3 = (uint)(1000 / ((ulong)*(uint *)(param_2 + 0x160) / 10000));
        if (0x23 < uVar3) {
          uVar3 = 0x23;
        }
        iVar5 = uVar3 * 2;
      }
      else {
        nvAssertFailedNoLog("refreshTime != 0",
                            "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x6ad);
        iVar5 = 0;
      }
      osDelay(iVar5);
    }
  }
  return uVar2;
}


// ===== 003169f0 gsyncSupportsLargeSyncSkew_P2060 =====

bool gsyncSupportsLargeSyncSkew_P2060(long param_1)

{
  if (*(int *)(param_1 + 0x1c) == 0x2061) {
    return true;
  }
  if (*(int *)(param_1 + 0x1c) == 0x2060) {
    return 2 < *(uint *)(param_1 + 0x20);
  }
  nvAssertFailedNoLog("pExtdev->deviceId == DAC_EXTERNAL_DEVICE_P2060",
                      "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x152a);
  return 2 < *(uint *)(param_1 + 0x20);
}


// ===== 00316a60 gsyncGetMulDiv_P2060 =====

int gsyncGetMulDiv_P2060(undefined8 param_1,long param_2,char *param_3)

{
  int iVar1;
  byte local_9;
  
  if (param_3 == (char *)0x0) {
    nvAssertFailedNoLog("pMulDivSettings != NULL",
                        "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x15a7);
    return 0x1f;
  }
  if ((*(int *)(param_2 + 0x1c) == 0x2061) &&
     ((2 < *(uint *)(param_2 + 0x20) ||
      ((*(uint *)(param_2 + 0x20) == 2 && (3 < *(byte *)(param_2 + 0x24))))))) {
    iVar1 = readregu008_extdeviceTargeted(param_1,param_2,0x2f,&local_9);
    if (iVar1 == 0) {
      param_3[1] = local_9 >> 7;
      *param_3 = (local_9 & 7) + 1;
      portMemCopy(param_2 + 0x184,4,param_3,4);
      return 0;
    }
    nvCheckOkFailedNoLog
              (1,iVar1,
               "readregu008_extdeviceTargeted(pGpu, pExtDev, NV_P2060_MULTIPLIER_DIVIDER, &reg)",
               "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x15aa);
  }
  else {
    nvCheckFailedNoLog(1,"supportsMulDiv(pExtDev)",
                       "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x15a8);
    iVar1 = 0x56;
  }
  return iVar1;
}


// ===== 00316b90 gsyncSetMulDiv_P2060 =====

int gsyncSetMulDiv_P2060(undefined8 param_1,long param_2,char *param_3)

{
  byte bVar1;
  int iVar2;
  long lVar3;
  
  if (param_3 == (char *)0x0) {
    nvAssertFailedNoLog("pMulDivSettings != NULL",
                        "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x15c6);
    return 0x1f;
  }
  if ((*(int *)(param_2 + 0x1c) == 0x2061) &&
     ((2 < *(uint *)(param_2 + 0x20) ||
      ((*(uint *)(param_2 + 0x20) == 2 && (3 < *(byte *)(param_2 + 0x24))))))) {
    lVar3 = GetP2060MasterableGpu_isra_0(param_2);
    if (lVar3 == 0) {
      nvAssertFailedNoLog("pGpu != NULL",
                          "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x15c9);
      return 0xffff;
    }
    bVar1 = 0;
    if (param_3[1] != '\0') {
      if (param_3[1] != '\x01') {
        return 0x3b;
      }
      bVar1 = 0x80;
    }
    if (7 < (byte)(*param_3 - 1U)) {
      return 0x3b;
    }
    iVar2 = writeregu008_extdeviceTargeted(lVar3,param_2,0x2f,*param_3 - 1U | bVar1);
    if (iVar2 == 0) {
      portMemCopy(param_2 + 0x184,4,param_3,4);
      iVar2 = 0;
    }
    else {
      nvCheckOkFailedNoLog
                (1,iVar2,
                 "writeregu008_extdeviceTargeted(pGpu, pExtDev, NV_P2060_MULTIPLIER_DIVIDER, reg)",
                 "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x15e5);
    }
  }
  else {
    nvCheckFailedNoLog(1,"supportsMulDiv(pExtDev)",
                       "src/kernel/gpu/external_device/arch/kepler/kern_gsync_p2060.c",0x15c7);
    iVar2 = 0x56;
  }
  return iVar2;
}


// ===== 00316d20 gsyncGetHouseSyncMode_P2061 =====

undefined4 gsyncGetHouseSyncMode_P2061(undefined8 param_1,undefined8 param_2,byte *param_3)

{
  undefined4 uVar1;
  byte local_19 [9];
  
  uVar1 = readregu008_extdeviceTargeted(param_1,param_2,6,local_19);
  *param_3 = local_19[0] >> 6 & 1;
  return uVar1;
}


// ===== 00316d60 gsyncSetHouseSyncMode_P2061 =====

uint gsyncSetHouseSyncMode_P2061(undefined8 param_1,undefined8 param_2,byte param_3)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  byte local_2a;
  byte local_29 [9];
  
  if (param_3 < 2) {
    readregu008_extdeviceTargeted(param_1,param_2,1,&local_2a);
    uVar1 = readregu008_extdeviceTargeted(param_1,param_2,6,local_29);
    if ((((local_29[0] & 0x40) == 0) && ((local_2a & 0x30) != 0)) && ((param_3 & 1) != 0)) {
      uVar1 = 0x40;
    }
    else {
      bVar3 = local_29[0] & 0xbf;
      local_29[0] = bVar3 | param_3 << 6;
      uVar2 = writeregu008_extdeviceTargeted(param_1,param_2,6,bVar3 | param_3 << 6);
      uVar1 = uVar1 | uVar2;
    }
    return uVar1;
  }
  return 0x1f;
}


// ===== 00316e10 gsyncGetCplStatus_P2061 =====

void gsyncGetCplStatus_P2061(undefined8 param_1,undefined8 param_2,int param_3,uint *param_4)

{
  int iVar1;
  byte local_1a;
  char local_19;
  
  if (param_3 != 0xc) {
    gsyncGetCplStatus_P2060();
    return;
  }
  iVar1 = readregu008_extdeviceTargeted(param_1,param_2,1,&local_1a);
  if (iVar1 == 0) {
    iVar1 = readregu008_extdeviceTargeted(param_1,param_2,0x2e);
    if (iVar1 == 0) {
      if ((~local_1a & 3) == 0) {
        *param_4 = (uint)~(int)local_19 >> 0x1f;
      }
      else {
        *param_4 = 0;
      }
    }
  }
  return;
}


// ===== 00316e90 gsyncSetSyncSkew_P2061_V204 =====

ulong gsyncSetSyncSkew_P2061_V204(undefined8 param_1,long param_2,uint param_3)

{
  ulong uVar1;
  undefined8 uVar2;
  ulong uVar3;
  char *pcVar4;
  
  if (0xffffff < param_3) {
    nvCheckFailedNoLog(1,"syncSkew <= NV_P2061_V204_SYNC_SKEW_MAX_UNITS",
                       "src/kernel/gpu/external_device/arch/pascal/kern_gsync_p2061.c",0x9b);
    return 0x1f;
  }
  *(uint *)(param_2 + 400) = param_3;
  uVar3 = ((ulong)param_3 * 70000000) / 0x48c2739;
  *(uint *)(param_2 + 0x13c) = (uint)uVar3;
  uVar1 = writeregu008_extdeviceTargeted(param_1,param_2,8,uVar3 & 0xff);
  uVar2 = 0xb3;
  pcVar4 = 
  "writeregu008_extdeviceTargeted(pGpu, pExtDev, (NvU8)NV_P2060_SYNC_SKEW_LOW, syncSkew & DRF_MASK(NV_P2060_SYNC_SKEW_LOW_VAL))"
  ;
  if ((int)uVar1 == 0) {
    uVar1 = writeregu008_extdeviceTargeted(param_1,param_2,9,uVar3 >> 8 & 0xff);
    uVar2 = 0xb6;
    pcVar4 = 
    "writeregu008_extdeviceTargeted(pGpu, pExtDev, (NvU8)NV_P2060_SYNC_SKEW_HIGH, (syncSkew >> 8) & DRF_MASK(NV_P2060_SYNC_SKEW_HIGH_VAL))"
    ;
    if ((int)uVar1 == 0) {
      uVar1 = writeregu008_extdeviceTargeted(param_1,param_2,0x35,(uint)uVar3 >> 0x10 & 0xff);
      if ((int)uVar1 == 0) {
        return uVar1;
      }
      uVar2 = 0xb9;
      pcVar4 = 
      "writeregu008_extdeviceTargeted(pGpu, pExtDev, (NvU8)NV_P2060_SYNC_SKEW_UPPER, (syncSkew >> 16) & DRF_MASK(NV_P2060_SYNC_SKEW_UPPER_VAL))"
      ;
    }
  }
  nvAssertOkFailedNoLog
            (uVar1 & 0xffffffff,pcVar4,
             "src/kernel/gpu/external_device/arch/pascal/kern_gsync_p2061.c",uVar2);
  return uVar1 & 0xffffffff;
}


// ===== 00316fc0 gsyncGetSyncSkew_P2061_V204 =====

int gsyncGetSyncSkew_P2061_V204(undefined8 param_1,long param_2,int *param_3)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  ulong uVar7;
  byte local_39 [9];
  
  *param_3 = 0;
  iVar4 = readregu008_extdeviceTargeted(param_1,param_2,8,local_39);
  bVar2 = local_39[0];
  if (iVar4 == 0) {
    iVar4 = readregu008_extdeviceTargeted(param_1,param_2,9,local_39);
    bVar3 = local_39[0];
    if (iVar4 == 0) {
      iVar4 = readregu008_extdeviceTargeted(param_1,param_2,0x35,local_39);
      if (iVar4 == 0) {
        uVar5 = (uint)local_39[0] << 0x10 | (uint)bVar3 << 8 | (uint)bVar2;
        *(uint *)(param_2 + 0x13c) = uVar5;
        uVar7 = (ulong)uVar5 * 0x48c2739;
        if (uVar7 < 0x42c1d80000000) {
          iVar6 = (int)(uVar7 / 70000000);
        }
        else {
          nvCheckFailedNoLog(1,"syncSkew <= NV_P2061_V204_SYNC_SKEW_MAX_UNITS",
                             "src/kernel/gpu/external_device/arch/pascal/kern_gsync_p2061.c",0xe9);
          iVar6 = 0xffffff;
        }
        iVar1 = *(int *)(param_2 + 400);
        if ((iVar1 != 0x1000000) && ((iVar6 - iVar1) + 2U < 5)) {
          iVar6 = iVar1;
        }
        *param_3 = iVar6;
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar4,
                   "readregu008_extdeviceTargeted(pGpu, pExtDev, (NvU8)NV_P2060_SYNC_SKEW_UPPER, &data)"
                   ,"src/kernel/gpu/external_device/arch/pascal/kern_gsync_p2061.c",0xd6);
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar4,
                 "readregu008_extdeviceTargeted(pGpu, pExtDev, (NvU8)NV_P2060_SYNC_SKEW_HIGH, &data)"
                 ,"src/kernel/gpu/external_device/arch/pascal/kern_gsync_p2061.c",0xd3);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar4,
               "readregu008_extdeviceTargeted(pGpu, pExtDev, (NvU8)NV_P2060_SYNC_SKEW_LOW, &data)",
               "src/kernel/gpu/external_device/arch/pascal/kern_gsync_p2061.c",0xd0);
  }
  return iVar4;
}


// ===== 00317180 gsyncSetRasterSyncDecodeMode_P2061_V300 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong gsyncSetRasterSyncDecodeMode_P2061_V300(undefined8 param_1,long param_2,undefined8 param_3)

{
  uint uVar1;
  ulong uVar2;
  byte bVar3;
  byte local_1d;
  int local_1c;
  
  uVar1 = (**(code **)(param_2 + 0x3b90))
                    (param_2 + 0x3b58,*(undefined4 *)(param_2 + 0x3b34),
                     *(undefined4 *)(param_2 + 0x3b3c),0x20800a14,&local_1c,4);
  if (uVar1 != 0) {
    nvAssertOkFailedNoLog
              (uVar1,
               "pRmApi->Control(pRmApi, pServerGpu->hInternalClient, pServerGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_GSYNC_GET_RASTER_SYNC_DECODE_MODE, &rasterSyncDecodeModeParams, sizeof(rasterSyncDecodeModeParams))"
               ,"src/kernel/gpu/external_device/arch/pascal/kern_gsync_p2061.c",0x119);
    return (ulong)uVar1;
  }
  uVar2 = readregu008_extdeviceTargeted(param_1,param_3,0x15,&local_1d);
  if ((int)uVar2 == 0) {
    if (local_1c == 0) {
      bVar3 = local_1d & 0xfc;
    }
    else {
      if (local_1c != 1) {
        return 0x3b;
      }
      bVar3 = local_1d & 0xfc | 1;
    }
    if (bVar3 != local_1d) {
      local_1d = bVar3;
      uVar2 = writeregu008_extdeviceTargeted(param_1,param_3,0x15,bVar3);
      if ((int)uVar2 != 0) {
        nvAssertOkFailedNoLog
                  (uVar2 & 0xffffffff,
                   "writeregu008_extdeviceTargeted(pGpu, pExtDev, NV_P2061_CONTROL5, data)",
                   "src/kernel/gpu/external_device/arch/pascal/kern_gsync_p2061.c",0x133);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
  }
  else {
    nvAssertOkFailedNoLog
              (uVar2 & 0xffffffff,
               "readregu008_extdeviceTargeted(pGpu, pExtDev, (NvU8)NV_P2061_CONTROL5, &data)",
               "src/kernel/gpu/external_device/arch/pascal/kern_gsync_p2061.c",0x11d);
    uVar2 = uVar2 & 0xffffffff;
  }
  return uVar2;
}


// ===== 003172d0 gsyncGetVRR_P2061_V300 =====

int gsyncGetVRR_P2061_V300(undefined8 param_1,undefined8 param_2,uint *param_3)

{
  int iVar1;
  byte local_19 [9];
  
  iVar1 = readregu008_extdeviceTargeted(param_1,param_2,0x15,local_19);
  if (iVar1 == 0) {
    *param_3 = local_19[0] >> 2 & 1;
    return 0;
  }
  nvAssertOkFailedNoLog
            (iVar1,"readregu008_extdeviceTargeted(pGpu, pExtDev, (NvU8)NV_P2061_CONTROL5, &data)",
             "src/kernel/gpu/external_device/arch/pascal/kern_gsync_p2061.c",0x145);
  return iVar1;
}


// ===== 00317340 gsyncSetVRR_P2061_V300 =====

ulong gsyncSetVRR_P2061_V300(undefined8 param_1,undefined8 param_2,int param_3)

{
  ulong uVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte local_29 [9];
  
  uVar1 = readregu008_extdeviceTargeted(param_1,param_2,0x15,local_29);
  if ((int)uVar1 != 0) {
    nvAssertOkFailedNoLog
              (uVar1 & 0xffffffff,
               "readregu008_extdeviceTargeted(pGpu, pExtDev, (NvU8)NV_P2061_CONTROL5, &data)",
               "src/kernel/gpu/external_device/arch/pascal/kern_gsync_p2061.c",0x15b);
    return uVar1 & 0xffffffff;
  }
  if (param_3 == 0) {
    bVar4 = 0;
  }
  else {
    bVar4 = 4;
    if (param_3 != 1) {
      return 0x3b;
    }
  }
  bVar2 = local_29[0] & 0xfb;
  bVar3 = bVar2 | bVar4;
  if (bVar3 != local_29[0]) {
    local_29[0] = bVar3;
    uVar1 = writeregu008_extdeviceTargeted(param_1,param_2,0x15,bVar2 | bVar4);
    if ((int)uVar1 != 0) {
      nvAssertOkFailedNoLog
                (uVar1 & 0xffffffff,
                 "writeregu008_extdeviceTargeted(pGpu, pExtDev, NV_P2061_CONTROL5, data)",
                 "src/kernel/gpu/external_device/arch/pascal/kern_gsync_p2061.c",0x16d);
      uVar1 = uVar1 & 0xffffffff;
    }
  }
  return uVar1;
}


// ===== 00317430 gsyncNullGpuCanBeMaster =====

undefined8 gsyncNullGpuCanBeMaster(void)

{
  return 0;
}


// ===== 00317440 gsyncNullOptimizeTimingParameters =====

undefined8 gsyncNullOptimizeTimingParameters(void)

{
  return 0xffff;
}


// ===== 00317450 gsyncNullGetStereoLockMode =====

undefined8 gsyncNullGetStereoLockMode(void)

{
  return 0xffff;
}


// ===== 00317460 gsyncNullSetStereoLockMode =====

undefined8 gsyncNullSetStereoLockMode(void)

{
  return 0xffff;
}


// ===== 00317470 gsyncNullRefSwapBarrier =====

undefined8 gsyncNullRefSwapBarrier(void)

{
  return 0xffff;
}


// ===== 00317480 gsyncNullRefSignal =====

undefined8 gsyncNullRefSignal(void)

{
  return 0xffff;
}


// ===== 00317490 gsyncNullRefMaster =====

undefined8 gsyncNullRefMaster(void)

{
  return 0xffff;
}


// ===== 003174a0 gsyncNullRefSlaves =====

undefined8 gsyncNullRefSlaves(void)

{
  return 0xffff;
}


// ===== 003174b0 gsyncNullSetHouseSyncMode =====

undefined8 gsyncNullSetHouseSyncMode(void)

{
  return 0xffff;
}


// ===== 003174c0 gsyncNullGetMulDiv =====

undefined8 gsyncNullGetMulDiv(void)

{
  return 0x56;
}


// ===== 003174d0 gsyncNullSetVRR =====

undefined8 gsyncNullSetVRR(void)

{
  return 0x56;
}


// ===== 003174e0 gsyncNullSetRasterSyncDecodeMode =====

undefined8 gsyncNullSetRasterSyncDecodeMode(void)

{
  return 0;
}


// ===== 003174f0 gsyncGetMasterableGpu =====

undefined8 gsyncGetMasterableGpu(long param_1)

{
  uint uVar1;
  ulong uVar2;
  undefined8 uVar3;
  int *piVar4;
  
  if (*(uint *)(param_1 + 4) != 0) {
    piVar4 = (int *)(param_1 + 0x10);
    uVar2 = 0;
    do {
      if (((*(byte *)(param_1 + 0x4a) >> ((uint)uVar2 & 0x1f) & 1) != 0) && (*piVar4 != 0)) {
        uVar3 = gpumgrGetGpuFromId(*(undefined4 *)(param_1 + 0xc + uVar2 * 0xc));
        return uVar3;
      }
      uVar1 = (uint)uVar2 + 1;
      uVar2 = (ulong)uVar1;
      piVar4 = piVar4 + 3;
    } while (*(uint *)(param_1 + 4) != uVar1);
  }
  nvDbg_Printf("src/kernel/gpu/external_device/gsync.c",0xba,"gsyncGetMasterableGpu",4,
               "NVRM: Invalid gsync state\n");
  return 0;
}


// ===== 00317570 gsyncSetupNullProvider.isra.0 =====

void gsyncSetupNullProvider_isra_0(long param_1,uint param_2)

{
  long lVar1;
  
  lVar1 = (ulong)param_2 * 0x178;
  *(undefined4 *)(param_1 + 0x58 + lVar1) = 0;
  *(code **)(param_1 + 0xa0 + lVar1) = gsyncNullGpuCanBeMaster;
  *(code **)(param_1 + 0x168 + lVar1) = gsyncNullOptimizeTimingParameters;
  *(code **)(param_1 + 0x170 + lVar1) = gsyncNullGetStereoLockMode;
  *(code **)(param_1 + 0x178 + lVar1) = gsyncNullSetStereoLockMode;
  *(code **)(param_1 + 0xa8 + lVar1) = gsyncNullGetSyncPolarity;
  *(code **)(param_1 + 0xb0 + lVar1) = gsyncNullSetSyncPolarity;
  *(code **)(param_1 + 0xb8 + lVar1) = gsyncNullGetVideoMode;
  *(code **)(param_1 + 0xc0 + lVar1) = gsyncNullSetVideoMode;
  *(code **)(param_1 + 200 + lVar1) = gsyncNullGetNSync;
  *(code **)(param_1 + 0xd0 + lVar1) = gsyncNullSetNSync;
  *(code **)(param_1 + 0xd8 + lVar1) = gsyncNullGetSyncSkew;
  *(code **)(param_1 + 0xe0 + lVar1) = gsyncNullSetSyncSkew;
  *(code **)(param_1 + 0xe8 + lVar1) = gsyncNullGetUseHouse;
  *(code **)(param_1 + 0xf0 + lVar1) = gsyncNullSetUseHouse;
  *(code **)(param_1 + 0xf8 + lVar1) = gsyncNullGetSyncStartDelay;
  *(code **)(param_1 + 0x100 + lVar1) = gsyncNullSetSyncStartDelay;
  *(code **)(param_1 + 0x108 + lVar1) = gsyncNullGetEmitTestSignal;
  *(code **)(param_1 + 0x110 + lVar1) = gsyncNullSetEmitTestSignal;
  *(code **)(param_1 + 0x118 + lVar1) = gsyncNullGetInterlaceMode;
  *(code **)(param_1 + 0x120 + lVar1) = gsyncNullSetInterlaceMode;
  *(code **)(param_1 + 0x128 + lVar1) = gsyncNullRefSwapBarrier;
  *(code **)(param_1 + 0x130 + lVar1) = gsyncNullRefSignal;
  *(code **)(param_1 + 0x138 + lVar1) = gsyncNullRefMaster;
  *(code **)(param_1 + 0x140 + lVar1) = gsyncNullRefSlaves;
  *(code **)(param_1 + 0x148 + lVar1) = gsyncNullGetCplStatus;
  *(code **)(param_1 + 0x150 + lVar1) = gsyncNullSetWatchdog;
  *(code **)(param_1 + 0x158 + lVar1) = gsyncNullGetRevision;
  *(code **)(param_1 + 0x180 + lVar1) = gsyncNullSetMosaic;
  *(code **)(param_1 + 0x188 + lVar1) = gsyncNullConfigFlashGsync;
  *(code **)(param_1 + 400 + lVar1) = gsyncNullGetHouseSyncMode;
  *(code **)(param_1 + 0x198 + lVar1) = gsyncNullSetHouseSyncMode;
  *(code **)(param_1 + 0x1a0 + lVar1) = gsyncNullGetMulDiv;
  *(code **)(param_1 + 0x1a8 + lVar1) = gsyncNullSetMulDiv;
  *(code **)(param_1 + 0x1b0 + lVar1) = gsyncNullGetVRR;
  *(code **)(param_1 + 0x1b8 + lVar1) = gsyncNullSetVRR;
  *(code **)(param_1 + 0x1c0 + lVar1) = gsyncNullSetRasterSyncDecodeMode;
  return;
}


// ===== 00317740 gsyncNullGetCplStatus =====

undefined8 gsyncNullGetCplStatus(void)

{
  return 0xffff;
}


// ===== 00317750 gsyncNullGetSyncPolarity =====

undefined8 gsyncNullGetSyncPolarity(void)

{
  return 0xffff;
}


// ===== 00317760 gsyncNullGetVideoMode =====

undefined8 gsyncNullGetVideoMode(void)

{
  return 0xffff;
}


// ===== 00317770 gsyncNullGetNSync =====

undefined8 gsyncNullGetNSync(void)

{
  return 0xffff;
}


// ===== 00317780 gsyncNullGetSyncSkew =====

undefined8 gsyncNullGetSyncSkew(void)

{
  return 0xffff;
}


// ===== 00317790 gsyncNullGetUseHouse =====

undefined8 gsyncNullGetUseHouse(void)

{
  return 0xffff;
}


// ===== 003177a0 gsyncNullGetSyncStartDelay =====

undefined8 gsyncNullGetSyncStartDelay(void)

{
  return 0xffff;
}


// ===== 003177b0 gsyncNullGetEmitTestSignal =====

undefined8 gsyncNullGetEmitTestSignal(void)

{
  return 0xffff;
}


// ===== 003177c0 gsyncNullGetInterlaceMode =====

undefined8 gsyncNullGetInterlaceMode(void)

{
  return 0xffff;
}


// ===== 003177d0 gsyncNullGetRevision =====

undefined8 gsyncNullGetRevision(void)

{
  return 0xffff;
}


// ===== 003177e0 gsyncNullSetMosaic =====

undefined8 gsyncNullSetMosaic(void)

{
  return 0xffff;
}


// ===== 003177f0 gsyncNullGetHouseSyncMode =====

undefined8 gsyncNullGetHouseSyncMode(void)

{
  return 0xffff;
}


// ===== 00317800 gsyncNullSetSyncPolarity =====

undefined8 gsyncNullSetSyncPolarity(void)

{
  return 0xffff;
}


// ===== 00317810 gsyncNullSetVideoMode =====

undefined8 gsyncNullSetVideoMode(void)

{
  return 0xffff;
}


// ===== 00317820 gsyncNullSetNSync =====

undefined8 gsyncNullSetNSync(void)

{
  return 0xffff;
}


// ===== 00317830 gsyncNullSetSyncSkew =====

undefined8 gsyncNullSetSyncSkew(void)

{
  return 0xffff;
}


// ===== 00317840 gsyncNullSetUseHouse =====

undefined8 gsyncNullSetUseHouse(void)

{
  return 0xffff;
}


// ===== 00317850 gsyncNullSetSyncStartDelay =====

undefined8 gsyncNullSetSyncStartDelay(void)

{
  return 0xffff;
}


// ===== 00317860 gsyncNullSetEmitTestSignal =====

undefined8 gsyncNullSetEmitTestSignal(void)

{
  return 0xffff;
}


// ===== 00317870 gsyncNullSetInterlaceMode =====

undefined8 gsyncNullSetInterlaceMode(void)

{
  return 0xffff;
}


// ===== 00317880 gsyncNullSetWatchdog =====

undefined8 gsyncNullSetWatchdog(void)

{
  return 0xffff;
}


// ===== 00317890 gsyncNullConfigFlashGsync =====

undefined8 gsyncNullConfigFlashGsync(void)

{
  return 0xffff;
}


// ===== 003178a0 gsyncNullSetMulDiv =====

undefined8 gsyncNullSetMulDiv(void)

{
  return 0x56;
}


// ===== 003178b0 gsyncNullGetVRR =====

undefined8 gsyncNullGetVRR(void)

{
  return 0x56;
}


// ===== 003178c0 gsyncmgrConstruct_IMPL =====

undefined8 gsyncmgrConstruct_IMPL(long param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  nvDbg_Printf("src/kernel/gpu/external_device/gsync.c",0x77,"gsyncmgrConstruct_IMPL",1,"NVRM: \n");
  *(undefined4 *)(param_1 + 0x48) = 0;
  puVar1 = (undefined4 *)(param_1 + 0x50);
  do {
    portMemSet(puVar1,0,0x178);
    iVar2 = iVar2 + 1;
    gsyncSetupNullProvider_isra_0(param_1);
    *(undefined2 *)(puVar1 + 0x12) = 1;
    *puVar1 = 0xffffffff;
    puVar1 = puVar1 + 0x5e;
  } while (iVar2 != 4);
  return 0;
}


// ===== 00317960 gsyncmgrDestruct_IMPL =====

void gsyncmgrDestruct_IMPL(long param_1)

{
  long lVar1;
  long lVar2;
  
  nvDbg_Printf("src/kernel/gpu/external_device/gsync.c",0x8f,"gsyncmgrDestruct_IMPL",1,"NVRM: \n");
  lVar1 = param_1 + 0x50;
  do {
    lVar2 = lVar1 + 0x178;
    portMemSet(lVar1,0,0x178);
    lVar1 = lVar2;
  } while (lVar2 != param_1 + 0x630);
  return;
}


// ===== 003179c0 gsyncGetMasterableGpuByInstance =====

undefined8 gsyncGetMasterableGpuByInstance(uint param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  if (param_1 < 4) {
    lVar1 = *(long *)(g_pSys + 0x1e8);
    if (*(int *)(lVar1 + 0x54 + (ulong)param_1 * 0x178) == 0) {
      nvAssertFailedNoLog("pGsyncMgr->gsyncTable[gsyncInst].gpuCount > 0",
                          "src/kernel/gpu/external_device/gsync.c",0xa7);
    }
    uVar2 = gsyncGetMasterableGpu(lVar1 + 0x50 + (ulong)param_1 * 0x178);
    return uVar2;
  }
  return 0;
}


// ===== 00317a40 gsyncAttachGpu =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong gsyncAttachGpu(long param_1,long param_2,undefined4 param_3,long param_4,int param_5)

{
  long lVar1;
  long lVar2;
  char cVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  long *plVar9;
  int *piVar10;
  undefined4 uVar11;
  
  lVar2 = g_pSys;
  lVar6 = *(long *)(g_pSys + 0x1e8);
  cVar3 = rmGpuLockIsOwner();
  if (cVar3 == '\0') {
    nvAssertFailedNoLog("rmGpuLockIsOwner()","src/kernel/gpu/external_device/gsync.c",0x152);
  }
  lVar8 = 0;
  do {
    uVar4 = *(uint *)(lVar6 + 0x54 + lVar8);
    if (uVar4 != 0) {
      lVar5 = lVar6 + lVar8;
      lVar1 = lVar5 + (ulong)uVar4 * 0xc;
      do {
        if (*(int *)(lVar5 + 0x5c) == *(int *)(param_2 + 0x7ac)) {
          nvDbg_Printf("src/kernel/gpu/external_device/gsync.c",0x15b,"gsyncAttachGpu",4,
                       "NVRM: gpu is %d already attached!\n");
          return 0x1f;
        }
        lVar5 = lVar5 + 0xc;
      } while (lVar5 != lVar1);
    }
    lVar8 = lVar8 + 0x178;
  } while (lVar8 != 0x5e0);
  plVar9 = (long *)(lVar6 + 0x90);
  uVar4 = 0;
  do {
    if (*plVar9 == param_1) {
      uVar7 = (ulong)uVar4;
      uVar4 = *(uint *)(lVar6 + 0x54 + uVar7 * 0x178);
      if (uVar4 != 4) goto LAB_00317b93;
      goto LAB_00317b50;
    }
    uVar4 = uVar4 + 1;
    plVar9 = plVar9 + 0x2f;
  } while (uVar4 != 4);
  piVar10 = (int *)(lVar6 + 0x54);
  uVar4 = 0;
  do {
    if (*piVar10 == 0) {
      *(int *)(lVar6 + 0x48) = *(int *)(lVar6 + 0x48) + 1;
      uVar7 = (ulong)uVar4;
      uVar4 = 0;
LAB_00317b93:
      *(long *)(lVar6 + 0x90 + uVar7 * 0x178) = param_1;
      uVar11 = *(undefined4 *)(param_2 + 0x7ac);
      lVar8 = uVar7 * 0x178 + (ulong)uVar4 * 0xc;
      *(undefined4 *)(lVar6 + 0x60 + lVar8) = param_3;
      *(undefined4 *)(lVar6 + 0x5c + lVar8) = uVar11;
      uVar11 = 0xffffffff;
      if (param_4 != 0) {
        uVar11 = *(undefined4 *)(param_4 + 0x7ac);
      }
      lVar8 = uVar7 * 0x178;
      *(undefined4 *)(lVar6 + 100 + lVar8 + (ulong)uVar4 * 0xc) = uVar11;
      if (*(int *)(lVar6 + 0x50 + lVar8) == -1) {
        *(undefined4 *)(lVar6 + 0x50 + lVar8) = *(undefined4 *)(param_2 + 0x7ac);
      }
      lVar8 = uVar7 * 0x178 + lVar6;
      *(uint *)(lVar8 + 0x54) = uVar4 + 1;
      *(undefined1 *)(lVar2 + 0x69) = 1;
      if (param_5 == 0x2060) {
        lVar2 = *(long *)(lVar8 + 0x90);
        *(undefined1 *)(lVar8 + 0x9a) = 0xf;
        *(undefined4 *)(lVar8 + 0x58) = 4;
        *(code **)(lVar8 + 0xa0) = gsyncGpuCanBeMaster_P2060;
        *(code **)(lVar8 + 0x168) = gsyncOptimizeTimingParameters_P2060;
        *(code **)(lVar8 + 0x130) = gsyncRefSignal_P2060;
        *(code **)(lVar8 + 0x138) = gsyncRefMaster_P2060;
        *(code **)(lVar8 + 0x140) = gsyncRefSlaves_P2060;
        *(code **)(lVar8 + 0x148) = gsyncGetCplStatus_P2060;
        *(code **)(lVar8 + 0x150) = gsyncSetWatchdog_P2060;
        *(code **)(lVar8 + 0x158) = gsyncGetRevision_P2060;
        *(code **)(lVar8 + 0xe8) = gsyncGetUseHouse_P2060;
        *(code **)(lVar8 + 0xf0) = gsyncSetUseHouse_P2060;
        *(code **)(lVar8 + 0xa8) = gsyncGetSyncPolarity_P2060;
        *(code **)(lVar8 + 0xb0) = gsyncSetSyncPolarity_P2060;
        *(code **)(lVar8 + 0xb8) = gsyncGetVideoMode_P2060;
        *(code **)(lVar8 + 0xc0) = gsyncSetVideoMode_P2060;
        *(code **)(lVar8 + 200) = gsyncGetNSync_P2060;
        *(code **)(lVar8 + 0xd0) = gsyncSetNSync_P2060;
        *(code **)(lVar8 + 0xd8) = gsyncGetSyncSkew_P2060;
        *(code **)(lVar8 + 0xe0) = gsyncSetSyncSkew_P2060;
        *(code **)(lVar8 + 0xf8) = gsyncGetSyncStartDelay_P2060;
        *(code **)(lVar8 + 0x100) = gsyncSetSyncStartDelay_P2060;
        *(code **)(lVar8 + 0x108) = gsyncGetEmitTestSignal_P2060;
        *(code **)(lVar8 + 0x110) = gsyncSetEmitTestSignal_P2060;
        *(code **)(lVar8 + 0x118) = gsyncGetInterlaceMode_P2060;
        *(code **)(lVar8 + 0x120) = gsyncSetInterlaceMode_P2060;
        *(code **)(lVar8 + 0x170) = gsyncGetStereoLockMode_P2060;
        *(code **)(lVar8 + 0x178) = gsyncSetStereoLockMode_P2060;
        *(code **)(lVar8 + 0x1a0) = gsyncGetMulDiv_P2060;
        *(code **)(lVar8 + 0x1a8) = gsyncSetMulDiv_P2060;
        *(code **)(lVar8 + 0x128) = gsyncRefSwapBarrier_P2060;
        *(code **)(lVar8 + 0x180) = gsyncSetMosaic_P2060;
        *(code **)(lVar8 + 0x188) = gsyncConfigFlashGsync_P2060;
        *(undefined4 *)(lVar2 + 0x188) = 0x3d1;
        cVar3 = gsyncSupportsLargeSyncSkew_P2060(lVar2);
        *(uint *)(lVar2 + 0x18c) = (-(uint)(cVar3 == '\0') & 0xffff0002) + 0xffff;
      }
      else if (param_5 == 0x2061) {
        lVar2 = *(long *)(lVar8 + 0x90);
        *(undefined1 *)(lVar8 + 0x9a) = 0xf;
        *(undefined4 *)(lVar8 + 0x58) = 4;
        *(code **)(lVar8 + 0xa0) = gsyncGpuCanBeMaster_P2060;
        *(code **)(lVar8 + 0x168) = gsyncOptimizeTimingParameters_P2060;
        *(code **)(lVar8 + 0x130) = gsyncRefSignal_P2060;
        *(code **)(lVar8 + 0x138) = gsyncRefMaster_P2060;
        *(code **)(lVar8 + 0x140) = gsyncRefSlaves_P2060;
        *(code **)(lVar8 + 0x148) = gsyncGetCplStatus_P2060;
        *(code **)(lVar8 + 0x150) = gsyncSetWatchdog_P2060;
        *(code **)(lVar8 + 0x158) = gsyncGetRevision_P2060;
        *(code **)(lVar8 + 0xe8) = gsyncGetUseHouse_P2060;
        *(code **)(lVar8 + 0xf0) = gsyncSetUseHouse_P2060;
        *(code **)(lVar8 + 0xa8) = gsyncGetSyncPolarity_P2060;
        *(code **)(lVar8 + 0xb0) = gsyncSetSyncPolarity_P2060;
        *(code **)(lVar8 + 0xb8) = gsyncGetVideoMode_P2060;
        *(code **)(lVar8 + 0xc0) = gsyncSetVideoMode_P2060;
        *(code **)(lVar8 + 200) = gsyncGetNSync_P2060;
        *(code **)(lVar8 + 0xd0) = gsyncSetNSync_P2060;
        *(code **)(lVar8 + 0xd8) = gsyncGetSyncSkew_P2060;
        *(code **)(lVar8 + 0xe0) = gsyncSetSyncSkew_P2060;
        *(code **)(lVar8 + 0xf8) = gsyncGetSyncStartDelay_P2060;
        *(code **)(lVar8 + 0x100) = gsyncSetSyncStartDelay_P2060;
        *(code **)(lVar8 + 0x108) = gsyncGetEmitTestSignal_P2060;
        *(code **)(lVar8 + 0x110) = gsyncSetEmitTestSignal_P2060;
        *(code **)(lVar8 + 0x118) = gsyncGetInterlaceMode_P2060;
        *(code **)(lVar8 + 0x120) = gsyncSetInterlaceMode_P2060;
        *(code **)(lVar8 + 0x170) = gsyncGetStereoLockMode_P2060;
        *(code **)(lVar8 + 0x178) = gsyncSetStereoLockMode_P2060;
        *(code **)(lVar8 + 0x1a0) = gsyncGetMulDiv_P2060;
        *(code **)(lVar8 + 0x1a8) = gsyncSetMulDiv_P2060;
        *(code **)(lVar8 + 0x128) = gsyncRefSwapBarrier_P2060;
        *(code **)(lVar8 + 0x180) = gsyncSetMosaic_P2060;
        *(code **)(lVar8 + 0x188) = gsyncConfigFlashGsync_P2060;
        *(undefined4 *)(lVar2 + 0x188) = 0x3d1;
        cVar3 = gsyncSupportsLargeSyncSkew_P2060(lVar2);
        *(uint *)(lVar2 + 0x18c) = (-(uint)(cVar3 == '\0') & 0xffff0002) + 0xffff;
        *(code **)(lVar8 + 0x148) = gsyncGetCplStatus_P2061;
        *(code **)(lVar8 + 400) = gsyncGetHouseSyncMode_P2061;
        *(code **)(lVar8 + 0x198) = gsyncSetHouseSyncMode_P2061;
        if (0x203 < (*(int *)(*(long *)(lVar8 + 0x90) + 0x20) << 8 |
                    (uint)*(byte *)(*(long *)(lVar8 + 0x90) + 0x24))) {
          *(code **)(lVar8 + 0xd8) = gsyncGetSyncSkew_P2061_V204;
          *(code **)(lVar8 + 0xe0) = gsyncSetSyncSkew_P2061_V204;
          *(undefined8 *)(lVar2 + 0x188) = 0xffffff00000007;
          *(undefined4 *)(lVar2 + 400) = 0x1000000;
          if (0x2ff < (*(int *)(*(long *)(lVar8 + 0x90) + 0x20) << 8 |
                      (uint)*(byte *)(*(long *)(lVar8 + 0x90) + 0x24))) {
            *(code **)(lVar8 + 0x1c0) = gsyncSetRasterSyncDecodeMode_P2061_V300;
            *(code **)(lVar8 + 0x1b0) = gsyncGetVRR_P2061_V300;
            *(code **)(lVar8 + 0x1b8) = gsyncSetVRR_P2061_V300;
          }
        }
      }
      lVar6 = uVar7 * 0x178 + lVar6;
      if (*(int *)(lVar6 + 0x54) == 1) {
        uVar7 = (**(code **)(lVar6 + 0x1c0))(param_2,param_2,*(undefined8 *)(lVar6 + 0x90));
        if ((int)uVar7 == 0) {
          return uVar7;
        }
        nvCheckOkFailedNoLog
                  (3,uVar7 & 0xffffffff,
                   "pGsync->gsyncHal.gsyncSetRasterSyncDecodeMode(pGpu, pGpu, pGsync->pExtDev)",
                   "src/kernel/gpu/external_device/gsync.c",0x19d);
        return 0;
      }
      return 0;
    }
    uVar4 = uVar4 + 1;
    piVar10 = piVar10 + 0x5e;
  } while (uVar4 != 4);
LAB_00317b50:
  nvDbg_Printf("src/kernel/gpu/external_device/gsync.c",0x17a,"gsyncAttachGpu",4,
               "NVRM: gsync table full!\n");
  return 0x1a;
}


// ===== 003180b0 gsyncRemoveGpu =====

undefined8 gsyncRemoveGpu(long param_1)

{
  long lVar1;
  long lVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  uint uVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  
  lVar2 = g_pSys;
  lVar1 = *(long *)(g_pSys + 0x1e8);
  cVar3 = rmGpuLockIsOwner();
  if (cVar3 == '\0') {
    nvAssertFailedNoLog("rmGpuLockIsOwner()","src/kernel/gpu/external_device/gsync.c",0x1b1);
  }
  uVar10 = 0;
  lVar9 = lVar1;
  do {
    uVar7 = *(uint *)(lVar9 + 0x54);
    if (uVar7 != 0) {
      uVar6 = 0;
      lVar8 = lVar9;
      do {
        if (*(int *)(param_1 + 0x7ac) == *(int *)(lVar8 + 0x5c)) {
          uVar7 = uVar7 - 1;
          lVar8 = lVar1 + uVar10 * 0x178;
          lVar9 = uVar10 * 0x178 + 0x5c;
          *(uint *)(lVar8 + 0x54) = uVar7;
          if (uVar7 != (uint)uVar6) {
            portMemCopy(lVar9 + uVar6 * 0xc + lVar1,0xc,lVar9 + (ulong)uVar7 * 0xc + lVar1,0xc);
            uVar6 = (ulong)*(uint *)(lVar8 + 0x54);
          }
          portMemSet(lVar9 + uVar6 * 0xc + lVar1,0,0xc);
          lVar9 = uVar10 * 0x178 + lVar1;
          iVar5 = *(int *)(lVar1 + 0x48);
          if (*(int *)(lVar9 + 0x54) == 0) {
            *(int *)(lVar1 + 0x48) = iVar5 + -1;
            *(undefined4 *)(lVar9 + 0x50) = 0xffffffff;
            iVar5 = gsyncSetupNullProvider_isra_0(lVar1,uVar10);
          }
          if (iVar5 == 0) {
            *(undefined1 *)(lVar2 + 0x69) = 0;
          }
          return 0;
        }
        uVar4 = (uint)uVar6 + 1;
        uVar6 = (ulong)uVar4;
        lVar8 = lVar8 + 0xc;
      } while (uVar7 != uVar4);
    }
    uVar7 = (int)uVar10 + 1;
    uVar10 = (ulong)uVar7;
    lVar9 = lVar9 + 0x178;
  } while (uVar7 != 4);
  nvDbg_Printf("src/kernel/gpu/external_device/gsync.c",0x1e1,"gsyncRemoveGpu",1,
               "NVRM: GPU was not found in gsync object\n");
  return 0;
}


// ===== 00318270 gsyncmgrGetGsync =====

long gsyncmgrGetGsync(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  uint uVar4;
  ulong uVar5;
  long lVar6;
  
  if (param_1 != 0) {
    lVar6 = 0;
    uVar5 = 0;
    lVar2 = *(long *)(g_pSys + 0x1e8);
    do {
      uVar4 = *(uint *)(lVar2 + 0x54 + lVar6);
      if (uVar4 != 0) {
        lVar3 = lVar2 + lVar6;
        lVar1 = lVar3 + (ulong)uVar4 * 0xc;
        do {
          if (*(int *)(param_1 + 0x7ac) == *(int *)(lVar3 + 0x5c)) {
            return lVar2 + 0x50 + uVar5 * 0x178;
          }
          lVar3 = lVar3 + 0xc;
        } while (lVar3 != lVar1);
      }
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulong)uVar4;
      lVar6 = lVar6 + 0x178;
    } while (uVar4 != 4);
  }
  return 0;
}


// ===== 003182f0 gsyncGetAttachedIds =====

undefined8 gsyncGetAttachedIds(long param_1)

{
  long lVar1;
  undefined4 *puVar2;
  uint uVar3;
  ulong uVar4;
  
  uVar3 = 0;
  lVar1 = *(long *)(g_pSys + 0x1e8);
  puVar2 = (undefined4 *)(lVar1 + 0x50);
  do {
    if (puVar2[1] != 0) {
      uVar4 = (ulong)uVar3;
      uVar3 = uVar3 + 1;
      *(undefined4 *)(param_1 + uVar4 * 4) = *puVar2;
    }
    puVar2 = puVar2 + 0x5e;
  } while (puVar2 != (undefined4 *)(lVar1 + 0x630));
  if (uVar3 < 4) {
    puVar2 = (undefined4 *)(param_1 + (ulong)uVar3 * 4);
    do {
      *puVar2 = 0xffffffff;
      puVar2 = puVar2 + 1;
    } while (puVar2 != (undefined4 *)(param_1 + 4 + ((ulong)(3 - uVar3) + (ulong)uVar3) * 4));
  }
  return 0;
}


// ===== 00318360 gsyncGetIdInfo =====

undefined8 gsyncGetIdInfo(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = (int *)(*(long *)(g_pSys + 0x1e8) + 0x50);
  while ((piVar1[1] == 0 || (*param_1 != *piVar1))) {
    iVar2 = iVar2 + 1;
    piVar1 = piVar1 + 0x5e;
    if (iVar2 == 4) {
      return 0x1f;
    }
  }
  param_1[2] = iVar2;
  param_1[1] = 0;
  return 0;
}


// ===== 003183b0 gsyncGetGsyncInstance =====

int gsyncGetGsyncInstance(long param_1)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  
  lVar4 = 0;
  iVar5 = 0;
  do {
    uVar2 = *(uint *)(*(long *)(g_pSys + 0x1e8) + 0x54 + lVar4);
    if (uVar2 != 0) {
      lVar3 = *(long *)(g_pSys + 0x1e8) + lVar4;
      lVar1 = lVar3 + (ulong)uVar2 * 0xc;
      do {
        if (*(int *)(param_1 + 0x7ac) == *(int *)(lVar3 + 0x5c)) {
          return iVar5;
        }
        lVar3 = lVar3 + 0xc;
      } while (lVar3 != lVar1);
    }
    iVar5 = iVar5 + 1;
    lVar4 = lVar4 + 0x178;
  } while (iVar5 != 4);
  return 4;
}


// ===== 00318420 gsyncapiCtrlCmdGsyncGetVersion_IMPL =====

undefined8 gsyncapiCtrlCmdGsyncGetVersion_IMPL(undefined8 param_1,undefined8 *param_2)

{
  *param_2 = 1;
  return 0;
}


// ===== 00318430 gsyncapiCtrlCmdGetGsyncGpuTopology_IMPL =====

undefined8 gsyncapiCtrlCmdGetGsyncGpuTopology_IMPL(long param_1,undefined4 *param_2)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  uVar1 = *(uint *)(param_1 + 0x118);
  uVar6 = 0;
  lVar2 = *(long *)(g_pSys + 0x1e8);
  lVar3 = (ulong)uVar1 * 0x178 + lVar2;
  lVar4 = lVar3;
  puVar5 = param_2;
  do {
    if ((uVar6 < *(uint *)(lVar3 + 0x54)) && (*(uint *)(lVar4 + 0x60) < 5)) {
      *puVar5 = *(undefined4 *)(lVar4 + 0x5c);
      puVar5[1] = *(undefined4 *)(lVar4 + 0x60);
      puVar5[2] = *(undefined4 *)(lVar4 + 100);
    }
    else {
      *puVar5 = 0xffffffff;
    }
    uVar6 = uVar6 + 1;
    lVar4 = lVar4 + 0xc;
    puVar5 = puVar5 + 4;
  } while (uVar6 != 4);
  param_2[0x10] = *(undefined4 *)(lVar2 + 0x58 + (ulong)uVar1 * 0x178);
  return 0;
}


