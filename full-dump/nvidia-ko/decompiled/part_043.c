// ===== 004c4760 rpcMapMemoryDma_v03_00 =====

void rpcMapMemoryDma_v03_00(undefined8 param_1,long param_2,undefined4 *param_3)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0xe,0x38);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = *param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_3[1];
    *(undefined4 *)(lVar1 + 0x28) = param_3[2];
    *(undefined4 *)(lVar1 + 0x2c) = param_3[3];
    *(undefined4 *)(lVar1 + 0x40) = param_3[8];
    *(undefined8 *)(lVar1 + 0x30) = *(undefined8 *)(param_3 + 4);
    *(undefined8 *)(lVar1 + 0x38) = *(undefined8 *)(param_3 + 6);
    *(undefined8 *)(lVar1 + 0x48) = *(undefined8 *)(param_3 + 0xc);
    iVar2 = _issueRpcAndWait(param_1,param_2);
    if (iVar2 == 0) {
      *(undefined8 *)(param_3 + 0xc) = *(undefined8 *)(lVar1 + 0x48);
      return;
    }
  }
  return;
}


// ===== 004c4810 rpcMapMemoryDma_v2C_05 =====

void rpcMapMemoryDma_v2C_05(undefined8 param_1,long param_2,undefined4 *param_3)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0xe,0x38);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = *param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_3[1];
    *(undefined4 *)(lVar1 + 0x28) = param_3[2];
    *(undefined4 *)(lVar1 + 0x2c) = param_3[3];
    *(undefined4 *)(lVar1 + 0x40) = param_3[8];
    *(undefined8 *)(lVar1 + 0x30) = *(undefined8 *)(param_3 + 4);
    *(undefined8 *)(lVar1 + 0x38) = *(undefined8 *)(param_3 + 6);
    *(undefined8 *)(lVar1 + 0x48) = *(undefined8 *)(param_3 + 0xc);
    *(undefined4 *)(lVar1 + 0x44) = param_3[10];
    iVar2 = _issueRpcAndWait(param_1,param_2);
    if (iVar2 == 0) {
      *(undefined8 *)(param_3 + 0xc) = *(undefined8 *)(lVar1 + 0x48);
      return;
    }
  }
  return;
}


// ===== 004c48c0 rpcUnmapMemoryDma_v03_00 =====

void rpcUnmapMemoryDma_v03_00(undefined8 param_1,long param_2,undefined4 *param_3)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0xf,0x28);
  if (iVar2 != 0) {
    return;
  }
  *(undefined4 *)(lVar1 + 0x20) = *param_3;
  *(undefined4 *)(lVar1 + 0x24) = param_3[1];
  *(undefined4 *)(lVar1 + 0x28) = param_3[2];
  *(undefined4 *)(lVar1 + 0x2c) = param_3[3];
  *(undefined4 *)(lVar1 + 0x30) = param_3[4];
  *(undefined8 *)(lVar1 + 0x38) = *(undefined8 *)(param_3 + 6);
  _issueRpcAndWait(param_1,param_2);
  return;
}


// ===== 004c4950 rpcUnmapMemoryDma_v2C_05 =====

void rpcUnmapMemoryDma_v2C_05(undefined8 param_1,long param_2,undefined4 *param_3)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0xf,0x30);
  if (iVar2 != 0) {
    return;
  }
  *(undefined4 *)(lVar1 + 0x20) = *param_3;
  *(undefined4 *)(lVar1 + 0x24) = param_3[1];
  *(undefined4 *)(lVar1 + 0x28) = param_3[2];
  *(undefined4 *)(lVar1 + 0x2c) = param_3[3];
  *(undefined4 *)(lVar1 + 0x30) = param_3[4];
  *(undefined8 *)(lVar1 + 0x40) = *(undefined8 *)(param_3 + 8);
  *(undefined8 *)(lVar1 + 0x38) = *(undefined8 *)(param_3 + 6);
  _issueRpcAndWait(param_1,param_2);
  return;
}


// ===== 004c49e0 rpcAllocSubdevice_v08_01 =====

void rpcAllocSubdevice_v08_01
               (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0x13,0x28);
  if (iVar2 != 0) {
    return;
  }
  *(undefined4 *)(lVar1 + 0x28) = param_3;
  *(undefined4 *)(lVar1 + 0x2c) = param_4;
  *(undefined4 *)(lVar1 + 0x30) = param_5;
  *(undefined4 *)(lVar1 + 0x34) = param_6;
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_7;
  _issueRpcAndWait(param_1,param_2);
  return;
}


// ===== 004c4a80 rpcDupObject_v03_00 =====

ulong rpcDupObject_v03_00(long param_1,long param_2,undefined4 param_3,undefined4 param_4,
                         undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8
                         )

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  undefined8 uVar5;
  char *pcVar6;
  uint local_4c;
  long local_48;
  undefined8 local_40 [2];
  
  lVar2 = *(long *)(param_2 + 0x4d8);
  if ((*(char *)(param_1 + 0x4913) == '\0') || (*(char *)(param_1 + 0x491e) != '\0')) {
LAB_004c4acb:
    local_4c = rpcWriteCommonHeader(param_1,param_2,0x15,0x1c);
    if (local_4c == 0) {
      *(undefined4 *)(lVar2 + 0x20) = param_3;
      *(undefined4 *)(lVar2 + 0x30) = param_7;
      *(undefined4 *)(lVar2 + 0x24) = param_4;
      *(undefined4 *)(lVar2 + 0x28) = param_5;
      *(undefined4 *)(lVar2 + 0x2c) = param_6;
      *(undefined4 *)(lVar2 + 0x34) = param_8;
      uVar3 = _issueRpcAndWait(param_1,param_2);
      return uVar3;
    }
  }
  else {
    local_48 = 0;
    local_4c = serverGetClientUnderLock(g_resServ,param_6,local_40);
    if (local_4c == 0) {
      local_4c = clientGetResourceRef_IMPL(local_40[0],param_7,&local_48);
      if ((local_4c == 0) && (local_48 != 0)) {
        lVar4 = __nvoc_dynamicCast(*(undefined8 *)(local_48 + 8),__nvoc_class_def_Memory);
        if (lVar4 != 0) {
          uVar1 = *(uint *)(lVar4 + 0xfc);
          if (uVar1 < 0x72) {
            if ((0x3d < uVar1) && ((0x8000000000005U >> ((ulong)(uVar1 - 0x3e) & 0x3f) & 1) != 0)) {
              return 0;
            }
          }
          else if (uVar1 == 0x50a0) {
            return 0;
          }
        }
        goto LAB_004c4acb;
      }
      pcVar6 = "NVRM: Failed to get resource ref: 0x%x! hObject: 0x%x\n";
      uVar5 = 0x118b;
      param_3 = param_5;
    }
    else {
      pcVar6 = "NVRM: Failed to get client under lock: 0x%x! hClient: 0x%x\n";
      uVar5 = 0x1182;
    }
    nvDbg_Printf("src/kernel/vgpu/rpc.c",uVar5,"rpcDupObject_v03_00",4,pcVar6,local_4c,param_3);
  }
  return (ulong)local_4c;
}


// ===== 004c4c70 rpcIdleChannels_v03_00 =====

undefined8
rpcIdleChannels_v03_00
          (undefined8 param_1,long param_2,long param_3,long param_4,long param_5,ulong param_6,
          undefined4 param_7,undefined4 param_8)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  ulong uVar4;
  int iVar5;
  
  iVar5 = (int)param_6;
  uVar4 = ((ulong)*(uint *)(param_2 + 0x4f0) - 0x2c) / 0xc;
  if (uVar4 < (param_6 & 0xffffffff)) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x11bd,"rpcIdleChannels_v03_00",4,
                 "NVRM: NVRM_RPC: IdleChannels: requested %u entries (but only room for %u)\n",
                 param_6,uVar4);
    uVar2 = 0xffff;
  }
  else {
    uVar2 = rpcWriteCommonHeader(param_1,param_2,0x16,(iVar5 * 3 + 3) * 4);
    if ((int)uVar2 == 0) {
      *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_7;
      *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_8;
      *(int *)(*(long *)(param_2 + 0x4d8) + 0x28) = iVar5;
      if (iVar5 != 0) {
        uVar4 = 0;
        do {
          lVar3 = (uVar4 & 0xffffffff) * 0xc;
          *(undefined4 *)(*(long *)(param_2 + 0x4d8) + lVar3 + 0x2c) =
               *(undefined4 *)(param_3 + uVar4 * 4);
          *(undefined4 *)(*(long *)(param_2 + 0x4d8) + lVar3 + 0x30) =
               *(undefined4 *)(param_4 + uVar4 * 4);
          lVar1 = uVar4 * 4;
          uVar4 = uVar4 + 1;
          *(undefined4 *)(lVar3 + *(long *)(param_2 + 0x4d8) + 0x34) =
               *(undefined4 *)(param_5 + lVar1);
        } while ((param_6 & 0xffffffff) != uVar4);
      }
      uVar2 = _issueRpcAndWait(param_1);
      return uVar2;
    }
  }
  return uVar2;
}


// ===== 004c4dd0 rpcAllocEvent_v03_00 =====

ulong rpcAllocEvent_v03_00
                (long param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  ulong uVar1;
  undefined8 uVar2;
  undefined8 local_48;
  long local_40 [2];
  
  if ((*(char *)(param_1 + 0x4913) != '\0') && (*(char *)(param_1 + 0x491e) == '\0')) {
    local_40[0] = 0;
    uVar2 = serverGetClientUnderLock(g_resServ,param_4,&local_48);
    if ((int)uVar2 != 0) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x11e8,"rpcAllocEvent_v03_00",4,
                   "NVRM: Failed to get client(0x%x) under lock: 0x%x!\n",param_4,uVar2);
      return 0x1f;
    }
    uVar1 = clientGetResourceRef_IMPL(local_48,param_6,local_40);
    if (((int)uVar1 != 0) || (local_40[0] == 0)) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x11f1,"rpcAllocEvent_v03_00",4,
                   "NVRM: Failed to get resource ref: 0x%x! hObject: 0x%x\n",uVar1 & 0xffffffff,
                   param_6);
      return 0x1f;
    }
    if (*(int *)(local_40[0] + 0x11c) == 2) {
      return uVar1;
    }
  }
  uVar1 = rpcWriteCommonHeader(param_1,param_2,0x17,0x1c);
  if ((int)uVar1 != 0) {
    return uVar1;
  }
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x28) = param_5;
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x2c) = param_6;
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x30) = param_7;
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x34) = param_8;
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x38) = param_9;
  uVar1 = _issueRpcAndWait(param_1,param_2);
  return uVar1;
}


// ===== 004c4f90 rpcDmaControl_wrapper =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
rpcDmaControl_wrapper
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,uint param_5,
          long param_6,int param_7)

{
  undefined8 uVar1;
  
  if ((param_6 == 0) != (param_7 == 0)) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1226,"rpcDmaControl_wrapper",4,
                 "NVRM: NVRM_RPC: Bad pParamStructPtr/paramSize for cmd:0x%x\n",param_5);
    return 0x3b;
  }
  if (param_5 == 0x83de030b) {
    uVar1 = (**(code **)(param_2 + 0x58))(param_1,param_2,param_3,param_4,param_6);
    return uVar1;
  }
  if (param_5 < 0x83de030c) {
    if (param_5 == 0x20800ac3) {
      uVar1 = (**(code **)(param_2 + 0x60))(param_1,param_2,param_6);
      return uVar1;
    }
    if (param_5 < 0x20800ac4) {
      if (param_5 == 0x20800102) {
        uVar1 = (**(code **)(param_2 + 0x1b8))(param_1,param_2,param_3,param_4,param_6);
        return uVar1;
      }
      if (param_5 < 0x20800103) {
        if (param_5 == 0x80170f) {
          uVar1 = (**(code **)(param_2 + 0x480))(param_1,param_2,param_3,param_4,param_6);
          return uVar1;
        }
        if (param_5 < 0x801710) {
          if (param_5 == 0x800294) {
            uVar1 = (**(code **)(param_2 + 0x3b0))(param_1,param_2,param_3,param_4,0x800294);
            return uVar1;
          }
          if (param_5 < 0x800295) {
            if (param_5 == 299) {
              uVar1 = (**(code **)(param_2 + 0x248))(param_1,param_2,param_6);
              return uVar1;
            }
            if (param_5 == 0x13a) {
              uVar1 = (**(code **)(param_2 + 0x428))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0x127) {
              uVar1 = (**(code **)(param_2 + 0x338))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
          }
          else {
            if (param_5 == 0x801107) {
              uVar1 = (**(code **)(param_2 + 0x2d0))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0x801108) {
              uVar1 = (**(code **)(param_2 + 0x218))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
          }
        }
        else {
          if (param_5 == 0x80200a) {
            uVar1 = (**(code **)(param_2 + 0x378))(param_1,param_2,param_3,param_4,param_6);
            return uVar1;
          }
          if (param_5 < 0x80200b) {
            if (param_5 == 0x801813) {
              uVar1 = (**(code **)(param_2 + 0x240))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0x801814) {
              uVar1 = (**(code **)(param_2 + 0x108))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0x801812) {
              uVar1 = (**(code **)(param_2 + 0xd8))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
          }
          else {
            if (param_5 == 0x900105) {
              uVar1 = (**(code **)(param_2 + 0x268))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0xf80102) {
              uVar1 = (**(code **)(param_2 + 0xb8))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
          }
        }
      }
      else {
        if (param_5 == 0x208001a6) {
          uVar1 = (**(code **)(param_2 + 0xa0))(param_1,param_2,param_3,param_4,param_6);
          return uVar1;
        }
        if (param_5 < 0x208001a7) {
          if (param_5 == 0x2080012f) {
            uVar1 = (**(code **)(param_2 + 0x1f8))(param_1,param_2,param_3,param_4,param_6);
            return uVar1;
          }
          if (param_5 < 0x20800130) {
            if (param_5 == 0x2080012c) {
              uVar1 = (**(code **)(param_2 + 0x260))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0x2080012d) {
              uVar1 = (**(code **)(param_2 + 0x90))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0x2080012b) {
              uVar1 = (**(code **)(param_2 + 0x70))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
          }
          else {
            if (param_5 == 0x20800192) {
              uVar1 = (**(code **)(param_2 + 0x350))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0x208001a0) {
              uVar1 = (**(code **)(param_2 + 0x488))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
          }
        }
        else {
          if (param_5 == 0x20800407) {
            uVar1 = (**(code **)(param_2 + 0x2f8))(param_1,param_2,param_3,param_4,param_6);
            return uVar1;
          }
          if (param_5 < 0x20800408) {
            if (param_5 == 0x208001e3) {
              uVar1 = (**(code **)(param_2 + 0x2e0))(param_1,param_2,param_6);
              return uVar1;
            }
            if (param_5 == 0x208001f5) {
              uVar1 = (**(code **)(param_2 + 0x3a8))(param_1,param_2,param_6);
              return uVar1;
            }
          }
          else {
            if (param_5 == 0x20800a46) {
              uVar1 = (**(code **)(param_2 + 0x178))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0x20800a69) {
              uVar1 = (**(code **)(param_2 + 0x378))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
          }
        }
      }
    }
    else {
      if (param_5 == 0x2080206f) {
        uVar1 = (**(code **)(param_2 + 0x388))(param_1,param_2,param_3,param_4,param_6);
        return uVar1;
      }
      if (param_5 < 0x20802070) {
        if (param_5 == 0x20801303) {
          uVar1 = (**(code **)(param_2 + 0x230))(param_1,param_2,param_3,param_4,param_6);
          return uVar1;
        }
        if (param_5 < 0x20801304) {
          if (param_5 == 0x20801210) {
            uVar1 = (**(code **)(param_2 + 0x1c8))(param_1,param_2,param_3,param_4,param_6);
            return uVar1;
          }
          if (param_5 < 0x20801211) {
            if (param_5 == 0x20801118) {
              uVar1 = (**(code **)(param_2 + 0x28))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0x20801208) {
              uVar1 = (**(code **)(param_2 + 0x370))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0x2080110b) {
              uVar1 = (**(code **)(param_2 + 0x3f8))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
          }
          else {
            if (param_5 == 0x20801211) {
              uVar1 = (**(code **)(param_2 + 0x168))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0x20801212) {
              uVar1 = (**(code **)(param_2 + 0x310))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
          }
        }
        else {
          if (param_5 == 0x2080182e) {
            uVar1 = (**(code **)(param_2 + 0x1b0))(param_1,param_2,param_3,param_4,param_6);
            return uVar1;
          }
          if (param_5 < 0x2080182f) {
            if (param_5 == 0x20801346) {
              uVar1 = (**(code **)(param_2 + 0x3d0))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0x20801702) {
              uVar1 = (**(code **)(param_2 + 0x318))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
          }
          else {
            if (param_5 == 0x2080182f) {
              uVar1 = (**(code **)(param_2 + 0x38))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0x2080200a) {
              uVar1 = (**(code **)(param_2 + 0x470))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
          }
        }
      }
      else {
        if (param_5 == 0x20803604) {
          uVar1 = (**(code **)(param_2 + 0x140))(param_1,param_2,param_6);
          return uVar1;
        }
        if (param_5 < 0x20803605) {
          if (param_5 == 0x20803502) {
            uVar1 = (**(code **)(param_2 + 0x3c0))(param_1,param_2,param_3,param_4,param_6);
            return uVar1;
          }
          if (param_5 < 0x20803503) {
            if (param_5 == 0x20803002) {
              uVar1 = (**(code **)(param_2 + 0x2c0))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0x20803040) {
              uVar1 = (**(code **)(param_2 + 0x368))(param_1,param_2,param_6);
              return uVar1;
            }
            if (param_5 == 0x20802a02) {
              uVar1 = (**(code **)(param_2 + 600))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
          }
          else {
            if (param_5 == 0x20803504) {
              uVar1 = (**(code **)(param_2 + 0x360))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0x20803603) {
              uVar1 = (**(code **)(param_2 + 0x1a8))(param_1,param_2,param_6);
              return uVar1;
            }
          }
        }
        else {
          if (param_5 == 0x83de0307) {
            uVar1 = (**(code **)(param_2 + 0x478))(param_1,param_2,param_3,param_4,param_6);
            return uVar1;
          }
          if (param_5 < 0x83de0308) {
            if (param_5 == 0x20803801) {
              uVar1 = (**(code **)(param_2 + 0x1d8))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0x506f0105) {
              uVar1 = (**(code **)(param_2 + 0xd0))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
          }
          else {
            if (param_5 == 0x83de0308) {
              uVar1 = (**(code **)(param_2 + 0x200))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0x83de0309) {
              uVar1 = (**(code **)(param_2 + 0x148))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
          }
        }
      }
    }
  }
  else {
    if (param_5 == 0xa0800204) {
      uVar1 = (**(code **)(param_2 + 0x4b0))(param_1,param_2,param_6);
      return uVar1;
    }
    if (param_5 < 0xa0800205) {
      if (param_5 == 0x90960102) {
        uVar1 = (**(code **)(param_2 + 200))(param_1,param_2,param_3,param_4,param_6);
        return uVar1;
      }
      if (param_5 < 0x90960103) {
        if (param_5 == 0x83de031d) {
          uVar1 = (**(code **)(param_2 + 0x430))(param_1,param_2,param_3,param_4,param_6);
          return uVar1;
        }
        if (param_5 < 0x83de031e) {
          if (param_5 == 0x83de0313) {
            uVar1 = (**(code **)(param_2 + 0x78))(param_1,param_2,param_3,param_4,param_6);
            return uVar1;
          }
          if (param_5 < 0x83de0314) {
            if (param_5 == 0x83de030f) {
              uVar1 = (**(code **)(param_2 + 0x100))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0x83de0310) {
              uVar1 = (**(code **)(param_2 + 0x208))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0x83de030c) {
              uVar1 = (**(code **)(param_2 + 800))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
          }
          else {
            if (param_5 == 0x83de0317) {
              uVar1 = (**(code **)(param_2 + 0x420))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0x83de0318) {
              uVar1 = (**(code **)(param_2 + 1000))(param_1,param_2,param_3,param_4);
              return uVar1;
            }
          }
        }
        else {
          if (param_5 == 0x83de032b) {
            uVar1 = (**(code **)(param_2 + 0x460))(param_1,param_2,param_3,param_4,param_6);
            return uVar1;
          }
          if (param_5 < 0x83de032c) {
            if (param_5 == 0x83de0321) {
              uVar1 = (**(code **)(param_2 + 0x278))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0x83de032a) {
              uVar1 = (**(code **)(param_2 + 0x2b8))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0x83de031f) {
              uVar1 = (**(code **)(param_2 + 0xa8))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
          }
          else {
            if (param_5 == 0x906f0102) {
              uVar1 = (**(code **)(param_2 + 0x2a0))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0x90960101) {
              uVar1 = (**(code **)(param_2 + 0x328))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
          }
        }
      }
      else {
        if (param_5 == 0xa06c0103) {
          uVar1 = (**(code **)(param_2 + 0x1f0))(param_1,param_2,param_3,param_4,param_6);
          return uVar1;
        }
        if (param_5 < 0xa06c0104) {
          if (param_5 == 0x90960107) {
            uVar1 = (**(code **)(param_2 + 0x410))(param_1,param_2,param_3,param_4,param_6);
            return uVar1;
          }
          if (param_5 < 0x90960108) {
            if (param_5 == 0x90960103) {
              uVar1 = (**(code **)(param_2 + 0x1e0))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0x90960105) {
              uVar1 = (**(code **)(param_2 + 0x150))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
          }
          else {
            if (param_5 == 0x90f10106) {
              uVar1 = (**(code **)(param_2 + 0x158))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0xa06c0101) {
LAB_004c5cd6:
              uVar1 = (**(code **)(param_2 + 0x2a8))(param_1,param_2,param_3,param_4);
              return uVar1;
            }
            if (param_5 == 0x90e60102) {
              uVar1 = (**(code **)(param_2 + 0x448))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
          }
        }
        else {
          if (param_5 == 0xa06c010a) {
            uVar1 = (**(code **)(param_2 + 0x228))(param_1,param_2,param_3,param_4,param_6);
            return uVar1;
          }
          if (param_5 < 0xa06c010b) {
            if (param_5 == 0xa06c0105) {
              uVar1 = (**(code **)(param_2 + 0x88))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0xa06c0107) {
              uVar1 = (**(code **)(param_2 + 0x440))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
          }
          else {
            if (param_5 == 0xa06f0109) {
              uVar1 = (**(code **)(param_2 + 0x3e0))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0xa06f0112) {
              uVar1 = (**(code **)(param_2 + 0x2d8))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0xa06f0103) goto LAB_004c5cd6;
          }
        }
      }
    }
    else {
      if (param_5 == 0xb0cc0114) {
        uVar1 = (**(code **)(param_2 + 0x188))(param_1,param_2,param_3,param_4,param_6);
        return uVar1;
      }
      if (param_5 < 0xb0cc0115) {
        if (param_5 == 0xb0cc0109) {
          uVar1 = (**(code **)(param_2 + 0xb0))(param_1,param_2,param_3,param_4,param_6);
          return uVar1;
        }
        if (param_5 < 0xb0cc010a) {
          if (param_5 == 0xb0cc0103) {
            uVar1 = (**(code **)(param_2 + 0x98))(param_1,param_2,param_3,param_4,param_6);
            return uVar1;
          }
          if (param_5 < 0xb0cc0104) {
            if (param_5 == 0xa0bc0101) {
              uVar1 = (**(code **)(param_2 + 0x418))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0xb0cc0101) {
              uVar1 = (**(code **)(param_2 + 400))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
          }
          else {
            if (param_5 == 0xb0cc0106) {
              uVar1 = (**(code **)(param_2 + 0x438))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0xb0cc0107) {
              uVar1 = (**(code **)(param_2 + 0x498))(param_1,param_2,param_3,param_4);
              return uVar1;
            }
            if (param_5 == 0xb0cc0105) {
LAB_004c5f20:
              uVar1 = (**(code **)(param_2 + 0x170))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
          }
        }
        else {
          if (param_5 == 0xb0cc010e) {
            uVar1 = (**(code **)(param_2 + 0x400))(param_1,param_2,param_3,param_4,param_6);
            return uVar1;
          }
          if (param_5 < 0xb0cc010f) {
            if (param_5 == 0xb0cc010d) {
              uVar1 = (**(code **)(param_2 + 0x220))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0xb0cc010a) {
              uVar1 = (**(code **)(param_2 + 0x1d0))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            uVar1 = (**(code **)(param_2 + 0x138))(param_1,param_2,param_3,param_4);
            return uVar1;
          }
          if (param_5 == 0xb0cc010f) {
            uVar1 = (**(code **)(param_2 + 0x1c0))(param_1,param_2,param_3,param_4,param_6);
            return uVar1;
          }
          if (param_5 == 0xb0cc0113) {
            uVar1 = (**(code **)(param_2 + 0x450))(param_1,param_2,param_3,param_4,param_6);
            return uVar1;
          }
        }
      }
      else {
        if (param_5 == 0xb0cc0202) {
          uVar1 = (**(code **)(param_2 + 0x3c8))(param_1,param_2,param_3,param_4,param_6);
          return uVar1;
        }
        if (param_5 < 0xb0cc0203) {
          if (param_5 == 0xb0cc0119) {
            uVar1 = (**(code **)(param_2 + 0x110))(param_1,param_2,param_3,param_4,param_6);
            return uVar1;
          }
          if (param_5 < 0xb0cc011a) {
            if (param_5 == 0xb0cc0115) {
              uVar1 = (**(code **)(param_2 + 0x160))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0xb0cc0116) {
              uVar1 = (**(code **)(param_2 + 0x180))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
          }
          else {
            if (param_5 == 0xb0cc011a) {
              uVar1 = (**(code **)(param_2 + 0x2f0))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0xb0cc0201) {
              uVar1 = (**(code **)(param_2 + 0x1a0))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
          }
        }
        else {
          if (param_5 == 0xc6370101) {
            uVar1 = (**(code **)(param_2 + 0x390))(param_1,param_2,param_3,param_4,param_6);
            return uVar1;
          }
          if (param_5 < 0xc6370102) {
            if (param_5 == 0xc36f0108) {
              uVar1 = (**(code **)(param_2 + 0x398))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0xc36f010a) {
              uVar1 = (**(code **)(param_2 + 0x300))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0xb0cc0204) goto LAB_004c5f20;
          }
          else {
            if (param_5 == 0xc6370102) {
              uVar1 = (**(code **)(param_2 + 0x468))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
            if (param_5 == 0xc6370105) {
              uVar1 = (**(code **)(param_2 + 0xe8))(param_1,param_2,param_3,param_4,param_6);
              return uVar1;
            }
          }
        }
      }
    }
  }
  nvDbg_Printf("src/kernel/vgpu/rpc.c",0x136d,"rpcDmaControl_wrapper",4,
               "NVRM: DMA Control Command cmd 0x%x NOT supported\n",param_5);
  return 0x56;
}


// ===== 004c5f40 updateHostVgpuFbUsage =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

int updateHostVgpuFbUsage(long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  long lVar2;
  long local_448 [2];
  uint local_438;
  undefined4 local_434;
  uint local_430;
  undefined4 local_42c;
  uint local_428;
  
  lVar2 = rmapiGetInterface(4);
  portMemSet(local_448 + 1,0,0x404);
  local_448[1] = 0x1600000003;
  local_434 = 9;
  local_42c = 0x10;
  iVar1 = (**(code **)(lVar2 + 0x38))(lVar2,param_2,param_4,0x20801303,local_448 + 1,0x404);
  if (iVar1 == 0) {
    portMemSet(local_448,0,8);
    local_448[0] = (((ulong)local_430 + (ulong)local_428) - (ulong)local_438) * 0x400;
    lVar2 = gpuGetRpc(param_1);
    if (lVar2 == 0) {
      iVar1 = 0x1a;
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/vgpu/rpc.c",0x2aec);
    }
    else {
      if ((*(char *)(param_1 + 0x909) == '\0') && (*(char *)(param_1 + 0x90a) == '\0')) {
        iVar1 = rpcDmaControl_wrapper(param_1,lVar2,param_2,param_3,0xa0800204,local_448,8);
      }
      else {
        iVar1 = (**(code **)(param_1 + 0x3b90))
                          (param_1 + 0x3b58,param_2,param_3,0xa0800204,local_448,8);
      }
      if (iVar1 == 0) {
        return 0;
      }
    }
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2af5,"updateHostVgpuFbUsage",4,
                 "NVRM: NVRM_RPC: Host vGPU FB usage update failed : %x\n",iVar1);
  }
  else {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2ade,"updateHostVgpuFbUsage",4,
                 "NVRM: NVRM_RPC: Get FB usage info failed : %x\n",iVar1);
  }
  return iVar1;
}


// ===== 004c611a _freeGfxpBuffer.cold =====

void _freeGfxpBuffer_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 004c6130 _freeGfxpBuffer =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r11 replaced with injection: x86_indirect_thunk_r11 */

void _freeGfxpBuffer(long param_1,long param_2,undefined4 param_3,long param_4)

{
  undefined4 uVar1;
  char *pcVar2;
  long lVar3;
  code *pcVar4;
  undefined4 uVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  long local_b0;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 local_9c;
  undefined4 uStack_98;
  undefined4 local_94;
  undefined4 uStack_90;
  undefined4 local_8c;
  undefined4 uStack_88;
  undefined4 local_84;
  undefined4 uStack_80;
  undefined4 local_7c;
  undefined8 local_78;
  undefined4 local_50;
  
  local_b0 = 0;
  lVar7 = rmapiGetInterface(4);
  if (param_1 == 0) {
    return;
  }
  if (param_2 == 0) {
    return;
  }
  pcVar2 = *(char **)(param_4 + 0x150);
  if (pcVar2 == (char *)0x0) {
    return;
  }
  lVar8 = **(long **)(*(long *)(param_2 + 0x110) + 0x48);
  uVar1 = *(undefined4 *)(lVar8 + 0x48);
  uVar5 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
  iVar6 = subdeviceGetByInstance_IMPL
                    (lVar8,*(undefined4 *)(*(long *)(*(long *)(param_2 + 0x110) + 0x48) + 0x10),
                     uVar5,&local_b0);
  if ((iVar6 == 0) && (*pcVar2 != '\0')) {
    portMemSet(&local_a8,0,0x70);
    local_50 = 0;
    local_a8 = 2;
    uStack_98 = 0;
    local_94 = 0;
    uStack_90 = 0;
    local_8c = 0;
    uStack_88 = 0;
    local_84 = 0;
    uStack_80 = 0;
    local_7c = 0;
    local_78 = 0;
    uStack_a4 = uVar1;
    uStack_a0 = param_3;
    lVar8 = gpuGetRpc(param_1);
    if (lVar8 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/vgpu/rpc.c",0xc19);
      iVar6 = 0x1a;
    }
    else {
      if ((*(char *)(param_1 + 0x909) == '\0') && (*(char *)(param_1 + 0x90a) == '\0')) {
        if (local_b0 == 0) {
_freeGfxpBuffer_cold:
                    /* WARNING: Does not return */
          pcVar4 = (code *)invalidInstructionException();
          (*pcVar4)();
        }
        iVar6 = rpcDmaControl_wrapper
                          (param_1,lVar8,uVar1,
                           *(undefined4 *)(*(long *)(*(long *)(local_b0 + 0x140) + 0x48) + 0x10),
                           0x20801211,&local_a8,0x70);
      }
      else {
        if (local_b0 == 0) goto _freeGfxpBuffer_cold;
        iVar6 = (**(code **)(param_1 + 0x3b90))
                          (param_1 + 0x3b58,uVar1,
                           *(undefined4 *)(*(long *)(*(long *)(local_b0 + 0x140) + 0x48) + 0x10),
                           0x20801211,&local_a8,0x70);
      }
      if (iVar6 == 0) goto LAB_004c61f1;
    }
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0xc22,"_freeGfxpBuffer",4,
                 "NVRM: NVRM_RPC: rpc call to bind gfxp buffer for WFI mode failed : %x\n",iVar6);
  }
  else {
LAB_004c61f1:
    lVar8 = 0;
    do {
      lVar3 = *(long *)(pcVar2 + lVar8 * 2 + 0x30);
      if (lVar3 != 0) {
        local_94 = 0;
        uStack_88 = 0;
        local_9c = 0;
        uStack_98 = 0;
        local_84 = 0;
        uStack_80 = 0;
        local_7c = 0;
        uStack_a4 = *(undefined4 *)(*(long *)(*(long *)(param_2 + 0x110) + 0x48) + 0x10);
        uStack_a0 = *(undefined4 *)(pcVar2 + lVar8 + 0x1c);
        uStack_90 = (undefined4)lVar3;
        local_8c = (undefined4)((ulong)lVar3 >> 0x20);
        local_a8 = uVar1;
        iVar6 = (**(code **)(lVar7 + 0xa8))(lVar7,&local_a8);
        if (iVar6 != 0) {
          nvAssertOkFailedNoLog
                    (iVar6,"pRmApi->Unmap(pRmApi, &unmapDmaParams)","src/kernel/vgpu/rpc.c",0xc34);
        }
      }
      if ((*(int *)(pcVar2 + lVar8 + 0x1c) != 0) &&
         (iVar6 = (**(code **)(lVar7 + 0x18))(lVar7,uVar1), iVar6 != 0)) {
        nvAssertOkFailedNoLog
                  (iVar6,"pRmApi->Free(pRmApi, hClient, pVgpuGfxpBuffers->hDma[i])",
                   "src/kernel/vgpu/rpc.c",0xc39);
      }
      if ((*(int *)(pcVar2 + lVar8 + 8) != 0) &&
         (iVar6 = (**(code **)(lVar7 + 0x18))(lVar7,uVar1), iVar6 != 0)) {
        nvAssertOkFailedNoLog
                  (iVar6,"pRmApi->Free(pRmApi, hClient, pVgpuGfxpBuffers->hMemory[i])",
                   "src/kernel/vgpu/rpc.c",0xc3e);
      }
      lVar8 = lVar8 + 4;
    } while (lVar8 != 0x14);
  }
  portMemFree(pcVar2);
  *(undefined8 *)(param_4 + 0x150) = 0;
  return;
}


// ===== 004c64e2 rpcFree_v03_00.cold =====

void rpcFree_v03_00_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 004c64f0 rpcFree_v03_00 =====

/* WARNING: Removing unreachable block (ram,0x004c6885) */

ulong rpcFree_v03_00(long param_1,long param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  char *pcVar5;
  code *pcVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  long lVar10;
  ulong uVar11;
  long lVar12;
  long lVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  bool bVar17;
  int local_54;
  undefined8 local_50;
  long local_48;
  long local_40 [2];
  
  lVar2 = *(long *)(param_2 + 0x4d8);
  local_48 = 0;
  local_54 = 0;
  iVar8 = serverGetClientUnderLock(g_resServ,param_3,&local_50);
  if (iVar8 != 0) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0xcb2,"_rpcFreePrologue",4,
                 "NVRM: Failed to get client under lock: 0x%x! hClient: 0x%x\n",iVar8,param_3);
    goto LAB_004c6606;
  }
  iVar8 = clientGetResourceRef_IMPL(local_50,param_5,&local_48);
  if ((iVar8 != 0) || (local_48 == 0)) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0xcbb,"_rpcFreePrologue",4,
                 "NVRM: Failed to get resource ref: 0x%x! hObject: 0x%x\n",iVar8,param_5);
    goto LAB_004c6606;
  }
  iVar8 = *(int *)(local_48 + 0x11c);
  if ((*(char *)(param_1 + 0x4913) == '\0') || (*(char *)(param_1 + 0x491e) != '\0')) {
LAB_004c65f0:
    kgrmgrGetGrObjectType_IMPL(iVar8,&local_54);
joined_r0x004c66b0:
    if ((local_54 != 0) || (cVar7 = rmcfg_IsPASCAL_CLASSIC_GPUSorBetter(param_1), cVar7 == '\0'))
    goto LAB_004c6606;
    bVar17 = true;
LAB_004c66d4:
    lVar10 = local_48;
    lVar12 = __nvoc_dynamicCast(*(undefined8 *)(local_48 + 8),__nvoc_class_def_KernelGraphicsObject)
    ;
    if (lVar12 == 0) {
      nvAssertFailedNoLog("pKernelGraphicsObject != NULL","src/kernel/vgpu/rpc.c",0xc6b);
      uVar16 = 0x31;
    }
    else {
      lVar3 = *(long *)(lVar12 + 0x208);
      if (lVar3 == 0) {
        nvAssertFailedNoLog("pKernelGraphicsContext != NULL","src/kernel/vgpu/rpc.c",0xc6d);
      }
      else {
        lVar10 = *(long *)(lVar10 + 0x18);
        if (lVar10 == 0) {
          nvAssertFailedNoLog("pParentRef != NULL","src/kernel/vgpu/rpc.c",0xc73);
        }
        else {
          lVar4 = *(long *)(lVar10 + 0x18);
          if (lVar4 != 0) {
            pcVar5 = *(char **)(lVar3 + 0x150);
            if ((pcVar5 == (char *)0x0) || (*pcVar5 == '\0')) {
              nvDbg_Printf("src/kernel/vgpu/rpc.c",0xc82,"_rpcFreeBuffersForKGrObj",4,
                           "NVRM: No vGPU GFxP buffers associated! hChannel: 0x%x\n",
                           *(undefined4 *)(lVar10 + 0x10));
            }
            else {
              if (*(int *)(pcVar5 + 4) == 0) {
                nvAssertFailedNoLog("pVgpuGfxpBuffers->refCountChannel != 0","src/kernel/vgpu/rpc.c"
                                    ,0xc7a);
                uVar16 = 0x40;
                goto LAB_004c69bd;
              }
              *(int *)(pcVar5 + 4) = *(int *)(pcVar5 + 4) + -1;
              *(char **)(lVar3 + 0x150) = pcVar5;
              if (*(int *)(pcVar5 + 4) == 0) {
                lVar13 = __nvoc_dynamicCast(*(undefined8 *)(lVar4 + 8),
                                            __nvoc_class_def_KernelChannelGroupApi);
                if (lVar13 != 0) {
                  lVar10 = lVar4;
                }
                _freeGfxpBuffer(param_1,*(undefined8 *)(*(long *)(lVar12 + 0x1c0) + 0xe8),
                                *(undefined4 *)(lVar10 + 0x10),lVar3);
              }
            }
            goto LAB_004c67c0;
          }
          nvAssertFailedNoLog("pChannelParentRef != NULL","src/kernel/vgpu/rpc.c",0xc75);
        }
      }
      uVar16 = 0x36;
    }
LAB_004c69bd:
    nvAssertOkFailedNoLog
              (uVar16,"_rpcFreeBuffersForKGrObj(pGpu, pRsClient, pResourceRef)",
               "src/kernel/vgpu/rpc.c",0xd0d);
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0xd1e,__FUNCTION___106,4,
                 "NVRM: RPC Free prologue failed: 0x%x!\n",uVar16);
  }
  else {
    lVar10 = __nvoc_dynamicCast(*(undefined8 *)(local_48 + 8),__nvoc_class_def_Memory);
    if (lVar10 != 0) {
      iVar1 = *(int *)(lVar10 + 0xfc);
      if (iVar1 == 0x40) {
        uVar16 = *(undefined4 *)(param_1 + 0x3b18);
        uVar15 = *(undefined4 *)(param_1 + 0x3b1c);
        uVar14 = *(undefined4 *)(param_1 + 0x3b20);
        if ((*(long *)(param_1 + 0x1bc0) != 0) &&
           (cVar7 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1), cVar7 != '\0')) {
          if (*(long *)(lVar10 + 0xe0) == 0) {
            nvCheckFailedNoLog(4,"pMemory->pDevice != NULL","src/kernel/vgpu/rpc.c",0xcdf);
            iVar8 = 0x40;
          }
          else {
            uVar15 = *(undefined4 *)
                      (*(long *)(*(long *)(*(long *)(lVar10 + 0xe0) + 0x110) + 0x48) + 0x10);
            iVar8 = subdeviceGetByInstance_IMPL(local_50,uVar15,0,local_40);
            if (iVar8 == 0) {
              if (local_40[0] == 0) {
                    /* WARNING: Does not return */
                pcVar6 = (code *)invalidInstructionException();
                (*pcVar6)();
              }
              uVar14 = *(undefined4 *)(*(long *)(*(long *)(local_40[0] + 0x140) + 0x48) + 0x10);
              uVar16 = param_3;
              goto LAB_004c692a;
            }
            nvCheckOkFailedNoLog
                      (4,iVar8,
                       "subdeviceGetByInstance(pRsClient, hDeviceLocal, 0, &pSubdeviceLocal)",
                       "src/kernel/vgpu/rpc.c",0xce4);
          }
          nvDbg_Printf("src/kernel/vgpu/rpc.c",0xd1e,__FUNCTION___106,4,
                       "NVRM: RPC Free prologue failed: 0x%x!\n",iVar8);
          return 0;
        }
LAB_004c692a:
        iVar8 = updateHostVgpuFbUsage(param_1,uVar16,uVar15,uVar14);
        if (iVar8 != 0) {
          nvDbg_Printf("src/kernel/vgpu/rpc.c",0xced,"_rpcFreePrologue",4,
                       "NVRM: Failed to update FB usage to host : 0x%x\n",iVar8);
          return 0;
        }
        return 0;
      }
      if (iVar1 == 0x50a0) {
        return 0;
      }
      if (iVar1 == 0x3e) {
        return 0;
      }
      if (iVar1 == 0x71) {
        return 0;
      }
    }
    if (iVar8 == 0x79) {
      if (*(int *)(*(long *)(local_48 + 0x18) + 0x11c) == 2) {
        return 0;
      }
      kgrmgrGetGrObjectType_IMPL(0x79,&local_54);
      goto joined_r0x004c66b0;
    }
    if (((*(char *)(param_1 + 0x4913) == '\0') || (*(char *)(param_1 + 0x491e) != '\0')) ||
       (iVar8 != 0x70)) goto LAB_004c65f0;
    bVar17 = *(char *)(param_1 + 0x4922) == '\0';
    kgrmgrGetGrObjectType_IMPL(0x70,&local_54);
    if ((local_54 == 0) && (cVar7 = rmcfg_IsPASCAL_CLASSIC_GPUSorBetter(param_1), cVar7 != '\0'))
    goto LAB_004c66d4;
  }
LAB_004c67c0:
  if (!bVar17) {
    return 0;
  }
LAB_004c6606:
  uVar9 = rpcWriteCommonHeader(param_1,param_2,10,0x10);
  if (uVar9 == 0) {
    *(undefined4 *)(lVar2 + 0x20) = param_3;
    *(undefined4 *)(lVar2 + 0x28) = param_5;
    *(undefined4 *)(lVar2 + 0x24) = param_4;
    uVar11 = _issueRpcAndWait(param_1,param_2);
    return uVar11;
  }
  return (ulong)uVar9;
}


// ===== 004c6afb _allocateGfxpBuffer.cold =====

void _allocateGfxpBuffer_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 004c6b10 _allocateGfxpBuffer =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

void _allocateGfxpBuffer(long param_1,long param_2,undefined4 param_3,long param_4,long param_5)

{
  undefined4 uVar1;
  code *pcVar2;
  bool bVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  undefined1 *puVar10;
  long lVar11;
  long lVar12;
  undefined4 local_160;
  undefined4 local_15c;
  long local_158;
  ulong local_150 [5];
  undefined8 local_128;
  undefined8 local_120;
  ulong local_118;
  ulong local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined4 local_d0;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined4 local_a0;
  ulong local_78;
  ulong local_70;
  undefined4 local_4c;
  
  if (param_2 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar11 = **(long **)(*(long *)(param_2 + 0x110) + 0x48);
  local_158 = 0;
  lVar8 = rmapiGetInterface(4);
  local_150[0] = 0;
  local_150[1] = 0;
  local_150[2] = 0;
  local_150[3] = 0;
  local_150[4] = 0;
  if ((param_1 != 0 && param_4 != 0) && (lVar11 != 0)) {
    if (*(long *)(param_5 + 0x150) != 0) {
      nvAssertFailedNoLog("kgrctxGetVgpuGfxpBuffers(pGpu, pKernelGraphicsContext) == NULL",
                          "src/kernel/vgpu/rpc.c",0xe32);
    }
    uVar5 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
    lVar9 = gpuGetStaticInfo(param_1);
    if (lVar9 == 0) {
      nvAssertFailedNoLog("pVSI != NULL","src/kernel/vgpu/rpc.c",0xe38);
    }
    else {
      uVar1 = *(undefined4 *)(lVar11 + 0x48);
      puVar10 = (undefined1 *)portMemAllocNonPaged(0x58);
      if (puVar10 != (undefined1 *)0x0) {
        portMemSet(puVar10,0,0x58);
        bVar3 = false;
        lVar12 = 0;
        lVar9 = lVar9 + (ulong)(*(int *)(param_4 + 0x42c) + -1 +
                               (uint)(*(int *)(param_4 + 0x42c) == 0)) * 0xd0;
        do {
          local_128 = 0;
          local_120 = 0;
          local_118 = 0;
          local_110 = 0;
          local_108 = 0;
          local_100 = 0;
          local_f8 = 0;
          local_f0 = 0;
          if (*(int *)(lVar9 + 0xb7f4) != 0) {
            iVar6 = clientGenResourceHandle_IMPL(lVar11,&local_160);
            if (iVar6 != 0) {
              nvDbg_Printf("src/kernel/vgpu/rpc.c",0xe59,"_allocateGfxpBuffer",4,
                           "NVRM: cannot get unique memory handle for vidmem : %x\n",iVar6);
              goto LAB_004c711e;
            }
            portMemSet(&local_b8,0,0x80);
            local_b8 = 0xdeaf0006;
            local_78 = (ulong)*(uint *)(lVar9 + 0xb7f4);
            local_b0 = 0x100;
            local_a0 = 0;
            local_70 = (ulong)*(uint *)(lVar9 + 0xb7f8);
            cVar4 = rmGpuLockIsOwner();
            if (cVar4 == '\0') {
              iVar6 = (**(code **)(lVar8 + 8))
                                (lVar8,uVar1,
                                 *(undefined4 *)
                                  (*(long *)(*(long *)(param_2 + 0x110) + 0x48) + 0x10),local_160,
                                 0x40,&local_b8,0x80);
              if (bVar3) goto LAB_004c70c5;
            }
            else {
              rmGpuLocksRelease(0,0);
              iVar6 = (**(code **)(lVar8 + 8))
                                (lVar8,uVar1,
                                 *(undefined4 *)
                                  (*(long *)(*(long *)(param_2 + 0x110) + 0x48) + 0x10),local_160,
                                 0x40,&local_b8,0x80);
LAB_004c70c5:
              iVar7 = rmGpuLocksAcquire(0,0x8002);
              if (iVar7 != 0) {
                nvDbg_Printf("src/kernel/vgpu/rpc.c",0xe80,"_allocateGfxpBuffer",4,
                             "NVRM: failed to acquire lock\n");
                goto LAB_004c711e;
              }
              bVar3 = true;
            }
            if (iVar6 != 0) {
              nvDbg_Printf("src/kernel/vgpu/rpc.c",0xe88,"_allocateGfxpBuffer",4,
                           "NVRM: Failed to allocate vidmem for gfxp: 0x%x\n");
              goto LAB_004c711e;
            }
            *(undefined4 *)(puVar10 + lVar12 + 8) = local_160;
            iVar6 = clientGenResourceHandle_IMPL(lVar11,&local_15c);
            if (iVar6 != 0) {
              nvDbg_Printf("src/kernel/vgpu/rpc.c",0xe91,"_allocateGfxpBuffer",4,
                           "NVRM: cannot get unique memory handle for virtmem : %x\n",iVar6);
              goto LAB_004c711e;
            }
            portMemSet(&local_b8,0,0x80);
            local_b8 = 0xdeaf0006;
            local_78 = (ulong)*(uint *)(lVar9 + 0xb7f4);
            local_a0 = 0x6000000;
            local_4c = *(undefined4 *)(param_4 + 0x298);
            local_b0 = 0x80100;
            local_70 = (ulong)*(uint *)(lVar9 + 0xb7f8);
            iVar6 = (**(code **)(lVar8 + 8))
                              (lVar8,uVar1,
                               *(undefined4 *)(*(long *)(*(long *)(param_2 + 0x110) + 0x48) + 0x10),
                               local_15c,0x50a0,&local_b8,0x80);
            if (iVar6 != 0) {
              nvDbg_Printf("src/kernel/vgpu/rpc.c",0xeac,"_allocateGfxpBuffer",4,
                           "NVRM: Call to allocate virtmem for gfxp failed : %x\n",iVar6);
              goto LAB_004c711e;
            }
            *(undefined4 *)(puVar10 + lVar12 + 0x1c) = local_15c;
            local_120 = CONCAT44(local_160,local_15c);
            local_128 = CONCAT44(*(undefined4 *)
                                  (*(long *)(*(long *)(param_2 + 0x110) + 0x48) + 0x10),uVar1);
            local_110 = (ulong)*(uint *)(lVar9 + 0xb7f4);
            iVar6 = (**(code **)(lVar8 + 0x98))(lVar8,&local_128);
            if (iVar6 != 0) {
              nvDbg_Printf("src/kernel/vgpu/rpc.c",0xebd,"_allocateGfxpBuffer",4,
                           "NVRM: Call to map gfxp buffer to gpu va failed : %x\n",iVar6);
              goto LAB_004c711e;
            }
            *(undefined8 *)((long)local_150 + lVar12 * 2) = local_f8;
            *(undefined8 *)(puVar10 + lVar12 * 2 + 0x30) = local_f8;
          }
          lVar12 = lVar12 + 4;
          lVar9 = lVar9 + 8;
        } while (lVar12 != 0x14);
        iVar6 = subdeviceGetByInstance_IMPL
                          (lVar11,*(undefined4 *)
                                   (*(long *)(*(long *)(param_2 + 0x110) + 0x48) + 0x10),uVar5,
                           &local_158);
        if (iVar6 == 0) {
          portMemSet(&local_128,0,0x70);
          local_d0 = 1;
          local_128 = CONCAT44(uVar1,2);
          local_120 = CONCAT44(local_120._4_4_,param_3);
          local_118 = local_150[0];
          local_110 = local_150[1];
          local_108 = local_150[2];
          local_100 = local_150[3];
          local_f8 = local_150[4];
          lVar11 = gpuGetRpc(param_1);
          if (lVar11 == 0) {
            nvAssertFailedNoLog("pRpc != NULL","src/kernel/vgpu/rpc.c",0xeda);
            iVar6 = 0x1a;
          }
          else {
            if ((*(char *)(param_1 + 0x909) == '\0') && (*(char *)(param_1 + 0x90a) == '\0')) {
              if (local_158 == 0) {
_allocateGfxpBuffer_cold:
                    /* WARNING: Does not return */
                pcVar2 = (code *)invalidInstructionException();
                (*pcVar2)();
              }
              iVar6 = rpcDmaControl_wrapper
                                (param_1,lVar11,uVar1,
                                 *(undefined4 *)
                                  (*(long *)(*(long *)(local_158 + 0x140) + 0x48) + 0x10),0x20801211
                                 ,&local_128,0x70);
            }
            else {
              if (local_158 == 0) goto _allocateGfxpBuffer_cold;
              iVar6 = (**(code **)(param_1 + 0x3b90))
                                (param_1 + 0x3b58,uVar1,
                                 *(undefined4 *)
                                  (*(long *)(*(long *)(local_158 + 0x140) + 0x48) + 0x10),0x20801211
                                 ,&local_128,0x70);
            }
            if (iVar6 == 0) {
              *puVar10 = 1;
              *(undefined4 *)(puVar10 + 4) = 1;
              *(undefined1 **)(param_5 + 0x150) = puVar10;
              return;
            }
          }
          nvDbg_Printf("src/kernel/vgpu/rpc.c",0xee3,"_allocateGfxpBuffer",4,
                       "NVRM: NVRM_RPC: rpc call to bind gfxp buffer failed : %x\n",iVar6);
        }
        else {
          nvDbg_Printf("src/kernel/vgpu/rpc.c",0xeca,"_allocateGfxpBuffer",4,
                       "NVRM: cannot get subdevice handle\n");
        }
LAB_004c711e:
        portMemFree(puVar10);
        _freeGfxpBuffer(param_1,param_2,param_3,param_5);
        return;
      }
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0xe3d,"_allocateGfxpBuffer",4,
                   "NVRM: failed to allocate memory for pKernelGraphicsContext->pVgpuGfxpBuffers!\n"
                  );
    }
  }
  return;
}


// ===== 004c7370 _rpcAllocObjectPrologue.constprop.0 =====

int _rpcAllocObjectPrologue_constprop_0
              (long param_1,undefined4 param_2,undefined4 param_3,uint param_4,undefined1 *param_5)

{
  long lVar1;
  long lVar2;
  long lVar3;
  char *pcVar4;
  char cVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  int iVar9;
  int local_4c;
  undefined8 local_48;
  long local_40 [2];
  
  lVar6 = gpuGetStaticInfo();
  if ((*(char *)(param_1 + 0x4913) != '\0') && (*(char *)(param_1 + 0x491e) == '\0')) {
    if (param_4 == 0x70) {
      *param_5 = *(char *)(param_1 + 0x4922) == '\0';
      goto LAB_004c73f0;
    }
    *param_5 = 1;
  }
  if ((param_4 == 0xc076) || (param_4 == 0xc574)) {
    if ((*(char *)(param_1 + 0x909) == '\0') && ((*(byte *)(lVar6 + 0xa72c) & 2) == 0)) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0xf4d,"_rpcAllocObjectPrologue",4,
                   "NVRM: UVM (0x%x) object allocation is not supported\n",param_4);
      return 0x56;
    }
  }
  else if (*(char *)(param_1 + 0x908) != '\0') {
    if (param_4 < 0xc67f) {
      if (param_4 < 0xc670) {
        if (param_4 == 0x73) {
LAB_004c7550:
          nvDbg_Printf("src/kernel/vgpu/rpc.c",0xf62,"_rpcAllocObjectPrologue",4,
                       "NVRM: Display Class (0x%x) object allocation is not supported\n",param_4);
          return 0x56;
        }
      }
      else if ((0x6801UL >> ((ulong)(param_4 - 0xc670) & 0x3f) & 1) != 0) goto LAB_004c7550;
    }
    else if ((param_4 == 0xc770) || (param_4 == 0xc77d)) goto LAB_004c7550;
  }
LAB_004c73f0:
  kgrmgrGetGrObjectType_IMPL(param_4,&local_4c);
  if (local_4c == 0) {
    cVar5 = rmcfg_IsPASCAL_CLASSIC_GPUSorBetter(param_1);
    iVar9 = 0;
    if (cVar5 != '\0') {
      iVar9 = serverGetClientUnderLock(g_resServ,param_2,&local_48);
      if (iVar9 == 0) {
        iVar9 = clientGetResourceRef_IMPL(local_48,param_3,local_40);
        if (iVar9 == 0) {
          lVar6 = __nvoc_dynamicCast(*(undefined8 *)(local_40[0] + 8),
                                     __nvoc_class_def_KernelGraphicsObject);
          if (lVar6 == 0) {
            nvAssertFailedNoLog("pKernelGraphicsObject != NULL","src/kernel/vgpu/rpc.c",0xf09);
          }
          else {
            lVar1 = *(long *)(lVar6 + 0x208);
            if (lVar1 == 0) {
              nvAssertFailedNoLog("pKernelGraphicsContext != NULL","src/kernel/vgpu/rpc.c",0xf0b);
            }
            else {
              lVar2 = *(long *)(local_40[0] + 0x18);
              if (lVar2 == 0) {
                nvAssertFailedNoLog("pParentRef != NULL","src/kernel/vgpu/rpc.c",0xf11);
              }
              else {
                lVar3 = *(long *)(lVar2 + 0x18);
                if (lVar3 != 0) {
                  pcVar4 = *(char **)(lVar1 + 0x150);
                  if ((pcVar4 != (char *)0x0) && (*pcVar4 != '\0')) {
                    *(int *)(pcVar4 + 4) = *(int *)(pcVar4 + 4) + 1;
                    *(char **)(lVar1 + 0x150) = pcVar4;
                    return 0;
                  }
                  uVar7 = __nvoc_dynamicCast(*(undefined8 *)(lVar2 + 8),
                                             __nvoc_class_def_KernelChannel);
                  lVar8 = __nvoc_dynamicCast(*(undefined8 *)(lVar3 + 8),
                                             __nvoc_class_def_KernelChannelGroupApi);
                  if (lVar8 != 0) {
                    lVar2 = lVar3;
                  }
                  _allocateGfxpBuffer(param_1,*(undefined8 *)(*(long *)(lVar6 + 0x1c0) + 0xe8),
                                      *(undefined4 *)(lVar2 + 0x10),uVar7,lVar1);
                  return 0;
                }
                nvAssertFailedNoLog("pChannelParentRef != NULL","src/kernel/vgpu/rpc.c",0xf13);
              }
            }
          }
          iVar9 = 0x36;
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar9,"clientGetResourceRef(pRsClient, hObject, &pResourceRef)",
                     "src/kernel/vgpu/rpc.c",0xf06);
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar9,"serverGetClientUnderLock(&g_resServ, hClient, &pRsClient)",
                   "src/kernel/vgpu/rpc.c",0xf05);
      }
      nvAssertOkFailedNoLog
                (iVar9,"_rpcAllocBuffersForKGrObj(pGpu, hClient, hObject)","src/kernel/vgpu/rpc.c",
                 0xf6f);
    }
  }
  else {
    iVar9 = 0;
  }
  return iVar9;
}


// ===== 004c7700 rpcAllocObject_v2C_01 =====

ulong rpcAllocObject_v2C_01
                (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,int param_6,undefined4 *param_7)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  char local_39 [9];
  
  local_39[0] = '\x01';
  uVar2 = _rpcAllocObjectPrologue_constprop_0(param_1,param_3,param_5,param_6,local_39);
  if (uVar2 == 0) {
    uVar4 = 0;
    if (local_39[0] != '\0') {
      uVar2 = rpcWriteCommonHeader(param_1,param_2,9,0x50);
      uVar4 = (ulong)uVar2;
      if (uVar2 == 0) {
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x28) = param_5;
        *(int *)(*(long *)(param_2 + 0x4d8) + 0x2c) = param_6;
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x30) = 0;
        if (param_7 != (undefined4 *)0x0) {
          if (param_6 != 0xcdfa) {
            iVar3 = _serializeClassParams_v27_00(param_1,param_2,param_6,param_7);
            if (iVar3 != 0) {
              nvDbg_Printf("src/kernel/vgpu/rpc.c",0x10e5,"rpcAllocObject_v2C_01",4,
                           "NVRM: RmAllocObjectEx: vGPU: object RPC skipped (handle = 0x%08x, class = 0x%x) with non-NULL params ptr\n"
                           ,param_5,param_6);
              nvAssertFailedNoLog(&DAT_00d98b20,"src/kernel/vgpu/rpc.c",0x10ea);
              return 0x22;
            }
            uVar2 = _issueRpcAndWait(param_1);
            if (uVar2 != 0) {
              return (ulong)uVar2;
            }
            if (param_6 != 0x9067) {
              return 0;
            }
            param_7[2] = *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x40);
            return 0;
          }
          lVar1 = *(long *)(param_2 + 0x4d8);
          *(undefined4 *)(lVar1 + 0x38) = *param_7;
          *(undefined4 *)(lVar1 + 0x3c) = param_7[1];
          *(undefined4 *)(lVar1 + 0x40) = param_7[2];
          *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x30) = 0xc;
        }
        uVar4 = _issueRpcAndWait(param_1,param_2);
        return uVar4;
      }
    }
  }
  else {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x10cc,"rpcAllocObject_v2C_01",4,
                 "NVRM: Alloc object RPC prologue failed (status: 0x%x) for hObject: 0x%x, hClass: 0x%x, hChannel: 0x%x, hClient: 0x%x\n"
                 ,uVar2,param_5,param_6,param_4,param_3);
    uVar4 = (ulong)uVar2;
  }
  return uVar4;
}


// ===== 004c7910 rpcAllocObject_v2B_04 =====

ulong rpcAllocObject_v2B_04
                (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,int param_6,undefined4 *param_7)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  char local_39 [9];
  
  local_39[0] = '\x01';
  uVar2 = _rpcAllocObjectPrologue_constprop_0(param_1,param_3,param_5,param_6,local_39);
  if (uVar2 == 0) {
    uVar4 = 0;
    if (local_39[0] != '\0') {
      uVar2 = rpcWriteCommonHeader(param_1,param_2,9,0x50);
      uVar4 = (ulong)uVar2;
      if (uVar2 == 0) {
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x28) = param_5;
        *(int *)(*(long *)(param_2 + 0x4d8) + 0x2c) = param_6;
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x30) = 0;
        if (param_7 != (undefined4 *)0x0) {
          if (param_6 != 0xcdfa) {
            iVar3 = _serializeClassParams_v27_00(param_1,param_2,param_6,param_7);
            if (iVar3 != 0) {
              nvDbg_Printf("src/kernel/vgpu/rpc.c",0x10ae,"rpcAllocObject_v2B_04",4,
                           "NVRM: RmAllocObjectEx: vGPU: object RPC skipped (handle = 0x%08x, class = 0x%x) with non-NULL params ptr\n"
                           ,param_5,param_6);
              nvAssertFailedNoLog(&DAT_00d98b20,"src/kernel/vgpu/rpc.c",0x10b3);
              return 0x22;
            }
            uVar2 = _issueRpcAndWait(param_1);
            if (uVar2 != 0) {
              return (ulong)uVar2;
            }
            if (param_6 != 0x9067) {
              return 0;
            }
            param_7[2] = *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x40);
            return 0;
          }
          lVar1 = *(long *)(param_2 + 0x4d8);
          *(undefined4 *)(lVar1 + 0x38) = *param_7;
          *(undefined4 *)(lVar1 + 0x3c) = param_7[1];
          *(undefined4 *)(lVar1 + 0x40) = param_7[2];
          *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x30) = 0xc;
        }
        uVar4 = _issueRpcAndWait(param_1,param_2);
        return uVar4;
      }
    }
  }
  else {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1095,"rpcAllocObject_v2B_04",4,
                 "NVRM: Alloc object RPC prologue failed (status: 0x%x) for hObject: 0x%x, hClass: 0x%x, hChannel: 0x%x, hClient: 0x%x\n"
                 ,uVar2,param_5,param_6,param_4,param_3);
    uVar4 = (ulong)uVar2;
  }
  return uVar4;
}


// ===== 004c7b20 rpcAllocObject_v29_06 =====

ulong rpcAllocObject_v29_06
                (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,int param_6,undefined4 *param_7)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  char local_39 [9];
  
  local_39[0] = '\x01';
  uVar2 = _rpcAllocObjectPrologue_constprop_0(param_1,param_3,param_5,param_6,local_39);
  if (uVar2 == 0) {
    uVar4 = 0;
    if (local_39[0] != '\0') {
      uVar2 = rpcWriteCommonHeader(param_1,param_2,9,0x50);
      uVar4 = (ulong)uVar2;
      if (uVar2 == 0) {
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x28) = param_5;
        *(int *)(*(long *)(param_2 + 0x4d8) + 0x2c) = param_6;
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x30) = 0;
        if (param_7 != (undefined4 *)0x0) {
          if (param_6 != 0xcdfa) {
            iVar3 = _serializeClassParams_v27_00(param_1,param_2,param_6,param_7);
            if (iVar3 != 0) {
              nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1077,"rpcAllocObject_v29_06",4,
                           "NVRM: RmAllocObjectEx: vGPU: object RPC skipped (handle = 0x%08x, class = 0x%x) with non-NULL params ptr\n"
                           ,param_5,param_6);
              nvAssertFailedNoLog(&DAT_00d98b20,"src/kernel/vgpu/rpc.c",0x107c);
              return 0x22;
            }
            uVar2 = _issueRpcAndWait(param_1);
            if (uVar2 != 0) {
              return (ulong)uVar2;
            }
            if (param_6 != 0x9067) {
              return 0;
            }
            param_7[2] = *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x40);
            return 0;
          }
          lVar1 = *(long *)(param_2 + 0x4d8);
          *(undefined4 *)(lVar1 + 0x38) = *param_7;
          *(undefined4 *)(lVar1 + 0x3c) = param_7[1];
          *(undefined4 *)(lVar1 + 0x40) = param_7[2];
          *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x30) = 0xc;
        }
        uVar4 = _issueRpcAndWait(param_1,param_2);
        return uVar4;
      }
    }
  }
  else {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x105e,"rpcAllocObject_v29_06",4,
                 "NVRM: Alloc object RPC prologue failed (status: 0x%x) for hObject: 0x%x, hClass: 0x%x, hChannel: 0x%x, hClient: 0x%x\n"
                 ,uVar2,param_5,param_6,param_4,param_3);
    uVar4 = (ulong)uVar2;
  }
  return uVar4;
}


// ===== 004c7d30 rpcAllocObject_v27_00 =====

ulong rpcAllocObject_v27_00
                (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,int param_6,long param_7)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  char local_39 [9];
  
  local_39[0] = '\x01';
  uVar1 = _rpcAllocObjectPrologue_constprop_0(param_1,param_3,param_5,param_6,local_39);
  if (uVar1 == 0) {
    uVar3 = 0;
    if (local_39[0] != '\0') {
      uVar1 = rpcWriteCommonHeader(param_1,param_2,9,0x50);
      uVar3 = (ulong)uVar1;
      if (uVar1 == 0) {
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x28) = param_5;
        *(int *)(*(long *)(param_2 + 0x4d8) + 0x2c) = param_6;
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x30) = 0;
        if (param_7 == 0) {
          uVar3 = _issueRpcAndWait(param_1,param_2);
          return uVar3;
        }
        iVar2 = _serializeClassParams_v27_00(param_1,param_2,param_6);
        if (iVar2 == 0) {
          uVar1 = _issueRpcAndWait();
          uVar3 = (ulong)uVar1;
          if ((uVar1 == 0) && (param_6 == 0x9067)) {
            *(undefined4 *)(param_7 + 8) = *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x40);
          }
        }
        else {
          nvDbg_Printf("src/kernel/vgpu/rpc.c",0x103f,"rpcAllocObject_v27_00",4,
                       "NVRM: RmAllocObjectEx: vGPU: object RPC skipped (handle = 0x%08x, class = 0x%x) with non-NULL params ptr\n"
                       ,param_5,param_6);
          nvAssertFailedNoLog(&DAT_00d98b20,"src/kernel/vgpu/rpc.c",0x1045);
          uVar3 = 0x22;
        }
      }
    }
  }
  else {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1026,"rpcAllocObject_v27_00",4,
                 "NVRM: Alloc object RPC prologue failed (status: 0x%x) for hObject: 0x%x, hClass: 0x%x, hChannel: 0x%x, hClient: 0x%x\n"
                 ,uVar1,param_5,param_6,param_4,param_3);
    uVar3 = (ulong)uVar1;
  }
  return uVar3;
}


// ===== 004c7f10 rpcAllocObject_v26_00 =====

ulong rpcAllocObject_v26_00
                (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,int param_6,long param_7)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  char local_39 [9];
  
  local_39[0] = '\x01';
  uVar1 = _rpcAllocObjectPrologue_constprop_0(param_1,param_3,param_5,param_6,local_39);
  if (uVar1 == 0) {
    uVar3 = 0;
    if (local_39[0] != '\0') {
      uVar1 = rpcWriteCommonHeader(param_1,param_2,9,0x50);
      uVar3 = (ulong)uVar1;
      if (uVar1 == 0) {
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x28) = param_5;
        *(int *)(*(long *)(param_2 + 0x4d8) + 0x2c) = param_6;
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x30) = 0;
        if (param_7 == 0) {
LAB_004c7ff5:
          uVar3 = _issueRpcAndWait(param_1,param_2);
          return uVar3;
        }
        if (param_6 == 0xcfb7) {
          iVar2 = _serializeClassParams_v(param_1,param_2,0xc9b7,param_7);
        }
        else {
          if (param_6 - 0x2081U < 2) goto LAB_004c7ff5;
          iVar2 = _serializeClassParams_v(param_1,param_2,param_6,param_7);
        }
        if (iVar2 == 0) {
          uVar1 = _issueRpcAndWait(param_1,param_2);
          uVar3 = (ulong)uVar1;
          if ((uVar1 == 0) && (param_6 == 0x9067)) {
            *(undefined4 *)(param_7 + 8) = *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x40);
          }
        }
        else {
          nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1007,"rpcAllocObject_v26_00",4,
                       "NVRM: RmAllocObjectEx: vGPU: object RPC skipped (handle = 0x%08x, class = 0x%x) with non-NULL params ptr\n"
                       ,param_5,param_6);
          nvAssertFailedNoLog(&DAT_00d98b20,"src/kernel/vgpu/rpc.c",0x100d);
          uVar3 = 0x22;
        }
      }
    }
  }
  else {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0xfee,"rpcAllocObject_v26_00",4,
                 "NVRM: Alloc object RPC prologue failed (status: 0x%x) for hObject: 0x%x, hClass: 0x%x, hChannel: 0x%x, hClient: 0x%x\n"
                 ,uVar1,param_5,param_6,param_4,param_3);
    uVar3 = (ulong)uVar1;
  }
  return uVar3;
}


// ===== 004c8120 rpcAllocObject_v25_08 =====

ulong rpcAllocObject_v25_08
                (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,int param_6,long param_7)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  char local_39 [9];
  
  local_39[0] = '\x01';
  uVar1 = _rpcAllocObjectPrologue_constprop_0(param_1,param_3,param_5,param_6,local_39);
  if (uVar1 == 0) {
    uVar3 = 0;
    if (local_39[0] != '\0') {
      uVar1 = rpcWriteCommonHeader(param_1,param_2,9,0x50);
      uVar3 = (ulong)uVar1;
      if (uVar1 == 0) {
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x28) = param_5;
        *(int *)(*(long *)(param_2 + 0x4d8) + 0x2c) = param_6;
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x30) = 0;
        if ((param_7 == 0) || (param_6 - 0x2081U < 2)) {
          uVar3 = _issueRpcAndWait(param_1,param_2);
          return uVar3;
        }
        iVar2 = _serializeClassParams_v(param_1,param_2,param_6);
        if (iVar2 == 0) {
          uVar1 = _issueRpcAndWait();
          uVar3 = (ulong)uVar1;
          if ((uVar1 == 0) && (param_6 == 0x9067)) {
            *(undefined4 *)(param_7 + 8) = *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x40);
          }
        }
        else {
          nvDbg_Printf("src/kernel/vgpu/rpc.c",0xfcf,"rpcAllocObject_v25_08",4,
                       "NVRM: RmAllocObjectEx: vGPU: object RPC skipped (handle = 0x%08x, class = 0x%x) with non-NULL params ptr\n"
                       ,param_5,param_6);
          nvAssertFailedNoLog(&DAT_00d98b20,"src/kernel/vgpu/rpc.c",0xfd5);
          uVar3 = 0x22;
        }
      }
    }
  }
  else {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0xfb6,"rpcAllocObject_v25_08",4,
                 "NVRM: Alloc object RPC prologue failed (status: 0x%x) for hObject: 0x%x, hClass: 0x%x, hChannel: 0x%x, hClient: 0x%x\n"
                 ,uVar1,param_5,param_6,param_4,param_3);
    uVar3 = (ulong)uVar1;
  }
  return uVar3;
}


// ===== 004c8300 rpcDmaControl_v24_05 =====

void rpcDmaControl_v24_05(void)

{
  rpcDmaControl_wrapper();
  return;
}


// ===== 004c8310 rpcCtrlStopChannel_v1A_1E =====

undefined8
rpcCtrlStopChannel_v1A_1E
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined1 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x95,0xc);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined1 *)0x0) {
      *(undefined1 *)(lVar1 + 0x28) = *param_5;
      uVar2 = _issueRpcAndWait(param_1,param_2);
      return uVar2;
    }
    uVar2 = 0x1f;
  }
  return uVar2;
}


// ===== 004c83a0 rpcCtrlGpuEvictCtx_v1A_1C =====

undefined8
rpcCtrlGpuEvictCtx_v1A_1C
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x92,0x1c);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      *(undefined4 *)(lVar1 + 0x2c) = param_5[1];
      *(undefined4 *)(lVar1 + 0x30) = param_5[2];
      *(undefined4 *)(lVar1 + 0x34) = param_5[3];
      *(undefined4 *)(lVar1 + 0x38) = param_5[4];
      uVar2 = _issueRpcAndWait(param_1,param_2);
      return uVar2;
    }
    uVar2 = 0x1f;
  }
  return uVar2;
}


// ===== 004c8460 rpcCtrlFbGetFsInfo_v24_00 =====

int rpcCtrlFbGetFsInfo_v24_00
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,ushort *param_5
              )

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ushort *puVar4;
  ushort *puVar5;
  ushort *puVar6;
  long lVar7;
  long lVar8;
  
  lVar8 = *(long *)(param_2 + 0x4d8);
  iVar3 = rpcWriteCommonHeader(param_1,param_2,0x93,0xf10);
  if (iVar3 != 0) {
    return iVar3;
  }
  *(undefined4 *)(lVar8 + 0x20) = param_3;
  *(undefined4 *)(lVar8 + 0x24) = param_4;
  if ((param_5 != (ushort *)0x0) && (uVar1 = *param_5, uVar1 < 0x79)) {
    *(ushort *)(lVar8 + 0x28) = uVar1;
    if (uVar1 != 0) {
      puVar4 = (ushort *)(lVar8 + 0x30);
      puVar5 = param_5 + 4;
      do {
        while( true ) {
          uVar2 = *puVar5;
          *puVar4 = uVar2;
          if (uVar2 != 6) break;
LAB_004c855b:
          puVar6 = puVar5 + 0x10;
          *(undefined4 *)(puVar4 + 4) = *(undefined4 *)(puVar5 + 4);
          *(undefined4 *)(puVar4 + 6) = *(undefined4 *)(puVar5 + 6);
          puVar4 = puVar4 + 0x10;
          puVar5 = puVar6;
          if (puVar6 == param_5 + (ulong)(uVar1 - 1) * 0x10 + 0x14) goto LAB_004c8574;
        }
        if (uVar2 < 7) {
          if ((((uVar2 == 3) || (3 < uVar2)) || (uVar2 == 1)) || (uVar2 == 2)) goto LAB_004c8640;
        }
        else {
          if (uVar2 != 10) {
            if ((uVar2 < 0xb) || (uVar2 == 0xb)) goto LAB_004c855b;
            if (uVar2 != 0xc) {
              return 0x1f;
            }
          }
LAB_004c8640:
          *(undefined4 *)(puVar4 + 4) = *(undefined4 *)(puVar5 + 4);
        }
        puVar5 = puVar5 + 0x10;
        puVar4 = puVar4 + 0x10;
      } while (puVar5 != param_5 + (ulong)(uVar1 - 1) * 0x10 + 0x14);
    }
LAB_004c8574:
    iVar3 = _issueRpcAndWait(param_1,param_2);
    if (iVar3 != 0) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x13c3,"rpcCtrlFbGetFsInfo_v24_00",4,
                   "NVRM: Get FB FS Info RPC failed with error 0x%x\n");
      return iVar3;
    }
    if (*(ushort *)(lVar8 + 0x28) < 0x79) {
      if (*param_5 == 0) {
        return 0;
      }
      puVar4 = param_5 + (ulong)(*param_5 - 1) * 0x10 + 0x10;
      do {
        while( true ) {
          *(undefined4 *)(param_5 + 6) = *(undefined4 *)(lVar8 + 0x34);
          uVar1 = param_5[4];
          if (uVar1 != 6) break;
LAB_004c8678:
          *(undefined4 *)(param_5 + 0xc) = *(undefined4 *)(lVar8 + 0x40);
joined_r0x004c86d4:
          lVar8 = lVar8 + 0x20;
          param_5 = param_5 + 0x10;
          if (param_5 == puVar4) {
            return 0;
          }
        }
        if (uVar1 < 7) {
          if ((uVar1 == 3) || (3 < uVar1)) goto LAB_004c86a0;
          if (uVar1 == 1) {
LAB_004c86c0:
            *(undefined8 *)(param_5 + 0xc) = *(undefined8 *)(lVar8 + 0x40);
            goto joined_r0x004c86d4;
          }
          lVar7 = 0;
          if (uVar1 == 2) goto LAB_004c86a0;
          do {
            *(undefined1 *)((long)param_5 + lVar7 + 0x10) = *(undefined1 *)(lVar8 + 0x38 + lVar7);
            lVar7 = lVar7 + 1;
          } while (lVar7 != 0x18);
        }
        else {
          if (uVar1 != 10) {
            if (uVar1 < 0xb) goto LAB_004c8678;
            if (uVar1 == 0xb) goto LAB_004c86c0;
            if (uVar1 != 0xc) {
              return 0x1f;
            }
          }
LAB_004c86a0:
          *(undefined4 *)(param_5 + 10) = *(undefined4 *)(lVar8 + 0x3c);
        }
        lVar8 = lVar8 + 0x20;
        param_5 = param_5 + 0x10;
        if (param_5 == puVar4) {
          return 0;
        }
      } while( true );
    }
  }
  return 0x1f;
}


// ===== 004c8720 rpcCtrlFbGetFsInfo_v26_04 =====

int rpcCtrlFbGetFsInfo_v26_04
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,ushort *param_5
              )

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  long lVar4;
  ushort *puVar5;
  ushort *puVar6;
  long lVar7;
  
  lVar7 = *(long *)(param_2 + 0x4d8);
  iVar3 = rpcWriteCommonHeader(param_1,param_2,0x93,0xf10);
  if (iVar3 != 0) {
    return iVar3;
  }
  *(undefined4 *)(lVar7 + 0x20) = param_3;
  *(undefined4 *)(lVar7 + 0x24) = param_4;
  if ((param_5 != (ushort *)0x0) && (uVar1 = *param_5, uVar1 < 0x79)) {
    *(ushort *)(lVar7 + 0x28) = uVar1;
    if (uVar1 != 0) {
      puVar6 = param_5 + 4;
      puVar5 = (ushort *)(lVar7 + 0x30);
      do {
        uVar2 = *puVar6;
        *puVar5 = uVar2;
        if (uVar2 == 8) goto LAB_004c8940;
        if (uVar2 < 9) {
          if (uVar2 == 4) goto LAB_004c8800;
          if (uVar2 < 5) {
            if (((uVar2 == 2) || (uVar2 == 3)) || (uVar2 != 0)) goto LAB_004c8800;
          }
          else {
            if (uVar2 == 6) goto LAB_004c8940;
            if (uVar2 != 7) goto LAB_004c8800;
            *(undefined4 *)(puVar5 + 4) = *(undefined4 *)(puVar6 + 4);
            *(undefined4 *)(puVar5 + 6) = *(undefined4 *)(puVar6 + 6);
          }
        }
        else {
          if (uVar2 != 0xd) {
            if (uVar2 < 0xe) {
              if ((uVar2 == 0xb) || ((uVar2 != 0xc && (uVar2 == 9)))) {
LAB_004c8940:
                *(undefined4 *)(puVar5 + 4) = *(undefined4 *)(puVar6 + 4);
                *(undefined4 *)(puVar5 + 6) = *(undefined4 *)(puVar6 + 6);
                goto LAB_004c8806;
              }
            }
            else if (uVar2 != 0xf) {
              if (uVar2 == 0x10) goto LAB_004c8940;
              if (uVar2 != 0xe) {
                return 0x1f;
              }
            }
          }
LAB_004c8800:
          *(undefined4 *)(puVar5 + 4) = *(undefined4 *)(puVar6 + 4);
        }
LAB_004c8806:
        puVar6 = puVar6 + 0x10;
        puVar5 = puVar5 + 0x10;
      } while (puVar6 != param_5 + (ulong)(uVar1 - 1) * 0x10 + 0x14);
    }
    iVar3 = _issueRpcAndWait(param_1,param_2);
    if (iVar3 != 0) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x13e4,"rpcCtrlFbGetFsInfo_v26_04",4,
                   "NVRM: Get FB FS Info RPC failed with error 0x%x\n");
      return iVar3;
    }
    if (*(ushort *)(lVar7 + 0x28) < 0x79) {
      if (*param_5 == 0) {
        return 0;
      }
      puVar5 = param_5 + (ulong)(*param_5 - 1) * 0x10 + 0x10;
      do {
        *(undefined4 *)(param_5 + 6) = *(undefined4 *)(lVar7 + 0x34);
        uVar1 = param_5[4];
        if (uVar1 == 8) {
LAB_004c8990:
          *(undefined4 *)(param_5 + 0xc) = *(undefined4 *)(lVar7 + 0x40);
        }
        else {
          if (uVar1 < 9) {
            if (uVar1 != 4) {
              if (uVar1 < 5) {
                if ((uVar1 != 2) && (uVar1 != 3)) {
                  if (uVar1 != 0) goto LAB_004c8879;
                  lVar4 = 0;
                  do {
                    *(undefined1 *)((long)param_5 + lVar4 + 0x10) =
                         *(undefined1 *)(lVar7 + 0x38 + lVar4);
                    lVar4 = lVar4 + 1;
                  } while (lVar4 != 0x18);
                  goto LAB_004c8881;
                }
              }
              else if ((uVar1 == 6) || (uVar1 == 7)) goto LAB_004c8990;
            }
          }
          else if (uVar1 != 0xd) {
            if (uVar1 < 0xe) {
              if (uVar1 == 0xb) {
LAB_004c8879:
                *(undefined8 *)(param_5 + 0xc) = *(undefined8 *)(lVar7 + 0x40);
                goto LAB_004c8881;
              }
              if ((uVar1 != 0xc) && (uVar1 == 9)) goto LAB_004c8990;
            }
            else {
              if ((uVar1 == 0xf) || (uVar1 == 0x10)) goto LAB_004c8879;
              if (uVar1 != 0xe) {
                return 0x1f;
              }
            }
          }
          *(undefined4 *)(param_5 + 10) = *(undefined4 *)(lVar7 + 0x3c);
        }
LAB_004c8881:
        param_5 = param_5 + 0x10;
        lVar7 = lVar7 + 0x20;
        if (param_5 == puVar5) {
          return 0;
        }
      } while( true );
    }
  }
  return 0x1f;
}


// ===== 004c8a40 rpcCtrlFbGetFsInfo_v2B_07 =====

int rpcCtrlFbGetFsInfo_v2B_07
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,ushort *param_5
              )

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  long lVar4;
  ushort *puVar5;
  ushort *puVar6;
  long lVar7;
  
  lVar7 = *(long *)(param_2 + 0x4d8);
  iVar3 = rpcWriteCommonHeader(param_1,param_2,0x93,0xf10);
  if (iVar3 != 0) {
    return iVar3;
  }
  *(undefined4 *)(lVar7 + 0x20) = param_3;
  *(undefined4 *)(lVar7 + 0x24) = param_4;
  if ((param_5 != (ushort *)0x0) && (uVar1 = *param_5, uVar1 < 0x79)) {
    *(ushort *)(lVar7 + 0x28) = uVar1;
    if (uVar1 != 0) {
      puVar6 = param_5 + 4;
      puVar5 = (ushort *)(lVar7 + 0x30);
      do {
        uVar2 = *puVar6;
        *puVar5 = uVar2;
        if (uVar2 == 9) {
LAB_004c8c4a:
          *(undefined4 *)(puVar5 + 4) = *(undefined4 *)(puVar6 + 4);
          *(undefined4 *)(puVar5 + 6) = *(undefined4 *)(puVar6 + 6);
          goto LAB_004c8b26;
        }
        if (uVar2 < 10) {
          if (uVar2 == 4) goto LAB_004c8b20;
          if (uVar2 < 5) {
            if (((uVar2 == 2) || (uVar2 == 3)) || (uVar2 != 0)) goto LAB_004c8b20;
          }
          else {
            if ((uVar2 == 7) || (uVar2 == 8)) goto LAB_004c8c4a;
            if (uVar2 == 5) goto LAB_004c8b20;
            *(undefined4 *)(puVar5 + 4) = *(undefined4 *)(puVar6 + 4);
            *(undefined4 *)(puVar5 + 6) = *(undefined4 *)(puVar6 + 6);
          }
        }
        else {
          if (uVar2 != 0xe) {
            if (uVar2 < 0xf) {
              if (((uVar2 != 0xc) && (uVar2 != 0xd)) && (uVar2 != 10)) goto LAB_004c8c4a;
            }
            else if (uVar2 != 0x11) {
              if (uVar2 < 0x12) {
                if (uVar2 != 0xf) {
                  *(undefined4 *)(puVar5 + 4) = *(undefined4 *)(puVar6 + 4);
                  *(undefined4 *)(puVar5 + 6) = *(undefined4 *)(puVar6 + 6);
                  goto LAB_004c8b26;
                }
              }
              else if (uVar2 != 0x12) {
                return 0x1f;
              }
            }
          }
LAB_004c8b20:
          *(undefined4 *)(puVar5 + 4) = *(undefined4 *)(puVar6 + 4);
        }
LAB_004c8b26:
        puVar6 = puVar6 + 0x10;
        puVar5 = puVar5 + 0x10;
      } while (puVar6 != param_5 + (ulong)(uVar1 - 1) * 0x10 + 0x14);
    }
    iVar3 = _issueRpcAndWait(param_1,param_2);
    if (iVar3 != 0) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1405,"rpcCtrlFbGetFsInfo_v2B_07",4,
                   "NVRM: Get FB FS Info RPC failed with error 0x%x\n");
      return iVar3;
    }
    if (*(ushort *)(lVar7 + 0x28) < 0x79) {
      if (*param_5 == 0) {
        return 0;
      }
      puVar5 = param_5 + (ulong)(*param_5 - 1) * 0x10 + 0x10;
      do {
        *(undefined4 *)(param_5 + 6) = *(undefined4 *)(lVar7 + 0x34);
        uVar1 = param_5[4];
        if (uVar1 == 9) {
LAB_004c8cd6:
          *(undefined4 *)(param_5 + 0xc) = *(undefined4 *)(lVar7 + 0x40);
        }
        else {
          if (uVar1 < 10) {
            if (uVar1 != 4) {
              if (uVar1 < 5) {
                if ((uVar1 != 2) && (uVar1 != 3)) {
                  if (uVar1 != 0) goto LAB_004c8ba0;
                  lVar4 = 0;
                  do {
                    *(undefined1 *)((long)param_5 + lVar4 + 0x10) =
                         *(undefined1 *)(lVar7 + 0x38 + lVar4);
                    lVar4 = lVar4 + 1;
                  } while (lVar4 != 0x18);
                  goto LAB_004c8ba8;
                }
              }
              else if (((uVar1 == 7) || (uVar1 == 8)) || (uVar1 != 5)) goto LAB_004c8cd6;
            }
          }
          else if (uVar1 != 0xe) {
            if (uVar1 < 0xf) {
              if (((uVar1 == 0xc) || (uVar1 == 0xd)) || (uVar1 == 10)) goto LAB_004c8bf0;
            }
            else if (((uVar1 != 0x11) && (0x11 < uVar1)) && (uVar1 != 0x12)) {
              return 0x1f;
            }
LAB_004c8ba0:
            *(undefined8 *)(param_5 + 0xc) = *(undefined8 *)(lVar7 + 0x40);
            goto LAB_004c8ba8;
          }
LAB_004c8bf0:
          *(undefined4 *)(param_5 + 10) = *(undefined4 *)(lVar7 + 0x3c);
        }
LAB_004c8ba8:
        param_5 = param_5 + 0x10;
        lVar7 = lVar7 + 0x20;
        if (param_5 == puVar5) {
          return 0;
        }
      } while( true );
    }
  }
  return 0x1f;
}


// ===== 004c8d80 rpcCtrlGrmgrGetGrFsInfo_v1A_1D =====

int rpcCtrlGrmgrGetGrFsInfo_v1A_1D
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,ushort *param_5
              )

{
  ushort uVar1;
  ushort uVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  ushort *puVar8;
  ulong uVar9;
  long lVar10;
  
  lVar3 = *(long *)(param_2 + 0x4d8);
  iVar4 = rpcWriteCommonHeader(param_1,param_2,0x94,0x790);
  if (iVar4 != 0) {
    return iVar4;
  }
  *(undefined4 *)(lVar3 + 0x20) = param_3;
  *(undefined4 *)(lVar3 + 0x24) = param_4;
  if ((param_5 != (ushort *)0x0) && (uVar1 = *param_5, uVar1 < 0x61)) {
    *(ushort *)(lVar3 + 0x28) = uVar1;
    if (uVar1 != 0) {
      puVar8 = param_5 + 4;
      puVar7 = (ushort *)(lVar3 + 0x30);
      do {
        uVar2 = *puVar8;
        *puVar7 = uVar2;
        if (uVar2 == 5) {
LAB_004c8f60:
          *(undefined4 *)(puVar7 + 4) = *(undefined4 *)(puVar8 + 4);
          *(undefined4 *)(puVar7 + 6) = *(undefined4 *)(puVar8 + 6);
        }
        else if (uVar2 < 6) {
          if ((uVar2 != 3) && (uVar2 != 4)) {
            if (uVar2 == 1) goto LAB_004c8e58;
            if (uVar2 != 2) {
              return 0x1f;
            }
          }
LAB_004c8e52:
          *(undefined4 *)(puVar7 + 4) = *(undefined4 *)(puVar8 + 4);
        }
        else {
          if (uVar2 == 8) goto LAB_004c8f60;
          if (uVar2 < 9) {
            if (uVar2 != 6) {
              puVar7[4] = puVar8[4];
            }
          }
          else if (uVar2 != 9) {
            if (uVar2 != 10) {
              return 0x1f;
            }
            goto LAB_004c8e52;
          }
        }
LAB_004c8e58:
        puVar8 = puVar8 + 10;
        puVar7 = puVar7 + 10;
      } while (puVar8 != param_5 + (ulong)(uVar1 - 1) * 10 + 0xe);
    }
    iVar4 = _issueRpcAndWait(param_1,param_2);
    if (iVar4 != 0) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1426,"rpcCtrlGrmgrGetGrFsInfo_v1A_1D",4,
                   "NVRM: Get GR FS Info RPC failed with error 0x%x\n");
      return iVar4;
    }
    if (*(ushort *)(lVar3 + 0x28) < 0x61) {
      uVar1 = *param_5;
      if (uVar1 == 0) {
        return 0;
      }
      uVar5 = 0;
      do {
        uVar9 = (ulong)uVar5;
        lVar10 = lVar3 + uVar9 * 0x14;
        *(undefined4 *)(param_5 + uVar9 * 10 + 6) = *(undefined4 *)(lVar10 + 0x34);
        uVar2 = param_5[uVar9 * 10 + 4];
        if (uVar2 == 6) {
LAB_004c8f78:
          uVar5 = uVar5 + 1;
          *(undefined4 *)(param_5 + uVar9 * 10 + 8) = *(undefined4 *)(lVar10 + 0x38);
        }
        else if (uVar2 < 7) {
          if (uVar2 != 3) {
            if (uVar2 < 4) {
              if (uVar2 == 1) goto LAB_004c8f78;
              if (uVar2 != 2) {
                return 0x1f;
              }
            }
            else if (uVar2 != 4) goto LAB_004c8f0a;
          }
LAB_004c8ebc:
          uVar5 = uVar5 + 1;
          *(undefined4 *)(param_5 + uVar9 * 10 + 10) = *(undefined4 *)(lVar10 + 0x3c);
        }
        else {
          if (uVar2 == 9) goto LAB_004c8f78;
          if (9 < uVar2) {
            if (uVar2 != 10) {
              return 0x1f;
            }
            goto LAB_004c8ebc;
          }
          if (uVar2 == 7) {
            uVar2 = *(ushort *)(lVar10 + 0x3a);
            param_5[uVar9 * 10 + 9] = uVar2;
            if (8 < uVar2) {
              return 0x1f;
            }
            if (param_5[9] == 0) {
              uVar5 = 1;
            }
            else {
              lVar10 = 0;
              puVar7 = param_5 + 0x13;
              uVar6 = 0;
              do {
                uVar5 = uVar6;
                *(undefined1 *)((long)param_5 + lVar10 + 0x14) =
                     *(undefined1 *)(lVar3 + 0x3c + lVar10);
                uVar2 = *puVar7;
                uVar6 = uVar5 + 1;
                lVar10 = lVar10 + 0x15;
                puVar7 = puVar7 + 10;
              } while (uVar6 < uVar2);
              uVar5 = uVar5 + 2;
            }
          }
          else {
LAB_004c8f0a:
            uVar5 = uVar5 + 1;
            *(undefined4 *)(param_5 + uVar9 * 10 + 0xc) = *(undefined4 *)(lVar10 + 0x40);
          }
        }
        if (uVar1 <= uVar5) {
          return 0;
        }
      } while( true );
    }
  }
  return 0x1f;
}


// ===== 004c9080 rpcCtrlGrmgrGetGrFsInfo_v2B_09 =====

int rpcCtrlGrmgrGetGrFsInfo_v2B_09
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,ushort *param_5
              )

{
  ushort uVar1;
  ushort uVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  ushort *puVar8;
  ulong uVar9;
  long lVar10;
  
  lVar3 = *(long *)(param_2 + 0x4d8);
  iVar4 = rpcWriteCommonHeader(param_1,param_2,0x94,0x790);
  if (iVar4 != 0) {
    return iVar4;
  }
  *(undefined4 *)(lVar3 + 0x20) = param_3;
  *(undefined4 *)(lVar3 + 0x24) = param_4;
  if ((param_5 != (ushort *)0x0) && (uVar1 = *param_5, uVar1 < 0x61)) {
    *(ushort *)(lVar3 + 0x28) = uVar1;
    if (uVar1 != 0) {
      puVar8 = param_5 + 4;
      puVar7 = (ushort *)(lVar3 + 0x30);
      do {
        uVar2 = *puVar8;
        *puVar7 = uVar2;
        if (uVar2 == 7) {
          puVar7[4] = puVar8[4];
          goto LAB_004c9158;
        }
        if (uVar2 < 8) {
          if (uVar2 == 4) goto LAB_004c9152;
          if (uVar2 < 5) {
            if ((uVar2 == 2) || (uVar2 == 3)) goto LAB_004c9152;
            if (uVar2 != 1) {
              return 0x1f;
            }
          }
          else if (uVar2 == 5) {
            *(undefined4 *)(puVar7 + 4) = *(undefined4 *)(puVar8 + 4);
            *(undefined4 *)(puVar7 + 6) = *(undefined4 *)(puVar8 + 6);
          }
        }
        else {
          if (uVar2 != 10) {
            if (uVar2 < 0xb) {
              if (uVar2 == 8) goto LAB_004c9266;
            }
            else if (uVar2 != 0xb) {
              if (uVar2 != 0xc) {
                return 0x1f;
              }
LAB_004c9266:
              *(undefined4 *)(puVar7 + 4) = *(undefined4 *)(puVar8 + 4);
              *(undefined4 *)(puVar7 + 6) = *(undefined4 *)(puVar8 + 6);
            }
            goto LAB_004c9158;
          }
LAB_004c9152:
          *(undefined4 *)(puVar7 + 4) = *(undefined4 *)(puVar8 + 4);
        }
LAB_004c9158:
        puVar8 = puVar8 + 10;
        puVar7 = puVar7 + 10;
      } while (puVar8 != param_5 + (ulong)(uVar1 - 1) * 10 + 0xe);
    }
    iVar4 = _issueRpcAndWait(param_1,param_2);
    if (iVar4 != 0) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1447,"rpcCtrlGrmgrGetGrFsInfo_v2B_09",4,
                   "NVRM: Get GR FS Info RPC failed with error 0x%x\n");
      return iVar4;
    }
    if (*(ushort *)(lVar3 + 0x28) < 0x61) {
      uVar1 = *param_5;
      if (uVar1 == 0) {
        return 0;
      }
      uVar5 = 0;
      do {
        uVar9 = (ulong)uVar5;
        lVar10 = lVar3 + uVar9 * 0x14;
        *(undefined4 *)(param_5 + uVar9 * 10 + 6) = *(undefined4 *)(lVar10 + 0x34);
        uVar2 = param_5[uVar9 * 10 + 4];
        if (uVar2 == 7) {
          uVar2 = *(ushort *)(lVar10 + 0x3a);
          param_5[uVar9 * 10 + 9] = uVar2;
          if (8 < uVar2) {
            return 0x1f;
          }
          if (param_5[9] == 0) {
            uVar5 = 1;
          }
          else {
            lVar10 = 0;
            puVar8 = param_5 + 0x13;
            uVar6 = 0;
            do {
              uVar5 = uVar6;
              *(undefined1 *)((long)param_5 + lVar10 + 0x14) =
                   *(undefined1 *)(lVar3 + 0x3c + lVar10);
              uVar2 = *puVar8;
              uVar6 = uVar5 + 1;
              lVar10 = lVar10 + 0x15;
              puVar8 = puVar8 + 10;
            } while (uVar6 < uVar2);
            uVar5 = uVar5 + 2;
          }
        }
        else if (uVar2 < 8) {
          if (uVar2 == 4) goto LAB_004c92b0;
          if (uVar2 < 5) {
            if ((uVar2 == 2) || (uVar2 == 3)) goto LAB_004c92b0;
            if (uVar2 != 1) {
              return 0x1f;
            }
          }
          else if (uVar2 == 5) goto LAB_004c9218;
LAB_004c91ca:
          uVar5 = uVar5 + 1;
          *(undefined4 *)(param_5 + uVar9 * 10 + 8) = *(undefined4 *)(lVar10 + 0x38);
        }
        else if (uVar2 == 10) {
LAB_004c92b0:
          uVar5 = uVar5 + 1;
          *(undefined4 *)(param_5 + uVar9 * 10 + 10) = *(undefined4 *)(lVar10 + 0x3c);
        }
        else {
          if (uVar2 < 0xb) {
            if (uVar2 != 8) goto LAB_004c91ca;
          }
          else {
            if (uVar2 == 0xb) goto LAB_004c91ca;
            if (uVar2 != 0xc) {
              return 0x1f;
            }
          }
LAB_004c9218:
          uVar5 = uVar5 + 1;
          *(undefined4 *)(param_5 + uVar9 * 10 + 0xc) = *(undefined4 *)(lVar10 + 0x40);
        }
        if (uVar1 <= uVar5) {
          return 0;
        }
      } while( true );
    }
  }
  return 0x1f;
}


// ===== 004c93c0 rpcCtrlFlaSetupInstanceMemBlock_v21_05 =====

undefined8
rpcCtrlFlaSetupInstanceMemBlock_v21_05
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined8 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0xc2,0x18);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined8 *)0x0) {
      *(undefined8 *)(lVar1 + 0x28) = *param_5;
      *(undefined4 *)(lVar1 + 0x30) = *(undefined4 *)(param_5 + 1);
      *(undefined4 *)(lVar1 + 0x34) = *(undefined4 *)((long)param_5 + 0xc);
      uVar2 = _issueRpcAndWait(param_1,param_2);
      return uVar2;
    }
    uVar2 = 0x1f;
  }
  return uVar2;
}


// ===== 004c9460 rpcCtrlGetTotalHsCredits_v21_08 =====

int rpcCtrlGetTotalHsCredits_v21_08
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined4 *param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0xc4,0xc);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    iVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 == 0) {
        *param_5 = *(undefined4 *)(lVar1 + 0x28);
      }
      else {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x148a,"rpcCtrlGetTotalHsCredits_v21_08",4,
                     "NVRM: RPC to get total hs credits failed with error 0x%x\n");
      }
    }
  }
  return iVar2;
}


// ===== 004c9520 rpcCtrlGetHsCredits_v21_08 =====

int rpcCtrlGetHsCredits_v21_08
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,long param_5)

{
  long lVar1;
  int iVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0xc5,0x108);
  if (iVar2 != 0) {
    return iVar2;
  }
  *(undefined4 *)(lVar1 + 0x20) = param_3;
  *(undefined4 *)(lVar1 + 0x24) = param_4;
  iVar2 = serialize_NVB0CC_CTRL_GET_HS_CREDITS_PARAMS_v21_08(param_5,lVar1 + 0x28,0,0);
  if (iVar2 == 0) {
    iVar2 = _issueRpcAndWait(param_1,param_2);
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x14a7,"rpcCtrlGetHsCredits_v21_08",4,
                   "NVRM: RPC to get hs credits failed with error 0x%x\n");
      return iVar2;
    }
    if ((param_5 != 0) && (*(byte *)(lVar1 + 0x29) < 0x40)) {
      lVar3 = 0;
      *(undefined1 *)(param_5 + 2) = *(undefined1 *)(lVar1 + 0x2a);
      *(undefined1 *)(param_5 + 3) = *(undefined1 *)(lVar1 + 0x2b);
      do {
        *(undefined2 *)(param_5 + 6 + lVar3) = *(undefined2 *)(lVar1 + 0x2e + lVar3);
        lVar3 = lVar3 + 4;
      } while (lVar3 != 0xfc);
      return 0;
    }
  }
  return 0x1f;
}


// ===== 004c9650 rpcCtrlReserveHes_v29_07 =====

int rpcCtrlReserveHes_v29_07
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined4 *param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0xdb,0x10);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    iVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      *(undefined1 *)(lVar1 + 0x2c) = *(undefined1 *)(param_5 + 1);
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x14c3,"rpcCtrlReserveHes_v29_07",4,
                     "NVRM: RPC rpcCtrlReserveHes_v29_07 failed with error 0x%x\n");
      }
    }
  }
  return iVar2;
}


// ===== 004c9710 rpcCtrlReleaseHes_v29_07 =====

int rpcCtrlReleaseHes_v29_07
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined4 *param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0xdc,0xc);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    iVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x14de,"rpcCtrlReleaseHes_v29_07",4,
                     "NVRM: RPC rpcCtrlReleaseHes_v29_07 failed with error 0x%x\n");
      }
    }
  }
  return iVar2;
}


// ===== 004c97d0 rpcCtrlReserveCcuProf_v29_07 =====

int rpcCtrlReserveCcuProf_v29_07
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined1 *param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0xdd,0xc);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    iVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined1 *)0x0) {
      *(undefined1 *)(lVar1 + 0x28) = *param_5;
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x14fa,"rpcCtrlReserveCcuProf_v29_07",4,
                     "NVRM: RPC rpcCtrlReserveCcuProf_v29_07 failed with error 0x%x\n");
      }
    }
  }
  return iVar2;
}


// ===== 004c9890 rpcCtrlReleaseCcuProf_v29_07 =====

int rpcCtrlReleaseCcuProf_v29_07
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0xde,8);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    iVar2 = _issueRpcAndWait(param_1,param_2);
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1512,"rpcCtrlReleaseCcuProf_v29_07",4,
                   "NVRM: RPC rpcCtrlReleaseCcuProf_v29_07 failed with error 0x%x\n");
    }
  }
  return iVar2;
}


// ===== 004c9940 rpcCtrlCmdGetChipletHsCreditPool_v29_0A =====

int rpcCtrlCmdGetChipletHsCreditPool_v29_0A
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined2 *param_5)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  
  lVar2 = *(long *)(param_2 + 0x4d8);
  iVar3 = rpcWriteCommonHeader(param_1,param_2,0xe0,0x84);
  if (iVar3 != 0) {
    return iVar3;
  }
  *(undefined4 *)(lVar2 + 0x20) = param_3;
  *(undefined4 *)(lVar2 + 0x24) = param_4;
  if (param_5 != (undefined2 *)0x0) {
    uVar1 = *(uint *)(param_5 + 0x3c);
    if (uVar1 < 0x1f) {
      *(uint *)(lVar2 + 0xa0) = uVar1;
      if (uVar1 != 0) {
        puVar4 = param_5;
        puVar6 = (undefined2 *)(lVar2 + 0x28);
        do {
          puVar5 = puVar4 + 2;
          *puVar6 = *puVar4;
          *(undefined1 *)(puVar6 + 1) = *(undefined1 *)(puVar4 + 1);
          *(undefined1 *)((long)puVar6 + 3) = *(undefined1 *)((long)puVar4 + 3);
          puVar4 = puVar5;
          puVar6 = puVar6 + 2;
        } while (puVar5 != param_5 + (ulong)uVar1 * 2);
      }
      iVar3 = _issueRpcAndWait(param_1,param_2);
      if (iVar3 != 0) {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1530,"rpcCtrlCmdGetChipletHsCreditPool_v29_0A",4,
                     "NVRM: RPC to get chiplet hs credit pool failed with error 0x%x\n");
        return iVar3;
      }
      uVar1 = *(uint *)(lVar2 + 0xa0);
      if (uVar1 < 0x1f) {
        *(uint *)(param_5 + 0x3c) = uVar1;
        if (uVar1 == 0) {
          return 0;
        }
        puVar4 = (undefined2 *)(lVar2 + 0x28);
        puVar6 = param_5;
        do {
          puVar5 = puVar6 + 2;
          *puVar6 = *puVar4;
          *(undefined1 *)(puVar6 + 1) = *(undefined1 *)(puVar4 + 1);
          *(undefined1 *)((long)puVar6 + 3) = *(undefined1 *)((long)puVar4 + 3);
          puVar4 = puVar4 + 2;
          puVar6 = puVar5;
        } while (puVar5 != param_5 + (ulong)uVar1 * 2);
        return 0;
      }
    }
  }
  return 0x1f;
}


// ===== 004c9b00 rpcCtrlCmdGetHsCreditsMapping_v29_0A =====

int rpcCtrlCmdGetHsCreditsMapping_v29_0A
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,ushort *param_5
              )

{
  ushort uVar1;
  long lVar2;
  int iVar3;
  ushort *puVar4;
  ushort *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  
  lVar2 = *(long *)(param_2 + 0x4d8);
  iVar3 = rpcWriteCommonHeader(param_1,param_2,0xe1,0xcc);
  if (iVar3 != 0) {
    return iVar3;
  }
  *(undefined4 *)(lVar2 + 0x20) = param_3;
  *(undefined4 *)(lVar2 + 0x24) = param_4;
  portMemCopy(lVar2 + 0x28,0xc2,param_5,0xc2);
  if (param_5 != (ushort *)0x0) {
    uVar1 = *param_5;
    if (uVar1 < 0x40) {
      *(ushort *)(lVar2 + 0x28) = uVar1;
      *(char *)(lVar2 + 0x2a) = (char)param_5[1];
      *(undefined1 *)(lVar2 + 0x2b) = *(undefined1 *)((long)param_5 + 3);
      if (uVar1 != 0) {
        puVar4 = param_5 + 2;
        puVar6 = (undefined1 *)(lVar2 + 0x2c);
        do {
          puVar5 = (ushort *)((long)puVar4 + 3);
          *puVar6 = (char)*puVar4;
          puVar6[1] = *(undefined1 *)((long)puVar4 + 1);
          puVar6[2] = (char)puVar4[1];
          puVar4 = puVar5;
          puVar6 = puVar6 + 3;
        } while (puVar5 != (ushort *)((ulong)uVar1 * 3 + (long)(param_5 + 2)));
      }
      iVar3 = _issueRpcAndWait(param_1,param_2);
      if (iVar3 != 0) {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1554,"rpcCtrlCmdGetHsCreditsMapping_v29_0A",4,
                     "NVRM: RPC to get hs credits mapping failed with error 0x%x\n");
        return iVar3;
      }
      uVar1 = *(ushort *)(lVar2 + 0x28);
      if (uVar1 < 0x40) {
        *param_5 = uVar1;
        *(undefined1 *)(param_5 + 1) = *(undefined1 *)(lVar2 + 0x2a);
        *(undefined1 *)((long)param_5 + 3) = *(undefined1 *)(lVar2 + 0x2b);
        if (uVar1 == 0) {
          return 0;
        }
        puVar6 = (undefined1 *)(lVar2 + 0x2c);
        puVar4 = param_5 + 2;
        do {
          puVar7 = puVar6 + 3;
          *(undefined1 *)puVar4 = *puVar6;
          *(undefined1 *)((long)puVar4 + 1) = puVar6[1];
          *(undefined1 *)(puVar4 + 1) = puVar6[2];
          puVar6 = puVar7;
          puVar4 = (ushort *)((long)puVar4 + 3);
        } while (puVar7 != (undefined1 *)(lVar2 + 0x2c) + (ulong)uVar1 * 3);
        return 0;
      }
    }
  }
  return 0x1f;
}


// ===== 004c9cc0 rpcCtrlSetHsCredits_v21_08 =====

int rpcCtrlSetHsCredits_v21_08
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,long param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0xc6,0x108);
  if (iVar2 != 0) {
    return iVar2;
  }
  *(undefined4 *)(lVar1 + 0x20) = param_3;
  *(undefined4 *)(lVar1 + 0x24) = param_4;
  iVar2 = serialize_NVB0CC_CTRL_SET_HS_CREDITS_PARAMS_v21_08(param_5,lVar1 + 0x28,0,0);
  if (iVar2 == 0) {
    iVar2 = _issueRpcAndWait(param_1,param_2);
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1573,"rpcCtrlSetHsCredits_v21_08",4,
                   "NVRM: RPC to set hs credits failed with error 0x%x\n");
      return iVar2;
    }
    if (param_5 != 0) {
      *(undefined1 *)(param_5 + 2) = *(undefined1 *)(lVar1 + 0x2a);
      *(undefined1 *)(param_5 + 3) = *(undefined1 *)(lVar1 + 0x2b);
      return 0;
    }
  }
  return 0x1f;
}


// ===== 004c9dc0 rpcCtrlPmAreaPcSampler_v21_0B =====

void rpcCtrlPmAreaPcSampler_v21_0B
               (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,199,0xc);
  if (iVar2 != 0) {
    return;
  }
  *(undefined4 *)(lVar1 + 0x20) = param_3;
  *(undefined4 *)(lVar1 + 0x24) = param_4;
  *(undefined4 *)(lVar1 + 0x28) = param_5;
  _issueRpcAndWait(param_1,param_2);
  return;
}


// ===== 004c9e40 rpcRmApiControl_v25_0D =====

void rpcRmApiControl_v25_0D(void)

{
  rpcRmApiControl_wrapper();
  return;
}


// ===== 004c9e50 rpcRmApiControl_v25_0F =====

void rpcRmApiControl_v25_0F(void)

{
  rpcRmApiControl_wrapper();
  return;
}


// ===== 004c9e60 rpcRmApiControl_v25_10 =====

void rpcRmApiControl_v25_10(void)

{
  rpcRmApiControl_wrapper();
  return;
}


// ===== 004c9e70 rpcRmApiControl_v25_14 =====

void rpcRmApiControl_v25_14(void)

{
  rpcRmApiControl_wrapper();
  return;
}


// ===== 004c9e80 rpcRmApiControl_v25_15 =====

void rpcRmApiControl_v25_15(void)

{
  rpcRmApiControl_wrapper();
  return;
}


// ===== 004c9e90 rpcRmApiControl_v25_16 =====

void rpcRmApiControl_v25_16(void)

{
  rpcRmApiControl_wrapper();
  return;
}


// ===== 004c9ea0 rpcRmApiControl_v25_17 =====

void rpcRmApiControl_v25_17(void)

{
  rpcRmApiControl_wrapper();
  return;
}


// ===== 004c9eb0 rpcRmApiControl_v25_18 =====

void rpcRmApiControl_v25_18(void)

{
  rpcRmApiControl_wrapper();
  return;
}


// ===== 004c9ec0 rpcRmApiControl_v25_19 =====

void rpcRmApiControl_v25_19(void)

{
  rpcRmApiControl_wrapper();
  return;
}


// ===== 004c9ed0 rpcRmApiControl_v25_1A =====

void rpcRmApiControl_v25_1A(void)

{
  rpcRmApiControl_wrapper();
  return;
}


// ===== 004c9ee0 rpcRmApiControl_v27_03 =====

void rpcRmApiControl_v27_03(void)

{
  rpcRmApiControl_wrapper();
  return;
}


// ===== 004c9ef0 rpcRmApiControl_v29_04 =====

void rpcRmApiControl_v29_04(void)

{
  rpcRmApiControl_wrapper();
  return;
}


// ===== 004c9f00 rpcRmApiControl_v29_09 =====

void rpcRmApiControl_v29_09(void)

{
  rpcRmApiControl_wrapper();
  return;
}


// ===== 004c9f10 rpcRmApiControl_v2A_08 =====

void rpcRmApiControl_v2A_08(void)

{
  rpcRmApiControl_wrapper();
  return;
}


// ===== 004c9f20 rpcRmApiControl_v2C_04 =====

void rpcRmApiControl_v2C_04(void)

{
  rpcRmApiControl_wrapper();
  return;
}


// ===== 004c9f30 rpcRmApiControl_v2C_06 =====

void rpcRmApiControl_v2C_06(void)

{
  rpcRmApiControl_wrapper();
  return;
}


// ===== 004c9f40 rpcGetBrandCaps_v25_12 =====

int rpcGetBrandCaps_v25_12(undefined8 param_1,long param_2)

{
  long lVar1;
  int iVar2;
  undefined4 *in_R9;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0xd2,4);
  if (iVar2 == 0) {
    iVar2 = _issueRpcAndWait(param_1,param_2);
    if (iVar2 == 0) {
      if (in_R9 != (undefined4 *)0x0) {
        *in_R9 = *(undefined4 *)(lVar1 + 0x20);
        return 0;
      }
      iVar2 = 0x1f;
    }
    else {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1635,"rpcGetBrandCaps_v25_12",4,
                   "NVRM: RPC to get brand caps failed with error 0x%x\n");
    }
  }
  return iVar2;
}


// ===== 004ca000 rpcCtrlSetVgpuFbUsage_v1A_08 =====

undefined8 rpcCtrlSetVgpuFbUsage_v1A_08(long param_1,long param_2,long *param_3)

{
  long lVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  ulong uVar5;
  undefined8 uVar6;
  int local_30;
  int local_2c;
  
  lVar1 = *(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8);
  if ((lVar1 == 0) || (lVar2 = *param_3, lVar2 == *(long *)(lVar1 + 0x1c0))) {
    return 0;
  }
  lVar3 = *(long *)(param_2 + 0x4d8);
  iVar4 = osGetSystemTime(&local_30,&local_2c);
  if ((iVar4 == 0) &&
     (uVar5 = (ulong)(uint)(local_30 * 1000000 + local_2c),
     999999 < uVar5 - *(long *)(lVar1 + 0x1b8))) {
    *(ulong *)(lVar1 + 0x1b8) = uVar5;
    *(long *)(lVar1 + 0x1c0) = lVar2;
    uVar6 = rpcWriteCommonHeader(param_1,param_2,0x55,8);
    if ((int)uVar6 != 0) {
      return uVar6;
    }
    *(long *)(lVar3 + 0x20) = *param_3;
    uVar6 = _issueRpcAndWait(param_1,param_2);
    return uVar6;
  }
  return 0;
}


// ===== 004ca100 rpcCtrlNvencSwSessionUpdateInfo_v1A_09 =====

undefined8
rpcCtrlNvencSwSessionUpdateInfo_v1A_09
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  undefined4 uVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = *(long *)(param_2 + 0x4d8);
  uVar3 = rpcWriteCommonHeader(param_1,param_2,0x57,0x28);
  if ((int)uVar3 == 0) {
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar2 + 0x28) = *param_5;
      *(undefined4 *)(lVar2 + 0x2c) = param_5[1];
      *(undefined4 *)(lVar2 + 0x30) = param_5[2];
      uVar1 = param_5[3];
      *(undefined4 *)(lVar2 + 0x38) = 0;
      *(undefined4 *)(lVar2 + 0x34) = uVar1;
      uVar3 = _issueRpcAndWait(param_1,param_2);
      return uVar3;
    }
    uVar3 = 0x1f;
  }
  return uVar3;
}


// ===== 004ca1c0 rpcCtrlResetChannel_v1A_09 =====

undefined8
rpcCtrlResetChannel_v1A_09
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x58,0x14);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      *(undefined4 *)(lVar1 + 0x2c) = param_5[1];
      *(undefined4 *)(lVar1 + 0x30) = param_5[2];
      uVar2 = _issueRpcAndWait(param_1,param_2);
      return uVar2;
    }
    uVar2 = 0x1f;
  }
  return uVar2;
}


// ===== 004ca270 rpcCtrlResetIsolatedChannel_v1A_09 =====

undefined8
rpcCtrlResetIsolatedChannel_v1A_09
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x59,0x10);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
    uVar2 = 0x1f;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      *(undefined4 *)(lVar1 + 0x2c) = param_5[1];
      uVar2 = _issueRpcAndWait(param_1,param_2);
      if ((int)uVar2 == 0) {
        *param_5 = *(undefined4 *)(lVar1 + 0x28);
        param_5[1] = *(undefined4 *)(lVar1 + 0x2c);
      }
    }
  }
  return uVar2;
}


// ===== 004ca310 rpcCtrlGpuHandleVfPriFault_v1A_09 =====

undefined8
rpcCtrlGpuHandleVfPriFault_v1A_09
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x5a,0xc);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      uVar2 = _issueRpcAndWait(param_1,param_2);
      return uVar2;
    }
    uVar2 = 0x1f;
  }
  return uVar2;
}


// ===== 004ca3b0 rpcCtrlPerfBoost_v1A_09 =====

undefined8
rpcCtrlPerfBoost_v1A_09
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x5c,0x10);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
    uVar2 = 0x1f;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      *(undefined4 *)(lVar1 + 0x2c) = param_5[1];
      uVar2 = _issueRpcAndWait(param_1,param_2);
      if ((int)uVar2 == 0) {
        *param_5 = *(undefined4 *)(lVar1 + 0x28);
        param_5[1] = *(undefined4 *)(lVar1 + 0x2c);
      }
    }
  }
  return uVar2;
}


// ===== 004ca450 rpcCtrlGetZbcClearTable_v1A_09 =====

void rpcCtrlGetZbcClearTable_v1A_09
               (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,long param_5)

{
  long lVar1;
  int iVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0x5e,0x40);
  if (iVar2 == 0) {
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
    if (param_5 != 0) {
      lVar3 = 0;
      do {
        *(undefined4 *)(lVar1 + 0x28 + lVar3) = *(undefined4 *)(param_5 + lVar3);
        *(undefined4 *)(lVar1 + 0x38 + lVar3) = *(undefined4 *)(param_5 + 0x10 + lVar3);
        lVar3 = lVar3 + 4;
      } while (lVar3 != 0x10);
      *(undefined4 *)(lVar1 + 0x48) = *(undefined4 *)(param_5 + 0x20);
      *(undefined4 *)(lVar1 + 0x4c) = *(undefined4 *)(param_5 + 0x24);
      *(undefined4 *)(lVar1 + 0x50) = *(undefined4 *)(param_5 + 0x28);
      *(undefined4 *)(lVar1 + 0x54) = *(undefined4 *)(param_5 + 0x34);
      *(undefined4 *)(lVar1 + 0x58) = *(undefined4 *)(param_5 + 0x38);
      *(undefined4 *)(lVar1 + 0x5c) = *(undefined4 *)(param_5 + 0x3c);
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 == 0) {
        lVar3 = 0;
        do {
          *(undefined4 *)(param_5 + lVar3) = *(undefined4 *)(lVar1 + 0x28 + lVar3);
          *(undefined4 *)(param_5 + 0x10 + lVar3) = *(undefined4 *)(lVar1 + 0x38 + lVar3);
          lVar3 = lVar3 + 4;
        } while (lVar3 != 0x10);
        *(undefined4 *)(param_5 + 0x20) = *(undefined4 *)(lVar1 + 0x48);
        *(undefined4 *)(param_5 + 0x24) = *(undefined4 *)(lVar1 + 0x4c);
        *(undefined4 *)(param_5 + 0x28) = *(undefined4 *)(lVar1 + 0x50);
        *(undefined4 *)(param_5 + 0x34) = *(undefined4 *)(lVar1 + 0x54);
        *(undefined4 *)(param_5 + 0x38) = *(undefined4 *)(lVar1 + 0x58);
        *(undefined4 *)(param_5 + 0x3c) = *(undefined4 *)(lVar1 + 0x5c);
        return;
      }
    }
  }
  return;
}


// ===== 004ca580 rpcCtrlSetZbcColorClear_v1A_09 =====

void rpcCtrlSetZbcColorClear_v1A_09
               (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,long param_5)

{
  long lVar1;
  int iVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0x5f,0x2c);
  if (iVar2 == 0) {
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
    if (param_5 != 0) {
      lVar3 = 0;
      do {
        *(undefined4 *)(lVar1 + 0x28 + lVar3) = *(undefined4 *)(param_5 + lVar3);
        *(undefined4 *)(lVar1 + 0x38 + lVar3) = *(undefined4 *)(param_5 + 0x10 + lVar3);
        lVar3 = lVar3 + 4;
      } while (lVar3 != 0x10);
      *(undefined4 *)(lVar1 + 0x48) = *(undefined4 *)(param_5 + 0x20);
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 == 0) {
        lVar3 = 0;
        do {
          *(undefined4 *)(param_5 + lVar3) = *(undefined4 *)(lVar1 + 0x28 + lVar3);
          *(undefined4 *)(param_5 + 0x10 + lVar3) = *(undefined4 *)(lVar1 + 0x38 + lVar3);
          lVar3 = lVar3 + 4;
        } while (lVar3 != 0x10);
        *(undefined4 *)(param_5 + 0x20) = *(undefined4 *)(lVar1 + 0x48);
        return;
      }
    }
  }
  return;
}


// ===== 004ca660 rpcCtrlSetZbcDepthClear_v1A_09 =====

undefined8
rpcCtrlSetZbcDepthClear_v1A_09
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x60,0x10);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
    uVar2 = 0x1f;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      *(undefined4 *)(lVar1 + 0x2c) = param_5[1];
      uVar2 = _issueRpcAndWait(param_1,param_2);
      if ((int)uVar2 == 0) {
        *param_5 = *(undefined4 *)(lVar1 + 0x28);
        param_5[1] = *(undefined4 *)(lVar1 + 0x2c);
      }
    }
  }
  return uVar2;
}


// ===== 004ca700 rpcCtrlSetZbcStencilClear_v27_06 =====

undefined8
rpcCtrlSetZbcStencilClear_v27_06
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0xd6,0x14);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
    uVar2 = 0x1f;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      *(undefined4 *)(lVar1 + 0x2c) = param_5[1];
      *(undefined1 *)(lVar1 + 0x30) = *(undefined1 *)(param_5 + 2);
      uVar2 = _issueRpcAndWait(param_1,param_2);
      if ((int)uVar2 == 0) {
        *param_5 = *(undefined4 *)(lVar1 + 0x28);
        param_5[1] = *(undefined4 *)(lVar1 + 0x2c);
        *(undefined1 *)(param_5 + 2) = *(undefined1 *)(lVar1 + 0x30);
      }
    }
  }
  return uVar2;
}


// ===== 004ca7c0 rpcCtrlGpfifoSchedule_v1A_0A =====

undefined8
rpcCtrlGpfifoSchedule_v1A_0A
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined1 *param_6)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x61,0x10);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x28) = param_5;
    uVar2 = 0x1f;
    if (param_6 != (undefined1 *)0x0) {
      *(undefined1 *)(lVar1 + 0x2c) = *param_6;
      uVar2 = _issueRpcAndWait(param_1);
      if ((int)uVar2 == 0) {
        *param_6 = *(undefined1 *)(lVar1 + 0x2c);
      }
    }
  }
  return uVar2;
}


// ===== 004ca860 rpcCtrlSetTimeslice_v1A_0A =====

undefined8
rpcCtrlSetTimeslice_v1A_0A
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined8 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x62,0x10);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
    uVar2 = 0x1f;
    if (param_5 != (undefined8 *)0x0) {
      *(undefined8 *)(lVar1 + 0x28) = *param_5;
      uVar2 = _issueRpcAndWait(param_1);
      if ((int)uVar2 == 0) {
        *param_5 = *(undefined8 *)(lVar1 + 0x28);
      }
    }
  }
  return uVar2;
}


// ===== 004ca900 rpcCtrlFifoDisableChannels_v1A_0A =====

undefined8
rpcCtrlFifoDisableChannels_v1A_0A
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined1 *param_5
          )

{
  undefined1 uVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar2 = *(long *)(param_2 + 0x4d8);
  uVar3 = rpcWriteCommonHeader(param_1,param_2,100,0x220);
  if ((int)uVar3 != 0) {
    return uVar3;
  }
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
  if ((param_5 != (undefined1 *)0x0) && (*(uint *)(param_5 + 4) < 0x41)) {
    *(undefined1 *)(lVar2 + 0x28) = *param_5;
    *(undefined4 *)(lVar2 + 0x2c) = *(undefined4 *)(param_5 + 4);
    *(undefined1 *)(lVar2 + 0x30) = param_5[8];
    uVar1 = param_5[9];
    *(undefined8 *)(lVar2 + 0x38) = 0;
    *(undefined1 *)(lVar2 + 0x31) = uVar1;
    if (*(int *)(param_5 + 4) != 0) {
      lVar4 = 0;
      do {
        *(undefined4 *)(lVar2 + 0x40 + lVar4 * 4) = *(undefined4 *)(param_5 + lVar4 * 4 + 0x18);
        *(undefined4 *)(lVar2 + 0x140 + lVar4 * 4) = *(undefined4 *)(param_5 + lVar4 * 4 + 0x118);
        lVar4 = lVar4 + 1;
      } while ((uint)lVar4 < *(uint *)(param_5 + 4));
    }
    uVar3 = _issueRpcAndWait(param_1,param_2);
    return uVar3;
  }
  return 0x1f;
}


// ===== 004caa20 rpcCtrlPreempt_v1A_0A =====

undefined8
rpcCtrlPreempt_v1A_0A
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined1 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,99,0x10);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
    if (param_5 != (undefined1 *)0x0) {
      *(undefined1 *)(lVar1 + 0x28) = *param_5;
      *(undefined1 *)(lVar1 + 0x29) = param_5[1];
      *(undefined4 *)(lVar1 + 0x2c) = *(undefined4 *)(param_5 + 4);
      uVar2 = _issueRpcAndWait(param_1,param_2);
      return uVar2;
    }
    uVar2 = 0x1f;
  }
  return uVar2;
}


// ===== 004caad0 rpcCtrlSetTsgInterleaveLevel_v1A_0A =====

undefined8
rpcCtrlSetTsgInterleaveLevel_v1A_0A
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x65,0xc);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      uVar2 = _issueRpcAndWait(param_1,param_2);
      return uVar2;
    }
    uVar2 = 0x1f;
  }
  return uVar2;
}


// ===== 004cab70 rpcCtrlSetChannelInterleaveLevel_v1A_0A =====

undefined8
rpcCtrlSetChannelInterleaveLevel_v1A_0A
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x66,0xc);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      uVar2 = _issueRpcAndWait(param_1,param_2);
      return uVar2;
    }
    uVar2 = 0x1f;
  }
  return uVar2;
}


// ===== 004cac20 rpcCtrlGrCtxswPreemptionBind_v1A_0E =====

undefined8
rpcCtrlGrCtxswPreemptionBind_v1A_0E
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x70,0x70);
  if ((int)uVar2 != 0) {
    return uVar2;
  }
  *(undefined4 *)(lVar1 + 0x20) = param_3;
  *(undefined4 *)(lVar1 + 0x24) = param_4;
  if (param_5 != (undefined4 *)0x0) {
    *(undefined4 *)(lVar1 + 0x28) = *param_5;
    *(undefined4 *)(lVar1 + 0x2c) = param_5[1];
    *(undefined4 *)(lVar1 + 0x30) = param_5[2];
    lVar3 = 0;
    do {
      *(undefined8 *)(lVar1 + 0x38 + lVar3) = *(undefined8 *)((long)param_5 + lVar3 + 0x10);
      lVar3 = lVar3 + 8;
    } while (lVar3 != 0x40);
    *(undefined4 *)(lVar1 + 0x78) = param_5[0x16];
    *(undefined4 *)(lVar1 + 0x7c) = param_5[0x17];
    *(undefined4 *)(lVar1 + 0x80) = param_5[0x18];
    *(undefined8 *)(lVar1 + 0x88) = *(undefined8 *)(param_5 + 0x1a);
    uVar2 = _issueRpcAndWait(param_1,param_2);
    return uVar2;
  }
  return 0x1f;
}


// ===== 004cad20 rpcCtrlGrCtxswPreemptionBind_v28_07 =====

undefined8
rpcCtrlGrCtxswPreemptionBind_v28_07
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x70,0x78);
  if ((int)uVar2 != 0) {
    return uVar2;
  }
  *(undefined4 *)(lVar1 + 0x20) = param_3;
  *(undefined4 *)(lVar1 + 0x24) = param_4;
  if (param_5 != (undefined4 *)0x0) {
    *(undefined4 *)(lVar1 + 0x28) = *param_5;
    *(undefined4 *)(lVar1 + 0x2c) = param_5[1];
    *(undefined4 *)(lVar1 + 0x30) = param_5[2];
    lVar3 = 0;
    do {
      *(undefined8 *)(lVar1 + 0x38 + lVar3) = *(undefined8 *)((long)param_5 + lVar3 + 0x10);
      lVar3 = lVar3 + 8;
    } while (lVar3 != 0x48);
    *(undefined4 *)(lVar1 + 0x80) = param_5[0x16];
    *(undefined4 *)(lVar1 + 0x84) = param_5[0x17];
    *(undefined4 *)(lVar1 + 0x88) = param_5[0x18];
    *(undefined8 *)(lVar1 + 0x90) = *(undefined8 *)(param_5 + 0x1a);
    uVar2 = _issueRpcAndWait(param_1,param_2);
    return uVar2;
  }
  return 0x1f;
}


// ===== 004cae20 rpcCtrlGrSetCtxswPreemptionMode_v1A_0E =====

undefined8
rpcCtrlGrSetCtxswPreemptionMode_v1A_0E
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x71,0x28);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      *(undefined4 *)(lVar1 + 0x2c) = param_5[1];
      *(undefined4 *)(lVar1 + 0x30) = param_5[2];
      *(undefined4 *)(lVar1 + 0x34) = param_5[3];
      *(undefined4 *)(lVar1 + 0x38) = param_5[4];
      *(undefined8 *)(lVar1 + 0x40) = *(undefined8 *)(param_5 + 6);
      uVar2 = _issueRpcAndWait(param_1,param_2);
      return uVar2;
    }
    uVar2 = 0x1f;
  }
  return uVar2;
}


// ===== 004caee0 rpcCtrlGrCtxswZcullBind_v1A_0E =====

undefined8
rpcCtrlGrCtxswZcullBind_v1A_0E
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x72,0x20);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    uVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      *(undefined4 *)(lVar1 + 0x2c) = param_5[1];
      *(undefined8 *)(lVar1 + 0x30) = *(undefined8 *)(param_5 + 2);
      *(undefined4 *)(lVar1 + 0x38) = param_5[4];
      uVar2 = _issueRpcAndWait(param_1,param_2);
      if ((int)uVar2 == 0) {
        *param_5 = *(undefined4 *)(lVar1 + 0x28);
        param_5[1] = *(undefined4 *)(lVar1 + 0x2c);
        *(undefined8 *)(param_5 + 2) = *(undefined8 *)(lVar1 + 0x30);
        param_5[4] = *(undefined4 *)(lVar1 + 0x38);
      }
    }
  }
  return uVar2;
}


// ===== 004caf90 rpcCtrlGpuInitializeCtx_v1A_0E =====

undefined8
rpcCtrlGpuInitializeCtx_v1A_0E
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x73,0x40);
  if ((int)uVar2 != 0) {
    return uVar2;
  }
  *(undefined4 *)(lVar1 + 0x20) = param_3;
  *(undefined4 *)(lVar1 + 0x24) = param_4;
  if (param_5 != (undefined4 *)0x0) {
    *(undefined4 *)(lVar1 + 0x28) = *param_5;
    *(undefined4 *)(lVar1 + 0x2c) = param_5[1];
    *(undefined4 *)(lVar1 + 0x30) = param_5[2];
    *(undefined4 *)(lVar1 + 0x34) = param_5[3];
    *(undefined4 *)(lVar1 + 0x38) = param_5[4];
    *(undefined4 *)(lVar1 + 0x3c) = param_5[5];
    *(undefined8 *)(lVar1 + 0x40) = *(undefined8 *)(param_5 + 6);
    *(undefined4 *)(lVar1 + 0x48) = param_5[8];
    *(undefined4 *)(lVar1 + 0x4c) = param_5[9];
    *(undefined4 *)(lVar1 + 0x50) = param_5[10];
    *(undefined8 *)(lVar1 + 0x58) = *(undefined8 *)(param_5 + 0xc);
    uVar2 = _issueRpcAndWait(param_1,param_2);
    return uVar2;
  }
  return 0x1f;
}


// ===== 004cb080 rpcCtrlVaspaceCopyServerReservedPdes_v1E_04 =====

undefined8
rpcCtrlVaspaceCopyServerReservedPdes_v1E_04
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  lVar2 = *(long *)(param_2 + 0x4d8);
  uVar3 = rpcWriteCommonHeader(param_1,param_2,0x74,0xc0);
  if ((int)uVar3 != 0) {
    return uVar3;
  }
  *(undefined4 *)(lVar2 + 0x20) = param_3;
  *(undefined4 *)(lVar2 + 0x24) = param_4;
  if ((param_5 != (undefined4 *)0x0) && ((uint)param_5[8] < 7)) {
    *(undefined4 *)(lVar2 + 0x28) = *param_5;
    *(undefined4 *)(lVar2 + 0x2c) = param_5[1];
    *(undefined8 *)(lVar2 + 0x30) = *(undefined8 *)(param_5 + 2);
    *(undefined8 *)(lVar2 + 0x38) = *(undefined8 *)(param_5 + 4);
    *(undefined8 *)(lVar2 + 0x40) = *(undefined8 *)(param_5 + 6);
    uVar1 = param_5[8];
    *(uint *)(lVar2 + 0x48) = uVar1;
    if (uVar1 != 0) {
      puVar4 = (undefined8 *)(lVar2 + 0x50);
      puVar5 = param_5;
      do {
        puVar6 = puVar5 + 6;
        *puVar4 = *(undefined8 *)(puVar5 + 10);
        *(undefined4 *)(puVar4 + 2) = puVar5[0xe];
        puVar4[1] = *(undefined8 *)(puVar5 + 0xc);
        *(undefined1 *)((long)puVar4 + 0x14) = *(undefined1 *)(puVar5 + 0xf);
        puVar4 = puVar4 + 3;
        puVar5 = puVar6;
      } while (puVar6 != param_5 + (ulong)uVar1 * 6);
    }
    uVar3 = _issueRpcAndWait(param_1,param_2);
    return uVar3;
  }
  return 0x1f;
}


// ===== 004cb1a0 rpcCtrlMcServiceInterrupts_v1A_0E =====

undefined8
rpcCtrlMcServiceInterrupts_v1A_0E
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x77,0xc);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    uVar2 = _issueRpcAndWait(param_1,param_2);
    if ((int)uVar2 == 0) {
      if (param_5 != (undefined4 *)0x0) {
        *param_5 = *(undefined4 *)(lVar1 + 0x28);
        return uVar2;
      }
      uVar2 = 0x1f;
    }
  }
  return uVar2;
}


// ===== 004cb230 rpcCtrlGetP2pCapsV2_v1F_0D =====

int rpcCtrlGetP2pCapsV2_v1F_0D(undefined8 param_1,long param_2,long param_3)

{
  bool bVar1;
  int iVar2;
  long local_40;
  
  if (*(uint *)(param_2 + 0x4f0) < 0x8c0) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1933,"rpcCtrlGetP2pCapsV2_v1F_0D",4,
                 "NVRM: vGPU P2P_V2 parameters size (0x%x) exceed message_buffer size (0x%x)\n",
                 0x8c0,*(uint *)(param_2 + 0x4f0));
    nvAssertFailedNoLog(&DAT_00d98b20,"src/kernel/vgpu/rpc.c",0x1937);
    return 2;
  }
  local_40 = param_3 + 0x9c;
  bVar1 = false;
  if (*(uint *)(param_3 + 0x80) < 0x20) {
    while( true ) {
      iVar2 = rpcWriteCommonHeader(param_1,param_2,0x68,0x8a0);
      if (iVar2 != 0) {
        return iVar2;
      }
      *(bool *)(*(long *)(param_2 + 0x4d8) + 0x20) = bVar1;
      *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0xa4) = *(undefined4 *)(param_3 + 0x80);
      portMemCopy(*(long *)(param_2 + 0x4d8) + 0x24,0x80,param_3,0x80);
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 != 0) break;
      if (bVar1) {
        portMemCopy(local_40,0x800,*(long *)(param_2 + 0x4d8) + 0xc0,0x800);
        return 0;
      }
      *(undefined4 *)(param_3 + 0x84) = *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0xa8);
      *(undefined4 *)(param_3 + 0x88) = *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0xac);
      *(undefined4 *)(param_3 + 0x8c) = *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0xb0);
      portMemCopy(param_3 + 0x90,9,*(long *)(param_2 + 0x4d8) + 0xb4,9);
      portMemCopy(local_40,0x800,*(long *)(param_2 + 0x4d8) + 0xc0,0x800);
      local_40 = local_40 + 0x800;
      bVar1 = true;
    }
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1958,"rpcCtrlGetP2pCapsV2_v1F_0D",4,
                 "NVRM: RPC to fetch P2P caps failed with error 0x%x\n",iVar2);
    return iVar2;
  }
  nvAssertFailedNoLog(&DAT_00d98b20,"src/kernel/vgpu/rpc.c",0x193d);
  return 0x25;
}


// ===== 004cb4d0 rpcCtrlSubdeviceGetP2pCaps_v21_02 =====

int rpcCtrlSubdeviceGetP2pCaps_v21_02
              (undefined8 param_1,long param_2,undefined8 param_3,undefined8 param_4,char *param_5)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  char *pcVar7;
  long lVar8;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0xbf,0x608);
  if (iVar2 == 0) {
    if ((param_5 == (char *)0x0) || ((*param_5 == '\0' && (0x20 < *(uint *)(param_5 + 4))))) {
      return 0x1f;
    }
    *(char *)(lVar1 + 0x20) = *param_5;
    *(char *)(lVar1 + 0x21) = param_5[1];
    if ((*param_5 == '\0') &&
       (iVar2 = *(int *)(param_5 + 4), *(int *)(lVar1 + 0x24) = iVar2, iVar2 != 0)) {
      lVar5 = lVar1 + 0x2c;
      pcVar7 = param_5 + 0xc;
      uVar3 = 0;
      do {
        portMemCopy(lVar5,0x10,pcVar7,0x10);
        uVar3 = uVar3 + 1;
        lVar5 = lVar5 + 0x30;
        pcVar7 = pcVar7 + 0x34;
      } while (uVar3 < *(uint *)(param_5 + 4));
    }
    iVar2 = _issueRpcAndWait(param_1,param_2);
    if (iVar2 == 0) {
      uVar3 = *(uint *)(lVar1 + 0x24);
      if (0x20 < uVar3) {
        return 0x1f;
      }
      if (*(char *)(lVar1 + 0x20) != '\0') {
        *(uint *)(param_5 + 4) = uVar3;
      }
      if (uVar3 == 0) {
        iVar2 = 0;
      }
      else {
        pcVar7 = param_5 + 0x28;
        lVar5 = lVar1 + 0x48;
        uVar4 = 0;
        do {
          if (*(char *)(lVar1 + 0x20) != '\0') {
            portMemCopy(pcVar7 + -0x1c,0x10,lVar5 + -0x1c,0x10);
          }
          lVar6 = uVar4 * 0x34;
          lVar8 = uVar4 * 0x30 + lVar1;
          *(undefined4 *)(param_5 + lVar6 + 0x1c) = *(undefined4 *)(lVar8 + 0x3c);
          *(undefined4 *)(param_5 + lVar6 + 0x20) = *(undefined4 *)(lVar8 + 0x40);
          *(undefined4 *)(param_5 + lVar6 + 0x24) = *(undefined4 *)(lVar8 + 0x44);
          portMemCopy(pcVar7,9,lVar5,9);
          *(undefined4 *)(param_5 + lVar6 + 0x34) = *(undefined4 *)(lVar8 + 0x54);
          uVar3 = (int)uVar4 + 1;
          uVar4 = (ulong)uVar3;
          pcVar7 = pcVar7 + 0x34;
          lVar5 = lVar5 + 0x30;
        } while (uVar3 < *(uint *)(lVar1 + 0x24));
      }
    }
  }
  return iVar2;
}


// ===== 004cb6e0 rpcCtrlGpuPromoteCtx_v1A_20 =====

undefined8
rpcCtrlGpuPromoteCtx_v1A_20
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  lVar2 = *(long *)(param_2 + 0x4d8);
  uVar3 = rpcWriteCommonHeader(param_1,param_2,0x6f,0x238);
  if ((int)uVar3 != 0) {
    return uVar3;
  }
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
  if (param_5 != (undefined4 *)0x0) {
    *(undefined4 *)(lVar2 + 0x28) = *param_5;
    *(undefined4 *)(lVar2 + 0x2c) = param_5[1];
    *(undefined4 *)(lVar2 + 0x30) = param_5[2];
    *(undefined4 *)(lVar2 + 0x34) = param_5[3];
    *(undefined4 *)(lVar2 + 0x38) = param_5[4];
    *(undefined4 *)(lVar2 + 0x3c) = param_5[5];
    *(undefined8 *)(lVar2 + 0x40) = *(undefined8 *)(param_5 + 6);
    *(undefined8 *)(lVar2 + 0x48) = *(undefined8 *)(param_5 + 8);
    uVar1 = param_5[10];
    *(uint *)(lVar2 + 0x50) = uVar1;
    if (uVar1 < 0x11) {
      if (uVar1 != 0) {
        puVar4 = (undefined8 *)(lVar2 + 0x58);
        puVar5 = param_5;
        do {
          puVar6 = puVar5 + 8;
          *puVar4 = *(undefined8 *)(puVar5 + 0xc);
          puVar4[1] = *(undefined8 *)(puVar5 + 0xe);
          puVar4[2] = *(undefined8 *)(puVar5 + 0x10);
          *(undefined4 *)(puVar4 + 3) = puVar5[0x12];
          *(undefined2 *)((long)puVar4 + 0x1c) = *(undefined2 *)(puVar5 + 0x13);
          *(undefined1 *)((long)puVar4 + 0x1e) = *(undefined1 *)((long)puVar5 + 0x4e);
          *(undefined1 *)((long)puVar4 + 0x1f) = *(undefined1 *)((long)puVar5 + 0x4f);
          puVar4 = puVar4 + 4;
          puVar5 = puVar6;
        } while (puVar6 != param_5 + (ulong)uVar1 * 8);
      }
      uVar3 = _issueRpcAndWait(param_1,param_2);
      return uVar3;
    }
  }
  return 0x1f;
}


// ===== 004cb840 rpcCtrlReservePmAreaSmpc_v1A_0F =====

int rpcCtrlReservePmAreaSmpc_v1A_0F
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined1 *param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0x80,0xc);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    iVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined1 *)0x0) {
      *(undefined1 *)(lVar1 + 0x28) = *param_5;
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x19ca,"rpcCtrlReservePmAreaSmpc_v1A_0F",4,
                     "NVRM: RPC to acquire SMPC reservation failed with error 0x%x\n");
      }
    }
  }
  return iVar2;
}


// ===== 004cb900 rpcCtrlReserveHwpmLegacy_v1A_0F =====

int rpcCtrlReserveHwpmLegacy_v1A_0F
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined1 *param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0x81,0xc);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    iVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined1 *)0x0) {
      *(undefined1 *)(lVar1 + 0x28) = *param_5;
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x19ea,"rpcCtrlReserveHwpmLegacy_v1A_0F",4,
                     "NVRM: RPC to acquire HWPM reservation failed with error 0x%x\n");
      }
    }
  }
  return iVar2;
}


// ===== 004cb9c0 rpcCtrlB0ccExecRegOps_v1A_0F =====

int rpcCtrlB0ccExecRegOps_v1A_0F
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,uint *param_5)

{
  long lVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  uint uVar5;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0x82,0xf94);
  if (iVar2 != 0) {
    return iVar2;
  }
  *(undefined4 *)(lVar1 + 0x20) = param_3;
  *(undefined4 *)(lVar1 + 0x24) = param_4;
  if ((param_5 != (uint *)0x0) && (*param_5 < 0x7d)) {
    *(uint *)(lVar1 + 0x28) = *param_5;
    *(uint *)(lVar1 + 0x2c) = param_5[1];
    if (*param_5 != 0) {
      uVar4 = 0;
      do {
        uVar5 = (int)uVar4 + 1;
        lVar3 = uVar4 * 0x20;
        *(char *)(lVar1 + 0x34 + lVar3) = (char)param_5[uVar4 * 8 + 3];
        *(undefined1 *)(lVar1 + 0x35 + lVar3) = *(undefined1 *)((long)param_5 + lVar3 + 0xd);
        *(undefined1 *)(lVar1 + 0x37 + lVar3) = *(undefined1 *)((long)param_5 + lVar3 + 0xf);
        *(uint *)(lVar1 + 0x38 + lVar3) = param_5[uVar4 * 8 + 4];
        *(uint *)(lVar1 + 0x3c + lVar3) = param_5[uVar4 * 8 + 5];
        *(uint *)(lVar1 + 0x40 + lVar3) = param_5[uVar4 * 8 + 6];
        *(uint *)(lVar1 + 0x48 + lVar3) = param_5[uVar4 * 8 + 8];
        *(uint *)(lVar1 + 0x44 + lVar3) = param_5[uVar4 * 8 + 7];
        *(uint *)(lVar1 + 0x50 + lVar3) = param_5[uVar4 * 8 + 10];
        *(uint *)(lVar1 + 0x4c + lVar3) = param_5[uVar4 * 8 + 9];
        uVar4 = (ulong)uVar5;
      } while (uVar5 < *param_5);
    }
    iVar2 = _issueRpcAndWait(param_1,param_2);
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1a0d,"rpcCtrlB0ccExecRegOps_v1A_0F",4,
                   "NVRM: Profiler RegOps RPC failed with error 0x%x\n");
      return iVar2;
    }
    if (*(uint *)(lVar1 + 0x28) < 0x7d) {
      *(undefined1 *)(param_5 + 2) = *(undefined1 *)(lVar1 + 0x30);
      *(undefined1 *)((long)param_5 + 9) = *(undefined1 *)(lVar1 + 0x31);
      if (*(int *)(lVar1 + 0x28) == 0) {
        return 0;
      }
      uVar4 = 0;
      do {
        uVar5 = (int)uVar4 + 1;
        lVar3 = lVar1 + uVar4 * 0x20;
        *(undefined1 *)((long)param_5 + uVar4 * 0x20 + 0xe) = *(undefined1 *)(lVar3 + 0x36);
        param_5[uVar4 * 8 + 8] = *(uint *)(lVar3 + 0x48);
        param_5[uVar4 * 8 + 7] = *(uint *)(lVar3 + 0x44);
        uVar4 = (ulong)uVar5;
      } while (uVar5 < *(uint *)(lVar1 + 0x28));
      return 0;
    }
  }
  return 0x1f;
}


// ===== 004cbb80 rpcCtrlBindPmResources_v1A_0F =====

int rpcCtrlBindPmResources_v1A_0F
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0x83,8);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    iVar2 = _issueRpcAndWait(param_1,param_2);
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1a28,"rpcCtrlBindPmResources_v1A_0F",4,
                   "NVRM: RPC to bind PM resources failed with error 0x%x\n");
    }
  }
  return iVar2;
}


// ===== 004cbc20 rpcCtrlAllocPmaStream_v1A_14 =====

int rpcCtrlAllocPmaStream_v1A_14
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined4 *param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0x8c,0x40);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    iVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      *(undefined8 *)(lVar1 + 0x30) = *(undefined8 *)(param_5 + 2);
      *(undefined8 *)(lVar1 + 0x38) = *(undefined8 *)(param_5 + 4);
      *(undefined4 *)(lVar1 + 0x40) = param_5[6];
      *(undefined8 *)(lVar1 + 0x48) = *(undefined8 *)(param_5 + 8);
      *(undefined1 *)(lVar1 + 0x50) = *(undefined1 *)(param_5 + 10);
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 == 0) {
        param_5[0xb] = *(undefined4 *)(lVar1 + 0x54);
        *(undefined8 *)(param_5 + 0xc) = *(undefined8 *)(lVar1 + 0x58);
      }
      else {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1a46,"rpcCtrlAllocPmaStream_v1A_14",4,
                     "NVRM: PMA Stream allocation RPC failed with error 0x%x\n");
      }
    }
  }
  return iVar2;
}


// ===== 004cbd10 rpcCtrlPmaStreamUpdateGetPut_v1A_14 =====

int rpcCtrlPmaStreamUpdateGetPut_v1A_14
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined8 *param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0x8d,0x38);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    iVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined8 *)0x0) {
      *(undefined8 *)(lVar1 + 0x28) = *param_5;
      *(undefined1 *)(lVar1 + 0x30) = *(undefined1 *)(param_5 + 1);
      *(undefined1 *)(lVar1 + 0x31) = *(undefined1 *)((long)param_5 + 9);
      *(undefined1 *)(lVar1 + 0x40) = *(undefined1 *)(param_5 + 3);
      *(undefined4 *)(lVar1 + 0x50) = *(undefined4 *)(param_5 + 5);
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 == 0) {
        param_5[2] = *(undefined8 *)(lVar1 + 0x38);
        param_5[4] = *(undefined8 *)(lVar1 + 0x48);
      }
      else {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1a66,"rpcCtrlPmaStreamUpdateGetPut_v1A_14",4,
                     "NVRM: PMA Stream update get/put RPC failed with error 0x%x\n");
      }
    }
  }
  return iVar2;
}


// ===== 004cbdf0 rpcCtrlPmaStreamUpdateGetPut_v29_0B =====

int rpcCtrlPmaStreamUpdateGetPut_v29_0B
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined8 *param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0x8d,0x38);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    iVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined8 *)0x0) {
      *(undefined8 *)(lVar1 + 0x28) = *param_5;
      *(undefined1 *)(lVar1 + 0x30) = *(undefined1 *)(param_5 + 1);
      *(undefined1 *)(lVar1 + 0x31) = *(undefined1 *)((long)param_5 + 9);
      *(undefined1 *)(lVar1 + 0x40) = *(undefined1 *)(param_5 + 3);
      *(undefined4 *)(lVar1 + 0x50) = *(undefined4 *)(param_5 + 5);
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 == 0) {
        param_5[2] = *(undefined8 *)(lVar1 + 0x38);
        param_5[4] = *(undefined8 *)(lVar1 + 0x48);
        *(undefined1 *)((long)param_5 + 0x2c) = *(undefined1 *)(lVar1 + 0x54);
      }
      else {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1a86,"rpcCtrlPmaStreamUpdateGetPut_v29_0B",4,
                     "NVRM: PMA Stream update get/put RPC failed with error 0x%x\n");
      }
    }
  }
  return iVar2;
}


// ===== 004cbee0 rpcCtrlGrPcSamplingMode_v1A_1F =====

int rpcCtrlGrPcSamplingMode_v1A_1F
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined4 *param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0x96,0x20);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    iVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      *(undefined4 *)(lVar1 + 0x2c) = param_5[1];
      *(undefined4 *)(lVar1 + 0x30) = param_5[2];
      *(undefined8 *)(lVar1 + 0x38) = *(undefined8 *)(param_5 + 4);
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1aa6,"rpcCtrlGrPcSamplingMode_v1A_1F",4,
                     "NVRM: Set PC sampling mode RPC failed with error 0x%x\n");
      }
    }
  }
  return iVar2;
}


// ===== 004cbfb0 rpcCtrlPerfRatedTdpGetStatus_v1A_1F =====

int rpcCtrlPerfRatedTdpGetStatus_v1A_1F
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined4 *param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0x97,0x28);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    iVar2 = _issueRpcAndWait(param_1,param_2);
    if (iVar2 == 0) {
      if (param_5 == (undefined4 *)0x0) {
        iVar2 = 0x1f;
      }
      else {
        *param_5 = *(undefined4 *)(lVar1 + 0x28);
        *(undefined1 *)(param_5 + 1) = *(undefined1 *)(lVar1 + 0x2c);
        param_5[2] = *(undefined4 *)(lVar1 + 0x30);
        param_5[4] = *(undefined4 *)(lVar1 + 0x34);
        param_5[5] = *(undefined4 *)(lVar1 + 0x38);
        param_5[6] = *(undefined4 *)(lVar1 + 0x3c);
        param_5[7] = *(undefined4 *)(lVar1 + 0x40);
        param_5[8] = *(undefined4 *)(lVar1 + 0x44);
      }
    }
    else {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1ac8,"rpcCtrlPerfRatedTdpGetStatus_v1A_1F",4,
                   "NVRM: RPC to fetch RATED_TDP status failed with error 0x%x\n");
    }
  }
  return iVar2;
}


// ===== 004cc0c0 rpcCtrlPerfRatedTdpSetControl_v1A_1F =====

int rpcCtrlPerfRatedTdpSetControl_v1A_1F
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined4 *param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0x98,0x10);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    iVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      *(undefined4 *)(lVar1 + 0x2c) = param_5[1];
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1ae8,"rpcCtrlPerfRatedTdpSetControl_v1A_1F",4,
                     "NVRM: RPC to set RATED_TDP control action failed with error 0x%x\n");
      }
    }
  }
  return iVar2;
}


// ===== 004cc180 rpcCtrlFreePmaStream_v1A_1F =====

int rpcCtrlFreePmaStream_v1A_1F
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined4 *param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0x99,0xc);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    iVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1b08,"rpcCtrlFreePmaStream_v1A_1F",4,
                     "NVRM: PMA Stream free RPC failed with error 0x%x\n");
      }
    }
  }
  return iVar2;
}


// ===== 004cc240 rpcCtrlTimerSetGrTickFreq_v1A_1F =====

int rpcCtrlTimerSetGrTickFreq_v1A_1F
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined1 *param_5)

{
  long lVar1;
  char cVar2;
  int iVar3;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  cVar2 = rmcfg_IsHOPPER_CLASSIC_GPUSorBetter();
  iVar3 = 0x56;
  if (cVar2 == '\0') {
    iVar3 = rpcWriteCommonHeader(param_1,param_2,0x9a,0xc);
    if (iVar3 == 0) {
      *(undefined4 *)(lVar1 + 0x20) = param_3;
      iVar3 = 0x1f;
      *(undefined4 *)(lVar1 + 0x24) = param_4;
      if (param_5 != (undefined1 *)0x0) {
        *(undefined1 *)(lVar1 + 0x28) = *param_5;
        iVar3 = _issueRpcAndWait(param_1,param_2);
        if (iVar3 != 0) {
          nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1b2e,"rpcCtrlTimerSetGrTickFreq_v1A_1F",4,
                       "NVRM: RPC to set GR update/tick frequency failed with error 0x%x\n");
        }
      }
    }
  }
  return iVar3;
}


// ===== 004cc310 rpcCtrlFifoSetupVfZombieSubctxPdb_v1A_23 =====

undefined8
rpcCtrlFifoSetupVfZombieSubctxPdb_v1A_23
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined8 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x9b,0x20);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined8 *)0x0) {
      *(undefined8 *)(lVar1 + 0x28) = *param_5;
      *(undefined8 *)(lVar1 + 0x30) = param_5[1];
      *(undefined4 *)(lVar1 + 0x38) = *(undefined4 *)(param_5 + 2);
      *(undefined4 *)(lVar1 + 0x3c) = *(undefined4 *)((long)param_5 + 0x14);
      uVar2 = _issueRpcAndWait(param_1,param_2);
      return uVar2;
    }
    uVar2 = 0x1f;
  }
  return uVar2;
}


// ===== 004cc3b0 rpcCtrlDbgSetSingleSmSingleStep_v1C_02 =====

int rpcCtrlDbgSetSingleSmSingleStep_v1C_02
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined4 *param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0x9d,0x10);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    iVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      *(undefined1 *)(lVar1 + 0x2c) = *(undefined1 *)(param_5 + 1);
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1b6d,"rpcCtrlDbgSetSingleSmSingleStep_v1C_02",4,
                     "NVRM: RPC to set single SM single step failed with error 0x%x\n");
      }
    }
  }
  return iVar2;
}


// ===== 004cc470 rpcCtrlGrGetTpcPartitionMode_v1C_04 =====

int rpcCtrlGrGetTpcPartitionMode_v1C_04
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined4 *param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0x9e,0x28);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    iVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      *(undefined4 *)(lVar1 + 0x2c) = param_5[1];
      *(undefined1 *)(lVar1 + 0x30) = *(undefined1 *)(param_5 + 2);
      *(undefined4 *)(lVar1 + 0x38) = param_5[4];
      *(undefined8 *)(lVar1 + 0x40) = *(undefined8 *)(param_5 + 6);
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1b8d,"rpcCtrlGrGetTpcPartitionMode_v1C_04",4,
                     "NVRM: RPC to get gr tpc partition mode failed with error 0x%x\n");
      }
    }
  }
  return iVar2;
}


// ===== 004cc540 rpcCtrlGrSetTpcPartitionMode_v1C_04 =====

int rpcCtrlGrSetTpcPartitionMode_v1C_04
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined4 *param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0x9f,0x28);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    iVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      *(undefined4 *)(lVar1 + 0x2c) = param_5[1];
      *(undefined1 *)(lVar1 + 0x30) = *(undefined1 *)(param_5 + 2);
      *(undefined4 *)(lVar1 + 0x38) = param_5[4];
      *(undefined8 *)(lVar1 + 0x40) = *(undefined8 *)(param_5 + 6);
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1bad,"rpcCtrlGrSetTpcPartitionMode_v1C_04",4,
                     "NVRM: RPC to set gr tpc partition mode failed with error 0x%x\n");
      }
    }
  }
  return iVar2;
}


// ===== 004cc610 rpcCtrlInternalMemsysSetZbcReferenced_v1F_05 =====

int rpcCtrlInternalMemsysSetZbcReferenced_v1F_05
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined1 *param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0xb7,0xc);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    iVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined1 *)0x0) {
      *(undefined1 *)(lVar1 + 0x28) = *param_5;
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1bd8,"rpcCtrlInternalMemsysSetZbcReferenced_v1F_05",4
                     ,"NVRM: RPC to internal memsys set zbc referenced failed with error 0x%x\n");
      }
    }
  }
  return iVar2;
}


// ===== 004cc6d0 rpcCtrlInternalMemsysSetZbcReferenced_v2A_00 =====

int rpcCtrlInternalMemsysSetZbcReferenced_v2A_00
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,long param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0xb7,0xc);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    iVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != 0) {
      *(undefined1 *)(lVar1 + 0x28) = *(undefined1 *)(param_5 + 4);
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1c01,"rpcCtrlInternalMemsysSetZbcReferenced_v2A_00",4
                     ,"NVRM: RPC to internal memsys set zbc referenced failed with error 0x%x\n");
      }
    }
  }
  return iVar2;
}


// ===== 004cc790 rpcCtrlInternalMemsysSetZbcReferenced_v2B_0E =====

int rpcCtrlInternalMemsysSetZbcReferenced_v2B_0E
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined4 *param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0xb7,0x10);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    iVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      *(undefined1 *)(lVar1 + 0x2c) = *(undefined1 *)(param_5 + 1);
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1c2a,"rpcCtrlInternalMemsysSetZbcReferenced_v2B_0E",4
                     ,"NVRM: RPC to internal memsys set zbc referenced failed with error 0x%x\n");
      }
    }
  }
  return iVar2;
}


// ===== 004cc860 rpcCtrlFabricMemoryDescribe_v1E_0C =====

int rpcCtrlFabricMemoryDescribe_v1E_0C
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined8 *param_5)

{
  long lVar1;
  int iVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0xb3,0x820);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    iVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined8 *)0x0) {
      *(undefined8 *)(lVar1 + 0x28) = *param_5;
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 == 0) {
        portMemSet(param_5,0,0x858);
        lVar3 = 0;
        param_5[1] = *(undefined8 *)(lVar1 + 0x30);
        do {
          *(undefined4 *)((long)param_5 + lVar3 + 0x10) = *(undefined4 *)(lVar1 + 0x38 + lVar3);
          lVar3 = lVar3 + 4;
        } while (lVar3 != 0x800);
        *(undefined4 *)(param_5 + 0x102) = *(undefined4 *)(lVar1 + 0x838);
      }
      else {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1c57,"rpcCtrlFabricMemoryDescribe_v1E_0C",4,
                     "NVRM: RPC to 00f8 describe failed with error 0x%x\n",iVar2);
      }
    }
  }
  return iVar2;
}


// ===== 004cc970 rpcCtrlFabricMemStats_v1E_0C =====

int rpcCtrlFabricMemStats_v1E_0C
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined8 *param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0xb4,0x18);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    iVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined8 *)0x0) {
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 == 0) {
        *param_5 = *(undefined8 *)(lVar1 + 0x28);
        param_5[1] = *(undefined8 *)(lVar1 + 0x30);
      }
      else {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1c84,"rpcCtrlFabricMemStats_v1E_0C",4,
                     "NVRM: RPC to fabric memory stats failed with error 0x%x\n");
      }
    }
  }
  return iVar2;
}


// ===== 004cca30 rpcCtrlInternalPromoteFaultMethodBuffers_v1E_07 =====

ulong rpcCtrlInternalPromoteFaultMethodBuffers_v1E_07
                (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
                undefined8 param_5)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0xaf,0x60);
  uVar4 = (ulong)uVar2;
  if (uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    uVar4 = 0x1f;
    iVar3 = serialize_NVA06C_CTRL_INTERNAL_PROMOTE_FAULT_METHOD_BUFFERS_PARAMS_v1E_07
                      (param_5,lVar1 + 0x28,0,0);
    if (iVar3 == 0) {
      uVar2 = _issueRpcAndWait(param_1,param_2);
      uVar4 = (ulong)uVar2;
      if (uVar2 != 0) {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1caf,
                     "rpcCtrlInternalPromoteFaultMethodBuffers_v1E_07",4,
                     "NVRM: RPC to promote fault method buffers failed with error 0x%x\n");
        uVar4 = (ulong)uVar2;
      }
    }
  }
  return uVar4 & 0xffffffff;
}


// ===== 004ccaf0 rpcCtrlInternalQuiescePmaChannel_v1C_08 =====

int rpcCtrlInternalQuiescePmaChannel_v1C_08
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined4 *param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0xa7,0x10);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    iVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      *(undefined1 *)(lVar1 + 0x2c) = *(undefined1 *)(param_5 + 1);
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1cd2,"rpcCtrlInternalQuiescePmaChannel_v1C_08",4,
                     "NVRM: Quiesce PMA channel RPC failed with error 0x%x\n");
      }
    }
  }
  return iVar2;
}


// ===== 004ccbb0 rpcCtrlInternalSriovPromotePmaStream_v1C_0C =====

int rpcCtrlInternalSriovPromotePmaStream_v1C_0C
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined4 *param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0xad,0x38);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    iVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      *(undefined8 *)(lVar1 + 0x30) = *(undefined8 *)(param_5 + 2);
      *(undefined8 *)(lVar1 + 0x38) = *(undefined8 *)(param_5 + 4);
      *(undefined8 *)(lVar1 + 0x40) = *(undefined8 *)(param_5 + 6);
      *(undefined8 *)(lVar1 + 0x48) = *(undefined8 *)(param_5 + 8);
      *(undefined1 *)(lVar1 + 0x50) = *(undefined1 *)(param_5 + 10);
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1cf2,"rpcCtrlInternalSriovPromotePmaStream_v1C_0C",4,
                     "NVRM: RPC to promote PMA stream for full SRIOV failed with error 0x%x\n");
      }
    }
  }
  return iVar2;
}


// ===== 004ccc90 rpcCtrlDbgClearAllSmErrorStates_v1A_0C =====

undefined8
rpcCtrlDbgClearAllSmErrorStates_v1A_0C
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x6c,0x10);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    uVar2 = 0x1f;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      *(undefined4 *)(lVar1 + 0x2c) = param_5[1];
      uVar2 = _issueRpcAndWait(param_1,param_2);
      if ((int)uVar2 == 0) {
        *param_5 = *(undefined4 *)(lVar1 + 0x28);
        param_5[1] = *(undefined4 *)(lVar1 + 0x2c);
      }
    }
  }
  return uVar2;
}


// ===== 004ccd20 rpcCtrlDbgSetExceptionMask_v1A_0C =====

undefined8
rpcCtrlDbgSetExceptionMask_v1A_0C
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x6e,0xc);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    uVar2 = 0x1f;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      uVar2 = _issueRpcAndWait(param_1,param_2);
      if ((int)uVar2 == 0) {
        *param_5 = *(undefined4 *)(lVar1 + 0x28);
      }
    }
  }
  return uVar2;
}


// ===== 004ccdb0 rpcCtrlDbgReadAllSmErrorStates_v21_06 =====

int rpcCtrlDbgReadAllSmErrorStates_v21_06
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined4 *param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  ulong uVar6;
  uint uVar7;
  
  if (*(uint *)(param_2 + 0x4f0) < 0xf40) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1d3e,"rpcCtrlDbgReadAllSmErrorStates_v21_06",4,
                 "NVRM: NVRM_RPC: Insufficient space in message buffer to copy all SMs error states\n"
                );
    return 2;
  }
  if ((uint)param_5[1] < 0x65) {
    puVar2 = *(undefined4 **)(param_2 + 0x4d8);
    iVar4 = rpcWriteCommonHeader(param_1,param_2,0x6d);
    if (iVar4 == 0) {
      puVar2[8] = param_3;
      puVar2[9] = param_4;
      if (param_5[1] != 0) {
        uVar7 = 0;
        do {
          puVar2[0x3cf] = param_5[0x4b5] + uVar7;
          uVar5 = param_5[1] - uVar7;
          if (0x50 < uVar5) {
            uVar5 = 0x50;
          }
          puVar2[0xb] = uVar5;
          puVar2[10] = *param_5;
          iVar4 = _issueRpcAndWait(param_1,param_2);
          if (iVar4 != 0) {
            return iVar4;
          }
          if (0x50 < (uint)puVar2[0xb]) {
            return 0x1f;
          }
          if (puVar2[0xb] != 0) {
            uVar5 = 0;
            puVar3 = puVar2;
            do {
              uVar6 = (ulong)(uVar5 + uVar7);
              uVar5 = uVar5 + 1;
              param_5[uVar6 * 0xc + 2] = puVar3[0xc];
              param_5[uVar6 * 0xc + 3] = puVar3[0xd];
              param_5[uVar6 * 0xc + 4] = puVar3[0xe];
              param_5[uVar6 * 0xc + 5] = puVar3[0xf];
              param_5[uVar6 * 0xc + 6] = puVar3[0x10];
              *(undefined8 *)(param_5 + uVar6 * 0xc + 8) = *(undefined8 *)(puVar3 + 0x12);
              *(undefined8 *)(param_5 + uVar6 * 0xc + 10) = *(undefined8 *)(puVar3 + 0x14);
              param_5[uVar6 * 0xc + 0xc] = puVar3[0x16];
              param_5[uVar6 * 0xc + 0xd] = puVar3[0x17];
              puVar3 = puVar3 + 0xc;
            } while (uVar5 < (uint)puVar2[0xb]);
          }
          *(undefined1 *)(param_5 + 0x4b3) = *(undefined1 *)(puVar2 + 0x3cd);
          uVar1 = puVar2[0x3ce];
          param_5[0x4b4] = uVar1;
          param_5[0x4b2] = uVar1;
          uVar7 = uVar7 + puVar2[0xb];
        } while (uVar7 < (uint)param_5[1]);
        return 0;
      }
    }
    return iVar4;
  }
  return 0x1f;
}


// ===== 004ccfc0 rpcCtrlExecPartitionsCreate_v24_05 =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

int rpcCtrlExecPartitionsCreate_v24_05
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,long param_5)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  lVar3 = *(long *)(param_2 + 0x4d8);
  iVar1 = rpcWriteCommonHeader(param_1,param_2,0xb8,0x1b4);
  if (iVar1 != 0) {
    return iVar1;
  }
  *(undefined4 *)(lVar3 + 0x20) = param_3;
  *(undefined4 *)(lVar3 + 0x24) = param_4;
  iVar1 = serialize_NVC637_CTRL_CMD_EXEC_PARTITIONS_CREATE_v24_05(param_5,lVar3 + 0x2c,0,0);
  if (iVar1 == 0) {
    iVar1 = _issueRpcAndWait(param_1,param_2);
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1d92,"rpcCtrlExecPartitionsCreate_v24_05",4,
                   "NVRM: RPC to create exec partitions failed with error 0x%x\n",iVar1);
      return iVar1;
    }
    if (*(int *)(lVar3 + 0x28) != 0) {
      return *(int *)(lVar3 + 0x28);
    }
    if ((param_5 != 0) && (*(uint *)(lVar3 + 0x30) < 9)) {
      if (*(uint *)(lVar3 + 0x30) != 0) {
        lVar2 = 0;
        puVar4 = (undefined4 *)(lVar3 + 0x60);
        puVar5 = (undefined4 *)(param_5 + 0x3c);
        do {
          *(undefined4 *)(param_5 + 0x1ac + lVar2 * 4) = *(undefined4 *)(lVar3 + 0x1b4 + lVar2 * 4);
          lVar2 = lVar2 + 1;
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 0xc;
          puVar5 = puVar5 + 0xd;
        } while ((uint)lVar2 < *(uint *)(lVar3 + 0x30));
      }
      lVar3 = gpuGetRpc(param_1);
      if (lVar3 == 0) {
        return 0;
      }
      iVar1 = (**(code **)(lVar3 + 0x290))(param_1,lVar3,*(code **)(lVar3 + 0x290));
      if (iVar1 == 0) {
        return 0;
      }
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1d8c,"rpcCtrlExecPartitionsCreate_v24_05",4,
                   "NVRM: NVRM_RPC: GET_CONSOLIDATED_GR_STATIC_INFO : failed.\n");
      return iVar1;
    }
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1d85,"rpcCtrlExecPartitionsCreate_v24_05",4,
                 "NVRM: NVRM_RPC: deserialize exec partition creation params : failed.\n");
  }
  return 0x1f;
}


// ===== 004cd1a0 rpcCtrlExecPartitionsDelete_v1F_0A =====

int rpcCtrlExecPartitionsDelete_v1F_0A
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,uint *param_5)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  
  lVar2 = *(long *)(param_2 + 0x4d8);
  iVar3 = rpcWriteCommonHeader(param_1,param_2,0xb9,0x2c);
  if (iVar3 == 0) {
    *(undefined4 *)(lVar2 + 0x20) = param_3;
    *(undefined4 *)(lVar2 + 0x24) = param_4;
    if (param_5 != (uint *)0x0) {
      uVar1 = *param_5;
      if (uVar1 < 9) {
        *(uint *)(lVar2 + 0x28) = uVar1;
        if (uVar1 != 0) {
          lVar4 = 0;
          do {
            *(undefined4 *)(lVar2 + 0x2c + lVar4) = *(undefined4 *)((long)param_5 + lVar4 + 4);
            lVar4 = lVar4 + 4;
          } while (lVar4 != (ulong)uVar1 << 2);
        }
        iVar3 = _issueRpcAndWait(param_1,param_2);
        if (iVar3 == 0) {
          return 0;
        }
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1dba,"rpcCtrlExecPartitionsDelete_v1F_0A",4,
                     "NVRM: RPC to delete exec partitions failed with error 0x%x\n");
        return iVar3;
      }
    }
    iVar3 = 0x1f;
  }
  return iVar3;
}


// ===== 004cd2b0 rpcCtrlExecPartitionsExport_v29_0C =====

int rpcCtrlExecPartitionsExport_v29_0C
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined4 *param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0xe2,0x70);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    iVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x30) = *param_5;
      *(undefined1 *)(lVar1 + 0x88) = *(undefined1 *)(param_5 + 0x16);
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 == 0) {
        *(undefined8 *)(param_5 + 2) = *(undefined8 *)(lVar1 + 0x38);
        *(undefined8 *)(param_5 + 4) = *(undefined8 *)(lVar1 + 0x40);
        *(undefined8 *)(param_5 + 6) = *(undefined8 *)(lVar1 + 0x48);
        *(undefined8 *)(param_5 + 8) = *(undefined8 *)(lVar1 + 0x50);
        param_5[0xe] = *(undefined4 *)(lVar1 + 0x68);
        param_5[0xf] = *(undefined4 *)(lVar1 + 0x6c);
        param_5[0x10] = *(undefined4 *)(lVar1 + 0x70);
        param_5[0x11] = *(undefined4 *)(lVar1 + 0x74);
        param_5[0x12] = *(undefined4 *)(lVar1 + 0x78);
        param_5[0x13] = *(undefined4 *)(lVar1 + 0x7c);
        param_5[0x14] = *(undefined4 *)(lVar1 + 0x80);
        param_5[0x15] = *(undefined4 *)(lVar1 + 0x84);
      }
      else {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1de3,"rpcCtrlExecPartitionsExport_v29_0C",4,
                     "NVRM: RPC to export exec partitions failed with error 0x%x\n");
      }
    }
  }
  return iVar2;
}


// ===== 004cd3e0 rpcCtrlGpfifoGetWorkSubmitToken_v1F_0A =====

int rpcCtrlGpfifoGetWorkSubmitToken_v1F_0A
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined4 *param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0xba,0xc);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    iVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 == 0) {
        *param_5 = *(undefined4 *)(lVar1 + 0x28);
      }
      else {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1e0d,"rpcCtrlGpfifoGetWorkSubmitToken_v1F_0A",4,
                     "NVRM: RPC to get work submit token failed with error 0x%x\n");
      }
    }
  }
  return iVar2;
}


// ===== 004cd4a0 rpcCtrlGpfifoSetWorkSubmitTokenNotifIndex_v1F_0A =====

int rpcCtrlGpfifoSetWorkSubmitTokenNotifIndex_v1F_0A
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined4 *param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0xbb,0xc);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    iVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1e36,
                     "rpcCtrlGpfifoSetWorkSubmitTokenNotifIndex_v1F_0A",4,
                     "NVRM: RPC to set work submit token notify index failed with error 0x%x\n");
      }
    }
  }
  return iVar2;
}


// ===== 004cd560 rpcCtrlMasterGetVirtualFunctionErrorContIntrMask_v1F_0D =====

int rpcCtrlMasterGetVirtualFunctionErrorContIntrMask_v1F_0D
              (long param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5)

{
  char cVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_2 + 0x4d8);
  if (*(char *)(param_1 + 0x4913) == '\0') {
LAB_004cd5a9:
    iVar2 = rpcWriteCommonHeader(param_1,param_2,0xbd,0x10);
    if (iVar2 == 0) {
      *(undefined4 *)(lVar3 + 0x20) = param_3;
      iVar2 = 0x1f;
      *(undefined4 *)(lVar3 + 0x24) = param_4;
      if (param_5 != (undefined4 *)0x0) {
        iVar2 = _issueRpcAndWait(param_1,param_2);
        if (iVar2 == 0) {
          *param_5 = *(undefined4 *)(lVar3 + 0x28);
          param_5[1] = *(undefined4 *)(lVar3 + 0x2c);
        }
        else {
          nvDbg_Printf("src/kernel/vgpu/rpc.c",0x1e68,
                       "rpcCtrlMasterGetVirtualFunctionErrorContIntrMask_v1F_0D",4,
                       "NVRM: RPC to get vf error cont intr mask failed with error 0x%x\n");
        }
      }
    }
  }
  else {
    if (*(long *)(param_1 + 0x1bc0) != 0) {
      cVar1 = kmigmgrIsMIGGpuInstancingEnabled_IMPL();
      if (cVar1 != '\0') goto LAB_004cd5a9;
    }
    lVar3 = gpuGetStaticInfo(param_1);
    iVar2 = 0;
    *param_5 = *(undefined4 *)(lVar3 + 0x25ed4);
    param_5[1] = *(undefined4 *)(lVar3 + 0x25ed8);
  }
  return iVar2;
}


// ===== 004cd670 rpcCtrlDbgSuspendContext_v1A_10 =====

undefined8
rpcCtrlDbgSuspendContext_v1A_10
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x84,0x10);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    uVar2 = 0x1f;
    if (param_5 != (undefined4 *)0x0) {
      uVar2 = _issueRpcAndWait(param_1,param_2);
      if ((int)uVar2 == 0) {
        *param_5 = *(undefined4 *)(lVar1 + 0x28);
        param_5[1] = *(undefined4 *)(lVar1 + 0x2c);
      }
    }
  }
  return uVar2;
}


// ===== 004cd700 rpcCtrlDbgResumeContext_v1A_10 =====

void rpcCtrlDbgResumeContext_v1A_10
               (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0x85,8);
  if (iVar2 != 0) {
    return;
  }
  *(undefined4 *)(lVar1 + 0x20) = param_3;
  *(undefined4 *)(lVar1 + 0x24) = param_4;
  _issueRpcAndWait(param_1,param_2);
  return;
}


// ===== 004cd780 rpcCtrlDbgExecRegOps_v1A_10 =====

int rpcCtrlDbgExecRegOps_v1A_10
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined1 *param_5)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  uint uVar5;
  ulong uVar6;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0x86,0xc90);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if ((param_5 == (undefined1 *)0x0) || (100 < *(uint *)(param_5 + 4))) {
      iVar2 = 0x1f;
    }
    else {
      *(undefined1 *)(lVar1 + 0x28) = *param_5;
      iVar2 = *(int *)(param_5 + 4);
      *(int *)(lVar1 + 0x2c) = iVar2;
      uVar6 = 0;
      if (iVar2 != 0) {
        do {
          uVar5 = (int)uVar6 + 1;
          lVar3 = uVar6 * 0x20;
          *(undefined1 *)(lVar1 + 0x30 + lVar3) = param_5[lVar3 + 8];
          *(undefined1 *)(lVar1 + 0x31 + lVar3) = param_5[lVar3 + 9];
          *(undefined1 *)(lVar1 + 0x33 + lVar3) = param_5[lVar3 + 0xb];
          *(undefined4 *)(lVar1 + 0x34 + lVar3) = *(undefined4 *)(param_5 + lVar3 + 0xc);
          *(undefined4 *)(lVar1 + 0x38 + lVar3) = *(undefined4 *)(param_5 + lVar3 + 0x10);
          *(undefined4 *)(lVar1 + 0x3c + lVar3) = *(undefined4 *)(param_5 + lVar3 + 0x14);
          *(undefined4 *)(lVar1 + 0x4c + lVar3) = *(undefined4 *)(param_5 + lVar3 + 0x24);
          *(undefined4 *)(lVar1 + 0x48 + lVar3) = *(undefined4 *)(param_5 + lVar3 + 0x20);
          *(undefined4 *)(lVar1 + 0x44 + lVar3) = *(undefined4 *)(param_5 + lVar3 + 0x1c);
          *(undefined4 *)(lVar1 + 0x40 + lVar3) = *(undefined4 *)(param_5 + lVar3 + 0x18);
          uVar6 = (ulong)uVar5;
        } while (uVar5 < *(uint *)(param_5 + 4));
      }
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if ((iVar2 == 0) && (*(int *)(lVar1 + 0x2c) != 0)) {
        uVar6 = 0;
        do {
          uVar5 = (int)uVar6 + 1;
          lVar4 = uVar6 * 0x20;
          lVar3 = lVar1 + lVar4;
          param_5[lVar4 + 10] = *(undefined1 *)(lVar3 + 0x32);
          *(undefined4 *)(param_5 + lVar4 + 0x1c) = *(undefined4 *)(lVar3 + 0x44);
          *(undefined4 *)(param_5 + lVar4 + 0x18) = *(undefined4 *)(lVar3 + 0x40);
          uVar6 = (ulong)uVar5;
        } while (uVar5 < *(uint *)(lVar1 + 0x2c));
      }
    }
  }
  return iVar2;
}


// ===== 004cd900 rpcCtrlDbgSetModeMmuDebug_v1A_10 =====

undefined8
rpcCtrlDbgSetModeMmuDebug_v1A_10
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x87,0xc);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      uVar2 = _issueRpcAndWait(param_1,param_2);
      return uVar2;
    }
    uVar2 = 0x1f;
  }
  return uVar2;
}


// ===== 004cd990 rpcCtrlDbgSetModeMmuGccDebug_v2A_05 =====

undefined8
rpcCtrlDbgSetModeMmuGccDebug_v2A_05
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0xd9,0xc);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      uVar2 = _issueRpcAndWait(param_1,param_2);
      return uVar2;
    }
    uVar2 = 0x1f;
  }
  return uVar2;
}


// ===== 004cda20 rpcCtrlDbgClearSingleSmErrorState_v1A_10 =====

undefined8
rpcCtrlDbgClearSingleSmErrorState_v1A_10
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x89,0x10);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      *(undefined4 *)(lVar1 + 0x2c) = param_5[1];
      uVar2 = _issueRpcAndWait(param_1,param_2);
      return uVar2;
    }
    uVar2 = 0x1f;
  }
  return uVar2;
}


// ===== 004cdac0 rpcCtrlDbgReadSingleSmErrorState_v21_06 =====

undefined8
rpcCtrlDbgReadSingleSmErrorState_v21_06
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x88,0x40);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    uVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      *(undefined4 *)(lVar1 + 0x2c) = param_5[1];
      uVar2 = _issueRpcAndWait(param_1,param_2);
      if ((int)uVar2 == 0) {
        param_5[2] = *(undefined4 *)(lVar1 + 0x30);
        param_5[3] = *(undefined4 *)(lVar1 + 0x34);
        param_5[4] = *(undefined4 *)(lVar1 + 0x38);
        param_5[5] = *(undefined4 *)(lVar1 + 0x3c);
        param_5[6] = *(undefined4 *)(lVar1 + 0x40);
        *(undefined8 *)(param_5 + 8) = *(undefined8 *)(lVar1 + 0x48);
        *(undefined8 *)(param_5 + 10) = *(undefined8 *)(lVar1 + 0x50);
        param_5[0xc] = *(undefined4 *)(lVar1 + 0x58);
        param_5[0xd] = *(undefined4 *)(lVar1 + 0x5c);
        return uVar2;
      }
    }
  }
  return uVar2;
}


// ===== 004cdb90 rpcCtrlDbgSetModeErrbarDebug_v1A_10 =====

undefined8
rpcCtrlDbgSetModeErrbarDebug_v1A_10
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x8a,0xc);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      uVar2 = _issueRpcAndWait(param_1,param_2);
      return uVar2;
    }
    uVar2 = 0x1f;
  }
  return uVar2;
}


// ===== 004cdc20 rpcCtrlDbgSetNextStopTriggerType_v1A_10 =====

undefined8
rpcCtrlDbgSetNextStopTriggerType_v1A_10
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x8b,0xc);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      uVar2 = _issueRpcAndWait(param_1,param_2);
      return uVar2;
    }
    uVar2 = 0x1f;
  }
  return uVar2;
}


// ===== 004cdcb0 rpcCtrlDmaSetDefaultVaspace_v1A_0E =====

undefined8
rpcCtrlDmaSetDefaultVaspace_v1A_0E
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x78,0xc);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    uVar2 = 0x1f;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      uVar2 = _issueRpcAndWait(param_1,param_2);
      if ((int)uVar2 == 0) {
        *param_5 = *(undefined4 *)(lVar1 + 0x28);
      }
    }
  }
  return uVar2;
}


// ===== 004cdd40 rpcCtrlGetCePceMask_v1A_0E =====

undefined8
rpcCtrlGetCePceMask_v1A_0E
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x79,0x10);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    uVar2 = 0x1f;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      uVar2 = _issueRpcAndWait(param_1,param_2);
      if ((int)uVar2 == 0) {
        param_5[1] = *(undefined4 *)(lVar1 + 0x2c);
      }
    }
  }
  return uVar2;
}


// ===== 004cddd0 rpcCtrlGetZbcClearTableEntry_v1A_0E =====

undefined8
rpcCtrlGetZbcClearTableEntry_v1A_0E
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,long param_5)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x7a,0x40);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    uVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != 0) {
      *(undefined4 *)(lVar1 + 0x54) = *(undefined4 *)(param_5 + 0x2c);
      *(undefined4 *)(lVar1 + 0x5c) = *(undefined4 *)(param_5 + 0x34);
      uVar2 = _issueRpcAndWait(param_1,param_2);
      if ((int)uVar2 == 0) {
        lVar3 = 0;
        do {
          *(undefined4 *)(param_5 + lVar3) = *(undefined4 *)(lVar1 + 0x28 + lVar3);
          *(undefined4 *)(param_5 + 0x10 + lVar3) = *(undefined4 *)(lVar1 + 0x38 + lVar3);
          lVar3 = lVar3 + 4;
        } while (lVar3 != 0x10);
        *(undefined4 *)(param_5 + 0x20) = *(undefined4 *)(lVar1 + 0x48);
        *(undefined4 *)(param_5 + 0x24) = *(undefined4 *)(lVar1 + 0x4c);
        *(undefined4 *)(param_5 + 0x28) = *(undefined4 *)(lVar1 + 0x50);
        *(undefined4 *)(param_5 + 0x2c) = *(undefined4 *)(lVar1 + 0x54);
        *(undefined1 *)(param_5 + 0x30) = *(undefined1 *)(lVar1 + 0x58);
        *(undefined4 *)(param_5 + 0x34) = *(undefined4 *)(lVar1 + 0x5c);
        return uVar2;
      }
    }
  }
  return uVar2;
}


// ===== 004cdeb0 rpcCtrlGetNvlinkStatus_v23_04 =====

int rpcCtrlGetNvlinkStatus_v23_04
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,uint *param_5)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  
  lVar2 = *(long *)(param_2 + 0x4d8);
  iVar1 = rpcWriteCommonHeader(param_1,param_2,0x7c,0xc10);
  if (iVar1 == 0) {
    *(undefined4 *)(lVar2 + 0x20) = param_3;
    iVar1 = 0x1f;
    *(undefined4 *)(lVar2 + 0x24) = param_4;
    if ((param_5 != (uint *)0x0) && (iVar1 = _issueRpcAndWait(param_1,param_2), iVar1 == 0)) {
      uVar3 = *(uint *)(lVar2 + 0x28);
      *param_5 = uVar3;
      if (uVar3 != 0) {
        param_5 = param_5 + 0x28;
        lVar2 = lVar2 + 0x70;
        uVar4 = 0;
        while( true ) {
          for (; (uVar3 & 1) == 0; uVar3 = uVar3 >> 1) {
            uVar4 = uVar4 + 1;
            param_5 = param_5 + 0x36;
            lVar2 = lVar2 + 0x80;
          }
          if (0x17 < uVar4) {
            return 0;
          }
          param_5[-0x20] = *(uint *)(lVar2 + -0x40);
          *(undefined1 *)(param_5 + -0x1f) = *(undefined1 *)(lVar2 + -0x3c);
          *(undefined1 *)((long)param_5 + -0x7b) = *(undefined1 *)(lVar2 + -0x3b);
          param_5[-0x1e] = *(uint *)(lVar2 + -0x38);
          *(undefined1 *)(param_5 + -0x1d) = *(undefined1 *)(lVar2 + -0x34);
          *(undefined1 *)((long)param_5 + -0x73) = *(undefined1 *)(lVar2 + -0x33);
          *(undefined1 *)((long)param_5 + -0x71) = *(undefined1 *)(lVar2 + -0x32);
          *(undefined1 *)(param_5 + -0x1c) = *(undefined1 *)(lVar2 + -0x31);
          *(undefined1 *)((long)param_5 + -0x6f) = *(undefined1 *)(lVar2 + -0x30);
          param_5[-0x1b] = *(uint *)(lVar2 + -0x2c);
          param_5[-0x17] = *(uint *)(lVar2 + -0x28);
          *(undefined1 *)(param_5 + -0x12) = *(undefined1 *)(lVar2 + -0x24);
          *(undefined1 *)((long)param_5 + -0x46) = *(undefined1 *)(lVar2 + -0x23);
          *(undefined1 *)((long)param_5 + -0x45) = *(undefined1 *)(lVar2 + -0x22);
          param_5[-8] = *(uint *)(lVar2 + -0x20);
          param_5[-7] = *(uint *)(lVar2 + -0x1c);
          *(undefined2 *)(param_5 + -6) = *(undefined2 *)(lVar2 + -0x18);
          *(undefined2 *)((long)param_5 + -0x16) = *(undefined2 *)(lVar2 + -0x16);
          *(undefined2 *)(param_5 + -5) = *(undefined2 *)(lVar2 + -0x14);
          param_5[-4] = *(uint *)(lVar2 + -0x10);
          *(undefined8 *)(param_5 + -2) = *(undefined8 *)(lVar2 + -8);
          portMemCopy(param_5,0x10,lVar2,0x10);
          param_5[6] = *(uint *)(lVar2 + 0x10);
          param_5[7] = *(uint *)(lVar2 + 0x14);
          *(undefined2 *)(param_5 + 8) = *(undefined2 *)(lVar2 + 0x18);
          *(undefined2 *)((long)param_5 + 0x22) = *(undefined2 *)(lVar2 + 0x1a);
          *(undefined2 *)(param_5 + 9) = *(undefined2 *)(lVar2 + 0x1c);
          param_5[10] = *(uint *)(lVar2 + 0x20);
          *(undefined8 *)(param_5 + 0xc) = *(undefined8 *)(lVar2 + 0x28);
          portMemCopy(param_5 + 0xe,0x10,lVar2 + 0x30,0x10);
          uVar3 = uVar3 >> 1;
          if (uVar3 == 0) break;
          uVar4 = uVar4 + 1;
          param_5 = param_5 + 0x36;
          lVar2 = lVar2 + 0x80;
        }
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}


// ===== 004ce0d0 rpcCtrlGetNvlinkStatus_v28_09 =====

int rpcCtrlGetNvlinkStatus_v28_09
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,uint *param_5)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  
  lVar2 = *(long *)(param_2 + 0x4d8);
  iVar1 = rpcWriteCommonHeader(param_1,param_2,0x7c,0xd90);
  if (iVar1 == 0) {
    *(undefined4 *)(lVar2 + 0x20) = param_3;
    iVar1 = 0x1f;
    *(undefined4 *)(lVar2 + 0x24) = param_4;
    if ((param_5 != (uint *)0x0) && (iVar1 = _issueRpcAndWait(param_1,param_2), iVar1 == 0)) {
      uVar3 = *(uint *)(lVar2 + 0x28);
      *param_5 = uVar3;
      if (uVar3 != 0) {
        param_5 = param_5 + 0x28;
        lVar2 = lVar2 + 0x70;
        uVar4 = 0;
        while( true ) {
          for (; (uVar3 & 1) == 0; uVar3 = uVar3 >> 1) {
            uVar4 = uVar4 + 1;
            param_5 = param_5 + 0x36;
            lVar2 = lVar2 + 0x90;
          }
          if (0x17 < uVar4) {
            return 0;
          }
          param_5[-0x20] = *(uint *)(lVar2 + -0x40);
          *(undefined1 *)(param_5 + -0x1f) = *(undefined1 *)(lVar2 + -0x3c);
          *(undefined1 *)((long)param_5 + -0x7b) = *(undefined1 *)(lVar2 + -0x3b);
          param_5[-0x1e] = *(uint *)(lVar2 + -0x38);
          *(undefined1 *)(param_5 + -0x1d) = *(undefined1 *)(lVar2 + -0x34);
          *(undefined1 *)((long)param_5 + -0x73) = *(undefined1 *)(lVar2 + -0x33);
          *(undefined1 *)((long)param_5 + -0x71) = *(undefined1 *)(lVar2 + -0x32);
          *(undefined1 *)(param_5 + -0x1c) = *(undefined1 *)(lVar2 + -0x31);
          *(undefined1 *)((long)param_5 + -0x6f) = *(undefined1 *)(lVar2 + -0x30);
          param_5[-0x1b] = *(uint *)(lVar2 + -0x2c);
          param_5[-0x17] = *(uint *)(lVar2 + -0x28);
          *(undefined1 *)(param_5 + -0x12) = *(undefined1 *)(lVar2 + -0x24);
          *(undefined1 *)((long)param_5 + -0x46) = *(undefined1 *)(lVar2 + -0x23);
          *(undefined1 *)((long)param_5 + -0x45) = *(undefined1 *)(lVar2 + -0x22);
          param_5[-8] = *(uint *)(lVar2 + -0x20);
          param_5[-7] = *(uint *)(lVar2 + -0x1c);
          *(undefined2 *)(param_5 + -6) = *(undefined2 *)(lVar2 + -0x18);
          *(undefined2 *)((long)param_5 + -0x16) = *(undefined2 *)(lVar2 + -0x16);
          *(undefined2 *)(param_5 + -5) = *(undefined2 *)(lVar2 + -0x14);
          param_5[-4] = *(uint *)(lVar2 + -0x10);
          *(undefined8 *)(param_5 + -2) = *(undefined8 *)(lVar2 + -8);
          portMemCopy(param_5,0x10,lVar2,0x10);
          param_5[4] = *(uint *)(lVar2 + 0x10);
          param_5[6] = *(uint *)(lVar2 + 0x18);
          param_5[7] = *(uint *)(lVar2 + 0x1c);
          *(undefined2 *)(param_5 + 8) = *(undefined2 *)(lVar2 + 0x20);
          *(undefined2 *)((long)param_5 + 0x22) = *(undefined2 *)(lVar2 + 0x22);
          *(undefined2 *)(param_5 + 9) = *(undefined2 *)(lVar2 + 0x24);
          param_5[10] = *(uint *)(lVar2 + 0x28);
          *(undefined8 *)(param_5 + 0xc) = *(undefined8 *)(lVar2 + 0x30);
          portMemCopy(param_5 + 0xe,0x10,lVar2 + 0x38,0x10);
          uVar3 = uVar3 >> 1;
          param_5[0x12] = *(uint *)(lVar2 + 0x48);
          if (uVar3 == 0) break;
          uVar4 = uVar4 + 1;
          param_5 = param_5 + 0x36;
          lVar2 = lVar2 + 0x90;
        }
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}


// ===== 004ce300 rpcCtrlGetNvlinkStatus_v2B_11 =====

int rpcCtrlGetNvlinkStatus_v2B_11
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined4 *param_5)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  
  lVar2 = *(long *)(param_2 + 0x4d8);
  iVar1 = rpcWriteCommonHeader(param_1,param_2,0x7c,0xda0);
  if (iVar1 == 0) {
    *(undefined4 *)(lVar2 + 0x24) = param_4;
    iVar1 = 0x1f;
    *(undefined4 *)(lVar2 + 0x20) = param_3;
    if ((param_5 != (undefined4 *)0x0) && (iVar1 = _issueRpcAndWait(param_1,param_2), iVar1 == 0)) {
      *param_5 = *(undefined4 *)(lVar2 + 0x28);
      *(undefined1 *)(param_5 + 2) = *(undefined1 *)(lVar2 + 0x30);
      *(undefined8 *)(param_5 + 4) = *(undefined8 *)(lVar2 + 0x38);
      uVar4 = *(uint *)(lVar2 + 0x28);
      if (uVar4 != 0) {
        param_5 = param_5 + 0x28;
        lVar2 = lVar2 + 0x80;
        uVar3 = 0;
        while( true ) {
          for (; (uVar4 & 1) == 0; uVar4 = uVar4 >> 1) {
            uVar3 = uVar3 + 1;
            param_5 = param_5 + 0x36;
            lVar2 = lVar2 + 0x90;
          }
          if (0x17 < uVar3) {
            return 0;
          }
          param_5[-0x20] = *(undefined4 *)(lVar2 + -0x40);
          *(undefined1 *)(param_5 + -0x1f) = *(undefined1 *)(lVar2 + -0x3c);
          *(undefined1 *)((long)param_5 + -0x7b) = *(undefined1 *)(lVar2 + -0x3b);
          param_5[-0x1e] = *(undefined4 *)(lVar2 + -0x38);
          *(undefined1 *)(param_5 + -0x1d) = *(undefined1 *)(lVar2 + -0x34);
          *(undefined1 *)((long)param_5 + -0x73) = *(undefined1 *)(lVar2 + -0x33);
          *(undefined1 *)((long)param_5 + -0x71) = *(undefined1 *)(lVar2 + -0x32);
          *(undefined1 *)(param_5 + -0x1c) = *(undefined1 *)(lVar2 + -0x31);
          *(undefined1 *)((long)param_5 + -0x6f) = *(undefined1 *)(lVar2 + -0x30);
          param_5[-0x1b] = *(undefined4 *)(lVar2 + -0x2c);
          param_5[-0x17] = *(undefined4 *)(lVar2 + -0x28);
          *(undefined1 *)(param_5 + -0x12) = *(undefined1 *)(lVar2 + -0x24);
          *(undefined1 *)((long)param_5 + -0x46) = *(undefined1 *)(lVar2 + -0x23);
          *(undefined1 *)((long)param_5 + -0x45) = *(undefined1 *)(lVar2 + -0x22);
          param_5[-8] = *(undefined4 *)(lVar2 + -0x20);
          param_5[-7] = *(undefined4 *)(lVar2 + -0x1c);
          *(undefined2 *)(param_5 + -6) = *(undefined2 *)(lVar2 + -0x18);
          *(undefined2 *)((long)param_5 + -0x16) = *(undefined2 *)(lVar2 + -0x16);
          *(undefined2 *)(param_5 + -5) = *(undefined2 *)(lVar2 + -0x14);
          param_5[-4] = *(undefined4 *)(lVar2 + -0x10);
          *(undefined8 *)(param_5 + -2) = *(undefined8 *)(lVar2 + -8);
          portMemCopy(param_5,0x10,lVar2,0x10);
          param_5[4] = *(undefined4 *)(lVar2 + 0x10);
          param_5[6] = *(undefined4 *)(lVar2 + 0x18);
          param_5[7] = *(undefined4 *)(lVar2 + 0x1c);
          *(undefined2 *)(param_5 + 8) = *(undefined2 *)(lVar2 + 0x20);
          *(undefined2 *)((long)param_5 + 0x22) = *(undefined2 *)(lVar2 + 0x22);
          *(undefined2 *)(param_5 + 9) = *(undefined2 *)(lVar2 + 0x24);
          param_5[10] = *(undefined4 *)(lVar2 + 0x28);
          *(undefined8 *)(param_5 + 0xc) = *(undefined8 *)(lVar2 + 0x30);
          portMemCopy(param_5 + 0xe,0x10,lVar2 + 0x38,0x10);
          uVar4 = uVar4 >> 1;
          param_5[0x12] = *(undefined4 *)(lVar2 + 0x48);
          if (uVar4 == 0) break;
          uVar3 = uVar3 + 1;
          param_5 = param_5 + 0x36;
          lVar2 = lVar2 + 0x90;
        }
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}


// ===== 004ce520 rpcCtrlGetNvlinkStatus_v2D_01 =====

int rpcCtrlGetNvlinkStatus_v2D_01
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,long param_5)

{
  long lVar1;
  char cVar2;
  long lVar3;
  int iVar4;
  byte bVar5;
  ulong uVar6;
  long lVar7;
  uint uVar8;
  ulong uVar9;
  long lVar10;
  uint uVar11;
  uint local_68;
  uint local_4c;
  
  local_68 = *(int *)(param_2 + 0x4f0) - 0x40;
  if (local_68 < 0x90) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2021,"rpcCtrlGetNvlinkStatus_v2D_01",4,
                 "NVRM: NVRM_RPC: Insufficient space for any links in RPC buffer\n");
    return 2;
  }
  local_68 = local_68 / 0x90;
  lVar3 = *(long *)(param_2 + 0x4d8);
  portMemSet(param_5,0,0x3628);
  local_4c = 0;
  while( true ) {
    uVar8 = 0x24 - local_4c;
    if (local_68 < 0x24 - local_4c) {
      uVar8 = local_68;
    }
    uVar6 = 0;
    uVar11 = local_4c + uVar8;
    do {
      bVar5 = (byte)local_4c;
      local_4c = local_4c + 1;
      uVar6 = uVar6 | 1L << (bVar5 & 0x3f);
    } while (local_4c != uVar11);
    iVar4 = rpcWriteCommonHeader(param_1,param_2,0x7c,uVar8 * 0x90 + 0x20);
    if (iVar4 != 0) {
      return iVar4;
    }
    *(ulong *)(lVar3 + 0x38) = uVar6;
    *(undefined1 *)(lVar3 + 0x30) = 1;
    *(undefined4 *)(lVar3 + 0x20) = param_3;
    *(undefined4 *)(lVar3 + 0x24) = param_4;
    if (param_5 == 0) {
      return 0x1f;
    }
    iVar4 = _issueRpcAndWait(param_1,param_2);
    if (iVar4 != 0) break;
    cVar2 = *(char *)(lVar3 + 0x30);
    *(char *)(param_5 + 8) = cVar2;
    if (cVar2 != '\0') {
      *(ulong *)(param_5 + 0x10) = *(ulong *)(param_5 + 0x10) | *(ulong *)(lVar3 + 0x38);
    }
    uVar6 = *(ulong *)(lVar3 + 0x38);
    if (uVar6 != 0) {
      lVar7 = param_5 + 0xa0;
      uVar9 = 0;
      uVar8 = 0;
      while( true ) {
        for (; (uVar6 & 1) == 0; uVar6 = uVar6 >> 1) {
          uVar8 = uVar8 + 1;
          lVar7 = lVar7 + 0xd8;
        }
        if (0x23 < uVar8) {
          nvDbg_Printf("inc/kernel/vgpu/rm_plugin_shared_code.h",0x52e,
                       "deserialize_NV2080_CTRL_CMD_NVLINK_GET_NVLINK_STATUS_PARAMS_v2D_01",4,
                       "NVRM: NVRM_RPC: Invalid link index - link: %u, max: %u\n",uVar8,0x24);
          return 0x1f;
        }
        lVar10 = uVar9 * 0x90;
        lVar1 = lVar3 + lVar10;
        *(undefined4 *)(lVar7 + -0x80) = *(undefined4 *)(lVar1 + 0x40);
        *(undefined1 *)(lVar7 + -0x7c) = *(undefined1 *)(lVar1 + 0x44);
        *(undefined1 *)(lVar7 + -0x7b) = *(undefined1 *)(lVar1 + 0x45);
        *(undefined4 *)(lVar7 + -0x78) = *(undefined4 *)(lVar1 + 0x48);
        *(undefined1 *)(lVar7 + -0x74) = *(undefined1 *)(lVar1 + 0x4c);
        *(undefined1 *)(lVar7 + -0x73) = *(undefined1 *)(lVar1 + 0x4d);
        *(undefined1 *)(lVar7 + -0x71) = *(undefined1 *)(lVar1 + 0x4e);
        *(undefined1 *)(lVar7 + -0x70) = *(undefined1 *)(lVar1 + 0x4f);
        *(undefined1 *)(lVar7 + -0x6f) = *(undefined1 *)(lVar1 + 0x50);
        *(undefined4 *)(lVar7 + -0x6c) = *(undefined4 *)(lVar1 + 0x54);
        *(undefined4 *)(lVar7 + -0x5c) = *(undefined4 *)(lVar1 + 0x58);
        *(undefined1 *)(lVar7 + -0x48) = *(undefined1 *)(lVar1 + 0x5c);
        *(undefined1 *)(lVar7 + -0x46) = *(undefined1 *)(lVar1 + 0x5d);
        *(undefined1 *)(lVar7 + -0x45) = *(undefined1 *)(lVar1 + 0x5e);
        *(undefined4 *)(lVar7 + -0x20) = *(undefined4 *)(lVar1 + 0x60);
        *(undefined4 *)(lVar7 + -0x1c) = *(undefined4 *)(lVar1 + 100);
        *(undefined2 *)(lVar7 + -0x18) = *(undefined2 *)(lVar1 + 0x68);
        *(undefined2 *)(lVar7 + -0x16) = *(undefined2 *)(lVar1 + 0x6a);
        *(undefined2 *)(lVar7 + -0x14) = *(undefined2 *)(lVar1 + 0x6c);
        *(undefined4 *)(lVar7 + -0x10) = *(undefined4 *)(lVar1 + 0x70);
        *(undefined8 *)(lVar7 + -8) = *(undefined8 *)(lVar1 + 0x78);
        portMemCopy(lVar7,0x10,lVar3 + 0x80 + lVar10,0x10);
        *(undefined4 *)(lVar7 + 0x10) = *(undefined4 *)(lVar1 + 0x90);
        *(undefined4 *)(lVar7 + 0x18) = *(undefined4 *)(lVar1 + 0x98);
        *(undefined4 *)(lVar7 + 0x1c) = *(undefined4 *)(lVar1 + 0x9c);
        *(undefined2 *)(lVar7 + 0x20) = *(undefined2 *)(lVar1 + 0xa0);
        *(undefined2 *)(lVar7 + 0x22) = *(undefined2 *)(lVar1 + 0xa2);
        *(undefined2 *)(lVar7 + 0x24) = *(undefined2 *)(lVar1 + 0xa4);
        *(undefined4 *)(lVar7 + 0x28) = *(undefined4 *)(lVar1 + 0xa8);
        *(undefined8 *)(lVar7 + 0x30) = *(undefined8 *)(lVar1 + 0xb0);
        portMemCopy(lVar7 + 0x38,0x10,lVar3 + 0xb8 + lVar10,0x10);
        uVar6 = uVar6 >> 1;
        *(undefined4 *)(lVar7 + 0x48) = *(undefined4 *)(lVar3 + 0x38 + (uVar9 * 9 + 9) * 0x10);
        if (uVar6 == 0) break;
        lVar7 = lVar7 + 0xd8;
        uVar9 = (ulong)((int)uVar9 + 1);
        uVar8 = uVar8 + 1;
      }
    }
    local_4c = uVar11;
    if (0x23 < uVar11) {
      return 0;
    }
  }
  return iVar4;
}


// ===== 004ce8c0 rpcCtrlGetP2pCaps_v1F_0D =====

int rpcCtrlGetP2pCaps_v1F_0D
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,long param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0x7d,0xa4);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    iVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != 0) {
      portMemCopy(lVar1 + 0x28,0x80,param_5,0x80);
      *(undefined4 *)(lVar1 + 0xa8) = *(undefined4 *)(param_5 + 0x80);
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 == 0) {
        *(undefined4 *)(param_5 + 0x84) = *(undefined4 *)(lVar1 + 0xac);
        *(undefined4 *)(param_5 + 0x88) = *(undefined4 *)(lVar1 + 0xb0);
        *(undefined4 *)(param_5 + 0x8c) = *(undefined4 *)(lVar1 + 0xb4);
        portMemCopy(param_5 + 0x90,9,lVar1 + 0xb8,9);
      }
    }
  }
  return iVar2;
}


// ===== 004ce9c0 rpcCtrlGetP2pCapsMatrix_v1A_0E =====

int rpcCtrlGetP2pCapsMatrix_v1A_0E
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  
  lVar2 = *(long *)(param_2 + 0x4d8);
  iVar3 = rpcWriteCommonHeader(param_1,param_2,0x7e,0x550);
  if (iVar3 == 0) {
    *(undefined4 *)(lVar2 + 0x20) = param_3;
    *(undefined4 *)(lVar2 + 0x24) = param_4;
    if (((param_5 != (int *)0x0) && (*param_5 - 1U < 8)) && ((uint)param_5[1] < 9)) {
      *(int *)(lVar2 + 0x28) = *param_5;
      *(int *)(lVar2 + 0x2c) = param_5[1];
      lVar4 = 0;
      do {
        *(undefined4 *)(lVar2 + 0x30 + lVar4) = *(undefined4 *)((long)param_5 + lVar4 + 8);
        *(undefined4 *)(lVar2 + 0x50 + lVar4) = *(undefined4 *)((long)param_5 + lVar4 + 0x28);
        lVar4 = lVar4 + 4;
      } while (lVar4 != 0x20);
      iVar3 = _issueRpcAndWait(param_1,param_2);
      if (iVar3 != 0) {
        return iVar3;
      }
      if ((*(int *)(lVar2 + 0x28) - 1U < 8) && (uVar1 = *(uint *)(lVar2 + 0x2c), uVar1 < 9)) {
        uVar6 = 0;
        lVar4 = lVar2;
LAB_004ceac0:
        lVar5 = 0;
        do {
          if (uVar1 == 0) {
            if (uVar6 < (uint)lVar5) goto LAB_004ceb30;
          }
          else if (*(uint *)(lVar2 + 0x2c) <= (uint)lVar5) goto LAB_004ceb30;
          param_5[lVar5 + 0x12] = *(int *)(lVar4 + 0x70 + lVar5 * 4);
          param_5[lVar5 + 0x52] = *(int *)(lVar4 + 0x170 + lVar5 * 4);
          param_5[lVar5 + 0x92] = *(int *)(lVar4 + 0x270 + lVar5 * 4);
          param_5[lVar5 + 0xd2] = *(int *)(lVar4 + 0x370 + lVar5 * 4);
          param_5[lVar5 + 0x112] = *(int *)(lVar4 + 0x470 + lVar5 * 4);
          lVar5 = lVar5 + 1;
        } while( true );
      }
    }
    iVar3 = 0x1f;
  }
  return iVar3;
LAB_004ceb30:
  uVar6 = uVar6 + 1;
  lVar4 = lVar4 + 0x20;
  param_5 = param_5 + 8;
  if (*(uint *)(lVar2 + 0x28) <= uVar6) {
    return 0;
  }
  goto LAB_004ceac0;
}


// ===== 004ceb60 rpcCtrlFbGetInfoV2_v27_00 =====

ulong rpcCtrlFbGetInfoV2_v27_00
                (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,uint *param_5
                )

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar3 = rpcWriteCommonHeader(param_1,param_2,0x8e,0x1d4);
  if ((int)uVar3 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if ((param_5 == (uint *)0x0) || (0x38 < *param_5 - 1)) {
      return 0x1f;
    }
    *(uint *)(lVar1 + 0x28) = *param_5;
    do {
      uVar4 = uVar3 & 0xffffffff;
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulong)uVar2;
      *(uint *)(lVar1 + 0x2c + uVar4 * 8) = param_5[uVar4 * 2 + 1];
      *(uint *)(lVar1 + 0x30 + uVar4 * 8) = param_5[uVar4 * 2 + 2];
    } while (uVar2 < *param_5);
    uVar3 = _issueRpcAndWait(param_1,param_2);
    if ((int)uVar3 == 0) {
      if (0x38 < *(uint *)(lVar1 + 0x28) - 1) {
        return 0x1f;
      }
      *param_5 = *(uint *)(lVar1 + 0x28);
      uVar2 = 0;
      do {
        uVar4 = (ulong)uVar2;
        uVar2 = uVar2 + 1;
        param_5[uVar4 * 2 + 1] = *(uint *)(lVar1 + 0x2c + uVar4 * 8);
        param_5[uVar4 * 2 + 2] = *(uint *)(lVar1 + 0x30 + uVar4 * 8);
      } while (uVar2 < *(uint *)(lVar1 + 0x28));
    }
  }
  return uVar3;
}


// ===== 004cec60 rpcCtrlFbGetInfoV2_v2B_00 =====

ulong rpcCtrlFbGetInfoV2_v2B_00
                (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,uint *param_5
                )

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar3 = rpcWriteCommonHeader(param_1,param_2,0x8e,0x40c);
  if ((int)uVar3 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if ((param_5 == (uint *)0x0) || (0x7f < *param_5 - 1)) {
      return 0x1f;
    }
    *(uint *)(lVar1 + 0x28) = *param_5;
    do {
      uVar4 = uVar3 & 0xffffffff;
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulong)uVar2;
      *(uint *)(lVar1 + 0x2c + uVar4 * 8) = param_5[uVar4 * 2 + 1];
      *(uint *)(lVar1 + 0x30 + uVar4 * 8) = param_5[uVar4 * 2 + 2];
    } while (uVar2 < *param_5);
    uVar3 = _issueRpcAndWait(param_1,param_2);
    if ((int)uVar3 == 0) {
      if (0x7f < *(uint *)(lVar1 + 0x28) - 1) {
        return 0x1f;
      }
      *param_5 = *(uint *)(lVar1 + 0x28);
      uVar2 = 0;
      do {
        uVar4 = (ulong)uVar2;
        uVar2 = uVar2 + 1;
        param_5[uVar4 * 2 + 1] = *(uint *)(lVar1 + 0x2c + uVar4 * 8);
        param_5[uVar4 * 2 + 2] = *(uint *)(lVar1 + 0x30 + uVar4 * 8);
      } while (uVar2 < *(uint *)(lVar1 + 0x28));
    }
  }
  return uVar3;
}


// ===== 004ced60 rpcUpdateGpmGuestBufferInfo_v27_01 =====

void rpcUpdateGpmGuestBufferInfo_v27_01
               (undefined8 param_1,long param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined1 param_7)

{
  int iVar1;
  
  iVar1 = rpcWriteCommonHeader(param_1,param_2,0xd4,0x18);
  if (iVar1 != 0) {
    return;
  }
  *(undefined8 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x28) = param_4;
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x2c) = param_5;
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x30) = param_6;
  *(undefined1 *)(*(long *)(param_2 + 0x4d8) + 0x34) = param_7;
  _issueRpcAndWait(param_1,param_2);
  return;
}


// ===== 004cee10 rpcUpdateGpmGuestBufferInfo_v2B_07 =====

void rpcUpdateGpmGuestBufferInfo_v2B_07
               (undefined8 param_1,long param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined1 param_7)

{
  int iVar1;
  
  iVar1 = rpcWriteCommonHeader(param_1,param_2,0xd4,0x18);
  if (iVar1 != 0) {
    return;
  }
  *(undefined8 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x28) = param_4;
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x2c) = param_5;
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x30) = param_6;
  *(undefined1 *)(*(long *)(param_2 + 0x4d8) + 0x34) = param_7;
  _issueRpcAndWait(param_1,param_2);
  return;
}


// ===== 004ceec0 rpcCtrlGetMmuDebugMode_v1E_06 =====

int rpcCtrlGetMmuDebugMode_v1E_06
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined1 *param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0xae,0xc);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    iVar2 = _issueRpcAndWait(param_1,param_2);
    if (iVar2 == 0) {
      if (param_5 == (undefined1 *)0x0) {
        iVar2 = 0x1f;
      }
      else {
        *param_5 = *(undefined1 *)(lVar1 + 0x28);
      }
    }
    else {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2103,"rpcCtrlGetMmuDebugMode_v1E_06",4,
                   "NVRM: RPC to get MMU debug mode failed with error 0x%x\n");
    }
  }
  return iVar2;
}


// ===== 004cef90 rpcCtrlFifoSetChannelProperties_v1A_16 =====

undefined8
rpcCtrlFifoSetChannelProperties_v1A_16
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x8f,0x18);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    uVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      *(undefined4 *)(lVar1 + 0x2c) = param_5[1];
      *(undefined8 *)(lVar1 + 0x30) = *(undefined8 *)(param_5 + 2);
      uVar2 = _issueRpcAndWait(param_1,param_2);
      if ((int)uVar2 == 0) {
        *param_5 = *(undefined4 *)(lVar1 + 0x28);
        param_5[1] = *(undefined4 *)(lVar1 + 0x2c);
        *(undefined8 *)(param_5 + 2) = *(undefined8 *)(lVar1 + 0x30);
      }
    }
  }
  return uVar2;
}


// ===== 004cf030 rpcCtrlBusSetP2pMapping_v29_08 =====

undefined8
rpcCtrlBusSetP2pMapping_v29_08
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0xc0,0x30);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      *(undefined4 *)(lVar1 + 0x2c) = param_5[1];
      *(undefined1 *)(lVar1 + 0x30) = *(undefined1 *)(param_5 + 2);
      *(uint *)(lVar1 + 0x34) = (uint)*(byte *)((long)param_5 + 9);
      *(undefined1 *)(lVar1 + 0x38) = *(undefined1 *)((long)param_5 + 10);
      *(undefined4 *)(lVar1 + 0x3c) = param_5[3];
      portMemCopy(lVar1 + 0x40,0x10,param_5 + 4,0x10);
      uVar2 = _issueRpcAndWait(param_1,param_2);
      return uVar2;
    }
    uVar2 = 0x1f;
  }
  return uVar2;
}


// ===== 004cf100 rpcCtrlBusSetP2pMapping_v21_03 =====

undefined8
rpcCtrlBusSetP2pMapping_v21_03
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0xc0,0x2c);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      *(undefined4 *)(lVar1 + 0x2c) = param_5[1];
      *(uint *)(lVar1 + 0x30) = (uint)*(byte *)((long)param_5 + 9);
      *(undefined1 *)(lVar1 + 0x34) = *(undefined1 *)((long)param_5 + 10);
      portMemCopy(lVar1 + 0x3c,0x10,param_5 + 4,0x10);
      uVar2 = _issueRpcAndWait(param_1,param_2);
      return uVar2;
    }
    uVar2 = 0x1f;
  }
  return uVar2;
}


// ===== 004cf1c0 rpcCtrlBusUnsetP2pMapping_v21_03 =====

undefined8
rpcCtrlBusUnsetP2pMapping_v21_03
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0xc1,0x28);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      *(undefined4 *)(lVar1 + 0x2c) = param_5[1];
      *(undefined1 *)(lVar1 + 0x30) = *(undefined1 *)(param_5 + 2);
      portMemCopy(lVar1 + 0x38,0x10,param_5 + 4,0x10);
      uVar2 = _issueRpcAndWait(param_1,param_2);
      return uVar2;
    }
    uVar2 = 0x1f;
  }
  return uVar2;
}


// ===== 004cf280 rpcCtrlGpuGetInfoV2_v25_11 =====

undefined8
rpcCtrlGpuGetInfoV2_v25_11
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,uint *param_5)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0xd1,0x214);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if ((param_5 == (uint *)0x0) || (0x41 < *param_5)) {
      return 0x1f;
    }
    *(uint *)(lVar1 + 0x28) = *param_5;
    lVar3 = 0;
    do {
      *(undefined4 *)(lVar1 + 0x2c + lVar3) = *(undefined4 *)((long)param_5 + lVar3 + 4);
      *(undefined4 *)(lVar1 + 0x30 + lVar3) = *(undefined4 *)((long)param_5 + lVar3 + 8);
      lVar3 = lVar3 + 8;
    } while (lVar3 != 0x208);
    uVar2 = _issueRpcAndWait(param_1,param_2);
    if ((int)uVar2 == 0) {
      if (0x41 < *(uint *)(lVar1 + 0x28)) {
        return 0x1f;
      }
      lVar3 = 0;
      do {
        *(undefined4 *)((long)param_5 + lVar3 + 8) = *(undefined4 *)(lVar1 + 0x30 + lVar3);
        lVar3 = lVar3 + 8;
      } while (lVar3 != 0x208);
    }
  }
  return uVar2;
}


// ===== 004cf380 rpcCtrlGpuGetInfoV2_v2A_04 =====

undefined8
rpcCtrlGpuGetInfoV2_v2A_04
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,uint *param_5)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0xd1,0x21c);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if ((param_5 == (uint *)0x0) || (0x42 < *param_5)) {
      return 0x1f;
    }
    *(uint *)(lVar1 + 0x28) = *param_5;
    lVar3 = 0;
    do {
      *(undefined4 *)(lVar1 + 0x2c + lVar3) = *(undefined4 *)((long)param_5 + lVar3 + 4);
      *(undefined4 *)(lVar1 + 0x30 + lVar3) = *(undefined4 *)((long)param_5 + lVar3 + 8);
      lVar3 = lVar3 + 8;
    } while (lVar3 != 0x210);
    uVar2 = _issueRpcAndWait(param_1,param_2);
    if ((int)uVar2 == 0) {
      if (0x42 < *(uint *)(lVar1 + 0x28)) {
        return 0x1f;
      }
      lVar3 = 0;
      do {
        *(undefined4 *)((long)param_5 + lVar3 + 8) = *(undefined4 *)(lVar1 + 0x30 + lVar3);
        lVar3 = lVar3 + 8;
      } while (lVar3 != 0x210);
    }
  }
  return uVar2;
}


// ===== 004cf480 rpcCtrlGpuGetInfoV2_v2B_03 =====

undefined8
rpcCtrlGpuGetInfoV2_v2B_03
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,uint *param_5)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0xd1,0x224);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if ((param_5 == (uint *)0x0) || (0x43 < *param_5)) {
      return 0x1f;
    }
    *(uint *)(lVar1 + 0x28) = *param_5;
    lVar3 = 0;
    do {
      *(undefined4 *)(lVar1 + 0x2c + lVar3) = *(undefined4 *)((long)param_5 + lVar3 + 4);
      *(undefined4 *)(lVar1 + 0x30 + lVar3) = *(undefined4 *)((long)param_5 + lVar3 + 8);
      lVar3 = lVar3 + 8;
    } while (lVar3 != 0x218);
    uVar2 = _issueRpcAndWait(param_1,param_2);
    if ((int)uVar2 == 0) {
      if (0x43 < *(uint *)(lVar1 + 0x28)) {
        return 0x1f;
      }
      lVar3 = 0;
      do {
        *(undefined4 *)((long)param_5 + lVar3 + 8) = *(undefined4 *)(lVar1 + 0x30 + lVar3);
        lVar3 = lVar3 + 8;
      } while (lVar3 != 0x218);
    }
  }
  return uVar2;
}


// ===== 004cf580 rpcCtrlGpuGetInfoV2_v2B_05 =====

undefined8
rpcCtrlGpuGetInfoV2_v2B_05
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,uint *param_5)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0xd1,0x22c);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if ((param_5 == (uint *)0x0) || (0x44 < *param_5)) {
      return 0x1f;
    }
    *(uint *)(lVar1 + 0x28) = *param_5;
    lVar3 = 0;
    do {
      *(undefined4 *)(lVar1 + 0x2c + lVar3) = *(undefined4 *)((long)param_5 + lVar3 + 4);
      *(undefined4 *)(lVar1 + 0x30 + lVar3) = *(undefined4 *)((long)param_5 + lVar3 + 8);
      lVar3 = lVar3 + 8;
    } while (lVar3 != 0x220);
    uVar2 = _issueRpcAndWait(param_1,param_2);
    if ((int)uVar2 == 0) {
      if (0x44 < *(uint *)(lVar1 + 0x28)) {
        return 0x1f;
      }
      lVar3 = 0;
      do {
        *(undefined4 *)((long)param_5 + lVar3 + 8) = *(undefined4 *)(lVar1 + 0x30 + lVar3);
        lVar3 = lVar3 + 8;
      } while (lVar3 != 0x220);
    }
  }
  return uVar2;
}


// ===== 004cf680 rpcCtrlGpuGetInfoV2_v2B_0C =====

undefined8
rpcCtrlGpuGetInfoV2_v2B_0C
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,uint *param_5)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0xd1,0x234);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if ((param_5 == (uint *)0x0) || (0x45 < *param_5)) {
      return 0x1f;
    }
    *(uint *)(lVar1 + 0x28) = *param_5;
    lVar3 = 0;
    do {
      *(undefined4 *)(lVar1 + 0x2c + lVar3) = *(undefined4 *)((long)param_5 + lVar3 + 4);
      *(undefined4 *)(lVar1 + 0x30 + lVar3) = *(undefined4 *)((long)param_5 + lVar3 + 8);
      lVar3 = lVar3 + 8;
    } while (lVar3 != 0x228);
    uVar2 = _issueRpcAndWait(param_1,param_2);
    if ((int)uVar2 == 0) {
      if (0x45 < *(uint *)(lVar1 + 0x28)) {
        return 0x1f;
      }
      lVar3 = 0;
      do {
        *(undefined4 *)((long)param_5 + lVar3 + 8) = *(undefined4 *)(lVar1 + 0x30 + lVar3);
        lVar3 = lVar3 + 8;
      } while (lVar3 != 0x228);
    }
  }
  return uVar2;
}


// ===== 004cf780 rpcCtrlGpuGetInfoV2_v2B_13 =====

undefined8
rpcCtrlGpuGetInfoV2_v2B_13
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,uint *param_5)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0xd1,0x23c);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if ((param_5 == (uint *)0x0) || (0x46 < *param_5)) {
      return 0x1f;
    }
    *(uint *)(lVar1 + 0x28) = *param_5;
    lVar3 = 0;
    do {
      *(undefined4 *)(lVar1 + 0x2c + lVar3) = *(undefined4 *)((long)param_5 + lVar3 + 4);
      *(undefined4 *)(lVar1 + 0x30 + lVar3) = *(undefined4 *)((long)param_5 + lVar3 + 8);
      lVar3 = lVar3 + 8;
    } while (lVar3 != 0x230);
    uVar2 = _issueRpcAndWait(param_1,param_2);
    if ((int)uVar2 == 0) {
      if (0x46 < *(uint *)(lVar1 + 0x28)) {
        return 0x1f;
      }
      lVar3 = 0;
      do {
        *(undefined4 *)((long)param_5 + lVar3 + 8) = *(undefined4 *)(lVar1 + 0x30 + lVar3);
        lVar3 = lVar3 + 8;
      } while (lVar3 != 0x230);
    }
  }
  return uVar2;
}


// ===== 004cf880 rpcCtrlGpuMigratableOps_v21_07 =====

undefined8
rpcCtrlGpuMigratableOps_v21_07
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  undefined1 *puVar3;
  uint uVar4;
  long lVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0xc3,0x730);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if ((param_5 == (undefined4 *)0x0) || (0x32 < (uint)param_5[3])) {
      return 0x1f;
    }
    *(undefined4 *)(lVar1 + 0x30) = param_5[2];
    *(undefined4 *)(lVar1 + 0x34) = param_5[3];
    *(undefined4 *)(lVar1 + 0x28) = *param_5;
    *(undefined4 *)(lVar1 + 0x2c) = param_5[1];
    if (param_5[3] != 0) {
      lVar5 = 0;
      puVar3 = (undefined1 *)(lVar1 + 0x100);
      puVar6 = param_5 + 0x36;
      do {
        *puVar3 = *(undefined1 *)puVar6;
        puVar3[1] = *(undefined1 *)((long)puVar6 + 1);
        puVar3[3] = *(undefined1 *)((long)puVar6 + 3);
        *(undefined4 *)(puVar3 + 4) = puVar6[1];
        *(undefined4 *)(puVar3 + 8) = puVar6[2];
        *(undefined4 *)(puVar3 + 0xc) = puVar6[3];
        *(undefined4 *)(puVar3 + 0x1c) = puVar6[7];
        *(undefined4 *)(puVar3 + 0x18) = puVar6[6];
        *(undefined4 *)(puVar3 + 0x14) = puVar6[5];
        *(undefined4 *)(puVar3 + 0x10) = puVar6[4];
        *(undefined4 *)(lVar1 + 0x38 + lVar5 * 4) = param_5[lVar5 + 4];
        lVar5 = lVar5 + 1;
        puVar3 = puVar3 + 0x20;
        puVar6 = puVar6 + 8;
      } while ((uint)lVar5 < (uint)param_5[3]);
    }
    uVar2 = _issueRpcAndWait(param_1,param_2);
    if (((int)uVar2 == 0) && (*(int *)(lVar1 + 0x34) != 0)) {
      uVar4 = 0;
      puVar3 = (undefined1 *)(lVar1 + 0x102);
      puVar7 = (undefined1 *)((long)param_5 + 0xda);
      do {
        uVar4 = uVar4 + 1;
        *puVar7 = *puVar3;
        *(undefined4 *)(puVar7 + 0x12) = *(undefined4 *)(puVar3 + 0x12);
        *(undefined4 *)(puVar7 + 0xe) = *(undefined4 *)(puVar3 + 0xe);
        puVar3 = puVar3 + 0x20;
        puVar7 = puVar7 + 0x20;
      } while (uVar4 < *(uint *)(lVar1 + 0x34));
      return uVar2;
    }
  }
  return uVar2;
}


// ===== 004cfa10 rpcCtrlGpuQueryEccStatus_v24_06 =====

undefined8 rpcCtrlGpuQueryEccStatus_v24_06(void)

{
  return 0x56;
}


// ===== 004cfa20 rpcCtrlGpuQueryEccStatus_v26_02 =====

undefined8 rpcCtrlGpuQueryEccStatus_v26_02(void)

{
  return 0x56;
}


// ===== 004cfa30 rpcCtrlDbgGetModeMmuDebug_v25_04 =====

undefined8
rpcCtrlDbgGetModeMmuDebug_v25_04
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0xcb,0xc);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    uVar2 = 0x1f;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      uVar2 = _issueRpcAndWait(param_1,param_2);
      if ((int)uVar2 == 0) {
        *param_5 = *(undefined4 *)(lVar1 + 0x28);
      }
    }
  }
  return uVar2;
}


// ===== 004cfac0 rpcCtrlDbgGetModeMmuGccDebug_v2A_05 =====

undefined8
rpcCtrlDbgGetModeMmuGccDebug_v2A_05
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0xda,0xc);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    uVar2 = 0x1f;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x28) = *param_5;
      uVar2 = _issueRpcAndWait(param_1,param_2);
      if ((int)uVar2 == 0) {
        *param_5 = *(undefined4 *)(lVar1 + 0x28);
      }
    }
  }
  return uVar2;
}


// ===== 004cfb50 RmRpcSetGuestSystemInfo =====

/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */
/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int RmRpcSetGuestSystemInfo(long param_1,long param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  uint uVar4;
  
  iVar2 = *(int *)(*(long *)(g_pSys + 0x1e0) + 0x3f158);
  if (iVar2 == 0) {
    _rpcVgxVersion = 0;
LAB_004cfb88:
    iVar2 = *(int *)(param_2 + 0x4f0);
  }
  else {
    if (((iVar2 == 1) || (*(char *)(param_1 + 0x909) != '\0')) ||
       ((*(char *)(param_1 + 0x908) != '\0' && (*(char *)(param_1 + 0x4a4e) != '\0'))))
    goto LAB_004cfb88;
    if (rpcVgxVersion == 0) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x22b0,"RmRpcSetGuestSystemInfo",4,
                   "NVRM: NVRM_RPC: RPC version handshake already failed. Bailing out for device instance 0x%x\n"
                   ,*(undefined4 *)(param_1 + 0x7a4));
      return 0xffff;
    }
    if ((*(char *)(param_1 + 0x444) == '\0') || (bSkipRpcVersionHandshake != '\0')) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x22a7,"RmRpcSetGuestSystemInfo",1,
                   "NVRM: NVRM_RPC: Skipping RPC version handshake for instance 0x%x\n",
                   *(undefined4 *)(param_1 + 0x7a4));
      iVar2 = rpcVgxVersion;
      uVar4 = DAT_0056eae4;
      goto LAB_004cfeb2;
    }
    bSkipRpcVersionHandshake = '\x01';
    iVar2 = *(int *)(param_2 + 0x4f0);
  }
  if (iVar2 + -0x338 < 0) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x22bd,"RmRpcSetGuestSystemInfo",4,
                 "NVRM: NVRM_RPC: SetGuestSystemInfo: Insufficient space on message buffer\n");
    return 2;
  }
  iVar2 = rpcWriteCommonHeader(param_1,param_2,1,0x318);
  if (iVar2 != 0) {
    return iVar2;
  }
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x28) = 0x100;
  portStringCopy(*(long *)(param_2 + 0x4d8) + 0x38,0x100,"595.71.05",0x100);
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x2c) = 0x100;
  portStringCopy(*(long *)(param_2 + 0x4d8) + 0x138,0x100,"rel/gpu_drv/r595/r596_25-250",0x100);
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x30) = 0x100;
  portStringCopy(*(long *)(param_2 + 0x4d8) + 0x238,0x100,
                 "Private r596_25 rel/gpu_drv/r595/r596_25-250 unknown",0x100);
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x34) = 0;
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = 0x2d;
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = 3;
  iVar2 = _issueRpcAndWait(param_1,param_2);
  if (iVar2 != 0) {
    return iVar2;
  }
  lVar3 = *(long *)(param_2 + 0x4d8);
  iVar2 = *(int *)(lVar3 + 0x14);
  if (iVar2 != 0) {
    iVar1 = *(int *)(lVar3 + 0x20);
    uVar4 = *(uint *)(lVar3 + 0x24);
    if (iVar1 == 0x2d) {
      if (uVar4 == 3) {
        return iVar2;
      }
    }
    else if (((uVar4 & 0xff) << 0x10 | iVar1 << 0x18) < 0x250e0000) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x230c,"RmRpcSetGuestSystemInfo",4,
                   "NVRM: NVRM_RPC: SetGuestSystemInfo: The host version (%d.%d) is too old.\nNVRM_RPC: SetGuestSystemInfo: Minimum required host version is %d.%d.\n"
                   ,iVar1,uVar4,0x25,0xe);
      lVar3 = gpuGetRpc(param_1);
      if (lVar3 != 0) {
        (**(code **)(lVar3 + 0x458))
                  (param_1,lVar3,"######## Guest NVIDIA Driver Information: ########",2,
                   *(code **)(lVar3 + 0x458));
      }
      lVar3 = gpuGetRpc(param_1);
      if (lVar3 != 0) {
        (**(code **)(lVar3 + 0x458))
                  (param_1,lVar3,"Driver Version: 595.71.05",2,*(code **)(lVar3 + 0x458));
      }
      lVar3 = gpuGetRpc(param_1);
      if (lVar3 != 0) {
        (**(code **)(lVar3 + 0x458))
                  (param_1,lVar3,
                   "Incompatible Guest/Host drivers: Host VGX version is older than the minimum version supported by the Guest. Disabling vGPU."
                   ,1,*(code **)(lVar3 + 0x458));
        return iVar2;
      }
      return iVar2;
    }
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2300,"RmRpcSetGuestSystemInfo",3,
                 "NVRM: NVRM_RPC: SetGuestSystemInfo: Guest VGX version (%d.%d) is newer than the host VGX version (%d.%d)\nNVRM_RPC: SetGuestSystemInfo: Retrying with the VGX version requested by the host.\n"
                 ,0x2d,3,iVar1,uVar4);
    iVar2 = _issueRpcAndWait(param_1,param_2);
    if (iVar2 != 0) {
      return iVar2;
    }
    lVar3 = *(long *)(param_2 + 0x4d8);
  }
  iVar2 = *(int *)(lVar3 + 0x20);
  if (rpcVgxVersion == 0) {
    uVar4 = *(uint *)(lVar3 + 0x24);
  }
  else {
    if (rpcVgxVersion != iVar2) {
      return 0x40;
    }
    uVar4 = *(uint *)(lVar3 + 0x24);
    if (DAT_0056eae4 != uVar4) {
      return 0x40;
    }
  }
  _rpcVgxVersion = CONCAT44(uVar4,iVar2);
LAB_004cfeb2:
  rpcSetIpVersion(param_1,param_2,(uVar4 & 0xff) << 0x10 | iVar2 << 0x18);
  lVar3 = gpuGetVgpuRpc(param_1);
  iVar2 = 0;
  if ((lVar3 != 0) &&
     (iVar2 = (**(code **)(lVar3 + 0x4c0))(param_1,lVar3,*(code **)(lVar3 + 0x4c0)), iVar2 != 0)) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2336,"RmRpcSetGuestSystemInfo",4,
                 "NVRM: SET_GUEST_SYSTEM_INFO_EXT : failed.\n");
  }
  return iVar2;
}


// ===== 004d0020 vgpuReinitializeRpcInfraOnStateLoad =====

int vgpuReinitializeRpcInfraOnStateLoad(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8);
  if (*(char *)(param_1 + 0x4a4e) == '\0') {
    if (*(char *)(param_1 + 0x4913) == '\0') {
      nvAssertFailedNoLog("IS_VIRTUAL_WITH_SRIOV(pGpu)","src/kernel/vgpu/rpc.c",0x410);
      iVar1 = 0x56;
    }
    else if (*(long *)(lVar2 + 8) == 0) {
      nvAssertFailedNoLog("(pVGpu->eventRing.mem.pMemory != NULL)","src/kernel/vgpu/rpc.c",0x411);
      iVar1 = 0x40;
    }
    else {
      portMemSet(*(long *)(lVar2 + 8),0,0x1000);
      lVar2 = gpuGetRpc(param_1);
      if (lVar2 == 0) {
        nvAssertFailedNoLog("pRpc != NULL","src/kernel/vgpu/rpc.c",0x415);
        iVar1 = 0x1a;
      }
      else {
        iVar1 = RmRpcSetGuestSystemInfo(param_1,lVar2);
        if (iVar1 == 0) {
          return 0;
        }
      }
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x418,"vgpuReinitializeRpcInfraOnStateLoad",4,
                   "NVRM: RPC: Failed to set GUEST_SYSTEM_INFO on resume from hibernate:0x%x\n");
      bSkipRpcVersionHandshake = 0;
    }
  }
  else {
    *(undefined1 *)(lVar2 + 0x26154) = 1;
    iVar1 = vgpuGspSetupBuffers();
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x3ff,"vgpuReinitializeRpcInfraOnStateLoad",4,
                   "NVRM: RPC buffers setup failed: 0x%x\n",iVar1);
      return iVar1;
    }
    *(undefined1 *)(lVar2 + 0x26154) = 0;
    lVar2 = gpuGetRpc(param_1);
    if (lVar2 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/vgpu/rpc.c",0x404);
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x407,"vgpuReinitializeRpcInfraOnStateLoad",4,
                   "NVRM: NVRM_RPC: SET_GUEST_SYSTEM_INFO : failed.\n");
      iVar1 = 0x1a;
    }
    else {
      iVar1 = RmRpcSetGuestSystemInfo(param_1,lVar2);
      if ((iVar1 != 0) &&
         (nvDbg_Printf("src/kernel/vgpu/rpc.c",0x407,"vgpuReinitializeRpcInfraOnStateLoad",4,
                       "NVRM: NVRM_RPC: SET_GUEST_SYSTEM_INFO : failed.\n"), iVar1 == 0x56)) {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x40a,"vgpuReinitializeRpcInfraOnStateLoad",4,
                     "NVRM: vGPU type is not supported");
      }
    }
  }
  return iVar1;
}


// ===== 004d0290 initRpcInfrastructure_VGPU =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int initRpcInfrastructure_VGPU(long param_1)

{
  long lVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  undefined8 uVar6;
  ulong local_30;
  
  lVar1 = *(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8);
  portMemSet(lVar1,0,0x26190);
  *(undefined1 *)(lVar1 + 0x150) = *(undefined1 *)(param_1 + 0x4a4e);
  lVar5 = initRpcObject(param_1);
  *(long *)(lVar1 + 0x26158) = lVar5;
  if (lVar5 == 0) {
    iVar3 = 0x3d;
    if (*(char *)(lVar1 + 0x150) == '\0') goto LAB_004d0420;
LAB_004d063e:
    vgpuGspTeardownBuffers(param_1);
  }
  else {
    if (*(char *)(lVar1 + 0x150) == '\0') {
      iVar3 = 0x56;
LAB_004d03b6:
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x69b,"initRpcInfrastructure_VGPU",4,
                   "NVRM: RPC buffers setup failed: 0x%x\n",iVar3);
    }
    else {
      iVar3 = vgpuGspSetupBuffers(param_1);
      if (iVar3 != 0) goto LAB_004d03b6;
      if ((*(char *)(param_1 + 0x908) == '\0') && (*(char *)(param_1 + 0x909) == '\0')) {
LAB_004d0470:
        local_30 = 0;
        if (*(char *)(param_1 + 0x472) == '\0') goto LAB_004d05f1;
        if (DAT_0054eab8 == 0) {
          listInitIntrusive_IMPL(&DAT_0054eac0,0x38);
        }
        listInitIntrusive_IMPL(lVar1 + 0x26168,0x20);
        iVar3 = listCount_IMPL(&DAT_0054eac0);
        if (iVar3 == 0) {
          lVar5 = *(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8);
          iVar3 = _allocRpcMemDesc(param_1,0x1000,1,1,0,&DAT_0054eab8,&DAT_0054eaa0,&DAT_0054eaa8);
          if (iVar3 == 0) {
            _DAT_0054eab0 = memdescGetPte(DAT_0054eab8,1,0);
            _DAT_0054eab0 = _DAT_0054eab0 >> 0xc;
            if (*(char *)(lVar5 + 0x150) != '\0') {
              lVar5 = *(long *)(lVar5 + 0x120);
              uVar6 = vgpuGspSysmemPfnMakeBufferAddress(DAT_0054eab8,_DAT_0054eab0);
              *(undefined8 *)(lVar5 + 0x50) = uVar6;
            }
            uVar4 = listCount_IMPL(&DAT_0054eac0);
            iVar3 = vgpuAllocSysmemPfnBitMapNode(param_1,&local_30,uVar4);
            if (iVar3 == 0) {
              listAppendExisting_IMPL(&DAT_0054eac0,local_30);
              vgpuSysmemPfnInfo = *(ulong *)(local_30 + 0x20);
              _DAT_0054ea88 = vgpuSysmemPfnInfo >> 3;
              DAT_0054ea90 = portMemAllocNonPaged(_DAT_0054ea88 << 4);
              if (DAT_0054ea90 != 0) {
                portMemSet(DAT_0054ea90,0,vgpuSysmemPfnInfo * 2);
                goto LAB_004d05ad;
              }
              iVar3 = 0x1a;
              nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2eb,"_setupSysmemPfnBitMap",4,
                           "NVRM: failed to allocate sysmem pfn refcount array\n");
              nvAssertFailedNoLog(&DAT_00d98b20,"src/kernel/vgpu/rpc.c",0x2ec);
              listRemoveIntrusive_IMPL(&DAT_0054eac0,local_30);
            }
            else {
              nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2dd,"_setupSysmemPfnBitMap",4,
                           "NVRM: NVRM_RPC: Failed to alloc sysmem pfn bitmap node\n");
            }
          }
          else {
            nvDbg_Printf("src/kernel/vgpu/rpc.c",0x298,"_initSysmemPfnRing",4,
                         "NVRM: RPC: PFN ring setup failed: 0x%x\n",iVar3);
            nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2cb,"_setupSysmemPfnBitMap",4,
                         "NVRM: NVRM_RPC: Failed to init sysmem pfn ring\n");
          }
          if (local_30 != 0) {
            vgpuFreeSysmemPfnBitMapNode();
          }
          portMemFree(DAT_0054ea90);
          vgpuSysmemPfnInfo = 0;
          _DAT_0054ea88 = 0;
          nvDbg_Printf("src/kernel/vgpu/rpc.c",0x6c4,"initRpcInfrastructure_VGPU",4,
                       "NVRM: RPC: Sysmem PFN bitmap setup failed: 0x%x\n",iVar3);
        }
        else {
LAB_004d05ad:
          iVar3 = listCount_IMPL(&DAT_0054eac0);
          if (iVar3 != 0) {
            local_30 = listHead_IMPL(&DAT_0054eac0);
            memdescAddRef(*(undefined8 *)(local_30 + 0x10));
          }
          DAT_0054ea98 = 1;
          if ((*(char *)(param_1 + 0x472) == '\0') ||
             (iVar3 = updateSharedBufferInfoInSysmemPfnBitMap_part_0(param_1,lVar1,1,1), iVar3 == 0)
             ) {
LAB_004d05f1:
            *(bool *)(lVar1 + 0x1ac) = *(int *)(*(long *)(lVar1 + 0x118) + 0xa4) != 0;
            iVar3 = *(int *)(*(long *)(lVar1 + 0x118) + 0xa0);
            *(undefined1 *)(lVar1 + 0x26152) = 1;
            *(bool *)(lVar1 + 0x1ad) = iVar3 != 0;
            return 0;
          }
          nvDbg_Printf("src/kernel/vgpu/rpc.c",0x6cd,"initRpcInfrastructure_VGPU",4,
                       "NVRM: RPC: Sysmem PFN bitmap update failed for shared buffer sysmem pages failed: 0x%x\n"
                       ,iVar3);
        }
      }
      else {
        local_30 = local_30 & 0xffffffff00000000;
        cVar2 = rmGpuGroupLockIsOwner(*(undefined4 *)(param_1 + 0x7a4),0,&local_30);
        if (cVar2 == '\0') {
          iVar3 = rmGpuGroupLockAcquire(*(undefined4 *)(param_1 + 0x7a4),0,0,0x8002,&local_30);
          if (iVar3 != 0) {
            nvAssertOkFailedNoLog
                      (iVar3,
                       "rmGpuGroupLockAcquire(pGpu->gpuInstance, GPU_LOCK_GRP_SUBDEVICE, GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_RPC, &gpuMaskRelease)"
                       ,"src/kernel/vgpu/rpc.c",0x6a7);
            return iVar3;
          }
          lVar5 = gpuGetRpc(param_1);
          if (lVar5 != 0) {
            iVar3 = RmRpcSetGuestSystemInfo(param_1,lVar5);
            if ((int)local_30 != 0) {
              rmGpuGroupLockRelease(local_30 & 0xffffffff,0);
            }
            goto LAB_004d0467;
          }
          nvAssertFailedNoLog("pRpc != NULL","src/kernel/vgpu/rpc.c",0x6af);
          if ((int)local_30 != 0) {
            rmGpuGroupLockRelease(local_30 & 0xffffffff,0);
          }
LAB_004d0898:
          iVar3 = 0x1a;
          nvDbg_Printf("src/kernel/vgpu/rpc.c",0x6b8,"initRpcInfrastructure_VGPU",4,
                       "NVRM: NVRM_RPC: SET_GUEST_SYSTEM_INFO : failed.\n");
        }
        else {
          lVar5 = gpuGetRpc(param_1);
          if (lVar5 == 0) {
            nvAssertFailedNoLog("pRpc != NULL","src/kernel/vgpu/rpc.c",0x6af);
            goto LAB_004d0898;
          }
          iVar3 = RmRpcSetGuestSystemInfo(param_1,lVar5);
LAB_004d0467:
          if (iVar3 == 0) goto LAB_004d0470;
          nvDbg_Printf("src/kernel/vgpu/rpc.c",0x6b8,"initRpcInfrastructure_VGPU",4,
                       "NVRM: NVRM_RPC: SET_GUEST_SYSTEM_INFO : failed.\n");
          if (iVar3 == 0x56) {
            nvErrorLog_va(param_1,0x4e,"vGPU type is not supported");
          }
        }
      }
    }
    if (*(char *)(lVar1 + 0x150) != '\0') goto LAB_004d063e;
  }
  if (*(long *)(lVar1 + 0x26158) != 0) {
    (**(code **)(*(long *)(lVar1 + 0x26158) + 0x10))(param_1);
    portMemFree(*(undefined8 *)(lVar1 + 0x26158));
    *(undefined8 *)(lVar1 + 0x26158) = 0;
  }
LAB_004d0420:
  if (*(char *)(param_1 + 0x472) != '\0') {
    teardownSysmemPfnBitMap_part_0(param_1);
  }
  return iVar3;
}


// ===== 004d0950 rpcSetGuestSystemInfoExt_v15_02 =====

void rpcSetGuestSystemInfoExt_v15_02(long param_1,long param_2)

{
  int iVar1;
  
  iVar1 = rpcWriteCommonHeader(param_1,param_2,0x40,0x108);
  if (iVar1 != 0) {
    return;
  }
  portStringCopy(*(long *)(param_2 + 0x4d8) + 0x20,0x100,"r596_25",8);
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x120) = *(undefined4 *)(param_1 + 0x87c);
  *(ushort *)(*(long *)(param_2 + 0x4d8) + 0x124) = (ushort)*(byte *)(param_1 + 0x879);
  *(ushort *)(*(long *)(param_2 + 0x4d8) + 0x126) = (ushort)*(byte *)(param_1 + 0x878);
  _issueRpcAndWait(param_1,param_2);
  return;
}


// ===== 004d0a00 rpcSetGuestSystemInfoExt_v25_1B =====

void rpcSetGuestSystemInfoExt_v25_1B(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0x40,0x10c);
  if (iVar2 != 0) {
    return;
  }
  portStringCopy(*(long *)(param_2 + 0x4d8) + 0x20,0x100,"r596_25",8);
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x120) = *(undefined4 *)(param_1 + 0x87c);
  *(ushort *)(*(long *)(param_2 + 0x4d8) + 0x124) = (ushort)*(byte *)(param_1 + 0x879);
  *(ushort *)(*(long *)(param_2 + 0x4d8) + 0x126) = (ushort)*(byte *)(param_1 + 0x878);
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar3 = osGetGridCspSupport();
  *(undefined4 *)(lVar1 + 0x128) = uVar3;
  _issueRpcAndWait(param_1,param_2);
  return;
}


// ===== 004d0ad0 RmRpcPerfGetCurrentPstate =====

undefined8 RmRpcPerfGetCurrentPstate(long param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)
              (*(long *)(*(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8) + 0x118) +
              0x90);
  return 0;
}


// ===== 004d0b00 rpcPerfGetLevelInfo_v03_00 =====

int rpcPerfGetLevelInfo_v03_00
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined4 *param_5,long param_6)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  uint uVar6;
  
  uVar6 = param_5[4] * 0x18;
  uVar2 = *(int *)(param_2 + 0x4f0) - 0x38;
  if (uVar2 < uVar6) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2397,"rpcPerfGetLevelInfo_v03_00",4,
                 "NVRM: NVRM_RPC: PerfGetLevelInfo : requested %u bytes (but only room for %u)\n",
                 uVar6,uVar2);
    return 0xffff;
  }
  iVar3 = rpcWriteCommonHeader(param_1,param_2,0x2a,0x18);
  if (iVar3 == 0) {
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x28) = *param_5;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x2c) = param_5[1];
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x30) = param_5[4];
    *(uint *)(*(long *)(param_2 + 0x4d8) + 0x34) = uVar6;
    if (param_6 == 0) {
      iVar3 = _issueRpcAndWait(param_1,param_2);
      if (iVar3 == 0) {
        param_5[1] = *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x2c);
      }
    }
    else {
      if ((ulong)(uint)param_5[4] * 3 != 0) {
        lVar1 = *(long *)(param_2 + 0x4d8);
        lVar5 = 0;
        do {
          iVar4 = (int)lVar5;
          *(undefined4 *)(lVar1 + 0x38 + lVar5) = *(undefined4 *)(param_6 + lVar5);
          lVar5 = lVar5 + 4;
        } while ((ulong)(iVar4 + 4) < (ulong)(uint)param_5[4] * 0x18);
      }
      iVar4 = _issueRpcAndWait(param_1,param_2);
      if (iVar4 != 0) {
        return iVar4;
      }
      param_5[1] = *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x2c);
      lVar1 = *(long *)(param_2 + 0x4d8);
      if ((ulong)(uint)param_5[4] * 3 != 0) {
        lVar5 = 0;
        do {
          iVar4 = (int)lVar5;
          *(undefined4 *)(param_6 + lVar5) = *(undefined4 *)(lVar1 + 0x38 + lVar5);
          lVar5 = lVar5 + 4;
        } while ((ulong)(iVar4 + 4) < (ulong)(uint)param_5[4] * 0x18);
      }
    }
  }
  return iVar3;
}


// ===== 004d0d40 rpcPerfGetLevelInfo_v2B_0D =====

undefined8
rpcPerfGetLevelInfo_v2B_0D
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5
          ,undefined8 *param_6)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  long lVar7;
  uint uVar8;
  undefined8 *puVar9;
  undefined1 local_348 [4];
  undefined4 local_344;
  undefined8 local_340;
  
  memset(local_348,0,0x30c);
  if (0x20 < (uint)param_5[4]) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x23d6,"rpcPerfGetLevelInfo_v2B_0D",4,
                 "NVRM: NVRM_RPC: PerfGetLevelInfo : List Size Exceeded for perfGetClkInfoList, currentSize:  %u (maxAllowedSize: %u)\n"
                 ,param_5[4],0x20);
    return 0x5b;
  }
  lVar2 = *(long *)(param_2 + 0x4d8);
  uVar4 = rpcWriteCommonHeader(param_1,param_2,0x2a,0x314);
  if ((int)uVar4 != 0) {
    return uVar4;
  }
  *(undefined4 *)(lVar2 + 0x20) = param_3;
  *(undefined4 *)(lVar2 + 0x24) = param_4;
  local_344 = param_5[1];
  uVar1 = *param_5;
  uVar8 = param_5[4];
  if (param_6 == (undefined8 *)0x0) {
    if (0x20 < uVar8) {
      return 0x1f;
    }
    *(undefined4 *)(lVar2 + 0x28) = uVar1;
    *(uint *)(lVar2 + 0x30) = uVar8;
    if (uVar8 == 0) goto LAB_004d0e9a;
  }
  else {
    if (uVar8 == 0) {
      *(undefined4 *)(lVar2 + 0x28) = uVar1;
      *(undefined4 *)(lVar2 + 0x30) = 0;
      goto LAB_004d0e9a;
    }
    puVar5 = param_6;
    puVar9 = &local_340;
    do {
      puVar6 = puVar5 + 3;
      uVar4 = puVar5[2];
      uVar3 = *puVar5;
      puVar9[1] = puVar5[1];
      puVar9[2] = uVar4;
      *puVar9 = uVar3;
      puVar5 = puVar6;
      puVar9 = puVar9 + 3;
    } while (puVar6 != param_6 + (ulong)uVar8 * 3);
    if (0x20 < uVar8) {
      return 0x1f;
    }
    *(undefined4 *)(lVar2 + 0x28) = uVar1;
    *(uint *)(lVar2 + 0x30) = uVar8;
  }
  lVar7 = 0;
  do {
    uVar1 = *(undefined4 *)((long)&local_340 + lVar7);
    *(undefined4 *)(lVar2 + 0x38 + lVar7) = *(undefined4 *)((long)&local_340 + lVar7 + 4);
    *(undefined4 *)(lVar2 + 0x34 + lVar7) = uVar1;
    lVar7 = lVar7 + 0x18;
  } while (lVar7 != (ulong)uVar8 * 0x18);
LAB_004d0e9a:
  uVar4 = _issueRpcAndWait(param_1,param_2);
  if ((int)uVar4 != 0) {
    return uVar4;
  }
  uVar4 = deserialize_NV2080_CTRL_PERF_GET_LEVEL_INFO_V2_PARAMS_v2B_0D(local_348,lVar2 + 0x28,0);
  if ((int)uVar4 != 0) {
    return 0x1f;
  }
  param_5[1] = local_344;
  if (param_6 == (undefined8 *)0x0) {
    return uVar4;
  }
  if (param_5[4] != 0) {
    uVar8 = 0;
    puVar5 = &local_340;
    do {
      uVar8 = uVar8 + 1;
      *(undefined4 *)param_6 = *(undefined4 *)puVar5;
      *(undefined4 *)((long)param_6 + 4) = *(undefined4 *)((long)puVar5 + 4);
      *(undefined4 *)(param_6 + 1) = *(undefined4 *)(puVar5 + 1);
      *(undefined4 *)((long)param_6 + 0xc) = *(undefined4 *)((long)puVar5 + 0xc);
      *(undefined4 *)(param_6 + 2) = *(undefined4 *)(puVar5 + 2);
      *(undefined4 *)((long)param_6 + 0x14) = *(undefined4 *)((long)puVar5 + 0x14);
      puVar5 = puVar5 + 3;
      param_6 = param_6 + 3;
    } while (uVar8 < (uint)param_5[4]);
    return uVar4;
  }
  return uVar4;
}


// ===== 004d0fe0 rpcSetSurfaceProperties_v07_07 =====

undefined8
rpcSetSurfaceProperties_v07_07
          (long param_1,long param_2,undefined4 param_3,undefined4 *param_4,char param_5)

{
  long lVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  lVar2 = *(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8);
  if (lVar2 == 0) {
    if (param_4[1] == 0) {
      return 0;
    }
  }
  else {
    if (*(char *)(lVar2 + 0x1ac) == '\0') {
      return 0;
    }
    if (param_4[1] == 0) {
      return 0;
    }
    if (*(char *)(lVar2 + 0x1ad) == '\0') goto LAB_004d1130;
    if ((param_5 == '\0') && (iVar3 = portMemCmp(param_4,lVar2 + 0x15c,0x4c), iVar3 == 0)) {
      return 0;
    }
  }
  uVar4 = rpcWriteCommonHeader(param_1,param_2,0x2d,0x4c);
  if ((int)uVar4 != 0) {
    return uVar4;
  }
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
  *(undefined4 *)(lVar1 + 0x24) = *param_4;
  *(undefined4 *)(lVar1 + 0x28) = param_4[1];
  *(undefined4 *)(lVar1 + 0x2c) = param_4[3];
  *(undefined4 *)(lVar1 + 0x30) = param_4[4];
  *(undefined4 *)(lVar1 + 0x34) = param_4[5];
  *(undefined4 *)(lVar1 + 0x38) = param_4[6];
  *(undefined4 *)(lVar1 + 0x3c) = param_4[7];
  *(undefined4 *)(lVar1 + 0x40) = param_4[8];
  *(undefined4 *)(lVar1 + 0x44) = param_4[9];
  *(undefined4 *)(lVar1 + 0x48) = param_4[10];
  *(undefined4 *)(lVar1 + 0x4c) = param_4[0xb];
  *(undefined4 *)(lVar1 + 0x50) = param_4[0xc];
  *(undefined4 *)(lVar1 + 0x54) = param_4[0xd];
  *(undefined4 *)(lVar1 + 0x58) = param_4[0xe];
  *(undefined4 *)(lVar1 + 0x5c) = param_4[0xf];
  *(undefined4 *)(lVar1 + 0x60) = param_4[0x10];
  *(undefined4 *)(lVar1 + 100) = param_4[0x11];
  *(undefined4 *)(lVar1 + 0x68) = param_4[0x12];
  uVar4 = _issueRpcAndWait(param_1,param_2);
  if (lVar2 == 0) {
    return uVar4;
  }
  if ((int)uVar4 != 0) {
    return uVar4;
  }
LAB_004d1130:
  if (param_5 == '\0') {
    *(undefined4 *)(lVar2 + 0x1a8) = param_3;
    portMemCopy(lVar2 + 0x15c,0x4c,param_4,0x4c);
  }
  return 0;
}


// ===== 004d11d0 rpcCleanupSurface_v03_00 =====

undefined8 rpcCleanupSurface_v03_00(long param_1,long param_2,int param_3,int *param_4)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar1 = *(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8);
  if ((((lVar1 != 0) && (*(char *)(lVar1 + 0x1ac) != '\0')) && (*(int *)(lVar1 + 0x15c) == *param_4)
      ) && (*(int *)(lVar1 + 0x1a8) == param_3)) {
    lVar2 = *(long *)(param_2 + 0x4d8);
    portMemSet(lVar1 + 0x15c,0,0x50);
    uVar3 = rpcWriteCommonHeader(param_1,param_2,0x2e,8);
    if ((int)uVar3 != 0) {
      return uVar3;
    }
    *(int *)(lVar2 + 0x20) = *param_4;
    *(int *)(lVar2 + 0x24) = param_4[1];
    uVar3 = _issueRpcAndWait(param_1,param_2);
    return uVar3;
  }
  return 0;
}


// ===== 004d1290 rpcUnloadingGuestDriver_v1F_07 =====

undefined8
rpcUnloadingGuestDriver_v1F_07
          (undefined8 param_1,long param_2,undefined1 param_3,undefined1 param_4,undefined4 param_5)

{
  undefined8 uVar1;
  
  if (*(uint *)(param_2 + 0x4f0) < 0x28) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x248d,"rpcUnloadingGuestDriver_v1F_07",4,
                 "NVRM: Unloading guest driver parameters size (0x%x) exceed message_buffer size (0x%x)\n"
                 ,0x28,*(uint *)(param_2 + 0x4f0));
    nvAssertFailedNoLog(&DAT_00d98b20,"src/kernel/vgpu/rpc.c",0x2491);
    return 0x1a;
  }
  uVar1 = rpcWriteCommonHeader(param_1,param_2,0x2f,8);
  if ((int)uVar1 != 0) {
    return uVar1;
  }
  *(undefined1 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
  *(undefined1 *)(*(long *)(param_2 + 0x4d8) + 0x21) = param_4;
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_5;
  uVar1 = _issueRpcAndWait(param_1);
  return uVar1;
}


// ===== 004d1380 cliresCtrlCmdDiagDumpRpc_IMPL =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 cliresCtrlCmdDiagDumpRpc_IMPL(undefined8 param_1,int *param_2)

{
  bool bVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 *puVar4;
  int iVar5;
  int *piVar6;
  
  if (bProfileRPC != '\0') {
    nvAssertFailedNoLog("!bProfileRPC","src/kernel/vgpu/rpc.c",0x24aa);
    return 0x40;
  }
  if (_DAT_0056eaf8 == 0) {
    rpcDumpRec = rpcMeterHead;
  }
  iVar3 = *param_2;
  if ((_DAT_0056eaf8 == iVar3) || (rpcDumpRec = rpcMeterHead, iVar3 == 0)) {
    if (rpcDumpRec != (undefined8 *)0x0) goto LAB_004d1440;
  }
  else {
    bVar1 = false;
    iVar5 = 0;
    puVar4 = rpcMeterHead;
    do {
      if (puVar4 == (undefined8 *)0x0) {
        if (bVar1) {
          rpcDumpRec = (undefined8 *)0x0;
        }
        nvAssertFailedNoLog("rpcDumpRec.pHead","src/kernel/vgpu/rpc.c",0x24b5);
        return 0x1f;
      }
      iVar5 = iVar5 + 1;
      puVar4 = (undefined8 *)puVar4[4];
      bVar1 = true;
    } while (iVar3 != iVar5);
    rpcDumpRec = puVar4;
    if (puVar4 != (undefined8 *)0x0) {
LAB_004d1440:
      piVar6 = param_2 + 6;
      _DAT_0056eaf8 = 0;
      do {
        _DAT_0056eaf8 = _DAT_0056eaf8 + 1;
        *(undefined8 *)piVar6 = *rpcDumpRec;
        *(undefined8 *)(piVar6 + 2) = rpcDumpRec[1];
        *(undefined8 *)(piVar6 + 4) = rpcDumpRec[2];
        *(undefined8 *)(piVar6 + 6) = rpcDumpRec[3];
        rpcDumpRec = (undefined8 *)rpcDumpRec[4];
        if (rpcDumpRec == (undefined8 *)0x0) {
          rpcDumpRec = (undefined8 *)0x0;
          iVar3 = 0;
          goto LAB_004d14c0;
        }
        piVar6 = piVar6 + 8;
      } while (_DAT_0056eaf8 != 100);
      iVar3 = (rpcProfilerEntryCount - iVar3) + -100;
      goto LAB_004d14c0;
    }
    rpcDumpRec = (undefined8 *)0x0;
  }
  _DAT_0056eaf8 = 0;
  iVar3 = 0;
LAB_004d14c0:
  param_2[2] = iVar3;
  uVar2 = elapsedTimeInNs;
  param_2[1] = _DAT_0056eaf8;
  *(undefined8 *)(param_2 + 4) = uVar2;
  return 0;
}


// ===== 004d1550 cliresCtrlCmdDiagProfileRpc_IMPL =====

undefined8 cliresCtrlCmdDiagProfileRpc_IMPL(undefined8 param_1,int *param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  iVar1 = *param_2;
  if (iVar1 == 1) {
    bProfileRPC = 1;
    osGetPerformanceCounter(&startTimeInNs);
  }
  else {
    lVar3 = rpcMeterHead;
    if (iVar1 != 2) {
      if (iVar1 == 0) {
        bProfileRPC = 0;
        osGetPerformanceCounter(&endTimeInNs);
        elapsedTimeInNs = (elapsedTimeInNs + endTimeInNs) - startTimeInNs;
        return 0;
      }
      return 0x1f;
    }
    while (lVar3 != 0) {
      lVar2 = *(long *)(lVar3 + 0x20);
      portMemFree(lVar3);
      lVar3 = lVar2;
    }
    rpcMeterHead = 0;
    DAT_0056eb18 = 0;
    rpcProfilerEntryCount = 0;
    elapsedTimeInNs = 0;
  }
  return 0;
}


// ===== 004d1640 rpcSwitchToVga_v03_00 =====

undefined8 rpcSwitchToVga_v03_00(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if ((*(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8) != 0) &&
     (*(char *)(*(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8) + 0x1ac) == '\0')) {
    return 0;
  }
  uVar1 = rpcWriteCommonHeader(param_1,param_2,0x31,0);
  if ((int)uVar1 != 0) {
    return uVar1;
  }
  uVar1 = _issueRpcAndWait(param_1,param_2);
  return uVar1;
}


// ===== 004d16b0 rpcGpuExecRegOps_v12_01 =====

int rpcGpuExecRegOps_v12_01
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined4 *param_5,long param_6)

{
  int iVar1;
  undefined1 *puVar2;
  long lVar3;
  uint uVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  if (param_5 == (undefined4 *)0x0) {
    return 0x1f;
  }
  if (param_5[5] == 0) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x251f,"rpcGpuExecRegOps_v12_01",4,
                 "NVRM: RegOps RPC failed: Invalid regOp count - requested 0x%x regOps\n",0);
    iVar1 = 0x1f;
  }
  else if (*(uint *)(param_2 + 0x4f0) < 0xcd8) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x252b,"rpcGpuExecRegOps_v12_01",4,
                 "NVRM: NVRM_RPC: rpcGpuExecRegOps_v12_01: Insufficient space on message buffer\n");
    iVar1 = 2;
  }
  else {
    iVar1 = rpcWriteCommonHeader(param_1,param_2,0x32);
    if (iVar1 == 0) {
      *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
      uVar10 = 0;
      *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
      *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x28) = *param_5;
      *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x2c) = param_5[1];
      *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x3c) = param_5[5];
      *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x40) = param_5[8];
      *(undefined8 *)(*(long *)(param_2 + 0x4d8) + 0x48) = *(undefined8 *)(param_5 + 10);
      uVar4 = param_5[5];
      if (uVar4 != 0) {
        do {
          uVar5 = 0;
          uVar9 = uVar10;
          while( true ) {
            uVar6 = (ulong)uVar9;
            uVar8 = (uint)uVar5;
            if (uVar4 <= uVar9) break;
            uVar8 = uVar8 + 1;
            uVar9 = uVar9 + 1;
            lVar3 = uVar5 * 0x20;
            puVar2 = (undefined1 *)(uVar6 * 0x20 + param_6);
            lVar7 = (uVar5 + 3) * 0x20;
            *(undefined1 *)(*(long *)(param_2 + 0x4d8) + lVar3 + 0x58) = *puVar2;
            *(undefined1 *)(*(long *)(param_2 + 0x4d8) + lVar3 + 0x59) = puVar2[1];
            *(undefined1 *)(*(long *)(param_2 + 0x4d8) + lVar3 + 0x5a) = puVar2[2];
            *(undefined1 *)(*(long *)(param_2 + 0x4d8) + lVar3 + 0x5b) = puVar2[3];
            *(undefined4 *)(*(long *)(param_2 + 0x4d8) + lVar3 + 0x5c) = *(undefined4 *)(puVar2 + 4)
            ;
            *(undefined4 *)(*(long *)(param_2 + 0x4d8) + lVar3 + 0x60) = *(undefined4 *)(puVar2 + 8)
            ;
            *(undefined4 *)(lVar3 + *(long *)(param_2 + 0x4d8) + 100) =
                 *(undefined4 *)(puVar2 + 0xc);
            *(undefined4 *)(*(long *)(param_2 + 0x4d8) + lVar7 + 8) = *(undefined4 *)(puVar2 + 0x10)
            ;
            *(undefined4 *)(*(long *)(param_2 + 0x4d8) + lVar7 + 0xc) =
                 *(undefined4 *)(puVar2 + 0x14);
            *(undefined4 *)(*(long *)(param_2 + 0x4d8) + lVar7 + 0x10) =
                 *(undefined4 *)(puVar2 + 0x18);
            *(undefined4 *)(lVar7 + *(long *)(param_2 + 0x4d8) + 0x14) =
                 *(undefined4 *)(puVar2 + 0x1c);
            if (uVar8 == 100) break;
            uVar4 = param_5[5];
            uVar5 = (ulong)uVar8;
          }
          *(uint *)(*(long *)(param_2 + 0x4d8) + 0x3c) = uVar8;
          iVar1 = _issueRpcAndWait(param_1);
          if (iVar1 == 0) {
            iVar1 = *(int *)(*(long *)(param_2 + 0x4d8) + 0x14);
            if (iVar1 == 0) {
              uVar5 = 0;
              do {
                if ((uint)param_5[5] <= uVar10) {
                  return 0;
                }
                uVar6 = (ulong)uVar10;
                uVar4 = (int)uVar5 + 1;
                uVar10 = uVar10 + 1;
                lVar7 = uVar6 * 0x20;
                lVar3 = (uVar5 + 3) * 0x20;
                *(undefined1 *)(param_6 + 2 + lVar7) =
                     *(undefined1 *)(uVar5 * 0x20 + *(long *)(param_2 + 0x4d8) + 0x5a);
                *(undefined4 *)(param_6 + 0x10 + lVar7) =
                     *(undefined4 *)(*(long *)(param_2 + 0x4d8) + lVar3 + 8);
                *(undefined4 *)(param_6 + 0x14 + lVar7) =
                     *(undefined4 *)(lVar3 + *(long *)(param_2 + 0x4d8) + 0xc);
                uVar5 = (ulong)uVar4;
                uVar9 = uVar10;
              } while (uVar4 != 100);
            }
            else {
              nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2560,"rpcGpuExecRegOps_v12_01",4,
                           "NVRM: RegOps RPC failed: skipping 0x%x regOps\n",param_5[5] - uVar10);
            }
          }
          uVar10 = uVar9;
          uVar4 = param_5[5];
        } while (uVar10 < uVar4);
      }
    }
  }
  return iVar1;
}


// ===== 004d1a00 rpcGetStaticData_v25_0E =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

int rpcGetStaticData_v25_0E(undefined8 param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  uint uVar7;
  ulong uVar8;
  uint uVar9;
  uint uVar10;
  uint local_3c [3];
  
  local_3c[0] = 0;
  if (*(uint *)(param_2 + 0x4f0) < 0x28) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2579,"rpcGetStaticData_v25_0E",4,
                 "NVRM: vGPU static data parameters size (0x%x) exceed message_buffer size (0x%x)\n"
                 ,0x28,*(uint *)(param_2 + 0x4f0));
    return 0x1a;
  }
  iVar3 = getStaticDataRpcBufferSize(param_1,param_2 + 0x2d30,local_3c);
  uVar9 = local_3c[0];
  iVar2 = *(int *)(param_2 + 0x4f0);
  lVar4 = portMemAllocNonPaged();
  if (lVar4 == 0) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2588,"rpcGetStaticData_v25_0E",4,
                 "NVRM: no memory for temporary buffer\n");
    return 0x1a;
  }
  uVar1 = iVar2 - 0x28;
  uVar10 = 0;
  if (uVar9 == 0) {
    if (iVar3 != 0) goto LAB_004d1b05;
  }
  else {
    do {
      uVar7 = uVar1;
      if (uVar9 < uVar1) {
        uVar7 = uVar9;
      }
      iVar3 = rpcWriteCommonHeader(param_1,param_2,0xcf,uVar7 + 8);
      if (iVar3 != 0) goto LAB_004d1b05;
      *(uint *)(*(long *)(param_2 + 0x4d8) + 0x20) = uVar10;
      *(uint *)(*(long *)(param_2 + 0x4d8) + 0x24) = uVar7;
      iVar3 = _issueRpcAndWait(param_1,param_2);
      if (iVar3 != 0) goto LAB_004d1b05;
      uVar8 = (ulong)uVar10;
      uVar10 = uVar10 + uVar7;
      portMemCopy(uVar8 + lVar4,uVar7,*(long *)(param_2 + 0x4d8) + 0x28,uVar7);
      uVar9 = uVar9 - uVar7;
    } while (uVar9 != 0);
  }
  uVar5 = gpuGetStaticInfo(param_1);
  iVar3 = copyPayloadToStaticData(param_1,param_2 + 0x2d30,lVar4,local_3c[0],uVar5);
  if (iVar3 == 0) {
    lVar6 = gpuGetRpc(param_1);
    if ((lVar6 != 0) &&
       (iVar3 = (**(code **)(lVar6 + 0x290))(param_1,lVar6,*(code **)(lVar6 + 0x290)), iVar3 != 0))
    {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x25bd,"rpcGetStaticData_v25_0E",4,
                   "NVRM: NVRM_RPC: GET_CONSOLIDATED_GR_STATIC_INFO failed.\n");
    }
  }
  else {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x25b5,"rpcGetStaticData_v25_0E",4,
                 "NVRM: Failed to copy the data from RPC to Static Info buffer. Status :%x\n",iVar3)
    ;
  }
LAB_004d1b05:
  portMemFree(lVar4);
  return iVar3;
}


// ===== 004d1c80 rpcGetStaticData_v27_01 =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

int rpcGetStaticData_v27_01(undefined8 param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  ulong uVar8;
  uint local_3c [3];
  
  local_3c[0] = 0;
  uVar3 = gpuGetStaticInfo();
  if (*(uint *)(param_2 + 0x4f0) < 0x28) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x25d8,"rpcGetStaticData_v27_01",4,
                 "NVRM: vGPU static data parameters size (0x%x) exceed message_buffer size (0x%x)\n"
                 ,0x28,*(uint *)(param_2 + 0x4f0));
  }
  else {
    iVar2 = getStaticDataRpcBufferSize(param_1,param_2 + 0x2d30,local_3c);
    uVar7 = local_3c[0];
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x25e1,"rpcGetStaticData_v27_01",4,
                   "NVRM: getStaticDataRpcBufferSize is failed. status: 0x%x\n",iVar2);
      return iVar2;
    }
    iVar2 = *(int *)(param_2 + 0x4f0);
    lVar4 = portMemAllocNonPaged();
    if (lVar4 != 0) {
      uVar1 = iVar2 - 0x28;
      uVar8 = 0;
      for (; uVar7 != 0; uVar7 = uVar7 - uVar6) {
        uVar6 = uVar1;
        if (uVar7 < uVar1) {
          uVar6 = uVar7;
        }
        iVar2 = rpcWriteCommonHeader(param_1,param_2,0xcf,uVar6 + 8);
        if (iVar2 != 0) goto LAB_004d1d95;
        *(int *)(*(long *)(param_2 + 0x4d8) + 0x20) = (int)uVar8;
        *(uint *)(*(long *)(param_2 + 0x4d8) + 0x24) = uVar6;
        iVar2 = _issueRpcAndWait(param_1,param_2);
        if (iVar2 != 0) goto LAB_004d1d95;
        lVar5 = uVar8 + lVar4;
        uVar8 = (ulong)((int)uVar8 + uVar6);
        portMemCopy(lVar5,uVar6,*(long *)(param_2 + 0x4d8) + 0x28,uVar6);
      }
      iVar2 = copyPayloadToStaticData(param_1,param_2 + 0x2d30,lVar4,local_3c[0],uVar3);
      if (iVar2 == 0) {
        lVar5 = gpuGetRpc(param_1);
        if ((lVar5 != 0) &&
           (iVar2 = (**(code **)(lVar5 + 0x290))(param_1,lVar5,*(code **)(lVar5 + 0x290)),
           iVar2 != 0)) {
          nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2617,"rpcGetStaticData_v27_01",4,
                       "NVRM: NVRM_RPC: GET_CONSOLIDATED_GR_STATIC_INFO failed.\n");
        }
      }
      else {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x260f,"rpcGetStaticData_v27_01",4,
                     "NVRM: Failed to copy the data from RPC to Static Info buffer. Status :%x\n",
                     iVar2);
      }
LAB_004d1d95:
      portMemFree(lVar4);
      return iVar2;
    }
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x25ec,"rpcGetStaticData_v27_01",4,
                 "NVRM: no memory for temporary buffer\n");
  }
  return 0x1a;
}


// ===== 004d1f40 rpcGetStaticData_v2D_00 =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

int rpcGetStaticData_v2D_00(long param_1,long param_2)

{
  uint uVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  long lVar7;
  uint uVar8;
  ulong uVar9;
  uint local_3c [3];
  
  local_3c[0] = 0;
  lVar4 = gpuGetStaticInfo();
  if (*(uint *)(param_2 + 0x4f0) < 0x28) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2631,"rpcGetStaticData_v2D_00",4,
                 "NVRM: vGPU static data parameters size (0x%x) exceed message_buffer size (0x%x)\n"
                 ,0x28,*(uint *)(param_2 + 0x4f0));
  }
  else {
    uVar2 = *(undefined8 *)(param_1 + 0x1cf8);
    iVar3 = getStaticDataRpcBufferSize(param_1,param_2 + 0x2d30,local_3c);
    uVar8 = local_3c[0];
    if (iVar3 != 0) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x263a,"rpcGetStaticData_v2D_00",4,
                   "NVRM: getStaticDataRpcBufferSize is failed. status: 0x%x\n",iVar3);
      return iVar3;
    }
    iVar3 = *(int *)(param_2 + 0x4f0);
    lVar5 = portMemAllocNonPaged();
    if (lVar5 != 0) {
      uVar1 = iVar3 - 0x28;
      uVar9 = 0;
      for (; uVar8 != 0; uVar8 = uVar8 - uVar6) {
        uVar6 = uVar1;
        if (uVar8 < uVar1) {
          uVar6 = uVar8;
        }
        iVar3 = rpcWriteCommonHeader(param_1,param_2,0xcf,uVar6 + 8);
        if (iVar3 != 0) goto LAB_004d205d;
        *(int *)(*(long *)(param_2 + 0x4d8) + 0x20) = (int)uVar9;
        *(uint *)(*(long *)(param_2 + 0x4d8) + 0x24) = uVar6;
        iVar3 = _issueRpcAndWait(param_1,param_2);
        if (iVar3 != 0) goto LAB_004d205d;
        lVar7 = uVar9 + lVar5;
        uVar9 = (ulong)((int)uVar9 + uVar6);
        portMemCopy(lVar7,uVar6,*(long *)(param_2 + 0x4d8) + 0x28,uVar6);
      }
      iVar3 = copyPayloadToStaticData(param_1,param_2 + 0x2d30,lVar5,local_3c[0],lVar4);
      if (iVar3 == 0) {
        iVar3 = griddisplaylessUpdateHeadNumInfo_IMPL(uVar2,lVar4 + 0x25f6c);
        if (iVar3 == 0) {
          iVar3 = griddisplaylessUpdateMaxResInfo_IMPL(uVar2,lVar4 + 0x25f60);
          if (iVar3 == 0) {
            iVar3 = griddisplaylessUpdateMaxPixels_IMPL(uVar2,*(undefined4 *)(lVar4 + 0xa728));
            if (iVar3 == 0) {
              lVar4 = gpuGetRpc(param_1);
              if ((lVar4 != 0) &&
                 (iVar3 = (**(code **)(lVar4 + 0x290))(param_1,lVar4,*(code **)(lVar4 + 0x290)),
                 iVar3 != 0)) {
                nvDbg_Printf("src/kernel/vgpu/rpc.c",0x268d,"rpcGetStaticData_v2D_00",4,
                             "NVRM: NVRM_RPC: GET_CONSOLIDATED_GR_STATIC_INFO failed.\n");
              }
            }
            else {
              nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2684,"rpcGetStaticData_v2D_00",4,
                           "NVRM: Failed to set maximum allowed pixel limit param in GRIDDISPLAYLESS object. Status :%x\n"
                           ,iVar3);
            }
          }
          else {
            nvDbg_Printf("src/kernel/vgpu/rpc.c",0x267b,"rpcGetStaticData_v2D_00",4,
                         "NVRM: Failed to set maximum allowed resolution param in GRIDDISPLAYLESS object. Status :%x\n"
                         ,iVar3);
          }
        }
        else {
          nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2671,"rpcGetStaticData_v2D_00",4,
                       "NVRM: Failed to set the numHeads param in GRIDDISPLAYLESS object. Status :%x\n"
                       ,iVar3);
        }
      }
      else {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2668,"rpcGetStaticData_v2D_00",4,
                     "NVRM: Failed to copy the data from RPC to Static Info buffer. Status :%x\n",
                     iVar3);
      }
LAB_004d205d:
      portMemFree(lVar5);
      return iVar3;
    }
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2645,"rpcGetStaticData_v2D_00",4,
                 "NVRM: no memory for temporary buffer\n");
  }
  return 0x1a;
}


// ===== 004d2310 rpcGetConsolidatedGrStaticInfo_v1B_04 =====

/* WARNING: Type propagation algorithm not settling */

int rpcGetConsolidatedGrStaticInfo_v1B_04(long param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  ulong uVar7;
  uint uVar8;
  uint uVar9;
  uint local_40 [4];
  
  local_40[0] = 0;
  if (*(uint *)(param_2 + 0x4f0) < 0x28) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x26a2,"rpcGetConsolidatedGrStaticInfo_v1B_04",4,
                 "NVRM: vGPU consolidated static information parameters size (0x%x) exceed message_buffer size (0x%x)\n"
                 ,0x28,*(uint *)(param_2 + 0x4f0));
    nvAssertFailedNoLog(&DAT_00d98b20,"src/kernel/vgpu/rpc.c",0x26a6);
    return 0x1a;
  }
  iVar3 = consolidated_gr_static_info_copy_constprop_0
                    (param_2 + 0x2d30,0,0,0,local_40,*(char *)(param_1 + 0x4a4e) != '\0');
  if (iVar3 != 0) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x94e,"getConsolidatedGrRpcBufferSize",4,
                 "NVRM: NVRM_RPC: getConsolidatedGrRpcBufferSize: failed.\n");
    nvAssertFailedNoLog(&DAT_00d98b20,"src/kernel/vgpu/rpc.c",0x950);
  }
  uVar8 = local_40[0];
  iVar2 = *(int *)(param_2 + 0x4f0);
  lVar4 = portMemAllocNonPaged();
  if (lVar4 == 0) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x26b3,"rpcGetConsolidatedGrStaticInfo_v1B_04",4,
                 "NVRM: no memory for temporary buffer\n");
    return 0x1a;
  }
  uVar1 = iVar2 - 0x28;
  uVar9 = 0;
  if (uVar8 == 0) {
    if (iVar3 != 0) goto LAB_004d2435;
  }
  else {
    do {
      uVar6 = uVar1;
      if (uVar8 < uVar1) {
        uVar6 = uVar8;
      }
      iVar3 = rpcWriteCommonHeader(param_1,param_2,0x9c,uVar6 + 8);
      if (iVar3 != 0) goto LAB_004d2435;
      *(uint *)(*(long *)(param_2 + 0x4d8) + 0x20) = uVar9;
      *(uint *)(*(long *)(param_2 + 0x4d8) + 0x24) = uVar6;
      iVar3 = _issueRpcAndWait(param_1,param_2);
      if (iVar3 != 0) goto LAB_004d2435;
      uVar7 = (ulong)uVar9;
      uVar9 = uVar9 + uVar6;
      portMemCopy(uVar7 + lVar4,uVar6,*(long *)(param_2 + 0x4d8) + 0x28,uVar6);
      uVar8 = uVar8 - uVar6;
    } while (uVar8 != 0);
  }
  lVar5 = gpuGetStaticInfo(param_1);
  local_40[1] = 0;
  if (lVar5 == 0) {
    nvAssertFailedNoLog("pVSI != NULL","src/kernel/vgpu/rpc.c",0x95e,local_40[0]);
    iVar3 = 0x1f;
  }
  else {
    iVar3 = consolidated_gr_static_info_copy_constprop_0
                      (param_2 + 0x2d30,lVar5,lVar4,local_40[0],local_40 + 1,
                       *(char *)(param_1 + 0x4a4e) != '\0');
    if (iVar3 == 0) goto LAB_004d2435;
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x966,"copyPayloadToGrStaticInfo",4,
                 "NVRM: NVRM_RPC: copyPayloadToGrStaticInfo: failed.\n");
    nvAssertFailedNoLog(&DAT_00d98b20,"src/kernel/vgpu/rpc.c",0x968);
  }
  nvDbg_Printf("src/kernel/vgpu/rpc.c",0x26e0,"rpcGetConsolidatedGrStaticInfo_v1B_04",4,
               "NVRM: Failed to copy the data from RPC to GR Static Info buffer. Status :%x\n");
LAB_004d2435:
  portMemFree(lVar4);
  return iVar3;
}


// ===== 004d2630 rpcGetGspStaticInfo_v14_00 =====

int rpcGetGspStaticInfo_v14_00(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  
  if (*(char *)(param_1 + 0x909) != '\0') {
    lVar3 = gpuGetGspStaticInfo();
    if (lVar3 == 0) {
      nvAssertFailedNoLog(&DAT_00d9b815,"src/kernel/vgpu/rpc.c",0x26f6);
      iVar2 = 0x3d;
    }
    else if (*(uint *)(param_2 + 0x4f0) < 0x658) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x26fc,"rpcGetGspStaticInfo_v14_00",4,
                   "NVRM: Gsp static info parameters size (0x%x) exceed message_buffer size (0x%x)\n"
                   ,0x658,*(uint *)(param_2 + 0x4f0));
      nvAssertFailedNoLog(&DAT_00d98b20,"src/kernel/vgpu/rpc.c",0x2700);
      iVar2 = 0x1a;
    }
    else {
      lVar1 = *(long *)(param_2 + 0x4d8);
      iVar2 = rpcWriteCommonHeader(param_1,param_2,0x41,0x638);
      if (iVar2 == 0) {
        iVar2 = _issueRpcAndWait(param_1,param_2);
        if (iVar2 == 0) {
          portMemCopy(lVar3,0x638,lVar1 + 0x20,0x638);
        }
        else {
          nvCheckFailedNoLog(1,"status == NV_OK","src/kernel/vgpu/rpc.c",0x270b);
        }
      }
    }
    return iVar2;
  }
  return 0x56;
}


// ===== 004d27c0 rpcUpdateBarPde_v15_00 =====

undefined8
rpcUpdateBarPde_v15_00
          (long param_1,long param_2,undefined4 param_3,undefined8 param_4,undefined8 param_5)

{
  long lVar1;
  undefined8 uVar2;
  
  if (*(char *)(param_1 + 0x909) == '\0') {
    return 0x56;
  }
  lVar1 = *(long *)(param_2 + 0x4d8);
  uVar2 = rpcWriteCommonHeader(param_1,param_2,0x46,0x18);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined8 *)(lVar1 + 0x28) = param_4;
    *(undefined8 *)(lVar1 + 0x30) = param_5;
    uVar2 = _issueRpcAndWait(param_1,param_2);
    return uVar2;
  }
  return uVar2;
}


// ===== 004d2850 rpcSetPageDirectory_v1E_05 =====

undefined8
rpcSetPageDirectory_v1E_05
          (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined8 *param_5
          )

{
  long lVar1;
  char cVar2;
  undefined8 uVar3;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  cVar2 = hypervisorIsType_IMPL(2);
  if ((cVar2 == '\0') || ((*(byte *)((long)param_5 + 0xc) & 3) == 0)) {
    uVar3 = rpcWriteCommonHeader(param_1,param_2,0x36,0x30);
    if ((int)uVar3 == 0) {
      *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
      *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
      *(undefined8 *)(lVar1 + 0x30) = *param_5;
      *(undefined4 *)(lVar1 + 0x38) = *(undefined4 *)(param_5 + 1);
      *(undefined4 *)(lVar1 + 0x3c) = *(undefined4 *)((long)param_5 + 0xc);
      *(undefined4 *)(lVar1 + 0x40) = *(undefined4 *)(param_5 + 2);
      *(undefined4 *)(lVar1 + 0x44) = *(undefined4 *)((long)param_5 + 0x14);
      *(undefined4 *)(lVar1 + 0x48) = *(undefined4 *)(param_5 + 3);
      *(undefined4 *)(lVar1 + 0x4c) = *(undefined4 *)((long)param_5 + 0x1c);
      uVar3 = _issueRpcAndWait(param_1,param_2);
      return uVar3;
    }
  }
  else {
    nvAssertFailedNoLog(&DAT_00d98b20,"src/kernel/vgpu/rpc.c",0x2737);
    uVar3 = 0x56;
  }
  return uVar3;
}


// ===== 004d2950 rpcUnsetPageDirectory_v1E_05 =====

void rpcUnsetPageDirectory_v1E_05
               (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
               undefined4 *param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0x4f,0x10);
  if (iVar2 != 0) {
    return;
  }
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
  *(undefined4 *)(lVar1 + 0x28) = *param_5;
  *(undefined4 *)(lVar1 + 0x2c) = param_5[1];
  _issueRpcAndWait(param_1,param_2);
  return;
}


// ===== 004d29f0 rpcSaveHibernationData_v1E_0E =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

int rpcSaveHibernationData_v1E_0E(long param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  uint uVar8;
  uint uVar9;
  
  lVar2 = *(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8);
  if (*(char *)(lVar2 + 0x150) == '\0') {
    iVar5 = *(int *)(param_2 + 0x4f0);
    lVar7 = *(long *)(param_2 + 0x4d8);
    iVar4 = rpcWriteCommonHeader(param_1,param_2,0xb5,iVar5 + -0x20);
    if (((iVar4 == 0) && (iVar4 = _issueRpcAndWait(param_1,param_2), iVar4 == 0)) &&
       (uVar8 = *(uint *)(lVar7 + 0x20), uVar8 != 0)) {
      *(uint *)(lVar2 + 0x26180) = uVar8;
      lVar6 = portMemAllocNonPaged(uVar8);
      *(long *)(lVar2 + 0x26188) = lVar6;
      if (lVar6 == 0) {
        iVar4 = 0x1a;
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x285d,"_saveHibernationDataNonGsp",4,
                     "NVRM: No memory for hibernation buffer\n");
      }
      else {
        lVar7 = lVar7 + 0x24;
        uVar9 = iVar5 - 0x24;
        if (uVar9 < uVar8) {
          portMemCopy(lVar6,uVar9,lVar7,uVar9);
          uVar8 = uVar8 - uVar9;
          uVar1 = uVar9;
          do {
            iVar5 = rpcWriteCommonHeader(param_1,param_2,0xb5,*(int *)(param_2 + 0x4f0) + -0x20);
            if ((iVar5 != 0) || (iVar5 = _issueRpcAndWait(param_1,param_2), iVar5 != 0)) {
              portMemFree(lVar6);
              bSkipRpcVersionHandshake = 0;
              return iVar5;
            }
            uVar3 = uVar8;
            if (uVar9 <= uVar8) {
              uVar3 = uVar9;
            }
            portMemCopy((ulong)uVar1 + lVar6,uVar3,lVar7,uVar3);
            uVar1 = uVar1 + uVar3;
            uVar8 = uVar8 - uVar3;
            iVar4 = 0;
          } while (uVar8 != 0);
        }
        else {
          portMemCopy(lVar6,uVar8,lVar7,uVar8);
        }
      }
    }
    bSkipRpcVersionHandshake = 0;
    return iVar4;
  }
  iVar5 = 0;
  if (*(long *)(lVar2 + 0x110) != 0) {
    lVar7 = gpuGetRpc();
    if ((lVar7 != 0) &&
       (iVar5 = (**(code **)(lVar7 + 0x380))(param_1,lVar7,*(code **)(lVar7 + 0x380)), iVar5 != 0))
    {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x27bc,"_saveHibernationDataGsp",4,
                   "NVRM: RPC SETUP_HIBERNATION_BUFFER failed, status 0x%x\n",iVar5);
      return iVar5;
    }
    *(undefined8 *)(lVar2 + 0x26180) = 0x800000;
    lVar7 = portMemAllocNonPaged(0x800000);
    *(long *)(lVar2 + 0x26188) = lVar7;
    if (lVar7 != 0) {
      iVar5 = rpcWriteCommonHeader(param_1,param_2,0xb5,4);
      if (iVar5 == 0) {
        iVar5 = _issueRpcAndWait(param_1,param_2);
        if (iVar5 == 0) {
          bSkipRpcVersionHandshake = 0;
          return 0;
        }
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x27d6,"_saveHibernationDataGsp",4,
                     "NVRM: RPC SAVE_HIBERNATION_DATA FAILURE, status 0x%x\n",iVar5);
      }
      portMemFree(lVar7);
      bSkipRpcVersionHandshake = 0;
      return iVar5;
    }
    iVar5 = 0x1a;
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x27c7,"_saveHibernationDataGsp",4,
                 "NVRM: No memory for hibernation buffer\n");
  }
  bSkipRpcVersionHandshake = 0;
  return iVar5;
}


// ===== 004d2d20 rpcRestoreHibernationData_v1E_0E =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

int rpcRestoreHibernationData_v1E_0E(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  lVar1 = *(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8);
  lVar2 = *(long *)(lVar1 + 0x26188);
  if (*(char *)(lVar1 + 0x150) == '\0') {
    uVar8 = *(uint *)(lVar1 + 0x26180);
    iVar4 = 0;
    if (uVar8 != 0) {
      lVar1 = *(long *)(param_2 + 0x4d8);
      uVar6 = *(int *)(param_2 + 0x4f0) - 0x24;
      uVar7 = 0;
      do {
        uVar3 = uVar6;
        if (uVar8 <= uVar6) {
          uVar3 = uVar8;
        }
        iVar4 = rpcWriteCommonHeader(param_1,param_2,0xb6,uVar3 + 4);
        if (iVar4 != 0) goto LAB_004d2e05;
        *(uint *)(lVar1 + 0x20) = uVar8;
        portMemCopy(lVar1 + 0x24,uVar3,(ulong)uVar7 + lVar2,uVar3);
        iVar4 = _issueRpcAndWait(param_1,param_2);
        if (iVar4 != 0) goto LAB_004d2e05;
        uVar7 = uVar7 + uVar3;
        uVar8 = uVar8 - uVar3;
      } while (uVar8 != 0);
      iVar4 = 0;
    }
  }
  else {
    iVar4 = 0;
    if (*(long *)(lVar1 + 0x110) != 0) {
      lVar5 = gpuGetRpc();
      if ((lVar5 == 0) ||
         (iVar4 = (**(code **)(lVar5 + 0x380))(param_1,lVar5,*(code **)(lVar5 + 0x380)), iVar4 == 0)
         ) {
        *(undefined4 *)(*(long *)(lVar1 + 0x120) + 0x78) = 1;
        iVar4 = rpcWriteCommonHeader(param_1,param_2,0xb6,4);
        if ((iVar4 == 0) && (iVar4 = _issueRpcAndWait(param_1,param_2), iVar4 != 0)) {
          nvDbg_Printf("src/kernel/vgpu/rpc.c",0x282e,"_restoreHibernationDataGsp",4,
                       "NVRM: RPC RESTORE_HIBERNATION_DATA FAILURE, status 0x%x\n",iVar4);
        }
      }
      else {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x281d,"_restoreHibernationDataGsp",4,
                     "NVRM: RPC SETUP_HIBERNATION_BUFFER failed, status 0x%x\n",iVar4);
      }
    }
  }
LAB_004d2e05:
  portMemFree(lVar2);
  return iVar4;
}


// ===== 004d2f10 rpcSetupHibernationBuffer_v2A_06 =====

int rpcSetupHibernationBuffer_v2A_06(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = vgpuGspMakeBufferAddress
                    (*(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8) + 0xf8,
                     *(undefined8 *)
                      (*(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8) + 0x110));
  iVar1 = rpcWriteCommonHeader(param_1,param_2,0xdf,8);
  if (iVar1 != 0) {
    return iVar1;
  }
  *(undefined8 *)(*(long *)(param_2 + 0x4d8) + 0x20) = uVar2;
  iVar1 = _issueRpcAndWait(param_1,param_2);
  if (iVar1 != 0) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x28f8,"rpcSetupHibernationBuffer_v2A_06",4,
                 "NVRM: SetupHibernationBuffer RPC FAILURE\n");
    return iVar1;
  }
  nvDbg_Printf("src/kernel/vgpu/rpc.c",0x28fc,"rpcSetupHibernationBuffer_v2A_06",1,
               "NVRM: SetupHibernationBuffer RPC SUCCESS\n");
  return 0;
}


// ===== 004d3030 __pfx_rpcGetEngineUtilization_v09_0C_GetPidList =====

ulong __pfx_rpcGetEngineUtilization_v09_0C_GetPidList
                (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 *param_6)

{
  long lVar1;
  undefined4 uVar2;
  long lVar3;
  uint uVar4;
  ulong uVar5;
  long lVar6;
  
  uVar4 = *(int *)(param_2 + 0x4f0) - 0x30;
  if (uVar4 < 0xfac) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x291c,"rpcGetEngineUtilization_v09_0C_GetPidList",4,
                 "NVRM: NVRM_RPC: SendDmaControl: requested %u bytes (but only room for %u)\n",0xfac
                 ,uVar4);
    return 0x1f;
  }
  uVar5 = rpcWriteCommonHeader(param_1,param_2,0x3c,0xfbc);
  if ((int)uVar5 == 0) {
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x28) = param_5;
    lVar3 = *(long *)(param_2 + 0x4d8);
    uVar2 = *param_6;
    *(undefined4 *)(lVar3 + 0x38) = 1;
    *(undefined4 *)(lVar3 + 0x30) = uVar2;
    do {
      uVar5 = _issueRpcAndWait(param_1,param_2);
      if ((int)uVar5 != 0) {
        return uVar5;
      }
      if (*(int *)(lVar3 + 0x3c) == 0) {
        return 0;
      }
      uVar4 = param_6[0xfa2];
      lVar6 = 0;
      do {
        uVar5 = (ulong)uVar4;
        uVar4 = uVar4 + 1;
        param_6[0xfa2] = uVar4;
        lVar1 = lVar6 * 4;
        lVar6 = lVar6 + 1;
        param_6[uVar5 + 2] = *(undefined4 *)(lVar3 + 0x40 + lVar1);
      } while ((uint)lVar6 < *(uint *)(lVar3 + 0x3c));
      uVar5 = (ulong)*(uint *)(lVar3 + 0x38);
    } while (*(uint *)(lVar3 + 0x38) != 0);
  }
  return uVar5;
}


// ===== 004d3040 rpcGetEngineUtilization_v09_0C_GetPidList =====

ulong rpcGetEngineUtilization_v09_0C_GetPidList
                (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 *param_6)

{
  long lVar1;
  undefined4 uVar2;
  long lVar3;
  uint uVar4;
  ulong uVar5;
  long lVar6;
  
  uVar4 = *(int *)(param_2 + 0x4f0) - 0x30;
  if (uVar4 < 0xfac) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x291c,"rpcGetEngineUtilization_v09_0C_GetPidList",4,
                 "NVRM: NVRM_RPC: SendDmaControl: requested %u bytes (but only room for %u)\n",0xfac
                 ,uVar4);
    return 0x1f;
  }
  uVar5 = rpcWriteCommonHeader(param_1,param_2,0x3c,0xfbc);
  if ((int)uVar5 == 0) {
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x28) = param_5;
    lVar3 = *(long *)(param_2 + 0x4d8);
    uVar2 = *param_6;
    *(undefined4 *)(lVar3 + 0x38) = 1;
    *(undefined4 *)(lVar3 + 0x30) = uVar2;
    do {
      uVar5 = _issueRpcAndWait(param_1,param_2);
      if ((int)uVar5 != 0) {
        return uVar5;
      }
      if (*(int *)(lVar3 + 0x3c) == 0) {
        return 0;
      }
      uVar4 = param_6[0xfa2];
      lVar6 = 0;
      do {
        uVar5 = (ulong)uVar4;
        uVar4 = uVar4 + 1;
        param_6[0xfa2] = uVar4;
        lVar1 = lVar6 * 4;
        lVar6 = lVar6 + 1;
        param_6[uVar5 + 2] = *(undefined4 *)(lVar3 + 0x40 + lVar1);
      } while ((uint)lVar6 < *(uint *)(lVar3 + 0x3c));
      uVar5 = (ulong)*(uint *)(lVar3 + 0x38);
    } while (*(uint *)(lVar3 + 0x38) != 0);
  }
  return uVar5;
}


// ===== 004d31c0 rpcGetEngineUtilization_v1F_0E =====

ulong rpcGetEngineUtilization_v1F_0E
                (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,int param_5,
                undefined8 *param_6,uint param_7)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  undefined8 *puVar4;
  ulong uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  
  if (param_6 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("pParamStructPtr != NULL","src/kernel/vgpu/rpc.c",0x2996);
    return 0x3b;
  }
  if (param_5 != 0xb04) {
    if (param_5 == 0x20802096) {
      param_7 = (param_7 / 0x308) * 0x38;
    }
    uVar2 = *(int *)(param_2 + 0x4f0) - 0x30;
    if (param_7 <= uVar2) {
      uVar2 = rpcWriteCommonHeader(param_1,param_2,0x3c,param_7 + 0x10);
      uVar5 = (ulong)uVar2;
      if (uVar2 == 0) {
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
        *(int *)(*(long *)(param_2 + 0x4d8) + 0x28) = param_5;
        lVar1 = *(long *)(param_2 + 0x4d8);
        if (param_5 == 0x20802096) {
          uVar2 = _issueRpcAndWait(param_1,param_2);
          uVar5 = (ulong)uVar2;
          if (uVar2 == 0) {
            puVar4 = (undefined8 *)(lVar1 + 0x30);
            puVar6 = param_6;
            do {
              puVar7 = puVar6 + 0x61;
              *puVar6 = *puVar4;
              *(undefined4 *)(puVar6 + 1) = *(undefined4 *)(puVar4 + 1);
              *(undefined4 *)(puVar6 + 2) = *(undefined4 *)((long)puVar4 + 0xc);
              *(undefined4 *)(puVar6 + 0x11) = *(undefined4 *)((long)puVar4 + 0x14);
              *(undefined4 *)(puVar6 + 0x12) = *(undefined4 *)(puVar4 + 3);
              *(undefined4 *)(puVar6 + 0x21) = *(undefined4 *)(puVar4 + 4);
              *(undefined4 *)(puVar6 + 0x22) = *(undefined4 *)((long)puVar4 + 0x24);
              *(undefined4 *)(puVar6 + 0x31) = *(undefined4 *)((long)puVar4 + 0x2c);
              *(undefined4 *)(puVar6 + 0x32) = *(undefined4 *)(puVar4 + 6);
              puVar4 = puVar4 + 7;
              puVar6 = puVar7;
            } while (puVar7 != param_6 + 0x1b48);
          }
        }
        else {
          iVar3 = engine_utilization_copy_params_to_rpc_buffer_v09_0C(param_5,lVar1 + 0x30,param_6);
          uVar5 = 0x56;
          if (iVar3 == 0) {
            uVar2 = _issueRpcAndWait(param_1,param_2);
            uVar5 = (ulong)uVar2;
            if (uVar2 == 0) {
              iVar3 = engine_utilization_copy_params_from_rpc_buffer_v09_0C
                                (param_5,param_6,lVar1 + 0x30);
              uVar5 = (ulong)(-(uint)(iVar3 != 0) & 0x56);
            }
          }
        }
      }
      return uVar5;
    }
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x29b4,"rpcGetEngineUtilization_v1F_0E",4,
                 "NVRM: NVRM_RPC: SendDmaControl: requested %u bytes (but only room for %u)\n",
                 param_7,uVar2);
    return 0x1f;
  }
  uVar5 = rpcGetEngineUtilization_v09_0C_GetPidList();
  return uVar5;
}


// ===== 004d3450 rpcGetEncoderCapacity_v07_00 =====

void rpcGetEncoderCapacity_v07_00
               (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
               undefined4 *param_5)

{
  int iVar1;
  
  iVar1 = rpcWriteCommonHeader(param_1,param_2,0x3e,0xc);
  if (iVar1 == 0) {
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x24) = param_4;
    iVar1 = _issueRpcAndWait(param_1,param_2);
    if (iVar1 == 0) {
      *param_5 = *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x28);
      return;
    }
  }
  return;
}


// ===== 004d34f0 rpcVgpuPfRegRead32_v15_00 =====

undefined8 rpcVgpuPfRegRead32_v15_00(void)

{
  return 0x56;
}


// ===== 004d3500 rpcDisableChannels_v1E_0B =====

undefined8 rpcDisableChannels_v1E_0B(long param_1,long param_2,byte *param_3)

{
  undefined8 uVar1;
  
  if (*(char *)(param_1 + 0x908) == '\0') {
    if (*(char *)(param_1 + 0x4913) == '\0') goto LAB_004d3521;
  }
  else if (*(char *)(param_1 + 0x4913) == '\0') {
    return 0;
  }
  if (*(char *)(param_1 + 0x491e) != '\0') {
    return 0;
  }
LAB_004d3521:
  uVar1 = rpcWriteCommonHeader(param_1,param_2,0xb2,4);
  if ((int)uVar1 != 0) {
    return uVar1;
  }
  *(uint *)(*(long *)(param_2 + 0x4d8) + 0x20) = (uint)*param_3;
  uVar1 = _issueRpcAndWait(param_1);
  return uVar1;
}


// ===== 004d3590 rpcInvalidateTlb_v23_03 =====

int rpcInvalidateTlb_v23_03(undefined8 param_1,long param_2,undefined8 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = rpcWriteCommonHeader(param_1,param_2,200,0x10);
  if (iVar1 == 0) {
    *(undefined8 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x28) = param_4;
    iVar2 = _issueRpcAndWait(param_1,param_2);
    iVar1 = 0;
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2a1e,"rpcInvalidateTlb_v23_03",4,
                   "NVRM: Failed to invaldiate TLB rpc 0x%x\n");
      return iVar2;
    }
  }
  return iVar1;
}


// ===== 004d3640 rpcGspSetSystemInfo_v17_00 =====

undefined8 rpcGspSetSystemInfo_v17_00(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  if (*(char *)(param_1 + 0x909) == '\0') {
    return 0x56;
  }
  if (*(uint *)(param_2 + 0x4f0) < 0x3d0) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2a3b,"rpcGspSetSystemInfo_v17_00",4,
                 "NVRM: GSP_SET_SYSTEM_INFO parameters size (0x%x) exceed message_buffer size (0x%x)\n"
                 ,0x3d0,*(uint *)(param_2 + 0x4f0));
    nvAssertFailedNoLog(&DAT_00d98b20,"src/kernel/vgpu/rpc.c",0x2a3f);
    uVar3 = 0x1a;
  }
  else {
    lVar1 = *(long *)(param_1 + 0x1ba8);
    if (*(long *)(lVar1 + 0xb38) == 0) {
      nvAssertFailedNoLog("pKernelGsp->pSystemInfo != NULL","src/kernel/vgpu/rpc.c",0x2a43);
      uVar3 = 0x40;
    }
    else {
      lVar2 = *(long *)(param_2 + 0x4d8);
      uVar3 = rpcWriteCommonHeader(param_1,param_2,0x48,0x3b0);
      if ((int)uVar3 == 0) {
        portMemCopy(lVar2 + 0x20,0x3b0,*(undefined8 *)(lVar1 + 0xb38),0x3b0);
        uVar3 = _issueRpcAsync(param_1,param_2);
        return uVar3;
      }
    }
  }
  return uVar3;
}


// ===== 004d3790 rpcSetRegistry_v17_00 =====

ulong rpcSetRegistry_v17_00(long param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  uint uVar4;
  ulong uVar5;
  long lVar6;
  
  if (*(char *)(param_1 + 0x909) == '\0') {
    return 0x56;
  }
  lVar3 = *(long *)(param_1 + 0x1ba8);
  if (*(long *)(lVar3 + 0xb48) == 0) {
    nvAssertFailedNoLog("pKernelGsp->pRegTable != NULL","src/kernel/vgpu/rpc.c",0x2a69);
    uVar5 = 0x40;
  }
  else {
    uVar4 = *(uint *)(lVar3 + 0xb40);
    uVar5 = rpcWriteCommonHeader(param_1,param_2,0x49,0);
    if ((int)uVar5 != 0) {
      return uVar5;
    }
    iVar2 = *(int *)(param_2 + 0x4f0);
    uVar1 = uVar4 + 0x20;
    uVar5 = (ulong)uVar1;
    if (**(ulong **)(param_2 + 0x510) <= uVar5) {
      nvAssertFailedNoLog("totalSize < pRpc->pMessageQueueInfo->commandQueueSize",
                          "src/kernel/vgpu/rpc.c",0x2a79);
    }
    if (iVar2 - 0x20U < uVar4) {
      lVar6 = portMemAllocNonPaged(uVar5);
      if (lVar6 == 0) {
        return 0x51;
      }
      portMemCopy(lVar6,uVar5,*(undefined8 *)(param_2 + 0x4d8),0x20);
      portMemCopy(lVar6 + 0x20,uVar4,*(undefined8 *)(lVar3 + 0xb48),uVar4);
      uVar4 = _issueRpcLarge(param_1,param_2,uVar1,lVar6,0,0);
    }
    else {
      lVar6 = 0;
      portMemCopy(*(long *)(param_2 + 0x4d8) + 0x20,uVar4,*(undefined8 *)(lVar3 + 0xb48),uVar4);
      *(uint *)(*(long *)(param_2 + 0x4d8) + 8) = uVar1;
      uVar4 = _issueRpcAsync(param_1,param_2);
    }
    portMemFree(lVar6);
    uVar5 = (ulong)uVar4;
  }
  return uVar5;
}


// ===== 004d3970 rpcDumpProtobufComponent_v18_12 =====

ulong rpcDumpProtobufComponent_v18_12
                (long param_1,long param_2,long param_3,long param_4,undefined2 param_5)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  
  if (*(char *)(param_1 + 0x909) == '\0') {
    return 0x56;
  }
  if (*(uint *)(param_2 + 0x4f0) < 0x30) {
    nvAssertFailedNoLog("fixed_param_size <= pRpc->maxRpcSize","src/kernel/vgpu/rpc.c",0x2aad);
    uVar4 = 0x40;
  }
  else {
    lVar1 = *(long *)(param_2 + 0x4d8);
    uVar4 = rpcWriteCommonHeader(param_1,param_2,0x4e,0x10);
    if ((int)uVar4 == 0) {
      *(undefined2 *)(lVar1 + 0x20) = param_5;
      *(char *)(lVar1 + 0x22) = (char)*(undefined4 *)(param_4 + 0x10);
      *(byte *)(lVar1 + 0x23) = *(byte *)(param_3 + 0x14c) >> 4 & 1;
      *(undefined4 *)(lVar1 + 0x24) = *(undefined4 *)(param_4 + 4);
      *(undefined4 *)(lVar1 + 0x28) = *(undefined4 *)(param_4 + 8);
      iVar3 = *(int *)(param_2 + 0x4f0);
      uVar2 = prbEncBufLeft(param_3);
      if (iVar3 - 0x30U < uVar2) {
        iVar3 = *(int *)(param_2 + 0x4f0) + -0x30;
      }
      else {
        iVar3 = prbEncBufLeft(param_3);
      }
      *(int *)(lVar1 + 0x2c) = iVar3;
      uVar4 = _issueRpcAndWait(param_1,param_2);
      if ((int)uVar4 == 0) {
        uVar2 = *(uint *)(lVar1 + 0x2c);
        uVar4 = (ulong)uVar2;
        if (uVar2 != 0) {
          uVar4 = prbEncStubbedAddBytes(param_3,lVar1 + 0x30,uVar2);
          return uVar4;
        }
      }
    }
  }
  return uVar4;
}


// ===== 004d3ae0 rpcRmApiControl_GSP =====

int rpcRmApiControl_GSP(long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       long param_5,uint param_6)

{
  long lVar1;
  long lVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  undefined1 *puVar9;
  undefined8 uVar10;
  uint uVar11;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  undefined8 extraout_RDX_01;
  undefined8 extraout_RDX_02;
  undefined8 extraout_RDX_03;
  undefined8 extraout_RDX_04;
  undefined8 extraout_RDX_05;
  undefined8 extraout_RDX_06;
  undefined8 extraout_RDX_07;
  long lVar12;
  undefined1 auVar13 [16];
  long unaff_retaddr;
  undefined8 uStack_100;
  long local_e0;
  byte local_d6;
  char local_d5;
  uint local_c4;
  long local_c0;
  int local_b8;
  uint local_b4;
  undefined4 local_b0;
  uint local_ac;
  undefined1 local_a8 [40];
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  long local_60;
  
  lVar1 = *(long *)(param_1 + 0xe0);
  local_c4 = param_6;
  local_c0 = param_5;
  lVar8 = gpuGetRpc(lVar1);
  lVar2 = local_c0;
  local_b8 = 0;
  iVar6 = *(int *)(lVar8 + 0x4f0);
  local_b4 = 0;
  local_b0 = 0;
  local_ac = 0;
  cVar4 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4));
  if (cVar4 == '\0') {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2b33,"rpcRmApiControl_GSP",3,
                 "NVRM: Calling RPC RmControl 0x%08x without adequate locks!\n",param_4);
    if (previousRetAddr_7 != unaff_retaddr) {
      previousRetAddr_7 = unaff_retaddr;
      osAssertFailed();
    }
    nvAssertFailedNoLog("RPC locking violation - see kernel_log.txt","src/kernel/vgpu/rpc.c",0x2b34)
    ;
    iVar5 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar1 + 0x7a4),0,2,0x8002,&local_b8);
    if (iVar5 != 0) {
      nvAssertOkFailedNoLog
                (iVar5,
                 "rmGpuGroupLockAcquire(pGpu->gpuInstance, GPU_LOCK_GRP_SUBDEVICE, GPU_LOCK_FLAGS_SAFE_LOCK_UPGRADE, RM_LOCK_MODULES_RPC, &gpuMaskRelease)"
                 ,"src/kernel/vgpu/rpc.c",0x2b36);
      return iVar5;
    }
  }
  iVar5 = rmapiutilGetControlInfo(param_4,&local_b4,&local_b0,0);
  local_d5 = '\0';
  if (iVar5 == 0) {
    local_d5 = rmapiControlIsCacheable(local_b4,local_b0,1);
  }
  puVar9 = (undefined1 *)resservGetTlsCallContext();
  if ((puVar9 == (undefined1 *)0x0) || (puVar9[0x68] != '\0')) {
    if (param_1 != lVar1 + 0x3b58) {
      nvAssertFailedNoLog("pRmApi == GPU_GET_PHYSICAL_RMAPI(pGpu)","src/kernel/vgpu/rpc.c",0x2b4e);
      return 0x40;
    }
    portMemSet(local_a8,0,0x70);
    local_80 = *(undefined8 *)(param_1 + 0xb8);
    puVar9 = local_a8;
    local_78 = *(undefined8 *)(param_1 + 0xc0);
    local_70 = *(undefined8 *)(param_1 + 200);
    local_68 = *(undefined8 *)(param_1 + 0xd0);
  }
  else {
    local_60 = *(long *)(puVar9 + 0x48);
  }
  if (local_60 == 0) {
    if ((local_ac & 4) != 0) goto LAB_004d3c65;
LAB_004d3e69:
    iVar5 = serverSerializeCtrlDown(puVar9,param_4,&local_c0,&local_c4,&local_ac);
    if (iVar5 != 0) {
      if (local_b8 != 0) {
        rmGpuGroupLockRelease(local_b8,0);
        portMemFree(0);
        goto LAB_004d414d;
      }
LAB_004d4146:
      portMemFree(0);
      goto LAB_004d414d;
    }
    if (local_d5 == '\0') {
      if ((local_ac & 4) == 0) {
        local_d6 = IsGssLegacyCall(param_4);
        if (local_d6 == 0) goto LAB_004d3c79;
        iVar5 = rmapiControlCacheGetUnchecked
                          (param_2,param_3,param_4,local_c0,local_c4,puVar9 + 0x28);
        goto LAB_004d3ee6;
      }
    }
    else {
      if ((local_ac & 4) != 0) {
LAB_004d4433:
        nvAssertFailedNoLog("!(bCacheable && (resCtrlFlags & NVOS54_FLAGS_FINN_SERIALIZED))",
                            "src/kernel/vgpu/rpc.c",0x2b69);
        return 0x40;
      }
      iVar5 = rmapiControlCacheGet(param_2,param_3,param_4,local_c0,local_c4,puVar9 + 0x28);
LAB_004d3ee6:
      if (iVar5 == 0) {
        iVar5 = 0;
        if (local_b8 != 0) {
          iVar5 = 0;
          rmGpuGroupLockRelease(local_b8,0);
          portMemFree(0);
          goto LAB_004d414d;
        }
        goto LAB_004d4146;
      }
    }
    local_d6 = 0;
  }
  else {
    local_ac = *(uint *)(local_60 + 0xc);
    if ((local_ac & 4) == 0) goto LAB_004d3e69;
LAB_004d3c65:
    if (local_d5 != '\0') goto LAB_004d4433;
    local_d6 = 1;
  }
LAB_004d3c79:
  uVar11 = local_c4;
  uStack_100 = 0x4d3c98;
  iVar5 = rpcWriteCommonHeader(lVar1,lVar8,0x4c,local_c4 + 0x28);
  if (iVar5 == 0) {
    iVar5 = uVar11 + 0x48;
    lVar12 = *(long *)(lVar8 + 0x4d8);
    uVar11 = local_b4 >> 0xb & 1;
    *(undefined4 *)(lVar12 + 0x20) = param_2;
    *(undefined4 *)(lVar12 + 0x28) = param_4;
    *(undefined4 *)(lVar12 + 0x24) = param_3;
    *(undefined8 *)(lVar12 + 0x38) = 0;
    *(uint *)(lVar12 + 0x30) = local_c4;
    if ((local_ac & 4) != 0) {
      uVar11 = uVar11 | 2;
    }
    *(uint *)(lVar12 + 0x34) = uVar11;
    if (iVar6 - 0x48U < local_c4) {
      local_e0 = portMemAllocNonPaged(iVar5);
      if (local_e0 == 0) {
        iVar5 = 0x51;
        nvAssertFailedNoLog("large_message_copy != NULL","src/kernel/vgpu/rpc.c",0x2ba7);
        uStack_100 = extraout_RDX_06;
      }
      else {
        uStack_100 = 0x4d4088;
        portMemCopy(local_e0,iVar5,*(undefined8 *)(lVar8 + 0x4d8),0x48);
        lVar12 = local_e0 + 0x20;
        if (local_c4 != 0) goto LAB_004d3f4b;
        if (local_c0 != 0) goto LAB_004d40b1;
LAB_004d3f89:
        iVar6 = _issueRpcLarge(lVar1,lVar8,iVar5,local_e0,1,1);
        iVar5 = *(int *)(lVar12 + 0xc);
        uStack_100 = extraout_RDX_02;
joined_r0x004d3d57:
        iVar7 = iVar5;
        iVar3 = iVar6;
        if (iVar6 == 0) {
          if (iVar5 == 0) {
            if ((local_ac & 4) == 0) {
              if (local_c4 != 0) {
LAB_004d4328:
                portMemCopy(local_c0,local_c4,lVar12 + 0x28,local_c4);
                goto LAB_004d4349;
              }
            }
            else {
LAB_004d4360:
              portMemCopy(*(undefined8 *)(puVar9 + 0x50),*(undefined4 *)(puVar9 + 0x60),
                          lVar12 + 0x28,*(undefined4 *)(lVar12 + 0x10));
              if ((local_d6 == 0) &&
                 (iVar5 = serverDeserializeCtrlUp(puVar9,param_4,&local_c0,&local_c4,&local_ac),
                 iVar5 != 0)) {
                if (local_b8 != 0) {
                  rmGpuGroupLockRelease(local_b8,0);
                }
                portMemFree(local_e0);
                goto LAB_004d414d;
              }
LAB_004d4349:
              iVar7 = *(int *)(lVar12 + 0xc);
              iVar3 = iVar7;
              if (iVar7 != 0) goto LAB_004d3fd2;
            }
            iVar5 = iVar6;
            if (local_d5 == '\0') {
              cVar4 = IsGssLegacyCall(param_4);
              uStack_100 = extraout_RDX_00;
              if ((cVar4 != '\0') && ((local_ac & 4) == 0)) {
                cVar4 = rmapiControlIsCacheable
                                  (*(undefined4 *)(lVar12 + 0x18),*(undefined4 *)(lVar12 + 0x1c),1);
                if ((cVar4 == '\0') || ((*(uint *)(lVar12 + 0x18) & 0x20000) != 0)) {
                  uStack_100 = extraout_RDX_01;
                  iVar5 = 0;
                }
                else {
                  rmapiControlCacheSetUnchecked(param_2,param_3,param_4,lVar12 + 0x28,local_c4);
                  uStack_100 = extraout_RDX_07;
                  iVar5 = 0;
                }
              }
            }
            else {
              rmapiControlCacheSet(param_2,param_3,param_4,lVar12 + 0x28,local_c4);
              uStack_100 = extraout_RDX_05;
            }
            goto LAB_004d40f0;
          }
          if ((*(byte *)(lVar12 + 0x14) & 1) == 0) goto LAB_004d40f0;
          if ((local_ac & 4) != 0) goto LAB_004d4360;
          iVar3 = iVar5;
          if (local_c4 != 0) goto LAB_004d4328;
        }
LAB_004d3fd2:
        iVar5 = iVar3;
        if ((iVar5 - 0x56U < 2) || (*(char *)(lVar8 + 0x2d2c) != '\0')) {
          uVar10 = 1;
        }
        else {
          uVar10 = 3;
        }
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2c16,"rpcRmApiControl_GSP",uVar10,
                     "NVRM: GspRmControl failed: hClient=0x%08x; hObject=0x%08x; cmd=0x%08x; paramsSize=0x%08x; paramsStatus=0x%08x; status=0x%08x\n"
                     ,param_2,param_3,param_4,local_c4,iVar7,iVar5);
        uStack_100 = extraout_RDX_03;
      }
    }
    else {
      lVar12 = lVar12 + 0x20;
      if (local_c4 == 0) {
        if (local_c0 == 0) {
LAB_004d3d25:
          iVar6 = _issueRpcAndWait(lVar1,lVar8);
          local_e0 = 0;
          iVar5 = *(int *)(lVar12 + 0xc);
          uStack_100 = extraout_RDX;
          goto joined_r0x004d3d57;
        }
        local_e0 = 0;
LAB_004d40b1:
        iVar5 = 0x1f;
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2bbf,"rpcRmApiControl_GSP",4,
                     "NVRM: Bad params: ptr %p size: 0x%x\n",local_c0,0);
      }
      else {
        local_e0 = 0;
LAB_004d3f4b:
        if (local_c0 == 0) {
          iVar5 = 0x1f;
          uStack_100 = 0;
        }
        else {
          auVar13 = portMemCopy(lVar12 + 0x28);
          uStack_100 = auVar13._8_8_;
          if (auVar13._0_8_ != 0) {
            if (local_e0 != 0) goto LAB_004d3f89;
            goto LAB_004d3d25;
          }
          iVar5 = 2;
        }
      }
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar5,
               "rpcWriteCommonHeader(pGpu, pRpc, NV_VGPU_MSG_FUNCTION_GSP_RM_CONTROL, rpc_params_size)"
               ,"src/kernel/vgpu/rpc.c",0x2b90);
    local_e0 = 0;
    uStack_100 = extraout_RDX_04;
  }
LAB_004d40f0:
  if (local_b8 != 0) {
    rmGpuGroupLockRelease(local_b8,0,uStack_100);
  }
  portMemFree(local_e0);
  if (((local_d6 ^ 1) & 1) == 0 && puVar9 != local_a8) {
    return iVar5;
  }
LAB_004d414d:
  serverFreeSerializeStructures(puVar9,lVar2);
  return iVar5;
}


// ===== 004d4480 rpcRmApiAlloc_GSP =====

int rpcRmApiAlloc_GSP(long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     int param_5,long param_6)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  long lVar9;
  ulong uVar10;
  undefined8 uVar12;
  long lVar13;
  undefined8 uVar14;
  char *pcVar15;
  long unaff_retaddr;
  long local_c0;
  char local_b5;
  uint local_b4;
  int local_b0;
  int local_ac;
  undefined8 local_a8 [15];
  ulong uVar11;
  
  lVar3 = *(long *)(param_1 + 0xe0);
  local_c0 = param_6;
  lVar9 = gpuGetRpc(lVar3);
  lVar5 = local_c0;
  uVar10 = 0;
  do {
    uVar7 = (int)uVar10 + 0x20;
    uVar11 = (ulong)uVar7;
    *(undefined8 *)((long)local_a8 + uVar10) = 0;
    *(undefined8 *)((long)local_a8 + uVar10 + 8) = 0;
    *(undefined8 *)((long)local_a8 + uVar10 + 0x10) = 0;
    *(undefined8 *)((long)local_a8 + uVar10 + 0x18) = 0;
    uVar10 = uVar11;
  } while (uVar7 < 0x60);
  *(undefined8 *)((long)local_a8 + uVar11) = 0;
  uVar1 = *(undefined4 *)(lVar3 + 0x7a4);
  *(undefined8 *)((long)local_a8 + uVar11 + 8) = 0;
  local_b4 = 0;
  iVar2 = *(int *)(lVar9 + 0x4f0);
  local_ac = 0;
  cVar6 = rmDeviceGpuLockIsOwner(uVar1);
  if (cVar6 == '\0') {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2c4a,"rpcRmApiAlloc_GSP",3,
                 "NVRM: Calling RPC RmAlloc 0x%04x without adequate locks!\n",param_5);
    if (previousRetAddr_5 != unaff_retaddr) {
      previousRetAddr_5 = unaff_retaddr;
      osAssertFailed();
    }
    nvAssertFailedNoLog("RPC locking violation - see kernel_log.txt","src/kernel/vgpu/rpc.c",0x2c4b)
    ;
    iVar8 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar3 + 0x7a4),0,2,0x8002,&local_ac);
    if (iVar8 != 0) {
      nvAssertOkFailedNoLog
                (iVar8,
                 "rmGpuGroupLockAcquire(pGpu->gpuInstance, GPU_LOCK_GRP_SUBDEVICE, GPU_LOCK_FLAGS_SAFE_LOCK_UPGRADE, RM_LOCK_MODULES_RPC, &gpuMaskRelease)"
                 ,"src/kernel/vgpu/rpc.c",0x2c4c);
      return iVar8;
    }
  }
  iVar8 = rmapiGetClassAllocParamSize(&local_b0,local_c0,&local_b5,param_5);
  if (iVar8 != 0) {
    nvAssertOkFailedNoLog
              (iVar8,
               "rmapiGetClassAllocParamSize(&paramsSize, NV_PTR_TO_NvP64(pAllocParams), &bNullAllowed, hClass)"
               ,"src/kernel/vgpu/rpc.c",0x2c51);
    goto LAB_004d4669;
  }
  if ((param_5 == 0) || (param_5 == 0x41)) {
    local_b0 = 0x78;
  }
  if ((local_c0 == 0) && (local_b5 == '\0')) {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2c5f,"rpcRmApiAlloc_GSP",4,
                 "NVRM: NULL allocation params not allowed for class 0x%x\n",param_5);
    iVar8 = 0x1f;
    goto LAB_004d4669;
  }
  iVar8 = rpcWriteCommonHeader(lVar3,lVar9,0x67,0x20);
  if (iVar8 != 0) {
    nvAssertOkFailedNoLog
              (iVar8,
               "rpcWriteCommonHeader(pGpu, pRpc, NV_VGPU_MSG_FUNCTION_GSP_RM_ALLOC, sizeof(rpc_gsp_rm_alloc_v03_00))"
               ,"src/kernel/vgpu/rpc.c",0x2c64);
    goto LAB_004d4669;
  }
  lVar4 = *(long *)(lVar9 + 0x4d8);
  *(undefined4 *)(lVar4 + 0x20) = param_2;
  *(undefined4 *)(lVar4 + 0x28) = param_4;
  *(undefined4 *)(lVar4 + 0x24) = param_3;
  *(int *)(lVar4 + 0x2c) = param_5;
  *(undefined4 *)(lVar4 + 0x38) = 0;
  if (local_b0 == 0) {
    *(undefined4 *)(lVar4 + 0x34) = 0;
LAB_004d45fc:
    uVar12 = _issueRpcAndWait(lVar3,lVar9);
    if ((int)uVar12 != 0) {
      if (*(char *)(lVar9 + 0x2d2c) == '\0') {
        uVar14 = 4;
      }
      else {
        uVar14 = 1;
      }
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2c96,"rpcRmApiAlloc_GSP",uVar14,
                   "NVRM: GspRmAlloc failed: hClient=0x%08x; hParent=0x%08x; hObject=0x%08x; hClass=0x%08x; paramsSize=0x%08x; paramsStatus=0x%08x; status=0x%08x\n"
                   ,param_2,param_3,param_4,param_5,local_b0,*(undefined4 *)(lVar4 + 0x30),uVar12);
      iVar8 = *(int *)(lVar4 + 0x30);
      goto LAB_004d4669;
    }
    iVar8 = serverDeserializeAllocUp(local_a8,param_5,&local_c0,&local_b0,&local_b4);
    if (iVar8 == 0) {
      if (((local_b4 & 2) == 0) && (iVar8 = 0, local_b0 != 0)) {
        portMemCopy(local_c0,local_b0,lVar4 + 0x40,local_b0);
        iVar8 = 0;
      }
      goto LAB_004d4669;
    }
    uVar12 = 0x2c8e;
    pcVar15 = "serverDeserializeAllocUp(&callContext, hClass, &pAllocParams, &paramsSize, &flags)";
  }
  else {
    iVar8 = serverSerializeAllocDown(local_a8,param_5,&local_c0,&local_b0,&local_b4);
    uVar12 = 0x2c75;
    pcVar15 = "serverSerializeAllocDown(&callContext, hClass, &pAllocParams, &paramsSize, &flags)";
    if (iVar8 == 0) {
      if ((local_b4 & 2) != 0) {
        *(uint *)(lVar4 + 0x38) = *(uint *)(lVar4 + 0x38) | 2;
      }
      lVar13 = portMemCopy(lVar4 + 0x40,iVar2 + -0x40,local_c0,local_b0,0x2c75);
      *(int *)(lVar4 + 0x34) = local_b0;
      if (lVar13 == 0) {
        iVar8 = 2;
        goto LAB_004d4669;
      }
      goto LAB_004d45fc;
    }
  }
  nvCheckOkFailedNoLog(1,iVar8,pcVar15,"src/kernel/vgpu/rpc.c",uVar12);
LAB_004d4669:
  if (local_ac != 0) {
    rmGpuGroupLockRelease(local_ac,0);
  }
  serverFreeSerializeStructures(local_a8,lVar5);
  return iVar8;
}


// ===== 004d4990 rpcRmApiDupObject_GSP =====

int rpcRmApiDupObject_GSP
              (long param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
              undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  char cVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  long unaff_retaddr;
  int local_3c [3];
  
  lVar2 = *(long *)(param_1 + 0xe0);
  lVar6 = gpuGetRpc(lVar2);
  local_3c[0] = 0;
  cVar4 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar2 + 0x7a4));
  if (cVar4 == '\0') {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2cb9,"rpcRmApiDupObject_GSP",3,
                 "NVRM: Calling RPC RmDupObject without adequate locks!\n");
    if (previousRetAddr_3 != unaff_retaddr) {
      previousRetAddr_3 = unaff_retaddr;
      osAssertFailed();
    }
    nvAssertFailedNoLog("RPC locking violation - see kernel_log.txt","src/kernel/vgpu/rpc.c",0x2cba)
    ;
    iVar5 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar2 + 0x7a4),0,2,0x8002,local_3c);
    if (iVar5 != 0) {
      nvAssertOkFailedNoLog
                (iVar5,
                 "rmGpuGroupLockAcquire(pGpu->gpuInstance, GPU_LOCK_GRP_SUBDEVICE, GPU_LOCK_FLAGS_SAFE_LOCK_UPGRADE, RM_LOCK_MODULES_RPC, &gpuMaskRelease)"
                 ,"src/kernel/vgpu/rpc.c",0x2cbb);
      return iVar5;
    }
  }
  iVar5 = rpcWriteCommonHeader(lVar2,lVar6,0x15,0x1c);
  if (iVar5 == 0) {
    lVar3 = *(long *)(lVar6 + 0x4d8);
    *(undefined4 *)(lVar3 + 0x20) = param_2;
    *(undefined4 *)(lVar3 + 0x24) = param_3;
    uVar1 = *param_4;
    *(undefined4 *)(lVar3 + 0x34) = param_7;
    *(undefined4 *)(lVar3 + 0x28) = uVar1;
    *(undefined4 *)(lVar3 + 0x2c) = param_5;
    *(undefined4 *)(lVar3 + 0x30) = param_6;
    iVar5 = _issueRpcAndWait(lVar2,lVar6);
    if (iVar5 != 0) {
      if (*(char *)(lVar6 + 0x2d2c) == '\0') {
        uVar7 = 4;
      }
      else {
        uVar7 = 1;
      }
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2ccf,"rpcRmApiDupObject_GSP",uVar7,
                   "NVRM: GspRmDupObject failed: hClient=0x%08x; hParent=0x%08x; hObject=0x%08x; hClientSrc=0x%08x; hObjectSrc=0x%08x; flags=0x%08x; paramsStatus=0x%08x; status=0x%08x\n"
                   ,param_2,param_3,*param_4,param_5,param_6,param_7,*(undefined4 *)(lVar3 + 0x38),
                   iVar5);
    }
  }
  if (local_3c[0] != 0) {
    rmGpuGroupLockRelease(local_3c[0],0);
  }
  return iVar5;
}


// ===== 004d4bc0 rpcRmApiFree_GSP =====

int rpcRmApiFree_GSP(long param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  long unaff_retaddr;
  int local_3c [3];
  
  lVar1 = *(long *)(param_1 + 0xe0);
  lVar5 = gpuGetRpc(lVar1);
  local_3c[0] = 0;
  cVar3 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4));
  if (cVar3 == '\0') {
    nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2cea,"rpcRmApiFree_GSP",3,
                 "NVRM: Calling RPC RmFree without adequate locks!\n");
    if (previousRetAddr_1 != unaff_retaddr) {
      previousRetAddr_1 = unaff_retaddr;
      osAssertFailed();
    }
    nvAssertFailedNoLog("RPC locking violation - see kernel_log.txt","src/kernel/vgpu/rpc.c",0x2ceb)
    ;
    iVar4 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar1 + 0x7a4),0,2,0x8002,local_3c);
    if (iVar4 != 0) {
      nvAssertOkFailedNoLog
                (iVar4,
                 "rmGpuGroupLockAcquire(pGpu->gpuInstance, GPU_LOCK_GRP_SUBDEVICE, GPU_LOCK_FLAGS_SAFE_LOCK_UPGRADE, RM_LOCK_MODULES_RPC, &gpuMaskRelease)"
                 ,"src/kernel/vgpu/rpc.c",0x2cec);
      return iVar4;
    }
  }
  iVar4 = rpcWriteCommonHeader(lVar1,lVar5,10,0x10);
  if (iVar4 == 0) {
    lVar2 = *(long *)(lVar5 + 0x4d8);
    *(undefined4 *)(lVar2 + 0x20) = param_2;
    *(undefined4 *)(lVar2 + 0x24) = 0;
    *(undefined4 *)(lVar2 + 0x28) = param_3;
    iVar4 = _issueRpcAndWait(lVar1,lVar5);
    if (iVar4 != 0) {
      if (*(char *)(lVar5 + 0x2d2c) == '\0') {
        uVar6 = 4;
      }
      else {
        uVar6 = 1;
      }
      nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2cfd,"rpcRmApiFree_GSP",uVar6,
                   "NVRM: GspRmFree failed: hClient=0x%08x; hObject=0x%08x; paramsStatus=0x%08x; status=0x%08x\n"
                   ,param_2,param_3,*(undefined4 *)(lVar2 + 0x2c),iVar4);
    }
  }
  if (local_3c[0] != 0) {
    rmGpuGroupLockRelease(local_3c[0],0);
  }
  return iVar4;
}


// ===== 004d4da0 rpcEccNotifierWriteAck_v23_05 =====

undefined8 rpcEccNotifierWriteAck_v23_05(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if (*(char *)(param_1 + 0x909) == '\0') {
    return 0x56;
  }
  uVar1 = rpcWriteCommonHeader(param_1,param_2,0xca,0);
  if ((int)uVar1 == 0) {
    uVar1 = _issueRpcAsync(param_1,param_2);
    return uVar1;
  }
  return uVar1;
}


// ===== 004d4e00 rpcCtrlCmdInternalGpuStartFabricProbe_v25_09 =====

void rpcCtrlCmdInternalGpuStartFabricProbe_v25_09
               (undefined8 param_1,long param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = rpcWriteCommonHeader(param_1,param_2,0xcd,1);
  if (iVar1 != 0) {
    return;
  }
  *(char *)(*(long *)(param_2 + 0x4d8) + 0x20) = (char)*param_3;
  _issueRpcAndWait(param_1,param_2);
  return;
}


// ===== 004d4e70 rpcCtrlNvlinkGetInbandReceivedData_v25_0C =====

int rpcCtrlNvlinkGetInbandReceivedData_v25_0C
              (undefined8 param_1,long param_2,long param_3,short param_4,undefined8 param_5)

{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_4 == 1) {
    uVar2 = 0x8a;
  }
  else {
    uVar2 = 0x48;
    if (param_4 != 3) {
      return 0x56;
    }
  }
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar3 = rpcWriteCommonHeader(param_1,param_2,0xce,uVar2);
  if (iVar3 == 0) {
    *(short *)(lVar1 + 0x20) = param_4;
    iVar3 = _issueRpcAndWait(param_1,param_2);
    if (iVar3 == 0) {
      if (*(uint *)(lVar1 + 0x24) < 0x1401) {
        *(bool *)param_5 = *(char *)(lVar1 + 0x22) != '\0';
        uVar2 = *(undefined4 *)(lVar1 + 0x24);
        *(undefined4 *)(param_3 + 0x1400) = uVar2;
        portMemCopy(param_3,uVar2,lVar1 + 0x28,uVar2);
      }
      else {
        iVar3 = 0x51;
      }
    }
  }
  return iVar3;
}


// ===== 004d4f50 rpcCtrlCmdNvlinkInbandSendData_v26_05 =====

void rpcCtrlCmdNvlinkInbandSendData_v26_05(undefined8 param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  
  lVar2 = *(long *)(param_2 + 0x4d8);
  iVar3 = rpcWriteCommonHeader(param_1,param_2,0xd3,0x404);
  if (iVar3 != 0) {
    return;
  }
  uVar1 = *(undefined4 *)(param_3 + 0x1400);
  *(undefined4 *)(lVar2 + 0x420) = uVar1;
  portMemCopy(lVar2 + 0x20,uVar1,param_3,uVar1);
  _issueRpcAndWait(param_1,param_2);
  return;
}


// ===== 004d4fd0 rpcCtrlCmdInternalControlGspTrace_v28_00 =====

void rpcCtrlCmdInternalControlGspTrace_v28_00(undefined8 param_1,long param_2,undefined8 *param_3)

{
  int iVar1;
  
  iVar1 = rpcWriteCommonHeader(param_1,param_2,0xd5,0x20);
  if (iVar1 != 0) {
    return;
  }
  *(int *)(*(long *)(param_2 + 0x4d8) + 0x24) = (int)*param_3;
  *(undefined8 *)(*(long *)(param_2 + 0x4d8) + 0x30) = param_3[1];
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x20) = *(undefined4 *)(param_3 + 2);
  *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x28) = *(undefined4 *)((long)param_3 + 0x14);
  *(undefined1 *)(*(long *)(param_2 + 0x4d8) + 0x38) = *(undefined1 *)(param_3 + 3);
  _issueRpcAndWait(param_1,param_2);
  return;
}


// ===== 004d5080 rpcCtrlSubdeviceGetVgpuHeapStats_v28_03 =====

undefined8 rpcCtrlSubdeviceGetVgpuHeapStats_v28_03(long param_1,long param_2,undefined8 *param_3)

{
  long lVar1;
  undefined8 uVar2;
  
  if ((*(char *)(param_1 + 0x908) != '\0') && (*(char *)(param_1 + 0x4a4e) != '\0')) {
    if (param_3 != (undefined8 *)0x0) {
      lVar1 = *(long *)(param_2 + 0x4d8);
      *(undefined8 *)(lVar1 + 0x28) = *param_3;
      *(undefined8 *)(lVar1 + 0x30) = param_3[1];
      *(undefined8 *)(lVar1 + 0x38) = param_3[2];
      *(undefined4 *)(lVar1 + 0x40) = *(undefined4 *)(param_3 + 3);
      *(undefined4 *)(lVar1 + 0x44) = *(undefined4 *)((long)param_3 + 0x1c);
      uVar2 = rpcWriteCommonHeader(param_1,param_2,0xd7,0x28);
      if ((int)uVar2 == 0) {
        portMemSet(*(long *)(param_2 + 0x4d8) + 0x20,0,0x28);
        uVar2 = _issueRpcAndWait(param_1,param_2);
        if ((int)uVar2 == 0) {
          *param_3 = *(undefined8 *)(lVar1 + 0x28);
          param_3[1] = *(undefined8 *)(lVar1 + 0x30);
          param_3[2] = *(undefined8 *)(lVar1 + 0x38);
          *(undefined4 *)(param_3 + 3) = *(undefined4 *)(lVar1 + 0x40);
          *(undefined4 *)((long)param_3 + 0x1c) = *(undefined4 *)(lVar1 + 0x44);
        }
      }
      return uVar2;
    }
    return 0x1f;
  }
  return 0x56;
}


// ===== 004d5170 rpcCtrlSubdeviceGetVgpuHeapStats_v28_06 =====

undefined8 rpcCtrlSubdeviceGetVgpuHeapStats_v28_06(long param_1,long param_2,undefined8 *param_3)

{
  long lVar1;
  undefined8 uVar2;
  
  if ((*(char *)(param_1 + 0x908) != '\0') && (*(char *)(param_1 + 0x4a4e) != '\0')) {
    if (param_3 != (undefined8 *)0x0) {
      lVar1 = *(long *)(param_2 + 0x4d8);
      *(undefined8 *)(lVar1 + 0x28) = *param_3;
      *(undefined8 *)(lVar1 + 0x30) = param_3[1];
      *(undefined8 *)(lVar1 + 0x38) = param_3[2];
      *(undefined4 *)(lVar1 + 0x40) = *(undefined4 *)(param_3 + 3);
      *(undefined4 *)(lVar1 + 0x44) = *(undefined4 *)((long)param_3 + 0x1c);
      *(undefined8 *)(lVar1 + 0x48) = param_3[4];
      uVar2 = rpcWriteCommonHeader(param_1,param_2,0xd7,0x30);
      if ((int)uVar2 == 0) {
        portMemSet(*(long *)(param_2 + 0x4d8) + 0x20,0,0x30);
        uVar2 = _issueRpcAndWait(param_1,param_2);
        if ((int)uVar2 == 0) {
          *param_3 = *(undefined8 *)(lVar1 + 0x28);
          param_3[1] = *(undefined8 *)(lVar1 + 0x30);
          param_3[2] = *(undefined8 *)(lVar1 + 0x38);
          *(undefined4 *)(param_3 + 3) = *(undefined4 *)(lVar1 + 0x40);
          *(undefined4 *)((long)param_3 + 0x1c) = *(undefined4 *)(lVar1 + 0x44);
          param_3[4] = *(undefined8 *)(lVar1 + 0x48);
        }
      }
      return uVar2;
    }
    return 0x1f;
  }
  return 0x56;
}


// ===== 004d5270 rpcCtrlSubdeviceGetLibosHeapStats_v29_02 =====

int rpcCtrlSubdeviceGetLibosHeapStats_v29_02(long param_1,long param_2,long param_3)

{
  int iVar1;
  byte bVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  
  if ((*(char *)(param_1 + 0x908) == '\0') || (*(char *)(param_1 + 0x4a4e) == '\0')) {
    return 0x56;
  }
  if ((param_3 != 0) && (bVar2 = *(byte *)(param_3 + 0x408), bVar2 < 0x41)) {
    lVar3 = *(long *)(param_2 + 0x4d8);
    *(byte *)(lVar3 + 0x430) = bVar2;
    *(undefined8 *)(lVar3 + 0x428) = *(undefined8 *)(param_3 + 0x400);
    if (bVar2 != 0) {
      lVar4 = lVar3 + 0x28;
      bVar2 = 0;
      lVar5 = param_3;
      do {
        portMemCopy(lVar4,0x10,lVar5,0x10);
        bVar2 = bVar2 + 1;
        lVar4 = lVar4 + 0x10;
        lVar5 = lVar5 + 0x10;
      } while (bVar2 < *(byte *)(lVar3 + 0x430));
    }
    iVar1 = rpcWriteCommonHeader(param_1,param_2,0xd8,0x418);
    if (iVar1 == 0) {
      portMemSet(*(long *)(param_2 + 0x4d8) + 0x20,0,0x418);
      iVar1 = _issueRpcAndWait(param_1,param_2);
      if (iVar1 == 0) {
        bVar2 = *(byte *)(lVar3 + 0x430);
        if (0x40 < bVar2) {
          return 0x1f;
        }
        *(byte *)(param_3 + 0x408) = bVar2;
        *(undefined8 *)(param_3 + 0x400) = *(undefined8 *)(lVar3 + 0x428);
        if (bVar2 != 0) {
          lVar4 = 0;
          lVar3 = lVar3 + 0x28;
          do {
            lVar5 = lVar4 * 0x10;
            lVar4 = lVar4 + 1;
            portMemCopy(lVar5 + param_3,0x10,lVar3,0x10);
            lVar3 = lVar3 + 0x10;
          } while ((byte)lVar4 < *(byte *)(param_3 + 0x408));
        }
      }
    }
    return iVar1;
  }
  return 0x1f;
}


// ===== 004d5440 rpcCtrlCmdInternalGpuCheckCtsIdValid_v2B_12 =====

int rpcCtrlCmdInternalGpuCheckCtsIdValid_v2B_12
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
              undefined4 *param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_2 + 0x4d8);
  iVar2 = rpcWriteCommonHeader(param_1,param_2,0xe3,0x1c);
  if (iVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    iVar2 = 0x1f;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    if (param_5 != (undefined4 *)0x0) {
      *(undefined4 *)(lVar1 + 0x2c) = *param_5;
      *(undefined1 *)(lVar1 + 0x30) = *(undefined1 *)(param_5 + 1);
      *(undefined4 *)(lVar1 + 0x34) = param_5[2];
      iVar2 = _issueRpcAndWait(param_1,param_2);
      if (iVar2 == 0) {
        *(undefined1 *)(param_5 + 3) = *(undefined1 *)(lVar1 + 0x38);
      }
      else {
        nvDbg_Printf("src/kernel/vgpu/rpc.c",0x2e2c,"rpcCtrlCmdInternalGpuCheckCtsIdValid_v2B_12",4,
                     "NVRM: RPC to check CTS ID validity failed with error 0x%x\n");
      }
    }
  }
  return iVar2;
}


// ===== 004d5510 rpcInitGspTraceCrashBuffer_v03_00 =====

undefined8
rpcInitGspTraceCrashBuffer_v03_00(long param_1,long param_2,undefined8 param_3,undefined4 param_4)

{
  undefined8 uVar1;
  
  if (*(char *)(param_1 + 0x909) == '\0') {
    return 0x56;
  }
  uVar1 = rpcWriteCommonHeader(param_1,param_2,0xe4,0x10);
  if ((int)uVar1 == 0) {
    *(undefined8 *)(*(long *)(param_2 + 0x4d8) + 0x20) = param_3;
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x28) = param_4;
    uVar1 = _issueRpcAndWait(param_1);
    return uVar1;
  }
  return uVar1;
}


// ===== 004d5590 deserialize_NV2080_CTRL_FB_GET_LTC_INFO_FOR_FBP_PARAMS_v15_03 =====

undefined8 deserialize_NV2080_CTRL_FB_GET_LTC_INFO_FOR_FBP_PARAMS_v15_03(void)

{
  int *in_RCX;
  
  if (in_RCX != (int *)0x0) {
    *in_RCX = *in_RCX + 0xc;
    return 0;
  }
  return 0x1f;
}


// ===== 004d55b0 __pfx_deserialize_VGPU_FB_GET_LTC_INFO_FOR_FBP_v1A_0D =====

undefined8
__pfx_deserialize_VGPU_FB_GET_LTC_INFO_FOR_FBP_v1A_0D
          (undefined1 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined1 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0xc0)) {
      return 2;
    }
    puVar2 = (undefined1 *)(param_2 + (ulong)uVar1);
    puVar3 = puVar2;
    do {
      puVar4 = puVar3 + 0xc;
      *param_1 = *puVar3;
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(puVar3 + 4);
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(puVar3 + 8);
      puVar3 = puVar4;
      param_1 = param_1 + 0x14;
    } while (puVar4 != puVar2 + 0xc0);
  }
  *param_4 = *param_4 + 0xc0;
  return 0;
}


// ===== 004d55c0 deserialize_VGPU_FB_GET_LTC_INFO_FOR_FBP_v1A_0D =====

undefined8
deserialize_VGPU_FB_GET_LTC_INFO_FOR_FBP_v1A_0D
          (undefined1 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined1 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0xc0)) {
      return 2;
    }
    puVar2 = (undefined1 *)(param_2 + (ulong)uVar1);
    puVar3 = puVar2;
    do {
      puVar4 = puVar3 + 0xc;
      *param_1 = *puVar3;
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(puVar3 + 4);
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(puVar3 + 8);
      puVar3 = puVar4;
      param_1 = param_1 + 0x14;
    } while (puVar4 != puVar2 + 0xc0);
  }
  *param_4 = *param_4 + 0xc0;
  return 0;
}


// ===== 004d5650 __pfx_deserialize_VGPU_FB_GET_LTC_INFO_FOR_FBP_v2D_03 =====

undefined8
__pfx_deserialize_VGPU_FB_GET_LTC_INFO_FOR_FBP_v2D_03
          (undefined1 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined1 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x120)) {
      return 2;
    }
    puVar2 = (undefined1 *)(param_2 + (ulong)uVar1);
    puVar3 = puVar2;
    do {
      puVar4 = puVar3 + 0xc;
      *param_1 = *puVar3;
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(puVar3 + 4);
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(puVar3 + 8);
      puVar3 = puVar4;
      param_1 = param_1 + 0x14;
    } while (puVar4 != puVar2 + 0x120);
  }
  *param_4 = *param_4 + 0x120;
  return 0;
}


// ===== 004d5660 deserialize_VGPU_FB_GET_LTC_INFO_FOR_FBP_v2D_03 =====

undefined8
deserialize_VGPU_FB_GET_LTC_INFO_FOR_FBP_v2D_03
          (undefined1 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined1 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x120)) {
      return 2;
    }
    puVar2 = (undefined1 *)(param_2 + (ulong)uVar1);
    puVar3 = puVar2;
    do {
      puVar4 = puVar3 + 0xc;
      *param_1 = *puVar3;
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(puVar3 + 4);
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(puVar3 + 8);
      puVar3 = puVar4;
      param_1 = param_1 + 0x14;
    } while (puVar4 != puVar2 + 0x120);
  }
  *param_4 = *param_4 + 0x120;
  return 0;
}


// ===== 004d56f0 __pfx_deserialize_NV2080_CTRL_MC_GET_ENGINE_NOTIFICATION_INTR_VECTORS_PARAMS_v16_00 =====

undefined8
__pfx_deserialize_NV2080_CTRL_MC_GET_ENGINE_NOTIFICATION_INTR_VECTORS_PARAMS_v16_00
          (uint *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  long lVar2;
  uint *puVar3;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (uint *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x804)) {
      return 2;
    }
    puVar3 = (uint *)(param_2 + (ulong)uVar1);
    uVar1 = *puVar3;
    *param_1 = uVar1;
    if (uVar1 != 0) {
      lVar2 = 0;
      do {
        *(undefined4 *)((long)param_1 + lVar2 + 4) = *(undefined4 *)((long)puVar3 + lVar2 + 4);
        *(undefined4 *)((long)param_1 + lVar2 + 8) = *(undefined4 *)((long)puVar3 + lVar2 + 8);
        lVar2 = lVar2 + 8;
      } while ((ulong)uVar1 << 3 != lVar2);
    }
  }
  *param_4 = *param_4 + 0x804;
  return 0;
}


// ===== 004d5700 deserialize_NV2080_CTRL_MC_GET_ENGINE_NOTIFICATION_INTR_VECTORS_PARAMS_v16_00 =====

undefined8
deserialize_NV2080_CTRL_MC_GET_ENGINE_NOTIFICATION_INTR_VECTORS_PARAMS_v16_00
          (uint *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  long lVar2;
  uint *puVar3;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (uint *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x804)) {
      return 2;
    }
    puVar3 = (uint *)(param_2 + (ulong)uVar1);
    uVar1 = *puVar3;
    *param_1 = uVar1;
    if (uVar1 != 0) {
      lVar2 = 0;
      do {
        *(undefined4 *)((long)param_1 + lVar2 + 4) = *(undefined4 *)((long)puVar3 + lVar2 + 4);
        *(undefined4 *)((long)param_1 + lVar2 + 8) = *(undefined4 *)((long)puVar3 + lVar2 + 8);
        lVar2 = lVar2 + 8;
      } while ((ulong)uVar1 << 3 != lVar2);
    }
  }
  *param_4 = *param_4 + 0x804;
  return 0;
}


// ===== 004d5780 deserialize_NV2080_CTRL_MC_GET_INTR_CATEGORY_SUBTREE_MAP_PARAMS_v2B_0A =====

undefined8
deserialize_NV2080_CTRL_MC_GET_INTR_CATEGORY_SUBTREE_MAP_PARAMS_v2B_0A
          (long param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  long lVar2;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if (uVar1 <= param_3) {
      lVar2 = 0;
      if ((ulong)uVar1 + 0x38 <= (ulong)param_3) {
        do {
          *(undefined8 *)(param_1 + lVar2) = *(undefined8 *)(param_2 + (ulong)uVar1 + lVar2);
          lVar2 = lVar2 + 8;
        } while (lVar2 != 0x38);
        goto LAB_004d57d2;
      }
    }
    return 2;
  }
LAB_004d57d2:
  *param_4 = *param_4 + 0x38;
  return 0;
}


// ===== 004d5800 deserialize_NV2080_CTRL_MC_GET_STATIC_INTR_TABLE_PARAMS_v1E_09 =====

undefined8
deserialize_NV2080_CTRL_MC_GET_STATIC_INTR_TABLE_PARAMS_v1E_09
          (uint *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (uint *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x204)) {
      return 2;
    }
    puVar2 = (uint *)(param_2 + (ulong)uVar1);
    uVar1 = *puVar2;
    *param_1 = uVar1;
    if (uVar1 != 0) {
      puVar3 = puVar2;
      puVar5 = param_1 + 1;
      do {
        puVar4 = puVar3 + 4;
        *puVar5 = puVar3[1];
        puVar5[1] = puVar3[2];
        puVar5[2] = puVar3[3];
        puVar5[3] = *puVar4;
        puVar3 = puVar4;
        puVar5 = puVar5 + 4;
      } while (puVar4 != puVar2 + (ulong)uVar1 * 4);
    }
  }
  *param_4 = *param_4 + 0x204;
  return 0;
}


// ===== 004d5890 deserialize_VGPU_FIFO_GET_DEVICE_INFO_TABLE_v1A_07 =====

undefined8
deserialize_VGPU_FIFO_GET_DEVICE_INFO_TABLE_v1A_07
          (long param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  long lVar2;
  undefined4 *puVar3;
  long lVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x6460)) {
      return 2;
    }
    puVar3 = (undefined4 *)(param_2 + 0xc84 + (ulong)uVar1);
    param_1 = param_1 + 0xc;
    lVar4 = 0;
    do {
      *(undefined4 *)(param_1 + -0xc) = puVar3[-0x321];
      *(undefined4 *)(param_1 + -8) = *puVar3;
      *(undefined1 *)(param_1 + -4) = *(undefined1 *)(puVar3 + 1);
      lVar2 = param_1;
      puVar5 = puVar3 + -800;
      do {
        portMemCopy(lVar2,0x40,puVar5,0x40);
        portMemCopy(lVar2 + 0x40,8,puVar5 + 0x10,8);
        portMemCopy(lVar2 + 0x48,8,puVar5 + 0x12,8);
        puVar6 = puVar5 + 0x19;
        portMemCopy(lVar2 + 0x54,0x10,puVar5 + 0x15,0x10);
        *(undefined4 *)(lVar2 + 0x50) = puVar5[0x14];
        lVar2 = lVar2 + 100;
        puVar5 = puVar6;
      } while (puVar3 != puVar6);
      lVar4 = lVar4 + 0xc8c;
      param_1 = param_1 + 0xc8c;
      puVar3 = puVar3 + 0x323;
    } while (lVar4 != 0x6460);
  }
  *param_4 = *param_4 + 0x6460;
  return 0;
}


// ===== 004d5a00 deserialize_VGPU_FB_GET_DYNAMIC_BLACKLISTED_PAGES_v1A_07 =====

undefined8
deserialize_VGPU_FB_GET_DYNAMIC_BLACKLISTED_PAGES_v1A_07
          (long param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x2080)) {
      return 2;
    }
    param_2 = param_2 + (ulong)uVar1;
    puVar6 = (undefined1 *)(param_1 + 8);
    puVar5 = (undefined1 *)(param_2 + 0x408);
    do {
      *(undefined4 *)(puVar6 + 0x3fc) = *(undefined4 *)(puVar5 + -4);
      *(undefined4 *)(puVar6 + 0x3f8) = *(undefined4 *)(puVar5 + -8);
      puVar6[0x400] = *puVar5;
      puVar2 = puVar5 + -0x400;
      puVar4 = puVar6;
      do {
        puVar3 = puVar2 + 0x10;
        *(undefined8 *)(puVar4 + -8) = *(undefined8 *)(puVar2 + -8);
        *puVar4 = *puVar2;
        puVar2 = puVar3;
        puVar4 = puVar4 + 0x10;
      } while (puVar3 != puVar5);
      puVar5 = puVar5 + 0x410;
      puVar6 = puVar6 + 0x410;
    } while (puVar5 != (undefined1 *)(param_2 + 0x2488));
  }
  *param_4 = *param_4 + 0x2080;
  return 0;
}


// ===== 004d5b00 deserialize_NV2080_CTRL_BUS_GET_INFO_V2_PARAMS_v1C_09 =====

undefined8
deserialize_NV2080_CTRL_BUS_GET_INFO_V2_PARAMS_v1C_09
          (uint *param_1,long param_2,uint param_3,uint *param_4)

{
  ulong uVar1;
  uint uVar2;
  uint *puVar3;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (uint *)0x0) && (param_2 != 0)) {
    uVar2 = *param_4;
    if ((param_3 < uVar2) || ((ulong)param_3 < (ulong)uVar2 + 0x1a4)) {
      return 2;
    }
    puVar3 = (uint *)(param_2 + (ulong)uVar2);
    uVar2 = *puVar3;
    *param_1 = uVar2;
    if (0x34 < uVar2) {
      return 0x5b;
    }
    if (uVar2 != 0) {
      uVar2 = 0;
      do {
        uVar1 = (ulong)uVar2;
        uVar2 = uVar2 + 1;
        param_1[uVar1 * 2 + 1] = puVar3[uVar1 * 2 + 1];
        param_1[uVar1 * 2 + 2] = puVar3[uVar1 * 2 + 2];
      } while (uVar2 < *puVar3);
    }
  }
  *param_4 = *param_4 + 0x1a4;
  return 0;
}


// ===== 004d5b90 deserialize_NV2080_CTRL_GR_GET_SM_ISSUE_RATE_MODIFIER_PARAMS_v1A_1F =====

undefined8
deserialize_NV2080_CTRL_GR_GET_SM_ISSUE_RATE_MODIFIER_PARAMS_v1A_1F
          (undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x20)) {
      return 2;
    }
    puVar2 = (undefined4 *)(param_2 + (ulong)uVar1);
    *param_1 = *puVar2;
    *(undefined8 *)(param_1 + 2) = *(undefined8 *)(puVar2 + 2);
    *(undefined1 *)(param_1 + 4) = *(undefined1 *)(puVar2 + 4);
    *(undefined1 *)((long)param_1 + 0x11) = *(undefined1 *)((long)puVar2 + 0x11);
    *(undefined1 *)((long)param_1 + 0x12) = *(undefined1 *)((long)puVar2 + 0x12);
    *(undefined1 *)((long)param_1 + 0x13) = *(undefined1 *)((long)puVar2 + 0x13);
    *(undefined1 *)(param_1 + 5) = *(undefined1 *)(puVar2 + 5);
    *(undefined1 *)((long)param_1 + 0x15) = *(undefined1 *)((long)puVar2 + 0x15);
    *(undefined1 *)((long)param_1 + 0x16) = *(undefined1 *)((long)puVar2 + 0x16);
    *(undefined1 *)((long)param_1 + 0x17) = *(undefined1 *)((long)puVar2 + 0x17);
    *(undefined1 *)(param_1 + 6) = *(undefined1 *)(puVar2 + 6);
  }
  *param_4 = *param_4 + 0x20;
  return 0;
}


// ===== 004d5c30 __pfx_deserialize_NV2080_CTRL_GR_GET_SM_ISSUE_RATE_MODIFIER_V2_PARAMS_v2B_06 =====

undefined8
__pfx_deserialize_NV2080_CTRL_GR_GET_SM_ISSUE_RATE_MODIFIER_V2_PARAMS_v2B_06
          (uint *param_1,long param_2,uint param_3,uint *param_4)

{
  ulong uVar1;
  uint uVar2;
  uint *puVar3;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (uint *)0x0) && (param_2 != 0)) {
    uVar2 = *param_4;
    if ((param_3 < uVar2) || ((ulong)param_3 < (ulong)uVar2 + 0x7fc)) {
      return 2;
    }
    puVar3 = (uint *)(param_2 + (ulong)uVar2);
    uVar2 = *puVar3;
    *param_1 = uVar2;
    if (0xff < uVar2) {
      return 0x5b;
    }
    if (uVar2 != 0) {
      uVar2 = 0;
      do {
        uVar1 = (ulong)uVar2;
        uVar2 = uVar2 + 1;
        param_1[uVar1 * 2 + 1] = puVar3[uVar1 * 2 + 1];
        param_1[uVar1 * 2 + 2] = puVar3[uVar1 * 2 + 2];
      } while (uVar2 < *puVar3);
    }
  }
  *param_4 = *param_4 + 0x7fc;
  return 0;
}


// ===== 004d5c40 deserialize_NV2080_CTRL_GR_GET_SM_ISSUE_RATE_MODIFIER_V2_PARAMS_v2B_06 =====

undefined8
deserialize_NV2080_CTRL_GR_GET_SM_ISSUE_RATE_MODIFIER_V2_PARAMS_v2B_06
          (uint *param_1,long param_2,uint param_3,uint *param_4)

{
  ulong uVar1;
  uint uVar2;
  uint *puVar3;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (uint *)0x0) && (param_2 != 0)) {
    uVar2 = *param_4;
    if ((param_3 < uVar2) || ((ulong)param_3 < (ulong)uVar2 + 0x7fc)) {
      return 2;
    }
    puVar3 = (uint *)(param_2 + (ulong)uVar2);
    uVar2 = *puVar3;
    *param_1 = uVar2;
    if (0xff < uVar2) {
      return 0x5b;
    }
    if (uVar2 != 0) {
      uVar2 = 0;
      do {
        uVar1 = (ulong)uVar2;
        uVar2 = uVar2 + 1;
        param_1[uVar1 * 2 + 1] = puVar3[uVar1 * 2 + 1];
        param_1[uVar1 * 2 + 2] = puVar3[uVar1 * 2 + 2];
      } while (uVar2 < *puVar3);
    }
  }
  *param_4 = *param_4 + 0x7fc;
  return 0;
}


// ===== 004d5cf0 __pfx_deserialize_NV2080_CTRL_GR_GET_SM_ISSUE_THROTTLE_CTRL_PARAMS_v2B_10 =====

undefined8
__pfx_deserialize_NV2080_CTRL_GR_GET_SM_ISSUE_THROTTLE_CTRL_PARAMS_v2B_10
          (uint *param_1,long param_2,uint param_3,uint *param_4)

{
  ulong uVar1;
  uint uVar2;
  uint *puVar3;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (uint *)0x0) && (param_2 != 0)) {
    uVar2 = *param_4;
    if ((param_3 < uVar2) || ((ulong)param_3 < (ulong)uVar2 + 0x7fc)) {
      return 2;
    }
    puVar3 = (uint *)(param_2 + (ulong)uVar2);
    uVar2 = *puVar3;
    *param_1 = uVar2;
    if (0xff < uVar2) {
      return 0x5b;
    }
    if (uVar2 != 0) {
      uVar2 = 0;
      do {
        uVar1 = (ulong)uVar2;
        uVar2 = uVar2 + 1;
        param_1[uVar1 * 2 + 1] = puVar3[uVar1 * 2 + 1];
        param_1[uVar1 * 2 + 2] = puVar3[uVar1 * 2 + 2];
      } while (uVar2 < *puVar3);
    }
  }
  *param_4 = *param_4 + 0x7fc;
  return 0;
}


// ===== 004d5d00 deserialize_NV2080_CTRL_GR_GET_SM_ISSUE_THROTTLE_CTRL_PARAMS_v2B_10 =====

undefined8
deserialize_NV2080_CTRL_GR_GET_SM_ISSUE_THROTTLE_CTRL_PARAMS_v2B_10
          (uint *param_1,long param_2,uint param_3,uint *param_4)

{
  ulong uVar1;
  uint uVar2;
  uint *puVar3;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (uint *)0x0) && (param_2 != 0)) {
    uVar2 = *param_4;
    if ((param_3 < uVar2) || ((ulong)param_3 < (ulong)uVar2 + 0x7fc)) {
      return 2;
    }
    puVar3 = (uint *)(param_2 + (ulong)uVar2);
    uVar2 = *puVar3;
    *param_1 = uVar2;
    if (0xff < uVar2) {
      return 0x5b;
    }
    if (uVar2 != 0) {
      uVar2 = 0;
      do {
        uVar1 = (ulong)uVar2;
        uVar2 = uVar2 + 1;
        param_1[uVar1 * 2 + 1] = puVar3[uVar1 * 2 + 1];
        param_1[uVar1 * 2 + 2] = puVar3[uVar1 * 2 + 2];
      } while (uVar2 < *puVar3);
    }
  }
  *param_4 = *param_4 + 0x7fc;
  return 0;
}


// ===== 004d5db0 __pfx_deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_INFO_PARAMS_v24_07 =====

undefined8
__pfx_deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_INFO_PARAMS_v24_07
          (long param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0xe00)) {
      return 2;
    }
    param_2 = param_2 + (ulong)uVar1;
    puVar6 = (undefined4 *)(param_1 + 4);
    puVar5 = (undefined4 *)(param_2 + 0x1c4);
    do {
      puVar2 = puVar5 + -0x70;
      puVar4 = puVar6;
      do {
        puVar3 = puVar2 + 2;
        puVar4[-1] = puVar2[-1];
        *puVar4 = *puVar2;
        puVar2 = puVar3;
        puVar4 = puVar4 + 2;
      } while (puVar3 != puVar5);
      puVar5 = puVar5 + 0x70;
      puVar6 = puVar6 + 0x76;
    } while (puVar5 != (undefined4 *)(param_2 + 0xfc4));
  }
  *param_4 = *param_4 + 0xe00;
  return 0;
}


// ===== 004d5dc0 deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_INFO_PARAMS_v24_07 =====

undefined8
deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_INFO_PARAMS_v24_07
          (long param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0xe00)) {
      return 2;
    }
    param_2 = param_2 + (ulong)uVar1;
    puVar6 = (undefined4 *)(param_1 + 4);
    puVar5 = (undefined4 *)(param_2 + 0x1c4);
    do {
      puVar2 = puVar5 + -0x70;
      puVar4 = puVar6;
      do {
        puVar3 = puVar2 + 2;
        puVar4[-1] = puVar2[-1];
        *puVar4 = *puVar2;
        puVar2 = puVar3;
        puVar4 = puVar4 + 2;
      } while (puVar3 != puVar5);
      puVar5 = puVar5 + 0x70;
      puVar6 = puVar6 + 0x76;
    } while (puVar5 != (undefined4 *)(param_2 + 0xfc4));
  }
  *param_4 = *param_4 + 0xe00;
  return 0;
}


// ===== 004d5e80 deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_INFO_PARAMS_v29_00 =====

undefined8
deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_INFO_PARAMS_v29_00
          (long param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0xe80)) {
      return 2;
    }
    param_2 = param_2 + (ulong)uVar1;
    puVar6 = (undefined4 *)(param_1 + 4);
    puVar5 = (undefined4 *)(param_2 + 0x1d4);
    do {
      puVar2 = puVar5 + -0x74;
      puVar4 = puVar6;
      do {
        puVar3 = puVar2 + 2;
        puVar4[-1] = puVar2[-1];
        *puVar4 = *puVar2;
        puVar2 = puVar3;
        puVar4 = puVar4 + 2;
      } while (puVar3 != puVar5);
      puVar5 = puVar5 + 0x74;
      puVar6 = puVar6 + 0x76;
    } while (puVar5 != (undefined4 *)(param_2 + 0x1054));
  }
  *param_4 = *param_4 + 0xe80;
  return 0;
}


// ===== 004d5f40 deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_INFO_PARAMS_v2C_03 =====

undefined8
deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_INFO_PARAMS_v2C_03
          (long param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0xec0)) {
      return 2;
    }
    param_2 = param_2 + (ulong)uVar1;
    puVar6 = (undefined4 *)(param_1 + 4);
    puVar5 = (undefined4 *)(param_2 + 0x1dc);
    do {
      puVar2 = puVar5 + -0x76;
      puVar4 = puVar6;
      do {
        puVar3 = puVar2 + 2;
        puVar4[-1] = puVar2[-1];
        *puVar4 = *puVar2;
        puVar2 = puVar3;
        puVar4 = puVar4 + 2;
      } while (puVar3 != puVar5);
      puVar5 = puVar5 + 0x76;
      puVar6 = puVar6 + 0x76;
    } while (puVar5 != (undefined4 *)(param_2 + 0x109c));
  }
  *param_4 = *param_4 + 0xec0;
  return 0;
}


// ===== 004d6000 deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_GLOBAL_SM_ORDER_PARAMS_v1F_01 =====

undefined8
deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_GLOBAL_SM_ORDER_PARAMS_v1F_01
          (undefined2 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined2 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x5a20)) {
      return 2;
    }
    param_2 = param_2 + (ulong)uVar1;
    puVar5 = (undefined2 *)(param_2 + 0xb40);
    do {
      puVar2 = puVar5 + -0x5a0;
      puVar4 = param_1;
      do {
        puVar3 = puVar2 + 6;
        *puVar4 = *puVar2;
        puVar4[1] = puVar2[1];
        puVar4[2] = puVar2[2];
        puVar4[3] = puVar2[3];
        puVar4[4] = puVar2[4];
        puVar4[5] = puVar2[5];
        puVar2 = puVar3;
        puVar4 = puVar4 + 9;
      } while (puVar3 != puVar5);
      puVar2 = puVar5 + 0x5a2;
      param_1[0x870] = *puVar5;
      param_1[0x871] = puVar5[1];
      puVar5 = puVar2;
      param_1 = param_1 + 0x872;
    } while (puVar2 != (undefined2 *)(param_2 + 0x6560));
  }
  *param_4 = *param_4 + 0x5a20;
  return 0;
}


// ===== 004d6100 deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_GLOBAL_SM_ORDER_PARAMS_v2A_02 =====

undefined8
deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_GLOBAL_SM_ORDER_PARAMS_v2A_02
          (undefined2 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined2 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x6920)) {
      return 2;
    }
    param_2 = param_2 + (ulong)uVar1;
    puVar5 = (undefined2 *)(param_2 + 0xd20);
    do {
      puVar2 = puVar5 + -0x690;
      puVar4 = param_1;
      do {
        puVar3 = puVar2 + 7;
        *puVar4 = *puVar2;
        puVar4[1] = puVar2[1];
        puVar4[2] = puVar2[2];
        puVar4[3] = puVar2[3];
        puVar4[4] = puVar2[4];
        puVar4[5] = puVar2[5];
        puVar4[6] = puVar2[6];
        puVar2 = puVar3;
        puVar4 = puVar4 + 9;
      } while (puVar3 != puVar5);
      puVar2 = puVar5 + 0x692;
      param_1[0x870] = *puVar5;
      param_1[0x871] = puVar5[1];
      puVar5 = puVar2;
      param_1 = param_1 + 0x872;
    } while (puVar2 != (undefined2 *)(param_2 + 0x7640));
  }
  *param_4 = *param_4 + 0x6920;
  return 0;
}


// ===== 004d61e0 deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_GLOBAL_SM_ORDER_PARAMS_v2B_0B =====

undefined8
deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_GLOBAL_SM_ORDER_PARAMS_v2B_0B
          (undefined2 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined2 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x8720)) {
      return 2;
    }
    param_2 = param_2 + (ulong)uVar1;
    puVar5 = (undefined2 *)(param_2 + 0x10e0);
    do {
      puVar2 = puVar5 + -0x870;
      puVar4 = param_1;
      do {
        puVar3 = puVar2 + 9;
        *puVar4 = *puVar2;
        puVar4[1] = puVar2[1];
        puVar4[2] = puVar2[2];
        puVar4[3] = puVar2[3];
        puVar4[4] = puVar2[4];
        puVar4[5] = puVar2[5];
        puVar4[7] = puVar2[7];
        puVar4[8] = puVar2[8];
        puVar4[6] = puVar2[6];
        puVar2 = puVar3;
        puVar4 = puVar4 + 9;
      } while (puVar3 != puVar5);
      puVar2 = puVar5 + 0x872;
      param_1[0x870] = *puVar5;
      param_1[0x871] = puVar5[1];
      puVar5 = puVar2;
      param_1 = param_1 + 0x872;
    } while (puVar2 != (undefined2 *)(param_2 + 0x9800));
  }
  *param_4 = *param_4 + 0x8720;
  return 0;
}


// ===== 004d62e0 deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_ROP_INFO_PARAMS_v1B_05 =====

undefined8
deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_ROP_INFO_PARAMS_v1B_05
          (undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x60)) {
      return 2;
    }
    puVar2 = (undefined4 *)(param_2 + (ulong)uVar1);
    puVar3 = puVar2;
    do {
      puVar4 = puVar3 + 3;
      *param_1 = *puVar3;
      param_1[1] = puVar3[1];
      param_1[2] = puVar3[2];
      puVar3 = puVar4;
      param_1 = param_1 + 3;
    } while (puVar4 != puVar2 + 0x18);
  }
  *param_4 = *param_4 + 0x60;
  return 0;
}


// ===== 004d6360 deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_PPC_MASKS_PARAMS_v1C_06 =====

undefined8
deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_PPC_MASKS_PARAMS_v1C_06
          (long param_1,long param_2,uint param_3,uint *param_4)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar2 = *param_4;
    if ((param_3 < uVar2) || ((ulong)param_3 < (ulong)uVar2 + 0x180)) {
      return 2;
    }
    param_2 = param_2 + (ulong)uVar2;
    lVar1 = param_2 + 0x180;
    do {
      lVar3 = 0;
      do {
        *(undefined4 *)(param_1 + lVar3) = *(undefined4 *)(param_2 + lVar3);
        lVar3 = lVar3 + 4;
      } while (lVar3 != 0x30);
      param_2 = param_2 + 0x30;
      param_1 = param_1 + 0x80;
    } while (param_2 != lVar1);
  }
  *param_4 = *param_4 + 0x180;
  return 0;
}


// ===== 004d6400 deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_CONTEXT_BUFFERS_INFO_PARAMS_v25_07 =====

undefined8
deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_CONTEXT_BUFFERS_INFO_PARAMS_v25_07
          (long param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x680)) {
      return 2;
    }
    param_2 = param_2 + (ulong)uVar1;
    puVar6 = (undefined4 *)(param_1 + 4);
    puVar5 = (undefined4 *)(param_2 + 0xd4);
    do {
      puVar2 = puVar5 + -0x34;
      puVar4 = puVar6;
      do {
        puVar3 = puVar2 + 2;
        puVar4[-1] = puVar2[-1];
        *puVar4 = *puVar2;
        puVar2 = puVar3;
        puVar4 = puVar4 + 2;
      } while (puVar3 != puVar5);
      puVar5 = puVar5 + 0x34;
      puVar6 = puVar6 + 0x34;
    } while (puVar5 != (undefined4 *)(param_2 + 0x754));
  }
  *param_4 = *param_4 + 0x680;
  return 0;
}


// ===== 004d64b0 deserialize_NV2080_CTRL_CMD_BUS_GET_PCIE_REQ_ATOMICS_CAPS_PARAMS_v25_0B =====

undefined8
deserialize_NV2080_CTRL_CMD_BUS_GET_PCIE_REQ_ATOMICS_CAPS_PARAMS_v25_0B
          (long param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 4)) {
      return 2;
    }
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + (ulong)uVar1);
  }
  *param_4 = *param_4 + 4;
  return 0;
}


// ===== 004d6500 deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_SM_ISSUE_RATE_MODIFIER_PARAMS_v1B_05 =====

undefined8
deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_SM_ISSUE_RATE_MODIFIER_PARAMS_v1B_05
          (undefined1 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined1 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x48)) {
      return 2;
    }
    puVar2 = (undefined1 *)(param_2 + (ulong)uVar1);
    puVar3 = puVar2;
    do {
      puVar4 = puVar3 + 9;
      *param_1 = *puVar3;
      param_1[5] = puVar3[5];
      param_1[6] = puVar3[6];
      param_1[7] = puVar3[7];
      param_1[8] = puVar3[8];
      param_1[1] = puVar3[1];
      param_1[3] = puVar3[3];
      param_1[4] = puVar3[4];
      param_1[2] = puVar3[2];
      puVar3 = puVar4;
      param_1 = param_1 + 9;
    } while (puVar4 != puVar2 + 0x48);
  }
  *param_4 = *param_4 + 0x48;
  return 0;
}


// ===== 004d65a0 deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_SM_ISSUE_RATE_MODIFIER_V2_PARAMS_v2B_06 =====

undefined8
deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_SM_ISSUE_RATE_MODIFIER_V2_PARAMS_v2B_06
          (uint *param_1,long param_2,uint param_3,uint *param_4)

{
  uint *puVar1;
  uint uVar2;
  long lVar3;
  uint *puVar4;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (uint *)0x0) && (param_2 != 0)) {
    uVar2 = *param_4;
    if ((param_3 < uVar2) || ((ulong)param_3 < (ulong)uVar2 + 0x3fe0)) {
      return 2;
    }
    puVar4 = (uint *)(param_2 + (ulong)uVar2);
    puVar1 = puVar4 + 0xff8;
    do {
      uVar2 = *puVar4;
      *param_1 = uVar2;
      if (0xff < uVar2) {
        return 0x5b;
      }
      if (uVar2 != 0) {
        lVar3 = 0;
        do {
          param_1[lVar3 * 2 + 1] = puVar4[lVar3 * 2 + 1];
          param_1[lVar3 * 2 + 2] = puVar4[lVar3 * 2 + 2];
          lVar3 = lVar3 + 1;
        } while ((uint)lVar3 < *puVar4);
      }
      puVar4 = puVar4 + 0x1ff;
      param_1 = param_1 + 0x1ff;
    } while (puVar4 != puVar1);
  }
  *param_4 = *param_4 + 0x3fe0;
  return 0;
}


// ===== 004d6660 deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_SM_ISSUE_THROTTLE_CTRL_PARAMS_v2B_10 =====

undefined8
deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_SM_ISSUE_THROTTLE_CTRL_PARAMS_v2B_10
          (uint *param_1,long param_2,uint param_3,uint *param_4)

{
  uint *puVar1;
  uint uVar2;
  long lVar3;
  uint *puVar4;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (uint *)0x0) && (param_2 != 0)) {
    uVar2 = *param_4;
    if ((param_3 < uVar2) || ((ulong)param_3 < (ulong)uVar2 + 0x3fe0)) {
      return 2;
    }
    puVar4 = (uint *)(param_2 + (ulong)uVar2);
    puVar1 = puVar4 + 0xff8;
    do {
      uVar2 = *puVar4;
      *param_1 = uVar2;
      if (0xff < uVar2) {
        return 0x5b;
      }
      if (uVar2 != 0) {
        lVar3 = 0;
        do {
          param_1[lVar3 * 2 + 1] = puVar4[lVar3 * 2 + 1];
          param_1[lVar3 * 2 + 2] = puVar4[lVar3 * 2 + 2];
          lVar3 = lVar3 + 1;
        } while ((uint)lVar3 < *puVar4);
      }
      puVar4 = puVar4 + 0x1ff;
      param_1 = param_1 + 0x1ff;
    } while (puVar4 != puVar1);
  }
  *param_4 = *param_4 + 0x3fe0;
  return 0;
}


// ===== 004d6740 deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_FLOORSWEEPING_MASKS_PARAMS_v1D_03 =====

undefined8
deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_FLOORSWEEPING_MASKS_PARAMS_v1D_03
          (undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  long lVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar2 = *param_4;
    if ((param_3 < uVar2) || ((ulong)param_3 < (ulong)uVar2 + 0x900)) {
      return 2;
    }
    puVar8 = (undefined4 *)(param_2 + (ulong)uVar2);
    puVar7 = puVar8 + 0xd;
    puVar1 = puVar8 + 0x24d;
    do {
      puVar4 = puVar7 + -0xc;
      puVar3 = param_1;
      do {
        puVar5 = puVar4 + 1;
        puVar3[1] = *puVar4;
        puVar3[0x21] = puVar4[0xc];
        puVar3[0x6c] = puVar4[0x2f];
        puVar3[0x42] = puVar4[0x19];
        puVar3[0x8c] = puVar4[0x3b];
        puVar4 = puVar5;
        puVar3 = puVar3 + 1;
      } while (puVar5 != puVar7);
      *param_1 = *puVar8;
      param_1[0x41] = puVar7[0xc];
      lVar6 = 0;
      do {
        *(undefined4 *)((long)param_1 + lVar6 + 0x188) =
             *(undefined4 *)((long)puVar8 + lVar6 + 0x98);
        lVar6 = lVar6 + 4;
      } while (lVar6 != 0x28);
      puVar7 = puVar7 + 0x48;
      puVar8 = puVar8 + 0x48;
      param_1 = param_1 + 0xae;
    } while (puVar7 != puVar1);
  }
  *param_4 = *param_4 + 0x900;
  return 0;
}


// ===== 004d6880 deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_FLOORSWEEPING_MASKS_PARAMS_v2B_01 =====

undefined8
deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_FLOORSWEEPING_MASKS_PARAMS_v2B_01
          (undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  long lVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar2 = *param_4;
    if ((param_3 < uVar2) || ((ulong)param_3 < (ulong)uVar2 + 0xb80)) {
      return 2;
    }
    puVar8 = (undefined4 *)(param_2 + (ulong)uVar2);
    puVar7 = puVar8 + 0x11;
    puVar1 = puVar8 + 0x2f1;
    do {
      puVar4 = puVar7 + -0x10;
      puVar3 = param_1;
      do {
        puVar5 = puVar4 + 1;
        puVar3[1] = *puVar4;
        puVar3[0x21] = puVar4[0x10];
        puVar3[0x6c] = puVar4[0x3b];
        puVar3[0x42] = puVar4[0x21];
        puVar3[0x8c] = puVar4[0x4b];
        puVar4 = puVar5;
        puVar3 = puVar3 + 1;
      } while (puVar5 != puVar7);
      *param_1 = *puVar8;
      param_1[0x41] = puVar7[0x10];
      lVar6 = 0;
      do {
        *(undefined4 *)((long)param_1 + lVar6 + 0x188) = *(undefined4 *)((long)puVar8 + lVar6 + 200)
        ;
        lVar6 = lVar6 + 4;
      } while (lVar6 != 0x28);
      puVar7 = puVar7 + 0x5c;
      puVar8 = puVar8 + 0x5c;
      param_1 = param_1 + 0xae;
    } while (puVar7 != puVar1);
  }
  *param_4 = *param_4 + 0xb80;
  return 0;
}


// ===== 004d69c0 deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_FLOORSWEEPING_MASKS_PARAMS_v2D_02 =====

undefined8
deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_FLOORSWEEPING_MASKS_PARAMS_v2D_02
          (undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  long lVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar2 = *param_4;
    if ((param_3 < uVar2) || ((ulong)param_3 < (ulong)uVar2 + 0x1580)) {
      return 2;
    }
    puVar8 = (undefined4 *)(param_2 + (ulong)uVar2);
    puVar7 = puVar8 + 0x21;
    puVar1 = puVar8 + 0x581;
    do {
      puVar4 = puVar7 + -0x20;
      puVar3 = param_1;
      do {
        puVar5 = puVar4 + 1;
        puVar3[1] = *puVar4;
        puVar3[0x21] = puVar4[0x20];
        puVar3[0x6c] = puVar4[0x6b];
        puVar3[0x42] = puVar4[0x41];
        puVar3[0x8c] = puVar4[0x8b];
        puVar4 = puVar5;
        puVar3 = puVar3 + 1;
      } while (puVar5 != puVar7);
      *param_1 = *puVar8;
      param_1[0x41] = puVar7[0x20];
      lVar6 = 0;
      do {
        *(undefined4 *)((long)param_1 + lVar6 + 0x188) =
             *(undefined4 *)((long)puVar8 + lVar6 + 0x188);
        lVar6 = lVar6 + 4;
      } while (lVar6 != 0x28);
      puVar7 = puVar7 + 0xac;
      puVar8 = puVar8 + 0xac;
      param_1 = param_1 + 0xae;
    } while (puVar7 != puVar1);
  }
  *param_4 = *param_4 + 0x1580;
  return 0;
}


// ===== 004d6af0 deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_ZCULL_INFO_PARAMS_v1B_05 =====

undefined8
deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_ZCULL_INFO_PARAMS_v1B_05
          (undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if (uVar1 <= param_3) {
      puVar2 = (undefined4 *)(param_2 + (ulong)uVar1);
      puVar3 = puVar2;
      if ((ulong)uVar1 + 0x140 <= (ulong)param_3) {
        do {
          puVar4 = puVar3 + 10;
          *param_1 = *puVar3;
          param_1[1] = puVar3[1];
          param_1[2] = puVar3[2];
          param_1[3] = puVar3[3];
          param_1[4] = puVar3[4];
          param_1[5] = puVar3[5];
          param_1[6] = puVar3[6];
          param_1[7] = puVar3[7];
          param_1[8] = puVar3[8];
          param_1[9] = puVar3[9];
          puVar3 = puVar4;
          param_1 = param_1 + 10;
        } while (puVar4 != puVar2 + 0x50);
        goto LAB_004d6b78;
      }
    }
    return 2;
  }
LAB_004d6b78:
  *param_4 = *param_4 + 0x140;
  return 0;
}


// ===== 004d6ba0 deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_FECS_RECORD_SIZE_PARAMS_v1B_05 =====

undefined8
deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_FECS_RECORD_SIZE_PARAMS_v1B_05
          (long param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  long lVar2;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if (uVar1 <= param_3) {
      lVar2 = 0;
      if ((ulong)uVar1 + 0x20 <= (ulong)param_3) {
        do {
          *(undefined4 *)(param_1 + lVar2) = *(undefined4 *)(param_2 + (ulong)uVar1 + lVar2);
          lVar2 = lVar2 + 4;
        } while (lVar2 != 0x20);
        goto LAB_004d6be0;
      }
    }
    return 2;
  }
LAB_004d6be0:
  *param_4 = *param_4 + 0x20;
  return 0;
}


// ===== 004d6c40 deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_FECS_TRACE_DEFINES_PARAMS_v1D_04 =====

undefined8
deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_FECS_TRACE_DEFINES_PARAMS_v1D_04
          (undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x100)) {
      return 2;
    }
    puVar2 = (undefined4 *)(param_2 + (ulong)uVar1);
    puVar3 = puVar2;
    do {
      puVar4 = puVar3 + 8;
      *param_1 = *puVar3;
      param_1[1] = puVar3[1];
      *(undefined1 *)(param_1 + 2) = *(undefined1 *)(puVar3 + 2);
      *(undefined8 *)(param_1 + 4) = *(undefined8 *)(puVar3 + 4);
      *(undefined1 *)(param_1 + 6) = *(undefined1 *)(puVar3 + 6);
      puVar3 = puVar4;
      param_1 = param_1 + 8;
    } while (puVar4 != puVar2 + 0x40);
  }
  *param_4 = *param_4 + 0x100;
  return 0;
}


// ===== 004d6ce0 deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_PDB_PROPERTIES_PARAMS_v1E_02 =====

undefined8
deserialize_NV2080_CTRL_INTERNAL_STATIC_GR_GET_PDB_PROPERTIES_PARAMS_v1E_02
          (long param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  long lVar2;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if (uVar1 <= param_3) {
      lVar2 = 0;
      if ((ulong)uVar1 + 8 <= (ulong)param_3) {
        do {
          *(undefined1 *)(param_1 + lVar2) = *(undefined1 *)(param_2 + (ulong)uVar1 + lVar2);
          lVar2 = lVar2 + 1;
        } while (lVar2 != 8);
        goto LAB_004d6d31;
      }
    }
    return 2;
  }
LAB_004d6d31:
  *param_4 = *param_4 + 8;
  return 0;
}


// ===== 004d6d60 deserialize_VGPU_DISPLAYLESS_INFO_v24_08 =====

undefined8
deserialize_VGPU_DISPLAYLESS_INFO_v24_08(long param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x34)) {
      return 2;
    }
    puVar2 = (undefined4 *)(param_2 + (ulong)uVar1);
    *(undefined4 *)(param_1 + 0x25f6c) = *puVar2;
    *(undefined4 *)(param_1 + 0x25f70) = puVar2[1];
    *(undefined4 *)(param_1 + 0x25f60) = puVar2[2];
    *(undefined4 *)(param_1 + 0x25f64) = puVar2[3];
    *(undefined4 *)(param_1 + 0x25f68) = puVar2[4];
  }
  *param_4 = *param_4 + 0x34;
  return 0;
}


// ===== 004d6de0 deserialize_VGPU_DISPLAYLESS_INFO_v2D_00 =====

undefined8
deserialize_VGPU_DISPLAYLESS_INFO_v2D_00(long param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x34)) {
      return 2;
    }
    puVar2 = (undefined4 *)(param_2 + (ulong)uVar1);
    *(undefined4 *)(param_1 + 0x25f6c) = *puVar2;
    *(undefined4 *)(param_1 + 0x25f70) = puVar2[1];
    *(undefined4 *)(param_1 + 0x25f60) = puVar2[2];
    *(undefined4 *)(param_1 + 0x25f64) = puVar2[3];
    *(undefined4 *)(param_1 + 0x25f68) = puVar2[4];
  }
  *param_4 = *param_4 + 0x34;
  return 0;
}


// ===== 004d6e60 deserialize_VGPU_STATIC_DATA_v25_0E =====

undefined8 deserialize_VGPU_STATIC_DATA_v25_0E(long param_1,long param_2,uint param_3,uint *param_4)

{
  undefined8 *puVar1;
  uint uVar2;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar2 = *param_4;
    if ((param_3 < uVar2) || ((ulong)param_3 < (ulong)uVar2 + 0x1d8)) {
      return 2;
    }
    puVar1 = (undefined8 *)(param_2 + (ulong)uVar2);
    *(undefined8 *)(param_1 + 0x1f9a8) = *puVar1;
    *(undefined8 *)(param_1 + 0x1f9b0) = puVar1[1];
    *(undefined4 *)(param_1 + 0x25e7c) = *(undefined4 *)(puVar1 + 2);
    *(ulong *)(param_1 + 0x1fd40) = (ulong)*(uint *)((long)puVar1 + 0x14);
    *(undefined4 *)(param_1 + 0x25e80) = *(undefined4 *)(puVar1 + 3);
    *(ulong *)(param_1 + 0x25e88) = (ulong)*(uint *)((long)puVar1 + 0x1c);
    *(undefined4 *)(param_1 + 0x25e90) = *(undefined4 *)(puVar1 + 4);
    *(undefined4 *)(param_1 + 0xa7a4) = *(undefined4 *)((long)puVar1 + 0x24);
    *(undefined8 *)(param_1 + 0xa768) = puVar1[5];
    *(undefined4 *)(param_1 + 0x25e94) = *(undefined4 *)(puVar1 + 6);
    *(undefined1 *)(param_1 + 0x1fe4a) = *(undefined1 *)((long)puVar1 + 0x34);
    *(undefined1 *)(param_1 + 0x1f100) = *(undefined1 *)((long)puVar1 + 0x35);
    portMemCopy(param_1 + 0x1fd49,0x40,(long)puVar1 + 0x36,0x40);
    portMemCopy(param_1 + 0x1fd8a,0x80,(long)puVar1 + 0xb6,0x80);
    portMemCopy(param_1 + 0x1fe0a,0x40,(long)puVar1 + 0x76,0x40);
    *(undefined1 *)(param_1 + 0x1fd48) = *(undefined1 *)((long)puVar1 + 0x136);
    *(undefined8 *)(param_1 + 0xa7c8) = puVar1[0x27];
    *(undefined1 *)(param_1 + 0xa78c) = *(undefined1 *)(puVar1 + 0x28);
    *(undefined1 *)(param_1 + 0xa7a0) = *(undefined1 *)((long)puVar1 + 0x141);
    *(undefined1 *)(param_1 + 0x1fe4b) = *(undefined1 *)((long)puVar1 + 0x142);
    *(undefined1 *)(param_1 + 0xa8db) = *(undefined1 *)((long)puVar1 + 0x143);
    *(undefined1 *)(param_1 + 0xa8b8) = *(undefined1 *)((long)puVar1 + 0x144);
    *(undefined1 *)(param_1 + 0xa8ba) = *(undefined1 *)((long)puVar1 + 0x145);
    *(undefined4 *)(param_1 + 0xa8bc) = *(undefined4 *)(puVar1 + 0x29);
    *(undefined1 *)(param_1 + 0xa8b9) = *(undefined1 *)((long)puVar1 + 0x14c);
    *(undefined4 *)(param_1 + 0xa8c0) = *(undefined4 *)(puVar1 + 0x2a);
    *(undefined4 *)(param_1 + 0xa788) = *(undefined4 *)((long)puVar1 + 0x154);
    portMemCopy(param_1 + 0xa8c4,0x17,puVar1 + 0x2b,0x17);
    portMemCopy(param_1 + 0x1f104,9,(long)puVar1 + 0x1cc,9);
  }
  *param_4 = *param_4 + 0x1d8;
  return 0;
}


// ===== 004d70a0 deserialize_VGPU_STATIC_DATA_v27_00 =====

undefined8 deserialize_VGPU_STATIC_DATA_v27_00(long param_1,long param_2,uint param_3,uint *param_4)

{
  undefined8 *puVar1;
  uint uVar2;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar2 = *param_4;
    if ((param_3 < uVar2) || ((ulong)param_3 < (ulong)uVar2 + 0x1e8)) {
      return 2;
    }
    puVar1 = (undefined8 *)(param_2 + (ulong)uVar2);
    *(undefined8 *)(param_1 + 0x1f9a8) = *puVar1;
    *(undefined8 *)(param_1 + 0x1f9b0) = puVar1[1];
    *(undefined4 *)(param_1 + 0x25e7c) = *(undefined4 *)(puVar1 + 2);
    *(undefined8 *)(param_1 + 0x1fd40) = puVar1[3];
    *(undefined4 *)(param_1 + 0x25e80) = *(undefined4 *)(puVar1 + 4);
    *(undefined8 *)(param_1 + 0x25e88) = puVar1[5];
    *(undefined4 *)(param_1 + 0x25e90) = *(undefined4 *)(puVar1 + 6);
    *(undefined4 *)(param_1 + 0xa7a4) = *(undefined4 *)((long)puVar1 + 0x34);
    *(undefined8 *)(param_1 + 0xa768) = puVar1[7];
    *(undefined4 *)(param_1 + 0x25e94) = *(undefined4 *)(puVar1 + 8);
    *(undefined1 *)(param_1 + 0x1fe4a) = *(undefined1 *)((long)puVar1 + 0x44);
    *(undefined1 *)(param_1 + 0x1f100) = *(undefined1 *)((long)puVar1 + 0x45);
    portMemCopy(param_1 + 0x1fd49,0x40,(long)puVar1 + 0x46,0x40);
    portMemCopy(param_1 + 0x1fd8a,0x80,(long)puVar1 + 0xc6,0x80);
    portMemCopy(param_1 + 0x1fe0a,0x40,(long)puVar1 + 0x86,0x40);
    *(undefined1 *)(param_1 + 0x1fd48) = *(undefined1 *)((long)puVar1 + 0x146);
    *(undefined8 *)(param_1 + 0xa7c8) = puVar1[0x29];
    *(undefined1 *)(param_1 + 0xa78c) = *(undefined1 *)(puVar1 + 0x2a);
    *(undefined1 *)(param_1 + 0xa7a0) = *(undefined1 *)((long)puVar1 + 0x151);
    *(undefined1 *)(param_1 + 0x1fe4b) = *(undefined1 *)((long)puVar1 + 0x152);
    *(undefined1 *)(param_1 + 0xa8db) = *(undefined1 *)((long)puVar1 + 0x153);
    *(undefined1 *)(param_1 + 0xa8b8) = *(undefined1 *)((long)puVar1 + 0x154);
    *(undefined1 *)(param_1 + 0xa8ba) = *(undefined1 *)((long)puVar1 + 0x155);
    *(undefined4 *)(param_1 + 0xa8bc) = *(undefined4 *)(puVar1 + 0x2b);
    *(undefined1 *)(param_1 + 0xa8b9) = *(undefined1 *)((long)puVar1 + 0x15c);
    *(undefined4 *)(param_1 + 0xa8c0) = *(undefined4 *)(puVar1 + 0x2c);
    *(undefined4 *)(param_1 + 0xa788) = *(undefined4 *)((long)puVar1 + 0x164);
    portMemCopy(param_1 + 0xa8c4,0x17,puVar1 + 0x2d,0x17);
    portMemCopy(param_1 + 0x1f104,9,(long)puVar1 + 0x1dc,9);
  }
  *param_4 = *param_4 + 0x1e8;
  return 0;
}


// ===== 004d72f0 deserialize_VGPU_STATIC_DATA_v27_01 =====

undefined8 deserialize_VGPU_STATIC_DATA_v27_01(long param_1,long param_2,uint param_3,uint *param_4)

{
  undefined8 *puVar1;
  uint uVar2;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar2 = *param_4;
    if ((param_3 < uVar2) || ((ulong)param_3 < (ulong)uVar2 + 0x200)) {
      return 2;
    }
    puVar1 = (undefined8 *)(param_2 + (ulong)uVar2);
    *(undefined8 *)(param_1 + 0x1f9a8) = *puVar1;
    *(undefined8 *)(param_1 + 0x1f9b0) = puVar1[1];
    *(undefined4 *)(param_1 + 0x25e7c) = *(undefined4 *)(puVar1 + 2);
    *(undefined8 *)(param_1 + 0x1fd40) = puVar1[3];
    *(undefined4 *)(param_1 + 0x25e80) = *(undefined4 *)(puVar1 + 4);
    *(undefined8 *)(param_1 + 0x25e88) = puVar1[5];
    *(undefined4 *)(param_1 + 0x25e90) = *(undefined4 *)(puVar1 + 6);
    *(undefined4 *)(param_1 + 0xa7a4) = *(undefined4 *)((long)puVar1 + 0x34);
    *(undefined4 *)(param_1 + 0x25e94) = *(undefined4 *)(puVar1 + 0xb);
    *(undefined1 *)(param_1 + 0x1fe4a) = *(undefined1 *)((long)puVar1 + 0x5c);
    *(undefined1 *)(param_1 + 0x1f100) = *(undefined1 *)((long)puVar1 + 0x5d);
    portMemCopy(param_1 + 0x1fd49,0x40,(long)puVar1 + 0x5e,0x40);
    portMemCopy(param_1 + 0x1fd8a,0x80,(long)puVar1 + 0xde,0x80);
    portMemCopy(param_1 + 0x1fe0a,0x40,(long)puVar1 + 0x9e,0x40);
    *(undefined1 *)(param_1 + 0x1fd48) = *(undefined1 *)((long)puVar1 + 0x15e);
    *(undefined8 *)(param_1 + 0xa7c8) = puVar1[0x2c];
    *(undefined1 *)(param_1 + 0xa78c) = *(undefined1 *)(puVar1 + 0x2d);
    *(undefined1 *)(param_1 + 0xa7a0) = *(undefined1 *)((long)puVar1 + 0x169);
    *(undefined1 *)(param_1 + 0x1fe4b) = *(undefined1 *)((long)puVar1 + 0x16a);
    *(undefined1 *)(param_1 + 0xa8db) = *(undefined1 *)((long)puVar1 + 0x16b);
    *(undefined1 *)(param_1 + 0xa8b8) = *(undefined1 *)((long)puVar1 + 0x16c);
    *(undefined1 *)(param_1 + 0xa8ba) = *(undefined1 *)((long)puVar1 + 0x16d);
    *(undefined4 *)(param_1 + 0xa8bc) = *(undefined4 *)(puVar1 + 0x2e);
    *(undefined1 *)(param_1 + 0xa8b9) = *(undefined1 *)((long)puVar1 + 0x174);
    *(undefined4 *)(param_1 + 0xa8c0) = *(undefined4 *)(puVar1 + 0x2f);
    *(undefined4 *)(param_1 + 0xa788) = *(undefined4 *)((long)puVar1 + 0x17c);
    portMemCopy(param_1 + 0xa8c4,0x17,puVar1 + 0x30,0x17);
    *(undefined8 *)(param_1 + 0xa768) = puVar1[7];
    *(undefined8 *)(param_1 + 0xa770) = puVar1[8];
    *(undefined8 *)(param_1 + 0xa778) = puVar1[9];
    *(undefined8 *)(param_1 + 0xa780) = puVar1[10];
    portMemCopy(param_1 + 0x1f104,9,(long)puVar1 + 500,9);
  }
  *param_4 = *param_4 + 0x200;
  return 0;
}


// ===== 004d7560 deserialize_VGPU_STATIC_DATA_v2A_07 =====

undefined8 deserialize_VGPU_STATIC_DATA_v2A_07(long param_1,long param_2,uint param_3,uint *param_4)

{
  undefined8 *puVar1;
  uint uVar2;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar2 = *param_4;
    if ((param_3 < uVar2) || ((ulong)param_3 < (ulong)uVar2 + 0x1a0)) {
      return 2;
    }
    puVar1 = (undefined8 *)(param_2 + (ulong)uVar2);
    *(undefined8 *)(param_1 + 0x1f9a8) = *puVar1;
    *(undefined8 *)(param_1 + 0x1f9b0) = puVar1[1];
    *(undefined4 *)(param_1 + 0x25e7c) = *(undefined4 *)(puVar1 + 2);
    *(undefined8 *)(param_1 + 0x1fd40) = puVar1[3];
    *(undefined4 *)(param_1 + 0x25e80) = *(undefined4 *)(puVar1 + 4);
    *(undefined8 *)(param_1 + 0x25e88) = puVar1[5];
    *(undefined4 *)(param_1 + 0x25e90) = *(undefined4 *)(puVar1 + 6);
    *(undefined4 *)(param_1 + 0xa7a4) = *(undefined4 *)((long)puVar1 + 0x34);
    *(undefined4 *)(param_1 + 0x25e94) = *(undefined4 *)(puVar1 + 7);
    *(undefined1 *)(param_1 + 0x1fe4a) = *(undefined1 *)((long)puVar1 + 0x3c);
    *(undefined1 *)(param_1 + 0x1f100) = *(undefined1 *)((long)puVar1 + 0x3d);
    portMemCopy(param_1 + 0x1fd49,0x40,(long)puVar1 + 0x3e,0x40);
    portMemCopy(param_1 + 0x1fd8a,0x80,(long)puVar1 + 0xbe,0x80);
    portMemCopy(param_1 + 0x1fe0a,0x40,(long)puVar1 + 0x7e,0x40);
    *(undefined1 *)(param_1 + 0x1fd48) = *(undefined1 *)((long)puVar1 + 0x13e);
    *(undefined8 *)(param_1 + 0xa7c8) = puVar1[0x28];
    *(undefined1 *)(param_1 + 0xa78c) = *(undefined1 *)(puVar1 + 0x29);
    *(undefined1 *)(param_1 + 0xa7a0) = *(undefined1 *)((long)puVar1 + 0x149);
    *(undefined1 *)(param_1 + 0x1fe4b) = *(undefined1 *)((long)puVar1 + 0x14a);
    *(undefined1 *)(param_1 + 0xa8db) = *(undefined1 *)((long)puVar1 + 0x14b);
    *(undefined1 *)(param_1 + 0xa8b8) = *(undefined1 *)((long)puVar1 + 0x14c);
    *(undefined1 *)(param_1 + 0xa8ba) = *(undefined1 *)((long)puVar1 + 0x14d);
    *(undefined4 *)(param_1 + 0xa8bc) = *(undefined4 *)(puVar1 + 0x2a);
    *(undefined1 *)(param_1 + 0xa8b9) = *(undefined1 *)((long)puVar1 + 0x154);
    *(undefined4 *)(param_1 + 0xa8c0) = *(undefined4 *)(puVar1 + 0x2b);
    *(undefined4 *)(param_1 + 0xa788) = *(undefined4 *)((long)puVar1 + 0x15c);
    portMemCopy(param_1 + 0xa8c4,0x17,puVar1 + 0x2c,0x17);
    *(undefined8 *)(param_1 + 0xa768) = puVar1[0x30];
    *(undefined8 *)(param_1 + 0xa770) = puVar1[0x31];
    *(undefined8 *)(param_1 + 0xa778) = puVar1[0x32];
    *(undefined8 *)(param_1 + 0xa780) = puVar1[0x33];
    portMemCopy(param_1 + 0x1f104,9,(long)puVar1 + 0x177,9);
  }
  *param_4 = *param_4 + 0x1a0;
  return 0;
}


// ===== 004d77d0 deserialize_VGPU_STATIC_DATA_v2B_08 =====

undefined8 deserialize_VGPU_STATIC_DATA_v2B_08(long param_1,long param_2,uint param_3,uint *param_4)

{
  undefined8 *puVar1;
  uint uVar2;
  undefined8 *puVar3;
  long lVar4;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar2 = *param_4;
    if ((param_3 < uVar2) || ((ulong)param_3 < (ulong)uVar2 + 0x218)) {
      return 2;
    }
    puVar1 = (undefined8 *)(param_2 + (ulong)uVar2);
    lVar4 = param_1 + 0x1f104;
    *(undefined8 *)(param_1 + 0x1f9a8) = *puVar1;
    *(undefined8 *)(param_1 + 0x1f9b0) = puVar1[1];
    *(undefined4 *)(param_1 + 0x25e7c) = *(undefined4 *)(puVar1 + 2);
    *(undefined8 *)(param_1 + 0x1fd40) = puVar1[3];
    *(undefined4 *)(param_1 + 0x25e80) = *(undefined4 *)(puVar1 + 4);
    *(undefined8 *)(param_1 + 0x25e88) = puVar1[5];
    *(undefined4 *)(param_1 + 0x25e90) = *(undefined4 *)(puVar1 + 6);
    *(undefined4 *)(param_1 + 0xa7a4) = *(undefined4 *)((long)puVar1 + 0x34);
    *(undefined4 *)(param_1 + 0x25e94) = *(undefined4 *)(puVar1 + 7);
    *(undefined1 *)(param_1 + 0x1fe4a) = *(undefined1 *)((long)puVar1 + 0x3c);
    *(undefined1 *)(param_1 + 0x1f100) = *(undefined1 *)((long)puVar1 + 0x3d);
    portMemCopy(param_1 + 0x1fd49,0x40,(long)puVar1 + 0x3e,0x40);
    portMemCopy(param_1 + 0x1fd8a,0x80,(long)puVar1 + 0xbe,0x80);
    portMemCopy(param_1 + 0x1fe0a,0x40,(long)puVar1 + 0x7e,0x40);
    puVar3 = puVar1 + 0x2f;
    *(undefined1 *)(param_1 + 0x1fd48) = *(undefined1 *)((long)puVar1 + 0x13e);
    *(undefined8 *)(param_1 + 0xa7c8) = puVar1[0x28];
    *(undefined1 *)(param_1 + 0xa78c) = *(undefined1 *)(puVar1 + 0x29);
    *(undefined1 *)(param_1 + 0xa7a0) = *(undefined1 *)((long)puVar1 + 0x149);
    *(undefined1 *)(param_1 + 0x1fe4b) = *(undefined1 *)((long)puVar1 + 0x14a);
    *(undefined1 *)(param_1 + 0xa8db) = *(undefined1 *)((long)puVar1 + 0x14b);
    *(undefined1 *)(param_1 + 0xa8b8) = *(undefined1 *)((long)puVar1 + 0x14c);
    *(undefined1 *)(param_1 + 0xa8ba) = *(undefined1 *)((long)puVar1 + 0x14d);
    *(undefined4 *)(param_1 + 0xa8bc) = *(undefined4 *)(puVar1 + 0x2a);
    *(undefined1 *)(param_1 + 0xa8b9) = *(undefined1 *)((long)puVar1 + 0x154);
    *(undefined4 *)(param_1 + 0xa8c0) = *(undefined4 *)(puVar1 + 0x2b);
    *(undefined4 *)(param_1 + 0xa788) = *(undefined4 *)((long)puVar1 + 0x15c);
    portMemCopy(param_1 + 0xa8c4,0x17,puVar1 + 0x2c,0x17);
    *(undefined8 *)(param_1 + 0xa768) = puVar1[0x3f];
    *(undefined8 *)(param_1 + 0xa770) = puVar1[0x40];
    *(undefined8 *)(param_1 + 0xa778) = puVar1[0x41];
    *(undefined8 *)(param_1 + 0xa780) = puVar1[0x42];
    do {
      portMemCopy(lVar4,0x10,puVar3,0x10);
      lVar4 = lVar4 + 0x10;
      puVar3 = puVar3 + 2;
    } while (param_1 + 0x1f184 != lVar4);
  }
  *param_4 = *param_4 + 0x218;
  return 0;
}


// ===== 004d7a50 deserialize_VGPU_STATIC_DATA_v2D_00 =====

undefined8 deserialize_VGPU_STATIC_DATA_v2D_00(long param_1,long param_2,uint param_3,uint *param_4)

{
  undefined8 *puVar1;
  uint uVar2;
  undefined8 *puVar3;
  long lVar4;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar2 = *param_4;
    if ((param_3 < uVar2) || ((ulong)param_3 < (ulong)uVar2 + 0x218)) {
      return 2;
    }
    puVar1 = (undefined8 *)(param_2 + (ulong)uVar2);
    lVar4 = param_1 + 0x1f104;
    *(undefined8 *)(param_1 + 0x1f9a8) = *puVar1;
    *(undefined8 *)(param_1 + 0x1f9b0) = puVar1[1];
    *(undefined4 *)(param_1 + 0x25e7c) = *(undefined4 *)(puVar1 + 2);
    *(undefined8 *)(param_1 + 0x1fd40) = puVar1[3];
    *(undefined4 *)(param_1 + 0x25e80) = *(undefined4 *)(puVar1 + 4);
    *(undefined8 *)(param_1 + 0x25e88) = puVar1[5];
    *(undefined4 *)(param_1 + 0x25e90) = *(undefined4 *)(puVar1 + 6);
    *(undefined4 *)(param_1 + 0xa7a4) = *(undefined4 *)((long)puVar1 + 0x34);
    *(undefined4 *)(param_1 + 0x25e94) = *(undefined4 *)(puVar1 + 7);
    *(undefined1 *)(param_1 + 0x1fe4a) = *(undefined1 *)((long)puVar1 + 0x3c);
    *(undefined1 *)(param_1 + 0x1f100) = *(undefined1 *)((long)puVar1 + 0x3d);
    portMemCopy(param_1 + 0x1fd49,0x40,(long)puVar1 + 0x3e,0x40);
    portMemCopy(param_1 + 0x1fd8a,0x80,(long)puVar1 + 0xbe,0x80);
    portMemCopy(param_1 + 0x1fe0a,0x40,(long)puVar1 + 0x7e,0x40);
    puVar3 = puVar1 + 0x2f;
    *(undefined1 *)(param_1 + 0x1fd48) = *(undefined1 *)((long)puVar1 + 0x13e);
    *(undefined8 *)(param_1 + 0xa7c8) = puVar1[0x28];
    *(undefined1 *)(param_1 + 0xa78c) = *(undefined1 *)(puVar1 + 0x29);
    *(undefined1 *)(param_1 + 0xa7a0) = *(undefined1 *)((long)puVar1 + 0x149);
    *(undefined1 *)(param_1 + 0x1fe4b) = *(undefined1 *)((long)puVar1 + 0x14a);
    *(undefined1 *)(param_1 + 0xa8db) = *(undefined1 *)((long)puVar1 + 0x14b);
    *(undefined1 *)(param_1 + 0xa8b8) = *(undefined1 *)((long)puVar1 + 0x14c);
    *(undefined1 *)(param_1 + 0xa8ba) = *(undefined1 *)((long)puVar1 + 0x14d);
    *(undefined4 *)(param_1 + 0xa8bc) = *(undefined4 *)(puVar1 + 0x2a);
    *(undefined1 *)(param_1 + 0xa8b9) = *(undefined1 *)((long)puVar1 + 0x154);
    *(undefined4 *)(param_1 + 0xa8c0) = *(undefined4 *)(puVar1 + 0x2b);
    *(undefined4 *)(param_1 + 0xa788) = *(undefined4 *)((long)puVar1 + 0x15c);
    portMemCopy(param_1 + 0xa8c4,0x17,puVar1 + 0x2c,0x17);
    *(undefined8 *)(param_1 + 0xa768) = puVar1[0x3f];
    *(undefined8 *)(param_1 + 0xa770) = puVar1[0x40];
    *(undefined8 *)(param_1 + 0xa778) = puVar1[0x41];
    *(undefined8 *)(param_1 + 0xa780) = puVar1[0x42];
    do {
      portMemCopy(lVar4,0x10,puVar3,0x10);
      lVar4 = lVar4 + 0x10;
      puVar3 = puVar3 + 2;
    } while (param_1 + 0x1f184 != lVar4);
  }
  *param_4 = *param_4 + 0x218;
  return 0;
}


// ===== 004d7cd0 deserialize_NV0000_CTRL_SYSTEM_GET_VGX_SYSTEM_INFO_PARAMS_v03_00 =====

undefined8
deserialize_NV0000_CTRL_SYSTEM_GET_VGX_SYSTEM_INFO_PARAMS_v03_00
          (long param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x508)) {
      return 2;
    }
    param_2 = param_2 + (ulong)uVar1;
    portMemCopy(param_1,0x100,param_2,0x100);
    portMemCopy(param_1 + 0x100,0x100,param_2 + 0x100,0x100);
    portMemCopy(param_1 + 0x200,0x100,param_2 + 0x200,0x100);
    portMemCopy(param_1 + 0x300,0x100,param_2 + 0x300,0x100);
    portMemCopy(param_1 + 0x400,0x100,param_2 + 0x400,0x100);
    *(undefined4 *)(param_1 + 0x500) = *(undefined4 *)(param_2 + 0x500);
    *(undefined4 *)(param_1 + 0x504) = *(undefined4 *)(param_2 + 0x504);
  }
  *param_4 = *param_4 + 0x508;
  return 0;
}


// ===== 004d7e10 deserialize_NV2080_CTRL_GPU_GET_GID_INFO_PARAMS_v03_00 =====

undefined8
deserialize_NV2080_CTRL_GPU_GET_GID_INFO_PARAMS_v03_00
          (undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((uVar1 <= param_3) && ((ulong)uVar1 + 0x10c <= (ulong)param_3)) {
      puVar2 = (undefined4 *)(param_2 + (ulong)uVar1);
      *param_1 = *puVar2;
      param_1[1] = puVar2[1];
      param_1[2] = puVar2[2];
      portMemCopy(param_1 + 3,0x100,puVar2 + 3,0x100);
      *param_4 = *param_4 + 0x10c;
      return 0;
    }
    return 2;
  }
  *param_4 = *param_4 + 0x10c;
  return 0;
}


// ===== 004d7eb0 deserialize_NV2080_CTRL_BIOS_GET_SKU_INFO_PARAMS_v25_0E =====

undefined8
deserialize_NV2080_CTRL_BIOS_GET_SKU_INFO_PARAMS_v25_0E
          (undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar2 = *param_4;
    if ((param_3 < uVar2) || ((ulong)param_3 < (ulong)uVar2 + 0x30)) {
      return 2;
    }
    puVar1 = (undefined4 *)(param_2 + (ulong)uVar2);
    *param_1 = *puVar1;
    param_1[5] = puVar1[5];
    portMemCopy(param_1 + 1,9,puVar1 + 1,9);
    portMemCopy((long)param_1 + 0xd,5,(long)puVar1 + 0xd,5);
    portMemCopy(param_1 + 6,5,puVar1 + 6,5);
    portMemCopy((long)param_1 + 0x1d,5,(long)puVar1 + 0x1d,5);
    portMemCopy((long)param_1 + 0x22,6,(long)puVar1 + 0x22,6);
    portMemCopy(param_1 + 10,2,puVar1 + 10,2);
    param_1[0xb] = puVar1[0xb];
  }
  *param_4 = *param_4 + 0x30;
  return 0;
}


// ===== 004d7fe0 deserialize_NV2080_CTRL_CMD_FB_GET_FB_REGION_INFO_PARAMS_v03_00 =====

undefined8
deserialize_NV2080_CTRL_CMD_FB_GET_FB_REGION_INFO_PARAMS_v03_00
          (undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  long lVar2;
  undefined4 *puVar3;
  long lVar4;
  long lVar5;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x308)) {
      return 2;
    }
    puVar3 = (undefined4 *)(param_2 + (ulong)uVar1);
    *param_1 = *puVar3;
    lVar2 = (long)puVar3 + 0x27;
    lVar4 = (long)param_1 + 0x27;
    do {
      lVar5 = lVar4 + 0x38;
      *(undefined8 *)(lVar4 + -0x1f) = *(undefined8 *)(lVar2 + -0x1f);
      *(undefined8 *)(lVar4 + -0x17) = *(undefined8 *)(lVar2 + -0x17);
      *(undefined8 *)(lVar4 + -0xf) = *(undefined8 *)(lVar2 + -0xf);
      *(undefined4 *)(lVar4 + -7) = *(undefined4 *)(lVar2 + -7);
      *(undefined1 *)(lVar4 + -3) = *(undefined1 *)(lVar2 + -3);
      *(undefined1 *)(lVar4 + -2) = *(undefined1 *)(lVar2 + -2);
      *(undefined1 *)(lVar4 + -1) = *(undefined1 *)(lVar2 + -1);
      portMemCopy(lVar4,0x12,lVar2,0x11);
      lVar2 = lVar2 + 0x30;
      lVar4 = lVar5;
    } while (lVar5 != (long)param_1 + 0x3a7);
  }
  *param_4 = *param_4 + 0x308;
  return 0;
}


// ===== 004d80f0 deserialize_NV2080_CTRL_CMD_FB_GET_FB_REGION_INFO_PARAMS_v2B_02 =====

undefined8
deserialize_NV2080_CTRL_CMD_FB_GET_FB_REGION_INFO_PARAMS_v2B_02
          (undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  long lVar2;
  undefined4 *puVar3;
  long lVar4;
  long lVar5;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x388)) {
      return 2;
    }
    puVar3 = (undefined4 *)(param_2 + (ulong)uVar1);
    *param_1 = *puVar3;
    lVar2 = (long)puVar3 + 0x27;
    lVar4 = (long)param_1 + 0x27;
    do {
      lVar5 = lVar4 + 0x38;
      *(undefined8 *)(lVar4 + -0x1f) = *(undefined8 *)(lVar2 + -0x1f);
      *(undefined8 *)(lVar4 + -0x17) = *(undefined8 *)(lVar2 + -0x17);
      *(undefined8 *)(lVar4 + -0xf) = *(undefined8 *)(lVar2 + -0xf);
      *(undefined4 *)(lVar4 + -7) = *(undefined4 *)(lVar2 + -7);
      *(undefined1 *)(lVar4 + -3) = *(undefined1 *)(lVar2 + -3);
      *(undefined1 *)(lVar4 + -2) = *(undefined1 *)(lVar2 + -2);
      *(undefined1 *)(lVar4 + -1) = *(undefined1 *)(lVar2 + -1);
      portMemCopy(lVar4,0x12,lVar2,0x12);
      lVar2 = lVar2 + 0x38;
      lVar4 = lVar5;
    } while (lVar5 != (long)param_1 + 0x3a7);
  }
  *param_4 = *param_4 + 0x388;
  return 0;
}


// ===== 004d8200 deserialize_NV2080_CTRL_GPU_GET_COMPUTE_PROFILES_PARAMS_v20_04 =====

undefined8
deserialize_NV2080_CTRL_GPU_GET_COMPUTE_PROFILES_PARAMS_v20_04
          (long param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  undefined1 *puVar5;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((uVar1 <= param_3) && ((ulong)uVar1 + 0x7c <= (ulong)param_3)) {
      puVar2 = (uint *)((ulong)uVar1 + param_2);
      uVar1 = *puVar2;
      if (8 < uVar1) {
        nvAssertFailedNoLog("ciProfiles_v20_04->profileCount <= NV_ARRAY_ELEMENTS(ciProfiles->profiles)"
                            ,"src/kernel/vgpu/rpcstructurecopy.c",0x7de);
        uVar1 = *puVar2;
      }
      *(uint *)(param_1 + 4) = uVar1;
      if (uVar1 != 0) {
        puVar3 = puVar2;
        puVar5 = (undefined1 *)(param_1 + 8);
        do {
          puVar4 = puVar3 + 5;
          *(uint *)(puVar5 + 4) = puVar3[2];
          *puVar5 = (char)puVar3[1];
          *(uint *)(puVar5 + 8) = puVar3[3];
          *(uint *)(puVar5 + 0xc) = puVar3[4];
          *(uint *)(puVar5 + 0x10) = *puVar4;
          puVar3 = puVar4;
          puVar5 = puVar5 + 0x14;
        } while (puVar4 != puVar2 + (ulong)uVar1 * 5);
      }
      *param_4 = *param_4 + 0x7c;
      return 0;
    }
    return 2;
  }
  *param_4 = *param_4 + 0x7c;
  return 0;
}


// ===== 004d8320 deserialize_NVC637_CTRL_EXEC_PARTITIONS_GET_PARAMS_v24_05 =====

undefined8
deserialize_NVC637_CTRL_EXEC_PARTITIONS_GET_PARAMS_v24_05
          (uint *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  uint *puVar2;
  long lVar3;
  uint *puVar4;
  uint *puVar5;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (uint *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x1a4)) {
      return 2;
    }
    puVar5 = (uint *)(param_2 + (ulong)uVar1);
    uVar1 = *puVar5;
    *param_1 = uVar1;
    if (uVar1 != 0) {
      lVar3 = 1;
      puVar2 = param_1 + 9;
      puVar4 = puVar5 + 9;
      do {
        param_1[lVar3] = puVar5[lVar3];
        lVar3 = lVar3 + 1;
        *puVar2 = *puVar4;
        puVar2[1] = puVar4[1];
        puVar2[2] = puVar4[2];
        puVar2[3] = puVar4[3];
        puVar2[4] = puVar4[4];
        puVar2[5] = puVar4[5];
        puVar2[6] = puVar4[6];
        puVar2[7] = puVar4[7];
        puVar2[8] = puVar4[8];
        puVar2[10] = puVar4[9];
        puVar2[0xb] = puVar4[10];
        puVar2[0xc] = puVar4[0xb];
        puVar2 = puVar2 + 0xd;
        puVar4 = puVar4 + 0xc;
      } while (lVar3 != (ulong)uVar1 + 1);
    }
  }
  *param_4 = *param_4 + 0x1a4;
  return 0;
}


// ===== 004d8430 deserialize_NV9096_CTRL_GET_ZBC_CLEAR_TABLE_SIZE_PARAMS_v1A_07 =====

undefined8
deserialize_NV9096_CTRL_GET_ZBC_CLEAR_TABLE_SIZE_PARAMS_v1A_07
          (undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 8)) {
      return 2;
    }
    puVar2 = (undefined4 *)(param_2 + (ulong)uVar1);
    puVar3 = param_1;
    do {
      puVar4 = puVar3 + 3;
      *puVar3 = *puVar2;
      puVar3[1] = puVar2[1];
      puVar2 = puVar2 + 2;
      puVar3 = puVar4;
    } while (puVar4 != param_1 + 0xc);
  }
  *param_4 = *param_4 + 0x20;
  return 0;
}


// ===== 004d84c0 deserialize_GPU_PARTITION_INFO_v24_05 =====

undefined8
deserialize_GPU_PARTITION_INFO_v24_05(undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar2 = *param_4;
    if ((param_3 < uVar2) || ((ulong)param_3 < (ulong)uVar2 + 0xe0)) {
      return 2;
    }
    puVar1 = (undefined4 *)(param_2 + (ulong)uVar2);
    *param_1 = *puVar1;
    uVar2 = puVar1[1];
    param_1[1] = uVar2;
    param_1[2] = puVar1[2];
    param_1[3] = puVar1[3];
    param_1[4] = puVar1[4];
    param_1[5] = puVar1[5];
    param_1[6] = puVar1[6];
    param_1[0x27] = puVar1[0x27];
    param_1[0x28] = puVar1[0x28];
    param_1[0x29] = puVar1[0x29];
    param_1[0x2a] = puVar1[0x2a];
    param_1[0x2b] = puVar1[0x2b];
    param_1[0x2c] = puVar1[0x2c];
    *(undefined8 *)(param_1 + 0x2e) = *(undefined8 *)(puVar1 + 0x2e);
    *(undefined1 *)(param_1 + 0x30) = *(undefined1 *)(puVar1 + 0x30);
    *(undefined8 *)(param_1 + 0x32) = *(undefined8 *)(puVar1 + 0x32);
    *(undefined8 *)(param_1 + 0x34) = *(undefined8 *)(puVar1 + 0x34);
    *(undefined8 *)(param_1 + 0x36) = *(undefined8 *)(puVar1 + 0x36);
    if (uVar2 != 0) {
      puVar3 = puVar1;
      puVar5 = param_1 + 7;
      do {
        puVar4 = puVar3 + 1;
        *puVar5 = puVar3[7];
        puVar5[0x18] = puVar3[0x1f];
        puVar5[8] = puVar3[0xf];
        puVar5[0x10] = puVar3[0x17];
        puVar3 = puVar4;
        puVar5 = puVar5 + 1;
      } while (puVar4 != puVar1 + uVar2);
    }
  }
  *param_4 = *param_4 + 0xe0;
  return 0;
}


// ===== 004d8680 deserialize_GPU_PARTITION_INFO_v28_02 =====

undefined8
deserialize_GPU_PARTITION_INFO_v28_02(undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar2 = *param_4;
    if ((param_3 < uVar2) || ((ulong)param_3 < (ulong)uVar2 + 0xe8)) {
      return 2;
    }
    puVar1 = (undefined4 *)(param_2 + (ulong)uVar2);
    *param_1 = *puVar1;
    uVar2 = puVar1[1];
    param_1[1] = uVar2;
    param_1[2] = puVar1[2];
    param_1[3] = puVar1[3];
    param_1[4] = puVar1[4];
    param_1[5] = puVar1[5];
    param_1[6] = puVar1[6];
    param_1[0x27] = puVar1[0x27];
    param_1[0x28] = puVar1[0x28];
    param_1[0x29] = puVar1[0x29];
    param_1[0x2a] = puVar1[0x2a];
    param_1[0x2b] = puVar1[0x2b];
    param_1[0x2c] = puVar1[0x2c];
    *(undefined8 *)(param_1 + 0x2e) = *(undefined8 *)(puVar1 + 0x2e);
    *(undefined1 *)(param_1 + 0x30) = *(undefined1 *)(puVar1 + 0x30);
    *(undefined8 *)(param_1 + 0x32) = *(undefined8 *)(puVar1 + 0x32);
    *(undefined8 *)(param_1 + 0x34) = *(undefined8 *)(puVar1 + 0x34);
    *(undefined8 *)(param_1 + 0x36) = *(undefined8 *)(puVar1 + 0x36);
    *(undefined8 *)(param_1 + 0x38) = *(undefined8 *)(puVar1 + 0x38);
    if (uVar2 != 0) {
      puVar3 = puVar1;
      puVar5 = param_1 + 7;
      do {
        puVar4 = puVar3 + 1;
        *puVar5 = puVar3[7];
        puVar5[0x18] = puVar3[0x1f];
        puVar5[8] = puVar3[0xf];
        puVar5[0x10] = puVar3[0x17];
        puVar3 = puVar4;
        puVar5 = puVar5 + 1;
      } while (puVar4 != puVar1 + uVar2);
    }
  }
  *param_4 = *param_4 + 0xe8;
  return 0;
}


// ===== 004d8810 deserialize_NV2080_CTRL_GPU_QUERY_ECC_STATUS_PARAMS_v24_06 =====

undefined8
deserialize_NV2080_CTRL_GPU_QUERY_ECC_STATUS_PARAMS_v24_06
          (undefined1 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined1 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x3f0)) {
      return 2;
    }
    puVar2 = (undefined1 *)(param_2 + (ulong)uVar1);
    param_1[0x668] = puVar2[1000];
    puVar3 = puVar2;
    do {
      puVar4 = puVar3 + 0x28;
      *param_1 = *puVar3;
      param_1[1] = puVar3[1];
      param_1[2] = puVar3[2];
      *(undefined8 *)(param_1 + 8) = *(undefined8 *)(puVar3 + 8);
      *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(puVar3 + 0x10);
      *(undefined8 *)(param_1 + 0x18) = *(undefined8 *)(puVar3 + 0x18);
      *(undefined8 *)(param_1 + 0x20) = *(undefined8 *)(puVar3 + 0x20);
      puVar3 = puVar4;
      param_1 = param_1 + 0x28;
    } while (puVar4 != puVar2 + 1000);
  }
  *param_4 = *param_4 + 0x3f0;
  return 0;
}


// ===== 004d88d0 deserialize_NV2080_CTRL_GPU_QUERY_ECC_STATUS_PARAMS_v26_02 =====

undefined8
deserialize_NV2080_CTRL_GPU_QUERY_ECC_STATUS_PARAMS_v26_02
          (undefined1 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined1 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x4b8)) {
      return 2;
    }
    puVar2 = (undefined1 *)(param_2 + (ulong)uVar1);
    param_1[0x668] = puVar2[0x4b0];
    puVar3 = puVar2;
    do {
      puVar4 = puVar3 + 0x28;
      *param_1 = *puVar3;
      param_1[1] = puVar3[1];
      param_1[2] = puVar3[2];
      *(undefined8 *)(param_1 + 8) = *(undefined8 *)(puVar3 + 8);
      *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(puVar3 + 0x10);
      *(undefined8 *)(param_1 + 0x18) = *(undefined8 *)(puVar3 + 0x18);
      *(undefined8 *)(param_1 + 0x20) = *(undefined8 *)(puVar3 + 0x20);
      puVar3 = puVar4;
      param_1 = param_1 + 0x28;
    } while (puVar4 != puVar2 + 0x4b0);
  }
  *param_4 = *param_4 + 0x4b8;
  return 0;
}


// ===== 004d8990 deserialize_NV2080_CTRL_GPU_QUERY_ECC_STATUS_PARAMS_v27_04 =====

undefined8
deserialize_NV2080_CTRL_GPU_QUERY_ECC_STATUS_PARAMS_v27_04
          (undefined1 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined1 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x4e0)) {
      return 2;
    }
    puVar2 = (undefined1 *)(param_2 + (ulong)uVar1);
    param_1[0x668] = puVar2[0x4d8];
    puVar3 = puVar2;
    do {
      puVar4 = puVar3 + 0x28;
      *param_1 = *puVar3;
      param_1[1] = puVar3[1];
      param_1[2] = puVar3[2];
      *(undefined8 *)(param_1 + 8) = *(undefined8 *)(puVar3 + 8);
      *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(puVar3 + 0x10);
      *(undefined8 *)(param_1 + 0x18) = *(undefined8 *)(puVar3 + 0x18);
      *(undefined8 *)(param_1 + 0x20) = *(undefined8 *)(puVar3 + 0x20);
      puVar3 = puVar4;
      param_1 = param_1 + 0x28;
    } while (puVar4 != puVar2 + 0x4d8);
  }
  *param_4 = *param_4 + 0x4e0;
  return 0;
}


// ===== 004d8a50 deserialize_NV2080_CTRL_GPU_QUERY_ECC_STATUS_PARAMS_v28_01 =====

undefined8
deserialize_NV2080_CTRL_GPU_QUERY_ECC_STATUS_PARAMS_v28_01
          (undefined1 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined1 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x530)) {
      return 2;
    }
    puVar2 = (undefined1 *)(param_2 + (ulong)uVar1);
    param_1[0x668] = puVar2[0x528];
    puVar3 = puVar2;
    do {
      puVar4 = puVar3 + 0x28;
      *param_1 = *puVar3;
      param_1[1] = puVar3[1];
      param_1[2] = puVar3[2];
      *(undefined8 *)(param_1 + 8) = *(undefined8 *)(puVar3 + 8);
      *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(puVar3 + 0x10);
      *(undefined8 *)(param_1 + 0x18) = *(undefined8 *)(puVar3 + 0x18);
      *(undefined8 *)(param_1 + 0x20) = *(undefined8 *)(puVar3 + 0x20);
      puVar3 = puVar4;
      param_1 = param_1 + 0x28;
    } while (puVar4 != puVar2 + 0x528);
  }
  *param_4 = *param_4 + 0x530;
  return 0;
}


// ===== 004d8b10 deserialize_NV2080_CTRL_GPU_QUERY_ECC_STATUS_PARAMS_v28_08 =====

undefined8
deserialize_NV2080_CTRL_GPU_QUERY_ECC_STATUS_PARAMS_v28_08
          (undefined1 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined1 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x5a8)) {
      return 2;
    }
    puVar2 = (undefined1 *)(param_2 + (ulong)uVar1);
    param_1[0x668] = puVar2[0x5a0];
    puVar3 = puVar2;
    do {
      puVar4 = puVar3 + 0x28;
      *param_1 = *puVar3;
      param_1[1] = puVar3[1];
      param_1[2] = puVar3[2];
      *(undefined8 *)(param_1 + 8) = *(undefined8 *)(puVar3 + 8);
      *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(puVar3 + 0x10);
      *(undefined8 *)(param_1 + 0x18) = *(undefined8 *)(puVar3 + 0x18);
      *(undefined8 *)(param_1 + 0x20) = *(undefined8 *)(puVar3 + 0x20);
      puVar3 = puVar4;
      param_1 = param_1 + 0x28;
    } while (puVar4 != puVar2 + 0x5a0);
  }
  *param_4 = *param_4 + 0x5a8;
  return 0;
}


// ===== 004d8bd0 deserialize_NV2080_CTRL_GPU_QUERY_ECC_STATUS_PARAMS_v2C_02 =====

undefined8
deserialize_NV2080_CTRL_GPU_QUERY_ECC_STATUS_PARAMS_v2C_02
          (undefined1 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined1 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x670)) {
      return 2;
    }
    puVar2 = (undefined1 *)(param_2 + (ulong)uVar1);
    param_1[0x668] = puVar2[0x668];
    puVar3 = puVar2;
    do {
      puVar4 = puVar3 + 0x28;
      *param_1 = *puVar3;
      param_1[1] = puVar3[1];
      param_1[2] = puVar3[2];
      *(undefined8 *)(param_1 + 8) = *(undefined8 *)(puVar3 + 8);
      *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(puVar3 + 0x10);
      *(undefined8 *)(param_1 + 0x18) = *(undefined8 *)(puVar3 + 0x18);
      *(undefined8 *)(param_1 + 0x20) = *(undefined8 *)(puVar3 + 0x20);
      puVar3 = puVar4;
      param_1 = param_1 + 0x28;
    } while (puVar4 != puVar2 + 0x668);
  }
  *param_4 = *param_4 + 0x670;
  return 0;
}


// ===== 004d8c80 deserialize_GPU_EXEC_SYSPIPE_INFO_v26_01 =====

undefined8
deserialize_GPU_EXEC_SYSPIPE_INFO_v26_01(uint *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  long lVar2;
  uint *puVar3;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (uint *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x44)) {
      return 2;
    }
    puVar3 = (uint *)(param_2 + (ulong)uVar1);
    uVar1 = *puVar3;
    *param_1 = uVar1;
    if (uVar1 != 0) {
      lVar2 = 0;
      do {
        param_1[lVar2 + 1] = puVar3[lVar2 + 1];
        param_1[lVar2 + 9] = puVar3[lVar2 + 9];
        lVar2 = lVar2 + 1;
      } while ((uint)lVar2 < *puVar3);
    }
  }
  *param_4 = *param_4 + 0x44;
  return 0;
}


// ===== 004d8d00 deserialize_NV2080_CTRL_INTERNAL_CCU_SAMPLE_INFO_PARAMS_v29_05 =====

undefined8
deserialize_NV2080_CTRL_INTERNAL_CCU_SAMPLE_INFO_PARAMS_v29_05
          (undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 4)) {
      return 2;
    }
    *param_1 = *(undefined4 *)(param_2 + (ulong)uVar1);
  }
  *param_4 = *param_4 + 4;
  return 0;
}


// ===== 004d8d50 deserialize_NV2080_CTRL_GR_GET_ZCULL_INFO_PARAMS_v12_01 =====

undefined8
deserialize_NV2080_CTRL_GR_GET_ZCULL_INFO_PARAMS_v12_01
          (undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x38)) {
      return 2;
    }
    puVar2 = (undefined4 *)(param_2 + (ulong)uVar1);
    *param_1 = *puVar2;
    param_1[1] = puVar2[1];
    param_1[2] = puVar2[2];
    param_1[3] = puVar2[3];
    param_1[4] = puVar2[4];
    param_1[5] = puVar2[5];
    param_1[6] = puVar2[6];
    param_1[7] = puVar2[7];
    param_1[8] = puVar2[8];
    param_1[9] = puVar2[9];
  }
  *param_4 = *param_4 + 0x38;
  return 0;
}


// ===== 004d8de0 deserialize_VGPU_STATIC_PROPERTIES_v1B_01 =====

undefined8
deserialize_VGPU_STATIC_PROPERTIES_v1B_01
          (undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x10)) {
      return 2;
    }
    puVar2 = (undefined4 *)(param_2 + (ulong)uVar1);
    *param_1 = *puVar2;
    *(undefined1 *)(param_1 + 1) = *(undefined1 *)(puVar2 + 1);
    *(undefined1 *)((long)param_1 + 5) = *(undefined1 *)((long)puVar2 + 5);
    param_1[2] = puVar2[2];
    *(undefined1 *)(param_1 + 3) = *(undefined1 *)(puVar2 + 3);
  }
  *param_4 = *param_4 + 0x10;
  return 0;
}


// ===== 004d8e50 deserialize_VGPU_STATIC_PROPERTIES_v26_03 =====

undefined8
deserialize_VGPU_STATIC_PROPERTIES_v26_03
          (undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x18)) {
      return 2;
    }
    puVar2 = (undefined4 *)(param_2 + (ulong)uVar1);
    *param_1 = *puVar2;
    *(undefined1 *)(param_1 + 1) = *(undefined1 *)(puVar2 + 1);
    *(undefined1 *)((long)param_1 + 5) = *(undefined1 *)((long)puVar2 + 5);
    param_1[2] = puVar2[2];
    *(undefined1 *)(param_1 + 3) = *(undefined1 *)(puVar2 + 3);
    *(undefined8 *)(param_1 + 4) = *(undefined8 *)(puVar2 + 4);
  }
  *param_4 = *param_4 + 0x18;
  return 0;
}


// ===== 004d8ec0 deserialize_VGPU_STATIC_PROPERTIES_v29_03 =====

undefined8
deserialize_VGPU_STATIC_PROPERTIES_v29_03
          (undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x20)) {
      return 2;
    }
    puVar2 = (undefined4 *)(param_2 + (ulong)uVar1);
    *param_1 = *puVar2;
    *(undefined1 *)(param_1 + 1) = *(undefined1 *)(puVar2 + 1);
    *(undefined1 *)((long)param_1 + 5) = *(undefined1 *)((long)puVar2 + 5);
    param_1[2] = puVar2[2];
    *(undefined1 *)(param_1 + 3) = *(undefined1 *)(puVar2 + 3);
    *(undefined8 *)(param_1 + 4) = *(undefined8 *)(puVar2 + 4);
    param_1[6] = puVar2[6];
  }
  *param_4 = *param_4 + 0x20;
  return 0;
}


// ===== 004d8f40 deserialize_VGPU_BSP_GET_CAPS_v25_00 =====

undefined8
deserialize_VGPU_BSP_GET_CAPS_v25_00(long param_1,long param_2,uint param_3,uint *param_4)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar2 = *param_4;
    if ((param_3 < uVar2) || ((ulong)param_3 < (ulong)uVar2 + 0x80)) {
      return 2;
    }
    lVar3 = param_2 + 8 + (ulong)uVar2;
    lVar1 = param_1 + 0x40;
    do {
      portMemCopy(param_1,8,lVar3,8);
      param_1 = param_1 + 8;
      lVar3 = lVar3 + 0x10;
    } while (param_1 != lVar1);
  }
  *param_4 = *param_4 + 0x80;
  return 0;
}


// ===== 004d9000 deserialize_VGPU_GET_LATENCY_BUFFER_SIZE_v1C_09 =====

undefined8
deserialize_VGPU_GET_LATENCY_BUFFER_SIZE_v1C_09
          (undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    if ((ulong)param_3 < (ulong)*param_4 + 0x270) {
      return 0x51;
    }
    puVar1 = (undefined4 *)(param_2 + (ulong)*param_4);
    puVar2 = puVar1;
    do {
      puVar3 = puVar2 + 3;
      *param_1 = *puVar2;
      param_1[1] = puVar2[1];
      param_1[2] = puVar2[2];
      puVar2 = puVar3;
      param_1 = param_1 + 3;
    } while (puVar3 != puVar1 + 0x9c);
  }
  *param_4 = *param_4 + 0x270;
  return 0;
}


// ===== 004d9080 deserialize_VGPU_GET_LATENCY_BUFFER_SIZE_v27_02 =====

undefined8
deserialize_VGPU_GET_LATENCY_BUFFER_SIZE_v27_02
          (undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    if ((ulong)param_3 < (ulong)*param_4 + 0x3f0) {
      return 0x51;
    }
    puVar1 = (undefined4 *)(param_2 + (ulong)*param_4);
    puVar2 = puVar1;
    do {
      puVar3 = puVar2 + 3;
      *param_1 = *puVar2;
      param_1[1] = puVar2[1];
      param_1[2] = puVar2[2];
      puVar2 = puVar3;
      param_1 = param_1 + 3;
    } while (puVar3 != puVar1 + 0xfc);
  }
  *param_4 = *param_4 + 0x3f0;
  return 0;
}


// ===== 004d90f0 deserialize_VGPU_CE_GET_CAPS_V2_v24_09 =====

undefined8
deserialize_VGPU_CE_GET_CAPS_V2_v24_09(long param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x200)) {
      return 2;
    }
    lVar2 = param_1 + 4;
    lVar4 = param_2 + 4 + (ulong)uVar1;
    do {
      lVar3 = lVar2 + 8;
      *(undefined4 *)(lVar2 + -4) = *(undefined4 *)(lVar4 + -4);
      portMemCopy(lVar2,2,lVar4,2);
      lVar2 = lVar3;
      lVar4 = lVar4 + 8;
    } while (lVar3 != param_1 + 0x204);
  }
  *param_4 = *param_4 + 0x200;
  return 0;
}


// ===== 004d91b0 deserialize_NV2080_CTRL_CMD_NVLINK_GET_NVLINK_CAPS_PARAMS_v15_02 =====

undefined8
deserialize_NV2080_CTRL_CMD_NVLINK_GET_NVLINK_CAPS_PARAMS_v15_02
          (undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x10)) {
      return 2;
    }
    puVar2 = (undefined4 *)(param_2 + (ulong)uVar1);
    *param_1 = *puVar2;
    *(undefined1 *)(param_1 + 1) = *(undefined1 *)(puVar2 + 1);
    *(undefined1 *)((long)param_1 + 5) = *(undefined1 *)((long)puVar2 + 5);
    *(undefined1 *)((long)param_1 + 6) = *(undefined1 *)((long)puVar2 + 6);
    *(undefined1 *)((long)param_1 + 7) = *(undefined1 *)((long)puVar2 + 7);
    param_1[2] = puVar2[2];
    param_1[3] = puVar2[3];
  }
  *param_4 = *param_4 + 0x10;
  return 0;
}


// ===== 004d9230 deserialize_NV2080_CTRL_CMD_NVLINK_GET_NVLINK_CAPS_PARAMS_v2B_11 =====

undefined8
deserialize_NV2080_CTRL_CMD_NVLINK_GET_NVLINK_CAPS_PARAMS_v2B_11
          (undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x30)) {
      return 2;
    }
    puVar2 = (undefined4 *)(param_2 + (ulong)uVar1);
    *param_1 = *puVar2;
    *(undefined1 *)(param_1 + 1) = *(undefined1 *)(puVar2 + 1);
    *(undefined1 *)((long)param_1 + 5) = *(undefined1 *)((long)puVar2 + 5);
    *(undefined1 *)((long)param_1 + 6) = *(undefined1 *)((long)puVar2 + 6);
    *(undefined1 *)((long)param_1 + 7) = *(undefined1 *)((long)puVar2 + 7);
    param_1[2] = puVar2[2];
    param_1[3] = puVar2[3];
    *(undefined1 *)(param_1 + 4) = *(undefined1 *)(puVar2 + 4);
    *(undefined8 *)(param_1 + 6) = *(undefined8 *)(puVar2 + 6);
    *(undefined1 *)(param_1 + 8) = *(undefined1 *)(puVar2 + 8);
    *(undefined8 *)(param_1 + 10) = *(undefined8 *)(puVar2 + 10);
  }
  *param_4 = *param_4 + 0x30;
  return 0;
}


// ===== 004d92d0 deserialize_NV2080_CTRL_FLA_GET_RANGE_PARAMS_v1A_18 =====

undefined8
deserialize_NV2080_CTRL_FLA_GET_RANGE_PARAMS_v1A_18
          (undefined8 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined8 *puVar2;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined8 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x10)) {
      return 2;
    }
    puVar2 = (undefined8 *)(param_2 + (ulong)uVar1);
    *param_1 = *puVar2;
    param_1[1] = puVar2[1];
  }
  *param_4 = *param_4 + 0x10;
  return 0;
}


// ===== 004d9330 deserialize_NVA080_CTRL_VGPU_GET_CONFIG_PARAMS_v21_0C =====

undefined8
deserialize_NVA080_CTRL_VGPU_GET_CONFIG_PARAMS_v21_0C
          (undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar2 = *param_4;
    if ((param_3 < uVar2) || ((ulong)param_3 < (ulong)uVar2 + 0x48)) {
      return 2;
    }
    puVar1 = (undefined4 *)(param_2 + (ulong)uVar2);
    *param_1 = *puVar1;
    param_1[1] = puVar1[1];
    param_1[2] = puVar1[2];
    param_1[3] = puVar1[3];
    param_1[4] = puVar1[4];
    param_1[5] = puVar1[5];
    *(undefined8 *)(param_1 + 6) = *(undefined8 *)(puVar1 + 6);
    *(undefined8 *)(param_1 + 8) = *(undefined8 *)(puVar1 + 8);
    *(undefined8 *)(param_1 + 10) = *(undefined8 *)(puVar1 + 10);
    param_1[0xc] = puVar1[0xc];
    param_1[0xd] = puVar1[0xd];
    param_1[0xe] = puVar1[0xe];
    param_1[0xf] = puVar1[0xf];
    *(undefined1 *)(param_1 + 0x10) = *(undefined1 *)(puVar1 + 0x10);
  }
  *param_4 = *param_4 + 0x48;
  return 0;
}


// ===== 004d93e0 deserialize_NV2080_CTRL_CMD_BUS_GET_PCIE_SUPPORTED_GPU_ATOMICS_PARAMS_v1F_08 =====

undefined8
deserialize_NV2080_CTRL_CMD_BUS_GET_PCIE_SUPPORTED_GPU_ATOMICS_PARAMS_v1F_08
          (long param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  long lVar2;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if (uVar1 <= param_3) {
      param_2 = param_2 + (ulong)uVar1;
      lVar2 = 0;
      if ((ulong)uVar1 + 0x68 <= (ulong)param_3) {
        do {
          *(undefined1 *)(param_1 + 8 + lVar2) = *(undefined1 *)(param_2 + lVar2);
          *(undefined4 *)(param_1 + 0xc + lVar2) = *(undefined4 *)(param_2 + 4 + lVar2);
          lVar2 = lVar2 + 8;
        } while (lVar2 != 0x68);
        goto LAB_004d943a;
      }
    }
    return 2;
  }
LAB_004d943a:
  *param_4 = *param_4 + 0x68;
  return 0;
}


// ===== 004d9460 deserialize_NV2080_CTRL_CE_GET_ALL_CAPS_PARAMS_v21_0A =====

undefined8
deserialize_NV2080_CTRL_CE_GET_ALL_CAPS_PARAMS_v21_0A
          (long param_1,long param_2,uint param_3,uint *param_4)

{
  long lVar1;
  uint uVar2;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar2 = *param_4;
    if ((param_3 < uVar2) || ((ulong)param_3 < (ulong)uVar2 + 0x44)) {
      return 2;
    }
    param_2 = param_2 + (ulong)uVar2;
    lVar1 = param_1 + 0x40;
    *(ulong *)(param_1 + 0x80) = (ulong)*(uint *)(param_2 + 0x40);
    do {
      portMemCopy(param_1,2,param_2,2);
      param_1 = param_1 + 2;
      param_2 = param_2 + 2;
    } while (param_1 != lVar1);
  }
  *param_4 = *param_4 + 0x44;
  return 0;
}


// ===== 004d9520 deserialize_NV2080_CTRL_CMD_BUS_GET_C2C_INFO_PARAMS_v22_01 =====

undefined8
deserialize_NV2080_CTRL_CMD_BUS_GET_C2C_INFO_PARAMS_v22_01
          (undefined1 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined1 *puVar2;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined1 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x14)) {
      return 2;
    }
    puVar2 = (undefined1 *)(param_2 + (ulong)uVar1);
    *param_1 = *puVar2;
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(puVar2 + 4);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(puVar2 + 8);
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(puVar2 + 0xc);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(puVar2 + 0x10);
  }
  *param_4 = *param_4 + 0x14;
  return 0;
}


// ===== 004d9590 deserialize_NV0080_CTRL_MSENC_GET_CAPS_V2_PARAMS_v25_00 =====

undefined8
deserialize_NV0080_CTRL_MSENC_GET_CAPS_V2_PARAMS_v25_00
          (long param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((uVar1 <= param_3) && ((ulong)uVar1 + 8 <= (ulong)param_3)) {
      param_2 = param_2 + (ulong)uVar1;
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 4);
      portMemCopy(param_1,6,param_2,4);
      *param_4 = *param_4 + 8;
      return 0;
    }
    return 2;
  }
  *param_4 = *param_4 + 8;
  return 0;
}


// ===== 004d9620 deserialize_NV0080_CTRL_MSENC_GET_CAPS_V2_PARAMS_v2C_07 =====

undefined8
deserialize_NV0080_CTRL_MSENC_GET_CAPS_V2_PARAMS_v2C_07
          (long param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((uVar1 <= param_3) && ((ulong)uVar1 + 0xc <= (ulong)param_3)) {
      param_2 = param_2 + (ulong)uVar1;
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
      portMemCopy(param_1,6,param_2,6);
      *param_4 = *param_4 + 0xc;
      return 0;
    }
    return 2;
  }
  *param_4 = *param_4 + 0xc;
  return 0;
}


// ===== 004d96b0 __pfx_deserialize_NV2080_CTRL_GPU_GET_CONSTRUCTED_FALCON_INFO_PARAMS_v25_01 =====

undefined8
__pfx_deserialize_NV2080_CTRL_GPU_GET_CONSTRUCTED_FALCON_INFO_PARAMS_v25_01
          (undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x504)) {
      return 2;
    }
    puVar5 = (undefined4 *)(param_2 + (ulong)uVar1);
    *param_1 = *puVar5;
    puVar2 = puVar5 + 1;
    puVar4 = param_1 + 1;
    do {
      puVar3 = puVar2 + 5;
      *puVar4 = *puVar2;
      puVar4[1] = puVar2[1];
      puVar4[2] = puVar2[2];
      puVar4[3] = puVar2[3];
      puVar4[4] = puVar2[4];
      puVar2 = puVar3;
      puVar4 = puVar4 + 5;
    } while (puVar3 != puVar5 + 0x141);
  }
  *param_4 = *param_4 + 0x504;
  return 0;
}


// ===== 004d96c0 deserialize_NV2080_CTRL_GPU_GET_CONSTRUCTED_FALCON_INFO_PARAMS_v25_01 =====

undefined8
deserialize_NV2080_CTRL_GPU_GET_CONSTRUCTED_FALCON_INFO_PARAMS_v25_01
          (undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x504)) {
      return 2;
    }
    puVar5 = (undefined4 *)(param_2 + (ulong)uVar1);
    *param_1 = *puVar5;
    puVar2 = puVar5 + 1;
    puVar4 = param_1 + 1;
    do {
      puVar3 = puVar2 + 5;
      *puVar4 = *puVar2;
      puVar4[1] = puVar2[1];
      puVar4[2] = puVar2[2];
      puVar4[3] = puVar2[3];
      puVar4[4] = puVar2[4];
      puVar2 = puVar3;
      puVar4 = puVar4 + 5;
    } while (puVar3 != puVar5 + 0x141);
  }
  *param_4 = *param_4 + 0x504;
  return 0;
}


// ===== 004d9740 deserialize_VGPU_P2P_CAPABILITY_PARAMS_v25_03 =====

undefined8
deserialize_VGPU_P2P_CAPABILITY_PARAMS_v25_03
          (undefined1 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined1 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 1)) {
      return 2;
    }
    *param_1 = *(undefined1 *)(param_2 + (ulong)uVar1);
  }
  *param_4 = *param_4 + 1;
  return 0;
}


// ===== 004d9790 deserialize_NV2080_CTRL_INTERNAL_GET_DEVICE_INFO_TABLE_PARAMS_v25_05 =====

undefined8
deserialize_NV2080_CTRL_INTERNAL_GET_DEVICE_INFO_TABLE_PARAMS_v25_05
          (undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x2404)) {
      return 2;
    }
    puVar4 = (undefined4 *)(param_2 + (ulong)uVar1);
    *param_1 = *puVar4;
    puVar2 = param_1 + 1;
    puVar4 = puVar4 + 1;
    do {
      puVar3 = puVar2 + 0xc;
      *puVar2 = *puVar4;
      puVar2[1] = puVar4[1];
      puVar2[2] = puVar4[2];
      puVar2[3] = puVar4[3];
      puVar2[4] = puVar4[4];
      puVar2[5] = puVar4[5];
      puVar2[6] = puVar4[6];
      puVar2[7] = puVar4[7];
      puVar2[8] = puVar4[8];
      puVar2 = puVar3;
      puVar4 = puVar4 + 9;
    } while (puVar3 != param_1 + 0xc01);
  }
  *param_4 = *param_4 + 0x2404;
  return 0;
}


// ===== 004d9840 deserialize_NV2080_CTRL_INTERNAL_GET_DEVICE_INFO_TABLE_PARAMS_v27_05 =====

undefined8
deserialize_NV2080_CTRL_INTERNAL_GET_DEVICE_INFO_TABLE_PARAMS_v27_05
          (undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x2c04)) {
      return 2;
    }
    puVar5 = (undefined4 *)(param_2 + (ulong)uVar1);
    *param_1 = *puVar5;
    puVar2 = puVar5 + 1;
    puVar4 = param_1 + 1;
    do {
      puVar3 = puVar2 + 0xb;
      *puVar4 = *puVar2;
      puVar4[1] = puVar2[1];
      puVar4[2] = puVar2[2];
      puVar4[3] = puVar2[3];
      puVar4[4] = puVar2[4];
      puVar4[5] = puVar2[5];
      puVar4[6] = puVar2[6];
      puVar4[7] = puVar2[7];
      puVar4[8] = puVar2[8];
      puVar4[9] = puVar2[9];
      puVar4[10] = puVar2[10];
      puVar2 = puVar3;
      puVar4 = puVar4 + 0xc;
    } while (puVar3 != puVar5 + 0xb01);
  }
  *param_4 = *param_4 + 0x2c04;
  return 0;
}


// ===== 004d9900 deserialize_NV2080_CTRL_INTERNAL_GET_DEVICE_INFO_TABLE_PARAMS_v28_04 =====

undefined8
deserialize_NV2080_CTRL_INTERNAL_GET_DEVICE_INFO_TABLE_PARAMS_v28_04
          (undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 0x6004)) {
      return 2;
    }
    puVar5 = (undefined4 *)(param_2 + (ulong)uVar1);
    *param_1 = *puVar5;
    puVar2 = puVar5 + 1;
    puVar4 = param_1 + 1;
    do {
      puVar3 = puVar2 + 0xc;
      *puVar4 = *puVar2;
      puVar4[1] = puVar2[1];
      puVar4[2] = puVar2[2];
      puVar4[3] = puVar2[3];
      puVar4[4] = puVar2[4];
      puVar4[5] = puVar2[5];
      puVar4[6] = puVar2[6];
      puVar4[7] = puVar2[7];
      puVar4[8] = puVar2[8];
      puVar4[9] = puVar2[9];
      puVar4[10] = puVar2[10];
      puVar4[0xb] = puVar2[0xb];
      puVar2 = puVar3;
      puVar4 = puVar4 + 0xc;
    } while (puVar3 != puVar5 + 0x1801);
  }
  *param_4 = *param_4 + 0x6004;
  return 0;
}


// ===== 004d99d0 deserialize_NV2080_CTRL_INTERNAL_MEMSYS_GET_STATIC_CONFIG_PARAMS_v25_06 =====

undefined8
deserialize_NV2080_CTRL_INTERNAL_MEMSYS_GET_STATIC_CONFIG_PARAMS_v25_06
          (undefined1 *param_1,long param_2,uint param_3,uint *param_4)

{
  undefined1 *puVar1;
  uint uVar2;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined1 *)0x0) && (param_2 != 0)) {
    uVar2 = *param_4;
    if ((param_3 < uVar2) || ((ulong)param_3 < (ulong)uVar2 + 0x28)) {
      return 2;
    }
    puVar1 = (undefined1 *)(param_2 + (ulong)uVar2);
    *param_1 = *puVar1;
    param_1[1] = puVar1[1];
    param_1[2] = puVar1[2];
    param_1[3] = puVar1[3];
    param_1[4] = puVar1[4];
    param_1[5] = puVar1[5];
    param_1[6] = puVar1[6];
    *(undefined8 *)(param_1 + 8) = *(undefined8 *)(puVar1 + 8);
    param_1[0x10] = puVar1[0x10];
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(puVar1 + 0x14);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(puVar1 + 0x18);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(puVar1 + 0x1c);
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(puVar1 + 0x20);
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(puVar1 + 0x24);
  }
  *param_4 = *param_4 + 0x28;
  return 0;
}


// ===== 004d9a90 deserialize_NV90E6_CTRL_MASTER_GET_VIRTUAL_FUNCTION_ERROR_CONT_INTR_MASK_PARAMS_v25_13 =====

undefined8
deserialize_NV90E6_CTRL_MASTER_GET_VIRTUAL_FUNCTION_ERROR_CONT_INTR_MASK_PARAMS_v25_13
          (undefined4 *param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_4 == (uint *)0x0) {
    return 0x1f;
  }
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar1 = *param_4;
    if ((param_3 < uVar1) || ((ulong)param_3 < (ulong)uVar1 + 8)) {
      return 2;
    }
    puVar2 = (undefined4 *)(param_2 + (ulong)uVar1);
    *param_1 = *puVar2;
    param_1[1] = puVar2[1];
  }
  *param_4 = *param_4 + 8;
  return 0;
}


// ===== 004d9af0 deserialize_NV90E6_CTRL_MASTER_GET_VIRTUAL_FUNCTION_ERROR_CONT_INTR_MASK_PARAMS_v18_0B =====

undefined8
deserialize_NV90E6_CTRL_MASTER_GET_VIRTUAL_FUNCTION_ERROR_CONT_INTR_MASK_PARAMS_v18_0B(void)

{
  return 0x56;
}


// ===== 004d9b00 _rmPstateEventCallback =====

void _rmPstateEventCallback(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  char cVar2;
  long lVar3;
  undefined8 local_40;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  lVar3 = gpumgrGetGpu();
  uVar1 = *param_2;
  local_40 = 0;
  tmrGetCurrentTime_IMPL(*(undefined8 *)(lVar3 + 0x1b88),&local_40);
  cVar2 = gpuIsGpuFullPower_IMPL(lVar3);
  if ((((cVar2 != '\0') && (*(char *)(lVar3 + 0x44c) != '\0')) && (*(char *)(lVar3 + 0x44f) == '\0')
      ) && (((*(char *)(lVar3 + 0x450) == '\0' && (*(char *)(lVar3 + 0x451) == '\0')) &&
            ((*(char *)(lVar3 + 0x455) == '\0' &&
             (cVar2 = gpuCheckSysmemAccess_IMPL(lVar3), cVar2 != '\0')))))) {
    local_30 = (undefined4)local_40;
    local_34 = (undefined4)((ulong)local_40 >> 0x20);
    local_2c = uVar1;
    gpuNotifySubDeviceEvent_IMPL(lVar3,0x21,&local_34,0xc,uVar1,0);
    return;
  }
  nvDbg_Printf("src/kernel/vgpu/vgpu_events.c",0x20b,"_rmPstateEventCallback",4,
               "NVRM: GPU sanity check failed! gpuInstance = 0x%x.\n",param_1);
  return;
}


// ===== 004d9bf0 _setupGspEventInfrastructure =====

int _setupGspEventInfrastructure(long param_1,long *param_2)

{
  int iVar1;
  ulong uVar2;
  char cVar3;
  
  cVar3 = '\x01';
  if (*(char *)(*(long *)(&DAT_00001b90 + param_1) + 0xad05) != '\0') {
    cVar3 = (*(char *)((long)param_2 + 0x26154) == '\0') + '\x01';
  }
  iVar1 = _allocRpcMemDesc(param_1,0x1000,1,cVar3,0,param_2,param_2 + 1,param_2 + 2);
  if (iVar1 == 0) {
    uVar2 = memdescGetPte(*param_2,1,0);
    param_2[3] = uVar2 >> 0xc;
    portMemSet(param_2[1],0,*(undefined8 *)(*param_2 + 0x30));
    return 0;
  }
  nvDbg_Printf("src/kernel/vgpu/vgpu_events.c",0x70,"_setupGspEventInfrastructure",4,
               "NVRM: _setupGspEventInfrastructure: GSP Event buf memory setup failed: 0x%x\n",iVar1
              );
  return iVar1;
}


// ===== 004d9cc0 _teardownGspEventInfrastructure =====

void _teardownGspEventInfrastructure(undefined8 param_1,long param_2)

{
  *(undefined8 *)(param_2 + 0x18) = 0;
  _freeRpcMemDesc(param_1,param_2,param_2 + 8,param_2 + 0x10);
  return;
}


// ===== 004d9ce0 vgpuGetPendingEvent =====

uint vgpuGetPendingEvent(long param_1)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  
  lVar2 = *(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8);
  uVar3 = (uint)*(byte *)(lVar2 + 0x150);
  if (*(byte *)(lVar2 + 0x150) != 0) {
    iVar1 = *(int *)(*(long *)(lVar2 + 0x128) + 4);
    uVar3 = CONCAT31((int3)((uint)iVar1 >> 8),*(int *)(*(long *)(lVar2 + 0x120) + 0x48) != iVar1);
  }
  return uVar3;
}


// ===== 004d9d20 vgpuServiceEventGuestAllocated =====

undefined8 vgpuServiceEventGuestAllocated(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 *local_20;
  
  uVar1 = param_3[2];
  uVar2 = CliGetEventNotificationList(*param_3,param_3[1],0,&local_20);
  if ((int)uVar2 != 0) {
    return uVar2;
  }
  notifyEvents(param_1,*local_20,uVar1,0,0,0);
  return 1;
}


// ===== 004d9d90 vgpuServiceEventRC =====

ulong vgpuServiceEventRC(long param_1,undefined8 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  undefined8 uVar9;
  ulong uVar10;
  long lVar12;
  ulong uVar13;
  undefined8 *local_b8;
  uint local_a4;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90 [12];
  ulong uVar11;
  
  uVar1 = *param_3;
  uVar2 = param_3[1];
  iVar3 = param_3[6];
  uVar4 = param_3[7];
  uVar5 = param_3[9];
  uVar9 = gpuGetRmEngineType_IMPL(uVar4 & 0xffff);
  local_a4 = (uint)uVar9;
  nvDbg_Printf("src/kernel/vgpu/vgpu_events.c",0xe6,"vgpuServiceEventRC",4,
               "NVRM: ROBUST_CHANNEL error occurred (hClient = 0x%x hFifo = 0x%x chID = %d exceptType = %d engineID = 0x%x (0x%x)) ...\n"
               ,uVar1,uVar2,uVar5,iVar3,uVar4 & 0xffff,uVar9);
  if ((param_1 != 0) && (*(long *)(param_1 + 0x1bc0) != 0)) {
    cVar6 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1);
    if (cVar6 != '\0') {
      uVar9 = *(undefined8 *)(param_1 + 0x1bc0);
      local_a0 = 0;
      local_98 = 0;
      iVar7 = serverGetClientUnderLock(g_resServ,uVar1,&local_a0);
      if (iVar7 != 0) {
        uVar10 = nvAssertOkFailedNoLog
                           (iVar7,"serverGetClientUnderLock(&g_resServ, hClient, &pClient)",
                            "src/kernel/vgpu/vgpu_events.c",0xf1);
        return uVar10;
      }
      iVar7 = deviceGetByGpu_IMPL(local_a0,param_1,1,&local_98);
      if (iVar7 != 0) {
        uVar10 = nvAssertOkFailedNoLog
                           (iVar7,"deviceGetByGpu(pClient, pGpu, NV_TRUE, &pDevice)",
                            "src/kernel/vgpu/vgpu_events.c",0xf4);
        return uVar10;
      }
      iVar7 = kmigmgrGetInstanceRefFromDevice_IMPL(param_1,uVar9,local_98,local_90);
      if (iVar7 != 0) {
        uVar10 = nvAssertOkFailedNoLog
                           (iVar7,
                            "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)"
                            ,"src/kernel/vgpu/vgpu_events.c",0xf7);
        return uVar10;
      }
      iVar7 = kmigmgrGetLocalToGlobalEngineType_IMPL
                        (param_1,uVar9,local_90[0],local_90[1],local_a4,&local_a4);
      if (iVar7 != 0) {
        uVar10 = nvAssertOkFailedNoLog
                           (iVar7,
                            "kmigmgrGetLocalToGlobalEngineType(pGpu, pKernelMIGManager, ref, rmEngineType, &rmEngineType)"
                            ,"src/kernel/vgpu/vgpu_events.c",0xfb);
        return uVar10;
      }
    }
  }
  uVar4 = local_a4;
  local_b8 = &local_98;
  uVar13 = (ulong)local_a4;
  local_98 = 0;
  uVar9 = gpuGetKernelFifoShared_IMPL(param_1);
  uVar10 = 0;
  do {
    uVar8 = (int)uVar10 + 0x20;
    uVar11 = (ulong)uVar8;
    *(undefined8 *)((long)local_90 + uVar10) = 0;
    *(undefined8 *)((long)local_90 + uVar10 + 8) = 0;
    *(undefined8 *)((long)local_90 + uVar10 + 0x10) = 0;
    *(undefined8 *)((long)local_90 + uVar10 + 0x18) = 0;
    uVar10 = uVar11;
  } while (uVar8 < 0x40);
  *(undefined8 *)((long)local_90 + uVar11) = 0;
  *(undefined8 *)((long)local_90 + uVar11 + 8) = 0;
  *(undefined8 *)((long)local_90 + uVar11 + 0x10) = 0;
  iVar7 = kfifoGetChidMgrFromType_IMPL(param_1,uVar9,2,uVar13,local_b8);
  if (iVar7 == 0) {
    lVar12 = kfifoChidMgrGetKernelChannel_IMPL(param_1,uVar9,local_98,uVar5);
    if (lVar12 == 0) {
      uVar13 = nvCheckFailedNoLog(4,"pKernelChannel != NULL","src/kernel/vgpu/vgpu_events.c",0xac);
    }
    else {
      if ((iVar3 != 0x1f) ||
         ((*(char *)(param_1 + 0x908) != '\0' && (*(char *)(param_1 + 0x4913) == '\0')))) {
        krcErrorSetNotifier_IMPL(param_1,*(undefined8 *)(param_1 + 0x1c18),lVar12,iVar3,uVar4,1);
      }
      krcErrorInvokeCallback_IMPL
                (param_1,*(undefined8 *)(param_1 + 0x1c18),lVar12,local_90,iVar3,2,uVar13,
                 0xffffffffffffffff);
    }
  }
  else {
    uVar13 = nvAssertFailedNoLog("status == NV_OK","src/kernel/vgpu/vgpu_events.c",0xa8);
  }
  return uVar13;
}


// ===== 004da110 vgpuServiceEventVnc =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

void vgpuServiceEventVnc(undefined8 param_1,long param_2)

{
  int iVar1;
  long lVar2;
  bool bVar3;
  
  bVar3 = *(int *)(*(long *)(param_2 + 0x118) + 0xa0) != 0;
  *(bool *)(param_2 + 0x1ad) = bVar3;
  if (!bVar3) {
    return;
  }
  lVar2 = gpuGetRpc();
  if (lVar2 != 0) {
    iVar1 = (**(code **)(lVar2 + 0x2e8))
                      (param_1,lVar2,*(undefined4 *)(param_2 + 0x1a8),param_2 + 0x15c,1,
                       *(code **)(lVar2 + 0x2e8));
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/vgpu/vgpu_events.c",0x112,"vgpuServiceEventVnc",4,
                   "NVRM: SET_SURFACE_PROPERTY RPC failed with error : 0x%x\n",iVar1);
      return;
    }
  }
  return;
}


// ===== 004da1b0 vgpuServiceEventPstate =====

void vgpuServiceEventPstate(undefined8 param_1,long param_2)

{
  int iVar1;
  
  iVar1 = osQueueWorkItem(param_1,_rmPstateEventCallback,*(long *)(param_2 + 0x118) + 0x90,0x81);
  if (iVar1 == 0) {
    return;
  }
  nvDbg_Printf("src/kernel/vgpu/vgpu_events.c",0x129,"vgpuServiceEventPstate",4,
               "NVRM: Failed to schedule Pstate callback! 0x%x\n",iVar1);
  return;
}


// ===== 004da210 vgpuServiceEventEcc =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void vgpuServiceEventEcc(long param_1,long param_2)

{
  long *plVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  char cVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  
  lVar7 = gpuGetStaticInfo();
  lVar5 = *(long *)(param_2 + 0x118);
  iVar2 = *(int *)(lVar5 + 0x94);
  uVar3 = *(uint *)(lVar5 + 0x98);
  uVar4 = *(uint *)(lVar5 + 0x9c);
  if (uVar3 < 0x29) {
    uVar8 = (ulong)uVar3;
    uVar9 = (ulong)uVar4;
    if (iVar2 == 0x6f) {
      plVar1 = (long *)(lVar7 + 0x1ea98 + uVar8 * 0x28);
      *plVar1 = *plVar1 + uVar9;
      plVar1 = (long *)(lVar7 + 0x1eaa0 + uVar8 * 0x28);
      *plVar1 = *plVar1 + uVar9;
    }
    else {
      plVar1 = (long *)(lVar7 + 0x1ea88 + uVar8 * 0x28);
      *plVar1 = *plVar1 + uVar9;
      plVar1 = (long *)(lVar7 + 0x1ea90 + uVar8 * 0x28);
      *plVar1 = *plVar1 + uVar9;
    }
  }
  cVar6 = (**(code **)(param_1 + 0x350))(param_1);
  if (cVar6 != '\0') {
    *(bool *)(lVar7 + 0x1f0e8) = *(int *)(*(long *)(param_2 + 0x118) + 0xa8) != 0;
  }
  if (uVar4 == 0) {
    return;
  }
  gpuNotifySubDeviceEvent_IMPL(param_1,iVar2,0,0,uVar4,uVar3 & 0xffff);
  return;
}


// ===== 004da300 vgpuServiceEventInbandResponse =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void vgpuServiceEventInbandResponse(long param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  char local_39 [9];
  
  lVar3 = gpuGetRpc();
  local_39[0] = '\x01';
  if ((lVar3 != 0) && (lVar4 = 0, *(char *)(param_2 + 0x150) != '\0')) {
    while (uVar1 = *(uint *)(*(long *)(param_2 + 0x118) + 0xb0), uVar1 != 0) {
      if (lVar4 == 0) {
        lVar4 = portMemAllocNonPaged(0x1404);
      }
      portMemSet(lVar4,0,0x1404);
      if ((uVar1 & 1) != 0) {
        iVar2 = (**(code **)(lVar3 + 0x250))(param_1,lVar3,lVar4,1,local_39);
        if (iVar2 == 0) {
          knvlinkInbandMsgCallbackDispatcher_IMPL
                    (param_1,*(undefined8 *)(param_1 + 0x1ce8),0x1404,lVar4);
        }
        break;
      }
      if ((((uVar1 & 2) != 0) &&
          ((iVar2 = (**(code **)(lVar3 + 0x250))(param_1,lVar3,lVar4,3,local_39), iVar2 != 0 ||
           (iVar2 = knvlinkInbandMsgCallbackDispatcher_IMPL
                              (param_1,*(undefined8 *)(param_1 + 0x1ce8),0x1404,lVar4), iVar2 != 0))
          )) || (local_39[0] == '\0')) break;
    }
    if (lVar4 != 0) {
      portMemFree(lVar4);
      return;
    }
  }
  return;
}


// ===== 004da460 vgpuServiceEvents =====

void vgpuServiceEvents(long param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(*(long *)(param_2 + 0x120) + 0x48);
  *(uint *)(param_2 + 0x20) = uVar2;
  uVar1 = *(uint *)(*(long *)(param_2 + 0x128) + 4);
  *(uint *)(param_2 + 0x24) = uVar1;
  if (uVar1 == uVar2) {
    return;
  }
  do {
    uVar1 = *(uint *)(*(long *)(param_2 + 8) + (ulong)uVar2 * 0x28 + 0xc);
    uVar2 = uVar1 & 0xf;
    if (uVar2 == 0) {
      vgpuServiceEventGuestAllocated(param_1,param_2);
    }
    else if (uVar2 == 1) {
      uVar1 = uVar1 >> 0x10;
      if (uVar1 == 5) {
        vgpuServiceEventEcc(param_1,param_2);
      }
      else if (uVar1 < 6) {
        if (uVar1 == 3) {
          vgpuServiceEventVnc(param_1,param_2);
        }
        else if (uVar1 == 4) {
          vgpuServiceEventPstate(param_1,param_2);
        }
        else if (uVar1 == 0) {
          vgpuServiceEventRC(param_1,param_2);
        }
        else {
LAB_004da5c0:
          nvDbg_Printf("src/kernel/vgpu/vgpu_events.c",0x1ce,"vgpuServiceEvents",4,
                       "NVRM: Unsupported vgpu event type %d\n");
        }
      }
      else if (uVar1 == 7) {
        vgpuServiceEventInbandResponse(param_1,param_2);
      }
      else if (uVar1 == 8) {
        gspTraceServiceVgpuEventTracing(param_1);
      }
      else {
        if (uVar1 != 6) goto LAB_004da5c0;
        *(undefined4 *)(param_1 + 0x49e0) = *(undefined4 *)(*(long *)(param_2 + 0x118) + 0xac);
      }
    }
    uVar1 = (*(int *)(param_2 + 0x20) + 1U) % 0x66;
    *(uint *)(param_2 + 0x20) = uVar1;
    *(uint *)(*(long *)(param_2 + 0x120) + 0x48) = uVar1;
    uVar1 = *(uint *)(*(long *)(param_2 + 0x128) + 4);
    uVar2 = *(uint *)(param_2 + 0x20);
    *(uint *)(param_2 + 0x24) = uVar1;
    if (uVar2 == uVar1) {
      return;
    }
  } while( true );
}


// ===== 004da620 vgpuService =====

void vgpuService(long param_1)

{
  if (*(char *)(*(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8) + 0x150) == '\0') {
    return;
  }
  vgpuServiceEvents();
  return;
}


// ===== 004da650 vgpuFreeSysmemPfnBitMapNode =====

void vgpuFreeSysmemPfnBitMapNode(undefined8 *param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  
  if (((param_1 != (undefined8 *)0x0) && (lVar1 = param_1[2], lVar1 != 0)) &&
     (*(char *)(lVar1 + 100) != '\0')) {
    uVar2 = param_1[1];
    uVar3 = *param_1;
    uVar4 = memdescGetFlag(lVar1,0x200);
    memdescUnmapOld(param_1[2],uVar4,uVar3,uVar2);
    memdescFree(param_1[2]);
    memdescDestroy(param_1[2]);
    portMemFree(param_1);
    return;
  }
  return;
}


// ===== 004da6d0 vgpuGspSysmemPfnMakeBufferAddress =====

ulong vgpuGspSysmemPfnMakeBufferAddress(undefined8 param_1,long param_2)

{
  int iVar1;
  
  iVar1 = memdescGetAddressSpace();
  if (iVar1 == 1) {
    return param_2 << 0xc | 3;
  }
  nvDbg_Printf("src/kernel/vgpu/vgpu_util.c",0x4b,"vgpuGspSysmemPfnMakeBufferAddress",4,
               "NVRM: Dirty sysmem pfn: Invlid address space %d\n",iVar1);
  return 0;
}


// ===== 004da740 vgpuAllocSysmemPfnBitMapNode =====

int vgpuAllocSysmemPfnBitMapNode(long param_1,long *param_2,uint param_3)

{
  long lVar1;
  short *psVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  long *plVar7;
  ulong uVar8;
  short *psVar9;
  ulong uVar10;
  
  lVar1 = *(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8);
  uVar4 = listCount_IMPL(&DAT_0054eac0);
  if ((uVar4 == param_3) && (param_2 != (long *)0x0)) {
    lVar6 = portMemAllocNonPaged(0x48);
    *param_2 = lVar6;
    if (lVar6 == 0) {
      iVar5 = 0x51;
      nvDbg_Printf("src/kernel/vgpu/vgpu_util.c",0x76,"vgpuAllocSysmemPfnBitMapNode",4,
                   "NVRM: failed to allocate memory for sysmem pfn bitmap node \n");
    }
    else {
      portMemSet(lVar6,0,0x48);
      *(undefined8 *)(*param_2 + 0x10) = 0;
      *(undefined8 *)*param_2 = 0;
      *(undefined8 *)(*param_2 + 8) = 0;
      *(ulong *)(*param_2 + 0x18) = (ulong)(param_3 * 0x1000000);
      *(ulong *)(*param_2 + 0x20) = (ulong)(param_3 * 0x1000000 + 0x1000000);
      *(uint *)(*param_2 + 0x30) = param_3;
      *(ulong *)(*param_2 + 0x28) =
           (-(ulong)(*(char *)(lVar1 + 0x150) == '\0') & 0xfffffffffffff000) + 0x201000;
      iVar5 = memdescCreate(*param_2 + 0x10,param_1,*(undefined8 *)(*param_2 + 0x28),0,0,1,0,0);
      if (iVar5 == 0) {
        memdescSetFlag(*(undefined8 *)(*param_2 + 0x10),0x200,1);
        *(undefined4 *)(*(long *)(*param_2 + 0x10) + 0x9c) = 0x79;
        iVar5 = memdescAlloc(*(undefined8 *)(*param_2 + 0x10));
        if (iVar5 == 0) {
          lVar6 = *param_2;
          uVar3 = memdescGetFlag(*(undefined8 *)(lVar6 + 0x10),0x200);
          iVar5 = memdescMapOld(*(undefined8 *)(*param_2 + 0x10),0,*(undefined8 *)(*param_2 + 0x28),
                                uVar3,3,lVar6,lVar6 + 8);
          plVar7 = (long *)*param_2;
          if (iVar5 == 0) {
            psVar9 = DAT_0054eaa0;
            if (*(char *)(lVar1 + 0x150) != '\0') {
              psVar9 = (short *)(*plVar7 + 0x200000);
            }
            uVar10 = 0;
            while( true ) {
              uVar8 = memdescGetPte(plVar7[2],1,uVar10 & 0xffffffff);
              *(ulong *)(psVar9 + uVar10 * 4) = uVar8 >> 0xc;
              psVar2 = DAT_0054eaa0;
              uVar10 = uVar10 + 1;
              if (uVar10 == 0x200) break;
              plVar7 = (long *)*param_2;
            }
            if (*(char *)(lVar1 + 0x150) != '\0') {
              if (param_3 < 0x1ff) {
                uVar10 = memdescGetPte(*(undefined8 *)(*param_2 + 0x10),1,0x200);
                iVar5 = memdescGetAddressSpace(*(undefined8 *)(*param_2 + 0x10));
                if (iVar5 == 1) {
                  uVar10 = uVar10 & 0xfffffffffffff000 | 3;
                }
                else {
                  nvDbg_Printf("src/kernel/vgpu/vgpu_util.c",0x4b,
                               "vgpuGspSysmemPfnMakeBufferAddress",4,
                               "NVRM: Dirty sysmem pfn: Invlid address space %d\n",iVar5);
                  uVar10 = 0;
                }
                *(ulong *)(psVar2 + (ulong)param_3 * 4 + 4) = uVar10;
              }
              else {
                nvDbg_Printf("src/kernel/vgpu/vgpu_util.c",0xd1,"vgpuAllocSysmemPfnBitMapNode",4,
                             "NVRM: Exhausted limit of dirty sysmem tracking. Migration will not work correctly.\n"
                            );
                nvAssertFailedNoLog(&DAT_00d9dbcc,"src/kernel/vgpu/vgpu_util.c",0xd2);
              }
              *psVar2 = (short)param_3 + 1;
            }
            *(long *)(&DAT_0054ead8 + (ulong)param_3 * 8) = *param_2;
            return 0;
          }
          nvDbg_Printf("src/kernel/vgpu/vgpu_util.c",0xaf,"vgpuAllocSysmemPfnBitMapNode",4,
                       "NVRM: Cannot map sysmem pfn bitmap node buffer (size = 0x%llx)\n",plVar7[5])
          ;
        }
        else {
          nvDbg_Printf("src/kernel/vgpu/vgpu_util.c",0xa2,"vgpuAllocSysmemPfnBitMapNode",4,
                       "NVRM: Cannot alloc sysmem pfn bitmap node buffer\n");
        }
      }
      else {
        nvDbg_Printf("src/kernel/vgpu/vgpu_util.c",0x96,"vgpuAllocSysmemPfnBitMapNode",4,
                     "NVRM: Cannot alloc memory descriptor for sysmem pfn bitmap node (size = 0x%llx)\n"
                     ,*(undefined8 *)(*param_2 + 0x28));
      }
      vgpuFreeSysmemPfnBitMapNode(*param_2);
    }
  }
  else {
    iVar5 = 0x1f;
    nvDbg_Printf("src/kernel/vgpu/vgpu_util.c",0x6e,"vgpuAllocSysmemPfnBitMapNode",4,
                 "NVRM: Invalid argumets passed while allocating sysmem pfn bitmap node \n");
  }
  return iVar5;
}


// ===== 004dab30 vgpuUpdateSysmemPfnBitMap =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int vgpuUpdateSysmemPfnBitMap(long param_1,long param_2,char param_3)

{
  ulong *puVar1;
  short sVar2;
  long *plVar3;
  byte bVar4;
  ulong uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  ulong uVar9;
  ulong uVar10;
  long lVar11;
  long lVar12;
  ulong uVar13;
  short *psVar14;
  long local_40 [2];
  
  if ((*(char *)(param_1 + 0x472) == '\0') || (DAT_0054ea98 == '\0')) {
LAB_004dab52:
    iVar6 = 0;
  }
  else {
    iVar6 = listCount_IMPL(&DAT_0054eac0);
    if (iVar6 == 0) {
      nvAssertFailedNoLog("listCount(&(vgpuSysmemPfnInfo.listVgpuSysmemPfnBitmapHead)) > 0",
                          "src/kernel/vgpu/vgpu_util.c",0x1b3);
    }
    else {
      if (DAT_0054ea90 != 0) {
        uVar9 = 0;
        if (*(long *)(param_2 + 0x18) != 0) {
LAB_004dac08:
          do {
            uVar10 = memdescGetPte(param_2,0,uVar9);
            uVar13 = uVar10 >> 0xc;
            if ((param_3 != '\0') && (vgpuSysmemPfnInfo <= uVar13)) {
              nvDbg_Printf("src/kernel/vgpu/vgpu_util.c",0x1c0,"vgpuUpdateSysmemPfnBitMap",1,
                           "NVRM: Update sysmem pfn bitmap for pfn: 0x%llx > guestMaxPfn: 0x%llx\n",
                           uVar13,vgpuSysmemPfnInfo);
              uVar5 = vgpuSysmemPfnInfo;
              DAT_0054ea98 = '\0';
              do {
                local_40[0] = 0;
                uVar8 = listCount_IMPL(&DAT_0054eac0);
                iVar6 = vgpuAllocSysmemPfnBitMapNode(param_1,local_40,uVar8);
                lVar11 = local_40[0];
                if (iVar6 != 0) {
                  nvDbg_Printf("src/kernel/vgpu/vgpu_util.c",0x102,"vgpuExpandSysmemPfnBitMapList",4
                               ,"NVRM: Failed to alloc sysmem pfn bitmap node\n");
                  goto LAB_004dade5;
                }
                listAppendExisting_IMPL(&DAT_0054eac0,local_40[0]);
                vgpuSysmemPfnInfo = *(ulong *)(lVar11 + 0x20);
                _DAT_0054ea88 = vgpuSysmemPfnInfo >> 3;
              } while (vgpuSysmemPfnInfo <= uVar13);
              lVar12 = portMemAllocNonPaged(vgpuSysmemPfnInfo * 2);
              if (lVar12 == 0) {
                iVar6 = 0x1a;
                nvDbg_Printf("src/kernel/vgpu/vgpu_util.c",0x112,"vgpuExpandSysmemPfnBitMapList",4,
                             "NVRM: failed to allocate sysmem pfn refcount array\n");
                nvAssertFailedNoLog(&DAT_00d9dbcc,"src/kernel/vgpu/vgpu_util.c",0x113);
LAB_004dade5:
                portMemFree(DAT_0054ea90);
                lVar11 = listHead_IMPL(&DAT_0054eac0);
                while (lVar11 != 0) {
                  lVar12 = listNext_IMPL(&DAT_0054eac0,lVar11);
                  listRemoveIntrusive_IMPL(&DAT_0054eac0,lVar11);
                  vgpuFreeSysmemPfnBitMapNode(lVar11);
                  lVar11 = lVar12;
                }
LAB_004dae41:
                nvDbg_Printf("src/kernel/vgpu/vgpu_util.c",0x1c5,"vgpuUpdateSysmemPfnBitMap",4,
                             "NVRM: Cannot re-allocate sysmem PFN bitmap :%x\n",iVar6);
                return iVar6;
              }
              portMemSet(lVar12,0,vgpuSysmemPfnInfo * 2);
              portMemCopy(lVar12,vgpuSysmemPfnInfo * 2,DAT_0054ea90,uVar5 * 2);
              portMemFree(DAT_0054ea90);
              DAT_0054ea98 = '\x01';
              DAT_0054ea90 = lVar12;
              if ((*(long *)(lVar11 + 0x10) != 0) && (iVar6 = memdescGetAddressSpace(), iVar6 == 1))
              {
                lVar11 = listHead_IMPL(&DAT_0054eac0);
                while (lVar12 = lVar11, lVar11 != 0) {
                  while (lVar11 = listNext_IMPL(&DAT_0054eac0,lVar12),
                        *(char *)(lVar12 + 0x34) == '\0') {
                    iVar6 = vgpuUpdateSysmemPfnBitMap(param_1,*(undefined8 *)(lVar12 + 0x10),1);
                    if (iVar6 != 0) {
                      nvDbg_Printf("src/kernel/vgpu/vgpu_util.c",0x142,
                                   "vgpuExpandSysmemPfnBitMapList",1,
                                   "NVRM: Failed to update sysmemPfnMap info in PFN bitmap, error 0x%x\n"
                                   ,iVar6);
                      goto LAB_004dae41;
                    }
                    *(undefined1 *)(lVar12 + 0x34) = 1;
                    lVar12 = lVar11;
                    if (lVar11 == 0) goto LAB_004dac35;
                  }
                }
              }
            }
LAB_004dac35:
            uVar7 = listCount_IMPL(&DAT_0054eac0);
            if ((uVar7 <= (uint)(uVar10 >> 0x24)) ||
               (plVar3 = *(long **)(&DAT_0054ead8 + (uVar10 >> 0x24) * 8), plVar3 == (long *)0x0)) {
              nvDbg_Printf("src/kernel/vgpu/vgpu_util.c",0x1d0,"vgpuUpdateSysmemPfnBitMap",4,
                           "NVRM: Sysmem PFN bitmap update failed :%x\n",0x57);
              return 0x57;
            }
            lVar11 = uVar13 * 2;
            uVar7 = (uint)(uVar10 >> 0x12);
            if (param_3 == '\0') {
              psVar14 = (short *)(DAT_0054ea90 + lVar11);
              sVar2 = *psVar14;
              if (sVar2 == 0) {
                nvAssertFailedNoLog("vgpuSysmemPfnInfo.sysmemPfnRefCount[pfn] > 0",
                                    "src/kernel/vgpu/vgpu_util.c",0x179);
                psVar14 = (short *)(DAT_0054ea90 + lVar11);
                sVar2 = *psVar14;
                if (sVar2 == 0) goto LAB_004dabf7;
              }
              *psVar14 = sVar2 + -1;
              if (*(short *)(DAT_0054ea90 + uVar13 * 2) == 0) {
                bVar4 = (byte)uVar13 & 0x3f;
                puVar1 = (ulong *)(*plVar3 + (ulong)(uVar7 & 0x3ffff) * 8);
                *puVar1 = *puVar1 & (-2L << bVar4 | 0xfffffffffffffffeU >> 0x40 - bVar4);
                uVar9 = (ulong)((int)uVar9 + 1);
                if (*(ulong *)(param_2 + 0x18) <= uVar9) break;
                goto LAB_004dac08;
              }
            }
            else {
              puVar1 = (ulong *)(*plVar3 + (ulong)(uVar7 & 0x3ffff) * 8);
              *puVar1 = *puVar1 | 1L << ((byte)uVar13 & 0x3f);
              *(short *)(lVar11 + DAT_0054ea90) = *(short *)(lVar11 + DAT_0054ea90) + 1;
            }
LAB_004dabf7:
            uVar9 = (ulong)((int)uVar9 + 1);
          } while (uVar9 < *(ulong *)(param_2 + 0x18));
        }
        goto LAB_004dab52;
      }
      nvAssertFailedNoLog("(vgpuSysmemPfnInfo.sysmemPfnRefCount != NULL)",
                          "src/kernel/vgpu/vgpu_util.c",0x1b5);
    }
    iVar6 = 0x38;
  }
  return iVar6;
}


// ===== 004db080 vgpuUpdateGuestSysmemPfnBitMap =====

undefined8 vgpuUpdateGuestSysmemPfnBitMap(long param_1,long param_2,undefined1 param_3)

{
  undefined8 uVar1;
  
  if ((((param_1 != 0) && (*(char *)(param_1 + 0x4913) != '\0')) &&
      (*(char *)(param_1 + 0x491e) == '\0')) &&
     ((*(int *)(param_2 + 0x68) == 1 && ((*(byte *)(param_2 + 10) & 0x40) == 0)))) {
    uVar1 = vgpuUpdateSysmemPfnBitMap(param_1,param_2,param_3);
    return uVar1;
  }
  return 0;
}


// ===== 004db0c0 vgpuapiConstruct_IMPL =====

undefined8 vgpuapiConstruct_IMPL(long param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = 0x56;
  if (*(char *)(*(long *)(*(long *)(param_1 + 0x128) + 0xe0) + 0x908) != '\0') {
    uVar1 = *(uint *)(param_3 + 8);
    uVar2 = *(undefined4 *)(param_3 + 4);
    *(long *)(param_1 + 0x138) = param_1;
    *(ulong *)(param_1 + 0x140) = (ulong)uVar1;
    *(ulong *)(param_1 + 0x148) = (ulong)uVar1;
    *(ulong *)(param_1 + 0x170) = CONCAT44(uVar2,uVar1);
    uVar3 = 0;
  }
  return uVar3;
}


// ===== 004db110 vgpuapiDestruct_IMPL =====

void vgpuapiDestruct_IMPL(long param_1)

{
  long lVar1;
  undefined1 local_28 [8];
  long local_20 [2];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  resGetFreeParams_IMPL(*(undefined8 *)(param_1 + 0x110),local_28,local_20);
  *(uint *)(local_20[0] + 0x30) = -(uint)(*(char *)(lVar1 + 0x908) == '\0') & 0x56;
  return;
}


// ===== 004db160 vgpuapiCtrlCmdVgpuDisplaySetSurfaceProperties_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

undefined8 vgpuapiCtrlCmdVgpuDisplaySetSurfaceProperties_IMPL(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  ulong uVar5;
  long lVar6;
  long local_30 [2];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  if (*(char *)(lVar1 + 0x484) != '\0') {
LAB_004db250:
    lVar6 = gpuGetRpc(lVar1);
    if (lVar6 != 0) {
      uVar4 = (**(code **)(lVar6 + 0x2e8))
                        (lVar1,lVar6,
                         *(undefined4 *)(**(long **)(*(long *)(param_1 + 0x110) + 0x48) + 0x48),
                         param_2,0,*(code **)(lVar6 + 0x2e8));
      return uVar4;
    }
    return 0;
  }
  local_30[0] = 0;
  uVar4 = memGetByHandle_IMPL(**(undefined8 **)(*(long *)(param_1 + 0x110) + 0x48),
                              *(undefined4 *)(param_2 + 8),local_30);
  if ((int)uVar4 == 0) {
    uVar4 = 0x36;
    if (*(long *)(*(long *)(*(long *)(local_30[0] + 0xe0) + 0x128) + 0xe0) == lVar1) {
      iVar2 = memdescGetAddressSpace(*(undefined8 *)(local_30[0] + 0x118));
      uVar4 = 0x31;
      if (iVar2 == 2) {
        uVar5 = memdescGetPhysAddr(*(undefined8 *)(local_30[0] + 0x118),1,
                                   *(undefined4 *)(param_2 + 0xc));
        uVar4 = 0x37;
        if (uVar5 >> 0x20 == 0) {
          *(int *)(param_2 + 0xc) = (int)uVar5;
          uVar3 = memdescGetPteKindForGpu
                            (*(undefined8 **)(local_30[0] + 0x118),
                             **(undefined8 **)(local_30[0] + 0x118));
          *(undefined4 *)(param_2 + 0x3c) = uVar3;
          goto LAB_004db250;
        }
      }
    }
  }
  return uVar4;
}


// ===== 004db2b0 vgpuapiCtrlCmdVgpuDisplayCleanupSurface_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

undefined8 vgpuapiCtrlCmdVgpuDisplayCleanupSurface_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0);
  lVar1 = gpuGetRpc(uVar2);
  if (lVar1 != 0) {
    uVar2 = (**(code **)(lVar1 + 0x1e8))
                      (uVar2,lVar1,
                       *(undefined4 *)(**(long **)(*(long *)(param_1 + 0x110) + 0x48) + 0x48),
                       param_2,*(code **)(lVar1 + 0x1e8));
    return uVar2;
  }
  return 0;
}


// ===== 004db330 vgpuapiCtrlCmdVGpuGetConfig_IMPL =====

undefined8 vgpuapiCtrlCmdVGpuGetConfig_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  
  lVar1 = gpuGetStaticInfo(*(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0));
  if (lVar1 != 0) {
    portMemCopy(param_2,0x48,lVar1 + 0xa6f0,0x48);
  }
  return 0;
}


// ===== 004db380 vgpuMgrFillVgpuType =====

void vgpuMgrFillVgpuType(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  
  puVar1 = param_1 + 0x41;
  portMemSet(param_2,0,0x818);
  *param_2 = *param_1;
  param_2[0xc4] = param_1[0x61];
  param_2[0xc5] = param_1[0x62];
  param_2[0xc6] = param_1[99];
  param_2[199] = param_1[100];
  param_2[200] = param_1[0x65];
  param_2[0xc9] = param_1[0x66];
  param_2[0xca] = param_1[0x67];
  param_2[0xcb] = param_1[0x68];
  param_2[0xcc] = param_1[0x69];
  param_2[0xcd] = param_1[0x6b];
  *(undefined8 *)(param_2 + 0xce) = *(undefined8 *)(param_1 + 0x6c);
  *(undefined8 *)(param_2 + 0xd0) = *(undefined8 *)(param_1 + 0x6e);
  *(undefined8 *)(param_2 + 0xd2) = *(undefined8 *)(param_1 + 0x70);
  *(undefined8 *)(param_2 + 0xd4) = *(undefined8 *)(param_1 + 0x72);
  *(undefined8 *)(param_2 + 0xd6) = *(undefined8 *)(param_1 + 0x74);
  *(undefined8 *)(param_2 + 0xd8) = *(undefined8 *)(param_1 + 0x76);
  *(undefined8 *)(param_2 + 0xda) = *(undefined8 *)(param_1 + 0x78);
  param_2[0xdc] = param_1[0x7a];
  *(undefined8 *)(param_2 + 0xde) = *(undefined8 *)(param_1 + 0x7c);
  param_2[0xe1] = param_1[0x4e1];
  param_2[0xe2] = param_1[0x4e2];
  param_2[0xe3] = param_1[0x4e3];
  param_2[0xe4] = param_1[0x4e4];
  param_2[0xe0] = param_1[0x7e];
  portStringCopy(param_2 + 1,0x40,param_1 + 1,0x40);
  portStringCopy(param_2 + 0x11,0x40,param_1 + 0x11,0x40);
  portStringCopy(param_2 + 0x21,0x80,puVar1,0x80);
  portStringCopy(param_2 + 0xe5,0x400,param_1 + 0xe0,0x1000);
  pcVar4 = "NVIDIA Virtual PC";
  portMemCopy(param_2 + 0x1e5,0x80,param_1 + 0x21,0x80);
  lVar3 = portStringLength(
                          "GRID-Virtual-PC,2.0;Quadro-Virtual-DWS,5.0;GRID-Virtual-WS,2.0;GRID-Virtual-WS-Ext,2.0"
                          );
  iVar2 = portStringCompare(puVar1,
                            "GRID-Virtual-PC,2.0;Quadro-Virtual-DWS,5.0;GRID-Virtual-WS,2.0;GRID-Virtual-WS-Ext,2.0"
                            ,lVar3 + 1);
  if (iVar2 != 0) {
    pcVar4 = "NVIDIA Virtual Applications";
    lVar3 = portStringLength("GRID-Virtual-Apps,3.0");
    iVar2 = portStringCompare(puVar1,"GRID-Virtual-Apps,3.0",lVar3 + 1);
    if (iVar2 != 0) {
      pcVar4 = "NVIDIA RTX Virtual Workstation";
      lVar3 = portStringLength("Quadro-Virtual-DWS,5.0;GRID-Virtual-WS,2.0;GRID-Virtual-WS-Ext,2.0")
      ;
      iVar2 = portStringCompare(puVar1,
                                "Quadro-Virtual-DWS,5.0;GRID-Virtual-WS,2.0;GRID-Virtual-WS-Ext,2.0"
                                ,lVar3 + 1);
      if (iVar2 != 0) {
        pcVar4 = "NVIDIA Cloud Gaming";
        lVar3 = portStringLength("GRID-vGaming,8.0");
        iVar2 = portStringCompare(puVar1,"GRID-vGaming,8.0",lVar3 + 1);
        if (iVar2 != 0) {
          lVar3 = portStringLength("NVIDIA-vComputeServer,9.0");
          iVar2 = portStringCompare(puVar1,"NVIDIA-vComputeServer,9.0",lVar3 + 1);
          if (iVar2 != 0) {
            return;
          }
          pcVar4 = "NVIDIA vGPU for Compute";
        }
      }
    }
  }
  lVar3 = portStringLength(pcVar4);
  portStringCopy(param_2 + 0x41,0x80,pcVar4,lVar3 + 1);
  return;
}


// ===== 004db6b0 vgpuMgrReserveSystemChannelIDs =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong vgpuMgrReserveSystemChannelIDs
                (long param_1,undefined4 *param_2,undefined4 param_3,undefined8 param_4,
                undefined8 param_5,undefined8 param_6,uint param_7,short param_8,uint param_9,
                long param_10)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  int *piVar6;
  ulong uVar7;
  undefined8 uVar8;
  char *pcVar9;
  int *piVar10;
  ulong uVar11;
  uint local_44;
  undefined8 local_40 [2];
  
  lVar5 = gpuGetKernelFifoShared_IMPL();
  local_40[0] = 0;
  if (param_9 == 0) {
    nvAssertFailedNoLog("engineFifoListNumEntries != 0",
                        "src/kernel/virtualization/common_vgpu_mgr.c",0x96);
    return 0x40;
  }
  if (param_8 == -1) {
    uVar4 = 4;
  }
  else {
    if ((((param_1 == 0) || (*(long *)(param_1 + 0x1bc0) == 0)) ||
        (cVar1 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1), cVar1 == '\0')) ||
       (cVar1 = kvgpumgrIsMigTimeslicingModeEnabled(param_1), cVar1 == '\0')) {
      uVar4 = 0xffffffff;
      local_44 = CONCAT31(local_44._1_3_,*(char *)(param_1 + 0x4a5));
      cVar1 = *(char *)(param_1 + 0x4a5);
    }
    else {
      uVar4 = kvgpuMgrGetSwizzIdFromDevice(param_1,param_6);
      uVar2 = kvgpuMgrGetHeterogeneousModePerGI(param_1,uVar4,&local_44);
      if (uVar2 != 0) {
        nvCheckOkFailedNoLog
                  (4,uVar2,
                   "kvgpuMgrGetHeterogeneousModePerGI(pGpu, swizzId, &bHeterogeneousModeEnabled)",
                   "src/kernel/virtualization/common_vgpu_mgr.c",0xa8);
        return (ulong)uVar2;
      }
      cVar1 = (char)local_44;
    }
    if (cVar1 == '\0') {
      iVar3 = kvgpumgrCheckHomogeneousPlacementSupported(param_1,uVar4);
      uVar4 = 4;
      if (iVar3 != 0) goto LAB_004db782;
      uVar2 = kvgpumgrHomogeneousGetChidOffset(*param_2,param_8,param_7,local_40);
      if (uVar2 != 0) {
        uVar8 = 0xb9;
        pcVar9 = 
        "kvgpumgrHomogeneousGetChidOffset(vgpuTypeInfo->vgpuTypeId, placementId, numChannels, &heapOffset)"
        ;
        goto LAB_004dba39;
      }
    }
    else {
      uVar2 = kvgpumgrHeterogeneousGetChidOffset(*param_2,param_8,param_7,local_40);
      uVar8 = 0xb1;
      pcVar9 = 
      "kvgpumgrHeterogeneousGetChidOffset(vgpuTypeInfo->vgpuTypeId, placementId, numChannels, &heapOffset)"
      ;
      if (uVar2 != 0) {
LAB_004dba39:
        nvAssertOkFailedNoLog(uVar2,pcVar9,"src/kernel/virtualization/common_vgpu_mgr.c",uVar8);
        return (ulong)uVar2;
      }
    }
    uVar4 = 0x14;
  }
LAB_004db782:
  uVar11 = 0;
  piVar10 = (int *)(param_10 + 8);
  piVar6 = piVar10 + (ulong)param_9 * 0x18;
  do {
    if (*piVar10 != 0x2d) {
      uVar7 = (**(code **)(lVar5 + 0x218))(param_1,lVar5,1,piVar10[-1],3,&local_44);
      if ((int)uVar7 != 0) {
        uVar8 = 0xd3;
        pcVar9 = 
        "kfifoEngineInfoXlate_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_FIFO_TAG, engineFifoList[i].engineData[ENGINE_INFO_TYPE_FIFO_TAG], ENGINE_INFO_TYPE_RUNLIST, &runlistId)"
        ;
        goto LAB_004db993;
      }
      uVar8 = kfifoGetChidMgr_IMPL(param_1,lVar5,local_44);
      iVar3 = kfifoChidMgrGetNumChannels_IMPL(param_1,lVar5,uVar8);
      cVar1 = hypervisorIsType_IMPL(2);
      if ((cVar1 == '\0') || (0x13 < *piVar10 - 9U)) {
LAB_004db960:
        uVar7 = (ulong)param_7;
      }
      else if (*(char *)(param_1 + 0x491f) == '\0') {
        uVar2 = param_2[0xc4];
        if (((uVar2 == 0) || ((uVar2 - 1 & uVar2) != 0)) &&
           ((*(long *)(param_1 + 0x1bc0) == 0 ||
            (cVar1 = kmigmgrIsMIGEnabled_IMPL(param_1), cVar1 == '\0')))) goto LAB_004db960;
        uVar7 = (ulong)(param_7 >> 1);
      }
      else {
        if (*(long *)(param_1 + 0x1bc0) != 0) {
          cVar1 = kmigmgrIsMIGEnabled_IMPL(param_1);
          if (cVar1 != '\0') {
            uVar7 = (ulong)(iVar3 - 0x20U) / (ulong)(uint)param_2[0xe3];
            goto LAB_004db880;
          }
        }
        uVar7 = (ulong)(iVar3 - 0x20U) / (ulong)(uint)param_2[0xc4];
      }
LAB_004db880:
      if ((uVar11 >> ((ulong)local_44 & 0x3f) & 1) == 0) {
        uVar7 = kfifoChidMgrReserveSystemChids_IMPL
                          (param_1,lVar5,uVar8,uVar7,uVar4,param_3,param_4,local_40[0],param_5,
                           param_6,param_9,param_10);
        if ((int)uVar7 != 0) {
          uVar8 = 0x104;
          pcVar9 = 
          "kfifoChidMgrReserveSystemChids(pGpu, pKernelFifo, pChidMgr, currentNumChannels, flags, gfid, pChidOffset, heapOffset, pChannelCount, pMigDevice, engineFifoListNumEntries, engineFifoList)"
          ;
LAB_004db993:
          nvAssertOkFailedNoLog
                    (uVar7 & 0xffffffff,pcVar9,"src/kernel/virtualization/common_vgpu_mgr.c",uVar8);
          return uVar7 & 0xffffffff;
        }
        if (*(int *)(lVar5 + 0x370) == 1) {
          return uVar7;
        }
        uVar11 = uVar11 | 1L << ((byte)local_44 & 0x3f);
      }
    }
    piVar10 = piVar10 + 0x18;
    if (piVar6 == piVar10) {
      return 0;
    }
  } while( true );
}


// ===== 004dbb00 vgpuMgrFreeSystemChannelIDs =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void vgpuMgrFreeSystemChannelIDs
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,uint param_6,long param_7)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  ulong uVar5;
  undefined4 *puVar6;
  uint local_3c [3];
  
  lVar2 = gpuGetKernelFifoShared_IMPL();
  if (param_6 == 0) {
    nvAssertFailedNoLog("engineFifoListNumEntries != 0",
                        "src/kernel/virtualization/common_vgpu_mgr.c",0x129);
    return;
  }
  puVar6 = (undefined4 *)(param_7 + 4);
  uVar5 = 0;
  puVar4 = puVar6 + (ulong)param_6 * 0x18;
  do {
    if (puVar6[1] != 0x2d) {
      iVar1 = (**(code **)(lVar2 + 0x218))(param_1,lVar2,1,*puVar6,3,local_3c);
      if (iVar1 != 0) {
        nvAssertFailedNoLog("kfifoEngineInfoXlate_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_FIFO_TAG, engineFifoList[i].engineData[ENGINE_INFO_TYPE_FIFO_TAG], ENGINE_INFO_TYPE_RUNLIST, &runlistId) == NV_OK"
                            ,"src/kernel/virtualization/common_vgpu_mgr.c",0x13b);
        return;
      }
      uVar3 = kfifoGetChidMgr_IMPL(param_1,lVar2,local_3c[0]);
      if ((uVar5 >> ((ulong)local_3c[0] & 0x3f) & 1) == 0) {
        iVar1 = kfifoChidMgrFreeSystemChids_IMPL
                          (param_1,lVar2,uVar3,param_2,param_3,param_4,param_5,param_6,param_7);
        if (iVar1 != 0) {
          nvAssertFailedNoLog("kfifoChidMgrFreeSystemChids(pGpu, pKernelFifo, pChidMgr, gfid, pChidOffset, pChannelCount, pMigDevice, engineFifoListNumEntries, engineFifoList) == NV_OK"
                              ,"src/kernel/virtualization/common_vgpu_mgr.c",0x14a);
          return;
        }
        if (*(int *)(lVar2 + 0x370) == 1) {
          return;
        }
        uVar5 = uVar5 | 1L << ((byte)local_3c[0] & 0x3f);
      }
    }
    puVar6 = puVar6 + 0x18;
    if (puVar4 == puVar6) {
      return;
    }
  } while( true );
}


// ===== 004dbc90 vgpuMgrGetVmsetCountToAllocate =====

int vgpuMgrGetVmsetCountToAllocate(long param_1,int param_2)

{
  char cVar1;
  int iVar2;
  
  if ((3 < param_2 - 0x25U) && (7 < param_2 - 1U)) {
    return 1;
  }
  iVar2 = gpuGetSchedulerPolicy_IMPL();
  if (iVar2 == 0) {
    return 1;
  }
  if (((param_1 != 0) && (*(long *)(param_1 + 0x1bc0) != 0)) &&
     (cVar1 = kmigmgrIsMIGEnabled_IMPL(param_1), cVar1 != '\0')) {
    cVar1 = rmcfg_IsGB20XorBetter(param_1);
    return (-(uint)(cVar1 == '\0') & 0xfffffff4) + 0xe;
  }
  return 0x22;
}


// ===== 004dbd20 vgpuMgrGetVgpuSsvid =====

undefined8 vgpuMgrGetVgpuSsvid(void)

{
  return 0x10de;
}


// ===== 004dbd30 vgpuMgrSetNominalFbSize =====

void vgpuMgrSetNominalFbSize(ulong *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  ulong uVar3;
  uint local_1c [3];
  
  if ((param_2[0xc4] == 1) && (*param_1 < *(ulong *)(param_2 + 0xd2))) {
    *param_1 = *(ulong *)(param_2 + 0xd2);
    iVar2 = param_2[0xe3];
  }
  else {
    iVar2 = param_2[0xe3];
  }
  if (iVar2 != 1) {
    return;
  }
  uVar1 = *param_2;
  iVar2 = kvgpumgrGetPartitionFlag(uVar1,local_1c);
  uVar3 = (ulong)(local_1c[0] & 3);
  if (iVar2 != 0) {
    nvDbg_Printf("src/kernel/virtualization/common_vgpu_mgr.c",0x19f,
                 "_vgpuMgrGetNominalFbSizeGIIndex",4,
                 "NVRM: partition flag not found for vgpuTypeId=%u; defaulting to FULL\n",uVar1);
    uVar3 = 0;
  }
  if (param_1[uVar3 + 1] < *(ulong *)(param_2 + 0xd2)) {
    param_1[uVar3 + 1] = *(ulong *)(param_2 + 0xd2);
  }
  return;
}


// ===== 004dbe00 vgpuMgrGetPlacementRegionSize =====

ulong vgpuMgrGetPlacementRegionSize(undefined8 param_1,ulong *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  ulong uVar3;
  uint local_1c;
  
  if (param_3[0xcc] == 0) {
    return *param_2 >> 0x1e;
  }
  uVar1 = *param_3;
  iVar2 = kvgpumgrGetPartitionFlag(uVar1,&local_1c);
  uVar3 = (ulong)(local_1c & 3);
  if (iVar2 != 0) {
    nvDbg_Printf("src/kernel/virtualization/common_vgpu_mgr.c",0x19f,
                 "_vgpuMgrGetNominalFbSizeGIIndex",4,
                 "NVRM: partition flag not found for vgpuTypeId=%u; defaulting to FULL\n",uVar1);
    uVar3 = 0;
  }
  return param_2[uVar3 + 1] >> 0x1e;
}


// ===== 004dbe90 _dummyHypervIsP2PSupported =====

undefined8 _dummyHypervIsP2PSupported(void)

{
  return 0;
}


// ===== 004dbea0 _childPartitionDetection =====

/* WARNING: Type propagation algorithm not settling */

undefined8 _childPartitionDetection(undefined8 param_1,undefined1 *param_2)

{
  int iVar1;
  uint local_24;
  uint local_20 [4];
  
  local_24 = 0;
  local_20[0] = 0;
  local_20[1] = 0;
  if (param_2 == (undefined1 *)0x0) {
    nvAssertFailedNoLog("result != NULL","src/kernel/virtualization/hypervisor/hyperv/hyperv.c",0x38
                       );
  }
  *param_2 = 0;
  iVar1 = osNv_cpuid(0x40000003,0,local_20 + 1,local_20,local_20 + 1);
  if (iVar1 != 0) {
    iVar1 = osNv_cpuid(0x40000004,0,&local_24,local_20 + 1,local_20 + 1);
    if (iVar1 != 0) {
      if (((local_20[0] & 0x1000) != 0) && ((local_24 & 0x1000) == 0)) {
        *param_2 = 0;
        return 0;
      }
      *param_2 = 1;
      return 0;
    }
  }
  nvDbg_Printf("src/kernel/virtualization/hypervisor/hyperv/hyperv.c",0x3f,
               "_childPartitionDetection",3,"NVRM: CPUID is NOT supported!\n");
  return 0x56;
}


// ===== 004dbf90 hypervisorDestruct_IMPL =====

void hypervisorDestruct_IMPL(long param_1)

{
  *(undefined4 *)(param_1 + 0x4c) = 4;
  return;
}


// ===== 004dbfa0 hypervisorConstruct_IMPL =====

undefined8 hypervisorConstruct_IMPL(long param_1)

{
  _hypervisorOps._0_8_ = xenHypervisorOps;
  _hypervisorOps._8_8_ = PTR_s_XenVMMXenVMM_005a37e8;
  _hypervisorOps._16_8_ = PTR__dummyXenPostDetection_005a37f0;
  _hypervisorOps._24_8_ = PTR__dummyXenIsP2PSupported_005a37f8;
  _hypervisorOps._96_8_ = kvmHypervisorOps;
  _hypervisorOps._104_8_ = PTR_s_KVMKVMKVM_005a37a8;
  _hypervisorOps._112_8_ = PTR__dummyKvmChildPartitionDetection_005a37b0;
  _hypervisorOps._120_8_ = PTR__dummyKvmIsP2PSupported_005a37b8;
  _hypervisorOps._64_8_ = hypervHypervisorOps;
  _hypervisorOps._72_8_ = PTR_s_Microsoft_Hv_005a3788;
  _hypervisorOps._80_8_ = PTR__childPartitionDetection_005a3790;
  _hypervisorOps._88_8_ = PTR__dummyHypervIsP2PSupported_005a3798;
  _hypervisorOps._32_8_ = vmwareHypervisorOps;
  _hypervisorOps._40_8_ = PTR_s_VMwareVMware_005a37c8;
  _hypervisorOps._48_8_ = PTR__dummyVmwareChildPartitionDetection_005a37d0;
  _hypervisorOps._56_8_ = PTR__dummyVmwareIsP2PSupported_005a37d8;
  *(undefined4 *)(param_1 + 0x4c) = 4;
  *(undefined1 *)(param_1 + 0x49) = 0;
  return 0;
}


// ===== 004dc0a0 hypervisorPcieP2pDetection_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 hypervisorPcieP2pDetection_IMPL(long param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  char cVar5;
  undefined2 local_2f;
  char local_2d;
  undefined4 local_2c [3];
  
  local_2c[0] = 0;
  cVar1 = -1;
  do {
    cVar5 = cVar1;
    lVar3 = gpumgrGetNextGpu(param_2,local_2c);
    if (lVar3 == 0) {
      return 1;
    }
  } while ((*(char *)(lVar3 + 0x7e8) != '\0') &&
          ((cVar1 = *(char *)(lVar3 + 0x7e9), cVar5 == -1 || (cVar5 == cVar1))));
  local_2c[0] = 0;
  while( true ) {
    lVar3 = gpumgrGetNextGpu(param_2,local_2c);
    if (lVar3 == 0) {
      return 1;
    }
    if (*(char *)(lVar3 + 0x4912) == '\0') break;
    local_2d = '\0';
    local_2f = 0;
    iVar2 = (**(code **)(lVar3 + 0x3b90))
                      (lVar3 + 0x3b58,*(undefined4 *)(lVar3 + 0x3b34),
                       *(undefined4 *)(lVar3 + 0x3b3c),0x20800ab8,&local_2f,3);
    if ((iVar2 != 0) || (local_2f._1_1_ != '\0' || local_2d != '\0')) break;
  }
  cVar1 = hypervisorIsVgxHyper_IMPL();
  if (cVar1 == '\0') {
    uVar4 = (**(code **)(_hypervisorOps + (ulong)*(uint *)(param_1 + 0x4c) * 0x20 + 0x18))(param_2);
    return uVar4;
  }
  return 0;
}


// ===== 004dc1d0 hypervisorDetection_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 hypervisorDetection_IMPL(long param_1,undefined8 param_2)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  uint uVar5;
  uint uVar6;
  undefined4 local_48;
  undefined1 local_44 [4];
  undefined1 local_40 [4];
  undefined1 local_3c [12];
  
  cVar1 = hypervisorIsVgxHyper_IMPL();
  if (cVar1 == '\0') {
    local_48 = 0;
    uVar5 = 0x40000000;
    uVar6 = 0;
    do {
      iVar2 = osNv_cpuid(uVar5,0,&local_48,local_44,local_40,local_3c);
      if (iVar2 == 0) {
        nvDbg_Printf("src/kernel/virtualization/hypervisor/hypervisor.c",0x95,
                     "_hypervisorDetection_HVM",3,"NVRM: CPUID is NOT supported!\n");
        return 0x56;
      }
      lVar4 = 0;
      do {
        iVar2 = portMemCmp(*(undefined8 *)(_hypervisorOps + lVar4 * 0x20 + 8),local_44,0xc);
        if ((iVar2 == 0) && (uVar6 < uVar5)) {
          *(int *)(param_1 + 0x4c) = (int)lVar4;
          uVar6 = uVar5;
        }
        lVar4 = lVar4 + 1;
      } while (lVar4 != 4);
      uVar5 = uVar5 + 0x100;
    } while (uVar5 != 0x40001000);
    if (uVar6 == 0) {
      return 0x56;
    }
    uVar3 = (**(code **)(_hypervisorOps + (ulong)*(uint *)(param_1 + 0x4c) * 0x20 + 0x10))
                      (param_2,param_1 + 0x4a);
    if ((int)uVar3 != 0) {
      return uVar3;
    }
    cVar1 = *(char *)(param_1 + 0x4a);
    if (*(int *)(param_1 + 0x4c) == 2) {
      if (cVar1 != '\0') {
        *(undefined1 *)(param_1 + 0x49) = 1;
        goto LAB_004dc300;
      }
      *(undefined1 *)(param_1 + 0x50) = 1;
      *(undefined1 *)(param_1 + 0x49) = 1;
      goto LAB_004dc205;
    }
  }
  else {
    cVar1 = *(char *)(param_1 + 0x4a);
  }
  *(undefined1 *)(param_1 + 0x49) = 1;
  if (cVar1 != '\0') {
LAB_004dc300:
    nvDbg_Printf("src/kernel/virtualization/hypervisor/hypervisor.c",0x79,"hypervisorDetection_IMPL"
                 ,2,"NVRM: Found HVM kernel running on hypervisor: %s.\n",
                 *(undefined8 *)(_hypervisorOps + (ulong)*(uint *)(param_1 + 0x4c) * 0x20));
    return 0;
  }
LAB_004dc205:
  cVar1 = hypervisorIsVgxHyper_IMPL();
  if (cVar1 != '\0') {
    nvDbg_Printf("src/kernel/virtualization/hypervisor/hypervisor.c",0x7f,"hypervisorDetection_IMPL"
                 ,2,"NVRM: Found PV kernel running with vGPU hypervisor.\n");
  }
  return 0;
}


// ===== 004dc3f0 hypervisorGetHypervisorType_IMPL =====

undefined4 hypervisorGetHypervisorType_IMPL(long param_1)

{
  undefined4 uVar1;
  
  uVar1 = 4;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x4c);
  }
  return uVar1;
}


// ===== 004dc410 hypervisorIsType_IMPL =====

undefined8 hypervisorIsType_IMPL(int param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(g_pSys + 0x238);
  if (lVar1 != 0) {
    return CONCAT71((int7)((ulong)lVar1 >> 8),*(int *)(lVar1 + 0x4c) == param_1);
  }
  return 0;
}


// ===== 004dc440 hypervisorCheckForObjectAccess_IMPL =====

undefined8 hypervisorCheckForObjectAccess_IMPL(void)

{
  return 0;
}


// ===== 004dc450 _dummyKvmIsP2PSupported =====

undefined8 _dummyKvmIsP2PSupported(void)

{
  return 0;
}


// ===== 004dc460 _dummyKvmChildPartitionDetection =====

undefined8 _dummyKvmChildPartitionDetection(undefined8 param_1,undefined1 *param_2)

{
  *param_2 = 1;
  return 0;
}


// ===== 004dc470 _dummyVmwareIsP2PSupported =====

undefined8 _dummyVmwareIsP2PSupported(void)

{
  return 0;
}


// ===== 004dc480 _dummyVmwareChildPartitionDetection =====

undefined8 _dummyVmwareChildPartitionDetection(undefined8 param_1,undefined1 *param_2)

{
  *param_2 = 1;
  return 0;
}


// ===== 004dc490 _dummyXenIsP2PSupported =====

undefined8 _dummyXenIsP2PSupported(void)

{
  return 0;
}


// ===== 004dc4a0 _dummyXenPostDetection =====

undefined8 _dummyXenPostDetection(undefined8 param_1,undefined1 *param_2)

{
  *param_2 = 1;
  return 0;
}


// ===== 004dc4b0 kernelhostvgpudeviceshrConstruct_IMPL =====

undefined8 kernelhostvgpudeviceshrConstruct_IMPL(void)

{
  return 0;
}


// ===== 004dc4c0 kernelhostvgpudeviceshrDestruct_IMPL =====

void kernelhostvgpudeviceshrDestruct_IMPL(void)

{
  return;
}


// ===== 004dc4d0 kernelhostvgpudeviceapiCanCopy_IMPL =====

undefined8 kernelhostvgpudeviceapiCanCopy_IMPL(void)

{
  return 1;
}


// ===== 004dc4e0 kernelhostvgpudeviceapiCopyConstruct_IMPL =====

int kernelhostvgpudeviceapiCopyConstruct_IMPL(long param_1,long param_2,long param_3)

{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  long local_30 [2];
  
  lVar3 = __nvoc_dynamicCast(*(undefined8 *)(*(long *)(param_3 + 0x58) + 8),
                             __nvoc_class_def_KernelHostVgpuDeviceApi);
  if (lVar3 == 0) {
    return 0x1f;
  }
  iVar1 = deviceGetByGpu_IMPL(*(undefined8 *)(param_2 + 8),
                              *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0),1,local_30);
  if (iVar1 == 0) {
    uVar4 = 0;
    if (*(long *)(lVar3 + 0x178) != 0) {
      uVar4 = *(undefined8 *)(*(long *)(lVar3 + 0x178) + 0x88);
    }
    serverRefShare(g_resServ,uVar4);
    lVar3 = *(long *)(lVar3 + 0x178);
    *(long *)(param_1 + 0x178) = lVar3;
    iVar2 = 0;
    if (((*(uint *)(local_30[0] + 0x1b4) & 0x2000) == 0) ||
       (iVar2 = 0x40, *(long *)(local_30[0] + 0x1d8) != 0)) {
      return iVar2;
    }
    *(undefined8 *)(local_30[0] + 0x1d8) = *(undefined8 *)(lVar3 + 0x98);
  }
  else {
    nvAssertOkFailedNoLog
              (iVar1,"deviceGetByGpu(pCallContext->pClient, pGpu, NV_TRUE, &pDevice)",
               "src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0xc9);
  }
  return iVar1;
}


// ===== 004dc600 kernelhostvgpudeviceapiConstruct_IMPL =====

int kernelhostvgpudeviceapiConstruct_IMPL(long param_1,long param_2,long param_3)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  long local_50;
  undefined8 local_48;
  long local_40 [2];
  
  iVar3 = 0x56;
  local_50 = 0;
  lVar1 = *(long *)(param_3 + 0x40);
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (*(char *)(lVar2 + 0x908) == '\0') {
    iVar3 = deviceGetByGpu_IMPL(*(undefined8 *)(param_2 + 8),lVar2,1,local_40);
    if (iVar3 == 0) {
      if (*(long *)(param_3 + 0x58) == 0) {
        iVar3 = kvgpumgrGuestRegister
                          (lVar2,*(undefined4 *)(lVar1 + 4),*(undefined4 *)(lVar1 + 0xc),
                           *(undefined4 *)(lVar1 + 0x10),*(undefined4 *)(lVar1 + 0x24),
                           *(undefined4 *)(*(long *)(param_2 + 8) + 0x48),
                           *(undefined8 *)(lVar1 + 0x28),*(undefined8 *)(lVar1 + 0x30),
                           *(undefined4 *)(lVar1 + 0x18),*(undefined4 *)(lVar1 + 0x1c),
                           *(undefined4 *)(lVar1 + 8),*(undefined4 *)(lVar1 + 0x3c),
                           *(undefined1 *)(lVar1 + 0x38),*(undefined2 *)(lVar1 + 0x20),lVar1 + 0x44,
                           *(undefined4 *)(lVar1 + 0x14),&local_50);
        if (iVar3 == 0) {
          iVar3 = serverAllocShare(g_resServ,__nvoc_class_def_KernelHostVgpuDeviceShr,&local_48);
          if (iVar3 != 0) {
LAB_004dc7f5:
            kvgpumgrGuestUnregister(lVar2,local_50);
            return iVar3;
          }
          lVar4 = __nvoc_dynamicCast(local_48,__nvoc_class_def_KernelHostVgpuDeviceShr);
          *(long *)(param_1 + 0x178) = lVar4;
          *(long *)(lVar4 + 0x98) = local_50;
          *(undefined8 *)(local_50 + 0x538) = 0;
          *(undefined1 *)(local_50 + 0x889) = 0;
          *(undefined4 *)(local_50 + 0x88c) = *(undefined4 *)(lVar1 + 0x3c);
          *(undefined1 *)(local_50 + 0x888) = *(undefined1 *)(lVar1 + 0x54);
          if ((*(byte *)(local_40[0] + 0x1b5) & 0x20) != 0) {
            if (*(long *)(local_40[0] + 0x1d8) != 0) {
              if (*(long *)(local_50 + 0x2f8) != 0) {
                portMemFree();
                *(undefined8 *)(local_50 + 0x2f8) = 0;
                *(undefined4 *)(local_50 + 0x300) = 0;
                if (*(long *)(local_50 + 0x538) != 0) {
                  memdescRemoveRef();
                  *(undefined8 *)(local_50 + 0x538) = 0;
                }
              }
              serverFreeShare(g_resServ,local_48);
              iVar3 = 0x40;
              goto LAB_004dc7f5;
            }
            *(long *)(local_40[0] + 0x1d8) = local_50;
          }
          CliNotifyVgpuConfigEvent(lVar2,0);
          iVar3 = 0;
        }
        else {
          nvDbg_Printf("src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x78,
                       "kernelhostvgpudeviceapiConstruct_IMPL",4,
                       "NVRM: failed to register HOST_VGPU_DEVICE object\n");
        }
      }
      else {
        iVar3 = kernelhostvgpudeviceapiCopyConstruct_IMPL(param_1,param_2,param_3);
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar3,"deviceGetByGpu(pCallContext->pClient, pGpu, NV_TRUE, &pDevice)",
                 "src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x5d);
    }
  }
  return iVar3;
}


// ===== 004dc8e0 destroyKernelHostVgpuDeviceShare =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void destroyKernelHostVgpuDeviceShare(long param_1,long param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  undefined4 local_40;
  undefined4 local_3c [3];
  
  if (param_2 == 0) {
    nvCheckFailedNoLog(2,"pShare != NULL","src/kernel/virtualization/kernel_hostvgpudeviceapi.c",
                       0x10e);
    return;
  }
  uVar2 = *(undefined8 *)(param_2 + 0x88);
  lVar3 = *(long *)(param_2 + 0x98);
  iVar6 = serverGetShareRefCount(g_resServ,uVar2);
  serverFreeShare(g_resServ,uVar2);
  if (1 < iVar6) {
    return;
  }
  lVar7 = vgpuGetCallingContextDevice(param_1);
  if (lVar7 == 0) {
    nvAssertFailedNoLog("pDevice != NULL","src/kernel/virtualization/kernel_hostvgpudeviceapi.c",
                        0x11c);
    goto LAB_004dca40;
  }
  uVar2 = *(undefined8 *)(param_1 + 0x1b70);
  lVar4 = *(long *)(param_1 + 0x1b98);
  uVar5 = *(undefined8 *)(&DAT_00001b90 + param_1);
  lVar8 = portMemAllocNonPaged(0xfb8);
  if (lVar8 == 0) {
    iVar6 = 0x51;
LAB_004dcb85:
    nvDbg_Printf("src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x122,
                 "destroyKernelHostVgpuDeviceShare",4,
                 "NVRM: Failed to invalidate TLBs and L2 cache. Status:0x%x\n",iVar6);
  }
  else {
    if (*(char *)(param_1 + 0x491d) == '\0') {
      (**(code **)(lVar4 + 0x1e8))(param_1,lVar4,0,0,1,0,0,0);
    }
    *(undefined4 *)(lVar8 + 0xfb0) = 0x19;
    iVar6 = kmemsysFlushGpuCache_IMPL(param_1,uVar2,uVar5,lVar8);
    if (iVar6 != 0) {
      nvDbg_Printf("src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0xf5,
                   "_kernelhostvgpudeviceInvalidateGpuTLBL2Cache",4,
                   "NVRM: Failed to invalidate gpu L2 cache for sysmem. Status:0x%x\n",iVar6);
    }
    portMemSet(lVar8,0,0xfb8);
    *(undefined4 *)(lVar8 + 0xfb0) = 0x18;
    iVar6 = kmemsysFlushGpuCache_IMPL(param_1,uVar2,uVar5,lVar8);
    if (iVar6 != 0) {
      nvDbg_Printf("src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x104,
                   "_kernelhostvgpudeviceInvalidateGpuTLBL2Cache",4,
                   "NVRM: Failed to invalidate gpu L2 cache for vidmem. Status:0x%x\n",iVar6);
      portMemFree(lVar8);
      goto LAB_004dcb85;
    }
    portMemFree(lVar8);
  }
  *(undefined8 *)(lVar7 + 0x1d8) = 0;
LAB_004dca40:
  if ((*(char *)(param_1 + 0x909) != '\0') && (*(char *)(lVar3 + 0x889) != '\0')) {
    local_3c[0] = 0;
    uVar1 = *(undefined4 *)(param_1 + 0x1af4);
    *(undefined4 *)(param_1 + 0x1af4) = 30000000;
    local_40 = *(undefined4 *)(lVar3 + 0x18);
    iVar6 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20804002,&local_40,4);
    if (iVar6 != 0) {
      nvDbg_Printf("src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x138,
                   "destroyKernelHostVgpuDeviceShare",4,
                   "NVRM: Failed to call NV2080_CTRL_CMD_VGPU_MGR_INTERNAL_SHUTDOWN_GSP_VGPU_PLUGIN_TASK\n"
                  );
    }
    local_3c[0] = *(undefined4 *)(lVar3 + 0x18);
    iVar6 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20804008,local_3c,4);
    *(undefined4 *)(param_1 + 0x1af4) = uVar1;
    if (iVar6 != 0) {
      nvDbg_Printf("src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x140,
                   "destroyKernelHostVgpuDeviceShare",4,
                   "NVRM: Failed to call cleanup plugin resources\n");
    }
    if ((*(char *)(param_1 + 0x4a4e) != '\0') && (*(long *)(lVar3 + 0x538) != 0)) {
      memdescDestroy();
    }
    (**(code **)(*(long *)(param_1 + 0x1ba8) + 0x998))
              (param_1,*(long *)(param_1 + 0x1ba8),*(undefined4 *)(lVar3 + 0x18));
  }
  iVar6 = kvgpumgrGuestUnregister(param_1,lVar3);
  if (iVar6 != 0) {
    nvDbg_Printf("src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x14e,
                 "destroyKernelHostVgpuDeviceShare",4,
                 "NVRM: Failed to unregister HOST_VGPU_DEVICE object\n");
  }
  CliNotifyVgpuConfigEvent(param_1,2);
  return;
}


// ===== 004dcce0 kernelhostvgpudeviceapiDestruct_IMPL =====

void kernelhostvgpudeviceapiDestruct_IMPL(long param_1)

{
  destroyKernelHostVgpuDeviceShare
            (*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0),*(undefined8 *)(param_1 + 0x178));
  return;
}


// ===== 004dcd00 kernelhostvgpudeviceapiCtrlCmdSetVgpuDeviceInfo_IMPL =====

undefined8 kernelhostvgpudeviceapiCtrlCmdSetVgpuDeviceInfo_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  nvDbg_Printf("src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x167,
               "kernelhostvgpudeviceapiCtrlCmdSetVgpuDeviceInfo_IMPL",1,"NVRM: %s\n");
  lVar2 = *(long *)(*(long *)(param_1 + 0x178) + 0x98);
  if ((*(char *)(lVar1 + 0x909) == '\0') || (*(char *)(lVar2 + 0x889) != '\0')) {
    portMemCopy(lVar2 + 0x2cc,0x10,param_2,0x10);
    CliNotifyVgpuConfigEvent(lVar1,0);
    uVar3 = 0;
  }
  else {
    nvAssertFailedNoLog("!IS_GSP_CLIENT(pGpu) || pKernelHostVgpuDeviceApi->pShared->pDevice->bGspPluginTaskInitialized"
                        ,"src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x169);
    uVar3 = 0x40;
  }
  return uVar3;
}


// ===== 004dcdd0 kernelhostvgpudeviceapiCtrlCmdSetVgpuGuestLifeCycleState_IMPL =====

undefined4 kernelhostvgpudeviceapiCtrlCmdSetVgpuGuestLifeCycleState_IMPL(long param_1,int *param_2)

{
  int iVar1;
  long lVar2;
  undefined4 uVar3;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  nvDbg_Printf("src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x17f,
               "kernelhostvgpudeviceapiCtrlCmdSetVgpuGuestLifeCycleState_IMPL",1,"NVRM: %s\n");
  if ((*(char *)(lVar2 + 0x909) == '\0') ||
     (*(char *)(*(long *)(*(long *)(param_1 + 0x178) + 0x98) + 0x889) != '\0')) {
    iVar1 = *param_2;
    uVar3 = 0;
    if (iVar1 == 2) {
      uVar3 = kvgpumgrClearGuestVmInfo(lVar2,*(undefined8 *)(*(long *)(param_1 + 0x178) + 0x98));
      iVar1 = *param_2;
    }
    CliNotifyVgpuConfigEvent(lVar2,iVar1);
  }
  else {
    uVar3 = 0x40;
    nvAssertFailedNoLog("!IS_GSP_CLIENT(pGpu) || pKernelHostVgpuDeviceApi->pShared->pDevice->bGspPluginTaskInitialized"
                        ,"src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x181);
  }
  return uVar3;
}


// ===== 004dceb0 kernelhostvgpudeviceapiCtrlCmdVfConfigSpaceAccess_IMPL =====

undefined8 kernelhostvgpudeviceapiCtrlCmdVfConfigSpaceAccess_IMPL(void)

{
  return 0x56;
}


// ===== 004dcec0 kernelhostvgpudeviceapiCtrlCmdBindFecsEvtbuf_IMPL =====

undefined8 kernelhostvgpudeviceapiCtrlCmdBindFecsEvtbuf_IMPL(void)

{
  return 0x56;
}


// ===== 004dcee0 kernelhostvgpudeviceapiCtrlCmdSetOfflinedPagePatchInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kernelhostvgpudeviceapiCtrlCmdSetOfflinedPagePatchInfo_IMPL(long param_1,uint *param_2)

{
  uint uVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  ulong uVar7;
  long lVar8;
  int iVar9;
  ulong uVar10;
  sbyte sVar11;
  ulong uVar12;
  long local_48;
  undefined8 local_40 [2];
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if ((*(char *)(lVar2 + 0x909) == '\0') ||
     (*(char *)(*(long *)(*(long *)(param_1 + 0x178) + 0x98) + 0x889) != '\0')) {
    if ((*(char *)(lVar2 + 0x4a4e) == '\0') &&
       (((*(char *)(lVar2 + 0x457) != '\0' &&
         (cVar3 = (**(code **)(lVar2 + 0x2f0))(lVar2), cVar3 != '\0')) &&
        (*(char *)(lVar2 + 0x491d) == '\0')))) {
      lVar2 = *(long *)(*(long *)(param_1 + 0x178) + 0x98);
      if ((lVar2 != 0) && (*(char *)(lVar2 + 0x318) != '\0')) {
        if (*param_2 == 0x10000) {
          sVar11 = 0x10;
        }
        else {
          if (*param_2 != 0x200000) {
            nvDbg_Printf("src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x20a,
                         "kernelhostvgpudeviceapiCtrlCmdSetOfflinedPagePatchInfo_IMPL",4,
                         "NVRM: Invalid Guest FB Segment Page Size\n");
            return 0x1f;
          }
          sVar11 = 0x15;
        }
        if (0x40 < param_2[1]) {
          nvAssertFailedNoLog("(pParams->offlinedPageCount <= NV2080_CTRL_FB_OFFLINED_PAGES_MAX_PAGES)"
                              ,"src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x211);
          return 0x5b;
        }
        uVar7 = *(ulong *)(lVar2 + 0x308);
        uVar12 = *(ulong *)(lVar2 + 0x310) >> sVar11;
        iVar5 = (int)uVar12;
        piVar6 = (int *)portMemAllocNonPaged((uVar12 & 0xffffffff) << 2);
        *(int **)(lVar2 + 800) = piVar6;
        if (piVar6 == (int *)0x0) {
          nvDbg_Printf("src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x216,
                       "kernelhostvgpudeviceapiCtrlCmdSetOfflinedPagePatchInfo_IMPL",4,
                       "NVRM: GuestFbSegment allocation failed\n");
          return 0x51;
        }
        if (iVar5 != 0) {
          iVar9 = (int)(uVar7 >> sVar11);
          *piVar6 = iVar9;
          if (iVar5 != 1) {
            iVar4 = iVar9 + 1;
            lVar8 = 4;
            do {
              *(int *)(*(long *)(lVar2 + 800) + lVar8) = iVar4;
              iVar4 = iVar4 + 1;
              lVar8 = lVar8 + 4;
            } while (iVar4 != iVar9 + iVar5);
          }
        }
        lVar8 = 0;
        if (param_2[1] != 0) {
          do {
            local_48 = 0;
            uVar12 = (ulong)*param_2;
            local_40[0] = 0;
            uVar1 = param_2[lVar8 + 0x82];
            uVar7 = *(ulong *)(param_2 + lVar8 * 2 + 2);
            if (*(char *)(lVar2 + 0x318) != '\0') {
              uVar10 = uVar7;
              if (uVar7 <= uVar12) {
                uVar10 = uVar12;
              }
              if ((*(ulong *)(lVar2 + 0x310) <= uVar10) ||
                 (*(ulong *)(lVar2 + 0x310) <= uVar12 + uVar7)) {
                iVar5 = 0x5b;
                nvAssertFailedNoLog("(gpa < guestFbLength) && (size < guestFbLength) && ((gpa + size) < guestFbLength)"
                                    ,"src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x1b4);
                goto LAB_004dd1e3;
              }
            }
            iVar5 = serverGetClientUnderLock(g_resServ,*(undefined4 *)(lVar2 + 0x304),local_40);
            if (iVar5 != 0) {
              iVar5 = 0x23;
              nvDbg_Printf("src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x1be,
                           "_kernelhostvgpudeviceValidateOfflinedPageInfoAndGetSpa",4,
                           "NVRM: Failed to get pClient\n");
LAB_004dd1e3:
              nvDbg_Printf("src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x227,
                           "kernelhostvgpudeviceapiCtrlCmdSetOfflinedPagePatchInfo_IMPL",4,
                           "NVRM: Offlined Page info Validation Failed\n");
              portMemFree(*(undefined8 *)(lVar2 + 800));
              *(undefined8 *)(lVar2 + 800) = 0;
              return iVar5;
            }
            iVar5 = memGetByHandle_IMPL(local_40[0],uVar1,&local_48);
            if (iVar5 != 0) {
              nvDbg_Printf("src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x1c5,
                           "_kernelhostvgpudeviceValidateOfflinedPageInfoAndGetSpa",4,
                           "NVRM: Invalid Memory handle\n");
              goto LAB_004dd1e3;
            }
            uVar7 = memdescGetPhysAddr(*(undefined8 *)(local_48 + 0x118),1,0);
            *(int *)(*(long *)(lVar2 + 800) +
                    (*(ulong *)(param_2 + lVar8 * 2 + 2) >> sVar11 & 0xffffffff) * 4) =
                 (int)(uVar7 >> sVar11);
            *(undefined8 *)(lVar2 + 0x338 + lVar8 * 8) = *(undefined8 *)(param_2 + lVar8 * 2 + 2);
            lVar8 = lVar8 + 1;
          } while ((uint)lVar8 < param_2[1]);
        }
        *(ulong *)(lVar2 + 0x328) = (ulong)*param_2;
        uVar1 = param_2[1];
        *(undefined1 *)(lVar2 + 0x330) = 1;
        *(uint *)(lVar2 + 0x334) = uVar1;
      }
      iVar5 = 0;
    }
    else {
      iVar5 = 0x56;
    }
  }
  else {
    iVar5 = 0x40;
    nvAssertFailedNoLog("!IS_GSP_CLIENT(pGpu) || pKernelHostVgpuDeviceApi->pShared->pDevice->bGspPluginTaskInitialized"
                        ,"src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x1f6);
  }
  return iVar5;
}


// ===== 004dd300 kernelhostvgpudeviceapiCtrlCmdTriggerPrivDoorbell_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kernelhostvgpudeviceapiCtrlCmdTriggerPrivDoorbell_IMPL(long param_1,int *param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  char cVar4;
  undefined8 uVar5;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(*(long *)(param_1 + 0x178) + 0x98);
  if ((*(char *)(lVar1 + 0x909) == '\0') || (*(char *)(lVar2 + 0x889) != '\0')) {
    if (*param_2 == 0x11) {
      lVar3 = *(long *)(lVar1 + 0x1c20);
      cVar4 = rmapiLockIsOwner();
      if ((cVar4 == '\0') || (cVar4 = rmGpuLockIsOwner(), cVar4 == '\0')) {
        nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                            "src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x278);
        return 0x2f;
      }
      if ((*(char *)(lVar1 + 0x4a4e) != '\0') &&
         ((*(char *)(lVar1 + 0x491d) != '\0' && (*(char *)(lVar1 + 0x908) == '\0')))) {
        uVar5 = (**(code **)(lVar3 + 0x208))(lVar1,lVar3,*(int *)(lVar2 + 0x18) * 0x20 + *param_2);
        return uVar5;
      }
      return 0x56;
    }
    nvAssertFailedNoLog("pParams->handle == NV_DOORBELL_NOTIFY_LEAF_VF_CPU_PLUGIN_HANDLE",
                        "src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x275);
    uVar5 = 0x1f;
  }
  else {
    nvAssertFailedNoLog("!IS_GSP_CLIENT(pGpu) || pKernelHostVgpuDeviceApi->pShared->pDevice->bGspPluginTaskInitialized"
                        ,"src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x272);
    uVar5 = 0x40;
  }
  return uVar5;
}


// ===== 004dd460 kernelhostvgpudeviceapiCtrlCmdEventSetNotification_IMPL =====

undefined8 kernelhostvgpudeviceapiCtrlCmdEventSetNotification_IMPL(long param_1,uint *param_2)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  
  if ((*(char *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x909) == '\0') ||
     (*(char *)(*(long *)(*(long *)(param_1 + 0x178) + 0x98) + 0x889) != '\0')) {
    lVar2 = inotifyGetNotificationList_IMPL(*(undefined8 *)(param_1 + 0x160));
    if (lVar2 != 0) {
      uVar3 = (ulong)*param_2;
      if (*param_2 < 10) {
        uVar1 = param_2[1];
        if (uVar1 == 0) {
          *(undefined4 *)(param_1 + 0x180 + uVar3 * 4) = 0;
          return 0;
        }
        if (uVar1 - 1 < 2) {
          if (*(int *)(param_1 + 0x180 + uVar3 * 4) != 0) {
            return 0x40;
          }
          *(uint *)(param_1 + (uVar3 + 0x60) * 4) = uVar1;
          return 0;
        }
      }
      else {
        nvDbg_Printf("src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x29e,
                     "kernelhostvgpudeviceapiCtrlCmdEventSetNotification_IMPL",4,
                     "NVRM: bad event 0x%x\n");
      }
      return 0x1f;
    }
    nvDbg_Printf("src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x297,
                 "kernelhostvgpudeviceapiCtrlCmdEventSetNotification_IMPL",4,
                 "NVRM: cmd 0x%x: no event list\n",0xa0840107);
  }
  else {
    nvAssertFailedNoLog("!IS_GSP_CLIENT(pGpu) || pKernelHostVgpuDeviceApi->pShared->pDevice->bGspPluginTaskInitialized"
                        ,"src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x291);
  }
  return 0x40;
}


// ===== 004dd5a0 kernelhostvgpudeviceapiCtrlCmdGetBarMappingRanges_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int kernelhostvgpudeviceapiCtrlCmdGetBarMappingRanges_IMPL(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  uint uVar6;
  long lVar8;
  int iVar9;
  ulong uVar10;
  ulong uVar11;
  uint uVar12;
  undefined8 uVar13;
  uint local_dc;
  long local_d8 [10];
  long local_88 [11];
  ulong uVar7;
  
  local_dc = 0;
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar5 = *(long *)(lVar1 + 7000);
  if (*(char *)(lVar1 + 0x909) == '\0') {
    if (lVar5 == 0) {
LAB_004dd7f0:
      nvAssertFailedNoLog("pKernelBif != NULL",
                          "src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x2d7);
      return 0x40;
    }
    lVar8 = *(long *)(*(long *)(param_1 + 0x178) + 0x98);
    if (lVar8 == 0) {
      nvAssertFailedNoLog("pKernelHostVgpuDevice != NULL",
                          "src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x2da);
      return 0x40;
    }
  }
  else {
    lVar8 = *(long *)(*(long *)(param_1 + 0x178) + 0x98);
    if (*(char *)(lVar8 + 0x889) == '\0') {
      nvAssertFailedNoLog("!IS_GSP_CLIENT(pGpu) || pKernelHostVgpuDeviceApi->pShared->pDevice->bGspPluginTaskInitialized"
                          ,"src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x2d4);
      return 0x40;
    }
    if (lVar5 == 0) goto LAB_004dd7f0;
  }
  uVar13 = 0;
  iVar9 = (**(code **)(lVar5 + 0x260))
                    (lVar1,lVar5,lVar8,*(undefined4 *)(param_2 + 0xa4),&local_dc,0);
  if (iVar9 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar9,
               "kbifGetVFSparseMmapRegions_HAL( pGpu, pKernelBif, pKernelHostVgpuDevice, pParams->osPageSize, &numAreas, NULL, NULL)"
               ,"src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x2dd);
    return iVar9;
  }
  if (local_dc < 0xb) {
    iVar9 = (**(code **)(lVar5 + 0x260))
                      (lVar1,lVar5,lVar8,*(undefined4 *)(param_2 + 0xa4),&local_dc,local_d8,local_88
                      );
    if (iVar9 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar9,
                 "kbifGetVFSparseMmapRegions_HAL( pGpu, pKernelBif, pKernelHostVgpuDevice, pParams->osPageSize, &numAreas, vfRegionOffsets, vfRegionSizes)"
                 ,"src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x2ea);
      return iVar9;
    }
    uVar12 = local_dc - 1;
    if (uVar12 < 10) {
      uVar4 = 0;
      lVar5 = 0;
      uVar11 = 0;
      lVar8 = 0;
      do {
        while( true ) {
          uVar6 = (int)uVar11 + 1;
          uVar7 = (ulong)uVar6;
          lVar3 = local_88[uVar4];
          if ((uVar4 != 0) || (lVar5 != local_d8[0])) break;
          *(long *)(param_2 + uVar11 * 8) = local_d8[0];
          *(long *)(param_2 + 0x50 + uVar11 * 8) = local_88[0];
          uVar4 = 1;
          *(undefined1 *)(param_2 + 0xa8 + uVar11) = 0;
          uVar10 = (ulong)uVar6;
          lVar5 = local_d8[0];
          uVar11 = uVar10;
          lVar8 = lVar3;
          if ((ulong)local_dc == 1) goto LAB_004dd750;
        }
        lVar2 = local_d8[uVar4];
        lVar8 = lVar5 + lVar8;
        uVar10 = (ulong)((int)uVar11 + 2);
        *(long *)(param_2 + uVar11 * 8) = lVar8;
        lVar5 = local_d8[uVar4];
        uVar4 = uVar4 + 1;
        *(long *)(param_2 + 0x50 + uVar11 * 8) = lVar2 - lVar8;
        *(undefined1 *)(param_2 + 0xa8 + uVar11) = 1;
        *(long *)(param_2 + uVar7 * 8) = lVar2;
        *(long *)(param_2 + 0x50 + uVar7 * 8) = lVar3;
        *(undefined1 *)(param_2 + 0xa8 + uVar7) = 0;
        uVar11 = uVar10;
        lVar8 = lVar3;
      } while (uVar4 != local_dc);
LAB_004dd750:
      iVar9 = (int)uVar10;
      lVar5 = local_88[uVar12] + local_d8[uVar12];
      if (lVar5 != *(long *)(&DAT_00003a70 + lVar1)) {
        iVar9 = iVar9 + 1;
        *(long *)(param_2 + uVar10 * 8) = lVar5;
        *(long *)(param_2 + 0x50 + uVar10 * 8) = *(long *)(&DAT_00003a70 + lVar1) - lVar5;
        *(undefined1 *)(param_2 + 0xa8 + uVar10) = 1;
      }
      *(int *)(param_2 + 0xa0) = iVar9;
      return 0;
    }
  }
  else {
    nvAssertFailedNoLog("numAreas <= NVA084_CTRL_KERNEL_HOST_VGPU_DEVICE_MAX_BAR_MAPPING_RANGES",
                        "src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x2e7,uVar13);
  }
  return 0x40;
}


// ===== 004dd8e0 kernelhostvgpudeviceapiCtrlCmdRestoreDefaultExecPartition_IMPL =====

ulong kernelhostvgpudeviceapiCtrlCmdRestoreDefaultExecPartition_IMPL(long param_1)

{
  long lVar1;
  long lVar2;
  char cVar3;
  uint uVar4;
  ulong uVar5;
  undefined8 local_20;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(*(long *)(param_1 + 0x178) + 0x98);
  if (*(char *)(lVar1 + 0x909) == '\0') {
    if (lVar2 == 0) {
      nvAssertFailedNoLog("pKernelHostVgpuDevice != NULL",
                          "src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x32b);
      return 0x40;
    }
  }
  else if (*(char *)(lVar2 + 0x889) == '\0') {
    nvAssertFailedNoLog("!IS_GSP_CLIENT(pGpu) || pKernelHostVgpuDeviceApi->pShared->pDevice->bGspPluginTaskInitialized"
                        ,"src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x327);
    return 0x40;
  }
  if (*(char *)(lVar2 + 0x540) != '\0') {
    nvDbg_Printf("src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x32f,
                 "kernelhostvgpudeviceapiCtrlCmdRestoreDefaultExecPartition_IMPL",4,
                 "NVRM: Default MIG compute instance save/restore disabled\n");
    return 0x40;
  }
  if ((*(long *)(lVar1 + 0x1bc0) != 0) &&
     (cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar1), cVar3 != '\0')) {
    uVar4 = kmigmgrGetGPUInstanceInfo_IMPL
                      (lVar1,*(undefined8 *)(lVar1 + 0x1bc0),*(undefined4 *)(lVar2 + 0x1c),&local_20
                      );
    if (uVar4 == 0) {
      uVar5 = kvgpuMgrRestoreSmcExecPart(lVar1,lVar2,local_20);
      if ((int)uVar5 != 0) {
        nvAssertOkFailedNoLog
                  (uVar5 & 0xffffffff,
                   "kvgpuMgrRestoreSmcExecPart(pGpu, pKernelHostVgpuDevice, pKernelMIGGpuInstance)",
                   "src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x340);
        uVar5 = uVar5 & 0xffffffff;
      }
    }
    else {
      nvAssertOkFailedNoLog
                (uVar4,
                 "kmigmgrGetGPUInstanceInfo(pGpu, pKernelMIGManager, pKernelHostVgpuDevice->swizzId, &pKernelMIGGpuInstance)"
                 ,"src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x33c);
      uVar5 = (ulong)uVar4;
    }
    return uVar5;
  }
  return 0x56;
}


// ===== 004dda80 kernelhostvgpudeviceapiCtrlCmdFreeStates_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kernelhostvgpudeviceapiCtrlCmdFreeStates_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  undefined8 local_10;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(*(long *)(param_1 + 0x178) + 0x98);
  if ((*(char *)(lVar1 + 0x909) != '\0') && (*(char *)(lVar2 + 0x889) == '\0')) {
    nvAssertFailedNoLog("!IS_GSP_CLIENT(pGpu) || pKernelHostVgpuDeviceApi->pShared->pDevice->bGspPluginTaskInitialized"
                        ,"src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x357);
    return 0x40;
  }
  local_10 = CONCAT44(*param_2,*(undefined4 *)(lVar2 + 0x18));
  uVar3 = (**(code **)(lVar1 + 0x3b90))
                    (lVar1 + 0x3b58,*(undefined4 *)(lVar1 + 0x3b34),*(undefined4 *)(lVar1 + 0x3b3c),
                     0x2080400c,&local_10,8);
  if ((int)uVar3 == 0) {
    return uVar3;
  }
  nvCheckOkFailedNoLog
            (4,uVar3 & 0xffffffff,
             "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_VGPU_MGR_INTERNAL_FREE_STATES, &params, sizeof(params))"
             ,"src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x35e);
  return uVar3 & 0xffffffff;
}


// ===== 004ddb50 kernelhostvgpudeviceapiCtrlCmdBootloadVgpuTask_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kernelhostvgpudeviceapiCtrlCmdBootloadVgpuTask_IMPL(long param_1,uint *param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  long lVar9;
  ulong uVar10;
  undefined8 uVar11;
  long *plVar12;
  long lVar13;
  char *pcVar14;
  ulong uVar15;
  long lVar16;
  long lVar17;
  long *local_60;
  long local_48;
  undefined8 local_40 [2];
  
  local_40[0] = 0;
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1ba8);
  if (*(char *)(lVar1 + 0x909) == '\0') {
    return 0x56;
  }
  lVar3 = *(long *)(*(long *)(param_1 + 0x178) + 0x98);
  if (lVar3 == 0) {
    nvAssertFailedNoLog("pKernelHostVgpuDevice != NULL",
                        "src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x37a);
    return 0x40;
  }
  if (*(char *)(lVar3 + 0x889) != '\0') {
    nvAssertFailedNoLog("!pKernelHostVgpuDevice->bGspPluginTaskInitialized",
                        "src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x37b);
    return 0x40;
  }
  iVar6 = serverGetClientUnderLock(g_resServ,*(undefined4 *)(lVar3 + 0x304),local_40);
  if (iVar6 != 0) {
    nvDbg_Printf("src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x380,
                 "kernelhostvgpudeviceapiCtrlCmdBootloadVgpuTask_IMPL",4,
                 "NVRM: Failed to get pClient\n");
    return 0x23;
  }
  if ((*(char *)(lVar1 + 0x4a4e) == '\0') || (*(char *)(lVar1 + 0x491d) == '\0')) {
    iVar6 = 0x56;
    portMemFree(0);
    goto LAB_004ddfc5;
  }
  if (*param_2 - 1 < 0x180) {
    lVar13 = *(long *)(lVar1 + 0x3b10);
    if (lVar13 == 0) {
      iVar6 = 0x40;
      portMemFree(0);
      goto LAB_004ddfc5;
    }
    lVar4 = *(long *)(lVar1 + 0x1b70);
    lVar9 = portMemAllocNonPaged(0x19d8);
    if (lVar9 == 0) {
      portMemFree(0);
LAB_004de167:
      iVar6 = 0x51;
      goto LAB_004ddfc5;
    }
    portMemSet(lVar9,0,0x19d8);
    if (*(char *)(lVar1 + 0x4915) != '\0') {
      lVar16 = portMemAllocNonPaged((ulong)*param_2 << 4);
      *(long *)(lVar3 + 0x2f8) = lVar16;
      if (lVar16 == 0) {
        portMemFree(lVar9);
        goto LAB_004de167;
      }
      *(undefined4 *)(lVar3 + 0x300) = 0;
    }
    if (*param_2 != 0) {
      lVar16 = 0;
      do {
        iVar6 = memGetByHandle_IMPL(local_40[0],param_2[lVar16 + 1],&local_48);
        if (iVar6 != 0) {
          nvDbg_Printf("src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x3b4,
                       "kernelhostvgpudeviceapiCtrlCmdBootloadVgpuTask_IMPL",4,
                       "NVRM: Invalid Memory handle\n");
          portMemFree(lVar9);
          goto LAB_004ddfc5;
        }
        uVar10 = memdescGetPhysAddr(*(undefined8 *)(local_48 + 0x118),1,0);
        *(ulong *)(lVar9 + 0x178 + lVar16 * 8) = uVar10;
        uVar15 = *(ulong *)(*(long *)(local_48 + 0x118) + 0x30);
        *(ulong *)(lVar9 + 0xd78 + lVar16 * 8) = uVar15;
        if ((lVar13 - 1U & (uVar10 | uVar15)) != 0) {
          nvDbg_Printf("src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x3be,
                       "kernelhostvgpudeviceapiCtrlCmdBootloadVgpuTask_IMPL",4,
                       "NVRM: guest fb segment PA or length is not VMMU segment size aligned\n");
          portMemFree(lVar9);
          goto LAB_004de037;
        }
        if (*(char *)(lVar1 + 0x4915) != '\0') {
          lVar5 = *(long *)(lVar3 + 0x2f8);
          lVar17 = lVar16 * 0x10;
          uVar11 = memdescGetPhysAddr(*(undefined8 *)(local_48 + 0x118),1,0);
          *(undefined8 *)(lVar5 + lVar17) = uVar11;
          plVar12 = (long *)(*(long *)(lVar3 + 0x2f8) + lVar17);
          *plVar12 = *plVar12 + *(long *)(lVar4 + 0x478);
          *(undefined8 *)(*(long *)(lVar3 + 0x2f8) + 8 + lVar17) =
               *(undefined8 *)(*(long *)(local_48 + 0x118) + 0x30);
          *(int *)(lVar3 + 0x300) = *(int *)(lVar3 + 0x300) + 1;
        }
        lVar16 = lVar16 + 1;
      } while ((uint)lVar16 < *param_2);
    }
    local_60 = &local_48;
    iVar6 = memGetByHandle_IMPL(local_40[0],param_2[0x181],local_60);
    if (iVar6 != 0) {
      nvDbg_Printf("src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x3ce,
                   "kernelhostvgpudeviceapiCtrlCmdBootloadVgpuTask_IMPL",4,
                   "NVRM: Invalid plugin heap Memory handle\n");
      portMemFree(lVar9);
      goto LAB_004ddfc5;
    }
    *(undefined8 *)(lVar3 + 0x538) = *(undefined8 *)(local_48 + 0x118);
    memdescAddRef();
    lVar13 = memdescGetPhysAddr(*(undefined8 *)(local_48 + 0x118),1,0);
    *(long *)(lVar9 + 0x1978) = lVar13;
    uVar15 = *(ulong *)(*(long *)(local_48 + 0x118) + 0x30);
    *(ulong *)(lVar9 + 0x1980) = uVar15;
    if ((ulong)(*(long *)(param_2 + 0x186) + *(long *)(param_2 + 0x184)) < uVar15) {
      if ((ulong)(*(long *)(param_2 + 0x18a) + *(long *)(param_2 + 0x188)) < uVar15) {
        if ((ulong)(*(long *)(param_2 + 0x18e) + *(long *)(param_2 + 0x18c)) < uVar15) {
          *(long *)(lVar9 + 0x1990) = lVar13 + *(long *)(param_2 + 0x184);
          *(undefined8 *)(lVar9 + 0x1998) = *(undefined8 *)(param_2 + 0x186);
          *(long *)(lVar9 + 0x19a0) = *(long *)(param_2 + 0x188) + lVar13;
          *(undefined8 *)(lVar9 + 0x19a8) = *(undefined8 *)(param_2 + 0x18a);
          *(long *)(lVar9 + 0x19b0) = lVar13 + *(long *)(param_2 + 0x18c);
          *(undefined8 *)(lVar9 + 0x19b8) = *(undefined8 *)(param_2 + 0x18e);
          iVar6 = (**(code **)(lVar2 + 0x988))(lVar1,lVar2,*(undefined4 *)(lVar3 + 0x18));
          if (iVar6 == 0) {
            *(undefined4 *)(lVar9 + 4) = *(undefined4 *)(lVar3 + 0x18);
            *(undefined4 *)(lVar9 + 0x10) = *(undefined4 *)(lVar3 + 0x1c);
            *(uint *)(lVar9 + 0x170) = *param_2;
            *(undefined8 *)(lVar9 + 0x1988) = *(undefined8 *)(param_2 + 0x182);
            uVar15 = 0;
            *(char *)(lVar9 + 0x19d0) = (char)param_2[0x191];
            do {
              uVar7 = gpuGetRmEngineType_IMPL(uVar15 & 0xffffffff);
              *(undefined4 *)(lVar9 + 0x1c + uVar15 * 4) =
                   *(undefined4 *)(lVar3 + 0x2c + (ulong)uVar7 * 4);
              uVar15 = uVar15 + 1;
            } while (uVar15 != 0x54);
            iVar6 = (**(code **)(lVar1 + 0x3b90))
                              (lVar1 + 0x3b58,*(undefined4 *)(lVar1 + 0x3b34),
                               *(undefined4 *)(lVar1 + 0x3b3c),0x20804001,lVar9,0x19d8);
            iVar8 = (**(code **)(lVar2 + 0x990))(lVar1,lVar2,*(undefined4 *)(lVar3 + 0x18));
            if (iVar8 != 0) {
              nvAssertOkFailedNoLog
                        (iVar8,
                         "kgspPreserveVgpuPartitionLogging(pGpu, pKernelGsp, pKernelHostVgpuDevice->gfid)"
                         ,"src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x424);
            }
            if (iVar6 == 0) {
              portMemFree(lVar9);
              *(undefined1 *)(lVar3 + 0x889) = 1;
              return 0;
            }
            nvDbg_Printf("src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x42c,
                         "kernelhostvgpudeviceapiCtrlCmdBootloadVgpuTask_IMPL",4,
                         "NVRM: Failed to call NV2080_CTRL_CMD_VGPU_MGR_INTERNAL_BOOTLOAD_GSP_VGPU_PLUGIN_TASK\n"
                        );
            iVar8 = (**(code **)(lVar2 + 0x998))(lVar1,lVar2,*(undefined4 *)(lVar3 + 0x18));
            if (iVar8 != 0) {
              nvAssertOkFailedNoLog
                        (iVar8,
                         "kgspFreeVgpuPartitionLogging_HAL(pGpu, pKernelGsp, pKernelHostVgpuDevice->gfid)"
                         ,"src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x42d);
            }
            portMemFree(lVar9);
          }
          else {
            nvCheckOkFailedNoLog
                      (4,iVar6,
                       "kgspInitVgpuPartitionLogging_HAL(pGpu, pKernelGsp, pKernelHostVgpuDevice->gfid, pBootloadParams->initTaskLogBuffOffset, pBootloadParams->initTaskLogBuffSize, pBootloadParams->vgpuTaskLogBuffOffset, pBootloadParams->vgpuTaskLogBuffSize, pBootloadParams->kernelLogBuffOffset, pBootloadParams->kernelLogBuffSize)"
                       ,"src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x401);
            portMemFree(lVar9);
          }
          goto LAB_004ddfc5;
        }
        pcVar14 = "NVRM: Invalid vgpu kernel log buffer\n";
        uVar11 = 0x3f1;
      }
      else {
        pcVar14 = "NVRM: Invalid vgpu task log buffer\n";
        uVar11 = 0x3e9;
      }
    }
    else {
      pcVar14 = "NVRM: Invalid init task log buffer\n";
      uVar11 = 0x3e1;
    }
    nvDbg_Printf("src/kernel/virtualization/kernel_hostvgpudeviceapi.c",uVar11,
                 "kernelhostvgpudeviceapiCtrlCmdBootloadVgpuTask_IMPL",4,pcVar14);
    portMemFree(lVar9);
  }
  else {
    portMemFree(0);
  }
LAB_004de037:
  iVar6 = 0x1f;
LAB_004ddfc5:
  if (*(long *)(lVar3 + 0x2f8) != 0) {
    portMemFree();
    *(undefined8 *)(lVar3 + 0x2f8) = 0;
    *(undefined4 *)(lVar3 + 0x300) = 0;
  }
  if (*(long *)(lVar3 + 0x538) != 0) {
    memdescRemoveRef();
    *(undefined8 *)(lVar3 + 0x538) = 0;
  }
  kvgpumgrGuestUnregister(lVar1,lVar3);
  return iVar6;
}


// ===== 004de320 kernelhostvgpudeviceapiCtrlCmdSetPlacementId_IMPL =====

ulong kernelhostvgpudeviceapiCtrlCmdSetPlacementId_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  undefined4 *puVar2;
  char cVar3;
  uint uVar4;
  ulong uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  char *pcVar8;
  bool bVar9;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined1 local_98 [80];
  undefined4 local_48;
  undefined8 local_40;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if ((lVar1 == 0) || (*(long *)(lVar1 + 0x1bc0) == 0)) {
    bVar9 = false;
  }
  else {
    cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar1);
    bVar9 = cVar3 != '\0';
  }
  local_b0 = 0;
  local_a8 = 0;
  nvDbg_Printf("src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x45b,
               "kernelhostvgpudeviceapiCtrlCmdSetPlacementId_IMPL",1,"NVRM: %s\n");
  puVar2 = *(undefined4 **)(*(long *)(param_1 + 0x178) + 0x98);
  *(undefined2 *)(puVar2 + 9) = *(undefined2 *)(param_2 + 1);
  if (*(char *)(lVar1 + 0x491d) == '\0') {
    return 0;
  }
  uVar5 = kvgpumgrGetVgpuTypeInfo(*puVar2,&local_b0);
  if ((int)uVar5 != 0) {
    nvAssertOkFailedNoLog
              (uVar5 & 0xffffffff,
               "kvgpumgrGetVgpuTypeInfo(pKernelHostVgpuDevice->vgpuType, &vgpuTypeInfo)",
               "src/kernel/virtualization/kernel_hostvgpudeviceapi.c",0x463);
    return uVar5 & 0xffffffff;
  }
  if (*(char *)(lVar1 + 0x909) == '\0') {
    return uVar5;
  }
  uVar6 = gpuGetKernelFifoShared_IMPL(lVar1);
  if (bVar9) {
    uVar4 = serverGetClientUnderLock(g_resServ,puVar2[1],&local_a0);
    uVar7 = 0x46d;
    pcVar8 = "serverGetClientUnderLock(&g_resServ, pKernelHostVgpuDevice->hMigClient, &pClient)";
    if (uVar4 == 0) {
      uVar4 = deviceGetByHandle_IMPL(local_a0,puVar2[2],&local_a8,0x46d);
      if (uVar4 == 0) goto LAB_004de486;
      uVar7 = 0x46e;
      pcVar8 = "deviceGetByHandle(pClient, pKernelHostVgpuDevice->hMigDevice, &pMigDevice)";
    }
    nvAssertOkFailedNoLog(uVar4,pcVar8,"src/kernel/virtualization/kernel_hostvgpudeviceapi.c",uVar7)
    ;
  }
  else {
LAB_004de486:
    portMemSet(local_98,0,0x60);
    uVar4 = kfifoGetHostDeviceInfoTable_KERNEL(lVar1,uVar6,local_98,local_a8);
    if (uVar4 == 0) {
      uVar4 = vgpuMgrReserveSystemChannelIDs
                        (lVar1,local_b0,puVar2[6],puVar2 + 0xb,puVar2 + 0x5f,local_a8,*param_2,
                         *(undefined2 *)(puVar2 + 9),local_48,local_40);
    }
    portMemFree(local_40);
  }
  return (ulong)uVar4;
}


// ===== 004de580 _get_chip_id_for_alias_pgpu =====

void _get_chip_id_for_alias_pgpu(int *param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  ulong uVar3;
  int local_128 [68];
  
  memcpy(local_128,&DAT_005a7300,0x110);
  piVar1 = local_128;
  uVar3 = 0;
  while ((*param_1 != *piVar1 || (*param_2 != piVar1[1]))) {
    uVar2 = (int)uVar3 + 1;
    uVar3 = (ulong)uVar2;
    piVar1 = piVar1 + 4;
    if (uVar2 == 0x11) {
      return;
    }
  }
  *param_1 = local_128[uVar3 * 4 + 2];
  *param_2 = local_128[uVar3 * 4 + 3];
  return;
}


// ===== 004de600 _kvgpumgrIsPlacementValid =====

undefined8 _kvgpumgrIsPlacementValid(long param_1,long param_2,uint param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  long lVar3;
  int local_50 [18];
  
  local_50[2] = 2;
  local_50[3] = 3;
  local_50[4] = 8;
  local_50[5] = 9;
  local_50[6] = 0xe;
  local_50[7] = 0xf;
  local_50[8] = 0x14;
  local_50[9] = 0x15;
  local_50[10] = 0x1a;
  local_50[0xb] = 0x1b;
  local_50[0xc] = 0x20;
  local_50[0xd] = 0x21;
  local_50[0xe] = 0x26;
  local_50[0xf] = 0x27;
  local_50[0x10] = 0x2c;
  local_50[0x11] = 0x2d;
  local_50[0] = 8;
  local_50[1] = 0x20;
  if (*(char *)(param_1 + 0x909) == '\0') {
    piVar2 = local_50;
    lVar3 = 2;
  }
  else {
    piVar2 = local_50 + 2;
    lVar3 = 0x10;
  }
  if ((ulong)*(uint *)(param_2 + 0x5ec0 + (ulong)param_3 * 0x488) * *(long *)(param_1 + 0x3b10) ==
      0x40000000) {
    piVar1 = piVar2 + lVar3;
    do {
      if (*piVar2 == param_4) {
        return 0;
      }
      piVar2 = piVar2 + 1;
    } while (piVar1 != piVar2);
  }
  return 1;
}


// ===== 004de700 _kvgpumgrGetCreatedVgpuOnGpuInstance =====

undefined4 _kvgpumgrGetCreatedVgpuOnGpuInstance(long param_1,int param_2,undefined4 *param_3)

{
  long lVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  uVar5 = 0;
  lVar1 = *(long *)(g_pSys + 0x1f8);
  piVar3 = (int *)(lVar1 + 0x48);
  while ((*(int *)(param_1 + 0x7ac) != *piVar3 || ((char)piVar3[0x18e] != '\x01'))) {
    uVar5 = uVar5 + 1;
    piVar3 = piVar3 + 0x2eee0;
    if (uVar5 == 0x20) {
      nvCheckOkFailedNoLog
                (4,0x57,"kvgpumgrGetPgpuIndex(pKernelVgpuMgr, pGpu->gpuId, &pgpuIndex)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0x182);
      return 0x57;
    }
  }
  iVar2 = osIsVgpuVfioPresent();
  if (iVar2 != 0) {
    lVar1 = lVar1 + 600 + (ulong)uVar5 * 0xbbb80;
    puVar4 = (undefined4 *)listHead_IMPL(lVar1);
    while( true ) {
      if (puVar4 == (undefined4 *)0x0) {
        return 0x57;
      }
      if (puVar4[7] == param_2) break;
      puVar4 = (undefined4 *)listNext_IMPL(lVar1);
    }
    *param_3 = *puVar4;
    return 0;
  }
  puVar4 = (undefined4 *)listHead_IMPL(lVar1 + 0x17770b0);
  while( true ) {
    if (puVar4 == (undefined4 *)0x0) {
      return 0x57;
    }
    if ((puVar4[5] == *(int *)(param_1 + 0x7ac)) && (puVar4[7] == param_2)) break;
    puVar4 = (undefined4 *)listNext_IMPL(lVar1 + 0x17770b0);
  }
  *param_3 = *puVar4;
  return 0;
}


// ===== 004de840 _kvgpumgrSetHeterogeneousResources.constprop.0 =====

void _kvgpumgrSetHeterogeneousResources_constprop_0
               (long param_1,long param_2,uint param_3,int param_4,ulong param_5,int param_6,
               uint param_7,uint param_8,ulong param_9,long param_10,uint param_11)

{
  long lVar1;
  ulong uVar2;
  uint uVar3;
  bool bVar4;
  ulong uVar5;
  char cVar6;
  long lVar7;
  ulong uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  ulong uVar12;
  ulong uVar13;
  long lVar14;
  int iVar15;
  int *piVar16;
  ulong uVar17;
  bool bVar18;
  short local_68;
  undefined2 local_60;
  short local_48;
  uint local_44;
  
  bVar4 = true;
  uVar5 = param_9;
  do {
    if (0x18 < param_11) {
      return;
    }
    uVar3 = param_11 * 2;
    uVar9 = param_8 + param_7 >> 1;
    uVar13 = param_5;
    if (*(int *)(param_2 + 0x208) == 0) {
LAB_004debd0:
      param_9 = param_10 + uVar5 >> 1;
      uVar10 = (uint)(param_6 + (int)uVar13) >> 1;
      local_44 = param_4 + param_3 >> 1;
      _kvgpumgrSetHeterogeneousResources_constprop_0
                (param_1,param_2,param_3,local_44,uVar13,uVar10,param_7,uVar9,uVar5,param_9,uVar3);
    }
    else {
      piVar16 = (int *)(param_2 + 0x5ec0);
      uVar13 = 0;
      uVar2 = *(ulong *)(param_1 + 0x3b10);
      bVar18 = false;
      do {
        lVar14 = *(long *)(param_2 + 0x238 + uVar13 * 8);
        iVar15 = *(int *)(lVar14 + 0x184);
        if (iVar15 != 0) {
          uVar10 = *(uint *)(lVar14 + 0x310);
          uVar17 = uVar13 & 0xffffffff;
          uVar11 = uVar10 >> 1 | uVar10;
          uVar11 = uVar11 >> 2 | uVar11;
          uVar11 = uVar11 >> 4 | uVar11;
          uVar11 = uVar11 >> 8 | uVar11;
          uVar11 = uVar11 >> 0x10 | uVar11;
          uVar11 = uVar11 - (uVar11 >> 1);
          if (uVar10 == uVar3) {
            if ((*(char *)(param_1 + 0x909) != '\0') && (!bVar18)) {
              bVar18 = *(ulong *)(lVar14 + 0x358) == uVar2;
            }
            cVar6 = _kvgpumgrIsPlacementValid(param_1,param_2,uVar17,param_3);
            if (cVar6 != '\0') {
LAB_004de9a3:
              uVar8 = (ulong)*(ushort *)(lVar14 + 0x30c);
              local_44._0_2_ = (undefined2)param_3;
              *(undefined2 *)(lVar14 + 0x18c + uVar8 * 8) = (undefined2)local_44;
              local_60 = (undefined2)param_5;
              *(undefined2 *)(lVar14 + 0x18e + uVar8 * 8) = local_60;
              if (*(char *)(param_1 + 0x909) == '\0') {
                *(uint *)(param_2 + 0x5a44 + uVar17 * 0x488 + uVar8 * 0x18) = param_7;
              }
              else {
                uVar12 = uVar5;
                if (uVar2 <= *(ulong *)(lVar14 + 0x358)) {
                  uVar12 = (param_7 + *piVar16) * uVar2;
                }
                lVar7 = uVar17 * 0x488 + uVar8 * 0x18 + param_2;
                *(uint *)(lVar7 + 0x5a44) = param_7;
                if (uVar11 == 0x20) {
                  *(ulong *)(lVar7 + 0x5a48) = (param_7 + *piVar16) * uVar2;
                }
                else {
                  *(ulong *)(lVar7 + 0x5a48) = uVar12;
                }
              }
              *(short *)(lVar14 + 0x30c) = *(short *)(lVar14 + 0x30c) + 1;
              if (cVar6 != '\x01') goto LAB_004de900;
              iVar15 = *(int *)(lVar14 + 0x184);
            }
LAB_004dea10:
            cVar6 = _kvgpumgrIsPlacementValid(param_1,param_2,uVar17,param_4 - iVar15);
            if (cVar6 != '\0') {
              local_48 = (short)param_4;
              uVar8 = (ulong)*(ushort *)(lVar14 + 0x30c);
              *(short *)(lVar14 + 0x18c + uVar8 * 8) = local_48 - (short)iVar15;
              local_68 = (short)param_6;
              *(short *)(lVar14 + 0x18e + uVar8 * 8) = local_68 - *(short *)(lVar14 + 0x188);
              uVar10 = param_8 - *piVar16;
              if (*(char *)(param_1 + 0x909) == '\0') {
                *(uint *)(param_2 + 0x5a44 + uVar17 * 0x488 + uVar8 * 0x18) = uVar10;
              }
              else {
                if (*(ulong *)(lVar14 + 0x358) < uVar2) {
                  *(uint *)(param_2 + 0x5a44 + uVar17 * 0x488 + uVar8 * 0x18) = uVar10;
                  lVar7 = param_10 - *(long *)(lVar14 + 0x358);
                }
                else {
                  *(uint *)(param_2 + 0x5a44 + uVar17 * 0x488 + uVar8 * 0x18) =
                       uVar10 - (int)(*(ulong *)(lVar14 + 0x358) / uVar2);
                  lVar7 = param_8 * uVar2 - *(long *)(lVar14 + 0x358);
                }
                lVar1 = uVar17 * 0x488 + uVar8 * 0x18;
                *(long *)(param_2 + 0x5a48 + lVar1) = lVar7;
                if (uVar11 == 0x20) {
                  *(uint *)(param_2 + 0x5a44 + lVar1) = uVar10;
                  *(ulong *)(param_2 + 0x5a48 + lVar1) = uVar10 * uVar2 - *(long *)(lVar14 + 0x358);
                }
              }
              *(short *)(lVar14 + 0x30c) = *(short *)(lVar14 + 0x30c) + 1;
            }
          }
          else if (((uVar11 < uVar10) && (uVar11 == param_11)) || ((uVar10 == 1 && (param_11 == 1)))
                  ) {
            if (!bVar4) goto LAB_004dea10;
            cVar6 = _kvgpumgrIsPlacementValid(param_1,param_2,uVar17,param_3);
            if (cVar6 != '\0') {
              cVar6 = '\0';
              goto LAB_004de9a3;
            }
          }
        }
LAB_004de900:
        uVar13 = uVar13 + 1;
        piVar16 = piVar16 + 0x122;
      } while ((uint)uVar13 < *(uint *)(param_2 + 0x208));
      uVar13 = param_5 & 0xffffffff;
      if (!bVar18) goto LAB_004debd0;
      if (uVar5 != 0) {
        nvAssertFailedNoLog("(gspHeapOffsetMin == 0)","src/kernel/virtualization/kernel_vgpu_mgr.c",
                            0xcbc);
      }
      uVar10 = (uint)(param_6 + (int)param_5) >> 1;
      local_44 = param_4 + param_3 >> 1;
      _kvgpumgrSetHeterogeneousResources_constprop_0
                (param_1,param_2,param_3,local_44,param_5 & 0xffffffff,uVar10,param_7 + 1,uVar9,
                 param_7 * uVar2,uVar2 + param_7 * uVar2,uVar3);
      param_8 = param_8 - 1;
      param_9 = param_8 * uVar2;
      param_10 = uVar2 + param_9;
    }
    param_5 = (ulong)uVar10;
    bVar4 = false;
    param_3 = local_44;
    param_11 = uVar3;
    uVar5 = param_9;
    param_7 = uVar9;
  } while( true );
}


// ===== 004ded20 kvgpumgrConstruct_IMPL =====

undefined8 kvgpumgrConstruct_IMPL(long param_1)

{
  undefined8 uVar1;
  
  nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x4b,"kvgpumgrConstruct_IMPL",1,
               "NVRM: Enter function\n");
  *(undefined8 *)(param_1 + 0x17770a8) = 0;
  *(undefined8 *)(param_1 + 0x17770a0) = 0x1c000100180001;
  uVar1 = portMemAllocatorGetGlobalNonPaged();
  listInit_IMPL(param_1 + 0x1777050,uVar1,0x818);
  uVar1 = portMemAllocatorGetGlobalNonPaged();
  listInit_IMPL(param_1 + 0x1777078,uVar1,0xa0);
  uVar1 = portMemAllocatorGetGlobalNonPaged();
  listInit_IMPL(param_1 + 0x17770b0,uVar1,0x30);
  return 0;
}


// ===== 004dedd0 kvgpumgrDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kvgpumgrDestruct_IMPL(long param_1)

{
  if (*(undefined8 **)(param_1 + 0x17770a8) != (undefined8 *)0x0) {
    (*(code *)**(undefined8 **)(param_1 + 0x17770a8))();
    portMemFree(*(undefined8 *)(param_1 + 0x17770a8));
  }
  listDestroy_IMPL(param_1 + 0x17770b0);
  listDestroy_IMPL(param_1 + 0x1777050);
  listDestroy_IMPL(param_1 + 0x1777078);
  return;
}


// ===== 004dee30 kvgpumgrGetMaxInstanceOfVgpu =====

undefined8 kvgpumgrGetMaxInstanceOfVgpu(int param_1,int *param_2)

{
  int *piVar1;
  long lVar2;
  
  if (param_2 == (int *)0x0) {
    return 0x1f;
  }
  lVar2 = *(long *)(g_pSys + 0x1f8) + 0x1777050;
  piVar1 = (int *)listHead_IMPL(lVar2);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return 0x57;
    }
    if (param_1 == *piVar1) break;
    piVar1 = (int *)listNext_IMPL(lVar2);
  }
  *param_2 = piVar1[0xc4];
  return 0;
}


// ===== 004deed0 __pfx_kvgpumgrGetPgpuIndex =====

undefined8 __pfx_kvgpumgrGetPgpuIndex(long param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x48);
  iVar1 = 0;
  while ((*piVar2 != param_2 || ((char)piVar2[0x18e] != '\x01'))) {
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 0x2eee0;
    if (iVar1 == 0x20) {
      return 0x57;
    }
  }
  *param_3 = iVar1;
  return 0;
}


// ===== 004deee0 kvgpumgrGetPgpuIndex =====

undefined8 kvgpumgrGetPgpuIndex(long param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x48);
  iVar1 = 0;
  while ((*piVar2 != param_2 || ((char)piVar2[0x18e] != '\x01'))) {
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 0x2eee0;
    if (iVar1 == 0x20) {
      return 0x57;
    }
  }
  *param_3 = iVar1;
  return 0;
}


// ===== 004def30 kvgpumgrIsHeterogeneousVgpuTypeSupported =====

bool kvgpumgrIsHeterogeneousVgpuTypeSupported(void)

{
  int iVar1;
  
  iVar1 = osIsVgpuVfioPresent();
  if (iVar1 == 0) {
    return true;
  }
  iVar1 = osIsVgpuDeviceVmPresent();
  return iVar1 == 0;
}


// ===== 004def60 _kvgpumgrCheckPartitionFlag =====

int _kvgpumgrCheckPartitionFlag(long param_1,int param_2,int param_3,undefined8 param_4)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  int *piVar5;
  long local_30 [2];
  
  if ((((param_1 == 0) || (*(long *)(param_1 + 0x1bc0) == 0)) ||
      (cVar1 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1,*(long *)(param_1 + 0x1bc0)),
      param_2 == -1)) || (cVar1 == '\0')) {
    iVar2 = 0x56;
  }
  else {
    iVar2 = kmigmgrGetGPUInstanceInfo_IMPL
                      (param_1,*(undefined8 *)(param_1 + 0x1bc0),param_2,local_30);
    piVar5 = &DAT_00da1848;
    uVar4 = 0;
    if (iVar2 == 0) {
      do {
        if (param_3 == *piVar5) {
          iVar2 = (&DAT_00da1844)[uVar4 * 3];
          goto LAB_004deffd;
        }
        uVar3 = (int)uVar4 + 1;
        uVar4 = (ulong)uVar3;
        piVar5 = piVar5 + 3;
      } while (uVar3 != 0x129);
      nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x8e8,"kvgpumgrGetPartitionFlag",4,
                   "NVRM: Invalid SMC vGpu TypeId: 0x%x\n",param_3);
      iVar2 = -1;
LAB_004deffd:
      *(bool *)param_4 = *(int *)(local_30[0] + 0x96c) == iVar2;
      return 0;
    }
    nvAssertOkFailedNoLog
              (iVar2,
               "kmigmgrGetGPUInstanceInfo(pGpu, pKernelMIGManager, swizzId, &pKernelMIGGpuInstance)"
               ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0xb7);
  }
  return iVar2;
}


// ===== 004df0a0 kvgpumgrIsVgpuWarmUpdateSupported =====

bool kvgpumgrIsVgpuWarmUpdateSupported(void)

{
  int iVar1;
  
  iVar1 = osIsVgpuVfioPresent();
  if (iVar1 == 0) {
    return true;
  }
  iVar1 = osIsVgpuDeviceVmPresent();
  return iVar1 == 0;
}


// ===== 004df0d0 kvgpumgrCheckVgpuTypeCreatable =====

byte kvgpumgrCheckVgpuTypeCreatable(long param_1,long param_2,int *param_3)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = osIsVgpuVfioPresent();
  if (iVar2 == 0) {
    uVar3 = *(uint *)(param_2 + 0xbb7f4);
    if (uVar3 == 0) {
      return 0;
    }
    if (*(uint *)(param_2 + 0x208) != 0) {
      lVar1 = param_2 + (ulong)*(uint *)(param_2 + 0x208) * 4;
      do {
        if (*(int *)(param_2 + 4) == *param_3) break;
        if (*(int *)(param_2 + 4) == 0) {
          return 0x56;
        }
        param_2 = param_2 + 4;
      } while (lVar1 != param_2);
    }
  }
  else {
    uVar3 = *(uint *)(param_2 + 0x204);
    if (uVar3 == 0) {
      return 0;
    }
    if (*(uint *)(param_2 + 0x208) != 0) {
      lVar1 = param_2 + (ulong)*(uint *)(param_2 + 0x208) * 4;
      do {
        if (*(int *)(param_2 + 4) == *param_3) break;
        if (*(int *)(param_2 + 4) == 0) {
          return 0x56;
        }
        param_2 = param_2 + 4;
      } while (lVar1 != param_2);
    }
  }
  if (*(char *)(param_1 + 0x4a5) == '\0') {
    return ~-(uVar3 < (uint)param_3[0xc4]) & 0x1a;
  }
  return 0;
}


// ===== 004df1d0 kvgpumgrGetVgpuTypeInfo =====

undefined8 kvgpumgrGetVgpuTypeInfo(int param_1,undefined8 *param_2)

{
  int *piVar1;
  long lVar2;
  
  lVar2 = *(long *)(g_pSys + 0x1f8) + 0x1777050;
  piVar1 = (int *)listHead_IMPL(lVar2);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return 0x57;
    }
    if (*piVar1 == param_1) break;
    piVar1 = (int *)listNext_IMPL(lVar2);
  }
  *param_2 = piVar1;
  return 0;
}


// ===== 004df260 kvgpumgrSendAllVgpuTypesToGsp =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kvgpumgrSendAllVgpuTypesToGsp(long param_1)

{
  undefined1 *puVar1;
  long lVar2;
  long lVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  undefined1 *puVar7;
  uint uVar8;
  ulong uVar9;
  undefined1 *puVar10;
  long lVar11;
  
  uVar9 = 0;
  lVar3 = *(long *)(g_pSys + 0x1f8);
  piVar6 = (int *)(lVar3 + 0x48);
  while ((*(int *)(param_1 + 0x7ac) != *piVar6 || ((char)piVar6[0x18e] != '\x01'))) {
    uVar8 = (int)uVar9 + 1;
    uVar9 = (ulong)uVar8;
    piVar6 = piVar6 + 0x2eee0;
    if (uVar8 == 0x20) {
      nvCheckOkFailedNoLog
                (4,0x57,"kvgpumgrGetPgpuIndex(pKernelVgpuMgr, pGpu->gpuId, &index)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0x29b);
      return 0x57;
    }
  }
  lVar2 = lVar3 + uVar9 * 0xbbb80;
  if (*(int *)(lVar2 + 0x250) != 0) {
    puVar7 = (undefined1 *)portMemAllocNonPaged(0xa9808);
    if (puVar7 == (undefined1 *)0x0) {
      nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x2a9,
                   "kvgpumgrSendAllVgpuTypesToGsp",4,
                   "NVRM: Failed to alloc memory for add vGPU type params\n");
      return 0x51;
    }
    portMemSet(puVar7,0,0xa9808);
    if (*(int *)(lVar2 + 0x250) != 0) {
      puVar10 = puVar7 + 0xc;
      lVar11 = 0;
      do {
        puVar4 = *(undefined4 **)(lVar2 + 0x280 + lVar11 * 8);
        lVar11 = lVar11 + 1;
        *(undefined4 *)(puVar10 + -4) = *puVar4;
        *(undefined4 *)(puVar10 + 0x180) = puVar4[0xc4];
        *(undefined4 *)(puVar10 + 0x184) = puVar4[0xc5];
        *(undefined4 *)(puVar10 + 0x188) = puVar4[0xc6];
        *(undefined4 *)(puVar10 + 0x18c) = puVar4[199];
        *(undefined4 *)(puVar10 + 400) = puVar4[200];
        *(undefined4 *)(puVar10 + 0x194) = puVar4[0xc9];
        *(undefined4 *)(puVar10 + 0x198) = puVar4[0xca];
        *(undefined4 *)(puVar10 + 0x19c) = puVar4[0xcb];
        *(undefined4 *)(puVar10 + 0x1a0) = puVar4[0xcc];
        *(undefined4 *)(puVar10 + 0x1a8) = puVar4[0xcd];
        *(undefined8 *)(puVar10 + 0x1ac) = *(undefined8 *)(puVar4 + 0xce);
        *(undefined8 *)(puVar10 + 0x1b4) = *(undefined8 *)(puVar4 + 0xd0);
        *(undefined8 *)(puVar10 + 0x1bc) = *(undefined8 *)(puVar4 + 0xd2);
        *(undefined8 *)(puVar10 + 0x1c4) = *(undefined8 *)(puVar4 + 0xd4);
        *(undefined8 *)(puVar10 + 0x1cc) = *(undefined8 *)(puVar4 + 0xd6);
        *(undefined8 *)(puVar10 + 0x1d4) = *(undefined8 *)(puVar4 + 0xd8);
        *(undefined8 *)(puVar10 + 0x1dc) = *(undefined8 *)(puVar4 + 0xda);
        *(undefined4 *)(puVar10 + 0x1e4) = puVar4[0xdc];
        *(undefined8 *)(puVar10 + 0x1ec) = *(undefined8 *)(puVar4 + 0xde);
        *(undefined4 *)(puVar10 + 0x1380) = puVar4[0xe1];
        *(undefined4 *)(puVar10 + 0x1384) = puVar4[0xe2];
        *(undefined4 *)(puVar10 + 5000) = puVar4[0xe3];
        *(undefined4 *)(puVar10 + 0x138c) = puVar4[0xe4];
        *(undefined4 *)(puVar10 + 500) = puVar4[0xe0];
        portStringCopy(puVar10,0x40,puVar4 + 1,0x40);
        portStringCopy(puVar10 + 0x40,0x40,puVar4 + 0x11,0x40);
        portStringCopy(puVar10 + 0x100,0x80,puVar4 + 0x21,0x80);
        portStringCopy(puVar10 + 0x37c,0x1000,puVar4 + 0xe5,0x400);
        puVar1 = puVar10 + 0x80;
        puVar10 = puVar10 + 0x1530;
        portMemCopy(puVar1,0x80,puVar4 + 0x1e5,0x80);
      } while ((uint)lVar11 < *(uint *)(lVar2 + 0x250));
    }
    *puVar7 = 1;
    *(undefined4 *)(puVar7 + 4) = *(undefined4 *)(lVar3 + 0x250 + uVar9 * 0xbbb80);
    iVar5 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20804003,puVar7,0xa9808);
    if (iVar5 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar5,
                 "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_VGPU_MGR_INTERNAL_PGPU_ADD_VGPU_TYPE, pAddVgpuTypeParams, sizeof(*pAddVgpuTypeParams))"
                 ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x2b8);
    }
    portMemFree(puVar7);
    return iVar5;
  }
  return 0;
}


// ===== 004df640 kvgpumgrPgpuAddVgpuType =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kvgpumgrPgpuAddVgpuType(long param_1,char param_2,int *param_3)

{
  long lVar1;
  char *pcVar2;
  long lVar3;
  int *piVar4;
  ulong uVar5;
  uint uVar6;
  int iVar7;
  ulong uVar8;
  
  lVar1 = *(long *)(g_pSys + 0x1f8);
  pcVar2 = (char *)portMemAllocNonPaged(0xa9808);
  if (pcVar2 == (char *)0x0) {
    nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x2db,"kvgpumgrPgpuAddVgpuType",4,
                 "NVRM: Failed to alloc add vGPU type ctrl params.\n");
    return 0x51;
  }
  portMemSet(pcVar2,0,0xa9808);
  *pcVar2 = param_2;
  pcVar2[4] = '\x01';
  pcVar2[5] = '\0';
  pcVar2[6] = '\0';
  pcVar2[7] = '\0';
  memcpy(pcVar2 + 8,param_3,0x1530);
  iVar7 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20804003,pcVar2,0xa9808);
  portMemFree(pcVar2);
  if (iVar7 != 0) {
    nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x2ec,"kvgpumgrPgpuAddVgpuType",4,
                 "NVRM: Failed to create vGPU type on GSP.\n");
    return iVar7;
  }
  piVar4 = (int *)(lVar1 + 0x48);
  uVar8 = 0;
  while ((*(int *)(param_1 + 0x7ac) != *piVar4 || ((char)piVar4[0x18e] != '\x01'))) {
    uVar6 = (int)uVar8 + 1;
    uVar8 = (ulong)uVar6;
    piVar4 = piVar4 + 0x2eee0;
    if (uVar6 == 0x20) {
      return 0x57;
    }
  }
  if ((*(int *)(lVar1 + 0x250 + uVar8 * 0xbbb80) == 0x80) && (param_2 == '\0')) {
    return 0x56;
  }
  if ((*(int *)(lVar1 + 0x14 + (uVar8 + 1) * 0xbbb80) == 0) && (param_3[0x61] != 1)) {
    param_3[0x6b] = 0;
  }
  iVar7 = *param_3;
  lVar3 = *(long *)(g_pSys + 0x1f8) + 0x1777050;
  piVar4 = (int *)listHead_IMPL(lVar3);
  while (piVar4 != (int *)0x0) {
    if (iVar7 == *piVar4) goto LAB_004df7d2;
    piVar4 = (int *)listNext_IMPL(lVar3);
  }
  piVar4 = (int *)listAppendNew_IMPL(*(long *)(g_pSys + 0x1f8) + 0x1777050);
  if (piVar4 == (int *)0x0) {
    nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x308,"kvgpumgrPgpuAddVgpuType",4,
                 "NVRM: Failed to create vGPU type.\n");
    return 0x51;
  }
  vgpuMgrFillVgpuType(param_3,piVar4);
LAB_004df7d2:
  if (param_2 == '\0') {
    uVar6 = *(uint *)(lVar1 + 0x250 + uVar8 * 0xbbb80);
    uVar5 = (ulong)uVar6;
    iVar7 = uVar6 + 1;
    if (uVar6 != 0) goto LAB_004df85e;
  }
  else {
    *(undefined4 *)(lVar1 + 0x250 + uVar8 * 0xbbb80) = 0;
  }
  *(undefined1 *)(lVar1 + 0xbb838 + uVar8 * 0xbbb80) = *(undefined1 *)(param_1 + 0x491d);
  uVar5 = 0;
  iVar7 = 1;
LAB_004df85e:
  *(int **)(lVar1 + 0x10 + (uVar5 + 0x4e + uVar8 * 0x17770) * 8) = piVar4;
  *(int *)(lVar1 + 0x250 + uVar8 * 0xbbb80) = iVar7;
  vgpuMgrSetNominalFbSize(lVar1 + 0xbbba0 + uVar8 * 0xbbb80);
  return 0;
}


// ===== 004df980 kvgpumgrAttachGpu =====

undefined8 kvgpumgrAttachGpu(int param_1)

{
  uint uVar1;
  long lVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  long lVar6;
  undefined8 uVar7;
  ulong uVar8;
  uint uVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  long local_50;
  long local_48;
  long local_40;
  
  lVar2 = *(long *)(g_pSys + 0x1f8);
  nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x32c,"kvgpumgrAttachGpu",1,
               "NVRM: Enter function\n");
  if (lVar2 == 0) {
    nvAssertFailedNoLog("(pKernelVgpuMgr != NULL)","src/kernel/virtualization/kernel_vgpu_mgr.c",
                        0x32e);
    return 0x56;
  }
  uVar1 = *(uint *)(lVar2 + 0x1777048);
  uVar8 = (ulong)uVar1;
  if (uVar1 == 0) {
    lVar10 = 0;
    uVar12 = 0;
    local_50 = 600;
    local_48 = 0xbb810;
    local_40 = 0x29ed0;
  }
  else {
    piVar3 = (int *)(lVar2 + 0x48);
    uVar9 = 0;
    do {
      if (((char)piVar3[0x18e] != '\x01') && (*piVar3 == param_1)) {
        uVar8 = (ulong)uVar9;
        break;
      }
      uVar9 = uVar9 + 1;
      piVar3 = piVar3 + 0x2eee0;
    } while (uVar1 != uVar9);
    if ((int)uVar8 == 0x20) {
      nvAssertFailedNoLog("(index != NV_MAX_DEVICES)","src/kernel/virtualization/kernel_vgpu_mgr.c",
                          0x337);
      return 0x1a;
    }
    lVar10 = uVar8 * 0xbbb80;
    local_40 = lVar10 + 0x29ed0;
    local_48 = lVar10 + 0xbb810;
    local_50 = lVar10 + 600;
    uVar12 = uVar8;
  }
  lVar11 = uVar12 * 0xbbb80;
  puVar4 = (undefined4 *)(lVar2 + 0x4c + lVar11);
  do {
    *puVar4 = 0;
    puVar5 = puVar4 + 2;
    puVar4[1] = 0;
    puVar4 = puVar5;
  } while (puVar5 != (undefined4 *)(lVar2 + 0x24c + lVar11));
  uVar1 = *(uint *)(lVar2 + 0x250 + uVar12 * 0xbbb80);
  if (uVar1 != 0) {
    lVar11 = lVar2 + lVar11;
    do {
      lVar6 = lVar11 + 4;
      *(undefined4 *)(lVar11 + 0x4c) =
           **(undefined4 **)((uVar12 * -0xbbb80 - lVar2) + 0x280 + lVar11 * 2);
      lVar11 = lVar6;
    } while (lVar2 + ((ulong)uVar1 + uVar12 * 0x2eee0) * 4 != lVar6);
  }
  lVar11 = uVar12 * 0xbbb80;
  *(undefined4 *)(lVar2 + 0x24c + lVar11) = 0;
  *(undefined1 *)(lVar2 + 0x680 + lVar11) = 1;
  *(undefined4 *)(lVar2 + 0xbb83c + lVar11) = 0;
  uVar7 = portMemAllocatorGetGlobalNonPaged();
  listInit_IMPL(local_48 + lVar2,uVar7,0x10);
  uVar7 = portMemAllocatorGetGlobalNonPaged();
  listInit_IMPL(local_50 + lVar2,uVar7,0x890);
  if (*(int *)(lVar2 + 0x1777048) == (int)uVar8) {
    *(int *)(lVar2 + 0x48 + lVar11) = param_1;
    *(undefined8 *)(lVar2 + 0x250 + lVar11) = 0;
    portMemSet(lVar2 + 0xbbba0 + lVar10,0,0x28);
    *(int *)(lVar2 + 0x1777048) = *(int *)(lVar2 + 0x1777048) + 1;
  }
  portMemSet(local_40 + lVar2,0,0x91940);
  return 0;
}


// ===== 004dfc20 kvgpumgrMigTimeslicingModeEnabled =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kvgpumgrMigTimeslicingModeEnabled(long param_1)

{
  long lVar1;
  char cVar2;
  ulong uVar3;
  int *piVar4;
  uint uVar5;
  undefined1 local_19;
  
  lVar1 = *(long *)(g_pSys + 0x1f8);
  cVar2 = hypervisorIsVgxHyper_IMPL();
  uVar3 = 0;
  if (cVar2 != '\0') {
    local_19 = 0;
    if (lVar1 == 0) {
      nvAssertFailedNoLog("(pKernelVgpuMgr != NULL)","src/kernel/virtualization/kernel_vgpu_mgr.c",
                          0x360);
    }
    else {
      if (param_1 != 0) {
        piVar4 = (int *)(lVar1 + 0x48);
        uVar3 = 0;
        while ((*(int *)(param_1 + 0x7ac) != *piVar4 || ((char)piVar4[0x18e] != '\x01'))) {
          uVar5 = (int)uVar3 + 1;
          uVar3 = (ulong)uVar5;
          piVar4 = piVar4 + 0x2eee0;
          if (uVar5 == 0x20) {
            nvCheckOkFailedNoLog
                      (4,0x57,"kvgpumgrGetPgpuIndex(pKernelVgpuMgr, pGpu->gpuId, &i)",
                       "src/kernel/virtualization/kernel_vgpu_mgr.c",0x364);
            return 0x57;
          }
        }
        *(undefined1 *)(lVar1 + 0xbbb99 + uVar3 * 0xbbb80) = 0;
        local_19 = *(char *)(param_1 + 0x46b) != '\0';
        *(undefined1 *)(lVar1 + 0xbbb99 + uVar3 * 0xbbb80) = local_19;
        uVar3 = (**(code **)(param_1 + 0x3b90))
                          (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                           *(undefined4 *)(param_1 + 0x3b3c),0x2080400f,&local_19,1);
        if ((int)uVar3 == 0) {
          return uVar3;
        }
        nvCheckOkFailedNoLog
                  (4,uVar3 & 0xffffffff,
                   "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_VGPU_MGR_INTERNAL_SET_VGPU_MIG_TIMESLICE_MODE, &params, sizeof(params))"
                   ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x371);
        return uVar3 & 0xffffffff;
      }
      nvAssertFailedNoLog("(pGpu != NULL)","src/kernel/virtualization/kernel_vgpu_mgr.c",0x362);
    }
    uVar3 = 0x1f;
  }
  return uVar3;
}


// ===== 004dfda0 kvgpumgrIsMigTimeslicingModeEnabled =====

undefined1 kvgpumgrIsMigTimeslicingModeEnabled(long param_1)

{
  long lVar1;
  int *piVar2;
  uint uVar3;
  ulong uVar4;
  
  lVar1 = *(long *)(g_pSys + 0x1f8);
  if (lVar1 == 0) {
    nvCheckFailedNoLog(4,"(pKernelVgpuMgr != NULL)","src/kernel/virtualization/kernel_vgpu_mgr.c",
                       0x381);
  }
  else if (param_1 == 0) {
    nvCheckFailedNoLog(4,"(pGpu != NULL)","src/kernel/virtualization/kernel_vgpu_mgr.c",899);
  }
  else {
    piVar2 = (int *)(lVar1 + 0x48);
    uVar4 = 0;
    do {
      if ((*(int *)(param_1 + 0x7ac) == *piVar2) && ((char)piVar2[0x18e] == '\x01')) {
        return *(undefined1 *)(lVar1 + 0xbbb99 + uVar4 * 0xbbb80);
      }
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulong)uVar3;
      piVar2 = piVar2 + 0x2eee0;
    } while (uVar3 != 0x20);
    nvCheckOkFailedNoLog
              (4,0x57,"kvgpumgrGetPgpuIndex(pKernelVgpuMgr, pGpu->gpuId, &i)",
               "src/kernel/virtualization/kernel_vgpu_mgr.c",0x385);
  }
  return 0;
}


// ===== 004dfe80 _kvgpumgrGetMaxTotalGspHeapSize =====

ulong _kvgpumgrGetMaxTotalGspHeapSize(long param_1,long param_2,int *param_3)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  int iVar6;
  int *extraout_RDX;
  int *extraout_RDX_00;
  int *extraout_RDX_01;
  int *piVar7;
  long lVar8;
  ulong local_40;
  
  if (*(int *)(param_2 + 0x208) == 0) {
    local_40 = 0;
  }
  else {
    lVar8 = 0;
    iVar6 = (int)param_3;
    local_40 = 0;
    while (piVar7 = *(int **)(param_2 + 0x238 + lVar8 * 8), piVar7 != (int *)0x0) {
      if (param_1 != 0) {
        while (((*(long *)(param_1 + 0x1bc0) != 0 &&
                (cVar1 = kmigmgrIsMIGGpuInstancingEnabled_IMPL
                                   (param_1,*(long *)(param_1 + 0x1bc0),param_3),
                param_3 = extraout_RDX, cVar1 != '\0')) &&
               (cVar1 = kvgpumgrIsMigTimeslicingModeEnabled(param_1), param_3 = extraout_RDX_00,
               cVar1 != '\0'))) {
          param_3 = (int *)(ulong)(uint)piVar7[0xcc];
          if (piVar7[0xcc] != 0) {
            param_3 = &DAT_00da1848;
            uVar5 = 0;
            do {
              if (*piVar7 == *param_3) {
                iVar4 = (&DAT_00da1844)[uVar5 * 3];
                goto LAB_004dffbe;
              }
              uVar3 = (int)uVar5 + 1;
              uVar5 = (ulong)uVar3;
              param_3 = param_3 + 3;
            } while (uVar3 != 0x129);
            nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x8e8,
                         "kvgpumgrGetPartitionFlag",4,"NVRM: Invalid SMC vGpu TypeId: 0x%x\n");
            iVar4 = -1;
            param_3 = extraout_RDX_01;
LAB_004dffbe:
            if (iVar6 == iVar4) goto LAB_004dfeda;
          }
          lVar8 = lVar8 + 1;
          if (*(uint *)(param_2 + 0x208) <= (uint)lVar8) {
            return local_40;
          }
          piVar7 = *(int **)(param_2 + 0x238 + lVar8 * 8);
          if (piVar7 == (int *)0x0) {
            return local_40;
          }
        }
      }
      uVar5 = local_40;
      if (piVar7[0xcc] == 0) {
LAB_004dfeda:
        uVar3 = piVar7[0x61];
        uVar2 = vgpuMgrGetPlacementRegionSize(param_1,param_2 + 0xbbb58,piVar7);
        param_3 = (int *)(((ulong)uVar2 * *(long *)(piVar7 + 0xd6)) % (ulong)uVar3);
        uVar5 = ((ulong)uVar2 * *(long *)(piVar7 + 0xd6)) / (ulong)uVar3 + 0x1fffff &
                0xffffffffffe00000;
        if (uVar5 <= local_40) {
          uVar5 = local_40;
        }
      }
      local_40 = uVar5;
      lVar8 = lVar8 + 1;
      if (*(uint *)(param_2 + 0x208) <= (uint)lVar8) {
        return local_40;
      }
    }
  }
  return local_40;
}


// ===== 004e0060 kvgpumgrDetachGpu =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kvgpumgrDetachGpu(int param_1)

{
  long lVar1;
  long lVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  uint uVar10;
  ulong uVar11;
  undefined2 *puVar12;
  undefined2 *puVar13;
  long lVar14;
  
  lVar2 = *(long *)(g_pSys + 0x1f8);
  nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x39c,"kvgpumgrDetachGpu",1,
               "NVRM: Enter function\n");
  uVar11 = 0;
  piVar4 = (int *)(lVar2 + 0x48);
  if (lVar2 == 0) {
    nvAssertFailedNoLog("(pKernelVgpuMgr != NULL)","src/kernel/virtualization/kernel_vgpu_mgr.c",
                        0x39e);
    return 0x56;
  }
  while ((param_1 != *piVar4 || ((char)piVar4[0x18e] != '\x01'))) {
    uVar10 = (int)uVar11 + 1;
    uVar11 = (ulong)uVar10;
    piVar4 = piVar4 + 0x2eee0;
    if (uVar10 == 0x20) {
      return 0x57;
    }
  }
  lVar14 = uVar11 * 0xbbb80;
  lVar9 = lVar2 + lVar14;
  *(undefined1 *)(lVar9 + 0x680) = 0;
  *(undefined8 *)(lVar9 + 0xbbb40) = 0;
  *(undefined8 *)(lVar9 + 0xbbb50) = 0;
  *(undefined4 *)(lVar9 + 0xbb83c) = 0;
  puVar6 = (undefined4 *)(lVar2 + 0x4c + lVar14);
  do {
    *puVar6 = 0;
    puVar5 = puVar6 + 2;
    puVar6[1] = 0;
    puVar6 = puVar5;
  } while (puVar5 != (undefined4 *)(lVar2 + 0x24c + lVar14));
  puVar6 = (undefined4 *)(lVar2 + 0xbbb58 + lVar14);
  do {
    *puVar6 = 0;
    puVar5 = puVar6 + 3;
    puVar6[1] = 0;
    puVar6[2] = 0;
    puVar6 = puVar5;
  } while (puVar5 != (undefined4 *)(lVar2 + 0xbbb94 + lVar14));
  lVar7 = uVar11 * 0xbbb80 + lVar2;
  if (*(char *)(lVar7 + 0xbb83a) == '\x01') {
    uVar10 = *(uint *)(lVar7 + 0x250);
    if (uVar10 != 0) {
      puVar13 = (undefined2 *)(lVar2 + 0x5a88 + lVar14);
      do {
        lVar7 = *(long *)(lVar9 + 0x280);
        if ((lVar7 != 0) && (*(short *)(lVar7 + 0x30e) != 0)) {
          lVar8 = 0;
          puVar12 = puVar13;
          do {
            lVar1 = lVar8 * 8;
            lVar8 = lVar8 + 1;
            *puVar12 = *(undefined2 *)(lVar7 + 400 + lVar1);
            puVar12 = puVar12 + 0xc;
          } while ((uint)lVar8 < (uint)*(ushort *)(lVar7 + 0x30e));
        }
        lVar9 = lVar9 + 8;
        puVar13 = puVar13 + 0x244;
      } while (lVar9 != lVar2 + ((ulong)uVar10 + uVar11 * 0x17770) * 8);
    }
    bitVectorClrAll_IMPL(lVar2 + 0x29e90 + lVar14,0x200);
    iVar3 = listCount_IMPL(lVar2 + 0x17770b0);
  }
  else {
    iVar3 = listCount_IMPL(lVar2 + 0x17770b0);
  }
  if (iVar3 != 0) {
    lVar9 = listHead_IMPL(lVar2 + 0x17770b0);
    while (lVar7 = lVar9, lVar7 != 0) {
      lVar9 = listNext_IMPL(lVar2 + 0x17770b0,lVar7);
      if (*(int *)(lVar7 + 0x14) == param_1) {
        (**(code **)(*(long *)(lVar2 + 0x17770a8) + 0x10))
                  (*(long *)(lVar2 + 0x17770a8),*(undefined2 *)(lVar7 + 0x24));
        listRemove_IMPL(lVar2 + 0x17770b0,lVar7);
      }
    }
  }
  listDestroy_IMPL(lVar2 + 600 + lVar14);
  portMemSet(lVar2 + 0x29ed0 + lVar14,0,0x91940);
  return 0;
}


// ===== 004e0360 kvgpumgrRegisterGuestId =====

undefined8 kvgpumgrRegisterGuestId(char *param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  int *piVar3;
  long lVar4;
  
  lVar4 = *(long *)(g_pSys + 0x1f8);
  if (*param_1 == '\0') {
    lVar4 = lVar4 + 0x1777078;
    for (piVar3 = (int *)listHead_IMPL(lVar4); piVar3 != (int *)0x0;
        piVar3 = (int *)listNext_IMPL(lVar4,piVar3)) {
      iVar1 = *(int *)(param_1 + 8);
      if (iVar1 == *piVar3) {
        if (iVar1 == 0) {
          if (*(long *)(param_1 + 0x10) == *(long *)(piVar3 + 2)) goto LAB_004e0440;
        }
        else if ((iVar1 == 1) && (iVar1 = portMemCmp(param_1 + 0x10,piVar3 + 2,0x10), iVar1 == 0))
        goto LAB_004e0440;
      }
    }
    piVar3 = (int *)listAppendNew_IMPL(lVar4);
    if (piVar3 == (int *)0x0) {
      uVar2 = 0x51;
    }
    else {
      portMemSet(piVar3,0,0xa0);
LAB_004e0440:
      if (piVar3[0x26] == 0x10) {
        nvAssertFailedNoLog("pVgpuGuest->numVgpuDevices != MAX_VGPU_DEVICES_PER_VM",
                            "src/kernel/virtualization/kernel_vgpu_mgr.c",0x419);
        uVar2 = 0x1a;
      }
      else {
        piVar3[0x26] = piVar3[0x26] + 1;
        *(int **)(param_2 + 0x10) = piVar3;
        iVar1 = *(int *)(param_1 + 8);
        *piVar3 = iVar1;
        if (iVar1 == 0) {
          *(undefined8 *)(piVar3 + 2) = *(undefined8 *)(param_1 + 0x10);
          return 0;
        }
        if (iVar1 == 1) {
          portMemCopy(piVar3 + 2,0x10,param_1 + 0x10,0x10);
          uVar2 = 0;
        }
        else {
          uVar2 = 0;
        }
      }
    }
  }
  else {
    uVar2 = 0x1f;
    if (*param_1 == '\x01') {
      if (*(long *)(param_2 + 0x10) == 0) {
        uVar2 = 0x10007;
      }
      else {
        piVar3 = (int *)(*(long *)(param_2 + 0x10) + 0x98);
        *piVar3 = *piVar3 + -1;
        if (*piVar3 == 0) {
          listRemove_IMPL(lVar4 + 0x1777078);
        }
        *(undefined8 *)(param_2 + 0x10) = 0;
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}


// ===== 004e0560 kvgpumgrHeterogeneousGetChidOffset =====

undefined8 kvgpumgrHeterogeneousGetChidOffset(int param_1,short param_2,int param_3,ulong *param_4)

{
  ushort uVar1;
  int *piVar2;
  ulong uVar3;
  long lVar4;
  
  lVar4 = *(long *)(g_pSys + 0x1f8) + 0x1777050;
  piVar2 = (int *)listHead_IMPL(lVar4);
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return 0x57;
    }
    if (param_1 == *piVar2) break;
    piVar2 = (int *)listNext_IMPL(lVar4);
  }
  if (param_2 == -1) {
    return 0x1f;
  }
  if (piVar2[0x62] != param_3) {
    return 0x40;
  }
  uVar1 = *(ushort *)(piVar2 + 0xc3);
  if (uVar1 < 0x31) {
    if (uVar1 == 0) {
      return 0x57;
    }
    uVar3 = 0;
    do {
      if ((short)piVar2[uVar3 * 2 + 99] == param_2) {
        *param_4 = (ulong)*(ushort *)((long)piVar2 + (uVar3 & 0xffffffff) * 8 + 0x18e);
        return 0;
      }
      uVar3 = uVar3 + 1;
    } while ((uint)uVar3 < (uint)uVar1);
    return 0x57;
  }
  return 0x2c;
}


// ===== 004e0660 kvgpumgrHomogeneousGetChidOffset =====

undefined8 kvgpumgrHomogeneousGetChidOffset(int param_1,short param_2,int param_3,ulong *param_4)

{
  ushort uVar1;
  int *piVar2;
  ulong uVar3;
  long lVar4;
  
  lVar4 = *(long *)(g_pSys + 0x1f8) + 0x1777050;
  piVar2 = (int *)listHead_IMPL(lVar4);
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return 0x57;
    }
    if (param_1 == *piVar2) break;
    piVar2 = (int *)listNext_IMPL(lVar4);
  }
  if (param_2 == -1) {
    return 0x1f;
  }
  if (piVar2[0x62] != param_3) {
    return 0x40;
  }
  uVar1 = *(ushort *)((long)piVar2 + 0x30e);
  if (uVar1 < 0x31) {
    if (uVar1 == 0) {
      return 0x57;
    }
    uVar3 = 0;
    do {
      if ((short)piVar2[uVar3 * 2 + 100] == param_2) {
        *param_4 = (ulong)*(ushort *)((long)piVar2 + (uVar3 & 0xffffffff) * 8 + 0x192);
        return 0;
      }
      uVar3 = uVar3 + 1;
    } while ((uint)uVar3 < (uint)uVar1);
    return 0x57;
  }
  return 0x2c;
}


// ===== 004e0760 kvgpumgrCheckPgpuMigrationSupport =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined1 kvgpumgrCheckPgpuMigrationSupport(long param_1)

{
  int iVar1;
  undefined1 local_9;
  
  local_9 = 0;
  iVar1 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x2080400a,&local_9,1);
  if (iVar1 == 0) {
    return local_9;
  }
  nvCheckOkFailedNoLog
            (4,iVar1,
             "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_VGPU_MGR_INTERNAL_GET_PGPU_MIGRATION_SUPPORT, &params, sizeof(params))"
             ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x6cf);
  return 0;
}


// ===== 004e07e0 kvgpumgrGetPgpuDevIdEncoding =====

undefined8 kvgpumgrGetPgpuDevIdEncoding(long param_1,long param_2,uint param_3)

{
  char *pcVar1;
  char *pcVar2;
  byte bVar3;
  char cVar4;
  uint local_20;
  uint local_1c;
  
  local_20 = (uint)*(ushort *)(param_1 + 0x7f6);
  local_1c = (uint)*(ushort *)(param_1 + 0x7fe);
  _get_chip_id_for_alias_pgpu(&local_20,&local_1c);
  if ((7 < param_3) && (param_2 != 0)) {
    pcVar1 = (char *)(param_2 + 3);
    do {
      bVar3 = (byte)local_20 & 0xf;
      cVar4 = bVar3 + 0x37;
      if (bVar3 < 10) {
        cVar4 = bVar3 + 0x30;
      }
      pcVar2 = pcVar1 + -1;
      local_20 = local_20 >> 4;
      *pcVar1 = cVar4;
      pcVar1 = pcVar2;
    } while ((char *)(param_2 + -1) != pcVar2);
    return 4;
  }
  return 0xffffffff;
}


// ===== 004e0880 kvgpumgrGetPgpuSubdevIdEncoding =====

undefined8 kvgpumgrGetPgpuSubdevIdEncoding(long param_1,long param_2,uint param_3)

{
  char *pcVar1;
  char *pcVar2;
  byte bVar3;
  char cVar4;
  uint local_20;
  uint local_1c;
  
  local_20 = (uint)*(ushort *)(param_1 + 0x7f6);
  local_1c = (uint)*(ushort *)(param_1 + 0x7fe);
  _get_chip_id_for_alias_pgpu(&local_20,&local_1c);
  if ((7 < param_3) && (param_2 != 0)) {
    pcVar1 = (char *)(param_2 + 3);
    do {
      bVar3 = (byte)local_1c & 0xf;
      cVar4 = bVar3 + 0x37;
      if (bVar3 < 10) {
        cVar4 = bVar3 + 0x30;
      }
      pcVar2 = pcVar1 + -1;
      local_1c = local_1c >> 4;
      *pcVar1 = cVar4;
      pcVar1 = pcVar2;
    } while ((char *)(param_2 + -1) != pcVar2);
    return 4;
  }
  return 0xffffffff;
}


// ===== 004e0920 kvgpumgrGetPgpuFSEncoding =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 kvgpumgrGetPgpuFSEncoding(long param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 local_12c [256];
  undefined4 local_2c;
  
  memset(local_12c,0,0x104);
  local_2c = param_3;
  iVar1 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20804009,local_12c,0x104);
  if (iVar1 == 0) {
    portMemCopy(param_2,param_3,local_12c,local_2c);
    return local_2c;
  }
  nvCheckOkFailedNoLog
            (4,iVar1,
             "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_VGPU_MGR_INTERNAL_GET_PGPU_FS_ENCODING, &params, sizeof(params))"
             ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x72c);
  return 0xffffffff;
}


// ===== 004e09f0 kvgpumgrGetEccAndPrReservedFb =====

long kvgpumgrGetEccAndPrReservedFb(long param_1)

{
  undefined8 uVar1;
  char cVar2;
  long lVar3;
  long lVar4;
  ulong local_20;
  
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x1b78) + 0x478);
  lVar3 = kmemsysGetStaticConfig_IMPL(param_1,*(undefined8 *)(param_1 + 0x1b70));
  if ((*(char *)(param_1 + 0x491d) == '\0') && (*(char *)(param_1 + 0x457) != '\0')) {
    cVar2 = rmcfg_IsPASCAL_CLASSIC_GPUSorBetter(param_1);
    lVar4 = (-(ulong)(cVar2 == '\0') & 0xfffffffff8400000) + 0x8000000;
  }
  else {
    lVar4 = 0;
  }
  if (*(char *)(lVar3 + 5) != '\0') {
    if ((1 < *(int *)(lVar3 + 0x1c) - 0xeU) && (*(int *)(lVar3 + 0x1c) != 0x14)) {
      heapGetUsableSize_IMPL(uVar1,&local_20);
      return lVar4 + local_20 / 0xf;
    }
  }
  return lVar4;
}


// ===== 004e0ac0 kvgpumgrGetPgpuCapEncoding =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kvgpumgrGetPgpuCapEncoding(long param_1,long param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  ulong uVar4;
  char *pcVar6;
  byte bVar7;
  char local_698 [8];
  undefined8 auStack_690 [7];
  char local_655;
  char local_30 [24];
  ulong uVar5;
  
  if ((param_3 < 8) || (param_2 == 0)) {
    return 0xffffffff;
  }
  memset(local_698,0,0x680);
  iVar1 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x2080012f,local_698,0x680);
  if (iVar1 == 0) {
    pcVar3 = local_698;
    do {
      if (*pcVar3 != '\0') {
        bVar7 = 1;
        break;
      }
      pcVar3 = pcVar3 + 0x28;
      bVar7 = 0;
    } while (pcVar3 != local_30);
  }
  else {
    bVar7 = 0;
  }
  uVar4 = 0;
  do {
    uVar2 = (int)uVar4 + 0x20;
    uVar5 = (ulong)uVar2;
    pcVar3 = local_698 + uVar4;
    pcVar3[0] = '\0';
    pcVar3[1] = '\0';
    pcVar3[2] = '\0';
    pcVar3[3] = '\0';
    pcVar3[4] = '\0';
    pcVar3[5] = '\0';
    pcVar3[6] = '\0';
    pcVar3[7] = '\0';
    *(undefined8 *)((long)auStack_690 + uVar4) = 0;
    *(undefined8 *)((long)auStack_690 + uVar4 + 8) = 0;
    *(undefined8 *)((long)auStack_690 + uVar4 + 0x10) = 0;
    uVar4 = uVar5;
  } while (uVar2 < 0x40);
  pcVar3 = local_698 + uVar5;
  pcVar3[0] = '\0';
  pcVar3[1] = '\0';
  pcVar3[2] = '\0';
  pcVar3[3] = '\0';
  pcVar3[4] = '\0';
  pcVar3[5] = '\0';
  pcVar3[6] = '\0';
  pcVar3[7] = '\0';
  *(undefined8 *)((long)auStack_690 + uVar5) = 0;
  iVar1 = (**(code **)(param_1 + 0x310))(param_1);
  if ((iVar1 == 0) && (local_655 != '\0')) {
    bVar7 = bVar7 | 2;
  }
  pcVar3 = (char *)(param_2 + 7);
  do {
    pcVar6 = pcVar3 + -1;
    *pcVar3 = bVar7 + 0x30;
    bVar7 = 0;
    pcVar3 = pcVar6;
  } while (pcVar6 != (char *)(param_2 + -1));
  return 8;
}


// ===== 004e0c30 kvgpumgrGetHostVgpuVersion =====

undefined8 kvgpumgrGetHostVgpuVersion(undefined4 *param_1,undefined4 *param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(g_pSys + 0x1f8);
  *param_1 = *(undefined4 *)(lVar1 + 0x17770a0);
  *param_2 = *(undefined4 *)(lVar1 + 0x17770a4);
  return 0;
}


// ===== 004e0c60 kvgpumgrSetHostVgpuVersion =====

undefined1  [16] kvgpumgrSetHostVgpuVersion(ulong param_1,ulong param_2)

{
  long lVar1;
  undefined1 auVar2 [16];
  undefined8 extraout_RDX;
  undefined8 uVar3;
  undefined8 extraout_RDX_00;
  uint uVar4;
  uint uVar5;
  undefined1 auVar6 [16];
  ulong uStack_30;
  
  uVar5 = (uint)param_1;
  uVar4 = (uint)param_2;
  if (uVar4 < uVar5) {
    nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x7c0,"kvgpumgrSetHostVgpuVersion",4,
                 "NVRM: Maximum vGPU version (0x%x) being set is less than minimum version (0x%x)\n"
                 ,param_2 & 0xffffffff,param_1);
    uVar3 = extraout_RDX_00;
  }
  else {
    if ((0x180000 < uVar5) && (uVar4 < 0x1c0002)) {
      lVar1 = *(long *)(g_pSys + 0x1f8);
      nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x7d4,"kvgpumgrSetHostVgpuVersion",
                   1,"NVRM: vGPU version range enforced by user: (0x%x, 0x%x)\n",
                   param_1 & 0xffffffff,param_2);
      *(uint *)(lVar1 + 0x17770a4) = uVar4;
      *(uint *)(lVar1 + 0x17770a0) = uVar5;
      auVar2._8_8_ = 0;
      auVar2._0_8_ = uStack_30;
      return auVar2 << 0x40;
    }
    nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x7cc,"kvgpumgrSetHostVgpuVersion",4,
                 "NVRM: vGPU version range being set (0x%x, 0x%x) is outside the range supported by host (0x%x, 0x%x)\n"
                 ,param_1 & 0xffffffff,param_2 & 0xffffffff,0x180001,0x1c0001);
    uVar3 = extraout_RDX;
  }
  auVar6._8_8_ = uVar3;
  auVar6._0_8_ = 0x1f;
  return auVar6;
}


// ===== 004e0d80 _kvgpumgrClearAssignedSwizzIdMask =====

undefined8 _kvgpumgrClearAssignedSwizzIdMask(long param_1,uint param_2)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  ulong uVar7;
  ulong uVar8;
  long lVar9;
  
  if (0xe < param_2) {
    return 0x1f;
  }
  uVar7 = 0;
  lVar2 = *(long *)(g_pSys + 0x1f8);
  piVar5 = (int *)(lVar2 + 0x48);
  while ((*(int *)(param_1 + 0x7ac) != *piVar5 || ((char)piVar5[0x18e] != '\x01'))) {
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulong)uVar6;
    piVar5 = piVar5 + 0x2eee0;
    if (uVar6 == 0x20) {
      return 0x57;
    }
  }
  uVar8 = 1L << ((byte)param_2 & 0x3f);
  lVar9 = uVar7 * 0xbbb80 + lVar2;
  uVar3 = *(ulong *)(lVar9 + 0xbbb50);
  if ((uVar3 & uVar8) == 0) {
    nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x834,
                 "_kvgpumgrClearAssignedSwizzIdMask",4,"NVRM: SwizzID - %d not in use\n",param_2);
  }
  else {
    lVar1 = (ulong)param_2 + 0x2eed4 + uVar7 * 0x2eee0;
    iVar4 = *(int *)(lVar2 + 8 + lVar1 * 4);
    if (iVar4 != 0) {
      iVar4 = iVar4 + -1;
      *(int *)(lVar2 + 8 + lVar1 * 4) = iVar4;
      if (iVar4 == 0) {
        *(ulong *)(lVar9 + 0xbbb50) = ~uVar8 & uVar3;
        return 0;
      }
      return 0;
    }
    nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x83f,
                 "_kvgpumgrClearAssignedSwizzIdMask",4,
                 "NVRM: SwizzID - %d already has no assigned vGPU\n",param_2);
  }
  return 0x40;
}


// ===== 004e0ea0 kvgpumgrGetPartitionFlag =====

undefined8 kvgpumgrGetPartitionFlag(int param_1,undefined4 *param_2)

{
  uint uVar1;
  ulong uVar2;
  int *piVar3;
  
  *param_2 = 0xffffffff;
  piVar3 = &DAT_00da1848;
  uVar2 = 0;
  do {
    if (*piVar3 == param_1) {
      *param_2 = (&DAT_00da1844)[uVar2 * 3];
      return 0;
    }
    uVar1 = (int)uVar2 + 1;
    uVar2 = (ulong)uVar1;
    piVar3 = piVar3 + 3;
  } while (uVar1 != 0x129);
  nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x8e8,"kvgpumgrGetPartitionFlag",4,
               "NVRM: Invalid SMC vGpu TypeId: 0x%x\n",param_1);
  return 0x1f;
}


// ===== 004e0f20 kvgpumgrProcessVfInfo =====

undefined8
kvgpumgrProcessVfInfo
          (int param_1,char param_2,int param_3,uint param_4,uint param_5,uint param_6,
          undefined1 param_7,long param_8)

{
  int *piVar1;
  long lVar2;
  uint uVar3;
  ulong uVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  
  uVar5 = 0;
  lVar6 = *(long *)(g_pSys + 0x1f8);
  piVar1 = (int *)(lVar6 + 0x48);
  while ((param_1 != *piVar1 || ((char)piVar1[0x18e] != '\x01'))) {
    uVar3 = (int)uVar5 + 1;
    uVar5 = (ulong)uVar3;
    piVar1 = piVar1 + 0x2eee0;
    if (uVar3 == 0x20) {
      return 0x57;
    }
  }
  if (param_2 == '\0') {
    uVar4 = 0;
    lVar7 = uVar5 * 0xbbb80 + lVar6;
    lVar2 = lVar7;
    while ((((*(int *)(lVar2 + 0xbb840) != param_3 || (*(byte *)(lVar2 + 0xbb844) != param_4)) ||
            (*(byte *)(lVar2 + 0xbb845) != param_5)) || (*(byte *)(lVar2 + 0xbb846) != param_6))) {
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulong)uVar3;
      lVar2 = lVar2 + 0xc;
      if (uVar3 == 0x40) {
        uVar4 = 0;
        do {
          if (*(char *)(lVar7 + 0xbb847) == '\0') {
            lVar2 = uVar5 * 0xbbb80 + uVar4 * 0xc;
            *(undefined1 *)(lVar6 + 0xbb847 + lVar2) = 1;
            *(int *)(lVar6 + 0xbb840 + lVar2) = param_3;
            *(undefined1 *)(lVar6 + 0xbb848 + lVar2) = param_7;
            *(char *)(lVar6 + 0xbb844 + lVar2) = (char)param_4;
            *(char *)(lVar6 + 0xbb845 + lVar2) = (char)param_5;
            *(char *)(lVar6 + 0xbb846 + lVar2) = (char)param_6;
            return 0;
          }
          uVar3 = (int)uVar4 + 1;
          uVar4 = (ulong)uVar3;
          lVar7 = lVar7 + 0xc;
        } while (uVar3 != 0x40);
        nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x933,"kvgpumgrProcessVfInfo",4,
                     "NVRM: No free free slot to track VF PCI info\n");
        return 0x40;
      }
    }
    lVar2 = uVar5 * 0xbbb80 + uVar4 * 0xc;
    *(undefined1 *)(lVar6 + 0xbb847 + lVar2) = 1;
    *(undefined1 *)(lVar6 + 0xbb848 + lVar2) = param_7;
    return 0;
  }
  if ((byte)(param_2 - 1U) < 2) {
    uVar4 = 0;
    lVar2 = uVar5 * 0xbbb80 + lVar6;
    while (((*(int *)(lVar2 + 0xbb840) != param_3 || (*(byte *)(lVar2 + 0xbb844) != param_4)) ||
           ((*(byte *)(lVar2 + 0xbb845) != param_5 || (*(byte *)(lVar2 + 0xbb846) != param_6))))) {
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulong)uVar3;
      lVar2 = lVar2 + 0xc;
      if (uVar3 == 0x40) {
        nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x94e,"kvgpumgrProcessVfInfo",4,
                     "NVRM: Could not find entry for VF PCI info\n");
        return 0x4a;
      }
    }
    if (param_2 == '\x01') {
      *(undefined1 *)(lVar6 + 0xbb847 + uVar5 * 0xbbb80 + uVar4 * 0xc) = 0;
    }
    *(undefined1 *)(lVar6 + 0xbb848 + uVar5 * 0xbbb80 + uVar4 * 0xc) = 0;
    return 0;
  }
  if ((param_2 == '\x03') && (param_8 != 0)) {
    lVar2 = param_8 + 0x300;
    lVar6 = lVar6 + 0xbb840 + uVar5 * 0xbbb80;
    do {
      portMemCopy(param_8,0xc,lVar6,0xc);
      param_8 = param_8 + 0xc;
      lVar6 = lVar6 + 0xc;
    } while (param_8 != lVar2);
    return 0;
  }
  nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x95c,"kvgpumgrProcessVfInfo",4,
               "NVRM: Requested invalid operation on VF info\n");
  return 0x1f;
}


// ===== 004e1260 kvgpumgrEnumerateVgpuPerPgpu =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kvgpumgrEnumerateVgpuPerPgpu(long param_1,undefined8 param_2)

{
  ulong uVar1;
  
  uVar1 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20804004,param_2,0x2888);
  if ((int)uVar1 == 0) {
    return uVar1;
  }
  nvCheckOkFailedNoLog
            (4,uVar1 & 0xffffffff,
             "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_VGPU_MGR_INTERNAL_ENUMERATE_VGPU_PER_PGPU, pParams, sizeof(*pParams))"
             ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x968);
  return uVar1 & 0xffffffff;
}


// ===== 004e12d0 kvgpumgrClearGuestVmInfo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kvgpumgrClearGuestVmInfo(long param_1,long param_2)

{
  int iVar1;
  undefined4 local_1c;
  
  portMemSet(&local_1c,0,4);
  local_1c = *(undefined4 *)(param_2 + 0x18);
  iVar1 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20804005,&local_1c,4);
  if (iVar1 == 0) {
    return 0;
  }
  nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x97e,"kvgpumgrClearGuestVmInfo",4,
               "NVRM: Failed to clear guest vm info on GSP\n");
  return iVar1;
}


// ===== 004e1380 kvgpumgrGetHostVgpuDeviceFromGfid =====

undefined8 kvgpumgrGetHostVgpuDeviceFromGfid(int param_1,int param_2,long *param_3)

{
  long lVar1;
  int *piVar2;
  long lVar3;
  uint uVar4;
  ulong uVar5;
  
  lVar1 = *(long *)(g_pSys + 0x1f8);
  uVar5 = 0;
  piVar2 = (int *)(lVar1 + 0x48);
  while ((param_1 != *piVar2 || ((char)piVar2[0x18e] != '\x01'))) {
    uVar4 = (int)uVar5 + 1;
    uVar5 = (ulong)uVar4;
    piVar2 = piVar2 + 0x2eee0;
    if (uVar4 == 0x20) {
      nvCheckOkFailedNoLog
                (4,0x57,"kvgpumgrGetPgpuIndex(pKernelVgpuMgr, gpuPciId, &pgpuIndex)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0x98d);
      return 0x57;
    }
  }
  if (*(char *)(lVar1 + 0xbb838 + uVar5 * 0xbbb80) != '\0') {
    lVar1 = lVar1 + 600 + uVar5 * 0xbbb80;
    lVar3 = listHead_IMPL(lVar1);
    while( true ) {
      if (lVar3 == 0) {
        return 0x57;
      }
      if (*(int *)(lVar3 + 0x18) == param_2) break;
      lVar3 = listNext_IMPL(lVar1);
    }
    *param_3 = lVar3;
    return 0;
  }
  return 0x56;
}


// ===== 004e1480 kvgpumgrGetVgpuFbUsage =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kvgpumgrGetVgpuFbUsage(long param_1,uint *param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  long local_348;
  uint local_340 [2];
  undefined4 local_338 [2];
  undefined8 local_330 [96];
  
  nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x9a8,"kvgpumgrGetVgpuFbUsage",1,
               "NVRM: %s\n");
  iVar1 = 0;
  if (*(char *)(param_1 + 0x491d) != '\0') {
    portMemSet(local_340,0,0x308);
    iVar1 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20804006,local_340,0x308);
    if (iVar1 == 0) {
      iVar1 = 0x1a;
      if (local_340[0] < 0x31) {
        if (local_340[0] != 0) {
          uVar3 = 0;
          puVar2 = param_2 + 2;
          puVar4 = local_338;
          do {
            iVar1 = kvgpumgrGetHostVgpuDeviceFromGfid
                              (*(undefined4 *)(param_1 + 0x7ac),*puVar4,&local_348);
            if (iVar1 != 0) {
              nvCheckOkFailedNoLog
                        (4,iVar1,
                         "kvgpumgrGetHostVgpuDeviceFromGfid(pGpu->gpuId, internalParams.vgpuFbUsage[i].gfid, &pKernelHostVgpuDevice)"
                         ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x9ba);
              return iVar1;
            }
            uVar3 = uVar3 + 1;
            portMemCopy(puVar2,0x10,local_348 + 0x2cc,0x10);
            *(undefined8 *)(puVar2 + 4) = *(undefined8 *)(puVar4 + 2);
            puVar2 = puVar2 + 6;
            puVar4 = puVar4 + 4;
          } while (uVar3 < local_340[0]);
        }
        *param_2 = local_340[0];
        iVar1 = 0;
      }
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar1,
                 "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_VGPU_MGR_INTERNAL_GET_VGPU_FB_USAGE, &internalParams, sizeof(internalParams))"
                 ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x9b1);
    }
  }
  return iVar1;
}


// ===== 004e1680 kvgpumgrSetVgpuEncoderCapacity =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kvgpumgrSetVgpuEncoderCapacity(long param_1,undefined8 param_2,undefined4 param_3)

{
  long lVar1;
  int iVar2;
  int *piVar3;
  long lVar4;
  ulong uVar5;
  uint uVar6;
  undefined4 local_40;
  undefined4 local_3c;
  
  lVar1 = *(long *)(g_pSys + 0x1f8);
  nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x9d3,"kvgpumgrSetVgpuEncoderCapacity",
               1,"NVRM: %s\n");
  uVar5 = 0;
  piVar3 = (int *)(lVar1 + 0x48);
  while ((*(int *)(param_1 + 0x7ac) != *piVar3 || ((char)piVar3[0x18e] != '\x01'))) {
    uVar6 = (int)uVar5 + 1;
    uVar5 = (ulong)uVar6;
    piVar3 = piVar3 + 0x2eee0;
    if (uVar6 == 0x20) {
      nvCheckOkFailedNoLog
                (4,0x57,"kvgpumgrGetPgpuIndex(pKernelVgpuMgr, pGpu->gpuId, &i)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0x9d5);
      return 0x57;
    }
  }
  lVar1 = lVar1 + 600 + uVar5 * 0xbbb80;
  lVar4 = listHead_IMPL(lVar1);
  while( true ) {
    if (lVar4 == 0) {
      return 0x57;
    }
    iVar2 = portMemCmp(lVar4 + 0x2cc,param_2,0x10);
    if (iVar2 == 0) break;
    lVar4 = listNext_IMPL(lVar1,lVar4);
  }
  if (*(char *)(param_1 + 0x491d) != '\0') {
    local_40 = *(undefined4 *)(lVar4 + 0x18);
    local_3c = param_3;
    uVar5 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20804007,&local_40,8);
    if ((int)uVar5 == 0) {
      return uVar5;
    }
    nvCheckOkFailedNoLog
              (4,uVar5 & 0xffffffff,
               "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_VGPU_MGR_INTERNAL_SET_VGPU_ENCODER_CAPACITY, &params, sizeof(params))"
               ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x9ec);
    return uVar5 & 0xffffffff;
  }
  return 0;
}


// ===== 004e1860 kvgpumgrGetAvailableInstances =====

int kvgpumgrGetAvailableInstances(int *param_1,long param_2,int *param_3,uint param_4,char param_5)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  int *piVar10;
  byte bVar11;
  ulong uVar12;
  int local_44;
  long local_40 [2];
  
  lVar8 = *(long *)(g_pSys + 0x1f8);
  lVar9 = *(long *)(g_pSys + 0x238);
  *param_1 = 0;
  if (*(char *)(param_2 + 0x491d) == '\0') {
    iVar3 = kvgpumgrCheckVgpuTypeCreatable(param_2,lVar8 + 0x48 + (ulong)param_4 * 0xbbb80);
    if (iVar3 == 0) {
      *param_1 = param_3[0xc4] - *(int *)(lVar8 + 0xbb83c + (ulong)param_4 * 0xbbb80);
      return 0;
    }
  }
  else {
    if (*(char *)(lVar9 + 0x48) == '\0') {
      bVar11 = param_5 - *(char *)(param_2 + 0x3a5c);
      if (*(uint *)(param_2 + 0x3a58) < (uint)bVar11) {
        nvAssertFailedNoLog("fnId <= pGpu->sriovState.totalVFs",
                            "src/kernel/virtualization/kernel_vgpu_mgr.c",0xb07);
        return 0x1f;
      }
      if ((*(ulong *)(lVar8 + 0xbbb40 + (ulong)param_4 * 0xbbb80) >> ((ulong)bVar11 & 0x3f) & 1) !=
          0) {
        return 0;
      }
    }
    if ((*(long *)(param_2 + 0x1bc0) == 0) ||
       (cVar2 = kmigmgrIsMIGEnabled_IMPL(param_2), cVar2 == '\0')) {
      if (*(uint *)(lVar8 + 0xbb83c + (ulong)param_4 * 0xbbb80) < (uint)param_3[0xc4]) {
        if (param_3[0xcc] == 0) {
          iVar3 = kvgpumgrCheckVgpuTypeCreatable
                            (param_2,lVar8 + 0x48 + (ulong)param_4 * 0xbbb80,param_3);
          if (iVar3 == 0) {
            *param_1 = 1;
            return 0;
          }
          return 0;
        }
        nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0xb60,
                     "kvgpumgrGetAvailableInstances",1,"NVRM: Query for a MIG vGPU type\n");
      }
    }
    else if ((*(long *)(param_2 + 0x1bc0) != 0) &&
            (cVar2 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_2), cVar2 != '\0')) {
      uVar1 = *(undefined8 *)(param_2 + 0x1bc0);
      uVar7 = kmigmgrGetSwizzIdInUseMask_IMPL(param_2,uVar1);
      if (param_3[0xcc] == 0) {
        nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0xb1c,
                     "kvgpumgrGetAvailableInstances",1,"NVRM: Query for a non MIG vGPU type \n");
        return 0;
      }
      piVar10 = &DAT_00da1848;
      uVar12 = 0;
      while (*param_3 != *piVar10) {
        uVar4 = (int)uVar12 + 1;
        uVar12 = (ulong)uVar4;
        piVar10 = piVar10 + 3;
        if (uVar4 == 0x129) {
          nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x8e8,
                       "kvgpumgrGetPartitionFlag",4,"NVRM: Invalid SMC vGpu TypeId: 0x%x\n");
          nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0xb26,
                       "kvgpumgrGetAvailableInstances",4,"NVRM: Failed to get partition flags.\n");
          return 0x1f;
        }
      }
      if (uVar7 == 0) {
        return 0;
      }
      iVar3 = (&DAT_00da1844)[uVar12 * 3];
      lVar8 = (ulong)param_4 * 0xbbb80 + lVar8;
      uVar12 = 0;
      do {
        if ((uVar7 & 1) != 0) {
          iVar5 = kmigmgrGetGPUInstanceInfo_IMPL(param_2,uVar1,uVar12 & 0xffffffff,local_40);
          if (iVar5 != 0) {
            nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0xb34,
                         "kvgpumgrGetAvailableInstances",4,
                         "NVRM: No valid GPU instance with SwizzId - %d found\n",uVar12 & 0xffffffff
                        );
            return iVar5;
          }
          if (*(int *)(local_40[0] + 0x96c) != iVar3) goto LAB_004e1ae0;
          uVar4 = 0;
          if (*(int *)(lVar8 + 0xbbb58 + uVar12 * 4) == 0) {
LAB_004e1b10:
            if (uVar4 < (uint)param_3[0xe3]) {
              *param_1 = 1;
              return 0;
            }
          }
          else {
            iVar6 = _kvgpumgrGetCreatedVgpuOnGpuInstance(param_2,uVar12 & 0xffffffff,&local_44);
            iVar5 = local_44;
            if (iVar6 != 0) {
LAB_004e1b7b:
              uVar4 = *(uint *)(lVar8 + 0xbbb58 + uVar12 * 4);
              goto LAB_004e1b10;
            }
            lVar9 = *(long *)(g_pSys + 0x1f8) + 0x1777050;
            piVar10 = (int *)listHead_IMPL(lVar9);
            while( true ) {
              if (piVar10 == (int *)0x0) {
                nvAssertOkFailedNoLog
                          (0x57,"kvgpumgrGetVgpuTypeInfo(vgpuTypeId, &existingVgpuTypeInfo)",
                           "src/kernel/virtualization/kernel_vgpu_mgr.c",0xb41);
                return 0x57;
              }
              if (iVar5 == *piVar10) break;
              piVar10 = (int *)listNext_IMPL(lVar9);
            }
            iVar5 = osIsVgpuVfioPresent();
            if ((iVar5 == 0) || (iVar5 = osIsVgpuDeviceVmPresent(), iVar5 == 0)) {
              if (*(long *)(piVar10 + 0xd2) == *(long *)(param_3 + 0xd2)) goto LAB_004e1b7b;
            }
            else if (*piVar10 == *param_3) goto LAB_004e1b7b;
          }
LAB_004e1ae0:
          if (uVar7 >> 1 == 0) {
            return 0;
          }
        }
        uVar7 = uVar7 >> 1;
        uVar12 = uVar12 + 1;
      } while( true );
    }
  }
  return 0;
}


