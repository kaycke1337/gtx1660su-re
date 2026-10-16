// ===== 00291810 FUN_00291810 =====

void FUN_00291810(void)

{
  sysconf(0x1e);
  return;
}


// ===== 00291820 FUN_00291820 =====

int FUN_00291820(int *param_1,int param_2,int param_3)

{
  int iVar1;
  
  LOCK();
  iVar1 = *param_1;
  if (param_3 == iVar1) {
    *param_1 = param_2;
    iVar1 = param_3;
  }
  UNLOCK();
  return iVar1;
}


// ===== 00291830 FUN_00291830 =====

undefined4 FUN_00291830(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  LOCK();
  uVar1 = *param_1;
  *param_1 = param_2;
  UNLOCK();
  return uVar1;
}


// ===== 00291840 FUN_00291840 =====

int FUN_00291840(int *param_1)

{
  int iVar1;
  
  LOCK();
  iVar1 = *param_1;
  *param_1 = *param_1 + 1;
  UNLOCK();
  return iVar1 + 1;
}


// ===== 00291850 FUN_00291850 =====

int FUN_00291850(int *param_1)

{
  int iVar1;
  
  LOCK();
  iVar1 = *param_1;
  *param_1 = *param_1 + -1;
  UNLOCK();
  return iVar1 + -1;
}


// ===== 00291860 FUN_00291860 =====

undefined8 FUN_00291860(ulong param_1,ulong param_2)

{
  if ((param_2 != 0) && (!CARRY8(param_1,param_2))) {
    FUN_00292a40(param_1,param_1 + param_2);
    return 0;
  }
  return 0xffffffff;
}


// ===== 002918a0 FUN_002918a0 =====

void FUN_002918a0(void)

{
  sysconf(0x54);
  return;
}


// ===== 002918b0 FUN_002918b0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_002918b0(void)

{
  code *pcVar1;
  ulong uVar2;
  uint uVar3;
  int iVar4;
  void *__ptr;
  pthread_t pVar5;
  FILE *pFVar6;
  long lVar7;
  __ssize_t _Var8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong local_70;
  char *local_68;
  size_t local_60;
  undefined1 local_58 [8];
  ulong local_50;
  timespec local_48;
  
  FUN_00292c40();
  if (DAT_01218480 == '\0') {
    DAT_01218498 = 0;
    dlerror();
    DAT_01218490 = dlopen(0,1);
    if (DAT_01218490 != 0) {
      DAT_01218498 = dlvsym(DAT_01218490,"accept4","GLIBC_2.10");
      lVar7 = dlerror();
      if ((lVar7 != 0) && (DAT_01218490 != 0)) {
        dlclose();
        DAT_01218490 = 0;
        DAT_01218498 = 0;
      }
    }
    DAT_01218480 = '\x01';
    __cxa_atexit(FUN_002916a0,&DAT_01218490,&PTR_LOOP_0032f660);
  }
  if (DAT_01218460 == '\0') {
    DAT_01218478 = 0;
    dlerror();
    DAT_01218470 = dlopen(0,1);
    if (DAT_01218470 != 0) {
      DAT_01218478 = dlvsym(DAT_01218470,"pipe2","GLIBC_2.9");
      lVar7 = dlerror();
      if ((lVar7 != 0) && (DAT_01218470 != 0)) {
        dlclose();
        DAT_01218470 = 0;
        DAT_01218478 = 0;
      }
    }
    DAT_01218460 = '\x01';
    __cxa_atexit(FUN_002916c0,&DAT_01218470,&PTR_LOOP_0032f660);
  }
  if (DAT_01218440 == '\0') {
    DAT_01218458 = 0;
    dlerror();
    DAT_01218450 = dlopen(0,1);
    if (DAT_01218450 != 0) {
      DAT_01218458 = dlvsym(DAT_01218450,"eventfd","GLIBC_2.7");
      lVar7 = dlerror();
      if ((lVar7 != 0) && (DAT_01218450 != 0)) {
        dlclose();
        DAT_01218450 = 0;
        DAT_01218458 = 0;
      }
    }
    DAT_01218440 = '\x01';
    __cxa_atexit(FUN_002916e0,&DAT_01218450,&PTR_LOOP_0032f660);
  }
  if (DAT_01218420 == '\0') {
    DAT_01218438 = 0;
    dlerror();
    DAT_01218430 = dlopen(0,1);
    if (DAT_01218430 != 0) {
      DAT_01218438 = dlvsym(DAT_01218430,"sched_getcpu","GLIBC_2.6");
      lVar7 = dlerror();
      if ((lVar7 != 0) && (DAT_01218430 != 0)) {
        dlclose();
        DAT_01218430 = 0;
        DAT_01218438 = 0;
      }
    }
    DAT_01218420 = '\x01';
    __cxa_atexit(FUN_00291700,&DAT_01218430,&PTR_LOOP_0032f660);
  }
  if (DAT_01218400 == '\0') {
    _DAT_01218418 = 0;
    dlerror();
    DAT_01218410 = dlopen(0,1);
    if (DAT_01218410 != 0) {
      _DAT_01218418 = dlvsym(DAT_01218410,"bind","GLIBC_2.2.5");
      lVar7 = dlerror();
      if ((lVar7 != 0) && (DAT_01218410 != 0)) {
        dlclose();
        DAT_01218410 = 0;
        _DAT_01218418 = 0;
      }
    }
    DAT_01218400 = '\x01';
    __cxa_atexit(FUN_00291720,&DAT_01218410,&PTR_LOOP_0032f660);
  }
  if (DAT_012183e0 == '\0') {
    DAT_012183f8 = 0;
    dlerror();
    DAT_012183f0 = dlopen(0,1);
    if (DAT_012183f0 != 0) {
      DAT_012183f8 = dlvsym(DAT_012183f0,"pthread_setaffinity_np","GLIBC_2.3.4");
      lVar7 = dlerror();
      if ((lVar7 != 0) && (DAT_012183f0 != 0)) {
        dlclose();
        DAT_012183f0 = 0;
        DAT_012183f8 = 0;
      }
    }
    DAT_012183e0 = '\x01';
    __cxa_atexit(FUN_00291740,&DAT_012183f0,&PTR_LOOP_0032f660);
  }
  if (DAT_012183c8 == '\0') {
    DAT_012183d8 = (code *)0x0;
    dlerror();
    DAT_012183d0 = dlopen(0,1);
    if (DAT_012183d0 != 0) {
      DAT_012183d8 = (code *)dlvsym(DAT_012183d0,"pthread_getaffinity_np","GLIBC_2.3.4");
      lVar7 = dlerror();
      if ((lVar7 != 0) && (DAT_012183d0 != 0)) {
        dlclose();
        DAT_012183d0 = 0;
        DAT_012183d8 = (code *)0x0;
      }
    }
    DAT_012183c8 = '\x01';
    __cxa_atexit(FUN_00291680,&DAT_012183d0,&PTR_LOOP_0032f660);
  }
  _DAT_01218500 = DAT_01218498;
  _DAT_012184f8 = DAT_01218478;
  _DAT_012184f0 = DAT_01218458;
  DAT_012184e0 = DAT_012183d8;
  _DAT_012184e8 = DAT_012183f8;
  _DAT_012184d8 = DAT_01218438;
  _DAT_012184d0 = PTR_socket_0032efe8;
  _DAT_012184c8 = PTR_listen_0032ef98;
  _DAT_012184c0 = PTR_socketpair_0032ef78;
  _DAT_012184b8 = PTR_recvmsg_0032efa0;
  _DAT_012184b0 = PTR_sendmsg_0032ef50;
  _DAT_012184a8 = PTR_connect_0032efc8;
  _DAT_012184a0 = PTR_bind_0032efa8;
  uVar3 = FUN_002918a0();
  iVar4 = FUN_002918a0();
  pcVar1 = DAT_012184e0;
  uVar10 = ((ulong)uVar3 + 0x3f) - (ulong)(iVar4 + 0x3fU & 0x3f) >> 3;
  local_70 = uVar10;
  if ((DAT_012184e0 != (code *)0x0) && (__ptr = malloc(0x20000), __ptr != (void *)0x0)) {
    pVar5 = pthread_self();
    iVar4 = (*pcVar1)(pVar5,uVar10,__ptr);
    if (iVar4 == 0) {
LAB_00291c60:
      free(__ptr);
      local_70 = uVar10;
    }
    else {
      uVar2 = 0x20000;
      local_70 = 0x20000;
      uVar11 = 0;
      do {
        while (uVar9 = uVar2, iVar4 = (*DAT_012184e0)(pVar5,uVar9,__ptr), iVar4 == 0) {
          uVar2 = uVar9 + uVar11 >> 1;
          local_70 = uVar9;
          if (uVar9 <= uVar11 + 8) goto LAB_00291a9f;
        }
        if ((iVar4 != 0x16) || (uVar9 == 0x20000)) goto LAB_00291c60;
        uVar2 = local_70 + uVar9 >> 1;
        uVar11 = uVar9;
      } while (uVar9 + 8 < local_70);
LAB_00291a9f:
      free(__ptr);
      if (local_70 <= uVar10) {
        local_70 = uVar10;
      }
    }
  }
  _DAT_01218548 = local_70;
  iVar4 = clock_gettime(4,&local_48);
  if (iVar4 == 0) {
    DAT_00380788 = 4;
  }
  else {
    iVar4 = clock_gettime(1,&local_48);
    DAT_00380788 = (uint)(iVar4 == 0);
  }
  local_50 = 0;
  pFVar6 = fopen("/proc/sys/vm/mmap_min_addr","r");
  if (pFVar6 == (FILE *)0x0) {
    uVar3 = FUN_00291810();
    uVar10 = local_50;
    if (local_50 <= uVar3) {
      uVar3 = FUN_00291810();
      uVar10 = (ulong)uVar3;
    }
  }
  else {
    fscanf(pFVar6,"%zu",&local_50);
    uVar3 = FUN_00291810();
    if (local_50 <= uVar3) {
      uVar3 = FUN_00291810();
      local_50 = (ulong)uVar3;
    }
    fclose(pFVar6);
    uVar10 = local_50;
  }
  DAT_01218510 = uVar10;
  pFVar6 = fopen("/proc/cpuinfo","r");
  lVar7 = -1;
  if (pFVar6 != (FILE *)0x0) {
    local_68 = (char *)0x0;
    local_60 = 0;
    while ((_Var8 = __getdelim(&local_68,&local_60,10,pFVar6), -1 < _Var8 &&
           (iVar4 = sscanf(local_68,"address sizes\t: %lu bits physical, %lu bits virtual",local_58,
                           &local_50), iVar4 != 2))) {
      local_50 = 0;
    }
    fclose(pFVar6);
    free(local_68);
    lVar7 = -1;
    if (local_50 != 0) {
      lVar7 = (1L << ((byte)local_50 & 0x3f)) + -1;
    }
  }
  DAT_01218508 = lVar7;
  FUN_00291770();
  FUN_00292890(DAT_01218510,DAT_01218508);
  FUN_00291780();
  return;
}


// ===== 00292170 FUN_00292170 =====

void FUN_00292170(void)

{
  ulong *puVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  char *pcVar5;
  DIR *__dirp;
  dirent *pdVar6;
  int *piVar7;
  int iVar8;
  ulong uVar9;
  long lVar10;
  byte *pbVar11;
  ulong uVar12;
  bool bVar13;
  bool bVar14;
  byte bVar15;
  uint local_17c;
  char *local_160;
  char *local_158;
  long local_150;
  void *local_148;
  ulong local_140;
  char local_138 [264];
  
  bVar15 = 0;
  local_158 = (char *)0x0;
  local_150 = 0;
  local_148 = (void *)0x0;
  local_140 = 0;
  iVar2 = FUN_002918a0();
  if (((-1 < iVar2) &&
      (iVar3 = FUN_00291550("/proc/self/status","Mems_allowed:",&local_158,&local_150),
      lVar10 = local_150, iVar3 == 0)) &&
     (pvVar4 = calloc(1,(local_150 + 1U >> 1) + 7 & 0xfffffffffffffff8), DAT_012183b0 = pvVar4,
     pvVar4 != (void *)0x0)) {
    if (lVar10 != 0) {
      pcVar5 = local_158 + lVar10 + -1;
      do {
        uVar9 = (long)(local_158 + lVar10 + -1) - (long)pcVar5;
        puVar1 = (ulong *)((long)pvVar4 + (uVar9 >> 4) * 8);
        *puVar1 = *puVar1 | (long)*pcVar5 << (((byte)uVar9 & 0xf) << 2);
        bVar13 = local_158 != pcVar5;
        pcVar5 = pcVar5 + -1;
      } while (bVar13);
    }
    DAT_012183b8 = lVar10 * 4;
    DAT_012183a8 = calloc((long)iVar2,8);
    if (((DAT_012183a8 != (void *)0x0) &&
        (DAT_012183a0 = calloc(lVar10 * 4 + 0x3fU >> 3 & 0x1ffffffffffffff8,8),
        DAT_012183a0 != (void *)0x0)) &&
       (__dirp = opendir("/sys/devices/system/node"), __dirp != (DIR *)0x0)) {
      local_17c = 0;
      while( true ) {
        pdVar6 = readdir(__dirp);
        bVar13 = false;
        if (pdVar6 == (dirent *)0x0) break;
        lVar10 = 4;
        bVar14 = false;
        pcVar5 = pdVar6->d_name;
        pbVar11 = (byte *)0x2f5fe8;
        do {
          if (lVar10 == 0) break;
          lVar10 = lVar10 + -1;
          bVar13 = (byte)*pcVar5 < *pbVar11;
          bVar14 = *pcVar5 == *pbVar11;
          pcVar5 = pcVar5 + (ulong)bVar15 * -2 + 1;
          pbVar11 = pbVar11 + (ulong)bVar15 * -2 + 1;
        } while (bVar14);
        if ((!bVar13 && !bVar14) == bVar13) {
          piVar7 = __errno_location();
          *piVar7 = 0;
          uVar9 = strtoul(pdVar6->d_name + 4,&local_160,10);
          if (((*piVar7 == 0) && (pdVar6->d_name + 4 != local_160)) &&
             ((*local_160 == '\0' && (pdVar6->d_name[4] != '-')))) {
            local_17c = snprintf(local_138,0x100,"/sys/devices/system/node/%s/cpumap",pdVar6->d_name
                                );
            if (local_17c < 0x101) {
              iVar3 = FUN_00291550(local_138,&DAT_002dd473,&local_148,&local_140);
              if (iVar3 != 0) goto LAB_00292547;
              bVar13 = iVar2 == 0 || local_140 == 0;
              local_17c = 0;
              if (iVar2 != 0 && local_140 != 0) {
                iVar3 = 0;
                uVar12 = 0;
                pvVar4 = DAT_012183a8;
                do {
                  iVar8 = iVar2 - iVar3;
                  if (4 < iVar8) {
                    iVar8 = 4;
                  }
                  if ((long)iVar8 != 0) {
                    lVar10 = 0;
                    do {
                      if (((uint)(int)*(char *)((long)local_148 + ~uVar12 + local_140) >>
                           ((uint)lVar10 & 0x1f) & 1) != 0) {
                        *(ulong *)((long)pvVar4 + lVar10 * 8) = uVar9;
                        bVar13 = true;
                      }
                      lVar10 = lVar10 + 1;
                    } while (lVar10 != iVar8);
                  }
                  iVar8 = iVar3 + 4;
                  uVar12 = uVar12 + 1;
                  iVar3 = iVar3 + 4;
                  pvVar4 = (void *)((long)pvVar4 + 0x20);
                } while ((iVar8 < iVar2) && (uVar12 < local_140));
                if (bVar13) {
                  puVar1 = (ulong *)((long)DAT_012183a0 + (uVar9 >> 6) * 8);
                  *puVar1 = *puVar1 | 1L << ((byte)uVar9 & 0x3f);
                }
              }
            }
          }
        }
      }
      if (local_17c != 0) {
LAB_00292547:
        free(DAT_012183b0);
        DAT_012183b0 = (void *)0x0;
        free(DAT_012183a8);
        DAT_012183a8 = (void *)0x0;
        DAT_012183b8 = 0;
        free(DAT_012183a0);
        DAT_012183a0 = (void *)0x0;
      }
      free(local_158);
      free(local_148);
      closedir(__dirp);
      return;
    }
  }
  free(DAT_012183b0);
  DAT_012183b0 = (void *)0x0;
  free(DAT_012183a8);
  DAT_012183a8 = (void *)0x0;
  DAT_012183b8 = 0;
  free(DAT_012183a0);
  DAT_012183a0 = (void *)0x0;
  free(local_158);
  free(local_148);
  return;
}


// ===== 002925a0 FUN_002925a0 =====

void FUN_002925a0(void)

{
  free(DAT_012183b0);
  DAT_012183b0 = (void *)0x0;
  free(DAT_012183a8);
  DAT_012183a8 = (void *)0x0;
  free(DAT_012183a0);
  DAT_012183a0 = (void *)0x0;
  return;
}


// ===== 002925f0 FUN_002925f0 =====

bool FUN_002925f0(void)

{
  FUN_002931e0(&DAT_012183c0,FUN_00292170);
  return DAT_012183b8 != 0;
}


// ===== 00292620 FUN_00292620 =====

undefined8 FUN_00292620(void)

{
  FUN_002931e0(&DAT_012183c0,FUN_00292170);
  if (DAT_012183b0 != 0) {
    return DAT_012183b8;
  }
  return 0;
}


// ===== 00292660 FUN_00292660 =====

long FUN_00292660(void)

{
  long lVar1;
  
  FUN_002931e0(&DAT_012183c0,FUN_00292170);
  lVar1 = DAT_012183b0;
  if (DAT_012183b0 == 0) {
    FUN_002925f0();
  }
  return lVar1;
}


// ===== 002926a0 FUN_002926a0 =====

int FUN_002926a0(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  FUN_002925f0();
  uVar1 = FUN_00292620();
  lVar2 = syscall(0xef,param_1,param_2,uVar1,0,0);
  return -(uint)(lVar2 != 0);
}


// ===== 002926f0 FUN_002926f0 =====

long * FUN_002926f0(ulong param_1,long param_2)

{
  ulong uVar1;
  ulong uVar2;
  long *plVar3;
  ulong uVar4;
  ulong uVar5;
  long *plVar6;
  ulong uVar7;
  
  if (DAT_01218558 == 0) {
    return (long *)0x0;
  }
  uVar7 = 1;
  uVar1 = DAT_01218550 - 1;
  uVar5 = 0;
  while (uVar4 = uVar1, uVar7 < uVar4) {
    uVar2 = uVar4 + uVar5 >> 1;
    uVar1 = uVar2;
    if (*(ulong *)(DAT_01218558 + uVar2 * 0x10) <= param_1) {
      uVar7 = uVar2 + 1;
      uVar1 = uVar4;
      uVar5 = uVar2;
    }
  }
  plVar3 = (long *)(DAT_01218558 + uVar4 * 0x10);
  plVar6 = (long *)(uVar5 * 0x10 + DAT_01218558);
  if (*plVar3 == param_2) {
    return plVar6;
  }
  if (param_1 <= (ulong)plVar6[1]) {
    plVar3 = plVar6;
  }
  return plVar3;
}


// ===== 00292770 FUN_00292770 =====

void FUN_00292770(void *param_1)

{
  long lVar1;
  undefined8 *puVar2;
  long lVar3;
  long lVar4;
  
  lVar3 = DAT_01218558;
  lVar1 = DAT_01218550 + -1;
  lVar4 = DAT_01218550 * 0x10;
  memmove(param_1,(void *)((long)param_1 + 0x10),
          (lVar1 - ((long)param_1 - DAT_01218558 >> 4)) * 0x10);
  puVar2 = (undefined8 *)(lVar3 + -0x10 + lVar4);
  DAT_01218550 = lVar1;
  *puVar2 = 0;
  puVar2[1] = 0;
  return;
}


// ===== 002927e0 FUN_002927e0 =====

void FUN_002927e0(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined8 *__src;
  void *pvVar1;
  long lVar2;
  long lVar3;
  
  param_3 = param_3 - (long)DAT_01218558;
  lVar3 = DAT_01218550 + 1;
  lVar2 = DAT_01218550 - (param_3 >> 4);
  pvVar1 = realloc(DAT_01218558,lVar3 * 0x10);
  if (pvVar1 != (void *)0x0) {
    __src = (undefined8 *)((long)pvVar1 + param_3);
    DAT_01218558 = pvVar1;
    memmove((void *)((long)pvVar1 + param_3 + 0x10),__src,lVar2 * 0x10);
    *__src = param_1;
    __src[1] = param_2;
    DAT_01218550 = lVar3;
  }
  return;
}


// ===== 00292870 FUN_00292870 =====

void FUN_00292870(void)

{
  free(DAT_01218558);
  DAT_01218558 = (void *)0x0;
  return;
}


// ===== 00292890 FUN_00292890 =====

undefined8 FUN_00292890(ulong param_1,ulong param_2)

{
  int iVar1;
  FILE *__stream;
  __ssize_t _Var2;
  void *pvVar3;
  undefined8 uVar4;
  ulong *puVar5;
  long lVar6;
  long lVar7;
  bool bVar8;
  ulong local_88;
  void *local_80;
  size_t local_70;
  char *local_68;
  ulong local_60;
  ulong local_58;
  char local_50 [16];
  char acStack_40 [16];
  
  builtin_strncpy(local_50,"%zx-%zx",8);
  local_70 = 0;
  local_68 = (char *)0x0;
  local_50._8_8_ = s__proc_self_maps_002f6020._0_8_;
  acStack_40._0_8_ = s__proc_self_maps_002f6020._8_8_;
  __stream = fopen(local_50 + 8,"r");
  if (__stream == (FILE *)0x0) {
    uVar4 = 0xffffffff;
  }
  else {
    local_80 = realloc(DAT_01218558,0x10000);
    if (local_80 == (void *)0x0) {
      fclose(__stream);
      uVar4 = 0xffffffff;
    }
    else {
      local_88 = 0x1000;
      lVar6 = 0;
      do {
        do {
          iVar1 = feof(__stream);
          if (iVar1 != 0) goto LAB_002929a0;
          _Var2 = __getdelim(&local_68,&local_70,10,__stream);
          if (_Var2 < 0) goto LAB_002929a0;
          iVar1 = sscanf(local_68,local_50,&local_60,&local_58);
        } while (iVar1 != 2);
        lVar7 = lVar6;
        if (param_1 < local_60) {
          if (local_88 < lVar6 + 2U) {
            pvVar3 = realloc(local_80,local_88 << 5);
            if (pvVar3 == (void *)0x0) break;
            local_88 = local_88 << 1;
            local_80 = pvVar3;
          }
          lVar7 = lVar6 + 1;
          puVar5 = (ulong *)(lVar6 * 0x10 + (long)local_80);
          *puVar5 = param_1;
          puVar5[1] = local_60;
        }
        if (param_1 <= local_58) {
          param_1 = local_58;
        }
        bVar8 = param_1 < param_2;
        if (param_2 < param_1) {
          param_1 = param_2;
        }
        lVar6 = lVar7;
      } while (bVar8);
LAB_002929a0:
      lVar7 = lVar6;
      if (param_1 < param_2) {
        lVar7 = lVar6 + 1;
        puVar5 = (ulong *)(lVar6 * 0x10 + (long)local_80);
        *puVar5 = param_1;
        puVar5[1] = param_2;
      }
      fclose(__stream);
      free(local_68);
      DAT_01218558 = local_80;
      uVar4 = 0;
      DAT_01218550 = lVar7;
    }
  }
  return uVar4;
}


// ===== 00292a40 FUN_00292a40 =====

void FUN_00292a40(ulong param_1,ulong param_2)

{
  ulong uVar1;
  ulong *puVar2;
  ulong *puVar3;
  
  puVar2 = (ulong *)FUN_002926f0();
  if (puVar2 == (ulong *)0x0) {
    return;
  }
  uVar1 = puVar2[1];
  if ((param_1 < uVar1) && (*puVar2 < param_2)) {
    return;
  }
  puVar3 = puVar2 + 2;
  if (puVar3 == DAT_01218558 + DAT_01218550 * 2) {
    if (DAT_01218558 != puVar2) {
      if (param_1 == uVar1) goto LAB_00292af5;
      goto LAB_00292ad8;
    }
LAB_00292ac5:
    if (*puVar2 == param_2) {
      *puVar2 = param_1;
      return;
    }
  }
  else {
    if ((param_1 < puVar2[3]) && (puVar2[2] < param_2)) {
      return;
    }
    if (DAT_01218558 == puVar2) goto LAB_00292ac5;
  }
  if (param_1 == uVar1) {
    if (param_2 == puVar2[2]) {
      puVar2[1] = puVar2[3];
      FUN_00292770();
      return;
    }
LAB_00292af5:
    puVar2[1] = param_2;
    return;
  }
  puVar3 = puVar2;
  if (param_2 == puVar2[2]) {
    puVar2[2] = param_1;
    return;
  }
LAB_00292ad8:
  FUN_002927e0(param_1,param_2,puVar3);
  return;
}


// ===== 00292b20 FUN_00292b20 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00292b20(FILE *param_1,uint param_2,undefined2 param_3)

{
  int __fd;
  int iVar1;
  int *piVar2;
  ulong uVar3;
  float fVar4;
  undefined1 local_68 [16];
  undefined2 local_58;
  undefined2 local_56;
  undefined8 local_50;
  undefined8 local_48;
  
  __fd = fileno(param_1);
  if (__fd == -1) {
    return 0xffffffff;
  }
  local_56 = 0;
  local_50 = 0;
  local_48 = 0;
  local_58 = param_3;
  FUN_00291790(local_68);
  while( true ) {
    iVar1 = fcntl(__fd,6,&local_58);
    if (iVar1 == 0) {
      return 0;
    }
    piVar2 = __errno_location();
    if (((*piVar2 - 0xbU & 0xfffffffd) != 0) && (*piVar2 != 4)) break;
    fVar4 = (float)FUN_002917b0(local_68);
    if (_DAT_002986b4 <= fVar4) {
      uVar3 = (long)(fVar4 - _DAT_002986b4) ^ 0x8000000000000000;
    }
    else {
      uVar3 = (ulong)fVar4;
    }
    if (param_2 <= uVar3) {
      return 0xfffffffe;
    }
    uVar3 = param_2 - uVar3;
    if (uVar3 < 10) {
      usleep((int)uVar3 * 1000);
    }
    else {
      usleep(10000);
    }
  }
  return 0xffffffff;
}


// ===== 00292c40 FUN_00292c40 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00292c40(void)

{
  char *pcVar1;
  long lVar2;
  
  if (DAT_01218560 == '\0') {
    DAT_01218578 = 0;
    dlerror();
    DAT_01218570 = dlopen(0,1);
    if (DAT_01218570 != 0) {
      DAT_01218578 = dlvsym(DAT_01218570,"pipe2","GLIBC_2.9");
      lVar2 = dlerror();
      if ((lVar2 != 0) && (DAT_01218570 != 0)) {
        dlclose();
        DAT_01218570 = 0;
        DAT_01218578 = 0;
      }
    }
    DAT_01218560 = '\x01';
    __cxa_atexit(FUN_002916c0,&DAT_01218570,&PTR_LOOP_0032f660);
  }
  _DAT_01218588 = DAT_01218578;
  FUN_00291760();
  pcVar1 = (char *)gnu_get_libc_version();
  if ((*pcVar1 == '2') && (pcVar1[1] == '.')) {
    lVar2 = strtol(pcVar1 + 2,(char **)0x0,10);
    if ((int)lVar2 - 0x14U < 5) {
      DAT_01218580 = 1;
      return;
    }
  }
  return;
}


// ===== 00292d50 FUN_00292d50 =====

long FUN_00292d50(int *param_1)

{
  timeval local_68;
  tm local_58;
  
  gettimeofday(&local_68,(__timezone_ptr_t)0x0);
  localtime_r(&local_68.tv_sec,&local_58);
  *param_1 = local_58.tm_year + 0x76c;
  param_1[1] = local_58.tm_mon + 1;
  param_1[2] = local_58.tm_mday;
  param_1[3] = local_58.tm_wday;
  param_1[4] = local_58.tm_hour;
  param_1[5] = local_58.tm_min;
  param_1[6] = local_58.tm_sec;
  param_1[7] = (int)(local_68.tv_usec / 1000);
  return local_68.tv_usec * 0x20c49ba5e353f7cf;
}


// ===== 00292de0 FUN_00292de0 =====

size_t FUN_00292de0(char *param_1,void *param_2,ulong param_3)

{
  char *__s;
  size_t sVar1;
  
  __s = getenv(param_1);
  if (__s == (char *)0x0) {
    sVar1 = 0xffffffff;
  }
  else {
    sVar1 = strlen(__s);
    if (sVar1 < param_3) {
      memcpy(param_2,__s,sVar1 + 1);
      sVar1 = 0;
    }
  }
  return sVar1;
}


// ===== 00292e30 FUN_00292e30 =====

void FUN_00292e30(void *param_1,size_t param_2,int param_3)

{
  if (param_3 == 1) {
    mmap(param_1,param_2,0,0x32,-1,0);
    return;
  }
  if (param_3 != 2) {
    return;
  }
  FUN_00291770();
  FUN_00291860(param_1,param_2);
  munmap(param_1,param_2);
  FUN_00291780();
  return;
}


// ===== 00292ea0 FUN_00292ea0 =====

void FUN_00292ea0(undefined8 param_1)

{
  dlerror();
  dlopen(param_1,2);
  return;
}


// ===== 00292ed0 FUN_00292ed0 =====

bool FUN_00292ed0(void)

{
  int iVar1;
  
  iVar1 = dlclose();
  return iVar1 == 0;
}


// ===== 00292ef0 dlsym =====

void dlsym(void)

{
  (*(code *)PTR_dlsym_0032f5f8)();
  return;
}


// ===== 00292f00 FUN_00292f00 =====

void FUN_00292f00(uint param_1)

{
  int iVar1;
  int *piVar2;
  timespec local_48;
  timespec local_38;
  
  local_48.tv_sec = (ulong)param_1 / 1000;
  local_48.tv_nsec = (long)((param_1 + (int)local_48.tv_sec * -1000) * 1000000);
  iVar1 = nanosleep(&local_48,&local_38);
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    do {
      if (*piVar2 != 4) {
        return;
      }
      local_48.tv_sec = local_38.tv_sec;
      local_48.tv_nsec = local_38.tv_nsec;
      iVar1 = nanosleep(&local_48,&local_38);
    } while (iVar1 != 0);
  }
  return;
}


// ===== 00292f80 FUN_00292f80 =====

void FUN_00292f80(pthread_mutex_t *param_1,int param_2)

{
  int iVar1;
  pthread_mutexattr_t local_2c [3];
  
  iVar1 = pthread_mutexattr_init(local_2c);
  if (iVar1 == 0) {
    iVar1 = pthread_mutexattr_settype(local_2c,1);
    if (iVar1 == 0) {
      iVar1 = pthread_mutexattr_setpshared(local_2c,param_2);
      if (iVar1 == 0) {
        iVar1 = pthread_mutex_init(param_1,local_2c);
        if (iVar1 == 0) {
          pthread_mutexattr_destroy(local_2c);
        }
      }
    }
  }
  return;
}


// ===== 00292ff0 FUN_00292ff0 =====

void FUN_00292ff0(undefined8 param_1)

{
  FUN_00292f80(param_1,0);
  return;
}


// ===== 00293000 pthread_mutex_lock =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_lock(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_mutex_lock_0032f628)();
  return iVar1;
}


// ===== 00293010 pthread_mutex_unlock =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_unlock(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_mutex_unlock_0032f3e0)();
  return iVar1;
}


// ===== 00293020 FUN_00293020 =====

void FUN_00293020(undefined8 *param_1)

{
  int iVar1;
  pthread_rwlock_t *__rwlock;
  pthread_rwlockattr_t local_30 [2];
  
  __rwlock = calloc(1,0x38);
  if (__rwlock != (pthread_rwlock_t *)0x0) {
    iVar1 = pthread_rwlockattr_init(local_30);
    if (iVar1 == 0) {
      iVar1 = pthread_rwlockattr_setpshared(local_30,0);
      if (iVar1 == 0) {
        iVar1 = pthread_rwlock_init(__rwlock,local_30);
        if (iVar1 == 0) {
          *param_1 = __rwlock;
          pthread_rwlockattr_destroy(local_30);
          *param_1 = __rwlock;
          return;
        }
      }
    }
    pthread_rwlockattr_destroy(local_30);
    free(__rwlock);
  }
  *param_1 = 0;
  return;
}


// ===== 002930c0 FUN_002930c0 =====

void FUN_002930c0(undefined8 *param_1)

{
  pthread_rwlock_t *__rwlock;
  int iVar1;
  timespec local_28;
  
  __rwlock = (pthread_rwlock_t *)*param_1;
  if (DAT_01218580 != 0) {
    local_28.tv_sec = -1;
    local_28.tv_nsec = -1;
    iVar1 = pthread_rwlock_timedrdlock(__rwlock,&local_28);
    if (iVar1 == 0) {
      return;
    }
  }
  pthread_rwlock_rdlock(__rwlock);
  return;
}


// ===== 00293110 FUN_00293110 =====

void FUN_00293110(undefined8 *param_1)

{
  pthread_rwlock_t *__rwlock;
  int iVar1;
  timespec local_28;
  
  __rwlock = (pthread_rwlock_t *)*param_1;
  if (DAT_01218580 != 0) {
    local_28.tv_sec = -1;
    local_28.tv_nsec = -1;
    iVar1 = pthread_rwlock_timedwrlock(__rwlock,&local_28);
    if (iVar1 == 0) {
      return;
    }
  }
  pthread_rwlock_wrlock(__rwlock);
  return;
}


// ===== 00293160 FUN_00293160 =====

int FUN_00293160(undefined8 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = pthread_rwlock_trywrlock((pthread_rwlock_t *)*param_1);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = (iVar1 != 0x10) - 2;
  }
  return iVar2;
}


// ===== 00293180 FUN_00293180 =====

void FUN_00293180(undefined8 *param_1)

{
  pthread_rwlock_unlock((pthread_rwlock_t *)*param_1);
  return;
}


// ===== 00293190 FUN_00293190 =====

void FUN_00293190(undefined8 *param_1)

{
  pthread_rwlock_unlock((pthread_rwlock_t *)*param_1);
  return;
}


// ===== 002931a0 FUN_002931a0 =====

void FUN_002931a0(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    pthread_rwlock_destroy((pthread_rwlock_t *)*param_1);
    free((void *)*param_1);
    *param_1 = 0;
    return;
  }
  return;
}


// ===== 002931e0 FUN_002931e0 =====

int FUN_002931e0(pthread_once_t *param_1,__init_routine *param_2)

{
  int iVar1;
  
  iVar1 = pthread_once(param_1,param_2);
  return -(uint)(iVar1 != 0);
}


// ===== 00293200 getpid =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t getpid(void)

{
  __pid_t _Var1;
  
  _Var1 = (*(code *)PTR_getpid_0032f108)();
  return _Var1;
}


// ===== 00293210 FUN_00293210 =====

void FUN_00293210(undefined8 *param_1)

{
  ulong uVar1;
  undefined8 *puVar2;
  
  *param_1 = 0;
  param_1[0xb] = 0;
  puVar2 = (undefined8 *)((ulong)(param_1 + 1) & 0xfffffffffffffff8);
  for (uVar1 = (ulong)(((int)param_1 -
                       (int)(undefined8 *)((ulong)(param_1 + 1) & 0xfffffffffffffff8)) + 0x60U >> 3)
      ; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  pthread_mutex_init((pthread_mutex_t *)(param_1 + 1),(pthread_mutexattr_t *)0x0);
  pthread_cond_init((pthread_cond_t *)(param_1 + 6),(pthread_condattr_t *)0x0);
  return;
}


// ===== 00293260 FUN_00293260 =====

void FUN_00293260(long param_1)

{
  pthread_mutex_destroy((pthread_mutex_t *)(param_1 + 8));
  pthread_cond_destroy((pthread_cond_t *)(param_1 + 0x30));
  return;
}


// ===== 00293290 FUN_00293290 =====

void FUN_00293290(undefined1 *param_1)

{
  long lVar1;
  
  lVar1 = syscall(0xba);
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 8));
  *(int *)(param_1 + 4) = (int)lVar1;
  *param_1 = 1;
  pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 8));
  pthread_cond_broadcast((pthread_cond_t *)(param_1 + 0x30));
  return;
}


// ===== 002932e0 FUN_002932e0 =====

undefined8 FUN_002932e0(undefined8 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_00293290(param_1 + 4);
  uVar1 = (*(code *)*param_1)(param_1[1]);
  *(undefined4 *)(param_1 + 2) = uVar1;
  iVar2 = FUN_00291850(param_1 + 0x10);
  if (iVar2 != 0) {
    return 0;
  }
  FUN_00293260(param_1 + 4);
  free(param_1);
  return 0;
}


// ===== 00293340 FUN_00293340 =====

undefined4 FUN_00293340(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 *__arg;
  long lVar3;
  undefined8 *puVar4;
  byte bVar5;
  
  bVar5 = 0;
  *param_1 = 0;
  __arg = malloc(0x88);
  if (__arg == (undefined8 *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    puVar4 = __arg + 2;
    for (lVar3 = 0xf; lVar3 != 0; lVar3 = lVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + (ulong)bVar5 * -2 + 1;
    }
    __arg[1] = param_3;
    *__arg = param_2;
    *(undefined4 *)(__arg + 2) = 0xffffffff;
    *(undefined4 *)(__arg + 0x10) = 2;
    FUN_00293210(__arg + 4);
    iVar1 = pthread_create(__arg + 3,(pthread_attr_t *)0x0,FUN_002932e0,__arg);
    if (iVar1 == 0) {
      *param_1 = __arg;
      uVar2 = 0;
    }
    else {
      FUN_00293260(__arg + 4);
      free(__arg);
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}


// ===== 002933f0 FUN_002933f0 =====

void FUN_002933f0(void *param_1,undefined4 *param_2)

{
  int iVar1;
  void *local_20;
  
  local_20 = (void *)0x0;
  pthread_join(*(pthread_t *)((long)param_1 + 0x18),&local_20);
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)((long)param_1 + 0x10);
  }
  iVar1 = FUN_00291850((long)param_1 + 0x80);
  if (iVar1 != 0) {
    return;
  }
  FUN_00293260((long)param_1 + 0x20);
  free(param_1);
  return;
}


// ===== 00293460 FUN_00293460 =====

void FUN_00293460(undefined8 param_1,undefined8 param_2)

{
  FUN_00292b20(param_1,param_2,1);
  return;
}


// ===== 00293470 thunk_FUN_00293460 =====

void thunk_FUN_00293460(undefined8 param_1,undefined8 param_2)

{
  FUN_00292b20(param_1,param_2,1);
  return;
}


// ===== 00293480 FUN_00293480 =====

undefined8 FUN_00293480(FILE *param_1)

{
  int __fd;
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 local_48 [2];
  undefined8 local_40;
  undefined8 local_38;
  
  __fd = fileno(param_1);
  if (__fd != -1) {
    local_48[0] = 2;
    iVar3 = 0x11;
    local_40 = 0;
    local_38 = 0;
    do {
      iVar1 = fcntl(__fd,6,local_48);
      if (-1 < iVar1) {
        return 0;
      }
      piVar2 = __errno_location();
    } while ((*piVar2 == 4) && (iVar3 = iVar3 + -1, iVar3 != 0));
  }
  return 0xffffffff;
}


// ===== 00293510 thunk_FUN_00292ff0 =====

void thunk_FUN_00292ff0(undefined8 param_1)

{
  FUN_00292f80(param_1,0);
  return;
}


// ===== 00293520 pthread_mutex_lock =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_lock(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_mutex_lock_0032f628)();
  return iVar1;
}


// ===== 00293530 pthread_mutex_unlock =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_unlock(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_mutex_unlock_0032f3e0)();
  return iVar1;
}


// ===== 00293540 thunk_FUN_00293020 =====

void thunk_FUN_00293020(undefined8 *param_1)

{
  int iVar1;
  pthread_rwlock_t *__rwlock;
  pthread_rwlockattr_t apStack_30 [2];
  
  __rwlock = calloc(1,0x38);
  if (__rwlock != (pthread_rwlock_t *)0x0) {
    iVar1 = pthread_rwlockattr_init(apStack_30);
    if (iVar1 == 0) {
      iVar1 = pthread_rwlockattr_setpshared(apStack_30,0);
      if (iVar1 == 0) {
        iVar1 = pthread_rwlock_init(__rwlock,apStack_30);
        if (iVar1 == 0) {
          *param_1 = __rwlock;
          pthread_rwlockattr_destroy(apStack_30);
          *param_1 = __rwlock;
          return;
        }
      }
    }
    pthread_rwlockattr_destroy(apStack_30);
    free(__rwlock);
  }
  *param_1 = 0;
  return;
}


// ===== 00293550 thunk_FUN_002930c0 =====

void thunk_FUN_002930c0(undefined8 *param_1)

{
  pthread_rwlock_t *__rwlock;
  int iVar1;
  timespec tStack_28;
  
  __rwlock = (pthread_rwlock_t *)*param_1;
  if (DAT_01218580 != 0) {
    tStack_28.tv_sec = -1;
    tStack_28.tv_nsec = -1;
    iVar1 = pthread_rwlock_timedrdlock(__rwlock,&tStack_28);
    if (iVar1 == 0) {
      return;
    }
  }
  pthread_rwlock_rdlock(__rwlock);
  return;
}


// ===== 00293560 thunk_FUN_00293110 =====

void thunk_FUN_00293110(undefined8 *param_1)

{
  pthread_rwlock_t *__rwlock;
  int iVar1;
  timespec tStack_28;
  
  __rwlock = (pthread_rwlock_t *)*param_1;
  if (DAT_01218580 != 0) {
    tStack_28.tv_sec = -1;
    tStack_28.tv_nsec = -1;
    iVar1 = pthread_rwlock_timedwrlock(__rwlock,&tStack_28);
    if (iVar1 == 0) {
      return;
    }
  }
  pthread_rwlock_wrlock(__rwlock);
  return;
}


// ===== 00293570 thunk_FUN_00293160 =====

int thunk_FUN_00293160(undefined8 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = pthread_rwlock_trywrlock((pthread_rwlock_t *)*param_1);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = (iVar1 != 0x10) - 2;
  }
  return iVar2;
}


// ===== 00293580 thunk_FUN_00293180 =====

void thunk_FUN_00293180(undefined8 *param_1)

{
  pthread_rwlock_unlock((pthread_rwlock_t *)*param_1);
  return;
}


// ===== 00293590 thunk_FUN_00293190 =====

void thunk_FUN_00293190(undefined8 *param_1)

{
  pthread_rwlock_unlock((pthread_rwlock_t *)*param_1);
  return;
}


// ===== 002935a0 thunk_FUN_002931a0 =====

void thunk_FUN_002931a0(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    pthread_rwlock_destroy((pthread_rwlock_t *)*param_1);
    free((void *)*param_1);
    *param_1 = 0;
    return;
  }
  return;
}


// ===== 002935b0 FUN_002935b0 =====

void FUN_002935b0(char *param_1,stat *param_2)

{
  __xstat(1,param_1,param_2);
  return;
}


// ===== 002935c0 FUN_002935c0 =====

void FUN_002935c0(int param_1,stat *param_2)

{
  __fxstat(1,param_1,param_2);
  return;
}


// ===== 002935d0 FUN_002935d0 =====

void FUN_002935d0(int param_1,char *param_2,stat *param_3,int param_4)

{
  __fxstatat(1,param_1,param_2,param_3,param_4);
  return;
}


// ===== 002935f0 FUN_002935f0 =====

ulong FUN_002935f0(ulong param_1)

{
  ulong uVar1;
  
  param_1 = param_1 - (param_1 >> 1 & 0x5555555555555555);
  uVar1 = (param_1 >> 2 & 0x3333333333333333) + (param_1 & 0x3333333333333333);
  return ((uVar1 >> 4) + uVar1 & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >> 0x38;
}


// ===== 0029364a FUN_0029364a =====

undefined8 * FUN_0029364a(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined1 local_48 [48];
  undefined1 *local_18;
  undefined8 *local_10;
  
  local_10 = DAT_01218590;
  pthread_mutex_lock((pthread_mutex_t *)&DAT_01218640);
  puVar1 = DAT_01218590;
  if ((local_10 == (undefined8 *)0x0) &&
     (local_10 = calloc(1,0x60), puVar1 = local_10, local_10 == (undefined8 *)0x0)) {
    pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218640);
    local_10 = (undefined8 *)0x0;
  }
  else {
    DAT_01218590 = puVar1;
    uVar3 = DAT_01218838;
    if (*(int *)((long)local_10 + 0x5c) == 0) {
      local_10[3] = DAT_01218830;
      local_10[4] = uVar3;
      local_10[5] = DAT_01218840;
      *local_10 = local_10[3];
      local_10[1] = local_10[4];
      local_10[2] = local_10[5];
      uVar3 = FUN_002938c7();
      local_10[7] = uVar3;
      local_18 = local_48;
      FUN_002977c3(local_18,local_10 + 9,0x14,0);
      FUN_0029579d(local_18,local_10);
      FUN_0029579d(local_18,local_10 + 3);
      uVar2 = (**(code **)(*(long *)(local_18 + 8) + 0x20))(local_18);
      *(undefined4 *)((long)local_10 + 0x5c) = uVar2;
      if (*(long *)(*(long *)(local_18 + 8) + 0x38) != 0) {
        (**(code **)(*(long *)(local_18 + 8) + 0x38))(local_18);
      }
    }
    pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218640);
  }
  return local_10;
}


// ===== 002937bf FUN_002937bf =====

undefined4 FUN_002937bf(undefined8 param_1,long param_2)

{
  undefined4 local_c;
  
  local_c = 0;
  if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("xdrs != ((void *)0)",
                  "/nv/p4/tools/unix/hosts/Linux-x86/targets/build-scripts/libtirpc-1.3.5/src/auth_none.c"
                  ,0x73,"authnone_marshal");
  }
  pthread_mutex_lock((pthread_mutex_t *)&DAT_01218640);
  if (DAT_01218590 != 0) {
    local_c = (**(code **)(*(long *)(param_2 + 8) + 0x18))
                        (param_2,DAT_01218590 + 0x48,*(undefined4 *)(DAT_01218590 + 0x5c));
  }
  pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218640);
  return local_c;
}


// ===== 00293858 FUN_00293858 =====

void FUN_00293858(void)

{
  return;
}


// ===== 00293863 FUN_00293863 =====

undefined8 FUN_00293863(void)

{
  return 1;
}


// ===== 00293876 FUN_00293876 =====

undefined8 FUN_00293876(void)

{
  return 0;
}


// ===== 00293889 FUN_00293889 =====

void FUN_00293889(void)

{
  return;
}


// ===== 00293894 FUN_00293894 =====

void FUN_00293894(undefined8 param_1,undefined8 param_2,code *param_3,undefined8 param_4)

{
  (*param_3)(param_2,param_4);
  return;
}


// ===== 002938c7 FUN_002938c7 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * FUN_002938c7(void)

{
  pthread_mutex_lock((pthread_mutex_t *)&DAT_012186c0);
  if (DAT_012185a0 == (code *)0x0) {
    DAT_012185a0 = FUN_00293858;
    _DAT_012185a8 = FUN_002937bf;
    _DAT_012185b0 = FUN_00293863;
    _DAT_012185b8 = FUN_00293876;
    _DAT_012185c0 = FUN_00293889;
    _DAT_012185c8 = FUN_00293894;
    _DAT_012185d0 = FUN_00293894;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&DAT_012186c0);
  return &DAT_012185a0;
}


// ===== 00293960 FUN_00293960 =====

void FUN_00293960(long param_1,int *param_2)

{
  long local_10;
  
  local_10 = (long)*param_2;
  (**(code **)(*(long *)(param_1 + 8) + 8))(param_1,&local_10);
  return;
}


// ===== 0029399a FUN_0029399a =====

undefined8 * FUN_0029399a(void)

{
  undefined8 *puVar1;
  int *piVar2;
  
  puVar1 = calloc(1,0x10);
  if (puVar1 == (undefined8 *)0x0) {
    piVar2 = __errno_location();
    *piVar2 = 0xc;
    puVar1 = (undefined8 *)0x0;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = puVar1;
  }
  return puVar1;
}


// ===== 002939eb FUN_002939eb =====

undefined4 * FUN_002939eb(int param_1,long *param_2)

{
  int *piVar1;
  undefined4 *local_10;
  
  for (local_10 = (undefined4 *)*param_2;
      (local_10 != (undefined4 *)0x0 && (param_1 != local_10[0xe]));
      local_10 = *(undefined4 **)(local_10 + 0x10)) {
  }
  if (local_10 == (undefined4 *)0x0) {
    local_10 = calloc(1,0x50);
    if (local_10 == (undefined4 *)0x0) {
      piVar1 = __errno_location();
      *piVar1 = 0xc;
      local_10 = (undefined4 *)0x0;
    }
    else {
      local_10[0xe] = param_1;
      local_10[0xf] = 1;
      *local_10 = 0;
      local_10[1] = 0;
      pthread_cond_init((pthread_cond_t *)(local_10 + 2),(pthread_condattr_t *)0x0);
      *(long *)(local_10 + 0x10) = *param_2;
      if (*(long *)(local_10 + 0x10) == 0) {
        param_2[1] = (long)(local_10 + 0x10);
      }
      else {
        *(undefined4 **)(*param_2 + 0x48) = local_10 + 0x10;
      }
      *param_2 = (long)local_10;
      *(long **)(local_10 + 0x12) = param_2;
    }
  }
  else {
    local_10[0xf] = local_10[0xf] + 1;
  }
  return local_10;
}


// ===== 00293b18 FUN_00293b18 =====

void FUN_00293b18(undefined8 param_1,void *param_2,long param_3)

{
  *(int *)((long)param_2 + 0x3c) = *(int *)((long)param_2 + 0x3c) + -1;
  if (*(int *)((long)param_2 + 0x3c) == 0) {
    if (*(long *)((long)param_2 + 0x40) == 0) {
      *(undefined8 *)(param_3 + 8) = *(undefined8 *)((long)param_2 + 0x48);
    }
    else {
      *(undefined8 *)(*(long *)((long)param_2 + 0x40) + 0x48) =
           *(undefined8 *)((long)param_2 + 0x48);
    }
    **(undefined8 **)((long)param_2 + 0x48) = *(undefined8 *)((long)param_2 + 0x40);
    pthread_cond_destroy((pthread_cond_t *)((long)param_2 + 8));
    free(param_2);
  }
  return;
}


// ===== 00293bb4 FUN_00293bb4 =====

undefined8 *
FUN_00293bb4(int param_1,uint *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *piVar6;
  void *pvVar7;
  undefined8 uVar8;
  undefined4 local_258;
  undefined4 local_254;
  socklen_t local_23c;
  sockaddr local_238 [8];
  sigset_t local_1b8;
  __sigset_t local_138;
  uint local_b8 [4];
  undefined4 local_a8;
  timeval local_68;
  undefined4 *local_58;
  undefined4 *local_50;
  undefined4 *local_48;
  undefined4 *local_40;
  long local_38;
  undefined4 *local_30;
  undefined8 *local_28;
  int *local_20;
  
  local_20 = (int *)0x0;
  pthread_mutex_lock((pthread_mutex_t *)&DAT_01218740);
  if (DAT_012185e0 == 0) {
    DAT_012185e0 = (uint)param_2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218740);
  local_28 = calloc(1,0x28);
  local_20 = calloc(1,0x98);
  if ((local_28 == (undefined8 *)0x0) || (local_20 == (int *)0x0)) {
    local_58 = (undefined4 *)FUN_002956df();
    *local_58 = 0xc;
    piVar6 = __errno_location();
    local_58[2] = *piVar6;
    syslog(3,"%s : %s","clnt_vc_create","out of memory");
  }
  else {
    local_20[0xe] = 0;
    local_20[0xf] = 0;
    sigfillset(&local_1b8);
    pthread_sigmask(2,&local_1b8,&local_138);
    pthread_mutex_lock((pthread_mutex_t *)&DAT_01218680);
    if ((DAT_012185d8 == 0) && (DAT_012185d8 = FUN_0029399a(), DAT_012185d8 == 0)) {
      pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218680);
      local_30 = (undefined4 *)FUN_002956df();
      *local_30 = 0xc;
      piVar6 = __errno_location();
      local_30[2] = *piVar6;
    }
    else {
      local_38 = FUN_002939eb(param_1,DAT_012185d8);
      if (local_38 == 0) {
        pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218680);
        local_50 = (undefined4 *)FUN_002956df();
        *local_50 = 0xc;
        piVar6 = __errno_location();
        local_50[2] = *piVar6;
      }
      else {
        pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218680);
        local_23c = 0x80;
        iVar1 = getpeername(param_1,local_238,&local_23c);
        if (iVar1 < 0) {
          piVar6 = __errno_location();
          if (*piVar6 != 0x6b) {
            local_48 = (undefined4 *)FUN_002956df();
            *local_48 = 0xc;
            piVar6 = __errno_location();
            local_48[2] = *piVar6;
            pthread_sigmask(2,&local_138,(__sigset_t *)0x0);
            goto LAB_0029416f;
          }
          iVar1 = connect(param_1,*(sockaddr **)(param_2 + 2),param_2[1]);
          if ((iVar1 < 0) && (piVar6 = __errno_location(), *piVar6 != 0x6a)) {
            local_40 = (undefined4 *)FUN_002956df();
            *local_40 = 0xc;
            piVar6 = __errno_location();
            local_40[2] = *piVar6;
            pthread_sigmask(2,&local_138,(__sigset_t *)0x0);
            goto LAB_0029416f;
          }
        }
        iVar1 = FUN_00295efc(param_1,&local_258);
        if (iVar1 != 0) {
          pthread_sigmask(2,&local_138,(__sigset_t *)0x0);
          local_20[4] = 0;
          *local_20 = param_1;
          *(long *)(local_20 + 2) = local_38;
          local_20[8] = 0;
          local_20[9] = 0;
          local_20[10] = 0;
          pvVar7 = malloc((ulong)*param_2);
          *(void **)(local_20 + 0xe) = pvVar7;
          if (*(long *)(local_20 + 0xe) != 0) {
            memcpy(*(void **)(local_20 + 0xe),*(void **)(param_2 + 2),(ulong)param_2[1]);
            local_20[0xd] = param_2[1];
            local_20[0xc] = *param_2;
            gettimeofday(&local_68,(__timezone_ptr_t)0x0);
            pthread_mutex_lock((pthread_mutex_t *)&DAT_01218740);
            uVar2 = DAT_012185e0 + 1;
            DAT_012185e0 = uVar2;
            uVar3 = getpid();
            local_b8[0] = (uint)local_68.tv_usec ^ uVar3 ^ (uint)local_68.tv_sec ^ uVar2;
            pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218740);
            local_b8[1] = 0;
            local_b8[2] = 2;
            local_b8[3] = param_3;
            local_a8 = param_4;
            FUN_002977c3(local_20 + 0x1a,local_20 + 0x13,0x18,0);
            iVar1 = FUN_00295b27(local_20 + 0x1a,local_b8);
            if (iVar1 != 0) {
              iVar1 = (**(code **)(*(long *)(local_20 + 0x1c) + 0x20))(local_20 + 0x1a);
              local_20[0x19] = iVar1;
              if (*(long *)(*(long *)(local_20 + 0x1c) + 0x38) != 0) {
                (**(code **)(*(long *)(local_20 + 0x1c) + 0x38))(local_20 + 0x1a);
              }
              uVar8 = FUN_002955c2();
              local_28[1] = uVar8;
              local_28[2] = local_20;
              uVar8 = FUN_0029364a();
              *local_28 = uVar8;
              uVar4 = FUN_00295ea8(local_258,local_254,param_5);
              uVar5 = FUN_00295ea8(local_258,local_254,param_6);
              FUN_0029651d(local_20 + 0x1a,uVar4,uVar5,local_28[2],FUN_002953fe,FUN_0029553b);
              return local_28;
            }
            if (local_20[4] != 0) {
              close(param_1);
            }
          }
        }
      }
    }
  }
LAB_0029416f:
  if (local_28 == (undefined8 *)0x0) {
    if (local_20 != (int *)0x0) {
      if (local_20[0xd] != 0) {
        free(*(void **)(local_20 + 0xe));
      }
      free(local_20);
    }
  }
  else {
    if (local_20 != (int *)0x0) {
      if (local_20[0xd] != 0) {
        free(*(void **)(local_20 + 0xe));
      }
      free(local_20);
    }
    free(local_28);
  }
  return (undefined8 *)0x0;
}


// ===== 002941ef FUN_002941ef =====

undefined4
FUN_002941ef(long *param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,long param_5,
            undefined8 param_6,long param_7,long param_8)

{
  int iVar1;
  bool bVar2;
  undefined4 local_184;
  long *local_180;
  sigset_t local_178;
  __sigset_t local_f8;
  uint32_t local_78 [4];
  undefined8 local_68;
  long local_60;
  undefined8 local_58;
  undefined8 local_48;
  code *local_40;
  uint32_t local_30;
  int local_2c;
  uint32_t *local_28;
  undefined4 *local_20;
  long local_18;
  int local_c;
  
  local_18 = param_1[2];
  local_20 = (undefined4 *)(local_18 + 0x68);
  local_28 = (uint32_t *)(local_18 + 0x4c);
  local_c = 2;
  local_184 = param_2;
  local_180 = param_1;
  if (param_1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("cl != ((void *)0)",
                  "/nv/p4/tools/unix/hosts/Linux-x86/targets/build-scripts/libtirpc-1.3.5/src/clnt_vc.c"
                  ,0x164,"clnt_vc_call");
  }
  sigfillset(&local_178);
  pthread_sigmask(2,&local_178,&local_f8);
  pthread_mutex_lock((pthread_mutex_t *)&DAT_01218680);
  *(int *)(*(long *)(local_18 + 8) + 4) = *(int *)(*(long *)(local_18 + 8) + 4) + 1;
  while (**(int **)(local_18 + 8) != 0) {
    pthread_cond_wait((pthread_cond_t *)(*(long *)(local_18 + 8) + 8),
                      (pthread_mutex_t *)&DAT_01218680);
  }
  **(undefined4 **)(local_18 + 8) = 1;
  pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218680);
  if ((*(int *)(local_18 + 0x28) == 0) && (iVar1 = FUN_00295691(&param_7), iVar1 == 0)) {
    *(long *)(local_18 + 0x18) = param_7;
    *(long *)(local_18 + 0x20) = param_8;
  }
  if (((param_5 == 0) && (param_7 == 0)) && (param_8 == 0)) {
    local_2c = 0;
  }
  else {
    local_2c = 1;
  }
  while( true ) {
    *local_20 = 0;
    *(undefined4 *)(local_18 + 0x40) = 0;
    *local_28 = *local_28 - 1;
    local_30 = ntohl(*local_28);
    iVar1 = (**(code **)(*(long *)(local_20 + 2) + 0x18))
                      (local_20,local_18 + 0x4c,*(undefined4 *)(local_18 + 100));
    if (((iVar1 == 0) || (iVar1 = FUN_00293960(local_20,&local_184), iVar1 == 0)) ||
       ((iVar1 = (**(code **)(*(long *)(*local_180 + 0x38) + 8))(*local_180,local_20), iVar1 == 0 ||
        (iVar1 = (**(code **)(*(long *)(*local_180 + 0x38) + 0x28))
                           (*local_180,local_20,param_3,param_4), iVar1 == 0)))) {
      if (*(int *)(local_18 + 0x40) == 0) {
        *(undefined4 *)(local_18 + 0x40) = 1;
      }
      FUN_00296e9b(local_20,1);
      pthread_mutex_lock((pthread_mutex_t *)&DAT_01218680);
      **(undefined4 **)(local_18 + 8) = 0;
      *(int *)(*(long *)(local_18 + 8) + 4) = *(int *)(*(long *)(local_18 + 8) + 4) + -1;
      pthread_sigmask(2,&local_f8,(__sigset_t *)0x0);
      pthread_cond_signal((pthread_cond_t *)(*(long *)(local_18 + 8) + 8));
      pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218680);
      return *(undefined4 *)(local_18 + 0x40);
    }
    iVar1 = FUN_00296e9b(local_20,local_2c);
    if (iVar1 == 0) {
      pthread_mutex_lock((pthread_mutex_t *)&DAT_01218680);
      **(undefined4 **)(local_18 + 8) = 0;
      *(int *)(*(long *)(local_18 + 8) + 4) = *(int *)(*(long *)(local_18 + 8) + 4) + -1;
      pthread_sigmask(2,&local_f8,(__sigset_t *)0x0);
      pthread_cond_signal((pthread_cond_t *)(*(long *)(local_18 + 8) + 8));
      pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218680);
      *(undefined4 *)(local_18 + 0x40) = 3;
      return *(undefined4 *)(local_18 + 0x40);
    }
    if (local_2c == 0) {
      pthread_mutex_lock((pthread_mutex_t *)&DAT_01218680);
      **(undefined4 **)(local_18 + 8) = 0;
      *(int *)(*(long *)(local_18 + 8) + 4) = *(int *)(*(long *)(local_18 + 8) + 4) + -1;
      pthread_sigmask(2,&local_f8,(__sigset_t *)0x0);
      pthread_cond_signal((pthread_cond_t *)(*(long *)(local_18 + 8) + 8));
      pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218680);
      return 0;
    }
    if ((param_7 == 0) && (param_8 == 0)) {
      pthread_mutex_lock((pthread_mutex_t *)&DAT_01218680);
      **(undefined4 **)(local_18 + 8) = 0;
      *(int *)(*(long *)(local_18 + 8) + 4) = *(int *)(*(long *)(local_18 + 8) + 4) + -1;
      pthread_sigmask(2,&local_f8,(__sigset_t *)0x0);
      pthread_cond_signal((pthread_cond_t *)(*(long *)(local_18 + 8) + 8));
      pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218680);
      *(undefined4 *)(local_18 + 0x40) = 5;
      return *(undefined4 *)(local_18 + 0x40);
    }
    *local_20 = 1;
    do {
      while( true ) {
        local_68 = DAT_01218830;
        local_60 = DAT_01218838;
        local_58 = DAT_01218840;
        local_48 = 0;
        local_40 = FUN_00295ffe;
        iVar1 = FUN_00296d91(local_20);
        if (iVar1 == 0) {
          pthread_mutex_lock((pthread_mutex_t *)&DAT_01218680);
          **(undefined4 **)(local_18 + 8) = 0;
          *(int *)(*(long *)(local_18 + 8) + 4) = *(int *)(*(long *)(local_18 + 8) + 4) + -1;
          pthread_sigmask(2,&local_f8,(__sigset_t *)0x0);
          pthread_cond_signal((pthread_cond_t *)(*(long *)(local_18 + 8) + 8));
          pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218680);
          return *(undefined4 *)(local_18 + 0x40);
        }
        iVar1 = FUN_00295a5b(local_20,local_78);
        if (iVar1 != 0) break;
        if (*(int *)(local_18 + 0x40) != 0) {
          pthread_mutex_lock((pthread_mutex_t *)&DAT_01218680);
          **(undefined4 **)(local_18 + 8) = 0;
          *(int *)(*(long *)(local_18 + 8) + 4) = *(int *)(*(long *)(local_18 + 8) + 4) + -1;
          pthread_sigmask(2,&local_f8,(__sigset_t *)0x0);
          pthread_cond_signal((pthread_cond_t *)(*(long *)(local_18 + 8) + 8));
          pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218680);
          return *(undefined4 *)(local_18 + 0x40);
        }
      }
    } while (local_30 != local_78[0]);
    FUN_00295d73(local_78,local_18 + 0x40);
    if (*(int *)(local_18 + 0x40) == 0) break;
    iVar1 = local_c + -1;
    bVar2 = local_c == 0;
    local_c = iVar1;
    if ((bVar2) ||
       (iVar1 = (**(code **)(*(long *)(*local_180 + 0x38) + 0x18))(*local_180,local_78), iVar1 == 0)
       ) goto LAB_00294923;
  }
  iVar1 = (**(code **)(*(long *)(*local_180 + 0x38) + 0x10))(*local_180,&local_68);
  if (iVar1 == 0) {
    *(undefined4 *)(local_18 + 0x40) = 7;
    *(undefined4 *)(local_18 + 0x44) = 6;
  }
  else {
    iVar1 = (**(code **)(*(long *)(*local_180 + 0x38) + 0x30))(*local_180,local_20,param_5,param_6);
    if ((iVar1 == 0) && (*(int *)(local_18 + 0x40) == 0)) {
      *(undefined4 *)(local_18 + 0x40) = 2;
    }
  }
  if (local_60 != 0) {
    *local_20 = 2;
    FUN_0029579d(local_20,&local_68);
  }
LAB_00294923:
  pthread_mutex_lock((pthread_mutex_t *)&DAT_01218680);
  **(undefined4 **)(local_18 + 8) = 0;
  *(int *)(*(long *)(local_18 + 8) + 4) = *(int *)(*(long *)(local_18 + 8) + 4) + -1;
  pthread_sigmask(2,&local_f8,(__sigset_t *)0x0);
  pthread_cond_signal((pthread_cond_t *)(*(long *)(local_18 + 8) + 8));
  pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218680);
  return *(undefined4 *)(local_18 + 0x40);
}


// ===== 00294996 FUN_00294996 =====

void FUN_00294996(long param_1,undefined8 *param_2)

{
  long lVar1;
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("cl != ((void *)0)",
                  "/nv/p4/tools/unix/hosts/Linux-x86/targets/build-scripts/libtirpc-1.3.5/src/clnt_vc.c"
                  ,0x1d9,"clnt_vc_geterr");
  }
  if (param_2 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("errp != ((void *)0)",
                  "/nv/p4/tools/unix/hosts/Linux-x86/targets/build-scripts/libtirpc-1.3.5/src/clnt_vc.c"
                  ,0x1da,"clnt_vc_geterr");
  }
  lVar1 = *(long *)(param_1 + 0x10);
  *param_2 = *(undefined8 *)(lVar1 + 0x40);
  *(undefined4 *)(param_2 + 1) = *(undefined4 *)(lVar1 + 0x48);
  return;
}


// ===== 00294a16 FUN_00294a16 =====

undefined4 FUN_00294a16(long param_1,code *param_2,undefined8 param_3)

{
  sigset_t local_128;
  __sigset_t local_a8;
  undefined4 local_1c;
  undefined4 *local_18;
  long local_10;
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("cl != ((void *)0)",
                  "/nv/p4/tools/unix/hosts/Linux-x86/targets/build-scripts/libtirpc-1.3.5/src/clnt_vc.c"
                  ,0x1ec,"clnt_vc_freeres");
  }
  local_10 = *(long *)(param_1 + 0x10);
  local_18 = (undefined4 *)(local_10 + 0x68);
  sigfillset(&local_128);
  pthread_sigmask(2,&local_128,&local_a8);
  pthread_mutex_lock((pthread_mutex_t *)&DAT_01218680);
  *(int *)(*(long *)(local_10 + 8) + 4) = *(int *)(*(long *)(local_10 + 8) + 4) + 1;
  while (**(int **)(local_10 + 8) != 0) {
    pthread_cond_wait((pthread_cond_t *)(*(long *)(local_10 + 8) + 8),
                      (pthread_mutex_t *)&DAT_01218680);
  }
  *local_18 = 2;
  local_1c = (*param_2)(local_18,param_3);
  *(int *)(*(long *)(local_10 + 8) + 4) = *(int *)(*(long *)(local_10 + 8) + 4) + -1;
  pthread_sigmask(2,&local_a8,(__sigset_t *)0x0);
  pthread_cond_signal((pthread_cond_t *)(*(long *)(local_10 + 8) + 8));
  pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218680);
  return local_1c;
}


// ===== 00294b70 FUN_00294b70 =====

void FUN_00294b70(void)

{
  return;
}


// ===== 00294b7b FUN_00294b7b =====

undefined8 FUN_00294b7b(long param_1,int param_2,uint32_t *param_3)

{
  undefined8 uVar1;
  int iVar2;
  uint32_t uVar3;
  sigset_t local_118;
  __sigset_t local_98;
  uint32_t *local_18;
  uint32_t *local_10;
  
  local_10 = param_3;
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("cl != ((void *)0)",
                  "/nv/p4/tools/unix/hosts/Linux-x86/targets/build-scripts/libtirpc-1.3.5/src/clnt_vc.c"
                  ,0x215,"clnt_vc_control");
  }
  local_18 = *(uint32_t **)(param_1 + 0x10);
  sigfillset(&local_118);
  pthread_sigmask(2,&local_118,&local_98);
  pthread_mutex_lock((pthread_mutex_t *)&DAT_01218680);
  *(int *)(*(long *)(local_18 + 2) + 4) = *(int *)(*(long *)(local_18 + 2) + 4) + 1;
  while (**(int **)(local_18 + 2) != 0) {
    pthread_cond_wait((pthread_cond_t *)(*(long *)(local_18 + 2) + 8),
                      (pthread_mutex_t *)&DAT_01218680);
  }
  **(undefined4 **)(local_18 + 2) = 1;
  pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218680);
  if (param_2 == 8) {
    local_18[4] = 1;
    pthread_mutex_lock((pthread_mutex_t *)&DAT_01218680);
    **(undefined4 **)(local_18 + 2) = 0;
    *(int *)(*(long *)(local_18 + 2) + 4) = *(int *)(*(long *)(local_18 + 2) + 4) + -1;
    pthread_sigmask(2,&local_98,(__sigset_t *)0x0);
    pthread_cond_signal((pthread_cond_t *)(*(long *)(local_18 + 2) + 8));
    pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218680);
    return 1;
  }
  if (param_2 == 9) {
    local_18[4] = 0;
    pthread_mutex_lock((pthread_mutex_t *)&DAT_01218680);
    **(undefined4 **)(local_18 + 2) = 0;
    *(int *)(*(long *)(local_18 + 2) + 4) = *(int *)(*(long *)(local_18 + 2) + 4) + -1;
    pthread_sigmask(2,&local_98,(__sigset_t *)0x0);
    pthread_cond_signal((pthread_cond_t *)(*(long *)(local_18 + 2) + 8));
    pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218680);
    return 1;
  }
  if (param_3 != (uint32_t *)0x0) {
    switch(param_2) {
    default:
      pthread_mutex_lock((pthread_mutex_t *)&DAT_01218680);
      **(undefined4 **)(local_18 + 2) = 0;
      *(int *)(*(long *)(local_18 + 2) + 4) = *(int *)(*(long *)(local_18 + 2) + 4) + -1;
      pthread_sigmask(2,&local_98,(__sigset_t *)0x0);
      pthread_cond_signal((pthread_cond_t *)(*(long *)(local_18 + 2) + 8));
      pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218680);
      return 0;
    case 1:
      iVar2 = FUN_00295691(param_3);
      if (iVar2 != 0) {
        pthread_mutex_lock((pthread_mutex_t *)&DAT_01218680);
        **(undefined4 **)(local_18 + 2) = 0;
        *(int *)(*(long *)(local_18 + 2) + 4) = *(int *)(*(long *)(local_18 + 2) + 4) + -1;
        pthread_sigmask(2,&local_98,(__sigset_t *)0x0);
        pthread_cond_signal((pthread_cond_t *)(*(long *)(local_18 + 2) + 8));
        pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218680);
        return 0;
      }
      uVar1 = *(undefined8 *)(local_10 + 2);
      *(undefined8 *)(local_18 + 6) = *(undefined8 *)local_10;
      *(undefined8 *)(local_18 + 8) = uVar1;
      local_18[10] = 1;
      break;
    case 2:
      uVar1 = *(undefined8 *)(local_18 + 8);
      *(undefined8 *)local_10 = *(undefined8 *)(local_18 + 6);
      *(undefined8 *)(local_10 + 2) = uVar1;
      break;
    case 3:
      memcpy(param_3,*(void **)(local_18 + 0xe),(ulong)local_18[0xd]);
      break;
    case 6:
      *param_3 = *local_18;
      break;
    case 7:
      uVar1 = *(undefined8 *)(local_18 + 0xe);
      *(undefined8 *)param_3 = *(undefined8 *)(local_18 + 0xc);
      *(undefined8 *)(param_3 + 2) = uVar1;
      break;
    case 10:
      uVar3 = ntohl(local_18[0x13]);
      *param_3 = uVar3;
      break;
    case 0xb:
      uVar3 = htonl(*param_3 + 1);
      local_18[0x13] = uVar3;
      break;
    case 0xc:
      uVar3 = ntohl(local_18[0x17]);
      *param_3 = uVar3;
      break;
    case 0xd:
      uVar3 = htonl(*param_3);
      local_18[0x17] = uVar3;
      break;
    case 0xe:
      uVar3 = ntohl(local_18[0x16]);
      *param_3 = uVar3;
      break;
    case 0xf:
      uVar3 = htonl(*param_3);
      local_18[0x16] = uVar3;
      break;
    case 0x10:
      pthread_mutex_lock((pthread_mutex_t *)&DAT_01218680);
      **(undefined4 **)(local_18 + 2) = 0;
      *(int *)(*(long *)(local_18 + 2) + 4) = *(int *)(*(long *)(local_18 + 2) + 4) + -1;
      pthread_sigmask(2,&local_98,(__sigset_t *)0x0);
      pthread_cond_signal((pthread_cond_t *)(*(long *)(local_18 + 2) + 8));
      pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218680);
      return 0;
    }
    pthread_mutex_lock((pthread_mutex_t *)&DAT_01218680);
    **(undefined4 **)(local_18 + 2) = 0;
    *(int *)(*(long *)(local_18 + 2) + 4) = *(int *)(*(long *)(local_18 + 2) + 4) + -1;
    pthread_sigmask(2,&local_98,(__sigset_t *)0x0);
    pthread_cond_signal((pthread_cond_t *)(*(long *)(local_18 + 2) + 8));
    pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218680);
    return 1;
  }
  pthread_mutex_lock((pthread_mutex_t *)&DAT_01218680);
  **(undefined4 **)(local_18 + 2) = 0;
  *(int *)(*(long *)(local_18 + 2) + 4) = *(int *)(*(long *)(local_18 + 2) + 4) + -1;
  pthread_sigmask(2,&local_98,(__sigset_t *)0x0);
  pthread_cond_signal((pthread_cond_t *)(*(long *)(local_18 + 2) + 8));
  pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218680);
  return 0;
}


// ===== 002951e3 FUN_002951e3 =====

void FUN_002951e3(void *param_1)

{
  sigset_t local_128;
  __sigset_t local_a8;
  int *local_20;
  int local_14;
  int *local_10;
  
  if (param_1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("cl != ((void *)0)",
                  "/nv/p4/tools/unix/hosts/Linux-x86/targets/build-scripts/libtirpc-1.3.5/src/clnt_vc.c"
                  ,0x28d,"clnt_vc_destroy");
  }
  local_10 = *(int **)((long)param_1 + 0x10);
  local_14 = *local_10;
  local_20 = *(int **)(local_10 + 2);
  sigfillset(&local_128);
  pthread_sigmask(2,&local_128,&local_a8);
  pthread_mutex_lock((pthread_mutex_t *)&DAT_01218680);
  while (0 < local_20[1]) {
    if (*local_20 == 0) {
      pthread_cond_signal((pthread_cond_t *)(local_20 + 2));
    }
    pthread_cond_wait((pthread_cond_t *)(local_20 + 2),(pthread_mutex_t *)&DAT_01218680);
  }
  if ((local_10[4] != 0) && (*local_10 != -1)) {
    close(*local_10);
  }
  if (*(long *)(*(long *)(local_10 + 0x1c) + 0x38) != 0) {
    (**(code **)(*(long *)(local_10 + 0x1c) + 0x38))(local_10 + 0x1a);
  }
  if (*(long *)(local_10 + 0xe) != 0) {
    free(*(void **)(local_10 + 0xe));
  }
  free(local_10);
  if ((*(long *)((long)param_1 + 0x18) != 0) && (**(char **)((long)param_1 + 0x18) != '\0')) {
    free(*(void **)((long)param_1 + 0x18));
  }
  if ((*(long *)((long)param_1 + 0x20) != 0) && (**(char **)((long)param_1 + 0x20) != '\0')) {
    free(*(void **)((long)param_1 + 0x20));
  }
  free(param_1);
  pthread_cond_signal((pthread_cond_t *)(local_20 + 2));
  FUN_00293b18(local_14,local_20,DAT_012185d8);
  pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218680);
  pthread_sigmask(2,&local_a8,(__sigset_t *)0x0);
  return;
}


// ===== 002953fe FUN_002953fe =====

int FUN_002953fe(int *param_1,void *param_2,int param_3)

{
  int iVar1;
  ssize_t sVar2;
  int *piVar3;
  pollfd local_1c;
  int local_14;
  int *local_10;
  
  local_14 = (int)(*(long *)(param_1 + 8) / 1000) + (int)*(undefined8 *)(param_1 + 6) * 1000;
  if (param_3 == 0) {
    iVar1 = 0;
  }
  else {
    local_1c.fd = *param_1;
    local_1c.events = 1;
    local_10 = param_1;
    do {
      iVar1 = poll(&local_1c,1,local_14);
      if (iVar1 != -1) {
        if (iVar1 == 0) {
          local_10[0x10] = 5;
          return -1;
        }
        sVar2 = read(*local_10,param_2,(long)param_3);
        iVar1 = (int)sVar2;
        if (iVar1 != -1) {
          if (iVar1 != 0) {
            return iVar1;
          }
          local_10[0x11] = 0x68;
          local_10[0x10] = 4;
          return -1;
        }
        piVar3 = __errno_location();
        local_10[0x11] = *piVar3;
        local_10[0x10] = 4;
        return -1;
      }
      piVar3 = __errno_location();
    } while (*piVar3 == 4);
    local_10[0x10] = 4;
    piVar3 = __errno_location();
    local_10[0x11] = *piVar3;
    iVar1 = -1;
  }
  return iVar1;
}


// ===== 0029553b FUN_0029553b =====

int FUN_0029553b(int *param_1,void *param_2,int param_3)

{
  int iVar1;
  ssize_t sVar2;
  int *piVar3;
  void *local_38;
  int local_c;
  
  local_38 = param_2;
  local_c = param_3;
  while( true ) {
    if (local_c < 1) {
      return param_3;
    }
    sVar2 = write(*param_1,local_38,(long)local_c);
    iVar1 = (int)sVar2;
    if (iVar1 == -1) break;
    local_c = local_c - iVar1;
    local_38 = (void *)((long)local_38 + (long)iVar1);
  }
  piVar3 = __errno_location();
  param_1[0x11] = *piVar3;
  param_1[0x10] = 3;
  return -1;
}


// ===== 002955c2 FUN_002955c2 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * FUN_002955c2(void)

{
  sigset_t local_108;
  __sigset_t local_88;
  
  sigfillset(&local_108);
  pthread_sigmask(2,&local_108,&local_88);
  pthread_mutex_lock((pthread_mutex_t *)&DAT_012186c0);
  if (DAT_01218600 == (code *)0x0) {
    DAT_01218600 = FUN_002941ef;
    _DAT_01218608 = FUN_00294b70;
    _DAT_01218610 = FUN_00294996;
    _DAT_01218618 = FUN_00294a16;
    _DAT_01218620 = FUN_002951e3;
    _DAT_01218628 = FUN_00294b7b;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&DAT_012186c0);
  pthread_sigmask(2,&local_88,(__sigset_t *)0x0);
  return &DAT_01218600;
}


// ===== 00295691 FUN_00295691 =====

undefined8 FUN_00295691(long *param_1)

{
  undefined8 uVar1;
  
  if ((((*param_1 < 0) || (100000000 < *param_1)) || (param_1[1] < 0)) || (1000000 < param_1[1])) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 002956df FUN_002956df =====

undefined * FUN_002956df(void)

{
  int iVar1;
  undefined *__pointer;
  
  pthread_mutex_lock((pthread_mutex_t *)&DAT_01218700);
  if (DAT_0038078c == 0xffffffff) {
    pthread_key_create(&DAT_0038078c,(__destr_function *)PTR_free_0032ef38);
  }
  pthread_mutex_unlock((pthread_mutex_t *)&DAT_01218700);
  __pointer = pthread_getspecific(DAT_0038078c);
  if (__pointer == (undefined *)0x0) {
    __pointer = malloc(0x10);
    if ((__pointer == (undefined *)0x0) ||
       (iVar1 = pthread_setspecific(DAT_0038078c,__pointer), iVar1 != 0)) {
      if (__pointer != (undefined *)0x0) {
        free(__pointer);
      }
      __pointer = &DAT_01218790;
    }
    else {
      memset(__pointer,0,0x10);
    }
  }
  return __pointer;
}


// ===== 0029579d FUN_0029579d =====

undefined8 FUN_0029579d(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("xdrs != ((void *)0)",
                  "/nv/p4/tools/unix/hosts/Linux-x86/targets/build-scripts/libtirpc-1.3.5/src/rpc_prot.c"
                  ,0x41,"xdr_opaque_auth");
  }
  if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("ap != ((void *)0)",
                  "/nv/p4/tools/unix/hosts/Linux-x86/targets/build-scripts/libtirpc-1.3.5/src/rpc_prot.c"
                  ,0x42,"xdr_opaque_auth");
  }
  iVar1 = FUN_002961d1(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00296311(param_1,param_2 + 8,param_2 + 0x10,400);
  }
  return uVar2;
}


// ===== 0029583a FUN_0029583a =====

undefined8 FUN_0029583a(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("xdrs != ((void *)0)",
                  "/nv/p4/tools/unix/hosts/Linux-x86/targets/build-scripts/libtirpc-1.3.5/src/rpc_prot.c"
                  ,100,"xdr_accepted_reply");
  }
  if (param_2 != 0) {
    iVar1 = FUN_0029579d(param_1,param_2);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      iVar1 = FUN_002961d1(param_1,param_2 + 0x18);
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else {
        switch(*(undefined4 *)(param_2 + 0x18)) {
        case 0:
          uVar2 = (**(code **)(param_2 + 0x28))(param_1,*(undefined8 *)(param_2 + 0x20));
          break;
        default:
          uVar2 = 1;
          break;
        case 2:
          iVar1 = FUN_00296139(param_1,param_2 + 0x20);
          if (iVar1 == 0) {
            uVar2 = 0;
          }
          else {
            uVar2 = FUN_00296139(param_1,param_2 + 0x24);
          }
        }
      }
    }
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("ar != ((void *)0)",
                "/nv/p4/tools/unix/hosts/Linux-x86/targets/build-scripts/libtirpc-1.3.5/src/rpc_prot.c"
                ,0x65,"xdr_accepted_reply");
}


// ===== 00295975 FUN_00295975 =====

undefined8 FUN_00295975(long param_1,int *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("xdrs != ((void *)0)",
                  "/nv/p4/tools/unix/hosts/Linux-x86/targets/build-scripts/libtirpc-1.3.5/src/rpc_prot.c"
                  ,0x88,"xdr_rejected_reply");
  }
  if (param_2 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("rr != ((void *)0)",
                  "/nv/p4/tools/unix/hosts/Linux-x86/targets/build-scripts/libtirpc-1.3.5/src/rpc_prot.c"
                  ,0x89,"xdr_rejected_reply");
  }
  iVar1 = FUN_002961d1(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else if (*param_2 == 0) {
    iVar1 = FUN_00296139(param_1,param_2 + 1);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_00296139(param_1,param_2 + 2);
    }
  }
  else if (*param_2 == 1) {
    uVar2 = FUN_002961d1(param_1,param_2 + 1);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 00295a5b FUN_00295a5b =====

undefined8 FUN_00295a5b(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("xdrs != ((void *)0)",
                  "/nv/p4/tools/unix/hosts/Linux-x86/targets/build-scripts/libtirpc-1.3.5/src/rpc_prot.c"
                  ,0xa9,"xdr_replymsg");
  }
  if (param_2 != 0) {
    iVar1 = FUN_00296139(param_1,param_2);
    if (((iVar1 != 0) && (iVar1 = FUN_002961d1(param_1,param_2 + 4), iVar1 != 0)) &&
       (*(int *)(param_2 + 4) == 1)) {
      uVar2 = FUN_00296473(param_1,param_2 + 8,param_2 + 0x10,&DAT_00329760,0);
      return uVar2;
    }
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("rmsg != ((void *)0)",
                "/nv/p4/tools/unix/hosts/Linux-x86/targets/build-scripts/libtirpc-1.3.5/src/rpc_prot.c"
                ,0xaa,"xdr_replymsg");
}


// ===== 00295b27 FUN_00295b27 =====

undefined8 FUN_00295b27(int *param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("xdrs != ((void *)0)",
                  "/nv/p4/tools/unix/hosts/Linux-x86/targets/build-scripts/libtirpc-1.3.5/src/rpc_prot.c"
                  ,0xc2,"xdr_callhdr");
  }
  if (param_2 != 0) {
    *(undefined4 *)(param_2 + 4) = 0;
    *(undefined4 *)(param_2 + 8) = 2;
    if ((((*param_1 == 0) && (iVar1 = FUN_00296139(param_1,param_2), iVar1 != 0)) &&
        (iVar1 = FUN_002961d1(param_1,param_2 + 4), iVar1 != 0)) &&
       ((iVar1 = FUN_00296139(param_1,param_2 + 8), iVar1 != 0 &&
        (iVar1 = FUN_00296139(param_1,param_2 + 0xc), iVar1 != 0)))) {
      uVar2 = FUN_00296139(param_1,param_2 + 0x10);
      return uVar2;
    }
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("cmsg != ((void *)0)",
                "/nv/p4/tools/unix/hosts/Linux-x86/targets/build-scripts/libtirpc-1.3.5/src/rpc_prot.c"
                ,0xc3,"xdr_callhdr");
}


// ===== 00295c2f FUN_00295c2f =====

void FUN_00295c2f(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    switch(param_1) {
    case 0:
      *param_2 = 0;
      break;
    case 1:
      *param_2 = 8;
      break;
    case 2:
      *param_2 = 9;
      break;
    case 3:
      *param_2 = 10;
      break;
    case 4:
      *param_2 = 0xb;
      break;
    case 5:
      *param_2 = 0xc;
      break;
    default:
      *param_2 = 0x10;
      param_2[1] = 0;
      param_2[2] = param_1;
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("error != ((void *)0)",
                "/nv/p4/tools/unix/hosts/Linux-x86/targets/build-scripts/libtirpc-1.3.5/src/rpc_prot.c"
                ,0xd9,"accepted");
}


// ===== 00295cf7 FUN_00295cf7 =====

void FUN_00295cf7(int param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("error != ((void *)0)",
                  "/nv/p4/tools/unix/hosts/Linux-x86/targets/build-scripts/libtirpc-1.3.5/src/rpc_prot.c"
                  ,0x102,"rejected");
  }
  if (param_1 == 0) {
    *param_2 = 6;
  }
  else if (param_1 == 1) {
    *param_2 = 7;
  }
  else {
    *param_2 = 0x10;
    param_2[1] = 1;
    param_2[2] = param_1;
  }
  return;
}


// ===== 00295d73 FUN_00295d73 =====

void FUN_00295d73(long param_1,int *param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("msg != ((void *)0)",
                  "/nv/p4/tools/unix/hosts/Linux-x86/targets/build-scripts/libtirpc-1.3.5/src/rpc_prot.c"
                  ,0x11d,"_seterr_reply");
  }
  if (param_2 != (int *)0x0) {
    if (*(int *)(param_1 + 8) == 0) {
      if (*(int *)(param_1 + 0x28) == 0) {
        *param_2 = 0;
        return;
      }
      FUN_00295c2f(*(undefined4 *)(param_1 + 0x28),param_2);
    }
    else if (*(int *)(param_1 + 8) == 1) {
      FUN_00295cf7(*(undefined4 *)(param_1 + 0x10),param_2);
    }
    else {
      *param_2 = 0x10;
      param_2[1] = *(int *)(param_1 + 8);
    }
    iVar1 = *param_2;
    if (iVar1 == 7) {
      param_2[1] = *(int *)(param_1 + 0x14);
    }
    else if (iVar1 == 9) {
      param_2[1] = *(int *)(param_1 + 0x30);
      param_2[2] = *(int *)(param_1 + 0x34);
    }
    else if (iVar1 == 6) {
      param_2[1] = *(int *)(param_1 + 0x14);
      param_2[2] = *(int *)(param_1 + 0x18);
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("error != ((void *)0)",
                "/nv/p4/tools/unix/hosts/Linux-x86/targets/build-scripts/libtirpc-1.3.5/src/rpc_prot.c"
                ,0x11e,"_seterr_reply");
}


// ===== 00295ea8 FUN_00295ea8 =====

int FUN_00295ea8(undefined8 param_1,int param_2,int param_3)

{
  int local_c;
  
  if (param_2 == 6) {
    local_c = 0x10000;
  }
  else if (param_2 == 0x11) {
    local_c = 0x2260;
  }
  else {
    local_c = 9000;
  }
  if ((param_3 != 0) && (local_c = 0x40000, param_3 < 0x40001)) {
    local_c = param_3;
  }
  return local_c;
}


// ===== 00295efc FUN_00295efc =====

undefined8 FUN_00295efc(int param_1,uint *param_2)

{
  int iVar1;
  undefined8 uVar2;
  sockaddr local_98 [8];
  uint local_14;
  socklen_t local_10;
  uint local_c;
  
  local_10 = 0x80;
  iVar1 = getsockname(param_1,local_98,&local_10);
  if (iVar1 < 0) {
    uVar2 = 0;
  }
  else {
    param_2[3] = local_10;
    local_10 = 4;
    iVar1 = getsockopt(param_1,1,3,&local_14,&local_10);
    if (iVar1 < 0) {
      uVar2 = 0;
    }
    else {
      if (local_98[0].sa_family == 1) {
        local_c = 0;
      }
      else if (local_14 == 1) {
        local_c = 6;
      }
      else {
        if (local_14 != 2) {
          return 0;
        }
        local_c = 0x11;
      }
      *param_2 = (uint)local_98[0].sa_family;
      param_2[1] = local_c;
      param_2[2] = local_14;
      uVar2 = 1;
    }
  }
  return uVar2;
}


// ===== 00295ffe FUN_00295ffe =====

undefined8 FUN_00295ffe(void)

{
  return 1;
}


// ===== 00296009 FUN_00296009 =====

undefined8 FUN_00296009(int *param_1,int *param_2)

{
  int iVar1;
  undefined8 uVar2;
  long local_10;
  
  iVar1 = *param_1;
  if (iVar1 == 1) {
    iVar1 = (*(code *)**(undefined8 **)(param_1 + 2))(param_1,&local_10);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      *param_2 = (int)local_10;
      uVar2 = 1;
    }
  }
  else if (iVar1 == 0) {
    local_10 = (long)*param_2;
    uVar2 = (**(code **)(*(long *)(param_1 + 2) + 8))(param_1,&local_10);
  }
  else if (iVar1 == 2) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 002960a1 FUN_002960a1 =====

undefined8 FUN_002960a1(int *param_1,uint *param_2)

{
  int iVar1;
  undefined8 uVar2;
  ulong local_10;
  
  iVar1 = *param_1;
  if (iVar1 == 1) {
    iVar1 = (*(code *)**(undefined8 **)(param_1 + 2))(param_1,&local_10);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      *param_2 = (uint)local_10;
      uVar2 = 1;
    }
  }
  else if (iVar1 == 0) {
    local_10 = (ulong)*param_2;
    uVar2 = (**(code **)(*(long *)(param_1 + 2) + 8))(param_1,&local_10);
  }
  else if (iVar1 == 2) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 00296139 FUN_00296139 =====

undefined8 FUN_00296139(int *param_1,uint *param_2)

{
  int iVar1;
  undefined8 uVar2;
  ulong local_10;
  
  iVar1 = *param_1;
  if (iVar1 == 1) {
    iVar1 = (*(code *)**(undefined8 **)(param_1 + 2))(param_1,&local_10);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      *param_2 = (uint)local_10;
      uVar2 = 1;
    }
  }
  else if (iVar1 == 0) {
    local_10 = (ulong)*param_2;
    uVar2 = (**(code **)(*(long *)(param_1 + 2) + 8))(param_1,&local_10);
  }
  else if (iVar1 == 2) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 002961d1 FUN_002961d1 =====

void FUN_002961d1(undefined8 param_1,undefined8 param_2)

{
  FUN_00296009(param_1,param_2);
  return;
}


// ===== 002961f6 FUN_002961f6 =====

undefined8 FUN_002961f6(int *param_1,undefined8 param_2,uint param_3)

{
  int iVar1;
  undefined8 uVar2;
  uint local_c;
  
  if (param_3 == 0) {
    uVar2 = 1;
  }
  else {
    local_c = param_3 & 3;
    if (local_c != 0) {
      local_c = 4 - local_c;
    }
    if (*param_1 == 1) {
      iVar1 = (**(code **)(*(long *)(param_1 + 2) + 0x10))(param_1,param_2,param_3);
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else if (local_c == 0) {
        uVar2 = 1;
      }
      else {
        uVar2 = (**(code **)(*(long *)(param_1 + 2) + 0x10))(param_1,&DAT_01218770,local_c);
      }
    }
    else if (*param_1 == 0) {
      iVar1 = (**(code **)(*(long *)(param_1 + 2) + 0x18))(param_1,param_2,param_3);
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else if (local_c == 0) {
        uVar2 = 1;
      }
      else {
        uVar2 = (**(code **)(*(long *)(param_1 + 2) + 0x18))(param_1,&DAT_002f63c6,local_c);
      }
    }
    else if (*param_1 == 2) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


// ===== 00296311 FUN_00296311 =====

int FUN_00296311(int *param_1,undefined8 *param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  void *local_10;
  
  local_10 = (void *)*param_2;
  bVar3 = false;
  iVar2 = FUN_002960a1(param_1,param_3);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    uVar1 = *param_3;
    if ((param_4 < uVar1) && (*param_1 != 2)) {
      iVar2 = 0;
    }
    else {
      iVar2 = *param_1;
      if (iVar2 == 1) {
        if (uVar1 == 0) {
          return 1;
        }
        bVar3 = local_10 == (void *)0x0;
        if (bVar3) {
          local_10 = calloc(1,(ulong)uVar1);
          *param_2 = local_10;
        }
        if (local_10 == (void *)0x0) {
          warnx("xdr_bytes: out of memory");
          return 0;
        }
      }
      else if (iVar2 != 0) {
        if (iVar2 != 2) {
          return 0;
        }
        if (local_10 != (void *)0x0) {
          free(local_10);
          *param_2 = 0;
        }
        return 1;
      }
      iVar2 = FUN_002961f6(param_1,local_10,uVar1);
      if (((*param_1 == 1) && (iVar2 == 0)) && (bVar3)) {
        free(local_10);
        *param_2 = 0;
      }
    }
  }
  return iVar2;
}


// ===== 00296473 FUN_00296473 =====

undefined8
FUN_00296473(undefined8 param_1,int *param_2,undefined8 param_3,int *param_4,code *param_5)

{
  int iVar1;
  undefined8 uVar2;
  int *local_38;
  
  iVar1 = FUN_002961d1(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    for (local_38 = param_4; *(long *)(local_38 + 2) != 0; local_38 = local_38 + 4) {
      if (*param_2 == *local_38) {
        uVar2 = (**(code **)(local_38 + 2))(param_1,param_3);
        return uVar2;
      }
    }
    if (param_5 == (code *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (*param_5)(param_1,param_3);
    }
  }
  return uVar2;
}


// ===== 0029651d FUN_0029651d =====

void FUN_0029651d(long param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6)

{
  uint uVar1;
  uint uVar2;
  undefined8 *__ptr;
  void *pvVar3;
  
  __ptr = calloc(1,0x98);
  if (__ptr == (undefined8 *)0x0) {
    warnx("xdrrec_create: out of memory");
  }
  else {
    uVar1 = FUN_002976eb(param_2);
    *(uint *)((long)__ptr + 0x6c) = uVar1;
    pvVar3 = calloc(1,(ulong)*(uint *)((long)__ptr + 0x6c));
    __ptr[2] = pvVar3;
    if (__ptr[2] == 0) {
      warnx("xdrrec_create: out of memory");
      free(__ptr);
    }
    else {
      uVar2 = FUN_002976eb(param_3);
      *(uint *)(__ptr + 0xe) = uVar2;
      pvVar3 = calloc(1,(ulong)uVar2);
      __ptr[9] = pvVar3;
      if (__ptr[9] == 0) {
        warnx("xdrrec_create: out of memory");
        free((void *)__ptr[2]);
        free(__ptr);
      }
      else {
        *(undefined ***)(param_1 + 8) = &PTR_FUN_003297a0;
        *(undefined8 **)(param_1 + 0x18) = __ptr;
        *__ptr = param_4;
        __ptr[7] = param_5;
        __ptr[1] = param_6;
        __ptr[4] = __ptr[2];
        __ptr[3] = __ptr[4];
        __ptr[5] = __ptr[2];
        __ptr[3] = __ptr[3] + 4;
        __ptr[4] = __ptr[4] + (ulong)uVar1;
        *(undefined4 *)(__ptr + 6) = 0;
        __ptr[8] = (ulong)uVar2;
        __ptr[0xb] = __ptr[9];
        __ptr[0xb] = __ptr[0xb] + (ulong)uVar2;
        __ptr[10] = __ptr[0xb];
        __ptr[0xc] = 0;
        *(undefined4 *)(__ptr + 0xd) = 1;
        *(undefined4 *)(__ptr + 0xf) = 0;
        *(undefined4 *)(__ptr + 0x11) = 0;
        __ptr[0x10] = (long)__ptr + 0x7c;
        *(undefined4 *)((long)__ptr + 0x74) = 0;
        *(undefined4 *)((long)__ptr + 0x8c) = 0;
        *(undefined4 *)(__ptr + 0x12) = 0;
      }
    }
  }
  return;
}


// ===== 00296793 FUN_00296793 =====

undefined8 FUN_00296793(long param_1,ulong *param_2)

{
  uint32_t uVar1;
  int iVar2;
  uint32_t local_1c;
  uint32_t *local_18;
  long local_10;
  
  local_10 = *(long *)(param_1 + 0x18);
  local_18 = *(uint32_t **)(local_10 + 0x50);
  if ((*(ulong *)(local_10 + 0x60) < 4) ||
     ((ulong)(*(long *)(local_10 + 0x58) - (long)local_18) < 4)) {
    iVar2 = FUN_0029692d(param_1,&local_1c,4);
    if (iVar2 == 0) {
      return 0;
    }
    uVar1 = ntohl(local_1c);
    *param_2 = (ulong)uVar1;
  }
  else {
    uVar1 = ntohl(*local_18);
    *param_2 = (ulong)uVar1;
    *(long *)(local_10 + 0x60) = *(long *)(local_10 + 0x60) + -4;
    *(long *)(local_10 + 0x50) = *(long *)(local_10 + 0x50) + 4;
  }
  return 1;
}


// ===== 00296864 FUN_00296864 =====

undefined8 FUN_00296864(long param_1,undefined8 *param_2)

{
  long lVar1;
  int iVar2;
  uint32_t uVar3;
  uint32_t *local_10;
  
  lVar1 = *(long *)(param_1 + 0x18);
  local_10 = *(uint32_t **)(lVar1 + 0x18);
  *(long *)(lVar1 + 0x18) = *(long *)(lVar1 + 0x18) + 4;
  if (*(ulong *)(lVar1 + 0x20) < *(ulong *)(lVar1 + 0x18)) {
    *(long *)(lVar1 + 0x18) = *(long *)(lVar1 + 0x18) + -4;
    *(undefined4 *)(lVar1 + 0x30) = 1;
    iVar2 = FUN_00297332(lVar1,0);
    if (iVar2 == 0) {
      return 0;
    }
    local_10 = *(uint32_t **)(lVar1 + 0x18);
    *(long *)(lVar1 + 0x18) = *(long *)(lVar1 + 0x18) + 4;
  }
  uVar3 = htonl((uint32_t)*param_2);
  *local_10 = uVar3;
  return 1;
}


// ===== 0029692d FUN_0029692d =====

undefined8 FUN_0029692d(long param_1,long param_2,uint param_3)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = *(long *)(param_1 + 0x18);
  local_2c = param_3;
  local_28 = param_2;
  do {
    while( true ) {
      if (local_2c == 0) {
        return 1;
      }
      uVar2 = (uint)*(undefined8 *)(lVar1 + 0x60);
      if (uVar2 == 0) break;
      if (local_2c <= uVar2) {
        uVar2 = local_2c;
      }
      iVar3 = FUN_002974ab(lVar1,local_28,uVar2);
      if (iVar3 == 0) {
        return 0;
      }
      local_28 = local_28 + (int)uVar2;
      *(long *)(lVar1 + 0x60) = *(long *)(lVar1 + 0x60) - (long)(int)uVar2;
      local_2c = local_2c - uVar2;
    }
    if (*(int *)(lVar1 + 0x68) != 0) {
      return 0;
    }
    iVar3 = FUN_002975d8(lVar1);
  } while (iVar3 != 0);
  return 0;
}


// ===== 002969f1 FUN_002969f1 =====

undefined8 FUN_002969f1(long param_1,void *param_2,uint param_3)

{
  long lVar1;
  int iVar2;
  ulong __n;
  ulong uVar3;
  uint local_2c;
  void *local_28;
  
  lVar1 = *(long *)(param_1 + 0x18);
  local_2c = param_3;
  local_28 = param_2;
  do {
    do {
      if (local_2c == 0) {
        return 1;
      }
      uVar3 = *(long *)(lVar1 + 0x20) - *(long *)(lVar1 + 0x18);
      __n = (ulong)local_2c;
      if (uVar3 <= local_2c) {
        __n = uVar3;
      }
      memmove(*(void **)(lVar1 + 0x18),local_28,__n);
      *(ulong *)(lVar1 + 0x18) = *(long *)(lVar1 + 0x18) + __n;
      local_28 = (void *)((long)local_28 + __n);
      local_2c = local_2c - (int)__n;
    } while (*(long *)(lVar1 + 0x18) != *(long *)(lVar1 + 0x20));
    *(undefined4 *)(lVar1 + 0x30) = 1;
    iVar2 = FUN_00297332(lVar1,0);
  } while (iVar2 != 0);
  return 0;
}


// ===== 00296ad0 FUN_00296ad0 =====

long FUN_00296ad0(int *param_1)

{
  long lVar1;
  long local_10;
  
  lVar1 = *(long *)(param_1 + 6);
  if (*param_1 == 0) {
    local_10 = (*(long *)(lVar1 + 0x18) - *(long *)(lVar1 + 0x10)) + -4;
  }
  else if (*param_1 == 1) {
    local_10 = (*(long *)(lVar1 + 0x58) - *(long *)(lVar1 + 0x50)) + -4;
  }
  else {
    local_10 = -1;
  }
  return local_10;
}


// ===== 00296b4a FUN_00296b4a =====

undefined8 FUN_00296b4a(int *param_1,int param_2)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  
  lVar1 = *(long *)(param_1 + 6);
  iVar2 = FUN_00296ad0(param_1);
  param_2 = iVar2 - param_2;
  if (iVar2 != -1) {
    if (*param_1 == 1) {
      uVar3 = *(long *)(lVar1 + 0x50) - (long)param_2;
      if (((param_2 < (int)*(undefined8 *)(lVar1 + 0x60)) && (uVar3 <= *(ulong *)(lVar1 + 0x58))) &&
         (*(ulong *)(lVar1 + 0x48) <= uVar3)) {
        *(ulong *)(lVar1 + 0x50) = uVar3;
        *(long *)(lVar1 + 0x60) = *(long *)(lVar1 + 0x60) - (long)param_2;
        return 1;
      }
    }
    else if (((*param_1 == 0) &&
             (uVar3 = *(long *)(lVar1 + 0x18) - (long)param_2, *(ulong *)(lVar1 + 0x28) < uVar3)) &&
            (uVar3 < *(ulong *)(lVar1 + 0x20))) {
      *(ulong *)(lVar1 + 0x18) = uVar3;
      return 1;
    }
  }
  return 0;
}


// ===== 00296c61 FUN_00296c61 =====

undefined8 FUN_00296c61(int *param_1,uint param_2)

{
  long lVar1;
  undefined8 local_10;
  
  lVar1 = *(long *)(param_1 + 6);
  local_10 = 0;
  if (*param_1 == 1) {
    if (((long)(ulong)param_2 <= *(long *)(lVar1 + 0x60)) &&
       (*(long *)(lVar1 + 0x50) + (ulong)param_2 <= *(ulong *)(lVar1 + 0x58))) {
      local_10 = *(undefined8 *)(lVar1 + 0x50);
      *(ulong *)(lVar1 + 0x60) = *(long *)(lVar1 + 0x60) - (ulong)param_2;
      *(ulong *)(lVar1 + 0x50) = *(long *)(lVar1 + 0x50) + (ulong)param_2;
    }
  }
  else if ((*param_1 == 0) && (*(long *)(lVar1 + 0x18) + (ulong)param_2 <= *(ulong *)(lVar1 + 0x20))
          ) {
    local_10 = *(undefined8 *)(lVar1 + 0x18);
    *(ulong *)(lVar1 + 0x18) = *(long *)(lVar1 + 0x18) + (ulong)param_2;
  }
  return local_10;
}


// ===== 00296d4a FUN_00296d4a =====

void FUN_00296d4a(long param_1)

{
  void *__ptr;
  
  __ptr = *(void **)(param_1 + 0x18);
  free(*(void **)((long)__ptr + 0x10));
  free(*(void **)((long)__ptr + 0x48));
  free(__ptr);
  return;
}


// ===== 00296d91 FUN_00296d91 =====

undefined8 FUN_00296d91(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  int local_14;
  long local_10;
  
  local_10 = *(long *)(param_1 + 0x18);
  if (*(int *)(local_10 + 0x74) == 0) {
    do {
      if ((*(long *)(local_10 + 0x60) < 1) && (*(int *)(local_10 + 0x68) != 0)) {
        *(undefined4 *)(local_10 + 0x68) = 0;
        return 1;
      }
      iVar1 = FUN_00297660(local_10,*(undefined8 *)(local_10 + 0x60));
      if (iVar1 == 0) {
        return 0;
      }
      *(undefined8 *)(local_10 + 0x60) = 0;
    } while ((*(int *)(local_10 + 0x68) != 0) || (iVar1 = FUN_002975d8(local_10), iVar1 != 0));
    uVar2 = 0;
  }
  else {
    iVar1 = FUN_00296f6c(param_1,&local_14,0);
    if (iVar1 == 0) {
      if ((*(long *)(local_10 + 0x50) == *(long *)(local_10 + 0x58)) && (local_14 == 1)) {
        *(undefined8 *)(local_10 + 0x60) = 0;
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      *(undefined8 *)(local_10 + 0x60) = 0;
      uVar2 = 1;
    }
  }
  return uVar2;
}


// ===== 00296e9b FUN_00296e9b =====

undefined8 FUN_00296e9b(long param_1,int param_2)

{
  long lVar1;
  uint32_t *puVar2;
  uint32_t uVar3;
  undefined8 uVar4;
  
  lVar1 = *(long *)(param_1 + 0x18);
  if (((param_2 == 0) && (*(int *)(lVar1 + 0x30) == 0)) &&
     (*(long *)(lVar1 + 0x18) + 4U < *(ulong *)(lVar1 + 0x20))) {
    puVar2 = *(uint32_t **)(lVar1 + 0x28);
    uVar3 = htonl(((int)*(undefined8 *)(lVar1 + 0x18) - (int)*(undefined8 *)(lVar1 + 0x28)) - 4U |
                  0x80000000);
    *puVar2 = uVar3;
    *(undefined8 *)(lVar1 + 0x28) = *(undefined8 *)(lVar1 + 0x18);
    *(long *)(lVar1 + 0x18) = *(long *)(lVar1 + 0x18) + 4;
    uVar4 = 1;
  }
  else {
    *(undefined4 *)(lVar1 + 0x30) = 0;
    uVar4 = FUN_00297332(lVar1,1);
  }
  return uVar4;
}


// ===== 00296f6c FUN_00296f6c =====

undefined8 FUN_00296f6c(long param_1,undefined4 *param_2,int param_3)

{
  undefined8 *puVar1;
  int iVar2;
  uint32_t uVar3;
  uint uVar4;
  long lVar5;
  int *piVar6;
  undefined4 uVar7;
  
  puVar1 = *(undefined8 **)(param_1 + 0x18);
  if (*(int *)(puVar1 + 0xf) == 0) {
    iVar2 = (*(code *)puVar1[7])(*puVar1,puVar1[0x10],4 - *(int *)(puVar1 + 0x11));
    lVar5 = (long)iVar2;
    if (lVar5 == 0) {
      piVar6 = __errno_location();
      if ((*piVar6 == 0xb) || (piVar6 = __errno_location(), *piVar6 == 0xb)) {
        *param_2 = 2;
      }
      else {
        if (param_3 == 0) {
          uVar7 = 2;
        }
        else {
          uVar7 = 0;
        }
        *param_2 = uVar7;
      }
      return 0;
    }
    if (lVar5 < 0) {
      *param_2 = 0;
      return 0;
    }
    puVar1[0x10] = puVar1[0x10] + lVar5;
    *(int *)(puVar1 + 0x11) = iVar2 + *(int *)(puVar1 + 0x11);
    if (*(uint *)(puVar1 + 0x11) < 4) {
      *param_2 = 1;
      return 0;
    }
    uVar3 = ntohl(*(uint32_t *)((long)puVar1 + 0x7c));
    *(uint32_t *)((long)puVar1 + 0x7c) = uVar3;
    uVar4 = *(uint *)((long)puVar1 + 0x7c) & 0x7fffffff;
    if (((uVar4 == 0) || (*(int *)((long)puVar1 + 0x94) < (int)uVar4)) ||
       (*(int *)((long)puVar1 + 0x94) < (int)(*(int *)((long)puVar1 + 0x8c) + uVar4))) {
      *param_2 = 0;
      return 0;
    }
    *(uint *)((long)puVar1 + 0x8c) = *(int *)((long)puVar1 + 0x8c) + uVar4;
    if (*(uint *)(puVar1 + 0xe) < *(uint *)((long)puVar1 + 0x8c)) {
      FUN_0029770a(puVar1,*(undefined4 *)((long)puVar1 + 0x8c));
    }
    if (*(int *)((long)puVar1 + 0x7c) < 0) {
      *(uint *)((long)puVar1 + 0x7c) = *(uint *)((long)puVar1 + 0x7c) & 0x7fffffff;
      *(undefined4 *)(puVar1 + 0xd) = 1;
    }
    *(undefined4 *)(puVar1 + 0xf) = 1;
  }
  iVar2 = (*(code *)puVar1[7])
                    (*puVar1,puVar1[9] + (long)*(int *)(puVar1 + 0x12),
                     *(int *)((long)puVar1 + 0x8c) - *(int *)(puVar1 + 0x12));
  if (iVar2 < 0) {
    *param_2 = 0;
    return 0;
  }
  if (iVar2 == 0) {
    piVar6 = __errno_location();
    if ((*piVar6 == 0xb) || (piVar6 = __errno_location(), *piVar6 == 0xb)) {
      *param_2 = 2;
    }
    else {
      if (param_3 == 0) {
        uVar7 = 2;
      }
      else {
        uVar7 = 0;
      }
      *param_2 = uVar7;
    }
    return 0;
  }
  *(int *)(puVar1 + 0x12) = iVar2 + *(int *)(puVar1 + 0x12);
  if (*(int *)(puVar1 + 0x12) == *(int *)((long)puVar1 + 0x8c)) {
    *(undefined4 *)(puVar1 + 0xf) = 0;
    puVar1[0x10] = (long)puVar1 + 0x7c;
    *(undefined4 *)(puVar1 + 0x11) = 0;
    if (*(int *)(puVar1 + 0xd) != 0) {
      puVar1[0xc] = (long)*(int *)((long)puVar1 + 0x8c);
      puVar1[0xb] = puVar1[9] + (long)*(int *)((long)puVar1 + 0x8c);
      puVar1[10] = puVar1[9];
      *(undefined4 *)(puVar1 + 0x12) = 0;
      *(undefined4 *)((long)puVar1 + 0x8c) = *(undefined4 *)(puVar1 + 0x12);
      *param_2 = 1;
      return 1;
    }
  }
  *param_2 = 1;
  return 0;
}


// ===== 00297332 FUN_00297332 =====

bool FUN_00297332(undefined8 *param_1,int param_2)

{
  uint32_t *puVar1;
  uint uVar2;
  uint32_t uVar3;
  int iVar4;
  int iVar5;
  
  if (param_2 == 1) {
    uVar2 = 0x80000000;
  }
  else {
    uVar2 = 0;
  }
  puVar1 = (uint32_t *)param_1[5];
  uVar3 = htonl(((int)param_1[3] - (int)param_1[5]) - 4U | uVar2);
  *puVar1 = uVar3;
  iVar4 = (int)param_1[3] - (int)param_1[2];
  iVar5 = (*(code *)param_1[1])(*param_1,param_1[2],iVar4);
  if (iVar5 == iVar4) {
    param_1[5] = param_1[2];
    param_1[3] = param_1[2] + 4;
  }
  return iVar5 == iVar4;
}


// ===== 00297408 FUN_00297408 =====

undefined8 FUN_00297408(undefined8 *param_1)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  
  if (*(int *)((long)param_1 + 0x74) == 0) {
    uVar2 = (uint)param_1[0xb] & 3;
    lVar1 = param_1[9] + (ulong)uVar2;
    iVar3 = (*(code *)param_1[7])(*param_1,lVar1,(int)param_1[8] - uVar2);
    if (iVar3 == -1) {
      uVar4 = 0;
    }
    else {
      param_1[10] = lVar1;
      param_1[0xb] = lVar1 + iVar3;
      uVar4 = 1;
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}


// ===== 002974ab FUN_002974ab =====

undefined8 FUN_002974ab(long param_1,void *param_2,int param_3)

{
  int iVar1;
  undefined8 uVar2;
  ulong __n;
  ulong uVar3;
  int local_2c;
  void *local_28;
  
  local_2c = param_3;
  local_28 = param_2;
  if (*(int *)(param_1 + 0x74) == 0) {
    do {
      while( true ) {
        if (local_2c < 1) {
          return 1;
        }
        uVar3 = *(long *)(param_1 + 0x58) - *(long *)(param_1 + 0x50);
        if (uVar3 == 0) break;
        __n = (long)local_2c;
        if (uVar3 <= (ulong)(long)local_2c) {
          __n = uVar3;
        }
        memmove(local_28,*(void **)(param_1 + 0x50),__n);
        *(ulong *)(param_1 + 0x50) = *(long *)(param_1 + 0x50) + __n;
        local_28 = (void *)((long)local_28 + __n);
        local_2c = local_2c - (int)__n;
      }
      iVar1 = FUN_00297408(param_1);
    } while (iVar1 != 0);
    uVar2 = 0;
  }
  else if ((int)*(undefined8 *)(param_1 + 0x58) - (int)*(undefined8 *)(param_1 + 0x50) < param_3) {
    uVar2 = 0;
  }
  else {
    memcpy(param_2,*(void **)(param_1 + 0x50),(long)param_3);
    *(long *)(param_1 + 0x50) = *(long *)(param_1 + 0x50) + (long)param_3;
    uVar2 = 1;
  }
  return uVar2;
}


// ===== 002975d8 FUN_002975d8 =====

undefined8 FUN_002975d8(long param_1)

{
  int iVar1;
  uint32_t uVar2;
  undefined8 uVar3;
  uint32_t local_c;
  
  if (*(int *)(param_1 + 0x74) == 0) {
    iVar1 = FUN_002974ab(param_1,&local_c,4);
    if (iVar1 == 0) {
      uVar3 = 0;
    }
    else {
      uVar2 = ntohl(local_c);
      *(uint32_t *)(param_1 + 0x68) = uVar2 >> 0x1f;
      if (uVar2 == 0) {
        uVar3 = 0;
      }
      else {
        *(ulong *)(param_1 + 0x60) = (ulong)(uVar2 & 0x7fffffff);
        uVar3 = 1;
      }
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


// ===== 00297660 FUN_00297660 =====

undefined8 FUN_00297660(long param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  long local_28;
  
  local_28 = param_2;
  do {
    while( true ) {
      if (local_28 < 1) {
        return 1;
      }
      uVar1 = (int)*(undefined8 *)(param_1 + 0x58) - (int)*(undefined8 *)(param_1 + 0x50);
      if (uVar1 == 0) break;
      if (local_28 < (long)(ulong)uVar1) {
        uVar1 = (uint)local_28;
      }
      *(ulong *)(param_1 + 0x50) = *(long *)(param_1 + 0x50) + (ulong)uVar1;
      local_28 = local_28 - (ulong)uVar1;
    }
    iVar2 = FUN_00297408(param_1);
  } while (iVar2 != 0);
  return 0;
}


// ===== 002976eb FUN_002976eb =====

uint FUN_002976eb(uint param_1)

{
  undefined4 local_c;
  
  local_c = param_1;
  if (param_1 < 100) {
    local_c = 4000;
  }
  return local_c + 3 & 0xfffffffc;
}


// ===== 0029770a FUN_0029770a =====

undefined8 FUN_0029770a(long param_1,uint param_2)

{
  void *pvVar1;
  
  if (*(uint *)(param_1 + 0x70) < param_2) {
    pvVar1 = realloc(*(void **)(param_1 + 0x48),(long)(int)param_2);
    if (pvVar1 == (void *)0x0) {
      return 0;
    }
    *(long *)(param_1 + 0x50) =
         (long)pvVar1 + (*(long *)(param_1 + 0x50) - *(long *)(param_1 + 0x48));
    *(void **)(param_1 + 0x48) = pvVar1;
    *(long *)(param_1 + 0x58) = (long)(int)param_2 + (long)pvVar1;
    *(uint *)(param_1 + 0x70) = param_2;
    *(long *)(param_1 + 0x40) = (long)(int)param_2;
  }
  return 1;
}


// ===== 002977c3 FUN_002977c3 =====

void FUN_002977c3(undefined4 *param_1,ulong param_2,undefined4 param_3,undefined4 param_4)

{
  undefined **ppuVar1;
  
  *param_1 = param_4;
  if ((param_2 & 3) == 0) {
    ppuVar1 = &PTR_FUN_00329800;
  }
  else {
    ppuVar1 = &PTR_FUN_00329860;
  }
  *(undefined ***)(param_1 + 2) = ppuVar1;
  *(ulong *)(param_1 + 8) = param_2;
  *(undefined8 *)(param_1 + 6) = *(undefined8 *)(param_1 + 8);
  param_1[10] = param_3;
  return;
}


// ===== 0029782b FUN_0029782b =====

void FUN_0029782b(void)

{
  return;
}


// ===== 00297836 FUN_00297836 =====

bool FUN_00297836(long param_1,ulong *param_2)

{
  bool bVar1;
  uint32_t uVar2;
  
  bVar1 = 3 < *(uint *)(param_1 + 0x28);
  if (bVar1) {
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + -4;
    uVar2 = ntohl(**(uint32_t **)(param_1 + 0x18));
    *param_2 = (ulong)uVar2;
    *(long *)(param_1 + 0x18) = *(long *)(param_1 + 0x18) + 4;
  }
  return bVar1;
}


// ===== 0029789f FUN_0029789f =====

bool FUN_0029789f(long param_1,undefined8 *param_2)

{
  uint32_t *puVar1;
  bool bVar2;
  uint32_t uVar3;
  
  bVar2 = 3 < *(uint *)(param_1 + 0x28);
  if (bVar2) {
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + -4;
    puVar1 = *(uint32_t **)(param_1 + 0x18);
    uVar3 = htonl((uint32_t)*param_2);
    *puVar1 = uVar3;
    *(long *)(param_1 + 0x18) = *(long *)(param_1 + 0x18) + 4;
  }
  return bVar2;
}


// ===== 0029790e FUN_0029790e =====

bool FUN_0029790e(long param_1,ulong *param_2)

{
  bool bVar1;
  uint32_t uVar2;
  
  bVar1 = 3 < *(uint *)(param_1 + 0x28);
  if (bVar1) {
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + -4;
    uVar2 = ntohl(**(uint32_t **)(param_1 + 0x18));
    *param_2 = (ulong)uVar2;
    *(long *)(param_1 + 0x18) = *(long *)(param_1 + 0x18) + 4;
  }
  return bVar1;
}


// ===== 0029797d FUN_0029797d =====

bool FUN_0029797d(long param_1,undefined8 *param_2)

{
  bool bVar1;
  uint32_t uVar2;
  
  bVar1 = 3 < *(uint *)(param_1 + 0x28);
  if (bVar1) {
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + -4;
    uVar2 = htonl((uint32_t)*param_2);
    **(uint32_t **)(param_1 + 0x18) = uVar2;
    *(long *)(param_1 + 0x18) = *(long *)(param_1 + 0x18) + 4;
  }
  return bVar1;
}


// ===== 002979ea FUN_002979ea =====

bool FUN_002979ea(long param_1,void *param_2,uint param_3)

{
  bool bVar1;
  
  bVar1 = param_3 <= *(uint *)(param_1 + 0x28);
  if (bVar1) {
    *(uint *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) - param_3;
    memmove(param_2,*(void **)(param_1 + 0x18),(ulong)param_3);
    *(ulong *)(param_1 + 0x18) = *(long *)(param_1 + 0x18) + (ulong)param_3;
  }
  return bVar1;
}


// ===== 00297a5a FUN_00297a5a =====

bool FUN_00297a5a(long param_1,void *param_2,uint param_3)

{
  bool bVar1;
  
  bVar1 = param_3 <= *(uint *)(param_1 + 0x28);
  if (bVar1) {
    *(uint *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) - param_3;
    memmove(*(void **)(param_1 + 0x18),param_2,(ulong)param_3);
    *(ulong *)(param_1 + 0x18) = *(long *)(param_1 + 0x18) + (ulong)param_3;
  }
  return bVar1;
}


// ===== 00297aca FUN_00297aca =====

long FUN_00297aca(long param_1)

{
  return *(long *)(param_1 + 0x18) - *(long *)(param_1 + 0x20);
}


// ===== 00297aed FUN_00297aed =====

bool FUN_00297aed(long param_1,uint param_2)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar1 = (ulong)param_2 + *(long *)(param_1 + 0x20);
  uVar2 = (ulong)*(uint *)(param_1 + 0x28) + *(long *)(param_1 + 0x18);
  if (uVar1 <= uVar2) {
    *(ulong *)(param_1 + 0x18) = uVar1;
    *(int *)(param_1 + 0x28) = (int)uVar2 - (int)uVar1;
  }
  return uVar1 <= uVar2;
}


// ===== 00297b5d FUN_00297b5d =====

undefined8 FUN_00297b5d(long param_1,uint param_2)

{
  undefined8 local_10;
  
  local_10 = 0;
  if (param_2 <= *(uint *)(param_1 + 0x28)) {
    *(uint *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) - param_2;
    local_10 = *(undefined8 *)(param_1 + 0x18);
    *(ulong *)(param_1 + 0x18) = *(long *)(param_1 + 0x18) + (ulong)param_2;
  }
  return local_10;
}


// ===== 00297bb7 FUN_00297bb7 =====

undefined8 FUN_00297bb7(void)

{
  return 0;
}


// ===== 00297bd0 FUN_00297bd0 =====

void FUN_00297bd0(void)

{
  code *pcVar1;
  undefined8 *puVar2;
  
  if (DAT_00324478 != (code *)0xffffffffffffffff) {
    puVar2 = &DAT_00324478;
    pcVar1 = DAT_00324478;
    do {
      (*pcVar1)();
      pcVar1 = (code *)puVar2[-1];
      puVar2 = puVar2 + -1;
    } while (pcVar1 != (code *)0xffffffffffffffff);
    return;
  }
  return;
}


// ===== 00297c14 _DT_FINI =====

void _DT_FINI(void)

{
  FUN_0011fe00();
  return;
}


// ===== 01219000 munlock =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int munlock(void *__addr,size_t __len)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219008 getenv =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * getenv(char *__name)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219010 free =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219018 recv =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t recv(int __fd,void *__buf,size_t __n,int __flags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219020 pthread_create =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_create(pthread_t *__newthread,pthread_attr_t *__attr,__start_routine *__start_routine,
                  void *__arg)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219028 endmntent =====

/* WARNING: Control flow encountered bad instruction data */

void endmntent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219030 pthread_sigmask =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_sigmask(int __how,__sigset_t *__newmask,__sigset_t *__oldmask)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219038 strcasecmp =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcasecmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219040 posix_spawn_file_actions_init =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int posix_spawn_file_actions_init(posix_spawn_file_actions_t *__file_actions)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219048 localtime =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

tm * localtime(time_t *__timer)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219050 abort =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219058 __errno_location =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int * __errno_location(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219060 mlock =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int mlock(void *__addr,size_t __len)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219068 strncpy =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strncpy(char *__dest,char *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219070 remove =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int remove(char *__filename)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219078 strncmp =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219080 _ITM_deregisterTMCloneTable =====

/* WARNING: Control flow encountered bad instruction data */

void _ITM_deregisterTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219090 localtime_r =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

tm * localtime_r(time_t *__timer,tm *__tp)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219098 strcpy =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012190a0 __isoc99_fscanf =====

/* WARNING: Control flow encountered bad instruction data */

void __isoc99_fscanf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012190a8 pthread_cond_broadcast =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_cond_broadcast(pthread_cond_t *__cond)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012190b0 mkdir =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int mkdir(char *__path,__mode_t __mode)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012190b8 sendmsg =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t sendmsg(int __fd,msghdr *__message,int __flags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012190c0 puts =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int puts(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012190c8 ferror =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ferror(FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012190d0 qsort =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void qsort(void *__base,size_t __nmemb,size_t __size,__compar_fn_t __compar)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012190d8 fread =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t fread(void *__ptr,size_t __size,size_t __n,FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012190e0 vsnprintf =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int vsnprintf(char *__s,size_t __maxlen,char *__format,__gnuc_va_list __arg)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012190e8 setsockopt =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int setsockopt(int __fd,int __level,int __optname,void *__optval,socklen_t __optlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012190f0 atof =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double atof(char *__nptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012190f8 faccessat =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int faccessat(int __fd,char *__file,int __type,int __flag)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219100 fcntl =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fcntl(int __fd,int __cmd,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219108 write =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t write(int __fd,void *__buf,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219110 getpid =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t getpid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219118 lround =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long lround(double __x)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219120 dup3 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int dup3(int __fd,int __fd2,int __flags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219128 pthread_rwlock_init =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlock_init(pthread_rwlock_t *__rwlock,pthread_rwlockattr_t *__attr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219130 pthread_cond_wait =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_cond_wait(pthread_cond_t *__cond,pthread_mutex_t *__mutex)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219138 getpeername =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int getpeername(int __fd,sockaddr *__addr,socklen_t *__len)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219140 pthread_once =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_once(pthread_once_t *__once_control,__init_routine *__init_routine)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219148 fclose =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fclose(FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219150 posix_spawn_file_actions_destroy =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int posix_spawn_file_actions_destroy(posix_spawn_file_actions_t *__file_actions)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219158 __xstat64 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int __xstat64(int __ver,char *__filename,stat64 *__stat_buf)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219160 opendir =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DIR * opendir(char *__name)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219168 stpcpy =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * stpcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219170 strlen =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219178 openat =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int openat(int __fd,char *__file,int __oflag,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219180 pthread_mutexattr_destroy =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutexattr_destroy(pthread_mutexattr_t *__attr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219188 modff =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float modff(float __x,float *__iptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219190 getuid =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__uid_t getuid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219198 mmap =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * mmap(void *__addr,size_t __len,int __prot,int __flags,int __fd,__off_t __offset)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012191a0 getmntent_r =====

/* WARNING: Control flow encountered bad instruction data */

void getmntent_r(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012191a8 pthread_setaffinity_np =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_setaffinity_np(pthread_t __th,size_t __cpusetsize,cpu_set_t *__cpuset)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012191b0 dup2 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int dup2(int __fd,int __fd2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012191b8 send =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t send(int __fd,void *__buf,size_t __n,int __flags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012191c0 strchr =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strchr(char *__s,int __c)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012191c8 printf =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012191d0 warnx =====

/* WARNING: Control flow encountered bad instruction data */

void warnx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012191d8 pthread_setspecific =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_setspecific(pthread_key_t __key,void *__pointer)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012191e0 pthread_mutex_destroy =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_destroy(pthread_mutex_t *__mutex)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012191e8 symlink =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int symlink(char *__from,char *__to)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012191f0 __fxstatat =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int __fxstatat(int __ver,int __fildes,char *__filename,stat *__stat_buf,int __flag)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012191f8 snprintf =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219200 pthread_mutexattr_init =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutexattr_init(pthread_mutexattr_t *__attr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219208 nanosleep =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int nanosleep(timespec *__requested_time,timespec *__remaining)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219210 strrchr =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strrchr(char *__s,int __c)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219218 uname =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int uname(utsname *__name)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219220 lseek =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__off_t lseek(int __fd,__off_t __offset,int __whence)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219228 gettimeofday =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int gettimeofday(timeval *__tv,__timezone_ptr_t __tz)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219230 __assert_fail =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __assert_fail(char *__assertion,char *__file,uint __line,char *__function)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219238 iopl =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int iopl(int __level)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219240 fputs =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fputs(char *__s,FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219248 htonl =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint32_t htonl(uint32_t __hostlong)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219250 memset =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219258 geteuid =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__uid_t geteuid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219260 fscanf =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fscanf(FILE *__stream,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219268 ioctl =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ioctl(int __fd,ulong __request,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219270 strnlen =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219278 scandir =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int scandir(char *__dir,dirent ***__namelist,__selector *__selector,__cmp *__cmp)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219280 strncat =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strncat(char *__dest,char *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219288 pthread_rwlock_trywrlock =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlock_trywrlock(pthread_rwlock_t *__rwlock)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219290 close =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219298 rewinddir =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void rewinddir(DIR *__dirp)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012192a0 posix_spawn =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int posix_spawn(pid_t *__pid,char *__path,posix_spawn_file_actions_t *__file_actions,
               posix_spawnattr_t *__attrp,char **__argv,char **__envp)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012192a8 strspn =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strspn(char *__s,char *__accept)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012192b0 sched_setaffinity =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sched_setaffinity(__pid_t __pid,size_t __cpusetsize,cpu_set_t *__cpuset)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012192b8 closedir =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int closedir(DIR *__dirp)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012192c0 fputc =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fputc(int __c,FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012192c8 alphasort =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int alphasort(dirent **__e1,dirent **__e2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012192d0 strcspn =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strcspn(char *__s,char *__reject)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012192d8 read =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012192e0 memcmp =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int memcmp(void *__s1,void *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012192e8 fgets =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * fgets(char *__s,int __n,FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012192f0 pthread_cond_signal =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_cond_signal(pthread_cond_t *__cond)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012192f8 pthread_rwlock_wrlock =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlock_wrlock(pthread_rwlock_t *__rwlock)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219300 getsockopt =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int getsockopt(int __fd,int __level,int __optname,void *__optval,socklen_t *__optlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219308 pthread_rwlock_rdlock =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlock_rdlock(pthread_rwlock_t *__rwlock)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219310 strtoull =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulonglong strtoull(char *__nptr,char **__endptr,int __base)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219318 calloc =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * calloc(size_t __nmemb,size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219320 __getdelim =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__ssize_t __getdelim(char **__lineptr,size_t *__n,int __delimiter,FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219328 memcpy =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219330 strcmp =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219338 signal =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__sighandler_t signal(int __sig,__sighandler_t __handler)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219340 readlinkat =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t readlinkat(int __fd,char *__path,char *__buf,size_t __len)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219348 dlvsym =====

/* WARNING: Control flow encountered bad instruction data */

void dlvsym(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219350 dirfd =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int dirfd(DIR *__dirp)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219358 fprintf =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fprintf(FILE *__stream,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219360 syscall =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long syscall(long __sysno,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219368 feof =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int feof(FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219370 __gmon_start__ =====

/* WARNING: Control flow encountered bad instruction data */

void __gmon_start__(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219378 strtol =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long strtol(char *__nptr,char **__endptr,int __base)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219380 realpath =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * realpath(char *__name,char *__resolved)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219388 sigfillset =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sigfillset(sigset_t *__set)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219390 socketpair =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int socketpair(int __domain,int __type,int __protocol,int *__fds)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219398 pthread_rwlockattr_setpshared =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlockattr_setpshared(pthread_rwlockattr_t *__attr,int __pshared)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012193a8 __xmknod =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int __xmknod(int __ver,char *__path,__mode_t __mode,__dev_t *__dev)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012193b0 time =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

time_t time(time_t *__timer)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012193b8 fileno =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fileno(FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012193c0 select =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int select(int __nfds,fd_set *__readfds,fd_set *__writefds,fd_set *__exceptfds,timeval *__timeout)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012193c8 pwrite64 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t pwrite64(int __fd,void *__buf,size_t __n,__off64_t __offset)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012193d0 __xstat =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int __xstat(int __ver,char *__filename,stat *__stat_buf)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012193d8 pthread_cond_init =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_cond_init(pthread_cond_t *__cond,pthread_condattr_t *__cond_attr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012193e0 readdir =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

dirent * readdir(DIR *__dirp)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012193e8 dlopen =====

/* WARNING: Control flow encountered bad instruction data */

void dlopen(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012193f0 mmap64 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * mmap64(void *__addr,size_t __len,int __prot,int __flags,int __fd,__off64_t __offset)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012193f8 pthread_getaffinity_np =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_getaffinity_np(pthread_t __th,size_t __cpusetsize,cpu_set_t *__cpuset)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219400 pthread_getspecific =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * pthread_getspecific(pthread_key_t __key)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219408 pthread_mutex_unlock =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_unlock(pthread_mutex_t *__mutex)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219410 pthread_mutexattr_settype =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutexattr_settype(pthread_mutexattr_t *__attr,int __kind)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219418 malloc =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219420 strncasecmp =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncasecmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219428 fflush =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fflush(FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219430 _IO_getc =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _IO_getc(_IO_FILE *__fp)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219438 setmntent =====

/* WARNING: Control flow encountered bad instruction data */

void setmntent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219440 strsep =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219448 __isoc99_sscanf =====

/* WARNING: Control flow encountered bad instruction data */

void __isoc99_sscanf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219450 syslog =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void syslog(int __pri,char *__fmt,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219458 scandir64 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int scandir64(char *__dir,dirent64 ***__namelist,__selector *__selector,__cmp *__cmp)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219460 __sched_cpufree =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __sched_cpufree(cpu_set_t *__set)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219468 __fxstat =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int __fxstat(int __ver,int __fildes,stat *__stat_buf)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219470 listen =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int listen(int __fd,int __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219478 sscanf =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219480 clock_gettime =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int clock_gettime(clockid_t __clock_id,timespec *__tp)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219488 pthread_rwlock_unlock =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlock_unlock(pthread_rwlock_t *__rwlock)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219490 posix_spawn_file_actions_addopen =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int posix_spawn_file_actions_addopen
              (posix_spawn_file_actions_t *__file_actions,int __fd,char *__path,int __oflag,
              mode_t __mode)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219498 fseek =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fseek(FILE *__stream,long __off,int __whence)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012194a0 __sched_cpualloc =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

cpu_set_t * __sched_cpualloc(size_t __count)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012194a8 dlclose =====

/* WARNING: Control flow encountered bad instruction data */

void dlclose(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012194b0 pthread_rwlock_timedwrlock =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlock_timedwrlock(pthread_rwlock_t *__rwlock,timespec *__abstime)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012194b8 chown =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int chown(char *__file,__uid_t __owner,__gid_t __group)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012194c0 realloc =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * realloc(void *__ptr,size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012194c8 isalpha =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int isalpha(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012194d0 fdopen =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * fdopen(int __fd,char *__modes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012194d8 asprintf =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int asprintf(char **__ptr,char *__fmt,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012194e0 munmap =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int munmap(void *__addr,size_t __len)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012194e8 recvmsg =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t recvmsg(int __fd,msghdr *__message,int __flags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012194f0 pwrite =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t pwrite(int __fd,void *__buf,size_t __n,__off_t __offset)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012194f8 pthread_key_create =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_key_create(pthread_key_t *__key,__destr_function *__destr_function)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219500 gnu_get_libc_version =====

/* WARNING: Control flow encountered bad instruction data */

void gnu_get_libc_version(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219508 poll =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int poll(pollfd *__fds,nfds_t __nfds,int __timeout)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219510 chmod =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int chmod(char *__file,__mode_t __mode)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219518 bind =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int bind(int __fd,sockaddr *__addr,socklen_t __len)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219520 open64 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int open64(char *__file,int __oflag,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219528 memmove =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memmove(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219538 pread64 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t pread64(int __fd,void *__buf,size_t __nbytes,__off64_t __offset)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219540 pthread_self =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

pthread_t pthread_self(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219548 waitpid =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t waitpid(__pid_t __pid,int *__stat_loc,int __options)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219550 pthread_cond_destroy =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_cond_destroy(pthread_cond_t *__cond)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219558 mprotect =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int mprotect(void *__addr,size_t __len,int __prot)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219560 open =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int open(char *__file,int __oflag,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219568 access =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int access(char *__name,int __type)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219570 pthread_rwlockattr_destroy =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlockattr_destroy(pthread_rwlockattr_t *__attr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219578 pthread_rwlock_timedrdlock =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlock_timedrdlock(pthread_rwlock_t *__rwlock,timespec *__abstime)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219580 fopen =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * fopen(char *__filename,char *__modes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219588 sysconf =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long sysconf(int __name)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219590 pthread_join =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_join(pthread_t __th,void **__thread_return)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219598 vfork =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t vfork(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012195a0 vfprintf =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int vfprintf(FILE *__s,char *__format,__gnuc_va_list __arg)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012195a8 fdopendir =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DIR * fdopendir(int __fd)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012195b0 getsockname =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int getsockname(int __fd,sockaddr *__addr,socklen_t *__len)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012195b8 strtoul =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulong strtoul(char *__nptr,char **__endptr,int __base)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012195c0 sched_getcpu =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sched_getcpu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012195c8 __cxa_atexit =====

/* WARNING: Control flow encountered bad instruction data */

void __cxa_atexit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012195d0 atoi =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int atoi(char *__nptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012195d8 pread =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t pread(int __fd,void *__buf,size_t __nbytes,__off_t __offset)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012195e0 strcat =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcat(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012195e8 alphasort64 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int alphasort64(dirent64 **__e1,dirent64 **__e2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012195f0 sprintf =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012195f8 exit =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void exit(int __status)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219600 connect =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int connect(int __fd,sockaddr *__addr,socklen_t __len)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219608 eventfd =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int eventfd(int __count,int __flags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219610 fwrite =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t fwrite(void *__ptr,size_t __size,size_t __n,FILE *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219618 pthread_mutexattr_setpshared =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutexattr_setpshared(pthread_mutexattr_t *__attr,int __pshared)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219620 _ITM_registerTMCloneTable =====

/* WARNING: Control flow encountered bad instruction data */

void _ITM_registerTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219628 sched_getaffinity =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sched_getaffinity(__pid_t __pid,size_t __cpusetsize,cpu_set_t *__cpuset)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219630 posix_spawn_file_actions_adddup2 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int posix_spawn_file_actions_adddup2
              (posix_spawn_file_actions_t *__file_actions,int __fd,int __newfd)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219638 ntohl =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint32_t ntohl(uint32_t __netlong)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219640 strdup =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strdup(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219648 strerror =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strerror(int __errnum)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219650 dlsym =====

/* WARNING: Control flow encountered bad instruction data */

void dlsym(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219658 pthread_rwlock_destroy =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlock_destroy(pthread_rwlock_t *__rwlock)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219660 sleep =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint sleep(uint __seconds)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219668 pthread_mutex_init =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_init(pthread_mutex_t *__mutex,pthread_mutexattr_t *__mutexattr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219670 __cxa_finalize =====

/* WARNING: Control flow encountered bad instruction data */

void __cxa_finalize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219678 pthread_rwlockattr_init =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlockattr_init(pthread_rwlockattr_t *__attr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219680 strstr =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219688 pthread_mutex_lock =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_lock(pthread_mutex_t *__mutex)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219690 dlerror =====

/* WARNING: Control flow encountered bad instruction data */

void dlerror(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 01219698 __ctype_b_loc =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ushort ** __ctype_b_loc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012196a0 usleep =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int usleep(__useconds_t __useconds)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== 012196b0 socket =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int socket(int __domain,int __type,int __protocol)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


