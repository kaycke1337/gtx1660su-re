// ===== 0012d6a0 libspdm_rsa_get_public_key_from_x509 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012d6ab) */

undefined8 libspdm_rsa_get_public_key_from_x509(void)

{
  return 0;
}


// ===== 0012d6b0 __pfx_libspdm_ec_get_public_key_from_x509 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012d78b) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char __pfx_libspdm_ec_get_public_key_from_x509(long param_1,undefined8 param_2,long *param_3)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  long lVar5;
  int iVar6;
  long in_GS_OFFSET;
  long *aplStack_68 [6];
  long lStack_38;
  undefined8 uStack_30;
  long lStack_18;
  ulong uVar4;
  
  lStack_18 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uVar3 = 0;
  do {
    uVar2 = (int)uVar3 + 0x20;
    uVar4 = (ulong)uVar2;
    *(undefined8 *)((long)aplStack_68 + uVar3) = 0;
    *(undefined8 *)((long)aplStack_68 + uVar3 + 8) = 0;
    *(undefined8 *)((long)aplStack_68 + uVar3 + 0x10) = 0;
    *(undefined8 *)((long)aplStack_68 + uVar3 + 0x18) = 0;
    uVar3 = uVar4;
  } while (uVar2 < 0x40);
  *(undefined8 *)((long)aplStack_68 + uVar4) = 0;
  *(undefined8 *)((long)aplStack_68 + uVar4 + 8) = 0;
  lStack_38 = param_1;
  uStack_30 = param_2;
  if (param_1 != 0) {
    iVar6 = (*_pci_find_host_bridge)(aplStack_68);
    if (iVar6 == 0) {
      iVar6 = (int)aplStack_68[2][1] + -1;
      if ((int)aplStack_68[2][1] == 0x41) {
        lVar5 = libspdm_ec_new_by_nid(0x204);
LAB_0012d7b1:
        *param_3 = lVar5;
        if (lVar5 == 0) goto LAB_0012d75d;
        cVar1 = lkca_ec_set_pub_key(lVar5,*aplStack_68[2] + 1,iVar6);
        if (cVar1 == '\0') {
          libspdm_ec_free(*param_3);
        }
      }
      else {
        if (iVar6 == 0x60) {
          lVar5 = libspdm_ec_new_by_nid(0x205);
          goto LAB_0012d7b1;
        }
LAB_0012d75d:
        cVar1 = '\0';
      }
      (*_cc_mkdec)(aplStack_68);
      goto LAB_0012d777;
    }
  }
  cVar1 = '\0';
LAB_0012d777:
  if (lStack_18 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return cVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0012d6c0 libspdm_ec_get_public_key_from_x509 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012d78b) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char libspdm_ec_get_public_key_from_x509(long param_1,undefined8 param_2,long *param_3)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  long lVar5;
  int iVar6;
  long in_GS_OFFSET;
  long *local_68 [6];
  long local_38;
  undefined8 local_30;
  long local_18;
  ulong uVar4;
  
  local_18 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uVar3 = 0;
  do {
    uVar2 = (int)uVar3 + 0x20;
    uVar4 = (ulong)uVar2;
    *(undefined8 *)((long)local_68 + uVar3) = 0;
    *(undefined8 *)((long)local_68 + uVar3 + 8) = 0;
    *(undefined8 *)((long)local_68 + uVar3 + 0x10) = 0;
    *(undefined8 *)((long)local_68 + uVar3 + 0x18) = 0;
    uVar3 = uVar4;
  } while (uVar2 < 0x40);
  *(undefined8 *)((long)local_68 + uVar4) = 0;
  *(undefined8 *)((long)local_68 + uVar4 + 8) = 0;
  local_38 = param_1;
  local_30 = param_2;
  if (param_1 != 0) {
    iVar6 = (*_pci_find_host_bridge)(local_68);
    if (iVar6 == 0) {
      iVar6 = (int)local_68[2][1] + -1;
      if ((int)local_68[2][1] == 0x41) {
        lVar5 = libspdm_ec_new_by_nid(0x204);
LAB_0012d7b1:
        *param_3 = lVar5;
        if (lVar5 == 0) goto LAB_0012d75d;
        cVar1 = lkca_ec_set_pub_key(lVar5,*local_68[2] + 1,iVar6);
        if (cVar1 == '\0') {
          libspdm_ec_free(*param_3);
        }
      }
      else {
        if (iVar6 == 0x60) {
          lVar5 = libspdm_ec_new_by_nid(0x205);
          goto LAB_0012d7b1;
        }
LAB_0012d75d:
        cVar1 = '\0';
      }
      (*_cc_mkdec)(local_68);
      goto LAB_0012d777;
    }
  }
  cVar1 = '\0';
LAB_0012d777:
  if (local_18 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return cVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0012d800 __pfx_libspdm_x509_verify_cert =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012d823) */

bool __pfx_libspdm_x509_verify_cert(void)

{
  int iVar1;
  
  iVar1 = lkca_x509_verify_cert();
  return iVar1 == 0;
}


// ===== 0012d810 libspdm_x509_verify_cert =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012d823) */

bool libspdm_x509_verify_cert(void)

{
  int iVar1;
  
  iVar1 = lkca_x509_verify_cert();
  return iVar1 == 0;
}


// ===== 0012d830 __pfx_libspdm_x509_verify_cert_chain =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012d8e5) */
/* WARNING: Removing unreachable block (ram,0x0012d923) */

undefined8
__pfx_libspdm_x509_verify_cert_chain(char *param_1,char *param_2,char *param_3,char *param_4)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  undefined8 uVar7;
  
  if ((char *)0x3ffffffe < param_4 + -2) {
    return 0;
  }
  uVar7 = 0;
  pcVar4 = param_4;
  pcVar2 = param_3;
  while( true ) {
    pcVar5 = pcVar2;
    if (*pcVar5 != '0') {
      return uVar7;
    }
    cVar1 = pcVar5[1];
    if (cVar1 < '\0') {
      if (cVar1 == -0x7f) {
        if (pcVar4 == (char *)0x2) {
          return uVar7;
        }
        pcVar6 = (char *)((ulong)(byte)pcVar5[2] + 3);
      }
      else {
        if (cVar1 != -0x7e) {
          return uVar7;
        }
        if (pcVar4 < (char *)0x4) {
          return uVar7;
        }
        pcVar6 = (char *)(ulong)((byte)pcVar5[3] + 4 + (uint)(byte)pcVar5[2] * 0x100);
      }
    }
    else {
      pcVar6 = (char *)(ulong)(byte)(cVar1 + 2);
    }
    if (pcVar4 < pcVar6) {
      return uVar7;
    }
    iVar3 = lkca_x509_verify_cert(pcVar5,pcVar6,param_1,param_2);
    if (iVar3 != 0) break;
    uVar7 = 1;
    pcVar4 = param_3 + ((long)param_4 - (long)(pcVar5 + (long)pcVar6));
    pcVar2 = pcVar5 + (long)pcVar6;
    param_1 = pcVar5;
    param_2 = pcVar6;
    if ((char *)0x3ffffffe < pcVar4 + -2) {
      return 1;
    }
  }
  return 0;
}


// ===== 0012d840 libspdm_x509_verify_cert_chain =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012d8e5) */
/* WARNING: Removing unreachable block (ram,0x0012d923) */

undefined8 libspdm_x509_verify_cert_chain(char *param_1,char *param_2,char *param_3,char *param_4)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  undefined8 uVar7;
  
  if ((char *)0x3ffffffe < param_4 + -2) {
    return 0;
  }
  uVar7 = 0;
  pcVar4 = param_4;
  pcVar2 = param_3;
  while( true ) {
    pcVar5 = pcVar2;
    if (*pcVar5 != '0') {
      return uVar7;
    }
    cVar1 = pcVar5[1];
    if (cVar1 < '\0') {
      if (cVar1 == -0x7f) {
        if (pcVar4 == (char *)0x2) {
          return uVar7;
        }
        pcVar6 = (char *)((ulong)(byte)pcVar5[2] + 3);
      }
      else {
        if (cVar1 != -0x7e) {
          return uVar7;
        }
        if (pcVar4 < (char *)0x4) {
          return uVar7;
        }
        pcVar6 = (char *)(ulong)((byte)pcVar5[3] + 4 + (uint)(byte)pcVar5[2] * 0x100);
      }
    }
    else {
      pcVar6 = (char *)(ulong)(byte)(cVar1 + 2);
    }
    if (pcVar4 < pcVar6) {
      return uVar7;
    }
    iVar3 = lkca_x509_verify_cert(pcVar5,pcVar6,param_1,param_2);
    if (iVar3 != 0) break;
    uVar7 = 1;
    pcVar4 = param_3 + ((long)param_4 - (long)(pcVar5 + (long)pcVar6));
    pcVar2 = pcVar5 + (long)pcVar6;
    param_1 = pcVar5;
    param_2 = pcVar6;
    if ((char *)0x3ffffffe < pcVar4 + -2) {
      return 1;
    }
  }
  return 0;
}


// ===== 0012d940 __pfx_libspdm_x509_get_cert_from_cert_chain =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012da24) */
/* WARNING: Removing unreachable block (ram,0x0012da60) */
/* WARNING: Removing unreachable block (ram,0x0012da03) */
/* WARNING: Removing unreachable block (ram,0x0012da4f) */
/* WARNING: Removing unreachable block (ram,0x0012da1b) */

byte __pfx_libspdm_x509_get_cert_from_cert_chain
               (char *param_1,char *param_2,int param_3,long *param_4,undefined8 *param_5)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  if (param_1 == (char *)0x0 || param_4 == (long *)0x0) {
    return 0;
  }
  if ((-2 < param_3 && param_5 != (undefined8 *)0x0) && (param_2 + -2 < (char *)0x3fffffff)) {
    pcVar3 = (char *)0x0;
    iVar4 = -1;
    pcVar6 = param_2;
    pcVar7 = param_1;
    if (*param_1 == '0') {
      do {
        cVar1 = pcVar7[1];
        if (cVar1 < '\0') {
          if (cVar1 == -0x7f) {
            if (pcVar6 == (char *)0x2) {
LAB_0012d9e9:
              bVar2 = param_3 == -1 & (byte)~(byte)((uint)iVar4 >> 0x18) >> 7;
              if (bVar2 != 0) {
                *param_4 = (long)pcVar7 - (long)pcVar3;
                *param_5 = pcVar3;
              }
              return bVar2;
            }
            pcVar5 = (char *)((ulong)(byte)pcVar7[2] + 3);
          }
          else {
            if ((cVar1 != -0x7e) || (pcVar6 < (char *)0x4)) goto LAB_0012d9e9;
            pcVar5 = (char *)(ulong)((uint)(byte)pcVar7[2] * 0x100 + 4 + (uint)(byte)pcVar7[3]);
          }
        }
        else {
          pcVar5 = (char *)(ulong)(byte)(cVar1 + 2);
        }
        if (pcVar6 < pcVar5) goto LAB_0012d9e9;
        iVar4 = iVar4 + 1;
        if (param_3 == iVar4) {
          *param_4 = (long)pcVar7;
          *param_5 = pcVar5;
          return 1;
        }
        pcVar7 = pcVar7 + (long)pcVar5;
        pcVar3 = pcVar5;
        if (((char *)0x3ffffffe < param_1 + ((long)param_2 - (long)pcVar7) + -2) ||
           (pcVar6 = param_1 + ((long)param_2 - (long)pcVar7), *pcVar7 != '0')) goto LAB_0012d9e9;
      } while( true );
    }
  }
  return 0;
}


// ===== 0012d950 libspdm_x509_get_cert_from_cert_chain =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012da24) */
/* WARNING: Removing unreachable block (ram,0x0012da60) */
/* WARNING: Removing unreachable block (ram,0x0012da03) */
/* WARNING: Removing unreachable block (ram,0x0012da4f) */
/* WARNING: Removing unreachable block (ram,0x0012da1b) */

byte libspdm_x509_get_cert_from_cert_chain
               (char *param_1,char *param_2,int param_3,long *param_4,undefined8 *param_5)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  if (param_1 == (char *)0x0 || param_4 == (long *)0x0) {
    return 0;
  }
  if ((-2 < param_3 && param_5 != (undefined8 *)0x0) && (param_2 + -2 < (char *)0x3fffffff)) {
    pcVar3 = (char *)0x0;
    iVar4 = -1;
    pcVar6 = param_2;
    pcVar7 = param_1;
    if (*param_1 == '0') {
      do {
        cVar1 = pcVar7[1];
        if (cVar1 < '\0') {
          if (cVar1 == -0x7f) {
            if (pcVar6 == (char *)0x2) {
LAB_0012d9e9:
              bVar2 = param_3 == -1 & (byte)~(byte)((uint)iVar4 >> 0x18) >> 7;
              if (bVar2 != 0) {
                *param_4 = (long)pcVar7 - (long)pcVar3;
                *param_5 = pcVar3;
              }
              return bVar2;
            }
            pcVar5 = (char *)((ulong)(byte)pcVar7[2] + 3);
          }
          else {
            if ((cVar1 != -0x7e) || (pcVar6 < (char *)0x4)) goto LAB_0012d9e9;
            pcVar5 = (char *)(ulong)((uint)(byte)pcVar7[2] * 0x100 + 4 + (uint)(byte)pcVar7[3]);
          }
        }
        else {
          pcVar5 = (char *)(ulong)(byte)(cVar1 + 2);
        }
        if (pcVar6 < pcVar5) goto LAB_0012d9e9;
        iVar4 = iVar4 + 1;
        if (param_3 == iVar4) {
          *param_4 = (long)pcVar7;
          *param_5 = pcVar5;
          return 1;
        }
        pcVar7 = pcVar7 + (long)pcVar5;
        pcVar3 = pcVar5;
        if (((char *)0x3ffffffe < param_1 + ((long)param_2 - (long)pcVar7) + -2) ||
           (pcVar6 = param_1 + ((long)param_2 - (long)pcVar7), *pcVar7 != '0')) goto LAB_0012d9e9;
      } while( true );
    }
  }
  return 0;
}


// ===== 0012da80 __pfx_libspdm_x509_get_version =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012da9b) */

undefined8 __pfx_libspdm_x509_get_version(void)

{
  return 0;
}


// ===== 0012da90 libspdm_x509_get_version =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012da9b) */

undefined8 libspdm_x509_get_version(void)

{
  return 0;
}


// ===== 0012daa0 __pfx_libspdm_x509_get_serial_number =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012dabb) */

undefined8 __pfx_libspdm_x509_get_serial_number(void)

{
  return 0;
}


// ===== 0012dab0 libspdm_x509_get_serial_number =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012dabb) */

undefined8 libspdm_x509_get_serial_number(void)

{
  return 0;
}


// ===== 0012dac0 __pfx_libspdm_x509_get_issuer_name =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012dadb) */

undefined8 __pfx_libspdm_x509_get_issuer_name(void)

{
  return 0;
}


// ===== 0012dad0 libspdm_x509_get_issuer_name =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012dadb) */

undefined8 libspdm_x509_get_issuer_name(void)

{
  return 0;
}


// ===== 0012dae0 __pfx_libspdm_x509_get_signature_algorithm =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012dafb) */

undefined8 __pfx_libspdm_x509_get_signature_algorithm(void)

{
  return 0;
}


// ===== 0012daf0 libspdm_x509_get_signature_algorithm =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012dafb) */

undefined8 libspdm_x509_get_signature_algorithm(void)

{
  return 0;
}


// ===== 0012db00 __pfx_libspdm_x509_get_extension_data =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012db1b) */

undefined8 __pfx_libspdm_x509_get_extension_data(void)

{
  return 0;
}


// ===== 0012db10 libspdm_x509_get_extension_data =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012db1b) */

undefined8 libspdm_x509_get_extension_data(void)

{
  return 0;
}


// ===== 0012db20 __pfx_libspdm_x509_get_validity =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012db3b) */

undefined8 __pfx_libspdm_x509_get_validity(void)

{
  return 0;
}


// ===== 0012db30 libspdm_x509_get_validity =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012db3b) */

undefined8 libspdm_x509_get_validity(void)

{
  return 0;
}


// ===== 0012db40 __pfx_libspdm_x509_get_key_usage =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012db5b) */

undefined8 __pfx_libspdm_x509_get_key_usage(void)

{
  return 0;
}


// ===== 0012db50 libspdm_x509_get_key_usage =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012db5b) */

undefined8 libspdm_x509_get_key_usage(void)

{
  return 0;
}


// ===== 0012db60 __pfx_libspdm_x509_get_extended_key_usage =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012db7b) */

undefined8 __pfx_libspdm_x509_get_extended_key_usage(void)

{
  return 0;
}


// ===== 0012db70 libspdm_x509_get_extended_key_usage =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012db7b) */

undefined8 libspdm_x509_get_extended_key_usage(void)

{
  return 0;
}


// ===== 0012db80 __pfx_libspdm_x509_get_extended_basic_constraints =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012db9b) */

undefined8 __pfx_libspdm_x509_get_extended_basic_constraints(void)

{
  return 0;
}


// ===== 0012db90 libspdm_x509_get_extended_basic_constraints =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012db9b) */

undefined8 libspdm_x509_get_extended_basic_constraints(void)

{
  return 0;
}


// ===== 0012dba0 __pfx_libspdm_x509_set_date_time =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012dbbb) */

undefined8 __pfx_libspdm_x509_set_date_time(void)

{
  return 0;
}


// ===== 0012dbb0 libspdm_x509_set_date_time =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012dbbb) */

undefined8 libspdm_x509_set_date_time(void)

{
  return 0;
}


// ===== 0012dbc0 __pfx_libspdm_x509_compare_date_time =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012dbde) */

undefined8 __pfx_libspdm_x509_compare_date_time(void)

{
  return 0xfffffffd;
}


// ===== 0012dbd0 libspdm_x509_compare_date_time =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012dbde) */

undefined8 libspdm_x509_compare_date_time(void)

{
  return 0xfffffffd;
}


// ===== 0012dbf0 __pfx_libspdm_rsa_pss_sign =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_libspdm_rsa_pss_sign(void)

{
  lkca_rsa_pss_sign();
  return;
}


// ===== 0012dc00 libspdm_rsa_pss_sign =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void libspdm_rsa_pss_sign(void)

{
  lkca_rsa_pss_sign();
  return;
}


// ===== 0012dc10 __pfx_libspdm_rsa_pss_verify =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012dc2b) */

undefined8 __pfx_libspdm_rsa_pss_verify(void)

{
  return 0;
}


// ===== 0012dc20 libspdm_rsa_pss_verify =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012dc2b) */

undefined8 libspdm_rsa_pss_verify(void)

{
  return 0;
}


// ===== 0012dc30 __pfx_nv_procfs_release_permissions =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_release_permissions(void)

{
  single_release();
  return;
}


// ===== 0012dc40 nv_procfs_release_permissions =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_release_permissions(void)

{
  single_release();
  return;
}


// ===== 0012dc50 __pfx_nv_procfs_open_permissions =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_open_permissions(long param_1,undefined8 param_2)

{
  single_open(param_2,nv_procfs_read_permissions,*(undefined8 *)(param_1 + 0x230));
  return;
}


// ===== 0012dc60 nv_procfs_open_permissions =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_open_permissions(long param_1,undefined8 param_2)

{
  single_open(param_2,nv_procfs_read_permissions,*(undefined8 *)(param_1 + 0x230));
  return;
}


// ===== 0012dc90 __pfx_nv_procfs_read_permissions =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012dcc3) */

undefined8 __pfx_nv_procfs_read_permissions(undefined8 param_1)

{
  undefined8 in_R8;
  undefined8 in_R9;
  
  seq_printf(param_1,"%s: %u\n","DeviceFileMode",0x1b6,in_R8,in_R9,0x12dca9);
  return 0;
}


// ===== 0012dca0 nv_procfs_read_permissions =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012dcc3) */

undefined8 nv_procfs_read_permissions(undefined8 param_1)

{
  undefined8 in_R8;
  undefined8 in_R9;
  
  seq_printf(param_1,"%s: %u\n","DeviceFileMode",0x1b6,in_R8,in_R9,0x12dca9);
  return 0;
}


// ===== 0012dcd0 __pfx_nvlink_procfs_exit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012dd1d) */

void __pfx_nvlink_procfs_exit(void)

{
  if (nvlink_permissions != 0) {
    proc_remove();
    nvlink_permissions = 0;
  }
  if (nvlink_procfs_dir != 0) {
    proc_remove();
    nvlink_procfs_dir = 0;
  }
  return;
}


// ===== 0012dce0 nvlink_procfs_exit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012dd1d) */

void nvlink_procfs_exit(void)

{
  if (nvlink_permissions != 0) {
    proc_remove();
    nvlink_permissions = 0;
  }
  if (nvlink_procfs_dir != 0) {
    proc_remove();
    nvlink_procfs_dir = 0;
  }
  return;
}


// ===== 0012dd30 __pfx_nvlink_fops_unlocked_ioctl =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012deda) */

ulong __pfx_nvlink_fops_unlocked_ioctl(long param_1,ulong param_2,undefined8 param_3)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  long in_GS_OFFSET;
  undefined8 uStack_60;
  undefined8 uStack_58;
  long lStack_50;
  undefined8 uStack_48;
  long lStack_40;
  
  uVar2 = (uint)(param_2 >> 0x10);
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_60 = 0;
  uStack_58 = 0;
  lStack_50 = 0;
  uStack_48 = 0;
  uVar3 = uVar2 & 0x3fff;
  if ((param_2 & 0x3fff0000) == 0) {
    uStack_60 = *(undefined8 *)(param_1 + 0x18);
    uStack_48 = 0;
    uStack_58 = param_2 & 0xff;
    iVar4 = nvlink_lib_ioctl_ctrl(&uStack_60);
    uVar7 = -(ulong)(iVar4 != 0) & 0xffffffffffffffea;
    goto LAB_0012deb5;
  }
  lVar5 = __kmalloc_noprof(uVar3,0xdc0);
  if (lVar5 == 0) {
    uVar7 = 0xfffffffffffffff4;
    goto LAB_0012deb5;
  }
  if ((param_2 & 0x40000000) == 0) {
LAB_0012ddff:
    uStack_60 = *(undefined8 *)(param_1 + 0x18);
    uStack_48 = CONCAT44(uStack_48._4_4_,uVar2) & 0xffffffff00003fff;
    uVar7 = 0xffffffffffffffea;
    uStack_58 = CONCAT44(uStack_58._4_4_,(int)param_2) & 0xffffffff000000ff;
    lStack_50 = lVar5;
    iVar4 = nvlink_lib_ioctl_ctrl(&uStack_60);
    lVar6 = lStack_50;
    if ((iVar4 == 0) && (uVar7 = 0, (int)param_2 < 0)) {
      uVar7 = uStack_48 & 0xffffffff;
      if (0x7fffffff < uVar7) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)invalidInstructionException();
        (*pcVar1)();
      }
      __check_object_size(lStack_50,uVar7,1);
      lVar6 = _copy_to_user(param_3,lVar6,uVar7);
      uVar7 = -(ulong)(lVar6 != 0) & 0xfffffffffffffff2;
    }
  }
  else {
    __check_object_size(lVar5,uVar3,0);
    lVar6 = _copy_from_user(lVar5,param_3,uVar3);
    if (lVar6 == 0) goto LAB_0012ddff;
    uVar7 = 0xfffffffffffffff2;
  }
  kfree(lVar5);
LAB_0012deb5:
  if (lStack_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar7;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0012dd40 nvlink_fops_unlocked_ioctl =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012deda) */

ulong nvlink_fops_unlocked_ioctl(long param_1,ulong param_2,undefined8 param_3)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  long in_GS_OFFSET;
  undefined8 local_60;
  undefined8 local_58;
  long local_50;
  undefined8 local_48;
  long local_40;
  
  uVar2 = (uint)(param_2 >> 0x10);
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  uVar3 = uVar2 & 0x3fff;
  if ((param_2 & 0x3fff0000) == 0) {
    local_60 = *(undefined8 *)(param_1 + 0x18);
    local_48 = 0;
    local_58 = param_2 & 0xff;
    iVar4 = nvlink_lib_ioctl_ctrl(&local_60);
    uVar7 = -(ulong)(iVar4 != 0) & 0xffffffffffffffea;
    goto LAB_0012deb5;
  }
  lVar5 = __kmalloc_noprof(uVar3,0xdc0);
  if (lVar5 == 0) {
    uVar7 = 0xfffffffffffffff4;
    goto LAB_0012deb5;
  }
  if ((param_2 & 0x40000000) == 0) {
LAB_0012ddff:
    local_60 = *(undefined8 *)(param_1 + 0x18);
    local_48 = CONCAT44(local_48._4_4_,uVar2) & 0xffffffff00003fff;
    uVar7 = 0xffffffffffffffea;
    local_58 = CONCAT44(local_58._4_4_,(int)param_2) & 0xffffffff000000ff;
    local_50 = lVar5;
    iVar4 = nvlink_lib_ioctl_ctrl(&local_60);
    lVar6 = local_50;
    if ((iVar4 == 0) && (uVar7 = 0, (int)param_2 < 0)) {
      uVar7 = local_48 & 0xffffffff;
      if (0x7fffffff < uVar7) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)invalidInstructionException();
        (*pcVar1)();
      }
      __check_object_size(local_50,uVar7,1);
      lVar6 = _copy_to_user(param_3,lVar6,uVar7);
      uVar7 = -(ulong)(lVar6 != 0) & 0xfffffffffffffff2;
    }
  }
  else {
    __check_object_size(lVar5,uVar3,0);
    lVar6 = _copy_from_user(lVar5,param_3,uVar3);
    if (lVar6 == 0) goto LAB_0012ddff;
    uVar7 = 0xfffffffffffffff2;
  }
  kfree(lVar5);
LAB_0012deb5:
  if (local_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar7;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0012df20 __pfx_nv_procfs_read_lock_permissions =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012df90) */
/* WARNING: Removing unreachable block (ram,0x0012dfc0) */

undefined8
__pfx_nv_procfs_read_lock_permissions
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong *puVar1;
  int iVar2;
  undefined8 uVar3;
  long in_GS_OFFSET;
  
  puVar1 = *(ulong **)(&const_current_task + in_GS_OFFSET);
  while( true ) {
    iVar2 = down_read_trylock(nv_system_pm_lock);
    if (iVar2 != 0) {
      uVar3 = seq_read(param_1,param_2,param_3,param_4);
      up_read(nv_system_pm_lock);
      return uVar3;
    }
    if (((*puVar1 & 4) != 0) || ((*puVar1 & 2) != 0)) break;
    __SCT__cond_resched();
  }
  return 0xfffffffffffffffc;
}


// ===== 0012df30 nv_procfs_read_lock_permissions =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012df90) */
/* WARNING: Removing unreachable block (ram,0x0012dfc0) */

undefined8
nv_procfs_read_lock_permissions
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong *puVar1;
  int iVar2;
  undefined8 uVar3;
  long in_GS_OFFSET;
  
  puVar1 = *(ulong **)(&const_current_task + in_GS_OFFSET);
  while( true ) {
    iVar2 = down_read_trylock(nv_system_pm_lock);
    if (iVar2 != 0) {
      uVar3 = seq_read(param_1,param_2,param_3,param_4);
      up_read(nv_system_pm_lock);
      return uVar3;
    }
    if (((*puVar1 & 4) != 0) || ((*puVar1 & 2) != 0)) break;
    __SCT__cond_resched();
  }
  return 0xfffffffffffffffc;
}


// ===== 0012dfd0 __pfx_nvlink_print =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e0b1) */

void __pfx_nvlink_print(void)

{
  int in_ECX;
  undefined *puVar1;
  char *in_R8;
  undefined8 in_R9;
  long in_GS_OFFSET;
  undefined8 uStack_270;
  char acStack_258 [511];
  undefined1 uStack_59;
  long lStack_58;
  undefined8 uStack_28;
  
  lStack_58 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_270 = 0;
  uStack_28 = in_R9;
  memset(acStack_258,0,0x200);
  puVar1 = &DAT_00db05ec;
  if (in_ECX - 1U < 4) {
    puVar1 = *(undefined **)(CSWTCH_107 + (ulong)(in_ECX - 1U) * 8);
  }
  uStack_270 = CONCAT44(uStack_270._4_4_,0x28);
  vsnprintf(acStack_258,0x200,in_R8,&uStack_270);
  uStack_59 = 0;
  _printk("%snvidia-nvlink: %s",puVar1,acStack_258);
  if (lStack_58 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0012dfe0 nvlink_print =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e0b1) */

void nvlink_print(void)

{
  int in_ECX;
  undefined *puVar1;
  char *in_R8;
  undefined8 in_R9;
  long in_GS_OFFSET;
  undefined8 local_270;
  char local_258 [511];
  undefined1 local_59;
  long local_58;
  undefined8 local_28;
  
  local_58 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_270 = 0;
  local_28 = in_R9;
  memset(local_258,0,0x200);
  puVar1 = &DAT_00db05ec;
  if (in_ECX - 1U < 4) {
    puVar1 = *(undefined **)(CSWTCH_107 + (ulong)(in_ECX - 1U) * 8);
  }
  local_270 = CONCAT44(local_270._4_4_,0x28);
  vsnprintf(local_258,0x200,in_R8,&local_270);
  local_59 = 0;
  _printk("%snvidia-nvlink: %s",puVar1,local_258);
  if (local_58 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0012e0c0 __pfx_nvlink_core_exit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e0e2) */

void __pfx_nvlink_core_exit(void)

{
  if (nvlink_drvctx[0x18] == '\0') {
    return;
  }
  nvlink_cap_exit();
  if (nvlink_permissions != 0) {
    proc_remove();
    nvlink_permissions = 0;
  }
  if (nvlink_procfs_dir != 0) {
    proc_remove();
    nvlink_procfs_dir = 0;
  }
  cdev_del(0x547720);
  unregister_chrdev_region(nvlink_drvctx._136_4_,1);
  nvlink_lib_unload();
  nvlink_print("nvidia/nvlink_linux.c",0x199,"nvlink_core_exit",0,
               "Unregistered Nvlink Core, major device number %d\n",nvlink_drvctx._144_4_);
  return;
}


// ===== 0012e0d0 nvlink_core_exit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e0e2) */

void nvlink_core_exit(void)

{
  if (nvlink_drvctx[0x18] == '\0') {
    return;
  }
  nvlink_cap_exit();
  if (nvlink_permissions != 0) {
    proc_remove();
    nvlink_permissions = 0;
  }
  if (nvlink_procfs_dir != 0) {
    proc_remove();
    nvlink_procfs_dir = 0;
  }
  cdev_del(0x547720);
  unregister_chrdev_region(nvlink_drvctx._136_4_,1);
  nvlink_lib_unload();
  nvlink_print("nvidia/nvlink_linux.c",0x199,"nvlink_core_exit",0,
               "Unregistered Nvlink Core, major device number %d\n",nvlink_drvctx._144_4_);
  return;
}


// ===== 0012e170 __pfx_nvlink_fops_open =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e204) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __pfx_nvlink_fops_open(undefined8 param_1,long param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  nvlink_print("nvidia/nvlink_linux.c",0xb0,"nvlink_fops_open",0,"nvlink driver open\n");
  mutex_lock(nvlink_drvctx);
  if (nvlink_drvctx._140_4_ == 0) {
    puVar1 = (undefined4 *)__kmalloc_cache_noprof(_dma_set_mask,0xcc0,4);
    if (puVar1 == (undefined4 *)0x0) {
      uVar2 = 0xfffffff4;
    }
    else {
      *(undefined4 **)(param_2 + 0x18) = puVar1;
      *puVar1 = 0xffffffff;
      nvlink_drvctx._140_4_ = 1;
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0xfffffff0;
  }
  mutex_unlock(nvlink_drvctx);
  return uVar2;
}


// ===== 0012e180 nvlink_fops_open =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e204) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 nvlink_fops_open(undefined8 param_1,long param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  nvlink_print("nvidia/nvlink_linux.c",0xb0,"nvlink_fops_open",0,"nvlink driver open\n");
  mutex_lock(nvlink_drvctx);
  if (nvlink_drvctx._140_4_ == 0) {
    puVar1 = (undefined4 *)__kmalloc_cache_noprof(_dma_set_mask,0xcc0,4);
    if (puVar1 == (undefined4 *)0x0) {
      uVar2 = 0xfffffff4;
    }
    else {
      *(undefined4 **)(param_2 + 0x18) = puVar1;
      *puVar1 = 0xffffffff;
      nvlink_drvctx._140_4_ = 1;
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0xfffffff0;
  }
  mutex_unlock(nvlink_drvctx);
  return uVar2;
}


// ===== 0012e220 __pfx_nvlink_fops_release =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e2b2) */

undefined8 __pfx_nvlink_fops_release(undefined8 param_1,long param_2)

{
  int *piVar1;
  undefined8 uVar2;
  
  piVar1 = *(int **)(param_2 + 0x18);
  nvlink_print("nvidia/nvlink_linux.c",0xd1,"nvlink_fops_release",0,"nvlink driver close\n");
  if (piVar1 == (int *)0x0) {
    uVar2 = 0xfffffff4;
  }
  else {
    mutex_lock(nvlink_drvctx);
    if (0 < *piVar1) {
      nvlink_cap_release();
      *piVar1 = -1;
    }
    kfree(*(undefined8 *)(param_2 + 0x18));
    *(undefined8 *)(param_2 + 0x18) = 0;
    nvlink_drvctx._140_4_ = 0;
    mutex_unlock(nvlink_drvctx);
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 0012e230 nvlink_fops_release =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e2b2) */

undefined8 nvlink_fops_release(undefined8 param_1,long param_2)

{
  int *piVar1;
  undefined8 uVar2;
  
  piVar1 = *(int **)(param_2 + 0x18);
  nvlink_print("nvidia/nvlink_linux.c",0xd1,"nvlink_fops_release",0,"nvlink driver close\n");
  if (piVar1 == (int *)0x0) {
    uVar2 = 0xfffffff4;
  }
  else {
    mutex_lock(nvlink_drvctx);
    if (0 < *piVar1) {
      nvlink_cap_release();
      *piVar1 = -1;
    }
    kfree(*(undefined8 *)(param_2 + 0x18));
    *(undefined8 *)(param_2 + 0x18) = 0;
    nvlink_drvctx._140_4_ = 0;
    mutex_unlock(nvlink_drvctx);
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 0012e2c0 __pfx_nvlink_malloc =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvlink_malloc(undefined8 param_1)

{
  __kmalloc_noprof(param_1,0xcc0);
  return;
}


// ===== 0012e2d0 nvlink_malloc =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvlink_malloc(undefined8 param_1)

{
  __kmalloc_noprof(param_1,0xcc0);
  return;
}


// ===== 0012e2f0 __pfx_nvlink_free =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvlink_free(void)

{
  kfree();
  return;
}


// ===== 0012e300 nvlink_free =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvlink_free(void)

{
  kfree();
  return;
}


// ===== 0012e310 __pfx_nvlink_strcpy =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvlink_strcpy(char *param_1,char *param_2)

{
  strcpy(param_1,param_2);
  return;
}


// ===== 0012e320 nvlink_strcpy =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvlink_strcpy(char *param_1,char *param_2)

{
  strcpy(param_1,param_2);
  return;
}


// ===== 0012e330 __pfx_nvlink_strcmp =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvlink_strcmp(char *param_1,char *param_2)

{
  strcmp(param_1,param_2);
  return;
}


// ===== 0012e340 nvlink_strcmp =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvlink_strcmp(char *param_1,char *param_2)

{
  strcmp(param_1,param_2);
  return;
}


// ===== 0012e350 __pfx_nvlink_strlen =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvlink_strlen(char *param_1)

{
  strlen(param_1);
  return;
}


// ===== 0012e360 nvlink_strlen =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvlink_strlen(char *param_1)

{
  strlen(param_1);
  return;
}


// ===== 0012e370 __pfx_nvlink_snprintf =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e3e7) */

void __pfx_nvlink_snprintf(char *param_1,size_t param_2,char *param_3)

{
  long lVar1;
  long in_GS_OFFSET;
  undefined8 uStack_60;
  
  lVar1 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_60 = 0x18;
  vsnprintf(param_1,param_2,param_3,&uStack_60);
  if (lVar1 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0012e380 nvlink_snprintf =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e3e7) */

void nvlink_snprintf(char *param_1,size_t param_2,char *param_3)

{
  long lVar1;
  long in_GS_OFFSET;
  undefined8 local_60;
  
  lVar1 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_60 = 0x18;
  vsnprintf(param_1,param_2,param_3,&local_60);
  if (lVar1 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0012e400 __pfx_nvlink_memRd32 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e41b) */

undefined4 __pfx_nvlink_memRd32(undefined4 *param_1)

{
  return *param_1;
}


// ===== 0012e410 nvlink_memRd32 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e41b) */

undefined4 nvlink_memRd32(undefined4 *param_1)

{
  return *param_1;
}


// ===== 0012e420 __pfx_nvlink_memWr32 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e43b) */

void __pfx_nvlink_memWr32(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return;
}


// ===== 0012e430 nvlink_memWr32 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e43b) */

void nvlink_memWr32(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return;
}


// ===== 0012e440 __pfx_nvlink_memRd64 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e45c) */

undefined8 __pfx_nvlink_memRd64(undefined8 *param_1)

{
  return *param_1;
}


// ===== 0012e450 nvlink_memRd64 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e45c) */

undefined8 nvlink_memRd64(undefined8 *param_1)

{
  return *param_1;
}


// ===== 0012e470 __pfx_nvlink_memWr64 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e48c) */

void __pfx_nvlink_memWr64(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return;
}


// ===== 0012e480 nvlink_memWr64 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e48c) */

void nvlink_memWr64(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return;
}


// ===== 0012e4a0 __pfx_nvlink_memset =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvlink_memset(void *param_1,int param_2,size_t param_3)

{
  memset(param_1,param_2,param_3);
  return;
}


// ===== 0012e4b0 nvlink_memset =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvlink_memset(void *param_1,int param_2,size_t param_3)

{
  memset(param_1,param_2,param_3);
  return;
}


// ===== 0012e4c0 __pfx_nvlink_memcpy =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvlink_memcpy(void *param_1,void *param_2,size_t param_3)

{
  memcpy(param_1,param_2,param_3);
  return;
}


// ===== 0012e4d0 nvlink_memcpy =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvlink_memcpy(void *param_1,void *param_2,size_t param_3)

{
  memcpy(param_1,param_2,param_3);
  return;
}


// ===== 0012e4e0 __pfx_nvlink_memcmp =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvlink_memcmp(void *param_1,void *param_2,size_t param_3)

{
  memcmp(param_1,param_2,param_3);
  return;
}


// ===== 0012e4f0 nvlink_memcmp =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvlink_memcmp(void *param_1,void *param_2,size_t param_3)

{
  memcmp(param_1,param_2,param_3);
  return;
}


// ===== 0012e500 __pfx_nvlink_sleep =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e595) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __pfx_nvlink_sleep(ulong param_1)

{
  bool bVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  long in_GS_OFFSET;
  long lStack_48;
  long lStack_40;
  long lStack_38;
  long lStack_30;
  long lStack_28;
  
  param_1 = param_1 & 0xffffffff;
  lStack_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lStack_48 = 0;
  lStack_40 = 0;
  ktime_get_raw_ts64(&lStack_48);
  uVar4 = (*_mpi_powm)();
  if (((uVar4 & 0x200) == 0) || ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) != 0)) {
    for (; param_1 != 0; param_1 = param_1 - 1) {
      __const_udelay(0x418958);
    }
  }
  else {
    lStack_38 = 0;
    lStack_30 = 0;
    set_normalized_timespec64(&lStack_38,lStack_48,param_1 * 1000000 + lStack_40);
    lVar3 = lStack_30;
    lVar2 = lStack_38;
    if (param_1 != 0) {
      LOCK();
      *(undefined4 *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0x18) = 1;
      UNLOCK();
      while( true ) {
        while( true ) {
          schedule_timeout(param_1);
          ktime_get_raw_ts64(&lStack_48);
          bVar1 = lStack_48 < lVar2;
          if (lVar2 == lStack_48) {
            bVar1 = lStack_40 < lVar3;
          }
          if (!bVar1) goto LAB_0012e579;
          lStack_38 = 0;
          lStack_30 = 0;
          set_normalized_timespec64(&lStack_38,lVar2 - lStack_48,lVar3 - lStack_40);
          lStack_48 = lStack_38;
          lStack_40 = lStack_30;
          if (lStack_38 < 0x225c17d04) break;
          param_1 = 0x44b82fa09;
        }
        if (lStack_38 < -0x225c17d03) {
          uVar4 = 0x8000000000000000;
          goto LAB_0012e6ef;
        }
        uVar4 = lStack_38 * 1000000000 + lStack_30;
        if (uVar4 * 1000 < 1000000000) break;
        param_1 = (uVar4 * 1000) / 1000000000;
      }
      if (1000000 < uVar4) {
LAB_0012e6ef:
        uVar5 = uVar4 / 1000000;
        do {
          uVar5 = uVar5 - 1;
          __const_udelay(0x418958);
        } while (uVar5 != 0);
        uVar4 = uVar4 % 1000000;
      }
      if (uVar4 != 0) {
        __ndelay(uVar4);
      }
    }
  }
LAB_0012e579:
  if (lStack_28 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0012e510 nvlink_sleep =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e595) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void nvlink_sleep(ulong param_1)

{
  bool bVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  long in_GS_OFFSET;
  long local_48;
  long local_40;
  long local_38;
  long local_30;
  long local_28;
  
  param_1 = param_1 & 0xffffffff;
  local_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_48 = 0;
  local_40 = 0;
  ktime_get_raw_ts64(&local_48);
  uVar4 = (*_mpi_powm)();
  if (((uVar4 & 0x200) == 0) || ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) != 0)) {
    for (; param_1 != 0; param_1 = param_1 - 1) {
      __const_udelay(0x418958);
    }
  }
  else {
    local_38 = 0;
    local_30 = 0;
    set_normalized_timespec64(&local_38,local_48,param_1 * 1000000 + local_40);
    lVar3 = local_30;
    lVar2 = local_38;
    if (param_1 != 0) {
      LOCK();
      *(undefined4 *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0x18) = 1;
      UNLOCK();
      while( true ) {
        while( true ) {
          schedule_timeout(param_1);
          ktime_get_raw_ts64(&local_48);
          bVar1 = local_48 < lVar2;
          if (lVar2 == local_48) {
            bVar1 = local_40 < lVar3;
          }
          if (!bVar1) goto LAB_0012e579;
          local_38 = 0;
          local_30 = 0;
          set_normalized_timespec64(&local_38,lVar2 - local_48,lVar3 - local_40);
          local_48 = local_38;
          local_40 = local_30;
          if (local_38 < 0x225c17d04) break;
          param_1 = 0x44b82fa09;
        }
        if (local_38 < -0x225c17d03) {
          uVar4 = 0x8000000000000000;
          goto LAB_0012e6ef;
        }
        uVar4 = local_38 * 1000000000 + local_30;
        if (uVar4 * 1000 < 1000000000) break;
        param_1 = (uVar4 * 1000) / 1000000000;
      }
      if (1000000 < uVar4) {
LAB_0012e6ef:
        uVar5 = uVar4 / 1000000;
        do {
          uVar5 = uVar5 - 1;
          __const_udelay(0x418958);
        } while (uVar5 != 0);
        uVar4 = uVar4 % 1000000;
      }
      if (uVar4 != 0) {
        __ndelay(uVar4);
      }
    }
  }
LAB_0012e579:
  if (local_28 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0012e770 __pfx_nvlink_assert =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e78d) */

void __pfx_nvlink_assert(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined8 in_R9;
  undefined8 uVar3;
  
  uVar3 = 0x12e789;
  if (param_1 == 0) {
    iVar2 = __printk_ratelimit("nvlink_assert");
    if (iVar2 != 0) {
      nvlink_print("nvidia/nvlink_linux.c",0x22c,"nvlink_assert",4,"NVLink: Assertion failed!\n",
                   in_R9,uVar3);
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
  }
  return;
}


// ===== 0012e780 nvlink_assert =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e78d) */

void nvlink_assert(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined8 in_R9;
  undefined8 uVar3;
  
  uVar3 = 0x12e789;
  if (param_1 == 0) {
    iVar2 = __printk_ratelimit("nvlink_assert");
    if (iVar2 != 0) {
      nvlink_print("nvidia/nvlink_linux.c",0x22c,"nvlink_assert",4,"NVLink: Assertion failed!\n",
                   in_R9,uVar3);
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
  }
  return;
}


// ===== 0012e7d0 __pfx_nvlink_allocLock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e829) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * __pfx_nvlink_allocLock(void)

{
  undefined8 *puVar1;
  undefined8 in_R9;
  undefined8 uVar2;
  
  uVar2 = 0x12e7e9;
  puVar1 = (undefined8 *)__kmalloc_cache_noprof(___alloc_pages_noprof,0xcc0,0x18);
  if (puVar1 == (undefined8 *)0x0) {
    nvlink_print("nvidia/nvlink_linux.c",0x23b,"nvlink_allocLock",4,"Failed to allocate sema!\n",
                 in_R9,0,uVar2);
  }
  else {
    puVar1[1] = 0;
    *puVar1 = 0x100000000;
    puVar1[2] = 0;
  }
  return puVar1;
}


// ===== 0012e7e0 nvlink_allocLock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e829) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * nvlink_allocLock(void)

{
  undefined8 *puVar1;
  undefined8 in_R9;
  undefined8 uVar2;
  
  uVar2 = 0x12e7e9;
  puVar1 = (undefined8 *)__kmalloc_cache_noprof(___alloc_pages_noprof,0xcc0,0x18);
  if (puVar1 == (undefined8 *)0x0) {
    nvlink_print("nvidia/nvlink_linux.c",0x23b,"nvlink_allocLock",4,"Failed to allocate sema!\n",
                 in_R9,0,uVar2);
  }
  else {
    puVar1[1] = 0;
    *puVar1 = 0x100000000;
    puVar1[2] = 0;
  }
  return puVar1;
}


// ===== 0012e860 __pfx_nvlink_acquireLock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvlink_acquireLock(void)

{
  down();
  return;
}


// ===== 0012e870 nvlink_acquireLock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvlink_acquireLock(void)

{
  down();
  return;
}


// ===== 0012e880 __pfx_nvlink_releaseLock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvlink_releaseLock(void)

{
  up();
  return;
}


// ===== 0012e890 nvlink_releaseLock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvlink_releaseLock(void)

{
  up();
  return;
}


// ===== 0012e8a0 __pfx_nvlink_freeLock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e8c3) */

void __pfx_nvlink_freeLock(long param_1)

{
  if (param_1 != 0) {
    kfree();
    return;
  }
  return;
}


// ===== 0012e8b0 nvlink_freeLock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e8c3) */

void nvlink_freeLock(long param_1)

{
  if (param_1 != 0) {
    kfree();
    return;
  }
  return;
}


// ===== 0012e8d0 __pfx_nvlink_isLockOwner =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e8ee) */

undefined8 __pfx_nvlink_isLockOwner(void)

{
  return 1;
}


// ===== 0012e8e0 nvlink_isLockOwner =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e8ee) */

undefined8 nvlink_isLockOwner(void)

{
  return 1;
}


// ===== 0012e900 __pfx_nvlink_acquire_fabric_mgmt_cap =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e950) */
/* WARNING: Removing unreachable block (ram,0x0012e93c) */
/* WARNING: Removing unreachable block (ram,0x0012e943) */

undefined8 __pfx_nvlink_acquire_fabric_mgmt_cap(int *param_1,undefined8 param_2)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    return 1;
  }
  iVar1 = nvlink_cap_acquire(param_2,0);
  if (-1 < iVar1) {
    *param_1 = iVar1;
    return 0;
  }
  return 0x10;
}


// ===== 0012e910 nvlink_acquire_fabric_mgmt_cap =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e950) */
/* WARNING: Removing unreachable block (ram,0x0012e93c) */
/* WARNING: Removing unreachable block (ram,0x0012e943) */

undefined8 nvlink_acquire_fabric_mgmt_cap(int *param_1,undefined8 param_2)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    return 1;
  }
  iVar1 = nvlink_cap_acquire(param_2,0);
  if (-1 < iVar1) {
    *param_1 = iVar1;
    return 0;
  }
  return 0x10;
}


// ===== 0012e960 __pfx_nvlink_is_fabric_manager =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e985) */
/* WARNING: Removing unreachable block (ram,0x0012e98c) */

uint __pfx_nvlink_is_fabric_manager(uint *param_1)

{
  if (param_1 != (uint *)0x0) {
    return ~*param_1 >> 0x1f;
  }
  return 0;
}


// ===== 0012e970 nvlink_is_fabric_manager =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e985) */
/* WARNING: Removing unreachable block (ram,0x0012e98c) */

uint nvlink_is_fabric_manager(uint *param_1)

{
  if (param_1 != (uint *)0x0) {
    return ~*param_1 >> 0x1f;
  }
  return 0;
}


// ===== 0012e9a0 __pfx_nvlink_is_admin =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e9c6) */

undefined1 __pfx_nvlink_is_admin(void)

{
  undefined1 uVar1;
  
  uVar1 = capable(0x15);
  return uVar1;
}


// ===== 0012e9b0 nvlink_is_admin =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012e9c6) */

undefined1 nvlink_is_admin(void)

{
  undefined1 uVar1;
  
  uVar1 = capable(0x15);
  return uVar1;
}


// ===== 0012e9d0 __pfx_nvlink_get_platform_time =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ea54) */

long __pfx_nvlink_get_platform_time(void)

{
  long lVar1;
  long in_GS_OFFSET;
  long lStack_20;
  long lStack_18;
  long lStack_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x12e9e9;
  lStack_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lStack_20 = 0;
  lStack_18 = 0;
  ktime_get_raw_ts64(&lStack_20);
  if (lStack_20 < 0x225c17d04) {
    if (lStack_20 < -0x225c17d03) {
      lVar1 = -0x8000000000000000;
    }
    else {
      lVar1 = lStack_20 * 1000000000 + lStack_18;
    }
  }
  else {
    lVar1 = 0x7fffffffffffffff;
  }
  if (lStack_10 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return lVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0012e9e0 nvlink_get_platform_time =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ea54) */

long nvlink_get_platform_time(void)

{
  long lVar1;
  long in_GS_OFFSET;
  long local_20;
  long local_18;
  long local_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x12e9e9;
  local_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_20 = 0;
  local_18 = 0;
  ktime_get_raw_ts64(&local_20);
  if (local_20 < 0x225c17d04) {
    if (local_20 < -0x225c17d03) {
      lVar1 = -0x8000000000000000;
    }
    else {
      lVar1 = local_20 * 1000000000 + local_18;
    }
  }
  else {
    lVar1 = 0x7fffffffffffffff;
  }
  if (local_10 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return lVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0012ea80 __pfx_nvlink_cap_acquire =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012eab3) */
/* WARNING: Removing unreachable block (ram,0x0012eae1) */

undefined8 __pfx_nvlink_cap_acquire(int param_1,int param_2)

{
  undefined8 uVar1;
  undefined8 in_R9;
  undefined8 uVar2;
  
  uVar2 = 0x12ea99;
  if (-1 < param_1) {
    if (param_2 == 0) {
      uVar1 = nv_cap_validate_and_dup_fd(DAT_005477a8,param_1);
      if (-1 < (int)uVar1) {
        return uVar1;
      }
      nvlink_print("nvidia/nvlink_caps.c",0x37,"nvlink_cap_acquire",4,
                   "Failed to validate the fabric mgmt capability\n",in_R9,uVar2);
    }
    else {
      nvlink_print("nvidia/nvlink_caps.c",0x3f,"nvlink_cap_acquire",4,
                   "Unknown capability specified\n",in_R9,0x12ea99);
    }
  }
  return 0xffffffff;
}


// ===== 0012ea90 nvlink_cap_acquire =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012eab3) */
/* WARNING: Removing unreachable block (ram,0x0012eae1) */

undefined8 nvlink_cap_acquire(int param_1,int param_2)

{
  undefined8 uVar1;
  undefined8 in_R9;
  undefined8 uVar2;
  
  uVar2 = 0x12ea99;
  if (-1 < param_1) {
    if (param_2 == 0) {
      uVar1 = nv_cap_validate_and_dup_fd(DAT_005477a8,param_1);
      if (-1 < (int)uVar1) {
        return uVar1;
      }
      nvlink_print("nvidia/nvlink_caps.c",0x37,"nvlink_cap_acquire",4,
                   "Failed to validate the fabric mgmt capability\n",in_R9,uVar2);
    }
    else {
      nvlink_print("nvidia/nvlink_caps.c",0x3f,"nvlink_cap_acquire",4,
                   "Unknown capability specified\n",in_R9,0x12ea99);
    }
  }
  return 0xffffffff;
}


// ===== 0012eb10 __pfx_nvlink_cap_release =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012eb32) */

void __pfx_nvlink_cap_release(int param_1)

{
  if (-1 < param_1) {
    nv_cap_close_fd();
    return;
  }
  return;
}


// ===== 0012eb20 nvlink_cap_release =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012eb32) */

void nvlink_cap_release(int param_1)

{
  if (-1 < param_1) {
    nv_cap_close_fd();
    return;
  }
  return;
}


// ===== 0012eb40 __pfx_nvlink_cap_exit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012eb91) */

void __pfx_nvlink_cap_exit(void)

{
  if (DAT_005477a8 != 0) {
    nv_cap_destroy_entry();
    DAT_005477a8 = 0;
  }
  if (nvlink_caps != 0) {
    nv_cap_destroy_entry();
    nvlink_caps = 0;
  }
  return;
}


// ===== 0012eb50 nvlink_cap_exit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012eb91) */

void nvlink_cap_exit(void)

{
  if (DAT_005477a8 != 0) {
    nv_cap_destroy_entry();
    DAT_005477a8 = 0;
  }
  if (nvlink_caps != 0) {
    nv_cap_destroy_entry();
    nvlink_caps = 0;
  }
  return;
}


// ===== 0012eba0 __pfx_nvlink_cap_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ebf1) */
/* WARNING: Removing unreachable block (ram,0x0012ec22) */

undefined8 __pfx_nvlink_cap_init(long param_1)

{
  if (param_1 == 0) {
    nvlink_print("nvidia/nvlink_caps.c",100,"nvlink_cap_init",4,"Invalid path: %s\n",0,0x12ebb9);
  }
  else {
    nvlink_caps = nv_cap_init();
    if (nvlink_caps == 0) {
      nvlink_print("nvidia/nvlink_caps.c",0x6b,"nvlink_cap_init",4,
                   "Failed to initialize capabilities\n");
    }
    else {
      DAT_005477a8 = nv_cap_create_file_entry(nvlink_caps,"fabric-mgmt",0x100);
      if (DAT_005477a8 != 0) {
        return 0;
      }
      nvlink_print("nvidia/nvlink_caps.c",0x74,"nvlink_cap_init",4,
                   "Failed to create fabric-mgmt entry\n");
      if (DAT_005477a8 != 0) {
        nv_cap_destroy_entry();
        DAT_005477a8 = 0;
      }
      if (nvlink_caps != 0) {
        nv_cap_destroy_entry();
        nvlink_caps = 0;
      }
    }
  }
  return 0xffffffff;
}


// ===== 0012ebb0 nvlink_cap_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ebf1) */
/* WARNING: Removing unreachable block (ram,0x0012ec22) */

undefined8 nvlink_cap_init(long param_1)

{
  if (param_1 == 0) {
    nvlink_print("nvidia/nvlink_caps.c",100,"nvlink_cap_init",4,"Invalid path: %s\n",0,0x12ebb9);
  }
  else {
    nvlink_caps = nv_cap_init();
    if (nvlink_caps == 0) {
      nvlink_print("nvidia/nvlink_caps.c",0x6b,"nvlink_cap_init",4,
                   "Failed to initialize capabilities\n");
    }
    else {
      DAT_005477a8 = nv_cap_create_file_entry(nvlink_caps,"fabric-mgmt",0x100);
      if (DAT_005477a8 != 0) {
        return 0;
      }
      nvlink_print("nvidia/nvlink_caps.c",0x74,"nvlink_cap_init",4,
                   "Failed to create fabric-mgmt entry\n");
      if (DAT_005477a8 != 0) {
        nv_cap_destroy_entry();
        DAT_005477a8 = 0;
      }
      if (nvlink_caps != 0) {
        nv_cap_destroy_entry();
        nvlink_caps = 0;
      }
    }
  }
  return 0xffffffff;
}


// ===== 0012ecb0 __pfx___traceiter_nvswitch_dev_sxid =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ed2d) */

undefined8
__pfx___traceiter_nvswitch_dev_sxid
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  long *plVar1;
  code *pcVar2;
  long lVar3;
  long *plVar4;
  
  plVar4 = (long *)__tracepoint_nvswitch_dev_sxid._56_8_;
  lVar3 = __tracepoint_nvswitch_dev_sxid._56_8_;
  while (lVar3 != 0) {
    pcVar2 = (code *)*plVar4;
    plVar1 = plVar4 + 1;
    plVar4 = plVar4 + 3;
    (*pcVar2)(*plVar1,param_2,param_3,param_4);
    lVar3 = *plVar4;
  }
  return 0;
}


// ===== 0012ecc0 __traceiter_nvswitch_dev_sxid =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ed2d) */

undefined8
__traceiter_nvswitch_dev_sxid
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  long *plVar1;
  code *pcVar2;
  long lVar3;
  long *plVar4;
  
  plVar4 = (long *)__tracepoint_nvswitch_dev_sxid._56_8_;
  lVar3 = __tracepoint_nvswitch_dev_sxid._56_8_;
  while (lVar3 != 0) {
    pcVar2 = (code *)*plVar4;
    plVar1 = plVar4 + 1;
    plVar4 = plVar4 + 3;
    (*pcVar2)(*plVar1,param_2,param_3,param_4);
    lVar3 = *plVar4;
  }
  return 0;
}


// ===== 0012ed40 __pfx___probestub_nvswitch_dev_sxid =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ed59) */

void __pfx___probestub_nvswitch_dev_sxid(void)

{
  return;
}


// ===== 0012ed50 __probestub_nvswitch_dev_sxid =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ed59) */

void __probestub_nvswitch_dev_sxid(void)

{
  return;
}


// ===== 0012ed60 __pfx_trace_raw_output_nvswitch_dev_sxid =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ed8f) */

void __pfx_trace_raw_output_nvswitch_dev_sxid(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_1 + 0x4080);
  iVar2 = trace_raw_output_prep(param_1,param_3);
  if (iVar2 != 1) {
    return;
  }
  trace_event_printf(param_1,"SXid (PCI:%s): %u, %s\n",(ulong)*(ushort *)(lVar1 + 8) + lVar1,
                     *(undefined4 *)(lVar1 + 0xc),lVar1 + (ulong)*(ushort *)(lVar1 + 0x10));
  trace_handle_return(param_1 + 0x2080);
  return;
}


// ===== 0012ed70 trace_raw_output_nvswitch_dev_sxid =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ed8f) */

void trace_raw_output_nvswitch_dev_sxid(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_1 + 0x4080);
  iVar2 = trace_raw_output_prep(param_1,param_3);
  if (iVar2 != 1) {
    return;
  }
  trace_event_printf(param_1,"SXid (PCI:%s): %u, %s\n",(ulong)*(ushort *)(lVar1 + 8) + lVar1,
                     *(undefined4 *)(lVar1 + 0xc),lVar1 + (ulong)*(ushort *)(lVar1 + 0x10));
  trace_handle_return(param_1 + 0x2080);
  return;
}


// ===== 0012edd0 __pfx___bpf_trace_nvswitch_dev_sxid =====

void __pfx___bpf_trace_nvswitch_dev_sxid(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  bpf_trace_run3(param_1,param_2,param_3);
  return;
}


// ===== 0012ede0 __bpf_trace_nvswitch_dev_sxid =====

void __bpf_trace_nvswitch_dev_sxid(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  bpf_trace_run3(param_1,param_2,param_3);
  return;
}


// ===== 0012edf0 __pfx_nvswitch_is_device_blacklisted =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ee58) */

bool __pfx_nvswitch_is_device_blacklisted(long param_1)

{
  int iVar1;
  int iVar2;
  long in_GS_OFFSET;
  int iStack_1c;
  long lStack_18;
  
  lStack_18 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  iStack_1c = 0;
  iVar2 = nvswitch_lib_read_fabric_state(*(undefined8 *)(param_1 + 0x50),&iStack_1c,0,0);
  iVar1 = iStack_1c;
  if (iVar2 != 0) {
    _printk(&DAT_00df1628,param_1,iVar2);
  }
  if (lStack_18 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2 == 0 && iVar1 == 3;
}


// ===== 0012ee00 nvswitch_is_device_blacklisted =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ee58) */

bool nvswitch_is_device_blacklisted(long param_1)

{
  int iVar1;
  int iVar2;
  long in_GS_OFFSET;
  int local_1c;
  long local_18;
  
  local_18 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_1c = 0;
  iVar2 = nvswitch_lib_read_fabric_state(*(undefined8 *)(param_1 + 0x50),&local_1c,0,0);
  iVar1 = local_1c;
  if (iVar2 != 0) {
    _printk(&DAT_00df1628,param_1,iVar2);
  }
  if (local_18 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2 == 0 && iVar1 == 3;
}


// ===== 0012ee70 __pfx_nvswitch_device_poll =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ef3f) */

int __pfx_nvswitch_device_poll(long param_1,undefined8 *param_2)

{
  long *plVar1;
  long lVar2;
  int iVar3;
  long in_GS_OFFSET;
  undefined8 uStack_40;
  long lStack_38;
  
  plVar1 = *(long **)(param_1 + 0x18);
  lStack_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lVar2 = *plVar1;
  uStack_40 = 0;
  iVar3 = mutex_lock_interruptible(lVar2 + 0x38);
  if (iVar3 == 0) {
    if (*(char *)(lVar2 + 0x120) == '\0') {
      iVar3 = nvswitch_lib_get_client_event(*(undefined8 *)(lVar2 + 0x50),plVar1,&uStack_40);
      if (iVar3 == 0) {
        if ((param_2 != (undefined8 *)0x0) && ((code *)*param_2 != (code *)0x0)) {
          (*(code *)*param_2)(param_1,plVar1 + 1,param_2);
          LOCK();
          UNLOCK();
        }
        iVar3 = 0;
        if ((char)plVar1[4] != '\0') {
          *(undefined1 *)(plVar1 + 4) = 0;
          iVar3 = 3;
        }
      }
      else {
        iVar3 = 8;
        _printk(&DAT_00df1650,lVar2);
      }
    }
    else {
      iVar3 = 0x10;
      _printk(&DAT_00db0752,lVar2);
    }
    mutex_unlock(lVar2 + 0x38);
  }
  if (lStack_38 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}


// ===== 0012ee80 nvswitch_device_poll =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ef3f) */

int nvswitch_device_poll(long param_1,undefined8 *param_2)

{
  long *plVar1;
  long lVar2;
  int iVar3;
  long in_GS_OFFSET;
  undefined8 local_40;
  long local_38;
  
  plVar1 = *(long **)(param_1 + 0x18);
  local_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lVar2 = *plVar1;
  local_40 = 0;
  iVar3 = mutex_lock_interruptible(lVar2 + 0x38);
  if (iVar3 == 0) {
    if (*(char *)(lVar2 + 0x120) == '\0') {
      iVar3 = nvswitch_lib_get_client_event(*(undefined8 *)(lVar2 + 0x50),plVar1,&local_40);
      if (iVar3 == 0) {
        if ((param_2 != (undefined8 *)0x0) && ((code *)*param_2 != (code *)0x0)) {
          (*(code *)*param_2)(param_1,plVar1 + 1,param_2);
          LOCK();
          UNLOCK();
        }
        iVar3 = 0;
        if ((char)plVar1[4] != '\0') {
          *(undefined1 *)(plVar1 + 4) = 0;
          iVar3 = 3;
        }
      }
      else {
        iVar3 = 8;
        _printk(&DAT_00df1650,lVar2);
      }
    }
    else {
      iVar3 = 0x10;
      _printk(&DAT_00db0752,lVar2);
    }
    mutex_unlock(lVar2 + 0x38);
  }
  if (local_38 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}


// ===== 0012ef60 __pfx_nvswitch_isr_thread =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012efcc) */

undefined8 __pfx_nvswitch_isr_thread(undefined8 param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  
  lVar1 = param_2 + 0x38;
  mutex_lock(lVar1);
  iVar3 = nvswitch_lib_service_interrupts(*(undefined8 *)(param_2 + 0x50));
  __wake_up(param_2 + 0x58,3,1,0);
  if (*(char *)(param_2 + 0x138) == '\x03') {
    nvswitch_lib_enable_interrupts(*(undefined8 *)(param_2 + 0x50));
    mutex_unlock(lVar1);
  }
  else {
    mutex_unlock(lVar1);
  }
  if (iVar3 == 0) {
    return 1;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)invalidInstructionException();
  (*pcVar2)();
}


// ===== 0012ef70 nvswitch_isr_thread =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012efcc) */

undefined8 nvswitch_isr_thread(undefined8 param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  
  lVar1 = param_2 + 0x38;
  mutex_lock(lVar1);
  iVar3 = nvswitch_lib_service_interrupts(*(undefined8 *)(param_2 + 0x50));
  __wake_up(param_2 + 0x58,3,1,0);
  if (*(char *)(param_2 + 0x138) == '\x03') {
    nvswitch_lib_enable_interrupts(*(undefined8 *)(param_2 + 0x50));
    mutex_unlock(lVar1);
  }
  else {
    mutex_unlock(lVar1);
  }
  if (iVar3 == 0) {
    return 1;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)invalidInstructionException();
  (*pcVar2)();
}


// ===== 0012f010 __pfx__nvswitch_os_malloc =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012f059) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long __pfx__nvswitch_os_malloc(ulong param_1)

{
  ulong uVar1;
  long lVar2;
  long in_GS_OFFSET;
  
  uVar1 = (*_mpi_powm)();
  if (((uVar1 & 0x200) == 0) || ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) != 0)) {
    if (0x20000 < param_1) {
      return 0;
    }
    lVar2 = __kmalloc_noprof();
    return lVar2;
  }
  if ((param_1 < 0x20001) && (lVar2 = __kmalloc_noprof(), lVar2 != 0)) {
    return lVar2;
  }
  lVar2 = vmalloc_noprof();
  return lVar2;
}


// ===== 0012f020 _nvswitch_os_malloc =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012f059) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long _nvswitch_os_malloc(ulong param_1)

{
  ulong uVar1;
  long lVar2;
  long in_GS_OFFSET;
  
  uVar1 = (*_mpi_powm)();
  if (((uVar1 & 0x200) == 0) || ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) != 0)) {
    if (0x20000 < param_1) {
      return 0;
    }
    lVar2 = __kmalloc_noprof();
    return lVar2;
  }
  if ((param_1 < 0x20001) && (lVar2 = __kmalloc_noprof(), lVar2 != 0)) {
    return lVar2;
  }
  lVar2 = vmalloc_noprof();
  return lVar2;
}


// ===== 0012f090 __pfx__nvswitch_os_free =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012f0cc) */

void __pfx__nvswitch_os_free(long param_1)

{
  char cVar1;
  
  if (param_1 == 0) {
    return;
  }
  cVar1 = is_vmalloc_addr();
  if (cVar1 != '\0') {
    vfree();
    return;
  }
  kfree(param_1);
  return;
}


// ===== 0012f0a0 _nvswitch_os_free =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012f0cc) */

void _nvswitch_os_free(long param_1)

{
  char cVar1;
  
  if (param_1 == 0) {
    return;
  }
  cVar1 = is_vmalloc_addr();
  if (cVar1 != '\0') {
    vfree();
    return;
  }
  kfree(param_1);
  return;
}


// ===== 0012f0e0 __pfx_nvswitch_remove =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvswitch_remove(long param_1)

{
  long lVar1;
  
  mutex_lock(&DAT_005478a0);
  lVar1 = *(long *)(param_1 + 0x148);
  if (lVar1 != 0) {
    _printk(&DAT_00df1728,lVar1,**(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
            *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),*(uint *)(param_1 + 0x38) >> 3 & 0x1f,
            *(uint *)(param_1 + 0x38) & 7);
    mutex_lock();
    *(undefined1 *)(lVar1 + 0x120) = 1;
    mutex_unlock(lVar1 + 0x38);
    LOCK();
    DAT_0054789c = DAT_0054789c + -1;
    UNLOCK();
    __list_del_entry(lVar1 + 0x110);
    *(undefined8 *)(lVar1 + 0x110) = 0xdead000000000100;
    *(undefined8 *)(lVar1 + 0x118) = 0xdead000000000122;
    nvswitch_deinit_background_tasks(lVar1);
    nvswitch_deinit_device(lVar1);
    *(undefined8 *)(param_1 + 0x148) = 0;
    pci_iounmap(param_1,*(undefined8 *)(lVar1 + 0x70));
    pci_release_regions(param_1);
    pci_clear_master(param_1);
    pci_disable_device(param_1);
    nvswitch_procfs_device_remove(lVar1);
    if (*(int *)(lVar1 + 0x108) == 0) {
      kfree(lVar1);
    }
  }
  mutex_unlock(&DAT_005478a0);
  return;
}


// ===== 0012f0f0 nvswitch_remove =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvswitch_remove(long param_1)

{
  long lVar1;
  
  mutex_lock(&DAT_005478a0);
  lVar1 = *(long *)(param_1 + 0x148);
  if (lVar1 != 0) {
    _printk(&DAT_00df1728,lVar1,**(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
            *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),*(uint *)(param_1 + 0x38) >> 3 & 0x1f,
            *(uint *)(param_1 + 0x38) & 7);
    mutex_lock();
    *(undefined1 *)(lVar1 + 0x120) = 1;
    mutex_unlock(lVar1 + 0x38);
    LOCK();
    DAT_0054789c = DAT_0054789c + -1;
    UNLOCK();
    __list_del_entry(lVar1 + 0x110);
    *(undefined8 *)(lVar1 + 0x110) = 0xdead000000000100;
    *(undefined8 *)(lVar1 + 0x118) = 0xdead000000000122;
    nvswitch_deinit_background_tasks(lVar1);
    nvswitch_deinit_device(lVar1);
    *(undefined8 *)(param_1 + 0x148) = 0;
    pci_iounmap(param_1,*(undefined8 *)(lVar1 + 0x70));
    pci_release_regions(param_1);
    pci_clear_master(param_1);
    pci_disable_device(param_1);
    nvswitch_procfs_device_remove(lVar1);
    if (*(int *)(lVar1 + 0x108) == 0) {
      kfree(lVar1);
    }
  }
  mutex_unlock(&DAT_005478a0);
  return;
}


// ===== 0012f130 __pfx_nvswitch_task_dispatch =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012f17d) */

void __pfx_nvswitch_task_dispatch(long param_1)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  long in_GS_OFFSET;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  long lStack_28;
  
  lStack_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if (*(int *)(param_1 + 0xe0) != 0) {
    mutex_lock(param_1 + 0x38);
    uVar3 = nvswitch_lib_deferred_task_dispatcher(*(undefined8 *)(param_1 + 0x50));
    mutex_unlock(param_1 + 0x38);
    lVar4 = __usecs_to_jiffies(uVar3 / 1000 & 0xffffffff);
    __SCT__might_resched();
    lVar5 = lVar4;
    if (*(int *)(param_1 + 0xe0) == 0) {
      if (lVar4 == 0) goto LAB_0012f166;
    }
    else if (lVar4 != 0) {
      uStack_50 = 0;
      uStack_48 = 0;
      uStack_40 = 0;
      uStack_38 = 0;
      uStack_30 = 0;
      init_wait_entry(&uStack_50,0);
      while (lVar5 = prepare_to_wait_event(param_1 + 0xe8,&uStack_50,1),
            *(int *)(param_1 + 0xe0) != 0) {
        if (lVar5 != 0) goto LAB_0012f2a1;
        lVar4 = schedule_timeout(lVar4);
        if (*(int *)(param_1 + 0xe0) == 0) {
          if (lVar4 == 0) {
            lVar4 = 1;
          }
          break;
        }
        if (lVar4 == 0) break;
      }
      finish_wait(param_1 + 0xe8,&uStack_50);
      lVar5 = lVar4;
    }
LAB_0012f2a1:
    if (lVar5 < 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    if ((lVar5 == 0) &&
       (iVar2 = nv_kthread_q_schedule_q_item(param_1 + 0x78,param_1 + 0xc0), iVar2 == 0)) {
      nvswitch_task_dispatch_cold();
      return;
    }
  }
LAB_0012f166:
  if (lStack_28 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ===== 0012f140 nvswitch_task_dispatch =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012f17d) */

void nvswitch_task_dispatch(long param_1)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  long in_GS_OFFSET;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  local_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if (*(int *)(param_1 + 0xe0) != 0) {
    mutex_lock(param_1 + 0x38);
    uVar3 = nvswitch_lib_deferred_task_dispatcher(*(undefined8 *)(param_1 + 0x50));
    mutex_unlock(param_1 + 0x38);
    lVar4 = __usecs_to_jiffies(uVar3 / 1000 & 0xffffffff);
    __SCT__might_resched();
    lVar5 = lVar4;
    if (*(int *)(param_1 + 0xe0) == 0) {
      if (lVar4 == 0) goto LAB_0012f166;
    }
    else if (lVar4 != 0) {
      local_50 = 0;
      local_48 = 0;
      local_40 = 0;
      local_38 = 0;
      local_30 = 0;
      init_wait_entry(&local_50,0);
      while (lVar5 = prepare_to_wait_event(param_1 + 0xe8,&local_50,1),
            *(int *)(param_1 + 0xe0) != 0) {
        if (lVar5 != 0) goto LAB_0012f2a1;
        lVar4 = schedule_timeout(lVar4);
        if (*(int *)(param_1 + 0xe0) == 0) {
          if (lVar4 == 0) {
            lVar4 = 1;
          }
          break;
        }
        if (lVar4 == 0) break;
      }
      finish_wait(param_1 + 0xe8,&local_50);
      lVar5 = lVar4;
    }
LAB_0012f2a1:
    if (lVar5 < 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    if ((lVar5 == 0) &&
       (iVar2 = nv_kthread_q_schedule_q_item(param_1 + 0x78,param_1 + 0xc0), iVar2 == 0)) {
      nvswitch_task_dispatch_cold();
      return;
    }
  }
LAB_0012f166:
  if (local_28 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ===== 0012f300 __pfx_nvswitch_ioctl_state_sync.isra.0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012f36f) */
/* WARNING: Removing unreachable block (ram,0x0012f376) */

uint __pfx_nvswitch_ioctl_state_sync_isra_0
               (undefined8 param_1,ulong param_2,int param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  
  if ((param_3 < 0) && (param_2 != 0)) {
    if (param_2 < 0x80000000) {
      __check_object_size(param_1,param_2,1);
      iVar2 = _copy_to_user(param_4,param_1,param_2);
      return -(uint)(iVar2 != 0) & 0xfffffff2;
    }
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  return 0;
}


// ===== 0012f310 nvswitch_ioctl_state_sync.isra.0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012f36f) */
/* WARNING: Removing unreachable block (ram,0x0012f376) */

uint nvswitch_ioctl_state_sync_isra_0
               (undefined8 param_1,ulong param_2,int param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  
  if ((param_3 < 0) && (param_2 != 0)) {
    if (param_2 < 0x80000000) {
      __check_object_size(param_1,param_2,1);
      iVar2 = _copy_to_user(param_4,param_1,param_2);
      return -(uint)(iVar2 != 0) & 0xfffffff2;
    }
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  return 0;
}


// ===== 0012f390 __pfx_trace_event_get_offsets_nvswitch_dev_sxid.isra.0 =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012f416) */

int __pfx_trace_event_get_offsets_nvswitch_dev_sxid_isra_0(uint *param_1,long param_2,char *param_3)

{
  size_t sVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char *__s;
  int iVar6;
  
  __s = *(char **)(param_2 + 0x120);
  if ((__s == (char *)0x0) && (__s = *(char **)(param_2 + 0xd0), __s == (char *)0x0)) {
    uVar5 = 0x1b;
    uVar3 = 0x70014;
    iVar6 = 7;
  }
  else {
    sVar1 = strlen(__s);
    iVar6 = (int)sVar1 + 1;
    uVar5 = (int)sVar1 + 0x15;
    uVar3 = iVar6 * 0x10000 | 0x14;
  }
  *param_1 = uVar3;
  lVar2 = *(long *)(param_2 + 0x120);
  if (lVar2 == 0) {
    lVar2 = *(long *)(param_2 + 0xd0);
  }
  *(long *)(param_1 + 2) = lVar2;
  if (param_3 == (char *)0x0) {
    uVar3 = 0x70000;
    iVar4 = 7;
  }
  else {
    sVar1 = strlen(param_3);
    iVar4 = (int)sVar1 + 1;
    uVar3 = iVar4 * 0x10000;
  }
  *(char **)(param_1 + 6) = param_3;
  param_1[4] = uVar3 | uVar5;
  return iVar6 + iVar4;
}


// ===== 0012f3a0 trace_event_get_offsets_nvswitch_dev_sxid.isra.0 =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012f416) */

int trace_event_get_offsets_nvswitch_dev_sxid_isra_0(uint *param_1,long param_2,char *param_3)

{
  size_t sVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char *__s;
  int iVar6;
  
  __s = *(char **)(param_2 + 0x120);
  if ((__s == (char *)0x0) && (__s = *(char **)(param_2 + 0xd0), __s == (char *)0x0)) {
    uVar5 = 0x1b;
    uVar3 = 0x70014;
    iVar6 = 7;
  }
  else {
    sVar1 = strlen(__s);
    iVar6 = (int)sVar1 + 1;
    uVar5 = (int)sVar1 + 0x15;
    uVar3 = iVar6 * 0x10000 | 0x14;
  }
  *param_1 = uVar3;
  lVar2 = *(long *)(param_2 + 0x120);
  if (lVar2 == 0) {
    lVar2 = *(long *)(param_2 + 0xd0);
  }
  *(long *)(param_1 + 2) = lVar2;
  if (param_3 == (char *)0x0) {
    uVar3 = 0x70000;
    iVar4 = 7;
  }
  else {
    sVar1 = strlen(param_3);
    iVar4 = (int)sVar1 + 1;
    uVar3 = iVar4 * 0x10000;
  }
  *(char **)(param_1 + 6) = param_3;
  param_1[4] = uVar3 | uVar5;
  return iVar6 + iVar4;
}


// ===== 0012f450 __pfx_trace_event_raw_event_nvswitch_dev_sxid =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012f604) */

void __pfx_trace_event_raw_event_nvswitch_dev_sxid
               (long param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  long lVar6;
  void *pvVar7;
  size_t sVar8;
  char *__src;
  char *__src_00;
  long in_GS_OFFSET;
  undefined8 uStack_88;
  char *pcStack_80;
  undefined8 uStack_78;
  char *pcStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  long lStack_38;
  
  lStack_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  *(int *)(&__preempt_count + in_GS_OFFSET) = *(int *)(&__preempt_count + in_GS_OFFSET) + 1;
  uStack_88 = 0;
  pcStack_80 = (char *)0x0;
  uStack_78 = 0;
  pcStack_70 = (char *)0x0;
  uStack_68 = 0;
  uStack_60 = 0;
  uStack_58 = 0;
  uStack_50 = 0;
  uStack_48 = 0;
  uStack_40 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x160) == 0) || ((*(ulong *)(param_1 + 0x48) & 0x80) != 0)) ||
     (cVar4 = __trace_trigger_soft_disabled(), cVar4 == '\0')) {
    iVar5 = trace_event_get_offsets_nvswitch_dev_sxid_isra_0(&uStack_88,param_2,param_4);
    __src = pcStack_70;
    __src_00 = pcStack_80;
    uVar2 = (uint)uStack_88;
    uVar3 = (undefined4)uStack_78;
    lVar6 = trace_event_buffer_reserve(&uStack_68,param_1,(long)iVar5 + 0x14);
    if (lVar6 != 0) {
      *(uint *)(lVar6 + 8) = uVar2;
      *(undefined4 *)(lVar6 + 0x10) = uVar3;
      sVar8 = (size_t)(int)((uVar2 >> 0x10) - 1);
      if (__src_00 == (char *)0x0) {
        __src_00 = "(null)";
      }
      pvVar7 = memcpy((void *)((ulong)(uVar2 & 0xffff) + lVar6),__src_00,sVar8);
      *(undefined1 *)((long)pvVar7 + sVar8) = 0;
      sVar8 = (size_t)(int)((*(uint *)(lVar6 + 0x10) >> 0x10) - 1);
      if (__src == (char *)0x0) {
        __src = "(null)";
      }
      pvVar7 = memcpy((void *)((ulong)(*(uint *)(lVar6 + 0x10) & 0xffff) + lVar6),__src,sVar8);
      *(undefined1 *)((long)pvVar7 + sVar8) = 0;
      *(undefined4 *)(lVar6 + 0xc) = param_3;
      trace_event_buffer_commit(&uStack_68);
    }
  }
  piVar1 = (int *)(&__preempt_count + in_GS_OFFSET);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    __SCT__preempt_schedule_notrace();
  }
  if (lStack_38 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ===== 0012f460 trace_event_raw_event_nvswitch_dev_sxid =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012f604) */

void trace_event_raw_event_nvswitch_dev_sxid
               (long param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  long lVar6;
  void *pvVar7;
  size_t sVar8;
  char *__src;
  char *__src_00;
  long in_GS_OFFSET;
  undefined8 local_88;
  char *local_80;
  undefined8 local_78;
  char *local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  local_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  *(int *)(&__preempt_count + in_GS_OFFSET) = *(int *)(&__preempt_count + in_GS_OFFSET) + 1;
  local_88 = 0;
  local_80 = (char *)0x0;
  local_78 = 0;
  local_70 = (char *)0x0;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x160) == 0) || ((*(ulong *)(param_1 + 0x48) & 0x80) != 0)) ||
     (cVar4 = __trace_trigger_soft_disabled(), cVar4 == '\0')) {
    iVar5 = trace_event_get_offsets_nvswitch_dev_sxid_isra_0(&local_88,param_2,param_4);
    __src = local_70;
    __src_00 = local_80;
    uVar2 = (uint)local_88;
    uVar3 = (undefined4)local_78;
    lVar6 = trace_event_buffer_reserve(&local_68,param_1,(long)iVar5 + 0x14);
    if (lVar6 != 0) {
      *(uint *)(lVar6 + 8) = uVar2;
      *(undefined4 *)(lVar6 + 0x10) = uVar3;
      sVar8 = (size_t)(int)((uVar2 >> 0x10) - 1);
      if (__src_00 == (char *)0x0) {
        __src_00 = "(null)";
      }
      pvVar7 = memcpy((void *)((ulong)(uVar2 & 0xffff) + lVar6),__src_00,sVar8);
      *(undefined1 *)((long)pvVar7 + sVar8) = 0;
      sVar8 = (size_t)(int)((*(uint *)(lVar6 + 0x10) >> 0x10) - 1);
      if (__src == (char *)0x0) {
        __src = "(null)";
      }
      pvVar7 = memcpy((void *)((ulong)(*(uint *)(lVar6 + 0x10) & 0xffff) + lVar6),__src,sVar8);
      *(undefined1 *)((long)pvVar7 + sVar8) = 0;
      *(undefined4 *)(lVar6 + 0xc) = param_3;
      trace_event_buffer_commit(&local_68);
    }
  }
  piVar1 = (int *)(&__preempt_count + in_GS_OFFSET);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    __SCT__preempt_schedule_notrace();
  }
  if (local_38 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ===== 0012f660 __pfx_perf_trace_nvswitch_dev_sxid =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012f80a) */

void __pfx_perf_trace_nvswitch_dev_sxid
               (long param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  int *piVar1;
  int iVar2;
  long lVar3;
  void *pvVar4;
  long *plVar5;
  size_t sVar6;
  long in_GS_OFFSET;
  undefined8 unaff_retaddr;
  undefined4 uStack_64;
  long lStack_60;
  uint auStack_58 [2];
  char *pcStack_50;
  undefined4 uStack_48;
  char *pcStack_40;
  long lStack_38;
  
  lStack_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  *(int *)(&__preempt_count + in_GS_OFFSET) = *(int *)(&__preempt_count + in_GS_OFFSET) + 1;
  lStack_60 = 0;
  uStack_64 = 0;
  iVar2 = trace_event_get_offsets_nvswitch_dev_sxid_isra_0(auStack_58,param_2,param_4);
  plVar5 = (long *)(*(long *)(param_1 + 0x60) + *(long *)(&this_cpu_off + in_GS_OFFSET));
  if ((*(long *)(param_1 + 0x68) != 0) || (*plVar5 != 0)) {
    iVar2 = (iVar2 + 0x1fU & 0xfffffff8) - 4;
    lVar3 = perf_trace_buf_alloc(iVar2,&lStack_60,&uStack_64);
    if (lVar3 != 0) {
      *(undefined8 *)(lStack_60 + 0x80) = unaff_retaddr;
      *(undefined2 *)(lStack_60 + 0x88) = 0x10;
      *(undefined1 **)(lStack_60 + 0x98) = &stack0xfffffffffffffff8;
      *(undefined8 *)(lStack_60 + 0x90) = 0;
      *(uint *)(lVar3 + 8) = auStack_58[0];
      *(undefined4 *)(lVar3 + 0x10) = uStack_48;
      sVar6 = (size_t)(int)((auStack_58[0] >> 0x10) - 1);
      if (pcStack_50 == (char *)0x0) {
        pcStack_50 = "(null)";
      }
      pvVar4 = memcpy((void *)((ulong)(auStack_58[0] & 0xffff) + lVar3),pcStack_50,sVar6);
      *(undefined1 *)((long)pvVar4 + sVar6) = 0;
      sVar6 = (size_t)(int)((*(uint *)(lVar3 + 0x10) >> 0x10) - 1);
      if (pcStack_40 == (char *)0x0) {
        pcStack_40 = "(null)";
      }
      pvVar4 = memcpy((void *)((ulong)(*(uint *)(lVar3 + 0x10) & 0xffff) + lVar3),pcStack_40,sVar6);
      *(undefined1 *)((long)pvVar4 + sVar6) = 0;
      *(undefined4 *)(lVar3 + 0xc) = param_3;
      perf_trace_run_bpf_submit(lVar3,iVar2,uStack_64,param_1,1,lStack_60,plVar5,0);
    }
  }
  piVar1 = (int *)(&__preempt_count + in_GS_OFFSET);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    __SCT__preempt_schedule_notrace();
  }
  if (lStack_38 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ===== 0012f670 perf_trace_nvswitch_dev_sxid =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012f80a) */

void perf_trace_nvswitch_dev_sxid
               (long param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  int *piVar1;
  int iVar2;
  long lVar3;
  void *pvVar4;
  long *plVar5;
  size_t sVar6;
  long in_GS_OFFSET;
  undefined8 unaff_retaddr;
  undefined4 local_64;
  long local_60;
  uint local_58 [2];
  char *local_50;
  undefined4 local_48;
  char *local_40;
  long local_38;
  
  local_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  *(int *)(&__preempt_count + in_GS_OFFSET) = *(int *)(&__preempt_count + in_GS_OFFSET) + 1;
  local_60 = 0;
  local_64 = 0;
  iVar2 = trace_event_get_offsets_nvswitch_dev_sxid_isra_0(local_58,param_2,param_4);
  plVar5 = (long *)(*(long *)(param_1 + 0x60) + *(long *)(&this_cpu_off + in_GS_OFFSET));
  if ((*(long *)(param_1 + 0x68) != 0) || (*plVar5 != 0)) {
    iVar2 = (iVar2 + 0x1fU & 0xfffffff8) - 4;
    lVar3 = perf_trace_buf_alloc(iVar2,&local_60,&local_64);
    if (lVar3 != 0) {
      *(undefined8 *)(local_60 + 0x80) = unaff_retaddr;
      *(undefined2 *)(local_60 + 0x88) = 0x10;
      *(undefined1 **)(local_60 + 0x98) = &stack0xfffffffffffffff8;
      *(undefined8 *)(local_60 + 0x90) = 0;
      *(uint *)(lVar3 + 8) = local_58[0];
      *(undefined4 *)(lVar3 + 0x10) = local_48;
      sVar6 = (size_t)(int)((local_58[0] >> 0x10) - 1);
      if (local_50 == (char *)0x0) {
        local_50 = "(null)";
      }
      pvVar4 = memcpy((void *)((ulong)(local_58[0] & 0xffff) + lVar3),local_50,sVar6);
      *(undefined1 *)((long)pvVar4 + sVar6) = 0;
      sVar6 = (size_t)(int)((*(uint *)(lVar3 + 0x10) >> 0x10) - 1);
      if (local_40 == (char *)0x0) {
        local_40 = "(null)";
      }
      pvVar4 = memcpy((void *)((ulong)(*(uint *)(lVar3 + 0x10) & 0xffff) + lVar3),local_40,sVar6);
      *(undefined1 *)((long)pvVar4 + sVar6) = 0;
      *(undefined4 *)(lVar3 + 0xc) = param_3;
      perf_trace_run_bpf_submit(lVar3,iVar2,local_64,param_1,1,local_60,plVar5,0);
    }
  }
  piVar1 = (int *)(&__preempt_count + in_GS_OFFSET);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    __SCT__preempt_schedule_notrace();
  }
  if (local_38 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ===== 0012f840 __pfx_nvswitch_ioctl_state_start =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012f877) */
/* WARNING: Removing unreachable block (ram,0x0012f8f8) */

undefined4 __pfx_nvswitch_ioctl_state_start(long *param_1,uint param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  ulong uVar5;
  
  *param_1 = 0;
  uVar5 = (ulong)((int)param_2 >> 0x10 & 0x3fff);
  param_1[1] = uVar5;
  if (((int)param_2 >> 0x10 & 0x3fffU) == 0) {
    return 0;
  }
  lVar4 = __kmalloc_noprof(uVar5,0xdc0);
  *param_1 = lVar4;
  if (lVar4 == 0) {
    uVar3 = 0xfffffff4;
  }
  else {
    if ((param_2 & 0x40000000) == 0) {
      return 0;
    }
    uVar5 = param_1[1];
    if (0x7fffffff < uVar5) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    __check_object_size(lVar4,uVar5,0);
    iVar2 = _copy_from_user(lVar4,param_3,uVar5);
    if (iVar2 == 0) {
      return 0;
    }
    uVar3 = 0xfffffff2;
  }
  kfree(*param_1);
  *param_1 = 0;
  return uVar3;
}


// ===== 0012f850 nvswitch_ioctl_state_start =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012f877) */
/* WARNING: Removing unreachable block (ram,0x0012f8f8) */

undefined4 nvswitch_ioctl_state_start(long *param_1,uint param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  ulong uVar5;
  
  *param_1 = 0;
  uVar5 = (ulong)((int)param_2 >> 0x10 & 0x3fff);
  param_1[1] = uVar5;
  if (((int)param_2 >> 0x10 & 0x3fffU) == 0) {
    return 0;
  }
  lVar4 = __kmalloc_noprof(uVar5,0xdc0);
  *param_1 = lVar4;
  if (lVar4 == 0) {
    uVar3 = 0xfffffff4;
  }
  else {
    if ((param_2 & 0x40000000) == 0) {
      return 0;
    }
    uVar5 = param_1[1];
    if (0x7fffffff < uVar5) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    __check_object_size(lVar4,uVar5,0);
    iVar2 = _copy_from_user(lVar4,param_3,uVar5);
    if (iVar2 == 0) {
      return 0;
    }
    uVar3 = 0xfffffff2;
  }
  kfree(*param_1);
  *param_1 = 0;
  return uVar3;
}


// ===== 0012f930 __pfx_nvswitch_device_unlocked_ioctl =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012fa43) */

long __pfx_nvswitch_device_unlocked_ioctl(long param_1,uint param_2,undefined8 param_3)

{
  ulong uVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  long in_GS_OFFSET;
  ulong uStack_50;
  undefined8 uStack_48;
  long lStack_40;
  
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if ((param_2 & 0xff00) != 0x6400) {
    lVar4 = -0x16;
    goto LAB_0012fa2c;
  }
  lVar4 = **(long **)(param_1 + 0x18);
  iVar3 = mutex_lock_interruptible(lVar4 + 0x38);
  if (iVar3 != 0) {
    lVar4 = (long)iVar3;
    goto LAB_0012fa2c;
  }
  if (*(char *)(lVar4 + 0x120) == '\0') {
    uStack_50 = uStack_50 & 0xffffffff00000000;
    iVar3 = nvswitch_lib_read_fabric_state(*(undefined8 *)(lVar4 + 0x50),&uStack_50,0,0);
    if (iVar3 == 0) {
      if ((int)uStack_50 == 3) {
        _printk(&DAT_00df17c8,lVar4);
        goto LAB_00529f00;
      }
    }
    else {
      _printk(&DAT_00df1628,lVar4,iVar3);
    }
    uStack_50 = 0;
    uStack_48 = 0;
    iVar3 = nvswitch_ioctl_state_start(&uStack_50,param_2,param_3);
    uVar2 = uStack_48;
    uVar1 = uStack_50;
    if (iVar3 == 0) {
      iVar3 = nvswitch_lib_ctrl(*(undefined8 *)(lVar4 + 0x50),param_2 & 0xff,uStack_50,uStack_48,
                                *(undefined8 *)(param_1 + 0x18));
      uVar5 = 0;
      do {
        if ((iVar3 == (&nvswitch_status_map)[uVar5 * 2]) ||
           ((&nvswitch_status_map)[uVar5 * 2] == -iVar3)) {
          iVar3 = *(int *)(&DAT_005a6fa4 + (uVar5 & 0xffffffff) * 8);
          if (iVar3 == 0) {
            iVar3 = nvswitch_ioctl_state_sync_isra_0(uVar1,uVar2,param_2,param_3);
          }
          goto LAB_0012fa93;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 != 0xc);
      iVar3 = -5;
LAB_0012fa93:
      kfree(uVar1);
    }
  }
  else {
    _printk(&DAT_00db0752,lVar4);
LAB_00529f00:
    iVar3 = -0x13;
  }
  mutex_unlock(lVar4 + 0x38);
  lVar4 = (long)iVar3;
LAB_0012fa2c:
  if (lStack_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return lVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0012f940 nvswitch_device_unlocked_ioctl =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012fa43) */

long nvswitch_device_unlocked_ioctl(long param_1,uint param_2,undefined8 param_3)

{
  ulong uVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  long in_GS_OFFSET;
  ulong local_50;
  undefined8 local_48;
  long local_40;
  
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if ((param_2 & 0xff00) != 0x6400) {
    lVar4 = -0x16;
    goto LAB_0012fa2c;
  }
  lVar4 = **(long **)(param_1 + 0x18);
  iVar3 = mutex_lock_interruptible(lVar4 + 0x38);
  if (iVar3 != 0) {
    lVar4 = (long)iVar3;
    goto LAB_0012fa2c;
  }
  if (*(char *)(lVar4 + 0x120) == '\0') {
    local_50 = local_50 & 0xffffffff00000000;
    iVar3 = nvswitch_lib_read_fabric_state(*(undefined8 *)(lVar4 + 0x50),&local_50,0,0);
    if (iVar3 == 0) {
      if ((int)local_50 == 3) {
        _printk(&DAT_00df17c8,lVar4);
        goto LAB_00529f00;
      }
    }
    else {
      _printk(&DAT_00df1628,lVar4,iVar3);
    }
    local_50 = 0;
    local_48 = 0;
    iVar3 = nvswitch_ioctl_state_start(&local_50,param_2,param_3);
    uVar2 = local_48;
    uVar1 = local_50;
    if (iVar3 == 0) {
      iVar3 = nvswitch_lib_ctrl(*(undefined8 *)(lVar4 + 0x50),param_2 & 0xff,local_50,local_48,
                                *(undefined8 *)(param_1 + 0x18));
      uVar5 = 0;
      do {
        if ((iVar3 == (&nvswitch_status_map)[uVar5 * 2]) ||
           ((&nvswitch_status_map)[uVar5 * 2] == -iVar3)) {
          iVar3 = *(int *)(&DAT_005a6fa4 + (uVar5 & 0xffffffff) * 8);
          if (iVar3 == 0) {
            iVar3 = nvswitch_ioctl_state_sync_isra_0(uVar1,uVar2,param_2,param_3);
          }
          goto LAB_0012fa93;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 != 0xc);
      iVar3 = -5;
LAB_0012fa93:
      kfree(uVar1);
    }
  }
  else {
    _printk(&DAT_00db0752,lVar4);
LAB_00529f00:
    iVar3 = -0x13;
  }
  mutex_unlock(lVar4 + 0x38);
  lVar4 = (long)iVar3;
LAB_0012fa2c:
  if (local_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return lVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0012fb20 __pfx_nvswitch_ctl_unlocked_ioctl =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012fba2) */

long __pfx_nvswitch_ctl_unlocked_ioctl(undefined8 param_1,uint param_2,undefined8 param_3)

{
  int *piVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  int iVar4;
  undefined8 *puVar5;
  ulong uVar6;
  long lVar7;
  int *piVar8;
  long in_GS_OFFSET;
  int *piStack_48;
  undefined8 uStack_40;
  long lStack_38;
  
  lStack_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if ((param_2 & 0xff00) != 0x6300) {
    lVar7 = -0x16;
    goto LAB_0012fb83;
  }
  iVar4 = mutex_lock_interruptible(&DAT_005478a0);
  if (iVar4 != 0) {
    lVar7 = (long)iVar4;
    goto LAB_0012fb83;
  }
  piStack_48 = (int *)0x0;
  uStack_40 = 0;
  iVar4 = nvswitch_ioctl_state_start(&piStack_48,param_2,param_3);
  uVar2 = uStack_40;
  piVar1 = piStack_48;
  if (iVar4 == 0) {
    iVar4 = (int)uStack_40;
    if ((char)param_2 == '\x02') {
      if (iVar4 != 0x81) goto LAB_0012fd1e;
      piVar8 = piStack_48 + 0x10;
      *(undefined1 *)(piStack_48 + 0x20) = 0;
      *(undefined1 *)((long)piStack_48 + 0x3f) = 0;
      iVar4 = nvswitch_lib_check_api_version(piStack_48,piVar8,0x40);
      if (iVar4 == 0) {
        *(undefined1 *)(piVar1 + 0x20) = 1;
      }
      else {
        if (iVar4 != -0xd) {
          uVar6 = 0;
          do {
            if ((iVar4 == (&nvswitch_status_map)[uVar6 * 2]) ||
               ((&nvswitch_status_map)[uVar6 * 2] == -iVar4)) {
              iVar4 = *(int *)(&DAT_005a6fa4 + (uVar6 & 0xffffffff) * 8);
              if (iVar4 == 0) goto LAB_0012fca1;
              goto LAB_0012fe8b;
            }
            uVar6 = uVar6 + 1;
          } while (uVar6 != 0xc);
          iVar4 = -5;
LAB_0012fe8b:
          lVar7 = (long)iVar4;
          goto LAB_0012fcbc;
        }
        _printk(&DAT_00df17f8,piVar8,piVar1);
      }
LAB_0012fca1:
      iVar4 = nvswitch_ioctl_state_sync_isra_0(piVar1,uVar2,param_2,param_3);
      lVar7 = (long)iVar4;
    }
    else {
      if ((param_2 & 0xff) == 3) {
        if (iVar4 == 0xe04) {
          if ((undefined8 **)DAT_005478b8 == &DAT_005478b8) {
            iVar4 = 0;
          }
          else {
            piVar8 = piStack_48 + 2;
            iVar4 = 0;
            puVar5 = DAT_005478b8;
            do {
              piVar1[(long)iVar4 * 0xe + 1] = *(int *)(puVar5 + -0x1e);
              *(undefined8 *)piVar8 = *(undefined8 *)((long)puVar5 + -0xec);
              *(undefined8 *)(piVar8 + 2) = *(undefined8 *)((long)puVar5 + -0xe4);
              piVar1[(long)iVar4 * 0xe + 6] = **(int **)(*(long *)(puVar5[-2] + 0x10) + 200);
              piVar1[(long)iVar4 * 0xe + 7] = (uint)*(byte *)(*(long *)(puVar5[-2] + 0x10) + 0xd8);
              piVar1[(long)iVar4 * 0xe + 8] = *(uint *)(puVar5[-2] + 0x38) >> 3 & 0x1f;
              piVar1[(long)iVar4 * 0xe + 9] = *(uint *)(puVar5[-2] + 0x38) & 7;
              piVar1[(long)iVar4 * 0xe + 0xd] = *(int *)((long)puVar5 + 0x14);
              if (puVar5[-0x18] != 0) {
                mutex_lock(puVar5 + -0x1b);
                nvswitch_lib_read_fabric_state(puVar5[-0x18],piVar8 + 9,piVar8 + 10,piVar8 + 8);
                uVar3 = nvswitch_lib_is_tnvl_enabled(puVar5[-0x18]);
                *(undefined1 *)(piVar1 + (long)iVar4 * 0xe + 0xe) = uVar3;
                mutex_unlock(puVar5 + -0x1b);
              }
              puVar5 = (undefined8 *)*puVar5;
              iVar4 = iVar4 + 1;
              piVar8 = piVar8 + 0xe;
            } while ((undefined8 **)puVar5 != &DAT_005478b8);
          }
          *piVar1 = iVar4;
          goto LAB_0012fca1;
        }
      }
      else if (((param_2 & 0xff) == 1) && (iVar4 == 0x504)) {
        iVar4 = 0;
        puVar5 = DAT_005478b8;
        if ((undefined8 **)DAT_005478b8 == &DAT_005478b8) {
          iVar4 = 0;
        }
        else {
          do {
            lVar7 = (long)iVar4;
            iVar4 = iVar4 + 1;
            piStack_48[lVar7 * 5 + 1] = *(int *)(puVar5 + -0x1e);
            piStack_48[lVar7 * 5 + 2] = **(int **)(*(long *)(puVar5[-2] + 0x10) + 200);
            piStack_48[lVar7 * 5 + 3] = (uint)*(byte *)(*(long *)(puVar5[-2] + 0x10) + 0xd8);
            piStack_48[lVar7 * 5 + 4] = *(uint *)(puVar5[-2] + 0x38) >> 3 & 0x1f;
            piStack_48[lVar7 * 5 + 5] = *(uint *)(puVar5[-2] + 0x38) & 7;
            puVar5 = (undefined8 *)*puVar5;
          } while ((undefined8 **)puVar5 != &DAT_005478b8);
        }
        *piStack_48 = iVar4;
        goto LAB_0012fca1;
      }
LAB_0012fd1e:
      lVar7 = -0x16;
    }
LAB_0012fcbc:
    kfree(piVar1);
  }
  else {
    lVar7 = (long)iVar4;
  }
  mutex_unlock(&DAT_005478a0);
LAB_0012fb83:
  if (lStack_38 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar7;
}


// ===== 0012fb30 nvswitch_ctl_unlocked_ioctl =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012fba2) */

long nvswitch_ctl_unlocked_ioctl(undefined8 param_1,uint param_2,undefined8 param_3)

{
  int *piVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  int iVar4;
  undefined8 *puVar5;
  ulong uVar6;
  long lVar7;
  int *piVar8;
  long in_GS_OFFSET;
  int *local_48;
  undefined8 local_40;
  long local_38;
  
  local_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if ((param_2 & 0xff00) != 0x6300) {
    lVar7 = -0x16;
    goto LAB_0012fb83;
  }
  iVar4 = mutex_lock_interruptible(&DAT_005478a0);
  if (iVar4 != 0) {
    lVar7 = (long)iVar4;
    goto LAB_0012fb83;
  }
  local_48 = (int *)0x0;
  local_40 = 0;
  iVar4 = nvswitch_ioctl_state_start(&local_48,param_2,param_3);
  uVar2 = local_40;
  piVar1 = local_48;
  if (iVar4 == 0) {
    iVar4 = (int)local_40;
    if ((char)param_2 == '\x02') {
      if (iVar4 != 0x81) goto LAB_0012fd1e;
      piVar8 = local_48 + 0x10;
      *(undefined1 *)(local_48 + 0x20) = 0;
      *(undefined1 *)((long)local_48 + 0x3f) = 0;
      iVar4 = nvswitch_lib_check_api_version(local_48,piVar8,0x40);
      if (iVar4 == 0) {
        *(undefined1 *)(piVar1 + 0x20) = 1;
      }
      else {
        if (iVar4 != -0xd) {
          uVar6 = 0;
          do {
            if ((iVar4 == (&nvswitch_status_map)[uVar6 * 2]) ||
               ((&nvswitch_status_map)[uVar6 * 2] == -iVar4)) {
              iVar4 = *(int *)(&DAT_005a6fa4 + (uVar6 & 0xffffffff) * 8);
              if (iVar4 == 0) goto LAB_0012fca1;
              goto LAB_0012fe8b;
            }
            uVar6 = uVar6 + 1;
          } while (uVar6 != 0xc);
          iVar4 = -5;
LAB_0012fe8b:
          lVar7 = (long)iVar4;
          goto LAB_0012fcbc;
        }
        _printk(&DAT_00df17f8,piVar8,piVar1);
      }
LAB_0012fca1:
      iVar4 = nvswitch_ioctl_state_sync_isra_0(piVar1,uVar2,param_2,param_3);
      lVar7 = (long)iVar4;
    }
    else {
      if ((param_2 & 0xff) == 3) {
        if (iVar4 == 0xe04) {
          if ((undefined8 **)DAT_005478b8 == &DAT_005478b8) {
            iVar4 = 0;
          }
          else {
            piVar8 = local_48 + 2;
            iVar4 = 0;
            puVar5 = DAT_005478b8;
            do {
              piVar1[(long)iVar4 * 0xe + 1] = *(int *)(puVar5 + -0x1e);
              *(undefined8 *)piVar8 = *(undefined8 *)((long)puVar5 + -0xec);
              *(undefined8 *)(piVar8 + 2) = *(undefined8 *)((long)puVar5 + -0xe4);
              piVar1[(long)iVar4 * 0xe + 6] = **(int **)(*(long *)(puVar5[-2] + 0x10) + 200);
              piVar1[(long)iVar4 * 0xe + 7] = (uint)*(byte *)(*(long *)(puVar5[-2] + 0x10) + 0xd8);
              piVar1[(long)iVar4 * 0xe + 8] = *(uint *)(puVar5[-2] + 0x38) >> 3 & 0x1f;
              piVar1[(long)iVar4 * 0xe + 9] = *(uint *)(puVar5[-2] + 0x38) & 7;
              piVar1[(long)iVar4 * 0xe + 0xd] = *(int *)((long)puVar5 + 0x14);
              if (puVar5[-0x18] != 0) {
                mutex_lock(puVar5 + -0x1b);
                nvswitch_lib_read_fabric_state(puVar5[-0x18],piVar8 + 9,piVar8 + 10,piVar8 + 8);
                uVar3 = nvswitch_lib_is_tnvl_enabled(puVar5[-0x18]);
                *(undefined1 *)(piVar1 + (long)iVar4 * 0xe + 0xe) = uVar3;
                mutex_unlock(puVar5 + -0x1b);
              }
              puVar5 = (undefined8 *)*puVar5;
              iVar4 = iVar4 + 1;
              piVar8 = piVar8 + 0xe;
            } while ((undefined8 **)puVar5 != &DAT_005478b8);
          }
          *piVar1 = iVar4;
          goto LAB_0012fca1;
        }
      }
      else if (((param_2 & 0xff) == 1) && (iVar4 == 0x504)) {
        iVar4 = 0;
        puVar5 = DAT_005478b8;
        if ((undefined8 **)DAT_005478b8 == &DAT_005478b8) {
          iVar4 = 0;
        }
        else {
          do {
            lVar7 = (long)iVar4;
            iVar4 = iVar4 + 1;
            local_48[lVar7 * 5 + 1] = *(int *)(puVar5 + -0x1e);
            local_48[lVar7 * 5 + 2] = **(int **)(*(long *)(puVar5[-2] + 0x10) + 200);
            local_48[lVar7 * 5 + 3] = (uint)*(byte *)(*(long *)(puVar5[-2] + 0x10) + 0xd8);
            local_48[lVar7 * 5 + 4] = *(uint *)(puVar5[-2] + 0x38) >> 3 & 0x1f;
            local_48[lVar7 * 5 + 5] = *(uint *)(puVar5[-2] + 0x38) & 7;
            puVar5 = (undefined8 *)*puVar5;
          } while ((undefined8 **)puVar5 != &DAT_005478b8);
        }
        *local_48 = iVar4;
        goto LAB_0012fca1;
      }
LAB_0012fd1e:
      lVar7 = -0x16;
    }
LAB_0012fcbc:
    kfree(piVar1);
  }
  else {
    lVar7 = (long)iVar4;
  }
  mutex_unlock(&DAT_005478a0);
LAB_0012fb83:
  if (local_38 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar7;
}


// ===== 0012fef0 __pfx_nvswitch_probe =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ff52) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __pfx_nvswitch_probe(long param_1)

{
  char *__s;
  char *pcVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined8 *puVar5;
  char *__s_00;
  long lVar6;
  long lVar7;
  long lVar8;
  int iVar9;
  undefined4 uVar10;
  ulong uVar11;
  long in_GS_OFFSET;
  uint uStack_4c;
  ulong uStack_48;
  long lStack_40;
  
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  cVar2 = nvswitch_lib_validate_device_id(*(undefined2 *)(param_1 + 0x3e));
  if (cVar2 == '\0') {
    iVar3 = -0x16;
    goto LAB_0012ff38;
  }
  _printk(&DAT_00df1840,**(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
          *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),*(uint *)(param_1 + 0x38) >> 3 & 0x1f,
          *(uint *)(param_1 + 0x38) & 7,*(undefined2 *)(param_1 + 0x3c),
          *(undefined2 *)(param_1 + 0x3e),*(undefined4 *)(param_1 + 0x44));
  mutex_lock(&DAT_005478a0);
  uVar11 = 0;
  while (iVar9 = (int)uVar11, puVar5 = DAT_005478b8, (undefined8 **)DAT_005478b8 != &DAT_005478b8) {
    while (*(int *)(puVar5 + -0x1e) != iVar9) {
      puVar5 = (undefined8 *)*puVar5;
      if ((undefined8 **)puVar5 == &DAT_005478b8) goto LAB_00529feb;
    }
    uVar11 = (ulong)(iVar9 + 1U);
    if (iVar9 + 1U == 0x40) goto code_r0x00529fbf;
  }
LAB_00529feb:
  __s_00 = (char *)__kmalloc_cache_noprof(_trace_event_buffer_reserve,0xdc0,0x150);
  if (__s_00 == (char *)0x0) {
    iVar3 = -0xc;
    goto LAB_00529fc4;
  }
  mutex_init_generic(__s_00 + 0x38);
  __init_waitqueue_head(__s_00 + 0x58,"&nvswitch_dev->wait_q_errors",&nvswitch);
  __init_waitqueue_head(__s_00 + 0xe8,"&nvswitch_dev->wait_q_shutdown",&nvswitch);
  snprintf(__s_00,0x14,"nvidia-nvswitch%d",uVar11);
  __s = __s_00 + 0x14;
  snprintf(__s,10,"nvswi%d",uVar11);
  iVar3 = pci_enable_device(param_1);
  if (iVar3 != 0) {
    _printk(&DAT_00df18c8,__s_00,iVar3);
    goto LAB_0052a0ad;
  }
  pci_set_master(param_1);
  iVar3 = pci_request_regions(param_1,__s_00);
  if (iVar3 != 0) {
    _printk(&DAT_00df18f0,__s_00,iVar3);
    goto LAB_0052a0f3;
  }
  lVar6 = pci_iomap(param_1,0,0);
  *(long *)(__s_00 + 0x70) = lVar6;
  if (lVar6 == 0) {
    _printk(&DAT_00df1920,__s_00,0xfffffff4);
    iVar3 = -0xc;
    goto LAB_0052a139;
  }
  pcVar1 = __s_00 + 0x140;
  lVar6 = *(long *)(param_1 + 0x10);
  *(int *)(__s_00 + 0x20) = iVar9;
  *(char **)(__s_00 + 0x140) = pcVar1;
  *(char **)(__s_00 + 0x148) = pcVar1;
  uVar4 = *(uint *)(param_1 + 0x38);
  *(long *)(__s_00 + 0x100) = param_1;
  iVar3 = nvswitch_lib_register_device
                    (**(undefined2 **)(lVar6 + 200),*(undefined1 *)(lVar6 + 0xd8),uVar4 >> 3 & 0x1f,
                     uVar4 & 7,*(undefined2 *)(param_1 + 0x3e),param_1,uVar11,__s_00 + 0x50);
  if (iVar3 != 0) {
    _printk(&DAT_00df1948,__s_00,iVar3);
    iVar3 = -0x13;
    goto LAB_0052a1ca;
  }
  uStack_48 = 0;
  lVar6 = *(long *)(__s_00 + 0x100);
  uStack_4c = 0;
  nvswitch_lib_get_device_info(*(undefined8 *)(__s_00 + 0x50),&uStack_48);
  *(undefined4 *)(uStack_48 + 0x30) = 0x10;
  pci_read_config_dword(lVar6,0x10,&uStack_4c);
  *(ulong *)(uStack_48 + 0x18) = (ulong)uStack_4c & 0xfffffffffffffff0;
  if ((*(byte *)(lVar6 + 0x408) & 4) != 0) {
    pci_read_config_dword(lVar6,*(int *)(uStack_48 + 0x30) + 4,&uStack_4c);
    *(ulong *)(uStack_48 + 0x18) = *(ulong *)(uStack_48 + 0x18) | (ulong)uStack_4c << 0x20;
  }
  lVar7 = *(long *)(lVar6 + 0x3f0);
  *(long *)(uStack_48 + 0x20) = lVar7;
  lVar8 = 0;
  if (*(long *)(lVar6 + 0x3f8) != 0) {
    lVar8 = (*(long *)(lVar6 + 0x3f8) + 1) - lVar7;
  }
  *(long *)(uStack_48 + 0x28) = lVar8;
  *(undefined8 *)(uStack_48 + 0x38) = *(undefined8 *)(__s_00 + 0x70);
  iVar3 = nvswitch_lib_initialize_device(*(undefined8 *)(__s_00 + 0x50));
  if (iVar3 == 0) {
    nvswitch_lib_get_uuid(*(undefined8 *)(__s_00 + 0x50),__s_00 + 0x24);
    iVar3 = nvswitch_lib_get_bios_version(*(undefined8 *)(__s_00 + 0x50));
    if (iVar3 != 0) {
      __s_00[0x128] = '\0';
      __s_00[0x129] = '\0';
      __s_00[0x12a] = '\0';
      __s_00[299] = '\0';
      __s_00[300] = '\0';
      __s_00[0x12d] = '\0';
      __s_00[0x12e] = '\0';
      __s_00[0x12f] = '\0';
    }
    iVar3 = nvswitch_lib_get_physid(*(undefined8 *)(__s_00 + 0x50),__s_00 + 0x124);
    if (iVar3 != 0) {
      __s_00[0x124] = -1;
      __s_00[0x125] = -1;
      __s_00[0x126] = -1;
      __s_00[0x127] = -1;
    }
    lVar6 = *(long *)(__s_00 + 0x100);
    uStack_48 = 0;
    cVar2 = pci_find_capability(lVar6,0x11);
    if (cVar2 != '\0') {
      LOCK();
      uStack_48 = uStack_48 | 2;
      UNLOCK();
    }
    cVar2 = pci_find_capability(lVar6,5);
    if (cVar2 != '\0') {
      LOCK();
      uStack_48 = uStack_48 | 4;
      UNLOCK();
    }
    iVar3 = nvswitch_lib_use_pin_irq(*(undefined8 *)(__s_00 + 0x50));
    if (iVar3 != 0) {
      LOCK();
      uStack_48 = uStack_48 | 8;
      UNLOCK();
    }
    __s_00[0x138] = '\0';
    if ((uStack_48 & 4) == 0) {
LAB_0052a3db:
      if ((uStack_48 & 8) != 0) {
        __s_00[0x138] = '\x03';
        _printk(&DAT_00db0801,__s_00);
        if (__s_00[0x138] != '\0') {
          uVar10 = 0x80;
          goto LAB_0052a49b;
        }
      }
      _printk(&DAT_00df1998,__s_00);
      if ((uStack_48 & 2) != 0) {
        _printk(&DAT_00db0816,__s_00);
      }
      if ((uStack_48 & 4) != 0) {
        _printk(&DAT_00db0823,__s_00);
      }
      if ((uStack_48 & 8) != 0) {
        _printk(&DAT_00db082e,__s_00);
      }
      iVar3 = -0x16;
    }
    else {
      iVar3 = pci_enable_msi(*(undefined8 *)(__s_00 + 0x100));
      if (iVar3 == 0) {
        __s_00[0x138] = '\x02';
        _printk(&DAT_00db07f0,__s_00);
      }
      uVar10 = 0;
      if (__s_00[0x138] == '\0') goto LAB_0052a3db;
LAB_0052a49b:
      iVar3 = request_threaded_irq
                        (*(undefined4 *)(lVar6 + 0x3ec),nvswitch_isr_pending,nvswitch_isr_thread,
                         uVar10,__s,__s_00);
      if (iVar3 == 0) {
        cVar2 = nvswitch_is_device_blacklisted(__s_00);
        if (cVar2 == '\0') {
          nvswitch_lib_enable_interrupts(*(undefined8 *)(__s_00 + 0x50));
        }
        else {
          _printk(&DAT_00df19e8,__s_00);
        }
        cVar2 = nvswitch_is_device_blacklisted(__s_00);
        if (cVar2 != '\0') {
          nvswitch_lib_post_init_blacklist_device(*(undefined8 *)(__s_00 + 0x50));
          goto LAB_0052a520;
        }
        mutex_lock(__s_00 + 0x38);
        uStack_48 = uStack_48 & 0xffffffff00000000;
        cVar2 = nvswitch_lib_is_i2c_supported(*(undefined8 *)(__s_00 + 0x50));
        if (cVar2 == '\0') goto LAB_0052a5ae;
        iVar3 = nvswitch_lib_get_valid_ports_mask(*(undefined8 *)(__s_00 + 0x50),&uStack_48);
        if (iVar3 != 0) {
          _printk(&DAT_00df1a10);
          goto LAB_0052a5e7;
        }
        if ((uint)uStack_48 != 0) {
          iVar3 = 0;
          uVar4 = (uint)uStack_48;
          while( true ) {
            for (; (uVar4 & 1) == 0; uVar4 = uVar4 >> 1) {
              iVar3 = iVar3 + 1;
            }
            lVar6 = nvswitch_i2c_add_adapter(__s_00,iVar3);
            if (lVar6 != 0) {
              lVar7 = _nvswitch_os_malloc(0x18);
              if (lVar7 == 0) {
                _printk(&DAT_00df1a38);
                nvswitch_i2c_del_adapter(lVar6);
              }
              else {
                *(long *)(lVar7 + 0x10) = lVar6;
                __list_add(lVar7,*(undefined8 *)(__s_00 + 0x148),pcVar1);
              }
            }
            uVar4 = uVar4 >> 1;
            if (uVar4 == 0) break;
            iVar3 = iVar3 + 1;
          }
        }
LAB_0052a5ae:
        iVar3 = nvswitch_lib_post_init_device(*(undefined8 *)(__s_00 + 0x50));
        if (iVar3 == 0) {
          mutex_unlock(__s_00 + 0x38);
LAB_0052a520:
          iVar3 = nv_kthread_q_init(__s_00 + 0x78,__s);
          if (iVar3 == 0) {
            __s_00[0xe0] = '\x01';
            __s_00[0xe1] = '\0';
            __s_00[0xe2] = '\0';
            __s_00[0xe3] = '\0';
            nv_kthread_q_item_init(__s_00 + 0xc0,nvswitch_task_dispatch,__s_00);
            iVar3 = nv_kthread_q_schedule_q_item(__s_00 + 0x78,__s_00 + 0xc0);
            if (iVar3 != 0) {
              *(char **)(param_1 + 0x148) = __s_00;
              nvswitch_procfs_device_add(__s_00);
              __list_add(__s_00 + 0x110,_DAT_005478c0,&DAT_005478b8);
              LOCK();
              DAT_0054789c = DAT_0054789c + 1;
              UNLOCK();
              mutex_unlock(&DAT_005478a0);
              iVar3 = 0;
              goto LAB_0012ff38;
            }
            _printk(&DAT_00df1a88,__s_00);
            nvswitch_deinit_background_tasks(__s_00);
            iVar3 = -0x13;
          }
          else {
            _printk(&DAT_00df1a60,__s_00);
          }
          _printk(&DAT_00df1ab0,__s_00,iVar3);
        }
        else {
LAB_0052a5e7:
          mutex_unlock(__s_00 + 0x38);
          _printk(&DAT_00df1ae8,__s_00,0xffffffed);
          iVar3 = -0x13;
        }
        nvswitch_deinit_device(__s_00);
LAB_0052a1e1:
        pci_iounmap(param_1,*(undefined8 *)(__s_00 + 0x70));
LAB_0052a139:
        pci_release_regions(param_1);
LAB_0052a0f3:
        pci_clear_master(param_1);
        pci_disable_device(param_1);
LAB_0052a0ad:
        kfree(__s_00);
        goto LAB_00529fc4;
      }
      if (__s_00[0x138] == '\x02') {
        pci_disable_msi(lVar6);
      }
      _printk(&DAT_00db083d,__s_00);
    }
    _printk(&DAT_00df1b18,__s_00,iVar3);
    nvswitch_lib_shutdown_device(*(undefined8 *)(__s_00 + 0x50));
  }
  else {
    _printk(&DAT_00df1970,__s_00,iVar3);
    iVar3 = -0x13;
  }
  nvswitch_lib_unregister_device(*(undefined8 *)(__s_00 + 0x50));
  __s_00[0x50] = '\0';
  __s_00[0x51] = '\0';
  __s_00[0x52] = '\0';
  __s_00[0x53] = '\0';
  __s_00[0x54] = '\0';
  __s_00[0x55] = '\0';
  __s_00[0x56] = '\0';
  __s_00[0x57] = '\0';
LAB_0052a1ca:
  _printk(&DAT_00df1970,__s_00,iVar3);
  goto LAB_0052a1e1;
code_r0x00529fbf:
  iVar3 = -0x22;
LAB_00529fc4:
  mutex_unlock(&DAT_005478a0);
LAB_0012ff38:
  if (lStack_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}


// ===== 0012ff00 nvswitch_probe =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ff52) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int nvswitch_probe(long param_1)

{
  char *__s;
  char *pcVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined8 *puVar5;
  char *__s_00;
  long lVar6;
  long lVar7;
  long lVar8;
  int iVar9;
  undefined4 uVar10;
  ulong uVar11;
  long in_GS_OFFSET;
  uint uStack_4c;
  ulong uStack_48;
  long local_40;
  
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  cVar2 = nvswitch_lib_validate_device_id(*(undefined2 *)(param_1 + 0x3e));
  if (cVar2 == '\0') {
    iVar3 = -0x16;
    goto LAB_0012ff38;
  }
  _printk(&DAT_00df1840,**(undefined4 **)(*(long *)(param_1 + 0x10) + 200),
          *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xd8),*(uint *)(param_1 + 0x38) >> 3 & 0x1f,
          *(uint *)(param_1 + 0x38) & 7,*(undefined2 *)(param_1 + 0x3c),
          *(undefined2 *)(param_1 + 0x3e),*(undefined4 *)(param_1 + 0x44));
  mutex_lock(&DAT_005478a0);
  uVar11 = 0;
  while (iVar9 = (int)uVar11, puVar5 = DAT_005478b8, (undefined8 **)DAT_005478b8 != &DAT_005478b8) {
    while (*(int *)(puVar5 + -0x1e) != iVar9) {
      puVar5 = (undefined8 *)*puVar5;
      if ((undefined8 **)puVar5 == &DAT_005478b8) goto LAB_00529feb;
    }
    uVar11 = (ulong)(iVar9 + 1U);
    if (iVar9 + 1U == 0x40) goto code_r0x00529fbf;
  }
LAB_00529feb:
  __s_00 = (char *)__kmalloc_cache_noprof(_trace_event_buffer_reserve,0xdc0,0x150);
  if (__s_00 == (char *)0x0) {
    iVar3 = -0xc;
    goto LAB_00529fc4;
  }
  mutex_init_generic(__s_00 + 0x38);
  __init_waitqueue_head(__s_00 + 0x58,"&nvswitch_dev->wait_q_errors",&nvswitch);
  __init_waitqueue_head(__s_00 + 0xe8,"&nvswitch_dev->wait_q_shutdown",&nvswitch);
  snprintf(__s_00,0x14,"nvidia-nvswitch%d",uVar11);
  __s = __s_00 + 0x14;
  snprintf(__s,10,"nvswi%d",uVar11);
  iVar3 = pci_enable_device(param_1);
  if (iVar3 != 0) {
    _printk(&DAT_00df18c8,__s_00,iVar3);
    goto LAB_0052a0ad;
  }
  pci_set_master(param_1);
  iVar3 = pci_request_regions(param_1,__s_00);
  if (iVar3 != 0) {
    _printk(&DAT_00df18f0,__s_00,iVar3);
    goto LAB_0052a0f3;
  }
  lVar6 = pci_iomap(param_1,0,0);
  *(long *)(__s_00 + 0x70) = lVar6;
  if (lVar6 == 0) {
    _printk(&DAT_00df1920,__s_00,0xfffffff4);
    iVar3 = -0xc;
    goto LAB_0052a139;
  }
  pcVar1 = __s_00 + 0x140;
  lVar6 = *(long *)(param_1 + 0x10);
  *(int *)(__s_00 + 0x20) = iVar9;
  *(char **)(__s_00 + 0x140) = pcVar1;
  *(char **)(__s_00 + 0x148) = pcVar1;
  uVar4 = *(uint *)(param_1 + 0x38);
  *(long *)(__s_00 + 0x100) = param_1;
  iVar3 = nvswitch_lib_register_device
                    (**(undefined2 **)(lVar6 + 200),*(undefined1 *)(lVar6 + 0xd8),uVar4 >> 3 & 0x1f,
                     uVar4 & 7,*(undefined2 *)(param_1 + 0x3e),param_1,uVar11,__s_00 + 0x50);
  if (iVar3 != 0) {
    _printk(&DAT_00df1948,__s_00,iVar3);
    iVar3 = -0x13;
    goto LAB_0052a1ca;
  }
  uStack_48 = 0;
  lVar6 = *(long *)(__s_00 + 0x100);
  uStack_4c = 0;
  nvswitch_lib_get_device_info(*(undefined8 *)(__s_00 + 0x50),&uStack_48);
  *(undefined4 *)(uStack_48 + 0x30) = 0x10;
  pci_read_config_dword(lVar6,0x10,&uStack_4c);
  *(ulong *)(uStack_48 + 0x18) = (ulong)uStack_4c & 0xfffffffffffffff0;
  if ((*(byte *)(lVar6 + 0x408) & 4) != 0) {
    pci_read_config_dword(lVar6,*(int *)(uStack_48 + 0x30) + 4,&uStack_4c);
    *(ulong *)(uStack_48 + 0x18) = *(ulong *)(uStack_48 + 0x18) | (ulong)uStack_4c << 0x20;
  }
  lVar7 = *(long *)(lVar6 + 0x3f0);
  *(long *)(uStack_48 + 0x20) = lVar7;
  lVar8 = 0;
  if (*(long *)(lVar6 + 0x3f8) != 0) {
    lVar8 = (*(long *)(lVar6 + 0x3f8) + 1) - lVar7;
  }
  *(long *)(uStack_48 + 0x28) = lVar8;
  *(undefined8 *)(uStack_48 + 0x38) = *(undefined8 *)(__s_00 + 0x70);
  iVar3 = nvswitch_lib_initialize_device(*(undefined8 *)(__s_00 + 0x50));
  if (iVar3 == 0) {
    nvswitch_lib_get_uuid(*(undefined8 *)(__s_00 + 0x50),__s_00 + 0x24);
    iVar3 = nvswitch_lib_get_bios_version(*(undefined8 *)(__s_00 + 0x50));
    if (iVar3 != 0) {
      __s_00[0x128] = '\0';
      __s_00[0x129] = '\0';
      __s_00[0x12a] = '\0';
      __s_00[299] = '\0';
      __s_00[300] = '\0';
      __s_00[0x12d] = '\0';
      __s_00[0x12e] = '\0';
      __s_00[0x12f] = '\0';
    }
    iVar3 = nvswitch_lib_get_physid(*(undefined8 *)(__s_00 + 0x50),__s_00 + 0x124);
    if (iVar3 != 0) {
      __s_00[0x124] = -1;
      __s_00[0x125] = -1;
      __s_00[0x126] = -1;
      __s_00[0x127] = -1;
    }
    lVar6 = *(long *)(__s_00 + 0x100);
    uStack_48 = 0;
    cVar2 = pci_find_capability(lVar6,0x11);
    if (cVar2 != '\0') {
      LOCK();
      uStack_48 = uStack_48 | 2;
      UNLOCK();
    }
    cVar2 = pci_find_capability(lVar6,5);
    if (cVar2 != '\0') {
      LOCK();
      uStack_48 = uStack_48 | 4;
      UNLOCK();
    }
    iVar3 = nvswitch_lib_use_pin_irq(*(undefined8 *)(__s_00 + 0x50));
    if (iVar3 != 0) {
      LOCK();
      uStack_48 = uStack_48 | 8;
      UNLOCK();
    }
    __s_00[0x138] = '\0';
    if ((uStack_48 & 4) == 0) {
LAB_0052a3db:
      if ((uStack_48 & 8) != 0) {
        __s_00[0x138] = '\x03';
        _printk(&DAT_00db0801,__s_00);
        if (__s_00[0x138] != '\0') {
          uVar10 = 0x80;
          goto LAB_0052a49b;
        }
      }
      _printk(&DAT_00df1998,__s_00);
      if ((uStack_48 & 2) != 0) {
        _printk(&DAT_00db0816,__s_00);
      }
      if ((uStack_48 & 4) != 0) {
        _printk(&DAT_00db0823,__s_00);
      }
      if ((uStack_48 & 8) != 0) {
        _printk(&DAT_00db082e,__s_00);
      }
      iVar3 = -0x16;
    }
    else {
      iVar3 = pci_enable_msi(*(undefined8 *)(__s_00 + 0x100));
      if (iVar3 == 0) {
        __s_00[0x138] = '\x02';
        _printk(&DAT_00db07f0,__s_00);
      }
      uVar10 = 0;
      if (__s_00[0x138] == '\0') goto LAB_0052a3db;
LAB_0052a49b:
      iVar3 = request_threaded_irq
                        (*(undefined4 *)(lVar6 + 0x3ec),nvswitch_isr_pending,nvswitch_isr_thread,
                         uVar10,__s,__s_00);
      if (iVar3 == 0) {
        cVar2 = nvswitch_is_device_blacklisted(__s_00);
        if (cVar2 == '\0') {
          nvswitch_lib_enable_interrupts(*(undefined8 *)(__s_00 + 0x50));
        }
        else {
          _printk(&DAT_00df19e8,__s_00);
        }
        cVar2 = nvswitch_is_device_blacklisted(__s_00);
        if (cVar2 != '\0') {
          nvswitch_lib_post_init_blacklist_device(*(undefined8 *)(__s_00 + 0x50));
          goto LAB_0052a520;
        }
        mutex_lock(__s_00 + 0x38);
        uStack_48 = uStack_48 & 0xffffffff00000000;
        cVar2 = nvswitch_lib_is_i2c_supported(*(undefined8 *)(__s_00 + 0x50));
        if (cVar2 == '\0') goto LAB_0052a5ae;
        iVar3 = nvswitch_lib_get_valid_ports_mask(*(undefined8 *)(__s_00 + 0x50),&uStack_48);
        if (iVar3 != 0) {
          _printk(&DAT_00df1a10);
          goto LAB_0052a5e7;
        }
        if ((uint)uStack_48 != 0) {
          iVar3 = 0;
          uVar4 = (uint)uStack_48;
          while( true ) {
            for (; (uVar4 & 1) == 0; uVar4 = uVar4 >> 1) {
              iVar3 = iVar3 + 1;
            }
            lVar6 = nvswitch_i2c_add_adapter(__s_00,iVar3);
            if (lVar6 != 0) {
              lVar7 = _nvswitch_os_malloc(0x18);
              if (lVar7 == 0) {
                _printk(&DAT_00df1a38);
                nvswitch_i2c_del_adapter(lVar6);
              }
              else {
                *(long *)(lVar7 + 0x10) = lVar6;
                __list_add(lVar7,*(undefined8 *)(__s_00 + 0x148),pcVar1);
              }
            }
            uVar4 = uVar4 >> 1;
            if (uVar4 == 0) break;
            iVar3 = iVar3 + 1;
          }
        }
LAB_0052a5ae:
        iVar3 = nvswitch_lib_post_init_device(*(undefined8 *)(__s_00 + 0x50));
        if (iVar3 == 0) {
          mutex_unlock(__s_00 + 0x38);
LAB_0052a520:
          iVar3 = nv_kthread_q_init(__s_00 + 0x78,__s);
          if (iVar3 == 0) {
            __s_00[0xe0] = '\x01';
            __s_00[0xe1] = '\0';
            __s_00[0xe2] = '\0';
            __s_00[0xe3] = '\0';
            nv_kthread_q_item_init(__s_00 + 0xc0,nvswitch_task_dispatch,__s_00);
            iVar3 = nv_kthread_q_schedule_q_item(__s_00 + 0x78,__s_00 + 0xc0);
            if (iVar3 != 0) {
              *(char **)(param_1 + 0x148) = __s_00;
              nvswitch_procfs_device_add(__s_00);
              __list_add(__s_00 + 0x110,_DAT_005478c0,&DAT_005478b8);
              LOCK();
              DAT_0054789c = DAT_0054789c + 1;
              UNLOCK();
              mutex_unlock(&DAT_005478a0);
              iVar3 = 0;
              goto LAB_0012ff38;
            }
            _printk(&DAT_00df1a88,__s_00);
            nvswitch_deinit_background_tasks(__s_00);
            iVar3 = -0x13;
          }
          else {
            _printk(&DAT_00df1a60,__s_00);
          }
          _printk(&DAT_00df1ab0,__s_00,iVar3);
        }
        else {
LAB_0052a5e7:
          mutex_unlock(__s_00 + 0x38);
          _printk(&DAT_00df1ae8,__s_00,0xffffffed);
          iVar3 = -0x13;
        }
        nvswitch_deinit_device(__s_00);
LAB_0052a1e1:
        pci_iounmap(param_1,*(undefined8 *)(__s_00 + 0x70));
LAB_0052a139:
        pci_release_regions(param_1);
LAB_0052a0f3:
        pci_clear_master(param_1);
        pci_disable_device(param_1);
LAB_0052a0ad:
        kfree(__s_00);
        goto LAB_00529fc4;
      }
      if (__s_00[0x138] == '\x02') {
        pci_disable_msi(lVar6);
      }
      _printk(&DAT_00db083d,__s_00);
    }
    _printk(&DAT_00df1b18,__s_00,iVar3);
    nvswitch_lib_shutdown_device(*(undefined8 *)(__s_00 + 0x50));
  }
  else {
    _printk(&DAT_00df1970,__s_00,iVar3);
    iVar3 = -0x13;
  }
  nvswitch_lib_unregister_device(*(undefined8 *)(__s_00 + 0x50));
  __s_00[0x50] = '\0';
  __s_00[0x51] = '\0';
  __s_00[0x52] = '\0';
  __s_00[0x53] = '\0';
  __s_00[0x54] = '\0';
  __s_00[0x55] = '\0';
  __s_00[0x56] = '\0';
  __s_00[0x57] = '\0';
LAB_0052a1ca:
  _printk(&DAT_00df1970,__s_00,iVar3);
  goto LAB_0052a1e1;
code_r0x00529fbf:
  iVar3 = -0x22;
LAB_00529fc4:
  mutex_unlock(&DAT_005478a0);
LAB_0012ff38:
  if (local_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}


// ===== 0012ff80 __pfx_nvswitch_map_status =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ffbd) */
/* WARNING: Removing unreachable block (ram,0x0012ffcb) */

undefined4 __pfx_nvswitch_map_status(int param_1)

{
  ulong uVar1;
  
  uVar1 = 0;
  while (((&nvswitch_status_map)[uVar1 * 2] != param_1 &&
         ((&nvswitch_status_map)[uVar1 * 2] != -param_1))) {
    uVar1 = uVar1 + 1;
    if (uVar1 == 0xc) {
      return 0xfffffffb;
    }
  }
  return *(undefined4 *)(&DAT_005a6fa4 + (uVar1 & 0xffffffff) * 8);
}


// ===== 0012ff90 nvswitch_map_status =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ffbd) */
/* WARNING: Removing unreachable block (ram,0x0012ffcb) */

undefined4 nvswitch_map_status(int param_1)

{
  ulong uVar1;
  
  uVar1 = 0;
  while (((&nvswitch_status_map)[uVar1 * 2] != param_1 &&
         ((&nvswitch_status_map)[uVar1 * 2] != -param_1))) {
    uVar1 = uVar1 + 1;
    if (uVar1 == 0xc) {
      return 0xfffffffb;
    }
  }
  return *(undefined4 *)(&DAT_005a6fa4 + (uVar1 & 0xffffffff) * 8);
}


// ===== 0012ffd0 __pfx_nvswitch_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0052a770) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __pfx_nvswitch_init(void)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  
  if (nvswitch == '\0') {
    mutex_init_generic(&DAT_005478a0);
    DAT_005478b8 = &DAT_005478b8;
    _DAT_005478c0 = &DAT_005478b8;
    iVar1 = alloc_chrdev_region(&DAT_00547898,0,0x100,"nvidia-nvswitch");
    if (iVar1 < 0) {
      uVar3 = FUN_0052a805();
      return uVar3;
    }
    _printk(&DAT_00db0866,"nvidia-nvswitch: Major: %d Minor: %d\n",DAT_00547898 >> 0x14,
            DAT_00547898 & 0xfffff);
    cdev_init(&DAT_005477c8,device_fops);
    _DAT_00547808 = __this_module;
    uVar2 = cdev_add(&DAT_005477c8,DAT_00547898,0x40);
    if ((int)uVar2 < 0) {
      _printk(&DAT_00df1be0);
    }
    else {
      uVar2 = nvswitch_procfs_init();
      if (-1 < (int)uVar2) {
        uVar2 = __pci_register_driver(nvswitch_pci_driver,__this_module,"nvidia");
        if ((int)uVar2 < 0) {
          _printk(&DAT_00df1c10,uVar2);
        }
        else {
          uVar2 = DAT_00547898 >> 8;
          cdev_init(&DAT_00547830,ctl_fops);
          _DAT_00547870 = __this_module;
          uVar2 = cdev_add(&DAT_00547830,CONCAT71((uint7)((uint3)uVar2 & 0xfff000),0xff),1);
          if (-1 < (int)uVar2) {
            nvswitch = 1;
            return 0;
          }
          _printk(&DAT_00df1c48);
          pci_unregister_driver(nvswitch_pci_driver);
        }
      }
      cdev_del(&DAT_005477c8);
    }
    unregister_chrdev_region(DAT_00547898,0x100);
    uVar3 = (ulong)uVar2;
  }
  else {
    _printk(&DAT_00df1b48);
    uVar3 = 0xfffffff0;
  }
  return uVar3;
}


// ===== 0012ffe0 nvswitch_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0052a770) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong nvswitch_init(void)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  
  if (nvswitch == '\0') {
    mutex_init_generic(&DAT_005478a0);
    DAT_005478b8 = &DAT_005478b8;
    _DAT_005478c0 = &DAT_005478b8;
    iVar1 = alloc_chrdev_region(&DAT_00547898,0,0x100,"nvidia-nvswitch");
    if (iVar1 < 0) {
      uVar3 = FUN_0052a805();
      return uVar3;
    }
    _printk(&DAT_00db0866,"nvidia-nvswitch: Major: %d Minor: %d\n",DAT_00547898 >> 0x14,
            DAT_00547898 & 0xfffff);
    cdev_init(&DAT_005477c8,device_fops);
    _DAT_00547808 = __this_module;
    uVar2 = cdev_add(&DAT_005477c8,DAT_00547898,0x40);
    if ((int)uVar2 < 0) {
      _printk(&DAT_00df1be0);
    }
    else {
      uVar2 = nvswitch_procfs_init();
      if (-1 < (int)uVar2) {
        uVar2 = __pci_register_driver(nvswitch_pci_driver,__this_module,"nvidia");
        if ((int)uVar2 < 0) {
          _printk(&DAT_00df1c10,uVar2);
        }
        else {
          uVar2 = DAT_00547898 >> 8;
          cdev_init(&DAT_00547830,ctl_fops);
          _DAT_00547870 = __this_module;
          uVar2 = cdev_add(&DAT_00547830,CONCAT71((uint7)((uint3)uVar2 & 0xfff000),0xff),1);
          if (-1 < (int)uVar2) {
            nvswitch = 1;
            return 0;
          }
          _printk(&DAT_00df1c48);
          pci_unregister_driver(nvswitch_pci_driver);
        }
      }
      cdev_del(&DAT_005477c8);
    }
    unregister_chrdev_region(DAT_00547898,0x100);
    uVar3 = (ulong)uVar2;
  }
  else {
    _printk(&DAT_00df1b48);
    uVar3 = 0xfffffff0;
  }
  return uVar3;
}


// ===== 00130050 __pfx_nvswitch_exit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130072) */
/* WARNING: Removing unreachable block (ram,0x001300c4) */

void __pfx_nvswitch_exit(void)

{
  code *pcVar1;
  
  if (nvswitch == '\0') {
    return;
  }
  cdev_del(&DAT_00547830);
  pci_unregister_driver(nvswitch_pci_driver);
  nvswitch_procfs_exit();
  cdev_del(&DAT_005477c8);
  unregister_chrdev_region(DAT_00547898,0x100);
  if ((undefined8 **)DAT_005478b8 == &DAT_005478b8) {
    nvswitch = 0;
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00130060 nvswitch_exit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130072) */
/* WARNING: Removing unreachable block (ram,0x001300c4) */

void nvswitch_exit(void)

{
  code *pcVar1;
  
  if (nvswitch == '\0') {
    return;
  }
  cdev_del(&DAT_00547830);
  pci_unregister_driver(nvswitch_pci_driver);
  nvswitch_procfs_exit();
  cdev_del(&DAT_005477c8);
  unregister_chrdev_region(DAT_00547898,0x100);
  if ((undefined8 **)DAT_005478b8 == &DAT_005478b8) {
    nvswitch = 0;
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 001300d0 __pfx_nvswitch_os_get_platform_time =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130154) */

long __pfx_nvswitch_os_get_platform_time(void)

{
  long lVar1;
  long in_GS_OFFSET;
  long lStack_20;
  long lStack_18;
  long lStack_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x1300e9;
  lStack_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lStack_20 = 0;
  lStack_18 = 0;
  ktime_get_raw_ts64(&lStack_20);
  if (lStack_20 < 0x225c17d04) {
    if (lStack_20 < -0x225c17d03) {
      lVar1 = -0x8000000000000000;
    }
    else {
      lVar1 = lStack_20 * 1000000000 + lStack_18;
    }
  }
  else {
    lVar1 = 0x7fffffffffffffff;
  }
  if (lStack_10 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return lVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 001300e0 nvswitch_os_get_platform_time =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130154) */

long nvswitch_os_get_platform_time(void)

{
  long lVar1;
  long in_GS_OFFSET;
  long local_20;
  long local_18;
  long local_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x1300e9;
  local_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_20 = 0;
  local_18 = 0;
  ktime_get_raw_ts64(&local_20);
  if (local_20 < 0x225c17d04) {
    if (local_20 < -0x225c17d03) {
      lVar1 = -0x8000000000000000;
    }
    else {
      lVar1 = local_20 * 1000000000 + local_18;
    }
  }
  else {
    lVar1 = 0x7fffffffffffffff;
  }
  if (local_10 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return lVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00130180 __pfx_nvswitch_os_get_platform_time_epoch =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130204) */

long __pfx_nvswitch_os_get_platform_time_epoch(void)

{
  long lVar1;
  long in_GS_OFFSET;
  long lStack_20;
  long lStack_18;
  long lStack_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x130199;
  lStack_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lStack_20 = 0;
  lStack_18 = 0;
  ktime_get_real_ts64(&lStack_20);
  if (lStack_20 < 0x225c17d04) {
    if (lStack_20 < -0x225c17d03) {
      lVar1 = -0x8000000000000000;
    }
    else {
      lVar1 = lStack_20 * 1000000000 + lStack_18;
    }
  }
  else {
    lVar1 = 0x7fffffffffffffff;
  }
  if (lStack_10 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return lVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00130190 nvswitch_os_get_platform_time_epoch =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130204) */

long nvswitch_os_get_platform_time_epoch(void)

{
  long lVar1;
  long in_GS_OFFSET;
  long local_20;
  long local_18;
  long local_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x130199;
  local_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_20 = 0;
  local_18 = 0;
  ktime_get_real_ts64(&local_20);
  if (local_20 < 0x225c17d04) {
    if (local_20 < -0x225c17d03) {
      lVar1 = -0x8000000000000000;
    }
    else {
      lVar1 = local_20 * 1000000000 + local_18;
    }
  }
  else {
    lVar1 = 0x7fffffffffffffff;
  }
  if (local_10 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return lVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00130230 __pfx_nvswitch_os_print =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0013031b) */

void __pfx_nvswitch_os_print
               (uint param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  undefined *puVar1;
  long in_GS_OFFSET;
  undefined8 uStack_270;
  char acStack_258 [512];
  long lStack_58;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  
  lStack_58 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_270 = 0;
  uStack_40 = param_3;
  uStack_38 = param_4;
  uStack_30 = param_5;
  uStack_28 = param_6;
  memset(acStack_258,0,0x200);
  puVar1 = &DAT_00db0870;
  if (param_1 < 6) {
    puVar1 = *(undefined **)(CSWTCH_298 + (ulong)param_1 * 8);
  }
  uStack_270 = CONCAT44(uStack_270._4_4_,0x10);
  snprintf(acStack_258,0x200,"%s%s",puVar1,param_2);
  vprintk(acStack_258,&uStack_270);
  if (lStack_58 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00130240 nvswitch_os_print =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0013031b) */

void nvswitch_os_print(uint param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                      undefined8 param_5,undefined8 param_6)

{
  undefined *puVar1;
  long in_GS_OFFSET;
  undefined8 local_270;
  char local_258 [512];
  long local_58;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  
  local_58 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_270 = 0;
  local_40 = param_3;
  local_38 = param_4;
  local_30 = param_5;
  local_28 = param_6;
  memset(local_258,0,0x200);
  puVar1 = &DAT_00db0870;
  if (param_1 < 6) {
    puVar1 = *(undefined **)(CSWTCH_298 + (ulong)param_1 * 8);
  }
  local_270 = CONCAT44(local_270._4_4_,0x10);
  snprintf(local_258,0x200,"%s%s",puVar1,param_2);
  vprintk(local_258,&local_270);
  if (local_58 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00130330 __pfx_nvswitch_os_report_error =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130416) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __pfx_nvswitch_os_report_error(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  int iVar4;
  long in_GS_OFFSET;
  
  lVar1 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uVar2 = (*_mpi_powm)(param_1,param_3);
  iVar4 = 0x2820;
  if ((uVar2 & 0x200) != 0) {
    iVar4 = (-(uint)((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0) & 0x44a0) +
            0x2820;
  }
  if (param_1 != 0) {
    lVar3 = kvasprintf(iVar4);
    if (lVar3 != 0) {
      kfree(lVar3);
    }
  }
  if (lVar1 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00130340 nvswitch_os_report_error =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130416) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void nvswitch_os_report_error(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  int iVar4;
  long in_GS_OFFSET;
  
  lVar1 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uVar2 = (*_mpi_powm)(param_1,param_3);
  iVar4 = 0x2820;
  if ((uVar2 & 0x200) != 0) {
    iVar4 = (-(uint)((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0) & 0x44a0) +
            0x2820;
  }
  if (param_1 != 0) {
    lVar3 = kvasprintf(iVar4);
    if (lVar3 != 0) {
      kfree(lVar3);
    }
  }
  if (lVar1 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00130480 __pfx_nvswitch_os_override_platform =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0013049c) */

void __pfx_nvswitch_os_override_platform(undefined8 param_1,undefined1 *param_2)

{
  *param_2 = 0;
  return;
}


// ===== 00130490 nvswitch_os_override_platform =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0013049c) */

void nvswitch_os_override_platform(undefined8 param_1,undefined1 *param_2)

{
  *param_2 = 0;
  return;
}


// ===== 001304b0 __pfx_nvswitch_os_read_registery_binary =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001304ce) */

undefined8 __pfx_nvswitch_os_read_registery_binary(void)

{
  return 0xfffffff3;
}


// ===== 001304c0 nvswitch_os_read_registery_binary =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001304ce) */

undefined8 nvswitch_os_read_registery_binary(void)

{
  return 0xfffffff3;
}


// ===== 001304e0 __pfx_nvswitch_os_get_device_count =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001304ff) */

undefined4 __pfx_nvswitch_os_get_device_count(void)

{
  return DAT_0054789c;
}


// ===== 001304f0 nvswitch_os_get_device_count =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001304ff) */

undefined4 nvswitch_os_get_device_count(void)

{
  return DAT_0054789c;
}


// ===== 00130510 __pfx_nvswitch_os_read_registry_dword =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130684) */

undefined8
__pfx_nvswitch_os_read_registry_dword(undefined8 param_1,char *param_2,undefined4 *param_3)

{
  uint uVar1;
  char *pcVar2;
  char *pcVar3;
  ulong uVar4;
  undefined8 uVar5;
  uint uVar6;
  ulong uVar7;
  byte *pbVar8;
  long in_GS_OFFSET;
  byte abStack_33 [11];
  long lStack_28;
  
  lStack_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  *param_3 = 0;
  abStack_33[0] = 0;
  abStack_33[1] = 0;
  abStack_33[2] = 0;
  abStack_33[3] = 0;
  abStack_33[4] = 0;
  abStack_33[5] = 0;
  abStack_33[6] = 0;
  abStack_33[7] = 0;
  abStack_33[8] = 0;
  abStack_33[9] = 0;
  abStack_33[10] = 0;
  if (((NvSwitchRegDwords != (char *)0x0) &&
      (pcVar2 = strstr(NvSwitchRegDwords,param_2), pcVar2 != (char *)0x0)) &&
     (pcVar2 = strchr(pcVar2,0x3d), pcVar2 != (char *)0x0)) {
    pcVar3 = strchr(pcVar2,0x3b);
    if (pcVar3 == (char *)0x0) {
      pcVar3 = strchr(pcVar2,0);
    }
    uVar4 = (long)pcVar3 - (long)(pcVar2 + 1);
    if ((int)uVar4 - 1U < 10) {
      uVar4 = uVar4 & 0xffffffff;
      if (0xb < uVar4) {
                    /* WARNING: Subroutine does not return */
        __fortify_panic(1,0xb,uVar4);
      }
      strncpy((char *)abStack_33,pcVar2 + 1,uVar4);
      abStack_33[uVar4] = 0;
      if (param_3 != (undefined4 *)0x0) {
        uVar4 = (ulong)abStack_33[0];
        *param_3 = 0;
        if (abStack_33[0] == 0) {
          uVar7 = 0;
        }
        else {
          pbVar8 = abStack_33;
          uVar7 = 0;
          do {
            while( true ) {
              uVar1 = (uint)uVar4;
              uVar6 = uVar1 + 0x20;
              if (((&_ctype)[uVar4] & 1) == 0) {
                uVar6 = uVar1;
              }
              if ((char)uVar6 != 'x') break;
              if ((abStack_33[0] == 0x30) && (pbVar8 == abStack_33 + 1)) {
                pbVar8 = abStack_33 + 2;
                goto LAB_00130630;
              }
              if (9 < (byte)((char)uVar4 - 0x30U)) goto LAB_0013066c;
LAB_00130689:
              pbVar8 = pbVar8 + 1;
              uVar7 = uVar7 * 0x10 + (ulong)(uVar1 - 0x30);
              uVar4 = (ulong)*pbVar8;
              if (*pbVar8 == 0) goto LAB_0013069f;
            }
            if ((byte)((char)uVar4 - 0x30U) < 10) goto LAB_00130689;
            if (5 < (byte)((char)uVar6 + 0x9fU)) goto LAB_0013066c;
            pbVar8 = pbVar8 + 1;
            uVar7 = uVar7 * 0x10 + (ulong)((uVar6 & 0xff) - 0x57);
LAB_00130630:
            uVar4 = (ulong)*pbVar8;
          } while (*pbVar8 != 0);
LAB_0013069f:
          if (uVar7 >> 0x20 != 0) goto LAB_0013066c;
        }
        *param_3 = (int)uVar7;
        uVar5 = 0;
        goto LAB_00130671;
      }
    }
  }
LAB_0013066c:
  uVar5 = 0xfffffff9;
LAB_00130671:
  if (lStack_28 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}


// ===== 00130520 nvswitch_os_read_registry_dword =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130684) */

undefined8 nvswitch_os_read_registry_dword(undefined8 param_1,char *param_2,undefined4 *param_3)

{
  uint uVar1;
  char *pcVar2;
  char *pcVar3;
  ulong uVar4;
  undefined8 uVar5;
  uint uVar6;
  ulong uVar7;
  byte *pbVar8;
  long in_GS_OFFSET;
  byte local_33 [11];
  long local_28;
  
  local_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  *param_3 = 0;
  local_33[0] = 0;
  local_33[1] = 0;
  local_33[2] = 0;
  local_33[3] = 0;
  local_33[4] = 0;
  local_33[5] = 0;
  local_33[6] = 0;
  local_33[7] = 0;
  local_33[8] = 0;
  local_33[9] = 0;
  local_33[10] = 0;
  if (((NvSwitchRegDwords != (char *)0x0) &&
      (pcVar2 = strstr(NvSwitchRegDwords,param_2), pcVar2 != (char *)0x0)) &&
     (pcVar2 = strchr(pcVar2,0x3d), pcVar2 != (char *)0x0)) {
    pcVar3 = strchr(pcVar2,0x3b);
    if (pcVar3 == (char *)0x0) {
      pcVar3 = strchr(pcVar2,0);
    }
    uVar4 = (long)pcVar3 - (long)(pcVar2 + 1);
    if ((int)uVar4 - 1U < 10) {
      uVar4 = uVar4 & 0xffffffff;
      if (0xb < uVar4) {
                    /* WARNING: Subroutine does not return */
        __fortify_panic(1,0xb,uVar4);
      }
      strncpy((char *)local_33,pcVar2 + 1,uVar4);
      local_33[uVar4] = 0;
      if (param_3 != (undefined4 *)0x0) {
        uVar4 = (ulong)local_33[0];
        *param_3 = 0;
        if (local_33[0] == 0) {
          uVar7 = 0;
        }
        else {
          pbVar8 = local_33;
          uVar7 = 0;
          do {
            while( true ) {
              uVar1 = (uint)uVar4;
              uVar6 = uVar1 + 0x20;
              if (((&_ctype)[uVar4] & 1) == 0) {
                uVar6 = uVar1;
              }
              if ((char)uVar6 != 'x') break;
              if ((local_33[0] == 0x30) && (pbVar8 == local_33 + 1)) {
                pbVar8 = local_33 + 2;
                goto LAB_00130630;
              }
              if (9 < (byte)((char)uVar4 - 0x30U)) goto LAB_0013066c;
LAB_00130689:
              pbVar8 = pbVar8 + 1;
              uVar7 = uVar7 * 0x10 + (ulong)(uVar1 - 0x30);
              uVar4 = (ulong)*pbVar8;
              if (*pbVar8 == 0) goto LAB_0013069f;
            }
            if ((byte)((char)uVar4 - 0x30U) < 10) goto LAB_00130689;
            if (5 < (byte)((char)uVar6 + 0x9fU)) goto LAB_0013066c;
            pbVar8 = pbVar8 + 1;
            uVar7 = uVar7 * 0x10 + (ulong)((uVar6 & 0xff) - 0x57);
LAB_00130630:
            uVar4 = (ulong)*pbVar8;
          } while (*pbVar8 != 0);
LAB_0013069f:
          if (uVar7 >> 0x20 != 0) goto LAB_0013066c;
        }
        *param_3 = (int)uVar7;
        uVar5 = 0;
        goto LAB_00130671;
      }
    }
  }
LAB_0013066c:
  uVar5 = 0xfffffff9;
LAB_00130671:
  if (local_28 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}


// ===== 00130710 __pfx_nvswitch_os_alloc_contig_memory =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0013076a) */
/* WARNING: Removing unreachable block (ram,0x00130774) */

undefined8
__pfx_nvswitch_os_alloc_contig_memory(undefined8 param_1,long *param_2,uint param_3,char param_4)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  if (param_2 != (long *)0x0) {
    uVar3 = (ulong)param_3 - 1 >> 0xc;
    lVar1 = 0x3f;
    if (uVar3 != 0) {
      for (; uVar3 >> lVar1 == 0; lVar1 = lVar1 + -1) {
      }
    }
    lVar1 = get_free_pages_noprof((-(uint)(param_4 == '\0') & 0xfffffffc) + 0xcc4,(int)lVar1 + 1);
    if (lVar1 == 0) {
      _printk(&DAT_00df1c98);
      uVar2 = 0xfffffffe;
    }
    else {
      *param_2 = lVar1;
      uVar2 = 0;
    }
    return uVar2;
  }
  return 0xffffffff;
}


// ===== 00130720 nvswitch_os_alloc_contig_memory =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0013076a) */
/* WARNING: Removing unreachable block (ram,0x00130774) */

undefined8
nvswitch_os_alloc_contig_memory(undefined8 param_1,long *param_2,uint param_3,char param_4)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  if (param_2 != (long *)0x0) {
    uVar3 = (ulong)param_3 - 1 >> 0xc;
    lVar1 = 0x3f;
    if (uVar3 != 0) {
      for (; uVar3 >> lVar1 == 0; lVar1 = lVar1 + -1) {
      }
    }
    lVar1 = get_free_pages_noprof((-(uint)(param_4 == '\0') & 0xfffffffc) + 0xcc4,(int)lVar1 + 1);
    if (lVar1 == 0) {
      _printk(&DAT_00df1c98);
      uVar2 = 0xfffffffe;
    }
    else {
      *param_2 = lVar1;
      uVar2 = 0;
    }
    return uVar2;
  }
  return 0xffffffff;
}


// ===== 00130780 __pfx_nvswitch_os_free_contig_memory =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvswitch_os_free_contig_memory(undefined8 param_1,undefined8 param_2,uint param_3)

{
  long lVar1;
  ulong uVar2;
  
  uVar2 = (ulong)param_3 - 1 >> 0xc;
  lVar1 = 0x3f;
  if (uVar2 != 0) {
    for (; uVar2 >> lVar1 == 0; lVar1 = lVar1 + -1) {
    }
  }
  free_pages(param_2,(int)lVar1 + 1);
  return;
}


// ===== 00130790 nvswitch_os_free_contig_memory =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvswitch_os_free_contig_memory(undefined8 param_1,undefined8 param_2,uint param_3)

{
  long lVar1;
  ulong uVar2;
  
  uVar2 = (ulong)param_3 - 1 >> 0xc;
  lVar1 = 0x3f;
  if (uVar2 != 0) {
    for (; uVar2 >> lVar1 == 0; lVar1 = lVar1 + -1) {
    }
  }
  free_pages(param_2,(int)lVar1 + 1);
  return;
}


// ===== 001307c0 __pfx_nvswitch_os_map_dma_region =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001308b9) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__pfx_nvswitch_os_map_dma_region
          (long param_1,ulong param_2,long *param_3,undefined4 param_4,int param_5)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  
  if ((param_2 == 0 || param_3 == (long *)0x0) || (param_1 == 0)) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar4 = 2;
    if (param_5 != 0) {
      uVar4 = param_5 == 1;
    }
    cVar1 = is_vmalloc_addr(param_2);
    if (cVar1 != '\0') {
      dev_driver_string(param_1 + 0xd0);
      lVar2 = *(long *)(param_1 + 0x120);
      if (lVar2 == 0) {
        lVar2 = *(long *)(param_1 + 0xd0);
      }
      uVar3 = dev_driver_string(param_1 + 0xd0);
      __SCT__WARN_trap(&DAT_001011c0,uVar3,lVar2);
      *param_3 = -1;
      uVar3 = nvswitch_os_map_dma_region_cold();
      return uVar3;
    }
    lVar2 = _phys_base;
    if (param_2 < 0xffffffff80000000) {
      lVar2 = -0x80000000 - _page_offset_base;
    }
    lVar2 = dma_map_page_attrs(param_1 + 0xd0,
                               (param_2 + 0x80000000 + lVar2 >> 0xc) * 0x40 + _vmemmap_base,
                               (uint)param_2 & 0xfff,param_4,uVar4,0);
    *param_3 = lVar2;
    if (lVar2 == -1) {
      _printk(&DAT_00df1d48);
      uVar3 = 0xfffffff9;
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}


// ===== 001307d0 nvswitch_os_map_dma_region =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001308b9) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
nvswitch_os_map_dma_region(long param_1,ulong param_2,long *param_3,undefined4 param_4,int param_5)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  
  if ((param_2 == 0 || param_3 == (long *)0x0) || (param_1 == 0)) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar4 = 2;
    if (param_5 != 0) {
      uVar4 = param_5 == 1;
    }
    cVar1 = is_vmalloc_addr(param_2);
    if (cVar1 != '\0') {
      dev_driver_string(param_1 + 0xd0);
      lVar2 = *(long *)(param_1 + 0x120);
      if (lVar2 == 0) {
        lVar2 = *(long *)(param_1 + 0xd0);
      }
      uVar3 = dev_driver_string(param_1 + 0xd0);
      __SCT__WARN_trap(&DAT_001011c0,uVar3,lVar2);
      *param_3 = -1;
      uVar3 = nvswitch_os_map_dma_region_cold();
      return uVar3;
    }
    lVar2 = _phys_base;
    if (param_2 < 0xffffffff80000000) {
      lVar2 = -0x80000000 - _page_offset_base;
    }
    lVar2 = dma_map_page_attrs(param_1 + 0xd0,
                               (param_2 + 0x80000000 + lVar2 >> 0xc) * 0x40 + _vmemmap_base,
                               (uint)param_2 & 0xfff,param_4,uVar4,0);
    *param_3 = lVar2;
    if (lVar2 == -1) {
      _printk(&DAT_00df1d48);
      uVar3 = 0xfffffff9;
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}


// ===== 00130920 __pfx_nvswitch_os_unmap_dma_region =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0013096e) */
/* WARNING: Removing unreachable block (ram,0x00130978) */

undefined8
__pfx_nvswitch_os_unmap_dma_region
          (long param_1,long param_2,undefined8 param_3,undefined4 param_4,int param_5,
          undefined8 param_6)

{
  undefined1 uVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = 2;
    if (param_5 != 0) {
      uVar1 = param_5 == 1;
    }
    dma_unmap_page_attrs(param_1 + 0xd0,param_3,param_4,uVar1,0,param_6,0x130939);
    return 0;
  }
  return 0xffffffff;
}


// ===== 00130930 nvswitch_os_unmap_dma_region =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0013096e) */
/* WARNING: Removing unreachable block (ram,0x00130978) */

undefined8
nvswitch_os_unmap_dma_region
          (long param_1,long param_2,undefined8 param_3,undefined4 param_4,int param_5,
          undefined8 param_6)

{
  undefined1 uVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = 2;
    if (param_5 != 0) {
      uVar1 = param_5 == 1;
    }
    dma_unmap_page_attrs(param_1 + 0xd0,param_3,param_4,uVar1,0,param_6,0x130939);
    return 0;
  }
  return 0xffffffff;
}


// ===== 00130980 __pfx_nvswitch_os_set_dma_mask =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001309c9) */
/* WARNING: Removing unreachable block (ram,0x001309bf) */
/* WARNING: Removing unreachable block (ram,0x001309d3) */

undefined8 __pfx_nvswitch_os_set_dma_mask(long param_1,char param_2)

{
  undefined8 uVar1;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  uVar1 = dma_set_mask(param_1 + 0xd0,0xffffffffffffffff >> (-param_2 & 0x3fU));
  if ((int)uVar1 == 0) {
    return uVar1;
  }
  return 0xfffffff9;
}


// ===== 00130990 nvswitch_os_set_dma_mask =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001309c9) */
/* WARNING: Removing unreachable block (ram,0x001309bf) */
/* WARNING: Removing unreachable block (ram,0x001309d3) */

undefined8 nvswitch_os_set_dma_mask(long param_1,char param_2)

{
  undefined8 uVar1;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  uVar1 = dma_set_mask(param_1 + 0xd0,0xffffffffffffffff >> (-param_2 & 0x3fU));
  if ((int)uVar1 == 0) {
    return uVar1;
  }
  return 0xfffffff9;
}


// ===== 001309e0 __pfx_nvswitch_os_sync_dma_region_for_cpu =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130a3b) */
/* WARNING: Removing unreachable block (ram,0x00130a1a) */
/* WARNING: Removing unreachable block (ram,0x00130a24) */

undefined8
__pfx_nvswitch_os_sync_dma_region_for_cpu
          (long param_1,undefined8 param_2,undefined4 param_3,int param_4,undefined8 param_5,
          undefined8 param_6)

{
  undefined1 uVar1;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  uVar1 = 2;
  if (param_4 != 0) {
    uVar1 = param_4 == 1;
  }
  if ((*(byte *)(param_1 + 0x3dc) & 0x20) != 0) {
    return 0;
  }
  __dma_sync_single_for_cpu(param_1 + 0xd0,param_2,param_3,uVar1,param_5,param_6,0x1309f9);
  return 0;
}


// ===== 001309f0 nvswitch_os_sync_dma_region_for_cpu =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130a3b) */
/* WARNING: Removing unreachable block (ram,0x00130a1a) */
/* WARNING: Removing unreachable block (ram,0x00130a24) */

undefined8
nvswitch_os_sync_dma_region_for_cpu
          (long param_1,undefined8 param_2,undefined4 param_3,int param_4,undefined8 param_5,
          undefined8 param_6)

{
  undefined1 uVar1;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  uVar1 = 2;
  if (param_4 != 0) {
    uVar1 = param_4 == 1;
  }
  if ((*(byte *)(param_1 + 0x3dc) & 0x20) != 0) {
    return 0;
  }
  __dma_sync_single_for_cpu(param_1 + 0xd0,param_2,param_3,uVar1,param_5,param_6,0x1309f9);
  return 0;
}


// ===== 00130a40 __pfx_nvswitch_os_sync_dma_region_for_device =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130a9b) */
/* WARNING: Removing unreachable block (ram,0x00130a7a) */
/* WARNING: Removing unreachable block (ram,0x00130a84) */

undefined8
__pfx_nvswitch_os_sync_dma_region_for_device
          (long param_1,undefined8 param_2,undefined4 param_3,int param_4,undefined8 param_5,
          undefined8 param_6)

{
  undefined1 uVar1;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  uVar1 = 2;
  if (param_4 != 0) {
    uVar1 = param_4 == 1;
  }
  if ((*(byte *)(param_1 + 0x3dc) & 0x20) != 0) {
    return 0;
  }
  __dma_sync_single_for_device(param_1 + 0xd0,param_2,param_3,uVar1,param_5,param_6,0x130a59);
  return 0;
}


// ===== 00130a50 nvswitch_os_sync_dma_region_for_device =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130a9b) */
/* WARNING: Removing unreachable block (ram,0x00130a7a) */
/* WARNING: Removing unreachable block (ram,0x00130a84) */

undefined8
nvswitch_os_sync_dma_region_for_device
          (long param_1,undefined8 param_2,undefined4 param_3,int param_4,undefined8 param_5,
          undefined8 param_6)

{
  undefined1 uVar1;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  uVar1 = 2;
  if (param_4 != 0) {
    uVar1 = param_4 == 1;
  }
  if ((*(byte *)(param_1 + 0x3dc) & 0x20) != 0) {
    return 0;
  }
  __dma_sync_single_for_device(param_1 + 0xd0,param_2,param_3,uVar1,param_5,param_6,0x130a59);
  return 0;
}


// ===== 00130aa0 __pfx_nvswitch_os_malloc_trace =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvswitch_os_malloc_trace(void)

{
  _nvswitch_os_malloc();
  return;
}


// ===== 00130ab0 nvswitch_os_malloc_trace =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvswitch_os_malloc_trace(void)

{
  _nvswitch_os_malloc();
  return;
}


// ===== 00130ac0 __pfx_nvswitch_os_free =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130b05) */

void __pfx_nvswitch_os_free(long param_1)

{
  char cVar1;
  
  if (param_1 == 0) {
    return;
  }
  cVar1 = is_vmalloc_addr();
  if (cVar1 != '\0') {
    vfree();
    return;
  }
  kfree(param_1);
  return;
}


// ===== 00130ad0 nvswitch_os_free =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130b05) */

void nvswitch_os_free(long param_1)

{
  char cVar1;
  
  if (param_1 == 0) {
    return;
  }
  cVar1 = is_vmalloc_addr();
  if (cVar1 != '\0') {
    vfree();
    return;
  }
  kfree(param_1);
  return;
}


// ===== 00130b10 __pfx_nvswitch_os_strlen =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvswitch_os_strlen(char *param_1)

{
  strlen(param_1);
  return;
}


// ===== 00130b20 nvswitch_os_strlen =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvswitch_os_strlen(char *param_1)

{
  strlen(param_1);
  return;
}


// ===== 00130b30 __pfx_nvswitch_os_is_uuid_in_blacklist =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130cac) */

undefined8 __pfx_nvswitch_os_is_uuid_in_blacklist(long param_1)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  undefined8 uVar5;
  long lVar6;
  char *pcVar7;
  char *pcVar8;
  long lVar9;
  byte bVar10;
  int iVar11;
  long in_GS_OFFSET;
  char *pcStack_50;
  char acStack_44 [44];
  long lStack_18;
  
  pcVar7 = NvSwitchBlacklist;
  lStack_18 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  acStack_44[0x28] = 0;
  pcStack_50 = (char *)0x0;
  acStack_44[0] = '\0';
  acStack_44[1] = '\0';
  acStack_44[2] = '\0';
  acStack_44[3] = '\0';
  acStack_44[4] = '\0';
  acStack_44[5] = '\0';
  acStack_44[6] = '\0';
  acStack_44[7] = '\0';
  acStack_44[8] = '\0';
  acStack_44[9] = '\0';
  acStack_44[10] = '\0';
  acStack_44[0xb] = '\0';
  acStack_44[0xc] = '\0';
  acStack_44[0xd] = '\0';
  acStack_44[0xe] = '\0';
  acStack_44[0xf] = '\0';
  acStack_44[0x10] = '\0';
  acStack_44[0x11] = '\0';
  acStack_44[0x12] = '\0';
  acStack_44[0x13] = '\0';
  acStack_44[0x14] = '\0';
  acStack_44[0x15] = '\0';
  acStack_44[0x16] = '\0';
  acStack_44[0x17] = '\0';
  acStack_44[0x18] = '\0';
  acStack_44[0x19] = '\0';
  acStack_44[0x1a] = '\0';
  acStack_44[0x1b] = '\0';
  acStack_44[0x1c] = '\0';
  acStack_44[0x1d] = '\0';
  acStack_44[0x1e] = '\0';
  acStack_44[0x1f] = '\0';
  acStack_44[0x20] = '\0';
  acStack_44[0x21] = '\0';
  acStack_44[0x22] = '\0';
  acStack_44[0x23] = '\0';
  acStack_44[0x24] = '\0';
  acStack_44[0x25] = '\0';
  acStack_44[0x26] = '\0';
  acStack_44[0x27] = '\0';
  if ((NvSwitchBlacklist != (char *)0x0) && (param_1 != 0)) {
    lVar6 = 0;
    iVar3 = 4;
    builtin_strncpy(acStack_44,"SWX-",5);
    acStack_44[5] = '\0';
    acStack_44[6] = '\0';
    acStack_44[7] = '\0';
    do {
      lVar9 = (long)iVar3;
      if ((1L << ((byte)lVar6 & 0x3f) & 0x550U) == 0) {
        if ((int)lVar6 == 0x10) goto code_r0x00130be7;
      }
      else {
        iVar3 = iVar3 + 1;
        acStack_44[lVar9] = '-';
        lVar9 = (long)iVar3;
      }
      bVar10 = *(byte *)(param_1 + lVar6) >> 4;
      cVar2 = bVar10 + 0x30;
      if (9 < bVar10) {
        cVar2 = bVar10 + 0x37;
      }
      bVar10 = *(byte *)(param_1 + lVar6) & 0xf;
      iVar11 = iVar3 + 1;
      acStack_44[lVar9] = cVar2;
      cVar2 = bVar10 + 0x30;
      if (9 < bVar10) {
        cVar2 = bVar10 + 0x37;
      }
      iVar3 = iVar3 + 2;
      lVar6 = lVar6 + 1;
      acStack_44[iVar11] = cVar2;
    } while( true );
  }
LAB_00130c93:
  uVar5 = 0;
LAB_00130c95:
  if (lStack_18 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
code_r0x00130be7:
  acStack_44[lVar9] = '\0';
  if (iVar3 != -1) {
    iVar3 = nvswitch_os_strlen(NvSwitchBlacklist);
    pcVar4 = (char *)_nvswitch_os_malloc(iVar3 + 1);
    if (pcVar4 != (char *)0x0) {
      cVar2 = *pcVar7;
      pcVar8 = pcVar4;
      while (cVar2 != '\0') {
        if ((4 < (byte)(cVar2 - 9U)) && (cVar2 != ' ')) {
          *pcVar8 = cVar2;
          pcVar8 = pcVar8 + 1;
        }
        pcVar1 = pcVar7 + 1;
        pcVar7 = pcVar7 + 1;
        cVar2 = *pcVar1;
      }
      *pcVar8 = '\0';
      pcStack_50 = pcVar4;
      do {
        pcVar7 = strsep(&pcStack_50,",");
        if (pcVar7 == (char *)0x0) {
          cVar2 = is_vmalloc_addr(pcVar4);
          if (cVar2 == '\0') {
            kfree(pcVar4);
          }
          else {
            vfree();
          }
          goto LAB_00130c93;
        }
        iVar3 = strcmp(pcVar7,acStack_44);
      } while (iVar3 != 0);
      cVar2 = is_vmalloc_addr(pcVar4);
      if (cVar2 == '\0') {
        kfree();
      }
      else {
        vfree(pcVar4);
      }
      uVar5 = 1;
      goto LAB_00130c95;
    }
  }
  goto LAB_00130c93;
}


// ===== 00130b40 nvswitch_os_is_uuid_in_blacklist =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130cac) */

undefined8 nvswitch_os_is_uuid_in_blacklist(long param_1)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  undefined8 uVar5;
  long lVar6;
  char *pcVar7;
  char *pcVar8;
  long lVar9;
  byte bVar10;
  int iVar11;
  long in_GS_OFFSET;
  char *local_50;
  char local_44 [44];
  long local_18;
  
  pcVar7 = NvSwitchBlacklist;
  local_18 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_44[0x28] = 0;
  local_50 = (char *)0x0;
  local_44[0] = '\0';
  local_44[1] = '\0';
  local_44[2] = '\0';
  local_44[3] = '\0';
  local_44[4] = '\0';
  local_44[5] = '\0';
  local_44[6] = '\0';
  local_44[7] = '\0';
  local_44[8] = '\0';
  local_44[9] = '\0';
  local_44[10] = '\0';
  local_44[0xb] = '\0';
  local_44[0xc] = '\0';
  local_44[0xd] = '\0';
  local_44[0xe] = '\0';
  local_44[0xf] = '\0';
  local_44[0x10] = '\0';
  local_44[0x11] = '\0';
  local_44[0x12] = '\0';
  local_44[0x13] = '\0';
  local_44[0x14] = '\0';
  local_44[0x15] = '\0';
  local_44[0x16] = '\0';
  local_44[0x17] = '\0';
  local_44[0x18] = '\0';
  local_44[0x19] = '\0';
  local_44[0x1a] = '\0';
  local_44[0x1b] = '\0';
  local_44[0x1c] = '\0';
  local_44[0x1d] = '\0';
  local_44[0x1e] = '\0';
  local_44[0x1f] = '\0';
  local_44[0x20] = '\0';
  local_44[0x21] = '\0';
  local_44[0x22] = '\0';
  local_44[0x23] = '\0';
  local_44[0x24] = '\0';
  local_44[0x25] = '\0';
  local_44[0x26] = '\0';
  local_44[0x27] = '\0';
  if ((NvSwitchBlacklist != (char *)0x0) && (param_1 != 0)) {
    lVar6 = 0;
    iVar3 = 4;
    builtin_strncpy(local_44,"SWX-",5);
    local_44[5] = '\0';
    local_44[6] = '\0';
    local_44[7] = '\0';
    do {
      lVar9 = (long)iVar3;
      if ((1L << ((byte)lVar6 & 0x3f) & 0x550U) == 0) {
        if ((int)lVar6 == 0x10) goto code_r0x00130be7;
      }
      else {
        iVar3 = iVar3 + 1;
        local_44[lVar9] = '-';
        lVar9 = (long)iVar3;
      }
      bVar10 = *(byte *)(param_1 + lVar6) >> 4;
      cVar2 = bVar10 + 0x30;
      if (9 < bVar10) {
        cVar2 = bVar10 + 0x37;
      }
      bVar10 = *(byte *)(param_1 + lVar6) & 0xf;
      iVar11 = iVar3 + 1;
      local_44[lVar9] = cVar2;
      cVar2 = bVar10 + 0x30;
      if (9 < bVar10) {
        cVar2 = bVar10 + 0x37;
      }
      iVar3 = iVar3 + 2;
      lVar6 = lVar6 + 1;
      local_44[iVar11] = cVar2;
    } while( true );
  }
LAB_00130c93:
  uVar5 = 0;
LAB_00130c95:
  if (local_18 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
code_r0x00130be7:
  local_44[lVar9] = '\0';
  if (iVar3 != -1) {
    iVar3 = nvswitch_os_strlen(NvSwitchBlacklist);
    pcVar4 = (char *)_nvswitch_os_malloc(iVar3 + 1);
    if (pcVar4 != (char *)0x0) {
      cVar2 = *pcVar7;
      pcVar8 = pcVar4;
      while (cVar2 != '\0') {
        if ((4 < (byte)(cVar2 - 9U)) && (cVar2 != ' ')) {
          *pcVar8 = cVar2;
          pcVar8 = pcVar8 + 1;
        }
        pcVar1 = pcVar7 + 1;
        pcVar7 = pcVar7 + 1;
        cVar2 = *pcVar1;
      }
      *pcVar8 = '\0';
      local_50 = pcVar4;
      do {
        pcVar7 = strsep(&local_50,",");
        if (pcVar7 == (char *)0x0) {
          cVar2 = is_vmalloc_addr(pcVar4);
          if (cVar2 == '\0') {
            kfree(pcVar4);
          }
          else {
            vfree();
          }
          goto LAB_00130c93;
        }
        iVar3 = strcmp(pcVar7,local_44);
      } while (iVar3 != 0);
      cVar2 = is_vmalloc_addr(pcVar4);
      if (cVar2 == '\0') {
        kfree();
      }
      else {
        vfree(pcVar4);
      }
      uVar5 = 1;
      goto LAB_00130c95;
    }
  }
  goto LAB_00130c93;
}


// ===== 00130d60 __pfx_nvswitch_os_strncpy =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvswitch_os_strncpy(char *param_1,char *param_2,size_t param_3)

{
  strncpy(param_1,param_2,param_3);
  return;
}


// ===== 00130d70 nvswitch_os_strncpy =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvswitch_os_strncpy(char *param_1,char *param_2,size_t param_3)

{
  strncpy(param_1,param_2,param_3);
  return;
}


// ===== 00130d80 __pfx_nvswitch_os_strncmp =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvswitch_os_strncmp(char *param_1,char *param_2,size_t param_3)

{
  strncmp(param_1,param_2,param_3);
  return;
}


// ===== 00130d90 nvswitch_os_strncmp =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvswitch_os_strncmp(char *param_1,char *param_2,size_t param_3)

{
  strncmp(param_1,param_2,param_3);
  return;
}


// ===== 00130da0 __pfx_nvswitch_os_strncat =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvswitch_os_strncat(char *param_1,char *param_2,size_t param_3)

{
  strncat(param_1,param_2,param_3);
  return;
}


// ===== 00130db0 nvswitch_os_strncat =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvswitch_os_strncat(char *param_1,char *param_2,size_t param_3)

{
  strncat(param_1,param_2,param_3);
  return;
}


// ===== 00130dc0 __pfx_nvswitch_os_memset =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvswitch_os_memset(void *param_1,int param_2,size_t param_3)

{
  memset(param_1,param_2,param_3);
  return;
}


// ===== 00130dd0 nvswitch_os_memset =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvswitch_os_memset(void *param_1,int param_2,size_t param_3)

{
  memset(param_1,param_2,param_3);
  return;
}


// ===== 00130de0 __pfx_nvswitch_os_memcpy =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvswitch_os_memcpy(void *param_1,void *param_2,size_t param_3)

{
  memcpy(param_1,param_2,param_3);
  return;
}


// ===== 00130df0 nvswitch_os_memcpy =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvswitch_os_memcpy(void *param_1,void *param_2,size_t param_3)

{
  memcpy(param_1,param_2,param_3);
  return;
}


// ===== 00130e00 __pfx_nvswitch_os_memcmp =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvswitch_os_memcmp(void *param_1,void *param_2,size_t param_3)

{
  memcmp(param_1,param_2,param_3);
  return;
}


// ===== 00130e10 nvswitch_os_memcmp =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvswitch_os_memcmp(void *param_1,void *param_2,size_t param_3)

{
  memcmp(param_1,param_2,param_3);
  return;
}


// ===== 00130e20 __pfx_nvswitch_os_mem_read32 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130e3b) */

undefined4 __pfx_nvswitch_os_mem_read32(undefined4 *param_1)

{
  return *param_1;
}


// ===== 00130e30 nvswitch_os_mem_read32 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130e3b) */

undefined4 nvswitch_os_mem_read32(undefined4 *param_1)

{
  return *param_1;
}


// ===== 00130e40 __pfx_nvswitch_os_mem_write32 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130e5b) */

void __pfx_nvswitch_os_mem_write32(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return;
}


// ===== 00130e50 nvswitch_os_mem_write32 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130e5b) */

void nvswitch_os_mem_write32(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return;
}


// ===== 00130e60 __pfx_nvswitch_os_mem_read64 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130e7c) */

undefined8 __pfx_nvswitch_os_mem_read64(undefined8 *param_1)

{
  return *param_1;
}


// ===== 00130e70 nvswitch_os_mem_read64 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130e7c) */

undefined8 nvswitch_os_mem_read64(undefined8 *param_1)

{
  return *param_1;
}


// ===== 00130e90 __pfx_nvswitch_os_mem_write64 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130eac) */

void __pfx_nvswitch_os_mem_write64(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return;
}


// ===== 00130ea0 nvswitch_os_mem_write64 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130eac) */

void nvswitch_os_mem_write64(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return;
}


// ===== 00130ec0 __pfx_nvswitch_os_snprintf =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130f37) */

void __pfx_nvswitch_os_snprintf(char *param_1,size_t param_2,char *param_3)

{
  long lVar1;
  long in_GS_OFFSET;
  undefined8 uStack_60;
  
  lVar1 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_60 = 0x18;
  vsnprintf(param_1,param_2,param_3,&uStack_60);
  if (lVar1 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00130ed0 nvswitch_os_snprintf =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130f37) */

void nvswitch_os_snprintf(char *param_1,size_t param_2,char *param_3)

{
  long lVar1;
  long in_GS_OFFSET;
  undefined8 local_60;
  
  lVar1 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_60 = 0x18;
  vsnprintf(param_1,param_2,param_3,&local_60);
  if (lVar1 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00130f50 __pfx_nvswitch_os_vsnprintf =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvswitch_os_vsnprintf(char *param_1,size_t param_2,char *param_3,__gnuc_va_list param_4)

{
  vsnprintf(param_1,param_2,param_3,param_4);
  return;
}


// ===== 00130f60 nvswitch_os_vsnprintf =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvswitch_os_vsnprintf(char *param_1,size_t param_2,char *param_3,__gnuc_va_list param_4)

{
  vsnprintf(param_1,param_2,param_3,param_4);
  return;
}


// ===== 00130f70 __pfx_nvswitch_os_assert_log =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130ff7) */

void __pfx_nvswitch_os_assert_log
               (char *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  code *pcVar1;
  int iVar2;
  long in_GS_OFFSET;
  undefined8 uStack_268;
  char acStack_250 [512];
  long lStack_50;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  undefined8 uStack_20;
  
  lStack_50 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_40 = param_2;
  uStack_38 = param_3;
  uStack_30 = param_4;
  uStack_28 = param_5;
  uStack_20 = param_6;
  iVar2 = __printk_ratelimit("nvswitch_os_assert_log");
  if (iVar2 != 0) {
    uStack_268 = 0;
    memset(acStack_250,0,0x200);
    uStack_268 = CONCAT44(uStack_268._4_4_,8);
    vsnprintf(acStack_250,0x200,param_1,&uStack_268);
    nvswitch_os_print(5,acStack_250);
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  if (lStack_50 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00130f80 nvswitch_os_assert_log =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00130ff7) */

void nvswitch_os_assert_log
               (char *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  code *pcVar1;
  int iVar2;
  long in_GS_OFFSET;
  undefined8 local_268;
  char local_250 [512];
  long local_50;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  local_50 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_40 = param_2;
  local_38 = param_3;
  local_30 = param_4;
  local_28 = param_5;
  local_20 = param_6;
  iVar2 = __printk_ratelimit("nvswitch_os_assert_log");
  if (iVar2 != 0) {
    local_268 = 0;
    memset(local_250,0,0x200);
    local_268 = CONCAT44(local_268._4_4_,8);
    vsnprintf(local_250,0x200,param_1,&local_268);
    nvswitch_os_print(5,local_250);
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  if (local_50 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00131060 __pfx_nvswitch_isr_pending =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001310c6) */
/* WARNING: Removing unreachable block (ram,0x001310a5) */
/* WARNING: Removing unreachable block (ram,0x001310d0) */

undefined8 __pfx_nvswitch_isr_pending(undefined8 param_1,long param_2)

{
  int iVar1;
  
  if (*(char *)(param_2 + 0x138) == '\x02') {
    return 2;
  }
  if (*(char *)(param_2 + 0x138) == '\x03') {
    iVar1 = nvswitch_lib_check_interrupts(*(undefined8 *)(param_2 + 0x50));
    if (iVar1 == -10) {
      nvswitch_lib_disable_interrupts(*(undefined8 *)(param_2 + 0x50));
      return 2;
    }
    if ((iVar1 != 0) && (iVar1 != -6)) {
      _printk(&DAT_00df1d80);
      nvswitch_os_assert_log
                ("NVSwitch: Assertion failed in %s() at %s:%d\n","nvswitch_isr_pending",
                 "nvidia/linux_nvswitch.c",0x48d);
    }
  }
  else {
    _printk(&DAT_00df1de0);
    nvswitch_os_assert_log
              ("NVSwitch: Assertion failed in %s() at %s:%d\n","nvswitch_isr_pending",
               "nvidia/linux_nvswitch.c",0x493);
  }
  return 0;
}


// ===== 00131070 nvswitch_isr_pending =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001310c6) */
/* WARNING: Removing unreachable block (ram,0x001310a5) */
/* WARNING: Removing unreachable block (ram,0x001310d0) */

undefined8 nvswitch_isr_pending(undefined8 param_1,long param_2)

{
  int iVar1;
  
  if (*(char *)(param_2 + 0x138) == '\x02') {
    return 2;
  }
  if (*(char *)(param_2 + 0x138) == '\x03') {
    iVar1 = nvswitch_lib_check_interrupts(*(undefined8 *)(param_2 + 0x50));
    if (iVar1 == -10) {
      nvswitch_lib_disable_interrupts(*(undefined8 *)(param_2 + 0x50));
      return 2;
    }
    if ((iVar1 != 0) && (iVar1 != -6)) {
      _printk(&DAT_00df1d80);
      nvswitch_os_assert_log
                ("NVSwitch: Assertion failed in %s() at %s:%d\n","nvswitch_isr_pending",
                 "nvidia/linux_nvswitch.c",0x48d);
    }
  }
  else {
    _printk(&DAT_00df1de0);
    nvswitch_os_assert_log
              ("NVSwitch: Assertion failed in %s() at %s:%d\n","nvswitch_isr_pending",
               "nvidia/linux_nvswitch.c",0x493);
  }
  return 0;
}


// ===== 001310e0 __pfx_nvswitch_os_sleep =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00131175) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __pfx_nvswitch_os_sleep(ulong param_1)

{
  bool bVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  long in_GS_OFFSET;
  long lStack_48;
  long lStack_40;
  long lStack_38;
  long lStack_30;
  long lStack_28;
  
  param_1 = param_1 & 0xffffffff;
  lStack_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lStack_48 = 0;
  lStack_40 = 0;
  ktime_get_raw_ts64(&lStack_48);
  uVar4 = (*_mpi_powm)();
  if (((uVar4 & 0x200) == 0) || ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) != 0)) {
    for (; param_1 != 0; param_1 = param_1 - 1) {
      __const_udelay(0x418958);
    }
  }
  else {
    lStack_38 = 0;
    lStack_30 = 0;
    set_normalized_timespec64(&lStack_38,lStack_48,param_1 * 1000000 + lStack_40);
    lVar3 = lStack_30;
    lVar2 = lStack_38;
    if (param_1 != 0) {
      LOCK();
      *(undefined4 *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0x18) = 1;
      UNLOCK();
      while( true ) {
        while( true ) {
          schedule_timeout(param_1);
          ktime_get_raw_ts64(&lStack_48);
          bVar1 = lStack_48 < lVar2;
          if (lVar2 == lStack_48) {
            bVar1 = lStack_40 < lVar3;
          }
          if (!bVar1) goto LAB_00131159;
          lStack_38 = 0;
          lStack_30 = 0;
          set_normalized_timespec64(&lStack_38,lVar2 - lStack_48,lVar3 - lStack_40);
          lStack_48 = lStack_38;
          lStack_40 = lStack_30;
          if (lStack_38 < 0x225c17d04) break;
          param_1 = 0x44b82fa09;
        }
        if (lStack_38 < -0x225c17d03) {
          uVar4 = 0x8000000000000000;
          goto LAB_001312cf;
        }
        uVar4 = lStack_38 * 1000000000 + lStack_30;
        if (uVar4 * 1000 < 1000000000) break;
        param_1 = (uVar4 * 1000) / 1000000000;
      }
      if (1000000 < uVar4) {
LAB_001312cf:
        uVar5 = uVar4 / 1000000;
        do {
          uVar5 = uVar5 - 1;
          __const_udelay(0x418958);
        } while (uVar5 != 0);
        uVar4 = uVar4 % 1000000;
      }
      if (uVar4 != 0) {
        __ndelay(uVar4);
      }
    }
  }
LAB_00131159:
  if (lStack_28 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 001310f0 nvswitch_os_sleep =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00131175) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void nvswitch_os_sleep(ulong param_1)

{
  bool bVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  long in_GS_OFFSET;
  long local_48;
  long local_40;
  long local_38;
  long local_30;
  long local_28;
  
  param_1 = param_1 & 0xffffffff;
  local_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_48 = 0;
  local_40 = 0;
  ktime_get_raw_ts64(&local_48);
  uVar4 = (*_mpi_powm)();
  if (((uVar4 & 0x200) == 0) || ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) != 0)) {
    for (; param_1 != 0; param_1 = param_1 - 1) {
      __const_udelay(0x418958);
    }
  }
  else {
    local_38 = 0;
    local_30 = 0;
    set_normalized_timespec64(&local_38,local_48,param_1 * 1000000 + local_40);
    lVar3 = local_30;
    lVar2 = local_38;
    if (param_1 != 0) {
      LOCK();
      *(undefined4 *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0x18) = 1;
      UNLOCK();
      while( true ) {
        while( true ) {
          schedule_timeout(param_1);
          ktime_get_raw_ts64(&local_48);
          bVar1 = local_48 < lVar2;
          if (lVar2 == local_48) {
            bVar1 = local_40 < lVar3;
          }
          if (!bVar1) goto LAB_00131159;
          local_38 = 0;
          local_30 = 0;
          set_normalized_timespec64(&local_38,lVar2 - local_48,lVar3 - local_40);
          local_48 = local_38;
          local_40 = local_30;
          if (local_38 < 0x225c17d04) break;
          param_1 = 0x44b82fa09;
        }
        if (local_38 < -0x225c17d03) {
          uVar4 = 0x8000000000000000;
          goto LAB_001312cf;
        }
        uVar4 = local_38 * 1000000000 + local_30;
        if (uVar4 * 1000 < 1000000000) break;
        param_1 = (uVar4 * 1000) / 1000000000;
      }
      if (1000000 < uVar4) {
LAB_001312cf:
        uVar5 = uVar4 / 1000000;
        do {
          uVar5 = uVar5 - 1;
          __const_udelay(0x418958);
        } while (uVar5 != 0);
        uVar4 = uVar4 % 1000000;
      }
      if (uVar4 != 0) {
        __ndelay(uVar4);
      }
    }
  }
LAB_00131159:
  if (local_28 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00131350 __pfx_nvswitch_os_acquire_fabric_mgmt_cap =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0013139b) */
/* WARNING: Removing unreachable block (ram,0x00131386) */
/* WARNING: Removing unreachable block (ram,0x00131390) */

undefined8 __pfx_nvswitch_os_acquire_fabric_mgmt_cap(long param_1,undefined8 param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  iVar1 = nvlink_cap_acquire(param_2,0);
  if (-1 < iVar1) {
    *(int *)(param_1 + 0x28) = iVar1;
    return 0;
  }
  return 0xfffffff0;
}


// ===== 00131360 nvswitch_os_acquire_fabric_mgmt_cap =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0013139b) */
/* WARNING: Removing unreachable block (ram,0x00131386) */
/* WARNING: Removing unreachable block (ram,0x00131390) */

undefined8 nvswitch_os_acquire_fabric_mgmt_cap(long param_1,undefined8 param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  iVar1 = nvlink_cap_acquire(param_2,0);
  if (-1 < iVar1) {
    *(int *)(param_1 + 0x28) = iVar1;
    return 0;
  }
  return 0xfffffff0;
}


// ===== 001313a0 __pfx_nvswitch_os_is_fabric_manager =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001313c6) */
/* WARNING: Removing unreachable block (ram,0x001313cd) */

uint __pfx_nvswitch_os_is_fabric_manager(long param_1)

{
  if (param_1 != 0) {
    return ~*(uint *)(param_1 + 0x28) >> 0x1f;
  }
  return 0;
}


// ===== 001313b0 nvswitch_os_is_fabric_manager =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001313c6) */
/* WARNING: Removing unreachable block (ram,0x001313cd) */

uint nvswitch_os_is_fabric_manager(long param_1)

{
  if (param_1 != 0) {
    return ~*(uint *)(param_1 + 0x28) >> 0x1f;
  }
  return 0;
}


// ===== 001313e0 __pfx_nvswitch_os_is_admin =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00131406) */

undefined1 __pfx_nvswitch_os_is_admin(void)

{
  undefined1 uVar1;
  
  uVar1 = capable(0x15);
  return uVar1;
}


// ===== 001313f0 nvswitch_os_is_admin =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00131406) */

undefined1 nvswitch_os_is_admin(void)

{
  undefined1 uVar1;
  
  uVar1 = capable(0x15);
  return uVar1;
}


// ===== 00131410 __pfx_nvswitch_os_get_os_version =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0013144c) */

undefined8
__pfx_nvswitch_os_get_os_version(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 7;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 1;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 8;
  }
  return 0;
}


// ===== 00131420 nvswitch_os_get_os_version =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0013144c) */

undefined8 nvswitch_os_get_os_version(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 7;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 1;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 8;
  }
  return 0;
}


// ===== 00131460 __pfx_nvswitch_os_add_client_event =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0013147b) */

undefined8 __pfx_nvswitch_os_add_client_event(void)

{
  return 0;
}


// ===== 00131470 nvswitch_os_add_client_event =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0013147b) */

undefined8 nvswitch_os_add_client_event(void)

{
  return 0;
}


// ===== 00131480 __pfx_nvswitch_os_remove_client_event =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0013149b) */

undefined8 __pfx_nvswitch_os_remove_client_event(void)

{
  return 0;
}


// ===== 00131490 nvswitch_os_remove_client_event =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0013149b) */

undefined8 nvswitch_os_remove_client_event(void)

{
  return 0;
}


// ===== 001314a0 __pfx_nvswitch_os_notify_client_event =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001314d9) */
/* WARNING: Removing unreachable block (ram,0x001314e3) */

undefined8
__pfx_nvswitch_os_notify_client_event
          (undefined8 param_1,long param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
          undefined8 param_6)

{
  if (param_2 != 0) {
    *(undefined1 *)(param_2 + 0x20) = 1;
    __wake_up(param_2 + 8,1,1,0,param_5,param_6,0x1314b9);
    return 0;
  }
  return 0xffffffff;
}


// ===== 001314b0 nvswitch_os_notify_client_event =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001314d9) */
/* WARNING: Removing unreachable block (ram,0x001314e3) */

undefined8
nvswitch_os_notify_client_event
          (undefined8 param_1,long param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
          undefined8 param_6)

{
  if (param_2 != 0) {
    *(undefined1 *)(param_2 + 0x20) = 1;
    __wake_up(param_2 + 8,1,1,0,param_5,param_6,0x1314b9);
    return 0;
  }
  return 0xffffffff;
}


// ===== 001314f0 __pfx_nvswitch_os_get_supported_register_events_params =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00131511) */

undefined8
__pfx_nvswitch_os_get_supported_register_events_params(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = 0;
  *param_2 = 0;
  return 0;
}


// ===== 00131500 nvswitch_os_get_supported_register_events_params =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00131511) */

undefined8 nvswitch_os_get_supported_register_events_params(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = 0;
  *param_2 = 0;
  return 0;
}


// ===== 00131520 __pfx_nvswitch_os_get_pid =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00131550) */

undefined8 __pfx_nvswitch_os_get_pid(undefined4 *param_1)

{
  long in_GS_OFFSET;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *(undefined4 *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0xb30);
  }
  return 0;
}


// ===== 00131530 nvswitch_os_get_pid =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00131550) */

undefined8 nvswitch_os_get_pid(undefined4 *param_1)

{
  long in_GS_OFFSET;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *(undefined4 *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0xb30);
  }
  return 0;
}


// ===== 00131560 __pfx_nv_procfs_release_permissions =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_release_permissions(void)

{
  single_release();
  return;
}


// ===== 00131570 nv_procfs_release_permissions =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_release_permissions(void)

{
  single_release();
  return;
}


// ===== 00131580 __pfx_nv_procfs_open_device_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_open_device_info(long param_1,undefined8 param_2)

{
  single_open(param_2,nv_procfs_read_device_info,*(undefined8 *)(param_1 + 0x230));
  return;
}


// ===== 00131590 nv_procfs_open_device_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_open_device_info(long param_1,undefined8 param_2)

{
  single_open(param_2,nv_procfs_read_device_info,*(undefined8 *)(param_1 + 0x230));
  return;
}


// ===== 001315c0 __pfx_nv_procfs_open_permissions =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_open_permissions(long param_1,undefined8 param_2)

{
  single_open(param_2,nv_procfs_read_permissions,*(undefined8 *)(param_1 + 0x230));
  return;
}


// ===== 001315d0 nv_procfs_open_permissions =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_open_permissions(long param_1,undefined8 param_2)

{
  single_open(param_2,nv_procfs_read_permissions,*(undefined8 *)(param_1 + 0x230));
  return;
}


// ===== 00131600 __pfx_nv_procfs_read_permissions =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00131633) */

undefined8 __pfx_nv_procfs_read_permissions(undefined8 param_1)

{
  undefined8 in_R8;
  undefined8 in_R9;
  
  seq_printf(param_1,"%s: %u\n","DeviceFileMode",0x1b6,in_R8,in_R9,0x131619);
  return 0;
}


// ===== 00131610 nv_procfs_read_permissions =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00131633) */

undefined8 nv_procfs_read_permissions(undefined8 param_1)

{
  undefined8 in_R8;
  undefined8 in_R9;
  
  seq_printf(param_1,"%s: %u\n","DeviceFileMode",0x1b6,in_R8,in_R9,0x131619);
  return 0;
}


// ===== 00131640 __pfx_nv_procfs_read_device_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00131766) */

undefined8 __pfx_nv_procfs_read_device_info(long param_1)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  byte bVar7;
  char cVar8;
  long lVar9;
  long in_GS_OFFSET;
  undefined8 uStack_4c;
  undefined8 uStack_44;
  undefined8 uStack_3c;
  undefined8 uStack_34;
  undefined8 uStack_2c;
  undefined1 uStack_24;
  long lStack_20;
  
  lStack_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lVar2 = *(long *)(param_1 + 0x68);
  uStack_24 = 0;
  uStack_4c = 0;
  uStack_44 = 0;
  uStack_3c = 0;
  uStack_34 = 0;
  uStack_2c = 0;
  if (lVar2 == 0) {
    nvswitch_os_assert_log
              ("NVSwitch: Assertion failed in %s() at %s:%d\n","nv_procfs_read_device_info",
               "nvidia/procfs_nvswitch.c",0x44);
    uVar5 = 0xfffffff2;
    goto LAB_0013174a;
  }
  seq_printf(param_1,"BIOS Version: ");
  uVar3 = *(ulong *)(lVar2 + 0x128);
  if (uVar3 == 0) {
    seq_printf(param_1,&DAT_00db08fe);
  }
  else {
    seq_printf(param_1,"%02llx.%02llx.%02llx.%02llx.%02llx\n",uVar3 >> 0x20,uVar3 >> 0x18 & 0xff,
               uVar3 >> 0x10 & 0xff,uVar3 >> 8 & 0xff,uVar3 & 0xff);
  }
  if (lVar2 != -0x24) {
    uStack_4c = CONCAT44(uStack_4c._4_4_,0x2d585753);
    lVar6 = 0;
    iVar4 = 4;
    do {
      lVar9 = (long)iVar4;
      if ((1L << ((byte)lVar6 & 0x3f) & 0x550U) == 0) {
        if ((int)lVar6 == 0x10) goto code_r0x0013171b;
      }
      else {
        iVar4 = iVar4 + 1;
        *(undefined1 *)((long)&uStack_4c + lVar9) = 0x2d;
        lVar9 = (long)iVar4;
      }
      bVar7 = *(byte *)(lVar2 + 0x24 + lVar6) >> 4;
      cVar8 = bVar7 + 0x37;
      if (bVar7 < 10) {
        cVar8 = bVar7 + 0x30;
      }
      iVar1 = iVar4 + 1;
      *(char *)((long)&uStack_4c + lVar9) = cVar8;
      bVar7 = *(byte *)(lVar2 + 0x24 + lVar6) & 0xf;
      cVar8 = bVar7 + 0x30;
      if (9 < bVar7) {
        cVar8 = bVar7 + 0x37;
      }
      iVar4 = iVar4 + 2;
      lVar6 = lVar6 + 1;
      *(char *)((long)&uStack_4c + (long)iVar1) = cVar8;
    } while( true );
  }
  goto LAB_0013171f;
code_r0x0013171b:
  *(undefined1 *)((long)&uStack_4c + lVar9) = 0;
LAB_0013171f:
  seq_printf(param_1,"UUID: %s\n");
  seq_printf(param_1,"Physical location ID: %04x\n",*(undefined4 *)(lVar2 + 0x124));
  uVar5 = 0;
LAB_0013174a:
  if (lStack_20 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00131650 nv_procfs_read_device_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00131766) */

undefined8 nv_procfs_read_device_info(long param_1)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  byte bVar7;
  char cVar8;
  long lVar9;
  long in_GS_OFFSET;
  undefined8 local_4c;
  undefined8 local_44;
  undefined8 local_3c;
  undefined8 local_34;
  undefined8 local_2c;
  undefined1 local_24;
  long local_20;
  
  local_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lVar2 = *(long *)(param_1 + 0x68);
  local_24 = 0;
  local_4c = 0;
  local_44 = 0;
  local_3c = 0;
  local_34 = 0;
  local_2c = 0;
  if (lVar2 == 0) {
    nvswitch_os_assert_log
              ("NVSwitch: Assertion failed in %s() at %s:%d\n","nv_procfs_read_device_info",
               "nvidia/procfs_nvswitch.c",0x44);
    uVar5 = 0xfffffff2;
    goto LAB_0013174a;
  }
  seq_printf(param_1,"BIOS Version: ");
  uVar3 = *(ulong *)(lVar2 + 0x128);
  if (uVar3 == 0) {
    seq_printf(param_1,&DAT_00db08fe);
  }
  else {
    seq_printf(param_1,"%02llx.%02llx.%02llx.%02llx.%02llx\n",uVar3 >> 0x20,uVar3 >> 0x18 & 0xff,
               uVar3 >> 0x10 & 0xff,uVar3 >> 8 & 0xff,uVar3 & 0xff);
  }
  if (lVar2 != -0x24) {
    local_4c = CONCAT44(local_4c._4_4_,0x2d585753);
    lVar6 = 0;
    iVar4 = 4;
    do {
      lVar9 = (long)iVar4;
      if ((1L << ((byte)lVar6 & 0x3f) & 0x550U) == 0) {
        if ((int)lVar6 == 0x10) goto code_r0x0013171b;
      }
      else {
        iVar4 = iVar4 + 1;
        *(undefined1 *)((long)&local_4c + lVar9) = 0x2d;
        lVar9 = (long)iVar4;
      }
      bVar7 = *(byte *)(lVar2 + 0x24 + lVar6) >> 4;
      cVar8 = bVar7 + 0x37;
      if (bVar7 < 10) {
        cVar8 = bVar7 + 0x30;
      }
      iVar1 = iVar4 + 1;
      *(char *)((long)&local_4c + lVar9) = cVar8;
      bVar7 = *(byte *)(lVar2 + 0x24 + lVar6) & 0xf;
      cVar8 = bVar7 + 0x30;
      if (9 < bVar7) {
        cVar8 = bVar7 + 0x37;
      }
      iVar4 = iVar4 + 2;
      lVar6 = lVar6 + 1;
      *(char *)((long)&local_4c + (long)iVar1) = cVar8;
    } while( true );
  }
  goto LAB_0013171f;
code_r0x0013171b:
  *(undefined1 *)((long)&local_4c + lVar9) = 0;
LAB_0013171f:
  seq_printf(param_1,"UUID: %s\n");
  seq_printf(param_1,"Physical location ID: %04x\n",*(undefined4 *)(lVar2 + 0x124));
  uVar5 = 0;
LAB_0013174a:
  if (local_20 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00131840 __pfx_nv_procfs_release_device_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_release_device_info(void)

{
  single_release();
  return;
}


// ===== 00131850 nv_procfs_release_device_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_release_device_info(void)

{
  single_release();
  return;
}


// ===== 00131860 __pfx_nv_procfs_read_lock_permissions =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001318d0) */
/* WARNING: Removing unreachable block (ram,0x00131900) */

undefined8
__pfx_nv_procfs_read_lock_permissions
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong *puVar1;
  int iVar2;
  undefined8 uVar3;
  long in_GS_OFFSET;
  
  puVar1 = *(ulong **)(&const_current_task + in_GS_OFFSET);
  while( true ) {
    iVar2 = down_read_trylock(nv_system_pm_lock);
    if (iVar2 != 0) {
      uVar3 = seq_read(param_1,param_2,param_3,param_4);
      up_read(nv_system_pm_lock);
      return uVar3;
    }
    if (((*puVar1 & 4) != 0) || ((*puVar1 & 2) != 0)) break;
    __SCT__cond_resched();
  }
  return 0xfffffffffffffffc;
}


// ===== 00131870 nv_procfs_read_lock_permissions =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001318d0) */
/* WARNING: Removing unreachable block (ram,0x00131900) */

undefined8
nv_procfs_read_lock_permissions
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong *puVar1;
  int iVar2;
  undefined8 uVar3;
  long in_GS_OFFSET;
  
  puVar1 = *(ulong **)(&const_current_task + in_GS_OFFSET);
  while( true ) {
    iVar2 = down_read_trylock(nv_system_pm_lock);
    if (iVar2 != 0) {
      uVar3 = seq_read(param_1,param_2,param_3,param_4);
      up_read(nv_system_pm_lock);
      return uVar3;
    }
    if (((*puVar1 & 4) != 0) || ((*puVar1 & 2) != 0)) break;
    __SCT__cond_resched();
  }
  return 0xfffffffffffffffc;
}


// ===== 00131910 __pfx_nv_procfs_read_lock_device_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_read_lock_device_info(void)

{
  nv_procfs_read_lock_permissions();
  return;
}


// ===== 00131920 nv_procfs_read_lock_device_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_read_lock_device_info(void)

{
  nv_procfs_read_lock_permissions();
  return;
}


// ===== 00131930 __pfx_nvswitch_procfs_device_remove =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00131972) */

void __pfx_nvswitch_procfs_device_remove(long param_1)

{
  if ((param_1 != 0) && (*(long *)(param_1 + 0x130) != 0)) {
    proc_remove(*(long *)(param_1 + 0x130));
    *(undefined8 *)(param_1 + 0x130) = 0;
    return;
  }
  nvswitch_os_assert_log
            ("NVSwitch: Assertion failed in %s() at %s:%d\n","nvswitch_procfs_device_remove",
             "nvidia/procfs_nvswitch.c",0x6a);
  return;
}


// ===== 00131940 nvswitch_procfs_device_remove =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00131972) */

void nvswitch_procfs_device_remove(long param_1)

{
  if ((param_1 != 0) && (*(long *)(param_1 + 0x130) != 0)) {
    proc_remove(*(long *)(param_1 + 0x130));
    *(undefined8 *)(param_1 + 0x130) = 0;
    return;
  }
  nvswitch_os_assert_log
            ("NVSwitch: Assertion failed in %s() at %s:%d\n","nvswitch_procfs_device_remove",
             "nvidia/procfs_nvswitch.c",0x6a);
  return;
}


// ===== 001319a0 __pfx_nvswitch_procfs_device_add =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00131ab1) */

undefined8 __pfx_nvswitch_procfs_device_add(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  long in_GS_OFFSET;
  char acStack_38 [32];
  long lStack_18;
  
  lStack_18 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  acStack_38[0] = '\0';
  acStack_38[1] = '\0';
  acStack_38[2] = '\0';
  acStack_38[3] = '\0';
  acStack_38[4] = '\0';
  acStack_38[5] = '\0';
  acStack_38[6] = '\0';
  acStack_38[7] = '\0';
  acStack_38[8] = '\0';
  acStack_38[9] = '\0';
  acStack_38[10] = '\0';
  acStack_38[0xb] = '\0';
  acStack_38[0xc] = '\0';
  acStack_38[0xd] = '\0';
  acStack_38[0xe] = '\0';
  acStack_38[0xf] = '\0';
  acStack_38[0x10] = '\0';
  acStack_38[0x11] = '\0';
  acStack_38[0x12] = '\0';
  acStack_38[0x13] = '\0';
  acStack_38[0x14] = '\0';
  acStack_38[0x15] = '\0';
  acStack_38[0x16] = '\0';
  acStack_38[0x17] = '\0';
  acStack_38[0x18] = '\0';
  acStack_38[0x19] = '\0';
  acStack_38[0x1a] = '\0';
  acStack_38[0x1b] = '\0';
  acStack_38[0x1c] = '\0';
  acStack_38[0x1d] = '\0';
  acStack_38[0x1e] = '\0';
  acStack_38[0x1f] = '\0';
  if ((param_1 == 0) || (lVar1 = *(long *)(param_1 + 0x100), lVar1 == 0)) {
    nvswitch_os_assert_log
              ("NVSwitch: Assertion failed in %s() at %s:%d\n","nvswitch_procfs_device_add",
               "nvidia/procfs_nvswitch.c",0x7e);
  }
  else {
    snprintf(acStack_38,0x20,"%04x:%02x:%02x.%1x",(ulong)**(uint **)(*(long *)(lVar1 + 0x10) + 200),
             (ulong)*(byte *)(*(long *)(lVar1 + 0x10) + 0xd8),
             (ulong)(*(uint *)(lVar1 + 0x38) >> 3 & 0x1f),(ulong)(*(uint *)(lVar1 + 0x38) & 7));
    lVar1 = proc_mkdir_mode(acStack_38,0x416d,nvswitch_procfs_devices);
    if (lVar1 != 0) {
      *(long *)(param_1 + 0x130) = lVar1;
      lVar1 = proc_create_data("information",0x8124,lVar1,nv_procfs_device_info_fops,param_1);
      if (lVar1 != 0) {
        uVar2 = 0;
        goto LAB_00131a9a;
      }
      if (*(long *)(param_1 + 0x130) == 0) {
        nvswitch_os_assert_log
                  ("NVSwitch: Assertion failed in %s() at %s:%d\n","nvswitch_procfs_device_remove",
                   "nvidia/procfs_nvswitch.c",0x6a);
      }
      else {
        proc_remove();
        *(undefined8 *)(param_1 + 0x130) = 0;
      }
    }
  }
  uVar2 = 0xffffffff;
LAB_00131a9a:
  if (lStack_18 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}


// ===== 001319b0 nvswitch_procfs_device_add =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00131ab1) */

undefined8 nvswitch_procfs_device_add(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  long in_GS_OFFSET;
  char local_38 [32];
  long local_18;
  
  local_18 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_38[0] = '\0';
  local_38[1] = '\0';
  local_38[2] = '\0';
  local_38[3] = '\0';
  local_38[4] = '\0';
  local_38[5] = '\0';
  local_38[6] = '\0';
  local_38[7] = '\0';
  local_38[8] = '\0';
  local_38[9] = '\0';
  local_38[10] = '\0';
  local_38[0xb] = '\0';
  local_38[0xc] = '\0';
  local_38[0xd] = '\0';
  local_38[0xe] = '\0';
  local_38[0xf] = '\0';
  local_38[0x10] = '\0';
  local_38[0x11] = '\0';
  local_38[0x12] = '\0';
  local_38[0x13] = '\0';
  local_38[0x14] = '\0';
  local_38[0x15] = '\0';
  local_38[0x16] = '\0';
  local_38[0x17] = '\0';
  local_38[0x18] = '\0';
  local_38[0x19] = '\0';
  local_38[0x1a] = '\0';
  local_38[0x1b] = '\0';
  local_38[0x1c] = '\0';
  local_38[0x1d] = '\0';
  local_38[0x1e] = '\0';
  local_38[0x1f] = '\0';
  if ((param_1 == 0) || (lVar1 = *(long *)(param_1 + 0x100), lVar1 == 0)) {
    nvswitch_os_assert_log
              ("NVSwitch: Assertion failed in %s() at %s:%d\n","nvswitch_procfs_device_add",
               "nvidia/procfs_nvswitch.c",0x7e);
  }
  else {
    snprintf(local_38,0x20,"%04x:%02x:%02x.%1x",(ulong)**(uint **)(*(long *)(lVar1 + 0x10) + 200),
             (ulong)*(byte *)(*(long *)(lVar1 + 0x10) + 0xd8),
             (ulong)(*(uint *)(lVar1 + 0x38) >> 3 & 0x1f),(ulong)(*(uint *)(lVar1 + 0x38) & 7));
    lVar1 = proc_mkdir_mode(local_38,0x416d,nvswitch_procfs_devices);
    if (lVar1 != 0) {
      *(long *)(param_1 + 0x130) = lVar1;
      lVar1 = proc_create_data("information",0x8124,lVar1,nv_procfs_device_info_fops,param_1);
      if (lVar1 != 0) {
        uVar2 = 0;
        goto LAB_00131a9a;
      }
      if (*(long *)(param_1 + 0x130) == 0) {
        nvswitch_os_assert_log
                  ("NVSwitch: Assertion failed in %s() at %s:%d\n","nvswitch_procfs_device_remove",
                   "nvidia/procfs_nvswitch.c",0x6a);
      }
      else {
        proc_remove();
        *(undefined8 *)(param_1 + 0x130) = 0;
      }
    }
  }
  uVar2 = 0xffffffff;
LAB_00131a9a:
  if (local_18 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}


// ===== 00131b40 __pfx_nvswitch_procfs_exit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00131b75) */

void __pfx_nvswitch_procfs_exit(void)

{
  if (nvswitch_procfs_dir != 0) {
    proc_remove();
    nvswitch_procfs_dir = 0;
  }
  return;
}


// ===== 00131b50 nvswitch_procfs_exit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00131b75) */

void nvswitch_procfs_exit(void)

{
  if (nvswitch_procfs_dir != 0) {
    proc_remove();
    nvswitch_procfs_dir = 0;
  }
  return;
}


// ===== 00131b80 __pfx_nvswitch_procfs_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00131c01) */
/* WARNING: Removing unreachable block (ram,0x00131c27) */

undefined8 __pfx_nvswitch_procfs_init(void)

{
  long lVar1;
  undefined8 in_R9;
  undefined8 uVar2;
  
  uVar2 = 0x131b99;
  nvswitch_procfs_dir = proc_mkdir_mode("driver/nvidia-nvswitch",0x416d,0);
  if (nvswitch_procfs_dir != 0) {
    lVar1 = proc_create_data("permissions",0x8124,nvswitch_procfs_dir,nv_procfs_permissions_fops,0,
                             in_R9,uVar2);
    if (lVar1 != 0) {
      nvswitch_procfs_devices = proc_mkdir_mode("devices",0x416d,nvswitch_procfs_dir);
      if (nvswitch_procfs_devices != 0) {
        return 0;
      }
    }
    if (nvswitch_procfs_dir != 0) {
      proc_remove();
      nvswitch_procfs_dir = 0;
    }
  }
  return 0xfffffff3;
}


// ===== 00131b90 nvswitch_procfs_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00131c01) */
/* WARNING: Removing unreachable block (ram,0x00131c27) */

undefined8 nvswitch_procfs_init(void)

{
  long lVar1;
  undefined8 in_R9;
  undefined8 uVar2;
  
  uVar2 = 0x131b99;
  nvswitch_procfs_dir = proc_mkdir_mode("driver/nvidia-nvswitch",0x416d,0);
  if (nvswitch_procfs_dir != 0) {
    lVar1 = proc_create_data("permissions",0x8124,nvswitch_procfs_dir,nv_procfs_permissions_fops,0,
                             in_R9,uVar2);
    if (lVar1 != 0) {
      nvswitch_procfs_devices = proc_mkdir_mode("devices",0x416d,nvswitch_procfs_dir);
      if (nvswitch_procfs_devices != 0) {
        return 0;
      }
    }
    if (nvswitch_procfs_dir != 0) {
      proc_remove();
      nvswitch_procfs_dir = 0;
    }
  }
  return 0xfffffff3;
}


// ===== 00131c30 __pfx_nvswitch_i2c_algo_functionality =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00131c4e) */

undefined8 __pfx_nvswitch_i2c_algo_functionality(void)

{
  return 0x7f0001;
}


// ===== 00131c40 nvswitch_i2c_algo_functionality =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00131c4e) */

undefined8 nvswitch_i2c_algo_functionality(void)

{
  return 0x7f0001;
}


// ===== 00131c60 __pfx_nvswitch_i2c_algo_smbus_xfer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00131d6a) */
/* WARNING: Removing unreachable block (ram,0x00131d8c) */

undefined8
__pfx_nvswitch_i2c_algo_smbus_xfer
          (long param_1,uint param_2,undefined8 param_3,char param_4,undefined1 param_5,int param_6)

{
  long lVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  char cVar4;
  undefined1 uVar5;
  undefined1 *unaff_retaddr;
  undefined1 uStack_39;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0xb0) + 0x78);
  if (lVar1 == 0) {
    return 0xffffffed;
  }
  uStack_39 = param_5;
  uVar3 = mutex_lock_interruptible(lVar1 + 0x38);
  if ((int)uVar3 != 0) {
    return uVar3;
  }
  if (*(char *)(lVar1 + 0x120) != '\0') {
    _printk(&DAT_00db0973,lVar1);
    uVar3 = FUN_00131deb();
    return uVar3;
  }
  if (*(undefined4 **)(param_1 + 0x18) == (undefined4 *)0x0) {
    uVar2 = 8;
    goto LAB_00131d3d;
  }
  uVar5 = uStack_39;
  if (param_6 == 2) {
    uVar3 = 1;
    cVar4 = (param_4 != '\x01') + '\x02';
  }
  else if (param_6 < 3) {
    uVar5 = 0;
    if (param_6 == 0) {
      unaff_retaddr = (undefined1 *)0x0;
      uVar3 = 0;
      cVar4 = (param_4 != '\x01') + '\x04';
    }
    else {
      if (param_6 != 1) goto LAB_00131df5;
      if (param_4 == '\x01') {
        cVar4 = '\0';
        uVar3 = 1;
      }
      else {
        unaff_retaddr = &uStack_39;
        cVar4 = '\x01';
        uVar3 = 1;
      }
    }
  }
  else {
    if (param_6 != 3) {
LAB_00131df5:
      uVar2 = 1;
      goto LAB_00131d3d;
    }
    uVar3 = 2;
    cVar4 = (param_4 != '\x01') + '\x02';
  }
  uVar2 = nvswitch_lib_i2c_transfer
                    (*(undefined8 *)(lVar1 + 0x50),**(undefined4 **)(param_1 + 0x18),cVar4,
                     param_2 & 0x7f,uVar5,uVar3,unaff_retaddr);
LAB_00131d3d:
  mutex_unlock(lVar1 + 0x38);
  uVar3 = nvswitch_map_status(uVar2);
  return uVar3;
}


// ===== 00131c70 nvswitch_i2c_algo_smbus_xfer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00131d6a) */
/* WARNING: Removing unreachable block (ram,0x00131d8c) */

undefined8
nvswitch_i2c_algo_smbus_xfer
          (long param_1,uint param_2,undefined8 param_3,char param_4,undefined1 param_5,int param_6)

{
  long lVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  char cVar4;
  undefined1 uVar5;
  undefined1 *unaff_retaddr;
  undefined1 local_39;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0xb0) + 0x78);
  if (lVar1 == 0) {
    return 0xffffffed;
  }
  local_39 = param_5;
  uVar3 = mutex_lock_interruptible(lVar1 + 0x38);
  if ((int)uVar3 != 0) {
    return uVar3;
  }
  if (*(char *)(lVar1 + 0x120) != '\0') {
    _printk(&DAT_00db0973,lVar1);
    uVar3 = FUN_00131deb();
    return uVar3;
  }
  if (*(undefined4 **)(param_1 + 0x18) == (undefined4 *)0x0) {
    uVar2 = 8;
    goto LAB_00131d3d;
  }
  uVar5 = local_39;
  if (param_6 == 2) {
    uVar3 = 1;
    cVar4 = (param_4 != '\x01') + '\x02';
  }
  else if (param_6 < 3) {
    uVar5 = 0;
    if (param_6 == 0) {
      unaff_retaddr = (undefined1 *)0x0;
      uVar3 = 0;
      cVar4 = (param_4 != '\x01') + '\x04';
    }
    else {
      if (param_6 != 1) goto LAB_00131df5;
      if (param_4 == '\x01') {
        cVar4 = '\0';
        uVar3 = 1;
      }
      else {
        unaff_retaddr = &local_39;
        cVar4 = '\x01';
        uVar3 = 1;
      }
    }
  }
  else {
    if (param_6 != 3) {
LAB_00131df5:
      uVar2 = 1;
      goto LAB_00131d3d;
    }
    uVar3 = 2;
    cVar4 = (param_4 != '\x01') + '\x02';
  }
  uVar2 = nvswitch_lib_i2c_transfer
                    (*(undefined8 *)(lVar1 + 0x50),**(undefined4 **)(param_1 + 0x18),cVar4,
                     param_2 & 0x7f,uVar5,uVar3,unaff_retaddr);
LAB_00131d3d:
  mutex_unlock(lVar1 + 0x38);
  uVar3 = nvswitch_map_status(uVar2);
  return uVar3;
}


// ===== 00131deb FUN_00131deb =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00131d6a) */

void FUN_00131deb(void)

{
  long unaff_R15;
  
  mutex_unlock(unaff_R15 + 0x38);
  nvswitch_map_status(8);
  return;
}


// ===== 00131e20 __pfx_nvswitch_i2c_algo_master_xfer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00131eed) */
/* WARNING: Removing unreachable block (ram,0x00131f48) */

ulong __pfx_nvswitch_i2c_algo_master_xfer(long param_1,ushort *param_2,uint param_3)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort uVar3;
  undefined4 uVar4;
  long lVar5;
  uint uVar6;
  int iVar7;
  ulong uVar8;
  int iVar9;
  
  lVar5 = *(long *)(*(long *)(param_1 + 0xb0) + 0x78);
  if (lVar5 == 0) {
    uVar8 = 0xffffffed;
  }
  else {
    uVar8 = (ulong)param_3;
    uVar6 = mutex_lock_interruptible(lVar5 + 0x38);
    if (uVar6 != 0) {
      return (ulong)uVar6;
    }
    if (*(char *)(lVar5 + 0x120) != '\0') {
      _printk(&DAT_00db0973,lVar5);
      uVar8 = FUN_00131f4d();
      return uVar8;
    }
    if (*(undefined4 **)(param_1 + 0x18) == (undefined4 *)0x0) {
      iVar7 = 8;
    }
    else {
      iVar7 = 0;
      if (0 < (int)param_3) {
        uVar4 = **(undefined4 **)(param_1 + 0x18);
        iVar9 = 0;
        while (puVar1 = param_2 + 1, (*puVar1 & 0xfdfe) == 0) {
          uVar3 = *param_2;
          puVar2 = param_2 + 2;
          iVar9 = iVar9 + 1;
          param_2 = param_2 + 8;
          iVar7 = nvswitch_lib_i2c_transfer
                            (*(undefined8 *)(lVar5 + 0x50),uVar4,~*puVar1 & 1,uVar3 & 0x7f,0,*puVar2
                            );
          if (((int)param_3 <= iVar9) || (iVar7 != 0)) goto LAB_00131eb8;
        }
        iVar7 = 0xd;
      }
    }
LAB_00131eb8:
    mutex_unlock(lVar5 + 0x38);
    uVar6 = nvswitch_map_status(iVar7);
    if (uVar6 != 0) {
      uVar8 = (ulong)uVar6;
    }
  }
  return uVar8;
}


// ===== 00131e30 nvswitch_i2c_algo_master_xfer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00131eed) */
/* WARNING: Removing unreachable block (ram,0x00131f48) */

ulong nvswitch_i2c_algo_master_xfer(long param_1,ushort *param_2,uint param_3)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort uVar3;
  undefined4 uVar4;
  long lVar5;
  uint uVar6;
  int iVar7;
  ulong uVar8;
  int iVar9;
  
  lVar5 = *(long *)(*(long *)(param_1 + 0xb0) + 0x78);
  if (lVar5 == 0) {
    uVar8 = 0xffffffed;
  }
  else {
    uVar8 = (ulong)param_3;
    uVar6 = mutex_lock_interruptible(lVar5 + 0x38);
    if (uVar6 != 0) {
      return (ulong)uVar6;
    }
    if (*(char *)(lVar5 + 0x120) != '\0') {
      _printk(&DAT_00db0973,lVar5);
      uVar8 = FUN_00131f4d();
      return uVar8;
    }
    if (*(undefined4 **)(param_1 + 0x18) == (undefined4 *)0x0) {
      iVar7 = 8;
    }
    else {
      iVar7 = 0;
      if (0 < (int)param_3) {
        uVar4 = **(undefined4 **)(param_1 + 0x18);
        iVar9 = 0;
        while (puVar1 = param_2 + 1, (*puVar1 & 0xfdfe) == 0) {
          uVar3 = *param_2;
          puVar2 = param_2 + 2;
          iVar9 = iVar9 + 1;
          param_2 = param_2 + 8;
          iVar7 = nvswitch_lib_i2c_transfer
                            (*(undefined8 *)(lVar5 + 0x50),uVar4,~*puVar1 & 1,uVar3 & 0x7f,0,*puVar2
                            );
          if (((int)param_3 <= iVar9) || (iVar7 != 0)) goto LAB_00131eb8;
        }
        iVar7 = 0xd;
      }
    }
LAB_00131eb8:
    mutex_unlock(lVar5 + 0x38);
    uVar6 = nvswitch_map_status(iVar7);
    if (uVar6 != 0) {
      uVar8 = (ulong)uVar6;
    }
  }
  return uVar8;
}


// ===== 00131f4d FUN_00131f4d =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00131eed) */

int FUN_00131f4d(void)

{
  int iVar1;
  int unaff_EBP;
  long unaff_R15;
  
  mutex_unlock(unaff_R15 + 0x38);
  iVar1 = nvswitch_map_status(8);
  if (iVar1 != 0) {
    unaff_EBP = iVar1;
  }
  return unaff_EBP;
}


// ===== 00131f60 __pfx_nvswitch_i2c_add_adapter =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001320b2) */
/* WARNING: Removing unreachable block (ram,0x00132081) */
/* WARNING: Removing unreachable block (ram,0x001320cc) */

long __pfx_nvswitch_i2c_add_adapter(long param_1,undefined4 param_2)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  undefined4 *puVar5;
  
  if (param_1 == 0) {
    _printk(&DAT_00db098e);
    return 0;
  }
  lVar4 = nvswitch_os_malloc_trace(0x448,"nvidia/i2c_nvswitch.c",0x10c);
  if (lVar4 != 0) {
    nvswitch_os_memcpy(lVar4,nvswitch_i2c_adapter_prototype,0x448);
    puVar5 = (undefined4 *)nvswitch_os_malloc_trace(4,"nvidia/i2c_nvswitch.c",0x116);
    if (puVar5 != (undefined4 *)0x0) {
      *puVar5 = param_2;
      lVar1 = *(long *)(param_1 + 0x100);
      *(undefined4 **)(lVar4 + 0x18) = puVar5;
      *(long *)(lVar4 + 0xb0) = lVar1 + 0xd0;
      lVar1 = *(long *)(lVar1 + 0x10);
      uVar2 = nvswitch_os_snprintf
                        (lVar4 + 0x394,0x30,"NVIDIA NVSwitch i2c adapter %u at %04x:%x:%02x.%u",
                         param_2,**(undefined4 **)(lVar1 + 200),*(undefined1 *)(lVar1 + 0xd8));
      if ((uVar2 < 0x30) && (iVar3 = i2c_add_adapter(lVar4), -1 < iVar3)) {
        return lVar4;
      }
    }
    nvswitch_os_free(puVar5);
    nvswitch_os_free(lVar4);
    return 0;
  }
  return 0;
}


// ===== 00131f70 nvswitch_i2c_add_adapter =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001320b2) */
/* WARNING: Removing unreachable block (ram,0x00132081) */
/* WARNING: Removing unreachable block (ram,0x001320cc) */

long nvswitch_i2c_add_adapter(long param_1,undefined4 param_2)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  undefined4 *puVar5;
  
  if (param_1 == 0) {
    _printk(&DAT_00db098e);
    return 0;
  }
  lVar4 = nvswitch_os_malloc_trace(0x448,"nvidia/i2c_nvswitch.c",0x10c);
  if (lVar4 != 0) {
    nvswitch_os_memcpy(lVar4,nvswitch_i2c_adapter_prototype,0x448);
    puVar5 = (undefined4 *)nvswitch_os_malloc_trace(4,"nvidia/i2c_nvswitch.c",0x116);
    if (puVar5 != (undefined4 *)0x0) {
      *puVar5 = param_2;
      lVar1 = *(long *)(param_1 + 0x100);
      *(undefined4 **)(lVar4 + 0x18) = puVar5;
      *(long *)(lVar4 + 0xb0) = lVar1 + 0xd0;
      lVar1 = *(long *)(lVar1 + 0x10);
      uVar2 = nvswitch_os_snprintf
                        (lVar4 + 0x394,0x30,"NVIDIA NVSwitch i2c adapter %u at %04x:%x:%02x.%u",
                         param_2,**(undefined4 **)(lVar1 + 200),*(undefined1 *)(lVar1 + 0xd8));
      if ((uVar2 < 0x30) && (iVar3 = i2c_add_adapter(lVar4), -1 < iVar3)) {
        return lVar4;
      }
    }
    nvswitch_os_free(puVar5);
    nvswitch_os_free(lVar4);
    return 0;
  }
  return 0;
}


// ===== 001320e0 __pfx_nvswitch_i2c_del_adapter =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0013211c) */

void __pfx_nvswitch_i2c_del_adapter(long param_1)

{
  if (param_1 != 0) {
    nvswitch_os_free(*(undefined8 *)(param_1 + 0x18));
    i2c_del_adapter(param_1);
    nvswitch_os_free(param_1);
    return;
  }
  return;
}


// ===== 001320f0 nvswitch_i2c_del_adapter =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0013211c) */

void nvswitch_i2c_del_adapter(long param_1)

{
  if (param_1 != 0) {
    nvswitch_os_free(*(undefined8 *)(param_1 + 0x18));
    i2c_del_adapter(param_1);
    nvswitch_os_free(param_1);
    return;
  }
  return;
}


// ===== 00132140 resIsPartialUnmapSupported_d69453 =====

undefined8 resIsPartialUnmapSupported_d69453(void)

{
  return 0;
}


// ===== 00132150 __nvoc_down_thunk_AccessCounterBuffer_gpuresMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_AccessCounterBuffer_gpuresMap(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x310))(param_1 + -8);
  return;
}


// ===== 00132170 __nvoc_down_thunk_AccessCounterBuffer_gpuresUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_AccessCounterBuffer_gpuresUnmap(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x318))(param_1 + -8);
  return;
}


// ===== 00132190 __nvoc_down_thunk_AccessCounterBuffer_gpuresGetMapAddrSpace =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_AccessCounterBuffer_gpuresGetMapAddrSpace(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 800))(param_1 + -8);
  return;
}


// ===== 001321b0 __nvoc_up_thunk_GpuResource_accesscntrControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_accesscntrControl(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1b0))(param_1 + 8);
  return;
}


// ===== 001321d0 __nvoc_up_thunk_GpuResource_accesscntrShareCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_accesscntrShareCallback(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c8))(param_1 + 8);
  return;
}


// ===== 001321f0 __nvoc_up_thunk_GpuResource_accesscntrGetRegBaseOffsetAndSize =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_accesscntrGetRegBaseOffsetAndSize(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1d0))(param_1 + 8);
  return;
}


// ===== 00132210 __nvoc_up_thunk_GpuResource_accesscntrInternalControlForward =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_accesscntrInternalControlForward(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e0))(param_1 + 8);
  return;
}


// ===== 00132230 __nvoc_up_thunk_GpuResource_accesscntrGetInternalObjectHandle =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_accesscntrGetInternalObjectHandle(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e8))(param_1 + 8);
  return;
}


// ===== 00132250 __nvoc_up_thunk_RmResource_accesscntrAccessCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_accesscntrAccessCallback
               (long param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0xf0))(param_1 + 0x10,param_2,param_3,param_4);
  return;
}


// ===== 00132270 __nvoc_up_thunk_RmResource_accesscntrGetMemInterMapParams =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_accesscntrGetMemInterMapParams(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x100))(param_1 + 0x10);
  return;
}


// ===== 00132290 __nvoc_up_thunk_RmResource_accesscntrCheckMemInterUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_accesscntrCheckMemInterUnmap(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x108))(param_1 + 0x10,param_2);
  return;
}


// ===== 001322b0 __nvoc_up_thunk_RmResource_accesscntrGetMemoryMappingDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_accesscntrGetMemoryMappingDescriptor(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x110))(param_1 + 0x10);
  return;
}


// ===== 001322d0 __nvoc_up_thunk_RmResource_accesscntrControlSerialization_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_accesscntrControlSerialization_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x118))(param_1 + 0x10);
  return;
}


// ===== 001322f0 __nvoc_up_thunk_RmResource_accesscntrControlSerialization_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_accesscntrControlSerialization_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x120))(param_1 + 0x10);
  return;
}


// ===== 00132310 __nvoc_up_thunk_RmResource_accesscntrControl_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_accesscntrControl_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x128))(param_1 + 0x10);
  return;
}


// ===== 00132330 __nvoc_up_thunk_RmResource_accesscntrControl_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_accesscntrControl_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x130))(param_1 + 0x10);
  return;
}


// ===== 00132350 __nvoc_up_thunk_RsResource_accesscntrCanCopy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_accesscntrCanCopy(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x30))(param_1 + 0x18);
  return;
}


// ===== 00132370 __nvoc_up_thunk_RsResource_accesscntrIsDuplicate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_accesscntrIsDuplicate(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x38))(param_1 + 0x18);
  return;
}


// ===== 00132390 __nvoc_up_thunk_RsResource_accesscntrPreDestruct =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_accesscntrPreDestruct(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x40))(param_1 + 0x18);
  return;
}


// ===== 001323b0 __nvoc_up_thunk_RsResource_accesscntrControlFilter =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_accesscntrControlFilter(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x50))(param_1 + 0x18);
  return;
}


// ===== 001323d0 __nvoc_up_thunk_RsResource_accesscntrIsPartialUnmapSupported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_accesscntrIsPartialUnmapSupported(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x88))(param_1 + 0x18);
  return;
}


// ===== 001323f0 __nvoc_up_thunk_RsResource_accesscntrMapTo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_accesscntrMapTo(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x90))(param_1 + 0x18);
  return;
}


// ===== 00132410 __nvoc_up_thunk_RsResource_accesscntrUnmapFrom =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_accesscntrUnmapFrom(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x98))(param_1 + 0x18);
  return;
}


// ===== 00132430 __nvoc_up_thunk_RsResource_accesscntrGetRefCount =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_accesscntrGetRefCount(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0xa0))(param_1 + 0x18);
  return;
}


// ===== 00132450 __nvoc_up_thunk_RsResource_accesscntrAddAdditionalDependants =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_accesscntrAddAdditionalDependants(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x18) + 0xb8))(param_1,param_2 + 0x18);
  return;
}


// ===== 00132470 __nvoc_up_thunk_Notifier_accesscntrGetNotificationListPtr =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_accesscntrGetNotificationListPtr(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x108) + 0x58))(param_1 + 0x108);
  return;
}


// ===== 00132490 __nvoc_up_thunk_Notifier_accesscntrGetNotificationShare =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_accesscntrGetNotificationShare(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x108) + 0x60))(param_1 + 0x108);
  return;
}


// ===== 001324b0 __nvoc_up_thunk_Notifier_accesscntrSetNotificationShare =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_accesscntrSetNotificationShare(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x108) + 0x68))(param_1 + 0x108);
  return;
}


// ===== 001324d0 __nvoc_up_thunk_Notifier_accesscntrUnregisterEvent =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_accesscntrUnregisterEvent(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x108) + 0x70))(param_1 + 0x108);
  return;
}


// ===== 001324f0 __nvoc_up_thunk_Notifier_accesscntrGetOrAllocNotifShare =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_accesscntrGetOrAllocNotifShare(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x108) + 0x78))(param_1 + 0x108);
  return;
}


// ===== 00132510 __nvoc_dtor_AccessCounterBuffer =====

void __nvoc_dtor_AccessCounterBuffer(long param_1)

{
  accesscntrDestruct_IMPL();
  __nvoc_dtor_GpuResource(param_1 + 8);
  __nvoc_dtor_Notifier(param_1 + 0x108);
  return;
}


// ===== 00132540 __nvoc_ctor_AccessCounterBuffer =====

ulong __nvoc_ctor_AccessCounterBuffer(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  ulong uVar2;
  
  uVar2 = __nvoc_ctor_GpuResource(param_1 + 8);
  if ((int)uVar2 != 0) {
    return uVar2;
  }
  uVar1 = __nvoc_ctor_Notifier(param_1 + 0x108,param_2);
  if (uVar1 == 0) {
    uVar2 = accesscntrConstruct_IMPL(param_1,param_2,param_3);
    uVar1 = (uint)uVar2;
    if (uVar1 == 0) {
      return uVar2;
    }
    __nvoc_dtor_Notifier(param_1 + 0x108);
  }
  __nvoc_dtor_GpuResource(param_1 + 8);
  return (ulong)uVar1;
}


// ===== 001325e0 __nvoc_objCreate_AccessCounterBuffer =====

int __nvoc_objCreate_AccessCounterBuffer
              (long *param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  
  if ((param_3 & 2) == 0) {
    puVar3 = (undefined8 *)portMemAllocNonPaged(0x188);
    if (puVar3 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_access_cntr_buffer_nvoc.c",0x2ce);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar3 = (undefined8 *)*param_1, puVar3 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_access_cntr_buffer_nvoc.c",0x2c6);
    return 0x3b;
  }
  portMemSet(puVar3,0,0x188);
  puVar1 = puVar3 + 4;
  *(uint *)((long)puVar3 + 0x4c) = param_3;
  if ((param_2 == 0) || ((param_3 & 1) != 0)) {
    puVar3[6] = 0;
    lVar4 = 0;
  }
  else {
    lVar4 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(lVar4,puVar1);
  }
  puVar3[0x27] = puVar1;
  puVar3[0x28] = puVar3 + 3;
  puVar3[0x29] = puVar3 + 0x10;
  puVar3[0x2a] = puVar3 + 2;
  puVar3[0x2c] = puVar3 + 0x22;
  puVar3[0x2b] = puVar3 + 1;
  puVar3[0x2d] = puVar3 + 0x21;
  puVar3[0x2e] = puVar3;
  __nvoc_init__GpuResource();
  __nvoc_init__Notifier(puVar3 + 0x21);
  puVar3[4] = 0x5a7540;
  puVar3[3] = 0x5a7528;
  puVar3[0x10] = 0x5a75e8;
  puVar3[2] = 0x5a7510;
  puVar3[1] = 0x5a74f8;
  puVar3[0x22] = 0x5a7788;
  puVar3[0x21] = 0x5a7770;
  *puVar3 = __nvoc_metadata__AccessCounterBuffer;
  iVar2 = __nvoc_ctor_AccessCounterBuffer(puVar3,param_4,param_5);
  if (iVar2 == 0) {
    *param_1 = (long)puVar3;
  }
  else {
    if (lVar4 != 0) {
      objRemoveChild_IMPL(lVar4,puVar1);
    }
    if ((param_3 & 2) == 0) {
      portMemFree(puVar3);
      *param_1 = 0;
    }
    else {
      portMemSet(puVar3,0,0x188);
    }
  }
  return iVar2;
}


// ===== 00132830 __nvoc_objCreateDynamic_AccessCounterBuffer =====

void __nvoc_objCreateDynamic_AccessCounterBuffer
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
      goto LAB_0013285e;
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
LAB_0013285e:
  __nvoc_objCreate_AccessCounterBuffer(param_1,param_2,param_3,uVar5,*puVar4);
  return;
}


// ===== 00132890 resIsPartialUnmapSupported_d69453 =====

undefined8 resIsPartialUnmapSupported_d69453(void)

{
  return 0;
}


// ===== 001328a0 __nvoc_down_thunk_BinaryApi_gpuresControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_BinaryApi_gpuresControl(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x290))(param_1 + -8);
  return;
}


// ===== 001328c0 __nvoc_up_thunk_GpuResource_binapiMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_binapiMap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1b8))(param_1 + 8);
  return;
}


// ===== 001328e0 __nvoc_up_thunk_GpuResource_binapiUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_binapiUnmap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c0))(param_1 + 8);
  return;
}


// ===== 00132900 __nvoc_up_thunk_GpuResource_binapiShareCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_binapiShareCallback(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c8))(param_1 + 8);
  return;
}


// ===== 00132920 __nvoc_up_thunk_GpuResource_binapiGetRegBaseOffsetAndSize =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_binapiGetRegBaseOffsetAndSize(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1d0))(param_1 + 8);
  return;
}


// ===== 00132940 __nvoc_up_thunk_GpuResource_binapiGetMapAddrSpace =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_binapiGetMapAddrSpace(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1d8))(param_1 + 8);
  return;
}


// ===== 00132960 __nvoc_up_thunk_GpuResource_binapiInternalControlForward =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_binapiInternalControlForward(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e0))(param_1 + 8);
  return;
}


// ===== 00132980 __nvoc_up_thunk_GpuResource_binapiGetInternalObjectHandle =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_binapiGetInternalObjectHandle(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e8))(param_1 + 8);
  return;
}


// ===== 001329a0 __nvoc_up_thunk_RmResource_binapiAccessCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_binapiAccessCallback
               (long param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0xf0))(param_1 + 0x10,param_2,param_3,param_4);
  return;
}


// ===== 001329c0 __nvoc_up_thunk_RmResource_binapiGetMemInterMapParams =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_binapiGetMemInterMapParams(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x100))(param_1 + 0x10);
  return;
}


// ===== 001329e0 __nvoc_up_thunk_RmResource_binapiCheckMemInterUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_binapiCheckMemInterUnmap(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x108))(param_1 + 0x10,param_2);
  return;
}


// ===== 00132a00 __nvoc_up_thunk_RmResource_binapiGetMemoryMappingDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_binapiGetMemoryMappingDescriptor(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x110))(param_1 + 0x10);
  return;
}


// ===== 00132a20 __nvoc_up_thunk_RmResource_binapiControlSerialization_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_binapiControlSerialization_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x118))(param_1 + 0x10);
  return;
}


// ===== 00132a40 __nvoc_up_thunk_RmResource_binapiControlSerialization_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_binapiControlSerialization_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x120))(param_1 + 0x10);
  return;
}


// ===== 00132a60 __nvoc_up_thunk_RmResource_binapiControl_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_binapiControl_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x128))(param_1 + 0x10);
  return;
}


// ===== 00132a80 __nvoc_up_thunk_RmResource_binapiControl_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_binapiControl_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x130))(param_1 + 0x10);
  return;
}


// ===== 00132aa0 __nvoc_up_thunk_RsResource_binapiCanCopy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_binapiCanCopy(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x30))(param_1 + 0x18);
  return;
}


// ===== 00132ac0 __nvoc_up_thunk_RsResource_binapiIsDuplicate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_binapiIsDuplicate(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x38))(param_1 + 0x18);
  return;
}


// ===== 00132ae0 __nvoc_up_thunk_RsResource_binapiPreDestruct =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_binapiPreDestruct(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x40))(param_1 + 0x18);
  return;
}


// ===== 00132b00 __nvoc_up_thunk_RsResource_binapiControlFilter =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_binapiControlFilter(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x50))(param_1 + 0x18);
  return;
}


// ===== 00132b20 __nvoc_up_thunk_RsResource_binapiIsPartialUnmapSupported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_binapiIsPartialUnmapSupported(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x88))(param_1 + 0x18);
  return;
}


// ===== 00132b40 __nvoc_up_thunk_RsResource_binapiMapTo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_binapiMapTo(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x90))(param_1 + 0x18);
  return;
}


// ===== 00132b60 __nvoc_up_thunk_RsResource_binapiUnmapFrom =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_binapiUnmapFrom(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x98))(param_1 + 0x18);
  return;
}


// ===== 00132b80 __nvoc_up_thunk_RsResource_binapiGetRefCount =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_binapiGetRefCount(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0xa0))(param_1 + 0x18);
  return;
}


// ===== 00132ba0 __nvoc_up_thunk_RsResource_binapiAddAdditionalDependants =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_binapiAddAdditionalDependants(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x18) + 0xb8))(param_1,param_2 + 0x18);
  return;
}


// ===== 00132bc0 __nvoc_down_thunk_BinaryApiPrivileged_binapiControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_BinaryApiPrivileged_binapiControl(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x370))(param_1 + -8);
  return;
}


// ===== 00132be0 __nvoc_up_thunk_GpuResource_binapiprivMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_binapiprivMap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1b8))(param_1 + 0x10);
  return;
}


// ===== 00132c00 __nvoc_up_thunk_GpuResource_binapiprivUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_binapiprivUnmap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1c0))(param_1 + 0x10);
  return;
}


// ===== 00132c20 __nvoc_up_thunk_GpuResource_binapiprivShareCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_binapiprivShareCallback(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1c8))(param_1 + 0x10);
  return;
}


// ===== 00132c40 __nvoc_up_thunk_GpuResource_binapiprivGetRegBaseOffsetAndSize =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_binapiprivGetRegBaseOffsetAndSize(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1d0))(param_1 + 0x10);
  return;
}


// ===== 00132c60 __nvoc_up_thunk_GpuResource_binapiprivGetMapAddrSpace =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_binapiprivGetMapAddrSpace(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1d8))(param_1 + 0x10);
  return;
}


// ===== 00132c80 __nvoc_up_thunk_GpuResource_binapiprivInternalControlForward =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_binapiprivInternalControlForward(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1e0))(param_1 + 0x10);
  return;
}


// ===== 00132ca0 __nvoc_up_thunk_GpuResource_binapiprivGetInternalObjectHandle =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_binapiprivGetInternalObjectHandle(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1e8))(param_1 + 0x10);
  return;
}


// ===== 00132cc0 __nvoc_up_thunk_RmResource_binapiprivAccessCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_binapiprivAccessCallback
               (long param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0xf0))(param_1 + 0x18,param_2,param_3,param_4);
  return;
}


// ===== 00132ce0 __nvoc_up_thunk_RmResource_binapiprivGetMemInterMapParams =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_binapiprivGetMemInterMapParams(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x100))(param_1 + 0x18);
  return;
}


// ===== 00132d00 __nvoc_up_thunk_RmResource_binapiprivCheckMemInterUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_binapiprivCheckMemInterUnmap(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x108))(param_1 + 0x18,param_2);
  return;
}


// ===== 00132d20 __nvoc_up_thunk_RmResource_binapiprivGetMemoryMappingDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_binapiprivGetMemoryMappingDescriptor(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x110))(param_1 + 0x18);
  return;
}


// ===== 00132d40 __nvoc_up_thunk_RmResource_binapiprivControlSerialization_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_binapiprivControlSerialization_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x118))(param_1 + 0x18);
  return;
}


// ===== 00132d60 __nvoc_up_thunk_RmResource_binapiprivControlSerialization_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_binapiprivControlSerialization_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x120))(param_1 + 0x18);
  return;
}


// ===== 00132d80 __nvoc_up_thunk_RmResource_binapiprivControl_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_binapiprivControl_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x128))(param_1 + 0x18);
  return;
}


// ===== 00132da0 __nvoc_up_thunk_RmResource_binapiprivControl_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_binapiprivControl_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x130))(param_1 + 0x18);
  return;
}


// ===== 00132dc0 __nvoc_up_thunk_RsResource_binapiprivCanCopy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_binapiprivCanCopy(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x30))(param_1 + 0x20);
  return;
}


// ===== 00132de0 __nvoc_up_thunk_RsResource_binapiprivIsDuplicate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_binapiprivIsDuplicate(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x38))(param_1 + 0x20);
  return;
}


// ===== 00132e00 __nvoc_up_thunk_RsResource_binapiprivPreDestruct =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_binapiprivPreDestruct(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x40))(param_1 + 0x20);
  return;
}


// ===== 00132e20 __nvoc_up_thunk_RsResource_binapiprivControlFilter =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_binapiprivControlFilter(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x50))(param_1 + 0x20);
  return;
}


// ===== 00132e40 __nvoc_up_thunk_RsResource_binapiprivIsPartialUnmapSupported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_binapiprivIsPartialUnmapSupported(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x88))(param_1 + 0x20);
  return;
}


// ===== 00132e60 __nvoc_up_thunk_RsResource_binapiprivMapTo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_binapiprivMapTo(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x90))(param_1 + 0x20);
  return;
}


// ===== 00132e80 __nvoc_up_thunk_RsResource_binapiprivUnmapFrom =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_binapiprivUnmapFrom(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x98))(param_1 + 0x20);
  return;
}


// ===== 00132ea0 __nvoc_up_thunk_RsResource_binapiprivGetRefCount =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_binapiprivGetRefCount(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0xa0))(param_1 + 0x20);
  return;
}


// ===== 00132ec0 __nvoc_up_thunk_RsResource_binapiprivAddAdditionalDependants =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_binapiprivAddAdditionalDependants(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x20) + 0xb8))(param_1,param_2 + 0x20);
  return;
}


// ===== 00132ee0 __nvoc_dtor_BinaryApi =====

void __nvoc_dtor_BinaryApi(long param_1)

{
  __nvoc_dtor_GpuResource(param_1 + 8);
  return;
}


// ===== 00132ef0 __nvoc_dtor_BinaryApiPrivileged =====

void __nvoc_dtor_BinaryApiPrivileged(long param_1)

{
  __nvoc_dtor_GpuResource(param_1 + 0x10);
  return;
}


// ===== 00132f00 __nvoc_objCreate_BinaryApi =====

int __nvoc_objCreate_BinaryApi
              (long *param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  long local_58;
  
  if ((param_3 & 2) == 0) {
    puVar4 = (undefined8 *)portMemAllocNonPaged(0x138);
    if (puVar4 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_binary_api_nvoc.c",0x1e1);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar4 = (undefined8 *)*param_1, puVar4 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_binary_api_nvoc.c",0x1d9);
    return 0x3b;
  }
  portMemSet(puVar4,0,0x138);
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
  puVar4[0x21] = puVar1;
  puVar4[0x22] = puVar4 + 3;
  puVar4[0x23] = puVar4 + 0x10;
  puVar4[0x24] = puVar4 + 2;
  puVar4[0x25] = puVar2;
  puVar4[0x26] = puVar4;
  __nvoc_init__GpuResource(puVar2);
  puVar4[4] = 0x5a8480;
  puVar4[3] = 0x5a8468;
  puVar4[0x10] = 0x5a8528;
  puVar4[2] = 0x5a8450;
  puVar4[1] = 0x5a8438;
  *puVar4 = __nvoc_metadata__BinaryApi;
  iVar3 = __nvoc_ctor_GpuResource(puVar2,param_4,param_5);
  if (iVar3 == 0) {
    iVar3 = binapiConstruct_IMPL(puVar4,param_4,param_5);
    if (iVar3 == 0) {
      *param_1 = (long)puVar4;
      return 0;
    }
    __nvoc_dtor_GpuResource(puVar2);
  }
  if (local_58 != 0) {
    objRemoveChild_IMPL(local_58,puVar1);
  }
  if ((param_3 & 2) == 0) {
    portMemFree(puVar4);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar4,0,0x138);
  }
  return iVar3;
}


// ===== 00133180 __nvoc_objCreateDynamic_BinaryApi =====

void __nvoc_objCreateDynamic_BinaryApi
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
      goto LAB_001331ae;
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
LAB_001331ae:
  __nvoc_objCreate_BinaryApi(param_1,param_2,param_3,uVar5,*puVar4);
  return;
}


// ===== 001331e0 __nvoc_objCreate_BinaryApiPrivileged =====

int __nvoc_objCreate_BinaryApiPrivileged
              (long *param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  int iVar4;
  undefined8 *puVar5;
  long local_48;
  
  if ((param_3 & 2) == 0) {
    puVar5 = (undefined8 *)portMemAllocNonPaged(0x178);
    if (puVar5 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_binary_api_nvoc.c",0x428);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar5 = (undefined8 *)*param_1, puVar5 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_binary_api_nvoc.c",0x420);
    return 0x3b;
  }
  portMemSet(puVar5,0,0x178);
  puVar1 = puVar5 + 5;
  *(uint *)((long)puVar5 + 0x54) = param_3;
  if ((param_2 == 0) || ((param_3 & 1) != 0)) {
    puVar5[7] = 0;
    local_48 = 0;
  }
  else {
    local_48 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(local_48,puVar1);
  }
  puVar2 = puVar5 + 1;
  puVar5[0x28] = puVar1;
  puVar5[0x29] = puVar5 + 4;
  puVar3 = puVar5 + 2;
  puVar5[0x2a] = puVar5 + 0x11;
  puVar5[0x2b] = puVar5 + 3;
  puVar5[0x2d] = puVar2;
  puVar5[0x23] = puVar5 + 4;
  puVar5[0x24] = puVar5 + 0x11;
  puVar5[0x25] = puVar5 + 3;
  puVar5[0x27] = puVar2;
  puVar5[0x2c] = puVar3;
  puVar5[0x2e] = puVar5;
  puVar5[0x22] = puVar1;
  puVar5[0x26] = puVar3;
  __nvoc_init__GpuResource(puVar3);
  puVar5[5] = 0x5a7fb8;
  puVar5[4] = 0x5a7fa0;
  puVar5[0x11] = 0x5a8060;
  puVar5[3] = 0x5a7f88;
  puVar5[2] = 0x5a7f70;
  puVar5[1] = 0x5a7f58;
  *puVar5 = __nvoc_metadata__BinaryApiPrivileged;
  iVar4 = __nvoc_ctor_GpuResource(puVar3,param_4,param_5);
  if (iVar4 == 0) {
    iVar4 = binapiConstruct_IMPL(puVar2,param_4,param_5);
    if (iVar4 == 0) {
      iVar4 = binapiprivConstruct_IMPL(puVar5,param_4,param_5);
      if (iVar4 == 0) {
        *param_1 = (long)puVar5;
        return 0;
      }
      __nvoc_dtor_GpuResource(puVar3);
    }
    else {
      __nvoc_dtor_GpuResource(puVar3);
    }
  }
  if (local_48 != 0) {
    objRemoveChild_IMPL(local_48,puVar1);
  }
  if ((param_3 & 2) == 0) {
    portMemFree(puVar5);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar5,0,0x178);
  }
  return iVar4;
}


// ===== 001334d0 __nvoc_objCreateDynamic_BinaryApiPrivileged =====

void __nvoc_objCreateDynamic_BinaryApiPrivileged
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
      goto LAB_001334fe;
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
LAB_001334fe:
  __nvoc_objCreate_BinaryApiPrivileged(param_1,param_2,param_3,uVar5,*puVar4);
  return;
}


// ===== 00133530 kgspGetBinArchiveGspRmBoot_TU102 =====

undefined * kgspGetBinArchiveGspRmBoot_TU102(void)

{
  return &__kgspGetBinArchiveGspRmBoot_TU102;
}


// ===== 00133540 kgspGetBinArchiveGspRmBoot_GA100 =====

undefined * kgspGetBinArchiveGspRmBoot_GA100(void)

{
  return &__kgspGetBinArchiveGspRmBoot_GA100;
}


// ===== 00133550 kgspGetBinArchiveGspRmBoot_GA102 =====

undefined * kgspGetBinArchiveGspRmBoot_GA102(void)

{
  return &__kgspGetBinArchiveGspRmBoot_GA102;
}


// ===== 00133560 kgspGetBinArchiveGspRmBoot_AD102 =====

undefined * kgspGetBinArchiveGspRmBoot_AD102(void)

{
  return &__kgspGetBinArchiveGspRmBoot_AD102;
}


// ===== 00133570 kgspGetBinArchiveGspRmBoot_GH100 =====

undefined * kgspGetBinArchiveGspRmBoot_GH100(void)

{
  return &__kgspGetBinArchiveGspRmBoot_GH100;
}


// ===== 00133580 kgspGetBinArchiveGspRmBoot_GB100 =====

undefined * kgspGetBinArchiveGspRmBoot_GB100(void)

{
  return &__kgspGetBinArchiveGspRmBoot_GB100;
}


// ===== 00133590 kgspGetBinArchiveGspRmBoot_GB10B =====

undefined * kgspGetBinArchiveGspRmBoot_GB10B(void)

{
  return &__kgspGetBinArchiveGspRmBoot_GB10B;
}


// ===== 001335a0 kgspGetBinArchiveGspRmBoot_GB202 =====

undefined * kgspGetBinArchiveGspRmBoot_GB202(void)

{
  return &__kgspGetBinArchiveGspRmBoot_GB202;
}


// ===== 001335b0 kgspGetBinArchiveGspRmBoot_GB20B =====

undefined * kgspGetBinArchiveGspRmBoot_GB20B(void)

{
  return &__kgspGetBinArchiveGspRmBoot_GB20B;
}


// ===== 001335c0 kgspGetBinArchiveConcatenatedFMCDesc_GH100 =====

undefined * kgspGetBinArchiveConcatenatedFMCDesc_GH100(void)

{
  return &__kgspGetBinArchiveConcatenatedFMCDesc_GH100;
}


// ===== 001335d0 kgspGetBinArchiveConcatenatedFMCDesc_GB100 =====

undefined * kgspGetBinArchiveConcatenatedFMCDesc_GB100(void)

{
  return &__kgspGetBinArchiveConcatenatedFMCDesc_GB100;
}


// ===== 001335e0 kgspGetBinArchiveConcatenatedFMCDesc_GB202 =====

undefined * kgspGetBinArchiveConcatenatedFMCDesc_GB202(void)

{
  return &__kgspGetBinArchiveConcatenatedFMCDesc_GB202;
}


// ===== 001335f0 kgspGetBinArchiveConcatenatedFMC_GH100 =====

undefined * kgspGetBinArchiveConcatenatedFMC_GH100(void)

{
  return &__kgspGetBinArchiveConcatenatedFMC_GH100;
}


// ===== 00133600 kgspGetBinArchiveConcatenatedFMC_GB100 =====

undefined * kgspGetBinArchiveConcatenatedFMC_GB100(void)

{
  return &__kgspGetBinArchiveConcatenatedFMC_GB100;
}


// ===== 00133610 kgspGetBinArchiveConcatenatedFMC_GB202 =====

undefined * kgspGetBinArchiveConcatenatedFMC_GB202(void)

{
  return &__kgspGetBinArchiveConcatenatedFMC_GB202;
}


// ===== 00133620 kgspGetBinArchiveGspRmFmcGfwDebugSigned_GH100 =====

undefined * kgspGetBinArchiveGspRmFmcGfwDebugSigned_GH100(void)

{
  return &__kgspGetBinArchiveGspRmFmcGfwDebugSigned_GH100;
}


// ===== 00133630 kgspGetBinArchiveGspRmFmcGfwDebugSigned_GB100 =====

undefined * kgspGetBinArchiveGspRmFmcGfwDebugSigned_GB100(void)

{
  return &__kgspGetBinArchiveGspRmFmcGfwDebugSigned_GB100;
}


// ===== 00133640 kgspGetBinArchiveGspRmFmcGfwDebugSigned_GB10B =====

undefined * kgspGetBinArchiveGspRmFmcGfwDebugSigned_GB10B(void)

{
  return &__kgspGetBinArchiveGspRmFmcGfwDebugSigned_GB10B;
}


// ===== 00133650 kgspGetBinArchiveGspRmFmcGfwDebugSigned_GB202 =====

undefined * kgspGetBinArchiveGspRmFmcGfwDebugSigned_GB202(void)

{
  return &__kgspGetBinArchiveGspRmFmcGfwDebugSigned_GB202;
}


// ===== 00133660 kgspGetBinArchiveGspRmFmcGfwDebugSigned_GB20B =====

undefined * kgspGetBinArchiveGspRmFmcGfwDebugSigned_GB20B(void)

{
  return &__kgspGetBinArchiveGspRmFmcGfwDebugSigned_GB20B;
}


// ===== 00133670 kgspGetBinArchiveGspRmFmcGfwProdSigned_GH100 =====

undefined * kgspGetBinArchiveGspRmFmcGfwProdSigned_GH100(void)

{
  return &__kgspGetBinArchiveGspRmFmcGfwProdSigned_GH100;
}


// ===== 00133680 kgspGetBinArchiveGspRmFmcGfwProdSigned_GB100 =====

undefined * kgspGetBinArchiveGspRmFmcGfwProdSigned_GB100(void)

{
  return &__kgspGetBinArchiveGspRmFmcGfwProdSigned_GB100;
}


// ===== 00133690 kgspGetBinArchiveGspRmFmcGfwProdSigned_GB10B =====

undefined * kgspGetBinArchiveGspRmFmcGfwProdSigned_GB10B(void)

{
  return &__kgspGetBinArchiveGspRmFmcGfwProdSigned_GB10B;
}


// ===== 001336a0 kgspGetBinArchiveGspRmFmcGfwProdSigned_GB202 =====

undefined * kgspGetBinArchiveGspRmFmcGfwProdSigned_GB202(void)

{
  return &__kgspGetBinArchiveGspRmFmcGfwProdSigned_GB202;
}


// ===== 001336b0 kgspGetBinArchiveGspRmFmcGfwProdSigned_GB20B =====

undefined * kgspGetBinArchiveGspRmFmcGfwProdSigned_GB20B(void)

{
  return &__kgspGetBinArchiveGspRmFmcGfwProdSigned_GB20B;
}


// ===== 001336c0 kgspGetBinArchiveGspRmCcFmcGfwProdSigned_GH100 =====

undefined * kgspGetBinArchiveGspRmCcFmcGfwProdSigned_GH100(void)

{
  return &__kgspGetBinArchiveGspRmCcFmcGfwProdSigned_GH100;
}


// ===== 001336d0 kgspGetBinArchiveGspRmCcFmcGfwProdSigned_GB100 =====

undefined * kgspGetBinArchiveGspRmCcFmcGfwProdSigned_GB100(void)

{
  return &__kgspGetBinArchiveGspRmCcFmcGfwProdSigned_GB100;
}


// ===== 001336e0 kgspGetBinArchiveGspRmCcFmcGfwProdSigned_GB202 =====

undefined * kgspGetBinArchiveGspRmCcFmcGfwProdSigned_GB202(void)

{
  return &__kgspGetBinArchiveGspRmCcFmcGfwProdSigned_GB202;
}


// ===== 001336f0 kgspGetBinArchiveBooterLoadUcode_TU102 =====

undefined * kgspGetBinArchiveBooterLoadUcode_TU102(void)

{
  return &__kgspGetBinArchiveBooterLoadUcode_TU102;
}


// ===== 00133700 kgspGetBinArchiveBooterLoadUcode_TU116 =====

undefined * kgspGetBinArchiveBooterLoadUcode_TU116(void)

{
  return &__kgspGetBinArchiveBooterLoadUcode_TU116;
}


// ===== 00133710 kgspGetBinArchiveBooterLoadUcode_GA100 =====

undefined * kgspGetBinArchiveBooterLoadUcode_GA100(void)

{
  return &__kgspGetBinArchiveBooterLoadUcode_GA100;
}


