// ===== 0011d330 __pfx_os_free_rwlock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_free_rwlock(long param_1)

{
  if ((*(byte *)(param_1 + -8) & 1) != 0) {
    vfree();
    return;
  }
  kfree(param_1 + -8);
  return;
}


// ===== 0011d340 os_free_rwlock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_free_rwlock(long param_1)

{
  if ((*(byte *)(param_1 + -8) & 1) != 0) {
    vfree();
    return;
  }
  kfree(param_1 + -8);
  return;
}


// ===== 0011d360 __pfx_os_acquire_rwlock_read =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d398) */
/* WARNING: Removing unreachable block (ram,0x0011d3a2) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_os_acquire_rwlock_read(void)

{
  ulong uVar1;
  long in_GS_OFFSET;
  
  uVar1 = (*_mpi_powm)();
  if (((uVar1 & 0x200) != 0) && ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0)) {
    down_read();
    return 0;
  }
  return 0x3f;
}


// ===== 0011d370 os_acquire_rwlock_read =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d398) */
/* WARNING: Removing unreachable block (ram,0x0011d3a2) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 os_acquire_rwlock_read(void)

{
  ulong uVar1;
  long in_GS_OFFSET;
  
  uVar1 = (*_mpi_powm)();
  if (((uVar1 & 0x200) != 0) && ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0)) {
    down_read();
    return 0;
  }
  return 0x3f;
}


// ===== 0011d3b0 __pfx_os_acquire_rwlock_write =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d3e8) */
/* WARNING: Removing unreachable block (ram,0x0011d3f2) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_os_acquire_rwlock_write(void)

{
  ulong uVar1;
  long in_GS_OFFSET;
  
  uVar1 = (*_mpi_powm)();
  if (((uVar1 & 0x200) != 0) && ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0)) {
    down_write();
    return 0;
  }
  return 0x3f;
}


// ===== 0011d3c0 os_acquire_rwlock_write =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d3e8) */
/* WARNING: Removing unreachable block (ram,0x0011d3f2) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 os_acquire_rwlock_write(void)

{
  ulong uVar1;
  long in_GS_OFFSET;
  
  uVar1 = (*_mpi_powm)();
  if (((uVar1 & 0x200) != 0) && ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0)) {
    down_write();
    return 0;
  }
  return 0x3f;
}


// ===== 0011d400 __pfx_os_cond_acquire_rwlock_read =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d425) */

byte __pfx_os_cond_acquire_rwlock_read(void)

{
  int iVar1;
  
  iVar1 = down_read_trylock();
  return -(iVar1 != 0) & 0x66;
}


// ===== 0011d410 os_cond_acquire_rwlock_read =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d425) */

byte os_cond_acquire_rwlock_read(void)

{
  int iVar1;
  
  iVar1 = down_read_trylock();
  return -(iVar1 != 0) & 0x66;
}


// ===== 0011d430 __pfx_os_cond_acquire_rwlock_write =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d455) */

byte __pfx_os_cond_acquire_rwlock_write(void)

{
  int iVar1;
  
  iVar1 = down_write_trylock();
  return -(iVar1 != 0) & 0x66;
}


// ===== 0011d440 os_cond_acquire_rwlock_write =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d455) */

byte os_cond_acquire_rwlock_write(void)

{
  int iVar1;
  
  iVar1 = down_write_trylock();
  return -(iVar1 != 0) & 0x66;
}


// ===== 0011d460 __pfx_os_release_rwlock_read =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_release_rwlock_read(void)

{
  up_read();
  return;
}


// ===== 0011d470 os_release_rwlock_read =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_release_rwlock_read(void)

{
  up_read();
  return;
}


// ===== 0011d480 __pfx_os_release_rwlock_write =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_release_rwlock_write(void)

{
  up_write();
  return;
}


// ===== 0011d490 os_release_rwlock_write =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_release_rwlock_write(void)

{
  up_write();
  return;
}


// ===== 0011d4a0 __pfx_os_semaphore_may_sleep =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d4d6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __pfx_os_semaphore_may_sleep(void)

{
  ulong uVar1;
  long in_GS_OFFSET;
  bool bVar2;
  
  uVar1 = (*_mpi_powm)();
  bVar2 = false;
  if ((uVar1 & 0x200) != 0) {
    bVar2 = (*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0;
  }
  return bVar2;
}


// ===== 0011d4b0 os_semaphore_may_sleep =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d4d6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool os_semaphore_may_sleep(void)

{
  ulong uVar1;
  long in_GS_OFFSET;
  bool bVar2;
  
  uVar1 = (*_mpi_powm)();
  bVar2 = false;
  if ((uVar1 & 0x200) != 0) {
    bVar2 = (*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0;
  }
  return bVar2;
}


// ===== 0011d4e0 __pfx_os_is_isr =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d4fb) */

undefined8 __pfx_os_is_isr(void)

{
  return 0;
}


// ===== 0011d4f0 os_is_isr =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d4fb) */

undefined8 os_is_isr(void)

{
  return 0;
}


// ===== 0011d500 __pfx_os_is_administrator =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_is_administrator(void)

{
  capable(0x15);
  return;
}


// ===== 0011d510 os_is_administrator =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_is_administrator(void)

{
  capable(0x15);
  return;
}


// ===== 0011d530 __pfx_os_check_access =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d557) */

undefined8 __pfx_os_check_access(short param_1)

{
  undefined8 uVar1;
  
  if (param_1 == 1) {
    uVar1 = capable(0x17);
    return uVar1;
  }
  if (param_1 != 3) {
    return 0;
  }
  uVar1 = capable(0x26);
  return uVar1;
}


// ===== 0011d540 os_check_access =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d557) */

undefined8 os_check_access(short param_1)

{
  undefined8 uVar1;
  
  if (param_1 == 1) {
    uVar1 = capable(0x17);
    return uVar1;
  }
  if (param_1 != 3) {
    return 0;
  }
  uVar1 = capable(0x26);
  return uVar1;
}


// ===== 0011d570 __pfx_os_string_copy =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_string_copy(char *param_1,char *param_2)

{
  strcpy(param_1,param_2);
  return;
}


// ===== 0011d580 os_string_copy =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_string_copy(char *param_1,char *param_2)

{
  strcpy(param_1,param_2);
  return;
}


// ===== 0011d590 __pfx_os_string_length =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d5ae) */

void __pfx_os_string_length(char *param_1)

{
  strlen(param_1);
  return;
}


// ===== 0011d5a0 os_string_length =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d5ae) */

void os_string_length(char *param_1)

{
  strlen(param_1);
  return;
}


// ===== 0011d5c0 __pfx_os_strtoul =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d5de) */

void __pfx_os_strtoul(void)

{
  simple_strtoul();
  return;
}


// ===== 0011d5d0 os_strtoul =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d5de) */

void os_strtoul(void)

{
  simple_strtoul();
  return;
}


// ===== 0011d5f0 __pfx_os_string_compare =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_string_compare(char *param_1,char *param_2)

{
  strcmp(param_1,param_2);
  return;
}


// ===== 0011d600 os_string_compare =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_string_compare(char *param_1,char *param_2)

{
  strcmp(param_1,param_2);
  return;
}


// ===== 0011d610 __pfx_os_mem_copy =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_mem_copy(void *param_1,void *param_2,uint param_3)

{
  memcpy(param_1,param_2,(ulong)param_3);
  return;
}


// ===== 0011d620 os_mem_copy =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_mem_copy(void *param_1,void *param_2,uint param_3)

{
  memcpy(param_1,param_2,(ulong)param_3);
  return;
}


// ===== 0011d630 __pfx_os_memcpy_from_user =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d695) */

byte __pfx_os_memcpy_from_user(undefined8 param_1,undefined8 param_2,int param_3)

{
  code *pcVar1;
  long lVar2;
  
  if (-1 < param_3) {
    __check_object_size(param_1,param_3,0);
    lVar2 = _copy_from_user(param_1,param_2,param_3);
    return -(lVar2 != 0) & 0x1e;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0011d640 os_memcpy_from_user =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d695) */

byte os_memcpy_from_user(undefined8 param_1,undefined8 param_2,int param_3)

{
  code *pcVar1;
  long lVar2;
  
  if (-1 < param_3) {
    __check_object_size(param_1,param_3,0);
    lVar2 = _copy_from_user(param_1,param_2,param_3);
    return -(lVar2 != 0) & 0x1e;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0011d6b0 __pfx_os_memcpy_to_user =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d722) */

byte __pfx_os_memcpy_to_user(undefined8 param_1,undefined8 param_2,int param_3)

{
  code *pcVar1;
  long lVar2;
  
  if (-1 < param_3) {
    __check_object_size(param_2,param_3,1,param_1);
    lVar2 = _copy_to_user(param_1,param_2,param_3);
    return -(lVar2 != 0) & 0x1e;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0011d6c0 os_memcpy_to_user =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d722) */

byte os_memcpy_to_user(undefined8 param_1,undefined8 param_2,int param_3)

{
  code *pcVar1;
  long lVar2;
  
  if (-1 < param_3) {
    __check_object_size(param_2,param_3,1,param_1);
    lVar2 = _copy_to_user(param_1,param_2,param_3);
    return -(lVar2 != 0) & 0x1e;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0011d740 __pfx_os_mem_set =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_mem_set(void *param_1,byte param_2,uint param_3)

{
  memset(param_1,(uint)param_2,(ulong)param_3);
  return;
}


// ===== 0011d750 os_mem_set =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_mem_set(void *param_1,byte param_2,uint param_3)

{
  memset(param_1,(uint)param_2,(ulong)param_3);
  return;
}


// ===== 0011d770 __pfx_os_mem_cmp =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_mem_cmp(void *param_1,void *param_2,uint param_3)

{
  memcmp(param_1,param_2,(ulong)param_3);
  return;
}


// ===== 0011d780 os_mem_cmp =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_mem_cmp(void *param_1,void *param_2,uint param_3)

{
  memcmp(param_1,param_2,(ulong)param_3);
  return;
}


// ===== 0011d790 __pfx_os_alloc_mem =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d80c) */
/* WARNING: Removing unreachable block (ram,0x0011d889) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte __pfx_os_alloc_mem(long *param_1,ulong param_2)

{
  long lVar1;
  ulong *puVar2;
  ulong uVar3;
  long *plVar4;
  long in_GS_OFFSET;
  undefined1 auVar5 [16];
  
  if (param_1 == (long *)0x0) {
    return 0x1f;
  }
  *param_1 = 0;
  uVar3 = param_2 + 0xf & 0xfffffffffffffff8;
  if (uVar3 < param_2) {
    return 0x1f;
  }
  auVar5 = (*_mpi_powm)(param_1,param_2,param_1);
  plVar4 = auVar5._8_8_;
  if (((auVar5._0_8_ & 0x200) == 0) ||
     ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) != 0)) {
    if (uVar3 < 0x20001) {
      puVar2 = (ulong *)__kmalloc_noprof(uVar3,0x2820);
      *plVar4 = (long)puVar2;
    }
    else {
      puVar2 = (ulong *)*plVar4;
    }
  }
  else {
    if (uVar3 < 0x20001) {
      puVar2 = (ulong *)__kmalloc_noprof(uVar3,0x6cc0);
      *param_1 = (long)puVar2;
      plVar4 = param_1;
    }
    else {
      puVar2 = (ulong *)*param_1;
    }
    if (puVar2 != (ulong *)0x0) goto LAB_0011d7f2;
    puVar2 = (ulong *)__vmalloc_noprof(uVar3,0xcc0);
    *plVar4 = (long)puVar2;
    uVar3 = uVar3 | 1;
  }
  if (puVar2 == (ulong *)0x0) {
    return 0x51;
  }
LAB_0011d7f2:
  *puVar2 = uVar3;
  lVar1 = *plVar4;
  *plVar4 = lVar1 + 8;
  return -(lVar1 + 8 == 0) & 0x51;
}


// ===== 0011d7a0 os_alloc_mem =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d80c) */
/* WARNING: Removing unreachable block (ram,0x0011d889) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte os_alloc_mem(long *param_1,ulong param_2)

{
  long lVar1;
  ulong *puVar2;
  ulong uVar3;
  long *plVar4;
  long in_GS_OFFSET;
  undefined1 auVar5 [16];
  
  if (param_1 == (long *)0x0) {
    return 0x1f;
  }
  *param_1 = 0;
  uVar3 = param_2 + 0xf & 0xfffffffffffffff8;
  if (uVar3 < param_2) {
    return 0x1f;
  }
  auVar5 = (*_mpi_powm)(param_1,param_2,param_1);
  plVar4 = auVar5._8_8_;
  if (((auVar5._0_8_ & 0x200) == 0) ||
     ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) != 0)) {
    if (uVar3 < 0x20001) {
      puVar2 = (ulong *)__kmalloc_noprof(uVar3,0x2820);
      *plVar4 = (long)puVar2;
    }
    else {
      puVar2 = (ulong *)*plVar4;
    }
  }
  else {
    if (uVar3 < 0x20001) {
      puVar2 = (ulong *)__kmalloc_noprof(uVar3,0x6cc0);
      *param_1 = (long)puVar2;
      plVar4 = param_1;
    }
    else {
      puVar2 = (ulong *)*param_1;
    }
    if (puVar2 != (ulong *)0x0) goto LAB_0011d7f2;
    puVar2 = (ulong *)__vmalloc_noprof(uVar3,0xcc0);
    *plVar4 = (long)puVar2;
    uVar3 = uVar3 | 1;
  }
  if (puVar2 == (ulong *)0x0) {
    return 0x51;
  }
LAB_0011d7f2:
  *puVar2 = uVar3;
  lVar1 = *plVar4;
  *plVar4 = lVar1 + 8;
  return -(lVar1 + 8 == 0) & 0x51;
}


// ===== 0011d8c0 __pfx_os_free_mem =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_free_mem(long param_1)

{
  if ((*(byte *)(param_1 + -8) & 1) != 0) {
    vfree();
    return;
  }
  kfree(param_1 + -8);
  return;
}


// ===== 0011d8d0 os_free_mem =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_free_mem(long param_1)

{
  if ((*(byte *)(param_1 + -8) & 1) != 0) {
    vfree();
    return;
  }
  kfree(param_1 + -8);
  return;
}


// ===== 0011d8f0 __pfx_os_get_system_time =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d978) */

undefined8 __pfx_os_get_system_time(undefined4 *param_1,undefined4 *param_2)

{
  long in_GS_OFFSET;
  undefined8 uStack_30;
  long lStack_28;
  long lStack_20;
  
  lStack_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_30 = 0;
  lStack_28 = 0;
  ktime_get_real_ts64(&uStack_30);
  *param_1 = (int)uStack_30;
  *param_2 = (int)(lStack_28 / 1000);
  if (lStack_20 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011d900 os_get_system_time =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011d978) */

undefined8 os_get_system_time(undefined4 *param_1,undefined4 *param_2)

{
  long in_GS_OFFSET;
  undefined8 local_30;
  long local_28;
  long local_20;
  
  local_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_30 = 0;
  local_28 = 0;
  ktime_get_real_ts64(&local_30);
  *param_1 = (int)local_30;
  *param_2 = (int)(local_28 / 1000);
  if (local_20 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011d990 __pfx_os_get_monotonic_time_ns_hr =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011da14) */

long __pfx_os_get_monotonic_time_ns_hr(void)

{
  long lVar1;
  long in_GS_OFFSET;
  long lStack_20;
  long lStack_18;
  long lStack_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x11d9a9;
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


// ===== 0011d9a0 os_get_monotonic_time_ns_hr =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011da14) */

long os_get_monotonic_time_ns_hr(void)

{
  long lVar1;
  long in_GS_OFFSET;
  long local_20;
  long local_18;
  long local_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x11d9a9;
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


// ===== 0011da40 __pfx_os_get_monotonic_time_ns =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011dacb) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long __pfx_os_get_monotonic_time_ns(void)

{
  long lVar1;
  long in_GS_OFFSET;
  long lStack_20;
  long lStack_18;
  long lStack_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x11da59;
  lStack_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lStack_20 = 0;
  lStack_18 = 0;
  jiffies_to_timespec64(_jiffies,&lStack_20);
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


// ===== 0011da50 os_get_monotonic_time_ns =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011dacb) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long os_get_monotonic_time_ns(void)

{
  long lVar1;
  long in_GS_OFFSET;
  long local_20;
  long local_18;
  long local_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x11da59;
  local_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_20 = 0;
  local_18 = 0;
  jiffies_to_timespec64(_jiffies,&local_20);
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


// ===== 0011daf0 __pfx_os_get_monotonic_tick_resolution_ns =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011db0e) */

undefined8 __pfx_os_get_monotonic_tick_resolution_ns(void)

{
  return 1000000;
}


// ===== 0011db00 os_get_monotonic_tick_resolution_ns =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011db0e) */

undefined8 os_get_monotonic_tick_resolution_ns(void)

{
  return 1000000;
}


// ===== 0011db20 __pfx_os_delay_us =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011dba6) */

undefined8 __pfx_os_delay_us(uint param_1)

{
  ulong uVar1;
  
  if (999 < param_1) {
    uVar1 = (ulong)param_1 / 1000;
    do {
      __const_udelay(0x418958);
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  if (param_1 % 1000 != 0) {
    __udelay(param_1 % 1000);
  }
  return 0;
}


// ===== 0011db30 os_delay_us =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011dba6) */

undefined8 os_delay_us(uint param_1)

{
  ulong uVar1;
  
  if (999 < param_1) {
    uVar1 = (ulong)param_1 / 1000;
    do {
      __const_udelay(0x418958);
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  if (param_1 % 1000 != 0) {
    __udelay(param_1 % 1000);
  }
  return 0;
}


// ===== 0011dbb0 __pfx_os_delay =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011dc47) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_os_delay(ulong param_1)

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
          if (!bVar1) goto LAB_0011dc29;
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
          goto LAB_0011dda1;
        }
        uVar4 = lStack_38 * 1000000000 + lStack_30;
        if (uVar4 * 1000 < 1000000000) break;
        param_1 = (uVar4 * 1000) / 1000000000;
      }
      if (1000000 < uVar4) {
LAB_0011dda1:
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
LAB_0011dc29:
  if (lStack_28 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011dbc0 os_delay =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011dc47) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 os_delay(ulong param_1)

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
          if (!bVar1) goto LAB_0011dc29;
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
          goto LAB_0011dda1;
        }
        uVar4 = local_38 * 1000000000 + local_30;
        if (uVar4 * 1000 < 1000000000) break;
        param_1 = (uVar4 * 1000) / 1000000000;
      }
      if (1000000 < uVar4) {
LAB_0011dda1:
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
LAB_0011dc29:
  if (local_28 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011de20 __pfx_os_get_cpu_frequency =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011de46) */

int __pfx_os_get_cpu_frequency(void)

{
  int iVar1;
  
  iVar1 = cpufreq_get(0);
  return iVar1 * 1000;
}


// ===== 0011de30 os_get_cpu_frequency =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011de46) */

int os_get_cpu_frequency(void)

{
  int iVar1;
  
  iVar1 = cpufreq_get(0);
  return iVar1 * 1000;
}


// ===== 0011de50 __pfx_os_get_current_process =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011de77) */

undefined4 __pfx_os_get_current_process(void)

{
  long in_GS_OFFSET;
  
  return *(undefined4 *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0xb34);
}


// ===== 0011de60 os_get_current_process =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011de77) */

undefined4 os_get_current_process(void)

{
  long in_GS_OFFSET;
  
  return *(undefined4 *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0xb34);
}


// ===== 0011de80 __pfx_os_get_current_process_name =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_get_current_process_name(char *param_1,int param_2)

{
  long lVar1;
  long in_GS_OFFSET;
  
  lVar1 = *(long *)(&const_current_task + in_GS_OFFSET);
  _raw_spin_lock(lVar1 + 0xe60);
  strncpy(param_1,(char *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0xd48),
          (ulong)(param_2 - 1));
  param_1[param_2 - 1] = '\0';
  _raw_spin_unlock(lVar1 + 0xe60);
  return;
}


// ===== 0011de90 os_get_current_process_name =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_get_current_process_name(char *param_1,int param_2)

{
  long lVar1;
  long in_GS_OFFSET;
  
  lVar1 = *(long *)(&const_current_task + in_GS_OFFSET);
  _raw_spin_lock(lVar1 + 0xe60);
  strncpy(param_1,(char *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0xd48),
          (ulong)(param_2 - 1));
  param_1[param_2 - 1] = '\0';
  _raw_spin_unlock(lVar1 + 0xe60);
  return;
}


// ===== 0011def0 __pfx_os_iommu_sva_unbind =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_iommu_sva_unbind(void)

{
  iommu_sva_unbind_device();
  return;
}


// ===== 0011df00 os_iommu_sva_unbind =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_iommu_sva_unbind(void)

{
  iommu_sva_unbind_device();
  return;
}


// ===== 0011df10 __pfx_os_get_current_thread =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011df4b) */

undefined8 __pfx_os_get_current_thread(long *param_1)

{
  long lVar1;
  long in_GS_OFFSET;
  
  lVar1 = 0;
  if (*(short *)(&DAT_00f79bd9 + in_GS_OFFSET) == 0) {
    lVar1 = (long)*(int *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0xb30);
  }
  *param_1 = lVar1;
  return 0;
}


// ===== 0011df20 os_get_current_thread =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011df4b) */

undefined8 os_get_current_thread(long *param_1)

{
  long lVar1;
  long in_GS_OFFSET;
  
  lVar1 = 0;
  if (*(short *)(&DAT_00f79bd9 + in_GS_OFFSET) == 0) {
    lVar1 = (long)*(int *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0xb30);
  }
  *param_1 = lVar1;
  return 0;
}


// ===== 0011df50 __pfx_nv_printf =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011dfe7) */

undefined4 __pfx_nv_printf(uint param_1,char *param_2)

{
  long lVar1;
  undefined4 uVar2;
  size_t sVar3;
  undefined8 uVar4;
  long in_GS_OFFSET;
  undefined8 uStack_68;
  
  lVar1 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_68 = 0;
  if ((cur_debuglevel >> 4 & 3) <= param_1) {
    sVar3 = strlen(param_2);
    if (sVar3 != 0) {
      uVar4 = _raw_spin_lock_irqsave(&nv_error_string_lock);
      nv_error_string._0_2_ = 0x6301;
      if (0x20e < sVar3 + 1) {
                    /* WARNING: Subroutine does not return */
        __fortify_panic(0x11,0x20e);
      }
      memcpy(nv_error_string + 2,param_2,sVar3 + 1);
      uStack_68 = CONCAT44(uStack_68._4_4_,0x10);
      uVar2 = vprintk(nv_error_string,&uStack_68);
      _raw_spin_unlock_irqrestore(&nv_error_string_lock,uVar4);
      goto LAB_0011dfd3;
    }
  }
  uVar2 = 0;
LAB_0011dfd3:
  if (lVar1 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011df60 nv_printf =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011dfe7) */

undefined4 nv_printf(uint param_1,char *param_2)

{
  long lVar1;
  undefined4 uVar2;
  size_t sVar3;
  undefined8 uVar4;
  long in_GS_OFFSET;
  undefined8 local_68;
  
  lVar1 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_68 = 0;
  if ((cur_debuglevel >> 4 & 3) <= param_1) {
    sVar3 = strlen(param_2);
    if (sVar3 != 0) {
      uVar4 = _raw_spin_lock_irqsave(&nv_error_string_lock);
      nv_error_string._0_2_ = 0x6301;
      if (0x20e < sVar3 + 1) {
                    /* WARNING: Subroutine does not return */
        __fortify_panic(0x11,0x20e);
      }
      memcpy(nv_error_string + 2,param_2,sVar3 + 1);
      local_68 = CONCAT44(local_68._4_4_,0x10);
      uVar2 = vprintk(nv_error_string,&local_68);
      _raw_spin_unlock_irqrestore(&nv_error_string_lock,uVar4);
      goto LAB_0011dfd3;
    }
  }
  uVar2 = 0;
LAB_0011dfd3:
  if (lVar1 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011e090 __pfx_os_alloc_mutex =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e0e8) */
/* WARNING: Removing unreachable block (ram,0x0011e10d) */

int __pfx_os_alloc_mutex(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = os_alloc_mem(param_1,0x18);
  if (iVar1 == 0) {
    param_1 = (undefined8 *)*param_1;
    *param_1 = 0x100000000;
    param_1[1] = 0;
    param_1[2] = 0;
    return 0;
  }
  nv_printf(4,"NVRM: failed to allocate mutex!\n");
  return iVar1;
}


// ===== 0011e0a0 os_alloc_mutex =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e0e8) */
/* WARNING: Removing unreachable block (ram,0x0011e10d) */

int os_alloc_mutex(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = os_alloc_mem(param_1,0x18);
  if (iVar1 == 0) {
    param_1 = (undefined8 *)*param_1;
    *param_1 = 0x100000000;
    param_1[1] = 0;
    param_1[2] = 0;
    return 0;
  }
  nv_printf(4,"NVRM: failed to allocate mutex!\n");
  return iVar1;
}


// ===== 0011e120 __pfx_os_alloc_semaphore =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e197) */

undefined4 * __pfx_os_alloc_semaphore(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  long in_GS_OFFSET;
  undefined4 *puStack_20;
  long lStack_18;
  
  lStack_18 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  puStack_20 = (undefined4 *)0x0;
  iVar1 = os_alloc_mem(&puStack_20,0x18);
  if (iVar1 == 0) {
    *puStack_20 = 0;
    puStack_20[1] = param_1;
    *(undefined8 *)(puStack_20 + 2) = 0;
    *(undefined8 *)(puStack_20 + 4) = 0;
    puVar2 = puStack_20;
  }
  else {
    nv_printf(4,"NVRM: failed to allocate semaphore!\n");
    puVar2 = (undefined4 *)0x0;
  }
  if (lStack_18 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return puVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011e130 os_alloc_semaphore =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e197) */

undefined4 * os_alloc_semaphore(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  long in_GS_OFFSET;
  undefined4 *local_20;
  long local_18;
  
  local_18 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_20 = (undefined4 *)0x0;
  iVar1 = os_alloc_mem(&local_20,0x18);
  if (iVar1 == 0) {
    *local_20 = 0;
    local_20[1] = param_1;
    *(undefined8 *)(local_20 + 2) = 0;
    *(undefined8 *)(local_20 + 4) = 0;
    puVar2 = local_20;
  }
  else {
    nv_printf(4,"NVRM: failed to allocate semaphore!\n");
    puVar2 = (undefined4 *)0x0;
  }
  if (local_18 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return puVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011e1c0 __pfx_os_alloc_rwlock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e23e) */

undefined8 __pfx_os_alloc_rwlock(void)

{
  int iVar1;
  undefined8 uVar2;
  long in_GS_OFFSET;
  undefined8 uStack_18;
  long lStack_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x11e1d9;
  lStack_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_18 = 0;
  iVar1 = os_alloc_mem(&uStack_18,0x20);
  uVar2 = uStack_18;
  if (iVar1 == 0) {
    __init_rwsem(uStack_18,"&os_rwlock->sem",0x546205);
  }
  else {
    nv_printf(4,"NVRM: failed to allocate a struct os_rwlock_t!\n");
    uVar2 = 0;
  }
  if (lStack_10 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011e1d0 os_alloc_rwlock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e23e) */

undefined8 os_alloc_rwlock(void)

{
  int iVar1;
  undefined8 uVar2;
  long in_GS_OFFSET;
  undefined8 local_18;
  long local_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x11e1d9;
  local_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_18 = 0;
  iVar1 = os_alloc_mem(&local_18,0x20);
  uVar2 = local_18;
  if (iVar1 == 0) {
    __init_rwsem(local_18,"&os_rwlock->sem",0x546205);
  }
  else {
    nv_printf(4,"NVRM: failed to allocate a struct os_rwlock_t!\n");
    uVar2 = 0;
  }
  if (local_10 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011e260 __pfx_os_iommu_sva_bind =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e35d) */
/* WARNING: Removing unreachable block (ram,0x0011e32b) */
/* WARNING: Removing unreachable block (ram,0x0011e367) */

undefined8 __pfx_os_iommu_sva_bind(long param_1,ulong *param_2,undefined4 *param_3)

{
  long lVar1;
  undefined4 uVar2;
  ulong uVar3;
  long in_GS_OFFSET;
  
  if ((param_3 != (undefined4 *)0x0) && (param_2 != (ulong *)0x0)) {
    lVar1 = *(long *)(param_1 + 8);
    *param_3 = 0;
    *param_2 = 0;
    if (((*(char *)(param_1 + 0x329) != '\0') &&
        (*(long *)(&const_current_task + in_GS_OFFSET) != 0)) &&
       (*(long *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0xab8) != 0)) {
      uVar3 = iommu_sva_bind_device(*(undefined8 *)(lVar1 + 0x3b0));
      if (uVar3 < 0xfffffffffffff001) {
        uVar2 = iommu_sva_get_pasid(uVar3);
        *param_3 = uVar2;
        *param_2 = uVar3;
        nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: PASID: %u\n",*(undefined4 *)(param_1 + 0x14),
                  *(undefined1 *)(param_1 + 0x18),*(undefined1 *)(param_1 + 0x19),
                  *(undefined1 *)(param_1 + 0x1a),*param_3);
        return 0;
      }
    }
    nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: IOMMU SVA bind failed\n",
              *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
              *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a));
    return 0x40;
  }
  return 0x1f;
}


// ===== 0011e270 os_iommu_sva_bind =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e35d) */
/* WARNING: Removing unreachable block (ram,0x0011e32b) */
/* WARNING: Removing unreachable block (ram,0x0011e367) */

undefined8 os_iommu_sva_bind(long param_1,ulong *param_2,undefined4 *param_3)

{
  long lVar1;
  undefined4 uVar2;
  ulong uVar3;
  long in_GS_OFFSET;
  
  if ((param_3 != (undefined4 *)0x0) && (param_2 != (ulong *)0x0)) {
    lVar1 = *(long *)(param_1 + 8);
    *param_3 = 0;
    *param_2 = 0;
    if (((*(char *)(param_1 + 0x329) != '\0') &&
        (*(long *)(&const_current_task + in_GS_OFFSET) != 0)) &&
       (*(long *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0xab8) != 0)) {
      uVar3 = iommu_sva_bind_device(*(undefined8 *)(lVar1 + 0x3b0));
      if (uVar3 < 0xfffffffffffff001) {
        uVar2 = iommu_sva_get_pasid(uVar3);
        *param_3 = uVar2;
        *param_2 = uVar3;
        nv_printf(0,"NVRM: GPU %04x:%02x:%02x.%x: PASID: %u\n",*(undefined4 *)(param_1 + 0x14),
                  *(undefined1 *)(param_1 + 0x18),*(undefined1 *)(param_1 + 0x19),
                  *(undefined1 *)(param_1 + 0x1a),*param_3);
        return 0;
      }
    }
    nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: IOMMU SVA bind failed\n",
              *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
              *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a));
    return 0x40;
  }
  return 0x1f;
}


// ===== 0011e370 __pfx_os_numa_verify_gpu_memory_zone =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e394) */
/* WARNING: Removing unreachable block (ram,0x0011e40c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] __pfx_os_numa_verify_gpu_memory_zone(long param_1,long param_2,long *param_3)

{
  long lVar1;
  ulong uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  
  if (param_2 == 3) {
    lVar1 = *param_3;
    if (((*(ulong *)(param_1 + -0x20) <= (ulong)(lVar1 * 0x1000)) &&
        (param_3 = (long *)(param_3[1] * 0x1000),
        param_3 + lVar1 * 0x200 <=
        (long *)(*(ulong *)(param_1 + -0x20) + *(long *)(param_1 + -0x18)))) &&
       (((uint)((ulong)*(undefined8 *)(lVar1 * 0x40 + _vmemmap_base) >> 0x33) & 7) != 3)) {
      uVar2 = (ulong)*(byte *)(param_1 + -10);
      nv_printf(4,
                "NVRM: Failing GPU memory onlining as the onlining zone is not movable. pa: 0x%llx size: 0x%llx\nNVRM: The NVIDIA GPU %04x:%02x:%02x.%x installed in the system\nNVRM: requires auto onlining mode online_movable enabled in\nNVRM: /sys/devices/system/memory/auto_online_blocks\n"
                ,lVar1 * 0x1000,param_3,*(undefined4 *)(param_1 + -0x10),
                *(undefined1 *)(param_1 + -0xc),*(undefined1 *)(param_1 + -0xb),uVar2,0x11e389);
      auVar4._8_8_ = uVar2;
      auVar4._0_8_ = 0x8002;
      return auVar4;
    }
  }
  auVar3._8_8_ = param_3;
  auVar3._0_8_ = 1;
  return auVar3;
}


// ===== 0011e380 os_numa_verify_gpu_memory_zone =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e394) */
/* WARNING: Removing unreachable block (ram,0x0011e40c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] os_numa_verify_gpu_memory_zone(long param_1,long param_2,long *param_3)

{
  long lVar1;
  ulong uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  
  if (param_2 == 3) {
    lVar1 = *param_3;
    if (((*(ulong *)(param_1 + -0x20) <= (ulong)(lVar1 * 0x1000)) &&
        (param_3 = (long *)(param_3[1] * 0x1000),
        param_3 + lVar1 * 0x200 <=
        (long *)(*(ulong *)(param_1 + -0x20) + *(long *)(param_1 + -0x18)))) &&
       (((uint)((ulong)*(undefined8 *)(lVar1 * 0x40 + _vmemmap_base) >> 0x33) & 7) != 3)) {
      uVar2 = (ulong)*(byte *)(param_1 + -10);
      nv_printf(4,
                "NVRM: Failing GPU memory onlining as the onlining zone is not movable. pa: 0x%llx size: 0x%llx\nNVRM: The NVIDIA GPU %04x:%02x:%02x.%x installed in the system\nNVRM: requires auto onlining mode online_movable enabled in\nNVRM: /sys/devices/system/memory/auto_online_blocks\n"
                ,lVar1 * 0x1000,param_3,*(undefined4 *)(param_1 + -0x10),
                *(undefined1 *)(param_1 + -0xc),*(undefined1 *)(param_1 + -0xb),uVar2,0x11e389);
      auVar4._8_8_ = uVar2;
      auVar4._0_8_ = 0x8002;
      return auVar4;
    }
  }
  auVar3._8_8_ = param_3;
  auVar3._0_8_ = 1;
  return auVar3;
}


// ===== 0011e420 __pfx_os_map_kernel_space.part.0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e4cd) */
/* WARNING: Removing unreachable block (ram,0x0011e47f) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_os_map_kernel_space_part_0(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  uint uVar3;
  long in_GS_OFFSET;
  undefined1 auVar4 [12];
  
  auVar4 = (*_mpi_powm)();
  uVar3 = auVar4._8_4_;
  if (((auVar4._0_8_ & 0x200) != 0) &&
     ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0)) {
    if (uVar3 == 2) {
      cVar1 = rm_disable_iomap_wc();
      if (cVar1 == '\0') {
        uVar2 = ioremap_wc(param_1,param_2);
        return uVar2;
      }
    }
    else if (uVar3 < 3) {
      if (uVar3 == 0) {
        uVar2 = ioremap_cache();
        return uVar2;
      }
    }
    else if (uVar3 != 6) {
      nv_printf(4,"NVRM: os_map_kernel_space: unsupported mode!\n");
      return 0;
    }
    uVar2 = ioremap();
    return uVar2;
  }
  nv_printf(4,"NVRM: os_map_kernel_space: can\'t map 0x%0llx, invalid context!\n",param_1);
  return 0;
}


// ===== 0011e430 os_map_kernel_space.part.0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e4cd) */
/* WARNING: Removing unreachable block (ram,0x0011e47f) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 os_map_kernel_space_part_0(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  uint uVar3;
  long in_GS_OFFSET;
  undefined1 auVar4 [12];
  
  auVar4 = (*_mpi_powm)();
  uVar3 = auVar4._8_4_;
  if (((auVar4._0_8_ & 0x200) != 0) &&
     ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0)) {
    if (uVar3 == 2) {
      cVar1 = rm_disable_iomap_wc();
      if (cVar1 == '\0') {
        uVar2 = ioremap_wc(param_1,param_2);
        return uVar2;
      }
    }
    else if (uVar3 < 3) {
      if (uVar3 == 0) {
        uVar2 = ioremap_cache();
        return uVar2;
      }
    }
    else if (uVar3 != 6) {
      nv_printf(4,"NVRM: os_map_kernel_space: unsupported mode!\n");
      return 0;
    }
    uVar2 = ioremap();
    return uVar2;
  }
  nv_printf(4,"NVRM: os_map_kernel_space: can\'t map 0x%0llx, invalid context!\n",param_1);
  return 0;
}


// ===== 0011e4e0 __pfx_os_verify_smbios_header_uefi =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e5ac) */
/* WARNING: Removing unreachable block (ram,0x0011e634) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte __pfx_os_verify_smbios_header_uefi(ulong param_1)

{
  byte bVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  ulong uVar5;
  char *pcVar6;
  char cVar7;
  
  uVar5 = ~os_page_mask;
  lVar3 = _page_offset_base;
  if ((param_1 & os_page_mask) != 0) {
    lVar3 = os_map_kernel_space_part_0
                      (param_1 & os_page_mask,
                       ((uVar5 & param_1) - os_page_mask) + 0x1f & os_page_mask,0);
  }
  if (lVar3 == 0) {
    return 0x1a;
  }
  pcVar6 = (char *)((uVar5 & param_1) + lVar3);
  if (pcVar6 != (char *)0x0) {
    iVar2 = os_mem_cmp(pcVar6,"_SM3_",5);
    if ((iVar2 == 0) && ((byte)(pcVar6[6] - 1U) < 0x1f)) {
      cVar7 = '\0';
      pcVar4 = pcVar6;
      do {
        cVar7 = cVar7 + *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (pcVar4 != pcVar6 + (ulong)((byte)pcVar6[6] - 1) + 1);
      bVar1 = 0;
      if (cVar7 == '\0') goto LAB_0011e58f;
    }
    iVar2 = os_mem_cmp(pcVar6,&DAT_00daf6d8,4);
    if ((iVar2 == 0) && ((byte)(pcVar6[5] - 1U) < 0x1f)) {
      cVar7 = '\0';
      pcVar4 = pcVar6;
      do {
        cVar7 = cVar7 + *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (pcVar4 != pcVar6 + (ulong)((byte)pcVar6[5] - 1) + 1);
      if (cVar7 == '\0') {
        pcVar4 = pcVar6 + 0x10;
        iVar2 = os_mem_cmp(pcVar4,"_DMI_",5);
        if (iVar2 == 0) {
          cVar7 = '\0';
          do {
            cVar7 = cVar7 + *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (pcVar6 + 0x1f != pcVar4);
          bVar1 = -(cVar7 != '\0') & 0x57;
          goto LAB_0011e58f;
        }
      }
    }
  }
  bVar1 = 0x57;
LAB_0011e58f:
  if (lVar3 != _page_offset_base) {
    iounmap(lVar3);
  }
  return bVar1;
}


// ===== 0011e4f0 os_verify_smbios_header_uefi =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e5ac) */
/* WARNING: Removing unreachable block (ram,0x0011e634) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte os_verify_smbios_header_uefi(ulong param_1)

{
  byte bVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  ulong uVar5;
  char *pcVar6;
  char cVar7;
  
  uVar5 = ~os_page_mask;
  lVar3 = _page_offset_base;
  if ((param_1 & os_page_mask) != 0) {
    lVar3 = os_map_kernel_space_part_0
                      (param_1 & os_page_mask,
                       ((uVar5 & param_1) - os_page_mask) + 0x1f & os_page_mask,0);
  }
  if (lVar3 == 0) {
    return 0x1a;
  }
  pcVar6 = (char *)((uVar5 & param_1) + lVar3);
  if (pcVar6 != (char *)0x0) {
    iVar2 = os_mem_cmp(pcVar6,"_SM3_",5);
    if ((iVar2 == 0) && ((byte)(pcVar6[6] - 1U) < 0x1f)) {
      cVar7 = '\0';
      pcVar4 = pcVar6;
      do {
        cVar7 = cVar7 + *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (pcVar4 != pcVar6 + (ulong)((byte)pcVar6[6] - 1) + 1);
      bVar1 = 0;
      if (cVar7 == '\0') goto LAB_0011e58f;
    }
    iVar2 = os_mem_cmp(pcVar6,&DAT_00daf6d8,4);
    if ((iVar2 == 0) && ((byte)(pcVar6[5] - 1U) < 0x1f)) {
      cVar7 = '\0';
      pcVar4 = pcVar6;
      do {
        cVar7 = cVar7 + *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (pcVar4 != pcVar6 + (ulong)((byte)pcVar6[5] - 1) + 1);
      if (cVar7 == '\0') {
        pcVar4 = pcVar6 + 0x10;
        iVar2 = os_mem_cmp(pcVar4,"_DMI_",5);
        if (iVar2 == 0) {
          cVar7 = '\0';
          do {
            cVar7 = cVar7 + *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (pcVar6 + 0x1f != pcVar4);
          bVar1 = -(cVar7 != '\0') & 0x57;
          goto LAB_0011e58f;
        }
      }
    }
  }
  bVar1 = 0x57;
LAB_0011e58f:
  if (lVar3 != _page_offset_base) {
    iounmap(lVar3);
  }
  return bVar1;
}


// ===== 0011e670 __pfx_offline_numa_memory_callback =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e726) */

void __pfx_offline_numa_memory_callback(long *param_1)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  
  lVar2 = memory_block_size_bytes();
  uVar4 = param_1[1];
  if (uVar4 != 0) {
    uVar3 = ((uVar4 >> 7) - 1) + lVar2 & -lVar2;
    lVar2 = *param_1;
    do {
      if (uVar4 < uVar3) {
        uVar3 = uVar4;
      }
      uVar1 = offline_and_remove_memory(lVar2,uVar3);
      nv_printf(1,
                "NVRM: offline_and_remove_memory() returns: %d for segment_base: 0x%llx, segment_size: 0x%llx\n"
                ,uVar1,lVar2,uVar3);
      *(uint *)((long)param_1 + 0x14) = *(uint *)((long)param_1 + 0x14) | uVar1;
      schedule();
      uVar4 = uVar4 - uVar3;
      lVar2 = lVar2 + uVar3;
    } while (uVar4 != 0);
  }
  return;
}


// ===== 0011e680 offline_numa_memory_callback =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e726) */

void offline_numa_memory_callback(long *param_1)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  
  lVar2 = memory_block_size_bytes();
  uVar4 = param_1[1];
  if (uVar4 != 0) {
    uVar3 = ((uVar4 >> 7) - 1) + lVar2 & -lVar2;
    lVar2 = *param_1;
    do {
      if (uVar4 < uVar3) {
        uVar3 = uVar4;
      }
      uVar1 = offline_and_remove_memory(lVar2,uVar3);
      nv_printf(1,
                "NVRM: offline_and_remove_memory() returns: %d for segment_base: 0x%llx, segment_size: 0x%llx\n"
                ,uVar1,lVar2,uVar3);
      *(uint *)((long)param_1 + 0x14) = *(uint *)((long)param_1 + 0x14) | uVar1;
      schedule();
      uVar4 = uVar4 - uVar3;
      lVar2 = lVar2 + uVar3;
    } while (uVar4 != 0);
  }
  return;
}


// ===== 0011e730 __pfx_os_snprintf =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e7a9) */

void __pfx_os_snprintf(char *param_1,uint param_2,char *param_3)

{
  long lVar1;
  long in_GS_OFFSET;
  undefined8 uStack_60;
  
  lVar1 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_60 = 0x18;
  vsnprintf(param_1,(ulong)param_2,param_3,&uStack_60);
  if (lVar1 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011e740 os_snprintf =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e7a9) */

void os_snprintf(char *param_1,uint param_2,char *param_3)

{
  long lVar1;
  long in_GS_OFFSET;
  undefined8 local_60;
  
  lVar1 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_60 = 0x18;
  vsnprintf(param_1,(ulong)param_2,param_3,&local_60);
  if (lVar1 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011e7c0 __pfx_os_vsnprintf =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_vsnprintf(char *param_1,uint param_2,char *param_3,__gnuc_va_list param_4)

{
  vsnprintf(param_1,(ulong)param_2,param_3,param_4);
  return;
}


// ===== 0011e7d0 os_vsnprintf =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_vsnprintf(char *param_1,uint param_2,char *param_3,__gnuc_va_list param_4)

{
  vsnprintf(param_1,(ulong)param_2,param_3,param_4);
  return;
}


// ===== 0011e7e0 __pfx_os_log_error =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_log_error(char *param_1,__gnuc_va_list param_2)

{
  undefined8 uVar1;
  
  uVar1 = _raw_spin_lock_irqsave(&nv_error_string_lock);
  vsnprintf(nv_error_string,0x210,param_1,param_2);
  nv_error_string[0x20f] = 0;
  _printk(&DAT_00daf6e3,nv_error_string);
  _raw_spin_unlock_irqrestore(&nv_error_string_lock,uVar1);
  return;
}


// ===== 0011e7f0 os_log_error =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_log_error(char *param_1,__gnuc_va_list param_2)

{
  undefined8 uVar1;
  
  uVar1 = _raw_spin_lock_irqsave(&nv_error_string_lock);
  vsnprintf(nv_error_string,0x210,param_1,param_2);
  nv_error_string[0x20f] = 0;
  _printk(&DAT_00daf6e3,nv_error_string);
  _raw_spin_unlock_irqrestore(&nv_error_string_lock,uVar1);
  return;
}


// ===== 0011e860 __pfx_os_io_write_byte =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e87e) */

undefined4 __pfx_os_io_write_byte(undefined2 param_1,undefined4 param_2)

{
  out(param_1,(char)param_2);
  return param_2;
}


// ===== 0011e870 os_io_write_byte =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e87e) */

undefined4 os_io_write_byte(undefined2 param_1,undefined4 param_2)

{
  out(param_1,(char)param_2);
  return param_2;
}


// ===== 0011e890 __pfx_os_io_write_word =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e8af) */

undefined4 __pfx_os_io_write_word(undefined2 param_1,undefined4 param_2)

{
  out(param_1,(short)param_2);
  return param_2;
}


// ===== 0011e8a0 os_io_write_word =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e8af) */

undefined4 os_io_write_word(undefined2 param_1,undefined4 param_2)

{
  out(param_1,(short)param_2);
  return param_2;
}


// ===== 0011e8c0 __pfx_os_io_write_dword =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e8de) */

undefined4 __pfx_os_io_write_dword(undefined2 param_1,undefined4 param_2)

{
  out(param_1,param_2);
  return param_2;
}


// ===== 0011e8d0 os_io_write_dword =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e8de) */

undefined4 os_io_write_dword(undefined2 param_1,undefined4 param_2)

{
  out(param_1,param_2);
  return param_2;
}


// ===== 0011e8f0 __pfx_os_io_read_byte =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e90c) */

undefined1 __pfx_os_io_read_byte(undefined2 param_1)

{
  undefined1 uVar1;
  
  uVar1 = in(param_1);
  return uVar1;
}


// ===== 0011e900 os_io_read_byte =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e90c) */

undefined1 os_io_read_byte(undefined2 param_1)

{
  undefined1 uVar1;
  
  uVar1 = in(param_1);
  return uVar1;
}


// ===== 0011e920 __pfx_os_io_read_word =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e93d) */

undefined2 __pfx_os_io_read_word(undefined2 param_1)

{
  undefined2 uVar1;
  
  uVar1 = in(param_1);
  return uVar1;
}


// ===== 0011e930 os_io_read_word =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e93d) */

undefined2 os_io_read_word(undefined2 param_1)

{
  undefined2 uVar1;
  
  uVar1 = in(param_1);
  return uVar1;
}


// ===== 0011e950 __pfx_os_io_read_dword =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e96c) */

undefined4 __pfx_os_io_read_dword(undefined2 param_1)

{
  undefined4 uVar1;
  
  uVar1 = in(param_1);
  return uVar1;
}


// ===== 0011e960 os_io_read_dword =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e96c) */

undefined4 os_io_read_dword(undefined2 param_1)

{
  undefined4 uVar1;
  
  uVar1 = in(param_1);
  return uVar1;
}


// ===== 0011e980 __pfx_os_map_kernel_space =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e9a9) */
/* WARNING: Removing unreachable block (ram,0x0011e9c8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_os_map_kernel_space(long param_1,undefined8 param_2,int param_3)

{
  undefined8 uVar1;
  
  if (param_1 != 0) {
    uVar1 = os_map_kernel_space_part_0();
    return uVar1;
  }
  if (param_3 == 0) {
    return _page_offset_base;
  }
  nv_printf(4,"NVRM: os_map_kernel_space: won\'t map address 0x%0llx UC!\n",0);
  return 0;
}


// ===== 0011e990 os_map_kernel_space =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e9a9) */
/* WARNING: Removing unreachable block (ram,0x0011e9c8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 os_map_kernel_space(long param_1,undefined8 param_2,int param_3)

{
  undefined8 uVar1;
  
  if (param_1 != 0) {
    uVar1 = os_map_kernel_space_part_0();
    return uVar1;
  }
  if (param_3 == 0) {
    return _page_offset_base;
  }
  nv_printf(4,"NVRM: os_map_kernel_space: won\'t map address 0x%0llx UC!\n",0);
  return 0;
}


// ===== 0011e9d0 __pfx_os_unmap_kernel_space =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e9f7) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __pfx_os_unmap_kernel_space(long param_1)

{
  if (param_1 != _page_offset_base) {
    iounmap();
    return;
  }
  return;
}


// ===== 0011e9e0 os_unmap_kernel_space =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011e9f7) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void os_unmap_kernel_space(long param_1)

{
  if (param_1 != _page_offset_base) {
    iounmap();
    return;
  }
  return;
}


// ===== 0011ea00 __pfx_os_flush_cpu_cache_all =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011ea1e) */

undefined8 __pfx_os_flush_cpu_cache_all(void)

{
  return 0x56;
}


// ===== 0011ea10 os_flush_cpu_cache_all =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011ea1e) */

undefined8 os_flush_cpu_cache_all(void)

{
  return 0x56;
}


// ===== 0011ea30 __pfx_os_flush_user_cache =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011ea4e) */

undefined8 __pfx_os_flush_user_cache(void)

{
  return 0x56;
}


// ===== 0011ea40 os_flush_user_cache =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011ea4e) */

undefined8 os_flush_user_cache(void)

{
  return 0x56;
}


// ===== 0011ea60 __pfx_os_flush_cpu_write_combine_buffer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011ea7c) */

void __pfx_os_flush_cpu_write_combine_buffer(void)

{
  return;
}


// ===== 0011ea70 os_flush_cpu_write_combine_buffer =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011ea7c) */

void os_flush_cpu_write_combine_buffer(void)

{
  return;
}


// ===== 0011ea90 __pfx_os_dbg_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011eb0c) */

void __pfx_os_dbg_init(void)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  long in_GS_OFFSET;
  int iStack_1c;
  long lStack_18;
  
  lStack_18 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  iStack_1c = 0;
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    iVar2 = rm_read_registry_dword(0,0,"ResmanDebugLevel",&iStack_1c);
    if ((iVar2 == 0) && (iStack_1c != -1)) {
      cur_debuglevel = iStack_1c;
    }
  }
  else {
    puVar3 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = 0x2ff0;
      *(undefined4 **)(puVar3 + 2) = puVar3 + 0xc00;
      iVar2 = rm_read_registry_dword(puVar3,0,"ResmanDebugLevel",&iStack_1c);
      if ((iVar2 == 0) && (iStack_1c != -1)) {
        cur_debuglevel = iStack_1c;
      }
      cVar1 = rm_is_altstack_in_use();
      if (cVar1 != '\0') {
        kmem_cache_free(nvidia_stack_t_cache,puVar3);
      }
    }
  }
  if (lStack_18 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ===== 0011eaa0 os_dbg_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011eb0c) */

void os_dbg_init(void)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  long in_GS_OFFSET;
  int local_1c;
  long local_18;
  
  local_18 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_1c = 0;
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    iVar2 = rm_read_registry_dword(0,0,"ResmanDebugLevel",&local_1c);
    if ((iVar2 == 0) && (local_1c != -1)) {
      cur_debuglevel = local_1c;
    }
  }
  else {
    puVar3 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = 0x2ff0;
      *(undefined4 **)(puVar3 + 2) = puVar3 + 0xc00;
      iVar2 = rm_read_registry_dword(puVar3,0,"ResmanDebugLevel",&local_1c);
      if ((iVar2 == 0) && (local_1c != -1)) {
        cur_debuglevel = local_1c;
      }
      cVar1 = rm_is_altstack_in_use();
      if (cVar1 != '\0') {
        kmem_cache_free(nvidia_stack_t_cache,puVar3);
      }
    }
  }
  if (local_18 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ===== 0011eba0 __pfx_os_dbg_set_level =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011ebdc) */

void __pfx_os_dbg_set_level(undefined4 param_1)

{
  nv_printf(1,"NVRM: Changing debuglevel from 0x%x to 0x%x\n",cur_debuglevel,param_1);
  cur_debuglevel = param_1;
  return;
}


// ===== 0011ebb0 os_dbg_set_level =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011ebdc) */

void os_dbg_set_level(undefined4 param_1)

{
  nv_printf(1,"NVRM: Changing debuglevel from 0x%x to 0x%x\n",cur_debuglevel,param_1);
  cur_debuglevel = param_1;
  return;
}


// ===== 0011ebf0 __pfx_os_get_max_user_va =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011ec38) */
/* WARNING: Removing unreachable block (ram,0x0011ec47) */

long __pfx_os_get_max_user_va(void)

{
  long in_GS_OFFSET;
  
  if ((**(ulong **)(&const_current_task + in_GS_OFFSET) & 0x8000000) != 0) {
    return (ulong)(-(uint)(((*(ulong **)(&const_current_task + in_GS_OFFSET))[0x15c] & 0x8000000) ==
                          0) & 0x3fffe000) + 0xc0000000;
  }
  return 0x7ffffffff000;
}


// ===== 0011ec00 os_get_max_user_va =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011ec38) */
/* WARNING: Removing unreachable block (ram,0x0011ec47) */

long os_get_max_user_va(void)

{
  long in_GS_OFFSET;
  
  if ((**(ulong **)(&const_current_task + in_GS_OFFSET) & 0x8000000) != 0) {
    return (ulong)(-(uint)(((*(ulong **)(&const_current_task + in_GS_OFFSET))[0x15c] & 0x8000000) ==
                          0) & 0x3fffe000) + 0xc0000000;
  }
  return 0x7ffffffff000;
}


// ===== 0011ec50 __pfx_os_schedule =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011ec9f) */
/* WARNING: Removing unreachable block (ram,0x0011ecba) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_os_schedule(void)

{
  ulong uVar1;
  long in_GS_OFFSET;
  
  uVar1 = (*_mpi_powm)();
  if (((uVar1 & 0x200) != 0) && ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0)) {
    LOCK();
    *(undefined4 *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0x18) = 1;
    UNLOCK();
    schedule_timeout(1);
    return 0;
  }
  nv_printf(4,"NVRM: os_schedule: Attempted to yield the CPU while in atomic or interrupt context\n"
           );
  return 0x16;
}


// ===== 0011ec60 os_schedule =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011ec9f) */
/* WARNING: Removing unreachable block (ram,0x0011ecba) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 os_schedule(void)

{
  ulong uVar1;
  long in_GS_OFFSET;
  
  uVar1 = (*_mpi_powm)();
  if (((uVar1 & 0x200) != 0) && ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0)) {
    LOCK();
    *(undefined4 *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0x18) = 1;
    UNLOCK();
    schedule_timeout(1);
    return 0;
  }
  nv_printf(4,"NVRM: os_schedule: Attempted to yield the CPU while in atomic or interrupt context\n"
           );
  return 0x16;
}


// ===== 0011ecd0 __pfx_os_queue_work_item =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011ed69) */
/* WARNING: Removing unreachable block (ram,0x0011ed88) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_os_queue_work_item(undefined1 *param_1,undefined8 param_2)

{
  undefined1 *puVar1;
  long lVar2;
  undefined8 uVar3;
  
  puVar1 = nv_kthread_q;
  if (param_1 != (undefined1 *)0x0) {
    puVar1 = param_1;
  }
  if (*(long *)(puVar1 + 0x38) != 0) {
    lVar2 = __kmalloc_cache_noprof(_capable,0x2820,0x28);
    if (lVar2 == 0) {
      uVar3 = 0x51;
    }
    else {
      nv_kthread_q_item_init(lVar2,os_execute_work_item,lVar2);
      *(undefined8 *)(lVar2 + 0x20) = param_2;
      nv_kthread_q_schedule_q_item(puVar1,lVar2);
      uVar3 = 0;
    }
    return uVar3;
  }
  nv_printf(4,"NVRM: queue is not enabled\n");
  return 0x55;
}


// ===== 0011ece0 os_queue_work_item =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011ed69) */
/* WARNING: Removing unreachable block (ram,0x0011ed88) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 os_queue_work_item(undefined1 *param_1,undefined8 param_2)

{
  undefined1 *puVar1;
  long lVar2;
  undefined8 uVar3;
  
  puVar1 = nv_kthread_q;
  if (param_1 != (undefined1 *)0x0) {
    puVar1 = param_1;
  }
  if (*(long *)(puVar1 + 0x38) != 0) {
    lVar2 = __kmalloc_cache_noprof(_capable,0x2820,0x28);
    if (lVar2 == 0) {
      uVar3 = 0x51;
    }
    else {
      nv_kthread_q_item_init(lVar2,os_execute_work_item,lVar2);
      *(undefined8 *)(lVar2 + 0x20) = param_2;
      nv_kthread_q_schedule_q_item(puVar1,lVar2);
      uVar3 = 0;
    }
    return uVar3;
  }
  nv_printf(4,"NVRM: queue is not enabled\n");
  return 0x55;
}


// ===== 0011edb0 __pfx_os_flush_work_queue =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011ee18) */
/* WARNING: Removing unreachable block (ram,0x0011ee37) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_os_flush_work_queue(undefined1 *param_1,char param_2)

{
  ulong uVar1;
  long in_GS_OFFSET;
  
  if (param_1 == (undefined1 *)0x0) {
    param_1 = nv_kthread_q;
  }
  uVar1 = (*_mpi_powm)();
  if (((uVar1 & 0x200) != 0) && ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0)) {
    param_1[0x40] = param_2 != '\0';
    if (*(long *)(param_1 + 0x38) != 0) {
      nv_kthread_q_flush();
    }
    param_1[0x40] = 0;
    return 0;
  }
  nv_printf(4,
            "NVRM: os_flush_work_queue: attempted to execute passivework from an atomic or interrupt context.\n"
           );
  return 0x16;
}


// ===== 0011edc0 os_flush_work_queue =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011ee18) */
/* WARNING: Removing unreachable block (ram,0x0011ee37) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 os_flush_work_queue(undefined1 *param_1,char param_2)

{
  ulong uVar1;
  long in_GS_OFFSET;
  
  if (param_1 == (undefined1 *)0x0) {
    param_1 = nv_kthread_q;
  }
  uVar1 = (*_mpi_powm)();
  if (((uVar1 & 0x200) != 0) && ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0)) {
    param_1[0x40] = param_2 != '\0';
    if (*(long *)(param_1 + 0x38) != 0) {
      nv_kthread_q_flush();
    }
    param_1[0x40] = 0;
    return 0;
  }
  nv_printf(4,
            "NVRM: os_flush_work_queue: attempted to execute passivework from an atomic or interrupt context.\n"
           );
  return 0x16;
}


// ===== 0011ee40 __pfx_os_is_queue_flush_ongoing =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011ee6b) */

undefined1 __pfx_os_is_queue_flush_ongoing(undefined1 *param_1)

{
  if (param_1 == (undefined1 *)0x0) {
    param_1 = nv_kthread_q;
  }
  return param_1[0x40];
}


// ===== 0011ee50 os_is_queue_flush_ongoing =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011ee6b) */

undefined1 os_is_queue_flush_ongoing(undefined1 *param_1)

{
  if (param_1 == (undefined1 *)0x0) {
    param_1 = nv_kthread_q;
  }
  return param_1[0x40];
}


// ===== 0011ee70 __pfx_os_dbg_breakpoint =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011ee89) */

void __pfx_os_dbg_breakpoint(void)

{
  return;
}


// ===== 0011ee80 os_dbg_breakpoint =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011ee89) */

void os_dbg_breakpoint(void)

{
  return;
}


// ===== 0011ee90 __pfx_os_get_cpu_number =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011eec0) */
/* WARNING: Removing unreachable block (ram,0x0011eeca) */

ulong __pfx_os_get_cpu_number(void)

{
  int *piVar1;
  ulong uVar2;
  long in_GS_OFFSET;
  
  *(int *)(&__preempt_count + in_GS_OFFSET) = *(int *)(&__preempt_count + in_GS_OFFSET) + 1;
  piVar1 = (int *)(&__preempt_count + in_GS_OFFSET);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 != 0) {
    return (ulong)*(uint *)(&cpu_number + in_GS_OFFSET);
  }
  uVar2 = __SCT__preempt_schedule();
  return uVar2;
}


// ===== 0011eea0 os_get_cpu_number =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011eec0) */
/* WARNING: Removing unreachable block (ram,0x0011eeca) */

ulong os_get_cpu_number(void)

{
  int *piVar1;
  ulong uVar2;
  long in_GS_OFFSET;
  
  *(int *)(&__preempt_count + in_GS_OFFSET) = *(int *)(&__preempt_count + in_GS_OFFSET) + 1;
  piVar1 = (int *)(&__preempt_count + in_GS_OFFSET);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 != 0) {
    return (ulong)*(uint *)(&cpu_number + in_GS_OFFSET);
  }
  uVar2 = __SCT__preempt_schedule();
  return uVar2;
}


// ===== 0011eed0 __pfx_os_get_cpu_count =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011eeef) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __pfx_os_get_cpu_count(void)

{
  return ___num_possible_cpus;
}


// ===== 0011eee0 os_get_cpu_count =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011eeef) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 os_get_cpu_count(void)

{
  return ___num_possible_cpus;
}


// ===== 0011ef00 __pfx_os_pat_supported =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011ef24) */

undefined4 __pfx_os_pat_supported(void)

{
  return CONCAT31((int3)((uint)nv_pat_mode >> 8),nv_pat_mode != 0);
}


// ===== 0011ef10 os_pat_supported =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011ef24) */

undefined4 os_pat_supported(void)

{
  return CONCAT31((int3)((uint)nv_pat_mode >> 8),nv_pat_mode != 0);
}


// ===== 0011ef30 __pfx_os_is_efi_enabled =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011ef53) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __pfx_os_is_efi_enabled(void)

{
  return (uint)__copy_to_user & 1;
}


// ===== 0011ef40 os_is_efi_enabled =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011ef53) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint os_is_efi_enabled(void)

{
  return (uint)__copy_to_user & 1;
}


// ===== 0011ef60 __pfx_os_alloc_spinlock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011efa9) */
/* WARNING: Removing unreachable block (ram,0x0011efce) */

int __pfx_os_alloc_spinlock(undefined8 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = os_alloc_mem(param_1,0x10);
  if (iVar2 == 0) {
    puVar1 = (undefined4 *)*param_1;
    *puVar1 = 0;
    *(undefined8 *)(puVar1 + 2) = 0;
    return 0;
  }
  nv_printf(4,"NVRM: failed to allocate spinlock!\n");
  return iVar2;
}


// ===== 0011ef70 os_alloc_spinlock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011efa9) */
/* WARNING: Removing unreachable block (ram,0x0011efce) */

int os_alloc_spinlock(undefined8 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = os_alloc_mem(param_1,0x10);
  if (iVar2 == 0) {
    puVar1 = (undefined4 *)*param_1;
    *puVar1 = 0;
    *(undefined8 *)(puVar1 + 2) = 0;
    return 0;
  }
  nv_printf(4,"NVRM: failed to allocate spinlock!\n");
  return iVar2;
}


// ===== 0011efe0 __pfx_os_free_spinlock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_free_spinlock(long param_1)

{
  if ((*(byte *)(param_1 + -8) & 1) != 0) {
    vfree();
    return;
  }
  kfree(param_1 + -8);
  return;
}


// ===== 0011eff0 os_free_spinlock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_free_spinlock(long param_1)

{
  if ((*(byte *)(param_1 + -8) & 1) != 0) {
    vfree();
    return;
  }
  kfree(param_1 + -8);
  return;
}


// ===== 0011f010 __pfx_os_acquire_spinlock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f03c) */

uint __pfx_os_acquire_spinlock(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = _raw_spin_lock_irqsave();
  *(undefined8 *)(param_1 + 8) = uVar1;
  return (uint)uVar1 & 0x200;
}


// ===== 0011f020 os_acquire_spinlock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f03c) */

uint os_acquire_spinlock(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = _raw_spin_lock_irqsave();
  *(undefined8 *)(param_1 + 8) = uVar1;
  return (uint)uVar1 & 0x200;
}


// ===== 0011f050 __pfx_os_release_spinlock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_release_spinlock(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(param_1 + 8) = 0;
  _raw_spin_unlock_irqrestore(param_1,uVar1);
  return;
}


// ===== 0011f060 os_release_spinlock =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_release_spinlock(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(param_1 + 8) = 0;
  _raw_spin_unlock_irqrestore(param_1,uVar1);
  return;
}


// ===== 0011f080 __pfx_os_get_version_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f0b7) */

undefined8 __pfx_os_get_version_info(undefined8 *param_1)

{
  *(undefined4 *)(param_1 + 1) = 8;
  *param_1 = 0x100000007;
  param_1[2] = "7.1.8-arch1-3";
  return 0;
}


// ===== 0011f090 os_get_version_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f0b7) */

undefined8 os_get_version_info(undefined8 *param_1)

{
  *(undefined4 *)(param_1 + 1) = 8;
  *param_1 = 0x100000007;
  param_1[2] = "7.1.8-arch1-3";
  return 0;
}


// ===== 0011f0c0 __pfx_os_get_is_openrm =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f0de) */

undefined8 __pfx_os_get_is_openrm(undefined1 *param_1)

{
  *param_1 = 1;
  return 0;
}


// ===== 0011f0d0 os_get_is_openrm =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f0de) */

undefined8 os_get_is_openrm(undefined1 *param_1)

{
  *param_1 = 1;
  return 0;
}


// ===== 0011f0f0 __pfx_os_is_bif_reset_supported =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f117) */

undefined8 __pfx_os_is_bif_reset_supported(long param_1)

{
  return CONCAT71((int7)((ulong)*(long *)(param_1 + 8) >> 8),
                  *(char *)(*(long *)(param_1 + 8) + 0x5290) == '\0');
}


// ===== 0011f100 os_is_bif_reset_supported =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f117) */

undefined8 os_is_bif_reset_supported(long param_1)

{
  return CONCAT71((int7)((ulong)*(long *)(param_1 + 8) >> 8),
                  *(char *)(*(long *)(param_1 + 8) + 0x5290) == '\0');
}


// ===== 0011f120 __pfx_os_is_xen_dom0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f13b) */

undefined8 __pfx_os_is_xen_dom0(void)

{
  return 0;
}


// ===== 0011f130 os_is_xen_dom0 =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f13b) */

undefined8 os_is_xen_dom0(void)

{
  return 0;
}


// ===== 0011f140 __pfx_os_is_vgx_hyper =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f15b) */

undefined8 __pfx_os_is_vgx_hyper(void)

{
  return 0;
}


// ===== 0011f150 os_is_vgx_hyper =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f15b) */

undefined8 os_is_vgx_hyper(void)

{
  return 0;
}


// ===== 0011f160 __pfx_os_inject_vgx_msi =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f17e) */

undefined8 __pfx_os_inject_vgx_msi(void)

{
  return 0x56;
}


// ===== 0011f170 os_inject_vgx_msi =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f17e) */

undefined8 os_inject_vgx_msi(void)

{
  return 0x56;
}


// ===== 0011f190 __pfx_os_is_grid_supported =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f1ab) */

undefined8 __pfx_os_is_grid_supported(void)

{
  return 0;
}


// ===== 0011f1a0 os_is_grid_supported =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f1ab) */

undefined8 os_is_grid_supported(void)

{
  return 0;
}


// ===== 0011f1b0 __pfx_os_get_grid_csp_support =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f1cb) */

undefined8 __pfx_os_get_grid_csp_support(void)

{
  return 0;
}


// ===== 0011f1c0 os_get_grid_csp_support =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f1cb) */

undefined8 os_get_grid_csp_support(void)

{
  return 0;
}


// ===== 0011f1d0 __pfx_os_get_euid =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f1ff) */

undefined8 __pfx_os_get_euid(undefined4 *param_1)

{
  long in_GS_OFFSET;
  
  *param_1 = *(undefined4 *)
              (*(long *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0xd38) + 0x18);
  return 0;
}


// ===== 0011f1e0 os_get_euid =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f1ff) */

undefined8 os_get_euid(undefined4 *param_1)

{
  long in_GS_OFFSET;
  
  *param_1 = *(undefined4 *)
              (*(long *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0xd38) + 0x18);
  return 0;
}


// ===== 0011f210 __pfx_os_get_smbios_header =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f45d) */
/* WARNING: Removing unreachable block (ram,0x0011f27b) */
/* WARNING: Removing unreachable block (ram,0x0011f493) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_os_get_smbios_header(long *param_1)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  char *pcVar4;
  char cVar5;
  char *pcVar6;
  char *pcVar7;
  
  if ((__copy_to_user & 1) == 0) {
    pcVar3 = (char *)os_map_kernel_space_part_0(0xf0000,0x10000,0);
    if (pcVar3 != (char *)0x0) {
      pcVar6 = pcVar3;
      if (pcVar3 < pcVar3 + 0x10000) {
        do {
          pcVar4 = &DAT_00000010;
          if (pcVar6 != (char *)0x0) {
            iVar1 = os_mem_cmp(pcVar6,"_SM3_",5);
            if ((iVar1 == 0) && ((byte)(pcVar6[6] - 1U) < 0x1f)) {
              cVar5 = '\0';
              pcVar4 = pcVar6;
              do {
                cVar5 = cVar5 + *pcVar4;
                pcVar4 = pcVar4 + 1;
              } while (pcVar4 != pcVar6 + (ulong)((byte)pcVar6[6] - 1) + 1);
              if (cVar5 != '\0') goto LAB_0011f2c1;
              *param_1 = (long)(pcVar6 + (0xf0000 - (long)pcVar3));
LAB_0011f360:
              uVar2 = 0;
              goto LAB_0011f433;
            }
LAB_0011f2c1:
            iVar1 = os_mem_cmp(pcVar6,&DAT_00daf6d8,4);
            pcVar4 = pcVar6 + 0x10;
            if (iVar1 == 0) {
              pcVar4 = pcVar6 + 0x10;
              if ((byte)(pcVar6[5] - 1U) < 0x1f) {
                cVar5 = '\0';
                pcVar4 = pcVar6;
                do {
                  cVar5 = cVar5 + *pcVar4;
                  pcVar4 = pcVar4 + 1;
                } while (pcVar4 != pcVar6 + (ulong)((byte)pcVar6[5] - 1) + 1);
                pcVar4 = pcVar6 + 0x10;
                if ((cVar5 == '\0') && (iVar1 = os_mem_cmp(pcVar4,"_DMI_",5), iVar1 == 0)) {
                  cVar5 = '\0';
                  pcVar7 = pcVar4;
                  do {
                    cVar5 = cVar5 + *pcVar7;
                    pcVar7 = pcVar7 + 1;
                  } while (pcVar7 != pcVar6 + 0x1f);
                  if (cVar5 == '\0') {
                    *param_1 = (long)(pcVar6 + (0xf0000 - (long)pcVar3));
                    goto LAB_0011f360;
                  }
                }
              }
            }
          }
          pcVar6 = pcVar4;
        } while (pcVar3 + 0x10000 != pcVar4);
      }
      uVar2 = 0x59;
LAB_0011f433:
      if (pcVar3 == _page_offset_base) {
        return uVar2;
      }
      iounmap(pcVar3);
      return uVar2;
    }
    uVar2 = 0x1a;
  }
  else {
    uVar2 = 0x59;
    if ((_this_cpu_off == -1) || (uVar2 = os_verify_smbios_header_uefi(), (int)uVar2 != 0)) {
      if ((___trace_trigger_soft_disabled != -1) &&
         (uVar2 = os_verify_smbios_header_uefi(), (int)uVar2 == 0)) {
        *param_1 = ___trace_trigger_soft_disabled;
      }
    }
    else {
      *param_1 = _this_cpu_off;
    }
  }
  return uVar2;
}


// ===== 0011f220 os_get_smbios_header =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f45d) */
/* WARNING: Removing unreachable block (ram,0x0011f27b) */
/* WARNING: Removing unreachable block (ram,0x0011f493) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 os_get_smbios_header(long *param_1)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  char *pcVar4;
  char cVar5;
  char *pcVar6;
  char *pcVar7;
  
  if ((__copy_to_user & 1) == 0) {
    pcVar3 = (char *)os_map_kernel_space_part_0(0xf0000,0x10000,0);
    if (pcVar3 != (char *)0x0) {
      pcVar6 = pcVar3;
      if (pcVar3 < pcVar3 + 0x10000) {
        do {
          pcVar4 = &DAT_00000010;
          if (pcVar6 != (char *)0x0) {
            iVar1 = os_mem_cmp(pcVar6,"_SM3_",5);
            if ((iVar1 == 0) && ((byte)(pcVar6[6] - 1U) < 0x1f)) {
              cVar5 = '\0';
              pcVar4 = pcVar6;
              do {
                cVar5 = cVar5 + *pcVar4;
                pcVar4 = pcVar4 + 1;
              } while (pcVar4 != pcVar6 + (ulong)((byte)pcVar6[6] - 1) + 1);
              if (cVar5 != '\0') goto LAB_0011f2c1;
              *param_1 = (long)(pcVar6 + (0xf0000 - (long)pcVar3));
LAB_0011f360:
              uVar2 = 0;
              goto LAB_0011f433;
            }
LAB_0011f2c1:
            iVar1 = os_mem_cmp(pcVar6,&DAT_00daf6d8,4);
            pcVar4 = pcVar6 + 0x10;
            if (iVar1 == 0) {
              pcVar4 = pcVar6 + 0x10;
              if ((byte)(pcVar6[5] - 1U) < 0x1f) {
                cVar5 = '\0';
                pcVar4 = pcVar6;
                do {
                  cVar5 = cVar5 + *pcVar4;
                  pcVar4 = pcVar4 + 1;
                } while (pcVar4 != pcVar6 + (ulong)((byte)pcVar6[5] - 1) + 1);
                pcVar4 = pcVar6 + 0x10;
                if ((cVar5 == '\0') && (iVar1 = os_mem_cmp(pcVar4,"_DMI_",5), iVar1 == 0)) {
                  cVar5 = '\0';
                  pcVar7 = pcVar4;
                  do {
                    cVar5 = cVar5 + *pcVar7;
                    pcVar7 = pcVar7 + 1;
                  } while (pcVar7 != pcVar6 + 0x1f);
                  if (cVar5 == '\0') {
                    *param_1 = (long)(pcVar6 + (0xf0000 - (long)pcVar3));
                    goto LAB_0011f360;
                  }
                }
              }
            }
          }
          pcVar6 = pcVar4;
        } while (pcVar3 + 0x10000 != pcVar4);
      }
      uVar2 = 0x59;
LAB_0011f433:
      if (pcVar3 == _page_offset_base) {
        return uVar2;
      }
      iounmap(pcVar3);
      return uVar2;
    }
    uVar2 = 0x1a;
  }
  else {
    uVar2 = 0x59;
    if ((_this_cpu_off == -1) || (uVar2 = os_verify_smbios_header_uefi(), (int)uVar2 != 0)) {
      if ((___trace_trigger_soft_disabled != -1) &&
         (uVar2 = os_verify_smbios_header_uefi(), (int)uVar2 == 0)) {
        *param_1 = ___trace_trigger_soft_disabled;
      }
    }
    else {
      *param_1 = _this_cpu_off;
    }
  }
  return uVar2;
}


// ===== 0011f4a0 __pfx_os_get_acpi_rsdp_from_uefi =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f507) */
/* WARNING: Removing unreachable block (ram,0x0011f4d5) */
/* WARNING: Removing unreachable block (ram,0x0011f4df) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_os_get_acpi_rsdp_from_uefi(undefined4 *param_1)

{
  long lVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    return 0x40;
  }
  *param_1 = 0;
  lVar1 = _const_current_task;
  if ((_const_current_task == -1) &&
     (lVar1 = ___dma_sync_single_for_device, ___dma_sync_single_for_device == -1)) {
    nv_printf(4,"NVRM: RSDP Not found!\n");
    return 0x59;
  }
  *param_1 = (int)lVar1;
  return 0;
}


// ===== 0011f4b0 os_get_acpi_rsdp_from_uefi =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f507) */
/* WARNING: Removing unreachable block (ram,0x0011f4d5) */
/* WARNING: Removing unreachable block (ram,0x0011f4df) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 os_get_acpi_rsdp_from_uefi(undefined4 *param_1)

{
  long lVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    return 0x40;
  }
  *param_1 = 0;
  lVar1 = _const_current_task;
  if ((_const_current_task == -1) &&
     (lVar1 = ___dma_sync_single_for_device, ___dma_sync_single_for_device == -1)) {
    nv_printf(4,"NVRM: RSDP Not found!\n");
    return 0x59;
  }
  *param_1 = (int)lVar1;
  return 0;
}


// ===== 0011f510 __pfx_os_add_record_for_crashLog =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f529) */

void __pfx_os_add_record_for_crashLog(void)

{
  return;
}


// ===== 0011f520 os_add_record_for_crashLog =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f529) */

void os_add_record_for_crashLog(void)

{
  return;
}


// ===== 0011f530 __pfx_os_delete_record_for_crashLog =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f549) */

void __pfx_os_delete_record_for_crashLog(void)

{
  return;
}


// ===== 0011f540 os_delete_record_for_crashLog =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f549) */

void os_delete_record_for_crashLog(void)

{
  return;
}


// ===== 0011f550 __pfx_os_call_vgpu_vfio =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f56e) */

undefined8 __pfx_os_call_vgpu_vfio(void)

{
  return 0x56;
}


// ===== 0011f560 os_call_vgpu_vfio =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f56e) */

undefined8 os_call_vgpu_vfio(void)

{
  return 0x56;
}


// ===== 0011f580 __pfx_os_alloc_pages_node =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f64f) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_os_alloc_pages_node(uint param_1,uint param_2,uint param_3,long *param_4)

{
  long lVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  int iVar5;
  ulong uVar6;
  int iVar7;
  long in_GS_OFFSET;
  int iStack_2c;
  long lStack_28;
  
  uVar6 = (ulong)param_2 - 1 >> 0xc;
  lVar1 = 0x3f;
  if (uVar6 != 0) {
    for (; uVar6 >> lVar1 == 0; lVar1 = lVar1 + -1) {
    }
  }
  iVar5 = (int)lVar1 + 1;
  lStack_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  iVar7 = (-(uint)((param_3 & 1) == 0) & 0xc00) + 0x3460ca;
  uVar2 = param_1;
  if (param_1 == 0xffffffff) {
    uVar2 = *(uint *)(&numa_node + in_GS_OFFSET);
  }
  iStack_2c = iVar7;
  if (((byte)__release_region[(long)(int)uVar2 >> 3] >> ((long)(int)uVar2 & 7U) & 1) == 0) {
    _printk(&DAT_00db4d38,&iStack_2c);
    dump_stack();
  }
  puVar3 = (undefined8 *)__alloc_pages_noprof(iVar7,iVar5,uVar2,0);
  if (puVar3 == (undefined8 *)0x0) {
    nv_printf(0,"NVRM: alloc_pages_node(node = %d, order = %u) failed\n",param_1,iVar5);
  }
  else {
    if (param_1 == (uint)((ulong)*puVar3 >> 0x36)) {
      uVar4 = 0;
      *param_4 = ((long)puVar3 - _vmemmap_base >> 6) << 0xc;
      goto LAB_0011f638;
    }
    nv_printf(4,"NVRM: alloc_pages_node(node = %d, order = %u) wrong node ID.\n",param_1,iVar5);
    __free_pages(puVar3,iVar5);
  }
  uVar4 = 0x51;
LAB_0011f638:
  if (lStack_28 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011f590 os_alloc_pages_node =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f64f) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 os_alloc_pages_node(uint param_1,uint param_2,uint param_3,long *param_4)

{
  long lVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  int iVar5;
  ulong uVar6;
  int iVar7;
  long in_GS_OFFSET;
  int local_2c;
  long local_28;
  
  uVar6 = (ulong)param_2 - 1 >> 0xc;
  lVar1 = 0x3f;
  if (uVar6 != 0) {
    for (; uVar6 >> lVar1 == 0; lVar1 = lVar1 + -1) {
    }
  }
  iVar5 = (int)lVar1 + 1;
  local_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  iVar7 = (-(uint)((param_3 & 1) == 0) & 0xc00) + 0x3460ca;
  uVar2 = param_1;
  if (param_1 == 0xffffffff) {
    uVar2 = *(uint *)(&numa_node + in_GS_OFFSET);
  }
  local_2c = iVar7;
  if (((byte)__release_region[(long)(int)uVar2 >> 3] >> ((long)(int)uVar2 & 7U) & 1) == 0) {
    _printk(&DAT_00db4d38,&local_2c);
    dump_stack();
  }
  puVar3 = (undefined8 *)__alloc_pages_noprof(iVar7,iVar5,uVar2,0);
  if (puVar3 == (undefined8 *)0x0) {
    nv_printf(0,"NVRM: alloc_pages_node(node = %d, order = %u) failed\n",param_1,iVar5);
  }
  else {
    if (param_1 == (uint)((ulong)*puVar3 >> 0x36)) {
      uVar4 = 0;
      *param_4 = ((long)puVar3 - _vmemmap_base >> 6) << 0xc;
      goto LAB_0011f638;
    }
    nv_printf(4,"NVRM: alloc_pages_node(node = %d, order = %u) wrong node ID.\n",param_1,iVar5);
    __free_pages(puVar3,iVar5);
  }
  uVar4 = 0x51;
LAB_0011f638:
  if (local_28 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011f6a0 __pfx_os_get_page =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f6f6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_os_get_page(ulong param_1)

{
  int *piVar1;
  char cVar2;
  ulong uVar3;
  code *pcVar4;
  ulong uVar5;
  
  uVar5 = (param_1 >> 0xc) * 0x40 + _vmemmap_base;
  uVar3 = *(ulong *)(uVar5 + 8);
  uVar5 = (uVar3 | (ulong)((uint)uVar3 & 1) - 1) & uVar5;
  cVar2 = *(char *)(uVar5 + 0x33);
  if (cVar2 == -0xb) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  if (cVar2 != -8) {
    LOCK();
    piVar1 = (int *)(uVar5 + 0x34);
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    return 0;
  }
                    /* WARNING: Does not return */
  pcVar4 = (code *)invalidInstructionException();
  (*pcVar4)();
}


// ===== 0011f6b0 os_get_page =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f6f6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 os_get_page(ulong param_1)

{
  int *piVar1;
  char cVar2;
  ulong uVar3;
  code *pcVar4;
  ulong uVar5;
  
  uVar5 = (param_1 >> 0xc) * 0x40 + _vmemmap_base;
  uVar3 = *(ulong *)(uVar5 + 8);
  uVar5 = (uVar3 | (ulong)((uint)uVar3 & 1) - 1) & uVar5;
  cVar2 = *(char *)(uVar5 + 0x33);
  if (cVar2 == -0xb) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  if (cVar2 != -8) {
    LOCK();
    piVar1 = (int *)(uVar5 + 0x34);
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    return 0;
  }
                    /* WARNING: Does not return */
  pcVar4 = (code *)invalidInstructionException();
  (*pcVar4)();
}


// ===== 0011f710 __pfx_os_put_page =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f769) */
/* WARNING: Removing unreachable block (ram,0x0011f775) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_os_put_page(ulong param_1)

{
  int *piVar1;
  char cVar2;
  ulong uVar3;
  ulong uVar4;
  
  uVar4 = (param_1 >> 0xc) * 0x40 + _vmemmap_base;
  uVar3 = *(ulong *)(uVar4 + 8);
  uVar4 = (uVar3 | (ulong)((uint)uVar3 & 1) - 1) & uVar4;
  cVar2 = *(char *)(uVar4 + 0x33);
  if ((cVar2 != -0xb) && (cVar2 != -8)) {
    LOCK();
    piVar1 = (int *)(uVar4 + 0x34);
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 == 0) {
      __folio_put();
      return 0;
    }
  }
  return 0;
}


// ===== 0011f720 os_put_page =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f769) */
/* WARNING: Removing unreachable block (ram,0x0011f775) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 os_put_page(ulong param_1)

{
  int *piVar1;
  char cVar2;
  ulong uVar3;
  ulong uVar4;
  
  uVar4 = (param_1 >> 0xc) * 0x40 + _vmemmap_base;
  uVar3 = *(ulong *)(uVar4 + 8);
  uVar4 = (uVar3 | (ulong)((uint)uVar3 & 1) - 1) & uVar4;
  cVar2 = *(char *)(uVar4 + 0x33);
  if ((cVar2 != -0xb) && (cVar2 != -8)) {
    LOCK();
    piVar1 = (int *)(uVar4 + 0x34);
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 == 0) {
      __folio_put();
      return 0;
    }
  }
  return 0;
}


// ===== 0011f780 __pfx_os_get_page_refcount =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f7bf) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __pfx_os_get_page_refcount(ulong param_1)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar2 = (param_1 >> 0xc) * 0x40 + _vmemmap_base;
  uVar1 = *(ulong *)(uVar2 + 8);
  return *(undefined4 *)(((uVar1 | (ulong)((uint)uVar1 & 1) - 1) & uVar2) + 0x34);
}


// ===== 0011f790 os_get_page_refcount =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f7bf) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 os_get_page_refcount(ulong param_1)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar2 = (param_1 >> 0xc) * 0x40 + _vmemmap_base;
  uVar1 = *(ulong *)(uVar2 + 8);
  return *(undefined4 *)(((uVar1 | (ulong)((uint)uVar1 & 1) - 1) & uVar2) + 0x34);
}


// ===== 0011f7d0 __pfx_os_count_tail_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f822) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __pfx_os_count_tail_pages(ulong param_1)

{
  ulong uVar1;
  ulong *puVar2;
  int iVar3;
  ulong uVar4;
  
  uVar4 = (param_1 >> 0xc) * 0x40 + _vmemmap_base;
  uVar1 = *(ulong *)(uVar4 + 8);
  iVar3 = 1;
  puVar2 = (ulong *)((uVar1 | (ulong)((uint)uVar1 & 1) - 1) & uVar4);
  if ((*puVar2 & 0x40) != 0) {
    iVar3 = 1 << ((byte)puVar2[8] & 0x1f);
  }
  return iVar3;
}


// ===== 0011f7e0 os_count_tail_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f822) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int os_count_tail_pages(ulong param_1)

{
  ulong uVar1;
  ulong *puVar2;
  int iVar3;
  ulong uVar4;
  
  uVar4 = (param_1 >> 0xc) * 0x40 + _vmemmap_base;
  uVar1 = *(ulong *)(uVar4 + 8);
  iVar3 = 1;
  puVar2 = (ulong *)((uVar1 | (ulong)((uint)uVar1 & 1) - 1) & uVar4);
  if ((*puVar2 & 0x40) != 0) {
    iVar3 = 1 << ((byte)puVar2[8] & 0x1f);
  }
  return iVar3;
}


// ===== 0011f830 __pfx_os_free_pages_phys =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __pfx_os_free_pages_phys(ulong param_1,ulong param_2)

{
  long lVar1;
  ulong uVar2;
  
  uVar2 = (param_2 & 0xffffffff) - 1 >> 0xc;
  lVar1 = 0x3f;
  if (uVar2 != 0) {
    for (; uVar2 >> lVar1 == 0; lVar1 = lVar1 + -1) {
    }
  }
  __free_pages((param_1 >> 0xc) * 0x40 + _vmemmap_base,(int)lVar1 + 1);
  return;
}


// ===== 0011f840 os_free_pages_phys =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void os_free_pages_phys(ulong param_1,ulong param_2)

{
  long lVar1;
  ulong uVar2;
  
  uVar2 = (param_2 & 0xffffffff) - 1 >> 0xc;
  lVar1 = 0x3f;
  if (uVar2 != 0) {
    for (; uVar2 >> lVar1 == 0; lVar1 = lVar1 + -1) {
    }
  }
  __free_pages((param_1 >> 0xc) * 0x40 + _vmemmap_base,(int)lVar1 + 1);
  return;
}


// ===== 0011f880 __pfx_os_numa_memblock_size =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f8a8) */

undefined8 __pfx_os_numa_memblock_size(undefined8 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = memory_block_size_bytes();
  *param_1 = uVar1;
  return 0;
}


// ===== 0011f890 os_numa_memblock_size =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f8a8) */

undefined8 os_numa_memblock_size(undefined8 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = memory_block_size_bytes();
  *param_1 = uVar1;
  return 0;
}


// ===== 0011f8b0 __pfx_os_open_temporary_file =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f94b) */
/* WARNING: Removing unreachable block (ram,0x0011f919) */
/* WARNING: Removing unreachable block (ram,0x0011f955) */

undefined8 __pfx_os_open_temporary_file(ulong *param_1)

{
  undefined *puVar1;
  ulong uVar2;
  long in_GS_OFFSET;
  
  puVar1 = NVreg_TemporaryFilePath;
  if (*(long *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0xd88) == 0) {
    return 0x59;
  }
  if (NVreg_TemporaryFilePath != (undefined *)0x0) {
    uVar2 = filp_open(NVreg_TemporaryFilePath,0x418002,0);
    if ((uVar2 != 0xfffffffffffffffe) || (puVar1 == &DAT_00daf751)) goto LAB_0011f90a;
    nv_printf(4,
              "NVRM: The temporary file path specified via the NVreg_TemporaryFilePath\nNVRM: module parameter does not exist. Defaulting to /tmp.\n"
             );
  }
  uVar2 = filp_open(&DAT_00daf751,0x418002,0);
LAB_0011f90a:
  if (uVar2 < 0xfffffffffffff001) {
    *param_1 = uVar2;
    return 0;
  }
  return 0x59;
}


// ===== 0011f8c0 os_open_temporary_file =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011f94b) */
/* WARNING: Removing unreachable block (ram,0x0011f919) */
/* WARNING: Removing unreachable block (ram,0x0011f955) */

undefined8 os_open_temporary_file(ulong *param_1)

{
  undefined *puVar1;
  ulong uVar2;
  long in_GS_OFFSET;
  
  puVar1 = NVreg_TemporaryFilePath;
  if (*(long *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0xd88) == 0) {
    return 0x59;
  }
  if (NVreg_TemporaryFilePath != (undefined *)0x0) {
    uVar2 = filp_open(NVreg_TemporaryFilePath,0x418002,0);
    if ((uVar2 != 0xfffffffffffffffe) || (puVar1 == &DAT_00daf751)) goto LAB_0011f90a;
    nv_printf(4,
              "NVRM: The temporary file path specified via the NVreg_TemporaryFilePath\nNVRM: module parameter does not exist. Defaulting to /tmp.\n"
             );
  }
  uVar2 = filp_open(&DAT_00daf751,0x418002,0);
LAB_0011f90a:
  if (uVar2 < 0xfffffffffffff001) {
    *param_1 = uVar2;
    return 0;
  }
  return 0x59;
}


// ===== 0011f960 __pfx_os_close_file =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_close_file(undefined8 param_1)

{
  filp_close(param_1,0);
  return;
}


// ===== 0011f970 os_close_file =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_close_file(undefined8 param_1)

{
  filp_close(param_1,0);
  return;
}


// ===== 0011f980 __pfx_os_write_file =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011fa22) */

undefined8 __pfx_os_write_file(undefined8 param_1,long param_2,ulong param_3,undefined8 param_4)

{
  ulong uVar1;
  undefined8 uVar2;
  int iVar3;
  long in_GS_OFFSET;
  undefined8 uStack_38;
  long lStack_30;
  
  iVar3 = 10;
  lStack_30 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_38 = param_4;
  while( true ) {
    uVar1 = kernel_write(param_1,param_2,param_3,&uStack_38);
    if ((long)uVar1 < 0) break;
    if (param_3 <= uVar1) {
      uVar2 = 0;
      goto LAB_0011fa09;
    }
    if (uVar1 != 0) {
      param_2 = param_2 + uVar1;
    }
    if (uVar1 != 0) {
      param_3 = param_3 - uVar1;
    }
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) break;
    __SCT__cond_resched();
  }
  uVar2 = 0x59;
LAB_0011fa09:
  if (lStack_30 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011f990 os_write_file =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011fa22) */

undefined8 os_write_file(undefined8 param_1,long param_2,ulong param_3,undefined8 param_4)

{
  ulong uVar1;
  undefined8 uVar2;
  int iVar3;
  long in_GS_OFFSET;
  undefined8 local_38;
  long local_30;
  
  iVar3 = 10;
  local_30 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_38 = param_4;
  while( true ) {
    uVar1 = kernel_write(param_1,param_2,param_3,&local_38);
    if ((long)uVar1 < 0) break;
    if (param_3 <= uVar1) {
      uVar2 = 0;
      goto LAB_0011fa09;
    }
    if (uVar1 != 0) {
      param_2 = param_2 + uVar1;
    }
    if (uVar1 != 0) {
      param_3 = param_3 - uVar1;
    }
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) break;
    __SCT__cond_resched();
  }
  uVar2 = 0x59;
LAB_0011fa09:
  if (local_30 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011fa30 __pfx_os_read_file =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011fad2) */

undefined8 __pfx_os_read_file(undefined8 param_1,long param_2,ulong param_3,undefined8 param_4)

{
  ulong uVar1;
  undefined8 uVar2;
  int iVar3;
  long in_GS_OFFSET;
  undefined8 uStack_38;
  long lStack_30;
  
  iVar3 = 10;
  lStack_30 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_38 = param_4;
  while( true ) {
    uVar1 = kernel_read(param_1,param_2,param_3,&uStack_38);
    if ((long)uVar1 < 0) break;
    if (param_3 <= uVar1) {
      uVar2 = 0;
      goto LAB_0011fab9;
    }
    if (uVar1 != 0) {
      param_2 = param_2 + uVar1;
    }
    if (uVar1 != 0) {
      param_3 = param_3 - uVar1;
    }
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) break;
    __SCT__cond_resched();
  }
  uVar2 = 0x59;
LAB_0011fab9:
  if (lStack_30 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011fa40 os_read_file =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011fad2) */

undefined8 os_read_file(undefined8 param_1,long param_2,ulong param_3,undefined8 param_4)

{
  ulong uVar1;
  undefined8 uVar2;
  int iVar3;
  long in_GS_OFFSET;
  undefined8 local_38;
  long local_30;
  
  iVar3 = 10;
  local_30 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_38 = param_4;
  while( true ) {
    uVar1 = kernel_read(param_1,param_2,param_3,&local_38);
    if ((long)uVar1 < 0) break;
    if (param_3 <= uVar1) {
      uVar2 = 0;
      goto LAB_0011fab9;
    }
    if (uVar1 != 0) {
      param_2 = param_2 + uVar1;
    }
    if (uVar1 != 0) {
      param_3 = param_3 - uVar1;
    }
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) break;
    __SCT__cond_resched();
  }
  uVar2 = 0x59;
LAB_0011fab9:
  if (local_30 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011fae0 __pfx_os_open_readonly_file =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011fb31) */
/* WARNING: Removing unreachable block (ram,0x0011fb26) */
/* WARNING: Removing unreachable block (ram,0x0011fb3b) */

undefined8 __pfx_os_open_readonly_file(undefined8 param_1,ulong *param_2)

{
  ulong uVar1;
  long in_GS_OFFSET;
  
  if (*(long *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0xd88) == 0) {
    return 0x59;
  }
  uVar1 = filp_open(param_1,0,0);
  if (uVar1 < 0xfffffffffffff001) {
    *param_2 = uVar1;
    return 0;
  }
  return 0x59;
}


// ===== 0011faf0 os_open_readonly_file =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011fb31) */
/* WARNING: Removing unreachable block (ram,0x0011fb26) */
/* WARNING: Removing unreachable block (ram,0x0011fb3b) */

undefined8 os_open_readonly_file(undefined8 param_1,ulong *param_2)

{
  ulong uVar1;
  long in_GS_OFFSET;
  
  if (*(long *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0xd88) == 0) {
    return 0x59;
  }
  uVar1 = filp_open(param_1,0,0);
  if (uVar1 < 0xfffffffffffff001) {
    *param_2 = uVar1;
    return 0;
  }
  return 0x59;
}


// ===== 0011fb40 __pfx_os_open_and_read_file =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011fc39) */

undefined8 __pfx_os_open_and_read_file(undefined8 param_1,long param_2,ulong param_3)

{
  ulong uVar1;
  ulong uVar2;
  undefined8 uVar3;
  int iVar4;
  long in_GS_OFFSET;
  undefined8 uStack_38;
  long lStack_30;
  
  lStack_30 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if ((*(long *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0xd88) == 0) ||
     (uVar1 = filp_open(param_1,0,0), 0xfffffffffffff000 < uVar1)) {
    uVar3 = 0x59;
  }
  else {
    iVar4 = 10;
    uStack_38 = 0;
    while (uVar2 = kernel_read(uVar1,param_2,param_3,&uStack_38), -1 < (long)uVar2) {
      if (param_3 <= uVar2) {
        uVar3 = 0;
        goto LAB_0011fc06;
      }
      if (uVar2 != 0) {
        param_2 = param_2 + uVar2;
      }
      if (uVar2 != 0) {
        param_3 = param_3 - uVar2;
      }
      iVar4 = iVar4 + -1;
      if (iVar4 == 0) break;
      __SCT__cond_resched();
    }
    uVar3 = 0x59;
LAB_0011fc06:
    filp_close(uVar1,0);
  }
  if (lStack_30 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}


// ===== 0011fb50 os_open_and_read_file =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011fc39) */

undefined8 os_open_and_read_file(undefined8 param_1,long param_2,ulong param_3)

{
  ulong uVar1;
  ulong uVar2;
  undefined8 uVar3;
  int iVar4;
  long in_GS_OFFSET;
  undefined8 local_38;
  long local_30;
  
  local_30 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if ((*(long *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0xd88) == 0) ||
     (uVar1 = filp_open(param_1,0,0), 0xfffffffffffff000 < uVar1)) {
    uVar3 = 0x59;
  }
  else {
    iVar4 = 10;
    local_38 = 0;
    while (uVar2 = kernel_read(uVar1,param_2,param_3,&local_38), -1 < (long)uVar2) {
      if (param_3 <= uVar2) {
        uVar3 = 0;
        goto LAB_0011fc06;
      }
      if (uVar2 != 0) {
        param_2 = param_2 + uVar2;
      }
      if (uVar2 != 0) {
        param_3 = param_3 - uVar2;
      }
      iVar4 = iVar4 + -1;
      if (iVar4 == 0) break;
      __SCT__cond_resched();
    }
    uVar3 = 0x59;
LAB_0011fc06:
    filp_close(uVar1,0);
  }
  if (local_30 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}


// ===== 0011fc70 __pfx_os_is_nvswitch_present =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011fd1d) */

bool __pfx_os_is_nvswitch_present(void)

{
  int iVar1;
  long in_GS_OFFSET;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  undefined8 uStack_20;
  undefined8 uStack_18;
  long lStack_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x11fc89;
  lStack_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_48 = 0;
  uStack_60 = 0xffffffff000010de;
  uStack_40 = 0;
  uStack_38 = 0;
  uStack_30 = 0;
  uStack_28 = 0;
  uStack_20 = 0;
  uStack_18 = 0;
  uStack_58 = 0xffffffffffffffff;
  uStack_50 = 0xffffffff00068000;
  iVar1 = pci_dev_present(&uStack_60);
  if (lStack_10 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return iVar1 != 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011fc80 os_is_nvswitch_present =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011fd1d) */

bool os_is_nvswitch_present(void)

{
  int iVar1;
  long in_GS_OFFSET;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  long local_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x11fc89;
  local_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_48 = 0;
  local_60 = 0xffffffff000010de;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  local_28 = 0;
  local_20 = 0;
  local_18 = 0;
  local_58 = 0xffffffffffffffff;
  local_50 = 0xffffffff00068000;
  iVar1 = pci_dev_present(&local_60);
  if (local_10 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return iVar1 != 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 0011fd30 __pfx_os_get_random_bytes =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011fd70) */
/* WARNING: Removing unreachable block (ram,0x0011fd7f) */

undefined8 __pfx_os_get_random_bytes(undefined8 param_1,undefined2 param_2)

{
  int iVar1;
  
  iVar1 = wait_for_random_bytes();
  if (-1 < iVar1) {
    get_random_bytes(param_1,param_2);
    return 0;
  }
  return 0x55;
}


// ===== 0011fd40 os_get_random_bytes =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011fd70) */
/* WARNING: Removing unreachable block (ram,0x0011fd7f) */

undefined8 os_get_random_bytes(undefined8 param_1,undefined2 param_2)

{
  int iVar1;
  
  iVar1 = wait_for_random_bytes();
  if (-1 < iVar1) {
    get_random_bytes(param_1,param_2);
    return 0;
  }
  return 0x55;
}


// ===== 0011fd90 __pfx_os_get_current_process_flags =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011fdc9) */

uint __pfx_os_get_current_process_flags(void)

{
  uint uVar1;
  long in_GS_OFFSET;
  
  uVar1 = *(uint *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0x2c) >> 1 & 2;
  if ((*(uint *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0x2c) & 0x200000) != 0) {
    uVar1 = uVar1 | 1;
  }
  return uVar1;
}


// ===== 0011fda0 os_get_current_process_flags =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011fdc9) */

uint os_get_current_process_flags(void)

{
  uint uVar1;
  long in_GS_OFFSET;
  
  uVar1 = *(uint *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0x2c) >> 1 & 2;
  if ((*(uint *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0x2c) & 0x200000) != 0) {
    uVar1 = uVar1 | 1;
  }
  return uVar1;
}


// ===== 0011fdd0 __pfx_os_alloc_wait_queue =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011fe2b) */
/* WARNING: Removing unreachable block (ram,0x0011fe36) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_os_alloc_wait_queue(undefined8 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)__kmalloc_cache_noprof(___alloc_pages_noprof,0x2cc0,0x20);
  *param_1 = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    __init_swait_queue_head(puVar1 + 2,"&x->wait",0x546205);
    return 0;
  }
  return 0x51;
}


// ===== 0011fde0 os_alloc_wait_queue =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011fe2b) */
/* WARNING: Removing unreachable block (ram,0x0011fe36) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 os_alloc_wait_queue(undefined8 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)__kmalloc_cache_noprof(___alloc_pages_noprof,0x2cc0,0x20);
  *param_1 = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    __init_swait_queue_head(puVar1 + 2,"&x->wait",0x546205);
    return 0;
  }
  return 0x51;
}


// ===== 0011fe40 __pfx_os_free_wait_queue =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_free_wait_queue(void)

{
  kfree();
  return;
}


// ===== 0011fe50 os_free_wait_queue =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_free_wait_queue(void)

{
  kfree();
  return;
}


// ===== 0011fe60 __pfx_os_wait_uninterruptible =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_wait_uninterruptible(void)

{
  wait_for_completion();
  return;
}


// ===== 0011fe70 os_wait_uninterruptible =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_wait_uninterruptible(void)

{
  wait_for_completion();
  return;
}


// ===== 0011fe80 __pfx_os_wait_interruptible =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_wait_interruptible(void)

{
  wait_for_completion_interruptible();
  return;
}


// ===== 0011fe90 os_wait_interruptible =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_wait_interruptible(void)

{
  wait_for_completion_interruptible();
  return;
}


// ===== 0011fea0 __pfx_os_wake_up =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_wake_up(void)

{
  complete_all();
  return;
}


// ===== 0011feb0 os_wake_up =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_wake_up(void)

{
  complete_all();
  return;
}


// ===== 0011fec0 __pfx_os_get_tegra_platform =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011fede) */

undefined8 __pfx_os_get_tegra_platform(void)

{
  return 0x56;
}


// ===== 0011fed0 os_get_tegra_platform =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0011fede) */

undefined8 os_get_tegra_platform(void)

{
  return 0x56;
}


// ===== 0011fef0 __pfx_os_nv_cap_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_nv_cap_init(void)

{
  nv_cap_init();
  return;
}


// ===== 0011ff00 os_nv_cap_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_nv_cap_init(void)

{
  nv_cap_init();
  return;
}


// ===== 0011ff10 __pfx_os_nv_cap_create_dir_entry =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_nv_cap_create_dir_entry(void)

{
  nv_cap_create_dir_entry();
  return;
}


// ===== 0011ff20 os_nv_cap_create_dir_entry =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_nv_cap_create_dir_entry(void)

{
  nv_cap_create_dir_entry();
  return;
}


// ===== 0011ff30 __pfx_os_nv_cap_create_file_entry =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_nv_cap_create_file_entry(void)

{
  nv_cap_create_file_entry();
  return;
}


// ===== 0011ff40 os_nv_cap_create_file_entry =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_nv_cap_create_file_entry(void)

{
  nv_cap_create_file_entry();
  return;
}


// ===== 0011ff50 __pfx_os_nv_cap_destroy_entry =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_nv_cap_destroy_entry(void)

{
  nv_cap_destroy_entry();
  return;
}


// ===== 0011ff60 os_nv_cap_destroy_entry =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_nv_cap_destroy_entry(void)

{
  nv_cap_destroy_entry();
  return;
}


// ===== 0011ff70 __pfx_os_nv_cap_validate_and_dup_fd =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_nv_cap_validate_and_dup_fd(void)

{
  nv_cap_validate_and_dup_fd();
  return;
}


// ===== 0011ff80 os_nv_cap_validate_and_dup_fd =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_nv_cap_validate_and_dup_fd(void)

{
  nv_cap_validate_and_dup_fd();
  return;
}


// ===== 0011ff90 __pfx_os_nv_cap_close_fd =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_nv_cap_close_fd(void)

{
  nv_cap_close_fd();
  return;
}


// ===== 0011ffa0 os_nv_cap_close_fd =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_nv_cap_close_fd(void)

{
  nv_cap_close_fd();
  return;
}


// ===== 0011ffb0 __pfx_os_imex_channel_count =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_imex_channel_count(void)

{
  nv_caps_imex_channel_count();
  return;
}


// ===== 0011ffc0 os_imex_channel_count =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_imex_channel_count(void)

{
  nv_caps_imex_channel_count();
  return;
}


// ===== 0011ffd0 __pfx_os_imex_channel_get =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_imex_channel_get(void)

{
  nv_caps_imex_channel_get();
  return;
}


// ===== 0011ffe0 os_imex_channel_get =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_imex_channel_get(void)

{
  nv_caps_imex_channel_get();
  return;
}


// ===== 0011fff0 __pfx_os_tegra_igpu_perf_boost =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00120063) */
/* WARNING: Removing unreachable block (ram,0x00120035) */
/* WARNING: Removing unreachable block (ram,0x00120059) */

byte __pfx_os_tegra_igpu_perf_boost(long param_1,char param_2,undefined4 param_3)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_1 + 8);
  if (param_2 == '\0') {
    if (*(code **)(lVar1 + 0x5288) != (code *)0x0) {
      iVar2 = (**(code **)(lVar1 + 0x5288))(*(undefined8 *)(lVar1 + 0x3b0));
      return -(iVar2 != 0) & 0x59;
    }
  }
  else if (*(code **)(lVar1 + 0x5280) != (code *)0x0) {
    iVar2 = (**(code **)(lVar1 + 0x5280))(*(undefined8 *)(lVar1 + 0x3b0),param_3);
    return -(iVar2 != 0) & 0x59;
  }
  return 0x56;
}


// ===== 00120000 os_tegra_igpu_perf_boost =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00120063) */
/* WARNING: Removing unreachable block (ram,0x00120035) */
/* WARNING: Removing unreachable block (ram,0x00120059) */

byte os_tegra_igpu_perf_boost(long param_1,char param_2,undefined4 param_3)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_1 + 8);
  if (param_2 == '\0') {
    if (*(code **)(lVar1 + 0x5288) != (code *)0x0) {
      iVar2 = (**(code **)(lVar1 + 0x5288))(*(undefined8 *)(lVar1 + 0x3b0));
      return -(iVar2 != 0) & 0x59;
    }
  }
  else if (*(code **)(lVar1 + 0x5280) != (code *)0x0) {
    iVar2 = (**(code **)(lVar1 + 0x5280))(*(undefined8 *)(lVar1 + 0x3b0),param_3);
    return -(iVar2 != 0) & 0x59;
  }
  return 0x56;
}


// ===== 00120070 __pfx_os_get_numa_node_memory_usage =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00120175) */
/* WARNING: Removing unreachable block (ram,0x00120194) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_os_get_numa_node_memory_usage(int param_1,long *param_2,long *param_3)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  long *plVar5;
  
  if (param_1 < 0x400) {
    lVar1 = *(long *)(&node_data + (long)param_1 * 8);
    *param_2 = 0;
    *param_3 = 0;
    plVar5 = (long *)(lVar1 + 0x600);
    do {
      if (plVar5[-0xab] != 0) {
        lVar4 = *plVar5;
        iVar2 = 0;
        while( true ) {
          uVar3 = _find_next_bit(&__cpu_online_mask,_nr_cpu_ids,(long)iVar2);
          if (_nr_cpu_ids <= uVar3) break;
          iVar2 = uVar3 + 1;
          lVar4 = lVar4 + *(char *)(*(long *)(&__per_cpu_offset + (long)(int)uVar3 * 8) +
                                   plVar5[-0xb1]);
        }
        if (lVar4 < 0) {
          lVar4 = 0;
        }
        *param_2 = *param_2 + lVar4 * 0x1000;
        *param_3 = *param_3 + plVar5[-0xab] * 0x1000;
      }
      plVar5 = plVar5 + 0xe8;
    } while (plVar5 != (long *)(lVar1 + 0x2a40));
    return 0;
  }
  nv_printf(4,"Invalid NUMA node ID\n");
  return 0x1f;
}


// ===== 00120080 os_get_numa_node_memory_usage =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00120175) */
/* WARNING: Removing unreachable block (ram,0x00120194) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 os_get_numa_node_memory_usage(int param_1,long *param_2,long *param_3)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  long *plVar5;
  
  if (param_1 < 0x400) {
    lVar1 = *(long *)(&node_data + (long)param_1 * 8);
    *param_2 = 0;
    *param_3 = 0;
    plVar5 = (long *)(lVar1 + 0x600);
    do {
      if (plVar5[-0xab] != 0) {
        lVar4 = *plVar5;
        iVar2 = 0;
        while( true ) {
          uVar3 = _find_next_bit(&__cpu_online_mask,_nr_cpu_ids,(long)iVar2);
          if (_nr_cpu_ids <= uVar3) break;
          iVar2 = uVar3 + 1;
          lVar4 = lVar4 + *(char *)(*(long *)(&__per_cpu_offset + (long)(int)uVar3 * 8) +
                                   plVar5[-0xb1]);
        }
        if (lVar4 < 0) {
          lVar4 = 0;
        }
        *param_2 = *param_2 + lVar4 * 0x1000;
        *param_3 = *param_3 + plVar5[-0xab] * 0x1000;
      }
      plVar5 = plVar5 + 0xe8;
    } while (plVar5 != (long *)(lVar1 + 0x2a40));
    return 0;
  }
  nv_printf(4,"Invalid NUMA node ID\n");
  return 0x1f;
}


// ===== 001201a0 __pfx_os_numa_add_gpu_memory =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012048f) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_os_numa_add_gpu_memory(long param_1,long param_2,ulong param_3,int *param_4)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  long lVar8;
  undefined8 uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  long lVar13;
  ulong uVar14;
  ulong uVar15;
  long in_GS_OFFSET;
  code *pcStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  long lStack_40;
  
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lVar2 = *(long *)(param_1 + 0x148);
  uStack_50 = 0;
  uStack_48 = 0;
  uVar14 = param_2 + *(long *)(lVar2 + 0x3c0);
  pcStack_58 = os_numa_verify_gpu_memory_zone;
  if (param_4 == (int *)0x0) {
    uVar9 = 0x1f;
    goto LAB_0012046d;
  }
  lVar1 = lVar2 + 0x3d8;
  lVar8 = _find_first_bit(lVar1,0x400);
  uVar9 = 0x17;
  if (lVar8 == 0x400) goto LAB_0012046d;
  iVar5 = _find_first_bit(lVar1,0x400);
  uVar9 = 0x40;
  if (iVar5 == 0x400) goto LAB_0012046d;
  *(undefined4 *)(lVar2 + 0x4a4) = 2;
  iVar6 = register_memory_notifier(&pcStack_58);
  if (iVar6 == 0) {
    lVar8 = memory_block_size_bytes();
    if (param_3 == 0) {
      unregister_memory_notifier(&pcStack_58);
      uVar10 = *(ulong *)(*(long *)(&node_data + (long)iVar5 * 8) + 0x1650);
      if ((uVar10 == uVar14 >> 0xc) &&
         (uVar10 == *(long *)(*(long *)(&node_data + (long)iVar5 * 8) + 0x1660) + uVar10)) {
LAB_0012049c:
        uVar14 = (ulong)iVar5;
        lVar8 = *(long *)(&const_current_task + in_GS_OFFSET);
        lVar3 = (long)uVar14 >> 3;
        if ((*(byte *)(lVar8 + 0xf40 + lVar3) >> (uVar14 & 7) & 1) == 0) {
          lVar13 = _jiffies + 100;
          lVar4 = _jiffies - lVar13;
          while ((lVar4 < 0 && ((*(byte *)(lVar8 + 0xf40 + lVar3) >> (uVar14 & 7) & 1) == 0))) {
            os_schedule();
            lVar4 = _jiffies - lVar13;
          }
          if ((*(byte *)(lVar8 + 0xf40 + lVar3) >> (uVar14 & 7) & 1) == 0) {
            nv_printf(4,
                      "NVRM: Hotplugged GPU memory NUMA node: %d not set in current->mems_allowed!\n"
                      ,iVar5);
          }
        }
        *param_4 = iVar5;
        LOCK();
        *(byte *)(lVar1 + lVar3) = *(byte *)(lVar1 + lVar3) & ~('\x01' << (uVar14 & 7));
        UNLOCK();
        *(undefined4 *)(lVar2 + 0x4a4) = 3;
        uVar9 = 0;
        goto LAB_0012046d;
      }
      nv_printf(4,"NVRM: GPU memory zone movable auto onlining failed!\n");
    }
    else {
      uVar10 = ((param_3 >> 7) - 1) + lVar8 & -lVar8;
      uVar11 = param_3;
      uVar12 = uVar10;
      uVar15 = uVar14;
      do {
        if (uVar11 < uVar12) {
          uVar12 = uVar11;
        }
        iVar6 = add_memory_driver_managed(iVar5,uVar15,uVar12,"System RAM (NVIDIA)",0);
        nv_printf(1,
                  "NVRM: add_memory_driver_managed() returns: %d for segment_base: 0x%llx, segment_size: 0x%llx\n"
                  ,iVar6,uVar15);
        schedule();
        uVar11 = uVar11 - uVar12;
      } while ((uVar11 != 0) && (uVar15 = uVar15 + uVar12, iVar6 == 0));
      unregister_memory_notifier(&pcStack_58);
      if (iVar6 == 0) {
        uVar11 = *(ulong *)(*(long *)(&node_data + (long)iVar5 * 8) + 0x1650);
        if ((uVar11 == uVar14 >> 0xc) &&
           (uVar14 + param_3 >> 0xc ==
            uVar11 + *(long *)(*(long *)(&node_data + (long)iVar5 * 8) + 0x1660)))
        goto LAB_0012049c;
        nv_printf(4,"NVRM: GPU memory zone movable auto onlining failed!\n");
        do {
          if (param_3 < uVar10) {
            uVar10 = param_3;
          }
          uVar7 = offline_and_remove_memory(uVar14,uVar10);
          nv_printf(1,
                    "NVRM: offline_and_remove_memory() returns: %d for segment_base: 0x%llx, segment_size: 0x%llx\n"
                    ,uVar7,uVar14,uVar10);
          schedule();
          param_3 = param_3 - uVar10;
          uVar14 = uVar14 + uVar10;
        } while (param_3 != 0);
      }
      else {
        nv_printf(4,"NVRM: Memory add failed. base: 0x%lx size: 0x%lx ret: %d\n",uVar14,param_3,
                  iVar6);
      }
    }
  }
  else {
    nv_printf(4,"NVRM: Memory hotplug notifier registration failed\n");
  }
  *(undefined4 *)(lVar2 + 0x4a4) = 4;
  uVar9 = 0x59;
LAB_0012046d:
  if (lStack_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar9;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 001201b0 os_numa_add_gpu_memory =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012048f) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 os_numa_add_gpu_memory(long param_1,long param_2,ulong param_3,int *param_4)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  long lVar8;
  undefined8 uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  long lVar13;
  ulong uVar14;
  ulong uVar15;
  long in_GS_OFFSET;
  code *local_58;
  undefined8 local_50;
  undefined8 local_48;
  long local_40;
  
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lVar2 = *(long *)(param_1 + 0x148);
  local_50 = 0;
  local_48 = 0;
  uVar14 = param_2 + *(long *)(lVar2 + 0x3c0);
  local_58 = os_numa_verify_gpu_memory_zone;
  if (param_4 == (int *)0x0) {
    uVar9 = 0x1f;
    goto LAB_0012046d;
  }
  lVar1 = lVar2 + 0x3d8;
  lVar8 = _find_first_bit(lVar1,0x400);
  uVar9 = 0x17;
  if (lVar8 == 0x400) goto LAB_0012046d;
  iVar5 = _find_first_bit(lVar1,0x400);
  uVar9 = 0x40;
  if (iVar5 == 0x400) goto LAB_0012046d;
  *(undefined4 *)(lVar2 + 0x4a4) = 2;
  iVar6 = register_memory_notifier(&local_58);
  if (iVar6 == 0) {
    lVar8 = memory_block_size_bytes();
    if (param_3 == 0) {
      unregister_memory_notifier(&local_58);
      uVar10 = *(ulong *)(*(long *)(&node_data + (long)iVar5 * 8) + 0x1650);
      if ((uVar10 == uVar14 >> 0xc) &&
         (uVar10 == *(long *)(*(long *)(&node_data + (long)iVar5 * 8) + 0x1660) + uVar10)) {
LAB_0012049c:
        uVar14 = (ulong)iVar5;
        lVar8 = *(long *)(&const_current_task + in_GS_OFFSET);
        lVar3 = (long)uVar14 >> 3;
        if ((*(byte *)(lVar8 + 0xf40 + lVar3) >> (uVar14 & 7) & 1) == 0) {
          lVar13 = _jiffies + 100;
          lVar4 = _jiffies - lVar13;
          while ((lVar4 < 0 && ((*(byte *)(lVar8 + 0xf40 + lVar3) >> (uVar14 & 7) & 1) == 0))) {
            os_schedule();
            lVar4 = _jiffies - lVar13;
          }
          if ((*(byte *)(lVar8 + 0xf40 + lVar3) >> (uVar14 & 7) & 1) == 0) {
            nv_printf(4,
                      "NVRM: Hotplugged GPU memory NUMA node: %d not set in current->mems_allowed!\n"
                      ,iVar5);
          }
        }
        *param_4 = iVar5;
        LOCK();
        *(byte *)(lVar1 + lVar3) = *(byte *)(lVar1 + lVar3) & ~('\x01' << (uVar14 & 7));
        UNLOCK();
        *(undefined4 *)(lVar2 + 0x4a4) = 3;
        uVar9 = 0;
        goto LAB_0012046d;
      }
      nv_printf(4,"NVRM: GPU memory zone movable auto onlining failed!\n");
    }
    else {
      uVar10 = ((param_3 >> 7) - 1) + lVar8 & -lVar8;
      uVar11 = param_3;
      uVar12 = uVar10;
      uVar15 = uVar14;
      do {
        if (uVar11 < uVar12) {
          uVar12 = uVar11;
        }
        iVar6 = add_memory_driver_managed(iVar5,uVar15,uVar12,"System RAM (NVIDIA)",0);
        nv_printf(1,
                  "NVRM: add_memory_driver_managed() returns: %d for segment_base: 0x%llx, segment_size: 0x%llx\n"
                  ,iVar6,uVar15);
        schedule();
        uVar11 = uVar11 - uVar12;
      } while ((uVar11 != 0) && (uVar15 = uVar15 + uVar12, iVar6 == 0));
      unregister_memory_notifier(&local_58);
      if (iVar6 == 0) {
        uVar11 = *(ulong *)(*(long *)(&node_data + (long)iVar5 * 8) + 0x1650);
        if ((uVar11 == uVar14 >> 0xc) &&
           (uVar14 + param_3 >> 0xc ==
            uVar11 + *(long *)(*(long *)(&node_data + (long)iVar5 * 8) + 0x1660)))
        goto LAB_0012049c;
        nv_printf(4,"NVRM: GPU memory zone movable auto onlining failed!\n");
        do {
          if (param_3 < uVar10) {
            uVar10 = param_3;
          }
          uVar7 = offline_and_remove_memory(uVar14,uVar10);
          nv_printf(1,
                    "NVRM: offline_and_remove_memory() returns: %d for segment_base: 0x%llx, segment_size: 0x%llx\n"
                    ,uVar7,uVar14,uVar10);
          schedule();
          param_3 = param_3 - uVar10;
          uVar14 = uVar14 + uVar10;
        } while (param_3 != 0);
      }
      else {
        nv_printf(4,"NVRM: Memory add failed. base: 0x%lx size: 0x%lx ret: %d\n",uVar14,param_3,
                  iVar6);
      }
    }
  }
  else {
    nv_printf(4,"NVRM: Memory hotplug notifier registration failed\n");
  }
  *(undefined4 *)(lVar2 + 0x4a4) = 4;
  uVar9 = 0x59;
LAB_0012046d:
  if (local_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar9;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00120620 __pfx_os_numa_remove_gpu_memory =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012075f) */

undefined8
__pfx_os_numa_remove_gpu_memory(long param_1,long param_2,undefined8 param_3,ulong param_4)

{
  long lVar1;
  long lVar2;
  byte *pbVar3;
  undefined8 uVar4;
  long in_GS_OFFSET;
  long lStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  long lStack_48;
  
  lStack_48 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lVar1 = *(long *)(param_1 + 0x148);
  lStack_88 = 0;
  uStack_80 = 0;
  uStack_78 = 0;
  uStack_70 = 0;
  uStack_68 = 0;
  uStack_60 = 0;
  uStack_58 = 0;
  if ((uint)param_4 < 0x400) {
    lVar2 = (long)(param_4 & 0xffffffff) >> 3;
    if ((*(byte *)(lVar1 + 0x3d8 + lVar2) >> (param_4 & 7) & 1) == 0) {
      param_2 = *(long *)(lVar1 + 0x3c0) + param_2;
      *(undefined4 *)(lVar1 + 0x4a4) = 5;
      uStack_78 = param_4 & 0xffffffff;
      lStack_88 = param_2;
      uStack_80 = param_3;
      nv_kthread_q_item_init(&uStack_70,offline_numa_memory_callback,&lStack_88);
      nv_kthread_q_schedule_q_item(lVar1 + 0x458,&uStack_70);
      nv_kthread_q_flush(lVar1 + 0x458);
      if (uStack_78._4_4_ == 0) {
        LOCK();
        pbVar3 = (byte *)(lVar1 + 0x3d8 + lVar2);
        *pbVar3 = *pbVar3 | '\x01' << (param_4 & 7);
        UNLOCK();
        *(undefined4 *)(lVar1 + 0x4a4) = 1;
        uVar4 = 0;
      }
      else {
        nv_printf(4,"NVRM: Memory remove failed. base: 0x%lx size: 0x%lx ret: %d\n",param_2,param_3)
        ;
        uVar4 = 0x59;
        *(undefined4 *)(lVar1 + 0x4a4) = 6;
      }
      goto LAB_00120742;
    }
  }
  uVar4 = 0x1f;
LAB_00120742:
  if (lStack_48 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00120630 os_numa_remove_gpu_memory =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012075f) */

undefined8 os_numa_remove_gpu_memory(long param_1,long param_2,undefined8 param_3,ulong param_4)

{
  long lVar1;
  long lVar2;
  byte *pbVar3;
  undefined8 uVar4;
  long in_GS_OFFSET;
  long local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  long local_48;
  
  local_48 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lVar1 = *(long *)(param_1 + 0x148);
  local_88 = 0;
  local_80 = 0;
  local_78 = 0;
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  if ((uint)param_4 < 0x400) {
    lVar2 = (long)(param_4 & 0xffffffff) >> 3;
    if ((*(byte *)(lVar1 + 0x3d8 + lVar2) >> (param_4 & 7) & 1) == 0) {
      param_2 = *(long *)(lVar1 + 0x3c0) + param_2;
      *(undefined4 *)(lVar1 + 0x4a4) = 5;
      local_78 = param_4 & 0xffffffff;
      local_88 = param_2;
      local_80 = param_3;
      nv_kthread_q_item_init(&local_70,offline_numa_memory_callback,&local_88);
      nv_kthread_q_schedule_q_item(lVar1 + 0x458,&local_70);
      nv_kthread_q_flush(lVar1 + 0x458);
      if (local_78._4_4_ == 0) {
        LOCK();
        pbVar3 = (byte *)(lVar1 + 0x3d8 + lVar2);
        *pbVar3 = *pbVar3 | '\x01' << (param_4 & 7);
        UNLOCK();
        *(undefined4 *)(lVar1 + 0x4a4) = 1;
        uVar4 = 0;
      }
      else {
        nv_printf(4,"NVRM: Memory remove failed. base: 0x%lx size: 0x%lx ret: %d\n",param_2,param_3)
        ;
        uVar4 = 0x59;
        *(undefined4 *)(lVar1 + 0x4a4) = 6;
      }
      goto LAB_00120742;
    }
  }
  uVar4 = 0x1f;
LAB_00120742:
  if (local_48 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 001207a0 __pfx_os_offline_page_at_address =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001207ff) */
/* WARNING: Removing unreachable block (ram,0x0012081e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __pfx_os_offline_page_at_address(ulong param_1)

{
  long lVar1;
  
  lVar1 = (param_1 >> 0xc) * 0x40 + _vmemmap_base;
  if (lVar1 != 0) {
    lVar1 = lVar1 - _vmemmap_base >> 6;
    nv_printf(0,"NVRM: offlining page at address: 0x%llx pfn: 0x%llx\n",param_1,lVar1);
    memory_failure_queue(lVar1,0x20);
    return 0;
  }
  nv_printf(4,"NVRM: Failed to get page struct for address: 0x%llx\n",param_1);
  return 0x1f;
}


// ===== 001207b0 os_offline_page_at_address =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001207ff) */
/* WARNING: Removing unreachable block (ram,0x0012081e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 os_offline_page_at_address(ulong param_1)

{
  long lVar1;
  
  lVar1 = (param_1 >> 0xc) * 0x40 + _vmemmap_base;
  if (lVar1 != 0) {
    lVar1 = lVar1 - _vmemmap_base >> 6;
    nv_printf(0,"NVRM: offlining page at address: 0x%llx pfn: 0x%llx\n",param_1,lVar1);
    memory_failure_queue(lVar1,0x20);
    return 0;
  }
  nv_printf(4,"NVRM: Failed to get page struct for address: 0x%llx\n",param_1);
  return 0x1f;
}


// ===== 00120830 __pfx_os_get_pid_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_get_pid_info(void)

{
  long in_GS_OFFSET;
  
  get_task_pid(*(undefined8 *)(&const_current_task + in_GS_OFFSET),1);
  return;
}


// ===== 00120840 os_get_pid_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_get_pid_info(void)

{
  long in_GS_OFFSET;
  
  get_task_pid(*(undefined8 *)(&const_current_task + in_GS_OFFSET),1);
  return;
}


// ===== 00120860 __pfx_os_put_pid_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00120883) */

void __pfx_os_put_pid_info(long param_1)

{
  if (param_1 != 0) {
    put_pid();
    return;
  }
  return;
}


// ===== 00120870 os_put_pid_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00120883) */

void os_put_pid_info(long param_1)

{
  if (param_1 != 0) {
    put_pid();
    return;
  }
  return;
}


// ===== 00120890 __pfx_os_find_ns_pid =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001208d2) */
/* WARNING: Removing unreachable block (ram,0x001208dc) */

byte __pfx_os_find_ns_pid(long param_1,int *param_2)

{
  int iVar1;
  
  if ((param_1 != 0) && (param_2 != (int *)0x0)) {
    iVar1 = pid_vnr();
    *param_2 = iVar1;
    return -(iVar1 == 0) & 0x57;
  }
  return 0x1f;
}


// ===== 001208a0 os_find_ns_pid =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001208d2) */
/* WARNING: Removing unreachable block (ram,0x001208dc) */

byte os_find_ns_pid(long param_1,int *param_2)

{
  int iVar1;
  
  if ((param_1 != 0) && (param_2 != (int *)0x0)) {
    iVar1 = pid_vnr();
    *param_2 = iVar1;
    return -(iVar1 == 0) & 0x57;
  }
  return 0x1f;
}


// ===== 001208f0 __pfx_os_is_init_ns =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012091f) */

bool __pfx_os_is_init_ns(void)

{
  undefined *puVar1;
  long in_GS_OFFSET;
  
  puVar1 = (undefined *)task_active_pid_ns(*(undefined8 *)(&const_current_task + in_GS_OFFSET));
  return puVar1 == &init_pid_ns;
}


// ===== 00120900 os_is_init_ns =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012091f) */

bool os_is_init_ns(void)

{
  undefined *puVar1;
  long in_GS_OFFSET;
  
  puVar1 = (undefined *)task_active_pid_ns(*(undefined8 *)(&const_current_task + in_GS_OFFSET));
  return puVar1 == &init_pid_ns;
}


// ===== 00120930 __pfx_os_device_vm_present =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012094e) */

undefined8 __pfx_os_device_vm_present(void)

{
  return 0x56;
}


// ===== 00120940 os_device_vm_present =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012094e) */

undefined8 os_device_vm_present(void)

{
  return 0x56;
}


// ===== 00120960 __pfx_os_supports_kernel_suspend_notifiers =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00120983) */

bool __pfx_os_supports_kernel_suspend_notifiers(void)

{
  return NVreg_UseKernelSuspendNotifiers == 1;
}


// ===== 00120970 os_supports_kernel_suspend_notifiers =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00120983) */

bool os_supports_kernel_suspend_notifiers(void)

{
  return NVreg_UseKernelSuspendNotifiers == 1;
}


// ===== 00120990 __pfx_os_lookup_user_io_memory =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00120c2a) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __pfx_os_lookup_user_io_memory(ulong param_1,ulong param_2)

{
  long lVar1;
  long lVar2;
  int iVar3;
  ulong *puVar4;
  ulong uVar5;
  long in_GS_OFFSET;
  undefined1 auVar6 [16];
  long lStack_98;
  long lStack_88;
  ulong *puStack_80;
  ulong uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  long lStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  long lStack_40;
  
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lStack_88 = 0;
  lVar2 = *(long *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0xab8);
  auVar6 = (*_mpi_powm)();
  if (((auVar6._0_8_ & 0x200) == 0) ||
     ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) != 0)) {
    iVar3 = 0x56;
    nv_printf(4,"NVRM: %s(): invalid context!\n","os_lookup_user_io_memory");
    goto LAB_00120c01;
  }
  iVar3 = os_alloc_mem(&lStack_88,param_2 * 8);
  if (iVar3 != 0) {
    nv_printf(4,"NVRM: failed to allocate page table!\n");
    goto LAB_00120c01;
  }
  lVar1 = lVar2 + 400;
  down_read(lVar1);
  puVar4 = (ulong *)find_vma_intersection(lVar2,param_1,param_1 + 1);
  if ((((puVar4 == (ulong *)0x0) || ((*(byte *)((long)puVar4 + 0x21) & 0x44) == 0)) ||
      (param_1 < *puVar4)) || (puVar4[1] - param_1 >> 0xc < param_2)) {
    nv_printf(4,"Cannot map memory with base addr 0x%llx and size of 0x%llx pages\n",param_1,param_2
             );
LAB_00120c46:
    iVar3 = 0x1e;
  }
  else {
    uStack_70 = 0;
    uStack_68 = 0;
    lStack_60 = 0;
    uStack_58 = 0;
    uStack_50 = 0;
    uStack_48 = 0;
    puStack_80 = puVar4;
    uStack_78 = param_1;
    iVar3 = follow_pfnmap_start(&puStack_80);
    if (iVar3 == 0) {
      follow_pfnmap_end(&puStack_80);
    }
    else if (iVar3 < 0) goto LAB_00120c46;
    lVar2 = lStack_88;
    if (param_2 != 0) {
      lStack_98 = 0;
      uVar5 = 0;
      do {
        uStack_70 = 0;
        uStack_68 = 0;
        lStack_60 = 0;
        uStack_58 = 0;
        uStack_50 = 0;
        uStack_48 = 0;
        puStack_80 = puVar4;
        uStack_78 = param_1;
        iVar3 = follow_pfnmap_start(&puStack_80);
        if (iVar3 == 0) {
          lStack_98 = lStack_60;
          follow_pfnmap_end(&puStack_80);
        }
        else if (iVar3 < 0) goto LAB_00120c46;
        *(long *)(lVar2 + uVar5 * 8) = lStack_98 << 0xc;
        if ((uVar5 != 0) && (lStack_98 << 0xc != *(long *)(lVar2 + -8 + uVar5 * 8) + 0x1000))
        goto LAB_00120c46;
        uVar5 = uVar5 + 1;
        param_1 = param_1 + 0x1000;
      } while (param_2 != uVar5);
    }
    *auVar6._8_8_ = lStack_88;
    iVar3 = 0;
  }
  up_read(lVar1);
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = 0x1e;
    os_free_mem(lStack_88);
  }
LAB_00120c01:
  if (lStack_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}


// ===== 001209a0 os_lookup_user_io_memory =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00120c2a) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int os_lookup_user_io_memory(ulong param_1,ulong param_2)

{
  long lVar1;
  long lVar2;
  int iVar3;
  ulong *puVar4;
  ulong uVar5;
  long in_GS_OFFSET;
  undefined1 auVar6 [16];
  long local_98;
  long local_88;
  ulong *local_80;
  ulong local_78;
  undefined8 local_70;
  undefined8 local_68;
  long local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  long local_40;
  
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_88 = 0;
  lVar2 = *(long *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0xab8);
  auVar6 = (*_mpi_powm)();
  if (((auVar6._0_8_ & 0x200) == 0) ||
     ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) != 0)) {
    iVar3 = 0x56;
    nv_printf(4,"NVRM: %s(): invalid context!\n","os_lookup_user_io_memory");
    goto LAB_00120c01;
  }
  iVar3 = os_alloc_mem(&local_88,param_2 * 8);
  if (iVar3 != 0) {
    nv_printf(4,"NVRM: failed to allocate page table!\n");
    goto LAB_00120c01;
  }
  lVar1 = lVar2 + 400;
  down_read(lVar1);
  puVar4 = (ulong *)find_vma_intersection(lVar2,param_1,param_1 + 1);
  if ((((puVar4 == (ulong *)0x0) || ((*(byte *)((long)puVar4 + 0x21) & 0x44) == 0)) ||
      (param_1 < *puVar4)) || (puVar4[1] - param_1 >> 0xc < param_2)) {
    nv_printf(4,"Cannot map memory with base addr 0x%llx and size of 0x%llx pages\n",param_1,param_2
             );
LAB_00120c46:
    iVar3 = 0x1e;
  }
  else {
    local_70 = 0;
    local_68 = 0;
    local_60 = 0;
    local_58 = 0;
    local_50 = 0;
    local_48 = 0;
    local_80 = puVar4;
    local_78 = param_1;
    iVar3 = follow_pfnmap_start(&local_80);
    if (iVar3 == 0) {
      follow_pfnmap_end(&local_80);
    }
    else if (iVar3 < 0) goto LAB_00120c46;
    lVar2 = local_88;
    if (param_2 != 0) {
      local_98 = 0;
      uVar5 = 0;
      do {
        local_70 = 0;
        local_68 = 0;
        local_60 = 0;
        local_58 = 0;
        local_50 = 0;
        local_48 = 0;
        local_80 = puVar4;
        local_78 = param_1;
        iVar3 = follow_pfnmap_start(&local_80);
        if (iVar3 == 0) {
          local_98 = local_60;
          follow_pfnmap_end(&local_80);
        }
        else if (iVar3 < 0) goto LAB_00120c46;
        *(long *)(lVar2 + uVar5 * 8) = local_98 << 0xc;
        if ((uVar5 != 0) && (local_98 << 0xc != *(long *)(lVar2 + -8 + uVar5 * 8) + 0x1000))
        goto LAB_00120c46;
        uVar5 = uVar5 + 1;
        param_1 = param_1 + 0x1000;
      } while (param_2 != uVar5);
    }
    *auVar6._8_8_ = local_88;
    iVar3 = 0;
  }
  up_read(lVar1);
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = 0x1e;
    os_free_mem(local_88);
  }
LAB_00120c01:
  if (local_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}


// ===== 00120d60 __pfx_os_lock_user_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00120ec8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __pfx_os_lock_user_pages(undefined8 param_1,ulong param_2,undefined8 param_3,byte param_4)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  long in_GS_OFFSET;
  undefined1 auVar5 [16];
  long lStack_48;
  long lStack_40;
  
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  lStack_48 = 0;
  lVar1 = *(long *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0xab8);
  auVar5 = (*_mpi_powm)();
  if (((auVar5._0_8_ & 0x200) == 0) ||
     ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) != 0)) {
    iVar2 = 0x56;
    nv_printf(4,"NVRM: %s(): invalid context!\n","os_lock_user_pages");
  }
  else {
    iVar2 = os_alloc_mem(&lStack_48,param_2 * 8);
    if (iVar2 == 0) {
      lVar1 = lVar1 + 400;
      down_read(lVar1);
      uVar3 = pin_user_pages(param_1,param_2,CONCAT11(1,param_4 & 1),lStack_48);
      uVar4 = 0;
      if (-1 < (long)uVar3) {
        uVar4 = uVar3;
      }
      up_read(lVar1);
      if (uVar4 < param_2) {
        if (0 < (long)uVar3) {
          uVar3 = 0;
          do {
            lVar1 = uVar3 * 8;
            uVar3 = uVar3 + 1;
            unpin_user_page(*(undefined8 *)(lStack_48 + lVar1));
          } while (uVar4 != uVar3);
        }
        iVar2 = 0x1e;
        os_free_mem(lStack_48);
      }
      else {
        *auVar5._8_8_ = lStack_48;
      }
    }
    else {
      nv_printf(4,"NVRM: failed to allocate page table!\n");
    }
  }
  if (lStack_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00120d70 os_lock_user_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00120ec8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int os_lock_user_pages(undefined8 param_1,ulong param_2,undefined8 param_3,byte param_4)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  long in_GS_OFFSET;
  undefined1 auVar5 [16];
  long local_48;
  long local_40;
  
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_48 = 0;
  lVar1 = *(long *)(*(long *)(&const_current_task + in_GS_OFFSET) + 0xab8);
  auVar5 = (*_mpi_powm)();
  if (((auVar5._0_8_ & 0x200) == 0) ||
     ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) != 0)) {
    iVar2 = 0x56;
    nv_printf(4,"NVRM: %s(): invalid context!\n","os_lock_user_pages");
  }
  else {
    iVar2 = os_alloc_mem(&local_48,param_2 * 8);
    if (iVar2 == 0) {
      lVar1 = lVar1 + 400;
      down_read(lVar1);
      uVar3 = pin_user_pages(param_1,param_2,CONCAT11(1,param_4 & 1),local_48);
      uVar4 = 0;
      if (-1 < (long)uVar3) {
        uVar4 = uVar3;
      }
      up_read(lVar1);
      if (uVar4 < param_2) {
        if (0 < (long)uVar3) {
          uVar3 = 0;
          do {
            lVar1 = uVar3 * 8;
            uVar3 = uVar3 + 1;
            unpin_user_page(*(undefined8 *)(local_48 + lVar1));
          } while (uVar4 != uVar3);
        }
        iVar2 = 0x1e;
        os_free_mem(local_48);
      }
      else {
        *auVar5._8_8_ = local_48;
      }
    }
    else {
      nv_printf(4,"NVRM: failed to allocate page table!\n");
    }
  }
  if (local_40 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00120f90 __pfx_os_unlock_user_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121028) */

undefined8 __pfx_os_unlock_user_pages(ulong param_1,long param_2,uint param_3)

{
  undefined8 *puVar1;
  ulong uVar2;
  
  if (param_1 != 0) {
    uVar2 = 0;
    do {
      puVar1 = (undefined8 *)(param_2 + uVar2 * 8);
      if ((param_3 & 1) != 0) {
        set_page_dirty_lock(*puVar1);
      }
      unpin_user_page(*puVar1);
      uVar2 = (ulong)((int)uVar2 + 1);
    } while (uVar2 < param_1);
  }
  os_free_mem(param_2);
  return 0;
}


// ===== 00120fa0 os_unlock_user_pages =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121028) */

undefined8 os_unlock_user_pages(ulong param_1,long param_2,uint param_3)

{
  undefined8 *puVar1;
  ulong uVar2;
  
  if (param_1 != 0) {
    uVar2 = 0;
    do {
      puVar1 = (undefined8 *)(param_2 + uVar2 * 8);
      if ((param_3 & 1) != 0) {
        set_page_dirty_lock(*puVar1);
      }
      unpin_user_page(*puVar1);
      uVar2 = (ulong)((int)uVar2 + 1);
    } while (uVar2 < param_1);
  }
  os_free_mem(param_2);
  return 0;
}


// ===== 00121030 __pfx_os_pci_init_handle =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001210c5) */
/* WARNING: Removing unreachable block (ram,0x001210d0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long __pfx_os_pci_init_handle(void)

{
  ulong uVar1;
  long lVar2;
  undefined2 *in_R8;
  undefined2 *in_R9;
  long in_GS_OFFSET;
  
  uVar1 = (*_mpi_powm)();
  if ((((uVar1 & 0x200) != 0) && ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0))
     && (lVar2 = pci_get_domain_bus_and_slot(), lVar2 != 0)) {
    if (in_R8 != (undefined2 *)0x0) {
      *in_R8 = *(undefined2 *)(lVar2 + 0x3c);
    }
    if (in_R9 != (undefined2 *)0x0) {
      *in_R9 = *(undefined2 *)(lVar2 + 0x3e);
    }
    pci_dev_put(lVar2);
    return lVar2;
  }
  return 0;
}


// ===== 00121040 os_pci_init_handle =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001210c5) */
/* WARNING: Removing unreachable block (ram,0x001210d0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long os_pci_init_handle(void)

{
  ulong uVar1;
  long lVar2;
  undefined2 *in_R8;
  undefined2 *in_R9;
  long in_GS_OFFSET;
  
  uVar1 = (*_mpi_powm)();
  if ((((uVar1 & 0x200) != 0) && ((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0))
     && (lVar2 = pci_get_domain_bus_and_slot(), lVar2 != 0)) {
    if (in_R8 != (undefined2 *)0x0) {
      *in_R8 = *(undefined2 *)(lVar2 + 0x3c);
    }
    if (in_R9 != (undefined2 *)0x0) {
      *in_R9 = *(undefined2 *)(lVar2 + 0x3e);
    }
    pci_dev_put(lVar2);
    return lVar2;
  }
  return 0;
}


// ===== 001210e0 __pfx_os_pci_read_byte =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121108) */
/* WARNING: Removing unreachable block (ram,0x00121115) */

undefined8 __pfx_os_pci_read_byte(undefined8 param_1,uint param_2,undefined1 *param_3)

{
  if (param_2 < 0x1000) {
    pci_read_config_byte();
    return 0;
  }
  *param_3 = 0xff;
  return 0x56;
}


// ===== 001210f0 os_pci_read_byte =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121108) */
/* WARNING: Removing unreachable block (ram,0x00121115) */

undefined8 os_pci_read_byte(undefined8 param_1,uint param_2,undefined1 *param_3)

{
  if (param_2 < 0x1000) {
    pci_read_config_byte();
    return 0;
  }
  *param_3 = 0xff;
  return 0x56;
}


// ===== 00121120 __pfx_os_pci_read_word =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121148) */
/* WARNING: Removing unreachable block (ram,0x0012115a) */

undefined8 __pfx_os_pci_read_word(undefined8 param_1,uint param_2,undefined2 *param_3)

{
  if (param_2 < 0x1000) {
    pci_read_config_word();
    return 0;
  }
  *param_3 = 0xffff;
  return 0x56;
}


// ===== 00121130 os_pci_read_word =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121148) */
/* WARNING: Removing unreachable block (ram,0x0012115a) */

undefined8 os_pci_read_word(undefined8 param_1,uint param_2,undefined2 *param_3)

{
  if (param_2 < 0x1000) {
    pci_read_config_word();
    return 0;
  }
  *param_3 = 0xffff;
  return 0x56;
}


// ===== 00121160 __pfx_os_pci_read_dword =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121188) */
/* WARNING: Removing unreachable block (ram,0x00121198) */

undefined8 __pfx_os_pci_read_dword(undefined8 param_1,uint param_2,undefined4 *param_3)

{
  if (param_2 < 0x1000) {
    pci_read_config_dword();
    return 0;
  }
  *param_3 = 0xffffffff;
  return 0x56;
}


// ===== 00121170 os_pci_read_dword =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121188) */
/* WARNING: Removing unreachable block (ram,0x00121198) */

undefined8 os_pci_read_dword(undefined8 param_1,uint param_2,undefined4 *param_3)

{
  if (param_2 < 0x1000) {
    pci_read_config_dword();
    return 0;
  }
  *param_3 = 0xffffffff;
  return 0x56;
}


// ===== 001211a0 __pfx_os_pci_write_byte =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001211d0) */

undefined8 __pfx_os_pci_write_byte(undefined8 param_1,uint param_2,undefined1 param_3)

{
  undefined8 uVar1;
  
  uVar1 = 0x56;
  if (param_2 < 0x1000) {
    pci_write_config_byte(param_1,param_2,param_3);
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 001211b0 os_pci_write_byte =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001211d0) */

undefined8 os_pci_write_byte(undefined8 param_1,uint param_2,undefined1 param_3)

{
  undefined8 uVar1;
  
  uVar1 = 0x56;
  if (param_2 < 0x1000) {
    pci_write_config_byte(param_1,param_2,param_3);
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 001211e0 __pfx_os_pci_write_word =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121210) */

undefined8 __pfx_os_pci_write_word(undefined8 param_1,uint param_2,undefined2 param_3)

{
  undefined8 uVar1;
  
  uVar1 = 0x56;
  if (param_2 < 0x1000) {
    pci_write_config_word(param_1,param_2,param_3);
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 001211f0 os_pci_write_word =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121210) */

undefined8 os_pci_write_word(undefined8 param_1,uint param_2,undefined2 param_3)

{
  undefined8 uVar1;
  
  uVar1 = 0x56;
  if (param_2 < 0x1000) {
    pci_write_config_word(param_1,param_2,param_3);
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 00121220 __pfx_os_pci_write_dword =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012124d) */

undefined8 __pfx_os_pci_write_dword(undefined8 param_1,uint param_2)

{
  undefined8 uVar1;
  
  uVar1 = 0x56;
  if (param_2 < 0x1000) {
    pci_write_config_dword();
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 00121230 os_pci_write_dword =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012124d) */

undefined8 os_pci_write_dword(undefined8 param_1,uint param_2)

{
  undefined8 uVar1;
  
  uVar1 = 0x56;
  if (param_2 < 0x1000) {
    pci_write_config_dword();
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 00121260 __pfx_os_pci_remove_supported =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012127e) */

undefined8 __pfx_os_pci_remove_supported(void)

{
  return 1;
}


// ===== 00121270 os_pci_remove_supported =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012127e) */

undefined8 os_pci_remove_supported(void)

{
  return 1;
}


// ===== 00121290 __pfx_os_pci_remove =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_pci_remove(void)

{
  pci_stop_and_remove_bus_device();
  return;
}


// ===== 001212a0 os_pci_remove =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_pci_remove(void)

{
  pci_stop_and_remove_bus_device();
  return;
}


// ===== 001212b0 __pfx_os_enable_pci_req_atomics =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012133e) */

byte __pfx_os_enable_pci_req_atomics(undefined8 param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  long in_GS_OFFSET;
  ushort uStack_12;
  long lStack_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x1212c9;
  lStack_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_12 = 0;
  if (param_2 == 1) {
    iVar2 = pci_enable_atomic_ops_to_root(param_1,0x100);
joined_r0x00121357:
    if ((iVar2 == 0) && (iVar2 = pcie_capability_read_word(param_1,0x28,&uStack_12), iVar2 == 0)) {
      bVar1 = -((uStack_12 & 0x40) == 0) & 0x56;
      goto LAB_0012132b;
    }
  }
  else {
    if (param_2 == 2) {
      iVar2 = pci_enable_atomic_ops_to_root(param_1,0x200);
      goto joined_r0x00121357;
    }
    if (param_2 == 0) {
      iVar2 = pci_enable_atomic_ops_to_root(param_1,0x80);
      goto joined_r0x00121357;
    }
  }
  bVar1 = 0x56;
LAB_0012132b:
  if (lStack_10 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return bVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 001212c0 os_enable_pci_req_atomics =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012133e) */

byte os_enable_pci_req_atomics(undefined8 param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  long in_GS_OFFSET;
  ushort local_12;
  long local_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x1212c9;
  local_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_12 = 0;
  if (param_2 == 1) {
    iVar2 = pci_enable_atomic_ops_to_root(param_1,0x100);
joined_r0x00121357:
    if ((iVar2 == 0) && (iVar2 = pcie_capability_read_word(param_1,0x28,&local_12), iVar2 == 0)) {
      bVar1 = -((local_12 & 0x40) == 0) & 0x56;
      goto LAB_0012132b;
    }
  }
  else {
    if (param_2 == 2) {
      iVar2 = pci_enable_atomic_ops_to_root(param_1,0x200);
      goto joined_r0x00121357;
    }
    if (param_2 == 0) {
      iVar2 = pci_enable_atomic_ops_to_root(param_1,0x80);
      goto joined_r0x00121357;
    }
  }
  bVar1 = 0x56;
LAB_0012132b:
  if (local_10 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return bVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00121380 __pfx_os_pci_trigger_flr =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_os_pci_trigger_flr(undefined8 param_1)

{
  int iVar1;
  
  nv_printf(0,"NVRM: %s() Start to trigger FLR\n","os_pci_trigger_flr");
  iVar1 = pci_save_state(param_1);
  if (iVar1 != 0) {
    nv_printf(4,"NVRM: %s() PCI save state failed, Skip FLR\n","os_pci_trigger_flr");
    return;
  }
  iVar1 = pcie_reset_flr(param_1,0);
  if (iVar1 == 0) {
    pci_restore_state(param_1);
    return;
  }
  nv_printf(4,"NVRM: %s() PCI FLR might have failed\n","os_pci_trigger_flr");
  pci_restore_state(param_1);
  return;
}


// ===== 00121390 os_pci_trigger_flr =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void os_pci_trigger_flr(undefined8 param_1)

{
  int iVar1;
  
  nv_printf(0,"NVRM: %s() Start to trigger FLR\n","os_pci_trigger_flr");
  iVar1 = pci_save_state(param_1);
  if (iVar1 != 0) {
    nv_printf(4,"NVRM: %s() PCI save state failed, Skip FLR\n","os_pci_trigger_flr");
    return;
  }
  iVar1 = pcie_reset_flr(param_1,0);
  if (iVar1 == 0) {
    pci_restore_state(param_1);
    return;
  }
  nv_printf(4,"NVRM: %s() PCI FLR might have failed\n","os_pci_trigger_flr");
  pci_restore_state(param_1);
  return;
}


// ===== 00121410 __pfx_nv_parse_per_device_option_string =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001215a4) */

undefined8 __pfx_nv_parse_per_device_option_string(undefined8 param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  size_t sVar7;
  char *__s;
  char *pcVar8;
  char cVar9;
  undefined8 uVar10;
  long in_GS_OFFSET;
  char *pcStack_70;
  uint uStack_64;
  uint uStack_60;
  char *pcStack_58;
  char *pcStack_50;
  char *pcStack_48;
  long lStack_40;
  
  uVar10 = 0;
  lStack_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  pcStack_58 = (char *)0x0;
  pcStack_50 = (char *)0x0;
  if (NVreg_RegistryDwordsPerDevice != 0) {
    pcVar5 = (char *)rm_remove_spaces();
    if (pcVar5 == (char *)0x0) {
      uVar10 = 0xffff;
    }
    else {
      pcStack_70 = (char *)0x0;
      pcStack_58 = pcVar5;
LAB_00121499:
      pcStack_50 = strsep(&pcStack_58,";");
      if (pcStack_50 != (char *)0x0) {
        pcVar6 = strsep(&pcStack_50,"=");
        if ((((pcVar6 != (char *)0x0) && (sVar7 = strlen(pcVar6), sVar7 != 0)) &&
            (__s = strsep(&pcStack_50,"="), __s != (char *)0x0)) &&
           ((sVar7 = strlen(__s), sVar7 != 0 &&
            (pcVar8 = strsep(&pcStack_50,"="), pcVar8 == (char *)0x0)))) {
          iVar1 = strcmp(pcVar6,"pci");
          if (iVar1 == 0) {
            pcStack_48 = (char *)0x0;
            pcVar6 = (char *)rm_remove_spaces(__s);
            if (pcVar6 == (char *)0x0) {
              pcStack_70 = (char *)0x0;
              uVar10 = 0xffff;
              goto LAB_00121499;
            }
            pcStack_48 = pcVar6;
            sVar7 = strlen(pcVar6);
            cVar9 = '\0';
            if (sVar7 == 0) {
              os_free_mem(pcVar6);
            }
            else {
              pcVar8 = strsep(&pcStack_48,".");
              if (pcVar8 == (char *)0x0) {
                uVar10 = 0x1f;
                os_free_mem(pcVar6);
                pcStack_70 = (char *)0x0;
                goto LAB_00121499;
              }
              if (pcStack_48 == (char *)0x0) {
LAB_00121650:
                uStack_60 = simple_strtoul(pcVar8,&pcStack_48,0x10);
                if (((pcStack_48 != (char *)0x0) && (*pcStack_48 == ':')) && (pcStack_48[1] != '\0')
                   ) {
                  uVar3 = simple_strtoul(pcStack_48 + 1,&pcStack_48,0x10);
                  pcStack_70 = pcStack_48;
                  if (pcStack_48 == (char *)0x0) {
                    uVar10 = 0x1f;
                    nv_printf(4,"NVRM: Invalid PCI bus/slot in token %s\n",__s);
                    os_free_mem(pcVar6);
                  }
                  else {
                    if (*pcStack_48 == '\0') {
                      os_free_mem(pcVar6);
                      uStack_64 = 0;
                      uVar4 = uVar3;
                    }
                    else {
                      if ((*pcStack_48 != ':') || (pcStack_48[1] == '\0')) {
LAB_001217e5:
                        pcVar8 = "NVRM: Invalid PCI slot in token %s\n";
                        goto LAB_00121739;
                      }
                      pcVar8 = pcStack_48 + 1;
                      uVar4 = simple_strtoul(pcVar8,&pcStack_48,0x10);
                      uStack_64 = uStack_60;
                      uStack_60 = uVar3;
                      if (uVar4 == 0) {
                        if (pcVar8 == pcStack_48) goto LAB_001217e5;
                        os_free_mem(pcVar6);
                      }
                      else {
                        os_free_mem(pcVar6);
                      }
                    }
                    uVar10 = 0;
                    pcStack_70 = (char *)find_pci(uStack_64,(undefined1)uStack_60,uVar4 & 0xff,cVar9
                                                 );
                  }
                  goto LAB_00121499;
                }
                pcVar8 = "NVRM: Invalid PCI domain/bus in token %s\n";
LAB_00121739:
                nv_printf(4,pcVar8,__s);
                os_free_mem(pcVar6);
              }
              else {
                cVar9 = *pcStack_48;
                if ((byte)(cVar9 - 0x30U) < 8) {
                  sVar7 = strlen(pcStack_48);
                  cVar9 = cVar9 + -0x30;
                  if (sVar7 < 2) goto LAB_00121650;
                }
                nv_printf(4,"NVRM: Invalid PCI function in token %s\n",__s);
                os_free_mem(pcVar6);
              }
            }
            pcStack_70 = (char *)0x0;
            uVar10 = 0x1f;
            goto LAB_00121499;
          }
          if (pcStack_70 != (char *)0x0) {
            uVar2 = simple_strtoul(__s,0,0);
            rm_write_registry_dword(param_1,pcStack_70,pcVar6,uVar2);
          }
        }
        goto LAB_00121499;
      }
      os_free_mem(pcVar5);
    }
  }
  if (lStack_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}


// ===== 00121420 nv_parse_per_device_option_string =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001215a4) */

undefined8 nv_parse_per_device_option_string(undefined8 param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  size_t sVar7;
  char *__s;
  char *pcVar8;
  char cVar9;
  undefined8 uVar10;
  long in_GS_OFFSET;
  char *local_70;
  uint local_64;
  uint local_60;
  char *local_58;
  char *local_50;
  char *local_48;
  long local_40;
  
  uVar10 = 0;
  local_40 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_58 = (char *)0x0;
  local_50 = (char *)0x0;
  if (NVreg_RegistryDwordsPerDevice != 0) {
    pcVar5 = (char *)rm_remove_spaces();
    if (pcVar5 == (char *)0x0) {
      uVar10 = 0xffff;
    }
    else {
      local_70 = (char *)0x0;
      local_58 = pcVar5;
LAB_00121499:
      local_50 = strsep(&local_58,";");
      if (local_50 != (char *)0x0) {
        pcVar6 = strsep(&local_50,"=");
        if ((((pcVar6 != (char *)0x0) && (sVar7 = strlen(pcVar6), sVar7 != 0)) &&
            (__s = strsep(&local_50,"="), __s != (char *)0x0)) &&
           ((sVar7 = strlen(__s), sVar7 != 0 &&
            (pcVar8 = strsep(&local_50,"="), pcVar8 == (char *)0x0)))) {
          iVar1 = strcmp(pcVar6,"pci");
          if (iVar1 == 0) {
            local_48 = (char *)0x0;
            pcVar6 = (char *)rm_remove_spaces(__s);
            if (pcVar6 == (char *)0x0) {
              local_70 = (char *)0x0;
              uVar10 = 0xffff;
              goto LAB_00121499;
            }
            local_48 = pcVar6;
            sVar7 = strlen(pcVar6);
            cVar9 = '\0';
            if (sVar7 == 0) {
              os_free_mem(pcVar6);
            }
            else {
              pcVar8 = strsep(&local_48,".");
              if (pcVar8 == (char *)0x0) {
                uVar10 = 0x1f;
                os_free_mem(pcVar6);
                local_70 = (char *)0x0;
                goto LAB_00121499;
              }
              if (local_48 == (char *)0x0) {
LAB_00121650:
                local_60 = simple_strtoul(pcVar8,&local_48,0x10);
                if (((local_48 != (char *)0x0) && (*local_48 == ':')) && (local_48[1] != '\0')) {
                  uVar3 = simple_strtoul(local_48 + 1,&local_48,0x10);
                  local_70 = local_48;
                  if (local_48 == (char *)0x0) {
                    uVar10 = 0x1f;
                    nv_printf(4,"NVRM: Invalid PCI bus/slot in token %s\n",__s);
                    os_free_mem(pcVar6);
                  }
                  else {
                    if (*local_48 == '\0') {
                      os_free_mem(pcVar6);
                      local_64 = 0;
                      uVar4 = uVar3;
                    }
                    else {
                      if ((*local_48 != ':') || (local_48[1] == '\0')) {
LAB_001217e5:
                        pcVar8 = "NVRM: Invalid PCI slot in token %s\n";
                        goto LAB_00121739;
                      }
                      pcVar8 = local_48 + 1;
                      uVar4 = simple_strtoul(pcVar8,&local_48,0x10);
                      local_64 = local_60;
                      local_60 = uVar3;
                      if (uVar4 == 0) {
                        if (pcVar8 == local_48) goto LAB_001217e5;
                        os_free_mem(pcVar6);
                      }
                      else {
                        os_free_mem(pcVar6);
                      }
                    }
                    uVar10 = 0;
                    local_70 = (char *)find_pci(local_64,(undefined1)local_60,uVar4 & 0xff,cVar9);
                  }
                  goto LAB_00121499;
                }
                pcVar8 = "NVRM: Invalid PCI domain/bus in token %s\n";
LAB_00121739:
                nv_printf(4,pcVar8,__s);
                os_free_mem(pcVar6);
              }
              else {
                cVar9 = *local_48;
                if ((byte)(cVar9 - 0x30U) < 8) {
                  sVar7 = strlen(local_48);
                  cVar9 = cVar9 + -0x30;
                  if (sVar7 < 2) goto LAB_00121650;
                }
                nv_printf(4,"NVRM: Invalid PCI function in token %s\n",__s);
                os_free_mem(pcVar6);
              }
            }
            local_70 = (char *)0x0;
            uVar10 = 0x1f;
            goto LAB_00121499;
          }
          if (local_70 != (char *)0x0) {
            uVar2 = simple_strtoul(__s,0,0);
            rm_write_registry_dword(param_1,local_70,pcVar6,uVar2);
          }
        }
        goto LAB_00121499;
      }
      os_free_mem(pcVar5);
    }
  }
  if (local_40 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}


// ===== 00121860 __pfx_nv_is_uuid_in_gpu_exclusion_list =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121908) */

undefined8 __pfx_nv_is_uuid_in_gpu_exclusion_list(char *param_1)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  undefined8 uVar4;
  long in_GS_OFFSET;
  char *pcStack_28;
  long lStack_20;
  
  lStack_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  pcStack_28 = (char *)0x0;
  if (((NVreg_ExcludedGpus == 0) && (NVreg_GpuBlacklist == 0)) ||
     (pcVar2 = (char *)rm_remove_spaces(), pcVar3 = pcVar2, pcVar2 == (char *)0x0)) {
LAB_001218ee:
    uVar4 = 0;
  }
  else {
    do {
      pcStack_28 = pcVar3;
      pcVar3 = strsep(&pcStack_28,",");
      if (pcVar3 == (char *)0x0) {
        os_free_mem(pcVar2);
        goto LAB_001218ee;
      }
      iVar1 = strcmp(pcVar3,param_1);
      pcVar3 = pcStack_28;
    } while (iVar1 != 0);
    os_free_mem(pcVar2);
    uVar4 = 1;
  }
  if (lStack_20 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}


// ===== 00121870 nv_is_uuid_in_gpu_exclusion_list =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121908) */

undefined8 nv_is_uuid_in_gpu_exclusion_list(char *param_1)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  undefined8 uVar4;
  long in_GS_OFFSET;
  char *local_28;
  long local_20;
  
  local_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_28 = (char *)0x0;
  if (((NVreg_ExcludedGpus == 0) && (NVreg_GpuBlacklist == 0)) ||
     (pcVar2 = (char *)rm_remove_spaces(), pcVar3 = pcVar2, pcVar2 == (char *)0x0)) {
LAB_001218ee:
    uVar4 = 0;
  }
  else {
    do {
      local_28 = pcVar3;
      pcVar3 = strsep(&local_28,",");
      if (pcVar3 == (char *)0x0) {
        os_free_mem(pcVar2);
        goto LAB_001218ee;
      }
      iVar1 = strcmp(pcVar3,param_1);
      pcVar3 = local_28;
    } while (iVar1 != 0);
    os_free_mem(pcVar2);
    uVar4 = 1;
  }
  if (local_20 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}


// ===== 00121940 __pfx_os_registry_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121a4c) */
/* WARNING: Removing unreachable block (ram,0x00121a96) */

undefined8 __pfx_os_registry_init(void)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  size_t sVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  undefined **ppuVar7;
  
  cVar2 = rm_is_altstack_in_use();
  if (cVar2 == '\0') {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    puVar5 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar5 == (undefined4 *)0x0) {
      return 0x51;
    }
    *puVar5 = 0x2ff0;
    *(undefined4 **)(puVar5 + 2) = puVar5 + 0xc00;
  }
  pcVar1 = NVreg_RmNvlinkBandwidth;
  if (NVreg_RmNvlinkBandwidth != (char *)0x0) {
    sVar4 = strlen(NVreg_RmNvlinkBandwidth);
    rm_write_registry_string(puVar5,0,"RmNvlinkBandwidth",pcVar1,sVar4 & 0xffffffff);
  }
  pcVar1 = NVreg_RmMsg;
  if (NVreg_RmMsg != (char *)0x0) {
    sVar4 = strlen(NVreg_RmMsg);
    rm_write_registry_string(puVar5,0,"RmMsg",pcVar1,sVar4 & 0xffffffff);
  }
  if (NVreg_CoherentGPUMemoryMode != (char *)0x0) {
    iVar3 = strcmp(NVreg_CoherentGPUMemoryMode,"driver");
    if (iVar3 == 0) {
      NVreg_EnableUserNUMAManagement = 0;
    }
  }
  rm_parse_option_string(puVar5,NVreg_RegistryDwords);
  if (nv_parms != (undefined *)0x0) {
    puVar6 = nv_parms;
    ppuVar7 = &PTR_NVreg_ResmanDebugLevel_005702e8;
    do {
      rm_write_registry_dword(puVar5,0,puVar6,*(undefined4 *)*ppuVar7);
      puVar6 = ppuVar7[1];
      ppuVar7 = ppuVar7 + 2;
    } while (puVar6 != (undefined *)0x0);
  }
  if (puVar5 != (undefined4 *)0x0) {
    cVar2 = rm_is_altstack_in_use();
    if (cVar2 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar5);
    }
  }
  return 0;
}


// ===== 00121950 os_registry_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121a4c) */
/* WARNING: Removing unreachable block (ram,0x00121a96) */

undefined8 os_registry_init(void)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  size_t sVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  undefined **ppuVar7;
  
  cVar2 = rm_is_altstack_in_use();
  if (cVar2 == '\0') {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    puVar5 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar5 == (undefined4 *)0x0) {
      return 0x51;
    }
    *puVar5 = 0x2ff0;
    *(undefined4 **)(puVar5 + 2) = puVar5 + 0xc00;
  }
  pcVar1 = NVreg_RmNvlinkBandwidth;
  if (NVreg_RmNvlinkBandwidth != (char *)0x0) {
    sVar4 = strlen(NVreg_RmNvlinkBandwidth);
    rm_write_registry_string(puVar5,0,"RmNvlinkBandwidth",pcVar1,sVar4 & 0xffffffff);
  }
  pcVar1 = NVreg_RmMsg;
  if (NVreg_RmMsg != (char *)0x0) {
    sVar4 = strlen(NVreg_RmMsg);
    rm_write_registry_string(puVar5,0,"RmMsg",pcVar1,sVar4 & 0xffffffff);
  }
  if (NVreg_CoherentGPUMemoryMode != (char *)0x0) {
    iVar3 = strcmp(NVreg_CoherentGPUMemoryMode,"driver");
    if (iVar3 == 0) {
      NVreg_EnableUserNUMAManagement = 0;
    }
  }
  rm_parse_option_string(puVar5,NVreg_RegistryDwords);
  if (nv_parms != (undefined *)0x0) {
    puVar6 = nv_parms;
    ppuVar7 = &PTR_NVreg_ResmanDebugLevel_005702e8;
    do {
      rm_write_registry_dword(puVar5,0,puVar6,*(undefined4 *)*ppuVar7);
      puVar6 = ppuVar7[1];
      ppuVar7 = ppuVar7 + 2;
    } while (puVar6 != (undefined *)0x0);
  }
  if (puVar5 != (undefined4 *)0x0) {
    cVar2 = rm_is_altstack_in_use();
    if (cVar2 != '\0') {
      kmem_cache_free(nvidia_stack_t_cache,puVar5);
    }
  }
  return 0;
}


// ===== 00121ac0 __pfx_os_match_mmap_offset =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121b1d) */
/* WARNING: Removing unreachable block (ram,0x00121b5d) */

undefined8 __pfx_os_match_mmap_offset(long param_1,long param_2,ulong *param_3)

{
  uint uVar1;
  ulong uVar2;
  
  uVar1 = *(uint *)(param_1 + 0x20);
  if (uVar1 != 0) {
    uVar2 = 0;
    if ((*(byte *)(param_1 + 0x18) & 1) == 0) {
      do {
        if ((*(long **)(param_1 + 0x30))[uVar2 * 2] == param_2) goto LAB_00121b18;
        uVar2 = uVar2 + 1;
      } while (uVar2 != uVar1);
    }
    else {
      do {
        if (uVar2 * 0x1000 + **(long **)(param_1 + 0x30) == param_2) {
LAB_00121b18:
          *param_3 = uVar2;
          return 0;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 != uVar1);
    }
  }
  return 0x57;
}


// ===== 00121ad0 os_match_mmap_offset =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121b1d) */
/* WARNING: Removing unreachable block (ram,0x00121b5d) */

undefined8 os_match_mmap_offset(long param_1,long param_2,ulong *param_3)

{
  uint uVar1;
  ulong uVar2;
  
  uVar1 = *(uint *)(param_1 + 0x20);
  if (uVar1 != 0) {
    uVar2 = 0;
    if ((*(byte *)(param_1 + 0x18) & 1) == 0) {
      do {
        if ((*(long **)(param_1 + 0x30))[uVar2 * 2] == param_2) goto LAB_00121b18;
        uVar2 = uVar2 + 1;
      } while (uVar2 != uVar1);
    }
    else {
      do {
        if (uVar2 * 0x1000 + **(long **)(param_1 + 0x30) == param_2) {
LAB_00121b18:
          *param_3 = uVar2;
          return 0;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 != uVar1);
    }
  }
  return 0x57;
}


// ===== 00121b70 __pfx_nvidia_modeset_set_callbacks =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121ba1) */
/* WARNING: Removing unreachable block (ram,0x00121bb0) */

undefined8 __pfx_nvidia_modeset_set_callbacks(long param_1)

{
  if (nv_modeset_callbacks == 0) {
    if (param_1 == 0) {
      return 0xffffffea;
    }
  }
  else if (param_1 != 0) {
    return 0xffffffea;
  }
  nv_modeset_callbacks = param_1;
  return 0;
}


// ===== 00121b80 nvidia_modeset_set_callbacks =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121ba1) */
/* WARNING: Removing unreachable block (ram,0x00121bb0) */

undefined8 nvidia_modeset_set_callbacks(long param_1)

{
  if (nv_modeset_callbacks == 0) {
    if (param_1 == 0) {
      return 0xffffffea;
    }
  }
  else if (param_1 != 0) {
    return 0xffffffea;
  }
  nv_modeset_callbacks = param_1;
  return 0;
}


// ===== 00121bc0 __pfx_nvidia_get_rm_ops =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121c48) */
/* WARNING: Removing unreachable block (ram,0x00121c5a) */

undefined8 __pfx_nvidia_get_rm_ops(undefined8 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = strcmp((char *)*param_1,"595.71.05");
  iVar1 = nv_pat_mode;
  if (iVar2 == 0) {
    param_1[1] = 0;
    *param_1 = "595.71.05";
    param_1[2] = nvidia_modeset_rm_ops_alloc_stack;
    param_1[3] = nvidia_modeset_rm_ops_free_stack;
    param_1[4] = nvidia_modeset_enumerate_gpus;
    param_1[5] = nvidia_dev_get;
    param_1[6] = nvidia_dev_put;
    param_1[7] = rm_kernel_rmapi_op;
    param_1[8] = nvidia_modeset_set_callbacks;
    if (iVar1 != 0) {
      *(undefined1 *)(param_1 + 1) = 1;
    }
    return 0;
  }
  *param_1 = "595.71.05";
  return 0xffff;
}


// ===== 00121bd0 nvidia_get_rm_ops =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121c48) */
/* WARNING: Removing unreachable block (ram,0x00121c5a) */

undefined8 nvidia_get_rm_ops(undefined8 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = strcmp((char *)*param_1,"595.71.05");
  iVar1 = nv_pat_mode;
  if (iVar2 == 0) {
    param_1[1] = 0;
    *param_1 = "595.71.05";
    param_1[2] = nvidia_modeset_rm_ops_alloc_stack;
    param_1[3] = nvidia_modeset_rm_ops_free_stack;
    param_1[4] = nvidia_modeset_enumerate_gpus;
    param_1[5] = nvidia_dev_get;
    param_1[6] = nvidia_dev_put;
    param_1[7] = rm_kernel_rmapi_op;
    param_1[8] = nvidia_modeset_set_callbacks;
    if (iVar1 != 0) {
      *(undefined1 *)(param_1 + 1) = 1;
    }
    return 0;
  }
  *param_1 = "595.71.05";
  return 0xffff;
}


// ===== 00121c60 __pfx_nvidia_modeset_rm_ops_free_stack =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121c8c) */
/* WARNING: Removing unreachable block (ram,0x00121c91) */

void __pfx_nvidia_modeset_rm_ops_free_stack(long param_1)

{
  char cVar1;
  
  if (param_1 == 0) {
    return;
  }
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    return;
  }
  kmem_cache_free(nvidia_stack_t_cache,param_1);
  return;
}


// ===== 00121c70 nvidia_modeset_rm_ops_free_stack =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121c8c) */
/* WARNING: Removing unreachable block (ram,0x00121c91) */

void nvidia_modeset_rm_ops_free_stack(long param_1)

{
  char cVar1;
  
  if (param_1 == 0) {
    return;
  }
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    return;
  }
  kmem_cache_free(nvidia_stack_t_cache,param_1);
  return;
}


// ===== 00121cb0 __pfx_nvidia_modeset_rm_ops_alloc_stack =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121cde) */
/* WARNING: Removing unreachable block (ram,0x00121d12) */

undefined8 __pfx_nvidia_modeset_rm_ops_alloc_stack(undefined8 *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar2 == (undefined4 *)0x0) {
      return 0xfffffff4;
    }
    *puVar2 = 0x2ff0;
    *(undefined4 **)(puVar2 + 2) = puVar2 + 0xc00;
  }
  *param_1 = puVar2;
  return 0;
}


// ===== 00121cc0 nvidia_modeset_rm_ops_alloc_stack =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121cde) */
/* WARNING: Removing unreachable block (ram,0x00121d12) */

undefined8 nvidia_modeset_rm_ops_alloc_stack(undefined8 *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  
  cVar1 = rm_is_altstack_in_use();
  if (cVar1 == '\0') {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)kmem_cache_alloc_noprof(nvidia_stack_t_cache,0xcc0);
    if (puVar2 == (undefined4 *)0x0) {
      return 0xfffffff4;
    }
    *puVar2 = 0x2ff0;
    *(undefined4 **)(puVar2 + 2) = puVar2 + 0xc00;
  }
  *param_1 = puVar2;
  return 0;
}


// ===== 00121d20 __pfx_nvidia_modeset_enumerate_gpus =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121e0c) */
/* WARNING: Removing unreachable block (ram,0x00121de0) */

int __pfx_nvidia_modeset_enumerate_gpus(undefined4 *param_1)

{
  undefined1 uVar1;
  long lVar2;
  bool bVar3;
  int iVar4;
  
  down(nv_linux_devices_lock);
  iVar4 = 0;
  lVar2 = nv_linux_devices;
  if (nv_linux_devices != 0) {
    do {
      bVar3 = false;
      if (*(int *)(lVar2 + 0x4a0) != -1) {
        bVar3 = *(int *)(lVar2 + 0x4a4) != 0 && *(int *)(lVar2 + 0x4a4) != 3;
      }
      iVar4 = iVar4 + 1;
      *param_1 = *(undefined4 *)(lVar2 + 0x24);
      param_1[1] = *(undefined4 *)(lVar2 + 0x14);
      *(undefined1 *)(param_1 + 2) = *(undefined1 *)(lVar2 + 0x18);
      *(undefined1 *)((long)param_1 + 9) = *(undefined1 *)(lVar2 + 0x19);
      uVar1 = *(undefined1 *)(lVar2 + 0x1a);
      *(bool *)(param_1 + 3) = bVar3;
      *(undefined1 *)((long)param_1 + 10) = uVar1;
      *(undefined8 *)(param_1 + 4) = *(undefined8 *)(lVar2 + 0x3b0);
      *(byte *)((long)param_1 + 0xd) = *(byte *)(lVar2 + 0x10) & 0x10;
      lVar2 = *(long *)(lVar2 + 0x758);
      if (lVar2 == 0) {
        up(nv_linux_devices_lock);
        return iVar4;
      }
      param_1 = param_1 + 6;
    } while (iVar4 != 0x20);
    nv_printf(3,"NVRM: More than %d GPUs found.",0x20);
  }
  up(nv_linux_devices_lock);
  return 0;
}


// ===== 00121d30 nvidia_modeset_enumerate_gpus =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121e0c) */
/* WARNING: Removing unreachable block (ram,0x00121de0) */

int nvidia_modeset_enumerate_gpus(undefined4 *param_1)

{
  undefined1 uVar1;
  long lVar2;
  bool bVar3;
  int iVar4;
  
  down(nv_linux_devices_lock);
  iVar4 = 0;
  lVar2 = nv_linux_devices;
  if (nv_linux_devices != 0) {
    do {
      bVar3 = false;
      if (*(int *)(lVar2 + 0x4a0) != -1) {
        bVar3 = *(int *)(lVar2 + 0x4a4) != 0 && *(int *)(lVar2 + 0x4a4) != 3;
      }
      iVar4 = iVar4 + 1;
      *param_1 = *(undefined4 *)(lVar2 + 0x24);
      param_1[1] = *(undefined4 *)(lVar2 + 0x14);
      *(undefined1 *)(param_1 + 2) = *(undefined1 *)(lVar2 + 0x18);
      *(undefined1 *)((long)param_1 + 9) = *(undefined1 *)(lVar2 + 0x19);
      uVar1 = *(undefined1 *)(lVar2 + 0x1a);
      *(bool *)(param_1 + 3) = bVar3;
      *(undefined1 *)((long)param_1 + 10) = uVar1;
      *(undefined8 *)(param_1 + 4) = *(undefined8 *)(lVar2 + 0x3b0);
      *(byte *)((long)param_1 + 0xd) = *(byte *)(lVar2 + 0x10) & 0x10;
      lVar2 = *(long *)(lVar2 + 0x758);
      if (lVar2 == 0) {
        up(nv_linux_devices_lock);
        return iVar4;
      }
      param_1 = param_1 + 6;
    } while (iVar4 != 0x20);
    nv_printf(3,"NVRM: More than %d GPUs found.",0x20);
  }
  up(nv_linux_devices_lock);
  return 0;
}


// ===== 00121e20 __pfx_nvidia_modeset_suspend =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121e4e) */

void __pfx_nvidia_modeset_suspend(void)

{
  if (nv_modeset_callbacks != (undefined8 *)0x0) {
    (*(code *)*nv_modeset_callbacks)();
    return;
  }
  return;
}


// ===== 00121e30 nvidia_modeset_suspend =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121e4e) */

void nvidia_modeset_suspend(void)

{
  if (nv_modeset_callbacks != (undefined8 *)0x0) {
    (*(code *)*nv_modeset_callbacks)();
    return;
  }
  return;
}


// ===== 00121e60 __pfx_nvidia_modeset_resume =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121e8f) */

void __pfx_nvidia_modeset_resume(void)

{
  if (nv_modeset_callbacks != 0) {
    (**(code **)(nv_modeset_callbacks + 8))();
    return;
  }
  return;
}


// ===== 00121e70 nvidia_modeset_resume =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121e8f) */

void nvidia_modeset_resume(void)

{
  if (nv_modeset_callbacks != 0) {
    (**(code **)(nv_modeset_callbacks + 8))();
    return;
  }
  return;
}


// ===== 00121ea0 __pfx_nvidia_modeset_remove =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121ed4) */

void __pfx_nvidia_modeset_remove(void)

{
  if ((nv_modeset_callbacks != 0) && (*(code **)(nv_modeset_callbacks + 0x10) != (code *)0x0)) {
    (**(code **)(nv_modeset_callbacks + 0x10))();
    return;
  }
  return;
}


// ===== 00121eb0 nvidia_modeset_remove =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121ed4) */

void nvidia_modeset_remove(void)

{
  if ((nv_modeset_callbacks != 0) && (*(code **)(nv_modeset_callbacks + 0x10) != (code *)0x0)) {
    (**(code **)(nv_modeset_callbacks + 0x10))();
    return;
  }
  return;
}


// ===== 00121ee0 __pfx_nvidia_modeset_probe =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121fb2) */

void __pfx_nvidia_modeset_probe(long param_1)

{
  bool bVar1;
  long in_GS_OFFSET;
  undefined8 uStack_28;
  ulong uStack_20;
  undefined8 uStack_18;
  long lStack_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x121ef9;
  lStack_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if ((nv_modeset_callbacks != 0) && (*(code **)(nv_modeset_callbacks + 0x18) != (code *)0x0)) {
    bVar1 = false;
    if (*(int *)(param_1 + 0x4a0) != -1) {
      bVar1 = *(int *)(param_1 + 0x4a4) != 0 && *(int *)(param_1 + 0x4a4) != 3;
    }
    uStack_18 = *(undefined8 *)(param_1 + 0x3b0);
    uStack_28 = CONCAT44(*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x24));
    uStack_20 = (ulong)CONCAT33((int3)(((uint6)CONCAT11((char)*(undefined4 *)(param_1 + 0x10),bVar1)
                                       << 0x20) >> 0x18),*(undefined3 *)(param_1 + 0x18)) &
                0xffff10ffffffffff;
    (**(code **)(nv_modeset_callbacks + 0x18))(&uStack_28);
  }
  if (lStack_10 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00121ef0 nvidia_modeset_probe =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00121fb2) */

void nvidia_modeset_probe(long param_1)

{
  bool bVar1;
  long in_GS_OFFSET;
  undefined8 local_28;
  ulong local_20;
  undefined8 local_18;
  long local_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x121ef9;
  local_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if ((nv_modeset_callbacks != 0) && (*(code **)(nv_modeset_callbacks + 0x18) != (code *)0x0)) {
    bVar1 = false;
    if (*(int *)(param_1 + 0x4a0) != -1) {
      bVar1 = *(int *)(param_1 + 0x4a4) != 0 && *(int *)(param_1 + 0x4a4) != 3;
    }
    local_18 = *(undefined8 *)(param_1 + 0x3b0);
    local_28 = CONCAT44(*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x24));
    local_20 = (ulong)CONCAT33((int3)(((uint6)CONCAT11((char)*(undefined4 *)(param_1 + 0x10),bVar1)
                                      << 0x20) >> 0x18),*(undefined3 *)(param_1 + 0x18)) &
               0xffff10ffffffffff;
    (**(code **)(nv_modeset_callbacks + 0x18))(&local_28);
  }
  if (local_10 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00121fc0 __pfx__raw_q_schedule =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00122051) */
/* WARNING: Removing unreachable block (ram,0x00122072) */

undefined8 __pfx__raw_q_schedule(long *param_1,long *param_2)

{
  long *plVar1;
  undefined8 uVar2;
  
  uVar2 = _raw_spin_lock_irqsave(param_1 + 2);
  if (param_2 == (long *)*param_2) {
    plVar1 = (long *)param_1[1];
    if (((param_1 == (long *)*plVar1) && (param_2 != plVar1)) && (param_2 != param_1)) {
      param_1[1] = (long)param_2;
      param_2[1] = (long)plVar1;
      *param_2 = (long)param_1;
      *plVar1 = (long)param_2;
      _raw_spin_unlock_irqrestore(param_1 + 2,uVar2);
    }
    else {
      __list_add_valid_or_report(param_2,plVar1,param_1);
      _raw_spin_unlock_irqrestore(param_1 + 2,uVar2);
    }
    up(param_1 + 3);
    return 1;
  }
  _raw_spin_unlock_irqrestore(param_1 + 2,uVar2);
  return 0;
}


// ===== 00121fd0 _raw_q_schedule =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00122051) */
/* WARNING: Removing unreachable block (ram,0x00122072) */

undefined8 _raw_q_schedule(long *param_1,long *param_2)

{
  long *plVar1;
  undefined8 uVar2;
  
  uVar2 = _raw_spin_lock_irqsave(param_1 + 2);
  if (param_2 == (long *)*param_2) {
    plVar1 = (long *)param_1[1];
    if (((param_1 == (long *)*plVar1) && (param_2 != plVar1)) && (param_2 != param_1)) {
      param_1[1] = (long)param_2;
      param_2[1] = (long)plVar1;
      *param_2 = (long)param_1;
      *plVar1 = (long)param_2;
      _raw_spin_unlock_irqrestore(param_1 + 2,uVar2);
    }
    else {
      __list_add_valid_or_report(param_2,plVar1,param_1);
      _raw_spin_unlock_irqrestore(param_1 + 2,uVar2);
    }
    up(param_1 + 3);
    return 1;
  }
  _raw_spin_unlock_irqrestore(param_1 + 2,uVar2);
  return 0;
}


// ===== 00122080 __pfx__q_flush_function =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx__q_flush_function(void)

{
  complete();
  return;
}


// ===== 00122090 _q_flush_function =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void _q_flush_function(void)

{
  complete();
  return;
}


// ===== 001220a0 __pfx__main_loop =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012219c) */

undefined8 __pfx__main_loop(long *param_1)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  long lVar4;
  char cVar5;
  int iVar6;
  undefined8 uVar7;
  long in_GS_OFFSET;
  
  lVar1 = *(long *)(&const_current_task + in_GS_OFFSET);
LAB_001220d7:
  do {
    iVar6 = down_interruptible(param_1 + 3);
    while (iVar6 == 0) {
      if ((int)param_1[6] != 0) {
        while (cVar5 = kthread_should_stop(), cVar5 == '\0') {
          schedule();
        }
        return 0;
      }
      uVar7 = _raw_spin_lock_irqsave(param_1 + 2);
      if (param_1 == (long *)*param_1) {
        _raw_spin_unlock_irqrestore(param_1 + 2);
        if (*(short *)(&DAT_00f79bd9 + in_GS_OFFSET) == 0) {
          __SCT__WARN_trap(&DAT_00100eb0,*(long *)(&const_current_task + in_GS_OFFSET) + 0xd48,
                           param_1);
        }
        else {
          __SCT__WARN_trap(&DAT_00100ea0,param_1);
        }
        goto LAB_001220d7;
      }
      plVar2 = (long *)*param_1;
      plVar3 = (long *)plVar2[1];
      lVar4 = *plVar2;
      if ((plVar2 == (long *)*plVar3) && (plVar2 == *(long **)(lVar4 + 8))) {
        *(long **)(lVar4 + 8) = plVar3;
        *plVar3 = lVar4;
      }
      else {
        __list_del_entry_valid_or_report(plVar2);
      }
      *plVar2 = (long)plVar2;
      plVar2[1] = (long)plVar2;
      _raw_spin_unlock_irqrestore(param_1 + 2,uVar7);
      if ((code *)plVar2[2] != _q_flush_function) {
        (*(code *)plVar2[2])(plVar2[3]);
        goto LAB_001220d7;
      }
      complete();
      iVar6 = down_interruptible(param_1 + 3);
    }
    if (*(short *)(&DAT_00f79bd9 + in_GS_OFFSET) == 0) {
      __SCT__WARN_trap(&DAT_00100e90,lVar1 + 0xd48);
    }
    else {
      __SCT__WARN_trap(&DAT_00100e80);
    }
  } while( true );
}


// ===== 001220b0 _main_loop =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012219c) */

undefined8 _main_loop(long *param_1)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  long lVar4;
  char cVar5;
  int iVar6;
  undefined8 uVar7;
  long in_GS_OFFSET;
  
  lVar1 = *(long *)(&const_current_task + in_GS_OFFSET);
LAB_001220d7:
  do {
    iVar6 = down_interruptible(param_1 + 3);
    while (iVar6 == 0) {
      if ((int)param_1[6] != 0) {
        while (cVar5 = kthread_should_stop(), cVar5 == '\0') {
          schedule();
        }
        return 0;
      }
      uVar7 = _raw_spin_lock_irqsave(param_1 + 2);
      if (param_1 == (long *)*param_1) {
        _raw_spin_unlock_irqrestore(param_1 + 2);
        if (*(short *)(&DAT_00f79bd9 + in_GS_OFFSET) == 0) {
          __SCT__WARN_trap(&DAT_00100eb0,*(long *)(&const_current_task + in_GS_OFFSET) + 0xd48,
                           param_1);
        }
        else {
          __SCT__WARN_trap(&DAT_00100ea0,param_1);
        }
        goto LAB_001220d7;
      }
      plVar2 = (long *)*param_1;
      plVar3 = (long *)plVar2[1];
      lVar4 = *plVar2;
      if ((plVar2 == (long *)*plVar3) && (plVar2 == *(long **)(lVar4 + 8))) {
        *(long **)(lVar4 + 8) = plVar3;
        *plVar3 = lVar4;
      }
      else {
        __list_del_entry_valid_or_report(plVar2);
      }
      *plVar2 = (long)plVar2;
      plVar2[1] = (long)plVar2;
      _raw_spin_unlock_irqrestore(param_1 + 2,uVar7);
      if ((code *)plVar2[2] != _q_flush_function) {
        (*(code *)plVar2[2])(plVar2[3]);
        goto LAB_001220d7;
      }
      complete();
      iVar6 = down_interruptible(param_1 + 3);
    }
    if (*(short *)(&DAT_00f79bd9 + in_GS_OFFSET) == 0) {
      __SCT__WARN_trap(&DAT_00100e90,lVar1 + 0xd48);
    }
    else {
      __SCT__WARN_trap(&DAT_00100e80);
    }
  } while( true );
}


// ===== 00122210 __pfx_nv_kthread_q_init_on_node =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012236e) */

ulong __pfx_nv_kthread_q_init_on_node(long param_1,undefined8 param_2,uint param_3)

{
  char cVar1;
  ulong uVar2;
  undefined8 *puVar3;
  ulong uVar4;
  ulong uVar5;
  long in_GS_OFFSET;
  ulong auStack_58 [4];
  
  auStack_58[3] = *(ulong *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  *(long *)param_1 = param_1;
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(undefined8 *)(param_1 + 0x18) = 0;
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(undefined8 *)(param_1 + 0x40) = 0;
  *(long *)(param_1 + 8) = param_1;
  if (param_3 == 0xffffffff) {
    uVar4 = kthread_create_on_node(_main_loop,param_1,0xffffffff,param_2);
    *(ulong *)(param_1 + 0x38) = uVar4;
  }
  else {
    auStack_58[0] = 0;
    auStack_58[1] = 0;
    auStack_58[2] = 0;
    uVar4 = 0;
    do {
      uVar2 = kthread_create_on_node(_main_loop,param_1,param_3,param_2);
      uVar5 = uVar4 & 0xffffffff;
      auStack_58[uVar4] = uVar2;
      if (0xfffffffffffff000 < uVar2) {
        uVar5 = (ulong)((int)uVar4 + -1 + (uint)((int)uVar4 == 0));
        break;
      }
      cVar1 = is_vmalloc_addr(*(undefined8 *)(uVar2 + 0x20));
      if (cVar1 == '\0') break;
      if (uVar4 == 2) {
        uVar5 = 2;
        goto LAB_00122379;
      }
      uVar4 = uVar4 + 1;
      puVar3 = (undefined8 *)vmalloc_to_page(*(undefined8 *)(uVar2 + 0x20));
    } while (param_3 != (uint)((ulong)*puVar3 >> 0x36));
    if ((int)uVar5 != 0) {
LAB_00122379:
      kthread_stop(auStack_58[(int)uVar5 - 1]);
      if ((int)uVar5 == 1) {
        uVar5 = 1;
      }
      else {
        uVar5 = 2;
        kthread_stop(auStack_58[0]);
      }
    }
    uVar4 = auStack_58[uVar5];
    *(ulong *)(param_1 + 0x38) = uVar4;
  }
  if (uVar4 < 0xfffffffffffff001) {
    wake_up_process();
    uVar4 = 0;
  }
  else {
    *(undefined8 *)(param_1 + 0x38) = 0;
    uVar4 = uVar4 & 0xffffffff;
  }
  if (auStack_58[3] != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}


// ===== 00122220 nv_kthread_q_init_on_node =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012236e) */

ulong nv_kthread_q_init_on_node(long param_1,undefined8 param_2,uint param_3)

{
  char cVar1;
  ulong uVar2;
  undefined8 *puVar3;
  ulong uVar4;
  ulong uVar5;
  long in_GS_OFFSET;
  ulong local_58 [4];
  
  local_58[3] = *(ulong *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  *(long *)param_1 = param_1;
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(undefined8 *)(param_1 + 0x18) = 0;
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(undefined8 *)(param_1 + 0x40) = 0;
  *(long *)(param_1 + 8) = param_1;
  if (param_3 == 0xffffffff) {
    uVar4 = kthread_create_on_node(_main_loop,param_1,0xffffffff,param_2);
    *(ulong *)(param_1 + 0x38) = uVar4;
  }
  else {
    local_58[0] = 0;
    local_58[1] = 0;
    local_58[2] = 0;
    uVar4 = 0;
    do {
      uVar2 = kthread_create_on_node(_main_loop,param_1,param_3,param_2);
      uVar5 = uVar4 & 0xffffffff;
      local_58[uVar4] = uVar2;
      if (0xfffffffffffff000 < uVar2) {
        uVar5 = (ulong)((int)uVar4 + -1 + (uint)((int)uVar4 == 0));
        break;
      }
      cVar1 = is_vmalloc_addr(*(undefined8 *)(uVar2 + 0x20));
      if (cVar1 == '\0') break;
      if (uVar4 == 2) {
        uVar5 = 2;
        goto LAB_00122379;
      }
      uVar4 = uVar4 + 1;
      puVar3 = (undefined8 *)vmalloc_to_page(*(undefined8 *)(uVar2 + 0x20));
    } while (param_3 != (uint)((ulong)*puVar3 >> 0x36));
    if ((int)uVar5 != 0) {
LAB_00122379:
      kthread_stop(local_58[(int)uVar5 - 1]);
      if ((int)uVar5 == 1) {
        uVar5 = 1;
      }
      else {
        uVar5 = 2;
        kthread_stop(local_58[0]);
      }
    }
    uVar4 = local_58[uVar5];
    *(ulong *)(param_1 + 0x38) = uVar4;
  }
  if (uVar4 < 0xfffffffffffff001) {
    wake_up_process();
    uVar4 = 0;
  }
  else {
    *(undefined8 *)(param_1 + 0x38) = 0;
    uVar4 = uVar4 & 0xffffffff;
  }
  if (local_58[3] != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}


// ===== 00122410 __pfx_nv_kthread_q_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_kthread_q_init(undefined8 param_1,undefined8 param_2)

{
  nv_kthread_q_init_on_node(param_1,param_2,0xffffffff);
  return;
}


// ===== 00122420 nv_kthread_q_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_kthread_q_init(undefined8 param_1,undefined8 param_2)

{
  nv_kthread_q_init_on_node(param_1,param_2,0xffffffff);
  return;
}


// ===== 00122440 __pfx_nv_kthread_q_item_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00122468) */

void __pfx_nv_kthread_q_item_init(long param_1,undefined8 param_2,undefined8 param_3)

{
  *(long *)param_1 = param_1;
  *(undefined8 *)(param_1 + 0x10) = param_2;
  *(long *)(param_1 + 8) = param_1;
  *(undefined8 *)(param_1 + 0x18) = param_3;
  return;
}


// ===== 00122450 nv_kthread_q_item_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00122468) */

void nv_kthread_q_item_init(long param_1,undefined8 param_2,undefined8 param_3)

{
  *(long *)param_1 = param_1;
  *(undefined8 *)(param_1 + 0x10) = param_2;
  *(long *)(param_1 + 8) = param_1;
  *(undefined8 *)(param_1 + 0x18) = param_3;
  return;
}


// ===== 00122470 __pfx_nv_kthread_q_schedule_q_item =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001224b5) */

undefined8 __pfx_nv_kthread_q_schedule_q_item(long param_1)

{
  undefined8 uVar1;
  long in_GS_OFFSET;
  
  if (*(int *)(param_1 + 0x30) == 0) {
    uVar1 = _raw_q_schedule();
    return uVar1;
  }
  if (*(short *)(&DAT_00f79bd9 + in_GS_OFFSET) == 0) {
    __SCT__WARN_trap(&DAT_00100ed0,*(long *)(&const_current_task + in_GS_OFFSET) + 0xd48,param_1);
  }
  else {
    __SCT__WARN_trap(&DAT_00100ec0,param_1);
  }
  return 0;
}


// ===== 00122480 nv_kthread_q_schedule_q_item =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001224b5) */

undefined8 nv_kthread_q_schedule_q_item(long param_1)

{
  undefined8 uVar1;
  long in_GS_OFFSET;
  
  if (*(int *)(param_1 + 0x30) == 0) {
    uVar1 = _raw_q_schedule();
    return uVar1;
  }
  if (*(short *)(&DAT_00f79bd9 + in_GS_OFFSET) == 0) {
    __SCT__WARN_trap(&DAT_00100ed0,*(long *)(&const_current_task + in_GS_OFFSET) + 0xd48,param_1);
  }
  else {
    __SCT__WARN_trap(&DAT_00100ec0,param_1);
  }
  return 0;
}


// ===== 001224e0 __pfx_nv_kthread_q_flush =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001225d8) */

void __pfx_nv_kthread_q_flush(long param_1)

{
  long in_GS_OFFSET;
  undefined1 *puStack_80;
  undefined1 *puStack_78;
  code *pcStack_70;
  undefined8 *puStack_68;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 **ppuStack_48;
  undefined8 **ppuStack_40;
  long lStack_38;
  
  lStack_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if (*(int *)(param_1 + 0x30) == 0) {
    uStack_58 = 0;
    uStack_50 = 0;
    pcStack_70 = _q_flush_function;
    puStack_80 = (undefined1 *)&puStack_80;
    puStack_78 = (undefined1 *)&puStack_80;
    puStack_68 = &uStack_58;
    ppuStack_48 = &ppuStack_48;
    ppuStack_40 = &ppuStack_48;
    _raw_q_schedule(param_1,&puStack_80);
    wait_for_completion(&uStack_58);
    uStack_58 = 0;
    uStack_50 = 0;
    pcStack_70 = _q_flush_function;
    puStack_80 = (undefined1 *)&puStack_80;
    puStack_78 = (undefined1 *)&puStack_80;
    puStack_68 = &uStack_58;
    ppuStack_48 = &ppuStack_48;
    ppuStack_40 = &ppuStack_48;
    _raw_q_schedule(param_1,&puStack_80);
    wait_for_completion(&uStack_58);
  }
  else if (*(short *)(&DAT_00f79bd9 + in_GS_OFFSET) == 0) {
    __SCT__WARN_trap(&DAT_00100ef0,*(long *)(&const_current_task + in_GS_OFFSET) + 0xd48,param_1);
  }
  else {
    __SCT__WARN_trap(&DAT_00100ee0,param_1);
  }
  if (lStack_38 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 001224f0 nv_kthread_q_flush =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001225d8) */

void nv_kthread_q_flush(long param_1)

{
  long in_GS_OFFSET;
  undefined1 *local_80;
  undefined1 *local_78;
  code *local_70;
  undefined8 *local_68;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 **local_48;
  undefined8 **local_40;
  long local_38;
  
  local_38 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  if (*(int *)(param_1 + 0x30) == 0) {
    local_58 = 0;
    local_50 = 0;
    local_70 = _q_flush_function;
    local_80 = (undefined1 *)&local_80;
    local_78 = (undefined1 *)&local_80;
    local_68 = &local_58;
    local_48 = &local_48;
    local_40 = &local_48;
    _raw_q_schedule(param_1,&local_80);
    wait_for_completion(&local_58);
    local_58 = 0;
    local_50 = 0;
    local_70 = _q_flush_function;
    local_80 = (undefined1 *)&local_80;
    local_78 = (undefined1 *)&local_80;
    local_68 = &local_58;
    local_48 = &local_48;
    local_40 = &local_48;
    _raw_q_schedule(param_1,&local_80);
    wait_for_completion(&local_58);
  }
  else if (*(short *)(&DAT_00f79bd9 + in_GS_OFFSET) == 0) {
    __SCT__WARN_trap(&DAT_00100ef0,*(long *)(&const_current_task + in_GS_OFFSET) + 0xd48,param_1);
  }
  else {
    __SCT__WARN_trap(&DAT_00100ee0,param_1);
  }
  if (local_38 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00122620 __pfx_nv_kthread_q_stop =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00122677) */
/* WARNING: Removing unreachable block (ram,0x0012267c) */

void __pfx_nv_kthread_q_stop(long *param_1)

{
  long in_GS_OFFSET;
  
  if (param_1[7] != 0) {
    nv_kthread_q_flush();
    if (param_1 != (long *)*param_1) {
      if (*(short *)(&DAT_00f79bd9 + in_GS_OFFSET) == 0) {
        __SCT__WARN_trap(&DAT_00100f10,*(long *)(&const_current_task + in_GS_OFFSET) + 0xd48);
      }
      else {
        __SCT__WARN_trap(&DAT_00100f00);
      }
    }
    if ((int)param_1[6] == 0) {
      *(undefined4 *)(param_1 + 6) = 1;
      up(param_1 + 3);
      kthread_stop(param_1[7]);
      param_1[7] = 0;
    }
    return;
  }
  return;
}


// ===== 00122630 nv_kthread_q_stop =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00122677) */
/* WARNING: Removing unreachable block (ram,0x0012267c) */

void nv_kthread_q_stop(long *param_1)

{
  long in_GS_OFFSET;
  
  if (param_1[7] != 0) {
    nv_kthread_q_flush();
    if (param_1 != (long *)*param_1) {
      if (*(short *)(&DAT_00f79bd9 + in_GS_OFFSET) == 0) {
        __SCT__WARN_trap(&DAT_00100f10,*(long *)(&const_current_task + in_GS_OFFSET) + 0xd48);
      }
      else {
        __SCT__WARN_trap(&DAT_00100f00);
      }
    }
    if ((int)param_1[6] == 0) {
      *(undefined4 *)(param_1 + 6) = 1;
      up(param_1 + 3);
      kthread_stop(param_1[7]);
      param_1[7] = 0;
    }
    return;
  }
  return;
}


// ===== 001226c0 __pfx_nv_memdbg_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001226ee) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __pfx_nv_memdbg_init(void)

{
  _DAT_005464f8 = 0;
  g_nv_memdbg = 0;
  return;
}


// ===== 001226d0 nv_memdbg_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001226ee) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void nv_memdbg_init(void)

{
  _DAT_005464f8 = 0;
  g_nv_memdbg = 0;
  return;
}


// ===== 00122700 __pfx_nv_memdbg_add =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012282b) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __pfx_nv_memdbg_add(long param_1,long param_2,undefined8 param_3,undefined4 param_4)

{
  long lVar1;
  code *pcVar2;
  long *plVar3;
  undefined8 uVar4;
  long lVar5;
  long *plVar6;
  int iVar7;
  long in_GS_OFFSET;
  undefined1 auVar8 [16];
  
  if (param_1 == 0) {
    return;
  }
  auVar8 = (*_mpi_powm)();
  iVar7 = 0x2820;
  if ((auVar8._0_8_ & 0x200) != 0) {
    iVar7 = (-(uint)((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0) & 0x4a0) +
            0x2820;
  }
  plVar3 = (long *)__kmalloc_cache_noprof(_capable,iVar7,0x38);
  if (plVar3 == (long *)0x0) {
    uVar4 = _raw_spin_lock_irqsave(&DAT_005464f8);
    DAT_005464f0 = DAT_005464f0 + 1;
    DAT_005464e8 = DAT_005464e8 + param_2;
  }
  else {
    plVar3[3] = param_1;
    plVar3[4] = param_2;
    plVar3[6] = auVar8._8_8_;
    *(undefined4 *)(plVar3 + 5) = param_4;
    uVar4 = _raw_spin_lock_irqsave(&DAT_005464f8);
    if (g_nv_memdbg == 0) {
      lVar5 = 0;
      plVar6 = &g_nv_memdbg;
    }
    else {
      lVar1 = g_nv_memdbg;
      do {
        lVar5 = lVar1;
        if (plVar3[3] == *(ulong *)(lVar5 + 0x18)) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)invalidInstructionException();
          (*pcVar2)();
        }
        if ((ulong)plVar3[3] < *(ulong *)(lVar5 + 0x18)) {
          lVar1 = *(long *)(lVar5 + 0x10);
          plVar6 = (long *)(lVar5 + 0x10);
        }
        else {
          lVar1 = *(long *)(lVar5 + 8);
          plVar6 = (long *)(lVar5 + 8);
        }
      } while (lVar1 != 0);
    }
    *plVar3 = lVar5;
    plVar3[1] = 0;
    plVar3[2] = 0;
    *plVar6 = (long)plVar3;
    rb_insert_color(plVar3,&g_nv_memdbg);
  }
  _raw_spin_unlock_irqrestore(&DAT_005464f8,uVar4);
  return;
}


// ===== 00122710 nv_memdbg_add =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012282b) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void nv_memdbg_add(long param_1,long param_2,undefined8 param_3,undefined4 param_4)

{
  long lVar1;
  code *pcVar2;
  long *plVar3;
  undefined8 uVar4;
  long lVar5;
  long *plVar6;
  int iVar7;
  long in_GS_OFFSET;
  undefined1 auVar8 [16];
  
  if (param_1 == 0) {
    return;
  }
  auVar8 = (*_mpi_powm)();
  iVar7 = 0x2820;
  if ((auVar8._0_8_ & 0x200) != 0) {
    iVar7 = (-(uint)((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0) & 0x4a0) +
            0x2820;
  }
  plVar3 = (long *)__kmalloc_cache_noprof(_capable,iVar7,0x38);
  if (plVar3 == (long *)0x0) {
    uVar4 = _raw_spin_lock_irqsave(&DAT_005464f8);
    DAT_005464f0 = DAT_005464f0 + 1;
    DAT_005464e8 = DAT_005464e8 + param_2;
  }
  else {
    plVar3[3] = param_1;
    plVar3[4] = param_2;
    plVar3[6] = auVar8._8_8_;
    *(undefined4 *)(plVar3 + 5) = param_4;
    uVar4 = _raw_spin_lock_irqsave(&DAT_005464f8);
    if (g_nv_memdbg == 0) {
      lVar5 = 0;
      plVar6 = &g_nv_memdbg;
    }
    else {
      lVar1 = g_nv_memdbg;
      do {
        lVar5 = lVar1;
        if (plVar3[3] == *(ulong *)(lVar5 + 0x18)) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)invalidInstructionException();
          (*pcVar2)();
        }
        if ((ulong)plVar3[3] < *(ulong *)(lVar5 + 0x18)) {
          lVar1 = *(long *)(lVar5 + 0x10);
          plVar6 = (long *)(lVar5 + 0x10);
        }
        else {
          lVar1 = *(long *)(lVar5 + 8);
          plVar6 = (long *)(lVar5 + 8);
        }
      } while (lVar1 != 0);
    }
    *plVar3 = lVar5;
    plVar3[1] = 0;
    plVar3[2] = 0;
    *plVar6 = (long)plVar3;
    rb_insert_color(plVar3,&g_nv_memdbg);
  }
  _raw_spin_unlock_irqrestore(&DAT_005464f8,uVar4);
  return;
}


// ===== 00122860 __pfx_nv_memdbg_remove =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00122915) */

void __pfx_nv_memdbg_remove(ulong param_1,long param_2)

{
  long *plVar1;
  ulong *puVar2;
  code *pcVar3;
  undefined8 uVar4;
  long lVar5;
  
  if (param_1 == 0) {
    return;
  }
  uVar4 = _raw_spin_lock_irqsave(&DAT_005464f8);
  lVar5 = g_nv_memdbg;
  if (g_nv_memdbg != 0) {
    do {
      puVar2 = (ulong *)(lVar5 + 0x18);
      if (param_1 == *puVar2) {
        rb_erase(lVar5,&g_nv_memdbg);
        _raw_spin_unlock_irqrestore(&DAT_005464f8,uVar4);
        if ((param_2 != 0) && (*(long *)(lVar5 + 0x20) != param_2)) {
          nv_printf(4,"NVRM: size mismatch on free: %llu != %llu\n",param_2);
          if (*(long *)(lVar5 + 0x30) == 0) {
            nv_printf(4,"NVRM:     allocation: 0x%p\n",*(undefined8 *)(lVar5 + 0x18));
          }
          else {
            nv_printf(4,"NVRM:     allocation: 0x%p @ %s:%d\n",*(undefined8 *)(lVar5 + 0x18),
                      *(long *)(lVar5 + 0x30),*(undefined4 *)(lVar5 + 0x28));
          }
          os_dbg_breakpoint();
          kfree(lVar5);
          return;
        }
        kfree(lVar5);
        return;
      }
      plVar1 = (long *)(lVar5 + 8);
      lVar5 = *(long *)(lVar5 + 0x10);
      if (*puVar2 <= param_1) {
        lVar5 = *plVar1;
      }
    } while (lVar5 != 0);
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)invalidInstructionException();
  (*pcVar3)();
}


// ===== 00122870 nv_memdbg_remove =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00122915) */

void nv_memdbg_remove(ulong param_1,long param_2)

{
  long *plVar1;
  ulong *puVar2;
  code *pcVar3;
  undefined8 uVar4;
  long lVar5;
  
  if (param_1 == 0) {
    return;
  }
  uVar4 = _raw_spin_lock_irqsave(&DAT_005464f8);
  lVar5 = g_nv_memdbg;
  if (g_nv_memdbg != 0) {
    do {
      puVar2 = (ulong *)(lVar5 + 0x18);
      if (param_1 == *puVar2) {
        rb_erase(lVar5,&g_nv_memdbg);
        _raw_spin_unlock_irqrestore(&DAT_005464f8,uVar4);
        if ((param_2 != 0) && (*(long *)(lVar5 + 0x20) != param_2)) {
          nv_printf(4,"NVRM: size mismatch on free: %llu != %llu\n",param_2);
          if (*(long *)(lVar5 + 0x30) == 0) {
            nv_printf(4,"NVRM:     allocation: 0x%p\n",*(undefined8 *)(lVar5 + 0x18));
          }
          else {
            nv_printf(4,"NVRM:     allocation: 0x%p @ %s:%d\n",*(undefined8 *)(lVar5 + 0x18),
                      *(long *)(lVar5 + 0x30),*(undefined4 *)(lVar5 + 0x28));
          }
          os_dbg_breakpoint();
          kfree(lVar5);
          return;
        }
        kfree(lVar5);
        return;
      }
      plVar1 = (long *)(lVar5 + 8);
      lVar5 = *(long *)(lVar5 + 0x10);
      if (*puVar2 <= param_1) {
        lVar5 = *plVar1;
      }
    } while (lVar5 != 0);
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)invalidInstructionException();
  (*pcVar3)();
}


// ===== 001229e0 __pfx_nv_memdbg_exit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00122b29) */

void __pfx_nv_memdbg_exit(void)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  
  if (g_nv_memdbg != 0) {
    nv_printf(4,"NVRM: list of leaked memory allocations:\n");
  }
  lVar3 = 0;
  lVar4 = 0;
  if (g_nv_memdbg != 0) {
    do {
      lVar1 = g_nv_memdbg;
      if (g_nv_memdbg == 0) {
        lVar2 = 0;
      }
      else {
        do {
          lVar2 = lVar1;
          lVar1 = *(long *)(lVar2 + 0x10);
        } while (*(long *)(lVar2 + 0x10) != 0);
      }
      lVar1 = *(long *)(lVar2 + 0x20);
      lVar3 = lVar3 + 1;
      lVar4 = lVar4 + lVar1;
      if (*(long *)(lVar2 + 0x30) == 0) {
        nv_printf(4,"NVRM:    %llu bytes, 0x%p\n",lVar1,*(undefined8 *)(lVar2 + 0x18));
      }
      else {
        nv_printf(4,"NVRM:    %llu bytes, 0x%p @ %s:%d\n",lVar1,*(undefined8 *)(lVar2 + 0x18),
                  *(long *)(lVar2 + 0x30),*(undefined4 *)(lVar2 + 0x28));
      }
      rb_erase(lVar2,&g_nv_memdbg);
      kfree(lVar2);
    } while (g_nv_memdbg != 0);
    if (lVar3 != 0) goto LAB_00122ac9;
  }
  if (DAT_005464f0 == 0) {
    return;
  }
  lVar3 = 0;
LAB_00122ac9:
  nv_printf(4,"NVRM: total leaked memory: %llu bytes in %llu allocations\n",DAT_005464e8 + lVar4,
            lVar3 + DAT_005464f0);
  if (DAT_005464f0 == 0) {
    return;
  }
  nv_printf(4,"NVRM:                      %llu bytes in %llu allocations untracked\n",DAT_005464e8);
  return;
}


// ===== 001229f0 nv_memdbg_exit =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00122b29) */

void nv_memdbg_exit(void)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  
  if (g_nv_memdbg != 0) {
    nv_printf(4,"NVRM: list of leaked memory allocations:\n");
  }
  lVar3 = 0;
  lVar4 = 0;
  if (g_nv_memdbg != 0) {
    do {
      lVar1 = g_nv_memdbg;
      if (g_nv_memdbg == 0) {
        lVar2 = 0;
      }
      else {
        do {
          lVar2 = lVar1;
          lVar1 = *(long *)(lVar2 + 0x10);
        } while (*(long *)(lVar2 + 0x10) != 0);
      }
      lVar1 = *(long *)(lVar2 + 0x20);
      lVar3 = lVar3 + 1;
      lVar4 = lVar4 + lVar1;
      if (*(long *)(lVar2 + 0x30) == 0) {
        nv_printf(4,"NVRM:    %llu bytes, 0x%p\n",lVar1,*(undefined8 *)(lVar2 + 0x18));
      }
      else {
        nv_printf(4,"NVRM:    %llu bytes, 0x%p @ %s:%d\n",lVar1,*(undefined8 *)(lVar2 + 0x18),
                  *(long *)(lVar2 + 0x30),*(undefined4 *)(lVar2 + 0x28));
      }
      rb_erase(lVar2,&g_nv_memdbg);
      kfree(lVar2);
    } while (g_nv_memdbg != 0);
    if (lVar3 != 0) goto LAB_00122ac9;
  }
  if (DAT_005464f0 == 0) {
    return;
  }
  lVar3 = 0;
LAB_00122ac9:
  nv_printf(4,"NVRM: total leaked memory: %llu bytes in %llu allocations\n",DAT_005464e8 + lVar4,
            lVar3 + DAT_005464f0);
  if (DAT_005464f0 == 0) {
    return;
  }
  nv_printf(4,"NVRM:                      %llu bytes in %llu allocations untracked\n",DAT_005464e8);
  return;
}


// ===== 00122b60 __pfx___traceiter_nvidia_dev_xid =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00122bdd) */

undefined8
__pfx___traceiter_nvidia_dev_xid
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  long *plVar1;
  code *pcVar2;
  long lVar3;
  long *plVar4;
  
  plVar4 = (long *)__tracepoint_nvidia_dev_xid._56_8_;
  lVar3 = __tracepoint_nvidia_dev_xid._56_8_;
  while (lVar3 != 0) {
    pcVar2 = (code *)*plVar4;
    plVar1 = plVar4 + 1;
    plVar4 = plVar4 + 3;
    (*pcVar2)(*plVar1,param_2,param_3,param_4);
    lVar3 = *plVar4;
  }
  return 0;
}


// ===== 00122b70 __traceiter_nvidia_dev_xid =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00122bdd) */

undefined8
__traceiter_nvidia_dev_xid
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  long *plVar1;
  code *pcVar2;
  long lVar3;
  long *plVar4;
  
  plVar4 = (long *)__tracepoint_nvidia_dev_xid._56_8_;
  lVar3 = __tracepoint_nvidia_dev_xid._56_8_;
  while (lVar3 != 0) {
    pcVar2 = (code *)*plVar4;
    plVar1 = plVar4 + 1;
    plVar4 = plVar4 + 3;
    (*pcVar2)(*plVar1,param_2,param_3,param_4);
    lVar3 = *plVar4;
  }
  return 0;
}


// ===== 00122bf0 __pfx___probestub_nvidia_dev_xid =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00122c09) */

void __pfx___probestub_nvidia_dev_xid(void)

{
  return;
}


// ===== 00122c00 __probestub_nvidia_dev_xid =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00122c09) */

void __probestub_nvidia_dev_xid(void)

{
  return;
}


// ===== 00122c10 __pfx_nvidia_register_error_cb =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00122c4b) */
/* WARNING: Removing unreachable block (ram,0x00122c41) */
/* WARNING: Removing unreachable block (ram,0x00122c55) */

undefined8 __pfx_nvidia_register_error_cb(long param_1)

{
  if (param_1 == 0) {
    return 0xffffffea;
  }
  if (nv_error_cb_handle == 0) {
    nv_error_cb_handle = param_1;
    return 0;
  }
  return 0xfffffff0;
}


// ===== 00122c20 nvidia_register_error_cb =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00122c4b) */
/* WARNING: Removing unreachable block (ram,0x00122c41) */
/* WARNING: Removing unreachable block (ram,0x00122c55) */

undefined8 nvidia_register_error_cb(long param_1)

{
  if (param_1 == 0) {
    return 0xffffffea;
  }
  if (nv_error_cb_handle == 0) {
    nv_error_cb_handle = param_1;
    return 0;
  }
  return 0xfffffff0;
}


// ===== 00122c60 __pfx_nvidia_unregister_error_cb =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00122c90) */
/* WARNING: Removing unreachable block (ram,0x00122c9a) */

undefined8 __pfx_nvidia_unregister_error_cb(void)

{
  if (nv_error_cb_handle != 0) {
    nv_error_cb_handle = 0;
    return 0;
  }
  return 0xffffffff;
}


// ===== 00122c70 nvidia_unregister_error_cb =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00122c90) */
/* WARNING: Removing unreachable block (ram,0x00122c9a) */

undefined8 nvidia_unregister_error_cb(void)

{
  if (nv_error_cb_handle != 0) {
    nv_error_cb_handle = 0;
    return 0;
  }
  return 0xffffffff;
}


// ===== 00122ca0 __pfx_trace_raw_output_nvidia_dev_xid =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00122ccf) */

void __pfx_trace_raw_output_nvidia_dev_xid(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_1 + 0x4080);
  iVar2 = trace_raw_output_prep(param_1,param_3);
  if (iVar2 != 1) {
    return;
  }
  trace_event_printf(param_1,"Xid (PCI:%s): %u, %s\n",(ulong)*(ushort *)(lVar1 + 8) + lVar1,
                     *(undefined4 *)(lVar1 + 0xc),lVar1 + (ulong)*(ushort *)(lVar1 + 0x10));
  trace_handle_return(param_1 + 0x2080);
  return;
}


// ===== 00122cb0 trace_raw_output_nvidia_dev_xid =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00122ccf) */

void trace_raw_output_nvidia_dev_xid(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_1 + 0x4080);
  iVar2 = trace_raw_output_prep(param_1,param_3);
  if (iVar2 != 1) {
    return;
  }
  trace_event_printf(param_1,"Xid (PCI:%s): %u, %s\n",(ulong)*(ushort *)(lVar1 + 8) + lVar1,
                     *(undefined4 *)(lVar1 + 0xc),lVar1 + (ulong)*(ushort *)(lVar1 + 0x10));
  trace_handle_return(param_1 + 0x2080);
  return;
}


// ===== 00122d10 __pfx___bpf_trace_nvidia_dev_xid =====

void __pfx___bpf_trace_nvidia_dev_xid(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  bpf_trace_run3(param_1,param_2,param_3);
  return;
}


// ===== 00122d20 __bpf_trace_nvidia_dev_xid =====

void __bpf_trace_nvidia_dev_xid(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  bpf_trace_run3(param_1,param_2,param_3);
  return;
}


// ===== 00122d30 __pfx_trace_event_get_offsets_nvidia_dev_xid.isra.0 =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00122db6) */

int __pfx_trace_event_get_offsets_nvidia_dev_xid_isra_0(uint *param_1,long param_2,char *param_3)

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


// ===== 00122d40 trace_event_get_offsets_nvidia_dev_xid.isra.0 =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00122db6) */

int trace_event_get_offsets_nvidia_dev_xid_isra_0(uint *param_1,long param_2,char *param_3)

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


// ===== 00122df0 __pfx_trace_event_raw_event_nvidia_dev_xid =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00122fa4) */

void __pfx_trace_event_raw_event_nvidia_dev_xid
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
    iVar5 = trace_event_get_offsets_nvidia_dev_xid_isra_0(&uStack_88,param_2,param_4);
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


// ===== 00122e00 trace_event_raw_event_nvidia_dev_xid =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00122fa4) */

void trace_event_raw_event_nvidia_dev_xid
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
    iVar5 = trace_event_get_offsets_nvidia_dev_xid_isra_0(&local_88,param_2,param_4);
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


// ===== 00123000 __pfx_perf_trace_nvidia_dev_xid =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001231aa) */

void __pfx_perf_trace_nvidia_dev_xid
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
  iVar2 = trace_event_get_offsets_nvidia_dev_xid_isra_0(auStack_58,param_2,param_4);
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


// ===== 00123010 perf_trace_nvidia_dev_xid =====

/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001231aa) */

void perf_trace_nvidia_dev_xid
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
  iVar2 = trace_event_get_offsets_nvidia_dev_xid_isra_0(local_58,param_2,param_4);
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


// ===== 001231e0 __pfx_nv_report_error =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00123309) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __pfx_nv_report_error
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  ulong uVar2;
  char *__s;
  size_t sVar3;
  int iVar4;
  long in_GS_OFFSET;
  
  uVar2 = (*_mpi_powm)(param_1,param_3,param_4);
  iVar4 = 0x2820;
  if ((uVar2 & 0x200) != 0) {
    iVar4 = (-(uint)((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0) & 0x44a0) +
            0x2820;
  }
  __s = (char *)kvasprintf(iVar4);
  pcVar1 = nv_error_cb_handle;
  if (__s != (char *)0x0) {
    if (nv_error_cb_handle != (code *)0x0) {
      sVar3 = strlen(__s);
      (*pcVar1)(param_1,param_2,__s,sVar3 + 1);
    }
    kfree(__s);
    return;
  }
  return;
}


// ===== 001231f0 nv_report_error =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00123309) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void nv_report_error(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  ulong uVar2;
  char *__s;
  size_t sVar3;
  int iVar4;
  long in_GS_OFFSET;
  
  uVar2 = (*_mpi_powm)(param_1,param_3,param_4);
  iVar4 = 0x2820;
  if ((uVar2 & 0x200) != 0) {
    iVar4 = (-(uint)((*(uint *)(&__preempt_count + in_GS_OFFSET) & 0x7fffffff) == 0) & 0x44a0) +
            0x2820;
  }
  __s = (char *)kvasprintf(iVar4);
  pcVar1 = nv_error_cb_handle;
  if (__s != (char *)0x0) {
    if (nv_error_cb_handle != (code *)0x0) {
      sVar3 = strlen(__s);
      (*pcVar1)(param_1,param_2,__s,sVar3 + 1);
    }
    kfree(__s);
    return;
  }
  return;
}


// ===== 00123310 __pfx_nv_init_rsync_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012336c) */

void __pfx_nv_init_rsync_info(void)

{
  g_rsync_info._56_8_ = 0;
  g_rsync_info._0_8_ = 0x100000000;
  g_rsync_info._8_8_ = 0;
  g_rsync_info._16_8_ = 0;
  g_rsync_info._24_4_ = 0;
  g_rsync_info[0x1c] = 0;
  return;
}


// ===== 00123320 nv_init_rsync_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012336c) */

void nv_init_rsync_info(void)

{
  g_rsync_info._56_8_ = 0;
  g_rsync_info._0_8_ = 0x100000000;
  g_rsync_info._8_8_ = 0;
  g_rsync_info._16_8_ = 0;
  g_rsync_info._24_4_ = 0;
  g_rsync_info[0x1c] = 0;
  return;
}


// ===== 00123380 __pfx_nv_destroy_rsync_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001233b6) */

void __pfx_nv_destroy_rsync_info(void)

{
  code *pcVar1;
  
  if (g_rsync_info._56_8_ != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  if (g_rsync_info._24_4_ == 0) {
    if (g_rsync_info[0x1c] == '\0') {
      return;
    }
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00123390 nv_destroy_rsync_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001233b6) */

void nv_destroy_rsync_info(void)

{
  code *pcVar1;
  
  if (g_rsync_info._56_8_ != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  if (g_rsync_info._24_4_ == 0) {
    if (g_rsync_info[0x1c] == '\0') {
      return;
    }
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 001233e0 __pfx_nv_get_rsync_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012348e) */

int __pfx_nv_get_rsync_info(void)

{
  int iVar1;
  long in_GS_OFFSET;
  int iStack_1c;
  long lStack_18;
  
  lStack_18 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  iStack_1c = 0;
  down(g_rsync_info);
  if ((g_rsync_info._24_4_ == 0) && (g_rsync_info._32_8_ != 0)) {
    iVar1 = (*(code *)g_rsync_info._32_8_)(&iStack_1c,g_rsync_info._56_8_);
    if (iVar1 != 0) goto LAB_0012346c;
    g_rsync_info[0x1c] = iStack_1c != 0;
  }
  g_rsync_info._24_4_ = g_rsync_info._24_4_ + 1;
  iVar1 = 0;
LAB_0012346c:
  up(g_rsync_info);
  if (lStack_18 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 001233f0 nv_get_rsync_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012348e) */

int nv_get_rsync_info(void)

{
  int iVar1;
  long in_GS_OFFSET;
  int local_1c;
  long local_18;
  
  local_18 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_1c = 0;
  down(g_rsync_info);
  if ((g_rsync_info._24_4_ == 0) && (g_rsync_info._32_8_ != 0)) {
    iVar1 = (*(code *)g_rsync_info._32_8_)(&local_1c,g_rsync_info._56_8_);
    if (iVar1 != 0) goto LAB_0012346c;
    g_rsync_info[0x1c] = local_1c != 0;
  }
  g_rsync_info._24_4_ = g_rsync_info._24_4_ + 1;
  iVar1 = 0;
LAB_0012346c:
  up(g_rsync_info);
  if (local_18 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 001234a0 __pfx_nv_put_rsync_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __pfx_nv_put_rsync_info(void)

{
  down(g_rsync_info);
  g_rsync_info._24_4_ = g_rsync_info._24_4_ + -1;
  if ((g_rsync_info._24_4_ == 0) && (g_rsync_info._40_8_ != 0)) {
    (*(code *)g_rsync_info._40_8_)(g_rsync_info[0x1c],g_rsync_info._56_8_);
    g_rsync_info[0x1c] = 0;
  }
  up(g_rsync_info);
  return;
}


// ===== 001234b0 nv_put_rsync_info =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void nv_put_rsync_info(void)

{
  down(g_rsync_info);
  g_rsync_info._24_4_ = g_rsync_info._24_4_ + -1;
  if ((g_rsync_info._24_4_ == 0) && (g_rsync_info._40_8_ != 0)) {
    (*(code *)g_rsync_info._40_8_)(g_rsync_info[0x1c],g_rsync_info._56_8_);
    g_rsync_info[0x1c] = 0;
  }
  up(g_rsync_info);
  return;
}


// ===== 00123500 __pfx_nv_register_rsync_driver =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012357d) */

undefined8
__pfx_nv_register_rsync_driver
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  
  down(g_rsync_info);
  if ((g_rsync_info._32_8_ == 0) && (g_rsync_info._24_4_ == 0)) {
    uVar1 = 0;
    g_rsync_info._32_8_ = param_1;
    g_rsync_info._40_8_ = param_2;
    g_rsync_info._48_8_ = param_3;
    g_rsync_info._56_8_ = param_4;
  }
  else {
    uVar1 = 0xfffffff0;
  }
  up(g_rsync_info);
  return uVar1;
}


// ===== 00123510 nv_register_rsync_driver =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x0012357d) */

undefined8
nv_register_rsync_driver
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  
  down(g_rsync_info);
  if ((g_rsync_info._32_8_ == 0) && (g_rsync_info._24_4_ == 0)) {
    uVar1 = 0;
    g_rsync_info._32_8_ = param_1;
    g_rsync_info._40_8_ = param_2;
    g_rsync_info._48_8_ = param_3;
    g_rsync_info._56_8_ = param_4;
  }
  else {
    uVar1 = 0xfffffff0;
  }
  up(g_rsync_info);
  return uVar1;
}


// ===== 00123590 __pfx_nv_unregister_rsync_driver =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_unregister_rsync_driver(long param_1,long param_2,long param_3,long param_4)

{
  code *pcVar1;
  
  down(g_rsync_info);
  if (g_rsync_info._24_4_ != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  if (g_rsync_info._32_8_ != param_1) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  if (g_rsync_info._40_8_ != param_2) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  if (g_rsync_info._48_8_ == param_3) {
    if (g_rsync_info._56_8_ == param_4) {
      g_rsync_info._32_8_ = 0;
      g_rsync_info._40_8_ = 0;
      g_rsync_info._48_8_ = 0;
      g_rsync_info._56_8_ = 0;
      up(g_rsync_info);
      return;
    }
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 001235a0 nv_unregister_rsync_driver =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_unregister_rsync_driver(long param_1,long param_2,long param_3,long param_4)

{
  code *pcVar1;
  
  down(g_rsync_info);
  if (g_rsync_info._24_4_ != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  if (g_rsync_info._32_8_ != param_1) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  if (g_rsync_info._40_8_ != param_2) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  if (g_rsync_info._48_8_ == param_3) {
    if (g_rsync_info._56_8_ == param_4) {
      g_rsync_info._32_8_ = 0;
      g_rsync_info._40_8_ = 0;
      g_rsync_info._48_8_ = 0;
      g_rsync_info._56_8_ = 0;
      up(g_rsync_info);
      return;
    }
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00123680 __pfx_nv_init_msi =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001236ce) */
/* WARNING: Removing unreachable block (ram,0x00123747) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __pfx_nv_init_msi(long param_1)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  long lVar5;
  
  lVar2 = *(long *)(param_1 + 8);
  iVar4 = pci_enable_msi(*(undefined8 *)(lVar2 + 0x3b8));
  if (iVar4 == 0) {
    uVar1 = *(undefined4 *)(*(long *)(lVar2 + 0x3b8) + 0x3ec);
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x20;
    uVar3 = ___alloc_pages_noprof;
    *(undefined4 *)(param_1 + 0x17c) = uVar1;
    *(undefined4 *)(lVar2 + 0x7dc) = 1;
    lVar5 = __kmalloc_cache_noprof(uVar3,0x2dc0,0x20);
    *(long *)(lVar2 + 0x5198) = lVar5;
    if (lVar5 != 0) {
      *(undefined2 *)(lVar2 + 0x51a0) = 0;
      return;
    }
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xffffffdf;
    nv_printf(4,
              "NVRM: GPU %04x:%02x:%02x.%x: Failed to allocate counter for MSI entry; falling back to PCIe virtual-wire interrupts.\n"
              ,*(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
              *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a));
    return;
  }
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xffffffdf;
  if (*(int *)(*(long *)(lVar2 + 0x3b8) + 0x3ec) == 0) {
    return;
  }
  nv_printf(4,
            "NVRM: GPU %04x:%02x:%02x.%x: Failed to enable MSI; falling back to PCIe virtual-wire interrupts.\n"
            ,*(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
            *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a));
  return;
}


// ===== 00123690 nv_init_msi =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001236ce) */
/* WARNING: Removing unreachable block (ram,0x00123747) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void nv_init_msi(long param_1)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  long lVar5;
  
  lVar2 = *(long *)(param_1 + 8);
  iVar4 = pci_enable_msi(*(undefined8 *)(lVar2 + 0x3b8));
  if (iVar4 == 0) {
    uVar1 = *(undefined4 *)(*(long *)(lVar2 + 0x3b8) + 0x3ec);
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x20;
    uVar3 = ___alloc_pages_noprof;
    *(undefined4 *)(param_1 + 0x17c) = uVar1;
    *(undefined4 *)(lVar2 + 0x7dc) = 1;
    lVar5 = __kmalloc_cache_noprof(uVar3,0x2dc0,0x20);
    *(long *)(lVar2 + 0x5198) = lVar5;
    if (lVar5 != 0) {
      *(undefined2 *)(lVar2 + 0x51a0) = 0;
      return;
    }
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xffffffdf;
    nv_printf(4,
              "NVRM: GPU %04x:%02x:%02x.%x: Failed to allocate counter for MSI entry; falling back to PCIe virtual-wire interrupts.\n"
              ,*(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
              *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a));
    return;
  }
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xffffffdf;
  if (*(int *)(*(long *)(lVar2 + 0x3b8) + 0x3ec) == 0) {
    return;
  }
  nv_printf(4,
            "NVRM: GPU %04x:%02x:%02x.%x: Failed to enable MSI; falling back to PCIe virtual-wire interrupts.\n"
            ,*(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
            *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a));
  return;
}


// ===== 00123780 __pfx_nv_init_msix =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00123990) */

void __pfx_nv_init_msix(long param_1)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  code *pcVar4;
  byte bVar5;
  int iVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  uint uVar10;
  ulong uVar11;
  long in_GS_OFFSET;
  ushort uStack_2a;
  long lStack_28;
  
  lVar2 = *(long *)(param_1 + 8);
  lStack_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  *(undefined4 *)(lVar2 + 0x7e0) = 0;
  iVar6 = os_alloc_mutex();
  if (iVar6 != 0) goto LAB_001237d9;
  uVar3 = *(undefined8 *)(lVar2 + 0x3b8);
  uStack_2a = 0;
  bVar5 = pci_find_capability(uVar3,0x11);
  pci_read_config_word(uVar3,bVar5 + 2,&uStack_2a);
  uVar10 = (uStack_2a & 0x7ff) + 1;
  if ((ushort)uVar10 < 9) {
    uVar9 = (ulong)uVar10;
    lVar7 = uVar9 * 8;
    uVar11 = (ulong)uVar10;
  }
  else {
    uVar11 = 8;
    nv_printf(0,
              "NVRM: GPU %04x:%02x:%02x.%x: Reducing MSI-X count from %d to the driver-supported maximum %d.\n"
              ,*(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
              *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a),(ulong)uVar10,8);
    lVar7 = 0x40;
    uVar9 = 8;
  }
  lVar7 = __kmalloc_noprof(lVar7,0x2cc0);
  *(long *)(lVar2 + 0x7f0) = lVar7;
  if (lVar7 == 0) {
    nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: Failed to allocate MSI-X entries.\n",
              *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
              *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a),uVar9);
    goto LAB_001237d9;
  }
  uVar8 = 0;
  if ((uVar11 & 1) == 0) {
LAB_00123900:
    do {
      *(short *)(lVar7 + 4 + uVar8 * 8) = (short)uVar8;
      lVar1 = uVar8 + 1;
      uVar8 = uVar8 + 2;
      *(short *)(lVar7 + 4 + lVar1 * 8) = (short)lVar1;
    } while (uVar11 != uVar8);
  }
  else {
    *(undefined2 *)(lVar7 + 4) = 0;
    uVar8 = 1;
    if (uVar11 != 1) goto LAB_00123900;
  }
  lVar7 = __kmalloc_noprof(uVar9 << 5,0x2dc0);
  *(long *)(lVar2 + 0x5198) = lVar7;
  if (lVar7 == 0) {
    nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: Failed to allocate counter for MSI-X entries.\n",
              *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
              *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a));
  }
  else {
    *(undefined2 *)(lVar2 + 0x51a0) = 0;
    iVar6 = pci_enable_msix_range
                      (*(undefined8 *)(lVar2 + 0x3b8),*(undefined8 *)(lVar2 + 0x7f0),uVar11,uVar11);
    if (-1 < iVar6) {
      if ((int)uVar11 != iVar6) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)invalidInstructionException();
        (*pcVar4)();
      }
      *(int *)(lVar2 + 0x7dc) = (int)uVar11;
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x40;
      if (lStack_28 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
  }
LAB_001237d9:
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xffffffbf;
  if (*(long *)(lVar2 + 0x7f0) != 0) {
    kfree();
  }
  if (*(long *)(lVar2 + 0x5198) != 0) {
    kfree();
  }
  if (*(long *)(lVar2 + 0x7e8) != 0) {
    os_free_mutex();
    *(undefined8 *)(lVar2 + 0x7e8) = 0;
  }
  if (lStack_28 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: Failed to enable MSI-X.\n",
            *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
            *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a));
  return;
}


// ===== 00123790 nv_init_msix =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00123990) */

void nv_init_msix(long param_1)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  code *pcVar4;
  byte bVar5;
  int iVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  uint uVar10;
  ulong uVar11;
  long in_GS_OFFSET;
  ushort local_2a;
  long local_28;
  
  lVar2 = *(long *)(param_1 + 8);
  local_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  *(undefined4 *)(lVar2 + 0x7e0) = 0;
  iVar6 = os_alloc_mutex();
  if (iVar6 != 0) goto LAB_001237d9;
  uVar3 = *(undefined8 *)(lVar2 + 0x3b8);
  local_2a = 0;
  bVar5 = pci_find_capability(uVar3,0x11);
  pci_read_config_word(uVar3,bVar5 + 2,&local_2a);
  uVar10 = (local_2a & 0x7ff) + 1;
  if ((ushort)uVar10 < 9) {
    uVar9 = (ulong)uVar10;
    lVar7 = uVar9 * 8;
    uVar11 = (ulong)uVar10;
  }
  else {
    uVar11 = 8;
    nv_printf(0,
              "NVRM: GPU %04x:%02x:%02x.%x: Reducing MSI-X count from %d to the driver-supported maximum %d.\n"
              ,*(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
              *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a),(ulong)uVar10,8);
    lVar7 = 0x40;
    uVar9 = 8;
  }
  lVar7 = __kmalloc_noprof(lVar7,0x2cc0);
  *(long *)(lVar2 + 0x7f0) = lVar7;
  if (lVar7 == 0) {
    nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: Failed to allocate MSI-X entries.\n",
              *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
              *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a),uVar9);
    goto LAB_001237d9;
  }
  uVar8 = 0;
  if ((uVar11 & 1) == 0) {
LAB_00123900:
    do {
      *(short *)(lVar7 + 4 + uVar8 * 8) = (short)uVar8;
      lVar1 = uVar8 + 1;
      uVar8 = uVar8 + 2;
      *(short *)(lVar7 + 4 + lVar1 * 8) = (short)lVar1;
    } while (uVar11 != uVar8);
  }
  else {
    *(undefined2 *)(lVar7 + 4) = 0;
    uVar8 = 1;
    if (uVar11 != 1) goto LAB_00123900;
  }
  lVar7 = __kmalloc_noprof(uVar9 << 5,0x2dc0);
  *(long *)(lVar2 + 0x5198) = lVar7;
  if (lVar7 == 0) {
    nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: Failed to allocate counter for MSI-X entries.\n",
              *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
              *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a));
  }
  else {
    *(undefined2 *)(lVar2 + 0x51a0) = 0;
    iVar6 = pci_enable_msix_range
                      (*(undefined8 *)(lVar2 + 0x3b8),*(undefined8 *)(lVar2 + 0x7f0),uVar11,uVar11);
    if (-1 < iVar6) {
      if ((int)uVar11 != iVar6) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)invalidInstructionException();
        (*pcVar4)();
      }
      *(int *)(lVar2 + 0x7dc) = (int)uVar11;
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x40;
      if (local_28 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
  }
LAB_001237d9:
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xffffffbf;
  if (*(long *)(lVar2 + 0x7f0) != 0) {
    kfree();
  }
  if (*(long *)(lVar2 + 0x5198) != 0) {
    kfree();
  }
  if (*(long *)(lVar2 + 0x7e8) != 0) {
    os_free_mutex();
    *(undefined8 *)(lVar2 + 0x7e8) = 0;
  }
  if (local_28 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  nv_printf(4,"NVRM: GPU %04x:%02x:%02x.%x: Failed to enable MSI-X.\n",
            *(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),
            *(undefined1 *)(param_1 + 0x19),*(undefined1 *)(param_1 + 0x1a));
  return;
}


// ===== 00123a50 __pfx_nv_request_msix_irq =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00123b21) */

int __pfx_nv_request_msix_irq(long param_1)

{
  undefined4 *puVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  
  if (*(int *)(param_1 + 0x7dc) == 0) {
    iVar2 = 0x1f;
  }
  else {
    uVar3 = 0;
    lVar4 = *(long *)(param_1 + 0x7f0);
    do {
      iVar2 = request_threaded_irq
                        (*(undefined4 *)(lVar4 + uVar3 * 8),nvidia_isr_msix,
                         nvidia_isr_msix_kthread_bh,
                         (ulong)((*(byte *)(param_1 + 0x10) & 0x60) == 0) << 7,nv_device_name,
                         param_1);
      if (iVar2 != 0) {
        if ((int)uVar3 < 1) {
          return iVar2;
        }
        lVar4 = 0;
        do {
          puVar1 = (undefined4 *)(*(long *)(param_1 + 0x7f0) + lVar4);
          lVar4 = lVar4 + 8;
          free_irq(*puVar1,param_1);
        } while ((uVar3 & 0xffffffff) << 3 != lVar4);
        return iVar2;
      }
      uVar3 = uVar3 + 1;
      iVar2 = 0;
    } while ((uint)uVar3 < *(uint *)(param_1 + 0x7dc));
  }
  return iVar2;
}


// ===== 00123a60 nv_request_msix_irq =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00123b21) */

int nv_request_msix_irq(long param_1)

{
  undefined4 *puVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  
  if (*(int *)(param_1 + 0x7dc) == 0) {
    iVar2 = 0x1f;
  }
  else {
    uVar3 = 0;
    lVar4 = *(long *)(param_1 + 0x7f0);
    do {
      iVar2 = request_threaded_irq
                        (*(undefined4 *)(lVar4 + uVar3 * 8),nvidia_isr_msix,
                         nvidia_isr_msix_kthread_bh,
                         (ulong)((*(byte *)(param_1 + 0x10) & 0x60) == 0) << 7,nv_device_name,
                         param_1);
      if (iVar2 != 0) {
        if ((int)uVar3 < 1) {
          return iVar2;
        }
        lVar4 = 0;
        do {
          puVar1 = (undefined4 *)(*(long *)(param_1 + 0x7f0) + lVar4);
          lVar4 = lVar4 + 8;
          free_irq(*puVar1,param_1);
        } while ((uVar3 & 0xffffffff) << 3 != lVar4);
        return iVar2;
      }
      uVar3 = uVar3 + 1;
      iVar2 = 0;
    } while ((uint)uVar3 < *(uint *)(param_1 + 0x7dc));
  }
  return iVar2;
}


// ===== 00123b40 __pfx_nv_cap_drv_open =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00123b5b) */

undefined8 __pfx_nv_cap_drv_open(void)

{
  return 0;
}


// ===== 00123b50 nv_cap_drv_open =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00123b5b) */

undefined8 nv_cap_drv_open(void)

{
  return 0;
}


// ===== 00123b60 __pfx_nv_procfs_release_nvlink_minors =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_release_nvlink_minors(void)

{
  single_release();
  return;
}


// ===== 00123b70 nv_procfs_release_nvlink_minors =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_release_nvlink_minors(void)

{
  single_release();
  return;
}


// ===== 00123b80 __pfx_nv_cap_procfs_release =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00123c2b) */

undefined8 __pfx_nv_cap_procfs_release(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long in_GS_OFFSET;
  undefined4 uStack_2c;
  long lStack_28;
  
  lStack_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uStack_2c = 0;
  if (*(long *)(param_2 + 0x18) == 0) {
    single_release(param_1,param_2);
  }
  else {
    lVar1 = *(long *)(*(long *)(param_2 + 0x18) + 0x68);
    lVar2 = *(long *)(param_1 + 0x230);
    single_release(param_1,param_2);
    if (lVar1 != 0) {
      if ((*(long *)(lVar1 + 0x90) != 0) &&
         (iVar3 = sscanf((char *)(lVar1 + 0xc),"DeviceFileModify: %d",&uStack_2c), iVar3 == 1)) {
        *(undefined4 *)(lVar2 + 0x18) = uStack_2c;
      }
      kfree(lVar1);
    }
  }
  *(undefined8 *)(param_2 + 0x18) = 0;
  if (lStack_28 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}


// ===== 00123b90 nv_cap_procfs_release =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00123c2b) */

undefined8 nv_cap_procfs_release(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long in_GS_OFFSET;
  undefined4 local_2c;
  long local_28;
  
  local_28 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  local_2c = 0;
  if (*(long *)(param_2 + 0x18) == 0) {
    single_release(param_1,param_2);
  }
  else {
    lVar1 = *(long *)(*(long *)(param_2 + 0x18) + 0x68);
    lVar2 = *(long *)(param_1 + 0x230);
    single_release(param_1,param_2);
    if (lVar1 != 0) {
      if ((*(long *)(lVar1 + 0x90) != 0) &&
         (iVar3 = sscanf((char *)(lVar1 + 0xc),"DeviceFileModify: %d",&local_2c), iVar3 == 1)) {
        *(undefined4 *)(lVar2 + 0x18) = local_2c;
      }
      kfree(lVar1);
    }
  }
  *(undefined8 *)(param_2 + 0x18) = 0;
  if (local_28 != *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}


// ===== 00123c80 __pfx_nv_procfs_open_sys_minors =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_open_sys_minors(long param_1,undefined8 param_2)

{
  single_open(param_2,nv_procfs_read_sys_minors,*(undefined8 *)(param_1 + 0x230));
  return;
}


// ===== 00123c90 nv_procfs_open_sys_minors =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_open_sys_minors(long param_1,undefined8 param_2)

{
  single_open(param_2,nv_procfs_read_sys_minors,*(undefined8 *)(param_1 + 0x230));
  return;
}


// ===== 00123cc0 __pfx_nv_procfs_open_nvlink_minors =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_open_nvlink_minors(long param_1,undefined8 param_2)

{
  single_open(param_2,nv_procfs_read_nvlink_minors,*(undefined8 *)(param_1 + 0x230));
  return;
}


// ===== 00123cd0 nv_procfs_open_nvlink_minors =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_open_nvlink_minors(long param_1,undefined8 param_2)

{
  single_open(param_2,nv_procfs_read_nvlink_minors,*(undefined8 *)(param_1 + 0x230));
  return;
}


// ===== 00123d00 __pfx_nv_procfs_open_mig_minors =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_open_mig_minors(long param_1,undefined8 param_2)

{
  single_open(param_2,nv_procfs_read_mig_minors,*(undefined8 *)(param_1 + 0x230));
  return;
}


// ===== 00123d10 nv_procfs_open_mig_minors =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_open_mig_minors(long param_1,undefined8 param_2)

{
  single_open(param_2,nv_procfs_read_mig_minors,*(undefined8 *)(param_1 + 0x230));
  return;
}


// ===== 00123d40 __pfx_nv_procfs_read_sys_minors =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00123de1) */

undefined8 __pfx_nv_procfs_read_sys_minors(undefined8 param_1)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  long in_GS_OFFSET;
  undefined8 auStack_90 [15];
  undefined1 uStack_11;
  long lStack_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x123d59;
  lStack_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uVar1 = 0;
  do {
    uVar3 = (ulong)uVar1;
    uVar1 = uVar1 + 0x20;
    *(undefined8 *)((long)auStack_90 + uVar3) = 0;
    *(undefined8 *)((long)auStack_90 + uVar3 + 8) = 0;
    *(undefined8 *)((long)auStack_90 + uVar3 + 0x10) = 0;
    *(undefined8 *)((long)auStack_90 + uVar3 + 0x18) = 0;
  } while (uVar1 < 0x80);
  iVar2 = sscanf(g_nv_cap_sys_table,"/driver/nvidia/capabilities/%s",auStack_90);
  if (iVar2 == 1) {
    uStack_11 = 0;
    seq_printf(param_1,"%s %d\n",auStack_90,DAT_00592628);
  }
  if (lStack_10 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00123d50 nv_procfs_read_sys_minors =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00123de1) */

undefined8 nv_procfs_read_sys_minors(undefined8 param_1)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  long in_GS_OFFSET;
  undefined8 local_90 [15];
  undefined1 local_11;
  long local_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x123d59;
  local_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uVar1 = 0;
  do {
    uVar3 = (ulong)uVar1;
    uVar1 = uVar1 + 0x20;
    *(undefined8 *)((long)local_90 + uVar3) = 0;
    *(undefined8 *)((long)local_90 + uVar3 + 8) = 0;
    *(undefined8 *)((long)local_90 + uVar3 + 0x10) = 0;
    *(undefined8 *)((long)local_90 + uVar3 + 0x18) = 0;
  } while (uVar1 < 0x80);
  iVar2 = sscanf(g_nv_cap_sys_table,"/driver/nvidia/capabilities/%s",local_90);
  if (iVar2 == 1) {
    local_11 = 0;
    seq_printf(param_1,"%s %d\n",local_90,DAT_00592628);
  }
  if (local_10 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00123e10 __pfx_nv_procfs_read_nvlink_minors =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00123eb1) */

undefined8 __pfx_nv_procfs_read_nvlink_minors(undefined8 param_1)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  long in_GS_OFFSET;
  undefined8 auStack_90 [15];
  undefined1 uStack_11;
  long lStack_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x123e29;
  lStack_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uVar1 = 0;
  do {
    uVar3 = (ulong)uVar1;
    uVar1 = uVar1 + 0x20;
    *(undefined8 *)((long)auStack_90 + uVar3) = 0;
    *(undefined8 *)((long)auStack_90 + uVar3 + 8) = 0;
    *(undefined8 *)((long)auStack_90 + uVar3 + 0x10) = 0;
    *(undefined8 *)((long)auStack_90 + uVar3 + 0x18) = 0;
  } while (uVar1 < 0x80);
  iVar2 = sscanf(g_nv_cap_nvlink_table,"/driver/nvidia-nvlink/capabilities/%s",auStack_90);
  if (iVar2 == 1) {
    uStack_11 = 0;
    seq_printf(param_1,"%s %d\n",auStack_90,DAT_00592688);
  }
  if (lStack_10 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00123e20 nv_procfs_read_nvlink_minors =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00123eb1) */

undefined8 nv_procfs_read_nvlink_minors(undefined8 param_1)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  long in_GS_OFFSET;
  undefined8 local_90 [15];
  undefined1 local_11;
  long local_10;
  undefined8 uStack_8;
  
  uStack_8 = 0x123e29;
  local_10 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uVar1 = 0;
  do {
    uVar3 = (ulong)uVar1;
    uVar1 = uVar1 + 0x20;
    *(undefined8 *)((long)local_90 + uVar3) = 0;
    *(undefined8 *)((long)local_90 + uVar3 + 8) = 0;
    *(undefined8 *)((long)local_90 + uVar3 + 0x10) = 0;
    *(undefined8 *)((long)local_90 + uVar3 + 0x18) = 0;
  } while (uVar1 < 0x80);
  iVar2 = sscanf(g_nv_cap_nvlink_table,"/driver/nvidia-nvlink/capabilities/%s",local_90);
  if (iVar2 == 1) {
    local_11 = 0;
    seq_printf(param_1,"%s %d\n",local_90,DAT_00592688);
  }
  if (local_10 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00123ee0 __pfx_nv_procfs_read_mig_minors =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00124002) */

undefined8 __pfx_nv_procfs_read_mig_minors(undefined8 param_1)

{
  undefined **ppuVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  undefined **ppuVar5;
  long in_GS_OFFSET;
  undefined4 uStack_a4;
  undefined8 auStack_a0 [15];
  undefined1 uStack_21;
  long lStack_20;
  
  lStack_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uVar2 = 0;
  uStack_a4 = 0;
  do {
    uVar4 = (ulong)uVar2;
    uVar2 = uVar2 + 0x20;
    *(undefined8 *)((long)auStack_a0 + uVar4) = 0;
    *(undefined8 *)((long)auStack_a0 + uVar4 + 8) = 0;
    *(undefined8 *)((long)auStack_a0 + uVar4 + 0x10) = 0;
    *(undefined8 *)((long)auStack_a0 + uVar4 + 0x18) = 0;
  } while (uVar2 < 0x80);
  ppuVar5 = &g_nv_cap_mig_table;
  do {
    iVar3 = sscanf(*ppuVar5,"/driver/nvidia/capabilities/mig/%s",auStack_a0);
    if (iVar3 == 1) {
      uStack_21 = 0;
      seq_printf(param_1,"%s %d\n",auStack_a0,*(undefined4 *)(ppuVar5 + 1));
    }
    ppuVar5 = ppuVar5 + 4;
  } while (ppuVar5 != &g_nv_cap_nvlink_table);
  ppuVar5 = &g_nv_cap_mig_gpu_table;
  do {
    while( true ) {
      iVar3 = sscanf(*ppuVar5,"/driver/nvidia/capabilities/gpu%d/mig/%s",&uStack_a4,auStack_a0);
      if (iVar3 != 2) break;
      ppuVar1 = ppuVar5 + 1;
      ppuVar5 = ppuVar5 + 4;
      uStack_21 = 0;
      seq_printf(param_1,"gpu%d/%s %d\n",uStack_a4,auStack_a0,*(undefined4 *)ppuVar1);
      if (ppuVar5 == &g_nv_cap_sys_table) goto LAB_00123fe5;
    }
    ppuVar5 = ppuVar5 + 4;
  } while (ppuVar5 != &g_nv_cap_sys_table);
LAB_00123fe5:
  if (lStack_20 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00123ef0 nv_procfs_read_mig_minors =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00124002) */

undefined8 nv_procfs_read_mig_minors(undefined8 param_1)

{
  undefined **ppuVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  undefined **ppuVar5;
  long in_GS_OFFSET;
  undefined4 local_a4;
  undefined8 local_a0 [15];
  undefined1 local_21;
  long local_20;
  
  local_20 = *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET);
  uVar2 = 0;
  local_a4 = 0;
  do {
    uVar4 = (ulong)uVar2;
    uVar2 = uVar2 + 0x20;
    *(undefined8 *)((long)local_a0 + uVar4) = 0;
    *(undefined8 *)((long)local_a0 + uVar4 + 8) = 0;
    *(undefined8 *)((long)local_a0 + uVar4 + 0x10) = 0;
    *(undefined8 *)((long)local_a0 + uVar4 + 0x18) = 0;
  } while (uVar2 < 0x80);
  ppuVar5 = &g_nv_cap_mig_table;
  do {
    iVar3 = sscanf(*ppuVar5,"/driver/nvidia/capabilities/mig/%s",local_a0);
    if (iVar3 == 1) {
      local_21 = 0;
      seq_printf(param_1,"%s %d\n",local_a0,*(undefined4 *)(ppuVar5 + 1));
    }
    ppuVar5 = ppuVar5 + 4;
  } while (ppuVar5 != &g_nv_cap_nvlink_table);
  ppuVar5 = &g_nv_cap_mig_gpu_table;
  do {
    while( true ) {
      iVar3 = sscanf(*ppuVar5,"/driver/nvidia/capabilities/gpu%d/mig/%s",&local_a4,local_a0);
      if (iVar3 != 2) break;
      ppuVar1 = ppuVar5 + 1;
      ppuVar5 = ppuVar5 + 4;
      local_21 = 0;
      seq_printf(param_1,"gpu%d/%s %d\n",local_a4,local_a0,*(undefined4 *)ppuVar1);
      if (ppuVar5 == &g_nv_cap_sys_table) goto LAB_00123fe5;
    }
    ppuVar5 = ppuVar5 + 4;
  } while (ppuVar5 != &g_nv_cap_sys_table);
LAB_00123fe5:
  if (local_20 == *(long *)(&__ref_stack_chk_guard + in_GS_OFFSET)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ===== 00124030 __pfx_nv_cap_procfs_open =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001240c9) */
/* WARNING: Removing unreachable block (ram,0x001240f1) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __pfx_nv_cap_procfs_open(long param_1,undefined8 param_2)

{
  undefined4 uVar1;
  long lVar2;
  undefined4 *puVar3;
  ulong uVar4;
  
  lVar2 = *(long *)(param_1 + 0x230);
  puVar3 = (undefined4 *)__kmalloc_cache_noprof(_strcasecmp,0x2cc0,0x98);
  if (puVar3 == (undefined4 *)0x0) {
    uVar4 = 0xfffffff4;
  }
  else {
    *puVar3 = *(undefined4 *)(lVar2 + 0x10);
    uVar1 = *(undefined4 *)(lVar2 + 0x14);
    *(undefined8 *)(puVar3 + 0x24) = 0;
    puVar3[1] = uVar1;
    puVar3[2] = *(undefined4 *)(lVar2 + 0x18);
    uVar4 = single_open(param_2,nv_cap_procfs_read,puVar3);
    if ((int)uVar4 < 0) {
      kfree(puVar3);
      return uVar4 & 0xffffffff;
    }
  }
  return uVar4;
}


// ===== 00124040 nv_cap_procfs_open =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001240c9) */
/* WARNING: Removing unreachable block (ram,0x001240f1) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong nv_cap_procfs_open(long param_1,undefined8 param_2)

{
  undefined4 uVar1;
  long lVar2;
  undefined4 *puVar3;
  ulong uVar4;
  
  lVar2 = *(long *)(param_1 + 0x230);
  puVar3 = (undefined4 *)__kmalloc_cache_noprof(_strcasecmp,0x2cc0,0x98);
  if (puVar3 == (undefined4 *)0x0) {
    uVar4 = 0xfffffff4;
  }
  else {
    *puVar3 = *(undefined4 *)(lVar2 + 0x10);
    uVar1 = *(undefined4 *)(lVar2 + 0x14);
    *(undefined8 *)(puVar3 + 0x24) = 0;
    puVar3[1] = uVar1;
    puVar3[2] = *(undefined4 *)(lVar2 + 0x18);
    uVar4 = single_open(param_2,nv_cap_procfs_read,puVar3);
    if ((int)uVar4 < 0) {
      kfree(puVar3);
      return uVar4 & 0xffffffff;
    }
  }
  return uVar4;
}


// ===== 00124100 __pfx_nv_cap_alloc =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00124282) */
/* WARNING: Removing unreachable block (ram,0x00124294) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * __pfx_nv_cap_alloc(undefined8 *param_1,char *param_2)

{
  char *__s;
  undefined4 uVar1;
  undefined8 *puVar2;
  size_t sVar3;
  size_t sVar4;
  char *__string;
  long lVar5;
  void *__dest;
  ulong uVar6;
  
  if ((param_1 == (undefined8 *)0x0) || (param_2 == (char *)0x0)) {
    return (undefined8 *)0x0;
  }
  puVar2 = (undefined8 *)__kmalloc_cache_noprof(_capable,0x2cc0,0x30);
  if (puVar2 != (undefined8 *)0x0) {
    sVar3 = strlen(param_2);
    sVar4 = strlen((char *)*param_1);
    uVar6 = (ulong)((int)sVar3 + 2 + (int)sVar4);
    __string = (char *)__kmalloc_noprof(uVar6,0x2cc0);
    *puVar2 = __string;
    if (__string != (char *)0x0) {
      __s = (char *)*param_1;
      sVar3 = strlen(__s);
      if (uVar6 < sVar3 + 1) {
                    /* WARNING: Subroutine does not return */
        __fortify_panic(0x1f,uVar6);
      }
      memcpy(__string,__s,sVar3 + 1);
      sVar3 = strnlen(__string,0xffffffffffffffff);
      if (sVar3 != 0xffffffffffffffff) {
        if (sVar3 == 0xfffffffffffffffe) {
          __string[-2] = '\0';
                    /* WARNING: Subroutine does not return */
          __fortify_panic(0xb,0xffffffffffffffff,0);
        }
        __string[sVar3] = '/';
        __string[sVar3 + 1] = '\0';
      }
      lVar5 = strlcat(*puVar2,param_2,0xffffffffffffffff);
      if (lVar5 == -1) {
                    /* WARNING: Subroutine does not return */
        __fortify_panic(0xb,0xffffffffffffffff,0);
      }
      sVar3 = strlen(param_2);
      uVar6 = (ulong)((int)sVar3 + 1);
      __dest = (void *)__kmalloc_noprof(uVar6,0x2cc0);
      puVar2[1] = __dest;
      if (__dest != (void *)0x0) {
        sVar3 = strlen(param_2);
        if (sVar3 + 1 <= uVar6) {
          memcpy(__dest,param_2,sVar3 + 1);
          uVar1 = NVreg_ModifyDeviceFiles;
          *(undefined4 *)(puVar2 + 2) = 0xffffffff;
          *(undefined4 *)(puVar2 + 3) = uVar1;
          return puVar2;
        }
                    /* WARNING: Subroutine does not return */
        __fortify_panic(0x1f,uVar6);
      }
      kfree(*puVar2);
    }
    kfree(puVar2);
  }
  return (undefined8 *)0x0;
}


// ===== 00124110 nv_cap_alloc =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00124282) */
/* WARNING: Removing unreachable block (ram,0x00124294) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * nv_cap_alloc(undefined8 *param_1,char *param_2)

{
  char *__s;
  undefined4 uVar1;
  undefined8 *puVar2;
  size_t sVar3;
  size_t sVar4;
  char *__string;
  long lVar5;
  void *__dest;
  ulong uVar6;
  
  if ((param_1 == (undefined8 *)0x0) || (param_2 == (char *)0x0)) {
    return (undefined8 *)0x0;
  }
  puVar2 = (undefined8 *)__kmalloc_cache_noprof(_capable,0x2cc0,0x30);
  if (puVar2 != (undefined8 *)0x0) {
    sVar3 = strlen(param_2);
    sVar4 = strlen((char *)*param_1);
    uVar6 = (ulong)((int)sVar3 + 2 + (int)sVar4);
    __string = (char *)__kmalloc_noprof(uVar6,0x2cc0);
    *puVar2 = __string;
    if (__string != (char *)0x0) {
      __s = (char *)*param_1;
      sVar3 = strlen(__s);
      if (uVar6 < sVar3 + 1) {
                    /* WARNING: Subroutine does not return */
        __fortify_panic(0x1f,uVar6);
      }
      memcpy(__string,__s,sVar3 + 1);
      sVar3 = strnlen(__string,0xffffffffffffffff);
      if (sVar3 != 0xffffffffffffffff) {
        if (sVar3 == 0xfffffffffffffffe) {
          __string[-2] = '\0';
                    /* WARNING: Subroutine does not return */
          __fortify_panic(0xb,0xffffffffffffffff,0);
        }
        __string[sVar3] = '/';
        __string[sVar3 + 1] = '\0';
      }
      lVar5 = strlcat(*puVar2,param_2,0xffffffffffffffff);
      if (lVar5 == -1) {
                    /* WARNING: Subroutine does not return */
        __fortify_panic(0xb,0xffffffffffffffff,0);
      }
      sVar3 = strlen(param_2);
      uVar6 = (ulong)((int)sVar3 + 1);
      __dest = (void *)__kmalloc_noprof(uVar6,0x2cc0);
      puVar2[1] = __dest;
      if (__dest != (void *)0x0) {
        sVar3 = strlen(param_2);
        if (sVar3 + 1 <= uVar6) {
          memcpy(__dest,param_2,sVar3 + 1);
          uVar1 = NVreg_ModifyDeviceFiles;
          *(undefined4 *)(puVar2 + 2) = 0xffffffff;
          *(undefined4 *)(puVar2 + 3) = uVar1;
          return puVar2;
        }
                    /* WARNING: Subroutine does not return */
        __fortify_panic(0x1f,uVar6);
      }
      kfree(*puVar2);
    }
    kfree(puVar2);
  }
  return (undefined8 *)0x0;
}


// ===== 001242d0 __pfx__nv_cap_table_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00124384) */

void __pfx__nv_cap_table_init(undefined8 *param_1,int param_2)

{
  char *__s;
  long lVar1;
  code *pcVar2;
  uint uVar3;
  size_t sVar4;
  int iVar5;
  int iVar6;
  
  param_2 = minor_1 + param_2;
  iVar5 = minor_1;
  do {
    __s = (char *)*param_1;
    iVar6 = iVar5 + 1;
    param_1[2] = 0;
    *(int *)(param_1 + 1) = iVar5;
    param_1[3] = 0;
    minor_1 = iVar6;
    sVar4 = strlen(__s);
    uVar3 = full_name_hash(0,__s,sVar4 & 0xffffffff);
    uVar3 = (uVar3 & 0x1ff) * 0x61c88647 >> 0x17;
    lVar1 = (&g_nv_cap_hash_table)[uVar3];
    param_1[2] = lVar1;
    if (lVar1 != 0) {
      *(undefined8 **)(lVar1 + 8) = param_1 + 2;
    }
    (&g_nv_cap_hash_table)[uVar3] = param_1 + 2;
    param_1[3] = &g_nv_cap_hash_table + uVar3;
    param_1 = param_1 + 4;
    iVar5 = iVar6;
  } while (iVar6 != param_2);
  if (iVar6 < 0x2001) {
    return;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)invalidInstructionException();
  (*pcVar2)();
}


// ===== 001242e0 _nv_cap_table_init =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x00124384) */

void _nv_cap_table_init(undefined8 *param_1,int param_2)

{
  char *__s;
  long lVar1;
  code *pcVar2;
  uint uVar3;
  size_t sVar4;
  int iVar5;
  int iVar6;
  
  param_2 = minor_1 + param_2;
  iVar5 = minor_1;
  do {
    __s = (char *)*param_1;
    iVar6 = iVar5 + 1;
    param_1[2] = 0;
    *(int *)(param_1 + 1) = iVar5;
    param_1[3] = 0;
    minor_1 = iVar6;
    sVar4 = strlen(__s);
    uVar3 = full_name_hash(0,__s,sVar4 & 0xffffffff);
    uVar3 = (uVar3 & 0x1ff) * 0x61c88647 >> 0x17;
    lVar1 = (&g_nv_cap_hash_table)[uVar3];
    param_1[2] = lVar1;
    if (lVar1 != 0) {
      *(undefined8 **)(lVar1 + 8) = param_1 + 2;
    }
    (&g_nv_cap_hash_table)[uVar3] = param_1 + 2;
    param_1[3] = &g_nv_cap_hash_table + uVar3;
    param_1 = param_1 + 4;
    iVar5 = iVar6;
  } while (iVar6 != param_2);
  if (iVar6 < 0x2001) {
    return;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)invalidInstructionException();
  (*pcVar2)();
}


// ===== 001243a0 __pfx_nv_cap_drv_release =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001243bb) */

undefined8 __pfx_nv_cap_drv_release(void)

{
  return 0;
}


// ===== 001243b0 nv_cap_drv_release =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */
/* WARNING: Function: __x86_return_thunk replaced with injection: x86_return_thunk */
/* WARNING: Removing unreachable block (ram,0x001243bb) */

undefined8 nv_cap_drv_release(void)

{
  return 0;
}


// ===== 001243c0 __pfx_nv_procfs_release_mig_minors =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void __pfx_nv_procfs_release_mig_minors(void)

{
  single_release();
  return;
}


// ===== 001243d0 nv_procfs_release_mig_minors =====

/* WARNING: Function: __fentry__ replaced with injection: fentry */

void nv_procfs_release_mig_minors(void)

{
  single_release();
  return;
}


