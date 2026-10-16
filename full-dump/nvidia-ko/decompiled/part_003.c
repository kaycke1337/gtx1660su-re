// ===== 001243e0 __pfx_nv_procfs_release_sys_minors =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_release_sys_minors(void)

{
  single_release();
  return;
}


// ===== 001243f0 nv_procfs_release_sys_minors =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_release_sys_minors(void)

{
  single_release();
  return;
}


// ===== 00124400 __pfx_nv_cap_procfs_write =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012450a) */

ulong __pfx_nv_cap_procfs_write(long param_1,undefined8 param_2,ulong param_3,undefined8 *param_4)

{
  ulong *puVar1;
  long lVar2;
  long lVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  long in_GS_OFFSET;
  
  puVar1 = *(ulong **)(&const_current_task + in_GS_OFFSET);
  while( true ) {
    iVar5 = down_read_trylock(nv_system_pm_lock);
    if (iVar5 != 0) {
      uVar7 = 0xffffffffffffffea;
      if (param_3 != 0) {
        lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x68);
        lVar3 = *(long *)(lVar2 + 0x90);
        if ((0x7fU - lVar3 < param_3) || (lVar3 == 0x7f)) {
          uVar7 = 0xffffffffffffffe4;
        }
        else {
          if (0x7fffffff < param_3) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)invalidInstructionException();
            (*pcVar4)();
          }
          lVar3 = lVar2 + 0xc + lVar3;
          __check_object_size(lVar3,param_3,0);
          lVar6 = _copy_from_user(lVar3,param_2,param_3);
          if (lVar6 == 0) {
            *(long *)(lVar2 + 0x90) = *(long *)(lVar2 + 0x90) + param_3;
            *(undefined1 *)(lVar3 + param_3) = 0;
            *param_4 = *(undefined8 *)(lVar2 + 0x90);
            uVar7 = param_3;
          }
          else {
            uVar7 = 0xfffffffffffffff2;
            nv_printf(4,"nv-caps: failed to copy in proc data!\n");
          }
        }
      }
      up_read(nv_system_pm_lock);
      return uVar7;
    }
    if (((*puVar1 & 4) != 0) || ((*puVar1 & 2) != 0)) break;
    __SCT__cond_resched();
  }
  nv_printf(4,"nv-caps: failed to lock the nv_system_pm_lock!\n");
  return 0xfffffffffffffffc;
}


// ===== 00124410 nv_cap_procfs_write =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012450a) */

ulong nv_cap_procfs_write(long param_1,undefined8 param_2,ulong param_3,undefined8 *param_4)

{
  ulong *puVar1;
  long lVar2;
  long lVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  long in_GS_OFFSET;
  
  puVar1 = *(ulong **)(&const_current_task + in_GS_OFFSET);
  while( true ) {
    iVar5 = down_read_trylock(nv_system_pm_lock);
    if (iVar5 != 0) {
      uVar7 = 0xffffffffffffffea;
      if (param_3 != 0) {
        lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x68);
        lVar3 = *(long *)(lVar2 + 0x90);
        if ((0x7fU - lVar3 < param_3) || (lVar3 == 0x7f)) {
          uVar7 = 0xffffffffffffffe4;
        }
        else {
          if (0x7fffffff < param_3) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)invalidInstructionException();
            (*pcVar4)();
          }
          lVar3 = lVar2 + 0xc + lVar3;
          __check_object_size(lVar3,param_3,0);
          lVar6 = _copy_from_user(lVar3,param_2,param_3);
          if (lVar6 == 0) {
            *(long *)(lVar2 + 0x90) = *(long *)(lVar2 + 0x90) + param_3;
            *(undefined1 *)(lVar3 + param_3) = 0;
            *param_4 = *(undefined8 *)(lVar2 + 0x90);
            uVar7 = param_3;
          }
          else {
            uVar7 = 0xfffffffffffffff2;
            nv_printf(4,"nv-caps: failed to copy in proc data!\n");
          }
        }
      }
      up_read(nv_system_pm_lock);
      return uVar7;
    }
    if (((*puVar1 & 4) != 0) || ((*puVar1 & 2) != 0)) break;
    __SCT__cond_resched();
  }
  nv_printf(4,"nv-caps: failed to lock the nv_system_pm_lock!\n");
  return 0xfffffffffffffffc;
}


// ===== 00124540 __pfx_nv_procfs_read_lock_nvlink_minors =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001245b0) */
/* WARNING: Removing unreachable block (ram,0x001245e0) */

undefined8
__pfx_nv_procfs_read_lock_nvlink_minors
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


// ===== 00124550 nv_procfs_read_lock_nvlink_minors =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001245b0) */
/* WARNING: Removing unreachable block (ram,0x001245e0) */

undefined8
nv_procfs_read_lock_nvlink_minors
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


// ===== 001245f0 __pfx_nv_procfs_read_lock_mig_minors =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00124660) */
/* WARNING: Removing unreachable block (ram,0x00124690) */

undefined8
__pfx_nv_procfs_read_lock_mig_minors
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


// ===== 00124600 nv_procfs_read_lock_mig_minors =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00124660) */
/* WARNING: Removing unreachable block (ram,0x00124690) */

undefined8
nv_procfs_read_lock_mig_minors
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


// ===== 001246a0 __pfx_nv_procfs_read_lock_sys_minors =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00124710) */
/* WARNING: Removing unreachable block (ram,0x00124740) */

undefined8
__pfx_nv_procfs_read_lock_sys_minors
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


// ===== 001246b0 nv_procfs_read_lock_sys_minors =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00124710) */
/* WARNING: Removing unreachable block (ram,0x00124740) */

undefined8
nv_procfs_read_lock_sys_minors
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


// ===== 00124750 __pfx_nv_cap_procfs_read =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001247ae) */
/* WARNING: Removing unreachable block (ram,0x00124815) */

undefined8 __pfx_nv_cap_procfs_read(long param_1)

{
  ulong *puVar1;
  undefined4 *puVar2;
  int iVar3;
  long in_GS_OFFSET;
  
  puVar1 = *(ulong **)(&const_current_task + in_GS_OFFSET);
  puVar2 = *(undefined4 **)(param_1 + 0x68);
  while( true ) {
    iVar3 = down_read_trylock(nv_system_pm_lock);
    if (iVar3 != 0) {
      seq_printf(param_1,"%s: %d\n","DeviceFileMinor",*puVar2);
      seq_printf(param_1,"%s: %d\n","DeviceFileMode",puVar2[1]);
      seq_printf(param_1,"%s: %d\n","DeviceFileModify",puVar2[2]);
      up_read(nv_system_pm_lock);
      return 0;
    }
    if (((*puVar1 & 4) != 0) || ((*puVar1 & 2) != 0)) break;
    __SCT__cond_resched();
  }
  return 0xfffffffc;
}


// ===== 00124760 nv_cap_procfs_read =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001247ae) */
/* WARNING: Removing unreachable block (ram,0x00124815) */

undefined8 nv_cap_procfs_read(long param_1)

{
  ulong *puVar1;
  undefined4 *puVar2;
  int iVar3;
  long in_GS_OFFSET;
  
  puVar1 = *(ulong **)(&const_current_task + in_GS_OFFSET);
  puVar2 = *(undefined4 **)(param_1 + 0x68);
  while( true ) {
    iVar3 = down_read_trylock(nv_system_pm_lock);
    if (iVar3 != 0) {
      seq_printf(param_1,"%s: %d\n","DeviceFileMinor",*puVar2);
      seq_printf(param_1,"%s: %d\n","DeviceFileMode",puVar2[1]);
      seq_printf(param_1,"%s: %d\n","DeviceFileModify",puVar2[2]);
      up_read(nv_system_pm_lock);
      return 0;
    }
    if (((*puVar1 & 4) != 0) || ((*puVar1 & 2) != 0)) break;
    __SCT__cond_resched();
  }
  return 0xfffffffc;
}


// ===== 00124820 __pfx_nv_cap_validate_and_dup_fd =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001248a6) */

int __pfx_nv_cap_validate_and_dup_fd(long param_1,undefined4 param_2)

{
  int iVar1;
  long lVar2;
  
  if ((param_1 != 0) && (lVar2 = fget(param_2), lVar2 != 0)) {
    if ((*(long *)(lVar2 + 0x20) != 0) &&
       (((*(undefined1 **)(lVar2 + 8) == g_nv_cap_drv_fops &&
         ((*(uint *)(*(long *)(lVar2 + 0x20) + 0x4c) & 0xfffff) == *(uint *)(param_1 + 0x10))) &&
        (iVar1 = get_unused_fd_flags(0x80000), -1 < iVar1)))) {
      fd_install(iVar1,lVar2);
      return iVar1;
    }
    fput(lVar2);
  }
  return -1;
}


// ===== 00124830 nv_cap_validate_and_dup_fd =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001248a6) */

int nv_cap_validate_and_dup_fd(long param_1,undefined4 param_2)

{
  int iVar1;
  long lVar2;
  
  if ((param_1 != 0) && (lVar2 = fget(param_2), lVar2 != 0)) {
    if ((*(long *)(lVar2 + 0x20) != 0) &&
       (((*(undefined1 **)(lVar2 + 8) == g_nv_cap_drv_fops &&
         ((*(uint *)(*(long *)(lVar2 + 0x20) + 0x4c) & 0xfffff) == *(uint *)(param_1 + 0x10))) &&
        (iVar1 = get_unused_fd_flags(0x80000), -1 < iVar1)))) {
      fd_install(iVar1,lVar2);
      return iVar1;
    }
    fput(lVar2);
  }
  return -1;
}


// ===== 001248d0 __pfx_nv_cap_close_fd =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00124951) */

void __pfx_nv_cap_close_fd(int param_1)

{
  long lVar1;
  undefined1 *puVar2;
  long lVar3;
  long in_GS_OFFSET;
  
  if (param_1 == -1) {
    return;
  }
  lVar1 = *(long *)(&const_current_task + in_GS_OFFSET) + 0xe60;
  _raw_spin_lock(lVar1);
  if (*(long *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0xd90) != 0) {
    lVar3 = fget(param_1);
    if (lVar3 != 0) {
      puVar2 = *(undefined1 **)(lVar3 + 8);
      fput(lVar3);
      if (puVar2 == g_nv_cap_drv_fops) {
        close_fd(param_1);
        _raw_spin_unlock(lVar1);
        return;
      }
    }
  }
  _raw_spin_unlock(lVar1);
  return;
}


// ===== 001248e0 nv_cap_close_fd =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00124951) */

void nv_cap_close_fd(int param_1)

{
  long lVar1;
  undefined1 *puVar2;
  long lVar3;
  long in_GS_OFFSET;
  
  if (param_1 == -1) {
    return;
  }
  lVar1 = *(long *)(&const_current_task + in_GS_OFFSET) + 0xe60;
  _raw_spin_lock(lVar1);
  if (*(long *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0xd90) != 0) {
    lVar3 = fget(param_1);
    if (lVar3 != 0) {
      puVar2 = *(undefined1 **)(lVar3 + 8);
      fput(lVar3);
      if (puVar2 == g_nv_cap_drv_fops) {
        close_fd(param_1);
        _raw_spin_unlock(lVar1);
        return;
      }
    }
  }
  _raw_spin_unlock(lVar1);
  return;
}


// ===== 00124970 __pfx_nv_cap_create_file_entry =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00124a64) */

undefined8 * __pfx_nv_cap_create_file_entry(long param_1,undefined8 param_2,undefined4 param_3)

{
  undefined8 uVar1;
  uint uVar2;
  int iVar3;
  undefined8 *puVar4;
  size_t sVar5;
  long lVar6;
  undefined8 *puVar7;
  char *__s;
  
  puVar4 = (undefined8 *)nv_cap_alloc();
  if (puVar4 != (undefined8 *)0x0) {
    uVar1 = *(undefined8 *)(param_1 + 0x28);
    __s = (char *)*puVar4;
    *(undefined4 *)((long)puVar4 + 0x14) = param_3;
    puVar4[4] = uVar1;
    sVar5 = strlen(__s);
    uVar2 = full_name_hash(0,__s,sVar5 & 0xffffffff);
    if (((&g_nv_cap_hash_table)[(uVar2 & 0x1ff) * 0x61c88647 >> 0x17] != 0) &&
       (puVar7 = (undefined8 *)
                 ((&g_nv_cap_hash_table)[(uVar2 & 0x1ff) * 0x61c88647 >> 0x17] + -0x10),
       puVar7 != (undefined8 *)0x0)) {
      while (iVar3 = strcmp(__s,(char *)*puVar7), iVar3 != 0) {
        if ((puVar7[2] == 0) ||
           (puVar7 = (undefined8 *)(puVar7[2] + -0x10), puVar7 == (undefined8 *)0x0))
        goto LAB_00124a26;
      }
      if (-1 < *(int *)(puVar7 + 1)) {
        *(int *)(puVar4 + 2) = *(int *)(puVar7 + 1);
        lVar6 = proc_create_data(param_2,0x8124,*(undefined8 *)(param_1 + 0x28),g_nv_cap_procfs_fops
                                 ,puVar4);
        puVar4[5] = lVar6;
        if (lVar6 != 0) {
          return puVar4;
        }
        __s = (char *)*puVar4;
        goto LAB_00124a2d;
      }
LAB_00124a26:
      __s = (char *)*puVar4;
    }
LAB_00124a2d:
    kfree(__s);
    kfree(puVar4[1]);
    kfree(puVar4);
  }
  return (undefined8 *)0x0;
}


// ===== 00124980 nv_cap_create_file_entry =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00124a64) */

undefined8 * nv_cap_create_file_entry(long param_1,undefined8 param_2,undefined4 param_3)

{
  undefined8 uVar1;
  uint uVar2;
  int iVar3;
  undefined8 *puVar4;
  size_t sVar5;
  long lVar6;
  undefined8 *puVar7;
  char *__s;
  
  puVar4 = (undefined8 *)nv_cap_alloc();
  if (puVar4 != (undefined8 *)0x0) {
    uVar1 = *(undefined8 *)(param_1 + 0x28);
    __s = (char *)*puVar4;
    *(undefined4 *)((long)puVar4 + 0x14) = param_3;
    puVar4[4] = uVar1;
    sVar5 = strlen(__s);
    uVar2 = full_name_hash(0,__s,sVar5 & 0xffffffff);
    if (((&g_nv_cap_hash_table)[(uVar2 & 0x1ff) * 0x61c88647 >> 0x17] != 0) &&
       (puVar7 = (undefined8 *)
                 ((&g_nv_cap_hash_table)[(uVar2 & 0x1ff) * 0x61c88647 >> 0x17] + -0x10),
       puVar7 != (undefined8 *)0x0)) {
      while (iVar3 = strcmp(__s,(char *)*puVar7), iVar3 != 0) {
        if ((puVar7[2] == 0) ||
           (puVar7 = (undefined8 *)(puVar7[2] + -0x10), puVar7 == (undefined8 *)0x0))
        goto LAB_00124a26;
      }
      if (-1 < *(int *)(puVar7 + 1)) {
        *(int *)(puVar4 + 2) = *(int *)(puVar7 + 1);
        lVar6 = proc_create_data(param_2,0x8124,*(undefined8 *)(param_1 + 0x28),g_nv_cap_procfs_fops
                                 ,puVar4);
        puVar4[5] = lVar6;
        if (lVar6 != 0) {
          return puVar4;
        }
        __s = (char *)*puVar4;
        goto LAB_00124a2d;
      }
LAB_00124a26:
      __s = (char *)*puVar4;
    }
LAB_00124a2d:
    kfree(__s);
    kfree(puVar4[1]);
    kfree(puVar4);
  }
  return (undefined8 *)0x0;
}


// ===== 00124ab0 __pfx_nv_cap_create_dir_entry =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00124b20) */

undefined8 * __pfx_nv_cap_create_dir_entry(long param_1,undefined8 param_2,long param_3)

{
  undefined8 *puVar1;
  long lVar2;
  undefined8 *puVar3;
  
  puVar1 = (undefined8 *)nv_cap_alloc();
  puVar3 = puVar1;
  if (puVar1 != (undefined8 *)0x0) {
    puVar1[4] = *(undefined8 *)(param_1 + 0x28);
    puVar1[2] = param_3 << 0x20 | 0xffffffff;
    lVar2 = proc_mkdir_mode(param_2,0x416d,*(undefined8 *)(param_1 + 0x28));
    puVar1[5] = lVar2;
    if (lVar2 == 0) {
      kfree(*puVar1);
      kfree(puVar1[1]);
      puVar3 = (undefined8 *)0x0;
      kfree(puVar1);
    }
  }
  return puVar3;
}


// ===== 00124ac0 nv_cap_create_dir_entry =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00124b20) */

undefined8 * nv_cap_create_dir_entry(long param_1,undefined8 param_2,long param_3)

{
  undefined8 *puVar1;
  long lVar2;
  undefined8 *puVar3;
  
  puVar1 = (undefined8 *)nv_cap_alloc();
  puVar3 = puVar1;
  if (puVar1 != (undefined8 *)0x0) {
    puVar1[4] = *(undefined8 *)(param_1 + 0x28);
    puVar1[2] = param_3 << 0x20 | 0xffffffff;
    lVar2 = proc_mkdir_mode(param_2,0x416d,*(undefined8 *)(param_1 + 0x28));
    puVar1[5] = lVar2;
    if (lVar2 == 0) {
      kfree(*puVar1);
      kfree(puVar1[1]);
      puVar3 = (undefined8 *)0x0;
      kfree(puVar1);
    }
  }
  return puVar3;
}


// ===== 00124b50 __pfx_nv_cap_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00124d18) */

undefined8 __pfx_nv_cap_init(char *param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint uVar4;
  size_t sVar5;
  char *__string;
  size_t sVar6;
  size_t sVar7;
  undefined8 uVar8;
  ulong uVar9;
  char *pcVar10;
  uint uVar11;
  long in_GS_OFFSET;
  undefined *puStack_70;
  undefined *puStack_68;
  undefined1 auStack_60 [8];
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [8];
  undefined1 auStack_48 [6];
  undefined4 uStack_42;
  undefined8 uStack_3e;
  undefined8 uStack_36;
  undefined6 uStack_2e;
  
  uStack_36._6_2_ = (undefined2)*(undefined8 *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_2e = (undefined6)((ulong)*(undefined8 *)(&__ref_stack_chk_guard + in_GS_OFFSET) >> 0x10);
  puStack_70 = (undefined *)0x0;
  uStack_3e._0_4_ = 0x7061632f;
  uStack_3e._4_2_ = 0x6261;
  puStack_68 = (undefined *)0x0;
  auStack_60 = (undefined1  [8])0x0;
  auStack_58 = (undefined1  [8])0x0;
  auStack_50 = (undefined1  [8])0x0;
  _auStack_48 = 0;
  uStack_3e._6_2_ = 0x6c69;
  uStack_36._0_6_ = 0x7365697469;
  if (param_1 == (char *)0x0) {
    uVar8 = 0;
  }
  else {
    sVar5 = strlen(param_1);
    uVar9 = sVar5 + 0xe;
    __string = (char *)__kmalloc_noprof(uVar9,0x2cc0);
    if (__string != (char *)0x0) {
      sVar6 = strlen(param_1);
      if (uVar9 < sVar6 + 1) {
                    /* WARNING: Subroutine does not return */
        __fortify_panic(0x1f,uVar9);
      }
      memcpy(__string,param_1,sVar6 + 1);
      sVar6 = strnlen(__string,uVar9);
      if (uVar9 < sVar6) {
                    /* WARNING: Subroutine does not return */
        __fortify_panic(2,uVar9,sVar6 + 1);
      }
      sVar7 = strnlen((char *)&uStack_3e,0xe);
      if (0xe < sVar7) {
                    /* WARNING: Subroutine does not return */
        __fortify_panic(2,0xe,sVar7 + 1);
      }
      if (sVar7 == 0xe) {
                    /* WARNING: Subroutine does not return */
        __fortify_panic(4,0xe,0xf);
      }
      uVar1 = sVar6 + sVar7;
      if (uVar9 != sVar6) {
        if (uVar1 < uVar9) {
          pcVar10 = __string + sVar6;
          uVar4 = (uint)sVar7;
          if (uVar4 < 0x20) {
            if ((sVar7 & 0x10) == 0) {
              if ((sVar7 & 8) == 0) {
                if ((sVar7 & 4) == 0) {
                  if (uVar4 != 0) {
                    *pcVar10 = (char)uStack_3e;
                    if ((sVar7 & 2) != 0) {
                      *(undefined2 *)(pcVar10 + ((sVar7 & 0xffffffff) - 2)) =
                           *(undefined2 *)((long)&uStack_42 + (sVar7 & 0xffffffff) + 2);
                    }
                  }
                }
                else {
                  *(undefined4 *)pcVar10 = (undefined4)uStack_3e;
                  *(undefined4 *)(pcVar10 + ((sVar7 & 0xffffffff) - 4)) =
                       *(undefined4 *)((long)&uStack_42 + (sVar7 & 0xffffffff));
                }
              }
              else {
                *(ulong *)pcVar10 =
                     CONCAT26(uStack_3e._6_2_,CONCAT24(uStack_3e._4_2_,(undefined4)uStack_3e));
                *(undefined8 *)(pcVar10 + ((sVar7 & 0xffffffff) - 8)) =
                     *(undefined8 *)(auStack_48 + (sVar7 & 0xffffffff) + 2);
              }
            }
            else {
              uVar9 = sVar7 & 0xffffffff;
              *(ulong *)pcVar10 =
                   CONCAT26(uStack_3e._6_2_,CONCAT24(uStack_3e._4_2_,(undefined4)uStack_3e));
              *(ulong *)(pcVar10 + 8) = CONCAT26(uStack_36._6_2_,(undefined6)uStack_36);
              *(undefined8 *)(pcVar10 + (uVar9 - 0x10)) = *(undefined8 *)(auStack_50 + uVar9 + 2);
              *(undefined8 *)(pcVar10 + (uVar9 - 8)) = *(undefined8 *)(auStack_48 + uVar9 + 2);
            }
          }
          else {
            uVar9 = sVar7 & 0xffffffff;
            *(undefined8 *)(pcVar10 + (uVar9 - 0x20)) = *(undefined8 *)(auStack_60 + uVar9 + 2);
            *(undefined8 *)(pcVar10 + (uVar9 - 0x18)) = *(undefined8 *)(auStack_58 + uVar9 + 2);
            *(undefined8 *)(pcVar10 + (uVar9 - 0x10)) = *(undefined8 *)(auStack_50 + uVar9 + 2);
            *(undefined8 *)(pcVar10 + (uVar9 - 8)) = *(undefined8 *)(auStack_48 + uVar9 + 2);
            if (0x1f < uVar4 - 1) {
              uVar9 = 0;
              do {
                uVar11 = (int)uVar9 + 0x20;
                uVar8 = *(undefined8 *)((long)&uStack_36 + uVar9);
                uVar2 = *(undefined8 *)((long)&uStack_2e + uVar9);
                uVar3 = *(undefined8 *)(&stack0xffffffffffffffda + uVar9);
                *(undefined8 *)(pcVar10 + uVar9) = *(undefined8 *)((long)&uStack_3e + uVar9);
                *(undefined8 *)(pcVar10 + uVar9 + 8) = uVar8;
                *(undefined8 *)(pcVar10 + uVar9 + 0x10) = uVar2;
                *(undefined8 *)(pcVar10 + uVar9 + 0x18) = uVar3;
                uVar9 = (ulong)uVar11;
              } while (uVar11 < (uVar4 - 1 & 0xffffffe0));
            }
          }
          __string[uVar1] = '\0';
          _auStack_48 = 0;
          puStack_70 = &DAT_00dafc78;
          puStack_68 = &DAT_00dafc78;
          uVar8 = nv_cap_create_dir_entry(&puStack_70,__string,0x16d);
          kfree(__string);
          goto LAB_00124cf9;
        }
        memcpy(__string + sVar6,&uStack_3e,(sVar5 + 0xd) - sVar6);
        __string[sVar5 + 0xd] = '\0';
      }
                    /* WARNING: Subroutine does not return */
      __fortify_panic(0xb,uVar9,uVar1 + 1);
    }
    uVar8 = 0;
  }
LAB_00124cf9:
  if (CONCAT62(uStack_2e,uStack_36._6_2_) != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8;
}


// ===== 00124b60 nv_cap_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00124d18) */

undefined8 nv_cap_init(char *param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint uVar4;
  size_t sVar5;
  char *__string;
  size_t sVar6;
  size_t sVar7;
  undefined8 uVar8;
  ulong uVar9;
  char *pcVar10;
  uint uVar11;
  long in_GS_OFFSET;
  undefined *local_70;
  undefined *local_68;
  undefined1 local_60 [8];
  undefined1 local_58 [8];
  undefined1 local_50 [8];
  undefined1 local_48 [6];
  undefined4 uStack_42;
  undefined8 local_3e;
  undefined8 uStack_36;
  undefined6 uStack_2e;
  
  uStack_36._6_2_ = (undefined2)*(undefined8 *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_2e = (undefined6)((ulong)*(undefined8 *)(&__ref_stack_chk_guard + in_GS_OFFSET) >> 0x10);
  local_70 = (undefined *)0x0;
  local_3e._0_4_ = 0x7061632f;
  local_3e._4_2_ = 0x6261;
  local_68 = (undefined *)0x0;
  local_60 = (undefined1  [8])0x0;
  local_58 = (undefined1  [8])0x0;
  local_50 = (undefined1  [8])0x0;
  _local_48 = 0;
  local_3e._6_2_ = 0x6c69;
  uStack_36._0_6_ = 0x7365697469;
  if (param_1 == (char *)0x0) {
    uVar8 = 0;
  }
  else {
    sVar5 = strlen(param_1);
    uVar9 = sVar5 + 0xe;
    __string = (char *)__kmalloc_noprof(uVar9,0x2cc0);
    if (__string != (char *)0x0) {
      sVar6 = strlen(param_1);
      if (uVar9 < sVar6 + 1) {
                    /* WARNING: Subroutine does not return */
        __fortify_panic(0x1f,uVar9);
      }
      memcpy(__string,param_1,sVar6 + 1);
      sVar6 = strnlen(__string,uVar9);
      if (uVar9 < sVar6) {
                    /* WARNING: Subroutine does not return */
        __fortify_panic(2,uVar9,sVar6 + 1);
      }
      sVar7 = strnlen((char *)&local_3e,0xe);
      if (0xe < sVar7) {
                    /* WARNING: Subroutine does not return */
        __fortify_panic(2,0xe,sVar7 + 1);
      }
      if (sVar7 == 0xe) {
                    /* WARNING: Subroutine does not return */
        __fortify_panic(4,0xe,0xf);
      }
      uVar1 = sVar6 + sVar7;
      if (uVar9 != sVar6) {
        if (uVar1 < uVar9) {
          pcVar10 = __string + sVar6;
          uVar4 = (uint)sVar7;
          if (uVar4 < 0x20) {
            if ((sVar7 & 0x10) == 0) {
              if ((sVar7 & 8) == 0) {
                if ((sVar7 & 4) == 0) {
                  if (uVar4 != 0) {
                    *pcVar10 = (char)local_3e;
                    if ((sVar7 & 2) != 0) {
                      *(undefined2 *)(pcVar10 + ((sVar7 & 0xffffffff) - 2)) =
                           *(undefined2 *)((long)&uStack_42 + (sVar7 & 0xffffffff) + 2);
                    }
                  }
                }
                else {
                  *(undefined4 *)pcVar10 = (undefined4)local_3e;
                  *(undefined4 *)(pcVar10 + ((sVar7 & 0xffffffff) - 4)) =
                       *(undefined4 *)((long)&uStack_42 + (sVar7 & 0xffffffff));
                }
              }
              else {
                *(ulong *)pcVar10 =
                     CONCAT26(local_3e._6_2_,CONCAT24(local_3e._4_2_,(undefined4)local_3e));
                *(undefined8 *)(pcVar10 + ((sVar7 & 0xffffffff) - 8)) =
                     *(undefined8 *)(local_48 + (sVar7 & 0xffffffff) + 2);
              }
            }
            else {
              uVar9 = sVar7 & 0xffffffff;
              *(ulong *)pcVar10 =
                   CONCAT26(local_3e._6_2_,CONCAT24(local_3e._4_2_,(undefined4)local_3e));
              *(ulong *)(pcVar10 + 8) = CONCAT26(uStack_36._6_2_,(undefined6)uStack_36);
              *(undefined8 *)(pcVar10 + (uVar9 - 0x10)) = *(undefined8 *)(local_50 + uVar9 + 2);
              *(undefined8 *)(pcVar10 + (uVar9 - 8)) = *(undefined8 *)(local_48 + uVar9 + 2);
            }
          }
          else {
            uVar9 = sVar7 & 0xffffffff;
            *(undefined8 *)(pcVar10 + (uVar9 - 0x20)) = *(undefined8 *)(local_60 + uVar9 + 2);
            *(undefined8 *)(pcVar10 + (uVar9 - 0x18)) = *(undefined8 *)(local_58 + uVar9 + 2);
            *(undefined8 *)(pcVar10 + (uVar9 - 0x10)) = *(undefined8 *)(local_50 + uVar9 + 2);
            *(undefined8 *)(pcVar10 + (uVar9 - 8)) = *(undefined8 *)(local_48 + uVar9 + 2);
            if (0x1f < uVar4 - 1) {
              uVar9 = 0;
              do {
                uVar11 = (int)uVar9 + 0x20;
                uVar8 = *(undefined8 *)((long)&uStack_36 + uVar9);
                uVar2 = *(undefined8 *)((long)&uStack_2e + uVar9);
                uVar3 = *(undefined8 *)(&stack0xffffffffffffffda + uVar9);
                *(undefined8 *)(pcVar10 + uVar9) = *(undefined8 *)((long)&local_3e + uVar9);
                *(undefined8 *)(pcVar10 + uVar9 + 8) = uVar8;
                *(undefined8 *)(pcVar10 + uVar9 + 0x10) = uVar2;
                *(undefined8 *)(pcVar10 + uVar9 + 0x18) = uVar3;
                uVar9 = (ulong)uVar11;
              } while (uVar11 < (uVar4 - 1 & 0xffffffe0));
            }
          }
          __string[uVar1] = '\0';
          _local_48 = 0;
          local_70 = &DAT_00dafc78;
          local_68 = &DAT_00dafc78;
          uVar8 = nv_cap_create_dir_entry(&local_70,__string,0x16d);
          kfree(__string);
          goto LAB_00124cf9;
        }
        memcpy(__string + sVar6,&local_3e,(sVar5 + 0xd) - sVar6);
        __string[sVar5 + 0xd] = '\0';
      }
                    /* WARNING: Subroutine does not return */
      __fortify_panic(0xb,uVar9,uVar1 + 1);
    }
    uVar8 = 0;
  }
LAB_00124cf9:
  if (CONCAT62(uStack_2e,uStack_36._6_2_) != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8;
}


// ===== 00124e40 __pfx_nv_cap_destroy_entry =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_cap_destroy_entry(undefined8 *param_1)

{
  code *pcVar1;
  
  if (param_1 != (undefined8 *)0x0) {
    remove_proc_entry(param_1[1],param_1[4]);
    kfree(*param_1);
    kfree(param_1[1]);
    kfree(param_1);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00124e50 nv_cap_destroy_entry =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_cap_destroy_entry(undefined8 *param_1)

{
  code *pcVar1;
  
  if (param_1 != (undefined8 *)0x0) {
    remove_proc_entry(param_1[1],param_1[4]);
    kfree(*param_1);
    kfree(param_1[1]);
    kfree(param_1);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00124e90 __pfx_nv_cap_drv_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125075) */
/* WARNING: Removing unreachable block (ram,0x00125033) */
/* WARNING: Removing unreachable block (ram,0x0012504c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __pfx_nv_cap_drv_init(void)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  long lVar4;
  
  puVar2 = &g_nv_cap_hash_table;
  do {
    *puVar2 = 0;
    puVar3 = puVar2 + 2;
    puVar2[1] = 0;
    puVar2 = puVar3;
  } while (puVar3 != (undefined8 *)&minor_1);
  _nv_cap_table_init(&g_nv_cap_nvlink_table,1);
  _nv_cap_table_init(&g_nv_cap_mig_table,2);
  _nv_cap_table_init(&g_nv_cap_mig_gpu_table,0x10e0);
  _nv_cap_table_init(&g_nv_cap_sys_table,1);
  if (g_nv_cap_drv != '\0') {
    nv_printf(4,"nv-caps-drv is already initialized.\n");
    return -0x10;
  }
  iVar1 = alloc_chrdev_region(&DAT_005465d0,0,0x2000,"nvidia-caps");
  if (iVar1 < 0) {
    nv_printf(4,"nv-caps-drv failed to create cdev region.\n");
    return iVar1;
  }
  cdev_init(&DAT_00546568,g_nv_cap_drv_fops);
  _DAT_005465a8 = __this_module;
  iVar1 = cdev_add(&DAT_00546568,DAT_005465d0,0x2000);
  if (iVar1 < 0) {
    nv_printf(4,"nv-caps-drv failed to create cdev.\n");
  }
  else {
    nv_cap_procfs_dir = proc_mkdir_mode("driver/nvidia-caps",0x416d,0);
    if (nv_cap_procfs_dir != 0) {
      lVar4 = proc_create_data("mig-minors",0x8124,nv_cap_procfs_dir,nv_procfs_mig_minors_fops,0);
      if (((lVar4 != 0) &&
          (lVar4 = proc_create_data("nvlink-minors",0x8124,nv_cap_procfs_dir,
                                    nv_procfs_nvlink_minors_fops,0), lVar4 != 0)) &&
         (lVar4 = proc_create_data("sys-minors",0x8124,nv_cap_procfs_dir,nv_procfs_sys_minors_fops,0
                                  ), lVar4 != 0)) {
        g_nv_cap_drv = 1;
        return 0;
      }
      if (nv_cap_procfs_dir != 0) {
        proc_remove();
        nv_cap_procfs_dir = 0;
      }
    }
    iVar1 = -0xd;
    nv_printf(4,"nv-caps-drv: unable to init proc\n");
    cdev_del(&DAT_00546568);
  }
  unregister_chrdev_region(DAT_005465d0,0x2000);
  return iVar1;
}


// ===== 00124ea0 nv_cap_drv_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125075) */
/* WARNING: Removing unreachable block (ram,0x00125033) */
/* WARNING: Removing unreachable block (ram,0x0012504c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int nv_cap_drv_init(void)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  long lVar4;
  
  puVar2 = &g_nv_cap_hash_table;
  do {
    *puVar2 = 0;
    puVar3 = puVar2 + 2;
    puVar2[1] = 0;
    puVar2 = puVar3;
  } while (puVar3 != (undefined8 *)&minor_1);
  _nv_cap_table_init(&g_nv_cap_nvlink_table,1);
  _nv_cap_table_init(&g_nv_cap_mig_table,2);
  _nv_cap_table_init(&g_nv_cap_mig_gpu_table,0x10e0);
  _nv_cap_table_init(&g_nv_cap_sys_table,1);
  if (g_nv_cap_drv != '\0') {
    nv_printf(4,"nv-caps-drv is already initialized.\n");
    return -0x10;
  }
  iVar1 = alloc_chrdev_region(&DAT_005465d0,0,0x2000,"nvidia-caps");
  if (iVar1 < 0) {
    nv_printf(4,"nv-caps-drv failed to create cdev region.\n");
    return iVar1;
  }
  cdev_init(&DAT_00546568,g_nv_cap_drv_fops);
  _DAT_005465a8 = __this_module;
  iVar1 = cdev_add(&DAT_00546568,DAT_005465d0,0x2000);
  if (iVar1 < 0) {
    nv_printf(4,"nv-caps-drv failed to create cdev.\n");
  }
  else {
    nv_cap_procfs_dir = proc_mkdir_mode("driver/nvidia-caps",0x416d,0);
    if (nv_cap_procfs_dir != 0) {
      lVar4 = proc_create_data("mig-minors",0x8124,nv_cap_procfs_dir,nv_procfs_mig_minors_fops,0);
      if (((lVar4 != 0) &&
          (lVar4 = proc_create_data("nvlink-minors",0x8124,nv_cap_procfs_dir,
                                    nv_procfs_nvlink_minors_fops,0), lVar4 != 0)) &&
         (lVar4 = proc_create_data("sys-minors",0x8124,nv_cap_procfs_dir,nv_procfs_sys_minors_fops,0
                                  ), lVar4 != 0)) {
        g_nv_cap_drv = 1;
        return 0;
      }
      if (nv_cap_procfs_dir != 0) {
        proc_remove();
        nv_cap_procfs_dir = 0;
      }
    }
    iVar1 = -0xd;
    nv_printf(4,"nv-caps-drv: unable to init proc\n");
    cdev_del(&DAT_00546568);
  }
  unregister_chrdev_region(DAT_005465d0,0x2000);
  return iVar1;
}


// ===== 001250e0 __pfx_nv_cap_drv_exit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125102) */
/* WARNING: Removing unreachable block (ram,0x00125146) */

void __pfx_nv_cap_drv_exit(void)

{
  if (g_nv_cap_drv == '\0') {
    return;
  }
  if (nv_cap_procfs_dir != 0) {
    proc_remove();
    nv_cap_procfs_dir = 0;
  }
  cdev_del(&DAT_00546568);
  unregister_chrdev_region(DAT_005465d0,0x2000);
  g_nv_cap_drv = 0;
  return;
}


// ===== 001250f0 nv_cap_drv_exit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125102) */
/* WARNING: Removing unreachable block (ram,0x00125146) */

void nv_cap_drv_exit(void)

{
  if (g_nv_cap_drv == '\0') {
    return;
  }
  if (nv_cap_procfs_dir != 0) {
    proc_remove();
    nv_cap_procfs_dir = 0;
  }
  cdev_del(&DAT_00546568);
  unregister_chrdev_region(DAT_005465d0,0x2000);
  g_nv_cap_drv = 0;
  return;
}


// ===== 00125150 __pfx_nv_caps_imex_open =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012516b) */

undefined8 __pfx_nv_caps_imex_open(void)

{
  return 0;
}


// ===== 00125160 nv_caps_imex_open =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012516b) */

undefined8 nv_caps_imex_open(void)

{
  return 0;
}


// ===== 00125170 __pfx_nv_caps_imex_devnode =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001251a6) */

undefined8 __pfx_nv_caps_imex_devnode(long param_1,undefined2 *param_2)

{
  if ((param_2 != (undefined2 *)0x0) && (*(int *)(param_1 + 700) == DAT_00547670)) {
    *param_2 = 0x1b6;
  }
  return 0;
}


// ===== 00125180 nv_caps_imex_devnode =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001251a6) */

undefined8 nv_caps_imex_devnode(long param_1,undefined2 *param_2)

{
  if ((param_2 != (undefined2 *)0x0) && (*(int *)(param_1 + 700) == DAT_00547670)) {
    *param_2 = 0x1b6;
  }
  return 0;
}


// ===== 001251b0 __pfx_nv_caps_imex_release =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001251cb) */

undefined8 __pfx_nv_caps_imex_release(void)

{
  return 0;
}


// ===== 001251c0 nv_caps_imex_release =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001251cb) */

undefined8 nv_caps_imex_release(void)

{
  return 0;
}


// ===== 001251d0 __pfx_nv_caps_imex_channel_get =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125217) */

uint __pfx_nv_caps_imex_channel_get(void)

{
  long lVar1;
  uint uVar2;
  
  lVar1 = fget();
  if (lVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    if ((*(long *)(lVar1 + 0x20) == 0) || (*(undefined1 **)(lVar1 + 8) != g_nv_caps_imex_fops)) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = *(uint *)(*(long *)(lVar1 + 0x20) + 0x4c) & 0xfffff;
    }
    fput();
  }
  return uVar2;
}


// ===== 001251e0 nv_caps_imex_channel_get =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125217) */

uint nv_caps_imex_channel_get(void)

{
  long lVar1;
  uint uVar2;
  
  lVar1 = fget();
  if (lVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    if ((*(long *)(lVar1 + 0x20) == 0) || (*(undefined1 **)(lVar1 + 8) != g_nv_caps_imex_fops)) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = *(uint *)(*(long *)(lVar1 + 0x20) + 0x4c) & 0xfffff;
    }
    fput();
  }
  return uVar2;
}


// ===== 00125230 __pfx_nv_caps_imex_channel_count =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012524f) */

undefined4 __pfx_nv_caps_imex_channel_count(void)

{
  return NVreg_ImexChannelCount;
}


// ===== 00125240 nv_caps_imex_channel_count =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012524f) */

undefined4 nv_caps_imex_channel_count(void)

{
  return NVreg_ImexChannelCount;
}


// ===== 00125260 __pfx_nv_caps_imex_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125362) */
/* WARNING: Removing unreachable block (ram,0x0012531d) */
/* WARNING: Removing unreachable block (ram,0x0012533e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __pfx_nv_caps_imex_init(void)

{
  int iVar1;
  ulong uVar2;
  
  if (g_nv_caps_imex != '\0') {
    nv_printf(4,"nv-caps-imex is already initialized.\n");
    return -0x10;
  }
  if (NVreg_ImexChannelCount != 0) {
    g_nv_caps_imex_class = 0;
    _DAT_00547678 = 0;
    iVar1 = alloc_chrdev_region(&DAT_00547670,0,NVreg_ImexChannelCount,"nvidia-caps-imex-channels");
    if (iVar1 < 0) {
      nv_printf(4,"nv-caps-imex failed to create cdev.\n");
      return iVar1;
    }
    cdev_init(&DAT_00547608,g_nv_caps_imex_fops);
    _DAT_00547648 = __this_module;
    iVar1 = cdev_add(&DAT_00547608,DAT_00547670,NVreg_ImexChannelCount);
    if (iVar1 < 0) {
      nv_printf(4,"nv-caps-imex failed to add cdev.\n");
    }
    else {
      if (NVreg_CreateImexChannel0 != 1) {
        g_nv_caps_imex = 1;
        return 0;
      }
      uVar2 = class_create("nvidia-caps-imex-channels");
      g_nv_caps_imex_class = uVar2;
      if (uVar2 < 0xfffffffffffff001) {
        *(code **)(uVar2 + 0x20) = nv_caps_imex_devnode;
        _DAT_00547678 =
             device_create(uVar2,0,DAT_00547670,0,"nvidia-caps-imex-channels!channel%d",0);
        if (_DAT_00547678 < 0xfffffffffffff001) {
          nv_printf(4,
                    "nv-caps-imex channel0 created. Make sure you are aware of the IMEX security model.\n"
                   );
          g_nv_caps_imex = 1;
          return 0;
        }
        nv_printf(4,"nv-caps-imex failed to create channel0.\n");
        class_destroy(g_nv_caps_imex_class);
        g_nv_caps_imex_class = 0;
      }
      else {
        nv_printf(4,"nv-caps-imex failed to register class.\n");
      }
      cdev_del(&DAT_00547608);
      iVar1 = -1;
    }
    unregister_chrdev_region(DAT_00547670,NVreg_ImexChannelCount);
    return iVar1;
  }
  nv_printf(0,"nv-caps-imex is disabled.\n");
  return 0;
}


// ===== 00125270 nv_caps_imex_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125362) */
/* WARNING: Removing unreachable block (ram,0x0012531d) */
/* WARNING: Removing unreachable block (ram,0x0012533e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int nv_caps_imex_init(void)

{
  int iVar1;
  ulong uVar2;
  
  if (g_nv_caps_imex != '\0') {
    nv_printf(4,"nv-caps-imex is already initialized.\n");
    return -0x10;
  }
  if (NVreg_ImexChannelCount != 0) {
    g_nv_caps_imex_class = 0;
    _DAT_00547678 = 0;
    iVar1 = alloc_chrdev_region(&DAT_00547670,0,NVreg_ImexChannelCount,"nvidia-caps-imex-channels");
    if (iVar1 < 0) {
      nv_printf(4,"nv-caps-imex failed to create cdev.\n");
      return iVar1;
    }
    cdev_init(&DAT_00547608,g_nv_caps_imex_fops);
    _DAT_00547648 = __this_module;
    iVar1 = cdev_add(&DAT_00547608,DAT_00547670,NVreg_ImexChannelCount);
    if (iVar1 < 0) {
      nv_printf(4,"nv-caps-imex failed to add cdev.\n");
    }
    else {
      if (NVreg_CreateImexChannel0 != 1) {
        g_nv_caps_imex = 1;
        return 0;
      }
      uVar2 = class_create("nvidia-caps-imex-channels");
      g_nv_caps_imex_class = uVar2;
      if (uVar2 < 0xfffffffffffff001) {
        *(code **)(uVar2 + 0x20) = nv_caps_imex_devnode;
        _DAT_00547678 =
             device_create(uVar2,0,DAT_00547670,0,"nvidia-caps-imex-channels!channel%d",0);
        if (_DAT_00547678 < 0xfffffffffffff001) {
          nv_printf(4,
                    "nv-caps-imex channel0 created. Make sure you are aware of the IMEX security model.\n"
                   );
          g_nv_caps_imex = 1;
          return 0;
        }
        nv_printf(4,"nv-caps-imex failed to create channel0.\n");
        class_destroy(g_nv_caps_imex_class);
        g_nv_caps_imex_class = 0;
      }
      else {
        nv_printf(4,"nv-caps-imex failed to register class.\n");
      }
      cdev_del(&DAT_00547608);
      iVar1 = -1;
    }
    unregister_chrdev_region(DAT_00547670,NVreg_ImexChannelCount);
    return iVar1;
  }
  nv_printf(0,"nv-caps-imex is disabled.\n");
  return 0;
}


// ===== 00125470 __pfx_nv_caps_imex_exit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125492) */
/* WARNING: Removing unreachable block (ram,0x001254e9) */

void __pfx_nv_caps_imex_exit(void)

{
  if (g_nv_caps_imex == '\0') {
    return;
  }
  if (g_nv_caps_imex_class != 0) {
    device_destroy(g_nv_caps_imex_class,DAT_00547670);
    class_destroy(g_nv_caps_imex_class);
    g_nv_caps_imex_class = 0;
  }
  cdev_del(&DAT_00547608);
  unregister_chrdev_region(DAT_00547670,NVreg_ImexChannelCount);
  g_nv_caps_imex = 0;
  return;
}


// ===== 00125480 nv_caps_imex_exit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125492) */
/* WARNING: Removing unreachable block (ram,0x001254e9) */

void nv_caps_imex_exit(void)

{
  if (g_nv_caps_imex == '\0') {
    return;
  }
  if (g_nv_caps_imex_class != 0) {
    device_destroy(g_nv_caps_imex_class,DAT_00547670);
    class_destroy(g_nv_caps_imex_class);
    g_nv_caps_imex_class = 0;
  }
  cdev_del(&DAT_00547608);
  unregister_chrdev_region(DAT_00547670,NVreg_ImexChannelCount);
  g_nv_caps_imex = 0;
  return;
}


// ===== 00125500 __pfx_nv_clk_get_handles =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125603) */

undefined8 __pfx_nv_clk_get_handles(long param_1)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  long in_GS_OFFSET;
  long lStack_48;
  long lStack_40;
  
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lVar1 = *(long *)(param_1 + 8);
  lStack_48 = 0;
  uVar2 = devm_clk_bulk_get_all(*(undefined8 *)(lVar1 + 0x3b0),&lStack_48);
  if ((int)uVar2 < 1) {
    uVar7 = 0x57;
    nv_printf(0,"NVRM: No clk handles for the dev\n");
    if (uVar2 == 0) goto LAB_001255de;
  }
  else {
    uVar7 = 0;
  }
  lVar6 = 0;
  do {
    lVar5 = 0;
    lVar8 = lVar6 * 0x10;
    do {
      iVar3 = strcmp((&osMapClk)[lVar5],*(char **)(lStack_48 + lVar8));
      if (iVar3 == 0) {
        *(undefined8 *)(lVar1 + 0x48e8 + lVar5 * 0x10) = *(undefined8 *)(lStack_48 + 8 + lVar8);
        uVar4 = __clk_get_name();
        *(undefined8 *)(lVar1 + 0x48f0 + lVar5 * 0x10) = uVar4;
        goto LAB_001255c6;
      }
      lVar5 = lVar5 + 1;
    } while (lVar5 != 0x86);
    nv_printf(0,"NVRM: nv_clk_get_handles, failed to find TEGRA_SOC_WHICH_CLK for %s\n",
              *(undefined8 *)(lStack_48 + lVar8));
LAB_001255c6:
    lVar6 = lVar6 + 1;
  } while ((uint)lVar6 < uVar2);
LAB_001255de:
  if (lStack_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}


// ===== 00125510 nv_clk_get_handles =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125603) */

undefined8 nv_clk_get_handles(long param_1)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  long in_GS_OFFSET;
  long local_48;
  long local_40;
  
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lVar1 = *(long *)(param_1 + 8);
  local_48 = 0;
  uVar2 = devm_clk_bulk_get_all(*(undefined8 *)(lVar1 + 0x3b0),&local_48);
  if ((int)uVar2 < 1) {
    uVar7 = 0x57;
    nv_printf(0,"NVRM: No clk handles for the dev\n");
    if (uVar2 == 0) goto LAB_001255de;
  }
  else {
    uVar7 = 0;
  }
  lVar6 = 0;
  do {
    lVar5 = 0;
    lVar8 = lVar6 * 0x10;
    do {
      iVar3 = strcmp((&osMapClk)[lVar5],*(char **)(local_48 + lVar8));
      if (iVar3 == 0) {
        *(undefined8 *)(lVar1 + 0x48e8 + lVar5 * 0x10) = *(undefined8 *)(local_48 + 8 + lVar8);
        uVar4 = __clk_get_name();
        *(undefined8 *)(lVar1 + 0x48f0 + lVar5 * 0x10) = uVar4;
        goto LAB_001255c6;
      }
      lVar5 = lVar5 + 1;
    } while (lVar5 != 0x86);
    nv_printf(0,"NVRM: nv_clk_get_handles, failed to find TEGRA_SOC_WHICH_CLK for %s\n",
              *(undefined8 *)(local_48 + lVar8));
LAB_001255c6:
    lVar6 = lVar6 + 1;
  } while ((uint)lVar6 < uVar2);
LAB_001255de:
  if (local_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}


// ===== 00125670 __pfx_nv_enable_clk =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001256d8) */

undefined8 __pfx_nv_enable_clk(long param_1,uint param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = 0x57;
  lVar1 = *(long *)(((ulong)param_2 + 0x48e) * 0x10 + *(long *)(param_1 + 8) + 8);
  if (lVar1 != 0) {
    iVar2 = clk_prepare(lVar1);
    if (iVar2 == 0) {
      iVar2 = clk_enable(lVar1);
      if (iVar2 == 0) {
        return 0;
      }
      clk_unprepare(lVar1);
    }
    nv_printf(4,"NVRM: clk_prepare_enable failed with error: %d\n",iVar2);
    uVar3 = 0x6d;
  }
  return uVar3;
}


// ===== 00125680 nv_enable_clk =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001256d8) */

undefined8 nv_enable_clk(long param_1,uint param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = 0x57;
  lVar1 = *(long *)(((ulong)param_2 + 0x48e) * 0x10 + *(long *)(param_1 + 8) + 8);
  if (lVar1 != 0) {
    iVar2 = clk_prepare(lVar1);
    if (iVar2 == 0) {
      iVar2 = clk_enable(lVar1);
      if (iVar2 == 0) {
        return 0;
      }
      clk_unprepare(lVar1);
    }
    nv_printf(4,"NVRM: clk_prepare_enable failed with error: %d\n",iVar2);
    uVar3 = 0x6d;
  }
  return uVar3;
}


// ===== 00125700 __pfx_nv_disable_clk =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_disable_clk(long param_1,uint param_2)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(((ulong)param_2 + 0x48e) * 0x10 + *(long *)(param_1 + 8) + 8);
  clk_disable(uVar1);
  clk_unprepare(uVar1);
  return;
}


// ===== 00125710 nv_disable_clk =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_disable_clk(long param_1,uint param_2)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(((ulong)param_2 + 0x48e) * 0x10 + *(long *)(param_1 + 8) + 8);
  clk_disable(uVar1);
  clk_unprepare(uVar1);
  return;
}


// ===== 00125740 __pfx_nv_get_curr_freq =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012579c) */
/* WARNING: Removing unreachable block (ram,0x001257a6) */

byte __pfx_nv_get_curr_freq(long param_1,uint param_2,int *param_3)

{
  ulong uVar1;
  int iVar2;
  
  if (*(long *)(((ulong)param_2 + 0x48e) * 0x10 + *(long *)(param_1 + 8) + 8) != 0) {
    uVar1 = clk_get_rate();
    iVar2 = (int)(uVar1 / 1000);
    *param_3 = iVar2;
    return -(iVar2 == 0) & 0x6d;
  }
  return 0x57;
}


// ===== 00125750 nv_get_curr_freq =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012579c) */
/* WARNING: Removing unreachable block (ram,0x001257a6) */

byte nv_get_curr_freq(long param_1,uint param_2,int *param_3)

{
  ulong uVar1;
  int iVar2;
  
  if (*(long *)(((ulong)param_2 + 0x48e) * 0x10 + *(long *)(param_1 + 8) + 8) != 0) {
    uVar1 = clk_get_rate();
    iVar2 = (int)(uVar1 / 1000);
    *param_3 = iVar2;
    return -(iVar2 == 0) & 0x6d;
  }
  return 0x57;
}


// ===== 001257b0 __pfx_nv_get_max_freq =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125839) */
/* WARNING: Removing unreachable block (ram,0x00125815) */
/* WARNING: Removing unreachable block (ram,0x0012581a) */

undefined8 __pfx_nv_get_max_freq(long param_1,uint param_2,undefined4 *param_3)

{
  long lVar1;
  ulong uVar2;
  
  lVar1 = *(long *)(((ulong)param_2 + 0x48e) * 0x10 + *(long *)(param_1 + 8) + 8);
  if (lVar1 == 0) {
    return 0x57;
  }
  uVar2 = clk_round_rate(lVar1,0xffffffff);
  if (-1 < (long)uVar2) {
    *param_3 = (int)(uVar2 / 1000);
    return 0;
  }
  nv_printf(4,"NVRM: clk_round_rate failed with error: %ld\n",uVar2);
  return 0x6d;
}


// ===== 001257c0 nv_get_max_freq =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125839) */
/* WARNING: Removing unreachable block (ram,0x00125815) */
/* WARNING: Removing unreachable block (ram,0x0012581a) */

undefined8 nv_get_max_freq(long param_1,uint param_2,undefined4 *param_3)

{
  long lVar1;
  ulong uVar2;
  
  lVar1 = *(long *)(((ulong)param_2 + 0x48e) * 0x10 + *(long *)(param_1 + 8) + 8);
  if (lVar1 == 0) {
    return 0x57;
  }
  uVar2 = clk_round_rate(lVar1,0xffffffff);
  if (-1 < (long)uVar2) {
    *param_3 = (int)(uVar2 / 1000);
    return 0;
  }
  nv_printf(4,"NVRM: clk_round_rate failed with error: %ld\n",uVar2);
  return 0x6d;
}


// ===== 00125840 __pfx_nv_get_min_freq =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001258c6) */
/* WARNING: Removing unreachable block (ram,0x001258a2) */
/* WARNING: Removing unreachable block (ram,0x001258a7) */

undefined8 __pfx_nv_get_min_freq(long param_1,uint param_2,undefined4 *param_3)

{
  long lVar1;
  ulong uVar2;
  
  lVar1 = *(long *)(((ulong)param_2 + 0x48e) * 0x10 + *(long *)(param_1 + 8) + 8);
  if (lVar1 == 0) {
    return 0x57;
  }
  uVar2 = clk_round_rate(lVar1,0);
  if (-1 < (long)uVar2) {
    *param_3 = (int)(uVar2 / 1000);
    return 0;
  }
  nv_printf(4,"NVRM: clk_round_rate failed with error: %ld\n",uVar2);
  return 0x6d;
}


// ===== 00125850 nv_get_min_freq =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001258c6) */
/* WARNING: Removing unreachable block (ram,0x001258a2) */
/* WARNING: Removing unreachable block (ram,0x001258a7) */

undefined8 nv_get_min_freq(long param_1,uint param_2,undefined4 *param_3)

{
  long lVar1;
  ulong uVar2;
  
  lVar1 = *(long *)(((ulong)param_2 + 0x48e) * 0x10 + *(long *)(param_1 + 8) + 8);
  if (lVar1 == 0) {
    return 0x57;
  }
  uVar2 = clk_round_rate(lVar1,0);
  if (-1 < (long)uVar2) {
    *param_3 = (int)(uVar2 / 1000);
    return 0;
  }
  nv_printf(4,"NVRM: clk_round_rate failed with error: %ld\n",uVar2);
  return 0x6d;
}


// ===== 001258d0 __pfx_nv_set_freq =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012591b) */
/* WARNING: Removing unreachable block (ram,0x00125936) */

undefined8 __pfx_nv_set_freq(long param_1,uint param_2,int param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = 0x57;
  lVar1 = *(long *)(((ulong)param_2 + 0x48e) * 0x10 + *(long *)(param_1 + 8) + 8);
  if (lVar1 != 0) {
    iVar2 = clk_set_rate(lVar1,param_3 * 1000);
    uVar3 = 0;
    if (iVar2 != 0) {
      nv_printf(4,"NVRM: clk_set_rate failed with error: %d\n");
      return 0x3f;
    }
  }
  return uVar3;
}


// ===== 001258e0 nv_set_freq =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012591b) */
/* WARNING: Removing unreachable block (ram,0x00125936) */

undefined8 nv_set_freq(long param_1,uint param_2,int param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = 0x57;
  lVar1 = *(long *)(((ulong)param_2 + 0x48e) * 0x10 + *(long *)(param_1 + 8) + 8);
  if (lVar1 != 0) {
    iVar2 = clk_set_rate(lVar1,param_3 * 1000);
    uVar3 = 0;
    if (iVar2 != 0) {
      nv_printf(4,"NVRM: clk_set_rate failed with error: %d\n");
      return 0x3f;
    }
  }
  return uVar3;
}


// ===== 00125940 __pfx_nv_clk_clear_handles =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125996) */

void __pfx_nv_clk_clear_handles(long param_1)

{
  long lVar1;
  long *plVar2;
  
  lVar1 = *(long *)(param_1 + 8);
  plVar2 = (long *)(lVar1 + 0x48e8);
  do {
    if (*plVar2 != 0) {
      *plVar2 = 0;
    }
    plVar2 = plVar2 + 2;
  } while (plVar2 != (long *)(lVar1 + 0x5148));
  return;
}


// ===== 00125950 nv_clk_clear_handles =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125996) */

void nv_clk_clear_handles(long param_1)

{
  long lVar1;
  long *plVar2;
  
  lVar1 = *(long *)(param_1 + 8);
  plVar2 = (long *)(lVar1 + 0x48e8);
  do {
    if (*plVar2 != 0) {
      *plVar2 = 0;
    }
    plVar2 = plVar2 + 2;
  } while (plVar2 != (long *)(lVar1 + 0x5148));
  return;
}


// ===== 001259a0 __pfx_nv_set_parent =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001259be) */

undefined8 __pfx_nv_set_parent(void)

{
  return 0x56;
}


// ===== 001259b0 nv_set_parent =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001259be) */

undefined8 nv_set_parent(void)

{
  return 0x56;
}


// ===== 001259d0 __pfx_nv_is_clk_enabled =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001259eb) */

undefined8 __pfx_nv_is_clk_enabled(void)

{
  return 0;
}


// ===== 001259e0 nv_is_clk_enabled =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001259eb) */

undefined8 nv_is_clk_enabled(void)

{
  return 0;
}


// ===== 001259f0 __pfx_nv_dp_uphy_pll_deinit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125a0e) */

undefined8 __pfx_nv_dp_uphy_pll_deinit(void)

{
  return 0x56;
}


// ===== 00125a00 nv_dp_uphy_pll_deinit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125a0e) */

undefined8 nv_dp_uphy_pll_deinit(void)

{
  return 0x56;
}


// ===== 00125a20 __pfx_nv_get_parent =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125a3e) */

undefined8 __pfx_nv_get_parent(void)

{
  return 0x56;
}


// ===== 00125a30 nv_get_parent =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125a3e) */

undefined8 nv_get_parent(void)

{
  return 0x56;
}


// ===== 00125a50 __pfx_nv_dp_uphy_pll_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125a6e) */

undefined8 __pfx_nv_dp_uphy_pll_init(void)

{
  return 0x56;
}


// ===== 00125a60 nv_dp_uphy_pll_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125a6e) */

undefined8 nv_dp_uphy_pll_init(void)

{
  return 0x56;
}


// ===== 00125a80 __pfx_nv_get_syncpoint_aperture =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125a9e) */

undefined8 __pfx_nv_get_syncpoint_aperture(void)

{
  return 0x56;
}


// ===== 00125a90 nv_get_syncpoint_aperture =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125a9e) */

undefined8 nv_get_syncpoint_aperture(void)

{
  return 0x56;
}


// ===== 00125ab0 __pfx_flush_top_half =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125ac9) */

void __pfx_flush_top_half(void)

{
  return;
}


// ===== 00125ac0 flush_top_half =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125ac9) */

void flush_top_half(void)

{
  return;
}


// ===== 00125ad0 __pfx_nvUvmInterfaceRegisterUvmEvents =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125b2a) */
/* WARNING: Removing unreachable block (ram,0x00125b3f) */

undefined4 __pfx_nvUvmInterfaceRegisterUvmEvents(long param_1)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    down(g_pNvUvmEventsLock);
    uVar1 = 0x17;
    if (g_pNvUvmEvents == 0) {
      uVar1 = 0;
      g_pNvUvmEvents = param_1;
    }
    up(g_pNvUvmEventsLock);
    return uVar1;
  }
  return 0x1f;
}


// ===== 00125ae0 nvUvmInterfaceRegisterUvmEvents =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125b2a) */
/* WARNING: Removing unreachable block (ram,0x00125b3f) */

undefined4 nvUvmInterfaceRegisterUvmEvents(long param_1)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    down(g_pNvUvmEventsLock);
    uVar1 = 0x17;
    if (g_pNvUvmEvents == 0) {
      uVar1 = 0;
      g_pNvUvmEvents = param_1;
    }
    up(g_pNvUvmEventsLock);
    return uVar1;
  }
  return 0x1f;
}


// ===== 00125b50 __pfx_nvUvmInterfaceHasPendingNonReplayableFaults =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvUvmInterfaceHasPendingNonReplayableFaults(long param_1,undefined8 param_2)

{
  rm_gpu_ops_has_pending_non_replayable_faults(*(undefined8 *)(param_1 + 0x80),param_1,param_2);
  return;
}


// ===== 00125b60 nvUvmInterfaceHasPendingNonReplayableFaults =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvUvmInterfaceHasPendingNonReplayableFaults(long param_1,undefined8 param_2)

{
  rm_gpu_ops_has_pending_non_replayable_faults(*(undefined8 *)(param_1 + 0x80),param_1,param_2);
  return;
}


// ===== 00125b80 __pfx_nvUvmInterfaceGetNonReplayableFaults =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvUvmInterfaceGetNonReplayableFaults(long param_1,undefined8 param_2,undefined8 param_3)

{
  rm_gpu_ops_get_non_replayable_faults(*(undefined8 *)(param_1 + 0x88),param_1,param_2,param_3);
  return;
}


// ===== 00125b90 nvUvmInterfaceGetNonReplayableFaults =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvUvmInterfaceGetNonReplayableFaults(long param_1,undefined8 param_2,undefined8 param_3)

{
  rm_gpu_ops_get_non_replayable_faults(*(undefined8 *)(param_1 + 0x88),param_1,param_2,param_3);
  return;
}


// ===== 00125bc0 __pfx_nvUvmInterfaceDeRegisterUvmEvents =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvUvmInterfaceDeRegisterUvmEvents(void)

{
  down(g_pNvUvmEventsLock);
  g_pNvUvmEvents = 0;
  up(g_pNvUvmEventsLock);
  on_each_cpu_cond_mask(0,flush_top_half,0,1,&__cpu_online_mask);
  return;
}


// ===== 00125bd0 nvUvmInterfaceDeRegisterUvmEvents =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvUvmInterfaceDeRegisterUvmEvents(void)

{
  down(g_pNvUvmEventsLock);
  g_pNvUvmEvents = 0;
  up(g_pNvUvmEventsLock);
  on_each_cpu_cond_mask(0,flush_top_half,0,1,&__cpu_online_mask);
  return;
}


// ===== 00125c20 __pfx_nvUvmInterfacePagingChannelPushStream =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvUvmInterfacePagingChannelPushStream(long param_1,undefined8 param_2,undefined4 param_3)

{
  rm_gpu_ops_paging_channel_push_stream(*(undefined8 *)(param_1 + 0x18),param_1,param_2,param_3);
  return;
}


// ===== 00125c30 nvUvmInterfacePagingChannelPushStream =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvUvmInterfacePagingChannelPushStream(long param_1,undefined8 param_2,undefined4 param_3)

{
  rm_gpu_ops_paging_channel_push_stream(*(undefined8 *)(param_1 + 0x18),param_1,param_2,param_3);
  return;
}


// ===== 00125c50 __pfx_nvUvmInterfaceCslRotateKey =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125c90) */

undefined8 __pfx_nvUvmInterfaceCslRotateKey(long *param_1,int param_2)

{
  undefined8 uVar1;
  
  if (((param_1 != (long *)0x0) && (param_2 != 0)) && (*param_1 != 0)) {
    uVar1 = rm_gpu_ops_ccsl_rotate_key(*(undefined8 *)(*param_1 + 8),param_1,param_2);
    return uVar1;
  }
  return 0x1f;
}


// ===== 00125c60 nvUvmInterfaceCslRotateKey =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125c90) */

undefined8 nvUvmInterfaceCslRotateKey(long *param_1,int param_2)

{
  undefined8 uVar1;
  
  if (((param_1 != (long *)0x0) && (param_2 != 0)) && (*param_1 != 0)) {
    uVar1 = rm_gpu_ops_ccsl_rotate_key(*(undefined8 *)(*param_1 + 8),param_1,param_2);
    return uVar1;
  }
  return 0x1f;
}


// ===== 00125ca0 __pfx_nvUvmInterfaceCslRotateIv =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvUvmInterfaceCslRotateIv(undefined8 *param_1,undefined1 param_2)

{
  rm_gpu_ops_ccsl_rotate_iv(param_1[1],*param_1,param_2);
  return;
}


// ===== 00125cb0 nvUvmInterfaceCslRotateIv =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvUvmInterfaceCslRotateIv(undefined8 *param_1,undefined1 param_2)

{
  rm_gpu_ops_ccsl_rotate_iv(param_1[1],*param_1,param_2);
  return;
}


// ===== 00125cd0 __pfx_nvUvmInterfaceCslEncrypt =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125d10) */

void __pfx_nvUvmInterfaceCslEncrypt
               (undefined8 *param_1,undefined4 param_2,undefined8 param_3,long param_4,
               undefined8 param_5,undefined8 param_6)

{
  if (param_4 != 0) {
    rm_gpu_ops_ccsl_encrypt_with_iv
              (param_1[1],*param_1,param_2,param_3,param_4,param_5,param_6,0x125ce9);
    return;
  }
  rm_gpu_ops_ccsl_encrypt(param_1[1],*param_1,param_2,param_3);
  return;
}


// ===== 00125ce0 nvUvmInterfaceCslEncrypt =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125d10) */

void nvUvmInterfaceCslEncrypt
               (undefined8 *param_1,undefined4 param_2,undefined8 param_3,long param_4,
               undefined8 param_5,undefined8 param_6)

{
  if (param_4 != 0) {
    rm_gpu_ops_ccsl_encrypt_with_iv
              (param_1[1],*param_1,param_2,param_3,param_4,param_5,param_6,0x125ce9);
    return;
  }
  rm_gpu_ops_ccsl_encrypt(param_1[1],*param_1,param_2,param_3);
  return;
}


// ===== 00125d30 __pfx_nvUvmInterfaceCslDecrypt =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125d77) */

void __pfx_nvUvmInterfaceCslDecrypt
               (undefined8 *param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5,undefined8 param_6)

{
  rm_gpu_ops_ccsl_decrypt(param_1[1],*param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ===== 00125d40 nvUvmInterfaceCslDecrypt =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125d77) */

void nvUvmInterfaceCslDecrypt
               (undefined8 *param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5,undefined8 param_6)

{
  rm_gpu_ops_ccsl_decrypt(param_1[1],*param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ===== 00125d80 __pfx_nvUvmInterfaceCslSign =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvUvmInterfaceCslSign
               (undefined8 *param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  rm_gpu_ops_ccsl_sign(param_1[1],*param_1,param_2,param_3,param_4);
  return;
}


// ===== 00125d90 nvUvmInterfaceCslSign =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvUvmInterfaceCslSign
               (undefined8 *param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  rm_gpu_ops_ccsl_sign(param_1[1],*param_1,param_2,param_3,param_4);
  return;
}


// ===== 00125db0 __pfx_nvUvmInterfaceCslQueryMessagePool =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvUvmInterfaceCslQueryMessagePool
               (undefined8 *param_1,undefined1 param_2,undefined8 param_3)

{
  rm_gpu_ops_ccsl_query_message_pool(param_1[1],*param_1,param_2,param_3);
  return;
}


// ===== 00125dc0 nvUvmInterfaceCslQueryMessagePool =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvUvmInterfaceCslQueryMessagePool(undefined8 *param_1,undefined1 param_2,undefined8 param_3)

{
  rm_gpu_ops_ccsl_query_message_pool(param_1[1],*param_1,param_2,param_3);
  return;
}


// ===== 00125de0 __pfx_nvUvmInterfaceCslIncrementIv =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvUvmInterfaceCslIncrementIv
               (undefined8 *param_1,undefined1 param_2,undefined8 param_3,undefined8 param_4)

{
  rm_gpu_ops_ccsl_increment_iv(param_1[1],*param_1,param_2,param_3,param_4);
  return;
}


// ===== 00125df0 nvUvmInterfaceCslIncrementIv =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvUvmInterfaceCslIncrementIv
               (undefined8 *param_1,undefined1 param_2,undefined8 param_3,undefined8 param_4)

{
  rm_gpu_ops_ccsl_increment_iv(param_1[1],*param_1,param_2,param_3,param_4);
  return;
}


// ===== 00125e10 __pfx_nvUvmInterfaceCslLogEncryption =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nvUvmInterfaceCslLogEncryption(undefined8 *param_1,undefined1 param_2,undefined4 param_3)

{
  rm_gpu_ops_ccsl_log_encryption(param_1[1],*param_1,param_2,param_3);
  return;
}


// ===== 00125e20 nvUvmInterfaceCslLogEncryption =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nvUvmInterfaceCslLogEncryption(undefined8 *param_1,undefined1 param_2,undefined4 param_3)

{
  rm_gpu_ops_ccsl_log_encryption(param_1[1],*param_1,param_2,param_3);
  return;
}


// ===== 00125e40 __pfx_nvUvmInterfaceDeinitCslContext =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125e81) */

void __pfx_nvUvmInterfaceDeinitCslContext(undefined8 *param_1)

{
  long lVar1;
  char cVar2;
  
  lVar1 = param_1[1];
  rm_gpu_ops_ccsl_context_clear(lVar1,*param_1);
  if (lVar1 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar1 != 0) {
    cVar2 = rm_is_altstack_in_use();
    if (cVar2 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar1);
      return;
    }
  }
  return;
}


// ===== 00125e50 nvUvmInterfaceDeinitCslContext =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125e81) */

void nvUvmInterfaceDeinitCslContext(undefined8 *param_1)

{
  long lVar1;
  char cVar2;
  
  lVar1 = param_1[1];
  rm_gpu_ops_ccsl_context_clear(lVar1,*param_1);
  if (lVar1 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar1 != 0) {
    cVar2 = rm_is_altstack_in_use();
    if (cVar2 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar1);
      return;
    }
  }
  return;
}


// ===== 00125eb0 __pfx_nvUvmInterfaceServiceDeviceInterruptsRM =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125f34) */
/* WARNING: Removing unreachable block (ram,0x00125f50) */

ulong __pfx_nvUvmInterfaceServiceDeviceInterruptsRM(undefined8 param_1)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_service_device_interrupts_rm(0,param_1);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_service_device_interrupts_rm(puVar4,param_1);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00125ec0 nvUvmInterfaceServiceDeviceInterruptsRM =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125f34) */
/* WARNING: Removing unreachable block (ram,0x00125f50) */

ulong nvUvmInterfaceServiceDeviceInterruptsRM(undefined8 param_1)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_service_device_interrupts_rm(0,param_1);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_service_device_interrupts_rm(puVar4,param_1);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00125f60 __pfx_nvUvmInterfaceQueryCaps =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125ff0) */
/* WARNING: Removing unreachable block (ram,0x0012600d) */

ulong __pfx_nvUvmInterfaceQueryCaps(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_query_caps(0,param_1,param_2);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_query_caps(puVar4,param_1,param_2);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00125f70 nvUvmInterfaceQueryCaps =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00125ff0) */
/* WARNING: Removing unreachable block (ram,0x0012600d) */

ulong nvUvmInterfaceQueryCaps(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_query_caps(0,param_1,param_2);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_query_caps(puVar4,param_1,param_2);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00126020 __pfx_nvUvmInterfaceQueryCopyEnginesCaps =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001260b0) */
/* WARNING: Removing unreachable block (ram,0x001260cd) */

ulong __pfx_nvUvmInterfaceQueryCopyEnginesCaps(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_query_ces_caps(0,param_1,param_2);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_query_ces_caps(puVar4,param_1,param_2);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00126030 nvUvmInterfaceQueryCopyEnginesCaps =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001260b0) */
/* WARNING: Removing unreachable block (ram,0x001260cd) */

ulong nvUvmInterfaceQueryCopyEnginesCaps(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_query_ces_caps(0,param_1,param_2);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_query_ces_caps(puVar4,param_1,param_2);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 001260e0 __pfx_nvUvmInterfaceGetFbInfo =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00126170) */
/* WARNING: Removing unreachable block (ram,0x0012618d) */

ulong __pfx_nvUvmInterfaceGetFbInfo(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_get_fb_info(0,param_1,param_2);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_get_fb_info(puVar4,param_1,param_2);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 001260f0 nvUvmInterfaceGetFbInfo =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00126170) */
/* WARNING: Removing unreachable block (ram,0x0012618d) */

ulong nvUvmInterfaceGetFbInfo(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_get_fb_info(0,param_1,param_2);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_get_fb_info(puVar4,param_1,param_2);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 001261a0 __pfx_nvUvmInterfaceGetEccInfo =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00126230) */
/* WARNING: Removing unreachable block (ram,0x0012624d) */

ulong __pfx_nvUvmInterfaceGetEccInfo(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_get_ecc_info(0,param_1,param_2);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_get_ecc_info(puVar4,param_1,param_2);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 001261b0 nvUvmInterfaceGetEccInfo =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00126230) */
/* WARNING: Removing unreachable block (ram,0x0012624d) */

ulong nvUvmInterfaceGetEccInfo(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_get_ecc_info(0,param_1,param_2);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_get_ecc_info(puVar4,param_1,param_2);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00126260 __pfx_nvUvmInterfaceOwnPageFaultIntr =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001262ef) */
/* WARNING: Removing unreachable block (ram,0x0012630c) */

ulong __pfx_nvUvmInterfaceOwnPageFaultIntr(undefined8 param_1,undefined1 param_2)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_own_page_fault_intr(0,param_1,param_2);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_own_page_fault_intr(puVar4,param_1,param_2);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00126270 nvUvmInterfaceOwnPageFaultIntr =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001262ef) */
/* WARNING: Removing unreachable block (ram,0x0012630c) */

ulong nvUvmInterfaceOwnPageFaultIntr(undefined8 param_1,undefined1 param_2)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_own_page_fault_intr(0,param_1,param_2);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_own_page_fault_intr(puVar4,param_1,param_2);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00126320 __pfx_nvUvmInterfaceGetNvlinkInfo =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001263b0) */
/* WARNING: Removing unreachable block (ram,0x001263cd) */

ulong __pfx_nvUvmInterfaceGetNvlinkInfo(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_get_nvlink_info(0,param_1,param_2);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_get_nvlink_info(puVar4,param_1,param_2);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00126330 nvUvmInterfaceGetNvlinkInfo =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001263b0) */
/* WARNING: Removing unreachable block (ram,0x001263cd) */

ulong nvUvmInterfaceGetNvlinkInfo(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_get_nvlink_info(0,param_1,param_2);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_get_nvlink_info(puVar4,param_1,param_2);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 001263e0 __pfx_nvUvmInterfaceBindChannelResources =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00126470) */
/* WARNING: Removing unreachable block (ram,0x0012648d) */

ulong __pfx_nvUvmInterfaceBindChannelResources(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_bind_channel_resources(0,param_1,param_2);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_bind_channel_resources(puVar4,param_1,param_2);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 001263f0 nvUvmInterfaceBindChannelResources =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00126470) */
/* WARNING: Removing unreachable block (ram,0x0012648d) */

ulong nvUvmInterfaceBindChannelResources(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_bind_channel_resources(0,param_1,param_2);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_bind_channel_resources(puVar4,param_1,param_2);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 001264a0 __pfx_nvUvmInterfaceGetP2PCaps =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012653c) */
/* WARNING: Removing unreachable block (ram,0x0012655b) */

ulong __pfx_nvUvmInterfaceGetP2PCaps(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_get_p2p_caps(0,param_1,param_2,param_3);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_get_p2p_caps(puVar4,param_1,param_2,param_3);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 001264b0 nvUvmInterfaceGetP2PCaps =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012653c) */
/* WARNING: Removing unreachable block (ram,0x0012655b) */

ulong nvUvmInterfaceGetP2PCaps(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_get_p2p_caps(0,param_1,param_2,param_3);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_get_p2p_caps(puVar4,param_1,param_2,param_3);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00126570 __pfx_nvUvmInterfaceGetPmaObject =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012660c) */
/* WARNING: Removing unreachable block (ram,0x0012662b) */

ulong __pfx_nvUvmInterfaceGetPmaObject(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_get_pma_object(0,param_1,param_2,param_3);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_get_pma_object(puVar4,param_1,param_2,param_3);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00126580 nvUvmInterfaceGetPmaObject =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012660c) */
/* WARNING: Removing unreachable block (ram,0x0012662b) */

ulong nvUvmInterfaceGetPmaObject(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_get_pma_object(0,param_1,param_2,param_3);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_get_pma_object(puVar4,param_1,param_2,param_3);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00126640 __pfx_nvUvmInterfaceTsgAllocate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001266dc) */
/* WARNING: Removing unreachable block (ram,0x001266fb) */

ulong __pfx_nvUvmInterfaceTsgAllocate(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_tsg_allocate(0,param_1,param_2,param_3);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_tsg_allocate(puVar4,param_1,param_2,param_3);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00126650 nvUvmInterfaceTsgAllocate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001266dc) */
/* WARNING: Removing unreachable block (ram,0x001266fb) */

ulong nvUvmInterfaceTsgAllocate(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_tsg_allocate(0,param_1,param_2,param_3);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_tsg_allocate(puVar4,param_1,param_2,param_3);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00126710 __pfx_nvUvmInterfaceGetGpuInfo =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001267ac) */
/* WARNING: Removing unreachable block (ram,0x001267cb) */

ulong __pfx_nvUvmInterfaceGetGpuInfo(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_get_gpu_info(0,param_1,param_2,param_3);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_get_gpu_info(puVar4,param_1,param_2,param_3);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00126720 nvUvmInterfaceGetGpuInfo =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001267ac) */
/* WARNING: Removing unreachable block (ram,0x001267cb) */

ulong nvUvmInterfaceGetGpuInfo(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_get_gpu_info(0,param_1,param_2,param_3);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_get_gpu_info(puVar4,param_1,param_2,param_3);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 001267e0 __pfx_nvUvmInterfaceInitAccessCntrInfo =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012687c) */
/* WARNING: Removing unreachable block (ram,0x0012689b) */

ulong __pfx_nvUvmInterfaceInitAccessCntrInfo
                (undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_init_access_cntr_info(0,param_1,param_2,param_3);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_init_access_cntr_info(puVar4,param_1,param_2,param_3);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 001267f0 nvUvmInterfaceInitAccessCntrInfo =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012687c) */
/* WARNING: Removing unreachable block (ram,0x0012689b) */

ulong nvUvmInterfaceInitAccessCntrInfo(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_init_access_cntr_info(0,param_1,param_2,param_3);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_init_access_cntr_info(puVar4,param_1,param_2,param_3);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 001268b0 __pfx_nvUvmInterfaceEnableAccessCntr =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012694c) */
/* WARNING: Removing unreachable block (ram,0x0012696b) */

ulong __pfx_nvUvmInterfaceEnableAccessCntr(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_enable_access_cntr(0,param_1,param_2,param_3);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_enable_access_cntr(puVar4,param_1,param_2,param_3);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 001268c0 nvUvmInterfaceEnableAccessCntr =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012694c) */
/* WARNING: Removing unreachable block (ram,0x0012696b) */

ulong nvUvmInterfaceEnableAccessCntr(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_enable_access_cntr(0,param_1,param_2,param_3);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_enable_access_cntr(puVar4,param_1,param_2,param_3);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00126980 __pfx_nvUvmInterfaceP2pObjectCreate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00126a1c) */
/* WARNING: Removing unreachable block (ram,0x00126a3b) */

ulong __pfx_nvUvmInterfaceP2pObjectCreate(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_p2p_object_create(0,param_1,param_2,param_3);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_p2p_object_create(puVar4,param_1,param_2,param_3);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00126990 nvUvmInterfaceP2pObjectCreate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00126a1c) */
/* WARNING: Removing unreachable block (ram,0x00126a3b) */

ulong nvUvmInterfaceP2pObjectCreate(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_p2p_object_create(0,param_1,param_2,param_3);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_p2p_object_create(puVar4,param_1,param_2,param_3);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00126a50 __pfx_nvUvmInterfaceMemoryAllocFB =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00126afb) */
/* WARNING: Removing unreachable block (ram,0x00126b1c) */

ulong __pfx_nvUvmInterfaceMemoryAllocFB
                (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_memory_alloc_fb(0,param_1,param_2,param_3,param_4);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_memory_alloc_fb(puVar4,param_1,param_2,param_3,param_4);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00126a60 nvUvmInterfaceMemoryAllocFB =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00126afb) */
/* WARNING: Removing unreachable block (ram,0x00126b1c) */

ulong nvUvmInterfaceMemoryAllocFB
                (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_memory_alloc_fb(0,param_1,param_2,param_3,param_4);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_memory_alloc_fb(puVar4,param_1,param_2,param_3,param_4);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00126b30 __pfx_nvUvmInterfaceMemoryAllocSys =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00126bdb) */
/* WARNING: Removing unreachable block (ram,0x00126bfc) */

ulong __pfx_nvUvmInterfaceMemoryAllocSys
                (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_memory_alloc_sys(0,param_1,param_2,param_3,param_4);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_memory_alloc_sys(puVar4,param_1,param_2,param_3,param_4);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00126b40 nvUvmInterfaceMemoryAllocSys =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00126bdb) */
/* WARNING: Removing unreachable block (ram,0x00126bfc) */

ulong nvUvmInterfaceMemoryAllocSys
                (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_memory_alloc_sys(0,param_1,param_2,param_3,param_4);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_memory_alloc_sys(puVar4,param_1,param_2,param_3,param_4);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00126c10 __pfx_nvUvmInterfacePmaRegisterEvictionCallbacks =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00126cbb) */
/* WARNING: Removing unreachable block (ram,0x00126cdc) */

ulong __pfx_nvUvmInterfacePmaRegisterEvictionCallbacks
                (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_pma_register_callbacks(0,param_1,param_2,param_3,param_4);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_pma_register_callbacks(puVar4,param_1,param_2,param_3,param_4);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00126c20 nvUvmInterfacePmaRegisterEvictionCallbacks =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00126cbb) */
/* WARNING: Removing unreachable block (ram,0x00126cdc) */

ulong nvUvmInterfacePmaRegisterEvictionCallbacks
                (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_pma_register_callbacks(0,param_1,param_2,param_3,param_4);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_pma_register_callbacks(puVar4,param_1,param_2,param_3,param_4);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00126cf0 __pfx_nvUvmInterfaceChannelAllocate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00126d9b) */
/* WARNING: Removing unreachable block (ram,0x00126dbc) */

ulong __pfx_nvUvmInterfaceChannelAllocate
                (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_channel_allocate(0,param_1,param_2,param_3,param_4);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_channel_allocate(puVar4,param_1,param_2,param_3,param_4);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00126d00 nvUvmInterfaceChannelAllocate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00126d9b) */
/* WARNING: Removing unreachable block (ram,0x00126dbc) */

ulong nvUvmInterfaceChannelAllocate
                (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_channel_allocate(0,param_1,param_2,param_3,param_4);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_channel_allocate(puVar4,param_1,param_2,param_3,param_4);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00126dd0 __pfx_nvUvmInterfacePagingChannelsMap =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00126e7b) */
/* WARNING: Removing unreachable block (ram,0x00126e9c) */

ulong __pfx_nvUvmInterfacePagingChannelsMap
                (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_paging_channels_map(0,param_1,param_2,param_3,param_4);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_paging_channels_map(puVar4,param_1,param_2,param_3,param_4);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00126de0 nvUvmInterfacePagingChannelsMap =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00126e7b) */
/* WARNING: Removing unreachable block (ram,0x00126e9c) */

ulong nvUvmInterfacePagingChannelsMap
                (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_paging_channels_map(0,param_1,param_2,param_3,param_4);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = 0x51;
  }
  else {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_paging_channels_map(puVar4,param_1,param_2,param_3,param_4);
    uVar3 = (ulong)uVar2;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar4);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00126eb0 __pfx_nvUvmInterfaceDeviceCreate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00126fa7) */
/* WARNING: Removing unreachable block (ram,0x00126f6c) */
/* WARNING: Removing unreachable block (ram,0x00126f84) */

ulong __pfx_nvUvmInterfaceDeviceCreate
                (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_device_create(0,param_1,param_2,param_3,param_4,param_5);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_device_create(puVar4,param_1,param_2,param_3,param_4,param_5);
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 == '\0') {
      return (ulong)uVar2;
    }
    kmem_cache_free(nvidia_stack_t_cache,puVar4);
    return (ulong)uVar2;
  }
  return 0x51;
}


// ===== 00126ec0 nvUvmInterfaceDeviceCreate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00126fa7) */
/* WARNING: Removing unreachable block (ram,0x00126f6c) */
/* WARNING: Removing unreachable block (ram,0x00126f84) */

ulong nvUvmInterfaceDeviceCreate
                (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_device_create(0,param_1,param_2,param_3,param_4,param_5);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_device_create(puVar4,param_1,param_2,param_3,param_4,param_5);
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 == '\0') {
      return (ulong)uVar2;
    }
    kmem_cache_free(nvidia_stack_t_cache,puVar4);
    return (ulong)uVar2;
  }
  return 0x51;
}


// ===== 00126fb0 __pfx_nvUvmInterfaceDupAddressSpace =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001270b1) */
/* WARNING: Removing unreachable block (ram,0x00127071) */
/* WARNING: Removing unreachable block (ram,0x00127089) */

ulong __pfx_nvUvmInterfaceDupAddressSpace
                (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
                undefined8 param_5)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_dup_address_space(0,param_1,param_2,param_3,param_4,param_5);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_dup_address_space(puVar4,param_1,param_2,param_3,param_4,param_5);
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 == '\0') {
      return (ulong)uVar2;
    }
    kmem_cache_free(nvidia_stack_t_cache,puVar4);
    return (ulong)uVar2;
  }
  return 0x51;
}


// ===== 00126fc0 nvUvmInterfaceDupAddressSpace =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001270b1) */
/* WARNING: Removing unreachable block (ram,0x00127071) */
/* WARNING: Removing unreachable block (ram,0x00127089) */

ulong nvUvmInterfaceDupAddressSpace
                (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
                undefined8 param_5)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_dup_address_space(0,param_1,param_2,param_3,param_4,param_5);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_dup_address_space(puVar4,param_1,param_2,param_3,param_4,param_5);
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 == '\0') {
      return (ulong)uVar2;
    }
    kmem_cache_free(nvidia_stack_t_cache,puVar4);
    return (ulong)uVar2;
  }
  return 0x51;
}


// ===== 001270c0 __pfx_nvUvmInterfacePmaAllocPages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001271b3) */
/* WARNING: Removing unreachable block (ram,0x00127178) */
/* WARNING: Removing unreachable block (ram,0x00127190) */

ulong __pfx_nvUvmInterfacePmaAllocPages
                (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
                undefined8 param_5)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_pma_alloc_pages(0,param_1,param_2,param_3,param_4,param_5);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_pma_alloc_pages(puVar4,param_1,param_2,param_3,param_4,param_5);
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 == '\0') {
      return (ulong)uVar2;
    }
    kmem_cache_free(nvidia_stack_t_cache,puVar4);
    return (ulong)uVar2;
  }
  return 0x51;
}


// ===== 001270d0 nvUvmInterfacePmaAllocPages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001271b3) */
/* WARNING: Removing unreachable block (ram,0x00127178) */
/* WARNING: Removing unreachable block (ram,0x00127190) */

ulong nvUvmInterfacePmaAllocPages
                (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
                undefined8 param_5)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_pma_alloc_pages(0,param_1,param_2,param_3,param_4,param_5);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_pma_alloc_pages(puVar4,param_1,param_2,param_3,param_4,param_5);
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 == '\0') {
      return (ulong)uVar2;
    }
    kmem_cache_free(nvidia_stack_t_cache,puVar4);
    return (ulong)uVar2;
  }
  return 0x51;
}


// ===== 001271c0 __pfx_nvUvmInterfacePmaPinPages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001272b5) */
/* WARNING: Removing unreachable block (ram,0x0012727a) */
/* WARNING: Removing unreachable block (ram,0x00127292) */

ulong __pfx_nvUvmInterfacePmaPinPages
                (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined4 param_5)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_pma_pin_pages(0,param_1,param_2,param_3,param_4,param_5);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_pma_pin_pages(puVar4,param_1,param_2,param_3,param_4,param_5);
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 == '\0') {
      return (ulong)uVar2;
    }
    kmem_cache_free(nvidia_stack_t_cache,puVar4);
    return (ulong)uVar2;
  }
  return 0x51;
}


// ===== 001271d0 nvUvmInterfacePmaPinPages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001272b5) */
/* WARNING: Removing unreachable block (ram,0x0012727a) */
/* WARNING: Removing unreachable block (ram,0x00127292) */

ulong nvUvmInterfacePmaPinPages
                (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined4 param_5)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_pma_pin_pages(0,param_1,param_2,param_3,param_4,param_5);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_pma_pin_pages(puVar4,param_1,param_2,param_3,param_4,param_5);
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 == '\0') {
      return (ulong)uVar2;
    }
    kmem_cache_free(nvidia_stack_t_cache,puVar4);
    return (ulong)uVar2;
  }
  return 0x51;
}


// ===== 001272c0 __pfx_nvUvmInterfaceMemoryCpuMap =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001273b5) */
/* WARNING: Removing unreachable block (ram,0x0012737a) */
/* WARNING: Removing unreachable block (ram,0x00127392) */

ulong __pfx_nvUvmInterfaceMemoryCpuMap
                (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined4 param_5)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_memory_cpu_map(0,param_1,param_2,param_3,param_4,param_5);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_memory_cpu_map(puVar4,param_1,param_2,param_3,param_4,param_5);
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 == '\0') {
      return (ulong)uVar2;
    }
    kmem_cache_free(nvidia_stack_t_cache,puVar4);
    return (ulong)uVar2;
  }
  return 0x51;
}


// ===== 001272d0 nvUvmInterfaceMemoryCpuMap =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001273b5) */
/* WARNING: Removing unreachable block (ram,0x0012737a) */
/* WARNING: Removing unreachable block (ram,0x00127392) */

ulong nvUvmInterfaceMemoryCpuMap
                (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined4 param_5)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_memory_cpu_map(0,param_1,param_2,param_3,param_4,param_5);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_memory_cpu_map(puVar4,param_1,param_2,param_3,param_4,param_5);
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 == '\0') {
      return (ulong)uVar2;
    }
    kmem_cache_free(nvidia_stack_t_cache,puVar4);
    return (ulong)uVar2;
  }
  return 0x51;
}


// ===== 001273c0 __pfx_nvUvmInterfaceDupAllocation =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001274c1) */
/* WARNING: Removing unreachable block (ram,0x00127481) */
/* WARNING: Removing unreachable block (ram,0x00127499) */

ulong __pfx_nvUvmInterfaceDupAllocation
                (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined8 param_5)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_dup_allocation(0,param_1,param_2,param_3,param_4,param_5);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_dup_allocation(puVar4,param_1,param_2,param_3,param_4,param_5);
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 == '\0') {
      return (ulong)uVar2;
    }
    kmem_cache_free(nvidia_stack_t_cache,puVar4);
    return (ulong)uVar2;
  }
  return 0x51;
}


// ===== 001273d0 nvUvmInterfaceDupAllocation =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001274c1) */
/* WARNING: Removing unreachable block (ram,0x00127481) */
/* WARNING: Removing unreachable block (ram,0x00127499) */

ulong nvUvmInterfaceDupAllocation
                (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined8 param_5)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_dup_allocation(0,param_1,param_2,param_3,param_4,param_5);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_dup_allocation(puVar4,param_1,param_2,param_3,param_4,param_5);
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 == '\0') {
      return (ulong)uVar2;
    }
    kmem_cache_free(nvidia_stack_t_cache,puVar4);
    return (ulong)uVar2;
  }
  return 0x51;
}


// ===== 001274d0 __pfx_nvUvmInterfaceDupMemory =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001275d1) */
/* WARNING: Removing unreachable block (ram,0x00127591) */
/* WARNING: Removing unreachable block (ram,0x001275a9) */

ulong __pfx_nvUvmInterfaceDupMemory
                (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
                undefined8 param_5)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_dup_memory(0,param_1,param_2,param_3,param_4,param_5);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_dup_memory(puVar4,param_1,param_2,param_3,param_4,param_5);
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 == '\0') {
      return (ulong)uVar2;
    }
    kmem_cache_free(nvidia_stack_t_cache,puVar4);
    return (ulong)uVar2;
  }
  return 0x51;
}


// ===== 001274e0 nvUvmInterfaceDupMemory =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001275d1) */
/* WARNING: Removing unreachable block (ram,0x00127591) */
/* WARNING: Removing unreachable block (ram,0x001275a9) */

ulong nvUvmInterfaceDupMemory
                (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
                undefined8 param_5)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_dup_memory(0,param_1,param_2,param_3,param_4,param_5);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_dup_memory(puVar4,param_1,param_2,param_3,param_4,param_5);
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 == '\0') {
      return (ulong)uVar2;
    }
    kmem_cache_free(nvidia_stack_t_cache,puVar4);
    return (ulong)uVar2;
  }
  return 0x51;
}


// ===== 001275e0 __pfx_nvUvmInterfaceGetExternalAllocPtes =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001276e1) */
/* WARNING: Removing unreachable block (ram,0x001276a1) */
/* WARNING: Removing unreachable block (ram,0x001276b9) */

ulong __pfx_nvUvmInterfaceGetExternalAllocPtes
                (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
                undefined8 param_5)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_get_external_alloc_ptes(0,param_1,param_2,param_3,param_4,param_5);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_get_external_alloc_ptes(puVar4,param_1,param_2,param_3,param_4,param_5);
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 == '\0') {
      return (ulong)uVar2;
    }
    kmem_cache_free(nvidia_stack_t_cache,puVar4);
    return (ulong)uVar2;
  }
  return 0x51;
}


// ===== 001275f0 nvUvmInterfaceGetExternalAllocPtes =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001276e1) */
/* WARNING: Removing unreachable block (ram,0x001276a1) */
/* WARNING: Removing unreachable block (ram,0x001276b9) */

ulong nvUvmInterfaceGetExternalAllocPtes
                (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
                undefined8 param_5)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_get_external_alloc_ptes(0,param_1,param_2,param_3,param_4,param_5);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_get_external_alloc_ptes(puVar4,param_1,param_2,param_3,param_4,param_5);
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 == '\0') {
      return (ulong)uVar2;
    }
    kmem_cache_free(nvidia_stack_t_cache,puVar4);
    return (ulong)uVar2;
  }
  return 0x51;
}


// ===== 001276f0 __pfx_nvUvmInterfaceGetExternalAllocPhysAddrs =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001277f1) */
/* WARNING: Removing unreachable block (ram,0x001277b1) */
/* WARNING: Removing unreachable block (ram,0x001277c9) */

ulong __pfx_nvUvmInterfaceGetExternalAllocPhysAddrs
                (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
                undefined8 param_5)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_get_external_alloc_phys_addrs(0,param_1,param_2,param_3,param_4,param_5);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_get_external_alloc_phys_addrs(puVar4,param_1,param_2,param_3,param_4,param_5)
    ;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 == '\0') {
      return (ulong)uVar2;
    }
    kmem_cache_free(nvidia_stack_t_cache,puVar4);
    return (ulong)uVar2;
  }
  return 0x51;
}


// ===== 00127700 nvUvmInterfaceGetExternalAllocPhysAddrs =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001277f1) */
/* WARNING: Removing unreachable block (ram,0x001277b1) */
/* WARNING: Removing unreachable block (ram,0x001277c9) */

ulong nvUvmInterfaceGetExternalAllocPhysAddrs
                (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
                undefined8 param_5)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_get_external_alloc_phys_addrs(0,param_1,param_2,param_3,param_4,param_5);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_get_external_alloc_phys_addrs(puVar4,param_1,param_2,param_3,param_4,param_5)
    ;
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 == '\0') {
      return (ulong)uVar2;
    }
    kmem_cache_free(nvidia_stack_t_cache,puVar4);
    return (ulong)uVar2;
  }
  return 0x51;
}


// ===== 00127800 __pfx_nvUvmInterfaceRetainChannel =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00127901) */
/* WARNING: Removing unreachable block (ram,0x001278c1) */
/* WARNING: Removing unreachable block (ram,0x001278d9) */

ulong __pfx_nvUvmInterfaceRetainChannel
                (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
                undefined8 param_5)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_retain_channel(0,param_1,param_2,param_3,param_4,param_5);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_retain_channel(puVar4,param_1,param_2,param_3,param_4,param_5);
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 == '\0') {
      return (ulong)uVar2;
    }
    kmem_cache_free(nvidia_stack_t_cache,puVar4);
    return (ulong)uVar2;
  }
  return 0x51;
}


// ===== 00127810 nvUvmInterfaceRetainChannel =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00127901) */
/* WARNING: Removing unreachable block (ram,0x001278c1) */
/* WARNING: Removing unreachable block (ram,0x001278d9) */

ulong nvUvmInterfaceRetainChannel
                (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
                undefined8 param_5)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_retain_channel(0,param_1,param_2,param_3,param_4,param_5);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_retain_channel(puVar4,param_1,param_2,param_3,param_4,param_5);
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 == '\0') {
      return (ulong)uVar2;
    }
    kmem_cache_free(nvidia_stack_t_cache,puVar4);
    return (ulong)uVar2;
  }
  return 0x51;
}


// ===== 00127910 __pfx_nvUvmInterfaceGetChannelResourcePtes =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00127a11) */
/* WARNING: Removing unreachable block (ram,0x001279d1) */
/* WARNING: Removing unreachable block (ram,0x001279e9) */

ulong __pfx_nvUvmInterfaceGetChannelResourcePtes
                (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined8 param_5)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_get_channel_resource_ptes(0,param_1,param_2,param_3,param_4,param_5);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_get_channel_resource_ptes(puVar4,param_1,param_2,param_3,param_4,param_5);
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 == '\0') {
      return (ulong)uVar2;
    }
    kmem_cache_free(nvidia_stack_t_cache,puVar4);
    return (ulong)uVar2;
  }
  return 0x51;
}


// ===== 00127920 nvUvmInterfaceGetChannelResourcePtes =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00127a11) */
/* WARNING: Removing unreachable block (ram,0x001279d1) */
/* WARNING: Removing unreachable block (ram,0x001279e9) */

ulong nvUvmInterfaceGetChannelResourcePtes
                (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined8 param_5)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar3 = rm_gpu_ops_get_channel_resource_ptes(0,param_1,param_2,param_3,param_4,param_5);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    uVar2 = rm_gpu_ops_get_channel_resource_ptes(puVar4,param_1,param_2,param_3,param_4,param_5);
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 == '\0') {
      return (ulong)uVar2;
    }
    kmem_cache_free(nvidia_stack_t_cache,puVar4);
    return (ulong)uVar2;
  }
  return 0x51;
}


// ===== 00127a20 __pfx_nvUvmInterfaceAddressSpaceCreate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00127a8c) */

undefined4
__pfx_nvUvmInterfaceAddressSpaceCreate
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4,
          undefined8 param_5,undefined8 param_6)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar2 = rm_gpu_ops_address_space_create(0,param_1,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    puVar3 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar3 == (undefined4 *)0x0) {
      uVar2 = 0x51;
    }
    else {
      *puVar3 = 0x2ff0;
      *(undefined4 **)(puVar3 + 2) = puVar3 + 0xc00;
      uVar2 = rm_gpu_ops_address_space_create(puVar3,param_1,param_2,param_3,param_4,param_5);
      cVar1 = rm_is_altstack_in_use();
      if (cVar1 != '\0') {
        kmem_cache_free(nvidia_stack_t_cache,puVar3,param_6);
      }
    }
  }
  return uVar2;
}


// ===== 00127a30 nvUvmInterfaceAddressSpaceCreate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00127a8c) */

undefined4
nvUvmInterfaceAddressSpaceCreate
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4,
          undefined8 param_5,undefined8 param_6)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar2 = rm_gpu_ops_address_space_create(0,param_1,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    puVar3 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar3 == (undefined4 *)0x0) {
      uVar2 = 0x51;
    }
    else {
      *puVar3 = 0x2ff0;
      *(undefined4 **)(puVar3 + 2) = puVar3 + 0xc00;
      uVar2 = rm_gpu_ops_address_space_create(puVar3,param_1,param_2,param_3,param_4,param_5);
      cVar1 = rm_is_altstack_in_use();
      if (cVar1 != '\0') {
        kmem_cache_free(nvidia_stack_t_cache,puVar3,param_6);
      }
    }
  }
  return uVar2;
}


// ===== 00127b00 __pfx_nvUvmInterfaceSetPageDirectory =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00127b6c) */

undefined4
__pfx_nvUvmInterfaceSetPageDirectory
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined1 param_4,
          undefined4 param_5,undefined8 param_6)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar2 = rm_gpu_ops_set_page_directory(0,param_1,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    puVar3 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar3 == (undefined4 *)0x0) {
      uVar2 = 0x51;
    }
    else {
      *puVar3 = 0x2ff0;
      *(undefined4 **)(puVar3 + 2) = puVar3 + 0xc00;
      uVar2 = rm_gpu_ops_set_page_directory(puVar3,param_1,param_2,param_3,param_4,param_5);
      cVar1 = rm_is_altstack_in_use();
      if (cVar1 != '\0') {
        kmem_cache_free(nvidia_stack_t_cache,puVar3,param_6);
      }
    }
  }
  return uVar2;
}


// ===== 00127b10 nvUvmInterfaceSetPageDirectory =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00127b6c) */

undefined4
nvUvmInterfaceSetPageDirectory
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined1 param_4,
          undefined4 param_5,undefined8 param_6)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    uVar2 = rm_gpu_ops_set_page_directory(0,param_1,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    puVar3 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar3 == (undefined4 *)0x0) {
      uVar2 = 0x51;
    }
    else {
      *puVar3 = 0x2ff0;
      *(undefined4 **)(puVar3 + 2) = puVar3 + 0xc00;
      uVar2 = rm_gpu_ops_set_page_directory(puVar3,param_1,param_2,param_3,param_4,param_5);
      cVar1 = rm_is_altstack_in_use();
      if (cVar1 != '\0') {
        kmem_cache_free(nvidia_stack_t_cache,puVar3,param_6);
      }
    }
  }
  return uVar2;
}


// ===== 00127be0 __pfx_nvUvmInterfaceSessionCreate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00127cbf) */
/* WARNING: Removing unreachable block (ram,0x00127c90) */
/* WARNING: Removing unreachable block (ram,0x00127ca2) */

ulong __pfx_nvUvmInterfaceSessionCreate(undefined8 param_1,undefined1 *param_2)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    *param_2 = nv_ats_supported;
    param_2[1] = os_cc_sme_enabled._4_1_;
    uVar3 = rm_gpu_ops_create_session(0,param_1);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    *param_2 = nv_ats_supported;
    param_2[1] = os_cc_sme_enabled._4_1_;
    uVar2 = rm_gpu_ops_create_session(puVar4,param_1);
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 == '\0') {
      return (ulong)uVar2;
    }
    kmem_cache_free(nvidia_stack_t_cache,puVar4);
    return (ulong)uVar2;
  }
  return 0x51;
}


// ===== 00127bf0 nvUvmInterfaceSessionCreate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00127cbf) */
/* WARNING: Removing unreachable block (ram,0x00127c90) */
/* WARNING: Removing unreachable block (ram,0x00127ca2) */

ulong nvUvmInterfaceSessionCreate(undefined8 param_1,undefined1 *param_2)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    *param_2 = nv_ats_supported;
    param_2[1] = os_cc_sme_enabled._4_1_;
    uVar3 = rm_gpu_ops_create_session(0,param_1);
    return uVar3;
  }
  puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    *param_2 = nv_ats_supported;
    param_2[1] = os_cc_sme_enabled._4_1_;
    uVar2 = rm_gpu_ops_create_session(puVar4,param_1);
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 == '\0') {
      return (ulong)uVar2;
    }
    kmem_cache_free(nvidia_stack_t_cache,puVar4);
    return (ulong)uVar2;
  }
  return 0x51;
}


// ===== 00127cd0 __pfx_nvUvmInterfaceRegisterGpu =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00127dff) */
/* WARNING: Removing unreachable block (ram,0x00127d50) */
/* WARNING: Removing unreachable block (ram,0x00127de0) */

undefined4 __pfx_nvUvmInterfaceRegisterGpu(undefined8 param_1,long param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)0x0;
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 != '\0') {
    puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar4 == (undefined4 *)0x0) {
      return 0x51;
    }
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
  }
  iVar2 = nvidia_dev_get_uuid(param_1,puVar4);
  if (iVar2 == 0) {
    iVar2 = nvidia_dev_get_pci_info(param_1,param_2,param_2 + 8,param_2 + 0x10);
    if (iVar2 == 0) {
      uVar3 = 0;
      iVar2 = nvidia_dev_block_gc6(param_1,puVar4);
      if (iVar2 == 0) goto LAB_00127d33;
    }
    nvidia_dev_put_uuid(param_1,puVar4);
  }
  uVar3 = 0x12;
  if ((iVar2 != -0x13) && (uVar3 = 0xffff, iVar2 == -0xc)) {
    uVar3 = 0x51;
  }
LAB_00127d33:
  if ((puVar4 != (undefined4 *)0x0) && (cVar1 = rm_is_altstack_in_use(), cVar1 != '\0')) {
    kmem_cache_free(nvidia_stack_t_cache,puVar4);
    return uVar3;
  }
  return uVar3;
}


// ===== 00127ce0 nvUvmInterfaceRegisterGpu =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00127dff) */
/* WARNING: Removing unreachable block (ram,0x00127d50) */
/* WARNING: Removing unreachable block (ram,0x00127de0) */

undefined4 nvUvmInterfaceRegisterGpu(undefined8 param_1,long param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)0x0;
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 != '\0') {
    puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar4 == (undefined4 *)0x0) {
      return 0x51;
    }
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
  }
  iVar2 = nvidia_dev_get_uuid(param_1,puVar4);
  if (iVar2 == 0) {
    iVar2 = nvidia_dev_get_pci_info(param_1,param_2,param_2 + 8,param_2 + 0x10);
    if (iVar2 == 0) {
      uVar3 = 0;
      iVar2 = nvidia_dev_block_gc6(param_1,puVar4);
      if (iVar2 == 0) goto LAB_00127d33;
    }
    nvidia_dev_put_uuid(param_1,puVar4);
  }
  uVar3 = 0x12;
  if ((iVar2 != -0x13) && (uVar3 = 0xffff, iVar2 == -0xc)) {
    uVar3 = 0x51;
  }
LAB_00127d33:
  if ((puVar4 != (undefined4 *)0x0) && (cVar1 = rm_is_altstack_in_use(), cVar1 != '\0')) {
    kmem_cache_free(nvidia_stack_t_cache,puVar4);
    return uVar3;
  }
  return uVar3;
}


// ===== 00127e10 __pfx_nvUvmInterfaceCslInitContext =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00127e62) */
/* WARNING: Removing unreachable block (ram,0x00127edb) */

int __pfx_nvUvmInterfaceCslInitContext(long param_1,undefined8 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    iVar2 = rm_gpu_ops_ccsl_context_init(0,param_1,param_2);
    puVar3 = (undefined4 *)0x0;
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  else {
    puVar3 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar3 == (undefined4 *)0x0) {
      return 0x51;
    }
    *puVar3 = 0x2ff0;
    *(undefined4 **)(puVar3 + 2) = puVar3 + 0xc00;
    iVar2 = rm_gpu_ops_ccsl_context_init(puVar3,param_1,param_2);
    if (iVar2 != 0) {
      cVar1 = rm_is_altstack_in_use();
      if (cVar1 == '\0') {
        return iVar2;
      }
      kmem_cache_free(nvidia_stack_t_cache,puVar3);
      return iVar2;
    }
  }
  *(undefined4 **)(param_1 + 8) = puVar3;
  return 0;
}


// ===== 00127e20 nvUvmInterfaceCslInitContext =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00127e62) */
/* WARNING: Removing unreachable block (ram,0x00127edb) */

int nvUvmInterfaceCslInitContext(long param_1,undefined8 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    iVar2 = rm_gpu_ops_ccsl_context_init(0,param_1,param_2);
    puVar3 = (undefined4 *)0x0;
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  else {
    puVar3 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar3 == (undefined4 *)0x0) {
      return 0x51;
    }
    *puVar3 = 0x2ff0;
    *(undefined4 **)(puVar3 + 2) = puVar3 + 0xc00;
    iVar2 = rm_gpu_ops_ccsl_context_init(puVar3,param_1,param_2);
    if (iVar2 != 0) {
      cVar1 = rm_is_altstack_in_use();
      if (cVar1 == '\0') {
        return iVar2;
      }
      kmem_cache_free(nvidia_stack_t_cache,puVar3);
      return iVar2;
    }
  }
  *(undefined4 **)(param_1 + 8) = puVar3;
  return 0;
}


// ===== 00127ee0 __pfx_nvUvmGetSafeStack =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00127f85) */
/* WARNING: Removing unreachable block (ram,0x00127f31) */
/* WARNING: Removing unreachable block (ram,0x00127f55) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __pfx_nvUvmGetSafeStack(void)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  ulong uVar4;
  undefined4 *puVar5;
  long in_GS_OFFSET;
  
  uVar4 = (*_mpi_powm)();
  if (((uVar4 & 0x200) == 0) || ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) != 0)) {
    LOCK();
    uVar1 = g_debugGlobalStackCount + 1;
    UNLOCK();
    uVar2 = g_debugGlobalStackCount & 1;
    g_debugGlobalStackCount = uVar1;
    if (uVar2 != 0) goto LAB_00127f36;
  }
  cVar3 = rm_is_altstack_in_use();
  if (cVar3 == '\0') {
    return (undefined4 *)0x0;
  }
  puVar5 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar5 != (undefined4 *)0x0) {
    *puVar5 = 0x2ff0;
    *(undefined4 **)(puVar5 + 2) = puVar5 + 0xc00;
    return puVar5;
  }
LAB_00127f36:
  puVar5 = g_sp;
  down(g_spLock);
  return puVar5;
}


// ===== 00127ef0 nvUvmGetSafeStack =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00127f85) */
/* WARNING: Removing unreachable block (ram,0x00127f31) */
/* WARNING: Removing unreachable block (ram,0x00127f55) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * nvUvmGetSafeStack(void)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  ulong uVar4;
  undefined4 *puVar5;
  long in_GS_OFFSET;
  
  uVar4 = (*_mpi_powm)();
  if (((uVar4 & 0x200) == 0) || ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) != 0)) {
    LOCK();
    uVar1 = g_debugGlobalStackCount + 1;
    UNLOCK();
    uVar2 = g_debugGlobalStackCount & 1;
    g_debugGlobalStackCount = uVar1;
    if (uVar2 != 0) goto LAB_00127f36;
  }
  cVar3 = rm_is_altstack_in_use();
  if (cVar3 == '\0') {
    return (undefined4 *)0x0;
  }
  puVar5 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
  if (puVar5 != (undefined4 *)0x0) {
    *puVar5 = 0x2ff0;
    *(undefined4 **)(puVar5 + 2) = puVar5 + 0xc00;
    return puVar5;
  }
LAB_00127f36:
  puVar5 = g_sp;
  down(g_spLock);
  return puVar5;
}


// ===== 00127f90 __pfx_nvUvmInterfaceUnregisterGpu =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00127fe5) */

void __pfx_nvUvmInterfaceUnregisterGpu(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvUvmGetSafeStack();
  nvidia_dev_unblock_gc6(param_1,lVar2);
  nvidia_dev_put_uuid(param_1,lVar2);
  if (lVar2 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar2 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar2);
      return;
    }
  }
  return;
}


// ===== 00127fa0 nvUvmInterfaceUnregisterGpu =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00127fe5) */

void nvUvmInterfaceUnregisterGpu(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvUvmGetSafeStack();
  nvidia_dev_unblock_gc6(param_1,lVar2);
  nvidia_dev_put_uuid(param_1,lVar2);
  if (lVar2 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar2 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar2);
      return;
    }
  }
  return;
}


// ===== 00128010 __pfx_nvUvmInterfaceSessionDestroy =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012808b) */
/* WARNING: Removing unreachable block (ram,0x0012805e) */
/* WARNING: Removing unreachable block (ram,0x00128073) */

undefined4 __pfx_nvUvmInterfaceSessionDestroy(undefined8 param_1)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = nvUvmGetSafeStack();
  uVar2 = rm_gpu_ops_destroy_session(lVar3,param_1);
  if (lVar3 == g_sp) {
    up(g_spLock);
    return uVar2;
  }
  if (lVar3 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar3);
      return uVar2;
    }
  }
  return uVar2;
}


// ===== 00128020 nvUvmInterfaceSessionDestroy =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012808b) */
/* WARNING: Removing unreachable block (ram,0x0012805e) */
/* WARNING: Removing unreachable block (ram,0x00128073) */

undefined4 nvUvmInterfaceSessionDestroy(undefined8 param_1)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = nvUvmGetSafeStack();
  uVar2 = rm_gpu_ops_destroy_session(lVar3,param_1);
  if (lVar3 == g_sp) {
    up(g_spLock);
    return uVar2;
  }
  if (lVar3 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar3);
      return uVar2;
    }
  }
  return uVar2;
}


// ===== 00128090 __pfx_nvUvmInterfaceDeviceDestroy =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001280da) */

void __pfx_nvUvmInterfaceDeviceDestroy(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvUvmGetSafeStack();
  rm_gpu_ops_device_destroy(lVar2,param_1);
  if (lVar2 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar2 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar2);
      return;
    }
  }
  return;
}


// ===== 001280a0 nvUvmInterfaceDeviceDestroy =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001280da) */

void nvUvmInterfaceDeviceDestroy(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvUvmGetSafeStack();
  rm_gpu_ops_device_destroy(lVar2,param_1);
  if (lVar2 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar2 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar2);
      return;
    }
  }
  return;
}


// ===== 00128100 __pfx_nvUvmInterfaceAddressSpaceDestroy =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012814a) */

void __pfx_nvUvmInterfaceAddressSpaceDestroy(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvUvmGetSafeStack();
  rm_gpu_ops_address_space_destroy(lVar2,param_1);
  if (lVar2 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar2 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar2);
      return;
    }
  }
  return;
}


// ===== 00128110 nvUvmInterfaceAddressSpaceDestroy =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012814a) */

void nvUvmInterfaceAddressSpaceDestroy(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvUvmGetSafeStack();
  rm_gpu_ops_address_space_destroy(lVar2,param_1);
  if (lVar2 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar2 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar2);
      return;
    }
  }
  return;
}


// ===== 00128170 __pfx_nvUvmInterfacePmaUnregisterEvictionCallbacks =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001281ba) */

void __pfx_nvUvmInterfacePmaUnregisterEvictionCallbacks(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvUvmGetSafeStack();
  rm_gpu_ops_pma_unregister_callbacks(lVar2,param_1);
  if (lVar2 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar2 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar2);
      return;
    }
  }
  return;
}


// ===== 00128180 nvUvmInterfacePmaUnregisterEvictionCallbacks =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001281ba) */

void nvUvmInterfacePmaUnregisterEvictionCallbacks(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvUvmGetSafeStack();
  rm_gpu_ops_pma_unregister_callbacks(lVar2,param_1);
  if (lVar2 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar2 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar2);
      return;
    }
  }
  return;
}


// ===== 001281e0 __pfx_nvUvmInterfaceMemoryFree =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128234) */

void __pfx_nvUvmInterfaceMemoryFree(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvUvmGetSafeStack();
  rm_gpu_ops_memory_free(lVar2,param_1,param_2);
  if (lVar2 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar2 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar2);
      return;
    }
  }
  return;
}


// ===== 001281f0 nvUvmInterfaceMemoryFree =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128234) */

void nvUvmInterfaceMemoryFree(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvUvmGetSafeStack();
  rm_gpu_ops_memory_free(lVar2,param_1,param_2);
  if (lVar2 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar2 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar2);
      return;
    }
  }
  return;
}


// ===== 00128260 __pfx_nvUvmInterfacePmaFreePages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001282d2) */

void __pfx_nvUvmInterfacePmaFreePages
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvUvmGetSafeStack();
  rm_gpu_ops_pma_free_pages(lVar2,param_1,param_2,param_3,param_4,param_5);
  if (lVar2 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar2 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar2);
      return;
    }
  }
  return;
}


// ===== 00128270 nvUvmInterfacePmaFreePages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001282d2) */

void nvUvmInterfacePmaFreePages
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvUvmGetSafeStack();
  rm_gpu_ops_pma_free_pages(lVar2,param_1,param_2,param_3,param_4,param_5);
  if (lVar2 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar2 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar2);
      return;
    }
  }
  return;
}


// ===== 00128310 __pfx_nvUvmInterfaceMemoryCpuUnMap =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128364) */

void __pfx_nvUvmInterfaceMemoryCpuUnMap(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvUvmGetSafeStack();
  rm_gpu_ops_memory_cpu_ummap(lVar2,param_1,param_2);
  if (lVar2 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar2 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar2);
      return;
    }
  }
  return;
}


// ===== 00128320 nvUvmInterfaceMemoryCpuUnMap =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128364) */

void nvUvmInterfaceMemoryCpuUnMap(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvUvmGetSafeStack();
  rm_gpu_ops_memory_cpu_ummap(lVar2,param_1,param_2);
  if (lVar2 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar2 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar2);
      return;
    }
  }
  return;
}


// ===== 00128390 __pfx_nvUvmInterfaceTsgDestroy =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001283da) */

void __pfx_nvUvmInterfaceTsgDestroy(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvUvmGetSafeStack();
  rm_gpu_ops_tsg_destroy(lVar2,param_1);
  if (lVar2 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar2 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar2);
      return;
    }
  }
  return;
}


// ===== 001283a0 nvUvmInterfaceTsgDestroy =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001283da) */

void nvUvmInterfaceTsgDestroy(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvUvmGetSafeStack();
  rm_gpu_ops_tsg_destroy(lVar2,param_1);
  if (lVar2 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar2 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar2);
      return;
    }
  }
  return;
}


// ===== 00128400 __pfx_nvUvmInterfaceChannelDestroy =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012844a) */

void __pfx_nvUvmInterfaceChannelDestroy(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvUvmGetSafeStack();
  rm_gpu_ops_channel_destroy(lVar2,param_1);
  if (lVar2 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar2 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar2);
      return;
    }
  }
  return;
}


// ===== 00128410 nvUvmInterfaceChannelDestroy =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012844a) */

void nvUvmInterfaceChannelDestroy(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvUvmGetSafeStack();
  rm_gpu_ops_channel_destroy(lVar2,param_1);
  if (lVar2 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar2 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar2);
      return;
    }
  }
  return;
}


// ===== 00128470 __pfx_nvUvmInterfaceUnsetPageDirectory =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001284eb) */
/* WARNING: Removing unreachable block (ram,0x001284be) */
/* WARNING: Removing unreachable block (ram,0x001284d3) */

undefined4 __pfx_nvUvmInterfaceUnsetPageDirectory(undefined8 param_1)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = nvUvmGetSafeStack();
  uVar2 = rm_gpu_ops_unset_page_directory(lVar3,param_1);
  if (lVar3 == g_sp) {
    up(g_spLock);
    return uVar2;
  }
  if (lVar3 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar3);
      return uVar2;
    }
  }
  return uVar2;
}


// ===== 00128480 nvUvmInterfaceUnsetPageDirectory =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001284eb) */
/* WARNING: Removing unreachable block (ram,0x001284be) */
/* WARNING: Removing unreachable block (ram,0x001284d3) */

undefined4 nvUvmInterfaceUnsetPageDirectory(undefined8 param_1)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = nvUvmGetSafeStack();
  uVar2 = rm_gpu_ops_unset_page_directory(lVar3,param_1);
  if (lVar3 == g_sp) {
    up(g_spLock);
    return uVar2;
  }
  if (lVar3 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar3);
      return uVar2;
    }
  }
  return uVar2;
}


// ===== 001284f0 __pfx_nvUvmInterfaceFreeDupedHandle =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128579) */
/* WARNING: Removing unreachable block (ram,0x00128548) */
/* WARNING: Removing unreachable block (ram,0x0012855f) */

undefined4 __pfx_nvUvmInterfaceFreeDupedHandle(undefined8 param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = nvUvmGetSafeStack();
  uVar2 = rm_gpu_ops_free_duped_handle(lVar3,param_1,param_2);
  if (lVar3 == g_sp) {
    up(g_spLock);
    return uVar2;
  }
  if (lVar3 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar3);
      return uVar2;
    }
  }
  return uVar2;
}


// ===== 00128500 nvUvmInterfaceFreeDupedHandle =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128579) */
/* WARNING: Removing unreachable block (ram,0x00128548) */
/* WARNING: Removing unreachable block (ram,0x0012855f) */

undefined4 nvUvmInterfaceFreeDupedHandle(undefined8 param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = nvUvmGetSafeStack();
  uVar2 = rm_gpu_ops_free_duped_handle(lVar3,param_1,param_2);
  if (lVar3 == g_sp) {
    up(g_spLock);
    return uVar2;
  }
  if (lVar3 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar3);
      return uVar2;
    }
  }
  return uVar2;
}


// ===== 00128580 __pfx_nvUvmInterfaceDestroyFaultInfo =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001286a5) */
/* WARNING: Removing unreachable block (ram,0x0012863c) */
/* WARNING: Removing unreachable block (ram,0x00128657) */

undefined4 __pfx_nvUvmInterfaceDestroyFaultInfo(undefined8 param_1,long param_2)

{
  long lVar1;
  char cVar2;
  undefined4 uVar3;
  long lVar4;
  
  lVar4 = nvUvmGetSafeStack();
  lVar1 = *(long *)(param_2 + 0x60);
  if (lVar1 != 0) {
    cVar2 = rm_is_altstack_in_use();
    if (cVar2 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar1);
    }
  }
  lVar1 = *(long *)(param_2 + 0x88);
  if (lVar1 != 0) {
    cVar2 = rm_is_altstack_in_use();
    if (cVar2 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar1);
    }
  }
  lVar1 = *(long *)(param_2 + 0x80);
  if (lVar1 != 0) {
    cVar2 = rm_is_altstack_in_use();
    if (cVar2 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar1);
    }
  }
  uVar3 = rm_gpu_ops_destroy_fault_info(lVar4,param_1,param_2);
  if (lVar4 != g_sp) {
    if (lVar4 != 0) {
      cVar2 = rm_is_altstack_in_use();
      if (cVar2 != '\0') {
        kmem_cache_free(nvidia_stack_t_cache,lVar4);
        return uVar3;
      }
    }
    return uVar3;
  }
  up(g_spLock);
  return uVar3;
}


// ===== 00128590 nvUvmInterfaceDestroyFaultInfo =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001286a5) */
/* WARNING: Removing unreachable block (ram,0x0012863c) */
/* WARNING: Removing unreachable block (ram,0x00128657) */

undefined4 nvUvmInterfaceDestroyFaultInfo(undefined8 param_1,long param_2)

{
  long lVar1;
  char cVar2;
  undefined4 uVar3;
  long lVar4;
  
  lVar4 = nvUvmGetSafeStack();
  lVar1 = *(long *)(param_2 + 0x60);
  if (lVar1 != 0) {
    cVar2 = rm_is_altstack_in_use();
    if (cVar2 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar1);
    }
  }
  lVar1 = *(long *)(param_2 + 0x88);
  if (lVar1 != 0) {
    cVar2 = rm_is_altstack_in_use();
    if (cVar2 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar1);
    }
  }
  lVar1 = *(long *)(param_2 + 0x80);
  if (lVar1 != 0) {
    cVar2 = rm_is_altstack_in_use();
    if (cVar2 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar1);
    }
  }
  uVar3 = rm_gpu_ops_destroy_fault_info(lVar4,param_1,param_2);
  if (lVar4 != g_sp) {
    if (lVar4 != 0) {
      cVar2 = rm_is_altstack_in_use();
      if (cVar2 != '\0') {
        kmem_cache_free(nvidia_stack_t_cache,lVar4);
        return uVar3;
      }
    }
    return uVar3;
  }
  up(g_spLock);
  return uVar3;
}


// ===== 001286b0 __pfx_nvUvmInterfaceFlushReplayableFaultBuffer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128738) */
/* WARNING: Removing unreachable block (ram,0x00128707) */
/* WARNING: Removing unreachable block (ram,0x0012871e) */

undefined4 __pfx_nvUvmInterfaceFlushReplayableFaultBuffer(undefined8 param_1,undefined1 param_2)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = nvUvmGetSafeStack();
  uVar2 = rm_gpu_ops_flush_replayable_fault_buffer(lVar3,param_1,param_2);
  if (lVar3 == g_sp) {
    up(g_spLock);
    return uVar2;
  }
  if (lVar3 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar3);
      return uVar2;
    }
  }
  return uVar2;
}


// ===== 001286c0 nvUvmInterfaceFlushReplayableFaultBuffer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128738) */
/* WARNING: Removing unreachable block (ram,0x00128707) */
/* WARNING: Removing unreachable block (ram,0x0012871e) */

undefined4 nvUvmInterfaceFlushReplayableFaultBuffer(undefined8 param_1,undefined1 param_2)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = nvUvmGetSafeStack();
  uVar2 = rm_gpu_ops_flush_replayable_fault_buffer(lVar3,param_1,param_2);
  if (lVar3 == g_sp) {
    up(g_spLock);
    return uVar2;
  }
  if (lVar3 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar3);
      return uVar2;
    }
  }
  return uVar2;
}


// ===== 00128740 __pfx_nvUvmInterfaceTogglePrefetchFaults =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001287c8) */
/* WARNING: Removing unreachable block (ram,0x00128797) */
/* WARNING: Removing unreachable block (ram,0x001287ae) */

undefined4 __pfx_nvUvmInterfaceTogglePrefetchFaults(undefined8 param_1,undefined1 param_2)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = nvUvmGetSafeStack();
  uVar2 = rm_gpu_ops_toggle_prefetch_faults(lVar3,param_1,param_2);
  if (lVar3 == g_sp) {
    up(g_spLock);
    return uVar2;
  }
  if (lVar3 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar3);
      return uVar2;
    }
  }
  return uVar2;
}


// ===== 00128750 nvUvmInterfaceTogglePrefetchFaults =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001287c8) */
/* WARNING: Removing unreachable block (ram,0x00128797) */
/* WARNING: Removing unreachable block (ram,0x001287ae) */

undefined4 nvUvmInterfaceTogglePrefetchFaults(undefined8 param_1,undefined1 param_2)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = nvUvmGetSafeStack();
  uVar2 = rm_gpu_ops_toggle_prefetch_faults(lVar3,param_1,param_2);
  if (lVar3 == g_sp) {
    up(g_spLock);
    return uVar2;
  }
  if (lVar3 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar3);
      return uVar2;
    }
  }
  return uVar2;
}


// ===== 001287d0 __pfx_nvUvmInterfaceDestroyAccessCntrInfo =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128859) */
/* WARNING: Removing unreachable block (ram,0x00128828) */
/* WARNING: Removing unreachable block (ram,0x0012883f) */

undefined4 __pfx_nvUvmInterfaceDestroyAccessCntrInfo(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = nvUvmGetSafeStack();
  uVar2 = rm_gpu_ops_destroy_access_cntr_info(lVar3,param_1,param_2);
  if (lVar3 == g_sp) {
    up(g_spLock);
    return uVar2;
  }
  if (lVar3 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar3);
      return uVar2;
    }
  }
  return uVar2;
}


// ===== 001287e0 nvUvmInterfaceDestroyAccessCntrInfo =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128859) */
/* WARNING: Removing unreachable block (ram,0x00128828) */
/* WARNING: Removing unreachable block (ram,0x0012883f) */

undefined4 nvUvmInterfaceDestroyAccessCntrInfo(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = nvUvmGetSafeStack();
  uVar2 = rm_gpu_ops_destroy_access_cntr_info(lVar3,param_1,param_2);
  if (lVar3 == g_sp) {
    up(g_spLock);
    return uVar2;
  }
  if (lVar3 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar3);
      return uVar2;
    }
  }
  return uVar2;
}


// ===== 00128860 __pfx_nvUvmInterfaceDisableAccessCntr =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001288e9) */
/* WARNING: Removing unreachable block (ram,0x001288b8) */
/* WARNING: Removing unreachable block (ram,0x001288cf) */

undefined4 __pfx_nvUvmInterfaceDisableAccessCntr(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = nvUvmGetSafeStack();
  uVar2 = rm_gpu_ops_disable_access_cntr(lVar3,param_1,param_2);
  if (lVar3 == g_sp) {
    up(g_spLock);
    return uVar2;
  }
  if (lVar3 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar3);
      return uVar2;
    }
  }
  return uVar2;
}


// ===== 00128870 nvUvmInterfaceDisableAccessCntr =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001288e9) */
/* WARNING: Removing unreachable block (ram,0x001288b8) */
/* WARNING: Removing unreachable block (ram,0x001288cf) */

undefined4 nvUvmInterfaceDisableAccessCntr(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = nvUvmGetSafeStack();
  uVar2 = rm_gpu_ops_disable_access_cntr(lVar3,param_1,param_2);
  if (lVar3 == g_sp) {
    up(g_spLock);
    return uVar2;
  }
  if (lVar3 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar3);
      return uVar2;
    }
  }
  return uVar2;
}


// ===== 001288f0 __pfx_nvUvmInterfaceAccessBitsBufAlloc =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128979) */
/* WARNING: Removing unreachable block (ram,0x00128948) */
/* WARNING: Removing unreachable block (ram,0x0012895f) */

undefined4 __pfx_nvUvmInterfaceAccessBitsBufAlloc(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = nvUvmGetSafeStack();
  uVar2 = rm_gpu_ops_access_bits_buffer_alloc(lVar3,param_1,param_2);
  if (lVar3 == g_sp) {
    up(g_spLock);
    return uVar2;
  }
  if (lVar3 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar3);
      return uVar2;
    }
  }
  return uVar2;
}


// ===== 00128900 nvUvmInterfaceAccessBitsBufAlloc =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128979) */
/* WARNING: Removing unreachable block (ram,0x00128948) */
/* WARNING: Removing unreachable block (ram,0x0012895f) */

undefined4 nvUvmInterfaceAccessBitsBufAlloc(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = nvUvmGetSafeStack();
  uVar2 = rm_gpu_ops_access_bits_buffer_alloc(lVar3,param_1,param_2);
  if (lVar3 == g_sp) {
    up(g_spLock);
    return uVar2;
  }
  if (lVar3 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar3);
      return uVar2;
    }
  }
  return uVar2;
}


// ===== 00128980 __pfx_nvUvmInterfaceAccessBitsBufFree =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128a09) */
/* WARNING: Removing unreachable block (ram,0x001289d8) */
/* WARNING: Removing unreachable block (ram,0x001289ef) */

undefined4 __pfx_nvUvmInterfaceAccessBitsBufFree(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = nvUvmGetSafeStack();
  uVar2 = rm_gpu_ops_access_bits_buffer_free(lVar3,param_1,param_2);
  if (lVar3 == g_sp) {
    up(g_spLock);
    return uVar2;
  }
  if (lVar3 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar3);
      return uVar2;
    }
  }
  return uVar2;
}


// ===== 00128990 nvUvmInterfaceAccessBitsBufFree =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128a09) */
/* WARNING: Removing unreachable block (ram,0x001289d8) */
/* WARNING: Removing unreachable block (ram,0x001289ef) */

undefined4 nvUvmInterfaceAccessBitsBufFree(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = nvUvmGetSafeStack();
  uVar2 = rm_gpu_ops_access_bits_buffer_free(lVar3,param_1,param_2);
  if (lVar3 == g_sp) {
    up(g_spLock);
    return uVar2;
  }
  if (lVar3 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar3);
      return uVar2;
    }
  }
  return uVar2;
}


// ===== 00128a10 __pfx_nvUvmInterfaceAccessBitsDump =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128aa7) */
/* WARNING: Removing unreachable block (ram,0x00128a72) */
/* WARNING: Removing unreachable block (ram,0x00128a8b) */

undefined4
__pfx_nvUvmInterfaceAccessBitsDump(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = nvUvmGetSafeStack();
  uVar2 = rm_gpu_ops_access_bits_dump(lVar3,param_1,param_2,param_3);
  if (lVar3 == g_sp) {
    up(g_spLock);
    return uVar2;
  }
  if (lVar3 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar3);
      return uVar2;
    }
  }
  return uVar2;
}


// ===== 00128a20 nvUvmInterfaceAccessBitsDump =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128aa7) */
/* WARNING: Removing unreachable block (ram,0x00128a72) */
/* WARNING: Removing unreachable block (ram,0x00128a8b) */

undefined4 nvUvmInterfaceAccessBitsDump(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = nvUvmGetSafeStack();
  uVar2 = rm_gpu_ops_access_bits_dump(lVar3,param_1,param_2,param_3);
  if (lVar3 == g_sp) {
    up(g_spLock);
    return uVar2;
  }
  if (lVar3 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar3);
      return uVar2;
    }
  }
  return uVar2;
}


// ===== 00128ab0 __pfx_nvUvmInterfaceP2pObjectDestroy =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128b04) */

void __pfx_nvUvmInterfaceP2pObjectDestroy(undefined8 param_1,undefined4 param_2)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvUvmGetSafeStack();
  rm_gpu_ops_p2p_object_destroy(lVar2,param_1,param_2);
  if (lVar2 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar2 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar2);
      return;
    }
  }
  return;
}


// ===== 00128ac0 nvUvmInterfaceP2pObjectDestroy =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128b04) */

void nvUvmInterfaceP2pObjectDestroy(undefined8 param_1,undefined4 param_2)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvUvmGetSafeStack();
  rm_gpu_ops_p2p_object_destroy(lVar2,param_1,param_2);
  if (lVar2 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar2 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar2);
      return;
    }
  }
  return;
}


// ===== 00128b30 __pfx_nvUvmInterfaceReleaseChannel =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128b7a) */

void __pfx_nvUvmInterfaceReleaseChannel(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvUvmGetSafeStack();
  rm_gpu_ops_release_channel(lVar2,param_1);
  if (lVar2 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar2 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar2);
      return;
    }
  }
  return;
}


// ===== 00128b40 nvUvmInterfaceReleaseChannel =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128b7a) */

void nvUvmInterfaceReleaseChannel(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvUvmGetSafeStack();
  rm_gpu_ops_release_channel(lVar2,param_1);
  if (lVar2 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar2 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar2);
      return;
    }
  }
  return;
}


// ===== 00128ba0 __pfx_nvUvmInterfaceStopChannel =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128bf3) */

void __pfx_nvUvmInterfaceStopChannel(undefined8 param_1,undefined1 param_2)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvUvmGetSafeStack();
  rm_gpu_ops_stop_channel(lVar2,param_1,param_2);
  if (lVar2 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar2 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar2);
      return;
    }
  }
  return;
}


// ===== 00128bb0 nvUvmInterfaceStopChannel =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128bf3) */

void nvUvmInterfaceStopChannel(undefined8 param_1,undefined1 param_2)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvUvmGetSafeStack();
  rm_gpu_ops_stop_channel(lVar2,param_1,param_2);
  if (lVar2 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar2 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar2);
      return;
    }
  }
  return;
}


// ===== 00128c20 __pfx_nvUvmInterfaceReportNonReplayableFault =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128ca9) */
/* WARNING: Removing unreachable block (ram,0x00128c78) */
/* WARNING: Removing unreachable block (ram,0x00128c8f) */

undefined4 __pfx_nvUvmInterfaceReportNonReplayableFault(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = nvUvmGetSafeStack();
  uVar2 = rm_gpu_ops_report_non_replayable_fault(lVar3,param_1,param_2);
  if (lVar3 == g_sp) {
    up(g_spLock);
    return uVar2;
  }
  if (lVar3 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar3);
      return uVar2;
    }
  }
  return uVar2;
}


// ===== 00128c30 nvUvmInterfaceReportNonReplayableFault =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128ca9) */
/* WARNING: Removing unreachable block (ram,0x00128c78) */
/* WARNING: Removing unreachable block (ram,0x00128c8f) */

undefined4 nvUvmInterfaceReportNonReplayableFault(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = nvUvmGetSafeStack();
  uVar2 = rm_gpu_ops_report_non_replayable_fault(lVar3,param_1,param_2);
  if (lVar3 == g_sp) {
    up(g_spLock);
    return uVar2;
  }
  if (lVar3 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar3);
      return uVar2;
    }
  }
  return uVar2;
}


// ===== 00128cb0 __pfx_nvUvmInterfacePagingChannelDestroy =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128d21) */
/* WARNING: Removing unreachable block (ram,0x00128d38) */

void __pfx_nvUvmInterfacePagingChannelDestroy(long param_1)

{
  long lVar1;
  long lVar2;
  char cVar3;
  
  if (param_1 == 0) {
    return;
  }
  lVar2 = nvUvmGetSafeStack();
  lVar1 = *(long *)(param_1 + 0x18);
  if (lVar1 != 0) {
    cVar3 = rm_is_altstack_in_use();
    if (cVar3 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar1);
    }
  }
  rm_gpu_ops_paging_channel_destroy(lVar2,param_1);
  if (lVar2 != g_sp) {
    if (lVar2 != 0) {
      cVar3 = rm_is_altstack_in_use();
      if (cVar3 != '\0') {
        kmem_cache_free(nvidia_stack_t_cache,lVar2);
        return;
      }
    }
    return;
  }
  up(g_spLock);
  return;
}


// ===== 00128cc0 nvUvmInterfacePagingChannelDestroy =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128d21) */
/* WARNING: Removing unreachable block (ram,0x00128d38) */

void nvUvmInterfacePagingChannelDestroy(long param_1)

{
  long lVar1;
  long lVar2;
  char cVar3;
  
  if (param_1 == 0) {
    return;
  }
  lVar2 = nvUvmGetSafeStack();
  lVar1 = *(long *)(param_1 + 0x18);
  if (lVar1 != 0) {
    cVar3 = rm_is_altstack_in_use();
    if (cVar3 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar1);
    }
  }
  rm_gpu_ops_paging_channel_destroy(lVar2,param_1);
  if (lVar2 != g_sp) {
    if (lVar2 != 0) {
      cVar3 = rm_is_altstack_in_use();
      if (cVar3 != '\0') {
        kmem_cache_free(nvidia_stack_t_cache,lVar2);
        return;
      }
    }
    return;
  }
  up(g_spLock);
  return;
}


// ===== 00128d60 __pfx_nvUvmInterfacePagingChannelsUnmap =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128dbe) */

void __pfx_nvUvmInterfacePagingChannelsUnmap
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvUvmGetSafeStack();
  rm_gpu_ops_paging_channels_unmap(lVar2,param_1,param_2,param_3);
  if (lVar2 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar2 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar2);
      return;
    }
  }
  return;
}


// ===== 00128d70 nvUvmInterfacePagingChannelsUnmap =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128dbe) */

void nvUvmInterfacePagingChannelsUnmap(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvUvmGetSafeStack();
  rm_gpu_ops_paging_channels_unmap(lVar2,param_1,param_2,param_3);
  if (lVar2 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar2 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar2);
      return;
    }
  }
  return;
}


// ===== 00128df0 __pfx_nvUvmInterfaceReportFatalError =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128e38) */

void __pfx_nvUvmInterfaceReportFatalError(undefined4 param_1)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvUvmGetSafeStack();
  rm_gpu_ops_report_fatal_error(lVar2,param_1);
  if (lVar2 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar2 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar2);
      return;
    }
  }
  return;
}


// ===== 00128e00 nvUvmInterfaceReportFatalError =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128e38) */

void nvUvmInterfaceReportFatalError(undefined4 param_1)

{
  char cVar1;
  long lVar2;
  
  lVar2 = nvUvmGetSafeStack();
  rm_gpu_ops_report_fatal_error(lVar2,param_1);
  if (lVar2 == g_sp) {
    up(g_spLock);
    return;
  }
  if (lVar2 != 0) {
    cVar1 = rm_is_altstack_in_use();
    if (cVar1 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,lVar2);
      return;
    }
  }
  return;
}


// ===== 00128e60 __pfx_nvUvmInterfacePagingChannelAllocate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128f8e) */
/* WARNING: Removing unreachable block (ram,0x00128ef0) */
/* WARNING: Removing unreachable block (ram,0x00128fe3) */

int __pfx_nvUvmInterfacePagingChannelAllocate
              (undefined8 param_1,undefined8 param_2,long *param_3,undefined8 param_4)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)0x0;
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 != '\0') {
    puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar4 == (undefined4 *)0x0) {
      return 0x51;
    }
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
  }
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    iVar2 = rm_gpu_ops_paging_channel_allocate(puVar4,param_1,param_2,param_3,param_4);
    puVar3 = (undefined4 *)0x0;
    if (iVar2 != 0) goto LAB_00128ed0;
  }
  else {
    puVar3 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar3 == (undefined4 *)0x0) {
      if ((puVar4 != (undefined4 *)0x0) && (cVar1 = rm_is_altstack_in_use(), cVar1 != '\0')) {
        kmem_cache_free(nvidia_stack_t_cache,puVar4);
      }
      return 0x51;
    }
    *puVar3 = 0x2ff0;
    *(undefined4 **)(puVar3 + 2) = puVar3 + 0xc00;
    iVar2 = rm_gpu_ops_paging_channel_allocate(puVar4,param_1,param_2,param_3,param_4);
    if (iVar2 != 0) {
      cVar1 = rm_is_altstack_in_use();
      if (cVar1 != '\0') {
        kmem_cache_free(nvidia_stack_t_cache,puVar3);
      }
      goto LAB_00128ed0;
    }
  }
  iVar2 = 0;
  *(undefined4 **)(*param_3 + 0x18) = puVar3;
LAB_00128ed0:
  if ((puVar4 != (undefined4 *)0x0) && (cVar1 = rm_is_altstack_in_use(), cVar1 != '\0')) {
    kmem_cache_free(nvidia_stack_t_cache,puVar4);
    return iVar2;
  }
  return iVar2;
}


// ===== 00128e70 nvUvmInterfacePagingChannelAllocate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00128f8e) */
/* WARNING: Removing unreachable block (ram,0x00128ef0) */
/* WARNING: Removing unreachable block (ram,0x00128fe3) */

int nvUvmInterfacePagingChannelAllocate
              (undefined8 param_1,undefined8 param_2,long *param_3,undefined8 param_4)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)0x0;
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 != '\0') {
    puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar4 == (undefined4 *)0x0) {
      return 0x51;
    }
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
  }
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    iVar2 = rm_gpu_ops_paging_channel_allocate(puVar4,param_1,param_2,param_3,param_4);
    puVar3 = (undefined4 *)0x0;
    if (iVar2 != 0) goto LAB_00128ed0;
  }
  else {
    puVar3 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar3 == (undefined4 *)0x0) {
      if ((puVar4 != (undefined4 *)0x0) && (cVar1 = rm_is_altstack_in_use(), cVar1 != '\0')) {
        kmem_cache_free(nvidia_stack_t_cache,puVar4);
      }
      return 0x51;
    }
    *puVar3 = 0x2ff0;
    *(undefined4 **)(puVar3 + 2) = puVar3 + 0xc00;
    iVar2 = rm_gpu_ops_paging_channel_allocate(puVar4,param_1,param_2,param_3,param_4);
    if (iVar2 != 0) {
      cVar1 = rm_is_altstack_in_use();
      if (cVar1 != '\0') {
        kmem_cache_free(nvidia_stack_t_cache,puVar3);
      }
      goto LAB_00128ed0;
    }
  }
  iVar2 = 0;
  *(undefined4 **)(*param_3 + 0x18) = puVar3;
LAB_00128ed0:
  if ((puVar4 != (undefined4 *)0x0) && (cVar1 = rm_is_altstack_in_use(), cVar1 != '\0')) {
    kmem_cache_free(nvidia_stack_t_cache,puVar4);
    return iVar2;
  }
  return iVar2;
}


// ===== 00129000 __pfx_nvUvmInterfaceInitFaultInfo =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012913d) */
/* WARNING: Removing unreachable block (ram,0x0012904f) */
/* WARNING: Removing unreachable block (ram,0x00129151) */

int __pfx_nvUvmInterfaceInitFaultInfo(undefined8 param_1,long param_2)

{
  long lVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  cVar2 = rm_is_altstack_in_use();
  if (cVar2 == '\0') {
    puVar4 = (undefined4 *)0x0;
    iVar3 = rm_gpu_ops_init_fault_info(0,param_1,param_2);
    if (iVar3 != 0) {
      return iVar3;
    }
  }
  else {
    puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar4 == (undefined4 *)0x0) {
      return 0x51;
    }
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    iVar3 = rm_gpu_ops_init_fault_info(puVar4,param_1,param_2);
    if (iVar3 != 0) goto LAB_0012910e;
  }
  *(undefined8 *)(param_2 + 0x80) = 0;
  *(undefined8 *)(param_2 + 0x88) = 0;
  *(undefined8 *)(param_2 + 0x60) = 0;
  cVar2 = rm_is_altstack_in_use();
  puVar5 = (undefined4 *)0x0;
  if (cVar2 == '\0') {
LAB_001290c6:
    *(undefined4 **)(param_2 + 0x80) = puVar5;
    cVar2 = rm_is_altstack_in_use();
    puVar5 = (undefined4 *)0x0;
    if (cVar2 != '\0') {
      puVar5 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
      if (puVar5 == (undefined4 *)0x0) goto LAB_00129182;
      *puVar5 = 0x2ff0;
      *(undefined4 **)(puVar5 + 2) = puVar5 + 0xc00;
    }
    *(undefined4 **)(param_2 + 0x88) = puVar5;
    if (*(long *)(param_2 + 0x58) != 0) {
      cVar2 = rm_is_altstack_in_use();
      puVar5 = (undefined4 *)0x0;
      if (cVar2 != '\0') {
        puVar5 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
        if (puVar5 == (undefined4 *)0x0) goto LAB_00129182;
        *puVar5 = 0x2ff0;
        *(undefined4 **)(puVar5 + 2) = puVar5 + 0xc00;
      }
      *(undefined4 **)(param_2 + 0x60) = puVar5;
    }
    iVar3 = 0;
  }
  else {
    puVar5 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar5 != (undefined4 *)0x0) {
      *puVar5 = 0x2ff0;
      *(undefined4 **)(puVar5 + 2) = puVar5 + 0xc00;
      goto LAB_001290c6;
    }
LAB_00129182:
    lVar1 = *(long *)(param_2 + 0x60);
    if ((lVar1 != 0) && (cVar2 = rm_is_altstack_in_use(), cVar2 != '\0')) {
      kmem_cache_free(nvidia_stack_t_cache,lVar1);
    }
    lVar1 = *(long *)(param_2 + 0x88);
    if ((lVar1 != 0) && (cVar2 = rm_is_altstack_in_use(), cVar2 != '\0')) {
      kmem_cache_free(nvidia_stack_t_cache,lVar1);
    }
    lVar1 = *(long *)(param_2 + 0x80);
    if ((lVar1 != 0) && (cVar2 = rm_is_altstack_in_use(), cVar2 != '\0')) {
      kmem_cache_free(nvidia_stack_t_cache,lVar1);
    }
    rm_gpu_ops_destroy_fault_info(puVar4,param_1,param_2);
    iVar3 = 0x51;
  }
  if (puVar4 == (undefined4 *)0x0) {
    return iVar3;
  }
LAB_0012910e:
  cVar2 = rm_is_altstack_in_use();
  if (cVar2 == '\0') {
    return iVar3;
  }
  kmem_cache_free(nvidia_stack_t_cache,puVar4);
  return iVar3;
}


// ===== 00129010 nvUvmInterfaceInitFaultInfo =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012913d) */
/* WARNING: Removing unreachable block (ram,0x0012904f) */
/* WARNING: Removing unreachable block (ram,0x00129151) */

int nvUvmInterfaceInitFaultInfo(undefined8 param_1,long param_2)

{
  long lVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  cVar2 = rm_is_altstack_in_use();
  if (cVar2 == '\0') {
    puVar4 = (undefined4 *)0x0;
    iVar3 = rm_gpu_ops_init_fault_info(0,param_1,param_2);
    if (iVar3 != 0) {
      return iVar3;
    }
  }
  else {
    puVar4 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar4 == (undefined4 *)0x0) {
      return 0x51;
    }
    *puVar4 = 0x2ff0;
    *(undefined4 **)(puVar4 + 2) = puVar4 + 0xc00;
    iVar3 = rm_gpu_ops_init_fault_info(puVar4,param_1,param_2);
    if (iVar3 != 0) goto LAB_0012910e;
  }
  *(undefined8 *)(param_2 + 0x80) = 0;
  *(undefined8 *)(param_2 + 0x88) = 0;
  *(undefined8 *)(param_2 + 0x60) = 0;
  cVar2 = rm_is_altstack_in_use();
  puVar5 = (undefined4 *)0x0;
  if (cVar2 == '\0') {
LAB_001290c6:
    *(undefined4 **)(param_2 + 0x80) = puVar5;
    cVar2 = rm_is_altstack_in_use();
    puVar5 = (undefined4 *)0x0;
    if (cVar2 != '\0') {
      puVar5 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
      if (puVar5 == (undefined4 *)0x0) goto LAB_00129182;
      *puVar5 = 0x2ff0;
      *(undefined4 **)(puVar5 + 2) = puVar5 + 0xc00;
    }
    *(undefined4 **)(param_2 + 0x88) = puVar5;
    if (*(long *)(param_2 + 0x58) != 0) {
      cVar2 = rm_is_altstack_in_use();
      puVar5 = (undefined4 *)0x0;
      if (cVar2 != '\0') {
        puVar5 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
        if (puVar5 == (undefined4 *)0x0) goto LAB_00129182;
        *puVar5 = 0x2ff0;
        *(undefined4 **)(puVar5 + 2) = puVar5 + 0xc00;
      }
      *(undefined4 **)(param_2 + 0x60) = puVar5;
    }
    iVar3 = 0;
  }
  else {
    puVar5 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar5 != (undefined4 *)0x0) {
      *puVar5 = 0x2ff0;
      *(undefined4 **)(puVar5 + 2) = puVar5 + 0xc00;
      goto LAB_001290c6;
    }
LAB_00129182:
    lVar1 = *(long *)(param_2 + 0x60);
    if ((lVar1 != 0) && (cVar2 = rm_is_altstack_in_use(), cVar2 != '\0')) {
      kmem_cache_free(nvidia_stack_t_cache,lVar1);
    }
    lVar1 = *(long *)(param_2 + 0x88);
    if ((lVar1 != 0) && (cVar2 = rm_is_altstack_in_use(), cVar2 != '\0')) {
      kmem_cache_free(nvidia_stack_t_cache,lVar1);
    }
    lVar1 = *(long *)(param_2 + 0x80);
    if ((lVar1 != 0) && (cVar2 = rm_is_altstack_in_use(), cVar2 != '\0')) {
      kmem_cache_free(nvidia_stack_t_cache,lVar1);
    }
    rm_gpu_ops_destroy_fault_info(puVar4,param_1,param_2);
    iVar3 = 0x51;
  }
  if (puVar4 == (undefined4 *)0x0) {
    return iVar3;
  }
LAB_0012910e:
  cVar2 = rm_is_altstack_in_use();
  if (cVar2 == '\0') {
    return iVar3;
  }
  kmem_cache_free(nvidia_stack_t_cache,puVar4);
  return iVar3;
}


// ===== 00129290 __pfx_nv_uvm_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00129304) */
/* WARNING: Removing unreachable block (ram,0x00129337) */

undefined8 __pfx_nv_uvm_init(void)

{
  char cVar1;
  undefined4 *puVar2;
  
  cVar1 = rm_is_altstack_in_use();
  puVar2 = (undefined4 *)0x0;
  if (cVar1 != '\0') {
    puVar2 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar2 == (undefined4 *)0x0) {
      return 0xfffffff4;
    }
    *puVar2 = 0x2ff0;
    *(undefined4 **)(puVar2 + 2) = puVar2 + 0xc00;
  }
  g_sp = puVar2;
  g_spLock._0_8_ = 0x100000000;
  g_pNvUvmEventsLock._0_8_ = 0x100000000;
  g_spLock._8_8_ = 0;
  g_spLock._16_8_ = 0;
  g_pNvUvmEventsLock._8_8_ = 0;
  g_pNvUvmEventsLock._16_8_ = 0;
  return 0;
}


// ===== 001292a0 nv_uvm_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00129304) */
/* WARNING: Removing unreachable block (ram,0x00129337) */

undefined8 nv_uvm_init(void)

{
  char cVar1;
  undefined4 *puVar2;
  
  cVar1 = rm_is_altstack_in_use();
  puVar2 = (undefined4 *)0x0;
  if (cVar1 != '\0') {
    puVar2 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar2 == (undefined4 *)0x0) {
      return 0xfffffff4;
    }
    *puVar2 = 0x2ff0;
    *(undefined4 **)(puVar2 + 2) = puVar2 + 0xc00;
  }
  g_sp = puVar2;
  g_spLock._0_8_ = 0x100000000;
  g_pNvUvmEventsLock._0_8_ = 0x100000000;
  g_spLock._8_8_ = 0;
  g_spLock._16_8_ = 0;
  g_pNvUvmEventsLock._8_8_ = 0;
  g_pNvUvmEventsLock._16_8_ = 0;
  return 0;
}


// ===== 00129340 __pfx_nv_uvm_exit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00129388) */
/* WARNING: Removing unreachable block (ram,0x0012938d) */

void __pfx_nv_uvm_exit(void)

{
  code *pcVar1;
  long lVar2;
  char cVar3;
  
  lVar2 = g_sp;
  if (g_pNvUvmEvents != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  if (g_sp != 0) {
    cVar3 = rm_is_altstack_in_use();
    if (cVar3 == '\0') {
      return;
    }
    kmem_cache_free(nvidia_stack_t_cache,lVar2);
    return;
  }
  return;
}


// ===== 00129350 nv_uvm_exit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00129388) */
/* WARNING: Removing unreachable block (ram,0x0012938d) */

void nv_uvm_exit(void)

{
  code *pcVar1;
  long lVar2;
  char cVar3;
  
  lVar2 = g_sp;
  if (g_pNvUvmEvents != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  if (g_sp != 0) {
    cVar3 = rm_is_altstack_in_use();
    if (cVar3 == '\0') {
      return;
    }
    kmem_cache_free(nvidia_stack_t_cache,lVar2);
    return;
  }
  return;
}


// ===== 001293b0 __pfx_nv_uvm_suspend =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00129401) */
/* WARNING: Removing unreachable block (ram,0x00129417) */

undefined4 __pfx_nv_uvm_suspend(void)

{
  undefined4 uVar1;
  
  down(g_pNvUvmEventsLock);
  if ((g_pNvUvmEvents != 0) && (*(code **)(g_pNvUvmEvents + 8) != (code *)0x0)) {
    uVar1 = (**(code **)(g_pNvUvmEvents + 8))();
    up(g_pNvUvmEventsLock);
    return uVar1;
  }
  up(g_pNvUvmEventsLock);
  return 0;
}


// ===== 001293c0 nv_uvm_suspend =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00129401) */
/* WARNING: Removing unreachable block (ram,0x00129417) */

undefined4 nv_uvm_suspend(void)

{
  undefined4 uVar1;
  
  down(g_pNvUvmEventsLock);
  if ((g_pNvUvmEvents != 0) && (*(code **)(g_pNvUvmEvents + 8) != (code *)0x0)) {
    uVar1 = (**(code **)(g_pNvUvmEvents + 8))();
    up(g_pNvUvmEventsLock);
    return uVar1;
  }
  up(g_pNvUvmEventsLock);
  return 0;
}


// ===== 00129420 __pfx_nv_uvm_resume =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00129471) */
/* WARNING: Removing unreachable block (ram,0x00129487) */

undefined4 __pfx_nv_uvm_resume(void)

{
  undefined4 uVar1;
  
  down(g_pNvUvmEventsLock);
  if ((g_pNvUvmEvents != 0) && (*(code **)(g_pNvUvmEvents + 0x10) != (code *)0x0)) {
    uVar1 = (**(code **)(g_pNvUvmEvents + 0x10))();
    up(g_pNvUvmEventsLock);
    return uVar1;
  }
  up(g_pNvUvmEventsLock);
  return 0;
}


// ===== 00129430 nv_uvm_resume =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00129471) */
/* WARNING: Removing unreachable block (ram,0x00129487) */

undefined4 nv_uvm_resume(void)

{
  undefined4 uVar1;
  
  down(g_pNvUvmEventsLock);
  if ((g_pNvUvmEvents != 0) && (*(code **)(g_pNvUvmEvents + 0x10) != (code *)0x0)) {
    uVar1 = (**(code **)(g_pNvUvmEvents + 0x10))();
    up(g_pNvUvmEventsLock);
    return uVar1;
  }
  up(g_pNvUvmEventsLock);
  return 0;
}


// ===== 00129490 __pfx_nv_uvm_event_interrupt =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001294c8) */

undefined8 __pfx_nv_uvm_event_interrupt(void)

{
  undefined8 uVar1;
  
  if ((g_pNvUvmEvents != (undefined8 *)0x0) && ((code *)*g_pNvUvmEvents != (code *)0x0)) {
    uVar1 = (*(code *)*g_pNvUvmEvents)();
    return uVar1;
  }
  return 0x50;
}


// ===== 001294a0 nv_uvm_event_interrupt =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001294c8) */

undefined8 nv_uvm_event_interrupt(void)

{
  undefined8 uVar1;
  
  if ((g_pNvUvmEvents != (undefined8 *)0x0) && ((code *)*g_pNvUvmEvents != (code *)0x0)) {
    uVar1 = (*(code *)*g_pNvUvmEvents)();
    return uVar1;
  }
  return 0x50;
}


// ===== 001294d0 __pfx_nv_uvm_drain_P2P =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00129560) */

undefined4 __pfx_nv_uvm_drain_P2P(undefined8 *param_1)

{
  undefined4 uVar1;
  long in_GS_OFFSET;
  undefined8 uStack_40;
  undefined8 uStack_38;
  long lStack_28;
  
  uStack_38 = param_1[1];
  lStack_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_40 = *param_1;
  down(g_pNvUvmEventsLock);
  if ((g_pNvUvmEvents == 0) || (*(code **)(g_pNvUvmEvents + 0x18) == (code *)0x0)) {
    uVar1 = 0x56;
  }
  else {
    uVar1 = (**(code **)(g_pNvUvmEvents + 0x18))(&uStack_40);
  }
  up(g_pNvUvmEventsLock);
  if (lStack_28 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 001294e0 nv_uvm_drain_P2P =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00129560) */

undefined4 nv_uvm_drain_P2P(undefined8 *param_1)

{
  undefined4 uVar1;
  long in_GS_OFFSET;
  undefined8 local_40;
  undefined8 local_38;
  long local_28;
  
  local_38 = param_1[1];
  local_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_40 = *param_1;
  down(g_pNvUvmEventsLock);
  if ((g_pNvUvmEvents == 0) || (*(code **)(g_pNvUvmEvents + 0x18) == (code *)0x0)) {
    uVar1 = 0x56;
  }
  else {
    uVar1 = (**(code **)(g_pNvUvmEvents + 0x18))(&local_40);
  }
  up(g_pNvUvmEventsLock);
  if (local_28 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00129580 __pfx_nv_uvm_resume_P2P =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00129610) */

undefined4 __pfx_nv_uvm_resume_P2P(undefined8 *param_1)

{
  undefined4 uVar1;
  long in_GS_OFFSET;
  undefined8 uStack_40;
  undefined8 uStack_38;
  long lStack_28;
  
  uStack_38 = param_1[1];
  lStack_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_40 = *param_1;
  down(g_pNvUvmEventsLock);
  if ((g_pNvUvmEvents == 0) || (*(code **)(g_pNvUvmEvents + 0x20) == (code *)0x0)) {
    uVar1 = 0x56;
  }
  else {
    uVar1 = (**(code **)(g_pNvUvmEvents + 0x20))(&uStack_40);
  }
  up(g_pNvUvmEventsLock);
  if (lStack_28 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00129590 nv_uvm_resume_P2P =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00129610) */

undefined4 nv_uvm_resume_P2P(undefined8 *param_1)

{
  undefined4 uVar1;
  long in_GS_OFFSET;
  undefined8 local_40;
  undefined8 local_38;
  long local_28;
  
  local_38 = param_1[1];
  local_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_40 = *param_1;
  down(g_pNvUvmEventsLock);
  if ((g_pNvUvmEvents == 0) || (*(code **)(g_pNvUvmEvents + 0x20) == (code *)0x0)) {
    uVar1 = 0x56;
  }
  else {
    uVar1 = (**(code **)(g_pNvUvmEvents + 0x20))(&local_40);
  }
  up(g_pNvUvmEventsLock);
  if (local_28 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00129630 __pfx_lkca_aead_internal =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001297c1) */
/* WARNING: Type propagation algorithm not settling */

ulong __pfx_lkca_aead_internal
                (long param_1,long param_2,undefined8 param_3,undefined4 param_4,undefined8 param_5,
                ulong param_6,undefined8 param_7,undefined4 param_8,undefined8 param_9,
                undefined8 *param_10,int param_11,char param_12)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  long in_GS_OFFSET;
  undefined8 unaff_retaddr;
  ulong auStack_68 [4];
  ulong uStack_48;
  long lStack_40;
  
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  auStack_68[0] = 0;
  auStack_68[1] = 0;
  auStack_68[2] = 0;
  auStack_68[3] = 0;
  uStack_48 = 0;
  __init_swait_queue_head(auStack_68 + 1,"&x->wait",&nvlink_permissions);
  iVar1 = crypto_aead_setkey(param_1,param_3,param_4);
  if (iVar1 == 0) {
    if (*(uint *)(*(long *)(param_1 + 0x28) + -0x10) == param_6) {
      *(undefined **)(param_2 + 0x10) = &crypto_req_done;
      *(ulong **)(param_2 + 0x18) = auStack_68;
      *(undefined4 *)(param_2 + 0x30) = param_8;
      *(undefined4 *)(param_2 + 0x28) = 0x600;
      *(undefined8 *)(param_2 + 0x40) = unaff_retaddr;
      *(undefined8 *)(param_2 + 0x48) = param_7;
      if (param_12 == '\0') {
        *(undefined8 *)(param_2 + 0x38) = param_5;
        *(int *)(param_2 + 0x34) = param_11 + (int)param_9;
        uVar2 = crypto_aead_decrypt(param_2);
        uVar3 = (ulong)uVar2;
        if ((uVar2 == 0xffffff8d) || (uVar2 == 0xfffffff0)) {
          wait_for_completion(auStack_68);
          uVar3 = uStack_48 & 0xffffffff;
          auStack_68[0] = auStack_68[0] & 0xffffffff00000000;
          if ((int)uStack_48 != 0) {
            uVar3 = lkca_aead_internal_cold();
            return uVar3;
          }
        }
        else if (uVar2 != 0) {
          uVar3 = lkca_aead_internal_cold();
          return uVar3;
        }
      }
      else {
        *(undefined8 *)(param_2 + 0x38) = param_5;
        *(int *)(param_2 + 0x34) = (int)param_9;
        uVar2 = crypto_aead_encrypt(param_2);
        uVar3 = (ulong)uVar2;
        if ((uVar2 == 0xffffff8d) || (uVar2 == 0xfffffff0)) {
          wait_for_completion(auStack_68);
          uVar3 = uStack_48 & 0xffffffff;
          auStack_68[0] = auStack_68[0] & 0xffffffff00000000;
          if ((int)uStack_48 != 0) {
            uVar3 = FUN_0052963a();
            return uVar3;
          }
        }
        else if (uVar2 != 0) {
          uVar3 = FUN_0052963a();
          return uVar3;
        }
      }
      *param_10 = param_9;
      goto LAB_001297a2;
    }
    _printk(&DAT_00db0463);
  }
  else {
    _printk(&DAT_00db044b);
  }
  uVar3 = 0xffffffea;
LAB_001297a2:
  if (lStack_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00129640 lkca_aead_internal =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001297c1) */
/* WARNING: Type propagation algorithm not settling */

ulong lkca_aead_internal(long param_1,long param_2,undefined8 param_3,undefined4 param_4,
                        undefined8 param_5,ulong param_6,undefined8 param_7,undefined4 param_8,
                        undefined8 param_9,undefined8 *param_10,int param_11,char param_12)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  long in_GS_OFFSET;
  undefined8 unaff_retaddr;
  ulong local_68 [4];
  ulong local_48;
  long local_40;
  
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_68[0] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  local_48 = 0;
  __init_swait_queue_head(local_68 + 1,"&x->wait",&nvlink_permissions);
  iVar1 = crypto_aead_setkey(param_1,param_3,param_4);
  if (iVar1 == 0) {
    if (*(uint *)(*(long *)(param_1 + 0x28) + -0x10) == param_6) {
      *(undefined **)(param_2 + 0x10) = &crypto_req_done;
      *(ulong **)(param_2 + 0x18) = local_68;
      *(undefined4 *)(param_2 + 0x30) = param_8;
      *(undefined4 *)(param_2 + 0x28) = 0x600;
      *(undefined8 *)(param_2 + 0x40) = unaff_retaddr;
      *(undefined8 *)(param_2 + 0x48) = param_7;
      if (param_12 == '\0') {
        *(undefined8 *)(param_2 + 0x38) = param_5;
        *(int *)(param_2 + 0x34) = param_11 + (int)param_9;
        uVar2 = crypto_aead_decrypt(param_2);
        uVar3 = (ulong)uVar2;
        if ((uVar2 == 0xffffff8d) || (uVar2 == 0xfffffff0)) {
          wait_for_completion(local_68);
          uVar3 = local_48 & 0xffffffff;
          local_68[0] = local_68[0] & 0xffffffff00000000;
          if ((int)local_48 != 0) {
            uVar3 = lkca_aead_internal_cold();
            return uVar3;
          }
        }
        else if (uVar2 != 0) {
          uVar3 = lkca_aead_internal_cold();
          return uVar3;
        }
      }
      else {
        *(undefined8 *)(param_2 + 0x38) = param_5;
        *(int *)(param_2 + 0x34) = (int)param_9;
        uVar2 = crypto_aead_encrypt(param_2);
        uVar3 = (ulong)uVar2;
        if ((uVar2 == 0xffffff8d) || (uVar2 == 0xfffffff0)) {
          wait_for_completion(local_68);
          uVar3 = local_48 & 0xffffffff;
          local_68[0] = local_68[0] & 0xffffffff00000000;
          if ((int)local_48 != 0) {
            uVar3 = FUN_0052963a();
            return uVar3;
          }
        }
        else if (uVar2 != 0) {
          uVar3 = FUN_0052963a();
          return uVar3;
        }
      }
      *param_10 = param_9;
      goto LAB_001297a2;
    }
    _printk(&DAT_00db0463);
  }
  else {
    _printk(&DAT_00db044b);
  }
  uVar3 = 0xffffffea;
LAB_001297a2:
  if (local_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00129810 __pfx_libspdm_aead_prealloced.constprop.0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00129c05) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
__pfx_libspdm_aead_prealloced_constprop_0
          (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          void *param_5,ulong param_6,ulong param_7,void *param_8,ulong param_9,void *param_10,
          undefined8 param_11,char param_12)

{
  undefined8 *__src;
  void *pvVar1;
  code *pcVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  undefined4 uVar9;
  long in_GS_OFFSET;
  void *unaff_retaddr;
  ulong uStack_100;
  uint uStack_f8;
  undefined4 uStack_f4;
  ulong auStack_f0 [3];
  uint uStack_d8;
  undefined4 uStack_d4;
  ulong uStack_c0;
  uint uStack_b8;
  undefined4 uStack_b4;
  ulong uStack_a0;
  uint uStack_98;
  undefined4 uStack_94;
  undefined8 auStack_90 [2];
  ulong uStack_80;
  uint uStack_78;
  undefined4 uStack_74;
  ulong uStack_60;
  uint uStack_58;
  undefined4 uStack_54;
  long lStack_40;
  
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uVar4 = 0;
  do {
    uVar6 = (ulong)uVar4;
    uVar4 = uVar4 + 0x20;
    *(undefined8 *)((long)&uStack_100 + uVar6) = 0;
    *(undefined8 *)((long)&uStack_f8 + uVar6) = 0;
    *(undefined8 *)((long)auStack_f0 + uVar6) = 0;
    *(undefined8 *)((long)auStack_f0 + uVar6 + 8) = 0;
  } while (uVar4 < 0x60);
  uVar4 = 0;
  do {
    uVar6 = (ulong)uVar4;
    uVar4 = uVar4 + 0x20;
    *(undefined8 *)((long)&uStack_a0 + uVar6) = 0;
    *(undefined8 *)((long)&uStack_98 + uVar6) = 0;
    *(undefined8 *)((long)auStack_90 + uVar6) = 0;
    *(undefined8 *)((long)auStack_90 + uVar6 + 8) = 0;
  } while (uVar4 < 0x60);
  sg_init_table(&uStack_100,3);
  sg_init_table(&uStack_a0,3);
  cVar3 = __virt_addr_valid(param_5);
  uVar5 = (undefined4)param_6;
  uVar9 = (undefined4)param_7;
  if (cVar3 == '\0') {
    if (param_6 < 0x200001) {
      pvVar1 = (void *)param_1[2];
      lVar7 = _phys_base;
      if (pvVar1 < (void *)0xffffffff80000000) {
        lVar7 = -0x80000000 - _page_offset_base;
      }
      uVar6 = ((ulong)((long)pvVar1 + lVar7 + 0x80000000) >> 0xc) * 0x40 + _vmemmap_base;
      if ((uVar6 & 3) != 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      uStack_f8 = (uint)pvVar1 & 0xfff;
      uStack_100 = (uint)uStack_100 & 3 | uVar6;
      uStack_a0 = uVar6 | (uint)uStack_a0 & 3;
      uStack_f4 = uVar5;
      uStack_98 = uStack_f8;
      uStack_94 = uVar5;
      memcpy(pvVar1,param_5,param_6);
      cVar3 = __virt_addr_valid(unaff_retaddr);
      if (cVar3 != '\0') goto LAB_00129cef;
LAB_001299d1:
      if (param_7 < 0x200001) {
        pvVar1 = (void *)param_1[3];
        lVar7 = _phys_base;
        if (pvVar1 < (void *)0xffffffff80000000) {
          lVar7 = -0x80000000 - _page_offset_base;
        }
        uVar6 = ((ulong)((long)pvVar1 + lVar7 + 0x80000000) >> 0xc) * 0x40 + _vmemmap_base;
        if ((uVar6 & 3) != 0) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)invalidInstructionException();
          (*pcVar2)();
        }
        auStack_f0[2] = uVar6 | (uint)auStack_f0[2] & 3;
        uStack_d8 = (uint)pvVar1 & 0xfff;
        uStack_d4 = uVar9;
        memcpy(pvVar1,unaff_retaddr,param_7);
        cVar3 = __virt_addr_valid(param_10);
        if (cVar3 != '\0') goto LAB_00129d92;
LAB_00129a58:
        uVar8 = param_1[4];
        lVar7 = _phys_base;
        if (uVar8 < 0xffffffff80000000) {
          lVar7 = -0x80000000 - _page_offset_base;
        }
        uVar6 = (uVar8 + 0x80000000 + lVar7 >> 0xc) * 0x40 + _vmemmap_base;
        if ((_vmemmap_base & 3) != 0) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)invalidInstructionException();
          (*pcVar2)();
        }
        goto LAB_00129a97;
      }
    }
  }
  else {
    lVar7 = _phys_base;
    if (param_5 < (void *)0xffffffff80000000) {
      lVar7 = -0x80000000 - _page_offset_base;
    }
    uVar6 = ((ulong)((long)param_5 + lVar7 + 0x80000000) >> 0xc) * 0x40 + _vmemmap_base;
    if ((uVar6 & 3) != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
    uStack_f8 = (uint)param_5 & 0xfff;
    uStack_100 = (uint)uStack_100 & 3 | uVar6;
    uStack_a0 = uVar6 | (uint)uStack_a0 & 3;
    uStack_f4 = uVar5;
    uStack_98 = uStack_f8;
    uStack_94 = uVar5;
    cVar3 = __virt_addr_valid(unaff_retaddr);
    if (cVar3 == '\0') goto LAB_001299d1;
LAB_00129cef:
    lVar7 = _phys_base;
    if (unaff_retaddr < (void *)0xffffffff80000000) {
      lVar7 = -0x80000000 - _page_offset_base;
    }
    uVar6 = ((ulong)((long)unaff_retaddr + lVar7 + 0x80000000) >> 0xc) * 0x40 + _vmemmap_base;
    if ((uVar6 & 3) != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
    uStack_d8 = (uint)unaff_retaddr & 0xfff;
    auStack_f0[2] = uVar6 | (uint)auStack_f0[2] & 3;
    uStack_d4 = uVar9;
    cVar3 = __virt_addr_valid(param_10);
    if (cVar3 == '\0') {
      if (0x200000 < param_7) goto LAB_00129d64;
      goto LAB_00129a58;
    }
LAB_00129d92:
    lVar7 = _phys_base;
    if (param_10 < (void *)0xffffffff80000000) {
      lVar7 = -0x80000000 - _page_offset_base;
    }
    uVar8 = (ulong)param_10 & 0xffffffff;
    uVar6 = ((ulong)((long)param_10 + lVar7 + 0x80000000) >> 0xc) * 0x40 + _vmemmap_base;
    if ((_vmemmap_base & 3) != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
LAB_00129a97:
    uStack_78 = (uint)uVar8 & 0xfff;
    uStack_80 = (uint)uStack_80 & 3 | uVar6;
    uStack_74 = uVar9;
    if (param_9 < 0x11) {
      __src = param_1 + 5;
      lVar7 = _phys_base;
      if (__src < (undefined8 *)0xffffffff80000000) {
        lVar7 = -0x80000000 - _page_offset_base;
      }
      uVar6 = ((ulong)((long)param_1 + lVar7 + 0x80000028) >> 0xc) * 0x40 + _vmemmap_base;
      if ((_vmemmap_base & 3) != 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      uStack_b8 = (uint)__src & 0xfff;
      uStack_c0 = (uint)uStack_c0 & 3 | uVar6;
      uStack_b4 = (undefined4)param_9;
      uStack_60 = (uint)uStack_60 & 3 | uVar6;
      uStack_54 = (undefined4)param_9;
      uStack_58 = uStack_b8;
      if (param_12 == '\0') {
        memcpy(__src,param_8,param_9);
        uVar5 = lkca_aead_internal(*param_1,param_1[1],param_2,param_3,param_4,0xc,&uStack_100,
                                   &uStack_a0,param_6,param_7,param_11,param_9,0);
      }
      else {
        uVar5 = lkca_aead_internal(*param_1,param_1[1],param_2,param_3,param_4,0xc,&uStack_100,
                                   &uStack_a0,param_6,param_7,param_11,param_9,1);
        memcpy(param_8,__src,param_9);
      }
      cVar3 = __virt_addr_valid(param_10);
      if (cVar3 == '\0') {
        memcpy(param_10,(void *)param_1[4],param_7);
      }
      goto LAB_00129bdc;
    }
  }
LAB_00129d64:
  uVar5 = 0xfffffff4;
LAB_00129bdc:
  if (lStack_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}


// ===== 00129820 libspdm_aead_prealloced.constprop.0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00129c05) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
libspdm_aead_prealloced_constprop_0
          (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          void *param_5,ulong param_6,ulong param_7,void *param_8,ulong param_9,void *param_10,
          undefined8 param_11,char param_12)

{
  undefined8 *__src;
  void *pvVar1;
  code *pcVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  undefined4 uVar9;
  long in_GS_OFFSET;
  void *unaff_retaddr;
  ulong local_100;
  uint local_f8;
  undefined4 local_f4;
  ulong auStack_f0 [3];
  uint local_d8;
  undefined4 local_d4;
  ulong local_c0;
  uint local_b8;
  undefined4 local_b4;
  ulong local_a0;
  uint local_98;
  undefined4 local_94;
  undefined8 auStack_90 [2];
  ulong local_80;
  uint local_78;
  undefined4 local_74;
  ulong local_60;
  uint local_58;
  undefined4 local_54;
  long local_40;
  
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uVar4 = 0;
  do {
    uVar6 = (ulong)uVar4;
    uVar4 = uVar4 + 0x20;
    *(undefined8 *)((long)&local_100 + uVar6) = 0;
    *(undefined8 *)((long)&local_f8 + uVar6) = 0;
    *(undefined8 *)((long)auStack_f0 + uVar6) = 0;
    *(undefined8 *)((long)auStack_f0 + uVar6 + 8) = 0;
  } while (uVar4 < 0x60);
  uVar4 = 0;
  do {
    uVar6 = (ulong)uVar4;
    uVar4 = uVar4 + 0x20;
    *(undefined8 *)((long)&local_a0 + uVar6) = 0;
    *(undefined8 *)((long)&local_98 + uVar6) = 0;
    *(undefined8 *)((long)auStack_90 + uVar6) = 0;
    *(undefined8 *)((long)auStack_90 + uVar6 + 8) = 0;
  } while (uVar4 < 0x60);
  sg_init_table(&local_100,3);
  sg_init_table(&local_a0,3);
  cVar3 = __virt_addr_valid(param_5);
  uVar5 = (undefined4)param_6;
  uVar9 = (undefined4)param_7;
  if (cVar3 == '\0') {
    if (param_6 < 0x200001) {
      pvVar1 = (void *)param_1[2];
      lVar7 = _phys_base;
      if (pvVar1 < (void *)0xffffffff80000000) {
        lVar7 = -0x80000000 - _page_offset_base;
      }
      uVar6 = ((ulong)((long)pvVar1 + lVar7 + 0x80000000) >> 0xc) * 0x40 + _vmemmap_base;
      if ((uVar6 & 3) != 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      local_f8 = (uint)pvVar1 & 0xfff;
      local_100 = (uint)local_100 & 3 | uVar6;
      local_a0 = uVar6 | (uint)local_a0 & 3;
      local_f4 = uVar5;
      local_98 = local_f8;
      local_94 = uVar5;
      memcpy(pvVar1,param_5,param_6);
      cVar3 = __virt_addr_valid(unaff_retaddr);
      if (cVar3 != '\0') goto LAB_00129cef;
LAB_001299d1:
      if (param_7 < 0x200001) {
        pvVar1 = (void *)param_1[3];
        lVar7 = _phys_base;
        if (pvVar1 < (void *)0xffffffff80000000) {
          lVar7 = -0x80000000 - _page_offset_base;
        }
        uVar6 = ((ulong)((long)pvVar1 + lVar7 + 0x80000000) >> 0xc) * 0x40 + _vmemmap_base;
        if ((uVar6 & 3) != 0) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)invalidInstructionException();
          (*pcVar2)();
        }
        auStack_f0[2] = uVar6 | (uint)auStack_f0[2] & 3;
        local_d8 = (uint)pvVar1 & 0xfff;
        local_d4 = uVar9;
        memcpy(pvVar1,unaff_retaddr,param_7);
        cVar3 = __virt_addr_valid(param_10);
        if (cVar3 != '\0') goto LAB_00129d92;
LAB_00129a58:
        uVar8 = param_1[4];
        lVar7 = _phys_base;
        if (uVar8 < 0xffffffff80000000) {
          lVar7 = -0x80000000 - _page_offset_base;
        }
        uVar6 = (uVar8 + 0x80000000 + lVar7 >> 0xc) * 0x40 + _vmemmap_base;
        if ((_vmemmap_base & 3) != 0) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)invalidInstructionException();
          (*pcVar2)();
        }
        goto LAB_00129a97;
      }
    }
  }
  else {
    lVar7 = _phys_base;
    if (param_5 < (void *)0xffffffff80000000) {
      lVar7 = -0x80000000 - _page_offset_base;
    }
    uVar6 = ((ulong)((long)param_5 + lVar7 + 0x80000000) >> 0xc) * 0x40 + _vmemmap_base;
    if ((uVar6 & 3) != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
    local_f8 = (uint)param_5 & 0xfff;
    local_100 = (uint)local_100 & 3 | uVar6;
    local_a0 = uVar6 | (uint)local_a0 & 3;
    local_f4 = uVar5;
    local_98 = local_f8;
    local_94 = uVar5;
    cVar3 = __virt_addr_valid(unaff_retaddr);
    if (cVar3 == '\0') goto LAB_001299d1;
LAB_00129cef:
    lVar7 = _phys_base;
    if (unaff_retaddr < (void *)0xffffffff80000000) {
      lVar7 = -0x80000000 - _page_offset_base;
    }
    uVar6 = ((ulong)((long)unaff_retaddr + lVar7 + 0x80000000) >> 0xc) * 0x40 + _vmemmap_base;
    if ((uVar6 & 3) != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
    local_d8 = (uint)unaff_retaddr & 0xfff;
    auStack_f0[2] = uVar6 | (uint)auStack_f0[2] & 3;
    local_d4 = uVar9;
    cVar3 = __virt_addr_valid(param_10);
    if (cVar3 == '\0') {
      if (0x200000 < param_7) goto LAB_00129d64;
      goto LAB_00129a58;
    }
LAB_00129d92:
    lVar7 = _phys_base;
    if (param_10 < (void *)0xffffffff80000000) {
      lVar7 = -0x80000000 - _page_offset_base;
    }
    uVar8 = (ulong)param_10 & 0xffffffff;
    uVar6 = ((ulong)((long)param_10 + lVar7 + 0x80000000) >> 0xc) * 0x40 + _vmemmap_base;
    if ((_vmemmap_base & 3) != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
LAB_00129a97:
    local_78 = (uint)uVar8 & 0xfff;
    local_80 = (uint)local_80 & 3 | uVar6;
    local_74 = uVar9;
    if (param_9 < 0x11) {
      __src = param_1 + 5;
      lVar7 = _phys_base;
      if (__src < (undefined8 *)0xffffffff80000000) {
        lVar7 = -0x80000000 - _page_offset_base;
      }
      uVar6 = ((ulong)((long)param_1 + lVar7 + 0x80000028) >> 0xc) * 0x40 + _vmemmap_base;
      if ((_vmemmap_base & 3) != 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      local_b8 = (uint)__src & 0xfff;
      local_c0 = (uint)local_c0 & 3 | uVar6;
      local_b4 = (undefined4)param_9;
      local_60 = (uint)local_60 & 3 | uVar6;
      local_54 = (undefined4)param_9;
      local_58 = local_b8;
      if (param_12 == '\0') {
        memcpy(__src,param_8,param_9);
        uVar5 = lkca_aead_internal(*param_1,param_1[1],param_2,param_3,param_4,0xc,&local_100,
                                   &local_a0,param_6,param_7,param_11,param_9,0);
      }
      else {
        uVar5 = lkca_aead_internal(*param_1,param_1[1],param_2,param_3,param_4,0xc,&local_100,
                                   &local_a0,param_6,param_7,param_11,param_9,1);
        memcpy(param_8,__src,param_9);
      }
      cVar3 = __virt_addr_valid(param_10);
      if (cVar3 == '\0') {
        memcpy(param_10,(void *)param_1[4],param_7);
      }
      goto LAB_00129bdc;
    }
  }
LAB_00129d64:
  uVar5 = 0xfffffff4;
LAB_00129bdc:
  if (local_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}


// ===== 00129e10 __pfx_libspdm_aead_free =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_libspdm_aead_free(long *param_1)

{
  crypto_destroy_tfm(*param_1,*param_1 + 8);
  kfree_sensitive(param_1[1]);
  kfree(param_1[2]);
  kfree(param_1[3]);
  kfree(param_1[4]);
  kfree(param_1);
  return;
}


// ===== 00129e20 libspdm_aead_free =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void libspdm_aead_free(long *param_1)

{
  crypto_destroy_tfm(*param_1,*param_1 + 8);
  kfree_sensitive(param_1[1]);
  kfree(param_1[2]);
  kfree(param_1[3]);
  kfree(param_1[4]);
  kfree(param_1);
  return;
}


// ===== 00129e70 __pfx_libspdm_aead =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012a39e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
__pfx_libspdm_aead(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  void *param_5,size_t param_6,size_t param_7,void *param_8,size_t param_9,
                  void *param_10,undefined8 param_11,char param_12,undefined8 param_13)

{
  code *pcVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  ulong uVar5;
  long lVar6;
  void *__dest;
  void *__dest_00;
  ulong uVar7;
  void *__src;
  long lVar8;
  long in_GS_OFFSET;
  void *unaff_retaddr;
  uint uStack_148;
  uint uStack_140;
  void *pvStack_138;
  long lStack_108;
  ulong uStack_100;
  uint uStack_f8;
  undefined4 uStack_f4;
  ulong auStack_f0 [3];
  uint uStack_d8;
  undefined4 uStack_d4;
  ulong uStack_c0;
  uint uStack_b8;
  undefined4 uStack_b4;
  ulong uStack_a0;
  uint uStack_98;
  undefined4 uStack_94;
  ulong auStack_90 [3];
  uint uStack_78;
  undefined4 uStack_74;
  ulong uStack_60;
  uint uStack_58;
  undefined4 uStack_54;
  long lStack_40;
  
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uVar3 = 0;
  do {
    uVar5 = (ulong)uVar3;
    uVar3 = uVar3 + 0x20;
    *(undefined8 *)((long)&uStack_100 + uVar5) = 0;
    *(undefined8 *)((long)&uStack_f8 + uVar5) = 0;
    *(undefined8 *)((long)auStack_f0 + uVar5) = 0;
    *(undefined8 *)((long)auStack_f0 + uVar5 + 8) = 0;
  } while (uVar3 < 0x60);
  uVar3 = 0;
  do {
    uVar5 = (ulong)uVar3;
    uVar3 = uVar3 + 0x20;
    *(undefined8 *)((long)&uStack_a0 + uVar5) = 0;
    *(undefined8 *)((long)&uStack_98 + uVar5) = 0;
    *(undefined8 *)((long)auStack_90 + uVar5) = 0;
    *(undefined8 *)((long)auStack_90 + uVar5 + 8) = 0;
  } while (uVar3 < 0x60);
  uVar5 = crypto_alloc_aead(param_13,3,0);
  if (0xfffffffffffff000 < uVar5) {
    uVar4 = 0xffffffed;
    _printk(&DAT_00df0eb8);
    goto LAB_0012a375;
  }
  lVar6 = __kmalloc_noprof((ulong)*(uint *)(uVar5 + 4) + 0x50);
  if (lVar6 == 0) {
    _printk(&DAT_00df0ee0);
    if (param_10 != (void *)0x0) {
      __src = (void *)0x0;
      uVar4 = 0xfffffff4;
      pvStack_138 = (void *)0x0;
      goto LAB_0012a333;
    }
    uVar4 = 0xfffffff4;
    pvStack_138 = (void *)0x0;
LAB_0012a33b:
    if (param_8 != (void *)0x0) {
LAB_0012a343:
      kfree(pvStack_138);
    }
    if (uVar5 != 0) {
LAB_0012a35b:
      lStack_108 = uVar5 + 8;
      crypto_destroy_tfm(uVar5,lStack_108);
    }
    if (lVar6 == 0) goto LAB_0012a375;
  }
  else {
    *(ulong *)(lVar6 + 0x20) = uVar5 + 8;
    sg_init_table(&uStack_100,3);
    sg_init_table(&uStack_a0,3);
    cVar2 = __virt_addr_valid(param_5);
    uVar4 = (undefined4)param_6;
    if (cVar2 != '\0') {
      lVar8 = _phys_base;
      if (param_5 < (void *)0xffffffff80000000) {
        lVar8 = -0x80000000 - _page_offset_base;
      }
      uVar7 = ((ulong)((long)param_5 + lVar8 + 0x80000000) >> 0xc) * 0x40 + _vmemmap_base;
      if ((uVar7 & 3) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)invalidInstructionException();
        (*pcVar1)();
      }
      __dest = (void *)0x0;
      uStack_f8 = (uint)param_5 & 0xfff;
      uStack_100 = (uint)uStack_100 & 3 | uVar7;
      uStack_a0 = uVar7 | (uint)uStack_a0 & 3;
      uStack_f4 = uVar4;
      uStack_98 = uStack_f8;
      uStack_94 = uVar4;
      cVar2 = __virt_addr_valid(unaff_retaddr);
      if (cVar2 != '\0') goto LAB_0012a43c;
LAB_0012a097:
      __dest_00 = (void *)__kmalloc_noprof(param_7,0xcc0);
      if (__dest_00 != (void *)0x0) {
        lVar8 = _phys_base;
        if (__dest_00 < (void *)0xffffffff80000000) {
          lVar8 = -0x80000000 - _page_offset_base;
        }
        uVar7 = ((ulong)((long)__dest_00 + lVar8 + 0x80000000) >> 0xc) * 0x40 + _vmemmap_base;
        if ((uVar7 & 3) != 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        auStack_f0[2] = uVar7 | (uint)auStack_f0[2] & 3;
        uStack_d8 = (uint)__dest_00 & 0xfff;
        uStack_d4 = (undefined4)param_7;
        memcpy(__dest_00,unaff_retaddr,param_7);
        cVar2 = __virt_addr_valid(param_10);
        goto joined_r0x0012a130;
      }
      if (__dest != (void *)0x0) {
        kfree(__dest);
        if (param_10 != (void *)0x0) {
          __src = (void *)0x0;
          uVar4 = 0xfffffff4;
          pvStack_138 = (void *)0x0;
          goto LAB_0012a333;
        }
LAB_0012a6b7:
        if (param_8 != (void *)0x0) {
          uVar4 = 0xfffffff4;
          pvStack_138 = (void *)0x0;
          goto LAB_0012a343;
        }
        uVar4 = 0xfffffff4;
        goto joined_r0x0012a712;
      }
      if (param_10 == (void *)0x0) goto LAB_0012a6b7;
      __src = (void *)0x0;
      uVar4 = 0xfffffff4;
      pvStack_138 = (void *)0x0;
LAB_0012a333:
      kfree(__src);
      goto LAB_0012a33b;
    }
    __dest = (void *)__kmalloc_noprof(param_6,0xcc0);
    if (__dest == (void *)0x0) {
      if (param_10 != (void *)0x0) {
        __src = (void *)0x0;
        uVar4 = 0xfffffff4;
        pvStack_138 = (void *)0x0;
        goto LAB_0012a333;
      }
      goto LAB_0012a6b7;
    }
    uStack_f8 = (uint)__dest & 0xfff;
    if (__dest < (void *)0xffffffff80000000) {
      lVar8 = -_page_offset_base;
    }
    else {
      lVar8 = _phys_base + 0x80000000;
    }
    uVar7 = ((ulong)((long)__dest + lVar8) >> 0xc) * 0x40 + _vmemmap_base;
    if ((_vmemmap_base & 3) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    uStack_100 = (uint)uStack_100 & 3 | uVar7;
    uStack_a0 = (uint)uStack_a0 & 3 | uVar7;
    uStack_f4 = uVar4;
    uStack_98 = uStack_f8;
    uStack_94 = uVar4;
    memcpy(__dest,param_5,param_6);
    cVar2 = __virt_addr_valid(unaff_retaddr);
    if (cVar2 == '\0') goto LAB_0012a097;
LAB_0012a43c:
    lVar8 = _phys_base;
    if (unaff_retaddr < (void *)0xffffffff80000000) {
      lVar8 = -0x80000000 - _page_offset_base;
    }
    uVar7 = ((ulong)((long)unaff_retaddr + lVar8 + 0x80000000) >> 0xc) * 0x40 + _vmemmap_base;
    if ((uVar7 & 3) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    uStack_d8 = (uint)unaff_retaddr & 0xfff;
    __dest_00 = (void *)0x0;
    auStack_f0[2] = uVar7 | (uint)auStack_f0[2] & 3;
    uStack_d4 = (undefined4)param_7;
    cVar2 = __virt_addr_valid(param_10);
joined_r0x0012a130:
    if (cVar2 == '\0') {
      __src = (void *)__kmalloc_noprof(param_7,0xcc0);
      if (__src != (void *)0x0) {
        lVar8 = _phys_base;
        if (__src < (void *)0xffffffff80000000) {
          lVar8 = -0x80000000 - _page_offset_base;
        }
        uVar7 = ((ulong)((long)__src + lVar8 + 0x80000000) >> 0xc) * 0x40 + _vmemmap_base;
        if ((uVar7 & 3) != 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        uStack_148 = (uint)__src;
        auStack_90[2] = uVar7 | (uint)auStack_90[2] & 3;
        goto LAB_0012a1a8;
      }
      uVar4 = 0xfffffff4;
      pvStack_138 = (void *)0x0;
    }
    else {
      lVar8 = _phys_base;
      if (param_10 < (void *)0xffffffff80000000) {
        lVar8 = -0x80000000 - _page_offset_base;
      }
      uVar7 = ((ulong)((long)param_10 + lVar8 + 0x80000000) >> 0xc) * 0x40 + _vmemmap_base;
      if ((uVar7 & 3) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)invalidInstructionException();
        (*pcVar1)();
      }
      uStack_148 = (uint)param_10;
      __src = (void *)0x0;
      auStack_90[2] = (uint)auStack_90[2] & 3 | uVar7;
LAB_0012a1a8:
      uStack_78 = uStack_148 & 0xfff;
      uStack_74 = (undefined4)param_7;
      cVar2 = __virt_addr_valid(param_8);
      if (cVar2 == '\0') {
        pvStack_138 = (void *)__kmalloc_noprof(param_9,0xcc0);
        if (pvStack_138 == (void *)0x0) {
          uVar4 = 0xfffffff4;
          goto LAB_0012a30e;
        }
        lVar8 = _phys_base;
        if (pvStack_138 < (void *)0xffffffff80000000) {
          lVar8 = -0x80000000 - _page_offset_base;
        }
        uVar7 = ((ulong)((long)pvStack_138 + lVar8 + 0x80000000) >> 0xc) * 0x40 + _vmemmap_base;
        if ((uVar7 & 3) != 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        uStack_c0 = (uint)uStack_c0 & 3 | uVar7;
        uStack_b8 = (uint)pvStack_138 & 0xfff;
        uStack_b4 = (undefined4)param_9;
        uStack_60 = uVar7 | (uint)uStack_60 & 3;
        uStack_54 = (undefined4)param_9;
        uStack_58 = uStack_b8;
        if (param_12 == '\0') {
          memcpy(pvStack_138,param_8,param_9);
          goto LAB_0012a2a5;
        }
        uVar4 = lkca_aead_internal(uVar5,lVar6,param_1,param_2,param_3,param_4,&uStack_100,
                                   &uStack_a0,param_6,param_7,param_11,param_9,1);
        memcpy(param_8,pvStack_138,param_9);
      }
      else {
        lVar8 = _phys_base;
        if (param_8 < (void *)0xffffffff80000000) {
          lVar8 = -0x80000000 - _page_offset_base;
        }
        uVar7 = ((ulong)((long)param_8 + lVar8 + 0x80000000) >> 0xc) * 0x40 + _vmemmap_base;
        if ((uVar7 & 3) != 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        uStack_140 = (uint)param_8;
        pvStack_138 = (void *)0x0;
        uStack_b4 = (undefined4)param_9;
        uStack_b8 = uStack_140 & 0xfff;
        uStack_c0 = (uint)uStack_c0 & 3 | uVar7;
        uStack_60 = uVar7 | (uint)uStack_60 & 3;
        uStack_58 = uStack_b8;
        uStack_54 = uStack_b4;
LAB_0012a2a5:
        uVar4 = lkca_aead_internal(uVar5,lVar6,param_1,param_2,param_3,param_4,&uStack_100,
                                   &uStack_a0,param_6,param_7,param_11,param_9,param_12);
      }
      if (__src != (void *)0x0) {
        memcpy(param_10,__src,param_7);
      }
    }
LAB_0012a30e:
    if (__dest != (void *)0x0) {
      kfree(__dest);
    }
    if (__dest_00 != (void *)0x0) {
      kfree(__dest_00);
    }
    if (param_10 != (void *)0x0) goto LAB_0012a333;
    if (param_8 != (void *)0x0) goto LAB_0012a343;
joined_r0x0012a712:
    if (uVar5 != 0) goto LAB_0012a35b;
  }
  kfree_sensitive(lVar6);
LAB_0012a375:
  if (lStack_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00129e80 libspdm_aead =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012a39e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
libspdm_aead(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
            void *param_5,size_t param_6,size_t param_7,void *param_8,size_t param_9,void *param_10,
            undefined8 param_11,char param_12,undefined8 param_13)

{
  code *pcVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  ulong uVar5;
  long lVar6;
  void *__dest;
  void *__dest_00;
  ulong uVar7;
  void *__src;
  long lVar8;
  long in_GS_OFFSET;
  void *unaff_retaddr;
  uint local_148;
  uint local_140;
  void *local_138;
  long local_108;
  ulong local_100;
  uint local_f8;
  undefined4 local_f4;
  ulong auStack_f0 [3];
  uint local_d8;
  undefined4 local_d4;
  ulong local_c0;
  uint local_b8;
  undefined4 local_b4;
  ulong local_a0;
  uint local_98;
  undefined4 local_94;
  ulong auStack_90 [3];
  uint local_78;
  undefined4 local_74;
  ulong local_60;
  uint local_58;
  undefined4 local_54;
  long local_40;
  
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uVar3 = 0;
  do {
    uVar5 = (ulong)uVar3;
    uVar3 = uVar3 + 0x20;
    *(undefined8 *)((long)&local_100 + uVar5) = 0;
    *(undefined8 *)((long)&local_f8 + uVar5) = 0;
    *(undefined8 *)((long)auStack_f0 + uVar5) = 0;
    *(undefined8 *)((long)auStack_f0 + uVar5 + 8) = 0;
  } while (uVar3 < 0x60);
  uVar3 = 0;
  do {
    uVar5 = (ulong)uVar3;
    uVar3 = uVar3 + 0x20;
    *(undefined8 *)((long)&local_a0 + uVar5) = 0;
    *(undefined8 *)((long)&local_98 + uVar5) = 0;
    *(undefined8 *)((long)auStack_90 + uVar5) = 0;
    *(undefined8 *)((long)auStack_90 + uVar5 + 8) = 0;
  } while (uVar3 < 0x60);
  uVar5 = crypto_alloc_aead(param_13,3,0);
  if (0xfffffffffffff000 < uVar5) {
    uVar4 = 0xffffffed;
    _printk(&DAT_00df0eb8);
    goto LAB_0012a375;
  }
  lVar6 = __kmalloc_noprof((ulong)*(uint *)(uVar5 + 4) + 0x50);
  if (lVar6 == 0) {
    _printk(&DAT_00df0ee0);
    if (param_10 != (void *)0x0) {
      __src = (void *)0x0;
      uVar4 = 0xfffffff4;
      local_138 = (void *)0x0;
      goto LAB_0012a333;
    }
    uVar4 = 0xfffffff4;
    local_138 = (void *)0x0;
LAB_0012a33b:
    if (param_8 != (void *)0x0) {
LAB_0012a343:
      kfree(local_138);
    }
    if (uVar5 != 0) {
LAB_0012a35b:
      local_108 = uVar5 + 8;
      crypto_destroy_tfm(uVar5,local_108);
    }
    if (lVar6 == 0) goto LAB_0012a375;
  }
  else {
    *(ulong *)(lVar6 + 0x20) = uVar5 + 8;
    sg_init_table(&local_100,3);
    sg_init_table(&local_a0,3);
    cVar2 = __virt_addr_valid(param_5);
    uVar4 = (undefined4)param_6;
    if (cVar2 != '\0') {
      lVar8 = _phys_base;
      if (param_5 < (void *)0xffffffff80000000) {
        lVar8 = -0x80000000 - _page_offset_base;
      }
      uVar7 = ((ulong)((long)param_5 + lVar8 + 0x80000000) >> 0xc) * 0x40 + _vmemmap_base;
      if ((uVar7 & 3) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)invalidInstructionException();
        (*pcVar1)();
      }
      __dest = (void *)0x0;
      local_f8 = (uint)param_5 & 0xfff;
      local_100 = (uint)local_100 & 3 | uVar7;
      local_a0 = uVar7 | (uint)local_a0 & 3;
      local_f4 = uVar4;
      local_98 = local_f8;
      local_94 = uVar4;
      cVar2 = __virt_addr_valid(unaff_retaddr);
      if (cVar2 != '\0') goto LAB_0012a43c;
LAB_0012a097:
      __dest_00 = (void *)__kmalloc_noprof(param_7,0xcc0);
      if (__dest_00 != (void *)0x0) {
        lVar8 = _phys_base;
        if (__dest_00 < (void *)0xffffffff80000000) {
          lVar8 = -0x80000000 - _page_offset_base;
        }
        uVar7 = ((ulong)((long)__dest_00 + lVar8 + 0x80000000) >> 0xc) * 0x40 + _vmemmap_base;
        if ((uVar7 & 3) != 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        auStack_f0[2] = uVar7 | (uint)auStack_f0[2] & 3;
        local_d8 = (uint)__dest_00 & 0xfff;
        local_d4 = (undefined4)param_7;
        memcpy(__dest_00,unaff_retaddr,param_7);
        cVar2 = __virt_addr_valid(param_10);
        goto joined_r0x0012a130;
      }
      if (__dest != (void *)0x0) {
        kfree(__dest);
        if (param_10 != (void *)0x0) {
          __src = (void *)0x0;
          uVar4 = 0xfffffff4;
          local_138 = (void *)0x0;
          goto LAB_0012a333;
        }
LAB_0012a6b7:
        if (param_8 != (void *)0x0) {
          uVar4 = 0xfffffff4;
          local_138 = (void *)0x0;
          goto LAB_0012a343;
        }
        uVar4 = 0xfffffff4;
        goto joined_r0x0012a712;
      }
      if (param_10 == (void *)0x0) goto LAB_0012a6b7;
      __src = (void *)0x0;
      uVar4 = 0xfffffff4;
      local_138 = (void *)0x0;
LAB_0012a333:
      kfree(__src);
      goto LAB_0012a33b;
    }
    __dest = (void *)__kmalloc_noprof(param_6,0xcc0);
    if (__dest == (void *)0x0) {
      if (param_10 != (void *)0x0) {
        __src = (void *)0x0;
        uVar4 = 0xfffffff4;
        local_138 = (void *)0x0;
        goto LAB_0012a333;
      }
      goto LAB_0012a6b7;
    }
    local_f8 = (uint)__dest & 0xfff;
    if (__dest < (void *)0xffffffff80000000) {
      lVar8 = -_page_offset_base;
    }
    else {
      lVar8 = _phys_base + 0x80000000;
    }
    uVar7 = ((ulong)((long)__dest + lVar8) >> 0xc) * 0x40 + _vmemmap_base;
    if ((_vmemmap_base & 3) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    local_100 = (uint)local_100 & 3 | uVar7;
    local_a0 = (uint)local_a0 & 3 | uVar7;
    local_f4 = uVar4;
    local_98 = local_f8;
    local_94 = uVar4;
    memcpy(__dest,param_5,param_6);
    cVar2 = __virt_addr_valid(unaff_retaddr);
    if (cVar2 == '\0') goto LAB_0012a097;
LAB_0012a43c:
    lVar8 = _phys_base;
    if (unaff_retaddr < (void *)0xffffffff80000000) {
      lVar8 = -0x80000000 - _page_offset_base;
    }
    uVar7 = ((ulong)((long)unaff_retaddr + lVar8 + 0x80000000) >> 0xc) * 0x40 + _vmemmap_base;
    if ((uVar7 & 3) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    local_d8 = (uint)unaff_retaddr & 0xfff;
    __dest_00 = (void *)0x0;
    auStack_f0[2] = uVar7 | (uint)auStack_f0[2] & 3;
    local_d4 = (undefined4)param_7;
    cVar2 = __virt_addr_valid(param_10);
joined_r0x0012a130:
    if (cVar2 == '\0') {
      __src = (void *)__kmalloc_noprof(param_7,0xcc0);
      if (__src != (void *)0x0) {
        lVar8 = _phys_base;
        if (__src < (void *)0xffffffff80000000) {
          lVar8 = -0x80000000 - _page_offset_base;
        }
        uVar7 = ((ulong)((long)__src + lVar8 + 0x80000000) >> 0xc) * 0x40 + _vmemmap_base;
        if ((uVar7 & 3) != 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        local_148 = (uint)__src;
        auStack_90[2] = uVar7 | (uint)auStack_90[2] & 3;
        goto LAB_0012a1a8;
      }
      uVar4 = 0xfffffff4;
      local_138 = (void *)0x0;
    }
    else {
      lVar8 = _phys_base;
      if (param_10 < (void *)0xffffffff80000000) {
        lVar8 = -0x80000000 - _page_offset_base;
      }
      uVar7 = ((ulong)((long)param_10 + lVar8 + 0x80000000) >> 0xc) * 0x40 + _vmemmap_base;
      if ((uVar7 & 3) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)invalidInstructionException();
        (*pcVar1)();
      }
      local_148 = (uint)param_10;
      __src = (void *)0x0;
      auStack_90[2] = (uint)auStack_90[2] & 3 | uVar7;
LAB_0012a1a8:
      local_78 = local_148 & 0xfff;
      local_74 = (undefined4)param_7;
      cVar2 = __virt_addr_valid(param_8);
      if (cVar2 == '\0') {
        local_138 = (void *)__kmalloc_noprof(param_9,0xcc0);
        if (local_138 == (void *)0x0) {
          uVar4 = 0xfffffff4;
          goto LAB_0012a30e;
        }
        lVar8 = _phys_base;
        if (local_138 < (void *)0xffffffff80000000) {
          lVar8 = -0x80000000 - _page_offset_base;
        }
        uVar7 = ((ulong)((long)local_138 + lVar8 + 0x80000000) >> 0xc) * 0x40 + _vmemmap_base;
        if ((uVar7 & 3) != 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        local_c0 = (uint)local_c0 & 3 | uVar7;
        local_b8 = (uint)local_138 & 0xfff;
        local_b4 = (undefined4)param_9;
        local_60 = uVar7 | (uint)local_60 & 3;
        local_54 = (undefined4)param_9;
        local_58 = local_b8;
        if (param_12 == '\0') {
          memcpy(local_138,param_8,param_9);
          goto LAB_0012a2a5;
        }
        uVar4 = lkca_aead_internal(uVar5,lVar6,param_1,param_2,param_3,param_4,&local_100,&local_a0,
                                   param_6,param_7,param_11,param_9,1);
        memcpy(param_8,local_138,param_9);
      }
      else {
        lVar8 = _phys_base;
        if (param_8 < (void *)0xffffffff80000000) {
          lVar8 = -0x80000000 - _page_offset_base;
        }
        uVar7 = ((ulong)((long)param_8 + lVar8 + 0x80000000) >> 0xc) * 0x40 + _vmemmap_base;
        if ((uVar7 & 3) != 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        local_140 = (uint)param_8;
        local_138 = (void *)0x0;
        local_b4 = (undefined4)param_9;
        local_b8 = local_140 & 0xfff;
        local_c0 = (uint)local_c0 & 3 | uVar7;
        local_60 = uVar7 | (uint)local_60 & 3;
        local_58 = local_b8;
        local_54 = local_b4;
LAB_0012a2a5:
        uVar4 = lkca_aead_internal(uVar5,lVar6,param_1,param_2,param_3,param_4,&local_100,&local_a0,
                                   param_6,param_7,param_11,param_9,param_12);
      }
      if (__src != (void *)0x0) {
        memcpy(param_10,__src,param_7);
      }
    }
LAB_0012a30e:
    if (__dest != (void *)0x0) {
      kfree(__dest);
    }
    if (__dest_00 != (void *)0x0) {
      kfree(__dest_00);
    }
    if (param_10 != (void *)0x0) goto LAB_0012a333;
    if (param_8 != (void *)0x0) goto LAB_0012a343;
joined_r0x0012a712:
    if (uVar5 != 0) goto LAB_0012a35b;
  }
  kfree_sensitive(lVar6);
LAB_0012a375:
  if (local_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0012a740 __pfx_libspdm_aead_gcm_prealloc =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012a879) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_libspdm_aead_gcm_prealloc(undefined8 *param_1)

{
  ulong *puVar1;
  ulong uVar2;
  ulong uVar3;
  
  puVar1 = (ulong *)__kmalloc_cache_noprof(_capable,0xcc0,0x38);
  if (puVar1 != (ulong *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    uVar2 = crypto_alloc_aead("gcm(aes)",3,0);
    *puVar1 = uVar2;
    if (uVar2 < 0xfffffffffffff001) {
      uVar3 = __kmalloc_noprof((ulong)*(uint *)(uVar2 + 4) + 0x50,0xcc0);
      if (uVar3 == 0) {
        puVar1[1] = 0;
        _printk(&DAT_00df0ee0);
        crypto_destroy_tfm(*puVar1,*puVar1 + 8);
        kfree(puVar1);
      }
      else {
        *(ulong *)(uVar3 + 0x20) = uVar2 + 8;
        puVar1[1] = uVar3;
        uVar2 = __kmalloc_large_noprof(0x200000,0xcc0);
        puVar1[2] = uVar2;
        if (uVar2 != 0) {
          uVar2 = __kmalloc_large_noprof(0x200000,0xcc0);
          puVar1[3] = uVar2;
          if (uVar2 == 0) {
            kfree(puVar1[2]);
            kfree_sensitive(puVar1[1]);
            crypto_destroy_tfm(*puVar1,*puVar1 + 8);
            kfree(puVar1);
            return 0;
          }
          uVar2 = __kmalloc_large_noprof(0x200000,0xcc0);
          puVar1[4] = uVar2;
          if (uVar2 != 0) {
            *param_1 = puVar1;
            return 1;
          }
          kfree(puVar1[2]);
          kfree(puVar1[3]);
          kfree_sensitive(puVar1[1]);
          crypto_destroy_tfm(*puVar1,*puVar1 + 8);
          kfree(puVar1);
          return 0;
        }
        kfree_sensitive(puVar1[1]);
        crypto_destroy_tfm(*puVar1,*puVar1 + 8);
        kfree(puVar1);
      }
    }
    else {
      _printk(&DAT_00df0eb8);
      kfree(puVar1);
    }
  }
  return 0;
}


// ===== 0012a750 libspdm_aead_gcm_prealloc =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012a879) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 libspdm_aead_gcm_prealloc(undefined8 *param_1)

{
  ulong *puVar1;
  ulong uVar2;
  ulong uVar3;
  
  puVar1 = (ulong *)__kmalloc_cache_noprof(_capable,0xcc0,0x38);
  if (puVar1 != (ulong *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    uVar2 = crypto_alloc_aead("gcm(aes)",3,0);
    *puVar1 = uVar2;
    if (uVar2 < 0xfffffffffffff001) {
      uVar3 = __kmalloc_noprof((ulong)*(uint *)(uVar2 + 4) + 0x50,0xcc0);
      if (uVar3 == 0) {
        puVar1[1] = 0;
        _printk(&DAT_00df0ee0);
        crypto_destroy_tfm(*puVar1,*puVar1 + 8);
        kfree(puVar1);
      }
      else {
        *(ulong *)(uVar3 + 0x20) = uVar2 + 8;
        puVar1[1] = uVar3;
        uVar2 = __kmalloc_large_noprof(0x200000,0xcc0);
        puVar1[2] = uVar2;
        if (uVar2 != 0) {
          uVar2 = __kmalloc_large_noprof(0x200000,0xcc0);
          puVar1[3] = uVar2;
          if (uVar2 == 0) {
            kfree(puVar1[2]);
            kfree_sensitive(puVar1[1]);
            crypto_destroy_tfm(*puVar1,*puVar1 + 8);
            kfree(puVar1);
            return 0;
          }
          uVar2 = __kmalloc_large_noprof(0x200000,0xcc0);
          puVar1[4] = uVar2;
          if (uVar2 != 0) {
            *param_1 = puVar1;
            return 1;
          }
          kfree(puVar1[2]);
          kfree(puVar1[3]);
          kfree_sensitive(puVar1[1]);
          crypto_destroy_tfm(*puVar1,*puVar1 + 8);
          kfree(puVar1);
          return 0;
        }
        kfree_sensitive(puVar1[1]);
        crypto_destroy_tfm(*puVar1,*puVar1 + 8);
        kfree(puVar1);
      }
    }
    else {
      _printk(&DAT_00df0eb8);
      kfree(puVar1);
    }
  }
  return 0;
}


// ===== 0012a920 __pfx_libspdm_aead_aes_gcm_encrypt_prealloc =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012a95b) */
/* WARNING: Removing unreachable block (ram,0x0012a9e2) */

bool __pfx_libspdm_aead_aes_gcm_encrypt_prealloc
               (undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4,long param_5,
               undefined8 param_6,undefined8 param_7,ulong param_8,undefined8 param_9,long param_10,
               undefined8 param_11,ulong *param_12)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  ulong unaff_retaddr;
  
  bVar1 = 0x7fffffff < (param_8 | unaff_retaddr);
  bVar2 = bVar1 || param_5 != 0xc;
  if (bVar1 || param_5 != 0xc) {
    bVar2 = false;
  }
  else if ((((param_3 - 0x10U < 0x11) && ((0x10101UL >> (param_3 - 0x10U & 0x3f) & 1) != 0)) &&
           (param_10 - 0xcU < 5)) &&
          ((param_12 == (ulong *)0x0 || ((param_8 <= *param_12 && (*param_12 < 0x80000000)))))) {
    iVar3 = libspdm_aead_prealloced_constprop_0();
    *param_12 = param_8;
    return iVar3 == 0;
  }
  return bVar2;
}


// ===== 0012a930 libspdm_aead_aes_gcm_encrypt_prealloc =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012a95b) */
/* WARNING: Removing unreachable block (ram,0x0012a9e2) */

bool libspdm_aead_aes_gcm_encrypt_prealloc
               (undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4,long param_5,
               undefined8 param_6,undefined8 param_7,ulong param_8,undefined8 param_9,long param_10,
               undefined8 param_11,ulong *param_12)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  ulong unaff_retaddr;
  
  bVar1 = 0x7fffffff < (param_8 | unaff_retaddr);
  bVar2 = bVar1 || param_5 != 0xc;
  if (bVar1 || param_5 != 0xc) {
    bVar2 = false;
  }
  else if ((((param_3 - 0x10U < 0x11) && ((0x10101UL >> (param_3 - 0x10U & 0x3f) & 1) != 0)) &&
           (param_10 - 0xcU < 5)) &&
          ((param_12 == (ulong *)0x0 || ((param_8 <= *param_12 && (*param_12 < 0x80000000)))))) {
    iVar3 = libspdm_aead_prealloced_constprop_0();
    *param_12 = param_8;
    return iVar3 == 0;
  }
  return bVar2;
}


// ===== 0012a9f0 __pfx_libspdm_aead_aes_gcm_decrypt_prealloc =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012aa2b) */
/* WARNING: Removing unreachable block (ram,0x0012aab2) */

bool __pfx_libspdm_aead_aes_gcm_decrypt_prealloc
               (undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4,long param_5,
               undefined8 param_6,undefined8 param_7,ulong param_8,undefined8 param_9,long param_10,
               undefined8 param_11,ulong *param_12)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  ulong unaff_retaddr;
  
  bVar1 = 0x7fffffff < (param_8 | unaff_retaddr);
  bVar2 = bVar1 || param_5 != 0xc;
  if (bVar1 || param_5 != 0xc) {
    bVar2 = false;
  }
  else if ((((param_3 - 0x10U < 0x11) && ((0x10101UL >> (param_3 - 0x10U & 0x3f) & 1) != 0)) &&
           (param_10 - 0xcU < 5)) &&
          ((param_12 == (ulong *)0x0 || ((param_8 <= *param_12 && (*param_12 < 0x80000000)))))) {
    iVar3 = libspdm_aead_prealloced_constprop_0();
    *param_12 = param_8;
    return iVar3 == 0;
  }
  return bVar2;
}


// ===== 0012aa00 libspdm_aead_aes_gcm_decrypt_prealloc =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012aa2b) */
/* WARNING: Removing unreachable block (ram,0x0012aab2) */

bool libspdm_aead_aes_gcm_decrypt_prealloc
               (undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4,long param_5,
               undefined8 param_6,undefined8 param_7,ulong param_8,undefined8 param_9,long param_10,
               undefined8 param_11,ulong *param_12)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  ulong unaff_retaddr;
  
  bVar1 = 0x7fffffff < (param_8 | unaff_retaddr);
  bVar2 = bVar1 || param_5 != 0xc;
  if (bVar1 || param_5 != 0xc) {
    bVar2 = false;
  }
  else if ((((param_3 - 0x10U < 0x11) && ((0x10101UL >> (param_3 - 0x10U & 0x3f) & 1) != 0)) &&
           (param_10 - 0xcU < 5)) &&
          ((param_12 == (ulong *)0x0 || ((param_8 <= *param_12 && (*param_12 < 0x80000000)))))) {
    iVar3 = libspdm_aead_prealloced_constprop_0();
    *param_12 = param_8;
    return iVar3 == 0;
  }
  return bVar2;
}


// ===== 0012aac0 __pfx_lkca_ecdsa_verify_crypto_sig.isra.0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012acfc) */

ulong __pfx_lkca_ecdsa_verify_crypto_sig_isra_0
                (long param_1,undefined8 param_2,undefined4 param_3,long param_4,long param_5)

{
  uint uVar1;
  ulong uVar3;
  ulong uVar4;
  int iVar5;
  long in_GS_OFFSET;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 auStack_c8 [9];
  undefined1 auStack_80 [72];
  long lStack_38;
  ulong uVar2;
  
  lStack_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_e8 = 0;
  uStack_e0 = 0;
  uStack_d8 = 0;
  uStack_d0 = 0;
  __init_swait_queue_head(&uStack_e8,"&x->wait",&nvlink_permissions);
  uVar3 = 0;
  do {
    uVar1 = (int)uVar3 + 0x20;
    uVar2 = (ulong)uVar1;
    *(undefined8 *)((long)auStack_c8 + uVar3) = 0;
    *(undefined8 *)((long)auStack_c8 + uVar3 + 8) = 0;
    *(undefined8 *)((long)auStack_c8 + uVar3 + 0x10) = 0;
    *(undefined8 *)((long)auStack_c8 + uVar3 + 0x18) = 0;
    uVar3 = uVar2;
  } while (uVar1 < 0x80);
  *(undefined8 *)((long)auStack_c8 + uVar2) = 0;
  *(undefined8 *)((long)auStack_c8 + uVar2 + 8) = 0;
  if (*(int *)(param_1 + 0xf8) == param_5) {
    uVar3 = (ulong)*(byte *)(param_1 + 0xe8);
    if (*(byte *)(param_1 + 0xe8) != 0) {
      uVar3 = crypto_alloc_sig(*(undefined8 *)(param_1 + 0xf0),7,0);
      if (0xfffffffffffff000 < uVar3) {
        _printk(&DAT_00df0f08);
        uVar3 = FUN_0012acd9();
        return uVar3;
      }
      *(undefined1 *)(param_1 + 0x57) = 4;
      iVar5 = (**(code **)(*(long *)(uVar3 + 0x20) + -0x38))
                        (uVar3,param_1 + 0x57,*(int *)(param_1 + 0xf8) + 1);
      if (iVar5 == 0) {
        uVar2 = 0;
        do {
          uVar1 = (int)uVar2 + 0x20;
          uVar4 = (ulong)uVar1;
          *(undefined8 *)((long)auStack_c8 + uVar2) = 0;
          *(undefined8 *)((long)auStack_c8 + uVar2 + 8) = 0;
          *(undefined8 *)((long)auStack_c8 + uVar2 + 0x10) = 0;
          *(undefined8 *)((long)auStack_c8 + uVar2 + 0x18) = 0;
          uVar2 = uVar4;
        } while (uVar1 < 0x80);
        *(undefined8 *)((long)auStack_c8 + uVar4) = 0;
        *(undefined8 *)((long)auStack_c8 + uVar4 + 8) = 0;
        ecc_digits_from_bytes(param_4,*(int *)(param_1 + 0xf8) / 2,auStack_c8,9);
        iVar5 = *(int *)(param_1 + 0xf8) / 2;
        ecc_digits_from_bytes(param_4 + iVar5,iVar5,auStack_80,9);
        iVar5 = (**(code **)(*(long *)(uVar3 + 0x20) + -0x40))
                          (uVar3,auStack_c8,0x90,param_2,param_3);
        if (iVar5 != 0) {
          _printk(&DAT_00df0f70,-iVar5);
        }
      }
      else {
        _printk(&DAT_00df0f38,-iVar5);
      }
      crypto_destroy_tfm(uVar3,uVar3);
      uVar3 = (ulong)CONCAT31((int3)((uint)iVar5 >> 8),iVar5 == 0);
    }
  }
  else {
    uVar3 = 0;
  }
  if (lStack_38 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0012aad0 lkca_ecdsa_verify_crypto_sig.isra.0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012acfc) */

ulong lkca_ecdsa_verify_crypto_sig_isra_0
                (long param_1,undefined8 param_2,undefined4 param_3,long param_4,long param_5)

{
  uint uVar1;
  ulong uVar3;
  ulong uVar4;
  int iVar5;
  long in_GS_OFFSET;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8 [9];
  undefined1 local_80 [72];
  long local_38;
  ulong uVar2;
  
  local_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_e8 = 0;
  local_e0 = 0;
  local_d8 = 0;
  local_d0 = 0;
  __init_swait_queue_head(&local_e8,"&x->wait",&nvlink_permissions);
  uVar3 = 0;
  do {
    uVar1 = (int)uVar3 + 0x20;
    uVar2 = (ulong)uVar1;
    *(undefined8 *)((long)local_c8 + uVar3) = 0;
    *(undefined8 *)((long)local_c8 + uVar3 + 8) = 0;
    *(undefined8 *)((long)local_c8 + uVar3 + 0x10) = 0;
    *(undefined8 *)((long)local_c8 + uVar3 + 0x18) = 0;
    uVar3 = uVar2;
  } while (uVar1 < 0x80);
  *(undefined8 *)((long)local_c8 + uVar2) = 0;
  *(undefined8 *)((long)local_c8 + uVar2 + 8) = 0;
  if (*(int *)(param_1 + 0xf8) == param_5) {
    uVar3 = (ulong)*(byte *)(param_1 + 0xe8);
    if (*(byte *)(param_1 + 0xe8) != 0) {
      uVar3 = crypto_alloc_sig(*(undefined8 *)(param_1 + 0xf0),7,0);
      if (0xfffffffffffff000 < uVar3) {
        _printk(&DAT_00df0f08);
        uVar3 = FUN_0012acd9();
        return uVar3;
      }
      *(undefined1 *)(param_1 + 0x57) = 4;
      iVar5 = (**(code **)(*(long *)(uVar3 + 0x20) + -0x38))
                        (uVar3,param_1 + 0x57,*(int *)(param_1 + 0xf8) + 1);
      if (iVar5 == 0) {
        uVar2 = 0;
        do {
          uVar1 = (int)uVar2 + 0x20;
          uVar4 = (ulong)uVar1;
          *(undefined8 *)((long)local_c8 + uVar2) = 0;
          *(undefined8 *)((long)local_c8 + uVar2 + 8) = 0;
          *(undefined8 *)((long)local_c8 + uVar2 + 0x10) = 0;
          *(undefined8 *)((long)local_c8 + uVar2 + 0x18) = 0;
          uVar2 = uVar4;
        } while (uVar1 < 0x80);
        *(undefined8 *)((long)local_c8 + uVar4) = 0;
        *(undefined8 *)((long)local_c8 + uVar4 + 8) = 0;
        ecc_digits_from_bytes(param_4,*(int *)(param_1 + 0xf8) / 2,local_c8,9);
        iVar5 = *(int *)(param_1 + 0xf8) / 2;
        ecc_digits_from_bytes(param_4 + iVar5,iVar5,local_80,9);
        iVar5 = (**(code **)(*(long *)(uVar3 + 0x20) + -0x40))(uVar3,local_c8,0x90,param_2,param_3);
        if (iVar5 != 0) {
          _printk(&DAT_00df0f70,-iVar5);
        }
      }
      else {
        _printk(&DAT_00df0f38,-iVar5);
      }
      crypto_destroy_tfm(uVar3,uVar3);
      uVar3 = (ulong)CONCAT31((int3)((uint)iVar5 >> 8),iVar5 == 0);
    }
  }
  else {
    uVar3 = 0;
  }
  if (local_38 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0012acd9 FUN_0012acd9 =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012acfc) */

undefined8 FUN_0012acd9(void)

{
  long in_GS_OFFSET;
  long in_stack_000000c8;
  
  if (in_stack_000000c8 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0012ad10 __pfx_libspdm_ec_new_by_nid =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ad8a) */
/* WARNING: Removing unreachable block (ram,0x0012ada2) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __pfx_libspdm_ec_new_by_nid(long param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  if (param_1 - 0x204U < 2) {
    puVar1 = (undefined4 *)__kmalloc_cache_noprof(_crypto_aead_setkey,0xcc0,0x100);
    if (puVar1 != (undefined4 *)0x0) {
      if (param_1 == 0x204) {
        uVar4 = 2;
        uVar2 = 0x40;
        pcVar3 = "ecdsa-nist-p256";
      }
      else {
        uVar4 = 3;
        uVar2 = 0x60;
        pcVar3 = "ecdsa-nist-p384";
      }
      *(char **)(puVar1 + 0x3c) = pcVar3;
      *puVar1 = uVar4;
      puVar1[0x3e] = uVar2;
      *(undefined2 *)(puVar1 + 0x3a) = 0;
    }
    return puVar1;
  }
  return (undefined4 *)0x0;
}


// ===== 0012ad20 libspdm_ec_new_by_nid =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ad8a) */
/* WARNING: Removing unreachable block (ram,0x0012ada2) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * libspdm_ec_new_by_nid(long param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  if (param_1 - 0x204U < 2) {
    puVar1 = (undefined4 *)__kmalloc_cache_noprof(_crypto_aead_setkey,0xcc0,0x100);
    if (puVar1 != (undefined4 *)0x0) {
      if (param_1 == 0x204) {
        uVar4 = 2;
        uVar2 = 0x40;
        pcVar3 = "ecdsa-nist-p256";
      }
      else {
        uVar4 = 3;
        uVar2 = 0x60;
        pcVar3 = "ecdsa-nist-p384";
      }
      *(char **)(puVar1 + 0x3c) = pcVar3;
      *puVar1 = uVar4;
      puVar1[0x3e] = uVar2;
      *(undefined2 *)(puVar1 + 0x3a) = 0;
    }
    return puVar1;
  }
  return (undefined4 *)0x0;
}


// ===== 0012adb0 __pfx_libspdm_ec_free =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_libspdm_ec_free(void)

{
  kfree();
  return;
}


// ===== 0012adc0 libspdm_ec_free =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void libspdm_ec_free(void)

{
  kfree();
  return;
}


// ===== 0012add0 __pfx_lkca_ecdsa_set_priv_key =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ae6b) */
/* WARNING: Removing unreachable block (ram,0x0012ae01) */
/* WARNING: Removing unreachable block (ram,0x0012ae7a) */

undefined8 __pfx_lkca_ecdsa_set_priv_key(undefined4 *param_1,void *param_2,ulong param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[0x3e];
  if ((long)(iVar1 / 2) != param_3) {
    return 0;
  }
  iVar2 = iVar1 + 0xf;
  if (-1 < iVar1) {
    iVar2 = iVar1;
  }
  if (0x48 < param_3) {
    __SCT__WARN_trap(&DAT_00101130,param_3,"field \"ctx->priv_key\" at nvidia/libspdm_ecc.c:114",
                     0x48);
  }
  memcpy(param_1 + 2,param_2,param_3);
  iVar1 = ecc_make_pub_key(*param_1,iVar2 >> 4,param_1 + 2,param_1 + 0x16);
  if (iVar1 == 0) {
    *(undefined2 *)(param_1 + 0x3a) = 0x101;
    return 1;
  }
  return 0;
}


// ===== 0012ade0 lkca_ecdsa_set_priv_key =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ae6b) */
/* WARNING: Removing unreachable block (ram,0x0012ae01) */
/* WARNING: Removing unreachable block (ram,0x0012ae7a) */

undefined8 lkca_ecdsa_set_priv_key(undefined4 *param_1,void *param_2,ulong param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[0x3e];
  if ((long)(iVar1 / 2) != param_3) {
    return 0;
  }
  iVar2 = iVar1 + 0xf;
  if (-1 < iVar1) {
    iVar2 = iVar1;
  }
  if (0x48 < param_3) {
    __SCT__WARN_trap(&DAT_00101130,param_3,"field \"ctx->priv_key\" at nvidia/libspdm_ecc.c:114",
                     0x48);
  }
  memcpy(param_1 + 2,param_2,param_3);
  iVar1 = ecc_make_pub_key(*param_1,iVar2 >> 4,param_1 + 2,param_1 + 0x16);
  if (iVar1 == 0) {
    *(undefined2 *)(param_1 + 0x3a) = 0x101;
    return 1;
  }
  return 0;
}


// ===== 0012aeb0 __pfx_lkca_ec_set_pub_key =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012af1d) */

undefined8 __pfx_lkca_ec_set_pub_key(undefined4 *param_1,void *param_2,ulong param_3)

{
  undefined4 *__dest;
  ulong uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  long in_GS_OFFSET;
  undefined4 *puStack_38;
  undefined4 *puStack_30;
  ulong uStack_28;
  long lStack_20;
  
  lStack_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  iVar4 = param_1[0x3e];
  puStack_38 = (undefined4 *)0x0;
  puStack_30 = (undefined4 *)0x0;
  uStack_28 = 0;
  if ((long)iVar4 == param_3) {
    __dest = param_1 + 0x16;
    iVar2 = iVar4 + 0xf;
    if (-1 < iVar4) {
      iVar2 = iVar4;
    }
    uVar6 = iVar2 >> 4;
    uStack_28 = (ulong)(byte)uVar6;
    puStack_30 = __dest + (ulong)uVar6 * 2;
    if (uVar6 != 0) {
      uVar3 = 0;
      do {
        lVar8 = (long)(int)uVar3;
        uVar7 = (uVar6 - 1) - uVar3;
        uVar3 = uVar3 + 1;
        uVar1 = *(ulong *)((long)param_2 + (ulong)uVar7 * 8);
        *(ulong *)(__dest + lVar8 * 2) =
             uVar1 >> 0x38 | (uVar1 & 0xff000000000000) >> 0x28 | (uVar1 & 0xff0000000000) >> 0x18 |
             (uVar1 & 0xff00000000) >> 8 | (uVar1 & 0xff000000) << 8 | (uVar1 & 0xff0000) << 0x18 |
             (uVar1 & 0xff00) << 0x28 | uVar1 << 0x38;
      } while (uVar6 != uVar3);
      uVar3 = 0;
      do {
        lVar8 = (long)(int)uVar3;
        uVar7 = (uVar6 - 1) - uVar3;
        uVar3 = uVar3 + 1;
        uVar1 = *(ulong *)((long)param_2 + (ulong)uVar6 * 8 + (ulong)uVar7 * 8);
        *(ulong *)(puStack_30 + lVar8 * 2) =
             uVar1 >> 0x38 | (uVar1 & 0xff000000000000) >> 0x28 | (uVar1 & 0xff0000000000) >> 0x18 |
             (uVar1 & 0xff00000000) >> 8 | (uVar1 & 0xff000000) << 8 | (uVar1 & 0xff0000) << 0x18 |
             (uVar1 & 0xff00) << 0x28 | uVar1 << 0x38;
      } while (uVar6 != uVar3);
    }
    puStack_38 = __dest;
    uVar5 = ecc_get_curve(*param_1);
    iVar4 = ecc_is_pubkey_valid_full(uVar5,&puStack_38);
    if (iVar4 == 0) {
      if (0x90 < param_3) {
        __SCT__WARN_trap(&DAT_00101140,param_3,"field \"ctx->pub_key\" at nvidia/libspdm_ecc.c:151",
                         0x90);
      }
      memcpy(__dest,param_2,param_3);
      uVar5 = 1;
      *(undefined1 *)(param_1 + 0x3a) = 1;
      goto LAB_0012af06;
    }
  }
  uVar5 = 0;
LAB_0012af06:
  if (lStack_20 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}


// ===== 0012aec0 lkca_ec_set_pub_key =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012af1d) */

undefined8 lkca_ec_set_pub_key(undefined4 *param_1,void *param_2,ulong param_3)

{
  undefined4 *__dest;
  ulong uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  long in_GS_OFFSET;
  undefined4 *local_38;
  undefined4 *local_30;
  ulong local_28;
  long local_20;
  
  local_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  iVar4 = param_1[0x3e];
  local_38 = (undefined4 *)0x0;
  local_30 = (undefined4 *)0x0;
  local_28 = 0;
  if ((long)iVar4 == param_3) {
    __dest = param_1 + 0x16;
    iVar2 = iVar4 + 0xf;
    if (-1 < iVar4) {
      iVar2 = iVar4;
    }
    uVar6 = iVar2 >> 4;
    local_28 = (ulong)(byte)uVar6;
    local_30 = __dest + (ulong)uVar6 * 2;
    if (uVar6 != 0) {
      uVar3 = 0;
      do {
        lVar8 = (long)(int)uVar3;
        uVar7 = (uVar6 - 1) - uVar3;
        uVar3 = uVar3 + 1;
        uVar1 = *(ulong *)((long)param_2 + (ulong)uVar7 * 8);
        *(ulong *)(__dest + lVar8 * 2) =
             uVar1 >> 0x38 | (uVar1 & 0xff000000000000) >> 0x28 | (uVar1 & 0xff0000000000) >> 0x18 |
             (uVar1 & 0xff00000000) >> 8 | (uVar1 & 0xff000000) << 8 | (uVar1 & 0xff0000) << 0x18 |
             (uVar1 & 0xff00) << 0x28 | uVar1 << 0x38;
      } while (uVar6 != uVar3);
      uVar3 = 0;
      do {
        lVar8 = (long)(int)uVar3;
        uVar7 = (uVar6 - 1) - uVar3;
        uVar3 = uVar3 + 1;
        uVar1 = *(ulong *)((long)param_2 + (ulong)uVar6 * 8 + (ulong)uVar7 * 8);
        *(ulong *)(local_30 + lVar8 * 2) =
             uVar1 >> 0x38 | (uVar1 & 0xff000000000000) >> 0x28 | (uVar1 & 0xff0000000000) >> 0x18 |
             (uVar1 & 0xff00000000) >> 8 | (uVar1 & 0xff000000) << 8 | (uVar1 & 0xff0000) << 0x18 |
             (uVar1 & 0xff00) << 0x28 | uVar1 << 0x38;
      } while (uVar6 != uVar3);
    }
    local_38 = __dest;
    uVar5 = ecc_get_curve(*param_1);
    iVar4 = ecc_is_pubkey_valid_full(uVar5,&local_38);
    if (iVar4 == 0) {
      if (0x90 < param_3) {
        __SCT__WARN_trap(&DAT_00101140,param_3,"field \"ctx->pub_key\" at nvidia/libspdm_ecc.c:151",
                         0x90);
      }
      memcpy(__dest,param_2,param_3);
      uVar5 = 1;
      *(undefined1 *)(param_1 + 0x3a) = 1;
      goto LAB_0012af06;
    }
  }
  uVar5 = 0;
LAB_0012af06:
  if (local_20 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}


// ===== 0012b0a0 __pfx_lkca_ec_get_pub_key =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012b0e3) */
/* WARNING: Removing unreachable block (ram,0x0012b0ed) */

undefined8 __pfx_lkca_ec_get_pub_key(long param_1,void *param_2,ulong *param_3)

{
  ulong uVar1;
  
  uVar1 = (ulong)*(int *)(param_1 + 0xf8);
  if (uVar1 <= *param_3) {
    *param_3 = uVar1;
    memcpy(param_2,(void *)(param_1 + 0x58),(long)*(int *)(param_1 + 0xf8));
    return 1;
  }
  *param_3 = uVar1;
  return 0;
}


// ===== 0012b0b0 lkca_ec_get_pub_key =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012b0e3) */
/* WARNING: Removing unreachable block (ram,0x0012b0ed) */

undefined8 lkca_ec_get_pub_key(long param_1,void *param_2,ulong *param_3)

{
  ulong uVar1;
  
  uVar1 = (ulong)*(int *)(param_1 + 0xf8);
  if (uVar1 <= *param_3) {
    *param_3 = uVar1;
    memcpy(param_2,(void *)(param_1 + 0x58),(long)*(int *)(param_1 + 0xf8));
    return 1;
  }
  *param_3 = uVar1;
  return 0;
}


// ===== 0012b100 __pfx_lkca_ec_generate_key =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012b176) */

undefined8 __pfx_lkca_ec_generate_key(undefined4 *param_1,void *param_2,long *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[0x3e];
  iVar2 = iVar1 + 0xf;
  if (-1 < iVar1) {
    iVar2 = iVar1;
  }
  iVar1 = ecc_gen_privkey(*param_1,iVar2 >> 4,param_1 + 2);
  if (iVar1 == 0) {
    iVar1 = ecc_make_pub_key(*param_1,iVar2 >> 4,param_1 + 2);
    if (iVar1 == 0) {
      memcpy(param_2,param_1 + 0x16,(long)(int)param_1[0x3e]);
      *param_3 = (long)(int)param_1[0x3e];
      *(undefined2 *)(param_1 + 0x3a) = 0x101;
      return 1;
    }
  }
  return 0;
}


// ===== 0012b110 lkca_ec_generate_key =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012b176) */

undefined8 lkca_ec_generate_key(undefined4 *param_1,void *param_2,long *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[0x3e];
  iVar2 = iVar1 + 0xf;
  if (-1 < iVar1) {
    iVar2 = iVar1;
  }
  iVar1 = ecc_gen_privkey(*param_1,iVar2 >> 4,param_1 + 2);
  if (iVar1 == 0) {
    iVar1 = ecc_make_pub_key(*param_1,iVar2 >> 4,param_1 + 2);
    if (iVar1 == 0) {
      memcpy(param_2,param_1 + 0x16,(long)(int)param_1[0x3e]);
      *param_3 = (long)(int)param_1[0x3e];
      *(undefined2 *)(param_1 + 0x3a) = 0x101;
      return 1;
    }
  }
  return 0;
}


// ===== 0012b1d0 __pfx_lkca_ec_compute_key =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012b1fe) */
/* WARNING: Removing unreachable block (ram,0x0012b282) */

char __pfx_lkca_ec_compute_key
               (undefined4 *param_1,undefined8 param_2,long param_3,undefined8 param_4,
               ulong *param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  
  iVar3 = param_1[0x3e];
  if (((iVar3 == param_3) && (cVar1 = *(char *)((long)param_1 + 0xe9), cVar1 != '\0')) &&
     ((ulong)(long)(iVar3 / 2) <= *param_5)) {
    iVar2 = iVar3 + 0xf;
    if (-1 < iVar3) {
      iVar2 = iVar3;
    }
    iVar3 = crypto_ecdh_shared_secret(*param_1,iVar2 >> 4,param_1 + 2,param_2,param_4);
    cVar4 = '\0';
    if (iVar3 == 0) {
      *param_5 = (long)((int)param_1[0x3e] / 2);
      cVar4 = cVar1;
    }
    return cVar4;
  }
  return '\0';
}


// ===== 0012b1e0 lkca_ec_compute_key =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012b1fe) */
/* WARNING: Removing unreachable block (ram,0x0012b282) */

char lkca_ec_compute_key(undefined4 *param_1,undefined8 param_2,long param_3,undefined8 param_4,
                        ulong *param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  
  iVar3 = param_1[0x3e];
  if (((iVar3 == param_3) && (cVar1 = *(char *)((long)param_1 + 0xe9), cVar1 != '\0')) &&
     ((ulong)(long)(iVar3 / 2) <= *param_5)) {
    iVar2 = iVar3 + 0xf;
    if (-1 < iVar3) {
      iVar2 = iVar3;
    }
    iVar3 = crypto_ecdh_shared_secret(*param_1,iVar2 >> 4,param_1 + 2,param_2,param_4);
    cVar4 = '\0';
    if (iVar3 == 0) {
      *param_5 = (long)((int)param_1[0x3e] / 2);
      cVar4 = cVar1;
    }
    return cVar4;
  }
  return '\0';
}


// ===== 0012b290 __pfx_lkca_ecdsa_verify =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_lkca_ecdsa_verify
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  lkca_ecdsa_verify_crypto_sig_isra_0(param_1,param_3,param_4,param_5,param_6);
  return;
}


// ===== 0012b2a0 lkca_ecdsa_verify =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void lkca_ecdsa_verify(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                      undefined8 param_5,undefined8 param_6)

{
  lkca_ecdsa_verify_crypto_sig_isra_0(param_1,param_3,param_4,param_5,param_6);
  return;
}


// ===== 0012b2c0 __pfx_lkca_hkdf_expand_only =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012b4eb) */

undefined8
__pfx_lkca_hkdf_expand_only
          (undefined8 param_1,undefined8 param_2,ulong param_3,undefined8 param_4,long param_5,
          long param_6)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  ulong __n;
  long in_GS_OFFSET;
  ulong unaff_retaddr;
  undefined4 uStack_228;
  char cStack_201;
  undefined8 uStack_200;
  undefined8 uStack_1f8;
  undefined8 uStack_1f0;
  undefined8 uStack_1e8;
  undefined8 uStack_1e0;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined8 uStack_1c8;
  undefined8 auStack_1c0 [48];
  long lStack_40;
  
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  cStack_201 = '\x01';
  uStack_200 = 0;
  uStack_1f8 = 0;
  uStack_1f0 = 0;
  uStack_1e8 = 0;
  uStack_1e0 = 0;
  uStack_1d8 = 0;
  uStack_1d0 = 0;
  uStack_1c8 = 0;
  memset(auStack_1c0,0,0x179);
  auStack_1c0[0] = param_1;
  iVar1 = crypto_shash_setkey(param_1,param_2,param_3 & 0xffffffff);
  if (iVar1 == 0) {
    cStack_201 = '\x01';
    if (unaff_retaddr != 0) {
      uStack_228 = (undefined4)param_5;
      uVar4 = 0;
      iVar1 = 0;
      do {
        iVar2 = crypto_shash_init(auStack_1c0);
        if ((((iVar2 != 0) ||
             ((iVar1 != 0 &&
              (iVar2 = crypto_shash_finup(auStack_1c0,(uVar4 - param_3) + param_6,
                                          param_3 & 0xffffffff,0), iVar2 != 0)))) ||
            ((param_5 != 0 &&
             (iVar2 = crypto_shash_finup(auStack_1c0,param_4,uStack_228,0), iVar2 != 0)))) ||
           (iVar2 = crypto_shash_finup(auStack_1c0,&cStack_201,1,0), iVar2 != 0)) goto LAB_0012b4a8;
        __n = unaff_retaddr - uVar4;
        if (__n < param_3) {
          iVar2 = crypto_shash_finup(auStack_1c0,0,0,&uStack_200);
          if (iVar2 != 0) goto LAB_0012b4a8;
          if (0x40 < __n) {
                    /* WARNING: Subroutine does not return */
            __fortify_panic(0x10,0x40,__n);
          }
          memcpy((void *)(param_6 + uVar4),&uStack_200,__n);
          memset(&uStack_200,0,0x40);
        }
        else {
          iVar2 = crypto_shash_finup(auStack_1c0,0,0,param_6 + uVar4);
          if (iVar2 != 0) goto LAB_0012b4a8;
        }
        iVar1 = iVar1 + (int)param_3;
        cStack_201 = cStack_201 + '\x01';
        uVar4 = (ulong)iVar1;
      } while (uVar4 < unaff_retaddr);
    }
    uVar3 = 1;
  }
  else {
    _printk(&DAT_00db04d8,param_3);
LAB_0012b4a8:
    uVar3 = 0;
  }
  if (lStack_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}


// ===== 0012b2d0 lkca_hkdf_expand_only =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012b4eb) */

undefined8
lkca_hkdf_expand_only
          (undefined8 param_1,undefined8 param_2,ulong param_3,undefined8 param_4,long param_5,
          long param_6)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  ulong __n;
  long in_GS_OFFSET;
  ulong unaff_retaddr;
  undefined4 local_228;
  char local_201;
  undefined8 local_200;
  undefined8 local_1f8;
  undefined8 local_1f0;
  undefined8 local_1e8;
  undefined8 local_1e0;
  undefined8 local_1d8;
  undefined8 local_1d0;
  undefined8 local_1c8;
  undefined8 local_1c0 [48];
  long local_40;
  
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_201 = '\x01';
  local_200 = 0;
  local_1f8 = 0;
  local_1f0 = 0;
  local_1e8 = 0;
  local_1e0 = 0;
  local_1d8 = 0;
  local_1d0 = 0;
  local_1c8 = 0;
  memset(local_1c0,0,0x179);
  local_1c0[0] = param_1;
  iVar1 = crypto_shash_setkey(param_1,param_2,param_3 & 0xffffffff);
  if (iVar1 == 0) {
    local_201 = '\x01';
    if (unaff_retaddr != 0) {
      local_228 = (undefined4)param_5;
      uVar4 = 0;
      iVar1 = 0;
      do {
        iVar2 = crypto_shash_init(local_1c0);
        if ((((iVar2 != 0) ||
             ((iVar1 != 0 &&
              (iVar2 = crypto_shash_finup(local_1c0,(uVar4 - param_3) + param_6,param_3 & 0xffffffff
                                          ,0), iVar2 != 0)))) ||
            ((param_5 != 0 &&
             (iVar2 = crypto_shash_finup(local_1c0,param_4,local_228,0), iVar2 != 0)))) ||
           (iVar2 = crypto_shash_finup(local_1c0,&local_201,1,0), iVar2 != 0)) goto LAB_0012b4a8;
        __n = unaff_retaddr - uVar4;
        if (__n < param_3) {
          iVar2 = crypto_shash_finup(local_1c0,0,0,&local_200);
          if (iVar2 != 0) goto LAB_0012b4a8;
          if (0x40 < __n) {
                    /* WARNING: Subroutine does not return */
            __fortify_panic(0x10,0x40,__n);
          }
          memcpy((void *)(param_6 + uVar4),&local_200,__n);
          memset(&local_200,0,0x40);
        }
        else {
          iVar2 = crypto_shash_finup(local_1c0,0,0,param_6 + uVar4);
          if (iVar2 != 0) goto LAB_0012b4a8;
        }
        iVar1 = iVar1 + (int)param_3;
        local_201 = local_201 + '\x01';
        uVar4 = (ulong)iVar1;
      } while (uVar4 < unaff_retaddr);
    }
    uVar3 = 1;
  }
  else {
    _printk(&DAT_00db04d8,param_3);
LAB_0012b4a8:
    uVar3 = 0;
  }
  if (local_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}


// ===== 0012b530 __pfx_lkca_hkdf_extract_and_expand =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012b640) */

ulong __pfx_lkca_hkdf_extract_and_expand
                (undefined8 param_1,long param_2,ulong param_3,long param_4,ulong param_5,
                long param_6,long param_7,ulong param_8)

{
  byte bVar1;
  int iVar2;
  ulong uVar3;
  bool bVar4;
  undefined8 in_R10;
  long in_GS_OFFSET;
  ulong unaff_retaddr;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  long lStack_20;
  ulong uVar5;
  
  lStack_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_60 = 0;
  uStack_58 = 0;
  uStack_50 = 0;
  uStack_48 = 0;
  uStack_40 = 0;
  uStack_38 = 0;
  uStack_30 = 0;
  uStack_28 = 0;
  bVar4 = param_2 == 0 || param_4 == 0;
  uVar5 = CONCAT71((int7)((ulong)in_R10 >> 8),bVar4);
  if (bVar4) {
    uVar5 = 0;
  }
  else if (param_6 != 0 && param_7 != 0) {
    bVar4 = 0x7fffffff < (unaff_retaddr | param_5) || 0x40 < param_3;
    uVar5 = CONCAT71((int7)(param_3 >> 8),bVar4) & 0xffffffff;
    if (bVar4) {
      uVar5 = 0;
    }
    else if (param_8 < 0x3fc1) {
      uVar3 = crypto_alloc_shash(param_1,0,0);
      uVar5 = 0;
      if (uVar3 < 0xfffffffffffff001) {
        iVar2 = crypto_shash_setkey(uVar3,param_4,param_5 & 0xffffffff);
        bVar1 = 0;
        if ((iVar2 == 0) &&
           (iVar2 = crypto_shash_tfm_digest(uVar3,param_2,param_3 & 0xffffffff,&uStack_60),
           iVar2 == 0)) {
          bVar1 = lkca_hkdf_expand_only
                            (uVar3,&uStack_60,*(undefined4 *)(*(long *)(uVar3 + 0x20) + -8),param_6,
                             unaff_retaddr,param_7,param_8);
        }
        crypto_destroy_tfm(uVar3,uVar3);
        uVar5 = (ulong)bVar1;
      }
    }
  }
  if (lStack_20 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5 & 0xffffffff;
}


// ===== 0012b540 lkca_hkdf_extract_and_expand =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012b640) */

ulong lkca_hkdf_extract_and_expand
                (undefined8 param_1,long param_2,ulong param_3,long param_4,ulong param_5,
                long param_6,long param_7,ulong param_8)

{
  byte bVar1;
  int iVar2;
  ulong uVar3;
  bool bVar4;
  undefined8 in_R10;
  long in_GS_OFFSET;
  ulong unaff_retaddr;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  long local_20;
  ulong uVar5;
  
  local_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  local_28 = 0;
  bVar4 = param_2 == 0 || param_4 == 0;
  uVar5 = CONCAT71((int7)((ulong)in_R10 >> 8),bVar4);
  if (bVar4) {
    uVar5 = 0;
  }
  else if (param_6 != 0 && param_7 != 0) {
    bVar4 = 0x7fffffff < (unaff_retaddr | param_5) || 0x40 < param_3;
    uVar5 = CONCAT71((int7)(param_3 >> 8),bVar4) & 0xffffffff;
    if (bVar4) {
      uVar5 = 0;
    }
    else if (param_8 < 0x3fc1) {
      uVar3 = crypto_alloc_shash(param_1,0,0);
      uVar5 = 0;
      if (uVar3 < 0xfffffffffffff001) {
        iVar2 = crypto_shash_setkey(uVar3,param_4,param_5 & 0xffffffff);
        bVar1 = 0;
        if ((iVar2 == 0) &&
           (iVar2 = crypto_shash_tfm_digest(uVar3,param_2,param_3 & 0xffffffff,&local_60),
           iVar2 == 0)) {
          bVar1 = lkca_hkdf_expand_only
                            (uVar3,&local_60,*(undefined4 *)(*(long *)(uVar3 + 0x20) + -8),param_6,
                             unaff_retaddr,param_7,param_8);
        }
        crypto_destroy_tfm(uVar3,uVar3);
        uVar5 = (ulong)bVar1;
      }
    }
  }
  if (local_20 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5 & 0xffffffff;
}


// ===== 0012b740 __pfx_lkca_hkdf_expand =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012b835) */
/* WARNING: Removing unreachable block (ram,0x0012b7b0) */
/* WARNING: Removing unreachable block (ram,0x0012b790) */
/* WARNING: Removing unreachable block (ram,0x0012b7b7) */

undefined1
__pfx_lkca_hkdf_expand
          (undefined8 param_1,long param_2,ulong param_3,long param_4,ulong param_5,long param_6)

{
  undefined1 uVar1;
  ulong uVar2;
  ulong unaff_retaddr;
  
  if (param_2 == 0 || param_4 == 0) {
    return 0;
  }
  if ((param_6 != 0 && param_3 < 0x41) && param_5 < 0x80000000) {
    if ((unaff_retaddr <= param_3 * 0xff) &&
       (uVar2 = crypto_alloc_shash(param_1,0,0), uVar2 < 0xfffffffffffff001)) {
      uVar1 = lkca_hkdf_expand_only(uVar2,param_2,param_3,param_4,param_5,param_6,unaff_retaddr);
      crypto_destroy_tfm(uVar2,uVar2);
      return uVar1;
    }
    return 0;
  }
  return 0;
}


// ===== 0012b750 lkca_hkdf_expand =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012b835) */
/* WARNING: Removing unreachable block (ram,0x0012b7b0) */
/* WARNING: Removing unreachable block (ram,0x0012b790) */
/* WARNING: Removing unreachable block (ram,0x0012b7b7) */

undefined1
lkca_hkdf_expand(undefined8 param_1,long param_2,ulong param_3,long param_4,ulong param_5,
                long param_6)

{
  undefined1 uVar1;
  ulong uVar2;
  ulong unaff_retaddr;
  
  if (param_2 == 0 || param_4 == 0) {
    return 0;
  }
  if ((param_6 != 0 && param_3 < 0x41) && param_5 < 0x80000000) {
    if ((unaff_retaddr <= param_3 * 0xff) &&
       (uVar2 = crypto_alloc_shash(param_1,0,0), uVar2 < 0xfffffffffffff001)) {
      uVar1 = lkca_hkdf_expand_only(uVar2,param_2,param_3,param_4,param_5,param_6,unaff_retaddr);
      crypto_destroy_tfm(uVar2,uVar2);
      return uVar1;
    }
    return 0;
  }
  return 0;
}


// ===== 0012b850 __pfx_libspdm_random_bytes =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012b873) */

undefined8 __pfx_libspdm_random_bytes(void)

{
  get_random_bytes();
  return 1;
}


// ===== 0012b860 libspdm_random_bytes =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012b873) */

undefined8 libspdm_random_bytes(void)

{
  get_random_bytes();
  return 1;
}


// ===== 0012b880 __pfx_lkca_hash_new =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012b8f5) */

ulong * __pfx_lkca_hash_new(undefined8 param_1)

{
  ulong uVar1;
  ulong *puVar2;
  
  uVar1 = crypto_alloc_shash(param_1,0,0);
  if (uVar1 < 0xfffffffffffff001) {
    puVar2 = (ulong *)__kmalloc_noprof((ulong)*(uint *)(*(long *)(uVar1 + 0x20) + -0x10) + 8,0xcc0);
    if (puVar2 == (ulong *)0x0) {
      _printk(&DAT_00db051d);
      crypto_destroy_tfm(uVar1,uVar1);
    }
    else {
      *puVar2 = uVar1;
    }
  }
  else {
    puVar2 = (ulong *)0x0;
    _printk(&DAT_00db0507,param_1);
  }
  return puVar2;
}


// ===== 0012b890 lkca_hash_new =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012b8f5) */

ulong * lkca_hash_new(undefined8 param_1)

{
  ulong uVar1;
  ulong *puVar2;
  
  uVar1 = crypto_alloc_shash(param_1,0,0);
  if (uVar1 < 0xfffffffffffff001) {
    puVar2 = (ulong *)__kmalloc_noprof((ulong)*(uint *)(*(long *)(uVar1 + 0x20) + -0x10) + 8,0xcc0);
    if (puVar2 == (ulong *)0x0) {
      _printk(&DAT_00db051d);
      crypto_destroy_tfm(uVar1,uVar1);
    }
    else {
      *puVar2 = uVar1;
    }
  }
  else {
    puVar2 = (ulong *)0x0;
    _printk(&DAT_00db0507,param_1);
  }
  return puVar2;
}


// ===== 0012b900 __pfx_lkca_hash_free =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_lkca_hash_free(undefined8 *param_1)

{
  crypto_destroy_tfm(*param_1,*param_1);
  kfree(param_1);
  return;
}


// ===== 0012b910 lkca_hash_free =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void lkca_hash_free(undefined8 *param_1)

{
  crypto_destroy_tfm(*param_1,*param_1);
  kfree(param_1);
  return;
}


// ===== 0012b940 __pfx_lkca_hash_duplicate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012b9b5) */

bool __pfx_lkca_hash_duplicate(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long in_GS_OFFSET;
  bool bVar2;
  undefined1 auStack_1a0 [384];
  long lStack_20;
  
  lStack_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  memset(auStack_1a0,0,0x179);
  iVar1 = crypto_shash_export(param_2,auStack_1a0);
  if (iVar1 == 0) {
    iVar1 = crypto_shash_import(param_1,auStack_1a0);
    bVar2 = iVar1 == 0;
  }
  else {
    bVar2 = false;
  }
  if (lStack_20 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return bVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0012b950 lkca_hash_duplicate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012b9b5) */

bool lkca_hash_duplicate(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long in_GS_OFFSET;
  bool bVar2;
  undefined1 auStack_1a0 [384];
  long local_20;
  
  local_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  memset(auStack_1a0,0,0x179);
  iVar1 = crypto_shash_export(param_2,auStack_1a0);
  if (iVar1 == 0) {
    iVar1 = crypto_shash_import(param_1,auStack_1a0);
    bVar2 = iVar1 == 0;
  }
  else {
    bVar2 = false;
  }
  if (local_20 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return bVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0012b9e0 __pfx_lkca_hmac_duplicate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_lkca_hmac_duplicate(long *param_1,long *param_2)

{
  void *__src;
  int iVar1;
  long lVar2;
  void *pvVar3;
  
  lVar2 = *(long *)(*param_1 + 0x20);
  iVar1 = *(int *)(lVar2 + -4);
  lVar2 = (long)(*(int *)(lVar2 + 0x28) + iVar1 * -2);
  __src = (void *)(*param_2 + 0x28 + lVar2);
  pvVar3 = memcpy((void *)(*param_1 + 0x28 + lVar2),__src,
                  (ulong)*(uint *)(*(long *)(*param_2 + 0x20) + 0x24));
  memcpy((void *)((long)pvVar3 + (long)iVar1),(void *)((long)__src + (long)iVar1),
         (ulong)*(uint *)(*(long *)(*param_2 + 0x20) + 0x24));
  *(uint *)(*param_1 + 4) = *(uint *)(*param_1 + 4) & 0xfffffffe;
  lkca_hash_duplicate(param_1,param_2);
  return;
}


// ===== 0012b9f0 lkca_hmac_duplicate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void lkca_hmac_duplicate(long *param_1,long *param_2)

{
  void *__src;
  int iVar1;
  long lVar2;
  void *pvVar3;
  
  lVar2 = *(long *)(*param_1 + 0x20);
  iVar1 = *(int *)(lVar2 + -4);
  lVar2 = (long)(*(int *)(lVar2 + 0x28) + iVar1 * -2);
  __src = (void *)(*param_2 + 0x28 + lVar2);
  pvVar3 = memcpy((void *)(*param_1 + 0x28 + lVar2),__src,
                  (ulong)*(uint *)(*(long *)(*param_2 + 0x20) + 0x24));
  memcpy((void *)((long)pvVar3 + (long)iVar1),(void *)((long)__src + (long)iVar1),
         (ulong)*(uint *)(*(long *)(*param_2 + 0x20) + 0x24));
  *(uint *)(*param_1 + 4) = *(uint *)(*param_1 + 4) & 0xfffffffe;
  lkca_hash_duplicate(param_1,param_2);
  return;
}


// ===== 0012ba70 __pfx_lkca_hash_all =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012baf0) */
/* WARNING: Removing unreachable block (ram,0x0012bb05) */

bool __pfx_lkca_hash_all(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4
                        )

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = crypto_alloc_shash(param_1,0,0);
  if (uVar2 < 0xfffffffffffff001) {
    iVar1 = crypto_shash_tfm_digest(uVar2,param_2,param_3,param_4);
    crypto_destroy_tfm(uVar2,uVar2);
    return iVar1 == 0;
  }
  return false;
}


// ===== 0012ba80 lkca_hash_all =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012baf0) */
/* WARNING: Removing unreachable block (ram,0x0012bb05) */

bool lkca_hash_all(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = crypto_alloc_shash(param_1,0,0);
  if (uVar2 < 0xfffffffffffff001) {
    iVar1 = crypto_shash_tfm_digest(uVar2,param_2,param_3,param_4);
    crypto_destroy_tfm(uVar2,uVar2);
    return iVar1 == 0;
  }
  return false;
}


// ===== 0012bb10 __pfx_lkca_hmac_set_key =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012bb3f) */
/* WARNING: Removing unreachable block (ram,0x0012bb52) */

bool __pfx_lkca_hmac_set_key(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = crypto_shash_setkey(*param_1);
  if (iVar1 != 0) {
    return iVar1 == 0;
  }
  iVar1 = crypto_shash_init(param_1);
  return iVar1 == 0;
}


// ===== 0012bb20 lkca_hmac_set_key =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012bb3f) */
/* WARNING: Removing unreachable block (ram,0x0012bb52) */

bool lkca_hmac_set_key(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = crypto_shash_setkey(*param_1);
  if (iVar1 != 0) {
    return iVar1 == 0;
  }
  iVar1 = crypto_shash_init(param_1);
  return iVar1 == 0;
}


// ===== 0012bb60 __pfx_lkca_hmac_all =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012bc01) */

bool __pfx_lkca_hmac_all(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4
                        ,undefined4 param_5,undefined8 param_6)

{
  int iVar1;
  ulong uVar2;
  bool bVar3;
  
  uVar2 = crypto_alloc_shash(param_1,0,0);
  if (uVar2 < 0xfffffffffffff001) {
    iVar1 = crypto_shash_setkey(uVar2,param_2,param_3);
    if (iVar1 == 0) {
      iVar1 = crypto_shash_tfm_digest(uVar2,param_4,param_5,param_6);
    }
    crypto_destroy_tfm(uVar2,uVar2);
    bVar3 = iVar1 == 0;
  }
  else {
    bVar3 = false;
  }
  return bVar3;
}


// ===== 0012bb70 lkca_hmac_all =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012bc01) */

bool lkca_hmac_all(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
                  undefined4 param_5,undefined8 param_6)

{
  int iVar1;
  ulong uVar2;
  bool bVar3;
  
  uVar2 = crypto_alloc_shash(param_1,0,0);
  if (uVar2 < 0xfffffffffffff001) {
    iVar1 = crypto_shash_setkey(uVar2,param_2,param_3);
    if (iVar1 == 0) {
      iVar1 = crypto_shash_tfm_digest(uVar2,param_4,param_5,param_6);
    }
    crypto_destroy_tfm(uVar2,uVar2);
    bVar3 = iVar1 == 0;
  }
  else {
    bVar3 = false;
  }
  return bVar3;
}


// ===== 0012bc20 __pfx_NV_PKCS1_MGF1.constprop.0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012be04) */

char __pfx_NV_PKCS1_MGF1_constprop_0(long param_1,ulong param_2,long param_3,undefined8 param_4)

{
  ulong uVar1;
  char cVar2;
  long lVar3;
  ulong uVar4;
  uint uVar5;
  long in_GS_OFFSET;
  uint uStack_74;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  long lStack_40;
  
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_74 = 0;
  uStack_70 = 0;
  uStack_68 = 0;
  uStack_60 = 0;
  uStack_58 = 0;
  uStack_50 = 0;
  uStack_48 = 0;
  if (param_1 == 0 || param_3 == 0) {
    cVar2 = '\0';
  }
  else {
    lVar3 = libspdm_sha384_new();
    if (lVar3 == 0) {
      _printk(&DAT_00df1068,__FUNCTION___7);
      cVar2 = '\0';
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      if (param_2 == 0) {
        cVar2 = '\x01';
      }
      else {
        do {
          uStack_74 = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 |
                      uVar5 << 0x18;
          cVar2 = libspdm_sha384_init(lVar3);
          if (cVar2 == '\0') {
            _printk(&DAT_00df1090,__FUNCTION___7);
            cVar2 = '\0';
            break;
          }
          cVar2 = libspdm_sha384_update(lVar3,param_3,param_4);
          if (cVar2 == '\0') {
            _printk(&DAT_00df10b8,__FUNCTION___7);
            cVar2 = '\0';
            break;
          }
          cVar2 = libspdm_sha384_update(lVar3,&uStack_74,4);
          if (cVar2 == '\0') {
            _printk(&DAT_00df10e8,__FUNCTION___7);
            cVar2 = '\0';
            break;
          }
          uVar1 = uVar4 + 0x30;
          if (param_2 < uVar1) {
            cVar2 = libspdm_sha384_final(lVar3,&uStack_70);
            if (cVar2 == '\0') {
              _printk(&DAT_00df1160,__FUNCTION___7);
            }
            else {
              if (0x30 < param_2 - uVar4) {
                    /* WARNING: Subroutine does not return */
                __fortify_panic(0x10,0x30);
              }
              memcpy((void *)(param_1 + uVar4),&uStack_70,param_2 - uVar4);
            }
            break;
          }
          cVar2 = libspdm_sha384_final(lVar3,param_1 + -0x30 + uVar1);
          if (cVar2 == '\0') {
            _printk(&DAT_00df1120,__FUNCTION___7);
            break;
          }
          uVar5 = uVar5 + 1;
          uVar4 = uVar1;
        } while (uVar1 < param_2);
      }
      libspdm_sha384_free(lVar3);
    }
  }
  if (lStack_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return cVar2;
}


// ===== 0012bc30 NV_PKCS1_MGF1.constprop.0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012be04) */

char NV_PKCS1_MGF1_constprop_0(long param_1,ulong param_2,long param_3,undefined8 param_4)

{
  ulong uVar1;
  char cVar2;
  long lVar3;
  ulong uVar4;
  uint uVar5;
  long in_GS_OFFSET;
  uint local_74;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  long local_40;
  
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_74 = 0;
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  if (param_1 == 0 || param_3 == 0) {
    cVar2 = '\0';
  }
  else {
    lVar3 = libspdm_sha384_new();
    if (lVar3 == 0) {
      _printk(&DAT_00df1068,__FUNCTION___7);
      cVar2 = '\0';
    }
    else {
      uVar5 = 0;
      uVar4 = 0;
      if (param_2 == 0) {
        cVar2 = '\x01';
      }
      else {
        do {
          local_74 = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18
          ;
          cVar2 = libspdm_sha384_init(lVar3);
          if (cVar2 == '\0') {
            _printk(&DAT_00df1090,__FUNCTION___7);
            cVar2 = '\0';
            break;
          }
          cVar2 = libspdm_sha384_update(lVar3,param_3,param_4);
          if (cVar2 == '\0') {
            _printk(&DAT_00df10b8,__FUNCTION___7);
            cVar2 = '\0';
            break;
          }
          cVar2 = libspdm_sha384_update(lVar3,&local_74,4);
          if (cVar2 == '\0') {
            _printk(&DAT_00df10e8,__FUNCTION___7);
            cVar2 = '\0';
            break;
          }
          uVar1 = uVar4 + 0x30;
          if (param_2 < uVar1) {
            cVar2 = libspdm_sha384_final(lVar3,&local_70);
            if (cVar2 == '\0') {
              _printk(&DAT_00df1160,__FUNCTION___7);
            }
            else {
              if (0x30 < param_2 - uVar4) {
                    /* WARNING: Subroutine does not return */
                __fortify_panic(0x10,0x30);
              }
              memcpy((void *)(param_1 + uVar4),&local_70,param_2 - uVar4);
            }
            break;
          }
          cVar2 = libspdm_sha384_final(lVar3,param_1 + -0x30 + uVar1);
          if (cVar2 == '\0') {
            _printk(&DAT_00df1120,__FUNCTION___7);
            break;
          }
          uVar5 = uVar5 + 1;
          uVar4 = uVar1;
        } while (uVar1 < param_2);
      }
      libspdm_sha384_free(lVar3);
    }
  }
  if (local_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return cVar2;
}


// ===== 0012be40 __pfx_libspdm_rsa_new =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012beae) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __pfx_libspdm_rsa_new(void)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  
  lVar1 = __kmalloc_cache_noprof(_strcasecmp,0xcc0,0x88);
  if (lVar1 != 0) {
    uVar3 = 0;
    do {
      uVar2 = (int)uVar3 + 0x20;
      *(undefined8 *)(lVar1 + uVar3) = 0;
      *(undefined8 *)(lVar1 + 8 + uVar3) = 0;
      *(undefined8 *)(lVar1 + 0x10 + uVar3) = 0;
      *(undefined8 *)(lVar1 + 0x18 + uVar3) = 0;
      uVar3 = (ulong)uVar2;
    } while (uVar2 < 0x80);
    *(undefined8 *)(lVar1 + (ulong)uVar2) = 0;
  }
  return;
}


// ===== 0012be50 libspdm_rsa_new =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012beae) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void libspdm_rsa_new(void)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  
  lVar1 = __kmalloc_cache_noprof(_strcasecmp,0xcc0,0x88);
  if (lVar1 != 0) {
    uVar3 = 0;
    do {
      uVar2 = (int)uVar3 + 0x20;
      *(undefined8 *)(lVar1 + uVar3) = 0;
      *(undefined8 *)(lVar1 + 8 + uVar3) = 0;
      *(undefined8 *)(lVar1 + 0x10 + uVar3) = 0;
      *(undefined8 *)(lVar1 + 0x18 + uVar3) = 0;
      uVar3 = (ulong)uVar2;
    } while (uVar2 < 0x80);
    *(undefined8 *)(lVar1 + (ulong)uVar2) = 0;
  }
  return;
}


// ===== 0012bec0 __pfx_libspdm_rsa_free =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012bf5a) */

void __pfx_libspdm_rsa_free(long *param_1)

{
  if (param_1 != (long *)0x0) {
    if (*param_1 != 0) {
      kfree();
    }
    if (param_1[1] != 0) {
      kfree();
    }
    if (param_1[2] != 0) {
      kfree();
    }
    if (param_1[4] != 0) {
      kfree();
    }
    if (param_1[3] != 0) {
      kfree();
    }
    if (param_1[6] != 0) {
      kfree();
    }
    if (param_1[5] != 0) {
      kfree();
    }
    if (param_1[7] != 0) {
      kfree();
    }
    kfree(param_1);
    return;
  }
  return;
}


// ===== 0012bed0 libspdm_rsa_free =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012bf5a) */

void libspdm_rsa_free(long *param_1)

{
  if (param_1 != (long *)0x0) {
    if (*param_1 != 0) {
      kfree();
    }
    if (param_1[1] != 0) {
      kfree();
    }
    if (param_1[2] != 0) {
      kfree();
    }
    if (param_1[4] != 0) {
      kfree();
    }
    if (param_1[3] != 0) {
      kfree();
    }
    if (param_1[6] != 0) {
      kfree();
    }
    if (param_1[5] != 0) {
      kfree();
    }
    if (param_1[7] != 0) {
      kfree();
    }
    kfree(param_1);
    return;
  }
  return;
}


// ===== 0012bf60 __pfx_libspdm_rsa_set_key =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012bf9d) */

ulong __pfx_libspdm_rsa_set_key(long *param_1,uint param_2,void *param_3,size_t param_4)

{
  void *pvVar1;
  bool bVar2;
  undefined8 unaff_RBX;
  ulong uVar3;
  
  bVar2 = param_1 != (long *)0x0 && param_2 < 8;
  uVar3 = CONCAT71((int7)((ulong)unaff_RBX >> 8),bVar2);
  if (bVar2) {
    if (param_3 == (void *)0x0) {
      pvVar1 = (void *)0x0;
      param_4 = 0;
    }
    else {
      pvVar1 = (void *)__kmalloc_noprof(param_4,0xcc0);
      if (pvVar1 == (void *)0x0) {
        uVar3 = 0;
        goto LAB_0012bf92;
      }
      pvVar1 = memcpy(pvVar1,param_3,param_4);
    }
    if (param_2 == 4) {
      if (param_1[4] != 0) {
        kfree();
      }
      param_1[4] = (long)pvVar1;
      param_1[0xc] = param_4;
    }
    else if (param_2 < 5) {
      if (param_2 == 2) {
        if (param_1[2] != 0) {
          kfree();
        }
        param_1[2] = (long)pvVar1;
        param_1[10] = param_4;
      }
      else if (param_2 == 3) {
        if (param_1[3] != 0) {
          kfree();
        }
        param_1[3] = (long)pvVar1;
        param_1[0xb] = param_4;
      }
      else if (param_2 == 0) {
        if (*param_1 != 0) {
          kfree();
        }
        *param_1 = (long)pvVar1;
        param_1[8] = param_4;
      }
      else {
        if (param_1[1] != 0) {
          kfree();
        }
        param_1[1] = (long)pvVar1;
        param_1[9] = param_4;
      }
    }
    else if (param_2 == 6) {
      if (param_1[6] != 0) {
        kfree();
      }
      param_1[6] = (long)pvVar1;
      param_1[0xe] = param_4;
    }
    else if (param_2 == 7) {
      if (param_1[7] != 0) {
        kfree();
      }
      param_1[7] = (long)pvVar1;
      param_1[0xf] = param_4;
    }
    else {
      if (param_1[5] != 0) {
        kfree();
      }
      param_1[5] = (long)pvVar1;
      param_1[0xd] = param_4;
    }
  }
LAB_0012bf92:
  return uVar3 & 0xffffffff;
}


// ===== 0012bf70 libspdm_rsa_set_key =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012bf9d) */

ulong libspdm_rsa_set_key(long *param_1,uint param_2,void *param_3,size_t param_4)

{
  void *pvVar1;
  bool bVar2;
  undefined8 unaff_RBX;
  ulong uVar3;
  
  bVar2 = param_1 != (long *)0x0 && param_2 < 8;
  uVar3 = CONCAT71((int7)((ulong)unaff_RBX >> 8),bVar2);
  if (bVar2) {
    if (param_3 == (void *)0x0) {
      pvVar1 = (void *)0x0;
      param_4 = 0;
    }
    else {
      pvVar1 = (void *)__kmalloc_noprof(param_4,0xcc0);
      if (pvVar1 == (void *)0x0) {
        uVar3 = 0;
        goto LAB_0012bf92;
      }
      pvVar1 = memcpy(pvVar1,param_3,param_4);
    }
    if (param_2 == 4) {
      if (param_1[4] != 0) {
        kfree();
      }
      param_1[4] = (long)pvVar1;
      param_1[0xc] = param_4;
    }
    else if (param_2 < 5) {
      if (param_2 == 2) {
        if (param_1[2] != 0) {
          kfree();
        }
        param_1[2] = (long)pvVar1;
        param_1[10] = param_4;
      }
      else if (param_2 == 3) {
        if (param_1[3] != 0) {
          kfree();
        }
        param_1[3] = (long)pvVar1;
        param_1[0xb] = param_4;
      }
      else if (param_2 == 0) {
        if (*param_1 != 0) {
          kfree();
        }
        *param_1 = (long)pvVar1;
        param_1[8] = param_4;
      }
      else {
        if (param_1[1] != 0) {
          kfree();
        }
        param_1[1] = (long)pvVar1;
        param_1[9] = param_4;
      }
    }
    else if (param_2 == 6) {
      if (param_1[6] != 0) {
        kfree();
      }
      param_1[6] = (long)pvVar1;
      param_1[0xe] = param_4;
    }
    else if (param_2 == 7) {
      if (param_1[7] != 0) {
        kfree();
      }
      param_1[7] = (long)pvVar1;
      param_1[0xf] = param_4;
    }
    else {
      if (param_1[5] != 0) {
        kfree();
      }
      param_1[5] = (long)pvVar1;
      param_1[0xd] = param_4;
    }
  }
LAB_0012bf92:
  return uVar3 & 0xffffffff;
}


// ===== 0012c1d0 __pfx_lkca_rsa_pss_sign =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012c4cc) */

ulong __pfx_lkca_rsa_pss_sign
                (undefined8 *param_1,long param_2,undefined8 param_3,long param_4,byte *param_5,
                ulong *param_6)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  long in_GS_OFFSET;
  long lStack_b8;
  uint uStack_9c;
  uint uStack_84;
  byte abStack_80 [64];
  long lStack_40;
  
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_84 = 0;
  abStack_80[0] = 0;
  abStack_80[1] = 0;
  abStack_80[2] = 0;
  abStack_80[3] = 0;
  abStack_80[4] = 0;
  abStack_80[5] = 0;
  abStack_80[6] = 0;
  abStack_80[7] = 0;
  abStack_80[8] = 0;
  abStack_80[9] = 0;
  abStack_80[10] = 0;
  abStack_80[0xb] = 0;
  abStack_80[0xc] = 0;
  abStack_80[0xd] = 0;
  abStack_80[0xe] = 0;
  abStack_80[0xf] = 0;
  abStack_80[0x10] = 0;
  abStack_80[0x11] = 0;
  abStack_80[0x12] = 0;
  abStack_80[0x13] = 0;
  abStack_80[0x14] = 0;
  abStack_80[0x15] = 0;
  abStack_80[0x16] = 0;
  abStack_80[0x17] = 0;
  abStack_80[0x18] = 0;
  abStack_80[0x19] = 0;
  abStack_80[0x1a] = 0;
  abStack_80[0x1b] = 0;
  abStack_80[0x1c] = 0;
  abStack_80[0x1d] = 0;
  abStack_80[0x1e] = 0;
  abStack_80[0x1f] = 0;
  abStack_80[0x20] = 0;
  abStack_80[0x21] = 0;
  abStack_80[0x22] = 0;
  abStack_80[0x23] = 0;
  abStack_80[0x24] = 0;
  abStack_80[0x25] = 0;
  abStack_80[0x26] = 0;
  abStack_80[0x27] = 0;
  abStack_80[0x28] = 0;
  abStack_80[0x29] = 0;
  abStack_80[0x2a] = 0;
  abStack_80[0x2b] = 0;
  abStack_80[0x2c] = 0;
  abStack_80[0x2d] = 0;
  abStack_80[0x2e] = 0;
  abStack_80[0x2f] = 0;
  abStack_80[0x30] = 0;
  abStack_80[0x31] = 0;
  abStack_80[0x32] = 0;
  abStack_80[0x33] = 0;
  abStack_80[0x34] = 0;
  abStack_80[0x35] = 0;
  abStack_80[0x36] = 0;
  abStack_80[0x37] = 0;
  abStack_80[0x38] = 0;
  abStack_80[0x39] = 0;
  abStack_80[0x3a] = 0;
  abStack_80[0x3b] = 0;
  abStack_80[0x3c] = 0;
  abStack_80[0x3d] = 0;
  abStack_80[0x3e] = 0;
  abStack_80[0x3f] = 0;
  uVar4 = mpi_alloc(0);
  lVar5 = mpi_alloc(0);
  lVar6 = mpi_read_raw_data(*param_1,param_1[8]);
  if (lVar6 == 0) {
    lVar8 = 0;
    uVar10 = 0;
    _printk(&DAT_00df11a0,"nvRsaPaddingAddPkcs1PssMgf1");
    lStack_b8 = 0;
  }
  else {
    lStack_b8 = mpi_read_raw_data(param_1[2],param_1[10]);
    if (lStack_b8 == 0) {
      lVar8 = 0;
      uVar10 = 0;
      _printk(&DAT_00df11c0,"nvRsaPaddingAddPkcs1PssMgf1");
    }
    else {
      uVar2 = *(uint *)(lVar6 + 8);
      if (uVar2 == 0) {
        *param_5 = 0;
        uVar9 = 0xffffffffffffffff;
        param_5 = param_5 + 1;
        uStack_9c = 0;
      }
      else {
        uVar9 = (ulong)uVar2 + 7 >> 3;
        uStack_9c = uVar2 - 1 & 7;
        if (uStack_9c == 0) {
          *param_5 = 0;
          uVar9 = uVar9 - 1;
          param_5 = param_5 + 1;
        }
        if (uVar9 < param_4 + 2U) {
          uVar10 = FUN_0052999c();
          return uVar10;
        }
      }
      if (param_2 == 2) {
        get_random_bytes(abStack_80,0x30);
        lVar7 = (uVar9 - param_4) + -1;
        lVar8 = libspdm_sha384_new();
        if (lVar8 == 0) {
          uVar10 = 0;
          _printk(&DAT_00df1230,"nvRsaPaddingAddPkcs1PssMgf1");
        }
        else {
          uVar2 = libspdm_sha384_init(lVar8);
          uVar10 = (ulong)uVar2;
          if ((char)uVar2 == '\0') {
            _printk(&DAT_00df1258,"nvRsaPaddingAddPkcs1PssMgf1");
          }
          else {
            uVar2 = libspdm_sha384_update(lVar8,&zeroes,8);
            uVar10 = (ulong)uVar2;
            if ((char)uVar2 == '\0') {
              _printk(&DAT_00df1288,"nvRsaPaddingAddPkcs1PssMgf1");
            }
            else {
              uVar2 = libspdm_sha384_update(lVar8,param_3,param_4);
              uVar10 = (ulong)uVar2;
              if ((char)uVar2 == '\0') {
                _printk(&DAT_00df12c0,"nvRsaPaddingAddPkcs1PssMgf1");
              }
              else {
                uVar2 = libspdm_sha384_update(lVar8,abStack_80,0x30);
                uVar10 = (ulong)uVar2;
                if ((char)uVar2 == '\0') {
                  _printk(&DAT_00df1300,"nvRsaPaddingAddPkcs1PssMgf1");
                }
                else {
                  uVar2 = libspdm_sha384_final(lVar8,param_5 + lVar7);
                  uVar10 = (ulong)uVar2;
                  if ((char)uVar2 == '\0') {
                    _printk(&DAT_00df1338,"nvRsaPaddingAddPkcs1PssMgf1");
                  }
                  else {
                    uVar2 = NV_PKCS1_MGF1_constprop_0(param_5,lVar7,param_5 + lVar7,param_4);
                    uVar10 = (ulong)uVar2;
                    if ((char)uVar2 == '\0') {
                      _printk(&DAT_00df1370,"nvRsaPaddingAddPkcs1PssMgf1");
                    }
                    else {
                      pbVar1 = param_5 + (uVar9 - param_4) + -0x32;
                      lVar5 = 0;
                      *pbVar1 = *pbVar1 ^ 1;
                      do {
                        pbVar1[lVar5 + 1] = pbVar1[lVar5 + 1] ^ abStack_80[lVar5];
                        lVar5 = lVar5 + 1;
                      } while (lVar5 != 0x30);
                      if (uStack_9c != 0) {
                        *param_5 = *param_5 & (byte)(0xff >> (8U - (char)uStack_9c & 0x1f));
                      }
                      param_5[uVar9 - 1] = 0xbc;
                      lVar5 = mpi_read_raw_data(param_5,uVar9);
                      if (lVar5 == 0) {
                        _printk(&DAT_00df1390,"nvRsaPaddingAddPkcs1PssMgf1");
                      }
                      else {
                        iVar3 = mpi_powm(uVar4,lVar5,lStack_b8,lVar6);
                        if (iVar3 == 0) {
                          iVar3 = mpi_read_buffer(uVar4,param_5,(int)*param_6,&uStack_84,0);
                          if (iVar3 == 0) {
                            if ((ulong)uStack_84 <= *param_6) {
                              *param_6 = (ulong)uStack_84;
                            }
                          }
                          else {
                            _printk(&DAT_00df13b8,"nvRsaPaddingAddPkcs1PssMgf1");
                          }
                        }
                        else {
                          _printk(&DAT_00db0549,"nvRsaPaddingAddPkcs1PssMgf1");
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
      else {
        lVar8 = 0;
        uVar10 = 0;
        _printk(&DAT_00df1208,"nvRsaPaddingAddPkcs1PssMgf1",0x30);
      }
    }
  }
  mpi_free(lVar6);
  mpi_free(lStack_b8);
  mpi_free(uVar4);
  mpi_free(lVar5);
  libspdm_sha384_free(lVar8);
  if (lStack_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar10;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0012c1e0 lkca_rsa_pss_sign =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012c4cc) */

ulong lkca_rsa_pss_sign(undefined8 *param_1,long param_2,undefined8 param_3,long param_4,
                       byte *param_5,ulong *param_6)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  long in_GS_OFFSET;
  long local_b8;
  uint local_9c;
  uint local_84;
  byte local_80 [64];
  long local_40;
  
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_84 = 0;
  local_80[0] = 0;
  local_80[1] = 0;
  local_80[2] = 0;
  local_80[3] = 0;
  local_80[4] = 0;
  local_80[5] = 0;
  local_80[6] = 0;
  local_80[7] = 0;
  local_80[8] = 0;
  local_80[9] = 0;
  local_80[10] = 0;
  local_80[0xb] = 0;
  local_80[0xc] = 0;
  local_80[0xd] = 0;
  local_80[0xe] = 0;
  local_80[0xf] = 0;
  local_80[0x10] = 0;
  local_80[0x11] = 0;
  local_80[0x12] = 0;
  local_80[0x13] = 0;
  local_80[0x14] = 0;
  local_80[0x15] = 0;
  local_80[0x16] = 0;
  local_80[0x17] = 0;
  local_80[0x18] = 0;
  local_80[0x19] = 0;
  local_80[0x1a] = 0;
  local_80[0x1b] = 0;
  local_80[0x1c] = 0;
  local_80[0x1d] = 0;
  local_80[0x1e] = 0;
  local_80[0x1f] = 0;
  local_80[0x20] = 0;
  local_80[0x21] = 0;
  local_80[0x22] = 0;
  local_80[0x23] = 0;
  local_80[0x24] = 0;
  local_80[0x25] = 0;
  local_80[0x26] = 0;
  local_80[0x27] = 0;
  local_80[0x28] = 0;
  local_80[0x29] = 0;
  local_80[0x2a] = 0;
  local_80[0x2b] = 0;
  local_80[0x2c] = 0;
  local_80[0x2d] = 0;
  local_80[0x2e] = 0;
  local_80[0x2f] = 0;
  local_80[0x30] = 0;
  local_80[0x31] = 0;
  local_80[0x32] = 0;
  local_80[0x33] = 0;
  local_80[0x34] = 0;
  local_80[0x35] = 0;
  local_80[0x36] = 0;
  local_80[0x37] = 0;
  local_80[0x38] = 0;
  local_80[0x39] = 0;
  local_80[0x3a] = 0;
  local_80[0x3b] = 0;
  local_80[0x3c] = 0;
  local_80[0x3d] = 0;
  local_80[0x3e] = 0;
  local_80[0x3f] = 0;
  uVar4 = mpi_alloc(0);
  lVar5 = mpi_alloc(0);
  lVar6 = mpi_read_raw_data(*param_1,param_1[8]);
  if (lVar6 == 0) {
    lVar8 = 0;
    uVar10 = 0;
    _printk(&DAT_00df11a0,"nvRsaPaddingAddPkcs1PssMgf1");
    local_b8 = 0;
  }
  else {
    local_b8 = mpi_read_raw_data(param_1[2],param_1[10]);
    if (local_b8 == 0) {
      lVar8 = 0;
      uVar10 = 0;
      _printk(&DAT_00df11c0,"nvRsaPaddingAddPkcs1PssMgf1");
    }
    else {
      uVar2 = *(uint *)(lVar6 + 8);
      if (uVar2 == 0) {
        *param_5 = 0;
        uVar9 = 0xffffffffffffffff;
        param_5 = param_5 + 1;
        local_9c = 0;
      }
      else {
        uVar9 = (ulong)uVar2 + 7 >> 3;
        local_9c = uVar2 - 1 & 7;
        if (local_9c == 0) {
          *param_5 = 0;
          uVar9 = uVar9 - 1;
          param_5 = param_5 + 1;
        }
        if (uVar9 < param_4 + 2U) {
          uVar10 = FUN_0052999c();
          return uVar10;
        }
      }
      if (param_2 == 2) {
        get_random_bytes(local_80,0x30);
        lVar7 = (uVar9 - param_4) + -1;
        lVar8 = libspdm_sha384_new();
        if (lVar8 == 0) {
          uVar10 = 0;
          _printk(&DAT_00df1230,"nvRsaPaddingAddPkcs1PssMgf1");
        }
        else {
          uVar2 = libspdm_sha384_init(lVar8);
          uVar10 = (ulong)uVar2;
          if ((char)uVar2 == '\0') {
            _printk(&DAT_00df1258,"nvRsaPaddingAddPkcs1PssMgf1");
          }
          else {
            uVar2 = libspdm_sha384_update(lVar8,&zeroes,8);
            uVar10 = (ulong)uVar2;
            if ((char)uVar2 == '\0') {
              _printk(&DAT_00df1288,"nvRsaPaddingAddPkcs1PssMgf1");
            }
            else {
              uVar2 = libspdm_sha384_update(lVar8,param_3,param_4);
              uVar10 = (ulong)uVar2;
              if ((char)uVar2 == '\0') {
                _printk(&DAT_00df12c0,"nvRsaPaddingAddPkcs1PssMgf1");
              }
              else {
                uVar2 = libspdm_sha384_update(lVar8,local_80,0x30);
                uVar10 = (ulong)uVar2;
                if ((char)uVar2 == '\0') {
                  _printk(&DAT_00df1300,"nvRsaPaddingAddPkcs1PssMgf1");
                }
                else {
                  uVar2 = libspdm_sha384_final(lVar8,param_5 + lVar7);
                  uVar10 = (ulong)uVar2;
                  if ((char)uVar2 == '\0') {
                    _printk(&DAT_00df1338,"nvRsaPaddingAddPkcs1PssMgf1");
                  }
                  else {
                    uVar2 = NV_PKCS1_MGF1_constprop_0(param_5,lVar7,param_5 + lVar7,param_4);
                    uVar10 = (ulong)uVar2;
                    if ((char)uVar2 == '\0') {
                      _printk(&DAT_00df1370,"nvRsaPaddingAddPkcs1PssMgf1");
                    }
                    else {
                      pbVar1 = param_5 + (uVar9 - param_4) + -0x32;
                      lVar5 = 0;
                      *pbVar1 = *pbVar1 ^ 1;
                      do {
                        pbVar1[lVar5 + 1] = pbVar1[lVar5 + 1] ^ local_80[lVar5];
                        lVar5 = lVar5 + 1;
                      } while (lVar5 != 0x30);
                      if (local_9c != 0) {
                        *param_5 = *param_5 & (byte)(0xff >> (8U - (char)local_9c & 0x1f));
                      }
                      param_5[uVar9 - 1] = 0xbc;
                      lVar5 = mpi_read_raw_data(param_5,uVar9);
                      if (lVar5 == 0) {
                        _printk(&DAT_00df1390,"nvRsaPaddingAddPkcs1PssMgf1");
                      }
                      else {
                        iVar3 = mpi_powm(uVar4,lVar5,local_b8,lVar6);
                        if (iVar3 == 0) {
                          iVar3 = mpi_read_buffer(uVar4,param_5,(int)*param_6,&local_84,0);
                          if (iVar3 == 0) {
                            if ((ulong)local_84 <= *param_6) {
                              *param_6 = (ulong)local_84;
                            }
                          }
                          else {
                            _printk(&DAT_00df13b8,"nvRsaPaddingAddPkcs1PssMgf1");
                          }
                        }
                        else {
                          _printk(&DAT_00db0549,"nvRsaPaddingAddPkcs1PssMgf1");
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
      else {
        lVar8 = 0;
        uVar10 = 0;
        _printk(&DAT_00df1208,"nvRsaPaddingAddPkcs1PssMgf1",0x30);
      }
    }
  }
  mpi_free(lVar6);
  mpi_free(local_b8);
  mpi_free(uVar4);
  mpi_free(lVar5);
  libspdm_sha384_free(lVar8);
  if (local_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar10;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0012c510 __pfx_libspdm_aead_aes_gcm_encrypt =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012c547) */
/* WARNING: Removing unreachable block (ram,0x0012c5d0) */

bool __pfx_libspdm_aead_aes_gcm_encrypt
               (undefined8 param_1,long param_2,undefined8 param_3,long param_4,undefined8 param_5,
               ulong param_6,ulong param_7,undefined8 param_8,long param_9,undefined8 param_10,
               ulong *param_11)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  
  bVar1 = 0x7fffffff < (param_7 | param_6);
  bVar2 = bVar1 || param_4 != 0xc;
  if (bVar1 || param_4 != 0xc) {
    bVar2 = false;
  }
  else if ((((param_2 - 0x10U < 0x11) && ((0x10101UL >> (param_2 - 0x10U & 0x3f) & 1) != 0)) &&
           (param_9 - 0xcU < 5)) &&
          ((param_11 == (ulong *)0x0 || ((param_7 <= *param_11 && (*param_11 < 0x80000000)))))) {
    iVar3 = libspdm_aead();
    *param_11 = param_7;
    return iVar3 == 0;
  }
  return bVar2;
}


// ===== 0012c520 libspdm_aead_aes_gcm_encrypt =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012c547) */
/* WARNING: Removing unreachable block (ram,0x0012c5d0) */

bool libspdm_aead_aes_gcm_encrypt
               (undefined8 param_1,long param_2,undefined8 param_3,long param_4,undefined8 param_5,
               ulong param_6,ulong param_7,undefined8 param_8,long param_9,undefined8 param_10,
               ulong *param_11)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  
  bVar1 = 0x7fffffff < (param_7 | param_6);
  bVar2 = bVar1 || param_4 != 0xc;
  if (bVar1 || param_4 != 0xc) {
    bVar2 = false;
  }
  else if ((((param_2 - 0x10U < 0x11) && ((0x10101UL >> (param_2 - 0x10U & 0x3f) & 1) != 0)) &&
           (param_9 - 0xcU < 5)) &&
          ((param_11 == (ulong *)0x0 || ((param_7 <= *param_11 && (*param_11 < 0x80000000)))))) {
    iVar3 = libspdm_aead();
    *param_11 = param_7;
    return iVar3 == 0;
  }
  return bVar2;
}


// ===== 0012c5e0 __pfx_libspdm_aead_aes_gcm_decrypt =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012c617) */
/* WARNING: Removing unreachable block (ram,0x0012c6a0) */

bool __pfx_libspdm_aead_aes_gcm_decrypt
               (undefined8 param_1,long param_2,undefined8 param_3,long param_4,undefined8 param_5,
               ulong param_6,ulong param_7,undefined8 param_8,long param_9,undefined8 param_10,
               ulong *param_11)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  
  bVar1 = 0x7fffffff < (param_7 | param_6);
  bVar2 = bVar1 || param_4 != 0xc;
  if (bVar1 || param_4 != 0xc) {
    bVar2 = false;
  }
  else if ((((param_2 - 0x10U < 0x11) && ((0x10101UL >> (param_2 - 0x10U & 0x3f) & 1) != 0)) &&
           (param_9 - 0xcU < 5)) &&
          ((param_11 == (ulong *)0x0 || ((param_7 <= *param_11 && (*param_11 < 0x80000000)))))) {
    iVar3 = libspdm_aead();
    *param_11 = param_7;
    return iVar3 == 0;
  }
  return bVar2;
}


// ===== 0012c5f0 libspdm_aead_aes_gcm_decrypt =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012c617) */
/* WARNING: Removing unreachable block (ram,0x0012c6a0) */

bool libspdm_aead_aes_gcm_decrypt
               (undefined8 param_1,long param_2,undefined8 param_3,long param_4,undefined8 param_5,
               ulong param_6,ulong param_7,undefined8 param_8,long param_9,undefined8 param_10,
               ulong *param_11)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  
  bVar1 = 0x7fffffff < (param_7 | param_6);
  bVar2 = bVar1 || param_4 != 0xc;
  if (bVar1 || param_4 != 0xc) {
    bVar2 = false;
  }
  else if ((((param_2 - 0x10U < 0x11) && ((0x10101UL >> (param_2 - 0x10U & 0x3f) & 1) != 0)) &&
           (param_9 - 0xcU < 5)) &&
          ((param_11 == (ulong *)0x0 || ((param_7 <= *param_11 && (*param_11 < 0x80000000)))))) {
    iVar3 = libspdm_aead();
    *param_11 = param_7;
    return iVar3 == 0;
  }
  return bVar2;
}


// ===== 0012c6b0 __pfx_libspdm_sha256_new =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_libspdm_sha256_new(void)

{
  lkca_hash_new("sha256");
  return;
}


// ===== 0012c6c0 libspdm_sha256_new =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void libspdm_sha256_new(void)

{
  lkca_hash_new("sha256");
  return;
}


// ===== 0012c6e0 __pfx_libspdm_sha256_free =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_libspdm_sha256_free(void)

{
  lkca_hash_free();
  return;
}


// ===== 0012c6f0 libspdm_sha256_free =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void libspdm_sha256_free(void)

{
  lkca_hash_free();
  return;
}


// ===== 0012c700 __pfx_libspdm_sha256_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012c723) */

bool __pfx_libspdm_sha256_init(void)

{
  int iVar1;
  
  iVar1 = crypto_shash_init();
  return iVar1 == 0;
}


// ===== 0012c710 libspdm_sha256_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012c723) */

bool libspdm_sha256_init(void)

{
  int iVar1;
  
  iVar1 = crypto_shash_init();
  return iVar1 == 0;
}


// ===== 0012c730 __pfx_libspdm_sha256_duplicate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012c763) */

undefined8 __pfx_libspdm_sha256_duplicate(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = lkca_hash_duplicate(param_2,param_1);
    return uVar1;
  }
  return 0;
}


// ===== 0012c740 libspdm_sha256_duplicate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012c763) */

undefined8 libspdm_sha256_duplicate(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = lkca_hash_duplicate(param_2,param_1);
    return uVar1;
  }
  return 0;
}


// ===== 0012c770 __pfx_libspdm_sha256_update =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012c7a9) */
/* WARNING: Removing unreachable block (ram,0x0012c7ba) */

bool __pfx_libspdm_sha256_update(long param_1,long param_2,ulong param_3)

{
  int iVar1;
  
  if (((param_1 != 0) && (param_2 != 0 || param_3 == 0)) && (param_3 < 0x80000000)) {
    iVar1 = crypto_shash_finup();
    return iVar1 == 0;
  }
  return false;
}


// ===== 0012c780 libspdm_sha256_update =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012c7a9) */
/* WARNING: Removing unreachable block (ram,0x0012c7ba) */

bool libspdm_sha256_update(long param_1,long param_2,ulong param_3)

{
  int iVar1;
  
  if (((param_1 != 0) && (param_2 != 0 || param_3 == 0)) && (param_3 < 0x80000000)) {
    iVar1 = crypto_shash_finup();
    return iVar1 == 0;
  }
  return false;
}


// ===== 0012c7c0 __pfx_libspdm_sha256_final =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012c7f4) */
/* WARNING: Removing unreachable block (ram,0x0012c7fb) */

bool __pfx_libspdm_sha256_final
               (long param_1,long param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6)

{
  int iVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = crypto_shash_finup(param_1,0,0,param_2,param_5,param_6,0x12c7d9);
    return iVar1 == 0;
  }
  return false;
}


// ===== 0012c7d0 libspdm_sha256_final =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012c7f4) */
/* WARNING: Removing unreachable block (ram,0x0012c7fb) */

bool libspdm_sha256_final
               (long param_1,long param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6)

{
  int iVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = crypto_shash_finup(param_1,0,0,param_2,param_5,param_6,0x12c7d9);
    return iVar1 == 0;
  }
  return false;
}


// ===== 0012c800 __pfx_libspdm_sha256_hash_all =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012c839) */

undefined8 __pfx_libspdm_sha256_hash_all(long param_1,ulong param_2,long param_3)

{
  undefined8 uVar1;
  
  if (((param_3 != 0) && (param_1 != 0 || param_2 == 0)) && (param_2 < 0x80000000)) {
    uVar1 = lkca_hash_all("sha256",param_1,param_2,param_3);
    return uVar1;
  }
  return 0;
}


// ===== 0012c810 libspdm_sha256_hash_all =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012c839) */

undefined8 libspdm_sha256_hash_all(long param_1,ulong param_2,long param_3)

{
  undefined8 uVar1;
  
  if (((param_3 != 0) && (param_1 != 0 || param_2 == 0)) && (param_2 < 0x80000000)) {
    uVar1 = lkca_hash_all("sha256",param_1,param_2,param_3);
    return uVar1;
  }
  return 0;
}


// ===== 0012c860 __pfx_libspdm_sha384_new =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_libspdm_sha384_new(void)

{
  lkca_hash_new("sha384");
  return;
}


// ===== 0012c870 libspdm_sha384_new =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void libspdm_sha384_new(void)

{
  lkca_hash_new("sha384");
  return;
}


// ===== 0012c890 __pfx_libspdm_sha384_free =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_libspdm_sha384_free(void)

{
  lkca_hash_free();
  return;
}


// ===== 0012c8a0 libspdm_sha384_free =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void libspdm_sha384_free(void)

{
  lkca_hash_free();
  return;
}


// ===== 0012c8b0 __pfx_libspdm_sha384_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012c8d3) */

bool __pfx_libspdm_sha384_init(void)

{
  int iVar1;
  
  iVar1 = crypto_shash_init();
  return iVar1 == 0;
}


// ===== 0012c8c0 libspdm_sha384_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012c8d3) */

bool libspdm_sha384_init(void)

{
  int iVar1;
  
  iVar1 = crypto_shash_init();
  return iVar1 == 0;
}


// ===== 0012c8e0 __pfx_libspdm_sha384_duplicate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012c913) */

undefined8 __pfx_libspdm_sha384_duplicate(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = lkca_hash_duplicate(param_2,param_1);
    return uVar1;
  }
  return 0;
}


// ===== 0012c8f0 libspdm_sha384_duplicate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012c913) */

undefined8 libspdm_sha384_duplicate(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = lkca_hash_duplicate(param_2,param_1);
    return uVar1;
  }
  return 0;
}


// ===== 0012c920 __pfx_libspdm_sha384_update =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012c959) */
/* WARNING: Removing unreachable block (ram,0x0012c96a) */

bool __pfx_libspdm_sha384_update(long param_1,long param_2,ulong param_3)

{
  int iVar1;
  
  if (((param_1 != 0) && (param_2 != 0 || param_3 == 0)) && (param_3 < 0x80000000)) {
    iVar1 = crypto_shash_finup();
    return iVar1 == 0;
  }
  return false;
}


// ===== 0012c930 libspdm_sha384_update =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012c959) */
/* WARNING: Removing unreachable block (ram,0x0012c96a) */

bool libspdm_sha384_update(long param_1,long param_2,ulong param_3)

{
  int iVar1;
  
  if (((param_1 != 0) && (param_2 != 0 || param_3 == 0)) && (param_3 < 0x80000000)) {
    iVar1 = crypto_shash_finup();
    return iVar1 == 0;
  }
  return false;
}


// ===== 0012c970 __pfx_libspdm_sha384_final =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012c9a4) */
/* WARNING: Removing unreachable block (ram,0x0012c9ab) */

bool __pfx_libspdm_sha384_final
               (long param_1,long param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6)

{
  int iVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = crypto_shash_finup(param_1,0,0,param_2,param_5,param_6,0x12c989);
    return iVar1 == 0;
  }
  return false;
}


// ===== 0012c980 libspdm_sha384_final =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012c9a4) */
/* WARNING: Removing unreachable block (ram,0x0012c9ab) */

bool libspdm_sha384_final
               (long param_1,long param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6)

{
  int iVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = crypto_shash_finup(param_1,0,0,param_2,param_5,param_6,0x12c989);
    return iVar1 == 0;
  }
  return false;
}


// ===== 0012c9b0 __pfx_libspdm_sha384_hash_all =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012c9e9) */

undefined8 __pfx_libspdm_sha384_hash_all(long param_1,ulong param_2,long param_3)

{
  undefined8 uVar1;
  
  if (((param_3 != 0) && (param_1 != 0 || param_2 == 0)) && (param_2 < 0x80000000)) {
    uVar1 = lkca_hash_all("sha384",param_1,param_2,param_3);
    return uVar1;
  }
  return 0;
}


// ===== 0012c9c0 libspdm_sha384_hash_all =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012c9e9) */

undefined8 libspdm_sha384_hash_all(long param_1,ulong param_2,long param_3)

{
  undefined8 uVar1;
  
  if (((param_3 != 0) && (param_1 != 0 || param_2 == 0)) && (param_2 < 0x80000000)) {
    uVar1 = lkca_hash_all("sha384",param_1,param_2,param_3);
    return uVar1;
  }
  return 0;
}


// ===== 0012ca10 __pfx_libspdm_hmac_sha256_new =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_libspdm_hmac_sha256_new(void)

{
  lkca_hash_new("hmac(sha256)");
  return;
}


// ===== 0012ca20 libspdm_hmac_sha256_new =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void libspdm_hmac_sha256_new(void)

{
  lkca_hash_new("hmac(sha256)");
  return;
}


// ===== 0012ca40 __pfx_libspdm_hmac_sha256_free =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_libspdm_hmac_sha256_free(void)

{
  lkca_hash_free();
  return;
}


// ===== 0012ca50 libspdm_hmac_sha256_free =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void libspdm_hmac_sha256_free(void)

{
  lkca_hash_free();
  return;
}


// ===== 0012ca60 __pfx_libspdm_hmac_sha256_set_key =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ca85) */

undefined8 __pfx_libspdm_hmac_sha256_set_key(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 != 0) {
    uVar1 = lkca_hmac_set_key();
    return uVar1;
  }
  return 0;
}


// ===== 0012ca70 libspdm_hmac_sha256_set_key =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ca85) */

undefined8 libspdm_hmac_sha256_set_key(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 != 0) {
    uVar1 = lkca_hmac_set_key();
    return uVar1;
  }
  return 0;
}


// ===== 0012ca90 __pfx_libspdm_hmac_sha256_duplicate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012cac3) */

undefined8 __pfx_libspdm_hmac_sha256_duplicate(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = lkca_hmac_duplicate(param_2,param_1);
    return uVar1;
  }
  return 0;
}


// ===== 0012caa0 libspdm_hmac_sha256_duplicate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012cac3) */

undefined8 libspdm_hmac_sha256_duplicate(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = lkca_hmac_duplicate(param_2,param_1);
    return uVar1;
  }
  return 0;
}


// ===== 0012cad0 __pfx_libspdm_hmac_sha256_update =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012cb09) */
/* WARNING: Removing unreachable block (ram,0x0012cb1a) */

bool __pfx_libspdm_hmac_sha256_update(long param_1,long param_2,ulong param_3)

{
  int iVar1;
  
  if (((param_1 != 0) && (param_2 != 0 || param_3 == 0)) && (param_3 < 0x80000000)) {
    iVar1 = crypto_shash_finup();
    return iVar1 == 0;
  }
  return false;
}


// ===== 0012cae0 libspdm_hmac_sha256_update =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012cb09) */
/* WARNING: Removing unreachable block (ram,0x0012cb1a) */

bool libspdm_hmac_sha256_update(long param_1,long param_2,ulong param_3)

{
  int iVar1;
  
  if (((param_1 != 0) && (param_2 != 0 || param_3 == 0)) && (param_3 < 0x80000000)) {
    iVar1 = crypto_shash_finup();
    return iVar1 == 0;
  }
  return false;
}


// ===== 0012cb20 __pfx_libspdm_hmac_sha256_final =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012cb54) */
/* WARNING: Removing unreachable block (ram,0x0012cb5b) */

bool __pfx_libspdm_hmac_sha256_final
               (long param_1,long param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6)

{
  int iVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = crypto_shash_finup(param_1,0,0,param_2,param_5,param_6,0x12cb39);
    return iVar1 == 0;
  }
  return false;
}


// ===== 0012cb30 libspdm_hmac_sha256_final =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012cb54) */
/* WARNING: Removing unreachable block (ram,0x0012cb5b) */

bool libspdm_hmac_sha256_final
               (long param_1,long param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6)

{
  int iVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = crypto_shash_finup(param_1,0,0,param_2,param_5,param_6,0x12cb39);
    return iVar1 == 0;
  }
  return false;
}


// ===== 0012cb60 __pfx_libspdm_hmac_sha256_all =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012cb9c) */

undefined8
__pfx_libspdm_hmac_sha256_all
          (long param_1,ulong param_2,undefined8 param_3,undefined8 param_4,long param_5)

{
  undefined8 uVar1;
  
  if (((param_5 != 0) && (param_1 != 0 || param_2 == 0)) && (param_2 < 0x80000000)) {
    uVar1 = lkca_hmac_all("hmac(sha256)",param_3,param_4,param_1,param_2,param_5);
    return uVar1;
  }
  return 0;
}


// ===== 0012cb70 libspdm_hmac_sha256_all =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012cb9c) */

undefined8
libspdm_hmac_sha256_all
          (long param_1,ulong param_2,undefined8 param_3,undefined8 param_4,long param_5)

{
  undefined8 uVar1;
  
  if (((param_5 != 0) && (param_1 != 0 || param_2 == 0)) && (param_2 < 0x80000000)) {
    uVar1 = lkca_hmac_all("hmac(sha256)",param_3,param_4,param_1,param_2,param_5);
    return uVar1;
  }
  return 0;
}


// ===== 0012cbc0 __pfx_libspdm_hmac_sha384_new =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_libspdm_hmac_sha384_new(void)

{
  lkca_hash_new("hmac(sha384)");
  return;
}


// ===== 0012cbd0 libspdm_hmac_sha384_new =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void libspdm_hmac_sha384_new(void)

{
  lkca_hash_new("hmac(sha384)");
  return;
}


// ===== 0012cbf0 __pfx_libspdm_hmac_sha384_free =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_libspdm_hmac_sha384_free(void)

{
  lkca_hash_free();
  return;
}


// ===== 0012cc00 libspdm_hmac_sha384_free =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void libspdm_hmac_sha384_free(void)

{
  lkca_hash_free();
  return;
}


// ===== 0012cc10 __pfx_libspdm_hmac_sha384_set_key =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012cc35) */

undefined8 __pfx_libspdm_hmac_sha384_set_key(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 != 0) {
    uVar1 = lkca_hmac_set_key();
    return uVar1;
  }
  return 0;
}


// ===== 0012cc20 libspdm_hmac_sha384_set_key =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012cc35) */

undefined8 libspdm_hmac_sha384_set_key(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 != 0) {
    uVar1 = lkca_hmac_set_key();
    return uVar1;
  }
  return 0;
}


// ===== 0012cc40 __pfx_libspdm_hmac_sha384_duplicate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012cc73) */

undefined8 __pfx_libspdm_hmac_sha384_duplicate(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = lkca_hmac_duplicate(param_2,param_1);
    return uVar1;
  }
  return 0;
}


// ===== 0012cc50 libspdm_hmac_sha384_duplicate =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012cc73) */

undefined8 libspdm_hmac_sha384_duplicate(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = lkca_hmac_duplicate(param_2,param_1);
    return uVar1;
  }
  return 0;
}


// ===== 0012cc80 __pfx_libspdm_hmac_sha384_update =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ccb9) */
/* WARNING: Removing unreachable block (ram,0x0012ccca) */

bool __pfx_libspdm_hmac_sha384_update(long param_1,long param_2,ulong param_3)

{
  int iVar1;
  
  if (((param_1 != 0) && (param_2 != 0 || param_3 == 0)) && (param_3 < 0x80000000)) {
    iVar1 = crypto_shash_finup();
    return iVar1 == 0;
  }
  return false;
}


// ===== 0012cc90 libspdm_hmac_sha384_update =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ccb9) */
/* WARNING: Removing unreachable block (ram,0x0012ccca) */

bool libspdm_hmac_sha384_update(long param_1,long param_2,ulong param_3)

{
  int iVar1;
  
  if (((param_1 != 0) && (param_2 != 0 || param_3 == 0)) && (param_3 < 0x80000000)) {
    iVar1 = crypto_shash_finup();
    return iVar1 == 0;
  }
  return false;
}


// ===== 0012ccd0 __pfx_libspdm_hmac_sha384_final =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012cd04) */
/* WARNING: Removing unreachable block (ram,0x0012cd0b) */

bool __pfx_libspdm_hmac_sha384_final
               (long param_1,long param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6)

{
  int iVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = crypto_shash_finup(param_1,0,0,param_2,param_5,param_6,0x12cce9);
    return iVar1 == 0;
  }
  return false;
}


// ===== 0012cce0 libspdm_hmac_sha384_final =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012cd04) */
/* WARNING: Removing unreachable block (ram,0x0012cd0b) */

bool libspdm_hmac_sha384_final
               (long param_1,long param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6)

{
  int iVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = crypto_shash_finup(param_1,0,0,param_2,param_5,param_6,0x12cce9);
    return iVar1 == 0;
  }
  return false;
}


// ===== 0012cd10 __pfx_libspdm_hmac_sha384_all =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012cd4c) */

undefined8
__pfx_libspdm_hmac_sha384_all
          (long param_1,ulong param_2,undefined8 param_3,undefined8 param_4,long param_5)

{
  undefined8 uVar1;
  
  if (((param_5 != 0) && (param_1 != 0 || param_2 == 0)) && (param_2 < 0x80000000)) {
    uVar1 = lkca_hmac_all("hmac(sha384)",param_3,param_4,param_1,param_2,param_5);
    return uVar1;
  }
  return 0;
}


// ===== 0012cd20 libspdm_hmac_sha384_all =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012cd4c) */

undefined8
libspdm_hmac_sha384_all
          (long param_1,ulong param_2,undefined8 param_3,undefined8 param_4,long param_5)

{
  undefined8 uVar1;
  
  if (((param_5 != 0) && (param_1 != 0 || param_2 == 0)) && (param_2 < 0x80000000)) {
    uVar1 = lkca_hmac_all("hmac(sha384)",param_3,param_4,param_1,param_2,param_5);
    return uVar1;
  }
  return 0;
}


// ===== 0012cd70 __pfx_libspdm_check_crypto_backend =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012cdaa) */

undefined8 __pfx_libspdm_check_crypto_backend(void)

{
  nv_printf(0,"libspdm_check_crypto_backend: LKCA wrappers found.\n");
  nv_printf(0,
            "libspdm_check_crypto_backend: LKCA calls may still fail if modules have not been loaded!\n"
           );
  return 1;
}


// ===== 0012cd80 libspdm_check_crypto_backend =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012cdaa) */

undefined8 libspdm_check_crypto_backend(void)

{
  nv_printf(0,"libspdm_check_crypto_backend: LKCA wrappers found.\n");
  nv_printf(0,
            "libspdm_check_crypto_backend: LKCA calls may still fail if modules have not been loaded!\n"
           );
  return 1;
}


// ===== 0012cdb0 __pfx_libspdm_hkdf_sha256_extract =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012cdd1) */

undefined8 __pfx_libspdm_hkdf_sha256_extract(void)

{
  undefined8 uVar1;
  long in_R9;
  
  if (in_R9 != 0x20) {
    return 0;
  }
  uVar1 = libspdm_hmac_sha256_all();
  return uVar1;
}


// ===== 0012cdc0 libspdm_hkdf_sha256_extract =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012cdd1) */

undefined8 libspdm_hkdf_sha256_extract(void)

{
  undefined8 uVar1;
  long in_R9;
  
  if (in_R9 != 0x20) {
    return 0;
  }
  uVar1 = libspdm_hmac_sha256_all();
  return uVar1;
}


// ===== 0012cde0 __pfx_libspdm_hkdf_sha256_expand =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ce17) */

void __pfx_libspdm_hkdf_sha256_expand
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  lkca_hkdf_expand("hmac(sha256)",param_1,param_2,param_3,param_4,param_5,param_6,0x12cdf9);
  return;
}


// ===== 0012cdf0 libspdm_hkdf_sha256_expand =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ce17) */

void libspdm_hkdf_sha256_expand
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  lkca_hkdf_expand("hmac(sha256)",param_1,param_2,param_3,param_4,param_5,param_6,0x12cdf9);
  return;
}


// ===== 0012ce20 __pfx_libspdm_hkdf_sha384_extract =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ce41) */

undefined8 __pfx_libspdm_hkdf_sha384_extract(void)

{
  undefined8 uVar1;
  long in_R9;
  
  if (in_R9 != 0x30) {
    return 0;
  }
  uVar1 = libspdm_hmac_sha384_all();
  return uVar1;
}


// ===== 0012ce30 libspdm_hkdf_sha384_extract =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ce41) */

undefined8 libspdm_hkdf_sha384_extract(void)

{
  undefined8 uVar1;
  long in_R9;
  
  if (in_R9 != 0x30) {
    return 0;
  }
  uVar1 = libspdm_hmac_sha384_all();
  return uVar1;
}


// ===== 0012ce50 __pfx_libspdm_hkdf_sha384_expand =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ce87) */

void __pfx_libspdm_hkdf_sha384_expand
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  lkca_hkdf_expand("hmac(sha384)",param_1,param_2,param_3,param_4,param_5,param_6,0x12ce69);
  return;
}


// ===== 0012ce60 libspdm_hkdf_sha384_expand =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012ce87) */

void libspdm_hkdf_sha384_expand
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  lkca_hkdf_expand("hmac(sha384)",param_1,param_2,param_3,param_4,param_5,param_6,0x12ce69);
  return;
}


// ===== 0012ce90 __pfx_libspdm_ec_generate_key =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012cecb) */

undefined8 __pfx_libspdm_ec_generate_key(long param_1,long param_2,long *param_3)

{
  undefined8 uVar1;
  
  if ((param_1 != 0 && param_3 != (long *)0x0) && ((param_2 != 0 || (*param_3 == 0)))) {
    uVar1 = lkca_ec_generate_key();
    return uVar1;
  }
  return 0;
}


// ===== 0012cea0 libspdm_ec_generate_key =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012cecb) */

undefined8 libspdm_ec_generate_key(long param_1,long param_2,long *param_3)

{
  undefined8 uVar1;
  
  if ((param_1 != 0 && param_3 != (long *)0x0) && ((param_2 != 0 || (*param_3 == 0)))) {
    uVar1 = lkca_ec_generate_key();
    return uVar1;
  }
  return 0;
}


// ===== 0012ced0 __pfx_libspdm_ec_compute_key =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012cf1f) */

undefined8
__pfx_libspdm_ec_compute_key(long param_1,long param_2,ulong param_3,long param_4,long param_5)

{
  undefined8 uVar1;
  
  if (((param_1 != 0 && param_2 != 0) && (param_5 != 0 && param_4 != 0)) && (param_3 < 0x80000000))
  {
    uVar1 = lkca_ec_compute_key(param_1,param_2,param_3);
    return uVar1;
  }
  return 0;
}


// ===== 0012cee0 libspdm_ec_compute_key =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012cf1f) */

undefined8 libspdm_ec_compute_key(long param_1,long param_2,ulong param_3,long param_4,long param_5)

{
  undefined8 uVar1;
  
  if (((param_1 != 0 && param_2 != 0) && (param_5 != 0 && param_4 != 0)) && (param_3 < 0x80000000))
  {
    uVar1 = lkca_ec_compute_key(param_1,param_2,param_3);
    return uVar1;
  }
  return 0;
}


// ===== 0012cf30 __pfx_libspdm_ecdsa_sign =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012cf4b) */

undefined8 __pfx_libspdm_ecdsa_sign(void)

{
  return 0;
}


// ===== 0012cf40 libspdm_ecdsa_sign =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012cf4b) */

undefined8 libspdm_ecdsa_sign(void)

{
  return 0;
}


// ===== 0012cf50 __pfx_libspdm_ecdsa_verify =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012cfaa) */

undefined8
__pfx_libspdm_ecdsa_verify
          (long param_1,long param_2,long param_3,long param_4,long param_5,long param_6)

{
  undefined8 uVar1;
  
  if (((param_1 != 0 && param_3 != 0) && param_5 != 0) && (param_6 - 1U < 0x7fffffff)) {
    if (param_2 == 2) {
      if (param_4 == 0x30) goto LAB_0012cfb5;
    }
    else if (param_2 == 3) {
      if (param_4 == 0x40) goto LAB_0012cfb5;
    }
    else if ((param_2 == 1) && (param_4 == 0x20)) {
LAB_0012cfb5:
      uVar1 = lkca_ecdsa_verify();
      return uVar1;
    }
  }
  return 0;
}


// ===== 0012cf60 libspdm_ecdsa_verify =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012cfaa) */

undefined8
libspdm_ecdsa_verify(long param_1,long param_2,long param_3,long param_4,long param_5,long param_6)

{
  undefined8 uVar1;
  
  if (((param_1 != 0 && param_3 != 0) && param_5 != 0) && (param_6 - 1U < 0x7fffffff)) {
    if (param_2 == 2) {
      if (param_4 == 0x30) goto LAB_0012cfb5;
    }
    else if (param_2 == 3) {
      if (param_4 == 0x40) goto LAB_0012cfb5;
    }
    else if ((param_2 == 1) && (param_4 == 0x20)) {
LAB_0012cfb5:
      uVar1 = lkca_ecdsa_verify();
      return uVar1;
    }
  }
  return 0;
}


// ===== 0012cfd0 __pfx_lkca_x509_verify_cert =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012d0f9) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __pfx_lkca_x509_verify_cert
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  int iVar2;
  ulong uVar4;
  long in_GS_OFFSET;
  undefined8 auStack_b8 [10];
  undefined8 auStack_68 [10];
  long lStack_18;
  ulong uVar3;
  
  lStack_18 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uVar4 = 0;
  do {
    uVar1 = (int)uVar4 + 0x20;
    uVar3 = (ulong)uVar1;
    *(undefined8 *)((long)auStack_b8 + uVar4) = 0;
    *(undefined8 *)((long)auStack_b8 + uVar4 + 8) = 0;
    *(undefined8 *)((long)auStack_b8 + uVar4 + 0x10) = 0;
    *(undefined8 *)((long)auStack_b8 + uVar4 + 0x18) = 0;
    uVar4 = uVar3;
  } while (uVar1 < 0x40);
  *(undefined8 *)((long)auStack_b8 + uVar3) = 0;
  *(undefined8 *)((long)auStack_b8 + uVar3 + 8) = 0;
  uVar4 = 0;
  do {
    uVar1 = (int)uVar4 + 0x20;
    uVar3 = (ulong)uVar1;
    *(undefined8 *)((long)auStack_68 + uVar4) = 0;
    *(undefined8 *)((long)auStack_68 + uVar4 + 8) = 0;
    *(undefined8 *)((long)auStack_68 + uVar4 + 0x10) = 0;
    *(undefined8 *)((long)auStack_68 + uVar4 + 0x18) = 0;
    uVar4 = uVar3;
  } while (uVar1 < 0x40);
  *(undefined8 *)((long)auStack_68 + uVar3) = 0;
  *(undefined8 *)((long)auStack_68 + uVar3 + 8) = 0;
  auStack_b8[6] = param_1;
  auStack_b8[7] = param_2;
  auStack_68[6] = param_3;
  auStack_68[7] = param_4;
  iVar2 = (*_pci_find_host_bridge)(auStack_b8);
  if (iVar2 == 0) {
    iVar2 = (*_pci_find_host_bridge)(auStack_68);
    if (iVar2 == 0) {
      iVar2 = public_key_verify_signature(auStack_68[2],auStack_b8[5]);
      (*_cc_mkdec)(auStack_b8);
      (*_cc_mkdec)(auStack_68);
    }
    else {
      (*_cc_mkdec)(auStack_b8);
    }
  }
  if (lStack_18 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0012cfe0 lkca_x509_verify_cert =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012d0f9) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int lkca_x509_verify_cert
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  int iVar2;
  ulong uVar4;
  long in_GS_OFFSET;
  undefined8 local_b8 [10];
  undefined8 local_68 [10];
  long local_18;
  ulong uVar3;
  
  local_18 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uVar4 = 0;
  do {
    uVar1 = (int)uVar4 + 0x20;
    uVar3 = (ulong)uVar1;
    *(undefined8 *)((long)local_b8 + uVar4) = 0;
    *(undefined8 *)((long)local_b8 + uVar4 + 8) = 0;
    *(undefined8 *)((long)local_b8 + uVar4 + 0x10) = 0;
    *(undefined8 *)((long)local_b8 + uVar4 + 0x18) = 0;
    uVar4 = uVar3;
  } while (uVar1 < 0x40);
  *(undefined8 *)((long)local_b8 + uVar3) = 0;
  *(undefined8 *)((long)local_b8 + uVar3 + 8) = 0;
  uVar4 = 0;
  do {
    uVar1 = (int)uVar4 + 0x20;
    uVar3 = (ulong)uVar1;
    *(undefined8 *)((long)local_68 + uVar4) = 0;
    *(undefined8 *)((long)local_68 + uVar4 + 8) = 0;
    *(undefined8 *)((long)local_68 + uVar4 + 0x10) = 0;
    *(undefined8 *)((long)local_68 + uVar4 + 0x18) = 0;
    uVar4 = uVar3;
  } while (uVar1 < 0x40);
  *(undefined8 *)((long)local_68 + uVar3) = 0;
  *(undefined8 *)((long)local_68 + uVar3 + 8) = 0;
  local_b8[6] = param_1;
  local_b8[7] = param_2;
  local_68[6] = param_3;
  local_68[7] = param_4;
  iVar2 = (*_pci_find_host_bridge)(local_b8);
  if (iVar2 == 0) {
    iVar2 = (*_pci_find_host_bridge)(local_68);
    if (iVar2 == 0) {
      iVar2 = public_key_verify_signature(local_68[2],local_b8[5]);
      (*_cc_mkdec)(local_b8);
      (*_cc_mkdec)(local_68);
    }
    else {
      (*_cc_mkdec)(local_b8);
    }
  }
  if (local_18 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0012d140 __pfx_libspdm_encode_base64 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012d1fe) */
/* WARNING: Removing unreachable block (ram,0x0012d229) */

undefined8 __pfx_libspdm_encode_base64(long param_1,char *param_2,ulong param_3,undefined8 *param_4)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  undefined1 uVar4;
  ushort uVar5;
  uint uVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  uint uVar10;
  char *pcVar11;
  char *pcVar12;
  
  if (param_3 < 3) {
    pcVar11 = (char *)0x0;
    lVar7 = 0;
    pcVar12 = param_2;
  }
  else {
    lVar9 = 0;
    pcVar11 = param_2;
    do {
      if ((char *)*param_4 < pcVar11 + (4 - (long)param_2)) goto LAB_0012d1f4;
      pcVar12 = pcVar11 + 4;
      uVar6 = (uint)*(byte *)(param_1 + lVar9) << 0x10 | (uint)*(byte *)(param_1 + 1 + lVar9) << 8;
      uVar10 = (uint)*(byte *)(param_1 + 2 + lVar9);
      cVar1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[uVar10 & 0x3f];
      *pcVar11 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                 [*(byte *)(param_1 + lVar9) >> 2];
      cVar2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
              [uVar6 >> 0xc & 0x3f];
      pcVar11[2] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                   [(uVar6 | uVar10) >> 6 & 0x3f];
      pcVar11[1] = cVar2;
      pcVar11[3] = cVar1;
      lVar7 = lVar9 + 3;
      uVar8 = lVar9 + 5;
      lVar9 = lVar7;
      pcVar11 = pcVar12;
    } while (uVar8 < param_3);
    pcVar11 = pcVar12 + -(long)param_2;
  }
  if (param_3 - 1 == lVar7) {
    if ((char *)*param_4 < pcVar11 + 4) goto LAB_0012d1f4;
    cVar1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
            [*(byte *)(param_1 + lVar7) >> 2];
    pcVar12[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                 [(*(byte *)(param_1 + lVar7) & 3) << 4];
    pcVar12[2] = '=';
    pcVar12[3] = '=';
    *pcVar12 = cVar1;
    pcVar11 = pcVar12 + (4 - (long)param_2);
    pcVar12 = pcVar12 + 4;
  }
  if (param_3 - 2 == lVar7) {
    if ((char *)*param_4 < pcVar11 + 4) {
LAB_0012d1f4:
      *param_4 = 0;
      return 0;
    }
    bVar3 = *(byte *)(param_1 + lVar7);
    uVar4 = *(undefined1 *)(param_1 + 1 + lVar7);
    pcVar12[3] = '=';
    uVar5 = CONCAT11(bVar3,uVar4);
    cVar1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[uVar5 >> 4 & 0x3f];
    cVar2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[bVar3 >> 2];
    pcVar12[2] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                 [(uVar5 & 0xf) << 2];
    pcVar11 = pcVar12 + (4 - (long)param_2);
    pcVar12[1] = cVar1;
    *pcVar12 = cVar2;
  }
  *param_4 = pcVar11;
  return 1;
}


// ===== 0012d150 libspdm_encode_base64 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012d1fe) */
/* WARNING: Removing unreachable block (ram,0x0012d229) */

undefined8 libspdm_encode_base64(long param_1,char *param_2,ulong param_3,undefined8 *param_4)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  undefined1 uVar4;
  ushort uVar5;
  uint uVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  uint uVar10;
  char *pcVar11;
  char *pcVar12;
  
  if (param_3 < 3) {
    pcVar11 = (char *)0x0;
    lVar7 = 0;
    pcVar12 = param_2;
  }
  else {
    lVar9 = 0;
    pcVar11 = param_2;
    do {
      if ((char *)*param_4 < pcVar11 + (4 - (long)param_2)) goto LAB_0012d1f4;
      pcVar12 = pcVar11 + 4;
      uVar6 = (uint)*(byte *)(param_1 + lVar9) << 0x10 | (uint)*(byte *)(param_1 + 1 + lVar9) << 8;
      uVar10 = (uint)*(byte *)(param_1 + 2 + lVar9);
      cVar1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[uVar10 & 0x3f];
      *pcVar11 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                 [*(byte *)(param_1 + lVar9) >> 2];
      cVar2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
              [uVar6 >> 0xc & 0x3f];
      pcVar11[2] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                   [(uVar6 | uVar10) >> 6 & 0x3f];
      pcVar11[1] = cVar2;
      pcVar11[3] = cVar1;
      lVar7 = lVar9 + 3;
      uVar8 = lVar9 + 5;
      lVar9 = lVar7;
      pcVar11 = pcVar12;
    } while (uVar8 < param_3);
    pcVar11 = pcVar12 + -(long)param_2;
  }
  if (param_3 - 1 == lVar7) {
    if ((char *)*param_4 < pcVar11 + 4) goto LAB_0012d1f4;
    cVar1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
            [*(byte *)(param_1 + lVar7) >> 2];
    pcVar12[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                 [(*(byte *)(param_1 + lVar7) & 3) << 4];
    pcVar12[2] = '=';
    pcVar12[3] = '=';
    *pcVar12 = cVar1;
    pcVar11 = pcVar12 + (4 - (long)param_2);
    pcVar12 = pcVar12 + 4;
  }
  if (param_3 - 2 == lVar7) {
    if ((char *)*param_4 < pcVar11 + 4) {
LAB_0012d1f4:
      *param_4 = 0;
      return 0;
    }
    bVar3 = *(byte *)(param_1 + lVar7);
    uVar4 = *(undefined1 *)(param_1 + 1 + lVar7);
    pcVar12[3] = '=';
    uVar5 = CONCAT11(bVar3,uVar4);
    cVar1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[uVar5 >> 4 & 0x3f];
    cVar2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[bVar3 >> 2];
    pcVar12[2] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                 [(uVar5 & 0xf) << 2];
    pcVar11 = pcVar12 + (4 - (long)param_2);
    pcVar12[1] = cVar1;
    *pcVar12 = cVar2;
  }
  *param_4 = pcVar11;
  return 1;
}


// ===== 0012d2f0 __pfx_libspdm_decode_base64 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012d549) */
/* WARNING: Type propagation algorithm not settling */

ulong __pfx_libspdm_decode_base64(char *param_1,long param_2,ulong param_3,long *param_4)

{
  char cVar1;
  undefined1 uVar2;
  byte bVar3;
  uint uVar4;
  ulong uVar5;
  ulong uVar6;
  uint uVar7;
  bool bVar8;
  long lVar9;
  long lVar10;
  undefined1 *puVar11;
  ulong uVar12;
  char *pcVar13;
  char *pcVar14;
  char *pcVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  char *pcVar18;
  undefined1 *puVar19;
  byte bVar20;
  undefined1 *puVar21;
  
  if (param_3 == 0) {
    puVar21 = (undefined1 *)0x0;
  }
  else {
    puVar21 = (undefined1 *)0x0;
    uVar5 = 0;
    pcVar15 = param_1;
    do {
      uVar6 = uVar5 + 0x41;
      if (uVar6 < param_3) {
        lVar9 = 0x3f;
        lVar10 = 0x30;
        uVar12 = 0x40;
      }
      else {
        uVar12 = (param_3 + 0x40) - uVar6;
        lVar10 = (uVar12 >> 2) * 3;
        lVar9 = (param_3 + 0x3f) - uVar6;
      }
      lVar10 = lVar10 - (ulong)(param_1[lVar9] == '=');
      puVar11 = (undefined1 *)(lVar10 - (ulong)(param_1[lVar10 + -2] == '='));
      lVar10 = *param_4;
      if ((undefined1 *)(lVar10 - (long)puVar21) < puVar11) {
        if (uVar5 < param_3) {
          *param_4 = 0;
          return 0;
        }
        break;
      }
      puVar19 = puVar21 + param_2;
      bVar8 = puVar19 == (undefined1 *)0x0 || pcVar15 == (char *)0x0;
      if (bVar8) {
        return 0;
      }
      if ((uVar12 & 3) != 0) {
LAB_0012d521:
        return CONCAT71((int7)((ulong)(lVar10 - (long)puVar21) >> 8),bVar8) & 0xffffffff;
      }
      pcVar14 = param_1 + uVar5 + 4;
      puVar16 = puVar19;
      pcVar18 = pcVar15;
      if (pcVar15 < pcVar15 + uVar12) {
        do {
          uVar7 = 0;
          bVar20 = 3;
          pcVar13 = pcVar18;
          do {
            cVar1 = *pcVar13;
            bVar3 = cVar1 + 0xbf;
            if (bVar3 < 0x1a) {
LAB_0012d4d7:
              uVar4 = (uint)(char)bVar3;
LAB_0012d428:
              uVar7 = uVar7 << 6 | uVar4;
            }
            else {
              if ((byte)(cVar1 + 0x9fU) < 0x1a) {
                uVar4 = (uint)(char)(cVar1 + -0x47);
                goto LAB_0012d428;
              }
              if ((byte)(cVar1 - 0x30U) < 10) {
                bVar3 = cVar1 + 4;
                goto LAB_0012d4d7;
              }
              if (cVar1 != '=') {
                if ((cVar1 - 0x2bU & 0xfd) == 0) {
                  uVar4 = 0x3e;
                }
                else {
                  if (cVar1 != '_' && cVar1 != '/') {
                    return 0;
                  }
                  uVar4 = 0x3f;
                }
                goto LAB_0012d428;
              }
              bVar20 = bVar20 - 1;
              uVar7 = uVar7 << 6;
            }
            pcVar13 = pcVar13 + 1;
          } while (pcVar13 != pcVar14);
          if (puVar11 < puVar16 + ((ulong)bVar20 - (long)puVar19)) goto LAB_0012d521;
          uVar2 = (undefined1)(uVar7 >> 0x10);
          if (bVar20 == 2) {
            *puVar16 = uVar2;
            puVar17 = puVar16 + 2;
            puVar16[1] = (char)(uVar7 >> 8);
          }
          else if (bVar20 == 3) {
            puVar17 = puVar16 + 3;
            *(ushort *)(puVar16 + 1) = (ushort)uVar7 << 8 | (ushort)uVar7 >> 8;
            *puVar16 = uVar2;
          }
          else {
            if (bVar20 != 1) goto LAB_0012d521;
            puVar17 = puVar16 + 1;
            *puVar16 = uVar2;
          }
          pcVar18 = pcVar18 + 4;
          pcVar14 = pcVar14 + 4;
          puVar16 = puVar17;
        } while (pcVar18 < pcVar15 + uVar12);
        puVar21 = puVar17 + ((long)puVar21 - (long)puVar19);
      }
      pcVar15 = pcVar15 + 0x41;
      uVar5 = uVar6;
    } while (uVar6 < param_3);
  }
  *param_4 = (long)puVar21;
  return 1;
}


// ===== 0012d300 libspdm_decode_base64 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012d549) */
/* WARNING: Type propagation algorithm not settling */

ulong libspdm_decode_base64(char *param_1,long param_2,ulong param_3,long *param_4)

{
  char cVar1;
  undefined1 uVar2;
  byte bVar3;
  uint uVar4;
  ulong uVar5;
  ulong uVar6;
  uint uVar7;
  bool bVar8;
  long lVar9;
  long lVar10;
  undefined1 *puVar11;
  ulong uVar12;
  char *pcVar13;
  char *pcVar14;
  char *pcVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  char *pcVar18;
  undefined1 *puVar19;
  byte bVar20;
  undefined1 *puVar21;
  
  if (param_3 == 0) {
    puVar21 = (undefined1 *)0x0;
  }
  else {
    puVar21 = (undefined1 *)0x0;
    uVar5 = 0;
    pcVar15 = param_1;
    do {
      uVar6 = uVar5 + 0x41;
      if (uVar6 < param_3) {
        lVar9 = 0x3f;
        lVar10 = 0x30;
        uVar12 = 0x40;
      }
      else {
        uVar12 = (param_3 + 0x40) - uVar6;
        lVar10 = (uVar12 >> 2) * 3;
        lVar9 = (param_3 + 0x3f) - uVar6;
      }
      lVar10 = lVar10 - (ulong)(param_1[lVar9] == '=');
      puVar11 = (undefined1 *)(lVar10 - (ulong)(param_1[lVar10 + -2] == '='));
      lVar10 = *param_4;
      if ((undefined1 *)(lVar10 - (long)puVar21) < puVar11) {
        if (uVar5 < param_3) {
          *param_4 = 0;
          return 0;
        }
        break;
      }
      puVar19 = puVar21 + param_2;
      bVar8 = puVar19 == (undefined1 *)0x0 || pcVar15 == (char *)0x0;
      if (bVar8) {
        return 0;
      }
      if ((uVar12 & 3) != 0) {
LAB_0012d521:
        return CONCAT71((int7)((ulong)(lVar10 - (long)puVar21) >> 8),bVar8) & 0xffffffff;
      }
      pcVar14 = param_1 + uVar5 + 4;
      puVar16 = puVar19;
      pcVar18 = pcVar15;
      if (pcVar15 < pcVar15 + uVar12) {
        do {
          uVar7 = 0;
          bVar20 = 3;
          pcVar13 = pcVar18;
          do {
            cVar1 = *pcVar13;
            bVar3 = cVar1 + 0xbf;
            if (bVar3 < 0x1a) {
LAB_0012d4d7:
              uVar4 = (uint)(char)bVar3;
LAB_0012d428:
              uVar7 = uVar7 << 6 | uVar4;
            }
            else {
              if ((byte)(cVar1 + 0x9fU) < 0x1a) {
                uVar4 = (uint)(char)(cVar1 + -0x47);
                goto LAB_0012d428;
              }
              if ((byte)(cVar1 - 0x30U) < 10) {
                bVar3 = cVar1 + 4;
                goto LAB_0012d4d7;
              }
              if (cVar1 != '=') {
                if ((cVar1 - 0x2bU & 0xfd) == 0) {
                  uVar4 = 0x3e;
                }
                else {
                  if (cVar1 != '_' && cVar1 != '/') {
                    return 0;
                  }
                  uVar4 = 0x3f;
                }
                goto LAB_0012d428;
              }
              bVar20 = bVar20 - 1;
              uVar7 = uVar7 << 6;
            }
            pcVar13 = pcVar13 + 1;
          } while (pcVar13 != pcVar14);
          if (puVar11 < puVar16 + ((ulong)bVar20 - (long)puVar19)) goto LAB_0012d521;
          uVar2 = (undefined1)(uVar7 >> 0x10);
          if (bVar20 == 2) {
            *puVar16 = uVar2;
            puVar17 = puVar16 + 2;
            puVar16[1] = (char)(uVar7 >> 8);
          }
          else if (bVar20 == 3) {
            puVar17 = puVar16 + 3;
            *(ushort *)(puVar16 + 1) = (ushort)uVar7 << 8 | (ushort)uVar7 >> 8;
            *puVar16 = uVar2;
          }
          else {
            if (bVar20 != 1) goto LAB_0012d521;
            puVar17 = puVar16 + 1;
            *puVar16 = uVar2;
          }
          pcVar18 = pcVar18 + 4;
          pcVar14 = pcVar14 + 4;
          puVar16 = puVar17;
        } while (pcVar18 < pcVar15 + uVar12);
        puVar21 = puVar17 + ((long)puVar21 - (long)puVar19);
      }
      pcVar15 = pcVar15 + 0x41;
      uVar5 = uVar6;
    } while (uVar6 < param_3);
  }
  *param_4 = (long)puVar21;
  return 1;
}


// ===== 0012d5e0 __pfx_libspdm_asn1_get_tag =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012d618) */
/* WARNING: Removing unreachable block (ram,0x0012d634) */

undefined8
__pfx_libspdm_asn1_get_tag(undefined8 *param_1,long param_2,undefined8 *param_3,uint param_4)

{
  byte *pbVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  
  pbVar3 = (byte *)*param_1;
  pbVar5 = (byte *)(param_2 - (long)pbVar3);
  if ((byte *)0x3ffffffe < pbVar5 + -2) {
    return 0;
  }
  if (param_4 != *pbVar3) {
    return 0;
  }
  bVar2 = pbVar3[1];
  if ((char)bVar2 < '\0') {
    if (bVar2 == 0x81) {
      if (pbVar5 != (byte *)0x2) {
        pbVar3 = (byte *)(ulong)pbVar3[2];
        pbVar4 = pbVar3 + 3;
        goto LAB_0012d62b;
      }
    }
    else if ((bVar2 == 0x82) && ((byte *)0x3 < pbVar5)) {
      pbVar4 = pbVar3 + 2;
      pbVar1 = pbVar3 + 3;
      pbVar3 = (byte *)0x0;
      pbVar4 = (byte *)(ulong)((uint)*pbVar4 * 0x100 + 4 + (uint)*pbVar1);
      goto LAB_0012d62b;
    }
    return 0;
  }
  pbVar4 = (byte *)(ulong)(byte)(bVar2 + 2);
LAB_0012d62b:
  *param_3 = pbVar4;
  return CONCAT71((int7)((ulong)pbVar3 >> 8),pbVar4 <= pbVar5);
}


// ===== 0012d5f0 libspdm_asn1_get_tag =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012d618) */
/* WARNING: Removing unreachable block (ram,0x0012d634) */

undefined8 libspdm_asn1_get_tag(undefined8 *param_1,long param_2,undefined8 *param_3,uint param_4)

{
  byte *pbVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  
  pbVar3 = (byte *)*param_1;
  pbVar5 = (byte *)(param_2 - (long)pbVar3);
  if ((byte *)0x3ffffffe < pbVar5 + -2) {
    return 0;
  }
  if (param_4 != *pbVar3) {
    return 0;
  }
  bVar2 = pbVar3[1];
  if ((char)bVar2 < '\0') {
    if (bVar2 == 0x81) {
      if (pbVar5 != (byte *)0x2) {
        pbVar3 = (byte *)(ulong)pbVar3[2];
        pbVar4 = pbVar3 + 3;
        goto LAB_0012d62b;
      }
    }
    else if ((bVar2 == 0x82) && ((byte *)0x3 < pbVar5)) {
      pbVar4 = pbVar3 + 2;
      pbVar1 = pbVar3 + 3;
      pbVar3 = (byte *)0x0;
      pbVar4 = (byte *)(ulong)((uint)*pbVar4 * 0x100 + 4 + (uint)*pbVar1);
      goto LAB_0012d62b;
    }
    return 0;
  }
  pbVar4 = (byte *)(ulong)(byte)(bVar2 + 2);
LAB_0012d62b:
  *param_3 = pbVar4;
  return CONCAT71((int7)((ulong)pbVar3 >> 8),pbVar4 <= pbVar5);
}


// ===== 0012d670 __pfx_libspdm_x509_get_subject_name =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012d68b) */

undefined8 __pfx_libspdm_x509_get_subject_name(void)

{
  return 0;
}


// ===== 0012d680 libspdm_x509_get_subject_name =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012d68b) */

undefined8 libspdm_x509_get_subject_name(void)

{
  return 0;
}


// ===== 0012d690 __pfx_libspdm_rsa_get_public_key_from_x509 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012d6ab) */

undefined8 __pfx_libspdm_rsa_get_public_key_from_x509(void)

{
  return 0;
}


