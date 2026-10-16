// ===== 0011f000 _DT_INIT =====

void _DT_INIT(void)

{
  FUN_0011fd70();
  thunk_FUN_0011fdc0();
  FUN_00297bd0();
  return;
}


// ===== 0011f020 FUN_0011f020 =====

void FUN_0011f020(void)

{
  (*(code *)PTR_0032f010)();
  return;
}


// ===== 0011f030 munlock =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int munlock(void *__addr,size_t __len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_munlock_0032f018)();
  return iVar1;
}


// ===== 0011f040 getenv =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * getenv(char *__name)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_getenv_0032f020)();
  return pcVar1;
}


// ===== 0011f050 recv =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t recv(int __fd,void *__buf,size_t __n,int __flags)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_recv_0032f028)();
  return sVar1;
}


// ===== 0011f060 pthread_create =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_create(pthread_t *__newthread,pthread_attr_t *__attr,__start_routine *__start_routine,
                  void *__arg)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_create_0032f030)();
  return iVar1;
}


// ===== 0011f070 endmntent =====

void endmntent(void)

{
  (*(code *)PTR_endmntent_0032f038)();
  return;
}


// ===== 0011f080 pthread_sigmask =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_sigmask(int __how,__sigset_t *__newmask,__sigset_t *__oldmask)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_sigmask_0032f040)();
  return iVar1;
}


// ===== 0011f090 strcasecmp =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcasecmp(char *__s1,char *__s2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strcasecmp_0032f048)();
  return iVar1;
}


// ===== 0011f0a0 posix_spawn_file_actions_init =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int posix_spawn_file_actions_init(posix_spawn_file_actions_t *__file_actions)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_posix_spawn_file_actions_init_0032f050)();
  return iVar1;
}


// ===== 0011f0b0 localtime =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

tm * localtime(time_t *__timer)

{
  tm *ptVar1;
  
  ptVar1 = (tm *)(*(code *)PTR_localtime_0032f058)();
  return ptVar1;
}


// ===== 0011f0c0 abort =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
  (*(code *)PTR_abort_0032f060)();
  return;
}


// ===== 0011f0d0 __errno_location =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int * __errno_location(void)

{
  int *piVar1;
  
  piVar1 = (int *)(*(code *)PTR___errno_location_0032f068)();
  return piVar1;
}


// ===== 0011f0e0 mlock =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int mlock(void *__addr,size_t __len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_mlock_0032f070)();
  return iVar1;
}


// ===== 0011f0f0 strncpy =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strncpy(char *__dest,char *__src,size_t __n)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strncpy_0032f078)();
  return pcVar1;
}


// ===== 0011f100 remove =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int remove(char *__filename)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_remove_0032f080)();
  return iVar1;
}


// ===== 0011f110 strncmp =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strncmp_0032f088)();
  return iVar1;
}


// ===== 0011f120 localtime_r =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

tm * localtime_r(time_t *__timer,tm *__tp)

{
  tm *ptVar1;
  
  ptVar1 = (tm *)(*(code *)PTR_localtime_r_0032f090)();
  return ptVar1;
}


// ===== 0011f130 strcpy =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strcpy_0032f098)();
  return pcVar1;
}


// ===== 0011f140 __isoc99_fscanf =====

void __isoc99_fscanf(void)

{
  (*(code *)PTR___isoc99_fscanf_0032f0a0)();
  return;
}


// ===== 0011f150 pthread_cond_broadcast =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_cond_broadcast(pthread_cond_t *__cond)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_cond_broadcast_0032f0a8)();
  return iVar1;
}


// ===== 0011f160 mkdir =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int mkdir(char *__path,__mode_t __mode)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_mkdir_0032f0b0)();
  return iVar1;
}


// ===== 0011f170 puts =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int puts(char *__s)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_puts_0032f0b8)();
  return iVar1;
}


// ===== 0011f180 ferror =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ferror(FILE *__stream)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_ferror_0032f0c0)();
  return iVar1;
}


// ===== 0011f190 qsort =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void qsort(void *__base,size_t __nmemb,size_t __size,__compar_fn_t __compar)

{
  (*(code *)PTR_qsort_0032f0c8)();
  return;
}


// ===== 0011f1a0 fread =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t fread(void *__ptr,size_t __size,size_t __n,FILE *__stream)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_fread_0032f0d0)();
  return sVar1;
}


// ===== 0011f1b0 vsnprintf =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int vsnprintf(char *__s,size_t __maxlen,char *__format,__gnuc_va_list __arg)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_vsnprintf_0032f0d8)();
  return iVar1;
}


// ===== 0011f1c0 setsockopt =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int setsockopt(int __fd,int __level,int __optname,void *__optval,socklen_t __optlen)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_setsockopt_0032f0e0)();
  return iVar1;
}


// ===== 0011f1d0 atof =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double atof(char *__nptr)

{
  double dVar1;
  
  dVar1 = (double)(*(code *)PTR_atof_0032f0e8)();
  return dVar1;
}


// ===== 0011f1e0 faccessat =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int faccessat(int __fd,char *__file,int __type,int __flag)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_faccessat_0032f0f0)();
  return iVar1;
}


// ===== 0011f1f0 fcntl =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fcntl(int __fd,int __cmd,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fcntl_0032f0f8)();
  return iVar1;
}


// ===== 0011f200 write =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t write(int __fd,void *__buf,size_t __n)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_write_0032f100)();
  return sVar1;
}


// ===== 0011f210 getpid =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t getpid(void)

{
  __pid_t _Var1;
  
  _Var1 = (*(code *)PTR_getpid_0032f108)();
  return _Var1;
}


// ===== 0011f220 lround =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long lround(double __x)

{
  long lVar1;
  
  lVar1 = (*(code *)PTR_lround_0032f110)();
  return lVar1;
}


// ===== 0011f230 dup3 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int dup3(int __fd,int __fd2,int __flags)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_dup3_0032f118)();
  return iVar1;
}


// ===== 0011f240 pthread_rwlock_init =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlock_init(pthread_rwlock_t *__rwlock,pthread_rwlockattr_t *__attr)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_rwlock_init_0032f120)();
  return iVar1;
}


// ===== 0011f250 pthread_cond_wait =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_cond_wait(pthread_cond_t *__cond,pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_cond_wait_0032f128)();
  return iVar1;
}


// ===== 0011f260 nvmlInit_v2 =====

/* WARNING: Switch with 1 destination removed at 0x0011f260 */

void nvmlInit_v2(void)

{
  nvmlInitWithFlags(0);
  return;
}


// ===== 0011f270 getpeername =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int getpeername(int __fd,sockaddr *__addr,socklen_t *__len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_getpeername_0032f138)();
  return iVar1;
}


// ===== 0011f280 pthread_once =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_once(pthread_once_t *__once_control,__init_routine *__init_routine)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_once_0032f140)();
  return iVar1;
}


// ===== 0011f290 fclose =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fclose(FILE *__stream)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fclose_0032f148)();
  return iVar1;
}


// ===== 0011f2a0 posix_spawn_file_actions_destroy =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int posix_spawn_file_actions_destroy(posix_spawn_file_actions_t *__file_actions)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_posix_spawn_file_actions_destroy_0032f150)();
  return iVar1;
}


// ===== 0011f2b0 __xstat64 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int __xstat64(int __ver,char *__filename,stat64 *__stat_buf)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR___xstat64_0032f158)();
  return iVar1;
}


// ===== 0011f2c0 opendir =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DIR * opendir(char *__name)

{
  DIR *pDVar1;
  
  pDVar1 = (DIR *)(*(code *)PTR_opendir_0032f160)();
  return pDVar1;
}


// ===== 0011f2d0 stpcpy =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * stpcpy(char *__dest,char *__src)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_stpcpy_0032f168)();
  return pcVar1;
}


// ===== 0011f2e0 strlen =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_strlen_0032f170)();
  return sVar1;
}


// ===== 0011f2f0 openat =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int openat(int __fd,char *__file,int __oflag,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_openat_0032f178)();
  return iVar1;
}


// ===== 0011f300 pthread_mutexattr_destroy =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutexattr_destroy(pthread_mutexattr_t *__attr)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_mutexattr_destroy_0032f180)();
  return iVar1;
}


// ===== 0011f310 modff =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float modff(float __x,float *__iptr)

{
  float fVar1;
  
  fVar1 = (float)(*(code *)PTR_modff_0032f188)();
  return fVar1;
}


// ===== 0011f320 getuid =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__uid_t getuid(void)

{
  __uid_t _Var1;
  
  _Var1 = (*(code *)PTR_getuid_0032f190)();
  return _Var1;
}


// ===== 0011f330 mmap =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * mmap(void *__addr,size_t __len,int __prot,int __flags,int __fd,__off_t __offset)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_mmap_0032f198)();
  return pvVar1;
}


// ===== 0011f340 nvmlInitWithFlags =====

/* WARNING: Switch with 1 destination removed at 0x0011f340 */

int nvmlInitWithFlags(uint param_1)

{
  int iVar1;
  __pid_t _Var2;
  undefined8 uVar3;
  long lVar4;
  int iVar5;
  float fVar6;
  float fStack_3c;
  
  FUN_002931e0(&DAT_003807b0,FUN_0012ee90);
  FUN_0012f510();
  do {
    iVar1 = FUN_00291820(&DAT_003807c0,1,0);
  } while (iVar1 != 0);
  _Var2 = getpid();
  if ((DAT_00380888 == _Var2) && (DAT_00380888 != 0)) {
    if (DAT_012148d4 == 0) goto LAB_0012098a;
    if ((DAT_01214898 == 0) && ((param_1 & 4) != 0)) {
      thunk_FUN_00293110(&DAT_003807c8);
      iVar1 = FUN_0019c370(param_1);
      goto joined_r0x00120abe;
    }
    iVar1 = 0;
    if (DAT_01216a78 < 5) {
      iVar5 = DAT_012148d4 + 1;
      DAT_012148d4 = iVar5;
      if (DAT_01216a78 != 4) goto LAB_00120a80;
      fStack_3c = DAT_00298548;
    }
    else {
      fVar6 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      fStack_3c = DAT_00298548;
      FUN_002340f0((double)(fVar6 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s(void) ()\n","DEBUG",lVar4,
                   "nvml.c",0x186,"nvmlInitWithFlags");
      iVar5 = DAT_012148d4 + 1;
      DAT_012148d4 = iVar5;
      if (DAT_01216a78 < 4) goto LAB_00120a80;
    }
    DAT_012148d4 = iVar5;
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar6 * fStack_3c),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n",&DAT_002983c2
                 ,lVar4,"nvml.c",0x18a,iVar5);
  }
  else {
    DAT_012148d4 = 0;
LAB_0012098a:
    thunk_FUN_00293020(&DAT_003807c8);
    thunk_FUN_00293110(&DAT_003807c8);
    iVar1 = FUN_001201a0(param_1,_Var2);
joined_r0x00120abe:
    if (iVar1 == 0) {
      DAT_012148d4 = DAT_012148d4 + 1;
    }
    thunk_FUN_00293190(&DAT_003807c8);
  }
  if (4 < DAT_01216a78) {
    uVar3 = nvmlErrorString(iVar1);
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar6 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar4,"nvml.c",
                 0x18e,iVar1,uVar3);
  }
LAB_00120a80:
  FUN_00291830(&DAT_003807c0,0);
  FUN_0012f530();
  return iVar1;
}


// ===== 0011f350 getmntent_r =====

void getmntent_r(void)

{
  (*(code *)PTR_getmntent_r_0032f1a8)();
  return;
}


// ===== 0011f360 dup2 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int dup2(int __fd,int __fd2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_dup2_0032f1b0)();
  return iVar1;
}


// ===== 0011f370 send =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t send(int __fd,void *__buf,size_t __n,int __flags)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_send_0032f1b8)();
  return sVar1;
}


// ===== 0011f380 strchr =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strchr(char *__s,int __c)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strchr_0032f1c0)();
  return pcVar1;
}


// ===== 0011f390 printf =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_printf_0032f1c8)();
  return iVar1;
}


// ===== 0011f3a0 warnx =====

void warnx(void)

{
  (*(code *)PTR_warnx_0032f1d0)();
  return;
}


// ===== 0011f3b0 pthread_setspecific =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_setspecific(pthread_key_t __key,void *__pointer)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_setspecific_0032f1d8)();
  return iVar1;
}


// ===== 0011f3c0 pthread_mutex_destroy =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_destroy(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_mutex_destroy_0032f1e0)();
  return iVar1;
}


// ===== 0011f3d0 symlink =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int symlink(char *__from,char *__to)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_symlink_0032f1e8)();
  return iVar1;
}


// ===== 0011f3e0 __fxstatat =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int __fxstatat(int __ver,int __fildes,char *__filename,stat *__stat_buf,int __flag)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR___fxstatat_0032f1f0)();
  return iVar1;
}


// ===== 0011f3f0 snprintf =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_snprintf_0032f1f8)();
  return iVar1;
}


// ===== 0011f400 pthread_mutexattr_init =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutexattr_init(pthread_mutexattr_t *__attr)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_mutexattr_init_0032f200)();
  return iVar1;
}


// ===== 0011f410 nanosleep =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int nanosleep(timespec *__requested_time,timespec *__remaining)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_nanosleep_0032f208)();
  return iVar1;
}


// ===== 0011f420 strrchr =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strrchr(char *__s,int __c)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strrchr_0032f210)();
  return pcVar1;
}


// ===== 0011f430 uname =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int uname(utsname *__name)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_uname_0032f218)();
  return iVar1;
}


// ===== 0011f440 lseek =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__off_t lseek(int __fd,__off_t __offset,int __whence)

{
  __off_t _Var1;
  
  _Var1 = (*(code *)PTR_lseek_0032f220)();
  return _Var1;
}


// ===== 0011f450 gettimeofday =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int gettimeofday(timeval *__tv,__timezone_ptr_t __tz)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_gettimeofday_0032f228)();
  return iVar1;
}


// ===== 0011f460 __assert_fail =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __assert_fail(char *__assertion,char *__file,uint __line,char *__function)

{
  (*(code *)PTR___assert_fail_0032f230)();
  return;
}


// ===== 0011f470 iopl =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int iopl(int __level)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_iopl_0032f238)();
  return iVar1;
}


// ===== 0011f480 fputs =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fputs(char *__s,FILE *__stream)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fputs_0032f240)();
  return iVar1;
}


// ===== 0011f490 htonl =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint32_t htonl(uint32_t __hostlong)

{
  uint32_t uVar1;
  
  uVar1 = (*(code *)PTR_htonl_0032f248)();
  return uVar1;
}


// ===== 0011f4a0 memset =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memset_0032f250)();
  return pvVar1;
}


// ===== 0011f4b0 geteuid =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__uid_t geteuid(void)

{
  __uid_t _Var1;
  
  _Var1 = (*(code *)PTR_geteuid_0032f258)();
  return _Var1;
}


// ===== 0011f4c0 fscanf =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fscanf(FILE *__stream,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fscanf_0032f260)();
  return iVar1;
}


// ===== 0011f4d0 ioctl =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ioctl(int __fd,ulong __request,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_ioctl_0032f268)();
  return iVar1;
}


// ===== 0011f4e0 strnlen =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_strnlen_0032f270)();
  return sVar1;
}


// ===== 0011f4f0 scandir =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int scandir(char *__dir,dirent ***__namelist,__selector *__selector,__cmp *__cmp)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_scandir_0032f278)();
  return iVar1;
}


// ===== 0011f500 strncat =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strncat(char *__dest,char *__src,size_t __n)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strncat_0032f280)();
  return pcVar1;
}


// ===== 0011f510 pthread_rwlock_trywrlock =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlock_trywrlock(pthread_rwlock_t *__rwlock)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_rwlock_trywrlock_0032f288)();
  return iVar1;
}


// ===== 0011f520 close =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_close_0032f290)();
  return iVar1;
}


// ===== 0011f530 rewinddir =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void rewinddir(DIR *__dirp)

{
  (*(code *)PTR_rewinddir_0032f298)();
  return;
}


// ===== 0011f540 posix_spawn =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int posix_spawn(pid_t *__pid,char *__path,posix_spawn_file_actions_t *__file_actions,
               posix_spawnattr_t *__attrp,char **__argv,char **__envp)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_posix_spawn_0032f2a0)();
  return iVar1;
}


// ===== 0011f550 strspn =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strspn(char *__s,char *__accept)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_strspn_0032f2a8)();
  return sVar1;
}


// ===== 0011f560 sched_setaffinity =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sched_setaffinity(__pid_t __pid,size_t __cpusetsize,cpu_set_t *__cpuset)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_sched_setaffinity_0032f2b0)();
  return iVar1;
}


// ===== 0011f570 closedir =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int closedir(DIR *__dirp)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_closedir_0032f2b8)();
  return iVar1;
}


// ===== 0011f580 fputc =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fputc(int __c,FILE *__stream)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fputc_0032f2c0)();
  return iVar1;
}


// ===== 0011f590 strcspn =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strcspn(char *__s,char *__reject)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_strcspn_0032f2c8)();
  return sVar1;
}


// ===== 0011f5a0 read =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_read_0032f2d0)();
  return sVar1;
}


// ===== 0011f5b0 memcmp =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int memcmp(void *__s1,void *__s2,size_t __n)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_memcmp_0032f2d8)();
  return iVar1;
}


// ===== 0011f5c0 fgets =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * fgets(char *__s,int __n,FILE *__stream)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_fgets_0032f2e0)();
  return pcVar1;
}


// ===== 0011f5d0 pthread_cond_signal =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_cond_signal(pthread_cond_t *__cond)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_cond_signal_0032f2e8)();
  return iVar1;
}


// ===== 0011f5e0 pthread_rwlock_wrlock =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlock_wrlock(pthread_rwlock_t *__rwlock)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_rwlock_wrlock_0032f2f0)();
  return iVar1;
}


// ===== 0011f5f0 getsockopt =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int getsockopt(int __fd,int __level,int __optname,void *__optval,socklen_t *__optlen)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_getsockopt_0032f2f8)();
  return iVar1;
}


// ===== 0011f600 pthread_rwlock_rdlock =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlock_rdlock(pthread_rwlock_t *__rwlock)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_rwlock_rdlock_0032f300)();
  return iVar1;
}


// ===== 0011f610 strtoull =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulonglong strtoull(char *__nptr,char **__endptr,int __base)

{
  ulonglong uVar1;
  
  uVar1 = (*(code *)PTR_strtoull_0032f308)();
  return uVar1;
}


// ===== 0011f620 calloc =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * calloc(size_t __nmemb,size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_calloc_0032f310)();
  return pvVar1;
}


// ===== 0011f630 __getdelim =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__ssize_t __getdelim(char **__lineptr,size_t *__n,int __delimiter,FILE *__stream)

{
  __ssize_t _Var1;
  
  _Var1 = (*(code *)PTR___getdelim_0032f318)();
  return _Var1;
}


// ===== 0011f640 memcpy =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memcpy_0032f320)();
  return pvVar1;
}


// ===== 0011f650 strcmp =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strcmp_0032f328)();
  return iVar1;
}


// ===== 0011f660 signal =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__sighandler_t signal(int __sig,__sighandler_t __handler)

{
  __sighandler_t p_Var1;
  
  p_Var1 = (__sighandler_t)(*(code *)PTR_signal_0032f330)();
  return p_Var1;
}


// ===== 0011f670 readlinkat =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t readlinkat(int __fd,char *__path,char *__buf,size_t __len)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_readlinkat_0032f338)();
  return sVar1;
}


// ===== 0011f680 dlvsym =====

void dlvsym(void)

{
  (*(code *)PTR_dlvsym_0032f340)();
  return;
}


// ===== 0011f690 dirfd =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int dirfd(DIR *__dirp)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_dirfd_0032f348)();
  return iVar1;
}


// ===== 0011f6a0 fprintf =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fprintf(FILE *__stream,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fprintf_0032f350)();
  return iVar1;
}


// ===== 0011f6b0 syscall =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long syscall(long __sysno,...)

{
  long lVar1;
  
  lVar1 = (*(code *)PTR_syscall_0032f358)();
  return lVar1;
}


// ===== 0011f6c0 feof =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int feof(FILE *__stream)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_feof_0032f360)();
  return iVar1;
}


// ===== 0011f6d0 strtol =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long strtol(char *__nptr,char **__endptr,int __base)

{
  long lVar1;
  
  lVar1 = (*(code *)PTR_strtol_0032f368)();
  return lVar1;
}


// ===== 0011f6e0 realpath =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * realpath(char *__name,char *__resolved)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_realpath_0032f370)();
  return pcVar1;
}


// ===== 0011f6f0 sigfillset =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sigfillset(sigset_t *__set)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_sigfillset_0032f378)();
  return iVar1;
}


// ===== 0011f700 pthread_rwlockattr_setpshared =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlockattr_setpshared(pthread_rwlockattr_t *__attr,int __pshared)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_rwlockattr_setpshared_0032f380)();
  return iVar1;
}


// ===== 0011f710 __xmknod =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int __xmknod(int __ver,char *__path,__mode_t __mode,__dev_t *__dev)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR___xmknod_0032f388)();
  return iVar1;
}


// ===== 0011f720 time =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

time_t time(time_t *__timer)

{
  time_t tVar1;
  
  tVar1 = (*(code *)PTR_time_0032f390)();
  return tVar1;
}


// ===== 0011f730 fileno =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fileno(FILE *__stream)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fileno_0032f398)();
  return iVar1;
}


// ===== 0011f740 select =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int select(int __nfds,fd_set *__readfds,fd_set *__writefds,fd_set *__exceptfds,timeval *__timeout)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_select_0032f3a0)();
  return iVar1;
}


// ===== 0011f750 pwrite64 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t pwrite64(int __fd,void *__buf,size_t __n,__off64_t __offset)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_pwrite64_0032f3a8)();
  return sVar1;
}


// ===== 0011f760 __xstat =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int __xstat(int __ver,char *__filename,stat *__stat_buf)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR___xstat_0032f3b0)();
  return iVar1;
}


// ===== 0011f770 pthread_cond_init =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_cond_init(pthread_cond_t *__cond,pthread_condattr_t *__cond_attr)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_cond_init_0032f3b8)();
  return iVar1;
}


// ===== 0011f780 readdir =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

dirent * readdir(DIR *__dirp)

{
  dirent *pdVar1;
  
  pdVar1 = (dirent *)(*(code *)PTR_readdir_0032f3c0)();
  return pdVar1;
}


// ===== 0011f790 dlopen =====

void dlopen(void)

{
  (*(code *)PTR_dlopen_0032f3c8)();
  return;
}


// ===== 0011f7a0 mmap64 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * mmap64(void *__addr,size_t __len,int __prot,int __flags,int __fd,__off64_t __offset)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_mmap64_0032f3d0)();
  return pvVar1;
}


// ===== 0011f7b0 pthread_getspecific =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * pthread_getspecific(pthread_key_t __key)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_pthread_getspecific_0032f3d8)();
  return pvVar1;
}


// ===== 0011f7c0 pthread_mutex_unlock =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_unlock(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_mutex_unlock_0032f3e0)();
  return iVar1;
}


// ===== 0011f7d0 pthread_mutexattr_settype =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutexattr_settype(pthread_mutexattr_t *__attr,int __kind)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_mutexattr_settype_0032f3e8)();
  return iVar1;
}


// ===== 0011f7e0 malloc =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_malloc_0032f3f0)();
  return pvVar1;
}


// ===== 0011f7f0 strncasecmp =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncasecmp(char *__s1,char *__s2,size_t __n)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strncasecmp_0032f3f8)();
  return iVar1;
}


// ===== 0011f800 fflush =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fflush(FILE *__stream)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fflush_0032f400)();
  return iVar1;
}


// ===== 0011f810 _IO_getc =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _IO_getc(_IO_FILE *__fp)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR__IO_getc_0032f408)();
  return iVar1;
}


// ===== 0011f820 setmntent =====

void setmntent(void)

{
  (*(code *)PTR_setmntent_0032f410)();
  return;
}


// ===== 0011f830 strsep =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strsep_0032f418)();
  return pcVar1;
}


// ===== 0011f840 __isoc99_sscanf =====

void __isoc99_sscanf(void)

{
  (*(code *)PTR___isoc99_sscanf_0032f420)();
  return;
}


// ===== 0011f850 syslog =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void syslog(int __pri,char *__fmt,...)

{
  (*(code *)PTR_syslog_0032f428)();
  return;
}


// ===== 0011f860 scandir64 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int scandir64(char *__dir,dirent64 ***__namelist,__selector *__selector,__cmp *__cmp)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_scandir64_0032f430)();
  return iVar1;
}


// ===== 0011f870 __sched_cpufree =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __sched_cpufree(cpu_set_t *__set)

{
  (*(code *)PTR___sched_cpufree_0032f438)();
  return;
}


// ===== 0011f880 __fxstat =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int __fxstat(int __ver,int __fildes,stat *__stat_buf)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR___fxstat_0032f440)();
  return iVar1;
}


// ===== 0011f890 sscanf =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_sscanf_0032f448)();
  return iVar1;
}


// ===== 0011f8a0 clock_gettime =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int clock_gettime(clockid_t __clock_id,timespec *__tp)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_clock_gettime_0032f450)();
  return iVar1;
}


// ===== 0011f8b0 pthread_rwlock_unlock =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlock_unlock(pthread_rwlock_t *__rwlock)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_rwlock_unlock_0032f458)();
  return iVar1;
}


// ===== 0011f8c0 posix_spawn_file_actions_addopen =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int posix_spawn_file_actions_addopen
              (posix_spawn_file_actions_t *__file_actions,int __fd,char *__path,int __oflag,
              mode_t __mode)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_posix_spawn_file_actions_addopen_0032f460)();
  return iVar1;
}


// ===== 0011f8d0 fseek =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fseek(FILE *__stream,long __off,int __whence)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fseek_0032f468)();
  return iVar1;
}


// ===== 0011f8e0 __sched_cpualloc =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

cpu_set_t * __sched_cpualloc(size_t __count)

{
  cpu_set_t *pcVar1;
  
  pcVar1 = (cpu_set_t *)(*(code *)PTR___sched_cpualloc_0032f470)();
  return pcVar1;
}


// ===== 0011f8f0 dlclose =====

void dlclose(void)

{
  (*(code *)PTR_dlclose_0032f478)();
  return;
}


// ===== 0011f900 pthread_rwlock_timedwrlock =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlock_timedwrlock(pthread_rwlock_t *__rwlock,timespec *__abstime)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_rwlock_timedwrlock_0032f480)();
  return iVar1;
}


// ===== 0011f910 chown =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int chown(char *__file,__uid_t __owner,__gid_t __group)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_chown_0032f488)();
  return iVar1;
}


// ===== 0011f920 realloc =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * realloc(void *__ptr,size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_realloc_0032f490)();
  return pvVar1;
}


// ===== 0011f930 isalpha =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int isalpha(int param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_isalpha_0032f498)();
  return iVar1;
}


// ===== 0011f940 fdopen =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * fdopen(int __fd,char *__modes)

{
  FILE *pFVar1;
  
  pFVar1 = (FILE *)(*(code *)PTR_fdopen_0032f4a0)();
  return pFVar1;
}


// ===== 0011f950 asprintf =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int asprintf(char **__ptr,char *__fmt,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_asprintf_0032f4a8)();
  return iVar1;
}


// ===== 0011f960 munmap =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int munmap(void *__addr,size_t __len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_munmap_0032f4b0)();
  return iVar1;
}


// ===== 0011f970 pwrite =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t pwrite(int __fd,void *__buf,size_t __n,__off_t __offset)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_pwrite_0032f4b8)();
  return sVar1;
}


// ===== 0011f980 pthread_key_create =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_key_create(pthread_key_t *__key,__destr_function *__destr_function)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_key_create_0032f4c0)();
  return iVar1;
}


// ===== 0011f990 gnu_get_libc_version =====

void gnu_get_libc_version(void)

{
  (*(code *)PTR_gnu_get_libc_version_0032f4c8)();
  return;
}


// ===== 0011f9a0 poll =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int poll(pollfd *__fds,nfds_t __nfds,int __timeout)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_poll_0032f4d0)();
  return iVar1;
}


// ===== 0011f9b0 chmod =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int chmod(char *__file,__mode_t __mode)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_chmod_0032f4d8)();
  return iVar1;
}


// ===== 0011f9c0 open64 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int open64(char *__file,int __oflag,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_open64_0032f4e0)();
  return iVar1;
}


// ===== 0011f9d0 memmove =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memmove(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memmove_0032f4e8)();
  return pvVar1;
}


// ===== 0011f9e0 pread64 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t pread64(int __fd,void *__buf,size_t __nbytes,__off64_t __offset)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_pread64_0032f4f0)();
  return sVar1;
}


// ===== 0011f9f0 waitpid =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t waitpid(__pid_t __pid,int *__stat_loc,int __options)

{
  __pid_t _Var1;
  
  _Var1 = (*(code *)PTR_waitpid_0032f4f8)();
  return _Var1;
}


// ===== 0011fa00 pthread_cond_destroy =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_cond_destroy(pthread_cond_t *__cond)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_cond_destroy_0032f500)();
  return iVar1;
}


// ===== 0011fa10 mprotect =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int mprotect(void *__addr,size_t __len,int __prot)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_mprotect_0032f508)();
  return iVar1;
}


// ===== 0011fa20 open =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int open(char *__file,int __oflag,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_open_0032f510)();
  return iVar1;
}


// ===== 0011fa30 access =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int access(char *__name,int __type)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_access_0032f518)();
  return iVar1;
}


// ===== 0011fa40 nvmlShutdown =====

/* WARNING: Switch with 1 destination removed at 0x0011fa40 */

undefined4 nvmlShutdown(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  undefined8 extraout_RDX_01;
  undefined8 extraout_RDX_02;
  float fVar5;
  undefined8 uStack_40;
  
  FUN_0012f510();
  do {
    iVar1 = FUN_00291820(&DAT_003807c0,1,0);
  } while (iVar1 != 0);
  uStack_40 = extraout_RDX;
  if (DAT_003807c8 == 0) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
    if (DAT_012148d4 == 0) {
      if (DAT_01216a78 < 2) goto LAB_00120f69;
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",
                   lVar4,"nvml.c",0x228);
      uStack_40 = extraout_RDX_00;
    }
    else if (DAT_012148d4 == 1) {
      thunk_FUN_00293110(&DAT_003807c8);
      uVar2 = FUN_00120bf0();
      thunk_FUN_00293190(&DAT_003807c8);
      thunk_FUN_002931a0(&DAT_003807c8);
      uStack_40 = extraout_RDX_02;
    }
    else {
      iVar1 = DAT_012148d4 + -1;
      DAT_012148d4 = iVar1;
      if (DAT_01216a78 < 4) goto LAB_00120f69;
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n",
                   &DAT_002983c2,lVar4,"nvml.c",0x237,iVar1);
      uStack_40 = extraout_RDX_01;
    }
    if (4 < DAT_01216a78) {
      uVar3 = nvmlErrorString(uVar2);
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      uStack_40 = 0x121025;
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar4,"nvml.c",
                   0x23b,uVar2,uVar3);
    }
  }
LAB_00120f69:
  FUN_00291830(&DAT_003807c0,0,uStack_40);
  FUN_0012f530();
  return uVar2;
}


// ===== 0011fa50 pthread_rwlockattr_destroy =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlockattr_destroy(pthread_rwlockattr_t *__attr)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_rwlockattr_destroy_0032f528)();
  return iVar1;
}


// ===== 0011fa60 pthread_rwlock_timedrdlock =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlock_timedrdlock(pthread_rwlock_t *__rwlock,timespec *__abstime)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_rwlock_timedrdlock_0032f530)();
  return iVar1;
}


// ===== 0011fa70 fopen =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * fopen(char *__filename,char *__modes)

{
  FILE *pFVar1;
  
  pFVar1 = (FILE *)(*(code *)PTR_fopen_0032f538)();
  return pFVar1;
}


// ===== 0011fa80 sysconf =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long sysconf(int __name)

{
  long lVar1;
  
  lVar1 = (*(code *)PTR_sysconf_0032f540)();
  return lVar1;
}


// ===== 0011fa90 pthread_join =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_join(pthread_t __th,void **__thread_return)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_join_0032f548)();
  return iVar1;
}


// ===== 0011faa0 nvmlErrorString =====

/* WARNING: Switch with 1 destination removed at 0x0011faa0 */

char * nvmlErrorString(undefined4 param_1)

{
  switch(param_1) {
  case 0:
    return "Success";
  case 1:
    return "Uninitialized";
  case 2:
    return "Invalid Argument";
  case 3:
    return "Not Supported";
  case 4:
    return "Insufficient Permissions";
  case 5:
    return "Already Initialized";
  case 6:
    return "Not Found";
  case 7:
    return "Insufficient Size";
  case 8:
    return "Insufficient External Power";
  case 9:
    return "Driver Not Loaded";
  case 10:
    return "Timeout";
  case 0xb:
    return "Interrupt Request Issue";
  case 0xc:
    return "NVML Shared Library Not Found";
  case 0xd:
    return "Function Not Found";
  case 0xe:
    return "Corrupted infoROM";
  case 0xf:
    return "GPU is lost";
  case 0x10:
    return "GPU requires reset";
  case 0x11:
    return "GPU access blocked by the operating system";
  case 0x12:
    return "Driver/library version mismatch";
  case 0x13:
    return "In use by another client";
  case 0x14:
    return "Insufficient Memory";
  case 0x15:
    return "No data";
  case 0x16:
    return "vGPU ECC not supported";
  case 0x17:
    return "Insufficient Resources";
  case 0x18:
    return "Invalid Frequency";
  case 0x19:
    return "Argument version mismatch";
  case 0x1a:
    return "Requested functionality has been deprecated";
  case 0x1b:
    return "System is not in ready state";
  case 0x1c:
    return "No supported GPUs were found";
  case 0x1d:
    return "Resource not in correct state to perform requested operation";
  case 0x1e:
    return "Reset type is not supported for given device";
  default:
    return "Unknown Error";
  }
}


// ===== 0011fab0 vfork =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t vfork(void)

{
  __pid_t _Var1;
  
  _Var1 = (*(code *)PTR_vfork_0032f558)();
  return _Var1;
}


// ===== 0011fac0 vfprintf =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int vfprintf(FILE *__s,char *__format,__gnuc_va_list __arg)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_vfprintf_0032f560)();
  return iVar1;
}


// ===== 0011fad0 fdopendir =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DIR * fdopendir(int __fd)

{
  DIR *pDVar1;
  
  pDVar1 = (DIR *)(*(code *)PTR_fdopendir_0032f568)();
  return pDVar1;
}


// ===== 0011fae0 getsockname =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int getsockname(int __fd,sockaddr *__addr,socklen_t *__len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_getsockname_0032f570)();
  return iVar1;
}


// ===== 0011faf0 strtoul =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulong strtoul(char *__nptr,char **__endptr,int __base)

{
  ulong uVar1;
  
  uVar1 = (*(code *)PTR_strtoul_0032f578)();
  return uVar1;
}


// ===== 0011fb00 sched_getcpu =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sched_getcpu(void)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_sched_getcpu_0032f580)();
  return iVar1;
}


// ===== 0011fb10 __cxa_atexit =====

void __cxa_atexit(void)

{
  (*(code *)PTR___cxa_atexit_0032f588)();
  return;
}


// ===== 0011fb20 atoi =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int atoi(char *__nptr)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_atoi_0032f590)();
  return iVar1;
}


// ===== 0011fb30 pread =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t pread(int __fd,void *__buf,size_t __nbytes,__off_t __offset)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_pread_0032f598)();
  return sVar1;
}


// ===== 0011fb40 strcat =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcat(char *__dest,char *__src)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strcat_0032f5a0)();
  return pcVar1;
}


// ===== 0011fb50 sprintf =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_sprintf_0032f5a8)();
  return iVar1;
}


// ===== 0011fb60 exit =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void exit(int __status)

{
  (*(code *)PTR_exit_0032f5b0)();
  return;
}


// ===== 0011fb70 eventfd =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int eventfd(int __count,int __flags)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_eventfd_0032f5b8)();
  return iVar1;
}


// ===== 0011fb80 fwrite =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t fwrite(void *__ptr,size_t __size,size_t __n,FILE *__s)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_fwrite_0032f5c0)();
  return sVar1;
}


// ===== 0011fb90 pthread_mutexattr_setpshared =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutexattr_setpshared(pthread_mutexattr_t *__attr,int __pshared)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_mutexattr_setpshared_0032f5c8)();
  return iVar1;
}


// ===== 0011fba0 sched_getaffinity =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sched_getaffinity(__pid_t __pid,size_t __cpusetsize,cpu_set_t *__cpuset)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_sched_getaffinity_0032f5d0)();
  return iVar1;
}


// ===== 0011fbb0 posix_spawn_file_actions_adddup2 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int posix_spawn_file_actions_adddup2
              (posix_spawn_file_actions_t *__file_actions,int __fd,int __newfd)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_posix_spawn_file_actions_adddup2_0032f5d8)();
  return iVar1;
}


// ===== 0011fbc0 ntohl =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint32_t ntohl(uint32_t __netlong)

{
  uint32_t uVar1;
  
  uVar1 = (*(code *)PTR_ntohl_0032f5e0)();
  return uVar1;
}


// ===== 0011fbd0 strdup =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strdup(char *__s)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strdup_0032f5e8)();
  return pcVar1;
}


// ===== 0011fbe0 strerror =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strerror(int __errnum)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strerror_0032f5f0)();
  return pcVar1;
}


// ===== 0011fbf0 dlsym =====

void dlsym(void)

{
  (*(code *)PTR_dlsym_0032f5f8)();
  return;
}


// ===== 0011fc00 pthread_rwlock_destroy =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlock_destroy(pthread_rwlock_t *__rwlock)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_rwlock_destroy_0032f600)();
  return iVar1;
}


// ===== 0011fc10 sleep =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint sleep(uint __seconds)

{
  uint uVar1;
  
  uVar1 = (*(code *)PTR_sleep_0032f608)();
  return uVar1;
}


// ===== 0011fc20 pthread_mutex_init =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_init(pthread_mutex_t *__mutex,pthread_mutexattr_t *__mutexattr)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_mutex_init_0032f610)();
  return iVar1;
}


// ===== 0011fc30 pthread_rwlockattr_init =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlockattr_init(pthread_rwlockattr_t *__attr)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_rwlockattr_init_0032f618)();
  return iVar1;
}


// ===== 0011fc40 strstr =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strstr_0032f620)();
  return pcVar1;
}


// ===== 0011fc50 pthread_mutex_lock =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_lock(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_mutex_lock_0032f628)();
  return iVar1;
}


// ===== 0011fc60 dlerror =====

void dlerror(void)

{
  (*(code *)PTR_dlerror_0032f630)();
  return;
}


// ===== 0011fc70 __ctype_b_loc =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ushort ** __ctype_b_loc(void)

{
  ushort **ppuVar1;
  
  ppuVar1 = (ushort **)(*(code *)PTR___ctype_b_loc_0032f638)();
  return ppuVar1;
}


// ===== 0011fc80 usleep =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int usleep(__useconds_t __useconds)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_usleep_0032f640)();
  return iVar1;
}


// ===== 0011fc90 free =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
  (*(code *)PTR_free_0032ef38)();
  return;
}


// ===== 0011fc98 pthread_setaffinity_np =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_setaffinity_np(pthread_t __th,size_t __cpusetsize,cpu_set_t *__cpuset)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_setaffinity_np_0032ef58)();
  return iVar1;
}


// ===== 0011fca0 pthread_getaffinity_np =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_getaffinity_np(pthread_t __th,size_t __cpusetsize,cpu_set_t *__cpuset)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_getaffinity_np_0032ef88)();
  return iVar1;
}


// ===== 0011fca8 pthread_self =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

pthread_t pthread_self(void)

{
  pthread_t pVar1;
  
  pVar1 = (*(code *)PTR_pthread_self_0032efb0)();
  return pVar1;
}


// ===== 0011fcb0 connect =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int connect(int __fd,sockaddr *__addr,socklen_t __len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_connect_0032efc8)();
  return iVar1;
}


// ===== 0011fcb8 __cxa_finalize =====

void __cxa_finalize(void)

{
  (*(code *)PTR___cxa_finalize_0032efd8)();
  return;
}


// ===== 0011fcc0 socket =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int socket(int __domain,int __type,int __protocol)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_socket_0032efe8)();
  return iVar1;
}


// ===== 0011fcd0 entry =====

char * processEntry entry(void)

{
  return "Unknown Error";
}


// ===== 0011fcd8 FUN_0011fcd8 =====

void FUN_0011fcd8(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0011fce2 FUN_0011fce2 =====

void FUN_0011fce2(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0011fcec default =====

undefined8 switchD_0013225f::default(void)

{
  return 999;
}


// ===== 0011fcf7 default =====

undefined8 switchD_001b7155::default(void)

{
  return 2;
}


// ===== 0011fd02 default =====

undefined8 switchD_001c390a::default(void)

{
  return 2;
}


// ===== 0011fd08 default =====

undefined8 switchD_001e7b4a::default(void)

{
  return 2;
}


// ===== 0011fd13 default =====

undefined8 switchD_00219b00::default(void)

{
  return 999;
}


// ===== 0011fd1e default =====

undefined8 switchD_0021e6f1::default(void)

{
  return 3;
}


// ===== 0011fd29 default =====

undefined8 switchD_00225f1e::default(void)

{
  return 2;
}


// ===== 0011fd34 default =====

undefined8 switchD_0022989b::default(void)

{
  return 999;
}


// ===== 0011fd3f default =====

undefined8 switchD_00229bcd::default(void)

{
  return 999;
}


// ===== 0011fd4a FUN_0011fd4a =====

void FUN_0011fd4a(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0011fd60 FUN_0011fd60 =====

void FUN_0011fd60(void)

{
  FUN_002925a0();
  FUN_00292870();
  return;
}


// ===== 0011fd70 FUN_0011fd70 =====

void FUN_0011fd70(void)

{
  if (PTR___gmon_start___0032ef70 != (undefined *)0x0) {
    (*(code *)PTR___gmon_start___0032ef70)();
  }
  return;
}


// ===== 0011fd90 FUN_0011fd90 =====

/* WARNING: Removing unreachable block (ram,0x0011fda3) */
/* WARNING: Removing unreachable block (ram,0x0011fdaf) */

void FUN_0011fd90(void)

{
  return;
}


// ===== 0011fdc0 FUN_0011fdc0 =====

/* WARNING: Removing unreachable block (ram,0x0011fde4) */
/* WARNING: Removing unreachable block (ram,0x0011fdf0) */

void FUN_0011fdc0(void)

{
  return;
}


// ===== 0011fe00 FUN_0011fe00 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0011fe00(void)

{
  if (DAT_003807a0 == '\0') {
    if (PTR___cxa_finalize_0032efd8 != (undefined *)0x0) {
      __cxa_finalize(PTR_LOOP_0032f660);
    }
    while (DAT_003807a8 == 0) {
      DAT_003807a8 = 1;
      (*_UNK_00324490)();
    }
    FUN_0011fd90();
    DAT_003807a0 = 1;
    return;
  }
  return;
}


// ===== 0011fe90 thunk_FUN_0011fdc0 =====

/* WARNING: Removing unreachable block (ram,0x0011fde4) */
/* WARNING: Removing unreachable block (ram,0x0011fdf0) */

void thunk_FUN_0011fdc0(void)

{
  return;
}


// ===== 0011fea0 FUN_0011fea0 =====

undefined8 FUN_0011fea0(void)

{
  __pid_t _Var1;
  
  _Var1 = getpid();
  if (DAT_003807c8 != 0) {
    thunk_FUN_002930c0(&DAT_003807c8);
    if (((DAT_012148d4 != 0) && (DAT_00380888 == _Var1)) && (DAT_00380888 != 0)) {
      FUN_00291840(&DAT_003807d0);
      return 0;
    }
    thunk_FUN_00293180(&DAT_003807c8);
  }
  return 1;
}


// ===== 0011ff20 FUN_0011ff20 =====

void FUN_0011ff20(void)

{
  FUN_00291850(&DAT_003807d0);
  thunk_FUN_00293180(&DAT_003807c8);
  return;
}


// ===== 0011ff50 nvmlSystemGetNVMLVersion =====

undefined8 nvmlSystemGetNVMLVersion(undefined8 *param_1,uint param_2)

{
  undefined8 uVar1;
  
  if (param_1 == (undefined8 *)0x0) {
    uVar1 = 2;
  }
  else {
    uVar1 = 7;
    if (0xc < param_2) {
      *(undefined4 *)(param_1 + 1) = 0x35302e31;
      *param_1 = 0x372e3539352e3331;
      *(undefined1 *)((long)param_1 + 0xc) = 0;
      return 0;
    }
  }
  return uVar1;
}


// ===== 0011ff90 nvmlErrorString =====

char * nvmlErrorString(undefined4 param_1)

{
  switch(param_1) {
  case 0:
    return "Success";
  case 1:
    return "Uninitialized";
  case 2:
    return "Invalid Argument";
  case 3:
    return "Not Supported";
  case 4:
    return "Insufficient Permissions";
  case 5:
    return "Already Initialized";
  case 6:
    return "Not Found";
  case 7:
    return "Insufficient Size";
  case 8:
    return "Insufficient External Power";
  case 9:
    return "Driver Not Loaded";
  case 10:
    return "Timeout";
  case 0xb:
    return "Interrupt Request Issue";
  case 0xc:
    return "NVML Shared Library Not Found";
  case 0xd:
    return "Function Not Found";
  case 0xe:
    return "Corrupted infoROM";
  case 0xf:
    return "GPU is lost";
  case 0x10:
    return "GPU requires reset";
  case 0x11:
    return "GPU access blocked by the operating system";
  case 0x12:
    return "Driver/library version mismatch";
  case 0x13:
    return "In use by another client";
  case 0x14:
    return "Insufficient Memory";
  case 0x15:
    return "No data";
  case 0x16:
    return "vGPU ECC not supported";
  case 0x17:
    return "Insufficient Resources";
  case 0x18:
    return "Invalid Frequency";
  case 0x19:
    return "Argument version mismatch";
  case 0x1a:
    return "Requested functionality has been deprecated";
  case 0x1b:
    return "System is not in ready state";
  case 0x1c:
    return "No supported GPUs were found";
  case 0x1d:
    return "Resource not in correct state to perform requested operation";
  case 0x1e:
    return "Reset type is not supported for given device";
  default:
    return "Unknown Error";
  }
}


// ===== 001201a0 FUN_001201a0 =====

int FUN_001201a0(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  undefined8 uVar5;
  float fVar6;
  float local_60;
  undefined4 local_58;
  char local_54;
  char local_48 [24];
  
  FUN_002918b0();
  FUN_002341a0("__NVML_DBG_LVL","__NVML_DBG_APPEND","__NVML_DBG_FILE",1);
  if (4 < DAT_01216a78) {
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar6 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s(void) ()\n","DEBUG",lVar4,"nvml.c",
                 0xa5,"initWithFlags_Underlock");
  }
  memset(&DAT_00380800,0,0xe95ca8);
  DAT_00380888 = param_2;
  iVar2 = FUN_00292de0("__NVML_CRAY_PSTATE",&local_58,0x10);
  if ((((iVar2 == 0) || (iVar2 = FUN_00292de0("__NVIDIA_NVML_3373",&local_58,0x10), iVar2 == 0)) &&
      (local_58 == 0x32313732)) && ((local_54 == '\0' && (DAT_003807b4 = 1, 3 < DAT_01216a78)))) {
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar4,"nvml.c",0xbb);
  }
  iVar2 = FUN_00292de0("__NVML_USE_RUSD",local_48,0x10);
  if ((iVar2 == 0) && (lVar4 = strtol(local_48,(char **)0x0,10), (int)lVar4 == 0)) {
    DAT_0032f668 = 0;
  }
  if (3 < DAT_01216a78) {
    uVar3 = FUN_00292de0("__NVML_ONLY_DAEMON_PERSISTENCE_MODE",&local_58,0x10);
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n",
                 &DAT_002983c2,lVar4,"nvml.c",0xfc,uVar3);
  }
  iVar2 = FUN_00292de0("__NVML_ONLY_DAEMON_PERSISTENCE_MODE",&local_58,0x10);
  if (((iVar2 == 0) && ((char)local_58 == '1')) && (local_58._1_1_ == '\0')) {
    DAT_0121489c = 1;
    if (3 < DAT_01216a78) {
      fVar6 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                   &DAT_002983c2,lVar4,"nvml.c",0x102);
      goto LAB_00120280;
    }
  }
  else {
LAB_00120280:
    if (3 < DAT_01216a78) {
      fVar6 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                   &DAT_002983c2,lVar4,"nvml.c",0x106);
    }
  }
  iVar2 = FUN_0012f1e0();
  if ((iVar2 != 0) && (1 < DAT_01216a78)) {
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","ERROR",
                 lVar4,"nvml.c",0x10c,iVar2);
    iVar2 = FUN_0019c370(param_1);
    if (iVar2 == 0) goto LAB_00120504;
LAB_00120303:
    if (DAT_01216a78 < 2) goto LAB_0012030c;
    uVar5 = nvmlErrorString(iVar2);
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    local_60 = DAT_00298548;
    FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d\n","ERROR"
                 ,lVar4,"nvml.c",0x116,uVar5,iVar2);
LAB_00120423:
    if (4 < DAT_01216a78) {
      uVar5 = nvmlErrorString(iVar2);
      fVar6 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar6 * local_60),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar4,"nvml.c",
                   0x129,iVar2,uVar5,lVar4);
    }
LAB_0012030c:
    FUN_00233fd0();
    FUN_0012f390();
    return iVar2;
  }
  iVar2 = FUN_0019c370(param_1);
  if (iVar2 != 0) goto LAB_00120303;
LAB_00120504:
  DAT_012148a8 = &DAT_012148a8;
  DAT_012148b0 = &DAT_012148a8;
  if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x28) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x28) + 0x100), pcVar1 == (code *)0x0)) {
    if (DAT_01216a78 < 5) goto LAB_00120648;
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","DEBUG",
                 lVar4,"nvml.c",0x121,3);
  }
  else {
    iVar2 = (*pcVar1)(DAT_012164a0,&DAT_012148b8);
    if (iVar2 != 0) {
      if (DAT_01216a78 < 5) {
        if (iVar2 == 3) goto LAB_00120648;
        goto LAB_0012030c;
      }
      fVar6 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      local_60 = DAT_00298548;
      FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","DEBUG",
                   lVar4,"nvml.c",0x121,iVar2);
      if (iVar2 != 3) goto LAB_00120423;
    }
  }
  if (4 < DAT_01216a78) {
    uVar5 = nvmlErrorString(0);
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar6 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar4,"nvml.c",
                 0x129,0,uVar5);
  }
LAB_00120648:
  iVar2 = FUN_00249bb0(0xffffffff,0);
  if (iVar2 == 0) {
    DAT_003807dc = 1;
  }
  else if (1 < DAT_01216a78) {
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",
                 lVar4,"nvml.c",0x135);
  }
  return 0;
}


// ===== 00120910 nvmlInitWithFlags =====

int nvmlInitWithFlags(uint param_1)

{
  int iVar1;
  __pid_t _Var2;
  undefined8 uVar3;
  long lVar4;
  int iVar5;
  float fVar6;
  float local_3c;
  
  FUN_002931e0(&DAT_003807b0,FUN_0012ee90);
  FUN_0012f510();
  do {
    iVar1 = FUN_00291820(&DAT_003807c0,1,0);
  } while (iVar1 != 0);
  _Var2 = getpid();
  if ((DAT_00380888 == _Var2) && (DAT_00380888 != 0)) {
    if (DAT_012148d4 == 0) goto LAB_0012098a;
    if ((DAT_01214898 == 0) && ((param_1 & 4) != 0)) {
      thunk_FUN_00293110(&DAT_003807c8);
      iVar1 = FUN_0019c370(param_1);
      goto joined_r0x00120abe;
    }
    iVar1 = 0;
    if (DAT_01216a78 < 5) {
      iVar5 = DAT_012148d4 + 1;
      DAT_012148d4 = iVar5;
      if (DAT_01216a78 != 4) goto LAB_00120a80;
      local_3c = DAT_00298548;
    }
    else {
      fVar6 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      local_3c = DAT_00298548;
      FUN_002340f0((double)(fVar6 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s(void) ()\n","DEBUG",lVar4,
                   "nvml.c",0x186,"nvmlInitWithFlags");
      iVar5 = DAT_012148d4 + 1;
      DAT_012148d4 = iVar5;
      if (DAT_01216a78 < 4) goto LAB_00120a80;
    }
    DAT_012148d4 = iVar5;
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar6 * local_3c),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n",&DAT_002983c2,
                 lVar4,"nvml.c",0x18a,iVar5);
  }
  else {
    DAT_012148d4 = 0;
LAB_0012098a:
    thunk_FUN_00293020(&DAT_003807c8);
    thunk_FUN_00293110(&DAT_003807c8);
    iVar1 = FUN_001201a0(param_1,_Var2);
joined_r0x00120abe:
    if (iVar1 == 0) {
      DAT_012148d4 = DAT_012148d4 + 1;
    }
    thunk_FUN_00293190(&DAT_003807c8);
  }
  if (4 < DAT_01216a78) {
    uVar3 = nvmlErrorString(iVar1);
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar4 = syscall(0xba);
    FUN_002340f0((double)(fVar6 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar4,"nvml.c",
                 0x18e,iVar1,uVar3);
  }
LAB_00120a80:
  FUN_00291830(&DAT_003807c0,0);
  FUN_0012f530();
  return iVar1;
}


// ===== 00120be0 nvmlInit_v2 =====

void nvmlInit_v2(void)

{
  nvmlInitWithFlags(0);
  return;
}


// ===== 00120bf0 FUN_00120bf0 =====

undefined8 FUN_00120bf0(void)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  float fVar7;
  
  if (4 < DAT_01216a78) {
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tEntering %s(void) ()\n","DEBUG",lVar6,"nvml.c",
                 0x1c5,"shutdown_Underlock");
  }
  DAT_012148d4 = DAT_012148d4 + -1;
  if (3 < DAT_01216a78) {
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar6,"nvml.c",0x1ca);
  }
  iVar4 = FUN_00249fc0();
  if ((iVar4 != 0) && (1 < DAT_01216a78)) {
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",
                 lVar6,"nvml.c",0x1d1);
  }
  DAT_003807dc = 0;
  thunk_FUN_00293190(&DAT_003807c8);
  do {
    iVar4 = FUN_00291820(&DAT_003807d0,0,0);
  } while (iVar4 != 0);
  FUN_0012d880();
  thunk_FUN_00293110(&DAT_003807c8);
  if (((DAT_012164a0 != 0) &&
      (((*(long *)(DAT_012164a0 + 0x28) == 0 ||
        (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x28) + 0x120), pcVar1 == (code *)0x0)) ||
       ((*pcVar1)(), DAT_012164a0 != 0)))) &&
     ((*(long *)(DAT_012164a0 + 0x20) != 0 &&
      (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x20) + 0xb0), pcVar1 != (code *)0x0)))) {
    (*pcVar1)();
  }
  if (4 < DAT_01216a78) {
    uVar5 = nvmlErrorString(0);
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar6,"nvml.c",
                 0x1f1,0,uVar5);
  }
  FUN_00233fd0();
  plVar3 = DAT_012148a8;
  while (DAT_012148a8 = plVar3, (long **)plVar3 != &DAT_012148a8) {
    plVar2 = (long *)plVar3[1];
    *(long **)(*plVar3 + 8) = plVar2;
    *plVar2 = *plVar3;
    free(plVar3 + -100);
    plVar3 = DAT_012148a8;
  }
  memset(&DAT_00380800,0,0xe95ca8);
  FUN_0012f390();
  FUN_00133630();
  return 0;
}


// ===== 00120ef0 nvmlShutdown =====

undefined4 nvmlShutdown(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  undefined8 extraout_RDX_01;
  undefined8 extraout_RDX_02;
  float fVar5;
  undefined8 uStack_40;
  
  FUN_0012f510();
  do {
    iVar1 = FUN_00291820(&DAT_003807c0,1,0);
  } while (iVar1 != 0);
  uStack_40 = extraout_RDX;
  if (DAT_003807c8 == 0) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
    if (DAT_012148d4 == 0) {
      if (DAT_01216a78 < 2) goto LAB_00120f69;
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",
                   lVar4,"nvml.c",0x228);
      uStack_40 = extraout_RDX_00;
    }
    else if (DAT_012148d4 == 1) {
      thunk_FUN_00293110(&DAT_003807c8);
      uVar2 = FUN_00120bf0();
      thunk_FUN_00293190(&DAT_003807c8);
      thunk_FUN_002931a0(&DAT_003807c8);
      uStack_40 = extraout_RDX_02;
    }
    else {
      iVar1 = DAT_012148d4 + -1;
      DAT_012148d4 = iVar1;
      if (DAT_01216a78 < 4) goto LAB_00120f69;
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n",
                   &DAT_002983c2,lVar4,"nvml.c",0x237,iVar1);
      uStack_40 = extraout_RDX_01;
    }
    if (4 < DAT_01216a78) {
      uVar3 = nvmlErrorString(uVar2);
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      uStack_40 = 0x121025;
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),
                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tReturning %d (%s)\n","DEBUG",lVar4,"nvml.c",
                   0x23b,uVar2,uVar3);
    }
  }
LAB_00120f69:
  FUN_00291830(&DAT_003807c0,0,uStack_40);
  FUN_0012f530();
  return uVar2;
}


// ===== 00121120 nvmlInit =====

int nvmlInit(void)

{
  int iVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  
  if (3 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar3,"nvml.c",0x1a0);
  }
  iVar1 = nvmlInit_v2();
  if (iVar1 == 0) {
    if (DAT_01216a78 < 4) {
      iVar2 = FUN_001906e0();
    }
    else {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                   &DAT_002983c2,lVar3,"nvml.c",0x1a4);
      iVar2 = FUN_001906e0();
    }
    iVar1 = 0;
    if (iVar2 != 0) {
      nvmlShutdown();
      return iVar2;
    }
  }
  return iVar1;
}


// ===== 00121250 nvmlInternalGetExportTable =====

undefined8 nvmlInternalGetExportTable(undefined8 *param_1,long *param_2)

{
  uint uVar1;
  ulong uVar2;
  undefined **ppuVar3;
  long *plVar4;
  
  if ((param_1 != (undefined8 *)0x0) && (param_2 != (long *)0x0)) {
    *param_1 = 0;
    plVar4 = &DAT_00298570;
    uVar2 = 0;
    ppuVar3 = &PTR_DAT_003298c0;
    while( true ) {
      if ((plVar4 != (long *)0x0) && (param_2[1] == plVar4[1] && *param_2 == *plVar4)) {
        *param_1 = (&PTR_DAT_003298c8)[uVar2 * 2];
        return 0;
      }
      uVar1 = (int)uVar2 + 1;
      uVar2 = (ulong)uVar1;
      ppuVar3 = ppuVar3 + 2;
      if (uVar1 == 3) break;
      plVar4 = (long *)*ppuVar3;
    }
  }
  return 2;
}


// ===== 001212c0 FUN_001212c0 =====

void FUN_001212c0(long param_1,int param_2,char *param_3)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 0x10);
  for (piVar2 = piVar1; piVar2 != (int *)0x0; piVar2 = *(int **)(piVar2 + 0x12)) {
    if (param_2 == *piVar2) {
      return;
    }
  }
  piVar2 = malloc(0x50);
  if (piVar2 == (int *)0x0) {
    return;
  }
  *piVar2 = param_2;
  strncpy((char *)(piVar2 + 1),param_3,0x3f);
  *(int **)(piVar2 + 0x12) = piVar1;
  *(int **)(param_1 + 0x10) = piVar2;
  *(undefined1 *)((long)piVar2 + 0x43) = 0;
  return;
}


// ===== 00121360 FUN_00121360 =====

undefined4 FUN_00121360(undefined4 *param_1)

{
  return *param_1;
}


// ===== 00121370 FUN_00121370 =====

bool FUN_00121370(int *param_1,int *param_2)

{
  return *param_1 == *param_2;
}


// ===== 00121380 free =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
  (*(code *)PTR_free_0032ef38)();
  return;
}


// ===== 00121390 free =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
  (*(code *)PTR_free_0032ef38)();
  return;
}


// ===== 001213a0 FUN_001213a0 =====

void * FUN_001213a0(long param_1,undefined4 param_2)

{
  int iVar1;
  void *pvVar2;
  undefined4 *__ptr;
  undefined4 local_2c;
  
  if (param_1 != 0) {
    local_2c = param_2;
    pvVar2 = (void *)FUN_00234de0(param_1,&local_2c);
    if (pvVar2 != (void *)0x0) {
      return pvVar2;
    }
    pvVar2 = calloc(0x40,1);
    if (pvVar2 != (void *)0x0) {
      __ptr = malloc(4);
      if (__ptr == (undefined4 *)0x0) {
        free(pvVar2);
        return (void *)0x0;
      }
      *__ptr = local_2c;
      iVar1 = FUN_00234c10(param_1,__ptr,pvVar2);
      if (iVar1 == 0) {
        return pvVar2;
      }
      free(pvVar2);
      free(__ptr);
      return (void *)0x0;
    }
  }
  return (void *)0x0;
}


// ===== 00121460 FUN_00121460 =====

undefined8 FUN_00121460(undefined8 param_1,undefined8 *param_2,int param_3)

{
  int *piVar1;
  undefined8 *puVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  int *piVar6;
  undefined8 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint local_40;
  uint local_3c;
  
  if (param_3 == 0) {
    return 0;
  }
  piVar6 = (int *)(param_2 + 2);
  uVar8 = 0;
  uVar11 = 0;
  uVar10 = 0;
  uVar9 = 0;
  local_40 = 0;
  local_3c = 0;
  do {
    uVar8 = uVar8 + (*piVar6 != -1);
    uVar9 = uVar9 + (piVar6[0x14] != -1);
    uVar10 = uVar10 + (piVar6[0x28] != -1);
    uVar11 = uVar11 + (piVar6[0x3c] != -1);
    local_3c = local_3c + (piVar6[0x50] != -1);
    piVar1 = piVar6 + 100;
    piVar6 = piVar6 + 0x7a;
    local_40 = local_40 + (*piVar1 != -1);
  } while (piVar6 != (int *)(param_2 + (ulong)(param_3 - 1) * 0x3d + 0x3f));
  puVar2 = param_2 + (ulong)(param_3 - 1) * 0x3d + 0x3d;
  do {
    iVar3 = *(int *)(param_2 + 2);
    if (iVar3 != -1) {
      uVar4 = *(uint *)(param_2 + 1);
      uVar5 = *param_2;
      puVar7 = (undefined8 *)FUN_001213a0(param_1,iVar3);
      if (puVar7 == (undefined8 *)0x0) {
        return 6;
      }
      *(int *)(puVar7 + 1) = iVar3;
      *puVar7 = uVar5;
      puVar7[2] = (double)uVar4 / (double)uVar8 + (double)puVar7[2];
    }
    iVar3 = *(int *)(param_2 + 0xc);
    if (iVar3 != -1) {
      uVar4 = *(uint *)(param_2 + 0xb);
      uVar5 = *param_2;
      puVar7 = (undefined8 *)FUN_001213a0(param_1,iVar3);
      if (puVar7 == (undefined8 *)0x0) {
        return 6;
      }
      *(int *)(puVar7 + 1) = iVar3;
      *puVar7 = uVar5;
      puVar7[3] = (double)uVar4 / (double)uVar9 + (double)puVar7[3];
    }
    iVar3 = *(int *)(param_2 + 0x16);
    if (iVar3 != -1) {
      uVar4 = *(uint *)(param_2 + 0x15);
      uVar5 = *param_2;
      puVar7 = (undefined8 *)FUN_001213a0(param_1,iVar3);
      if (puVar7 == (undefined8 *)0x0) {
        return 6;
      }
      *(int *)(puVar7 + 1) = iVar3;
      *puVar7 = uVar5;
      puVar7[4] = (double)uVar4 / (double)uVar10 + (double)puVar7[4];
    }
    iVar3 = *(int *)(param_2 + 0x20);
    if (iVar3 != -1) {
      uVar4 = *(uint *)(param_2 + 0x1f);
      uVar5 = *param_2;
      puVar7 = (undefined8 *)FUN_001213a0(param_1,iVar3);
      if (puVar7 == (undefined8 *)0x0) {
        return 6;
      }
      *(int *)(puVar7 + 1) = iVar3;
      *puVar7 = uVar5;
      puVar7[5] = (double)uVar4 / (double)uVar11 + (double)puVar7[5];
    }
    iVar3 = *(int *)(param_2 + 0x2a);
    if (iVar3 != -1) {
      uVar4 = *(uint *)(param_2 + 0x29);
      uVar5 = *param_2;
      puVar7 = (undefined8 *)FUN_001213a0(param_1,iVar3);
      if (puVar7 == (undefined8 *)0x0) {
        return 6;
      }
      *(int *)(puVar7 + 1) = iVar3;
      *puVar7 = uVar5;
      puVar7[6] = (double)uVar4 / (double)local_3c + (double)puVar7[6];
    }
    iVar3 = *(int *)(param_2 + 0x34);
    if (iVar3 != -1) {
      uVar4 = *(uint *)(param_2 + 0x33);
      uVar5 = *param_2;
      puVar7 = (undefined8 *)FUN_001213a0(param_1,iVar3);
      if (puVar7 == (undefined8 *)0x0) {
        return 6;
      }
      *(int *)(puVar7 + 1) = iVar3;
      *puVar7 = uVar5;
      puVar7[7] = (double)uVar4 / (double)local_40 + (double)puVar7[7];
    }
    param_2 = param_2 + 0x3d;
  } while (param_2 != puVar2);
  return 0;
}


// ===== 001217f0 thunk_FUN_00121800 =====

int * thunk_FUN_00121800(int *param_1,int param_2)

{
  while( true ) {
    if (param_1 == (int *)0x0) {
      return (int *)0x0;
    }
    if (*param_1 == param_2) break;
    param_1 = *(int **)(param_1 + 2);
  }
  return param_1;
}


// ===== 00121800 FUN_00121800 =====

int * FUN_00121800(int *param_1,int param_2)

{
  while( true ) {
    if (param_1 == (int *)0x0) {
      return (int *)0x0;
    }
    if (*param_1 == param_2) break;
    param_1 = *(int **)(param_1 + 2);
  }
  return param_1;
}


// ===== 00121820 FUN_00121820 =====

undefined8 FUN_00121820(undefined8 param_1,long param_2,uint param_3,undefined8 *param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  int *piVar6;
  char *__src;
  int local_80;
  char local_78 [63];
  undefined1 local_39;
  
  if (param_3 != 0) {
    local_80 = 0;
    __src = (char *)(param_2 + 0x18);
    do {
      iVar2 = *(int *)(__src + -8);
      iVar3 = *(int *)(__src + -4);
      if ((iVar2 != -1) && (iVar3 != 0)) {
        strncpy(local_78,__src,0x3f);
        local_39 = 0;
        piVar6 = (int *)thunk_FUN_00121800(*param_4,iVar2);
        if (piVar6 == (int *)0x0) {
          piVar6 = malloc(0x18);
          if (piVar6 == (int *)0x0) {
            return 0x14;
          }
          uVar4 = *param_4;
          *piVar6 = iVar2;
          piVar6[4] = 0;
          piVar6[5] = 0;
          piVar6[1] = local_80;
          local_80 = local_80 + 1;
          *(undefined8 *)(piVar6 + 2) = uVar4;
          *param_4 = piVar6;
        }
        FUN_001212c0(piVar6,iVar3,local_78);
        uVar1 = *(uint *)(__src + -0x10);
        uVar4 = *(undefined8 *)(__src + -0x18);
        puVar5 = (undefined8 *)FUN_001213a0(param_1,iVar3 * 100 + piVar6[1]);
        if (puVar5 == (undefined8 *)0x0) {
          return 6;
        }
        *(int *)(puVar5 + 1) = iVar2;
        *puVar5 = uVar4;
        puVar5[2] = (double)uVar1 / (double)param_3 + (double)puVar5[2];
      }
      iVar2 = *(int *)(__src + 0x48);
      iVar3 = *(int *)(__src + 0x4c);
      if ((iVar2 != -1) && (iVar3 != 0)) {
        strncpy(local_78,__src + 0x50,0x3f);
        local_39 = 0;
        piVar6 = (int *)thunk_FUN_00121800(*param_4,iVar2);
        if (piVar6 == (int *)0x0) {
          piVar6 = malloc(0x18);
          if (piVar6 == (int *)0x0) {
            return 0x14;
          }
          uVar4 = *param_4;
          *piVar6 = iVar2;
          piVar6[4] = 0;
          piVar6[5] = 0;
          piVar6[1] = local_80;
          local_80 = local_80 + 1;
          *(undefined8 *)(piVar6 + 2) = uVar4;
          *param_4 = piVar6;
        }
        FUN_001212c0(piVar6,iVar3,local_78);
        uVar1 = *(uint *)(__src + 0x40);
        uVar4 = *(undefined8 *)(__src + -0x18);
        puVar5 = (undefined8 *)FUN_001213a0(param_1,iVar3 * 100 + piVar6[1]);
        if (puVar5 == (undefined8 *)0x0) {
          return 6;
        }
        *(int *)(puVar5 + 1) = iVar2;
        *puVar5 = uVar4;
        puVar5[3] = (double)uVar1 / (double)param_3 + (double)puVar5[3];
      }
      iVar2 = *(int *)(__src + 0x98);
      iVar3 = *(int *)(__src + 0x9c);
      if ((iVar2 != -1) && (iVar3 != 0)) {
        strncpy(local_78,__src + 0xa0,0x3f);
        local_39 = 0;
        piVar6 = (int *)thunk_FUN_00121800(*param_4,iVar2);
        if (piVar6 == (int *)0x0) {
          piVar6 = malloc(0x18);
          if (piVar6 == (int *)0x0) {
            return 0x14;
          }
          uVar4 = *param_4;
          *piVar6 = iVar2;
          piVar6[4] = 0;
          piVar6[5] = 0;
          piVar6[1] = local_80;
          local_80 = local_80 + 1;
          *(undefined8 *)(piVar6 + 2) = uVar4;
          *param_4 = piVar6;
        }
        FUN_001212c0(piVar6,iVar3,local_78);
        uVar4 = *(undefined8 *)(__src + -0x18);
        uVar1 = *(uint *)(__src + 0x90);
        puVar5 = (undefined8 *)FUN_001213a0(param_1,iVar3 * 100 + piVar6[1]);
        if (puVar5 == (undefined8 *)0x0) {
          return 6;
        }
        *(int *)(puVar5 + 1) = iVar2;
        *puVar5 = uVar4;
        puVar5[4] = (double)uVar1 / (double)param_3 + (double)puVar5[4];
      }
      iVar2 = *(int *)(__src + 0xe8);
      iVar3 = *(int *)(__src + 0xec);
      if ((iVar2 != -1) && (iVar3 != 0)) {
        strncpy(local_78,__src + 0xf0,0x3f);
        local_39 = 0;
        piVar6 = (int *)thunk_FUN_00121800(*param_4,iVar2);
        if (piVar6 == (int *)0x0) {
          piVar6 = malloc(0x18);
          if (piVar6 == (int *)0x0) {
            return 0x14;
          }
          uVar4 = *param_4;
          *piVar6 = iVar2;
          piVar6[4] = 0;
          piVar6[5] = 0;
          piVar6[1] = local_80;
          local_80 = local_80 + 1;
          *(undefined8 *)(piVar6 + 2) = uVar4;
          *param_4 = piVar6;
        }
        FUN_001212c0(piVar6,iVar3,local_78);
        uVar4 = *(undefined8 *)(__src + -0x18);
        uVar1 = *(uint *)(__src + 0xe0);
        puVar5 = (undefined8 *)FUN_001213a0(param_1,iVar3 * 100 + piVar6[1]);
        if (puVar5 == (undefined8 *)0x0) {
          return 6;
        }
        *(int *)(puVar5 + 1) = iVar2;
        *puVar5 = uVar4;
        puVar5[5] = (double)uVar1 / (double)param_3 + (double)puVar5[5];
      }
      iVar2 = *(int *)(__src + 0x138);
      iVar3 = *(int *)(__src + 0x13c);
      if ((iVar2 != -1) && (iVar3 != 0)) {
        strncpy(local_78,__src + 0x140,0x3f);
        local_39 = 0;
        piVar6 = (int *)thunk_FUN_00121800(*param_4,iVar2);
        if (piVar6 == (int *)0x0) {
          piVar6 = malloc(0x18);
          if (piVar6 == (int *)0x0) {
            return 0x14;
          }
          uVar4 = *param_4;
          *piVar6 = iVar2;
          piVar6[4] = 0;
          piVar6[5] = 0;
          piVar6[1] = local_80;
          local_80 = local_80 + 1;
          *(undefined8 *)(piVar6 + 2) = uVar4;
          *param_4 = piVar6;
        }
        FUN_001212c0(piVar6,iVar3,local_78);
        uVar4 = *(undefined8 *)(__src + -0x18);
        uVar1 = *(uint *)(__src + 0x130);
        puVar5 = (undefined8 *)FUN_001213a0(param_1,iVar3 * 100 + piVar6[1]);
        if (puVar5 == (undefined8 *)0x0) {
          return 6;
        }
        *(int *)(puVar5 + 1) = iVar2;
        *puVar5 = uVar4;
        puVar5[6] = (double)uVar1 / (double)param_3 + (double)puVar5[6];
      }
      iVar2 = *(int *)(__src + 0x188);
      iVar3 = *(int *)(__src + 0x18c);
      if ((iVar2 != -1) && (iVar3 != 0)) {
        strncpy(local_78,__src + 400,0x3f);
        local_39 = 0;
        piVar6 = (int *)thunk_FUN_00121800(*param_4,iVar2);
        if (piVar6 == (int *)0x0) {
          piVar6 = malloc(0x18);
          if (piVar6 == (int *)0x0) {
            return 0x14;
          }
          uVar4 = *param_4;
          *piVar6 = iVar2;
          piVar6[4] = 0;
          piVar6[5] = 0;
          piVar6[1] = local_80;
          local_80 = local_80 + 1;
          *(undefined8 *)(piVar6 + 2) = uVar4;
          *param_4 = piVar6;
        }
        FUN_001212c0(piVar6,iVar3,local_78);
        uVar4 = *(undefined8 *)(__src + -0x18);
        uVar1 = *(uint *)(__src + 0x180);
        puVar5 = (undefined8 *)FUN_001213a0(param_1,iVar3 * 100 + piVar6[1]);
        if (puVar5 == (undefined8 *)0x0) {
          return 6;
        }
        *(int *)(puVar5 + 1) = iVar2;
        *puVar5 = uVar4;
        puVar5[7] = (double)uVar1 / (double)param_3 + (double)puVar5[7];
      }
      __src = __src + 0x1e8;
    } while ((char *)(param_2 + 0x200 + (ulong)(param_3 - 1) * 0x1e8) != __src);
  }
  return 0;
}


// ===== 00121ff0 FUN_00121ff0 =====

void FUN_00121ff0(undefined8 *param_1)

{
  void *pvVar1;
  void *pvVar2;
  void *__ptr;
  void *__ptr_00;
  
  __ptr = (void *)*param_1;
  while (__ptr != (void *)0x0) {
    pvVar1 = *(void **)((long)__ptr + 8);
    __ptr_00 = *(void **)((long)__ptr + 0x10);
    while (__ptr_00 != (void *)0x0) {
      pvVar2 = *(void **)((long)__ptr_00 + 0x48);
      free(__ptr_00);
      __ptr_00 = pvVar2;
    }
    free(__ptr);
    __ptr = pvVar1;
  }
  return;
}


// ===== 00122050 FUN_00122050 =====

bool FUN_00122050(void)

{
  int iVar1;
  long lVar2;
  int *piVar3;
  int local_518 [324];
  
  piVar3 = local_518;
  for (lVar2 = 0xa0; lVar2 != 0; lVar2 = lVar2 + -1) {
    piVar3[0] = 0;
    piVar3[1] = 0;
    piVar3 = piVar3 + 2;
  }
  *piVar3 = 0;
  iVar1 = FUN_00247df0(local_518);
  return iVar1 == 0 && local_518[0] != 0;
}


// ===== 001220a0 FUN_001220a0 =====

undefined4 FUN_001220a0(undefined8 *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  long lVar5;
  float fVar6;
  
  if (3 < DAT_01216a78) {
    uVar4 = *(undefined4 *)(param_1 + 4);
    uVar1 = *(undefined4 *)((long)param_1 + 0x1c);
    uVar2 = *(undefined4 *)(param_1 + 3);
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    FUN_002340f0((double)(fVar6 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n",&DAT_002983c2,lVar5,
                 "nvml_reset.c",0xa3,uVar2,uVar1,uVar4,0);
  }
  if (param_2 == 2) {
    uVar4 = FUN_00239c50(*param_1);
  }
  else if (param_2 == 1) {
    uVar4 = FUN_002389b0(*param_1);
  }
  else {
    uVar4 = 3;
    if (DAT_01216a78 < 2) {
      return 3;
    }
    uVar1 = *(undefined4 *)(param_1 + 4);
    uVar2 = *(undefined4 *)((long)param_1 + 0x1c);
    uVar3 = *(undefined4 *)(param_1 + 3);
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    FUN_002340f0((double)(fVar6 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x %d\n","ERROR",lVar5,
                 "nvml_reset.c",0xb6,uVar3,uVar2,uVar1,0,param_2);
  }
  if (3 < DAT_01216a78) {
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t  %x\n",
                 &DAT_002983c2,lVar5,"nvml_reset.c",0xbc,uVar4);
  }
  return uVar4;
}


// ===== 00122290 FUN_00122290 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00122290(int param_1,undefined8 *param_2,int *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  long lVar6;
  float fVar7;
  undefined4 local_58;
  undefined1 local_48 [24];
  
  if (param_1 == 0) {
    local_58 = 0;
  }
  else {
    local_58 = 0;
    piVar1 = param_3 + (ulong)(param_1 - 1) + 1;
    do {
      if (param_2[0xb] != 0) {
        FUN_00291790(local_48);
        do {
          while( true ) {
            if (3 < DAT_01216a78) {
              uVar2 = *(undefined4 *)(param_2 + 4);
              uVar3 = *(undefined4 *)(param_2 + 3);
              uVar4 = *(undefined4 *)((long)param_2 + 0x1c);
              fVar7 = (float)FUN_002917b0(&DAT_01216a60);
              lVar6 = syscall(0xba);
              FUN_002340f0((double)(fVar7 * DAT_00298548),
                           "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n",&DAT_002983c2,
                           lVar6,"nvml_reset.c",0x44,uVar3,uVar4,uVar2,0);
            }
            iVar5 = FUN_00238fc0(*param_2,param_2[0xb]);
            *param_3 = iVar5;
            if (iVar5 == 0) {
              FUN_00239730(param_2[0xb]);
              param_2[0xb] = 0;
              iVar5 = *param_3;
              goto joined_r0x001224bf;
            }
            usleep(100000);
            fVar7 = (float)FUN_002917b0(local_48);
            if (fVar7 < _DAT_002986b4) break;
            if (999 < ((long)(fVar7 - _DAT_002986b4) ^ 0x8000000000000000U)) goto LAB_0012236c;
          }
        } while ((ulong)(long)fVar7 < 1000);
LAB_0012236c:
        iVar5 = *param_3;
joined_r0x001224bf:
        if (iVar5 != 0) {
          FUN_00239730(param_2[0xb]);
          param_2[0xb] = 0;
          local_58 = 0x10;
          if (1 < DAT_01216a78) {
            iVar5 = *param_3;
            uVar2 = *(undefined4 *)(param_2 + 4);
            uVar3 = *(undefined4 *)((long)param_2 + 0x1c);
            uVar4 = *(undefined4 *)(param_2 + 3);
            fVar7 = (float)FUN_002917b0(&DAT_01216a60);
            lVar6 = syscall(0xba);
            FUN_002340f0((double)(fVar7 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x %x\n","ERROR",lVar6,
                         "nvml_reset.c",0x5c,uVar4,uVar3,uVar2,0,iVar5);
          }
        }
      }
      param_2 = param_2 + 0x2f;
      param_3 = param_3 + 1;
    } while (param_3 != piVar1);
  }
  return local_58;
}


// ===== 001224f0 FUN_001224f0 =====

int FUN_001224f0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  uint *puVar7;
  undefined4 *puVar8;
  undefined1 *puVar9;
  uint uVar10;
  byte bVar12;
  float fVar13;
  uint local_6458 [2];
  undefined4 local_6450 [322];
  uint local_5f48 [2];
  undefined1 local_5f40 [24];
  undefined4 local_5f28 [88];
  undefined1 local_5dc8 [23688];
  int local_140 [68];
  ulong uVar11;
  
  bVar12 = 0;
  memset(local_5f48,0,0x5f08);
  puVar7 = local_6458;
  for (lVar6 = 0xa0; lVar6 != 0; lVar6 = lVar6 + -1) {
    puVar7[0] = 0;
    puVar7[1] = 0;
    puVar7 = puVar7 + ((ulong)bVar12 * -2 + 1) * 2;
  }
  *puVar7 = 0;
  iVar4 = FUN_00247df0(local_6458);
  if (iVar4 != 0) {
    if (DAT_01216a78 < 2) {
      return iVar4;
    }
    fVar13 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    FUN_002340f0((double)(fVar13 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",
                 lVar6,"nvml_reset.c",0xd0);
    return iVar4;
  }
  puVar8 = local_6450;
  uVar11 = 0;
  puVar9 = local_5f40;
  if (local_6458[0] != 0) {
    do {
      uVar1 = *puVar8;
      uVar2 = puVar8[1];
      *(undefined8 *)(puVar9 + 0x58) = 0;
      uVar3 = puVar8[2];
      *(undefined4 *)(puVar9 + 0x18) = uVar1;
      *(undefined4 *)(puVar9 + 0x1c) = uVar2;
      *(undefined4 *)(puVar9 + 0x20) = uVar3;
      iVar4 = FUN_00237550();
      if (iVar4 != 0) {
        if (DAT_01216a78 < 2) {
          return iVar4;
        }
        uVar1 = local_5f28[uVar11 * 0x5e + 2];
        uVar2 = local_5f28[uVar11 * 0x5e + 1];
        uVar3 = local_5f28[uVar11 * 0x5e];
        fVar13 = (float)FUN_002917b0(&DAT_01216a60);
        lVar6 = syscall(0xba);
        FUN_002340f0((double)(fVar13 * DAT_00298548),
                     "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n","ERROR",lVar6,
                     "nvml_reset.c",0xe2,uVar3,uVar2,uVar1,0);
        return iVar4;
      }
      uVar10 = (int)uVar11 + 1;
      uVar11 = (ulong)uVar10;
      puVar8 = puVar8 + 5;
      puVar9 = puVar9 + 0x178;
    } while (uVar10 < local_6458[0]);
  }
  local_5f48[0] = local_6458[0];
  iVar4 = FUN_00123ce0(local_6458[0],0,local_5f40,local_140);
  if (iVar4 == 0) {
    if (local_5f48[0] != 0) {
      local_140[0] = FUN_001220a0(local_5f40,1);
      puVar9 = local_5dc8;
      iVar4 = local_140[0];
      for (lVar6 = 1; (uint)lVar6 < local_5f48[0]; lVar6 = lVar6 + 1) {
        iVar5 = FUN_001220a0(puVar9,1);
        if (iVar4 == 0) {
          iVar4 = iVar5;
        }
        local_140[lVar6] = iVar5;
        puVar9 = puVar9 + 0x178;
      }
      if (iVar4 != 0) goto LAB_00122672;
    }
    iVar4 = FUN_00122290(local_5f48[0],local_5f40,local_140);
  }
LAB_00122672:
  FUN_001243d0(local_5f48[0],local_5f40);
  return iVar4;
}


// ===== 001227d0 FUN_001227d0 =====

int FUN_001227d0(undefined8 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  float fVar6;
  
  if (param_1 == (undefined8 *)0x0) {
    return 2;
  }
  iVar4 = FUN_002388f0(*param_1);
  if ((iVar4 != 0) && (1 < DAT_01216a78)) {
    uVar1 = *(undefined4 *)(param_1 + 4);
    uVar2 = *(undefined4 *)((long)param_1 + 0x1c);
    uVar3 = *(undefined4 *)(param_1 + 3);
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    FUN_002340f0((double)(fVar6 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x %x\n","ERROR",lVar5,
                 "nvml_reset.c",0x1d1,uVar3,uVar2,uVar1,0,iVar4);
    return iVar4;
  }
  return iVar4;
}


// ===== 001228c0 FUN_001228c0 =====

int FUN_001228c0(uint param_1,undefined8 param_2,long param_3,int *param_4,long *param_5,
                undefined4 *param_6,undefined4 param_7)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  long lVar8;
  code *pcVar9;
  byte bVar10;
  int *piVar11;
  byte *pbVar12;
  long lVar13;
  long lVar14;
  float fVar15;
  int local_48;
  
  if (param_1 == 0) {
LAB_00122ca0:
    cVar4 = FUN_00122050();
    if ((cVar4 != '\0') && (param_1 == DAT_01214898)) {
      if (3 < DAT_01216a78) {
        fVar15 = (float)FUN_002917b0(&DAT_01216a60);
        lVar14 = syscall(0xba);
        FUN_002340f0((double)(fVar15 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                     &DAT_002983c2,lVar14,"nvml_reset.c",0x199);
      }
      if (param_6 != (undefined4 *)0x0) {
        *param_6 = 1;
      }
      iVar6 = FUN_001224f0();
      if (iVar6 != 0) {
        if (param_1 != 0) {
          piVar11 = param_4 + (ulong)(param_1 - 1) + 1;
          do {
            *param_4 = iVar6;
            param_4 = param_4 + 1;
          } while (param_4 != piVar11);
        }
        local_48 = 0x10;
        goto LAB_00122c26;
      }
    }
    if (DAT_01216a78 < 4) {
      if (param_1 == 0) goto LAB_00122afd;
      goto LAB_00122a07;
    }
    fVar15 = (float)FUN_002917b0(&DAT_01216a60);
    lVar14 = syscall(0xba);
    FUN_002340f0((double)(fVar15 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar14,"nvml_reset.c",0x1b3);
    if (param_1 != 0) goto LAB_00122a07;
  }
  else {
    memset(param_4,0,(ulong)param_1 << 2);
    if (param_1 != DAT_01214898) {
      pcVar7 = (char *)(param_3 + 0x171);
      local_48 = 0;
      piVar11 = param_4;
      do {
        if ((*pcVar7 != '\0') && (pcVar7[-1] == '\0')) {
          *piVar11 = 3;
          local_48 = 0x10;
        }
        piVar11 = piVar11 + 1;
        pcVar7 = pcVar7 + 0x178;
      } while (param_4 + (ulong)(param_1 - 1) + 1 != piVar11);
      if (local_48 != 0) {
        if (DAT_01216a78 < 2) {
          return local_48;
        }
        fVar15 = (float)FUN_002917b0(&DAT_01216a60);
        lVar14 = syscall(0xba);
        FUN_002340f0((double)(fVar15 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR"
                     ,lVar14,"nvml_reset.c",0x172);
        goto LAB_00122c26;
      }
    }
    bVar10 = 0;
    pbVar12 = (byte *)(param_3 + 0x170);
    uVar5 = 0;
    do {
      uVar5 = uVar5 + 1;
      bVar10 = bVar10 | *pbVar12;
      pbVar12 = pbVar12 + 0x178;
    } while (uVar5 < param_1);
    if (bVar10 == 0) goto LAB_00122ca0;
    if (3 < DAT_01216a78) {
      fVar15 = (float)FUN_002917b0(&DAT_01216a60);
      lVar14 = syscall(0xba);
      FUN_002340f0((double)(fVar15 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                   &DAT_002983c2,lVar14,"nvml_reset.c",0x180);
    }
    lVar13 = 0;
    local_48 = 0;
    lVar14 = param_3 + 0x70;
    do {
      while (*(char *)(lVar14 + 0x100) != '\0') {
        iVar6 = FUN_001284b0(lVar14);
        param_4[lVar13] = iVar6;
        if (iVar6 != 0) {
          local_48 = 0x10;
        }
        lVar13 = lVar13 + 1;
        lVar14 = lVar14 + 0x178;
        if (param_1 <= (uint)lVar13) goto LAB_001229f1;
      }
      lVar13 = lVar13 + 1;
      lVar14 = lVar14 + 0x178;
    } while ((uint)lVar13 < param_1);
LAB_001229f1:
    if (local_48 != 0) goto LAB_00122c26;
    if (3 < DAT_01216a78) {
      fVar15 = (float)FUN_002917b0(&DAT_01216a60);
      lVar14 = syscall(0xba);
      FUN_002340f0((double)(fVar15 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                   &DAT_002983c2,lVar14,"nvml_reset.c",0x1b3);
    }
LAB_00122a07:
    lVar13 = 0;
    local_48 = 0;
    lVar14 = param_3;
    do {
      iVar6 = FUN_001220a0(lVar14,param_7);
      param_4[lVar13] = iVar6;
      if ((iVar6 != 0) && (local_48 = 0x10, 1 < DAT_01216a78)) {
        uVar1 = *(undefined4 *)(lVar14 + 0x20);
        uVar2 = *(undefined4 *)(lVar14 + 0x1c);
        uVar3 = *(undefined4 *)(lVar14 + 0x18);
        fVar15 = (float)FUN_002917b0(&DAT_01216a60);
        lVar8 = syscall(0xba);
        FUN_002340f0((double)(fVar15 * DAT_00298548),
                     "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x %x\n","ERROR",lVar8,
                     "nvml_reset.c",0x1bb,uVar3,uVar2,uVar1,0,iVar6);
      }
      lVar13 = lVar13 + 1;
      lVar14 = lVar14 + 0x178;
    } while ((uint)lVar13 < param_1);
    if (local_48 != 0) {
LAB_00122c26:
      if (DAT_01216a78 < 2) {
        return local_48;
      }
      fVar15 = (float)FUN_002917b0(&DAT_01216a60);
      lVar14 = syscall(0xba);
      FUN_002340f0((double)(fVar15 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar14,"nvml_reset.c",0x212,"resetListedDevices",0x212,local_48);
      return local_48;
    }
  }
  if (3 < DAT_01216a78) {
    fVar15 = (float)FUN_002917b0(&DAT_01216a60);
    lVar14 = syscall(0xba);
    FUN_002340f0((double)(fVar15 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar14,"nvml_reset.c",0x213);
    if (3 < DAT_01216a78) {
      fVar15 = (float)FUN_002917b0(&DAT_01216a60);
      lVar14 = syscall(0xba);
      FUN_002340f0((double)(DAT_00298548 * fVar15),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                   &DAT_002983c2,lVar14,"nvml_reset.c",0x215);
    }
  }
LAB_00122afd:
  usleep(150000);
  if (3 < DAT_01216a78) {
    fVar15 = (float)FUN_002917b0(&DAT_01216a60);
    lVar14 = syscall(0xba);
    FUN_002340f0((double)(fVar15 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar14,"nvml_reset.c",0x219);
  }
  iVar6 = FUN_00122290(param_1,param_3,param_4);
  if (iVar6 == 0) {
    if ((param_5 != (long *)0x0) && (pcVar9 = (code *)*param_5, pcVar9 != (code *)0x0)) {
      if (3 < DAT_01216a78) {
        fVar15 = (float)FUN_002917b0(&DAT_01216a60);
        lVar14 = syscall(0xba);
        FUN_002340f0((double)(fVar15 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                     &DAT_002983c2,lVar14,"nvml_reset.c",0x224);
        pcVar9 = (code *)*param_5;
      }
      iVar6 = (*pcVar9)(param_1,param_2,param_4,param_5[1]);
      if (iVar6 != 0) {
        return iVar6;
      }
    }
    if (3 < DAT_01216a78) {
      fVar15 = (float)FUN_002917b0(&DAT_01216a60);
      lVar14 = syscall(0xba);
      FUN_002340f0((double)(fVar15 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                   &DAT_002983c2,lVar14,"nvml_reset.c",0x22e);
    }
    iVar6 = FUN_00123770(param_1,param_2,param_3,param_4);
    if (iVar6 == 0) {
      if (3 < DAT_01216a78) {
        fVar15 = (float)FUN_002917b0(&DAT_01216a60);
        lVar14 = syscall(0xba);
        FUN_002340f0((double)(fVar15 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                     &DAT_002983c2,lVar14,"nvml_reset.c",0x235);
      }
      FUN_00123b70(param_1,param_2,param_3);
    }
  }
  return iVar6;
}


// ===== 00123110 FUN_00123110 =====

int FUN_00123110(undefined4 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined8 param_5,undefined4 param_6)

{
  int iVar1;
  long lVar2;
  float fVar3;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40 [2];
  
  local_40[0] = 0;
  iVar1 = FUN_00168460(local_40,param_2,param_1,1);
  if (iVar1 == 0) {
    iVar1 = FUN_001244a0(local_40[0],&local_50,&local_48,param_3,0,FUN_001227d0);
    if (iVar1 == 0) {
      iVar1 = FUN_001228c0(param_1,param_2,local_50,param_3,param_4,param_5,param_6);
      if ((iVar1 != 0) && (1 < DAT_01216a78)) {
        fVar3 = (float)FUN_002917b0(&DAT_01216a60);
        lVar2 = syscall(0xba);
        FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",
                     lVar2,"nvml_reset.c",599);
      }
      FUN_00124440(param_1,0,local_50,local_48);
    }
    FUN_00127f20(local_40[0]);
  }
  else if (1 < DAT_01216a78) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar2,"nvml_reset.c",0x248,"resetDevices",0x248,iVar1);
  }
  return iVar1;
}


// ===== 001232d0 FUN_001232d0 =====

undefined4 FUN_001232d0(int param_1,long param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  long lVar3;
  undefined4 uVar4;
  float fVar5;
  
  if (3 < DAT_01216a78) {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar3,"nvml_reset.c",0x269);
  }
  if (param_1 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0;
    piVar1 = param_3 + (ulong)(param_1 - 1) + 1;
    do {
      iVar2 = FUN_001220a0(param_2,param_4);
      *param_3 = iVar2;
      if (iVar2 != 0) {
        uVar4 = 0x10;
      }
      param_3 = param_3 + 1;
      param_2 = param_2 + 0x178;
    } while (param_3 != piVar1);
  }
  return uVar4;
}


// ===== 001233c0 FUN_001233c0 =====

void FUN_001233c0(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  float fVar3;
  
  iVar1 = FUN_001232d0();
  if (iVar1 != 0) {
    return;
  }
  if (3 < DAT_01216a78) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar2,"nvml_reset.c",0x282);
    if (3 < DAT_01216a78) {
      fVar3 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(DAT_00298548 * fVar3),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                   &DAT_002983c2,lVar2,"nvml_reset.c",0x283);
      usleep(150000);
      goto joined_r0x00123545;
    }
  }
  usleep(150000);
joined_r0x00123545:
  if (3 < DAT_01216a78) {
    fVar3 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    FUN_002340f0((double)(fVar3 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar2,"nvml_reset.c",0x288);
  }
  FUN_00122290(param_1,param_2,param_3);
  return;
}


// ===== 00123560 FUN_00123560 =====

ulong FUN_00123560(long param_1,undefined8 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  long lVar4;
  long lVar5;
  char *pcVar6;
  uint uVar7;
  ulong uVar8;
  int *piVar9;
  int iVar10;
  undefined8 local_48;
  undefined8 local_40 [2];
  
  piVar3 = *(int **)(param_1 + 8);
  lVar4 = *(long *)(param_1 + 0x10);
  lVar5 = *(long *)(param_1 + 0x18);
  if ((piVar3 == (int *)0x0 || lVar4 == 0) || (lVar5 == 0)) {
    return 2;
  }
  iVar1 = *piVar3;
  if (iVar1 + piVar3[1] == 0) {
    return 2;
  }
  if (iVar1 != 0) {
    piVar9 = piVar3 + 2;
    do {
      pcVar6 = *(char **)piVar9;
      if (pcVar6 == (char *)0x0) {
        return 2;
      }
      if (*pcVar6 != '\x01') {
        if (*(int *)(pcVar6 + 0x14) == 0) {
          return 2;
        }
        if (*(int *)(pcVar6 + 0x1c) != 0) {
          return 2;
        }
        if (*(int *)(pcVar6 + 0x10) == 0) {
          return 2;
        }
        if (*(long *)(pcVar6 + 0x20) == 0) {
          return 2;
        }
      }
      piVar9 = piVar9 + 2;
    } while (piVar9 != piVar3 + (ulong)(iVar1 - 1) * 2 + 4);
  }
  uVar2 = *(undefined4 *)(param_1 + 0x28);
  if (*(undefined4 **)(param_1 + 0x20) != (undefined4 *)0x0) {
    **(undefined4 **)(param_1 + 0x20) = 0;
  }
  uVar8 = FUN_001244a0(piVar3,&local_48,local_40,lVar4,lVar5,FUN_001227d0);
  if ((int)uVar8 != 0) {
    return uVar8;
  }
  iVar1 = *piVar3;
  if ((iVar1 == 0) ||
     (uVar7 = FUN_001228c0(iVar1,piVar3 + 2,local_48,lVar4,param_2,*(undefined8 *)(param_1 + 0x20),
                           uVar2), uVar7 == 0)) {
    iVar10 = piVar3[1];
    uVar7 = 0;
    if (iVar10 != 0) {
      uVar7 = FUN_001233c0(iVar10,local_40[0],lVar5,uVar2);
    }
  }
  else {
    iVar10 = 0;
  }
  FUN_00124440(iVar1,iVar10,local_48,local_40[0]);
  return (ulong)uVar7;
}


// ===== 001236d0 FUN_001236d0 =====

undefined8 FUN_001236d0(int *param_1)

{
  undefined8 uVar1;
  
  if (*param_1 != 0x1000030) {
    return 0x19;
  }
  uVar1 = FUN_00123560();
  return uVar1;
}


// ===== 001236f0 FUN_001236f0 =====

void FUN_001236f0(int param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  
  if (param_1 != 0) {
    lVar2 = param_2 + 8;
    do {
      if (((DAT_012164a0 != 0) && (*(undefined8 **)(DAT_012164a0 + 0x138) != (undefined8 *)0x0)) &&
         (pcVar1 = (code *)**(undefined8 **)(DAT_012164a0 + 0x138), pcVar1 != (code *)0x0)) {
        (*pcVar1)(DAT_012164a0,lVar2,0);
      }
      lVar2 = lVar2 + 0x178;
    } while (lVar2 != param_2 + 0x180 + (ulong)(param_1 - 1) * 0x178);
    return;
  }
  return;
}


// ===== 00123770 FUN_00123770 =====

int FUN_00123770(uint param_1,long param_2,long param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  code *pcVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  ulong uVar9;
  float fVar10;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  
  if (3 < DAT_01216a78) {
    fVar10 = (float)FUN_002917b0(&DAT_01216a60);
    lVar7 = syscall(0xba);
    FUN_002340f0((double)(fVar10 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar7,"nvml_removal.c",0x177);
  }
  if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0xb0) == 0)) ||
     (pcVar5 = *(code **)(*(long *)(DAT_012164a0 + 0xb0) + 0x18), pcVar5 == (code *)0x0)) {
    iVar6 = 3;
  }
  else {
    iVar6 = (*pcVar5)();
    if (iVar6 == 0) {
      param_3 = param_3 + 0x70;
      uVar9 = 0;
      iVar6 = 0;
      if (param_1 == 0) {
        return 0;
      }
      do {
        if (3 < DAT_01216a78) {
          uVar4 = *(undefined4 *)(param_3 + -0x50);
          uVar2 = *(undefined4 *)(param_3 + -0x54);
          uVar3 = *(undefined4 *)(param_3 + -0x58);
          fVar10 = (float)FUN_002917b0(&DAT_01216a60);
          lVar7 = syscall(0xba);
          FUN_002340f0((double)(fVar10 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n",&DAT_002983c2,lVar7,
                       "nvml_removal.c",0x186,uVar3,uVar2,uVar4,0);
        }
        if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x20) == 0)) ||
           (pcVar5 = *(code **)(*(long *)(DAT_012164a0 + 0x20) + 0xb8), pcVar5 == (code *)0x0)) {
          local_50 = 3;
LAB_00123966:
          if (1 < DAT_01216a78) {
            local_4c = *(undefined4 *)(param_3 + -0x50);
            local_48 = *(undefined4 *)(param_3 + -0x54);
            uVar4 = *(undefined4 *)(param_3 + -0x58);
            fVar10 = (float)FUN_002917b0(&DAT_01216a60);
            lVar7 = syscall(0xba);
            uVar8 = 0x18d;
            fVar10 = fVar10 * DAT_00298548;
LAB_001239d7:
            FUN_002340f0((double)fVar10,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x: %x\n"
                         ,"ERROR",lVar7,"nvml_removal.c",uVar8,uVar4,local_48,local_4c,0,local_50);
          }
LAB_00123880:
          if (param_4 != (undefined4 *)0x0) {
            param_4[uVar9] = local_50;
          }
          iVar6 = 0x10;
        }
        else {
          local_50 = (*pcVar5)(DAT_012164a0,*(undefined8 *)(param_2 + uVar9 * 8));
          if (local_50 != 0) goto LAB_00123966;
          if ((*(char *)(param_3 + 0x100) != '\0') &&
             (local_50 = FUN_00128610(param_3), local_50 != 0)) {
            if (1 < DAT_01216a78) {
              local_4c = *(undefined4 *)(param_3 + -0x50);
              local_48 = *(undefined4 *)(param_3 + -0x54);
              uVar4 = *(undefined4 *)(param_3 + -0x58);
              fVar10 = (float)FUN_002917b0(&DAT_01216a60);
              lVar7 = syscall(0xba);
              uVar8 = 0x19a;
              fVar10 = fVar10 * DAT_00298548;
              goto LAB_001239d7;
            }
            goto LAB_00123880;
          }
        }
        uVar9 = uVar9 + 1;
        param_3 = param_3 + 0x178;
        if (uVar9 == param_1) {
          return iVar6;
        }
      } while( true );
    }
  }
  if (1 < DAT_01216a78) {
    fVar10 = (float)FUN_002917b0(&DAT_01216a60);
    lVar7 = syscall(0xba);
    FUN_002340f0((double)(fVar10 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",
                 lVar7,"nvml_removal.c",0x17b);
  }
  if (param_1 != 0) {
    puVar1 = param_4 + (ulong)(param_1 - 1) + 1;
    do {
      *param_4 = 0x10;
      param_4 = param_4 + 1;
    } while (param_4 != puVar1);
  }
  return iVar6;
}


// ===== 00123b70 FUN_00123b70 =====

void FUN_00123b70(int param_1,long *param_2,long param_3)

{
  long *plVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  code *pcVar5;
  int iVar6;
  long lVar7;
  int *piVar8;
  float fVar9;
  
  if (param_1 == 0) {
    return;
  }
  plVar1 = param_2 + (ulong)(param_1 - 1) + 1;
  piVar8 = (int *)(param_3 + 0x60);
  do {
    while (*piVar8 != 1) {
LAB_00123ba0:
      param_2 = param_2 + 1;
      piVar8 = piVar8 + 0x5e;
      if (param_2 == plVar1) {
        return;
      }
    }
    lVar7 = *(long *)(*param_2 + 0x256d8);
    if (((lVar7 == 0) || (*(long *)(lVar7 + 0xa8) == 0)) ||
       (pcVar5 = *(code **)(*(long *)(lVar7 + 0xa8) + 0x10), pcVar5 == (code *)0x0)) {
      iVar6 = 3;
    }
    else {
      iVar6 = (*pcVar5)(lVar7,*param_2,1,1,0);
      if (iVar6 == 0) goto LAB_00123ba0;
    }
    if (DAT_01216a78 < 3) goto LAB_00123ba0;
    lVar7 = *param_2;
    param_2 = param_2 + 1;
    piVar8 = piVar8 + 0x5e;
    uVar2 = *(undefined2 *)(lVar7 + 0xe);
    uVar3 = *(undefined2 *)(lVar7 + 0xc);
    uVar4 = *(undefined4 *)(lVar7 + 8);
    fVar9 = (float)FUN_002917b0(&DAT_01216a60);
    lVar7 = syscall(0xba);
    FUN_002340f0((double)(fVar9 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x: %x\n","WARNING",lVar7,
                 "nvml_removal.c",0x1b6,uVar4,uVar3,uVar2,0,iVar6);
    if (param_2 == plVar1) {
      return;
    }
  } while( true );
}


// ===== 00123ce0 FUN_00123ce0 =====

int FUN_00123ce0(int param_1,long param_2,long param_3,int *param_4)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  code *pcVar5;
  bool bVar6;
  int iVar7;
  long lVar8;
  int iVar9;
  long lVar10;
  float fVar11;
  
  if (param_1 == 0) {
    iVar9 = 0;
  }
  else {
    bVar6 = false;
    lVar10 = param_3 + 8;
    iVar9 = 0;
    piVar1 = param_4 + (ulong)(param_1 - 1) + 1;
    do {
      if (param_2 == 0) {
LAB_00123e7f:
        if (3 < DAT_01216a78) {
          uVar2 = *(undefined4 *)(lVar10 + 0x18);
          uVar3 = *(undefined4 *)(lVar10 + 0x14);
          uVar4 = *(undefined4 *)(lVar10 + 0x10);
          fVar11 = (float)FUN_002917b0(&DAT_01216a60);
          lVar8 = syscall(0xba);
          FUN_002340f0((double)(fVar11 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n",&DAT_002983c2,lVar8,
                       "nvml_removal.c",0x298,uVar4,uVar3,uVar2,0);
        }
        iVar7 = FUN_00238a70(*(undefined8 *)(lVar10 + -8),lVar10 + 0x50);
        *param_4 = iVar7;
        if ((iVar7 != 0) && (iVar9 = 0x10, 1 < DAT_01216a78)) {
          uVar2 = *(undefined4 *)(lVar10 + 0x18);
          uVar3 = *(undefined4 *)(lVar10 + 0x14);
          uVar4 = *(undefined4 *)(lVar10 + 0x10);
          fVar11 = (float)FUN_002917b0(&DAT_01216a60);
          lVar8 = syscall(0xba);
          FUN_002340f0((double)(fVar11 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x %x\n","ERROR",lVar8,
                       "nvml_removal.c",0x2a0,uVar4,uVar3,uVar2,0,iVar7);
        }
      }
      else {
        if (*(FILE **)(lVar10 + 0x60) != (FILE *)0x0) {
          fclose(*(FILE **)(lVar10 + 0x60));
          *(undefined8 *)(lVar10 + 0x60) = 0;
        }
        if (3 < DAT_01216a78) {
          uVar2 = *(undefined4 *)(lVar10 + 0x18);
          uVar3 = *(undefined4 *)(lVar10 + 0x14);
          uVar4 = *(undefined4 *)(lVar10 + 0x10);
          fVar11 = (float)FUN_002917b0(&DAT_01216a60);
          lVar8 = syscall(0xba);
          FUN_002340f0((double)(fVar11 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n",&DAT_002983c2,lVar8,
                       "nvml_removal.c",0x27b,uVar4,uVar3,uVar2,0);
        }
        if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0xa8) != 0)) &&
           (pcVar5 = *(code **)(*(long *)(DAT_012164a0 + 0xa8) + 8), pcVar5 != (code *)0x0)) {
          iVar7 = (*pcVar5)(DAT_012164a0,lVar10,0);
          *param_4 = iVar7;
          if (iVar7 == 6) {
            if (3 < DAT_01216a78) {
              uVar2 = *(undefined4 *)(lVar10 + 0x18);
              uVar3 = *(undefined4 *)(lVar10 + 0x14);
              uVar4 = *(undefined4 *)(lVar10 + 0x10);
              fVar11 = (float)FUN_002917b0(&DAT_01216a60);
              lVar8 = syscall(0xba);
              FUN_002340f0((double)(fVar11 * DAT_00298548),
                           "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n",&DAT_002983c2,
                           lVar8,"nvml_removal.c",0x284,uVar4,uVar3,uVar2,0);
            }
            *param_4 = 0;
            bVar6 = true;
          }
          else {
            if (iVar7 != 0) goto LAB_00123f23;
            bVar6 = true;
          }
          goto LAB_00123e7f;
        }
        *param_4 = 3;
        iVar7 = 3;
LAB_00123f23:
        if (1 < DAT_01216a78) {
          uVar2 = *(undefined4 *)(lVar10 + 0x18);
          uVar3 = *(undefined4 *)(lVar10 + 0x14);
          uVar4 = *(undefined4 *)(lVar10 + 0x10);
          fVar11 = (float)FUN_002917b0(&DAT_01216a60);
          lVar8 = syscall(0xba);
          FUN_002340f0((double)(fVar11 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x %x\n","ERROR",lVar8,
                       "nvml_removal.c",0x28b,uVar4,uVar3,uVar2,0,iVar7);
        }
        if (iVar9 == 0) {
          iVar9 = 999;
        }
      }
      param_4 = param_4 + 1;
      lVar10 = lVar10 + 0x178;
    } while (piVar1 != param_4);
    if ((iVar9 != 0 && param_2 != 0) && (!bVar6)) {
      FUN_001236f0(param_1,param_3);
      FUN_00123770(param_1,param_2,param_3,0);
      FUN_00123b70(param_1,param_2,param_3);
    }
  }
  return iVar9;
}


// ===== 00124170 FUN_00124170 =====

int FUN_00124170(uint param_1,undefined8 param_2,long param_3,int *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  uint uVar7;
  int iVar8;
  long lVar9;
  float fVar10;
  
  if ((param_1 == 0) || (param_4 == (int *)0x0)) {
    iVar8 = 0;
  }
  else {
    lVar9 = param_3 + 0x58;
    iVar8 = 0;
    uVar7 = 0;
    do {
      if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0xa8) == 0)) ||
         (pcVar4 = *(code **)(*(long *)(DAT_012164a0 + 0xa8) + 8), pcVar4 == (code *)0x0)) {
        *param_4 = 3;
LAB_001242e6:
        if (iVar8 == 0) {
          iVar8 = 999;
        }
      }
      else {
        iVar5 = (*pcVar4)(DAT_012164a0,lVar9 + -0x50,0);
        *param_4 = iVar5;
        if (iVar5 == 6) {
          *param_4 = 0;
        }
        else if (iVar5 != 0) goto LAB_001242e6;
        if (3 < DAT_01216a78) {
          uVar1 = *(undefined4 *)(lVar9 + -0x38);
          uVar2 = *(undefined4 *)(lVar9 + -0x3c);
          uVar3 = *(undefined4 *)(lVar9 + -0x40);
          fVar10 = (float)FUN_002917b0(&DAT_01216a60);
          lVar6 = syscall(0xba);
          FUN_002340f0((double)(fVar10 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n",&DAT_002983c2,lVar6,
                       "nvml_removal.c",0x2d4,uVar3,uVar2,uVar1,0);
        }
        iVar5 = FUN_00238a70(*(undefined8 *)(lVar9 + -0x58),lVar9);
        *param_4 = iVar5;
        if ((iVar5 != 0) && (iVar8 = 0x10, 1 < DAT_01216a78)) {
          uVar1 = *(undefined4 *)(lVar9 + -0x38);
          uVar2 = *(undefined4 *)(lVar9 + -0x3c);
          uVar3 = *(undefined4 *)(lVar9 + -0x40);
          fVar10 = (float)FUN_002917b0(&DAT_01216a60);
          lVar6 = syscall(0xba);
          FUN_002340f0((double)(fVar10 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x %x\n","ERROR",lVar6,
                       "nvml_removal.c",0x2dc,uVar3,uVar2,uVar1,0,iVar5);
        }
      }
      uVar7 = uVar7 + 1;
      lVar9 = lVar9 + 0x178;
      param_4 = param_4 + 1;
    } while (uVar7 < param_1);
    if (iVar8 != 0) {
      FUN_001236f0(param_1,param_3);
    }
  }
  return iVar8;
}


// ===== 001243d0 FUN_001243d0 =====

void FUN_001243d0(int param_1,long param_2)

{
  undefined8 *puVar1;
  
  if (param_1 != 0) {
    puVar1 = (undefined8 *)(param_2 + 0x68);
    do {
      if ((void *)puVar1[-2] != (void *)0x0) {
        free((void *)puVar1[-2]);
      }
      if ((FILE *)*puVar1 != (FILE *)0x0) {
        fclose((FILE *)*puVar1);
        *puVar1 = 0;
      }
      puVar1 = puVar1 + 0x2f;
    } while (puVar1 != (undefined8 *)(param_2 + 0x1e0 + (ulong)(param_1 - 1) * 0x178));
    return;
  }
  return;
}


// ===== 00124440 FUN_00124440 =====

void FUN_00124440(undefined4 param_1,undefined4 param_2,void *param_3,void *param_4)

{
  signal(2,(__sighandler_t)0x0);
  FUN_001243d0(param_1,param_3);
  free(param_3);
  FUN_001243d0(param_2,param_4);
  free(param_4);
  FUN_00237220();
  return;
}


// ===== 001244a0 FUN_001244a0 =====

int FUN_001244a0(uint *param_1,undefined8 *param_2,undefined8 *param_3,int *param_4,int *param_5,
                code *param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  char *pcVar7;
  code *pcVar8;
  ulong uVar9;
  undefined4 uVar10;
  ulong uVar11;
  undefined1 uVar12;
  int iVar13;
  void *__ptr;
  void *pvVar14;
  uint *puVar15;
  long lVar16;
  long lVar17;
  FILE *pFVar18;
  uint *puVar19;
  char *pcVar20;
  ulong extraout_RDX;
  ulong uVar21;
  ulong extraout_RDX_00;
  void *pvVar22;
  undefined8 uVar23;
  char *pcVar24;
  int *piVar25;
  uint *puVar26;
  undefined1 (*pauVar27) [16];
  float fVar28;
  double dVar29;
  undefined2 uVar30;
  undefined2 uVar31;
  int local_124;
  char local_115;
  int local_114;
  int local_110;
  uint local_10c;
  undefined1 local_108 [16];
  undefined8 local_f8;
  ulong uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  uint local_c8;
  undefined8 local_b8;
  undefined8 uStack_b0;
  ulong local_a8;
  ulong uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  uint local_78;
  
  uVar1 = *param_1;
  uVar2 = param_1[1];
  iVar13 = FUN_00236fb0();
  if (iVar13 != 0) {
    return iVar13;
  }
  __ptr = calloc((ulong)uVar1,0x178);
  if (__ptr == (void *)0x0) {
LAB_00125ed6:
    FUN_00237220();
    return 0x14;
  }
  pvVar14 = calloc((ulong)uVar2,0x178);
  if (pvVar14 == (void *)0x0) {
    free(__ptr);
    goto LAB_00125ed6;
  }
  signal(2,(__sighandler_t)0x1);
  if (3 < (int)DAT_01216a78) {
    fVar28 = (float)FUN_002917b0(&DAT_01216a60);
    lVar17 = syscall(0xba);
    FUN_002340f0((double)(fVar28 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar17,"nvml_removal.c",0x337);
  }
  pcVar24 = (char *)(ulong)uVar1;
  puVar15 = param_1 + 2;
  if (uVar1 != 0) {
    local_124 = 0;
    lVar17 = (long)__ptr + 0x70;
    piVar25 = param_4;
    puVar26 = puVar15;
    do {
      pcVar7 = *(char **)puVar26;
      local_f8 = 0;
      uStack_f0 = uStack_f0 & 0xffffffff00000000;
      local_114 = 0;
      local_110 = 0;
      local_108 = (undefined1  [16])0x0;
      if (pcVar7 == (char *)0x0) {
        *piVar25 = 2;
        iVar13 = 2;
LAB_001247b0:
        local_124 = 999;
        if (1 < (int)DAT_01216a78) {
          lVar16 = *(long *)puVar26;
          uVar31 = *(undefined2 *)(lVar16 + 0xe);
          uVar30 = *(undefined2 *)(lVar16 + 0xc);
          uVar3 = *(uint *)(lVar16 + 8);
          fVar28 = (float)FUN_002917b0(&DAT_01216a60);
          lVar16 = syscall(0xba);
          pcVar24 = (char *)(ulong)uVar3;
          FUN_002340f0((double)(fVar28 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x %x\n","ERROR",lVar16,
                       "nvml_removal.c",0x1d1,pcVar24,uVar30,uVar31,0,iVar13);
        }
      }
      else {
        iVar13 = FUN_00175bd0(pcVar7,&local_114);
        if ((iVar13 != 0) || (local_114 == 0)) {
LAB_001248f0:
          *piVar25 = 3;
          iVar13 = 3;
          goto LAB_001247b0;
        }
        lVar16 = *(long *)(pcVar7 + 0x256d8);
        pcVar20 = pcVar24;
        if (((lVar16 != 0) &&
            (((*(long *)(lVar16 + 0x60) != 0 &&
              (pcVar8 = *(code **)(*(long *)(lVar16 + 0x60) + 0x30), pcVar8 != (code *)0x0)) &&
             (iVar13 = (*pcVar8)(lVar16,pcVar7,&local_110), pcVar20 = pcVar24, iVar13 == 0)))) &&
           (local_110 != 0)) {
          if (1 < (int)DAT_01216a78) {
            uVar31 = *(undefined2 *)(pcVar7 + 0xc);
            uVar30 = *(undefined2 *)(pcVar7 + 0xe);
            uVar3 = *(uint *)(pcVar7 + 8);
            fVar28 = (float)FUN_002917b0(&DAT_01216a60);
            lVar16 = syscall(0xba);
            pcVar24 = (char *)(ulong)uVar3;
            iVar13 = 3;
            FUN_002340f0((double)(fVar28 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n","ERROR",lVar16,
                         "nvml_removal.c",0xba,pcVar24,uVar31,uVar30,0);
            *piVar25 = 3;
            goto LAB_001247b0;
          }
          goto LAB_001248f0;
        }
        *(undefined8 *)(lVar17 + -0x18) = 0;
        iVar13 = FUN_00237550(*(undefined4 *)(pcVar7 + 8),*(undefined2 *)(pcVar7 + 0xc),
                              *(undefined2 *)(pcVar7 + 0xe),0);
        if (iVar13 != 0) {
          if (1 < (int)DAT_01216a78) {
            uVar31 = *(undefined2 *)(pcVar7 + 0xe);
            uVar30 = *(undefined2 *)(pcVar7 + 0xc);
            uVar3 = *(uint *)(pcVar7 + 8);
            fVar28 = (float)FUN_002917b0(&DAT_01216a60);
            lVar16 = syscall(0xba);
            pcVar20 = (char *)(ulong)uVar3;
            uVar23 = 0x3b;
            dVar29 = (double)(fVar28 * DAT_00298548);
LAB_001249be:
            FUN_002340f0(dVar29,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x %x\n","ERROR",
                         lVar16,"nvml_removal.c",uVar23,pcVar20,uVar30,uVar31,0,iVar13);
LAB_001249e1:
            if (1 < (int)DAT_01216a78) {
              uVar31 = *(undefined2 *)(pcVar7 + 0xe);
              uVar30 = *(undefined2 *)(pcVar7 + 0xc);
              uVar3 = *(uint *)(pcVar7 + 8);
              fVar28 = (float)FUN_002917b0(&DAT_01216a60);
              lVar16 = syscall(0xba);
              pcVar20 = (char *)(ulong)uVar3;
              uVar23 = 0xc5;
              dVar29 = (double)(fVar28 * DAT_00298548);
LAB_00124a5f:
              FUN_002340f0(dVar29,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n","ERROR",
                           lVar16,"nvml_removal.c",uVar23,pcVar20,uVar30,uVar31,0);
            }
          }
LAB_001247a2:
          *piVar25 = iVar13;
          pcVar24 = pcVar20;
          goto LAB_001247b0;
        }
        iVar13 = FUN_0013ea40(pcVar7,lVar17 + -0x68);
        if (iVar13 != 0) {
          if (1 < (int)DAT_01216a78) {
            uVar31 = *(undefined2 *)(pcVar7 + 0xe);
            uVar30 = *(undefined2 *)(pcVar7 + 0xc);
            uVar3 = *(uint *)(pcVar7 + 8);
            fVar28 = (float)FUN_002917b0(&DAT_01216a60);
            lVar16 = syscall(0xba);
            pcVar20 = (char *)(ulong)uVar3;
            uVar23 = 0x45;
            dVar29 = (double)(fVar28 * DAT_00298548);
            goto LAB_001249be;
          }
          goto LAB_001247a2;
        }
        iVar13 = FUN_00192940(pcVar7,lVar17 + 0x104);
        if (iVar13 != 0) {
          if (1 < (int)DAT_01216a78) {
            uVar31 = *(undefined2 *)(pcVar7 + 0xe);
            uVar30 = *(undefined2 *)(pcVar7 + 0xc);
            uVar3 = *(uint *)(pcVar7 + 8);
            fVar28 = (float)FUN_002917b0(&DAT_01216a60);
            lVar16 = syscall(0xba);
            pcVar20 = (char *)(ulong)uVar3;
            uVar23 = 0x4e;
            dVar29 = (double)(fVar28 * DAT_00298548);
            goto LAB_001249be;
          }
          goto LAB_001247a2;
        }
        if (*(int *)(lVar17 + 0x104) == 7) {
          uVar12 = FUN_001281c0();
          *(undefined1 *)(lVar17 + 0x100) = uVar12;
          uVar12 = FUN_001280e0();
          *(undefined1 *)(lVar17 + 0x101) = uVar12;
          lVar16 = *(long *)(pcVar7 + 0x256d8);
          if (((lVar16 == 0) || (*(long *)(lVar16 + 0x38) == 0)) ||
             (pcVar8 = *(code **)(*(long *)(lVar16 + 0x38) + 0x38), pcVar8 == (code *)0x0)) {
            iVar13 = 3;
          }
          else {
            iVar13 = (*pcVar8)(lVar16,pcVar7,lVar17);
            if (iVar13 == 0) goto LAB_00124add;
          }
          if (1 < (int)DAT_01216a78) {
            uVar31 = *(undefined2 *)(pcVar7 + 0xe);
            uVar30 = *(undefined2 *)(pcVar7 + 0xc);
            uVar3 = *(uint *)(pcVar7 + 8);
            fVar28 = (float)FUN_002917b0(&DAT_01216a60);
            lVar16 = syscall(0xba);
            pcVar20 = (char *)(ulong)uVar3;
            uVar23 = 0x60;
            dVar29 = (double)(fVar28 * DAT_00298548);
            goto LAB_001249be;
          }
          goto LAB_001247a2;
        }
LAB_00124add:
        iVar13 = (*param_6)(lVar17 + -0x70);
        if (iVar13 != 0) goto LAB_001249e1;
        lVar16 = *(long *)(pcVar7 + 0x256d8);
        if (((lVar16 == 0) || (*(undefined8 **)(lVar16 + 0xa8) == (undefined8 *)0x0)) ||
           (pcVar8 = (code *)**(undefined8 **)(lVar16 + 0xa8), pcVar8 == (code *)0x0)) {
          iVar13 = 3;
LAB_00124dae:
          if (1 < (int)DAT_01216a78) {
            uVar31 = *(undefined2 *)(pcVar7 + 0xe);
            uVar30 = *(undefined2 *)(pcVar7 + 0xc);
            uVar3 = *(uint *)(pcVar7 + 8);
            fVar28 = (float)FUN_002917b0(&DAT_01216a60);
            lVar16 = syscall(0xba);
            fVar28 = fVar28 * DAT_00298548;
            uVar23 = 0xd4;
LAB_00124e2a:
            pcVar20 = (char *)(ulong)uVar3;
            FUN_002340f0((double)fVar28,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x %x\n",
                         "ERROR",lVar16,"nvml_removal.c",uVar23,pcVar20,uVar30,uVar31,0,iVar13);
          }
          goto LAB_001247a2;
        }
        iVar13 = (*pcVar8)(lVar16,pcVar7,lVar17 + -0x10);
        if (iVar13 != 0) goto LAB_00124dae;
        if (3 < (int)DAT_01216a78) {
          uVar3 = *(uint *)(pcVar7 + 8);
          fVar28 = (float)FUN_002917b0(&DAT_01216a60);
          lVar16 = syscall(0xba);
          pcVar20 = (char *)(ulong)uVar3;
          FUN_002340f0((double)(fVar28 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x %x %x\n",&DAT_002983c2,
                       lVar16);
        }
        if (local_115 == '\0') {
          lVar16 = *(long *)(pcVar7 + 0x256d8);
          if (((lVar16 == 0) || (*(long *)(lVar16 + 200) == 0)) ||
             (pcVar8 = *(code **)(*(long *)(lVar16 + 200) + 0x20), pcVar8 == (code *)0x0)) {
            iVar13 = 3;
LAB_0012580e:
            if ((int)DAT_01216a78 < 2) goto LAB_001247a2;
            fVar28 = (float)FUN_002917b0(&DAT_01216a60);
            lVar16 = syscall(0xba);
            pcVar20 = "openDevice";
            FUN_002340f0((double)(fVar28 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar16,
                         "nvml_removal.c",0x77,"openDevice",0x77,iVar13);
            uVar21 = extraout_RDX_00;
          }
          else {
            iVar13 = (*pcVar8)(lVar16,pcVar7,&local_10c);
            if (iVar13 != 0) goto LAB_0012580e;
            if (local_10c < 0x100) {
              pcVar24 = (char *)&local_b8;
              snprintf(pcVar24,0x80,"/dev/nvidia%d");
              pFVar18 = fopen(pcVar24,"r");
              *(FILE **)(lVar17 + -8) = pFVar18;
              uVar3 = DAT_01216a78;
              if (pFVar18 != (FILE *)0x0) goto LAB_00124b58;
              puVar19 = (uint *)__errno_location();
              uVar21 = (ulong)uVar3;
              if (0 < (int)uVar3) {
                uVar3 = *puVar19;
                pcVar20 = strerror(uVar3);
                fVar28 = (float)FUN_002917b0(&DAT_01216a60);
                lVar16 = syscall(0xba);
                uVar21 = (ulong)uVar3;
                FUN_002340f0((double)(fVar28 * DAT_00298548),
                             "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %s %d\n","CRITICAL",lVar16,
                             "nvml_removal.c",0x8c,pcVar24,pcVar20);
                pcVar20 = pcVar24;
              }
              if (*puVar19 == 0xd) {
                iVar13 = 4;
              }
              else {
                iVar13 = 9;
                if ((*puVar19 & 0xfffffffb) != 2) {
                  iVar13 = 999;
                }
              }
            }
            else {
              iVar13 = 999;
              uVar21 = extraout_RDX;
            }
          }
          if ((int)DAT_01216a78 < 2) goto LAB_001247a2;
          uVar31 = *(undefined2 *)(pcVar7 + 0xe);
          uVar30 = *(undefined2 *)(pcVar7 + 0xc);
          uVar3 = *(uint *)(pcVar7 + 8);
          fVar28 = (float)FUN_002917b0(&DAT_01216a60,uVar30,uVar21);
          lVar16 = syscall(0xba);
          fVar28 = fVar28 * DAT_00298548;
          uVar23 = 0xe9;
          goto LAB_00124e2a;
        }
LAB_00124b58:
        if (((DAT_012164a0 == 0) || (*(undefined8 **)(DAT_012164a0 + 0x138) == (undefined8 *)0x0))
           || (pcVar8 = (code *)**(undefined8 **)(DAT_012164a0 + 0x138), pcVar8 == (code *)0x0)) {
          iVar13 = 3;
LAB_00124d1e:
          if (1 < (int)DAT_01216a78) {
            uVar31 = *(undefined2 *)(pcVar7 + 0xe);
            uVar30 = *(undefined2 *)(pcVar7 + 0xc);
            uVar3 = *(uint *)(pcVar7 + 8);
            fVar28 = (float)FUN_002917b0(&DAT_01216a60);
            lVar16 = syscall(0xba);
            pcVar20 = (char *)(ulong)uVar3;
            uVar23 = 0xf9;
            dVar29 = (double)(fVar28 * DAT_00298548);
            goto LAB_00124a5f;
          }
          goto LAB_001247a2;
        }
        iVar13 = (*pcVar8)(DAT_012164a0,lVar17 + -0x68,1);
        if (iVar13 != 0) goto LAB_00124d1e;
        lVar16 = *(long *)(pcVar7 + 0x256d8);
        if (((lVar16 == 0) || (*(long *)(lVar16 + 0xa8) == 0)) ||
           (pcVar8 = *(code **)(*(long *)(lVar16 + 0xa8) + 0x10), pcVar8 == (code *)0x0)) {
          iVar13 = 3;
LAB_0012589e:
          if (1 < (int)DAT_01216a78) {
            uVar31 = *(undefined2 *)(pcVar7 + 0xe);
            uVar30 = *(undefined2 *)(pcVar7 + 0xc);
            uVar3 = *(uint *)(pcVar7 + 8);
            fVar28 = (float)FUN_002917b0(&DAT_01216a60);
            lVar16 = syscall(0xba);
            pcVar20 = (char *)(ulong)uVar3;
            uVar23 = 0x10a;
            dVar29 = (double)(fVar28 * DAT_00298548);
            goto LAB_00124a5f;
          }
          goto LAB_001247a2;
        }
        iVar13 = (*pcVar8)(lVar16,pcVar7,0);
        if (iVar13 != 0) goto LAB_0012589e;
        if (3 < (int)DAT_01216a78) {
          uVar3 = *(uint *)(pcVar7 + 8);
          fVar28 = (float)FUN_002917b0(&DAT_01216a60);
          lVar16 = syscall(0xba);
          pcVar20 = (char *)(ulong)uVar3;
          FUN_002340f0((double)(fVar28 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n",&DAT_002983c2,lVar16
                      );
        }
        do {
          iVar13 = FUN_00291820(pcVar7 + 0x30,1,0);
        } while (iVar13 != 0);
        pcVar7[0x2c] = '\0';
        pcVar7[0x2d] = '\0';
        pcVar7[0x2e] = '\0';
        pcVar7[0x2f] = '\0';
        FUN_00291830(pcVar7 + 0x30,0);
        pcVar7[0x25700] = '\0';
        pcVar7[0x25701] = '\0';
        pcVar7[0x25702] = '\0';
        pcVar7[0x25703] = '\0';
        if ((*pcVar7 == '\x01') ||
           ((((*(int *)(pcVar7 + 0x14) != 0 && (*(int *)(pcVar7 + 0x1c) == 0)) &&
             (*(int *)(pcVar7 + 0x10) != 0)) && (*(long *)(pcVar7 + 0x20) != 0)))) {
          lVar16 = *(long *)(pcVar7 + 0x256d8);
          if (((lVar16 != 0) && (*(long *)(lVar16 + 0x20) != 0)) &&
             (pcVar8 = *(code **)(*(long *)(lVar16 + 0x20) + 0x18), pcVar8 != (code *)0x0)) {
            (*pcVar8)(lVar16,pcVar7);
          }
          if (3 < (int)DAT_01216a78) {
            uVar3 = *(uint *)(pcVar7 + 8);
            fVar28 = (float)FUN_002917b0(&DAT_01216a60);
            lVar16 = syscall(0xba);
            pcVar20 = (char *)(ulong)uVar3;
            FUN_002340f0((double)(fVar28 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n",&DAT_002983c2,
                         lVar16);
          }
        }
        if ((*(char *)(lVar17 + 0x100) != '\0') && (iVar13 = FUN_001281f0(lVar17), iVar13 != 0)) {
          if (1 < (int)DAT_01216a78) {
            uVar31 = *(undefined2 *)(pcVar7 + 0xe);
            uVar30 = *(undefined2 *)(pcVar7 + 0xc);
            uVar3 = *(uint *)(pcVar7 + 8);
            fVar28 = (float)FUN_002917b0(&DAT_01216a60);
            lVar16 = syscall(0xba);
            pcVar20 = (char *)(ulong)uVar3;
            uVar23 = 300;
            dVar29 = (double)(fVar28 * DAT_00298548);
            goto LAB_00124a5f;
          }
          goto LAB_001247a2;
        }
        lVar16 = *(long *)(pcVar7 + 0x256d8);
        if (lVar16 == 0) {
LAB_00125c13:
          iVar13 = 3;
          goto LAB_001247a2;
        }
        pcVar24 = pcVar20;
        if (*(undefined8 **)(lVar16 + 0x60) == (undefined8 *)0x0) goto LAB_001248f0;
        pcVar8 = (code *)**(undefined8 **)(lVar16 + 0x60);
        if (pcVar8 == (code *)0x0) goto LAB_00125c13;
        iVar13 = (*pcVar8)(lVar16,pcVar7,local_108);
        pcVar24 = pcVar20;
        if (iVar13 == 0) {
          if (local_f8._4_4_ != 0) {
            if ((int)DAT_01216a78 < 2) {
              *piVar25 = 0x13;
              iVar13 = 0x13;
            }
            else {
              uVar31 = *(undefined2 *)(pcVar7 + 0xc);
              uVar30 = *(undefined2 *)(pcVar7 + 0xe);
              uVar3 = *(uint *)(pcVar7 + 8);
              fVar28 = (float)FUN_002917b0(&DAT_01216a60);
              lVar16 = syscall(0xba);
              pcVar24 = (char *)(ulong)uVar3;
              iVar13 = 0x13;
              FUN_002340f0((double)(fVar28 * DAT_00298548),
                           "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n","ERROR",lVar16,
                           "nvml_removal.c",0x13a,pcVar24,uVar31,uVar30,0,pcVar20);
              *piVar25 = 0x13;
            }
            goto LAB_001247b0;
          }
LAB_00124cea:
          if (*(char *)(lVar17 + 0x100) != '\0') {
LAB_00125c44:
            iVar13 = FUN_00128350(lVar17);
            if (iVar13 != 0) {
              if (1 < (int)DAT_01216a78) {
                uVar31 = *(undefined2 *)(pcVar7 + 0xe);
                uVar30 = *(undefined2 *)(pcVar7 + 0xc);
                uVar3 = *(uint *)(pcVar7 + 8);
                fVar28 = (float)FUN_002917b0(&DAT_01216a60);
                lVar16 = syscall(0xba);
                pcVar20 = (char *)(ulong)uVar3;
                uVar23 = 0x153;
                dVar29 = (double)(fVar28 * DAT_00298548);
                goto LAB_00124a5f;
              }
              goto LAB_001247a2;
            }
          }
          pcVar24 = pcVar20;
          if ((int)DAT_01216a78 < 4) goto LAB_00124d07;
          uVar31 = *(undefined2 *)(pcVar7 + 0xc);
          uVar30 = *(undefined2 *)(pcVar7 + 0xe);
          uVar3 = *(uint *)(pcVar7 + 8);
          fVar28 = (float)FUN_002917b0(&DAT_01216a60);
          lVar16 = syscall(0xba);
          pcVar24 = (char *)(ulong)uVar3;
          FUN_002340f0((double)(fVar28 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n",&DAT_002983c2,lVar16
                       ,"nvml_removal.c",0x15a,pcVar24,uVar31,uVar30,0);
          *piVar25 = 0;
        }
        else {
          if (iVar13 != 6) goto LAB_001247a2;
          if (3 < (int)DAT_01216a78) {
            uVar3 = *(uint *)(pcVar7 + 8);
            fVar28 = (float)FUN_002917b0(&DAT_01216a60);
            lVar16 = syscall(0xba);
            pcVar20 = (char *)(ulong)uVar3;
            FUN_002340f0((double)(fVar28 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n",&DAT_002983c2,
                         lVar16);
            goto LAB_00124cea;
          }
          if (*(char *)(lVar17 + 0x100) != '\0') goto LAB_00125c44;
LAB_00124d07:
          *piVar25 = 0;
        }
      }
      puVar26 = puVar26 + 2;
      piVar25 = piVar25 + 1;
      lVar17 = lVar17 + 0x178;
    } while (param_4 + (ulong)(uVar1 - 1) + 1 != piVar25);
    if (local_124 != 0) {
      FUN_001236f0(uVar1,__ptr);
      FUN_00123770(uVar1,puVar15,__ptr,0);
      FUN_00123b70(uVar1,puVar15,__ptr);
      goto LAB_001248cb;
    }
  }
  if ((uVar2 != 0) && (param_5 != (int *)0x0)) {
    local_124 = 0;
    pvVar22 = pvVar14;
    piVar25 = param_5;
    pauVar27 = (undefined1 (*) [16])(param_1 + 0x42);
    do {
      uVar21 = *(ulong *)pauVar27[1];
      uVar9 = *(ulong *)((long)pauVar27[1] + 8);
      local_b8 = *(undefined8 *)*pauVar27;
      uStack_b0 = *(undefined8 *)((long)*pauVar27 + 8);
      local_108 = *pauVar27;
      *(undefined8 *)((long)pvVar22 + 0x58) = 0;
      local_e8 = *(undefined8 *)pauVar27[2];
      uStack_e0 = *(undefined8 *)((long)pauVar27[2] + 8);
      local_d8 = *(undefined8 *)pauVar27[3];
      uStack_d0 = *(undefined8 *)((long)pauVar27[3] + 8);
      local_c8 = *(uint *)pauVar27[4];
      local_f8._4_4_ = (int)(uVar21 >> 0x20);
      uVar6 = local_f8._4_4_;
      local_f8 = uVar21;
      uStack_f0 = uVar9;
      local_a8 = uVar21;
      uStack_a0 = uVar9;
      local_98 = local_e8;
      uStack_90 = uStack_e0;
      local_88 = local_d8;
      uStack_80 = uStack_d0;
      local_78 = local_c8;
      iVar13 = FUN_00237550(uVar21 & 0xffffffff,uVar6,uVar9 & 0xffffffff,0,pvVar22);
      if (iVar13 == 0) {
        *(undefined1 *)((long)pvVar22 + 0x170) = 0;
        *(undefined1 *)((long)pvVar22 + 0x171) = 0;
        *(uint *)((long)pvVar22 + 0x48) = local_78;
        *(undefined8 *)((long)pvVar22 + 8) = local_b8;
        *(undefined8 *)((long)pvVar22 + 0x10) = uStack_b0;
        *(ulong *)((long)pvVar22 + 0x18) = local_a8;
        *(ulong *)((long)pvVar22 + 0x20) = uStack_a0;
        *(undefined8 *)((long)pvVar22 + 0x28) = local_98;
        *(undefined8 *)((long)pvVar22 + 0x30) = uStack_90;
        *(undefined8 *)((long)pvVar22 + 0x38) = local_88;
        *(undefined8 *)((long)pvVar22 + 0x40) = uStack_80;
        iVar13 = (*param_6)(pvVar22);
        if (iVar13 != 0) goto LAB_00125356;
        if (((DAT_012164a0 == 0) || (*(undefined8 **)(DAT_012164a0 + 0x138) == (undefined8 *)0x0))
           || (pcVar8 = (code *)**(undefined8 **)(DAT_012164a0 + 0x138), pcVar8 == (code *)0x0)) {
          iVar13 = 3;
LAB_001250d6:
          uVar21 = uStack_f0;
          if (1 < (int)DAT_01216a78) {
            uVar10 = local_f8._4_4_;
            uVar6 = (undefined4)local_f8;
            fVar28 = (float)FUN_002917b0(&DAT_01216a60);
            lVar17 = syscall(0xba);
            fVar28 = fVar28 * DAT_00298548;
            uVar23 = 0x22a;
            goto LAB_00125159;
          }
          goto LAB_0012501f;
        }
        iVar13 = (*pcVar8)(DAT_012164a0,local_108,1);
        uVar9 = uStack_f0;
        uVar21 = local_f8;
        if (iVar13 != 0) goto LAB_001250d6;
        if ((int)DAT_01216a78 < 4) {
          *piVar25 = 0;
        }
        else {
          uVar11 = local_f8 >> 0x20;
          fVar28 = (float)FUN_002917b0(&DAT_01216a60);
          lVar17 = syscall(0xba);
          FUN_002340f0((double)(fVar28 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n",&DAT_002983c2,lVar17
                       ,"nvml_removal.c",0x233,uVar21 & 0xffffffff,uVar11,uVar9 & 0xffffffff,0);
          *piVar25 = 0;
        }
      }
      else {
        if (1 < (int)DAT_01216a78) {
          fVar28 = (float)FUN_002917b0(&DAT_01216a60);
          lVar17 = syscall(0xba);
          FUN_002340f0((double)(fVar28 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x %x\n","ERROR",lVar17,
                       "nvml_removal.c",0x1fc,uVar21 & 0xffffffff,uVar6,uVar9 & 0xffffffff,0,iVar13)
          ;
LAB_00125356:
          uVar21 = uStack_f0;
          if (1 < (int)DAT_01216a78) {
            uVar10 = local_f8._4_4_;
            uVar6 = (undefined4)local_f8;
            fVar28 = (float)FUN_002917b0(&DAT_01216a60);
            lVar17 = syscall(0xba);
            fVar28 = fVar28 * DAT_00298548;
            uVar23 = 0x21c;
LAB_00125159:
            FUN_002340f0((double)fVar28,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x\n",
                         "ERROR",lVar17,"nvml_removal.c",uVar23,uVar6,uVar10,uVar21 & 0xffffffff,0);
          }
        }
LAB_0012501f:
        *piVar25 = iVar13;
        if (1 < (int)DAT_01216a78) {
          uVar3 = *(uint *)((long)pauVar27[1] + 8);
          uVar4 = *(uint *)((long)pauVar27[1] + 4);
          uVar5 = *(uint *)pauVar27[1];
          fVar28 = (float)FUN_002917b0(&DAT_01216a60);
          lVar17 = syscall(0xba);
          FUN_002340f0((double)(fVar28 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x %x\n","ERROR",lVar17,
                       "nvml_removal.c",0x24f,uVar5,uVar4,uVar3,0,iVar13);
        }
        local_124 = 999;
      }
      pauVar27 = (undefined1 (*) [16])((long)pauVar27[4] + 4);
      pvVar22 = (void *)((long)pvVar22 + 0x178);
      piVar25 = piVar25 + 1;
    } while (piVar25 != param_5 + (ulong)(uVar2 - 1) + 1);
    if (local_124 != 0) {
      FUN_001236f0(uVar2,pvVar14);
      goto LAB_001248cb;
    }
  }
  if (3 < (int)DAT_01216a78) {
    fVar28 = (float)FUN_002917b0(&DAT_01216a60);
    lVar17 = syscall(0xba);
    FUN_002340f0((double)(fVar28 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar17,"nvml_removal.c",0x34d);
  }
  if (((uVar1 == 0) || (local_124 = FUN_00123ce0(uVar1,puVar15,__ptr,param_4), local_124 == 0)) &&
     ((uVar2 == 0 ||
      (local_124 = FUN_00124170(uVar2,(undefined1 (*) [16])(param_1 + 0x42),pvVar14,param_5),
      local_124 == 0)))) {
    *param_2 = __ptr;
    *param_3 = pvVar14;
    return 0;
  }
LAB_001248cb:
  FUN_00124440(uVar1,uVar2,__ptr,pvVar14);
  return local_124;
}


// ===== 00125f90 FUN_00125f90 =====

int FUN_00125f90(undefined8 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  float fVar6;
  
  if (param_1 == (undefined8 *)0x0) {
    return 2;
  }
  iVar4 = FUN_00237fe0(*param_1,param_1 + 10);
  if ((iVar4 != 0) && (1 < DAT_01216a78)) {
    uVar1 = *(undefined4 *)(param_1 + 4);
    uVar2 = *(undefined4 *)((long)param_1 + 0x1c);
    uVar3 = *(undefined4 *)(param_1 + 3);
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    FUN_002340f0((double)(fVar6 * DAT_00298548),
                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x %x\n","ERROR",lVar5,
                 "nvml_zpi.c",0xa4,uVar3,uVar2,uVar1,0,iVar4);
    return iVar4;
  }
  return iVar4;
}


// ===== 00126080 FUN_00126080 =====

int FUN_00126080(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  int iVar10;
  undefined8 *puVar11;
  float fVar12;
  undefined8 *local_68;
  undefined4 local_58;
  undefined8 *local_48;
  undefined8 local_40 [2];
  
  if (param_1[0x262] == 0) {
    return 2;
  }
  iVar2 = *param_1;
  if (3 < DAT_01216a78) {
    fVar12 = (float)FUN_002917b0(&DAT_01216a60);
    lVar7 = syscall(0xba);
    FUN_002340f0((double)(fVar12 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar7,"nvml_zpi.c",0xbc);
  }
  iVar6 = FUN_001244a0(param_1,&local_48,local_40,param_2,0,FUN_00125f90);
  if (iVar6 != 0) {
    return iVar6;
  }
  local_68 = local_48;
  if (3 < DAT_01216a78) {
    fVar12 = (float)FUN_002917b0(&DAT_01216a60);
    lVar7 = syscall(0xba);
    FUN_002340f0((double)(fVar12 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                 &DAT_002983c2,lVar7,"nvml_zpi.c",199);
    local_68 = local_48;
  }
  if (iVar2 != 0) {
    piVar1 = param_2 + (ulong)(iVar2 - 1) + 1;
    puVar11 = local_68;
    local_48 = local_68;
    do {
      iVar6 = FUN_00239290(*puVar11);
      if (iVar6 != 0) {
        if (DAT_01216a78 < 2) goto LAB_00126143;
        local_58 = *(undefined4 *)(puVar11 + 4);
        uVar3 = *(undefined4 *)((long)puVar11 + 0x1c);
        uVar4 = *(undefined4 *)(puVar11 + 3);
        fVar12 = (float)FUN_002917b0(&DAT_01216a60);
        lVar7 = syscall(0xba);
        fVar12 = fVar12 * DAT_00298548;
        uVar8 = 0x21;
LAB_00126295:
        FUN_002340f0((double)fVar12,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x %x\n",
                     "ERROR",lVar7,"nvml_zpi.c",uVar8,uVar4,uVar3,local_58,0,iVar6);
        *param_2 = iVar6;
joined_r0x001262c5:
        if (1 < DAT_01216a78) {
          uVar3 = *(undefined4 *)(puVar11 + 4);
          uVar4 = *(undefined4 *)((long)puVar11 + 0x1c);
          uVar5 = *(undefined4 *)(puVar11 + 3);
          fVar12 = (float)FUN_002917b0(&DAT_01216a60);
          lVar7 = syscall(0xba);
          FUN_002340f0((double)(fVar12 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x %x\n","ERROR",lVar7,
                       "nvml_zpi.c",0x79,uVar5,uVar4,uVar3,0,iVar6);
        }
        puVar11 = local_68;
        goto LAB_00126190;
      }
      iVar6 = FUN_002397e0(puVar11[10],0);
      if (iVar6 != 0) {
        if (1 < DAT_01216a78) {
          local_58 = *(undefined4 *)(puVar11 + 4);
          uVar3 = *(undefined4 *)((long)puVar11 + 0x1c);
          uVar4 = *(undefined4 *)(puVar11 + 3);
          fVar12 = (float)FUN_002917b0(&DAT_01216a60);
          lVar7 = syscall(0xba);
          fVar12 = fVar12 * DAT_00298548;
          uVar8 = 0x2d;
          goto LAB_00126295;
        }
LAB_00126143:
        *param_2 = iVar6;
        goto joined_r0x001262c5;
      }
      *param_2 = 0;
      param_2 = param_2 + 1;
      puVar11 = puVar11 + 0x2f;
    } while (piVar1 != param_2);
    local_68 = local_48;
  }
  param_1[0x262] = 0;
  iVar10 = 0;
  goto LAB_001261f8;
  while (puVar11 = puVar11 + 0x2f, puVar9 = local_68,
        local_68 + (ulong)(iVar2 - 1) * 0x2f + 0x2f != puVar11) {
LAB_00126190:
    iVar6 = FUN_002397e0(puVar11[10],1);
    if (iVar6 != 0) {
      if (DAT_01216a78 < 2) goto LAB_001261b5;
      uVar3 = *(undefined4 *)(puVar11 + 4);
      uVar4 = *(undefined4 *)((long)puVar11 + 0x1c);
      uVar5 = *(undefined4 *)(puVar11 + 3);
      fVar12 = (float)FUN_002917b0(&DAT_01216a60);
      lVar7 = syscall(0xba);
      fVar12 = fVar12 * DAT_00298548;
      uVar8 = 0x5e;
      goto LAB_001265ae;
    }
  }
  do {
    iVar6 = FUN_002394e0(puVar9[10]);
    if (iVar6 != 0) {
      if (DAT_01216a78 < 2) {
LAB_001261b5:
        iVar10 = 0x10;
        local_68 = local_48;
      }
      else {
        uVar3 = *(undefined4 *)(puVar9 + 4);
        uVar4 = *(undefined4 *)((long)puVar9 + 0x1c);
        uVar5 = *(undefined4 *)(puVar9 + 3);
        fVar12 = (float)FUN_002917b0(&DAT_01216a60);
        lVar7 = syscall(0xba);
        fVar12 = fVar12 * DAT_00298548;
        uVar8 = 0x45;
LAB_001265ae:
        iVar10 = 0x10;
        FUN_002340f0((double)fVar12,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%04x:%02x:%02x.%x %x\n",
                     "ERROR",lVar7,"nvml_zpi.c",uVar8,uVar5,uVar4,uVar3,0,iVar6);
        local_68 = local_48;
      }
      goto LAB_001261f8;
    }
    puVar9 = puVar9 + 0x2f;
  } while (puVar9 != local_68 + (ulong)(iVar2 - 1) * 0x2f + 0x2f);
  iVar10 = 999;
  FUN_001236f0(iVar2,local_68);
  FUN_00123770(iVar2,param_1 + 2,local_68,0);
  FUN_00123b70(iVar2,param_1 + 2,local_68);
  local_68 = local_48;
LAB_001261f8:
  FUN_00124440(iVar2,0,local_68,local_40[0]);
  return iVar10;
}


// ===== 001265f0 FUN_001265f0 =====

undefined8 FUN_001265f0(void)

{
  return 3;
}


// ===== 00126600 FUN_00126600 =====

int FUN_00126600(long *param_1,long *param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *param_1;
  lVar2 = *param_2;
  if (*(int *)(lVar1 + 8) != *(int *)(lVar2 + 8)) {
    return *(int *)(lVar1 + 8) - *(int *)(lVar2 + 8);
  }
  if (*(ushort *)(lVar1 + 0xc) != *(ushort *)(lVar2 + 0xc)) {
    return (uint)*(ushort *)(lVar1 + 0xc) - (uint)*(ushort *)(lVar2 + 0xc);
  }
  return (uint)*(ushort *)(lVar1 + 0xe) - (uint)*(ushort *)(lVar2 + 0xe);
}


// ===== 00126640 FUN_00126640 =====

int FUN_00126640(long param_1,long param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10) - *(int *)(param_2 + 0x10);
  if ((*(int *)(param_1 + 0x10) == *(int *)(param_2 + 0x10)) &&
     (iVar1 = *(int *)(param_1 + 0x14) - *(int *)(param_2 + 0x14),
     *(int *)(param_1 + 0x14) == *(int *)(param_2 + 0x14))) {
    return *(int *)(param_1 + 0x18) - *(int *)(param_2 + 0x18);
  }
  return iVar1;
}


// ===== 00126680 FUN_00126680 =====

undefined4 FUN_00126680(char *param_1,uint *param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined4 uVar4;
  float fVar5;
  
  uVar4 = 2;
  if ((param_1 != (char *)0x0) &&
     ((*param_1 == '\x01' ||
      ((((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))))) {
    if (*(int *)(param_1 + 0x71c) == 0) {
      do {
        iVar2 = FUN_00291820(param_1 + 0x720,1,0);
      } while (iVar2 != 0);
      if (*(int *)(param_1 + 0x71c) == 0) {
        lVar3 = *(long *)(param_1 + 0x256d8);
        uVar4 = 3;
        if (((lVar3 != 0) && (*(long *)(lVar3 + 0x20) != 0)) &&
           (pcVar1 = *(code **)(*(long *)(lVar3 + 0x20) + 0x98), pcVar1 != (code *)0x0)) {
          uVar4 = (*pcVar1)(lVar3,param_1,param_1 + 0x708);
        }
        *(undefined4 *)(param_1 + 0x724) = uVar4;
        param_1[0x71c] = '\x01';
        param_1[0x71d] = '\0';
        param_1[0x71e] = '\0';
        param_1[0x71f] = '\0';
      }
      FUN_00291830(param_1 + 0x720,0);
    }
    if (*(int *)(param_1 + 0x724) == 0) {
      if (4 < DAT_01216a78) {
        uVar4 = *(undefined4 *)(param_1 + 0x708);
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),
                     "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tisArchOrNewer called: %d %d\n","DEBUG",
                     lVar3,"/dvs/p4/build/sw/rel/gpu_drv/r595/r596_25/apps/nvml/dmal/dmal.h",0x3d,10
                     ,uVar4);
      }
      *param_2 = (uint)(9 < *(uint *)(param_1 + 0x708));
      return 0;
    }
    if (*(int *)(param_1 + 0x724) == 0xf) {
      uVar4 = 0xf;
      if (4 < DAT_01216a78) {
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),
                     "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tisArchOrNewer error: %d\n","DEBUG",lVar3,
                     "/dvs/p4/build/sw/rel/gpu_drv/r595/r596_25/apps/nvml/dmal/dmal.h",0x42,10);
      }
    }
    else {
      if (1 < DAT_01216a78) {
        fVar5 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        FUN_002340f0((double)(fVar5 * DAT_00298548),
                     "%s:\t[tid %llu]\t[%.06fs - %s:%d]\tFailure to determine Architecture\n",
                     "ERROR",lVar3,"/dvs/p4/build/sw/rel/gpu_drv/r595/r596_25/apps/nvml/dmal/dmal.h"
                     ,0x46);
      }
      *param_2 = 0;
      uVar4 = 0;
    }
  }
  return uVar4;
}


// ===== 00126920 FUN_00126920 =====

int FUN_00126920(long param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  int *piVar6;
  long lVar7;
  uint uVar8;
  uint uVar9;
  int *piVar11;
  float fVar12;
  ulong uVar10;
  
  if (*(int *)(param_1 + 4) != 0) {
    uVar8 = 0;
    piVar11 = (int *)(param_1 + 0x118);
    do {
      iVar1 = *piVar11;
      uVar2 = piVar11[1];
      uVar3 = piVar11[2];
      if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x20) == 0)) ||
         (pcVar4 = *(code **)(*(long *)(DAT_012164a0 + 0x20) + 8), pcVar4 == (code *)0x0)) {
        iVar5 = 3;
LAB_00126a51:
        if (DAT_01216a78 < 2) {
          return iVar5;
        }
        fVar12 = (float)FUN_002917b0(&DAT_01216a60);
        lVar7 = syscall(0xba);
        FUN_002340f0((double)(fVar12 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n",
                     "ERROR",lVar7,"nvml_devgroup.c",0x124,iVar5);
        return iVar5;
      }
      iVar5 = (*pcVar4)(DAT_012164a0,iVar1,uVar2 & 0xffff,uVar3 & 0xffff);
      if (iVar5 != 0) goto LAB_00126a51;
      piVar6 = &DAT_012148f8;
      uVar10 = 0;
      if (DAT_01215b68 != 0) {
        do {
          if (((*piVar6 == iVar1) && (piVar6[1] == uVar2)) && (piVar6[2] == uVar3)) {
            if (DAT_01216a78 < 4) {
              return 3;
            }
            fVar12 = (float)FUN_002917b0(&DAT_01216a60);
            lVar7 = syscall(0xba);
            FUN_002340f0((double)(fVar12 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u %u %s\n",&DAT_002983c2,lVar7,
                         "nvml_devgroup.c",0x132,iVar1,uVar2,uVar3,&DAT_0121492c + uVar10 * 0x94);
            return 3;
          }
          uVar9 = (int)uVar10 + 1;
          uVar10 = (ulong)uVar9;
          piVar6 = piVar6 + 0x25;
        } while (uVar9 != DAT_01215b68);
      }
      uVar8 = uVar8 + 1;
      piVar11 = piVar11 + 0x11;
    } while (uVar8 < *(uint *)(param_1 + 4));
  }
  return 0;
}


// ===== 00126b50 FUN_00126b50 =====

int FUN_00126b50(uint *param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  char *pcVar3;
  code *pcVar4;
  undefined1 *puVar5;
  char cVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  long lVar11;
  ulong uVar12;
  long *plVar13;
  long lVar14;
  uint uVar15;
  undefined8 uVar16;
  uint uVar17;
  long lVar18;
  float fVar19;
  double dVar20;
  long *local_80;
  int local_70;
  int local_6c;
  uint local_68;
  int local_64;
  long local_60;
  undefined4 local_54;
  undefined2 local_50;
  undefined2 local_4e;
  undefined1 local_48 [24];
  
  local_70 = 0;
  if (*param_1 != 0) {
    lVar18 = 0;
    do {
      iVar7 = FUN_00126680(*(undefined8 *)(param_1 + lVar18 * 2 + 2),&local_70);
      if (iVar7 != 0) {
        if (DAT_01216a78 < 2) {
          return iVar7;
        }
        fVar19 = (float)FUN_002917b0(&DAT_01216a60);
        lVar18 = syscall(0xba);
        uVar16 = 0x149;
        dVar20 = (double)(fVar19 * DAT_00298548);
        goto LAB_00127353;
      }
      pcVar3 = *(char **)(param_1 + lVar18 * 2 + 2);
      if ((pcVar3 == (char *)0x0) ||
         ((*pcVar3 != '\x01' &&
          ((((*(int *)(pcVar3 + 0x14) == 0 || (*(int *)(pcVar3 + 0x1c) != 0)) ||
            (*(int *)(pcVar3 + 0x10) == 0)) || (*(long *)(pcVar3 + 0x20) == 0)))))) {
        iVar7 = 2;
LAB_00126ffe:
        if (DAT_01216a78 < 2) {
          return iVar7;
        }
        fVar19 = (float)FUN_002917b0(&DAT_01216a60);
        lVar18 = syscall(0xba);
        uVar16 = 0x14f;
        dVar20 = (double)(fVar19 * DAT_00298548);
        goto LAB_00127353;
      }
      if (*(int *)(pcVar3 + 0x71c) == 0) {
        do {
          iVar7 = FUN_00291820(pcVar3 + 0x720,1,0);
        } while (iVar7 != 0);
        if (*(int *)(pcVar3 + 0x71c) == 0) {
          lVar11 = *(long *)(pcVar3 + 0x256d8);
          uVar8 = 3;
          if (((lVar11 != 0) && (*(long *)(lVar11 + 0x20) != 0)) &&
             (pcVar4 = *(code **)(*(long *)(lVar11 + 0x20) + 0x98), pcVar4 != (code *)0x0)) {
            uVar8 = (*pcVar4)(lVar11,pcVar3,pcVar3 + 0x708);
          }
          *(undefined4 *)(pcVar3 + 0x724) = uVar8;
          pcVar3[0x71c] = '\x01';
          pcVar3[0x71d] = '\0';
          pcVar3[0x71e] = '\0';
          pcVar3[0x71f] = '\0';
        }
        FUN_00291830(pcVar3 + 0x720,0);
      }
      if (*(int *)(pcVar3 + 0x724) == 0) {
        if ((local_70 == 0) ||
           (((uVar17 = DAT_01214898, *(int *)(pcVar3 + 0x708) == 10 &&
             (cVar6 = FUN_001280e0(), uVar17 = DAT_01214898, cVar6 != '\0')) &&
            (cVar6 = FUN_001281c0(), uVar17 = DAT_01214898, cVar6 == '\0')))) {
LAB_00126d70:
          puVar5 = *(undefined1 **)(param_1 + lVar18 * 2 + 2);
          if (puVar5 == (undefined1 *)0x0) {
            iVar7 = 2;
          }
          else {
            uVar2 = *param_1;
            local_60 = 0;
            local_68 = 0;
            if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0xb8) == 0)) ||
               (pcVar4 = *(code **)(*(long *)(DAT_012164a0 + 0xb8) + 0x38), pcVar4 == (code *)0x0))
            {
              iVar9 = 3;
LAB_00127061:
              if (DAT_01216a78 < 2) {
                return iVar9;
              }
              fVar19 = (float)FUN_002917b0(&DAT_01216a60);
              lVar18 = syscall(0xba);
              uVar16 = 0x75;
              fVar19 = fVar19 * DAT_00298548;
              iVar7 = iVar9;
LAB_001270ab:
              FUN_002340f0((double)fVar19,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","ERROR",lVar18,
                           "nvml_devgroup.c",uVar16,iVar9);
              iVar9 = DAT_01216a78;
            }
            else {
              iVar9 = (*pcVar4)(DAT_012164a0,&local_64);
              uVar17 = DAT_01214898;
              if (iVar9 != 0) goto LAB_00127061;
              if (local_64 != 1) {
                local_80 = malloc((ulong)(DAT_01214898 - 1) << 3);
                if (local_80 != (long *)0x0) {
                  if (uVar17 != 0) {
                    uVar17 = 0;
                    uVar15 = 0;
                    do {
                      puVar1 = &DAT_00380898 + (ulong)uVar17 * 0x74a00;
                      if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x20) == 0)) ||
                         (pcVar4 = *(code **)(*(long *)(DAT_012164a0 + 0x20) + 0xb8),
                         pcVar4 == (code *)0x0)) {
                        iVar9 = 3;
LAB_0012728d:
                        if (1 < DAT_01216a78) {
                          fVar19 = (float)FUN_002917b0(&DAT_01216a60);
                          lVar18 = syscall(0xba);
                          FUN_002340f0((double)(fVar19 * DAT_00298548),
                                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","ERROR",lVar18,
                                       "nvml_devgroup.c",0x49);
                        }
                        iVar7 = DAT_01216a78;
                        free(local_80);
                        goto LAB_001272b2;
                      }
                      iVar9 = (*pcVar4)(DAT_012164a0,puVar1);
                      if (iVar9 != 0) goto LAB_0012728d;
                      if (puVar5 != puVar1) {
                        uVar12 = (ulong)uVar15;
                        uVar15 = uVar15 + 1;
                        local_80[uVar12] = (long)puVar1;
                      }
                      uVar17 = uVar17 + 1;
                    } while (uVar17 < DAT_01214898);
                    goto LAB_0012742f;
                  }
                  goto LAB_00126d1d;
                }
                iVar9 = 999;
                iVar7 = DAT_01216a78;
LAB_001272b2:
                if (iVar7 < 2) {
                  return 2;
                }
                fVar19 = (float)FUN_002917b0(&DAT_01216a60);
                lVar18 = syscall(0xba);
                uVar16 = 0x80;
                fVar19 = fVar19 * DAT_00298548;
                iVar7 = 2;
                goto LAB_001270ab;
              }
              lVar11 = *(long *)(puVar5 + 0x256d8);
              if (((lVar11 == 0) || (*(undefined8 **)(lVar11 + 0x158) == (undefined8 *)0x0)) ||
                 ((pcVar4 = (code *)**(undefined8 **)(lVar11 + 0x158), pcVar4 == (code *)0x0 ||
                  ((iVar7 = (*pcVar4)(lVar11,puVar5,&local_68), uVar17 = DAT_01214898, iVar7 != 0 ||
                   (local_68 == 0)))))) goto LAB_00126d1d;
              local_80 = malloc((ulong)local_68 * 8);
              if (local_80 != (long *)0x0) {
                uVar17 = 0;
                uVar15 = 0;
LAB_00126e72:
                do {
                  lVar11 = *(long *)(puVar5 + 0x256d8);
                  if (((lVar11 == 0) || (*(long *)(lVar11 + 0x158) == 0)) ||
                     (pcVar4 = *(code **)(*(long *)(lVar11 + 0x158) + 0x28), pcVar4 == (code *)0x0))
                  {
                    iVar7 = 3;
LAB_00127591:
                    if (1 < DAT_01216a78) {
                      fVar19 = (float)FUN_002917b0(&DAT_01216a60);
                      lVar18 = syscall(0xba);
                      uVar16 = 0x9f;
                      dVar20 = (double)(fVar19 * DAT_00298548);
LAB_00127541:
                      FUN_002340f0(dVar20,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","ERROR",lVar18,
                                   "nvml_devgroup.c",uVar16,iVar7);
                    }
LAB_001274d5:
                    iVar9 = DAT_01216a78;
                    free(local_80);
                    goto LAB_001270cd;
                  }
                  iVar7 = (*pcVar4)(lVar11,puVar5,uVar17,&local_6c);
                  if (iVar7 != 0) goto LAB_00127591;
                  if (local_6c != 0) {
LAB_00126fc4:
                    uVar17 = uVar17 + 1;
                    if (local_68 <= uVar17) break;
                    goto LAB_00126e72;
                  }
                  lVar11 = *(long *)(puVar5 + 0x256d8);
                  if (((lVar11 == 0) || (*(long *)(lVar11 + 0x158) == 0)) ||
                     (pcVar4 = *(code **)(*(long *)(lVar11 + 0x158) + 0x20), pcVar4 == (code *)0x0))
                  {
                    iVar7 = 3;
LAB_001275ed:
                    if (1 < DAT_01216a78) {
                      fVar19 = (float)FUN_002917b0(&DAT_01216a60);
                      lVar18 = syscall(0xba);
                      uVar16 = 0xb2;
                      dVar20 = (double)(fVar19 * DAT_00298548);
                      goto LAB_00127541;
                    }
                    goto LAB_001274d5;
                  }
                  iVar7 = (*pcVar4)(lVar11,puVar5,uVar17,&local_54,local_48);
                  if (iVar7 != 0) goto LAB_001275ed;
                  if (DAT_012164a0 == 0) {
                    iVar7 = 3;
                    if (local_60 == 0) goto LAB_001274c1;
LAB_001274f1:
                    iVar7 = 3;
LAB_001274f7:
                    if (1 < DAT_01216a78) {
                      fVar19 = (float)FUN_002917b0(&DAT_01216a60);
                      lVar18 = syscall(0xba);
                      uVar16 = 0xc0;
                      dVar20 = (double)(fVar19 * DAT_00298548);
                      goto LAB_00127541;
                    }
                    goto LAB_001274d5;
                  }
                  lVar11 = *(long *)(DAT_012164a0 + 0x20);
                  if (lVar11 == 0) {
                    if (local_60 == 0) {
                      iVar7 = 3;
                      goto LAB_001274c1;
                    }
                    goto LAB_001274f1;
                  }
                  if (*(code **)(lVar11 + 0x10) == (code *)0x0) {
                    if (local_60 != 0) goto LAB_00126f79;
                    iVar7 = 3;
LAB_001274c1:
                    if (1 < DAT_01216a78) {
                      fVar19 = (float)FUN_002917b0(&DAT_01216a60);
                      lVar18 = syscall(0xba);
                      uVar16 = 0xb9;
                      dVar20 = (double)(fVar19 * DAT_00298548);
                      goto LAB_00127541;
                    }
                    goto LAB_001274d5;
                  }
                  iVar7 = (**(code **)(lVar11 + 0x10))
                                    (DAT_012164a0,local_54,local_50,local_4e,&local_60);
                  if ((iVar7 != 0) && (local_60 == 0)) goto LAB_001274c1;
                  if ((DAT_012164a0 == 0) || (lVar11 = *(long *)(DAT_012164a0 + 0x20), lVar11 == 0))
                  goto LAB_001274f1;
LAB_00126f79:
                  if (*(code **)(lVar11 + 0xb8) == (code *)0x0) goto LAB_001274f1;
                  iVar7 = (**(code **)(lVar11 + 0xb8))(DAT_012164a0,local_60);
                  if (iVar7 != 0) goto LAB_001274f7;
                  uVar10 = 0;
                  plVar13 = local_80;
                  if (uVar15 != 0) {
                    do {
                      if (local_60 == *plVar13) goto LAB_00126fc4;
                      uVar10 = uVar10 + 1;
                      plVar13 = plVar13 + 1;
                    } while (uVar15 != uVar10);
                    plVar13 = local_80 + uVar15;
                  }
                  *plVar13 = local_60;
                  uVar15 = uVar15 + 1;
                  uVar17 = uVar17 + 1;
                } while (uVar17 < local_68);
LAB_0012742f:
                uVar17 = DAT_01214898;
                if (uVar15 != 0) {
                  plVar13 = local_80;
                  do {
                    lVar11 = 1;
                    if (uVar2 == 0) {
LAB_00127495:
                      uVar17 = *param_1;
                      *(long *)(param_1 + (ulong)uVar17 * 2 + 2) = *plVar13;
                      *param_1 = uVar17 + 1;
                    }
                    else {
                      do {
                        lVar14 = lVar11;
                        if (*(long *)(param_1 + lVar14 * 2) == *plVar13) goto LAB_00127471;
                        lVar11 = lVar14 + 1;
                      } while (lVar14 + 1 != (ulong)(uVar2 - 1) + 2);
                      if (uVar2 == (uint)lVar14) goto LAB_00127495;
                    }
LAB_00127471:
                    plVar13 = plVar13 + 1;
                  } while (local_80 + (ulong)(uVar15 - 1) + 1 != plVar13);
                  free(local_80);
                  uVar17 = DAT_01214898;
                }
                goto LAB_00126d1d;
              }
              iVar7 = 999;
              iVar9 = DAT_01216a78;
            }
LAB_001270cd:
            if (iVar9 < 2) {
              return iVar7;
            }
            uVar8 = *(undefined4 *)(puVar5 + 4);
            fVar19 = (float)FUN_002917b0(&DAT_01216a60);
            lVar18 = syscall(0xba);
            FUN_002340f0((double)(fVar19 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u %u\n","ERROR",lVar18,
                         "nvml_devgroup.c",0xf3,uVar8,iVar7);
          }
          if (DAT_01216a78 < 2) {
            return iVar7;
          }
          fVar19 = (float)FUN_002917b0(&DAT_01216a60);
          lVar18 = syscall(0xba);
          uVar16 = 0x15d;
          dVar20 = (double)(fVar19 * DAT_00298548);
LAB_00127353:
          FUN_002340f0(dVar20,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","ERROR",lVar18,
                       "nvml_devgroup.c",uVar16,iVar7);
          return iVar7;
        }
      }
      else {
        if (*(int *)(pcVar3 + 0x724) == 0xf) {
          iVar7 = 0xf;
          goto LAB_00126ffe;
        }
        if (1 < DAT_01216a78) {
          fVar19 = (float)FUN_002917b0(&DAT_01216a60);
          lVar11 = syscall(0xba);
          FUN_002340f0((double)(fVar19 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       "ERROR",lVar11,
                       "/dvs/p4/build/sw/rel/gpu_drv/r595/r596_25/apps/nvml/dmal/dmal.h",0x27);
        }
        uVar17 = DAT_01214898;
        if (local_70 == 0) goto LAB_00126d70;
      }
LAB_00126d1d:
    } while ((*param_1 != uVar17) && (lVar18 = lVar18 + 1, (uint)lVar18 < *param_1));
  }
  return 0;
}


// ===== 00127700 FUN_00127700 =====

int FUN_00127700(uint *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  int local_2c;
  
  local_2c = 0;
  if (param_2 == 1) {
    iVar2 = FUN_00126920();
    if (iVar2 == 3) {
      memset(param_1 + 0x42,0,(ulong)param_1[1] * 0x880);
      param_1[1] = 0;
      iVar2 = FUN_00126b50(param_1);
    }
  }
  else {
    iVar2 = 2;
    if (param_2 == 2) {
      lVar3 = 0;
      if (*param_1 != 0) {
        do {
          iVar2 = FUN_00126680(*(undefined8 *)(param_1 + lVar3 * 2 + 2),&local_2c);
          if (iVar2 != 0) {
            if (DAT_01216a78 < 2) {
              return iVar2;
            }
            fVar4 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n",
                         "ERROR",lVar3,"nvml_devgroup.c",0x18d,iVar2);
            return iVar2;
          }
          if ((local_2c == 0) || (cVar1 = FUN_001280e0(), cVar1 != '\0')) {
            if (1 < DAT_01216a78) {
              fVar4 = (float)FUN_002917b0(&DAT_01216a60);
              lVar3 = syscall(0xba);
              FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                           "ERROR",lVar3,"nvml_devgroup.c",0x193);
            }
            return 3;
          }
          lVar3 = lVar3 + 1;
        } while ((uint)lVar3 < *param_1);
      }
      iVar2 = 0;
    }
  }
  return iVar2;
}


// ===== 001278d0 FUN_001278d0 =====

int FUN_001278d0(undefined8 *param_1,void *param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint *__ptr;
  
  __ptr = calloc(1,0x990);
  if (__ptr == (uint *)0x0) {
    iVar1 = 999;
  }
  else {
    if (param_3 != 0) {
      memcpy(__ptr + 2,param_2,(ulong)param_3 << 3);
    }
    *__ptr = param_3;
    iVar1 = FUN_00127700(__ptr,param_4);
    if (iVar1 == 0) {
      qsort(__ptr + 2,(ulong)*__ptr,8,FUN_00126600);
      __ptr[0x263] = param_4;
      __ptr[0x262] = 1;
      *param_1 = __ptr;
    }
    else {
      free(__ptr);
    }
  }
  return iVar1;
}


// ===== 001279a0 FUN_001279a0 =====

int FUN_001279a0(undefined8 *param_1,long param_2,uint param_3,uint param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint *__ptr;
  ulong uVar7;
  long lVar8;
  undefined8 *puVar9;
  uint uVar10;
  undefined4 *puVar11;
  ulong uVar12;
  float fVar13;
  uint local_b4;
  uint local_90;
  uint local_8c;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  uint local_48;
  
  iVar5 = DAT_01215b90;
  iVar6 = DAT_01214898;
  uVar10 = DAT_01214898 + DAT_01215b90;
  if (4 < DAT_01216a78) {
    fVar13 = (float)FUN_002917b0(&DAT_01216a60);
    lVar8 = syscall(0xba);
    FUN_002340f0((double)(fVar13 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %d %d\n",
                 "DEBUG",lVar8,"nvml_devgroup.c",0x1d3,uVar10,iVar6,iVar5);
  }
  if (uVar10 < param_3) {
    return 2;
  }
  __ptr = calloc(1,0x990);
  if (__ptr == (uint *)0x0) {
    return 999;
  }
  if (param_3 == 0) {
    __ptr[1] = 0;
    iVar6 = FUN_00127700(__ptr,param_4);
    if (iVar6 == 0) goto LAB_00127c83;
  }
  else {
    local_b4 = 0;
    puVar11 = (undefined4 *)(param_2 + 0x10);
    puVar1 = (undefined4 *)(param_2 + 0x54 + (ulong)(param_3 - 1) * 0x44);
    uVar12 = 0;
LAB_00127b18:
    do {
      uVar10 = (uint)uVar12;
      if (DAT_012164a0 == 0) {
LAB_00127b28:
        iVar6 = 3;
LAB_00127b2e:
        if (1 < DAT_01216a78) {
          fVar13 = (float)FUN_002917b0(&DAT_01216a60);
          lVar8 = syscall(0xba);
          FUN_002340f0((double)(fVar13 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n",
                       "ERROR",lVar8,"nvml_devgroup.c",0x208,iVar6);
        }
        goto LAB_00127b3e;
      }
      puVar9 = *(undefined8 **)(DAT_012164a0 + 0x20);
      uVar2 = *puVar11;
      uVar3 = puVar11[1];
      uVar4 = puVar11[2];
      if (puVar9 == (undefined8 *)0x0) goto LAB_00127b28;
      if ((code *)*puVar9 != (code *)0x0) {
        iVar6 = (*(code *)*puVar9)(DAT_012164a0,uVar2,uVar3 & 0xffff,uVar4 & 0xffff,&local_90);
        if (iVar6 == 0) {
          uVar7 = (ulong)local_b4;
          puVar11 = puVar11 + 0x11;
          local_b4 = local_b4 + 1;
          *(undefined1 **)(__ptr + uVar7 * 2 + 2) = &DAT_00380898 + (ulong)local_90 * 0x74a00;
          if (puVar11 == puVar1) break;
          goto LAB_00127b18;
        }
        if ((DAT_012164a0 == 0) ||
           (puVar9 = *(undefined8 **)(DAT_012164a0 + 0x20), puVar9 == (undefined8 *)0x0))
        goto LAB_00127b28;
      }
      if ((code *)puVar9[1] == (code *)0x0) goto LAB_00127b28;
      iVar6 = (*(code *)puVar9[1])(DAT_012164a0,uVar2,uVar3 & 0xffff,uVar4 & 0xffff,&local_8c);
      if (iVar6 != 0) goto LAB_00127b2e;
      uVar7 = (ulong)local_8c;
      puVar11 = puVar11 + 0x11;
      uVar10 = uVar10 + 1;
      lVar8 = uVar7 * 0x48;
      local_88 = *(undefined8 *)(&DAT_01215b98 + lVar8);
      uStack_80 = *(undefined8 *)(lVar8 + 0x1215ba0);
      local_78 = *(undefined8 *)(&DAT_01215ba8 + uVar7 * 0x12);
      uStack_70 = *(undefined8 *)(&DAT_01215bb0 + uVar7 * 0x12);
      local_68 = *(undefined8 *)(&DAT_01215bb8 + lVar8);
      uStack_60 = *(undefined8 *)(lVar8 + 0x1215bc0);
      local_58 = *(undefined8 *)(&DAT_01215bc8 + lVar8);
      uStack_50 = *(undefined8 *)(lVar8 + 0x1215bd0);
      local_48 = *(uint *)(&DAT_01215bd8 + lVar8);
      __ptr[uVar12 * 0x11 + 0x52] = local_48;
      *(undefined8 *)(__ptr + uVar12 * 0x11 + 0x42) = local_88;
      *(undefined8 *)(__ptr + uVar12 * 0x11 + 0x44) = uStack_80;
      *(undefined8 *)(__ptr + uVar12 * 0x11 + 0x46) = local_78;
      *(undefined8 *)(__ptr + uVar12 * 0x11 + 0x48) = uStack_70;
      *(undefined8 *)(__ptr + uVar12 * 0x11 + 0x4a) = local_68;
      *(undefined8 *)(__ptr + uVar12 * 0x11 + 0x4c) = uStack_60;
      *(undefined8 *)(__ptr + uVar12 * 0x11 + 0x4e) = local_58;
      *(undefined8 *)(__ptr + uVar12 * 0x11 + 0x50) = uStack_50;
      uVar12 = (ulong)uVar10;
    } while (puVar11 != puVar1);
    __ptr[1] = uVar10;
    *__ptr = local_b4;
    iVar6 = FUN_00127700(__ptr,param_4);
    if (iVar6 == 0) {
      if (1 < local_b4) {
        qsort(__ptr + 2,(ulong)*__ptr,8,FUN_00126600);
      }
      if (1 < uVar10) {
        qsort(__ptr + 0x42,(ulong)__ptr[1],0x44,FUN_00126640);
      }
LAB_00127c83:
      __ptr[0x262] = 1;
      __ptr[0x263] = param_4;
      *param_1 = __ptr;
      if (DAT_01216a78 < 4) {
        return 0;
      }
      uVar10 = __ptr[1];
      uVar3 = *__ptr;
      fVar13 = (float)FUN_002917b0(&DAT_01216a60);
      lVar8 = syscall(0xba);
      FUN_002340f0((double)(fVar13 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %d\n",
                   &DAT_002983c2,lVar8,"nvml_devgroup.c",0x22f,uVar3,uVar10);
      return 0;
    }
  }
LAB_00127b3e:
  free(__ptr);
  return iVar6;
}


// ===== 00127e80 FUN_00127e80 =====

undefined8 FUN_00127e80(uint *param_1,long param_2,uint *param_3)

{
  long lVar1;
  long lVar2;
  uint uVar3;
  long lVar4;
  
  uVar3 = 0;
  if (*param_1 != 0) {
    lVar4 = 0;
    do {
      lVar2 = *(long *)(param_1 + lVar4 * 2 + 2);
      if (lVar2 == 0) {
        return 2;
      }
      lVar1 = lVar4 * 8;
      lVar4 = lVar4 + 1;
      snprintf(*(char **)(param_2 + lVar1),0x20,"%08X:%02X:%02X.0",(ulong)*(uint *)(lVar2 + 8),
               (ulong)*(ushort *)(lVar2 + 0xc),(ulong)*(ushort *)(lVar2 + 0xe));
      uVar3 = *param_1;
    } while ((uint)lVar4 < uVar3);
  }
  *param_3 = uVar3;
  return 0;
}


// ===== 00127f20 FUN_00127f20 =====

undefined8 FUN_00127f20(void *param_1)

{
  if (param_1 != (void *)0x0) {
    free(param_1);
    return 0;
  }
  return 0;
}


// ===== 00127f40 FUN_00127f40 =====

undefined4 FUN_00127f40(void)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  
  do {
    iVar2 = FUN_00291820(&DAT_012164b0,1,0);
  } while (iVar2 != 0);
  if (DAT_012164a8 == 0) {
    FUN_0024a6f0();
    if (3 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                   &DAT_002983c2,lVar3,"nvml_fabricmanager.c",0x36);
    }
    iVar2 = FUN_0024a760(&DAT_012164a8,1000,3000);
    if (3 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t0x%x\n",
                   &DAT_002983c2,lVar3,"nvml_fabricmanager.c",0x38,iVar2);
    }
    FUN_00291830(&DAT_012164b0,0);
    if (5 < iVar2 + 5U) {
      return 999;
    }
    uVar1 = *(undefined4 *)(&DAT_00298a10 + (ulong)(iVar2 + 5U) * 4);
  }
  else {
    FUN_00291830(&DAT_012164b0,0);
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 001280e0 FUN_001280e0 =====

ulong FUN_001280e0(void)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 unaff_R12;
  ulong uVar4;
  float fVar5;
  int local_1c;
  
  if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0xb8) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0xb8) + 0x38), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(DAT_012164a0,&local_1c);
    if (iVar2 == 0) {
      uVar4 = CONCAT71((int7)((ulong)unaff_R12 >> 8),local_1c != 1);
      goto LAB_00128127;
    }
  }
  uVar4 = 0;
  if (1 < DAT_01216a78) {
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%u\n","ERROR",
                 lVar3,"nvml_fabricmanager.c",0x49,iVar2);
    return 0;
  }
LAB_00128127:
  return uVar4 & 0xffffffff;
}


// ===== 001281c0 FUN_001281c0 =====

bool FUN_001281c0(void)

{
  char cVar1;
  
  cVar1 = FUN_001280e0();
  if (cVar1 == '\0') {
    return false;
  }
  FUN_00127f40();
  return DAT_012164a8 != 0;
}


// ===== 001281f0 FUN_001281f0 =====

ulong FUN_001281f0(undefined8 param_1)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  float fVar4;
  
  uVar2 = FUN_00127f40();
  if ((int)uVar2 == 0) {
    if (3 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n",
                   &DAT_002983c2,lVar3,"nvml_fabricmanager.c",0x65,param_1);
    }
    iVar1 = FUN_0024a930(DAT_012164a8,param_1);
    if (3 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t0x%x\n",
                   &DAT_002983c2,lVar3,"nvml_fabricmanager.c",0x67,iVar1);
    }
    uVar2 = 999;
    if (iVar1 + 5U < 6) {
      return (ulong)*(uint *)(&DAT_00298a10 + (ulong)(iVar1 + 5) * 4);
    }
  }
  return uVar2;
}


// ===== 00128350 FUN_00128350 =====

ulong FUN_00128350(undefined8 param_1)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  float fVar4;
  
  uVar2 = FUN_00127f40();
  if ((int)uVar2 == 0) {
    if (3 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n",
                   &DAT_002983c2,lVar3,"nvml_fabricmanager.c",0x76,param_1);
    }
    iVar1 = FUN_0024aa70(DAT_012164a8,param_1);
    if (3 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t0x%x\n",
                   &DAT_002983c2,lVar3,"nvml_fabricmanager.c",0x78,iVar1);
    }
    uVar2 = 999;
    if (iVar1 + 5U < 6) {
      return (ulong)*(uint *)(&DAT_00298a10 + (ulong)(iVar1 + 5) * 4);
    }
  }
  return uVar2;
}


// ===== 001284b0 FUN_001284b0 =====

ulong FUN_001284b0(undefined8 param_1)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  float fVar4;
  
  uVar2 = FUN_00127f40();
  if ((int)uVar2 == 0) {
    if (3 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n",
                   &DAT_002983c2,lVar3,"nvml_fabricmanager.c",0x87,param_1);
    }
    iVar1 = FUN_0024aba0(DAT_012164a8,param_1);
    if (3 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t0x%x\n",
                   &DAT_002983c2,lVar3,"nvml_fabricmanager.c",0x89,iVar1);
    }
    uVar2 = 999;
    if (iVar1 + 5U < 6) {
      return (ulong)*(uint *)(&DAT_00298a10 + (ulong)(iVar1 + 5) * 4);
    }
  }
  return uVar2;
}


// ===== 00128610 FUN_00128610 =====

ulong FUN_00128610(undefined8 param_1)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  float fVar4;
  
  uVar2 = FUN_00127f40();
  if ((int)uVar2 == 0) {
    if (3 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n",
                   &DAT_002983c2,lVar3,"nvml_fabricmanager.c",0x98,param_1);
    }
    iVar1 = FUN_0024acd0(DAT_012164a8,param_1);
    if (3 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t0x%x\n",
                   &DAT_002983c2,lVar3,"nvml_fabricmanager.c",0x9a,iVar1);
    }
    uVar2 = 999;
    if (iVar1 + 5U < 6) {
      return (ulong)*(uint *)(&DAT_00298a10 + (ulong)(iVar1 + 5) * 4);
    }
  }
  return uVar2;
}


// ===== 00128770 FUN_00128770 =====

uint FUN_00128770(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 - 0xaaU < 0x26) {
    uVar1 = (uint)(0x39ce739ce7 >> ((byte)(param_1 - 0xaaU) & 0x3f)) & 1;
  }
  return uVar1;
}


// ===== 00128790 FUN_00128790 =====

void FUN_00128790(char *param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  
  lVar1 = *(long *)(param_1 + 0x70508);
  if ((lVar1 != 0) && (*(int *)(lVar1 + 8) == 1)) {
    if ((*param_1 == '\x01') || (*(long *)(param_1 + 0x20) != 0)) {
      if (DAT_012164a0 == 0) {
        return;
      }
      if (*(long *)(DAT_012164a0 + 0x100) == 0) {
        return;
      }
      pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0x100) + 8);
      if (pcVar2 == (code *)0x0) {
        return;
      }
      iVar3 = (*pcVar2)(DAT_012164a0,param_1);
    }
    else {
      iVar3 = FUN_00137d80(param_1,lVar1 + 0x10);
    }
    if (iVar3 == 0) {
      *(undefined4 *)(lVar1 + 8) = 0;
    }
  }
  return;
}


// ===== 00128810 FUN_00128810 =====

int FUN_00128810(long param_1)

{
  code *pcVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  int iVar6;
  long lVar7;
  void *pvVar8;
  undefined8 uVar9;
  long lVar10;
  undefined8 *puVar11;
  long lVar12;
  ulong uVar13;
  int iVar14;
  undefined8 uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  undefined1 *puVar19;
  long lVar20;
  float fVar21;
  void *local_e8;
  uint local_cc;
  int local_c8;
  int local_c4;
  undefined1 local_c0 [8];
  undefined1 local_b8 [8];
  int iStack_b0;
  undefined8 local_a8;
  undefined1 local_98 [8];
  undefined8 uStack_90;
  undefined1 local_88 [16];
  undefined1 local_78 [8];
  uint uStack_70;
  uint uStack_6c;
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  
  if (param_1 == 0) {
    return 2;
  }
  local_e8 = *(void **)(param_1 + 0x70508);
  if (local_e8 == (void *)0x0) {
    local_e8 = calloc(1,0xb8);
    *(void **)(param_1 + 0x70508) = local_e8;
    if (local_e8 == (void *)0x0) {
      if (DAT_01216a78 < 2) {
        return 0x14;
      }
      fVar21 = (float)FUN_002917b0(&DAT_01216a60);
      lVar7 = syscall(0xba);
      FUN_002340f0((double)(fVar21 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",
                   lVar7,"nvml_gpm.c",0xe3);
      return 0x14;
    }
  }
  if (*(char *)((long)local_e8 + 0x40) == '\0') {
    auVar5[0xf] = 0;
    auVar5._0_15_ = stack0xffffffffffffff89;
    _local_78 = auVar5 << 8;
    lVar7 = *(long *)(param_1 + 0x256d8);
    if (((lVar7 != 0) && (*(long *)(lVar7 + 0x30) != 0)) &&
       (pcVar1 = *(code **)(*(long *)(lVar7 + 0x30) + 0x148), pcVar1 != (code *)0x0)) {
      (*pcVar1)(lVar7,param_1,local_78);
      if (local_78[0] != '\0') {
        pvVar8 = (void *)0x0;
        iVar14 = 0;
        *(undefined1 (*) [16])((long)local_e8 + 0x44) = (undefined1  [16])0x0;
        *(undefined1 (*) [16])((long)local_e8 + 0x54) = (undefined1  [16])0x0;
        lVar7 = FUN_00234e60(0,8,0);
LAB_0012892c:
        do {
          _local_78 = (undefined1  [16])0x0;
          local_68 = (undefined1  [16])0x0;
          local_58 = (undefined1  [16])0x0;
          iVar6 = FUN_0016a500(param_1,iVar14,local_78);
          if (iVar6 == 4) {
            if (1 < DAT_01216a78) {
              fVar21 = (float)FUN_002917b0(&DAT_01216a60);
              lVar10 = syscall(0xba);
              fVar21 = fVar21 * DAT_00298548;
              uVar9 = 0x68;
LAB_00128ee4:
              FUN_002340f0((double)fVar21,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",lVar10,
                           "nvml_gpm.c",uVar9);
            }
            break;
          }
          if (iVar6 == 0) {
            auVar2._12_4_ = 0;
            auVar2._0_12_ = stack0xffffffffffffff6c;
            _local_98 = auVar2 << 0x20;
            uVar13 = (ulong)uStack_6c;
            pvVar8 = realloc(pvVar8,uVar13 * 8);
            memset(pvVar8,0,uVar13 * 8);
            iVar6 = FUN_0016b8c0(param_1,local_78._0_4_,pvVar8,local_98);
            if (iVar6 == 4) {
              if (1 < DAT_01216a78) {
                fVar21 = (float)FUN_002917b0(&DAT_01216a60);
                lVar10 = syscall(0xba);
                fVar21 = fVar21 * DAT_00298548;
                uVar9 = 0x78;
                goto LAB_00128ee4;
              }
              break;
            }
            if (iVar6 == 0) {
              uVar13 = 0;
              if (local_98._0_4_ != 0) {
                do {
                  uVar16 = (int)uVar13 + 1;
                  FUN_00234f00(lVar7,(void *)((long)pvVar8 + uVar13 * 8));
                  uVar13 = (ulong)uVar16;
                } while (uVar16 < (uint)local_98._0_4_);
              }
            }
            else if (1 < DAT_01216a78) {
              uVar9 = nvmlErrorString(iVar6);
              fVar21 = (float)FUN_002917b0(&DAT_01216a60);
              lVar10 = syscall(0xba);
              fVar21 = fVar21 * DAT_00298548;
              uVar15 = 0x7d;
              goto LAB_00128a16;
            }
LAB_00128920:
            iVar14 = iVar14 + 1;
            if (iVar14 == 0x12) break;
            goto LAB_0012892c;
          }
          if (DAT_01216a78 < 2) goto LAB_00128920;
          uVar9 = nvmlErrorString(iVar6);
          fVar21 = (float)FUN_002917b0(&DAT_01216a60);
          lVar10 = syscall(0xba);
          uVar15 = 0x6d;
          fVar21 = fVar21 * DAT_00298548;
LAB_00128a16:
          iVar14 = iVar14 + 1;
          FUN_002340f0((double)fVar21,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n","ERROR",lVar10,
                       "nvml_gpm.c",uVar15,uVar9);
        } while (iVar14 != 0x12);
        if (pvVar8 != (void *)0x0) {
          free(pvVar8);
        }
        if (lVar7 == 0) {
          if (1 < DAT_01216a78) {
            lVar10 = 0;
            iVar14 = 0;
            fVar21 = (float)FUN_002917b0(&DAT_01216a60);
            lVar20 = syscall(0xba);
            FUN_002340f0((double)(fVar21 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                         "ERROR",lVar20,"nvml_gpm.c",0x103);
            goto LAB_00128e68;
          }
        }
        else {
          pvVar8 = (void *)0x0;
          lVar10 = FUN_00234e60(0,8,0);
          puVar11 = (undefined8 *)FUN_00234f80(lVar7,local_98);
          if (puVar11 != (undefined8 *)0x0) {
            do {
              uVar9 = *puVar11;
              iVar14 = 0;
              do {
                while( true ) {
                  auVar3._12_4_ = 0;
                  auVar3._0_12_ = local_58._4_12_;
                  local_58 = auVar3 << 0x20;
                  _local_78 = (undefined1  [16])0x0;
                  local_68 = (undefined1  [16])0x0;
                  iVar6 = FUN_0016bf10(uVar9,iVar14,0,local_78);
                  if (iVar6 == 4) {
                    if (1 < DAT_01216a78) {
                      fVar21 = (float)FUN_002917b0(&DAT_01216a60);
                      lVar20 = syscall(0xba);
                      FUN_002340f0((double)(fVar21 * DAT_00298548),
                                   "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",lVar20,
                                   "nvml_gpm.c",0xa3);
                    }
                    goto LAB_00128dff;
                  }
                  if (iVar6 == 0) break;
                  if (1 < DAT_01216a78) {
                    uVar15 = nvmlErrorString(iVar6);
                    fVar21 = (float)FUN_002917b0(&DAT_01216a60);
                    lVar20 = syscall(0xba);
                    FUN_002340f0((double)(fVar21 * DAT_00298548),
                                 "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n","ERROR",lVar20,
                                 "nvml_gpm.c",0xa8,uVar15);
                  }
LAB_00128b26:
                  iVar14 = iVar14 + 1;
                  if (iVar14 == 8) goto LAB_00128bf8;
                }
                auVar4._12_4_ = 0;
                auVar4._0_12_ = stack0xffffffffffffff4c;
                _local_b8 = auVar4 << 0x20;
                uVar13 = (ulong)uStack_70;
                pvVar8 = realloc(pvVar8,uVar13 << 3);
                memset(pvVar8,0,uVar13 << 3);
                FUN_0016cdd0(uVar9,local_78._0_4_,pvVar8,local_b8);
                if (local_b8._0_4_ == 0) goto LAB_00128b26;
                uVar13 = 0;
                do {
                  uVar16 = (int)uVar13 + 1;
                  FUN_00234f00(lVar10,(void *)((long)pvVar8 + uVar13 * 8));
                  uVar13 = (ulong)uVar16;
                } while (uVar16 < (uint)local_b8._0_4_);
                iVar14 = iVar14 + 1;
              } while (iVar14 != 8);
LAB_00128bf8:
              puVar11 = (undefined8 *)FUN_00234fb0(lVar7,local_98);
            } while (puVar11 != (undefined8 *)0x0);
LAB_00128dff:
            if (pvVar8 != (void *)0x0) {
              free(pvVar8);
            }
          }
          if (lVar10 != 0) {
            local_cc = 0;
            _local_78 = (undefined1  [16])0x0;
            local_68 = (undefined1  [16])0x0;
            local_58 = (undefined1  [16])0x0;
            local_48 = (undefined1  [16])0x0;
            iVar14 = FUN_0016dc70(param_1,&local_cc);
            uVar16 = local_cc;
            if (iVar14 == 0) {
              if (local_cc < 9) {
                *(uint *)((long)local_e8 + 0xa4) = local_cc;
                if (local_cc != 0) {
                  puVar19 = local_78;
                  uVar17 = 0;
                  do {
                    uVar18 = uVar17 + 1;
                    FUN_0016de90(param_1,uVar17,puVar19);
                    puVar19 = puVar19 + 8;
                    uVar17 = uVar18;
                  } while (uVar16 != uVar18);
                }
                puVar11 = (undefined8 *)FUN_00234f80(lVar10,local_c0);
                while (puVar11 != (undefined8 *)0x0) {
                  _local_98 = (undefined1  [16])0x0;
                  local_88 = (undefined1  [16])0x0;
                  FUN_0016d3f0(*puVar11,local_98);
                  local_a8 = 0;
                  _local_b8 = (undefined1  [16])0x0;
                  iVar14 = FUN_0016bd10(uStack_90,local_b8);
                  *(undefined4 *)
                   ((long)local_e8 + (ulong)(uint)(local_88._8_4_ + (int)local_a8) * 4 + 0x44) =
                       local_88._12_4_;
                  if (local_cc != 0) {
                    lVar20 = 0;
LAB_00129079:
                    do {
                      lVar12 = *(long *)(local_78 + lVar20 * 8);
                      if (lVar12 != 0) {
                        iVar14 = FUN_0016d830(lVar12,&local_c8);
                        if (iVar14 == 0) {
                          iVar14 = FUN_0016da50(lVar12,&local_c4);
                          if (iVar14 == 0) {
                            if ((iStack_b0 == local_c8) && (local_88._0_4_ == local_c4)) {
                              *(undefined4 *)((long)local_e8 + lVar20 * 4 + 100) = local_88._12_4_;
                              *(undefined4 *)((long)local_e8 + lVar20 * 4 + 0x84) = local_a8._4_4_;
                            }
                          }
                          else if (1 < DAT_01216a78) {
                            uVar9 = nvmlErrorString(iVar14);
                            fVar21 = (float)FUN_002917b0(&DAT_01216a60);
                            lVar12 = syscall(0xba);
                            uVar15 = 0x145;
                            fVar21 = fVar21 * DAT_00298548;
                            goto LAB_0012919b;
                          }
                        }
                        else if (1 < DAT_01216a78) {
                          uVar9 = nvmlErrorString(iVar14);
                          fVar21 = (float)FUN_002917b0(&DAT_01216a60);
                          lVar12 = syscall(0xba);
                          uVar15 = 0x13e;
                          fVar21 = fVar21 * DAT_00298548;
LAB_0012919b:
                          lVar20 = lVar20 + 1;
                          FUN_002340f0((double)fVar21,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n",
                                       "ERROR",lVar12,"nvml_gpm.c",uVar15,uVar9);
                          if (local_cc <= (uint)lVar20) break;
                          goto LAB_00129079;
                        }
                      }
                      lVar20 = lVar20 + 1;
                    } while ((uint)lVar20 < local_cc);
                  }
                  puVar11 = (undefined8 *)FUN_00234fb0(lVar10,local_c0);
                }
              }
              else {
                iVar14 = 7;
              }
            }
            goto LAB_00128e68;
          }
          if (1 < DAT_01216a78) {
            iVar14 = 0;
            fVar21 = (float)FUN_002917b0(&DAT_01216a60);
            lVar20 = syscall(0xba);
            FUN_002340f0((double)(fVar21 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                         "ERROR",lVar20,"nvml_gpm.c",0x10b);
            goto LAB_00128e68;
          }
        }
        iVar14 = 0;
        lVar10 = 0;
LAB_00128e68:
        FUN_00234fe0(lVar7);
        FUN_00234fe0(lVar10);
        *(undefined1 *)((long)local_e8 + 0x40) = 1;
        return iVar14;
      }
    }
    *(undefined8 *)((long)local_e8 + 0x44) = 0x100000001;
    *(undefined8 *)((long)local_e8 + 0x4c) = 0x100000001;
    *(undefined8 *)((long)local_e8 + 0x54) = 0x100000001;
    *(undefined8 *)((long)local_e8 + 0x5c) = 0x100000001;
  }
  return 0;
}


// ===== 00129330 FUN_00129330 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double FUN_00129330(double param_1,char *param_2)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  long local_20;
  
  if (param_2 == (char *)0x0) {
    return 0.0;
  }
  pcVar4 = param_2;
  if (*param_2 != '\x01') {
    if (((*(int *)(param_2 + 0x14) == 0) || (*(int *)(param_2 + 0x1c) != 0)) ||
       (*(int *)(param_2 + 0x10) == 0)) {
      if (*(long *)(param_2 + 0x20) != 0) {
        return 0.0;
      }
    }
    else if (*(long *)(param_2 + 0x20) != 0) goto LAB_00129390;
    local_20 = 0;
    iVar3 = FUN_001384c0(param_2,&local_20);
    if (iVar3 != 0) {
      return 0.0;
    }
    pcVar4 = *(char **)(local_20 + 0x98);
  }
LAB_00129390:
  lVar2 = *(long *)(param_2 + 0x70508);
  if (lVar2 == 0) {
    return 0.0;
  }
  uVar1 = *(uint *)(lVar2 + 0x30);
  if (*(uint *)(lVar2 + 0x30) == 0) {
    iVar3 = FUN_00175fd0(pcVar4,2,&local_20);
    if (iVar3 != 0) {
      return 0.0;
    }
    *(uint *)(lVar2 + 0x30) = (uint)local_20;
    uVar1 = (uint)local_20;
  }
  param_1 = (double)uVar1 * _DAT_00298b38 * param_1;
  if (*param_2 != '\x01') {
    if (*(long *)(param_2 + 0x20) == 0) {
      return param_1 * *(double *)(lVar2 + 0x38);
    }
    return param_1;
  }
  return param_1;
}


// ===== 00129450 FUN_00129450 =====

undefined8 FUN_00129450(undefined8 *param_1)

{
  char cVar1;
  long *plVar2;
  long lVar3;
  undefined8 *puVar4;
  ulong uVar5;
  long *plVar6;
  uint uVar7;
  double dVar8;
  undefined1 local_80e8 [160];
  undefined8 *local_8048;
  undefined8 local_8038 [2];
  undefined8 local_8028;
  undefined8 local_8018;
  undefined8 local_7ff8;
  undefined8 local_7fd8;
  undefined *local_7fc8;
  undefined8 local_7fb8;
  undefined8 local_7fa8;
  undefined *local_7f98;
  undefined *local_7f88;
  undefined *local_7f78;
  undefined8 local_6638;
  undefined8 local_3338;
  
  memset(local_80e8,0,0x80c0);
  local_8048 = local_8038;
  local_3338 = 120000000;
  local_6638 = 96000000;
  local_8038[0] = 150000000;
  local_8028 = 105000000;
  local_8018 = 75000000;
  local_7fd8 = 150000000;
  local_7ff8 = 37500000;
  local_7f98 = &DAT_007270e0;
  local_7fa8 = 0x1c9c38;
  local_7fb8 = 0xe4e1c;
  local_7fc8 = &DAT_007270e0;
  local_7f78 = &DAT_007270e0;
  local_7f88 = &DAT_00e4e1c0;
  dVar8 = (double)FUN_00129330(DAT_00298b40,*param_1);
  puVar4 = local_8048;
  if (DAT_00298b48 <= dVar8) {
    uVar5 = (long)(dVar8 - DAT_00298b48) ^ 0x8000000000000000;
  }
  else {
    uVar5 = (ulong)dVar8;
  }
  local_8048[0xae] = 1;
  puVar4[0xb0] = 2;
  puVar4[0xf2] = 0x200;
  puVar4[0xe2] = 0x400;
  puVar4[0x52] = uVar5 / 10;
  puVar4[0x112] = 0x400;
  puVar4[0x54] = uVar5 / 0x14;
  puVar4[0x102] = 0x200;
  plVar2 = (long *)((undefined8 *)param_1[1])[1];
  *(undefined8 *)param_1[1] = 0x8890;
  cVar1 = *(char *)(param_1 + 3);
joined_r0x001295cf:
  if (cVar1 == '\0') {
    return 0;
  }
  *plVar2 = *plVar2 + 100000;
  plVar6 = plVar2 + 1;
  uVar7 = 0;
  do {
    lVar3 = *(long *)((long)local_8048 + (-8 - (long)plVar2) + (long)plVar6);
    if (uVar7 < 0x400) {
      *plVar6 = *plVar6 + lVar3;
    }
    else {
      plVar6[0x89] = plVar6[0x89] + lVar3;
      if (uVar7 + 1 == 0x800) break;
    }
    plVar6 = plVar6 + 2;
    uVar7 = uVar7 + 1;
  } while( true );
  plVar2[0x1113] = *plVar2;
  FUN_00292f00(100);
  cVar1 = *(char *)(param_1 + 3);
  goto joined_r0x001295cf;
}


// ===== 00129660 FUN_00129660 =====

undefined8 FUN_00129660(undefined8 *param_1)

{
  long *plVar1;
  char cVar2;
  undefined8 *puVar3;
  long *plVar4;
  ulong uVar5;
  long lVar6;
  double dVar7;
  undefined1 local_80d8 [160];
  undefined8 *local_8038;
  undefined8 local_8028 [2];
  undefined8 local_8018;
  undefined8 local_8008;
  undefined8 local_7fe8;
  undefined8 local_7fb8;
  undefined *local_7fa8;
  undefined8 local_7f98;
  undefined8 local_7f88;
  undefined *local_7f78;
  undefined *local_7f68;
  undefined *local_7f58;
  undefined *local_7f48;
  undefined8 local_7da8;
  undefined8 local_6928;
  
  memset(local_80d8,0,0x80c0);
  local_8038 = local_8028;
  local_7da8 = 120000000;
  local_6928 = 96000000;
  local_8028[0] = 150000000;
  local_8018 = 105000000;
  local_8008 = 75000000;
  local_7fb8 = 150000000;
  local_7fe8 = 37500000;
  local_7f78 = &DAT_007270e0;
  local_7f88 = 0x1c9c38;
  local_7f98 = 0xe4e1c;
  local_7fa8 = &DAT_007270e0;
  local_7f48 = &DAT_00e4e1c0;
  local_7f68 = &DAT_007270e0;
  local_7f58 = &DAT_007270e0;
  dVar7 = (double)FUN_00129330(DAT_00298b50,*param_1);
  puVar3 = local_8038;
  if (DAT_00298b48 <= dVar7) {
    uVar5 = (long)(dVar7 - DAT_00298b48) ^ 0x8000000000000000;
  }
  else {
    uVar5 = (ulong)dVar7;
  }
  local_8038[0x84] = 1;
  puVar3[0x82] = 2;
  puVar3[0xb4] = 0x400;
  puVar3[0xa4] = 0x800;
  puVar3[0x42] = uVar5 / 10;
  puVar3[0xd4] = 0x800;
  puVar3[0x44] = uVar5 / 0x14;
  puVar3[0xc4] = 0x400;
  puVar3 = (undefined8 *)param_1[1];
  *puVar3 = 0x2790;
  plVar4 = (long *)puVar3[1];
  cVar2 = *(char *)(param_1 + 3);
  while (cVar2 != '\0') {
    *plVar4 = *plVar4 + 100000;
    lVar6 = 0;
    do {
      plVar1 = (long *)((long)plVar4 + lVar6 + 8);
      *plVar1 = *plVar1 + *(long *)((long)local_8038 + lVar6);
      lVar6 = lVar6 + 8;
    } while (lVar6 != 0x2790);
    plVar4[0x4f3] = *plVar4;
    FUN_00292f00(100);
    cVar2 = *(char *)(param_1 + 3);
  }
  return 0;
}


// ===== 00129850 FUN_00129850 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00129850(uint *param_1,long param_2,long *param_3,long *param_4)

{
  long *plVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auVar4 [4];
  code *pcVar5;
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  char cVar9;
  int iVar10;
  undefined8 *puVar11;
  long lVar12;
  long lVar13;
  ulong uVar14;
  long *plVar15;
  long lVar16;
  long lVar17;
  long extraout_RDX;
  ulong uVar18;
  char *pcVar19;
  undefined8 uVar20;
  long lVar21;
  char *pcVar22;
  float fVar23;
  double dVar24;
  double dVar25;
  double extraout_XMM1_Qa;
  double dVar26;
  undefined4 local_c8;
  undefined1 auStack_c4 [12];
  undefined1 local_b8 [16];
  undefined8 local_a8;
  undefined4 local_98;
  undefined1 auStack_94 [12];
  undefined1 local_88 [16];
  undefined8 local_78;
  undefined1 local_68 [4];
  undefined1 auStack_64 [12];
  undefined1 local_58 [16];
  undefined8 local_48;
  
  uVar20 = DAT_00298b68;
  uVar2 = *param_1;
  if (0x14c < uVar2) {
    param_1[1] = 2;
    *(undefined8 *)(param_1 + 2) = uVar20;
    return;
  }
  lVar16 = param_3[0x14];
  lVar21 = param_4[0x14];
  if (((uVar2 - 0x14 < 2) || (uVar2 - 0x3c < 0x26)) || (uVar2 - 100 < 0x3c)) {
    *(char **)(param_1 + 8) = "MiB/s";
  }
  else if ((uVar2 - 0xf8 < 0x31) || (cVar9 = FUN_00128770(uVar2), cVar9 != '\0')) {
    *(undefined **)(param_1 + 8) = &DAT_00298a39;
  }
  else if ((uVar2 - 0xad < 0x24) && ((0x842108421U >> ((ulong)(uVar2 - 0xad) & 0x3f) & 1) != 0)) {
    *(undefined **)(param_1 + 8) = &DAT_00298a3b;
  }
  else {
    *(undefined **)(param_1 + 8) = &DAT_00298a3f;
  }
  puVar11 = (undefined8 *)(PTR_PTR_0032efb8 + (ulong)uVar2 * 0x10);
  *(undefined8 *)(param_1 + 4) = *puVar11;
  *(undefined8 *)(param_1 + 6) = puVar11[1];
  if ((lVar16 == 0) || (lVar21 == 0)) {
    param_1[1] = 1;
    return;
  }
  lVar13 = param_3[1];
  lVar17 = param_4[1];
  if (lVar17 < lVar13) {
    if (1 < DAT_01216a78) {
      fVar23 = (float)FUN_002917b0(&DAT_01216a60);
      lVar12 = syscall(0xba);
      FUN_002340f0((double)(fVar23 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%lld %lld\n",
                   "ERROR",lVar12,"nvml_gpm.c",0x703,lVar13,lVar17);
    }
    param_1[1] = 2;
  }
  lVar13 = *param_4;
  if (*param_3 != lVar13) {
    param_1[1] = 2;
    lVar13 = *param_3;
  }
  if ((*(long *)(lVar13 + 0x70508) == 0) ||
     (iVar10 = *(int *)(*(long *)(lVar13 + 0x70508) + 0xb0), iVar10 == 0)) {
    param_1[1] = 3;
    return;
  }
  uVar3 = *(uint *)(param_4 + 0x1017);
  if ((uVar3 != 0) &&
     (((((uVar3 & 0xc) != 0 || (((uVar3 & 3) != 0 && (uVar2 - 2 < 0xc)))) ||
       (((uVar3 & 0x10) != 0 && (uVar2 - 0x1e < 8)))) ||
      (((((uVar3 & 0x20) != 0 && (uVar2 - 0xa6 < 4)) ||
        (((uVar3 & 0x40) != 0 && (uVar2 - 0x28 < 8)))) ||
       (((uVar3 & 0x80) != 0 && (uVar2 - 0x32 < 2)))))))) {
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[1] = 0;
    return;
  }
  lVar13 = param_2 + (ulong)uVar2 * 0x78;
  if (uVar2 == 0x3c) {
    if (iVar10 == 1) {
      uVar18 = (((((((((((((((((((*(long *)(lVar21 + 0x6a0) + *(long *)(lVar21 + 0x5a0) +
                                  *(long *)(lVar21 + 0x7a0) + *(long *)(lVar21 + 0x8a0) +
                                  *(long *)(lVar21 + 0x9a0) + *(long *)(lVar21 + 0xaa0) +
                                  *(long *)(lVar21 + 0xba0) + *(long *)(lVar21 + 0xca0) +
                                  *(long *)(lVar21 + 0xda0) + *(long *)(lVar21 + 0xea0) +
                                  *(long *)(lVar21 + 4000) + *(long *)(lVar21 + 0x10a0) +
                                  *(long *)(lVar21 + 0x11a0) + *(long *)(lVar21 + 0x12a0) +
                                  *(long *)(lVar21 + 0x13a0) + *(long *)(lVar21 + 0x14a0) +
                                  *(long *)(lVar21 + 0x15a0) + *(long *)(lVar21 + 0x16a0)) -
                                *(long *)(lVar16 + 0x5a0)) - *(long *)(lVar16 + 0x6a0)) -
                              *(long *)(lVar16 + 0x7a0)) - *(long *)(lVar16 + 0x8a0)) -
                            *(long *)(lVar16 + 0x9a0)) - *(long *)(lVar16 + 0xaa0)) -
                          *(long *)(lVar16 + 0xba0)) - *(long *)(lVar16 + 0xca0)) -
                        *(long *)(lVar16 + 0xda0)) - *(long *)(lVar16 + 0xea0)) -
                      *(long *)(lVar16 + 4000)) - *(long *)(lVar16 + 0x10a0)) -
                    *(long *)(lVar16 + 0x11a0)) - *(long *)(lVar16 + 0x12a0)) -
                  *(long *)(lVar16 + 0x13a0)) - *(long *)(lVar16 + 0x14a0)) -
                *(long *)(lVar16 + 0x15a0)) - *(long *)(lVar16 + 0x16a0)) * 0x200;
    }
    else {
      if (iVar10 != 2) {
        dVar26 = 0.0;
        if (iVar10 == 4) {
          uVar18 = (((((((((((((((((((((((((((((((((((((*(long *)(lVar21 + 0xd10) +
                                                        *(long *)(lVar21 + 0xc10) +
                                                        *(long *)(lVar21 + 0xe10) +
                                                        *(long *)(lVar21 + 0xf10) +
                                                        *(long *)(lVar21 + 0x1010) +
                                                        *(long *)(lVar21 + 0x1110) +
                                                        *(long *)(lVar21 + 0x1210) +
                                                        *(long *)(lVar21 + 0x1310) +
                                                        *(long *)(lVar21 + 0x1410) +
                                                        *(long *)(lVar21 + 0x1510) +
                                                        *(long *)(lVar21 + 0x1610) +
                                                        *(long *)(lVar21 + 0x1710) +
                                                        *(long *)(lVar21 + 0x1810) +
                                                        *(long *)(lVar21 + 0x1910) +
                                                        *(long *)(lVar21 + 0x1a10) +
                                                        *(long *)(lVar21 + 0x1b10) +
                                                        *(long *)(lVar21 + 0x1c10) +
                                                        *(long *)(lVar21 + 0x1d10) +
                                                        *(long *)(lVar21 + 0x5690) +
                                                        *(long *)(lVar21 + 0x5790) +
                                                        *(long *)(lVar21 + 0x5890) +
                                                        *(long *)(lVar21 + 0x5990) +
                                                        *(long *)(lVar21 + 0x5a90) +
                                                        *(long *)(lVar21 + 0x5b90) +
                                                        *(long *)(lVar21 + 0x5c90) +
                                                        *(long *)(lVar21 + 0x5d90) +
                                                        *(long *)(lVar21 + 0x5e90) +
                                                        *(long *)(lVar21 + 0x5f90) +
                                                        *(long *)(lVar21 + 0x6090) +
                                                        *(long *)(lVar21 + 0x6190) +
                                                        *(long *)(lVar21 + 0x6290) +
                                                        *(long *)(lVar21 + 0x6390) +
                                                        *(long *)(lVar21 + 0x6490) +
                                                        *(long *)(lVar21 + 26000) +
                                                        *(long *)(lVar21 + 0x6690) +
                                                       *(long *)(lVar21 + 0x6790)) -
                                                      *(long *)(lVar16 + 0xc10)) -
                                                     *(long *)(lVar16 + 0xd10)) -
                                                    *(long *)(lVar16 + 0xe10)) -
                                                   *(long *)(lVar16 + 0xf10)) -
                                                  *(long *)(lVar16 + 0x1010)) -
                                                 *(long *)(lVar16 + 0x1110)) -
                                                *(long *)(lVar16 + 0x1210)) -
                                               *(long *)(lVar16 + 0x1310)) -
                                              *(long *)(lVar16 + 0x1410)) -
                                             *(long *)(lVar16 + 0x1510)) -
                                            *(long *)(lVar16 + 0x1610)) - *(long *)(lVar16 + 0x1710)
                                           ) - *(long *)(lVar16 + 0x1810)) -
                                         *(long *)(lVar16 + 0x1910)) - *(long *)(lVar16 + 0x1a10)) -
                                       *(long *)(lVar16 + 0x1b10)) - *(long *)(lVar16 + 0x1c10)) -
                                     *(long *)(lVar16 + 0x1d10)) - *(long *)(lVar16 + 0x5690)) -
                                   *(long *)(lVar16 + 0x5790)) - *(long *)(lVar16 + 0x5890)) -
                                 *(long *)(lVar16 + 0x5990)) - *(long *)(lVar16 + 0x5a90)) -
                               *(long *)(lVar16 + 0x5b90)) - *(long *)(lVar16 + 0x5c90)) -
                             *(long *)(lVar16 + 0x5d90)) - *(long *)(lVar16 + 0x5e90)) -
                           *(long *)(lVar16 + 0x5f90)) - *(long *)(lVar16 + 0x6090)) -
                         *(long *)(lVar16 + 0x6190)) - *(long *)(lVar16 + 0x6290)) -
                       *(long *)(lVar16 + 0x6390)) - *(long *)(lVar16 + 0x6490)) -
                     *(long *)(lVar16 + 26000)) - *(long *)(lVar16 + 0x6690)) -
                   *(long *)(lVar16 + 0x6790)) * 0x400;
          if ((long)uVar18 < 0) goto LAB_0012b27b;
LAB_0012a135:
          dVar26 = (double)(long)uVar18;
        }
        goto LAB_00129c80;
      }
      uVar18 = (((((((((((((((((((*(long *)(lVar21 + 0x890) + *(long *)(lVar21 + 0x790) +
                                  *(long *)(lVar21 + 0x990) + *(long *)(lVar21 + 0xa90) +
                                  *(long *)(lVar21 + 0xb90) + *(long *)(lVar21 + 0xc90) +
                                  *(long *)(lVar21 + 0xd90) + *(long *)(lVar21 + 0xe90) +
                                  *(long *)(lVar21 + 0xf90) + *(long *)(lVar21 + 0x1090) +
                                  *(long *)(lVar21 + 0x1190) + *(long *)(lVar21 + 0x1290) +
                                  *(long *)(lVar21 + 0x1390) + *(long *)(lVar21 + 0x1490) +
                                  *(long *)(lVar21 + 0x1590) + *(long *)(lVar21 + 0x1690) +
                                  *(long *)(lVar21 + 0x1790) + *(long *)(lVar21 + 0x1890)) -
                                *(long *)(lVar16 + 0x790)) - *(long *)(lVar16 + 0x890)) -
                              *(long *)(lVar16 + 0x990)) - *(long *)(lVar16 + 0xa90)) -
                            *(long *)(lVar16 + 0xb90)) - *(long *)(lVar16 + 0xc90)) -
                          *(long *)(lVar16 + 0xd90)) - *(long *)(lVar16 + 0xe90)) -
                        *(long *)(lVar16 + 0xf90)) - *(long *)(lVar16 + 0x1090)) -
                      *(long *)(lVar16 + 0x1190)) - *(long *)(lVar16 + 0x1290)) -
                    *(long *)(lVar16 + 0x1390)) - *(long *)(lVar16 + 0x1490)) -
                  *(long *)(lVar16 + 0x1590)) - *(long *)(lVar16 + 0x1690)) -
                *(long *)(lVar16 + 0x1790)) - *(long *)(lVar16 + 0x1890)) * 0x400;
    }
joined_r0x0012aaef:
    if ((long)uVar18 < 0) {
      dVar26 = (double)(uVar18 >> 1) + (double)(uVar18 >> 1);
    }
    else {
      dVar26 = (double)(long)uVar18;
    }
LAB_00129c80:
    dVar26 = dVar26 * _DAT_00298b70;
  }
  else {
    if (uVar2 == 0x3d) {
      if (iVar10 == 1) {
        uVar18 = (((((((((((((((((((*(long *)(lVar21 + 0x620) + *(long *)(lVar21 + 0x520) +
                                    *(long *)(lVar21 + 0x720) + *(long *)(lVar21 + 0x820) +
                                    *(long *)(lVar21 + 0x920) + *(long *)(lVar21 + 0xa20) +
                                    *(long *)(lVar21 + 0xb20) + *(long *)(lVar21 + 0xc20) +
                                    *(long *)(lVar21 + 0xd20) + *(long *)(lVar21 + 0xe20) +
                                    *(long *)(lVar21 + 0xf20) + *(long *)(lVar21 + 0x1020) +
                                    *(long *)(lVar21 + 0x1120) + *(long *)(lVar21 + 0x1220) +
                                    *(long *)(lVar21 + 0x1320) + *(long *)(lVar21 + 0x1420) +
                                    *(long *)(lVar21 + 0x1520) + *(long *)(lVar21 + 0x1620)) -
                                  *(long *)(lVar16 + 0x520)) - *(long *)(lVar16 + 0x620)) -
                                *(long *)(lVar16 + 0x720)) - *(long *)(lVar16 + 0x820)) -
                              *(long *)(lVar16 + 0x920)) - *(long *)(lVar16 + 0xa20)) -
                            *(long *)(lVar16 + 0xb20)) - *(long *)(lVar16 + 0xc20)) -
                          *(long *)(lVar16 + 0xd20)) - *(long *)(lVar16 + 0xe20)) -
                        *(long *)(lVar16 + 0xf20)) - *(long *)(lVar16 + 0x1020)) -
                      *(long *)(lVar16 + 0x1120)) - *(long *)(lVar16 + 0x1220)) -
                    *(long *)(lVar16 + 0x1320)) - *(long *)(lVar16 + 0x1420)) -
                  *(long *)(lVar16 + 0x1520)) - *(long *)(lVar16 + 0x1620)) * 0x200;
      }
      else {
        if (iVar10 != 2) {
          dVar26 = 0.0;
          if (iVar10 == 4) {
            uVar18 = (((((((((((((((((((((((((((((((((((((*(long *)(lVar21 + 0xc90) +
                                                          *(long *)(lVar21 + 0xb90) +
                                                          *(long *)(lVar21 + 0xd90) +
                                                          *(long *)(lVar21 + 0xe90) +
                                                          *(long *)(lVar21 + 0xf90) +
                                                          *(long *)(lVar21 + 0x1090) +
                                                          *(long *)(lVar21 + 0x1190) +
                                                          *(long *)(lVar21 + 0x1290) +
                                                          *(long *)(lVar21 + 0x1390) +
                                                          *(long *)(lVar21 + 0x1490) +
                                                          *(long *)(lVar21 + 0x1590) +
                                                          *(long *)(lVar21 + 0x1690) +
                                                          *(long *)(lVar21 + 0x1790) +
                                                          *(long *)(lVar21 + 0x1890) +
                                                          *(long *)(lVar21 + 0x1990) +
                                                          *(long *)(lVar21 + 0x1a90) +
                                                          *(long *)(lVar21 + 0x1b90) +
                                                          *(long *)(lVar21 + 0x1c90) +
                                                          *(long *)(lVar21 + 0x5610) +
                                                          *(long *)(lVar21 + 0x5710) +
                                                          *(long *)(lVar21 + 0x5810) +
                                                          *(long *)(lVar21 + 0x5910) +
                                                          *(long *)(lVar21 + 0x5a10) +
                                                          *(long *)(lVar21 + 0x5b10) +
                                                          *(long *)(lVar21 + 0x5c10) +
                                                          *(long *)(lVar21 + 0x5d10) +
                                                          *(long *)(lVar21 + 0x5e10) +
                                                          *(long *)(lVar21 + 0x5f10) +
                                                          *(long *)(lVar21 + 0x6010) +
                                                          *(long *)(lVar21 + 0x6110) +
                                                          *(long *)(lVar21 + 0x6210) +
                                                          *(long *)(lVar21 + 0x6310) +
                                                          *(long *)(lVar21 + 0x6410) +
                                                          *(long *)(lVar21 + 0x6510) +
                                                          *(long *)(lVar21 + 0x6610) +
                                                         *(long *)(lVar21 + 0x6710)) -
                                                        *(long *)(lVar16 + 0xb90)) -
                                                       *(long *)(lVar16 + 0xc90)) -
                                                      *(long *)(lVar16 + 0xd90)) -
                                                     *(long *)(lVar16 + 0xe90)) -
                                                    *(long *)(lVar16 + 0xf90)) -
                                                   *(long *)(lVar16 + 0x1090)) -
                                                  *(long *)(lVar16 + 0x1190)) -
                                                 *(long *)(lVar16 + 0x1290)) -
                                                *(long *)(lVar16 + 0x1390)) -
                                               *(long *)(lVar16 + 0x1490)) -
                                              *(long *)(lVar16 + 0x1590)) -
                                             *(long *)(lVar16 + 0x1690)) -
                                            *(long *)(lVar16 + 0x1790)) - *(long *)(lVar16 + 0x1890)
                                           ) - *(long *)(lVar16 + 0x1990)) -
                                         *(long *)(lVar16 + 0x1a90)) - *(long *)(lVar16 + 0x1b90)) -
                                       *(long *)(lVar16 + 0x1c90)) - *(long *)(lVar16 + 0x5610)) -
                                     *(long *)(lVar16 + 0x5710)) - *(long *)(lVar16 + 0x5810)) -
                                   *(long *)(lVar16 + 0x5910)) - *(long *)(lVar16 + 0x5a10)) -
                                 *(long *)(lVar16 + 0x5b10)) - *(long *)(lVar16 + 0x5c10)) -
                               *(long *)(lVar16 + 0x5d10)) - *(long *)(lVar16 + 0x5e10)) -
                             *(long *)(lVar16 + 0x5f10)) - *(long *)(lVar16 + 0x6010)) -
                           *(long *)(lVar16 + 0x6110)) - *(long *)(lVar16 + 0x6210)) -
                         *(long *)(lVar16 + 0x6310)) - *(long *)(lVar16 + 0x6410)) -
                       *(long *)(lVar16 + 0x6510)) - *(long *)(lVar16 + 0x6610)) -
                     *(long *)(lVar16 + 0x6710)) * 0x400;
            if (-1 < (long)uVar18) goto LAB_0012a135;
LAB_0012b27b:
            dVar26 = (double)(uVar18 >> 1) + (double)(uVar18 >> 1);
          }
          goto LAB_00129c80;
        }
        uVar18 = (((((((((((((((((((*(long *)(lVar21 + 0x810) + *(long *)(lVar21 + 0x710) +
                                    *(long *)(lVar21 + 0x910) + *(long *)(lVar21 + 0xa10) +
                                    *(long *)(lVar21 + 0xb10) + *(long *)(lVar21 + 0xc10) +
                                    *(long *)(lVar21 + 0xd10) + *(long *)(lVar21 + 0xe10) +
                                    *(long *)(lVar21 + 0xf10) + *(long *)(lVar21 + 0x1010) +
                                    *(long *)(lVar21 + 0x1110) + *(long *)(lVar21 + 0x1210) +
                                    *(long *)(lVar21 + 0x1310) + *(long *)(lVar21 + 0x1410) +
                                    *(long *)(lVar21 + 0x1510) + *(long *)(lVar21 + 0x1610) +
                                    *(long *)(lVar21 + 0x1710) + *(long *)(lVar21 + 0x1810)) -
                                  *(long *)(lVar16 + 0x710)) - *(long *)(lVar16 + 0x810)) -
                                *(long *)(lVar16 + 0x910)) - *(long *)(lVar16 + 0xa10)) -
                              *(long *)(lVar16 + 0xb10)) - *(long *)(lVar16 + 0xc10)) -
                            *(long *)(lVar16 + 0xd10)) - *(long *)(lVar16 + 0xe10)) -
                          *(long *)(lVar16 + 0xf10)) - *(long *)(lVar16 + 0x1010)) -
                        *(long *)(lVar16 + 0x1110)) - *(long *)(lVar16 + 0x1210)) -
                      *(long *)(lVar16 + 0x1310)) - *(long *)(lVar16 + 0x1410)) -
                    *(long *)(lVar16 + 0x1510)) - *(long *)(lVar16 + 0x1610)) -
                  *(long *)(lVar16 + 0x1710)) - *(long *)(lVar16 + 0x1810)) * 0x400;
      }
      goto joined_r0x0012aaef;
    }
    if (uVar2 == 100) {
      if (iVar10 == 2) {
        uVar18 = (((((((((((((((*(long *)(lVar21 + 0x55b0) + *(long *)(lVar21 + 0x5530) +
                                *(long *)(lVar21 + 0x5630) + *(long *)(lVar21 + 0x56b0) +
                                *(long *)(lVar21 + 0x5730) + *(long *)(lVar21 + 0x57b0) +
                                *(long *)(lVar21 + 0x5830) + *(long *)(lVar21 + 0x58b0) +
                                *(long *)(lVar21 + 0x5930) + *(long *)(lVar21 + 0x59b0) +
                                *(long *)(lVar21 + 0x5a30) + *(long *)(lVar21 + 0x5ab0) +
                                *(long *)(lVar21 + 0x5b30) + *(long *)(lVar21 + 0x5bb0)) -
                              *(long *)(lVar16 + 0x5530)) - *(long *)(lVar16 + 0x55b0)) -
                            *(long *)(lVar16 + 0x5630)) - *(long *)(lVar16 + 0x56b0)) -
                          *(long *)(lVar16 + 0x5730)) - *(long *)(lVar16 + 0x57b0)) -
                        *(long *)(lVar16 + 0x5830)) - *(long *)(lVar16 + 0x58b0)) -
                      *(long *)(lVar16 + 0x5930)) - *(long *)(lVar16 + 0x59b0)) -
                    *(long *)(lVar16 + 0x5a30)) - *(long *)(lVar16 + 0x5ab0)) -
                  *(long *)(lVar16 + 0x5b30)) - *(long *)(lVar16 + 0x5bb0)) * 0x100;
        if ((long)uVar18 < 0) goto LAB_0012aeca;
LAB_0012acdf:
        dVar26 = (double)(long)uVar18;
      }
      else {
        dVar26 = 0.0;
        if (iVar10 == 4) {
          uVar18 = (((((((((((((((*(long *)(lVar21 + 0x4eb0) + *(long *)(lVar21 + 0x4e30) +
                                  *(long *)(lVar21 + 0x4f30) + *(long *)(lVar21 + 0x4fb0) +
                                  *(long *)(lVar21 + 0x5030) + *(long *)(lVar21 + 0x50b0) +
                                  *(long *)(lVar21 + 0x5130) + *(long *)(lVar21 + 0x51b0) +
                                  *(long *)(lVar21 + 0x5230) + *(long *)(lVar21 + 0x52b0) +
                                  *(long *)(lVar21 + 0x5330) + *(long *)(lVar21 + 0x53b0) +
                                  *(long *)(lVar21 + 0x5430) + *(long *)(lVar21 + 0x54b0)) -
                                *(long *)(lVar16 + 0x4e30)) - *(long *)(lVar16 + 0x4eb0)) -
                              *(long *)(lVar16 + 0x4f30)) - *(long *)(lVar16 + 0x4fb0)) -
                            *(long *)(lVar16 + 0x5030)) - *(long *)(lVar16 + 0x50b0)) -
                          *(long *)(lVar16 + 0x5130)) - *(long *)(lVar16 + 0x51b0)) -
                        *(long *)(lVar16 + 0x5230)) - *(long *)(lVar16 + 0x52b0)) -
                      *(long *)(lVar16 + 0x5330)) - *(long *)(lVar16 + 0x53b0)) -
                    *(long *)(lVar16 + 0x5430)) - *(long *)(lVar16 + 0x54b0)) * 0x100;
          if ((long)uVar18 < 0) goto LAB_0012a9d2;
LAB_0012a4b8:
          dVar26 = (double)(long)uVar18;
        }
      }
    }
    else if (uVar2 == 0x65) {
      if (iVar10 == 2) {
        lVar16 = ((((((((((((((*(long *)(lVar21 + 0x5590) + *(long *)(lVar21 + 0x5510) +
                               *(long *)(lVar21 + 0x5610) + *(long *)(lVar21 + 0x5690) +
                               *(long *)(lVar21 + 0x5710) + *(long *)(lVar21 + 0x5790) +
                               *(long *)(lVar21 + 0x5810) + *(long *)(lVar21 + 0x5890) +
                               *(long *)(lVar21 + 0x5910) + *(long *)(lVar21 + 0x5990) +
                               *(long *)(lVar21 + 0x5a10) + *(long *)(lVar21 + 0x5a90) +
                               *(long *)(lVar21 + 0x5b10) + *(long *)(lVar21 + 0x5b90)) -
                             *(long *)(lVar16 + 0x5510)) - *(long *)(lVar16 + 0x5590)) -
                           *(long *)(lVar16 + 0x5610)) - *(long *)(lVar16 + 0x5690)) -
                         *(long *)(lVar16 + 0x5710)) - *(long *)(lVar16 + 0x5790)) -
                       *(long *)(lVar16 + 0x5810)) - *(long *)(lVar16 + 0x5890)) -
                     *(long *)(lVar16 + 0x5910)) - *(long *)(lVar16 + 0x5990)) -
                   *(long *)(lVar16 + 0x5a10)) - *(long *)(lVar16 + 0x5a90)) -
                 *(long *)(lVar16 + 0x5b10)) - *(long *)(lVar16 + 0x5b90);
joined_r0x0012b5df:
        uVar18 = lVar16 * 0x100;
        if (-1 < (long)uVar18) goto LAB_0012acdf;
LAB_0012aeca:
        dVar26 = (double)(uVar18 >> 1) + (double)(uVar18 >> 1);
      }
      else {
        dVar26 = 0.0;
        if (iVar10 == 4) {
          lVar16 = ((((((((((((((*(long *)(lVar21 + 0x4e90) + *(long *)(lVar21 + 0x4e10) +
                                 *(long *)(lVar21 + 0x4f10) + *(long *)(lVar21 + 0x4f90) +
                                 *(long *)(lVar21 + 0x5010) + *(long *)(lVar21 + 0x5090) +
                                 *(long *)(lVar21 + 0x5110) + *(long *)(lVar21 + 0x5190) +
                                 *(long *)(lVar21 + 0x5210) + *(long *)(lVar21 + 0x5290) +
                                 *(long *)(lVar21 + 0x5310) + *(long *)(lVar21 + 0x5390) +
                                 *(long *)(lVar21 + 0x5410) + *(long *)(lVar21 + 0x5490)) -
                               *(long *)(lVar16 + 0x4e10)) - *(long *)(lVar16 + 0x4e90)) -
                             *(long *)(lVar16 + 0x4f10)) - *(long *)(lVar16 + 0x4f90)) -
                           *(long *)(lVar16 + 0x5010)) - *(long *)(lVar16 + 0x5090)) -
                         *(long *)(lVar16 + 0x5110)) - *(long *)(lVar16 + 0x5190)) -
                       *(long *)(lVar16 + 0x5210)) - *(long *)(lVar16 + 0x5290)) -
                     *(long *)(lVar16 + 0x5310)) - *(long *)(lVar16 + 0x5390)) -
                   *(long *)(lVar16 + 0x5410)) - *(long *)(lVar16 + 0x5490);
joined_r0x0012abea:
          uVar18 = lVar16 * 0x100;
          if (-1 < (long)uVar18) goto LAB_0012a4b8;
LAB_0012a9d2:
          dVar26 = (double)(uVar18 >> 1) + (double)(uVar18 >> 1);
        }
      }
    }
    else if (uVar2 == 0x66) {
      if (iVar10 == 2) {
        lVar16 = ((((((((((((((*(long *)(lVar21 + 0x55c0) + *(long *)(lVar21 + 0x5540) +
                               *(long *)(lVar21 + 0x5640) + *(long *)(lVar21 + 0x56c0) +
                               *(long *)(lVar21 + 0x5740) + *(long *)(lVar21 + 0x57c0) +
                               *(long *)(lVar21 + 0x5840) + *(long *)(lVar21 + 0x58c0) +
                               *(long *)(lVar21 + 0x5940) + *(long *)(lVar21 + 0x59c0) +
                               *(long *)(lVar21 + 0x5a40) + *(long *)(lVar21 + 0x5ac0) +
                               *(long *)(lVar21 + 0x5b40) + *(long *)(lVar21 + 0x5bc0)) -
                             *(long *)(lVar16 + 0x5540)) - *(long *)(lVar16 + 0x55c0)) -
                           *(long *)(lVar16 + 0x5640)) - *(long *)(lVar16 + 0x56c0)) -
                         *(long *)(lVar16 + 0x5740)) - *(long *)(lVar16 + 0x57c0)) -
                       *(long *)(lVar16 + 0x5840)) - *(long *)(lVar16 + 0x58c0)) -
                     *(long *)(lVar16 + 0x5940)) - *(long *)(lVar16 + 0x59c0)) -
                   *(long *)(lVar16 + 0x5a40)) - *(long *)(lVar16 + 0x5ac0)) -
                 *(long *)(lVar16 + 0x5b40)) - *(long *)(lVar16 + 0x5bc0);
        goto joined_r0x0012b5df;
      }
      dVar26 = 0.0;
      if (iVar10 == 4) {
        lVar16 = ((((((((((((((*(long *)(lVar21 + 0x4ec0) + *(long *)(lVar21 + 0x4e40) +
                               *(long *)(lVar21 + 0x4f40) + *(long *)(lVar21 + 0x4fc0) +
                               *(long *)(lVar21 + 0x5040) + *(long *)(lVar21 + 0x50c0) +
                               *(long *)(lVar21 + 0x5140) + *(long *)(lVar21 + 0x51c0) +
                               *(long *)(lVar21 + 0x5240) + *(long *)(lVar21 + 0x52c0) +
                               *(long *)(lVar21 + 0x5340) + *(long *)(lVar21 + 0x53c0) +
                               *(long *)(lVar21 + 0x5440) + *(long *)(lVar21 + 0x54c0)) -
                             *(long *)(lVar16 + 0x4e40)) - *(long *)(lVar16 + 0x4ec0)) -
                           *(long *)(lVar16 + 0x4f40)) - *(long *)(lVar16 + 0x4fc0)) -
                         *(long *)(lVar16 + 0x5040)) - *(long *)(lVar16 + 0x50c0)) -
                       *(long *)(lVar16 + 0x5140)) - *(long *)(lVar16 + 0x51c0)) -
                     *(long *)(lVar16 + 0x5240)) - *(long *)(lVar16 + 0x52c0)) -
                   *(long *)(lVar16 + 0x5340)) - *(long *)(lVar16 + 0x53c0)) -
                 *(long *)(lVar16 + 0x5440)) - *(long *)(lVar16 + 0x54c0);
        goto joined_r0x0012abea;
      }
    }
    else if (uVar2 == 0x67) {
      if (iVar10 == 2) {
        lVar16 = ((((((((((((((*(long *)(lVar21 + 0x55a0) + *(long *)(lVar21 + 0x5520) +
                               *(long *)(lVar21 + 0x5620) + *(long *)(lVar21 + 0x56a0) +
                               *(long *)(lVar21 + 0x5720) + *(long *)(lVar21 + 0x57a0) +
                               *(long *)(lVar21 + 0x5820) + *(long *)(lVar21 + 0x58a0) +
                               *(long *)(lVar21 + 0x5920) + *(long *)(lVar21 + 0x59a0) +
                               *(long *)(lVar21 + 0x5a20) + *(long *)(lVar21 + 0x5aa0) +
                               *(long *)(lVar21 + 0x5b20) + *(long *)(lVar21 + 0x5ba0)) -
                             *(long *)(lVar16 + 0x5520)) - *(long *)(lVar16 + 0x55a0)) -
                           *(long *)(lVar16 + 0x5620)) - *(long *)(lVar16 + 0x56a0)) -
                         *(long *)(lVar16 + 0x5720)) - *(long *)(lVar16 + 0x57a0)) -
                       *(long *)(lVar16 + 0x5820)) - *(long *)(lVar16 + 0x58a0)) -
                     *(long *)(lVar16 + 0x5920)) - *(long *)(lVar16 + 0x59a0)) -
                   *(long *)(lVar16 + 0x5a20)) - *(long *)(lVar16 + 0x5aa0)) -
                 *(long *)(lVar16 + 0x5b20)) - *(long *)(lVar16 + 0x5ba0);
        goto joined_r0x0012b5df;
      }
      dVar26 = 0.0;
      if (iVar10 == 4) {
        lVar16 = ((((((((((((((*(long *)(lVar21 + 0x4ea0) + *(long *)(lVar21 + 20000) +
                               *(long *)(lVar21 + 0x4f20) + *(long *)(lVar21 + 0x4fa0) +
                               *(long *)(lVar21 + 0x5020) + *(long *)(lVar21 + 0x50a0) +
                               *(long *)(lVar21 + 0x5120) + *(long *)(lVar21 + 0x51a0) +
                               *(long *)(lVar21 + 0x5220) + *(long *)(lVar21 + 0x52a0) +
                               *(long *)(lVar21 + 0x5320) + *(long *)(lVar21 + 0x53a0) +
                               *(long *)(lVar21 + 0x5420) + *(long *)(lVar21 + 0x54a0)) -
                             *(long *)(lVar16 + 20000)) - *(long *)(lVar16 + 0x4ea0)) -
                           *(long *)(lVar16 + 0x4f20)) - *(long *)(lVar16 + 0x4fa0)) -
                         *(long *)(lVar16 + 0x5020)) - *(long *)(lVar16 + 0x50a0)) -
                       *(long *)(lVar16 + 0x5120)) - *(long *)(lVar16 + 0x51a0)) -
                     *(long *)(lVar16 + 0x5220)) - *(long *)(lVar16 + 0x52a0)) -
                   *(long *)(lVar16 + 0x5320)) - *(long *)(lVar16 + 0x53a0)) -
                 *(long *)(lVar16 + 0x5420)) - *(long *)(lVar16 + 0x54a0);
        goto joined_r0x0012abea;
      }
    }
    else {
      dVar26 = 0.0;
      if (*(long *)(lVar13 + 8) != 0) {
        uVar18 = 0;
        dVar25 = 0.0;
        dVar26 = 0.0;
        do {
          uVar3 = *(uint *)(lVar13 + 0x10 + uVar18 * 8);
          plVar1 = (long *)(lVar21 + (ulong)uVar3 * 8);
          if (uVar2 == 1) {
            pcVar22 = (char *)*param_3;
            lVar17 = *(long *)(pcVar22 + 0x70508);
            if ((lVar17 == 0) || (*(int *)(lVar17 + 0xb0) == 0)) {
              dVar24 = dVar25;
              if (1 < DAT_01216a78) {
                fVar23 = (float)FUN_002917b0(&DAT_01216a60);
                lVar17 = syscall(0xba);
                fVar23 = fVar23 * DAT_00298548;
                uVar20 = 0x63e;
LAB_0012b49a:
                FUN_002340f0((double)fVar23,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",lVar17,
                             "nvml_gpm.c",uVar20);
                dVar24 = dVar25;
              }
            }
            else {
              dVar24 = DAT_00298b60;
              if ((*pcVar22 == '\x01') || (*(long *)(pcVar22 + 0x20) != 0)) {
                if ((char)param_3[2] == '\0') {
                  auVar8[0xf] = 0;
                  auVar8._0_15_ = stack0xffffffffffffff99;
                  _local_68 = auVar8 << 8;
                  lVar12 = *(long *)(pcVar22 + 0x256d8);
                  if (((lVar12 != 0) && (*(long *)(lVar12 + 0x30) != 0)) &&
                     (pcVar5 = *(code **)(*(long *)(lVar12 + 0x30) + 0x148), pcVar5 != (code *)0x0))
                  {
                    (*pcVar5)(lVar12,pcVar22,local_68);
                    dVar24 = DAT_00298b60;
                    if (local_68[0] != '\0') {
                      iVar10 = *(int *)(lVar17 + 0xb0);
                      if (iVar10 == 1) {
                        if (uVar3 == 0x3f0) {
LAB_0012bd0b:
                          lVar12 = 4;
                        }
                        else if (uVar3 < 0x3f1) {
                          if (uVar3 == 0x370) goto LAB_0012baa8;
                          if (uVar3 < 0x371) {
                            if (uVar3 == 0x2e0) goto LAB_0012b996;
                            lVar12 = 1;
                            if (uVar3 != 0x2f0) goto LAB_0012b8c9;
                          }
                          else {
                            lVar12 = 3;
                            if (uVar3 != 0x380) {
LAB_0012b8c9:
                              dVar24 = dVar25;
                              if (1 < DAT_01216a78) {
                                fVar23 = (float)FUN_002917b0(&DAT_01216a60);
                                lVar17 = syscall(0xba);
                                uVar20 = 0x65b;
                                dVar24 = (double)(fVar23 * DAT_00298548);
                                goto LAB_0012b949;
                              }
                              goto LAB_00129be8;
                            }
                          }
                        }
                        else if (uVar3 == 0x480) {
LAB_0012bab2:
                          lVar12 = 6;
                        }
                        else {
                          lVar12 = 7;
                          if ((uVar3 != 0x490) && (lVar12 = 5, uVar3 != 0x400)) goto LAB_0012b8c9;
                        }
                      }
                      else if (iVar10 == 2) {
                        if (uVar3 == 0x4a0) goto LAB_0012bd0b;
                        if (uVar3 < 0x4a1) {
                          if (uVar3 == 0x400) goto LAB_0012baa8;
                          if (uVar3 < 0x401) {
                            if (uVar3 == 0x340) goto LAB_0012b996;
                            lVar12 = 1;
                            if (uVar3 != 0x3a0) goto LAB_0012ba23;
                          }
                          else {
                            lVar12 = 3;
                            if (uVar3 != 0x450) {
LAB_0012ba23:
                              dVar24 = dVar25;
                              if (DAT_01216a78 < 2) goto LAB_00129be8;
                              fVar23 = (float)FUN_002917b0(&DAT_01216a60);
                              lVar17 = syscall(0xba);
                              uVar20 = 0x65f;
                              dVar24 = (double)(fVar23 * DAT_00298548);
                              goto LAB_0012b949;
                            }
                          }
                        }
                        else {
                          if (uVar3 == 0x560) goto LAB_0012bab2;
                          lVar12 = 7;
                          if ((uVar3 != 0x5b0) && (lVar12 = 5, uVar3 != 0x500)) goto LAB_0012ba23;
                        }
                      }
                      else if (iVar10 == 3) {
                        if (uVar3 == 0x430) {
LAB_0012baa8:
                          lVar12 = 2;
                        }
                        else if (uVar3 < 0x431) {
                          if (uVar3 == 0x340) {
LAB_0012b996:
                            lVar12 = 0;
                          }
                          else {
                            lVar12 = 1;
                            if (uVar3 != 0x3c0) goto LAB_0012bc70;
                          }
                        }
                        else {
                          lVar12 = 3;
                          if (uVar3 != 0x460) {
LAB_0012bc70:
                            dVar24 = dVar25;
                            if (1 < DAT_01216a78) {
                              fVar23 = (float)FUN_002917b0(&DAT_01216a60);
                              lVar17 = syscall(0xba);
                              uVar20 = 0x663;
                              dVar24 = (double)(fVar23 * DAT_00298548);
LAB_0012b949:
                              FUN_002340f0(dVar24,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%llu\n",
                                           "ERROR",lVar17,"nvml_gpm.c",uVar20);
                              dVar24 = dVar25;
                            }
                            goto LAB_00129be8;
                          }
                        }
                      }
                      else {
                        if (iVar10 != 4) {
                          dVar24 = dVar25;
                          if (1 < DAT_01216a78) {
                            fVar23 = (float)FUN_002917b0(&DAT_01216a60);
                            lVar17 = syscall(0xba);
                            fVar23 = fVar23 * DAT_00298548;
                            uVar20 = 0x66b;
                            goto LAB_0012b49a;
                          }
                          goto LAB_00129be8;
                        }
                        if (uVar3 == 0x530) goto LAB_0012bd0b;
                        if (uVar3 < 0x531) {
                          if (uVar3 == 0x490) goto LAB_0012baa8;
                          if (uVar3 < 0x491) {
                            if (uVar3 == 0x3d0) goto LAB_0012b996;
                            lVar12 = 1;
                            if (uVar3 != 0x430) goto LAB_0012bb12;
                          }
                          else {
                            lVar12 = 3;
                            if (uVar3 != 0x4e0) {
LAB_0012bb12:
                              dVar24 = dVar25;
                              if (DAT_01216a78 < 2) goto LAB_00129be8;
                              fVar23 = (float)FUN_002917b0(&DAT_01216a60);
                              lVar17 = syscall(0xba);
                              uVar20 = 0x667;
                              dVar24 = (double)(fVar23 * DAT_00298548);
                              goto LAB_0012b949;
                            }
                          }
                        }
                        else {
                          if (uVar3 == 0x5f0) goto LAB_0012bab2;
                          lVar12 = 7;
                          if ((uVar3 != 0x640) && (lVar12 = 5, uVar3 != 0x590)) goto LAB_0012bb12;
                        }
                      }
                      dVar24 = (double)*(int *)(lVar17 + 0x44 + lVar12 * 4);
                    }
                  }
                }
                else {
                  dVar24 = dVar25;
                  if ((int)param_3[3] != 0) {
                    plVar15 = param_3 + 4;
                    iVar10 = 0;
                    do {
                      iVar10 = iVar10 + (int)*plVar15;
                      plVar15 = plVar15 + 2;
                    } while (plVar15 != param_3 + (ulong)((int)param_3[3] - 1) * 2 + 6);
                    dVar24 = (double)iVar10;
                  }
                }
              }
            }
LAB_00129be8:
            dVar24 = (double)(ulong)(*plVar1 - *(long *)(lVar16 + (ulong)uVar3 * 8)) * dVar24;
          }
          else {
            iVar10 = *(int *)(lVar13 + 0x14 + uVar18 * 8);
            if (0x30 < uVar2 - 0xf8) {
              dVar24 = (double)iVar10;
              goto LAB_00129be8;
            }
            uVar14 = (long)iVar10 * *plVar1;
            if ((long)uVar14 < 0) {
              dVar24 = (double)uVar14;
            }
            else {
              dVar24 = (double)(long)uVar14;
            }
          }
          dVar26 = dVar26 + dVar24;
          uVar18 = uVar18 + 1;
        } while (uVar18 < *(ulong *)(lVar13 + 8));
      }
      if ((uVar2 - 0x14 < 2) || (uVar2 - 0x3c < 0x26)) goto LAB_00129c80;
    }
    if (uVar2 - 100 < 0x3c) goto LAB_00129c80;
  }
  dVar25 = 0.0;
  *(double *)(param_1 + 2) = dVar26;
  uVar18 = *(ulong *)(lVar13 + 0x50);
  if (uVar18 != 0) {
    uVar14 = 0;
    do {
      if ((uVar2 == 1) &&
         (((pcVar22 = (char *)*param_3, pcVar22 == (char *)0x0 || (*pcVar22 == '\x01')) ||
          (*(long *)(pcVar22 + 0x20) != 0)))) {
        auVar6[0xf] = 0;
        auVar6._0_15_ = stack0xffffffffffffff99;
        _local_68 = auVar6 << 8;
        lVar16 = *(long *)(pcVar22 + 0x256d8);
        if (((lVar16 != 0) && (*(long *)(lVar16 + 0x30) != 0)) &&
           (pcVar5 = *(code **)(*(long *)(lVar16 + 0x30) + 0x148), pcVar5 != (code *)0x0)) {
          (*pcVar5)(lVar16,pcVar22,local_68);
          if (local_68[0] == '\0') {
            uVar18 = *(ulong *)(lVar13 + 0x50);
          }
          else if ((char)param_3[2] == '\0') {
            if (*(long *)(pcVar22 + 0x70508) == 0) {
              if (DAT_01216a78 < 2) {
                uVar18 = *(ulong *)(lVar13 + 0x50);
              }
              else {
                fVar23 = (float)FUN_002917b0(&DAT_01216a60);
                lVar16 = syscall(0xba);
                FUN_002340f0((double)(fVar23 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n"
                             ,"ERROR",lVar16,"nvml_gpm.c",0x690);
                uVar18 = *(ulong *)(lVar13 + 0x50);
              }
            }
            else {
              uVar18 = *(ulong *)(lVar13 + 0x50);
            }
          }
          else {
            uVar18 = *(ulong *)(lVar13 + 0x50);
          }
        }
      }
      uVar14 = (ulong)((int)uVar14 + 1);
    } while (uVar14 < uVar18);
    dVar26 = *(double *)(param_1 + 2);
  }
  if (uVar2 == 10) {
    if ((char)param_3[2] == '\0') {
      pcVar22 = (char *)*param_3;
    }
    else {
      pcVar22 = (char *)param_3[5];
    }
    dVar26 = (dVar26 * _DAT_00298b78) / ((double)param_4[1] - (double)param_3[1]);
    *(double *)(param_1 + 2) = dVar26;
    dVar24 = dVar25;
    if (pcVar22 == (char *)0x0) {
LAB_0012a2b8:
      if (1 < DAT_01216a78) {
        fVar23 = (float)FUN_002917b0(&DAT_01216a60);
        lVar16 = syscall(0xba);
        FUN_002340f0((double)(fVar23 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR"
                     ,lVar16,"nvml_gpm.c",0x220);
        dVar26 = *(double *)(param_1 + 2);
      }
      goto LAB_00129d78;
    }
    uVar18 = param_4[1];
    uVar14 = param_3[1];
    pcVar19 = pcVar22;
    if (*pcVar22 == '\x01') {
LAB_0012a1d4:
      lVar16 = *(long *)(pcVar22 + 0x70508);
      if ((lVar16 != 0) && (uVar14 <= uVar18)) {
        if (*(int *)(lVar16 + 0x30) == 0) {
          iVar10 = FUN_00175fd0(pcVar19,2,&local_98);
          if (iVar10 == 0) {
            *(undefined4 *)(lVar16 + 0x30) = local_98;
            goto LAB_0012a1fa;
          }
          if (DAT_01216a78 < 2) goto LAB_0012aafa;
          fVar23 = (float)FUN_002917b0(&DAT_01216a60);
          lVar16 = syscall(0xba);
          fVar23 = fVar23 * DAT_00298548;
          uVar20 = 0x232;
LAB_0012b7e3:
          FUN_002340f0((double)fVar23,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","ERROR",lVar16,
                       "nvml_gpm.c",uVar20,iVar10);
          dVar26 = *(double *)(param_1 + 2);
        }
        else {
LAB_0012a1fa:
          auVar4 = (undefined1  [4])*(uint *)(lVar16 + 0x34);
          if (*(uint *)(lVar16 + 0x34) == 0) {
            iVar10 = FUN_001718d0(pcVar19,local_68);
            if (iVar10 != 0) {
              if (DAT_01216a78 < 2) goto LAB_0012aafa;
              fVar23 = (float)FUN_002917b0(&DAT_01216a60);
              lVar16 = syscall(0xba);
              fVar23 = fVar23 * DAT_00298548;
              uVar20 = 0x23f;
              goto LAB_0012b7e3;
            }
            *(undefined1 (*) [4])(lVar16 + 0x34) = local_68;
            auVar4 = local_68;
          }
          dVar26 = *(double *)(param_1 + 2);
          dVar24 = ((double)(uint)auVar4 * _DAT_00298b80 + (double)(uint)auVar4 * _DAT_00298b80) *
                   (double)*(uint *)(lVar16 + 0x30) * _DAT_00298b88;
          if ((*pcVar22 != '\x01') && (*(long *)(pcVar22 + 0x20) == 0)) {
            dVar24 = dVar24 * *(double *)(lVar16 + 0x38);
          }
        }
        goto LAB_00129d78;
      }
    }
    else {
      if (((*(int *)(pcVar22 + 0x14) == 0) || (*(int *)(pcVar22 + 0x1c) != 0)) ||
         (*(int *)(pcVar22 + 0x10) == 0)) {
        if (*(long *)(pcVar22 + 0x20) != 0) goto LAB_0012a2b8;
      }
      else if (*(long *)(pcVar22 + 0x20) != 0) goto LAB_0012a1d4;
      auVar7._8_8_ = 0;
      auVar7._0_8_ = auStack_64._4_8_;
      _local_68 = auVar7 << 0x40;
      iVar10 = FUN_001384c0(pcVar22,local_68);
      if (iVar10 == 0) {
        pcVar19 = *(char **)(_local_68 + 0x98);
        goto LAB_0012a1d4;
      }
      if (1 < DAT_01216a78) {
        fVar23 = (float)FUN_002917b0(&DAT_01216a60);
        lVar16 = syscall(0xba);
        FUN_002340f0((double)(fVar23 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n",
                     "ERROR",lVar16,"nvml_gpm.c",0x21a,iVar10);
        dVar26 = *(double *)(param_1 + 2);
        goto LAB_00129d78;
      }
    }
LAB_0012aafa:
    dVar26 = *(double *)(param_1 + 2);
LAB_00129d78:
    if (dVar24 == dVar25) {
      if (dVar26 != dVar25) {
        *(undefined8 *)(param_1 + 2) = DAT_00298b68;
      }
      goto LAB_00129d9f;
    }
    dVar26 = dVar26 / dVar24;
  }
  else if ((0x30 < uVar2 - 0xf8) && (cVar9 = FUN_00128770(uVar2), cVar9 == '\0')) {
    dVar24 = extraout_XMM1_Qa;
    if (extraout_RDX == 0) {
      dVar24 = (double)(param_4[1] - param_3[1]) / _DAT_00298b88;
    }
    goto LAB_00129d78;
  }
  *(double *)(param_1 + 2) = dVar26;
  if (*(char *)(lVar13 + 1) != '\0') {
    dVar24 = DAT_00298b58;
    if ((dVar26 <= DAT_00298b60) && (dVar24 = dVar25, dVar25 <= dVar26)) {
      dVar24 = DAT_00298b58 * dVar26;
    }
    *(double *)(param_1 + 2) = dVar24;
  }
LAB_00129d9f:
  if ((*(long *)(*param_3 + 0x70508) != 0) && (*(int *)(*(long *)(*param_3 + 0x70508) + 0xac) == 1))
  {
    uVar2 = *param_1;
    if (uVar2 == 7) {
      dVar26 = DAT_00298b90 * *(double *)(param_1 + 2);
      if (DAT_00298b58 <= DAT_00298b90 * *(double *)(param_1 + 2)) {
        dVar26 = DAT_00298b58;
      }
      *(double *)(param_1 + 2) = dVar26;
    }
    else if (uVar2 == 9) {
      dVar26 = _DAT_00298b98 * *(double *)(param_1 + 2);
      if (DAT_00298b58 <= _DAT_00298b98 * *(double *)(param_1 + 2)) {
        dVar26 = DAT_00298b58;
      }
      *(double *)(param_1 + 2) = dVar26;
    }
    else if (uVar2 == 5) {
      local_b8 = (undefined1  [16])0x0;
      local_88 = (undefined1  [16])0x0;
      local_58 = (undefined1  [16])0x0;
      local_a8 = 0;
      local_78 = 0;
      local_48 = 0;
      auStack_c4 = SUB1612((undefined1  [16])0x0,4);
      local_c8 = 8;
      auStack_94 = SUB1612((undefined1  [16])0x0,4);
      local_98 = 7;
      auStack_64 = SUB1612((undefined1  [16])0x0,4);
      local_68 = (undefined1  [4])0x9;
      FUN_00129850(&local_c8,param_2,param_3,param_4);
      FUN_00129850(&local_98,param_2,param_3,param_4);
      FUN_00129850(local_68,param_2,param_3,param_4);
      dVar25 = (double)auStack_c4._4_8_ + (double)auStack_94._4_8_ + (double)auStack_64._4_8_;
      dVar26 = *(double *)(param_1 + 2);
      if (*(double *)(param_1 + 2) <= dVar25) {
        dVar26 = dVar25;
      }
      if (DAT_00298b58 <= dVar26) {
        dVar26 = DAT_00298b58;
      }
      *(double *)(param_1 + 2) = dVar26;
    }
  }
  param_1[1] = 0;
  return;
}


// ===== 0012bd20 FUN_0012bd20 =====

int FUN_0012bd20(char *param_1,undefined4 *param_2)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  float fVar6;
  long local_30 [2];
  
  *param_2 = 0;
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 != '\x01') && (*(long *)(param_1 + 0x20) == 0)) {
    local_30[0] = 0;
    iVar3 = FUN_001384c0(param_1,local_30);
    if (iVar3 != 0) {
      if (DAT_01216a78 < 2) {
        return iVar3;
      }
      fVar6 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","ERROR",
                   lVar5,"nvml_gpm.c",0x169,iVar3);
      return iVar3;
    }
    param_1 = *(char **)(local_30[0] + 0x98);
  }
  if (*(int *)(param_1 + 0x71c) == 0) {
    do {
      iVar3 = FUN_00291820(param_1 + 0x720,1,0);
    } while (iVar3 != 0);
    if (*(int *)(param_1 + 0x71c) == 0) {
      lVar5 = *(long *)(param_1 + 0x256d8);
      uVar4 = 3;
      if (((lVar5 != 0) && (*(long *)(lVar5 + 0x20) != 0)) &&
         (pcVar2 = *(code **)(*(long *)(lVar5 + 0x20) + 0x98), pcVar2 != (code *)0x0)) {
        uVar4 = (*pcVar2)(lVar5,param_1,param_1 + 0x708);
      }
      *(undefined4 *)(param_1 + 0x724) = uVar4;
      param_1[0x71c] = '\x01';
      param_1[0x71d] = '\0';
      param_1[0x71e] = '\0';
      param_1[0x71f] = '\0';
    }
    FUN_00291830(param_1 + 0x720,0);
    iVar3 = *(int *)(param_1 + 0x724);
  }
  else {
    iVar3 = *(int *)(param_1 + 0x724);
  }
  if (iVar3 == 0) {
    iVar1 = *(int *)(param_1 + 0x70c);
    if (iVar1 == 0x180) {
      *param_2 = 1;
      return 0;
    }
    if (iVar1 == 0x1a0) {
      if (6 < *(uint *)(param_1 + 0x710)) goto LAB_0012bf1c;
      *param_2 = 2;
    }
    else if (iVar1 == 0x1b0) {
      if (5 < *(int *)(param_1 + 0x710) - 2U) goto LAB_0012bf1c;
      *param_2 = 3;
    }
    else {
      if ((iVar1 != 0x1c0) || ((*(uint *)(param_1 + 0x710) & 0xfffffffd) != 0)) {
LAB_0012bf1c:
        *param_2 = 0;
        return 0;
      }
      *param_2 = 4;
    }
  }
  else if (1 < DAT_01216a78) {
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar5,"nvml_gpm.c",0x170,"gpmCheckVersion",0x170,iVar3);
    return iVar3;
  }
  return iVar3;
}


// ===== 0012c010 FUN_0012c010 =====

byte FUN_0012c010(undefined8 *param_1)

{
  void *pvVar1;
  
  pvVar1 = calloc(1,0x80c0);
  *param_1 = pvVar1;
  return -(pvVar1 == (void *)0x0) & 0x14;
}


// ===== 0012c040 FUN_0012c040 =====

undefined8 FUN_0012c040(void *param_1)

{
  free(param_1);
  return 0;
}


// ===== 0012c050 FUN_0012c050 =====

int FUN_0012c050(char *param_1)

{
  code *pcVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined8 uVar5;
  int iVar6;
  void *pvVar7;
  long lVar8;
  char *pcVar9;
  float fVar10;
  undefined1 local_68 [4];
  undefined1 auStack_64 [12];
  undefined1 local_58 [16];
  undefined8 local_48;
  
  pvVar7 = *(void **)(param_1 + 0x70508);
  if (pvVar7 == (void *)0x0) {
    pvVar7 = calloc(1,0xb8);
    *(void **)(param_1 + 0x70508) = pvVar7;
    if (pvVar7 == (void *)0x0) {
      if (1 < DAT_01216a78) {
        fVar10 = (float)FUN_002917b0(&DAT_01216a60);
        lVar8 = syscall(0xba);
        FUN_002340f0((double)(fVar10 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR"
                     ,lVar8,"nvml_gpm.c",0x1ba);
        return 0x14;
      }
      return 0x14;
    }
  }
  if (*(char *)((long)pvVar7 + 0xa8) != '\0') {
    return 5;
  }
  pcVar9 = param_1;
  if ((*param_1 != '\x01') && (*(long *)(param_1 + 0x20) == 0)) {
    auVar3._8_8_ = 0;
    auVar3._0_8_ = auStack_64._4_8_;
    _local_68 = auVar3 << 0x40;
    iVar6 = FUN_001384c0(param_1,local_68);
    if (iVar6 != 0) {
      if (1 < DAT_01216a78) {
        fVar10 = (float)FUN_002917b0(&DAT_01216a60);
        lVar8 = syscall(0xba);
        FUN_002340f0((double)(fVar10 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n",
                     "ERROR",lVar8,"nvml_gpm.c",0x1cb,iVar6);
        return iVar6;
      }
      return iVar6;
    }
    pcVar9 = *(char **)(_local_68 + 0x98);
  }
  iVar6 = FUN_0012bd20(pcVar9,(long)pvVar7 + 0xb0);
  if (iVar6 != 0) {
    if (1 < DAT_01216a78) {
      fVar10 = (float)FUN_002917b0(&DAT_01216a60);
      lVar8 = syscall(0xba);
      FUN_002340f0((double)(fVar10 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar8,"nvml_gpm.c",0x1d2,"gpmInit",0x1d2,iVar6);
      return iVar6;
    }
    return iVar6;
  }
  if (*(int *)((long)pvVar7 + 0xb0) == 0) {
    return 3;
  }
  auVar2[0xf] = 0;
  auVar2._0_15_ = stack0xffffffffffffff99;
  _local_68 = auVar2 << 8;
  lVar8 = *(long *)(pcVar9 + 0x256d8);
  if ((lVar8 != 0) && (*(long *)(lVar8 + 0x28) != 0)) {
    pcVar1 = *(code **)(*(long *)(lVar8 + 0x28) + 0x68);
    if (pcVar1 != (code *)0x0) {
      (*pcVar1)(lVar8,pcVar9,local_68);
      if (local_68[0] != '\0') {
        return 3;
      }
    }
  }
  auVar4._12_4_ = 0;
  auVar4._0_12_ = local_58._4_12_;
  local_58 = auVar4 << 0x20;
  auStack_64 = SUB1612((undefined1  [16])0x0,4);
  local_68 = (undefined1  [4])0x1000014;
  iVar6 = FUN_001730a0(local_68);
  if (iVar6 != 3) {
    if (iVar6 != 0) {
      return 3;
    }
    if (auStack_64._4_4_ == 1) {
      return 3;
    }
    if (local_58._0_4_ == 1) {
      return 3;
    }
  }
  *(undefined4 *)((long)pvVar7 + 8) = 0;
  local_48 = 0;
  auStack_64 = SUB1612((undefined1  [16])0x0,4);
  local_68 = (undefined1  [4])0x2000028;
  local_58 = (undefined1  [16])0x0;
  iVar6 = FUN_0013e5a0(param_1,local_68);
  if ((iVar6 != 0) && (1 < DAT_01216a78)) {
    fVar10 = (float)FUN_002917b0(&DAT_01216a60);
    lVar8 = syscall(0xba);
    FUN_002340f0((double)(fVar10 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",
                 lVar8,"nvml_gpm.c",0x1ee);
  }
  uVar5 = auStack_64._4_8_;
  iVar6 = FUN_0013e5a0(pcVar9,local_68);
  if ((iVar6 != 0) && (1 < DAT_01216a78)) {
    fVar10 = (float)FUN_002917b0(&DAT_01216a60);
    lVar8 = syscall(0xba);
    FUN_002340f0((double)(fVar10 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",
                 lVar8,"nvml_gpm.c",0x1f5);
  }
  *(double *)((long)pvVar7 + 0x38) = (double)(ulong)uVar5 / (double)(ulong)auStack_64._4_8_;
  FUN_00128810(pcVar9);
  lVar8 = *(long *)(pcVar9 + 0x256d8);
  if (((lVar8 == 0) || (*(long *)(lVar8 + 0x100) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(lVar8 + 0x100) + 0x20), pcVar1 == (code *)0x0)) {
    iVar6 = 3;
  }
  else {
    iVar6 = (*pcVar1)(lVar8,pcVar9,(long)pvVar7 + 0xac);
    if (iVar6 == 0) goto LAB_0012c3d3;
  }
  if (1 < DAT_01216a78) {
    fVar10 = (float)FUN_002917b0(&DAT_01216a60);
    lVar8 = syscall(0xba);
    FUN_002340f0((double)(fVar10 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","ERROR",
                 lVar8,"nvml_gpm.c",0x201,iVar6);
  }
LAB_0012c3d3:
  *(undefined1 *)((long)pvVar7 + 0xa8) = 1;
  return 0;
}


// ===== 0012c590 FUN_0012c590 =====

int FUN_0012c590(char *param_1)

{
  long *plVar1;
  int iVar2;
  int iVar3;
  undefined8 *__ptr;
  void *pvVar4;
  long lVar5;
  undefined8 uVar6;
  float fVar7;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if (((*param_1 == '\x01') ||
      ((((iVar2 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) &&
     ((iVar2 = FUN_0012c050(param_1), iVar2 == 0 || (iVar2 == 5)))) {
    plVar1 = *(long **)(param_1 + 0x70508);
    if ((int)plVar1[0x16] - 1U < 2) {
      iVar2 = 5;
      if (*plVar1 == 0) {
        __ptr = calloc(0x20,1);
        if (__ptr == (undefined8 *)0x0) {
          iVar2 = 0x14;
        }
        else {
          *__ptr = param_1;
          __ptr[1] = plVar1 + 2;
          if ((int)plVar1[0x16] == 2) {
            pvVar4 = calloc(8,0x1114);
            plVar1[3] = (long)pvVar4;
          }
          else {
            pvVar4 = calloc(8,0x1002);
            plVar1[3] = (long)pvVar4;
          }
          if (pvVar4 == (void *)0x0) {
            iVar2 = 0x14;
          }
          else {
            *(undefined1 *)(__ptr + 3) = 1;
            if ((int)plVar1[0x16] == 2) {
              iVar3 = FUN_00293340(__ptr + 2,FUN_00129450,__ptr);
            }
            else {
              iVar3 = FUN_00293340(__ptr + 2,FUN_00129660,__ptr);
            }
            if (iVar3 == 0) {
              if (plVar1[3] != 0) {
                *plVar1 = (long)__ptr;
                *(undefined4 *)(plVar1 + 1) = 2;
                return 0;
              }
              iVar2 = 5000;
              do {
                FUN_00292f00(1);
                iVar2 = iVar2 + -1;
              } while (iVar2 != 0);
              if (1 < DAT_01216a78) {
                uVar6 = nvmlErrorString(10);
                fVar7 = (float)FUN_002917b0(&DAT_01216a60);
                lVar5 = syscall(0xba);
                FUN_002340f0((double)(fVar7 * DAT_00298548),
                             "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n","ERROR",lVar5,"nvml_gpm.c",
                             0x3a3,uVar6);
              }
              iVar2 = 10;
              if (__ptr[2] != 0) {
                FUN_002933f0(__ptr[2],0);
              }
            }
            else {
              iVar2 = 0x11;
              if (1 < DAT_01216a78) {
                fVar7 = (float)FUN_002917b0(&DAT_01216a60);
                lVar5 = syscall(0xba);
                FUN_002340f0((double)(fVar7 * DAT_00298548),
                             "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","ERROR",lVar5,"nvml_gpm.c",
                             0x395,iVar3);
              }
            }
          }
          free(__ptr);
        }
      }
    }
    else {
      iVar2 = 3;
    }
    if ((void *)plVar1[3] != (void *)0x0) {
      free((void *)plVar1[3]);
      plVar1[3] = 0;
      return iVar2;
    }
  }
  return iVar2;
}


// ===== 0012c890 FUN_0012c890 =====

undefined8 FUN_0012c890(char *param_1)

{
  long *plVar1;
  long lVar2;
  
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 != '\x01') &&
     ((((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x1c) != 0)) ||
       (*(int *)(param_1 + 0x10) == 0)) || (*(long *)(param_1 + 0x20) == 0)))) {
    return 2;
  }
  plVar1 = *(long **)(param_1 + 0x70508);
  if ((int)plVar1[1] != 2) {
    return 1;
  }
  lVar2 = *plVar1;
  *(undefined1 *)(lVar2 + 0x18) = 0;
  FUN_002933f0(*(undefined8 *)(lVar2 + 0x10),0);
  free((void *)plVar1[3]);
  plVar1[3] = 0;
  return 0;
}


// ===== 0012c920 FUN_0012c920 =====

undefined8 FUN_0012c920(int *param_1)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  char *pcVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uVar7;
  uint uVar8;
  undefined *puVar9;
  float fVar10;
  
  if (param_1 == (int *)0x0) {
    if (DAT_01216a78 < 2) {
      return 2;
    }
    fVar10 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    uVar7 = 0x80a;
    fVar10 = fVar10 * DAT_00298548;
LAB_0012ca59:
    FUN_002340f0((double)fVar10,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",lVar5,"nvml_gpm.c",
                 uVar7);
    return 2;
  }
  if (*param_1 != 1) {
    return 0x19;
  }
  if ((((0x14c < param_1[1] - 1U) ||
       (puVar2 = *(undefined8 **)(param_1 + 2), puVar2 == (undefined8 *)0x0)) ||
      (puVar3 = *(undefined8 **)(param_1 + 4), puVar3 == (undefined8 *)0x0)) || (puVar2 == puVar3))
  {
    if (DAT_01216a78 < 2) {
      return 2;
    }
    fVar10 = (float)FUN_002917b0(&DAT_01216a60);
    lVar5 = syscall(0xba);
    uVar7 = 0x816;
    fVar10 = fVar10 * DAT_00298548;
    goto LAB_0012ca59;
  }
  pcVar4 = (char *)*puVar2;
  if (pcVar4 != (char *)*puVar3) {
    return 2;
  }
  if (pcVar4 != (char *)0x0) {
    if (*(long *)(pcVar4 + 0x70508) == 0) {
      return 3;
    }
    iVar1 = *(int *)(*(long *)(pcVar4 + 0x70508) + 0xb0);
    if (iVar1 == 0) {
      return 3;
    }
    if (((*pcVar4 != '\x01') && (*(long *)(pcVar4 + 0x20) == 0)) || (*(char *)(puVar2 + 2) != '\0'))
    {
      if (iVar1 == 1) {
        puVar9 = &DAT_00369f40;
      }
      else if (iVar1 == 2) {
        puVar9 = &DAT_00356700;
      }
      else if (iVar1 == 3) {
        puVar9 = &DAT_00342ec0;
      }
      else {
        if (iVar1 != 4) {
          return 3;
        }
        puVar9 = &DAT_0032f680;
      }
      goto LAB_0012cb17;
    }
    if (iVar1 != 1) {
      if (iVar1 == 2) {
        puVar9 = &DAT_00360320;
      }
      else if (iVar1 == 3) {
        puVar9 = &DAT_0034cae0;
      }
      else {
        if (iVar1 != 4) {
          return 3;
        }
        puVar9 = &DAT_003392a0;
      }
      goto LAB_0012cb17;
    }
  }
  puVar9 = &DAT_00373b60;
LAB_0012cb17:
  uVar8 = 0;
  do {
    while (uVar6 = (ulong)uVar8, 0x14b < param_1[uVar6 * 10 + 6] - 1U) {
      param_1[uVar6 * 10 + 7] = 2;
      uVar8 = uVar8 + 1;
      if ((uint)param_1[1] <= uVar8) {
        return 0;
      }
    }
    FUN_00129850(param_1 + uVar6 * 10 + 6,puVar9,puVar2,puVar3);
    uVar8 = uVar8 + 1;
  } while (uVar8 < (uint)param_1[1]);
  return 0;
}


// ===== 0012cbd0 FUN_0012cbd0 =====

undefined8 FUN_0012cbd0(char *param_1,int *param_2)

{
  undefined1 auVar1 [16];
  int iVar2;
  undefined8 uVar3;
  undefined1 local_48 [8];
  ulong uStack_40;
  int local_38;
  
  if (param_2 == (int *)0x0) {
    return 2;
  }
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if (*param_1 != '\x01') {
    if (((*(int *)(param_1 + 0x14) == 0) || (*(int *)(param_1 + 0x1c) != 0)) ||
       (*(int *)(param_1 + 0x10) == 0)) {
      if (*(long *)(param_1 + 0x20) != 0) {
        return 2;
      }
    }
    else if (*(long *)(param_1 + 0x20) != 0) goto LAB_0012cc28;
    auVar1._8_8_ = 0;
    auVar1._0_8_ = uStack_40;
    _local_48 = auVar1 << 0x40;
    iVar2 = FUN_001384c0(param_1,local_48);
    if (iVar2 == 0) {
      param_1 = *(char **)((long)local_48 + 0x98);
    }
  }
LAB_0012cc28:
  uVar3 = 0x19;
  if (*param_2 == 1) {
    local_38 = 0;
    stack0xffffffffffffffbc = SUB1612((undefined1  [16])0x0,4);
    local_48._0_4_ = 0x1000014;
    iVar2 = FUN_001730a0(local_48);
    if (((iVar2 == 3) || (((iVar2 == 0 && ((int)uStack_40 != 1)) && (local_38 != 1)))) &&
       ((uVar3 = FUN_0012bd20(param_1,local_48), (int)uVar3 == 0 && (local_48._0_4_ != 0)))) {
      param_2[1] = 1;
      return uVar3;
    }
    param_2[1] = 0;
    uVar3 = 0;
  }
  return uVar3;
}


// ===== 0012ccf0 FUN_0012ccf0 =====

undefined8 FUN_0012ccf0(char *param_1)

{
  long lVar1;
  code *pcVar2;
  long *plVar3;
  undefined8 uVar4;
  undefined2 local_23;
  undefined1 local_21;
  undefined8 local_20;
  
  local_23 = 0;
  local_21 = 0;
  FUN_00292de0("__NVML_GPM_SIMULATOR",&local_23,3);
  if ((char)local_23 == '1') {
    plVar3 = *(long **)(param_1 + 0x70508);
    if (plVar3 == (long *)0x0) {
      return 1;
    }
    if ((int)plVar3[1] == 0) {
      uVar4 = 0;
      if (*plVar3 == 0) {
        uVar4 = FUN_0012c590(param_1);
      }
    }
    else {
      uVar4 = 5;
    }
  }
  else {
    local_20 = 1;
    FUN_0012cbd0(param_1,&local_20);
    uVar4 = 3;
    if (local_20._4_4_ != 0) {
      lVar1 = *(long *)(param_1 + 0x70508);
      if (lVar1 == 0) {
        return 1;
      }
      uVar4 = 5;
      if (*(int *)(lVar1 + 8) == 0) {
        if ((*param_1 == '\x01') || (*(long *)(param_1 + 0x20) != 0)) {
          if ((DAT_012164a0 == 0) ||
             ((*(undefined8 **)(DAT_012164a0 + 0x100) == (undefined8 *)0x0 ||
              (pcVar2 = (code *)**(undefined8 **)(DAT_012164a0 + 0x100), pcVar2 == (code *)0x0)))) {
            return 3;
          }
          uVar4 = (*pcVar2)(DAT_012164a0,param_1);
        }
        else {
          uVar4 = FUN_00137cd0(param_1,lVar1 + 0x10);
        }
        if ((int)uVar4 == 0) {
          *(undefined4 *)(lVar1 + 8) = 1;
        }
      }
    }
  }
  return uVar4;
}


// ===== 0012ce30 FUN_0012ce30 =====

undefined8 FUN_0012ce30(char *param_1,undefined8 *param_2)

{
  undefined8 *__dest;
  void *__src;
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  ulong __n;
  ulong uVar5;
  int iVar6;
  undefined8 *puVar7;
  long *plVar8;
  float fVar9;
  ulong local_68;
  ulong local_60;
  long *local_50;
  long *local_40;
  
  __dest = param_2 + 0x15;
  param_2[2] = 0;
  param_2[0x13] = 0;
  puVar7 = (undefined8 *)((ulong)(param_2 + 3) & 0xfffffffffffffff8);
  for (uVar4 = (ulong)(((int)param_2 -
                       (int)(undefined8 *)((ulong)(param_2 + 3) & 0xfffffffffffffff8)) + 0xa0U >> 3)
      ; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  uVar1 = FUN_0012c050(param_1);
  if (((int)uVar1 != 0) && ((int)uVar1 != 5)) {
    return uVar1;
  }
  uVar1 = FUN_0012ccf0(param_1);
  if (((int)uVar1 != 0) && ((int)uVar1 != 5)) {
    return uVar1;
  }
  lVar3 = *(long *)(param_1 + 0x70508);
  uVar4 = *(ulong *)(lVar3 + 0x10);
  if (*(int *)(lVar3 + 0xb0) != 1) {
    if ((*param_1 == '\x01') || (*(long *)(param_1 + 0x20) != 0)) {
      local_60 = uVar4 - 0x880;
    }
    else {
      local_60 = uVar4 - 0x438;
    }
    if (0x8010 < local_60) {
LAB_0012d0e8:
      if (1 < DAT_01216a78) {
        fVar9 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%zu %zu\n",
                     "ERROR",lVar3,"nvml_gpm.c",0x47e,local_60,0x8010);
      }
      FUN_00128790(param_1);
      return 0x17;
    }
    local_40 = *(long **)(lVar3 + 0x18);
    plVar8 = (long *)((long)local_40 + (uVar4 & 0xfffffffffffffff8) + 8);
    __n = local_60 >> 1;
    local_50 = (long *)((long)param_2 + (local_60 & 0xfffffffffffffff8) + 0xa0);
    uVar5 = __n & 0xfffffffffffffff8;
    local_68 = __n + 0x448 & 0xfffffffffffffff8;
    goto LAB_0012cf3b;
  }
  if (*param_1 == '\x01') {
    local_60 = uVar4 + 0x10;
    if (0x8010 < local_60) goto LAB_0012d0e8;
    local_40 = *(long **)(lVar3 + 0x18);
    lVar2 = (uVar4 & 0xfffffffffffffff8) + 8;
    __n = local_60 >> 1;
    plVar8 = (long *)((long)local_40 + lVar2);
    local_68 = __n + 0x448 & 0xfffffffffffffff8;
    uVar5 = __n & 0xfffffffffffffff8;
LAB_0012d0d6:
    local_60 = uVar4 + 0x10;
    local_50 = (long *)(lVar2 + (long)__dest);
  }
  else {
    if (*(long *)(param_1 + 0x20) == 0) {
      local_40 = *(long **)(lVar3 + 0x18);
      uVar5 = 0x408;
      __n = 0x408;
      local_68 = 0x850;
      local_60 = 0x810;
    }
    else {
      local_60 = uVar4 + 0x10;
      if (0x8010 < local_60) goto LAB_0012d0e8;
      local_40 = *(long **)(lVar3 + 0x18);
      lVar2 = (uVar4 & 0xfffffffffffffff8) + 8;
      __n = local_60 >> 1;
      plVar8 = (long *)((long)local_40 + lVar2);
      local_68 = __n + 0x448 & 0xfffffffffffffff8;
      uVar5 = __n & 0xfffffffffffffff8;
      if (*(long *)(param_1 + 0x20) != 0) goto LAB_0012d0d6;
    }
    local_50 = param_2 + 0x116;
    plVar8 = local_40 + 0x101;
  }
LAB_0012cf3b:
  *(int *)(param_2 + 0x1017) = (int)plVar8[1];
  iVar6 = 10;
  do {
    while (*local_40 == *plVar8) {
      __src = *(void **)(lVar3 + 0x18);
      if (*(int *)(lVar3 + 0xb0) == 1) {
        memcpy(__dest,__src,local_60);
      }
      else if ((*param_1 == '\x01') || (*(long *)(param_1 + 0x20) != 0)) {
        memcpy(__dest,__src,__n);
        memcpy((void *)((long)__dest + uVar5),(void *)(local_68 + *(long *)(lVar3 + 0x18)),__n);
        *(long *)((long)param_2 + (local_60 & 0xfffffffffffffff8) + 0xa0) = *plVar8;
      }
      else {
        memcpy(__dest,__src,local_60 - 8);
        *(long *)((long)__dest + (local_60 - 8 & 0xfffffffffffffff8)) = *plVar8;
      }
      if (param_2[0x15] == *local_50) {
        param_2[1] = param_2[0x15];
        param_2[0x14] = param_2 + 0x16;
        *param_2 = param_1;
        FUN_00128790(param_1);
        return 0;
      }
      iVar6 = iVar6 + -1;
      if (iVar6 == 0) goto LAB_0012d013;
    }
    FUN_00292f00(1);
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
LAB_0012d013:
  FUN_00128790(param_1);
  return 10;
}


// ===== 0012d250 FUN_0012d250 =====

int FUN_0012d250(long param_1,int param_2,long *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  long lVar7;
  ulong uVar8;
  undefined8 uVar9;
  uint uVar10;
  float fVar12;
  undefined8 uVar13;
  uint local_48;
  int local_44;
  long local_40 [2];
  ulong uVar11;
  
  if ((param_1 == 0) || (param_3 == (long *)0x0)) {
LAB_0012d640:
    iVar3 = 2;
  }
  else {
    iVar3 = FUN_00128810();
    if (iVar3 == 4) {
      if (DAT_01216a78 < 2) {
        return 4;
      }
      fVar12 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      FUN_002340f0((double)(fVar12 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",
                   lVar5,"nvml_gpm.c",0x527);
    }
    else if (iVar3 == 0) {
      lVar5 = *(long *)(param_1 + 0x70508);
      if (lVar5 == 0) {
        if (DAT_01216a78 < 2) {
          return 0;
        }
        fVar12 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        FUN_002340f0((double)(fVar12 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR"
                     ,lVar5,"nvml_gpm.c",0x532);
        return 0;
      }
      iVar3 = FUN_0012bd20(param_1);
      if (iVar3 != 0) {
        if (DAT_01216a78 < 2) {
          return iVar3;
        }
        fVar12 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        fVar12 = fVar12 * DAT_00298548;
        uVar13 = 0x537;
        uVar9 = 0x537;
LAB_0012d6a5:
        FUN_002340f0((double)fVar12,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar5,
                     "nvml_gpm.c",uVar9,"gpmMigSampleGet",uVar13,iVar3);
        return iVar3;
      }
      if (*(int *)(lVar5 + 0xb0) == 0) {
        return 3;
      }
      if (((*param_3 == param_1) && ((char)param_3[2] != '\0')) &&
         (*(int *)((long)param_3 + 0x14) == param_2)) {
LAB_0012d3ba:
        if ((int)param_3[3] != 0) {
          iVar3 = FUN_0012c010(local_40);
          param_3[1] = 0;
          param_3[0x14] = (long)(param_3 + 0x16);
          memset(param_3 + 0x15,0,0x8010);
          if ((int)param_3[3] != 0) {
            uVar11 = 0;
            do {
              iVar3 = FUN_0012ce30(param_3[uVar11 * 2 + 5],local_40[0]);
              if ((iVar3 != 0) ||
                 (uVar10 = *(uint *)((long)param_3 + uVar11 * 0x10 + 0x24), 7 < uVar10)) break;
              uVar2 = *(uint *)(lVar5 + 0xb0);
              lVar4 = 0xb0;
              uVar6 = 0xffffff90;
              uVar8 = (ulong)*(uint *)(lVar5 + 100 + (ulong)uVar10 * 4);
              do {
                lVar7 = *(long *)(local_40[0] + lVar4);
                if (uVar2 == 3) goto LAB_0012d477;
                if (3 < uVar2) goto LAB_0012d499;
LAB_0012d465:
                if (uVar2 != 1) {
                  if (uVar2 == 2) {
LAB_0012d477:
                    while ((uVar6 & 0xffffffbf) == 0) {
                      while( true ) {
                        *(long *)((long)param_3 + lVar4) =
                             *(long *)((long)param_3 + lVar4) + lVar7 * uVar8;
                        lVar4 = lVar4 + 8;
                        uVar6 = uVar6 + 1;
                        lVar7 = *(long *)(local_40[0] + lVar4);
                        if (uVar2 == 3) break;
                        if (uVar2 < 4) goto LAB_0012d465;
LAB_0012d499:
                        if (uVar2 != 4) goto LAB_0012d760;
                        if ((uVar6 & 0xffffffef) != 0) goto LAB_0012d4aa;
                      }
                    }
                    goto LAB_0012d4aa;
                  }
LAB_0012d760:
                  iVar3 = 3;
                  goto LAB_0012d4d8;
                }
                if ((uVar6 + 0x20 & 0xffffffbf) == 0) {
                  lVar7 = lVar7 * uVar8;
                }
LAB_0012d4aa:
                uVar6 = uVar6 + 1;
                *(long *)((long)param_3 + lVar4) = *(long *)((long)param_3 + lVar4) + lVar7;
                lVar4 = lVar4 + 8;
              } while (uVar6 != 0xf91);
              uVar10 = (int)uVar11 + 1;
              uVar11 = (ulong)uVar10;
              param_3[1] = param_3[1] + *(long *)(local_40[0] + 8);
            } while (uVar10 < *(uint *)(param_3 + 3));
          }
LAB_0012d4d8:
          FUN_0012c040(local_40[0]);
          return iVar3;
        }
      }
      else {
        local_48 = 0;
        iVar3 = FUN_0016dc70(param_1,&local_48);
        if (iVar3 != 0) {
          if (DAT_01216a78 < 2) {
            return iVar3;
          }
          fVar12 = (float)FUN_002917b0(&DAT_01216a60);
          lVar5 = syscall(0xba);
          fVar12 = fVar12 * DAT_00298548;
          uVar13 = 0x543;
          uVar9 = 0x543;
          goto LAB_0012d6a5;
        }
        if (8 < local_48) {
          return 7;
        }
        *param_3 = param_1;
        *(undefined1 *)(param_3 + 2) = 1;
        *(int *)((long)param_3 + 0x14) = param_2;
        *(undefined4 *)(param_3 + 3) = 0;
        if (local_48 != 0) {
          uVar11 = 0;
          do {
            iVar3 = FUN_0016de90(param_1,uVar11,local_40);
            if (iVar3 == 0) {
              local_44 = 0;
              iVar3 = FUN_0016d830(local_40[0]);
              if ((iVar3 == 0) && (local_44 == param_2)) {
                uVar10 = *(uint *)(param_3 + 3);
                param_3[(ulong)uVar10 * 2 + 5] = local_40[0];
                *(int *)((long)param_3 + (ulong)uVar10 * 0x10 + 0x24) = (int)uVar11;
                *(undefined4 *)(param_3 + (ulong)uVar10 * 2 + 4) =
                     *(undefined4 *)(lVar5 + 100 + uVar11 * 4);
                uVar1 = *(undefined4 *)(lVar5 + 0x84 + uVar11 * 4);
                *(uint *)(param_3 + 3) = uVar10 + 1;
                *(undefined4 *)((long)param_3 + 0x1c) = uVar1;
              }
            }
            uVar10 = (int)uVar11 + 1;
            uVar11 = (ulong)uVar10;
          } while (uVar10 < local_48);
          goto LAB_0012d3ba;
        }
      }
      if (2 < DAT_01216a78) {
        fVar12 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        FUN_002340f0((double)(fVar12 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %p\n",
                     "WARNING",lVar5,"nvml_gpm.c",0x56b,param_2,param_1);
      }
      goto LAB_0012d640;
    }
    if (1 < DAT_01216a78) {
      uVar9 = nvmlErrorString(iVar3);
      fVar12 = (float)FUN_002917b0(&DAT_01216a60);
      lVar5 = syscall(0xba);
      FUN_002340f0((double)(fVar12 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n","ERROR"
                   ,lVar5,"nvml_gpm.c",0x52b,uVar9);
    }
  }
  return iVar3;
}


// ===== 0012d810 FUN_0012d810 =====

void FUN_0012d810(long param_1)

{
  long *__ptr;
  long lVar1;
  
  __ptr = *(long **)(param_1 + 0x70508);
  if (__ptr != (long *)0x0) {
    if ((int)__ptr[1] == 2) {
      lVar1 = *__ptr;
      *(undefined1 *)(lVar1 + 0x18) = 0;
      FUN_002933f0(*(undefined8 *)(lVar1 + 0x10),0);
      free((void *)__ptr[3]);
    }
    else if ((int)__ptr[1] == 1) {
      FUN_00128790();
    }
    free(__ptr);
    *(undefined8 *)(param_1 + 0x70508) = 0;
  }
  return;
}


// ===== 0012d880 FUN_0012d880 =====

void FUN_0012d880(void)

{
  int iVar1;
  uint uVar2;
  uint local_24;
  undefined8 local_20;
  
  iVar1 = FUN_001904e0(&local_24);
  if ((iVar1 == 0) && (uVar2 = 0, local_24 != 0)) {
    do {
      iVar1 = FUN_00190770(uVar2,&local_20);
      if (iVar1 == 0) {
        FUN_0012d810(local_20);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < local_24);
  }
  return;
}


// ===== 0012d8d0 FUN_0012d8d0 =====

ulong FUN_0012d8d0(char *param_1,long *param_2)

{
  long *plVar1;
  long *plVar2;
  undefined8 *puVar3;
  long *plVar4;
  long *plVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  undefined8 *puVar9;
  uint uVar10;
  undefined8 *puVar11;
  ulong uVar12;
  int iVar13;
  byte bVar14;
  uint local_50;
  
  bVar14 = 0;
  uVar6 = FUN_0012c050();
  if (((int)uVar6 == 0) || ((int)uVar6 == 5)) {
    lVar7 = *(long *)(param_1 + 0x70508);
    if (lVar7 == 0) {
      return 2;
    }
    uVar6 = FUN_0012ccf0(param_1);
    if (((int)uVar6 == 0) || ((int)uVar6 == 5)) {
      uVar10 = *(uint *)(lVar7 + 0xb0);
      if (uVar10 < 2) {
        uVar6 = 3;
      }
      else {
        if ((param_2[1] != 0) && ((int)param_2[2] == 0)) {
          return 2;
        }
        if (uVar10 == 2) {
          local_50 = 0x108;
          uVar6 = 0x1e0;
          uVar12 = 0x380;
        }
        else if (uVar10 == 3) {
          local_50 = 0x118;
          uVar6 = 8;
          uVar12 = 0x128;
        }
        else {
          if (uVar10 != 4) {
            return 2;
          }
          local_50 = 0x180;
          uVar6 = 0x440;
          uVar12 = 0x3f0;
        }
        if ((*param_1 == '\x01') || (uVar10 = local_50, *(long *)(param_1 + 0x20) != 0)) {
          uVar10 = (int)uVar12 + (int)uVar6;
        }
        if ((param_2[1] != 0) && (uVar10 >> 3 <= *(uint *)(param_2 + 2))) {
          plVar4 = *(long **)(lVar7 + 0x18);
          iVar13 = 10;
          plVar2 = (long *)((long)plVar4 + (*(ulong *)(lVar7 + 0x10) & 0xfffffffffffffff8) + 8);
          puVar3 = (undefined8 *)
                   ((long)plVar4 +
                   ((*(ulong *)(lVar7 + 0x10) >> 1) + 0x4000 & 0xfffffffffffffff8) + 0x10);
          plVar1 = plVar4 + 0x802;
          do {
            while (*plVar4 == *plVar2) {
              plVar5 = (long *)param_2[1];
              if ((*param_1 == '\x01') || (*(long *)(param_1 + 0x20) != 0)) {
                *plVar5 = *plVar1;
                *(undefined8 *)((long)plVar5 + (uVar12 - 8)) =
                     *(undefined8 *)((long)plVar4 + uVar12 + 0x4008);
                lVar7 = (long)plVar5 - (long)((ulong)(plVar5 + 1) & 0xfffffffffffffff8);
                puVar11 = (undefined8 *)((long)plVar1 - lVar7);
                puVar9 = (undefined8 *)((ulong)(plVar5 + 1) & 0xfffffffffffffff8);
                for (uVar8 = (ulong)((uint)((int)lVar7 + (int)uVar12) >> 3); uVar8 != 0;
                    uVar8 = uVar8 - 1) {
                  *puVar9 = *puVar11;
                  puVar11 = puVar11 + (ulong)bVar14 * -2 + 1;
                  puVar9 = puVar9 + (ulong)bVar14 * -2 + 1;
                }
                puVar9 = (undefined8 *)(param_2[1] + (uVar12 >> 3) * 8);
                *puVar9 = *puVar3;
                *(undefined8 *)((long)puVar9 + (uVar6 - 8)) =
                     *(undefined8 *)((long)puVar3 + (uVar6 - 8));
                lVar7 = (long)puVar9 - (long)((ulong)(puVar9 + 1) & 0xfffffffffffffff8);
                puVar11 = (undefined8 *)((long)puVar3 - lVar7);
                puVar9 = (undefined8 *)((ulong)(puVar9 + 1) & 0xfffffffffffffff8);
                for (uVar8 = (ulong)((uint)((int)lVar7 + (int)uVar6) >> 3);
                    uVar10 = (int)(uVar6 >> 3) + (int)(uVar12 >> 3), uVar8 != 0; uVar8 = uVar8 - 1)
                {
                  *puVar9 = *puVar11;
                  puVar11 = puVar11 + (ulong)bVar14 * -2 + 1;
                  puVar9 = puVar9 + (ulong)bVar14 * -2 + 1;
                }
              }
              else {
                *plVar5 = *plVar1;
                *(undefined8 *)((long)plVar5 + ((ulong)local_50 - 8)) =
                     *(undefined8 *)((long)plVar4 + (ulong)local_50 + 0x4008);
                lVar7 = (long)plVar5 - (long)((ulong)(plVar5 + 1) & 0xfffffffffffffff8);
                puVar11 = (undefined8 *)((long)plVar1 - lVar7);
                puVar9 = (undefined8 *)((ulong)(plVar5 + 1) & 0xfffffffffffffff8);
                for (uVar8 = (ulong)((int)lVar7 + local_50 >> 3); uVar10 = local_50 >> 3, uVar8 != 0
                    ; uVar8 = uVar8 - 1) {
                  *puVar9 = *puVar11;
                  puVar11 = puVar11 + (ulong)bVar14 * -2 + 1;
                  puVar9 = puVar9 + (ulong)bVar14 * -2 + 1;
                }
              }
              if (*plVar4 == *plVar2) {
                *param_2 = *plVar4;
                *(uint *)(param_2 + 2) = uVar10;
                uVar10 = 0;
                goto LAB_0012daf8;
              }
              iVar13 = iVar13 + -1;
              if (iVar13 == 0) goto LAB_0012daf0;
            }
            FUN_00292f00(1);
            iVar13 = iVar13 + -1;
          } while (iVar13 != 0);
LAB_0012daf0:
          uVar10 = 10;
LAB_0012daf8:
          FUN_00128790(param_1);
          return (ulong)uVar10;
        }
        *(uint *)(param_2 + 2) = uVar10 >> 3;
        uVar6 = 7;
      }
    }
  }
  return uVar6;
}


// ===== 0012dbf0 FUN_0012dbf0 =====

undefined8 FUN_0012dbf0(ulong param_1)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  lVar1 = DAT_012164c0;
  while( true ) {
    uVar2 = FUN_00291820(&DAT_003807c0,1,0);
    if ((int)uVar2 == 0) {
      return uVar2;
    }
    if (param_1 == 0) break;
    uVar3 = (**(code **)(lVar1 + 0x88))();
    if (param_1 <= uVar3) {
      return 600;
    }
  }
  if ((int)uVar2 != 0) {
    return 600;
  }
  return uVar2;
}


// ===== 0012dc60 FUN_0012dc60 =====

undefined4 FUN_0012dc60(long param_1)

{
  long *plVar1;
  undefined1 uVar2;
  char cVar3;
  char cVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  code *pcVar7;
  uint uVar8;
  int iVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  undefined8 extraout_RDX;
  long *plVar13;
  undefined1 *__s;
  uint uVar14;
  float fVar15;
  double dVar16;
  undefined8 uVar17;
  float local_74;
  undefined4 local_50;
  undefined8 local_4c;
  undefined4 local_44;
  undefined8 local_40;
  
  lVar12 = DAT_012164a0;
  local_50 = 0;
  if (param_1 != 0) {
    iVar9 = (**(code **)(*(long *)(DAT_012164a0 + 0x10) + 8))(&DAT_0038088c);
    if (iVar9 != 0) {
      if (DAT_01216a78 < 2) {
        return 999;
      }
      fVar15 = (float)FUN_002917b0(&DAT_01216a60);
      lVar12 = syscall(0xba);
      FUN_002340f0((double)(fVar15 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n","ERROR"
                   ,lVar12,"nvml_checkpoint.c",0x159,iVar9);
      return 999;
    }
    if (DAT_003807dc == '\0') {
      if (4 < DAT_01216a78) {
        fVar15 = (float)FUN_002917b0(&DAT_01216a60);
        lVar10 = syscall(0xba);
        FUN_002340f0((double)(fVar15 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG"
                     ,lVar10,"nvml_checkpoint.c",0x167);
      }
    }
    else {
      iVar9 = FUN_00249540(0);
      if (iVar9 != 0) {
        if (1 < DAT_01216a78) {
          fVar15 = (float)FUN_002917b0(&DAT_01216a60);
          lVar12 = syscall(0xba);
          FUN_002340f0((double)(fVar15 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n",
                       "ERROR",lVar12,"nvml_checkpoint.c",0x16e,iVar9);
          return 0x130;
        }
        return 0x130;
      }
    }
    uVar8 = DAT_01214898;
    uVar14 = *(uint *)(param_1 + 8);
    if (DAT_01214898 <= uVar14) {
      if (DAT_01214898 != 0) {
        __s = &DAT_00380898;
        uVar14 = 0;
        do {
          if ((((&DAT_003808ac)[(ulong)uVar14 * 0x1d280] == 0) || (*(int *)(__s + 0x1c) != 0)) ||
             (*(int *)(__s + 0x10) == 0)) {
            if (1 < DAT_01216a78) {
              fVar15 = (float)FUN_002917b0(&DAT_01216a60);
              lVar10 = syscall(0xba);
              FUN_002340f0((double)(fVar15 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n"
                           ,"ERROR",lVar10,"nvml_checkpoint.c",0x20c,uVar14);
            }
            goto LAB_0012dea0;
          }
          if (*(int *)(param_1 + 8) < 1) {
LAB_0012df38:
            if (DAT_01216a78 < 2) {
              return 999;
            }
            fVar15 = (float)FUN_002917b0(&DAT_01216a60);
            lVar12 = syscall(0xba);
            FUN_002340f0((double)(fVar15 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n",
                         "ERROR",lVar12,"nvml_checkpoint.c",0x214,__s + 0x380);
            return 999;
          }
          plVar13 = *(long **)(param_1 + 0x10);
          plVar1 = plVar13 + (ulong)(*(int *)(param_1 + 8) - 1) * 4 + 4;
          while (plVar13[1] != *(long *)(__s + 0x388) || *plVar13 != *(long *)(__s + 0x380)) {
            plVar13 = plVar13 + 4;
            if (plVar13 == plVar1) goto LAB_0012df38;
          }
          if (4 < DAT_01216a78) {
            lVar10 = plVar13[3];
            fVar15 = (float)FUN_002917b0(&DAT_01216a60);
            lVar11 = syscall(0xba);
            FUN_002340f0((double)(fVar15 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %x\n","DEBUG",lVar11,
                         "nvml_checkpoint.c",0x219,uVar14,(int)lVar10);
          }
          lVar10 = plVar13[3];
          uVar2 = *__s;
          uVar17 = *(undefined8 *)(__s + 0x256d8);
          local_40 = 0;
          uVar6 = *(undefined8 *)(lVar12 + 0x10);
          uVar5 = *(undefined4 *)(__s + 0x25d58);
          cVar3 = __s[0x70550];
          local_4c = *(undefined8 *)(__s + 0x70554);
          cVar4 = __s[0x70500];
          memset(__s,0,0x74a00);
          *(uint *)(__s + 4) = uVar14;
          *(int *)(__s + 0x256e0) = (int)lVar10;
          *(undefined8 *)(__s + 0x256d8) = uVar17;
          *(undefined4 *)(__s + 0x25d58) = uVar5;
          *__s = uVar2;
          uVar17 = 0;
          local_44 = (int)lVar10;
          iVar9 = FUN_0019c780(uVar6,DAT_0038088c,DAT_0038088c,0x21b,&local_44,0xc);
          if (iVar9 != 0) {
            if (DAT_01216a78 < 2) {
              return 999;
            }
            fVar15 = (float)FUN_002917b0(&DAT_01216a60,0x12dda3,extraout_RDX,uVar17);
            lVar12 = syscall(0xba);
            local_74 = DAT_00298548;
            FUN_002340f0((double)(fVar15 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n",
                         "ERROR",lVar12,"nvml_checkpoint.c",0x1b1,iVar9);
            goto LAB_0012e0fb;
          }
          *(undefined4 *)(__s + 8) = (undefined4)local_40;
          *(undefined2 *)(__s + 0xc) = local_40._4_2_;
          *(undefined2 *)(__s + 0xe) = local_40._6_2_;
          iVar9 = FUN_0019fc20(lVar12,__s);
          if (iVar9 != 0) {
            if (DAT_01216a78 < 2) {
              return 999;
            }
            fVar15 = (float)FUN_002917b0(&DAT_01216a60);
            lVar12 = syscall(0xba);
            uVar17 = 0x1c1;
            local_74 = DAT_00298548;
            dVar16 = (double)(fVar15 * DAT_00298548);
LAB_0012e2b8:
            DAT_00298548 = local_74;
            FUN_002340f0(dVar16,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","ERROR",lVar12,
                         "nvml_checkpoint.c",uVar17,iVar9);
LAB_0012e0fb:
            if (DAT_01216a78 < 2) {
              return 999;
            }
            lVar12 = plVar13[3];
            fVar15 = (float)FUN_002917b0(&DAT_01216a60);
            lVar10 = syscall(0xba);
            FUN_002340f0((double)(fVar15 * local_74),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %d\n",
                         "ERROR",lVar10,"nvml_checkpoint.c",0x21f,uVar14,(int)lVar12);
            return 999;
          }
          if (cVar3 != '\0') {
            lVar10 = *(long *)(__s + 0x256d8);
            if (((lVar10 == 0) || (*(undefined8 **)(lVar10 + 0x180) == (undefined8 *)0x0)) ||
               (pcVar7 = (code *)**(undefined8 **)(lVar10 + 0x180), pcVar7 == (code *)0x0)) {
              iVar9 = 3;
            }
            else {
              iVar9 = (*pcVar7)(lVar10,__s,&local_4c);
              if (iVar9 == 0) {
                __s[0x70550] = 0;
                goto LAB_0012de91;
              }
            }
            if (DAT_01216a78 < 2) {
              return 999;
            }
            fVar15 = (float)FUN_002917b0(&DAT_01216a60);
            lVar12 = syscall(0xba);
            uVar17 = 0x1cc;
            local_74 = DAT_00298548;
            dVar16 = (double)(fVar15 * DAT_00298548);
            goto LAB_0012e2b8;
          }
LAB_0012de91:
          if (cVar4 != '\0') {
            iVar9 = FUN_0012c050(__s);
            if (iVar9 != 0) {
              if (DAT_01216a78 < 2) {
                return 999;
              }
              fVar15 = (float)FUN_002917b0(&DAT_01216a60);
              lVar12 = syscall(0xba);
              local_74 = DAT_00298548;
              uVar17 = 0x1d9;
              dVar16 = (double)(fVar15 * DAT_00298548);
              goto LAB_0012e2b8;
            }
            __s[0x70500] = 0;
          }
LAB_0012dea0:
          uVar14 = uVar14 + 1;
          __s = __s + 0x74a00;
        } while (uVar14 < DAT_01214898);
      }
      if ((((DAT_012164a0 != 0) &&
           ((((*(long *)(DAT_012164a0 + 0x20) == 0 ||
              (pcVar7 = *(code **)(*(long *)(DAT_012164a0 + 0x20) + 0x80), pcVar7 == (code *)0x0))
             || ((*pcVar7)(DAT_012164a0,&local_50), DAT_012164a0 != 0)) &&
            (((*(long *)(DAT_012164a0 + 0x30) == 0 ||
              (pcVar7 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0xb8), pcVar7 == (code *)0x0))
             || ((*pcVar7)(DAT_012164a0,DAT_0038088c,local_50), DAT_012164a0 != 0)))))) &&
          (((*(long *)(DAT_012164a0 + 0x20) == 0 ||
            (pcVar7 = *(code **)(*(long *)(DAT_012164a0 + 0x20) + 0x80), pcVar7 == (code *)0x0)) ||
           ((*pcVar7)(DAT_012164a0,&local_50), DAT_012164a0 != 0)))) &&
         ((*(long *)(DAT_012164a0 + 0x30) != 0 &&
          (pcVar7 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0xc0), pcVar7 != (code *)0x0)))) {
        (*pcVar7)(DAT_012164a0,DAT_0038088c,local_50);
      }
      FUN_001a23c0(lVar12);
      FUN_001353b0();
      return 0;
    }
    if (1 < DAT_01216a78) {
      fVar15 = (float)FUN_002917b0(&DAT_01216a60);
      lVar12 = syscall(0xba);
      FUN_002340f0((double)(fVar15 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x %x\n",
                   "ERROR",lVar12,"nvml_checkpoint.c",0x200,uVar14,uVar8);
    }
  }
  return 1;
}


// ===== 0012e5f0 FUN_0012e5f0 =====

undefined4 FUN_0012e5f0(void)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  char *pcVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  uint uVar8;
  float fVar9;
  double dVar10;
  int local_40;
  int local_3c [3];
  
  lVar4 = DAT_012164a0;
  if (DAT_01214898 != 0) {
    pcVar5 = &DAT_00380898;
    uVar8 = 0;
    do {
      if ((*pcVar5 == '\x01') ||
         (((((&DAT_003808ac)[(ulong)uVar8 * 0x1d280] != 0 && (*(int *)(pcVar5 + 0x1c) == 0)) &&
           (*(int *)(pcVar5 + 0x10) != 0)) && (*(long *)(pcVar5 + 0x20) != 0)))) {
        if ((*(long *)(pcVar5 + 0x70508) != 0) &&
           (*(char *)(*(long *)(pcVar5 + 0x70508) + 0xa8) != '\0')) {
          if (4 < DAT_01216a78) {
            fVar9 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                         "DEBUG",lVar3,"nvml_checkpoint.c",0xbf);
          }
          pcVar5[0x70500] = '\x01';
          FUN_0012d810(pcVar5);
        }
        if (*(long *)(pcVar5 + 0x70560) != 0) {
          lVar3 = *(long *)(pcVar5 + 0x256d8);
          pcVar5[0x70550] = '\x01';
          if (((lVar3 == 0) || (*(long *)(lVar3 + 0x180) == 0)) ||
             (pcVar1 = *(code **)(*(long *)(lVar3 + 0x180) + 8), pcVar1 == (code *)0x0)) {
            iVar2 = 3;
          }
          else {
            iVar2 = (*pcVar1)(lVar3,pcVar5);
            if (iVar2 == 0) {
              if (4 < DAT_01216a78) {
                fVar9 = (float)FUN_002917b0(&DAT_01216a60);
                lVar3 = syscall(0xba);
                FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                             "DEBUG",lVar3,"nvml_checkpoint.c",0xd2);
              }
              goto LAB_0012e6e3;
            }
          }
          if (1 < DAT_01216a78) {
            fVar9 = (float)FUN_002917b0(&DAT_01216a60);
            lVar4 = syscall(0xba);
            FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n",
                         "ERROR",lVar4,"nvml_checkpoint.c",0xcd,iVar2);
            if (1 < DAT_01216a78) {
              fVar9 = (float)FUN_002917b0(&DAT_01216a60);
              lVar4 = syscall(0xba);
              FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n",
                           "ERROR",lVar4,"nvml_checkpoint.c",0x13d,uVar8);
              return 999;
            }
          }
          goto LAB_0012e7f2;
        }
LAB_0012e6e3:
        FUN_001354b0(pcVar5,1);
        FUN_0019e770(lVar4,pcVar5);
        FUN_0019ea90(lVar4,pcVar5);
        if (*(void **)(pcVar5 + 0x153f8) != (void *)0x0) {
          free(*(void **)(pcVar5 + 0x153f8));
        }
        pcVar5[0x70508] = '\0';
        pcVar5[0x70509] = '\0';
        pcVar5[0x7050a] = '\0';
        pcVar5[0x7050b] = '\0';
        pcVar5[0x7050c] = '\0';
        pcVar5[0x7050d] = '\0';
        pcVar5[0x7050e] = '\0';
        pcVar5[0x7050f] = '\0';
        pcVar5[0x70560] = '\0';
        pcVar5[0x70561] = '\0';
        pcVar5[0x70562] = '\0';
        pcVar5[0x70563] = '\0';
        pcVar5[0x70564] = '\0';
        pcVar5[0x70565] = '\0';
        pcVar5[0x70566] = '\0';
        pcVar5[0x70567] = '\0';
        pcVar5[0x153f8] = '\0';
        pcVar5[0x153f9] = '\0';
        pcVar5[0x153fa] = '\0';
        pcVar5[0x153fb] = '\0';
        pcVar5[0x153fc] = '\0';
        pcVar5[0x153fd] = '\0';
        pcVar5[0x153fe] = '\0';
        pcVar5[0x153ff] = '\0';
      }
      else if (4 < DAT_01216a78) {
        fVar9 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n",
                     "DEBUG",lVar3,"nvml_checkpoint.c",0x136,uVar8);
      }
      uVar8 = uVar8 + 1;
      pcVar5 = pcVar5 + 0x74a00;
    } while (uVar8 < DAT_01214898);
  }
  if (DAT_003807dc == '\0') {
    if (4 < DAT_01216a78) {
      fVar9 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                   lVar3,"nvml_checkpoint.c",0xee);
    }
    goto LAB_0012ea18;
  }
  if (DAT_003807d8 == '\0') {
    if (1 < DAT_01216a78) {
      fVar9 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",
                   lVar4,"nvml_checkpoint.c",0xf4);
      return 0x130;
    }
LAB_0012e997:
    uVar7 = 0x130;
  }
  else {
    iVar2 = FUN_00249740(&local_40);
    if (iVar2 == 0) {
      iVar2 = dup2(DAT_003807d4,local_40);
      if (iVar2 != local_40) {
        if (1 < DAT_01216a78) {
          fVar9 = (float)FUN_002917b0(&DAT_01216a60);
          lVar4 = syscall(0xba);
          uVar6 = 0x101;
          fVar9 = fVar9 * DAT_00298548;
LAB_0012ec3e:
          FUN_002340f0((double)fVar9,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n","ERROR",lVar4,
                       "nvml_checkpoint.c",uVar6,local_40);
        }
        goto LAB_0012e997;
      }
      iVar2 = FUN_00249790(local_3c);
      if (iVar2 != 0x56) {
        if (iVar2 != 0) {
          if (1 < DAT_01216a78) {
            fVar9 = (float)FUN_002917b0(&DAT_01216a60);
            lVar4 = syscall(0xba);
            uVar6 = 0x10d;
            dVar10 = (double)(fVar9 * DAT_00298548);
            goto LAB_0012eacc;
          }
          goto LAB_0012e7f2;
        }
        iVar2 = dup2(DAT_003807d4,local_3c[0]);
        if (iVar2 != local_3c[0]) {
          if (1 < DAT_01216a78) {
            fVar9 = (float)FUN_002917b0(&DAT_01216a60);
            lVar4 = syscall(0xba);
            uVar6 = 0x113;
            fVar9 = fVar9 * DAT_00298548;
            local_40 = local_3c[0];
            goto LAB_0012ec3e;
          }
          goto LAB_0012e997;
        }
      }
LAB_0012ea18:
      iVar2 = (**(code **)(*(long *)(lVar4 + 0x10) + 0x28))(DAT_0038088c,0,DAT_0038088c);
      if (iVar2 == 0) {
        return 0;
      }
      if (1 < DAT_01216a78) {
        fVar9 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        uVar6 = 0x123;
        dVar10 = (double)(fVar9 * DAT_00298548);
        goto LAB_0012eacc;
      }
    }
    else if (1 < DAT_01216a78) {
      fVar9 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      uVar6 = 0xfb;
      dVar10 = (double)(fVar9 * DAT_00298548);
LAB_0012eacc:
      FUN_002340f0(dVar10,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%x\n","ERROR",lVar4,
                   "nvml_checkpoint.c",uVar6,iVar2);
    }
LAB_0012e7f2:
    uVar7 = 999;
  }
  return uVar7;
}


// ===== 0012ecf0 FUN_0012ecf0 =====

void FUN_0012ecf0(void)

{
  thunk_FUN_00293190(&DAT_003807c8);
  FUN_00291830(&DAT_003807c0,0);
  return;
}


// ===== 0012ed20 FUN_0012ed20 =====

int FUN_0012ed20(long param_1)

{
  ulong uVar1;
  long lVar2;
  int iVar3;
  ulong uVar4;
  
  uVar1 = *(ulong *)(param_1 + 8);
  iVar3 = FUN_0012dbf0(uVar1);
  lVar2 = DAT_012164c0;
  if (iVar3 == 0) {
    do {
      iVar3 = thunk_FUN_00293160(&DAT_003807c8);
      if (iVar3 == 0) {
        return 0;
      }
      if (uVar1 == 0) {
        if (iVar3 == 0) {
          return 0;
        }
        break;
      }
      uVar4 = (**(code **)(lVar2 + 0x88))();
    } while (uVar4 < uVar1);
    iVar3 = 600;
    FUN_00291830(&DAT_003807c0,0);
  }
  return iVar3;
}


// ===== 0012edd0 FUN_0012edd0 =====

void FUN_0012edd0(void)

{
  int iVar1;
  int local_1c;
  
  iVar1 = FUN_0012dbf0(0);
  if (iVar1 != 0) {
    return;
  }
  iVar1 = thunk_FUN_00293160(&DAT_003807c8);
  if (iVar1 == 0) {
    if (*(int *)(DAT_012164a0 + 8) == 0) {
      (**(code **)(*(long *)(DAT_012164a0 + 0x10) + 0x88))();
      local_1c = -1;
      iVar1 = FUN_00249740(&local_1c);
      if (iVar1 == 0) {
        close(local_1c);
        local_1c = -1;
        iVar1 = FUN_00249790(&local_1c);
        if (iVar1 == 0) {
          close(local_1c);
        }
      }
    }
    thunk_FUN_00293190(&DAT_003807c8);
  }
  FUN_00291830(&DAT_003807c0,0);
  return;
}


// ===== 0012ee90 FUN_0012ee90 =====

void FUN_0012ee90(void)

{
  ulong uVar1;
  int iVar2;
  long lVar3;
  code *pcVar4;
  char *pcVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  float fVar8;
  float local_3c;
  ulong *local_30 [2];
  
  lVar3 = FUN_00292ea0("libcuda.so.1");
  if (lVar3 == 0) {
    if (DAT_01216a78 < 5) {
      return;
    }
    fVar8 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    fVar8 = fVar8 * DAT_00298548;
    uVar6 = 0x273;
    pcVar5 = "DEBUG";
LAB_0012ef71:
    FUN_002340f0((double)fVar8,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",pcVar5,lVar3,
                 "nvml_checkpoint.c",uVar6);
    return;
  }
  DAT_003807e0 = lVar3;
  pcVar4 = (code *)dlsym(lVar3,"cuGetExportTable");
  if (pcVar4 == (code *)0x0) {
    if (DAT_01216a78 < 2) {
      return;
    }
    fVar8 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    uVar6 = 0x35;
    fVar8 = fVar8 * DAT_00298548;
  }
  else {
    iVar2 = (*pcVar4)(local_30,&DAT_0029ad60);
    if (iVar2 == 0) {
      uVar1 = *local_30[0];
      if (0x13f < uVar1) {
        DAT_012164c0 = local_30[0];
        if (DAT_003807d8 != '\0') {
          return;
        }
        DAT_003807d4 = eventfd(0,0x80000);
        if (-1 < DAT_003807d4) {
          DAT_003807d8 = 1;
          return;
        }
        if (DAT_01216a78 < 2) {
          return;
        }
        fVar8 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        fVar8 = fVar8 * DAT_00298548;
        uVar6 = 0x286;
        pcVar5 = "ERROR";
        goto LAB_0012ef71;
      }
      if (DAT_01216a78 < 2) {
        return;
      }
      fVar8 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      local_3c = DAT_00298548;
      uVar7 = 0x1d;
      FUN_002340f0((double)(fVar8 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%zu\n","ERROR"
                   ,lVar3,"nvml_checkpoint.c",0x41,uVar1);
      goto LAB_0012f008;
    }
    if (DAT_01216a78 < 2) {
      return;
    }
    fVar8 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    uVar6 = 0x3b;
    fVar8 = fVar8 * DAT_00298548;
  }
  local_3c = DAT_00298548;
  uVar7 = 6;
  FUN_002340f0((double)fVar8,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",lVar3,
               "nvml_checkpoint.c",uVar6);
LAB_0012f008:
  if (DAT_01216a78 < 2) {
    return;
  }
  fVar8 = (float)FUN_002917b0(&DAT_01216a60);
  lVar3 = syscall(0xba);
  FUN_002340f0((double)(fVar8 * local_3c),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","ERROR",lVar3,
               "nvml_checkpoint.c",0x27c,uVar7);
  return;
}


// ===== 0012f1e0 FUN_0012f1e0 =====

undefined4 FUN_0012f1e0(void)

{
  int iVar1;
  long lVar2;
  undefined4 uVar3;
  float fVar4;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  code *local_48;
  code *local_40;
  code *local_38;
  code *local_30;
  code *local_28;
  
  lVar2 = DAT_012164c0;
  if (DAT_003807e0 == 0) {
    uVar3 = 3;
    if (4 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                   lVar2,"nvml_checkpoint.c",0x294);
    }
  }
  else {
    local_50 = 0;
    uVar3 = 0x1d;
    if (DAT_012164c0 != 0) {
      local_58 = 0x38;
      local_48 = FUN_0012ed20;
      local_40 = FUN_0012ecf0;
      local_38 = FUN_0012e5f0;
      local_30 = FUN_0012dc60;
      local_28 = FUN_0012edd0;
      iVar1 = (**(code **)(DAT_012164c0 + 0x98))(&local_60,&local_58);
      if (iVar1 == 0) {
        (**(code **)(lVar2 + 0xa8))(local_60);
        DAT_012164c8 = local_60;
        return 0;
      }
      uVar3 = 0x14;
    }
    if (1 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d\n","ERROR",
                   lVar2,"nvml_checkpoint.c",0x29b,uVar3);
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 0012f390 FUN_0012f390 =====

undefined8 FUN_0012f390(void)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  float fVar4;
  
  lVar1 = DAT_012164c8;
  lVar2 = DAT_012164c0;
  if (DAT_003807e0 == 0) {
    uVar3 = 3;
    if (4 < DAT_01216a78) {
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",
                   lVar2,"nvml_checkpoint.c",0x2a9);
    }
  }
  else {
    if (DAT_012164c0 == 0) {
      if (1 < DAT_01216a78) {
        fVar4 = (float)FUN_002917b0(&DAT_01216a60);
        lVar2 = syscall(0xba);
        FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",
                     lVar2,"nvml_checkpoint.c",0x2b0);
      }
      return 0x1d;
    }
    if (DAT_012164c8 == 0) {
      return 0;
    }
    (**(code **)(DAT_012164c0 + 0xb0))(DAT_012164c8);
    uVar3 = 0;
    (**(code **)(lVar2 + 0xa0))(lVar1);
    DAT_012164c8 = 0;
  }
  return uVar3;
}


// ===== 0012f510 FUN_0012f510 =====

void FUN_0012f510(void)

{
  if (DAT_012164c0 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0012f51c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(DAT_012164c0 + 0xc0))();
    return;
  }
  return;
}


// ===== 0012f530 FUN_0012f530 =====

void FUN_0012f530(void)

{
  if (DAT_012164c0 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0012f53c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(DAT_012164c0 + 200))();
    return;
  }
  return;
}


// ===== 0012f550 FUN_0012f550 =====

undefined8 FUN_0012f550(void)

{
  long lVar1;
  float fVar2;
  
  if (DAT_01216a78 < 2) {
    return 0;
  }
  fVar2 = (float)FUN_002917b0(&DAT_01216a60);
  lVar1 = syscall(0xba);
  FUN_002340f0((double)(fVar2 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",lVar1,
               "nvml_utilization.c",0x5c);
  return 0;
}


// ===== 0012f5d0 FUN_0012f5d0 =====

undefined4 FUN_0012f5d0(undefined4 *param_1)

{
  return *param_1;
}


// ===== 0012f5e0 FUN_0012f5e0 =====

bool FUN_0012f5e0(int *param_1,int *param_2)

{
  return *param_1 == *param_2;
}


// ===== 0012f5f0 free =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
  (*(code *)PTR_free_0032ef38)();
  return;
}


// ===== 0012f600 free =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
  (*(code *)PTR_free_0032ef38)();
  return;
}


// ===== 0012f610 FUN_0012f610 =====

void * FUN_0012f610(long param_1,undefined4 param_2)

{
  int iVar1;
  void *pvVar2;
  undefined4 *__ptr;
  undefined4 local_2c;
  
  if (param_1 != 0) {
    local_2c = param_2;
    pvVar2 = (void *)FUN_00234de0(param_1,&local_2c);
    if (pvVar2 != (void *)0x0) {
      return pvVar2;
    }
    pvVar2 = calloc(0x40,1);
    if (pvVar2 != (void *)0x0) {
      __ptr = malloc(4);
      if (__ptr == (undefined4 *)0x0) {
        free(pvVar2);
        return (void *)0x0;
      }
      *__ptr = local_2c;
      iVar1 = FUN_00234c10(param_1,__ptr,pvVar2);
      if (iVar1 == 0) {
        return pvVar2;
      }
      free(pvVar2);
      free(__ptr);
      return (void *)0x0;
    }
  }
  return (void *)0x0;
}


// ===== 0012f6d0 thunk_FUN_0012f6e0 =====

int * thunk_FUN_0012f6e0(int *param_1,int param_2)

{
  while( true ) {
    if (param_1 == (int *)0x0) {
      return (int *)0x0;
    }
    if (*param_1 == param_2) break;
    param_1 = *(int **)(param_1 + 2);
  }
  return param_1;
}


// ===== 0012f6e0 FUN_0012f6e0 =====

int * FUN_0012f6e0(int *param_1,int param_2)

{
  while( true ) {
    if (param_1 == (int *)0x0) {
      return (int *)0x0;
    }
    if (*param_1 == param_2) break;
    param_1 = *(int **)(param_1 + 2);
  }
  return param_1;
}


// ===== 0012f700 FUN_0012f700 =====

undefined8 FUN_0012f700(undefined8 param_1,undefined8 *param_2,uint param_3,undefined8 *param_4)

{
  undefined8 *puVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  int *piVar5;
  undefined8 uVar6;
  float fVar7;
  double dVar8;
  undefined8 uVar9;
  
  if (param_3 == 0) {
    return 0;
  }
  puVar1 = param_2 + (ulong)(param_3 - 1) * 0x3d + 0x3d;
  do {
    iVar3 = *(int *)(param_2 + 2);
    if (iVar3 != -1) {
      lVar4 = thunk_FUN_0012f6e0(*param_4,iVar3);
      if (lVar4 == 0) {
        piVar5 = malloc(0x10);
        if (piVar5 == (int *)0x0) {
          lVar4 = FUN_0012f550();
          if (lVar4 == 0) {
            return 0x14;
          }
        }
        else {
          uVar6 = *param_4;
          *piVar5 = iVar3;
          *param_4 = piVar5;
          *(undefined8 *)(piVar5 + 2) = uVar6;
        }
      }
      uVar2 = *(uint *)(param_2 + 1);
      uVar6 = *param_2;
      piVar5 = (int *)FUN_0012f610(param_1,iVar3);
      if (piVar5 == (int *)0x0) {
        if (DAT_01216a78 < 2) {
          return 6;
        }
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        uVar9 = 0xd1;
        uVar6 = 0xd1;
        dVar8 = (double)(fVar7 * DAT_00298548);
        goto LAB_0012fd70;
      }
      *piVar5 = iVar3;
      *(undefined8 *)(piVar5 + 2) = uVar6;
      *(double *)(piVar5 + 4) = (double)uVar2 / (double)param_3 + *(double *)(piVar5 + 4);
    }
    iVar3 = *(int *)(param_2 + 0xc);
    if (iVar3 != -1) {
      lVar4 = thunk_FUN_0012f6e0(*param_4,iVar3);
      if (lVar4 == 0) {
        piVar5 = malloc(0x10);
        if (piVar5 == (int *)0x0) {
          lVar4 = FUN_0012f550();
          if (lVar4 == 0) {
            return 0x14;
          }
        }
        else {
          uVar6 = *param_4;
          *piVar5 = iVar3;
          *param_4 = piVar5;
          *(undefined8 *)(piVar5 + 2) = uVar6;
        }
      }
      uVar2 = *(uint *)(param_2 + 0xb);
      uVar6 = *param_2;
      piVar5 = (int *)FUN_0012f610(param_1,iVar3);
      if (piVar5 == (int *)0x0) {
        if (DAT_01216a78 < 2) {
          return 6;
        }
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        uVar9 = 0xe8;
        uVar6 = 0xe8;
        dVar8 = (double)(fVar7 * DAT_00298548);
        goto LAB_0012fd70;
      }
      *piVar5 = iVar3;
      *(undefined8 *)(piVar5 + 2) = uVar6;
      *(double *)(piVar5 + 6) = (double)uVar2 / (double)param_3 + *(double *)(piVar5 + 6);
    }
    iVar3 = *(int *)(param_2 + 0x16);
    if (iVar3 != -1) {
      lVar4 = thunk_FUN_0012f6e0(*param_4,iVar3);
      if (lVar4 == 0) {
        piVar5 = malloc(0x10);
        if (piVar5 == (int *)0x0) {
          lVar4 = FUN_0012f550();
          if (lVar4 == 0) {
            return 0x14;
          }
        }
        else {
          uVar6 = *param_4;
          *piVar5 = iVar3;
          *param_4 = piVar5;
          *(undefined8 *)(piVar5 + 2) = uVar6;
        }
      }
      uVar2 = *(uint *)(param_2 + 0x15);
      uVar6 = *param_2;
      piVar5 = (int *)FUN_0012f610(param_1,iVar3);
      if (piVar5 == (int *)0x0) {
        if (DAT_01216a78 < 2) {
          return 6;
        }
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        uVar9 = 0x100;
        uVar6 = 0x100;
        dVar8 = (double)(fVar7 * DAT_00298548);
        goto LAB_0012fd70;
      }
      *piVar5 = iVar3;
      *(undefined8 *)(piVar5 + 2) = uVar6;
      *(double *)(piVar5 + 8) = (double)uVar2 / (double)param_3 + *(double *)(piVar5 + 8);
    }
    iVar3 = *(int *)(param_2 + 0x20);
    if (iVar3 != -1) {
      lVar4 = thunk_FUN_0012f6e0(*param_4,iVar3);
      if (lVar4 == 0) {
        piVar5 = malloc(0x10);
        if (piVar5 == (int *)0x0) {
          lVar4 = FUN_0012f550();
          if (lVar4 == 0) {
            return 0x14;
          }
        }
        else {
          uVar6 = *param_4;
          *piVar5 = iVar3;
          *param_4 = piVar5;
          *(undefined8 *)(piVar5 + 2) = uVar6;
        }
      }
      uVar2 = *(uint *)(param_2 + 0x1f);
      uVar6 = *param_2;
      piVar5 = (int *)FUN_0012f610(param_1,iVar3);
      if (piVar5 == (int *)0x0) {
        if (DAT_01216a78 < 2) {
          return 6;
        }
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        uVar9 = 0x117;
        uVar6 = 0x117;
        dVar8 = (double)(fVar7 * DAT_00298548);
        goto LAB_0012fd70;
      }
      *piVar5 = iVar3;
      *(undefined8 *)(piVar5 + 2) = uVar6;
      *(double *)(piVar5 + 10) = (double)uVar2 / (double)param_3 + *(double *)(piVar5 + 10);
    }
    iVar3 = *(int *)(param_2 + 0x2a);
    if (iVar3 != -1) {
      lVar4 = thunk_FUN_0012f6e0(*param_4,iVar3);
      if (lVar4 == 0) {
        piVar5 = malloc(0x10);
        if (piVar5 == (int *)0x0) {
          lVar4 = FUN_0012f550();
          if (lVar4 == 0) {
            return 0x14;
          }
        }
        else {
          uVar6 = *param_4;
          *piVar5 = iVar3;
          *param_4 = piVar5;
          *(undefined8 *)(piVar5 + 2) = uVar6;
        }
      }
      uVar2 = *(uint *)(param_2 + 0x29);
      uVar6 = *param_2;
      piVar5 = (int *)FUN_0012f610(param_1,iVar3);
      if (piVar5 == (int *)0x0) {
        if (DAT_01216a78 < 2) {
          return 6;
        }
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        uVar9 = 0x12e;
        uVar6 = 0x12e;
        dVar8 = (double)(fVar7 * DAT_00298548);
        goto LAB_0012fd70;
      }
      *piVar5 = iVar3;
      *(undefined8 *)(piVar5 + 2) = uVar6;
      *(double *)(piVar5 + 0xc) = (double)uVar2 / (double)param_3 + *(double *)(piVar5 + 0xc);
    }
    iVar3 = *(int *)(param_2 + 0x34);
    if (iVar3 != -1) {
      lVar4 = thunk_FUN_0012f6e0(*param_4,iVar3);
      if (lVar4 == 0) {
        piVar5 = malloc(0x10);
        if (piVar5 == (int *)0x0) {
          lVar4 = FUN_0012f550();
          if (lVar4 == 0) {
            return 0x14;
          }
        }
        else {
          uVar6 = *param_4;
          *piVar5 = iVar3;
          *param_4 = piVar5;
          *(undefined8 *)(piVar5 + 2) = uVar6;
        }
      }
      uVar2 = *(uint *)(param_2 + 0x33);
      uVar6 = *param_2;
      piVar5 = (int *)FUN_0012f610(param_1,iVar3);
      if (piVar5 == (int *)0x0) {
        if (DAT_01216a78 < 2) {
          return 6;
        }
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        uVar9 = 0x145;
        uVar6 = 0x145;
        dVar8 = (double)(fVar7 * DAT_00298548);
LAB_0012fd70:
        FUN_002340f0(dVar8,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar4,
                     "nvml_utilization.c",uVar6,"updateProcessHashTable",uVar9,6);
        return 6;
      }
      *piVar5 = iVar3;
      *(undefined8 *)(piVar5 + 2) = uVar6;
      *(double *)(piVar5 + 0xe) = (double)uVar2 / (double)param_3 + *(double *)(piVar5 + 0xe);
    }
    param_2 = param_2 + 0x3d;
    if (puVar1 == param_2) {
      return 0;
    }
  } while( true );
}


// ===== 0012fe20 FUN_0012fe20 =====

void FUN_0012fe20(undefined8 *param_1)

{
  void *pvVar1;
  void *__ptr;
  
  __ptr = (void *)*param_1;
  while (__ptr != (void *)0x0) {
    pvVar1 = *(void **)((long)__ptr + 8);
    free(__ptr);
    __ptr = pvVar1;
  }
  return;
}


// ===== 0012fe50 FUN_0012fe50 =====

int * FUN_0012fe50(undefined8 param_1,long param_2,long param_3)

{
  byte bVar1;
  byte bVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  
  iVar4 = FUN_00257fb0(param_1,0xe);
  if (iVar4 + 2U < 2) {
    piVar8 = (int *)0x0;
  }
  else {
    piVar6 = (int *)FUN_002580d2(param_1,iVar4,0);
    piVar8 = (int *)0x0;
    for (; piVar6 != (int *)0x0; piVar6 = *(int **)(piVar6 + 0xe)) {
      piVar7 = piVar8;
      if ((*piVar6 == 0xe) && (lVar3 = *(long *)(piVar6 + 10), *(int *)(lVar3 + 0x20) == 1)) {
        if (**(short **)(param_2 + 0x28) == *(short *)(lVar3 + 0x1c)) {
          bVar1 = *(byte *)(lVar3 + 0x1e);
          uVar5 = (uint)*(byte *)(*(short **)(param_2 + 0x28) + 1);
          if ((((bVar1 <= uVar5) && (bVar2 = *(byte *)(lVar3 + 0x1f), uVar5 <= bVar2)) &&
              (**(short **)(param_3 + 0x28) == *(short *)(lVar3 + 0x1c))) &&
             (((uVar5 = (uint)*(byte *)(*(short **)(param_3 + 0x28) + 1), bVar1 <= uVar5 &&
               (uVar5 <= bVar2)) &&
              ((piVar7 = piVar6, piVar8 != (int *)0x0 &&
               (piVar7 = piVar8,
               (uint)bVar2 - (uint)bVar1 <
               (uint)*(byte *)(*(long *)(piVar8 + 10) + 0x1f) -
               (uint)*(byte *)(*(long *)(piVar8 + 10) + 0x1e))))))) {
            piVar7 = piVar6;
          }
        }
      }
      iVar4 = FUN_00257fb0(param_1,0xe);
      if (iVar4 + 2U < 2) {
        return piVar7;
      }
      if (iVar4 != piVar6[0xc]) {
        return piVar7;
      }
      piVar8 = piVar7;
    }
  }
  return piVar8;
}


// ===== 0012ff60 FUN_0012ff60 =====

int FUN_0012ff60(undefined8 param_1,int param_2,long *param_3)

{
  ushort *puVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  undefined8 uVar9;
  float fVar10;
  undefined8 uVar11;
  undefined1 local_88 [16];
  undefined1 local_78 [16];
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined4 local_48;
  
  iVar6 = FUN_001335a0();
  if (iVar6 == 0) {
    local_48 = 0;
    local_88 = (undefined1  [16])0x0;
    local_78 = (undefined1  [16])0x0;
    local_68 = (undefined1  [16])0x0;
    local_58 = (undefined1  [16])0x0;
    iVar6 = FUN_0013ef00(param_1,local_88);
    uVar9 = DAT_01216968;
    if (iVar6 == 0) {
      uVar5 = local_78._8_4_;
      uVar3 = local_78._0_4_;
      lVar8 = 0;
      uVar4 = local_78._4_4_;
      do {
        iVar6 = FUN_00257fb0(uVar9,0xf);
        if (iVar6 + 2U < 2) {
LAB_00130210:
          if (DAT_01216a78 < 2) {
            return 999;
          }
          fVar10 = (float)FUN_002917b0(&DAT_01216a60);
          lVar8 = syscall(0xba);
          fVar10 = fVar10 * DAT_00298548;
          uVar9 = 0x16f;
          goto LAB_00130264;
        }
        if (lVar8 == 0) {
          lVar8 = FUN_002580d2(uVar9,iVar6,0);
        }
        else {
          if (iVar6 != *(int *)(lVar8 + 0x30)) goto LAB_00130210;
          lVar8 = *(long *)(lVar8 + 0x38);
        }
        if (lVar8 == 0) goto LAB_00130210;
        puVar1 = *(ushort **)(lVar8 + 0x28);
      } while ((((uVar3 != (uint)*puVar1) || (uVar4 != (uint)(byte)puVar1[1])) ||
               (uVar5 != (uint)*(byte *)((long)puVar1 + 3))) || ((char)puVar1[2] != '\0'));
      if (param_2 == 0) {
        iVar6 = 0xd;
      }
      else {
        iVar6 = 1;
        if (param_2 != 1) {
          return 2;
        }
      }
      for (piVar2 = *(int **)(lVar8 + 0x48); piVar2 != (int *)0x0; piVar2 = *(int **)(piVar2 + 0x12)
          ) {
        if (iVar6 == *piVar2) {
          *param_3 = (long)piVar2;
          return 0;
        }
      }
      *param_3 = 0;
      do {
        if (*(long *)(lVar8 + 0xb8) != 0) {
          *param_3 = lVar8;
          return 0;
        }
        lVar8 = *(long *)(lVar8 + 0x48);
      } while (lVar8 != 0);
      if (1 < DAT_01216a78) {
        fVar10 = (float)FUN_002917b0(&DAT_01216a60);
        lVar8 = syscall(0xba);
        fVar10 = fVar10 * DAT_00298548;
        uVar9 = 0x186;
LAB_00130264:
        FUN_002340f0((double)fVar10,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",lVar8,
                     "common/nvhwloc.c",uVar9);
      }
      return 999;
    }
    if (DAT_01216a78 < 2) {
      return iVar6;
    }
    fVar10 = (float)FUN_002917b0(&DAT_01216a60);
    lVar8 = syscall(0xba);
    fVar10 = fVar10 * DAT_00298548;
    uVar11 = 0x169;
    uVar9 = 0x169;
    iVar7 = iVar6;
  }
  else {
    iVar6 = 3;
    if (DAT_01216a78 < 2) {
      return 3;
    }
    iVar7 = FUN_001335a0();
    fVar10 = (float)FUN_002917b0(&DAT_01216a60);
    lVar8 = syscall(0xba);
    fVar10 = fVar10 * DAT_00298548;
    uVar11 = 0x166;
    uVar9 = 0x166;
  }
  FUN_002340f0((double)fVar10,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar8,
               "common/nvhwloc.c",uVar9,"deviceGetAncestorObject",uVar11,iVar7);
  return iVar6;
}


// ===== 001302d0 FUN_001302d0 =====

ulong FUN_001302d0(undefined4 param_1,uint *param_2,long param_3)

{
  long *plVar1;
  ushort *puVar2;
  undefined8 uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  float fVar11;
  uint local_cc;
  undefined1 local_c0 [8];
  char local_b8 [136];
  
  iVar4 = FUN_001335a0();
  if (iVar4 != 0) {
    if (1 < DAT_01216a78) {
      uVar5 = FUN_001335a0();
      fVar11 = (float)FUN_002917b0(&DAT_01216a60);
      lVar8 = syscall(0xba);
      FUN_002340f0((double)(fVar11 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar8,"common/nvhwloc.c",0x69,"nvhwlocSystemGetTopologyGpuSet",0x69,uVar5
                  );
      return 3;
    }
    return 3;
  }
  if (*param_2 == 0) {
    if (param_3 != 0) {
      return 2;
    }
    uVar7 = FUN_00260eab();
    FUN_0026197d(uVar7,param_1);
    uVar3 = DAT_01216968;
    iVar4 = FUN_00257fb0(DAT_01216968,0xf);
    if ((iVar4 + 2U < 2) || (lVar8 = FUN_002580d2(uVar3,iVar4,0), lVar8 == 0)) {
      FUN_00260f71(uVar7);
      local_cc = 0;
      goto LAB_001303fd;
    }
    uVar10 = 1;
  }
  else {
    if (param_3 == 0) {
      return 2;
    }
    uVar7 = FUN_00260eab();
    FUN_0026197d(uVar7,param_1);
    uVar3 = DAT_01216968;
    iVar4 = FUN_00257fb0(DAT_01216968,0xf);
    if ((iVar4 + 2U < 2) || (lVar8 = FUN_002580d2(uVar3,iVar4,0), lVar8 == 0)) {
      FUN_00260f71(uVar7);
      return 0;
    }
    uVar10 = 0;
  }
  local_cc = 0;
  do {
    puVar2 = *(ushort **)(lVar8 + 0x28);
    if ((((char)puVar2[2] == '\0') &&
        (sprintf(local_b8,"%04x:%02x:%02x.%x",(ulong)*puVar2,(ulong)(byte)puVar2[1],
                 (ulong)*(byte *)((long)puVar2 + 3),0),
        *(short *)(*(long *)(lVar8 + 0x28) + 8) == 0x10de)) &&
       (iVar4 = FUN_0013a4a0(local_b8,local_c0), lVar9 = lVar8, iVar4 != 6)) {
      while (*(long *)(lVar9 + 0xb8) == 0) {
        plVar1 = (long *)(lVar9 + 0x48);
        lVar9 = *plVar1;
        if (*plVar1 == 0) {
          uVar10 = FUN_0011fcd8();
          return uVar10;
        }
      }
      iVar4 = FUN_002623d5(uVar7);
      if (iVar4 != 0) {
        if (((int)uVar10 == 0) &&
           (uVar6 = FUN_0013a4a0(local_b8,param_3 + (ulong)local_cc * 8), uVar6 != 0)) {
          FUN_00260f71(uVar7);
          return (ulong)uVar6;
        }
        local_cc = local_cc + 1;
      }
    }
    iVar4 = FUN_00257fb0(DAT_01216968,0xf);
  } while (((1 < iVar4 + 2U) && (iVar4 == *(int *)(lVar8 + 0x30))) &&
          (lVar8 = *(long *)(lVar8 + 0x38), lVar8 != 0));
  FUN_00260f71(uVar7);
  if ((int)uVar10 == 0) {
    return uVar10;
  }
LAB_001303fd:
  *param_2 = local_cc;
  return 0;
}


// ===== 001305f0 FUN_001305f0 =====

ulong FUN_001305f0(long param_1,uint param_2,uint *param_3,long param_4)

{
  ushort *puVar1;
  code *pcVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  undefined8 uVar13;
  uint uVar14;
  uint uVar15;
  float fVar16;
  double dVar17;
  undefined8 uVar18;
  uint local_ec;
  uint local_e8;
  uint local_e4;
  undefined8 local_e0;
  undefined1 local_d8 [16];
  uint local_c8;
  uint local_c4;
  uint local_c0;
  undefined1 local_88 [16];
  uint local_78;
  uint local_74;
  uint local_70;
  
  if ((param_1 == 0) || (param_3 == (uint *)0x0)) {
LAB_001308a0:
    local_ec = 2;
  }
  else {
    if (*param_3 == 0) {
      if (param_4 != 0) goto LAB_001308a0;
      bVar3 = true;
    }
    else {
      if (param_4 == 0) goto LAB_001308a0;
      bVar3 = false;
    }
    uVar7 = FUN_001904e0(&local_e4);
    local_ec = uVar7;
    if (uVar7 == 0) {
      uVar14 = 0;
      if (local_e4 != 0) {
        uVar14 = 0;
        uVar15 = 0;
LAB_00130688:
        do {
          if (*(uint *)(param_1 + 4) == uVar15) goto LAB_00130747;
          local_ec = FUN_00190770(uVar15,&local_e0);
          if (local_ec != 0) {
            if (DAT_01216a78 < 2) goto LAB_00130762;
            fVar16 = (float)FUN_002917b0(&DAT_01216a60);
            lVar10 = syscall(0xba);
            uVar18 = 0xd1;
            uVar13 = 0xd1;
            dVar17 = (double)(fVar16 * DAT_00298548);
            goto LAB_001309e0;
          }
          local_ec = thunk_FUN_00131ff0(param_1,local_e0,&local_e8);
          uVar13 = local_e0;
          uVar4 = local_e8;
          if (local_ec != 0) {
            if (DAT_01216a78 < 2) goto LAB_00130762;
            fVar16 = (float)FUN_002917b0(&DAT_01216a60);
            lVar10 = syscall(0xba);
            uVar18 = 0xd2;
            uVar13 = 0xd2;
            dVar17 = (double)(fVar16 * DAT_00298548);
            goto LAB_001309e0;
          }
          iVar8 = FUN_001335a0();
          if (iVar8 != 0) {
            if (DAT_01216a78 < 2) {
              local_ec = 3;
              goto LAB_00130762;
            }
            uVar9 = FUN_001335a0();
            fVar16 = (float)FUN_002917b0(&DAT_01216a60);
            lVar10 = syscall(0xba);
            FUN_002340f0((double)(fVar16 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar10,
                         "common/nvhwloc.c",0x1b,"compareLevels",0x1b,uVar9);
            local_ec = 3;
LAB_001307ba:
            if (DAT_01216a78 < 2) goto LAB_00130762;
            fVar16 = (float)FUN_002917b0(&DAT_01216a60);
            lVar10 = syscall(0xba);
            uVar13 = 0xd3;
            uVar18 = 0xd3;
            dVar17 = (double)(fVar16 * DAT_00298548);
            goto LAB_001309e0;
          }
          if (uVar4 == 0x1e) {
            if (0x1d < param_2) goto LAB_00130718;
            uVar15 = uVar15 + 1;
            if (local_e4 <= uVar15) break;
            goto LAB_00130688;
          }
          if (0x1e < uVar4) {
            if (uVar4 != 0x28) {
              if (uVar4 != 0x32) {
LAB_001307a9:
                local_ec = 999;
                goto LAB_001307ba;
              }
              goto LAB_00130718;
            }
            if (param_2 == 0x32) goto LAB_00130718;
            if (param_2 == 0x28) {
              local_ec = FUN_0013ef00(param_1,local_d8);
              if (local_ec == 0) {
                local_ec = FUN_0013ef00(uVar13,local_88);
                uVar6 = local_c0;
                uVar5 = local_c4;
                uVar4 = local_c8;
                uVar13 = DAT_01216968;
                if (local_ec == 0) {
                  lVar10 = 0;
                  while( true ) {
                    iVar8 = FUN_00257fb0(uVar13,0xf);
                    if (iVar8 + 2U < 2) break;
                    if (lVar10 == 0) {
                      lVar10 = FUN_002580d2(uVar13,iVar8,0);
                    }
                    else {
                      if (iVar8 != *(int *)(lVar10 + 0x30)) break;
                      lVar10 = *(long *)(lVar10 + 0x38);
                    }
                    if ((lVar10 == 0) ||
                       ((((puVar1 = *(ushort **)(lVar10 + 0x28), uVar4 == *puVar1 &&
                          (uVar5 == (byte)puVar1[1])) && (uVar6 == *(byte *)((long)puVar1 + 3))) &&
                        ((char)puVar1[2] == '\0')))) goto LAB_00130c40;
                  }
                  lVar10 = 0;
LAB_00130c40:
                  uVar6 = local_70;
                  uVar5 = local_74;
                  uVar4 = local_78;
                  uVar13 = DAT_01216968;
                  lVar11 = 0;
                  do {
                    iVar8 = FUN_00257fb0(uVar13,0xf);
                    if (iVar8 + 2U < 2) {
LAB_00130d50:
                      if (lVar10 == 0) {
                        uVar12 = FUN_0011fce2();
                        return uVar12;
                      }
                      lVar11 = 0;
                      goto LAB_00130d09;
                    }
                    if (lVar11 == 0) {
                      lVar11 = FUN_002580d2(uVar13,iVar8,0);
                    }
                    else {
                      if (iVar8 != *(int *)(lVar11 + 0x30)) goto LAB_00130d50;
                      lVar11 = *(long *)(lVar11 + 0x38);
                    }
                    if (lVar11 == 0) goto LAB_00130d50;
                    puVar1 = *(ushort **)(lVar11 + 0x28);
                  } while (((uVar4 != *puVar1) || (uVar5 != (byte)puVar1[1])) ||
                          ((uVar6 != *(byte *)((long)puVar1 + 3) || ((char)puVar1[2] != '\0'))));
                  if (lVar10 != 0) {
LAB_00130d09:
                    do {
                      if (*(long *)(lVar10 + 0xb8) != 0) goto LAB_00130d1c;
                      lVar10 = *(long *)(lVar10 + 0x48);
                      if (lVar10 == 0) goto LAB_00130d1c;
                    } while( true );
                  }
                  while (*(long *)(lVar11 + 0xb8) == 0) {
                    lVar11 = *(long *)(lVar11 + 0x48);
LAB_00130d1c:
                    if (lVar11 == 0) {
                    /* WARNING: Does not return */
                      pcVar2 = (code *)invalidInstructionException();
                      (*pcVar2)();
                    }
                  }
                  iVar8 = FUN_00262158(*(undefined8 *)(lVar10 + 0xb8));
                  if (iVar8 != 0) goto LAB_00130718;
                  goto LAB_00130747;
                }
                if (DAT_01216a78 < 2) goto LAB_00130762;
                fVar16 = (float)FUN_002917b0(&DAT_01216a60);
                lVar10 = syscall(0xba);
                fVar16 = fVar16 * DAT_00298548;
                uVar18 = 0x44;
                uVar13 = 0x44;
              }
              else {
                if (DAT_01216a78 < 2) goto LAB_00130762;
                fVar16 = (float)FUN_002917b0(&DAT_01216a60);
                lVar10 = syscall(0xba);
                fVar16 = fVar16 * DAT_00298548;
                uVar18 = 0x43;
                uVar13 = 0x43;
              }
              FUN_002340f0((double)fVar16,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",
                           lVar10,"common/nvhwloc.c",uVar13,"compareLevels",uVar18,local_ec);
              goto LAB_001307ba;
            }
LAB_00130747:
            uVar15 = uVar15 + 1;
            if (local_e4 <= uVar15) break;
            goto LAB_00130688;
          }
          if (uVar4 != 10) {
            if (uVar4 == 0x14) {
              if (param_2 < 0x14) goto LAB_00130747;
            }
            else if (uVar4 != 0) goto LAB_001307a9;
LAB_00130718:
            if ((!bVar3) && (uVar14 < *param_3)) {
              *(undefined8 *)(param_4 + (ulong)uVar14 * 8) = local_e0;
            }
            uVar14 = uVar14 + 1;
            goto LAB_00130747;
          }
          if (9 < param_2) goto LAB_00130718;
          uVar15 = uVar15 + 1;
        } while (uVar15 < local_e4);
      }
      *param_3 = uVar14;
      local_ec = uVar7;
    }
    else if (1 < DAT_01216a78) {
      fVar16 = (float)FUN_002917b0(&DAT_01216a60);
      lVar10 = syscall(0xba);
      uVar13 = 0xc6;
      uVar18 = 0xc6;
      dVar17 = (double)(fVar16 * DAT_00298548);
LAB_001309e0:
      FUN_002340f0(dVar17,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar10,
                   "common/nvhwloc.c",uVar13,"nvhwlocDeviceGetTopologyNearestGpus",uVar18,local_ec);
    }
  }
LAB_00130762:
  return (ulong)local_ec;
}


// ===== 00130e00 FUN_00130e00 =====

undefined8 FUN_00130e00(void)

{
  undefined8 uVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  undefined8 uVar5;
  float fVar6;
  
  iVar2 = FUN_001335a0();
  uVar1 = DAT_01216968;
  if (iVar2 == 0) {
    lVar4 = FUN_002580d2(DAT_01216968,0,0);
    uVar5 = 0;
    FUN_002600fa(uVar1,*(undefined8 *)(lVar4 + 0xb8),2);
  }
  else {
    uVar5 = 3;
    if (1 < DAT_01216a78) {
      uVar3 = FUN_001335a0();
      fVar6 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"common/nvhwloc.c",0x11f,"nvhwlocDeviceClearCpuAffinity",0x11f,
                   uVar3);
      return 3;
    }
  }
  return uVar5;
}


// ===== 00130ee0 FUN_00130ee0 =====

undefined8 FUN_00130ee0(long param_1)

{
  undefined8 *puVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  undefined8 uVar8;
  float fVar9;
  undefined8 local_a8 [17];
  
  if (param_1 == 0) {
    return 2;
  }
  FUN_0013d100(param_1,0x10,local_a8);
  iVar2 = FUN_001335a0();
  if (iVar2 == 0) {
    lVar4 = FUN_00260eab();
    if (lVar4 == 0) {
      uVar8 = 999;
      if (1 < DAT_01216a78) {
        fVar9 = (float)FUN_002917b0(&DAT_01216a60);
        lVar4 = syscall(0xba);
        FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",
                     lVar4,"common/nvhwloc.c",0x141);
      }
    }
    else {
      uVar6 = 0;
      do {
        puVar1 = local_a8 + uVar6;
        uVar7 = uVar6 & 0xffffffff;
        uVar6 = uVar6 + 1;
        FUN_00261c9e(lVar4,uVar7,*puVar1);
      } while (uVar6 != 0x10);
      iVar2 = FUN_002600fa(DAT_01216968,lVar4,2);
      if (iVar2 != 0) {
        if (DAT_01216a78 < 2) {
          FUN_00260f71(lVar4);
        }
        else {
          fVar9 = (float)FUN_002917b0(&DAT_01216a60);
          lVar5 = syscall(0xba);
          FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       "ERROR",lVar5,"common/nvhwloc.c",0x14d);
          FUN_00260f71(lVar4);
        }
        return 999;
      }
      uVar8 = 0;
      FUN_00260f71(lVar4);
    }
  }
  else {
    uVar8 = 3;
    if (1 < DAT_01216a78) {
      uVar3 = FUN_001335a0();
      fVar9 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar9 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"common/nvhwloc.c",0x13c,"nvhwlocDeviceSetCpuAffinity",0x13c,uVar3)
      ;
      return 3;
    }
  }
  return uVar8;
}


// ===== 00131150 FUN_00131150 =====

int FUN_00131150(long param_1,uint param_2,long param_3,undefined4 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  ulong uVar4;
  float fVar5;
  long local_40 [2];
  
  if ((param_3 == 0 || param_2 == 0) || (param_1 == 0)) {
    iVar1 = 2;
  }
  else {
    iVar1 = FUN_0012ff60(param_1,param_4,local_40);
    if (iVar1 == 0) {
      uVar4 = 0;
      lVar3 = *(long *)(local_40[0] + 0xb8);
      if (lVar3 == 0) {
        iVar1 = 999;
        if (1 < DAT_01216a78) {
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       "ERROR",lVar3,"common/nvhwloc.c",0x1a3);
        }
      }
      else {
        while( true ) {
          uVar2 = FUN_002618ab(lVar3,uVar4 & 0xffffffff);
          *(undefined8 *)(param_3 + uVar4 * 8) = uVar2;
          uVar4 = uVar4 + 1;
          if (param_2 <= (uint)uVar4) break;
          lVar3 = *(long *)(local_40[0] + 0xb8);
        }
      }
    }
    else if (1 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar3,"common/nvhwloc.c",0x19e,"nvhwlocDeviceGetCpuAffinity",0x19e,iVar1)
      ;
    }
  }
  return iVar1;
}


// ===== 001312f0 FUN_001312f0 =====

int FUN_001312f0(char *param_1,uint param_2,long param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  float fVar7;
  undefined8 uVar8;
  long local_40 [2];
  
  if (param_1 != (char *)0x0) {
    if (*param_1 != '\x01') {
      if (*(int *)(param_1 + 0x14) == 0) {
        return 2;
      }
      if (*(int *)(param_1 + 0x1c) != 0) {
        return 2;
      }
      if (*(int *)(param_1 + 0x10) == 0) {
        return 2;
      }
      if (*(long *)(param_1 + 0x20) == 0) {
        return 2;
      }
    }
    if ((param_3 != 0) && (param_2 != 0)) {
      iVar1 = FUN_001335a0();
      if (iVar1 == 0) {
        iVar1 = FUN_0012ff60(param_1,param_4,local_40);
        if (iVar1 == 0) {
          if (*(long *)(local_40[0] + 0xb8) == 0) {
            iVar1 = 999;
            if (DAT_01216a78 < 2) {
              return 999;
            }
            fVar7 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            uVar4 = 0x1c6;
            fVar7 = fVar7 * DAT_00298548;
          }
          else {
            lVar3 = FUN_00260eab();
            uVar4 = DAT_01216968;
            if (lVar3 != 0) {
              uVar8 = *(undefined8 *)(local_40[0] + 0xb8);
              iVar1 = FUN_00257fb0(DAT_01216968,0xd);
              FUN_0026180c(lVar3);
LAB_001314dd:
              lVar5 = FUN_002580d2(uVar4,iVar1,0);
              do {
                if (lVar5 == 0) goto LAB_00131420;
                iVar2 = FUN_002622a3(uVar8,*(undefined8 *)(lVar5 + 0xb8));
                if (iVar2 != 0) {
                  iVar2 = FUN_0026197d(lVar3,*(undefined4 *)(lVar5 + 0x10));
                  if (iVar2 < 0) {
LAB_00131420:
                    uVar6 = 0;
                    do {
                      uVar4 = FUN_002618ab(lVar3,uVar6 & 0xffffffff);
                      *(undefined8 *)(param_3 + uVar6 * 8) = uVar4;
                      uVar6 = uVar6 + 1;
                    } while ((uint)uVar6 < param_2);
                    FUN_00260f71(lVar3);
                    return 0;
                  }
                  if (lVar5 == 0) goto LAB_001314dd;
                  if (iVar1 != *(int *)(lVar5 + 0x30)) goto LAB_00131420;
                }
                lVar5 = *(long *)(lVar5 + 0x38);
              } while( true );
            }
            iVar1 = 0x14;
            if (DAT_01216a78 < 2) {
              return 0x14;
            }
            fVar7 = (float)FUN_002917b0(&DAT_01216a60);
            lVar3 = syscall(0xba);
            uVar4 = 0x1cd;
            fVar7 = fVar7 * DAT_00298548;
          }
          FUN_002340f0((double)fVar7,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","ERROR",lVar3,
                       "common/nvhwloc.c",uVar4);
          return iVar1;
        }
        if (DAT_01216a78 < 2) {
          return iVar1;
        }
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        fVar7 = fVar7 * DAT_00298548;
        uVar8 = 0x1c1;
        uVar4 = 0x1c1;
        iVar2 = iVar1;
      }
      else {
        iVar1 = 3;
        if (DAT_01216a78 < 2) {
          return 3;
        }
        iVar2 = FUN_001335a0();
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar3 = syscall(0xba);
        fVar7 = fVar7 * DAT_00298548;
        uVar8 = 0x1bf;
        uVar4 = 0x1bf;
      }
      FUN_002340f0((double)fVar7,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar3,
                   "common/nvhwloc.c",uVar4,"nvhwlocDeviceGetNumaIdByCpuAffinity",uVar8,iVar2);
      return iVar1;
    }
  }
  return 2;
}


// ===== 00131640 FUN_00131640 =====

int FUN_00131640(long param_1,uint param_2,long param_3,undefined4 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  ulong uVar4;
  float fVar5;
  long local_40 [2];
  
  if ((param_3 == 0 || param_2 == 0) || (param_1 == 0)) {
    iVar1 = 2;
  }
  else {
    iVar1 = FUN_0012ff60(param_1,param_4,local_40);
    if (iVar1 == 0) {
      uVar4 = 0;
      lVar3 = *(long *)(local_40[0] + 200);
      if (lVar3 == 0) {
        iVar1 = 999;
        if (1 < DAT_01216a78) {
          fVar5 = (float)FUN_002917b0(&DAT_01216a60);
          lVar3 = syscall(0xba);
          FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                       "ERROR",lVar3,"common/nvhwloc.c",0x1ef);
        }
      }
      else {
        while( true ) {
          uVar2 = FUN_002618ab(lVar3,uVar4 & 0xffffffff);
          *(undefined8 *)(param_3 + uVar4 * 8) = uVar2;
          uVar4 = uVar4 + 1;
          if (param_2 <= (uint)uVar4) break;
          lVar3 = *(long *)(local_40[0] + 200);
        }
      }
    }
    else if (1 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar3 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar3,"common/nvhwloc.c",0x1ea,"nvhwlocDeviceGetMemoryAffinity",0x1ea,
                   iVar1);
    }
  }
  return iVar1;
}


// ===== 001317e0 FUN_001317e0 =====

undefined8 FUN_001317e0(long param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  ushort *puVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  int *piVar15;
  long lVar16;
  undefined8 uVar17;
  float fVar18;
  double dVar19;
  uint local_58;
  uint local_54;
  uint local_50;
  undefined4 uStack_4c;
  uint local_48 [2];
  undefined4 *local_40;
  
  if ((param_2 == 0 || param_3 == (undefined4 *)0x0) || (param_1 == 0)) {
    return 2;
  }
  iVar8 = FUN_001335a0();
  uVar17 = DAT_01216968;
  if (iVar8 != 0) {
    if (1 < DAT_01216a78) {
      uVar9 = FUN_001335a0();
      fVar18 = (float)FUN_002917b0(&DAT_01216a60);
      lVar16 = syscall(0xba);
      FUN_002340f0((double)(fVar18 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar16,"common/nvhwloc.c",0x256,"nvhwlocDeviceGetTopologyInternal",0x256,
                   uVar9);
    }
    return 3;
  }
  local_58 = 0;
  iVar8 = __isoc99_sscanf(param_1,"%x:%x.%x",&local_54,&local_50,local_48);
  if ((iVar8 == 3) ||
     (iVar8 = __isoc99_sscanf(param_1,&DAT_0029adca,&local_58,&local_54,&local_50,local_48),
     iVar8 == 4)) {
    uVar7 = local_48[0];
    uVar6 = local_50;
    uVar5 = local_54;
    uVar4 = local_58;
    puVar13 = (undefined4 *)0x0;
    do {
      iVar8 = FUN_00257fb0(uVar17,0xf);
      if (iVar8 + 2U < 2) goto LAB_00131b78;
      if (puVar13 == (undefined4 *)0x0) {
        puVar13 = (undefined4 *)FUN_002580d2(uVar17,iVar8,0);
      }
      else {
        if (iVar8 != puVar13[0xc]) goto LAB_00131b78;
        puVar13 = *(undefined4 **)(puVar13 + 0xe);
      }
      uVar3 = DAT_01216968;
      if (puVar13 == (undefined4 *)0x0) goto LAB_00131b78;
      puVar2 = *(ushort **)(puVar13 + 10);
    } while ((((uVar4 != *puVar2) || (uVar5 != (byte)puVar2[1])) ||
             (uVar6 != *(byte *)((long)puVar2 + 3))) || (uVar7 != (byte)puVar2[2]));
    local_58 = 0;
    iVar8 = __isoc99_sscanf(param_2,"%x:%x.%x",&local_54,&local_50,local_48);
    if ((iVar8 == 3) ||
       (iVar8 = __isoc99_sscanf(param_2,&DAT_0029adca,&local_58,&local_54,&local_50,local_48),
       iVar8 == 4)) {
      uVar7 = local_48[0];
      uVar6 = local_50;
      uVar5 = local_54;
      uVar4 = local_58;
      puVar14 = (undefined4 *)0x0;
      do {
        iVar8 = FUN_00257fb0(uVar3,0xf);
        if (iVar8 + 2U < 2) goto LAB_00131ba8;
        if (puVar14 == (undefined4 *)0x0) {
          puVar14 = (undefined4 *)FUN_002580d2(uVar3,iVar8,0);
        }
        else {
          if (iVar8 != puVar14[0xc]) goto LAB_00131ba8;
          puVar14 = *(undefined4 **)(puVar14 + 0xe);
        }
        if (puVar14 == (undefined4 *)0x0) goto LAB_00131ba8;
        puVar2 = *(ushort **)(puVar14 + 10);
      } while (((uVar4 != *puVar2) || (uVar5 != (byte)puVar2[1])) ||
              ((uVar6 != *(byte *)((long)puVar2 + 3) || (uVar7 != (byte)puVar2[2]))));
      if (puVar13 == puVar14) {
        if (DAT_01216a78 < 2) {
          return 3;
        }
        fVar18 = (float)FUN_002917b0(&DAT_01216a60);
        lVar16 = syscall(0xba);
        FUN_002340f0((double)(fVar18 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %s\n",
                     "ERROR",lVar16,"common/nvhwloc.c",0x26a,param_1,param_2);
        return 3;
      }
      puVar10 = (undefined4 *)FUN_0012fe50(DAT_01216968,puVar13,puVar13);
      if (puVar10 == (undefined4 *)0x0) {
        if (DAT_01216a78 < 2) {
          return 999;
        }
        fVar18 = (float)FUN_002917b0(&DAT_01216a60);
        lVar16 = syscall(0xba);
        uVar17 = 0x273;
        dVar19 = (double)(fVar18 * DAT_00298548);
      }
      else {
        puVar11 = (undefined4 *)FUN_0012fe50(DAT_01216968,puVar14,puVar14);
        if (puVar11 != (undefined4 *)0x0) {
          puVar12 = (undefined4 *)FUN_0012fe50(DAT_01216968,puVar13,puVar14);
          if (puVar12 == (undefined4 *)0x0) {
            do {
              puVar12 = puVar13;
              if (*(long *)(puVar13 + 0x2e) != 0) break;
              puVar13 = *(undefined4 **)(puVar13 + 0x12);
              puVar12 = puVar13;
            } while (puVar13 != (undefined4 *)0x0);
            do {
              if (*(long *)(puVar14 + 0x2e) != 0) break;
              puVar14 = *(undefined4 **)(puVar14 + 0x12);
            } while (puVar14 != (undefined4 *)0x0);
            while (puVar14 != puVar12) {
              iVar1 = puVar14[0xc];
              iVar8 = puVar12[0xc];
              while (iVar1 < iVar8) {
                puVar12 = *(undefined4 **)(puVar12 + 0x12);
                iVar8 = puVar12[0xc];
              }
              while (iVar8 < iVar1) {
                puVar14 = *(undefined4 **)(puVar14 + 0x12);
                iVar1 = puVar14[0xc];
              }
              if ((puVar12 != puVar14) && (iVar1 == iVar8)) {
                puVar12 = *(undefined4 **)(puVar12 + 0x12);
                puVar14 = *(undefined4 **)(puVar14 + 0x12);
              }
            }
            if (puVar14 == (undefined4 *)0x0) {
              if (DAT_01216a78 < 2) {
                return 999;
              }
              fVar18 = (float)FUN_002917b0(&DAT_01216a60);
              lVar16 = syscall(0xba);
              FUN_002340f0((double)(fVar18 * DAT_00298548),
                           "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %s\n","ERROR",lVar16,
                           "common/nvhwloc.c",0x28d,param_1,param_2);
              return 999;
            }
          }
          switch(*puVar12) {
          case 0:
          case 1:
          case 2:
          case 0xc:
          case 0x11:
            local_48[0] = 0;
            *param_3 = 4;
            local_54 = 1;
            local_40 = puVar12;
            iVar8 = FUN_0025c292(DAT_01216968,local_48,&local_54,&local_50,0);
            if ((((iVar8 == 0) && (local_54 == 1)) &&
                ((int *)CONCAT44(uStack_4c,local_50) != (int *)0x0)) &&
               (*(int *)CONCAT44(uStack_4c,local_50) == 0xd)) {
              *param_3 = 3;
            }
            break;
          default:
            *param_3 = 4;
            break;
          case 0xd:
            *param_3 = 3;
            break;
          case 0xe:
            lVar16 = *(long *)(puVar12 + 10);
            if (*(int *)(lVar16 + 0x18) == 0) {
              *param_3 = 2;
            }
            else if (((puVar10 == puVar12) ||
                     (*(char *)(lVar16 + 0x1e) == *(char *)(*(long *)(puVar10 + 10) + 2))) &&
                    ((puVar11 == puVar12 ||
                     (*(char *)(lVar16 + 0x1e) == *(char *)(*(long *)(puVar11 + 10) + 2))))) {
              *param_3 = 0;
            }
            else {
              *param_3 = 1;
            }
          }
          if (4 < DAT_01216a78) {
            uVar9 = *param_3;
            fVar18 = (float)FUN_002917b0(&DAT_01216a60);
            lVar16 = syscall(0xba);
            FUN_002340f0((double)(fVar18 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %s %d\n","DEBUG",lVar16,
                         "common/nvhwloc.c",0x2b8,param_1,param_2,uVar9);
            return 0;
          }
          return 0;
        }
        if (DAT_01216a78 < 2) {
          return 999;
        }
        fVar18 = (float)FUN_002917b0(&DAT_01216a60);
        lVar16 = syscall(0xba);
        uVar17 = 0x27b;
        dVar19 = (double)(fVar18 * DAT_00298548);
        param_1 = param_2;
      }
    }
    else {
      piVar15 = __errno_location();
      *piVar15 = 0x16;
LAB_00131ba8:
      if (DAT_01216a78 < 2) {
        return 999;
      }
      fVar18 = (float)FUN_002917b0(&DAT_01216a60);
      lVar16 = syscall(0xba);
      uVar17 = 0x264;
      dVar19 = (double)(fVar18 * DAT_00298548);
      param_1 = param_2;
    }
  }
  else {
    piVar15 = __errno_location();
    *piVar15 = 0x16;
LAB_00131b78:
    if (DAT_01216a78 < 2) {
      return 999;
    }
    fVar18 = (float)FUN_002917b0(&DAT_01216a60);
    lVar16 = syscall(0xba);
    uVar17 = 0x25c;
    dVar19 = (double)(fVar18 * DAT_00298548);
  }
  FUN_002340f0(dVar19,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n","ERROR",lVar16,"common/nvhwloc.c",
               uVar17,param_1);
  return 999;
}


// ===== 00131ff0 FUN_00131ff0 =====

int FUN_00131ff0(char *param_1,char *param_2,uint *param_3)

{
  int iVar1;
  long lVar2;
  float fVar3;
  undefined4 local_d0;
  int local_cc;
  undefined1 local_c8 [36];
  undefined1 local_a4 [44];
  undefined1 local_78 [36];
  undefined1 local_54 [44];
  
  local_cc = 0;
  if (param_1 == (char *)0x0) {
    return 2;
  }
  if ((*param_1 == '\x01') ||
     ((((iVar1 = 2, *(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) == 0)) &&
       (*(int *)(param_1 + 0x10) != 0)) && (*(long *)(param_1 + 0x20) != 0)))) {
    if (param_2 == (char *)0x0) {
      iVar1 = 2;
    }
    else if ((*param_2 == '\x01') ||
            (((iVar1 = 2, *(int *)(param_2 + 0x14) != 0 && (*(int *)(param_2 + 0x1c) == 0)) &&
             ((*(int *)(param_2 + 0x10) != 0 && (*(long *)(param_2 + 0x20) != 0)))))) {
      if (param_3 == (uint *)0x0) {
        iVar1 = 2;
      }
      else {
        iVar1 = FUN_0013ef00(param_1,local_c8);
        if (iVar1 == 0) {
          iVar1 = FUN_0013ef00(param_2,local_78);
          if (iVar1 == 0) {
            iVar1 = FUN_001317e0(local_a4,local_54,&local_d0);
            if (iVar1 == 0) {
              switch(local_d0) {
              case 0:
                iVar1 = FUN_00176c20(param_1,&local_cc);
                if (iVar1 == 0) {
                  *param_3 = -(uint)(local_cc == 0) & 10;
                }
                else if (1 < DAT_01216a78) {
                  fVar3 = (float)FUN_002917b0(&DAT_01216a60);
                  lVar2 = syscall(0xba);
                  FUN_002340f0((double)(fVar3 * DAT_00298548),
                               "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar2,
                               "common/nvhwloc.c",0xfa,"nvhwlocDeviceGetTopologyCommonAncestor",0xfa
                               ,iVar1);
                }
                break;
              case 1:
                *param_3 = 0x14;
                break;
              case 2:
                *param_3 = 0x1e;
                break;
              case 3:
                *param_3 = 0x28;
                break;
              case 4:
                *param_3 = 0x32;
                break;
              default:
                iVar1 = 999;
              }
            }
            else if (1 < DAT_01216a78) {
              fVar3 = (float)FUN_002917b0(&DAT_01216a60);
              lVar2 = syscall(0xba);
              FUN_002340f0((double)(fVar3 * DAT_00298548),
                           "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar2,
                           "common/nvhwloc.c",0xf5,"nvhwlocDeviceGetTopologyCommonAncestor",0xf5,
                           iVar1);
            }
          }
          else if (1 < DAT_01216a78) {
            fVar3 = (float)FUN_002917b0(&DAT_01216a60);
            lVar2 = syscall(0xba);
            FUN_002340f0((double)(fVar3 * DAT_00298548),
                         "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar2,
                         "common/nvhwloc.c",0xf4,"nvhwlocDeviceGetTopologyCommonAncestor",0xf4,iVar1
                        );
          }
        }
        else if (1 < DAT_01216a78) {
          fVar3 = (float)FUN_002917b0(&DAT_01216a60);
          lVar2 = syscall(0xba);
          FUN_002340f0((double)(fVar3 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar2,
                       "common/nvhwloc.c",0xf3,"nvhwlocDeviceGetTopologyCommonAncestor",0xf3,iVar1);
        }
      }
    }
  }
  return iVar1;
}


// ===== 001323c0 FUN_001323c0 =====

int FUN_001323c0(char *param_1,int *param_2,long param_3)

{
  undefined4 *puVar1;
  ushort uVar2;
  undefined4 uVar3;
  ushort *puVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined8 uVar13;
  uint uVar14;
  uint uVar15;
  ulong uVar16;
  float fVar17;
  undefined8 uVar18;
  uint local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  undefined1 local_88 [36];
  undefined1 local_64 [52];
  
  if (param_1 != (char *)0x0) {
    if (*param_1 != '\x01') {
      if (*(int *)(param_1 + 0x14) == 0) {
        return 2;
      }
      if (*(int *)(param_1 + 0x1c) != 0) {
        return 2;
      }
      if (*(int *)(param_1 + 0x10) == 0) {
        return 2;
      }
      if (*(long *)(param_1 + 0x20) == 0) {
        return 2;
      }
    }
    if (param_3 != 0) {
      iVar5 = FUN_0013ef00(param_1,local_88);
      if (iVar5 == 0) {
        iVar5 = FUN_001335a0();
        uVar13 = DAT_01216968;
        if (iVar5 == 0) {
          local_98 = 0;
          iVar5 = __isoc99_sscanf(local_64,"%x:%x.%x",&local_94,&local_90,&local_8c);
          if ((iVar5 == 3) ||
             (iVar5 = __isoc99_sscanf(local_64,&DAT_0029adca,&local_98,&local_94,&local_90,&local_8c
                                     ), iVar5 == 4)) {
            uVar10 = local_98;
            lVar8 = 0;
            do {
              iVar5 = FUN_00257fb0(uVar13,0xf);
              if (iVar5 + 2U < 2) goto LAB_00132840;
              if (lVar8 == 0) {
                lVar8 = FUN_002580d2(uVar13,iVar5,0);
              }
              else {
                if (iVar5 != *(int *)(lVar8 + 0x30)) goto LAB_00132840;
                lVar8 = *(long *)(lVar8 + 0x38);
              }
              if (lVar8 == 0) goto LAB_00132840;
              puVar4 = *(ushort **)(lVar8 + 0x28);
            } while ((((uVar10 != *puVar4) || (local_94 != (byte)puVar4[1])) ||
                     (local_90 != *(byte *)((long)puVar4 + 3))) || (local_8c != (byte)puVar4[2]));
            uVar16 = 0;
            for (lVar8 = *(long *)(lVar8 + 0x48); lVar8 != 0; lVar8 = *(long *)(lVar8 + 0x48)) {
              if (*(int *)(*(long *)(lVar8 + 0x28) + 0x18) == 0) {
                if (4 < DAT_01216a78) {
                  fVar17 = (float)FUN_002917b0(&DAT_01216a60);
                  lVar8 = syscall(0xba);
                  FUN_002340f0((double)(fVar17 * DAT_00298548),
                               "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n","DEBUG",lVar8,
                               "common/nvhwloc.c",0x2f1);
                }
                *param_2 = (int)uVar16;
                return 0;
              }
              uVar3 = *(undefined4 *)(lVar8 + 0x34);
              puVar1 = (undefined4 *)(param_3 + uVar16 * 0x1c);
              *puVar1 = uVar3;
              iVar5 = DAT_01216a78;
              uVar2 = **(ushort **)(lVar8 + 0x28);
              puVar1[1] = (uint)uVar2;
              uVar10 = (uint)*(byte *)(*(long *)(lVar8 + 0x28) + 0x10);
              puVar1[2] = uVar10;
              uVar11 = (uint)*(byte *)(*(long *)(lVar8 + 0x28) + 2);
              puVar1[3] = uVar11;
              uVar12 = (uint)*(byte *)(*(long *)(lVar8 + 0x28) + 0x1e);
              puVar1[4] = uVar12;
              uVar14 = (uint)*(ushort *)(*(long *)(lVar8 + 0x28) + 8);
              puVar1[5] = uVar14;
              uVar15 = (uint)*(ushort *)(*(long *)(lVar8 + 0x28) + 10);
              puVar1[6] = uVar15;
              if (4 < iVar5) {
                fVar17 = (float)FUN_002917b0(&DAT_01216a60);
                lVar7 = syscall(0xba);
                FUN_002340f0((double)(fVar17 * DAT_00298548),
                             "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%d %d %d %d %d %d %d\n","DEBUG",
                             lVar7,"common/nvhwloc.c",0x2e9,uVar3,(uint)uVar2,uVar10,uVar11,uVar12,
                             uVar14,uVar15);
              }
              uVar16 = (ulong)((int)uVar16 + 1);
            }
            if (1 < DAT_01216a78) {
              fVar17 = (float)FUN_002917b0(&DAT_01216a60);
              lVar8 = syscall(0xba);
              FUN_002340f0((double)(fVar17 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t\n",
                           "ERROR",lVar8,"common/nvhwloc.c",0x2dd);
              return 999;
            }
          }
          else {
            piVar9 = __errno_location();
            *piVar9 = 0x16;
LAB_00132840:
            if (1 < DAT_01216a78) {
              fVar17 = (float)FUN_002917b0(&DAT_01216a60);
              lVar8 = syscall(0xba);
              FUN_002340f0((double)(fVar17 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s\n"
                           ,"ERROR",lVar8,"common/nvhwloc.c",0x2d6,local_64);
            }
          }
          return 999;
        }
        iVar5 = 3;
        if (DAT_01216a78 < 2) {
          return 3;
        }
        iVar6 = FUN_001335a0();
        fVar17 = (float)FUN_002917b0(&DAT_01216a60);
        lVar8 = syscall(0xba);
        fVar17 = fVar17 * DAT_00298548;
        uVar18 = 0x2d0;
        uVar13 = 0x2d0;
      }
      else {
        if (DAT_01216a78 < 2) {
          return iVar5;
        }
        fVar17 = (float)FUN_002917b0(&DAT_01216a60);
        lVar8 = syscall(0xba);
        fVar17 = fVar17 * DAT_00298548;
        uVar18 = 0x2ce;
        uVar13 = 0x2ce;
        iVar6 = iVar5;
      }
      FUN_002340f0((double)fVar17,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar8,
                   "common/nvhwloc.c",uVar13,"nvhwlocDeviceGetUpstreamBridgesInfo",uVar18,iVar6);
      return iVar5;
    }
  }
  return 2;
}


// ===== 00132980 FUN_00132980 =====

undefined8 FUN_00132980(char *param_1,void *param_2,long param_3)

{
  int __fd;
  undefined8 uVar1;
  ssize_t sVar2;
  
  if ((param_2 != (void *)0x0 && param_3 != 0) && (param_1 != (char *)0x0)) {
    __fd = open(param_1,0);
    uVar1 = 4;
    if (-1 < __fd) {
      sVar2 = read(__fd,param_2,param_3 - 1);
      *(undefined1 *)((long)param_2 + sVar2) = 0;
      close(__fd);
      uVar1 = 0;
    }
    return uVar1;
  }
  return 2;
}


// ===== 00132a00 FUN_00132a00 =====

int FUN_00132a00(undefined8 param_1,ulonglong *param_2)

{
  int iVar1;
  ulonglong uVar2;
  char *local_b0;
  char local_a8 [136];
  
  iVar1 = FUN_00132980(param_1,local_a8,0x80);
  if (iVar1 == 0) {
    uVar2 = strtoull(local_a8,&local_b0,0);
    *param_2 = uVar2;
    if (local_b0 == local_a8) {
      iVar1 = 999;
    }
  }
  return iVar1;
}


// ===== 00132a70 FUN_00132a70 =====

void FUN_00132a70(char *param_1)

{
  char *pcVar1;
  
  pcVar1 = strchr(param_1,10);
  if (pcVar1 != (char *)0x0) {
    *pcVar1 = '\0';
  }
  return;
}


// ===== 00132a90 FUN_00132a90 =====

int FUN_00132a90(long param_1,int param_2,char *param_3)

{
  int iVar1;
  DIR *__dirp;
  dirent *pdVar2;
  char *pcVar3;
  DIR *__dirp_00;
  char *pcVar4;
  long lVar5;
  int iVar6;
  uint local_52c;
  long local_528;
  long local_520;
  char local_518 [32];
  char local_4f8 [8];
  char acStack_4f0 [8];
  char local_4e8 [8];
  char acStack_4e0 [8];
  undefined2 local_4d8;
  undefined1 local_4d6;
  stat local_4c8;
  char local_438 [512];
  char local_238 [520];
  
  local_4f8 = (char  [8])s__sys_bus_i2c_devices_2_0040_hwmo_0029b100._0_8_;
  acStack_4f0 = (char  [8])s__sys_bus_i2c_devices_2_0040_hwmo_0029b100._8_8_;
  local_4d8 = 0x2f6e;
  local_4d6 = 0;
  local_4e8 = (char  [8])s__sys_bus_i2c_devices_2_0040_hwmo_0029b100._16_8_;
  acStack_4e0 = (char  [8])s__sys_bus_i2c_devices_2_0040_hwmo_0029b100._24_8_;
  __dirp = opendir(local_4f8);
  if (__dirp != (DIR *)0x0) {
    iVar6 = 0;
    while ((pdVar2 = readdir(__dirp), pdVar2 != (dirent *)0x0 && (iVar6 < param_2))) {
      snprintf(local_438,0x200,"%s%s",local_4f8,pdVar2->d_name);
      iVar1 = __xstat(1,local_438,&local_4c8);
      if (((iVar1 == 0) && ((local_4c8.st_mode & 0xf000) == 0x4000)) &&
         (pcVar3 = strstr(pdVar2->d_name,"hwmon"), pcVar3 != (char *)0x0)) {
        __dirp_00 = opendir(local_438);
        while ((pdVar2 = readdir(__dirp_00), pdVar2 != (dirent *)0x0 && (iVar6 < param_2))) {
          pcVar3 = pdVar2->d_name;
          pcVar4 = strstr(pcVar3,"in");
          if ((pcVar4 != (char *)0x0) && (pcVar4 = strstr(pcVar3,"_label"), pcVar4 != (char *)0x0))
          {
            snprintf(local_238,0x200,"%s/%s",local_438,pcVar3);
            iVar1 = FUN_00132980(local_238,local_518,0x20);
            if ((iVar1 == 0) &&
               (((FUN_00132a70(local_518), param_3 == (char *)0x0 ||
                 (iVar1 = strcmp(local_518,param_3), iVar1 == 0)) &&
                (iVar1 = __isoc99_sscanf(pcVar3,"in%d_label",&local_52c), iVar1 == 1)))) {
              snprintf(local_238,0x200,"%s/in%d_input",local_438,(ulong)local_52c);
              iVar1 = FUN_00132a00(local_238,&local_528);
              if (iVar1 == 0) {
                snprintf(local_238,0x200,"%s/curr%d_input",local_438,(ulong)local_52c);
                iVar1 = FUN_00132a00(local_238,&local_520);
                if (iVar1 == 0) {
                  lVar5 = (long)iVar6;
                  iVar6 = iVar6 + 1;
                  pcVar3 = strncpy((char *)(param_1 + lVar5 * 0x24),local_518,0x20);
                  *(int *)(pcVar3 + 0x20) = (int)((ulong)(local_528 * local_520) / 1000);
                }
              }
            }
          }
        }
        closedir(__dirp_00);
      }
    }
    closedir(__dirp);
    return iVar6;
  }
  return 0;
}


// ===== 00132db0 FUN_00132db0 =====

int FUN_00132db0(long param_1,int param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  DIR *__dirp;
  dirent *pdVar3;
  FILE *__stream;
  FILE *__stream_00;
  char *pcVar4;
  long lVar5;
  byte *pbVar6;
  int iVar7;
  bool bVar8;
  bool bVar9;
  byte bVar10;
  char local_258 [32];
  char local_238 [256];
  char local_138 [264];
  
  bVar10 = 0;
  __dirp = opendir("/sys/class/thermal/");
  if (__dirp == (DIR *)0x0) {
    return -1;
  }
  iVar7 = 0;
  do {
    do {
      do {
        pdVar3 = readdir(__dirp);
        if ((pdVar3 == (dirent *)0x0) || (bVar8 = false, param_2 <= iVar7)) {
          closedir(__dirp);
          return iVar7;
        }
        lVar5 = 0xc;
        bVar9 = false;
        pcVar4 = pdVar3->d_name;
        pbVar6 = (byte *)"thermal_zone";
        do {
          if (lVar5 == 0) break;
          lVar5 = lVar5 + -1;
          bVar8 = (byte)*pcVar4 < *pbVar6;
          bVar9 = *pcVar4 == *pbVar6;
          pcVar4 = pcVar4 + (ulong)bVar10 * -2 + 1;
          pbVar6 = pbVar6 + (ulong)bVar10 * -2 + 1;
        } while (bVar9);
      } while ((!bVar8 && !bVar9) != bVar8);
      snprintf(local_238,0x100,"%s%s/type","/sys/class/thermal/");
      snprintf(local_138,0x100,"%s%s/temp","/sys/class/thermal/",pdVar3->d_name);
      __stream = fopen(local_238,"r");
      __stream_00 = fopen(local_138,"r");
    } while ((__stream == (FILE *)0x0) || (__stream_00 == (FILE *)0x0));
    pcVar4 = fgets(local_258,0x20,__stream);
    if (pcVar4 != (char *)0x0) {
      if ((local_258[0] == '\0') || (local_258[0] == '\n')) {
        lVar5 = 0;
      }
      else {
        lVar5 = 0;
        do {
          lVar5 = lVar5 + 1;
          cVar1 = local_258[lVar5];
          if (cVar1 == '\n') break;
        } while (cVar1 != '\0');
      }
      local_258[lVar5] = '\0';
    }
    if ((param_3 == (char *)0x0) || (iVar2 = strncmp(local_258,param_3,0x20), iVar2 == 0)) {
      lVar5 = (long)iVar7;
      iVar7 = iVar7 + 1;
      pcVar4 = strncpy((char *)(param_1 + lVar5 * 0x24),local_258,0x20);
      __isoc99_fscanf(__stream_00,&DAT_002ae737,pcVar4 + 0x20);
    }
    fclose(__stream);
    fclose(__stream_00);
  } while( true );
}


// ===== 00132ff0 FUN_00132ff0 =====

ulong FUN_00132ff0(long param_1)

{
  uint uVar1;
  long lVar2;
  undefined8 extraout_RDX;
  undefined8 uVar3;
  ulong uVar4;
  float fVar5;
  double dVar6;
  undefined8 uVar7;
  ulong uVar8;
  float local_2c;
  
  if (param_1 == 0) {
    return 2;
  }
  uVar1 = FUN_00133390(&PTR_FUN_0037fb20);
  uVar4 = (ulong)uVar1;
  if (uVar1 == 0) {
    uVar1 = FUN_00133450(&PTR_FUN_0037f9a0);
    uVar4 = (ulong)uVar1;
    if (uVar1 == 0) {
      uVar1 = FUN_001334f0(&PTR_FUN_0037f200);
      uVar4 = (ulong)uVar1;
      if (uVar1 == 0) {
        *(undefined8 **)(param_1 + 0x170) = &DAT_012164e0;
        *(undefined8 **)(param_1 + 0x160) = &DAT_01216740;
        *(undefined8 **)(param_1 + 0x118) = &DAT_012168a0;
        return 0;
      }
      if (DAT_01216a78 < 2) {
        return uVar4;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      uVar7 = 0x1d;
      uVar3 = 0x1d;
      local_2c = DAT_00298548;
      dVar6 = (double)(fVar5 * DAT_00298548);
    }
    else {
      if (DAT_01216a78 < 2) {
        return uVar4;
      }
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      uVar7 = 0x1a;
      uVar3 = 0x1a;
      local_2c = DAT_00298548;
      dVar6 = (double)(fVar5 * DAT_00298548);
    }
  }
  else {
    if (DAT_01216a78 < 2) {
      return uVar4;
    }
    fVar5 = (float)FUN_002917b0(&DAT_01216a60);
    lVar2 = syscall(0xba);
    local_2c = DAT_00298548;
    uVar7 = 0x17;
    uVar3 = 0x17;
    dVar6 = (double)(fVar5 * DAT_00298548);
  }
  DAT_00298548 = local_2c;
  uVar8 = uVar4;
  FUN_002340f0(dVar6,"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar2,
               "dmal/sysfs/sysfs_layer.c",uVar3,"_nvmlSysfsInitializeSysfsDMALComponents");
  if (DAT_01216a78 < 2) {
    return uVar4;
  }
  fVar5 = (float)FUN_002917b0(&DAT_01216a60,uVar8,extraout_RDX,uVar7);
  lVar2 = syscall(0xba);
  FUN_002340f0((double)(fVar5 * local_2c),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",
               lVar2,"dmal/sysfs/sysfs_layer.c",0x2c,"sInjectSysfsDMAL",0x2c,uVar4);
  return uVar4;
}


// ===== 00133270 FUN_00133270 =====

char FUN_00133270(undefined8 param_1,undefined8 param_2,int param_3)

{
  char cVar1;
  
  cVar1 = '\0';
  if (param_3 != 0) {
    cVar1 = (param_3 != 3) * '\x03';
  }
  return cVar1;
}


// ===== 00133290 FUN_00133290 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00133290(undefined8 param_1,undefined8 param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  float fVar4;
  uint local_20 [2];
  
  if (param_3 == 0) {
    pcVar3 = "/sys/class/devfreq/gpu-gpc-0/cur_freq";
  }
  else {
    if (param_3 != 3) {
      if (DAT_01216a78 < 2) {
        return 3;
      }
      fVar4 = (float)FUN_002917b0(&DAT_01216a60);
      lVar2 = syscall(0xba);
      FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar2,"dmal/sysfs/sysfs_clock.c",0x20,"sDeviceGetClockInfo",0x20,3);
      return 3;
    }
    pcVar3 = "/sys/class/devfreq/gpu-nvd-0/cur_freq";
  }
  iVar1 = FUN_00132a00(pcVar3,local_20);
  if (iVar1 != 0) {
    return iVar1;
  }
  *param_4 = (int)(long)((double)local_20[0] * _DAT_0029b208);
  return 0;
}


// ===== 00133390 FUN_00133390 =====

undefined8 FUN_00133390(undefined8 *param_1)

{
  long lVar1;
  undefined8 *puVar2;
  
  if (param_1 != (undefined8 *)0x0) {
    puVar2 = &DAT_012164e0;
    for (lVar1 = 0x4b; lVar1 != 0; lVar1 = lVar1 + -1) {
      *puVar2 = *param_1;
      param_1 = param_1 + 1;
      puVar2 = puVar2 + 1;
    }
    DAT_01216500 = FUN_00133290;
    DAT_01216728 = FUN_00133270;
    return 0;
  }
  return 2;
}


// ===== 001333e0 FUN_001333e0 =====

undefined8
FUN_001333e0(undefined8 param_1,undefined8 param_2,char param_3,undefined4 *param_4,uint param_5)

{
  int iVar1;
  undefined1 local_48 [32];
  undefined4 local_28;
  
  if (((param_5 & 0xfffffffd) == 0) && (param_3 == '\0')) {
    iVar1 = FUN_00132a90(local_48,1,"VDD_GPU");
    if (iVar1 == 1) {
      *param_4 = local_28;
      return 0;
    }
  }
  return 3;
}


// ===== 00133450 FUN_00133450 =====

undefined8 FUN_00133450(undefined8 *param_1)

{
  long lVar1;
  undefined8 *puVar2;
  
  if (param_1 != (undefined8 *)0x0) {
    puVar2 = &DAT_01216740;
    for (lVar1 = 0x2a; lVar1 != 0; lVar1 = lVar1 + -1) {
      *puVar2 = *param_1;
      param_1 = param_1 + 1;
      puVar2 = puVar2 + 1;
    }
    DAT_01216748 = FUN_001333e0;
    return 0;
  }
  return 2;
}


// ===== 00133490 FUN_00133490 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00133490(void)

{
  int iVar1;
  undefined8 uVar2;
  int *in_RCX;
  undefined1 local_48 [32];
  uint local_28;
  
  iVar1 = FUN_00132db0(local_48,1,"gpu-thermal");
  uVar2 = 3;
  if (iVar1 == 1) {
    *in_RCX = (int)((double)local_28 * _DAT_0029b228);
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 001334f0 FUN_001334f0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_001334f0(long param_1)

{
  if (param_1 != 0) {
    uRam00000000012168a8 = *(undefined8 *)(param_1 + 8);
    DAT_012168a0 = FUN_00133490;
    _DAT_012168b0 = *(undefined8 *)(param_1 + 0x10);
    uRam00000000012168b8 = *(undefined8 *)(param_1 + 0x18);
    _DAT_012168c0 = *(undefined8 *)(param_1 + 0x20);
    uRam00000000012168c8 = *(undefined8 *)(param_1 + 0x28);
    _DAT_012168d0 = *(undefined8 *)(param_1 + 0x30);
    uRam00000000012168d8 = *(undefined8 *)(param_1 + 0x38);
    _DAT_012168e0 = *(undefined8 *)(param_1 + 0x40);
    uRam00000000012168e8 = *(undefined8 *)(param_1 + 0x48);
    _DAT_012168f0 = *(undefined8 *)(param_1 + 0x50);
    uRam00000000012168f8 = *(undefined8 *)(param_1 + 0x58);
    _DAT_01216900 = *(undefined8 *)(param_1 + 0x60);
    uRam0000000001216908 = *(undefined8 *)(param_1 + 0x68);
    _DAT_01216910 = *(undefined8 *)(param_1 + 0x70);
    uRam0000000001216918 = *(undefined8 *)(param_1 + 0x78);
    _DAT_01216920 = *(undefined8 *)(param_1 + 0x80);
    uRam0000000001216928 = *(undefined8 *)(param_1 + 0x88);
    _DAT_01216930 = *(undefined8 *)(param_1 + 0x90);
    uRam0000000001216938 = *(undefined8 *)(param_1 + 0x98);
    _DAT_01216940 = *(undefined8 *)(param_1 + 0xa0);
    uRam0000000001216948 = *(undefined8 *)(param_1 + 0xa8);
    _DAT_01216950 = *(undefined8 *)(param_1 + 0xb0);
    uRam0000000001216958 = *(undefined8 *)(param_1 + 0xb8);
    return 0;
  }
  return 2;
}


// ===== 001335a0 FUN_001335a0 =====

bool FUN_001335a0(void)

{
  int iVar1;
  bool bVar2;
  
  do {
    iVar1 = FUN_00291820(&DAT_01216960,1,0);
  } while (iVar1 != 0);
  bVar2 = false;
  if (DAT_01216968 == 0) {
    bVar2 = true;
    iVar1 = FUN_002541df(&DAT_01216968);
    if (iVar1 == 0) {
      iVar1 = FUN_00254366(DAT_01216968,0);
      if (iVar1 == 0) {
        iVar1 = FUN_002545c4(DAT_01216968);
        bVar2 = iVar1 != 0;
      }
    }
  }
  FUN_00291830(&DAT_01216960,0);
  return bVar2;
}


// ===== 00133630 FUN_00133630 =====

void FUN_00133630(void)

{
  if (DAT_01216968 != 0) {
    FUN_002544f4();
    DAT_01216968 = 0;
  }
  return;
}


// ===== 00133660 FUN_00133660 =====

char * FUN_00133660(int param_1)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = &DAT_00324790;
  iVar3 = 1;
  uVar2 = 0;
  while( true ) {
    if (iVar3 == param_1) {
      return *(char **)(&UNK_00324788 + uVar2 * 0x10);
    }
    uVar1 = (int)uVar2 + 1;
    uVar2 = (ulong)uVar1;
    if (uVar1 == 0x10) break;
    iVar3 = *piVar4;
    piVar4 = piVar4 + 4;
  }
  return "Unknown";
}


// ===== 001336b0 FUN_001336b0 =====

char * FUN_001336b0(int param_1)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = &DAT_00324794;
  iVar3 = 0x1f;
  uVar2 = 0;
  while( true ) {
    if (iVar3 == param_1) {
      return *(char **)(&UNK_00324788 + uVar2 * 0x10);
    }
    uVar1 = (int)uVar2 + 1;
    uVar2 = (ulong)uVar1;
    if (uVar1 == 0x10) break;
    iVar3 = *piVar4;
    piVar4 = piVar4 + 4;
  }
  return "Unknown";
}


// ===== 00133700 FUN_00133700 =====

undefined8 FUN_00133700(int param_1,undefined4 *param_2)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = &DAT_00324790;
  iVar3 = 1;
  uVar2 = 0;
  while( true ) {
    if (iVar3 == param_1) {
      *param_2 = *(undefined4 *)(&UNK_00324784 + uVar2 * 0x10);
      return 0;
    }
    uVar1 = (int)uVar2 + 1;
    uVar2 = (ulong)uVar1;
    if (uVar1 == 0x10) break;
    iVar3 = *piVar4;
    piVar4 = piVar4 + 4;
  }
  return 999;
}


// ===== 00133750 FUN_00133750 =====

undefined8 FUN_00133750(int param_1,undefined4 *param_2)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = &DAT_00324794;
  iVar3 = 0x1f;
  uVar2 = 0;
  while( true ) {
    if (iVar3 == param_1) {
      *param_2 = *(undefined4 *)(&DAT_00324780 + uVar2 * 0x10);
      return 0;
    }
    uVar1 = (int)uVar2 + 1;
    uVar2 = (ulong)uVar1;
    if (uVar1 == 0x10) break;
    iVar3 = *piVar4;
    piVar4 = piVar4 + 4;
  }
  return 2;
}


// ===== 001337a0 FUN_001337a0 =====

char * FUN_001337a0(int param_1)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = &DAT_003246b0;
  iVar3 = 1;
  uVar2 = 0;
  while( true ) {
    if (iVar3 == param_1) {
      return *(char **)(&UNK_003246a8 + uVar2 * 0x10);
    }
    uVar1 = (int)uVar2 + 1;
    uVar2 = (ulong)uVar1;
    if (uVar1 == 0xe) break;
    iVar3 = *piVar4;
    piVar4 = piVar4 + 4;
  }
  return "Unknown";
}


// ===== 001337f0 FUN_001337f0 =====

undefined4 FUN_001337f0(int param_1)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = &DAT_003246b4;
  iVar3 = 0;
  uVar2 = 0;
  while( true ) {
    if (iVar3 == param_1) {
      return *(undefined4 *)(&DAT_003246a0 + uVar2 * 0x10);
    }
    uVar1 = (int)uVar2 + 1;
    uVar2 = (ulong)uVar1;
    if (uVar1 == 0xe) break;
    iVar3 = *piVar4;
    piVar4 = piVar4 + 4;
  }
  return 0xffffffff;
}


// ===== 00133830 FUN_00133830 =====

undefined4 FUN_00133830(int param_1)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = &DAT_003245b0;
  iVar3 = 1;
  uVar2 = 0;
  while( true ) {
    if (iVar3 == param_1) {
      return *(undefined4 *)(&UNK_003245a4 + uVar2 * 0x10);
    }
    uVar1 = (int)uVar2 + 1;
    uVar2 = (ulong)uVar1;
    if (uVar1 == 0x10) break;
    iVar3 = *piVar4;
    piVar4 = piVar4 + 4;
  }
  return 0x20;
}


// ===== 00133870 FUN_00133870 =====

undefined8 FUN_00133870(int param_1,undefined4 *param_2)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = &DAT_003245b4;
  iVar3 = 0;
  uVar2 = 0;
  while( true ) {
    if (iVar3 == param_1) {
      *param_2 = *(undefined4 *)(&DAT_003245a0 + uVar2 * 0x10);
      return 0;
    }
    uVar1 = (int)uVar2 + 1;
    uVar2 = (ulong)uVar1;
    if (uVar1 == 0x10) break;
    iVar3 = *piVar4;
    piVar4 = piVar4 + 4;
  }
  return 2;
}


// ===== 001338c0 FUN_001338c0 =====

undefined8 FUN_001338c0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 1) {
    uVar1 = 0;
  }
  else if (param_1 == 2) {
    uVar1 = 1;
  }
  else if (param_1 == 4) {
    uVar1 = 2;
  }
  else {
    if (param_1 != 8) {
      return 999;
    }
    uVar1 = 3;
  }
  *param_2 = uVar1;
  return 0;
}


// ===== 00133920 FUN_00133920 =====

undefined8 FUN_00133920(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 1;
  }
  else if (param_1 == 1) {
    uVar1 = 2;
  }
  else if (param_1 == 2) {
    uVar1 = 4;
  }
  else {
    if (param_1 != 3) {
      return 2;
    }
    uVar1 = 8;
  }
  *param_2 = uVar1;
  return 0;
}


// ===== 00133980 FUN_00133980 =====

int FUN_00133980(int param_1)

{
  if (param_1 == 0) {
    return 0;
  }
  if (param_1 == 1) {
    return 1;
  }
  if (param_1 == 2) {
    return 2;
  }
  if (param_1 != 3) {
    return (uint)(param_1 == 4) * 5 + -1;
  }
  return 3;
}


// ===== 001339d0 FUN_001339d0 =====

undefined4 FUN_001339d0(int param_1)

{
  ulong uVar1;
  int iVar2;
  
  uVar1 = 0;
  iVar2 = 0;
  while( true ) {
    if (iVar2 == param_1) {
      return *(undefined4 *)(&DAT_0029b6a4 + (uVar1 & 0xffffffff) * 8);
    }
    uVar1 = uVar1 + 1;
    if (uVar1 == 0xc) break;
    iVar2 = *(int *)(&DAT_0029b6a0 + uVar1 * 8);
  }
  return 0xffffffff;
}


// ===== 00133a10 FUN_00133a10 =====

undefined4 FUN_00133a10(uint param_1)

{
  if ((((param_1 != 0) && (param_1 != 1)) && (param_1 != 2)) &&
     (((param_1 != 3 && (param_1 != 4)) && (param_1 != 5)))) {
    return 999;
  }
  return *(undefined4 *)(&DAT_0029b664 + (ulong)param_1 * 8);
}


// ===== 00133a50 FUN_00133a50 =====

undefined8 FUN_00133a50(int param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = 2;
  if (param_1 == 0) {
    *param_2 = 0;
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 00133a70 FUN_00133a70 =====

undefined8 FUN_00133a70(int param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = 999;
  if (param_1 == 0) {
    *param_2 = 0;
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 00133a90 FUN_00133a90 =====

undefined8 FUN_00133a90(int param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = 2;
  if (param_1 == 0) {
    *param_2 = 0;
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 00133ab0 FUN_00133ab0 =====

undefined8 FUN_00133ab0(int param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = 999;
  if (param_1 == 0) {
    *param_2 = 0;
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 00133ad0 FUN_00133ad0 =====

undefined8 FUN_00133ad0(char param_1,undefined4 *param_2)

{
  uint uVar1;
  ulong uVar2;
  char cVar3;
  char *pcVar4;
  
  pcVar4 = "\x01";
  cVar3 = '\0';
  uVar2 = 0;
  while( true ) {
    if (cVar3 == param_1) {
      *param_2 = *(undefined4 *)(&UNK_003244a4 + uVar2 * 0x10);
      return 0;
    }
    uVar1 = (int)uVar2 + 1;
    uVar2 = (ulong)uVar1;
    if (uVar1 == 0xf) break;
    cVar3 = *pcVar4;
    pcVar4 = pcVar4 + 0x10;
  }
  return 2;
}


// ===== 00133b20 FUN_00133b20 =====

undefined8 FUN_00133b20(int param_1,undefined1 *param_2)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = &DAT_003244b4;
  iVar3 = 0;
  uVar2 = 0;
  while( true ) {
    if (iVar3 == param_1) {
      *param_2 = (&DAT_003244a0)[uVar2 * 0x10];
      return 0;
    }
    uVar1 = (int)uVar2 + 1;
    uVar2 = (ulong)uVar1;
    if (uVar1 == 0xf) break;
    iVar3 = *piVar4;
    piVar4 = piVar4 + 4;
  }
  return 2;
}


// ===== 00133b70 FUN_00133b70 =====

undefined8 FUN_00133b70(int param_1,undefined4 *param_2)

{
  ulong uVar1;
  int iVar2;
  
  uVar1 = 0;
  iVar2 = 0;
  while( true ) {
    if (iVar2 == param_1) {
      *param_2 = (&DAT_0029b240)[(uVar1 & 0xffffffff) * 2];
      return 0;
    }
    uVar1 = uVar1 + 1;
    if (uVar1 == 0x20) break;
    iVar2 = (&DAT_0029b244)[uVar1 * 2];
  }
  return 2;
}


// ===== 00133bb0 FUN_00133bb0 =====

undefined8 FUN_00133bb0(int param_1,undefined4 *param_2)

{
  ulong uVar1;
  int iVar2;
  
  uVar1 = 0;
  iVar2 = 0;
  while( true ) {
    if (iVar2 == param_1) {
      *param_2 = (&DAT_0029b244)[(uVar1 & 0xffffffff) * 2];
      return 0;
    }
    uVar1 = uVar1 + 1;
    if (uVar1 == 0x20) break;
    iVar2 = (&DAT_0029b240)[uVar1 * 2];
  }
  return 999;
}


// ===== 00133bf0 FUN_00133bf0 =====

undefined8 FUN_00133bf0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    if (param_1 == 2) {
      uVar1 = 1;
    }
    else if (param_1 == 3) {
      uVar1 = 2;
    }
    else {
      if (param_1 != 4) {
        return 3;
      }
      uVar1 = 3;
    }
  }
  *param_2 = uVar1;
  return 0;
}


// ===== 00133c40 FUN_00133c40 =====

undefined8 FUN_00133c40(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    if (param_1 == 1) {
      uVar1 = 2;
    }
    else if (param_1 == 2) {
      uVar1 = 3;
    }
    else {
      if (param_1 != 3) {
        return 3;
      }
      uVar1 = 4;
    }
  }
  *param_2 = uVar1;
  return 0;
}


// ===== 00133c90 FUN_00133c90 =====

undefined8 FUN_00133c90(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (param_1 != 1) {
    if (param_1 == 3) {
      uVar1 = 0x1b;
    }
    else if (param_1 == 2) {
      uVar1 = 0x1c;
    }
    else {
      if (param_1 != 0) {
        return 2;
      }
      uVar1 = 1;
    }
  }
  *param_2 = uVar1;
  return 0;
}


// ===== 00133ce0 FUN_00133ce0 =====

undefined8 FUN_00133ce0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (param_1 != 1) {
    if (param_1 == 0x1b) {
      uVar1 = 3;
    }
    else {
      if (param_1 != 0x1c) {
        return 2;
      }
      uVar1 = 2;
    }
  }
  *param_2 = uVar1;
  return 0;
}


// ===== 00133d10 FUN_00133d10 =====

bool FUN_00133d10(char *param_1)

{
  char *pcVar1;
  
  if (param_1 != (char *)0x0) {
    if (*param_1 == '\0') {
      return false;
    }
    pcVar1 = *(char **)(param_1 + 0x74aa0);
    if ((*(long *)(param_1 + 0x28) == 0) && (pcVar1 != (char *)0x0)) {
      if (*pcVar1 == '\x01') {
        return true;
      }
      if (*(int *)(pcVar1 + 0x14) == 0) {
        return false;
      }
      if (*(int *)(pcVar1 + 0x1c) != 0) {
        return false;
      }
      if (*(int *)(pcVar1 + 0x10) == 0) {
        return false;
      }
      return *(long *)(pcVar1 + 0x20) != 0;
    }
  }
  return false;
}


// ===== 00133d60 FUN_00133d60 =====

long * FUN_00133d60(long param_1,int param_2,undefined4 param_3)

{
  undefined8 *puVar1;
  code *pcVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  long *plVar6;
  long local_a8 [4];
  long local_88;
  long lStack_80;
  long local_78;
  long lStack_70;
  long local_68;
  long lStack_60;
  long local_58;
  long lStack_50;
  long local_48;
  long lStack_40;
  long local_38;
  long lStack_30;
  
  plVar6 = local_a8;
  for (lVar5 = 0x10; lVar5 != 0; lVar5 = lVar5 + -1) {
    *plVar6 = 0;
    plVar6 = plVar6 + 1;
  }
  puVar1 = DAT_01216970;
  if ((undefined8 **)DAT_01216970 != &DAT_01216970) {
    do {
      if ((param_2 == *(int *)(puVar1 + -0x11)) && (param_1 == puVar1[-0x12])) {
        return puVar1 + -0x12;
      }
      puVar1 = (undefined8 *)*puVar1;
    } while ((undefined8 **)puVar1 != &DAT_01216970);
  }
  lVar5 = *(long *)(param_1 + 0x256d8);
  if ((((lVar5 != 0) && (*(long *)(lVar5 + 0x30) != 0)) &&
      (pcVar2 = *(code **)(*(long *)(lVar5 + 0x30) + 0x30), pcVar2 != (code *)0x0)) &&
     (iVar3 = (*pcVar2)(lVar5,param_1,param_2,local_a8), iVar3 == 0)) {
    plVar4 = malloc(0xa0);
    plVar6 = DAT_01216978;
    if (plVar4 == (long *)0x0) {
      return (long *)0x0;
    }
    *plVar4 = param_1;
    *(int *)(plVar4 + 1) = param_2;
    *(undefined4 *)((long)plVar4 + 0xc) = param_3;
    plVar4[2] = local_a8[0];
    plVar4[3] = local_a8[1];
    plVar4[4] = local_a8[2];
    plVar4[5] = local_a8[3];
    plVar4[6] = local_88;
    plVar4[7] = lStack_80;
    plVar4[8] = local_78;
    plVar4[9] = lStack_70;
    plVar4[10] = local_68;
    plVar4[0xb] = lStack_60;
    plVar4[0xc] = local_58;
    plVar4[0xd] = lStack_50;
    plVar4[0xe] = local_48;
    plVar4[0xf] = lStack_40;
    plVar4[0x10] = local_38;
    plVar4[0x11] = lStack_30;
    lVar5 = *plVar6;
    plVar4[0x13] = (long)plVar6;
    plVar4[0x12] = lVar5;
    *(long **)(*plVar6 + 8) = plVar4 + 0x12;
    *plVar6 = (long)(plVar4 + 0x12);
    return plVar4;
  }
  return (long *)0x0;
}


// ===== 00133ed0 FUN_00133ed0 =====

int FUN_00133ed0(uint param_1,char *param_2,undefined8 *param_3)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  float fVar5;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_40;
  
  if (param_2 != (char *)0x0) {
    if ((*param_2 == '\x01') || (*(long *)(param_2 + 0x20) != 0)) {
      param_2 = (char *)0x0;
    }
    else {
      param_2 = param_2 + -8;
    }
  }
  cVar2 = FUN_00133d10(param_2);
  iVar3 = 2;
  if (cVar2 != '\0') {
    if (((DAT_012164a0 == 0) || (*(long *)(DAT_012164a0 + 0x30) == 0)) ||
       (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 200), pcVar1 == (code *)0x0)) {
      iVar3 = 3;
    }
    else {
      iVar3 = (*pcVar1)(DAT_012164a0,param_2 + 0x74a08,&local_68);
      if (iVar3 == 0) {
        *param_3 = local_60;
        param_3[1] = local_58;
        param_3[2] = local_50;
        if (param_1 < 2) {
          return 0;
        }
        param_3[4] = local_40;
        *(undefined4 *)(param_3 + 3) = local_64;
        *(undefined4 *)((long)param_3 + 0x1c) = local_68;
        return 0;
      }
    }
    if (1 < DAT_01216a78) {
      fVar5 = (float)FUN_002917b0(&DAT_01216a60);
      lVar4 = syscall(0xba);
      FUN_002340f0((double)(fVar5 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                   "ERROR",lVar4,"nvml_mig.c",0x54,"tsmigGetMigDeviceAttributes",0x54,iVar3);
      return iVar3;
    }
  }
  return iVar3;
}


// ===== 00134020 FUN_00134020 =====

int FUN_00134020(long param_1,undefined4 param_2,long param_3,uint *param_4)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  void *__ptr;
  uint uVar4;
  ulong uVar5;
  float fVar6;
  uint local_3c [3];
  
  lVar3 = *(long *)(param_1 + 0x256d8);
  if (((lVar3 == 0) || (*(long *)(lVar3 + 0x30) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(lVar3 + 0x30) + 0x98), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar3,param_1,local_3c);
    if (iVar2 == 0) {
      __ptr = malloc((ulong)local_3c[0] << 2);
      if (__ptr == (void *)0x0) {
        return 0x14;
      }
      lVar3 = *(long *)(param_1 + 0x256d8);
      if (((lVar3 == 0) || (*(long *)(lVar3 + 0x30) == 0)) ||
         (pcVar1 = *(code **)(*(long *)(lVar3 + 0x30) + 0x48), pcVar1 == (code *)0x0)) {
        iVar2 = 3;
      }
      else {
        iVar2 = (*pcVar1)(lVar3,param_1,param_2,__ptr,param_4);
        if ((iVar2 == 0) && (uVar5 = 0, *param_4 != 0)) {
          do {
            lVar3 = FUN_00133d60(param_1,*(undefined4 *)((long)__ptr + uVar5 * 4),param_2);
            *(long *)(param_3 + uVar5 * 8) = lVar3;
            if (lVar3 == 0) {
              iVar2 = 0x14;
              break;
            }
            uVar4 = (int)uVar5 + 1;
            uVar5 = (ulong)uVar4;
          } while (uVar4 < *param_4);
        }
      }
      free(__ptr);
      return iVar2;
    }
  }
  if (1 < DAT_01216a78) {
    fVar6 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar6 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar3,"nvml_mig.c",0x451,"tsmigDeviceGetGpuInstances",0x451,iVar2);
  }
  return iVar2;
}


// ===== 00134200 FUN_00134200 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00134200(long param_1,undefined *param_2,ulong param_3,uint param_4,uint param_5,
                char *param_6,uint param_7)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  ulong uVar5;
  long lVar6;
  float fVar7;
  double dVar8;
  
  if ((param_2 == (undefined *)0x0) && (param_4 == param_5)) {
    param_2 = &DAT_002dd473;
  }
  if (*(int *)(param_1 + 0x27bc0) == 0) {
    do {
      iVar2 = FUN_00291820(param_1 + 0x27bc4,1,0);
    } while (iVar2 != 0);
    if (*(int *)(param_1 + 0x27bc0) == 0) {
      lVar6 = *(long *)(param_1 + 0x256d8);
      uVar4 = 3;
      if (((lVar6 != 0) && (*(long *)(lVar6 + 0x68) != 0)) &&
         (pcVar1 = *(code **)(*(long *)(lVar6 + 0x68) + 8), pcVar1 != (code *)0x0)) {
        uVar4 = (*pcVar1)(lVar6,param_1,param_1 + 0x27bb8);
      }
      *(undefined4 *)(param_1 + 0x27bc8) = uVar4;
      *(undefined4 *)(param_1 + 0x27bc0) = 1;
    }
    FUN_00291830(param_1 + 0x27bc4,0);
  }
  iVar2 = *(int *)(param_1 + 0x27bc8);
  if (iVar2 == 0) {
    dVar8 = (((double)param_3 * DAT_0029b9e8 * DAT_0029b9e8) / (double)*(ulong *)(param_1 + 0x27bb8)
            ) * _DAT_0029b9f0;
    if ((double)((ulong)dVar8 & DAT_0029ba00) < DAT_0029b9f8) {
      dVar8 = (double)((ulong)((double)(long)dVar8 +
                              (double)(-(ulong)((double)(long)dVar8 < dVar8) & DAT_00298b60)) |
                      ~DAT_0029ba00 & (ulong)dVar8);
    }
    uVar5 = lround(dVar8 * _DAT_00298b80 *
                   (double)(*(ulong *)(param_1 + 0x27bb8) + 0x3fffffff >> 0x1e & 0xffffffff));
    if (param_2 == (undefined *)0x0) {
      uVar3 = snprintf(param_6,(ulong)param_7,"MIG %uc.%ug.%ugb",(ulong)param_5,(ulong)param_4,
                       uVar5 & 0xffffffff);
    }
    else {
      uVar3 = snprintf(param_6,(ulong)param_7,"MIG %ug.%ugb%s",(ulong)param_4,uVar5 & 0xffffffff,
                       param_2);
      if ((int)uVar3 < 0) {
        return 0x11;
      }
    }
    if (param_7 <= uVar3) {
      iVar2 = 7;
    }
  }
  else if (1 < DAT_01216a78) {
    fVar7 = (float)FUN_002917b0(&DAT_01216a60);
    lVar6 = syscall(0xba);
    FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar6,"nvml_mig.c",0x337,"getMigProfileNameMemSize",0x337,iVar2);
  }
  return iVar2;
}


// ===== 001344e0 FUN_001344e0 =====

int FUN_001344e0(long param_1,undefined4 param_2,long param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  undefined8 local_30 [2];
  
  lVar3 = *(long *)(param_1 + 0x256d8);
  local_30[0] = 0;
  if (((lVar3 == 0) || (*(long *)(lVar3 + 0x30) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(lVar3 + 0x30) + 0x18), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar3,param_1,param_2,param_3,1,local_30);
    if (iVar2 == 0) {
      iVar2 = FUN_00134200(param_1,local_30[0],*(undefined8 *)(param_3 + 0x30),
                           *(undefined4 *)(param_3 + 0xc),*(undefined4 *)(param_3 + 0xc),
                           param_3 + 0x38,0x60);
      return iVar2;
    }
  }
  if (1 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar3,"nvml_mig.c",0x3e6,"tsmigDeviceGetGpuInstanceProfileInfoById",0x3e6,
                 iVar2);
    return iVar2;
  }
  return iVar2;
}


// ===== 00134630 FUN_00134630 =====

int FUN_00134630(long param_1,undefined4 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  float fVar4;
  undefined4 local_2c [3];
  
  lVar3 = *(long *)(param_1 + 0x256d8);
  local_2c[0] = 0;
  if (((lVar3 == 0) || (*(long *)(lVar3 + 0x30) == 0)) ||
     (pcVar1 = *(code **)(*(long *)(lVar3 + 0x30) + 0x10), pcVar1 == (code *)0x0)) {
    iVar2 = 3;
  }
  else {
    iVar2 = (*pcVar1)(lVar3,param_1,param_2,local_2c);
    if (iVar2 == 0) {
      iVar2 = FUN_001344e0(param_1,local_2c[0],param_3);
      return iVar2;
    }
  }
  if (1 < DAT_01216a78) {
    fVar4 = (float)FUN_002917b0(&DAT_01216a60);
    lVar3 = syscall(0xba);
    FUN_002340f0((double)(fVar4 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                 "ERROR",lVar3,"nvml_mig.c",0x3d8,"tsmigDeviceGetGpuInstanceProfileInfo",0x3d8,iVar2
                );
    return iVar2;
  }
  return iVar2;
}


// ===== 00134770 FUN_00134770 =====

int FUN_00134770(undefined8 *param_1,undefined4 param_2,undefined4 param_3,long param_4)

{
  undefined8 *puVar1;
  char *pcVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  float fVar6;
  
  puVar1 = DAT_01216970;
  if ((undefined8 **)DAT_01216970 != &DAT_01216970) {
    do {
      if (param_1 == puVar1 + -0x12) {
        pcVar2 = (char *)*param_1;
        if (pcVar2 == (char *)0x0) {
          return 2;
        }
        if (*pcVar2 != '\x01') {
          if (*(int *)(pcVar2 + 0x14) == 0) {
            return 2;
          }
          if (*(int *)(pcVar2 + 0x1c) != 0) {
            return 2;
          }
          if (*(int *)(pcVar2 + 0x10) == 0) {
            return 2;
          }
          if (*(long *)(pcVar2 + 0x20) == 0) {
            return 2;
          }
        }
        lVar5 = *(long *)(pcVar2 + 0x256d8);
        if (((lVar5 == 0) || (*(long *)(lVar5 + 0x30) == 0)) ||
           (pcVar3 = *(code **)(*(long *)(lVar5 + 0x30) + 0x58), pcVar3 == (code *)0x0)) {
          iVar4 = 3;
        }
        else {
          iVar4 = (*pcVar3)(lVar5,pcVar2,*(undefined4 *)(param_1 + 1),param_1 + 2,param_2,param_3,
                            param_4);
          if (iVar4 == 0) {
            iVar4 = FUN_00134200(*param_1,0,param_1[7],*(undefined4 *)(param_1 + 3),
                                 *(undefined4 *)(param_4 + 8),param_4 + 0x28,0x60);
            return iVar4;
          }
        }
        if (1 < DAT_01216a78) {
          fVar6 = (float)FUN_002917b0(&DAT_01216a60);
          lVar5 = syscall(0xba);
          FUN_002340f0((double)(fVar6 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar5,"nvml_mig.c",
                       0x4bf,"tsmigGpuInstanceGetComputeInstanceProfileInfo",0x4bf,iVar4);
          return iVar4;
        }
        return iVar4;
      }
      puVar1 = (undefined8 *)(puVar1 + -0x12)[0x12];
    } while ((undefined8 **)puVar1 != &DAT_01216970);
  }
  return 2;
}


// ===== 00134940 FUN_00134940 =====

void FUN_00134940(undefined8 *param_1,int param_2,undefined4 param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long *plVar9;
  undefined8 *puVar10;
  
  puVar10 = DAT_01216980;
  if ((undefined8 **)DAT_01216980 != &DAT_01216980) {
    do {
      if ((param_2 == *(int *)(puVar10 + -8)) && (param_1 == (undefined8 *)puVar10[-9])) {
        return;
      }
      puVar10 = (undefined8 *)*puVar10;
    } while ((undefined8 **)puVar10 != &DAT_01216980);
  }
  puVar10 = malloc(0x60);
  if (puVar10 == (undefined8 *)0x0) {
    return;
  }
  uVar1 = *param_1;
  uVar3 = *param_4;
  uVar4 = param_4[1];
  puVar10[1] = param_1;
  uVar5 = param_4[2];
  uVar6 = param_4[3];
  uVar7 = param_4[4];
  uVar8 = param_4[5];
  *(int *)(puVar10 + 2) = param_2;
  *puVar10 = uVar1;
  uVar1 = param_4[6];
  *(undefined4 *)((long)puVar10 + 0x14) = param_3;
  puVar10[9] = uVar1;
  plVar9 = DAT_01216988;
  puVar10[3] = uVar3;
  puVar10[4] = uVar4;
  puVar10[5] = uVar5;
  puVar10[6] = uVar6;
  puVar10[7] = uVar7;
  puVar10[8] = uVar8;
  lVar2 = *plVar9;
  puVar10[0xb] = plVar9;
  puVar10[10] = lVar2;
  *(undefined8 **)(*plVar9 + 8) = puVar10 + 10;
  *plVar9 = (long)(puVar10 + 10);
  return;
}


// ===== 00134a10 FUN_00134a10 =====

int FUN_00134a10(long *param_1,undefined4 param_2,long param_3,uint *param_4)

{
  undefined8 *puVar1;
  char *pcVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  undefined4 *__ptr;
  uint uVar7;
  float fVar8;
  uint local_7c;
  undefined1 local_78 [72];
  
  puVar1 = DAT_01216970;
  if ((undefined8 **)DAT_01216970 != &DAT_01216970) {
    do {
      if (param_1 == puVar1 + -0x12) {
        pcVar2 = (char *)*param_1;
        if (pcVar2 == (char *)0x0) {
          return 2;
        }
        if (*pcVar2 != '\x01') {
          if (*(int *)(pcVar2 + 0x14) == 0) {
            return 2;
          }
          if (*(int *)(pcVar2 + 0x1c) != 0) {
            return 2;
          }
          if (*(int *)(pcVar2 + 0x10) == 0) {
            return 2;
          }
          if (*(long *)(pcVar2 + 0x20) == 0) {
            return 2;
          }
        }
        lVar6 = *(long *)(pcVar2 + 0x256d8);
        if (((lVar6 == 0) || (*(long *)(lVar6 + 0x30) == 0)) ||
           (pcVar3 = *(code **)(*(long *)(lVar6 + 0x30) + 0xa8), pcVar3 == (code *)0x0)) {
          iVar4 = 3;
        }
        else {
          iVar4 = (*pcVar3)(lVar6,pcVar2,&local_7c);
          if (iVar4 == 0) {
            __ptr = malloc((ulong)local_7c << 2);
            if (__ptr == (undefined4 *)0x0) {
              return 0x14;
            }
            lVar6 = *(long *)(*param_1 + 0x256d8);
            if (((lVar6 != 0) && (*(long *)(lVar6 + 0x30) != 0)) &&
               (pcVar3 = *(code **)(*(long *)(lVar6 + 0x30) + 0x80), pcVar3 != (code *)0x0)) {
              iVar5 = (*pcVar3)(lVar6,*param_1,(int)param_1[1],param_1 + 2,param_2,__ptr,param_4);
              iVar4 = iVar5;
              if ((iVar5 != 0) || (*param_4 == 0)) goto LAB_00134cd0;
              lVar6 = *(long *)(*param_1 + 0x256d8);
              if ((lVar6 != 0) &&
                 ((*(long *)(lVar6 + 0x30) != 0 &&
                  (pcVar3 = *(code **)(*(long *)(lVar6 + 0x30) + 0x68), pcVar3 != (code *)0x0)))) {
                iVar4 = (*pcVar3)(lVar6,*param_1,(int)param_1[1],*__ptr);
                if ((iVar4 != 0) || (uVar7 = 0, iVar4 = iVar5, *param_4 == 0)) goto LAB_00134cd0;
                goto LAB_00134c78;
              }
            }
            iVar4 = 3;
            goto LAB_00134cd0;
          }
        }
        if (1 < DAT_01216a78) {
          fVar8 = (float)FUN_002917b0(&DAT_01216a60);
          lVar6 = syscall(0xba);
          FUN_002340f0((double)(fVar8 * DAT_00298548),
                       "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar6,"nvml_mig.c",
                       0x547,"tsmigGpuInstanceGetComputeInstances",0x547,iVar4);
          return iVar4;
        }
        return iVar4;
      }
      puVar1 = (undefined8 *)(puVar1 + -0x12)[0x12];
    } while ((undefined8 **)puVar1 != &DAT_01216970);
  }
  return 2;
  while (uVar7 = uVar7 + 1, uVar7 < *param_4) {
LAB_00134c78:
    lVar6 = FUN_00134940(param_1,__ptr[uVar7],param_2,local_78);
    *(long *)(param_3 + (ulong)uVar7 * 8) = lVar6;
    if (lVar6 == 0) {
      iVar4 = 0x14;
      break;
    }
  }
LAB_00134cd0:
  free(__ptr);
  return iVar4;
}


// ===== 00134d20 FUN_00134d20 =====

void FUN_00134d20(long param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 *__ptr;
  
  puVar1 = (undefined8 *)*DAT_01216980;
  __ptr = DAT_01216980 + -10;
  if ((undefined8 **)DAT_01216980 != &DAT_01216980) {
    do {
      puVar3 = puVar1 + -10;
      if ((param_1 == 0) || (__ptr[1] == param_1)) {
        puVar2 = (undefined8 *)__ptr[0xb];
        *(undefined8 **)(__ptr[10] + 8) = puVar2;
        *puVar2 = __ptr[10];
        free(__ptr);
      }
      puVar1 = (undefined8 *)*puVar1;
      __ptr = puVar3;
    } while (puVar3 != (undefined8 *)&DAT_01216930);
  }
  return;
}


// ===== 00134da0 FUN_00134da0 =====

void FUN_00134da0(long param_1)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  long lVar11;
  long *plVar12;
  long *plVar13;
  uint uVar14;
  void *__ptr;
  ulong uVar15;
  uint uVar16;
  float fVar17;
  uint local_f4;
  uint local_f0;
  undefined1 local_ec [4];
  void *local_e8;
  void *local_e0;
  long local_d8;
  long lStack_d0;
  long local_c8;
  long lStack_c0;
  long local_b8;
  long lStack_b0;
  long local_a8;
  long lStack_a0;
  long local_98;
  long lStack_90;
  long local_88;
  long lStack_80;
  long local_78;
  long lStack_70;
  long local_68;
  long lStack_60;
  long local_58;
  long lStack_50;
  long local_48;
  long lStack_40;
  
  lVar11 = *(long *)(param_1 + 0x256d8);
  local_e8 = (void *)0x0;
  local_e0 = (void *)0x0;
  if ((((lVar11 == 0) || (*(long *)(lVar11 + 0x30) == 0)) ||
      (pcVar1 = *(code **)(*(long *)(lVar11 + 0x30) + 0x90), pcVar1 == (code *)0x0)) ||
     (iVar8 = (*pcVar1)(lVar11,param_1,&local_e8,&local_f4), iVar8 != 0)) {
    return;
  }
  plVar2 = *(long **)(param_1 + 0x20);
  plVar3 = (long *)*plVar2;
  uVar15 = 0;
  plVar13 = (long *)*plVar3;
  if (plVar2 == plVar3) {
    if (local_f4 == 0) goto LAB_0013530d;
LAB_00134e89:
    do {
      while( true ) {
        lVar11 = *(long *)(param_1 + 0x256d8);
        if (((lVar11 != 0) && (*(long *)(lVar11 + 0x30) != 0)) &&
           (pcVar1 = *(code **)(*(long *)(lVar11 + 0x30) + 0xa0), pcVar1 != (code *)0x0)) break;
LAB_00134e78:
        uVar16 = (int)uVar15 + 1;
        uVar15 = (ulong)uVar16;
        if (local_f4 <= uVar16) goto LAB_00135136;
      }
      iVar8 = *(int *)((long)local_e8 + uVar15 * 4);
      iVar9 = (*pcVar1)(lVar11,param_1,iVar8,&local_e0,&local_f0);
      if (iVar9 != 0) goto LAB_00134e78;
      __ptr = local_e0;
      if (local_f0 != 0) {
        uVar16 = 0;
        do {
          iVar9 = *(int *)((long)__ptr + (ulong)uVar16 * 4);
          for (puVar4 = (undefined8 *)**(undefined8 **)(param_1 + 0x20);
              *(undefined8 **)(param_1 + 0x20) != puVar4; puVar4 = (undefined8 *)*puVar4) {
            if (((param_1 == puVar4[-2]) && (iVar8 == *(int *)((long)puVar4 + -0xa4))) &&
               (iVar9 == *(int *)(puVar4 + -0x14))) {
              if (*(char *)(puVar4 + -0xe956) != '\0') {
                *(undefined1 *)(puVar4 + -1) = 0;
                goto LAB_0013510f;
              }
              break;
            }
          }
          if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x30) != 0)) &&
             (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0xa8), pcVar1 != (code *)0x0)) {
            (*pcVar1)(DAT_012164a0,param_1,local_ec);
          }
          lVar11 = *(long *)(param_1 + 0x256d8);
          if (((lVar11 == 0) || (*(long *)(lVar11 + 0x30) == 0)) ||
             (pcVar1 = *(code **)(*(long *)(lVar11 + 0x30) + 0x88), pcVar1 == (code *)0x0)) {
            iVar10 = 3;
LAB_00135085:
            __ptr = local_e0;
            if (1 < DAT_01216a78) {
              fVar17 = (float)FUN_002917b0(&DAT_01216a60);
              lVar11 = syscall(0xba);
              FUN_002340f0((double)(fVar17 * DAT_00298548),
                           "%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n","ERROR",lVar11,
                           "nvml_mig.c",0x1a5,"createMigDevice",0x1a5,iVar10);
              __ptr = local_e0;
            }
          }
          else {
            iVar10 = (*pcVar1)(lVar11,param_1,iVar8);
            if (iVar10 != 0) goto LAB_00135085;
            plVar2 = *(long **)(param_1 + 0x20);
            plVar3 = (long *)*plVar2;
            if (plVar2 == plVar3) {
LAB_00135328:
              plVar12 = malloc(0x74ac0);
              if (plVar12 != (long *)0x0) {
                lVar11 = plVar2[2];
                *(int *)(plVar2 + 2) = (int)lVar11 + 1;
                *(int *)((long)plVar12 + 4) = (int)lVar11;
                goto LAB_00135217;
              }
              __ptr = local_e0;
              if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x30) != 0)) &&
                 (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0xb0), pcVar1 != (code *)0x0)
                 ) {
                (*pcVar1)(DAT_012164a0,&local_d8);
                __ptr = local_e0;
              }
            }
            else {
              uVar14 = 0xffffffff;
              plVar13 = (long *)0x0;
              do {
                plVar12 = plVar3 + -0xe956;
                if ((char)*plVar12 == '\0') {
                  if (((iVar8 == *(int *)((long)plVar3 + -0xa4)) && (iVar9 == (int)plVar3[-0x14]))
                     && (param_1 == plVar3[-2])) {
                    plVar13 = (long *)plVar3[1];
                    *(long **)(*plVar3 + 8) = plVar13;
                    *plVar13 = *plVar3;
                    *plVar3 = 0;
                    plVar3[1] = 0;
                    goto LAB_00135217;
                  }
                  if (*(uint *)((long)plVar3 + -0x74aac) < uVar14) {
                    plVar13 = plVar12;
                    uVar14 = *(uint *)((long)plVar3 + -0x74aac);
                  }
                }
                plVar12 = plVar13;
                plVar3 = (long *)*plVar3;
                plVar13 = plVar12;
              } while (plVar2 != plVar3);
              if (plVar12 == (long *)0x0) goto LAB_00135328;
              plVar3 = (long *)plVar12[0xe957];
              *(long **)(plVar12[0xe956] + 8) = plVar3;
              *plVar3 = plVar12[0xe956];
              plVar12[0xe956] = 0;
              plVar12[0xe957] = 0;
LAB_00135217:
              memset(plVar12 + 1,0,0x74a00);
              plVar12[0xe941] = local_d8;
              plVar12[0xe942] = lStack_d0;
              plVar12[0xe943] = local_c8;
              plVar12[0xe944] = lStack_c0;
              plVar12[0xe945] = local_b8;
              plVar12[0xe946] = lStack_b0;
              *(char *)plVar12 = '\x01';
              *(char *)(plVar12 + 0xe955) = '\0';
              plVar12[0xe947] = local_a8;
              plVar12[0xe948] = lStack_a0;
              plVar12[0xe949] = local_98;
              plVar12[0xe94a] = lStack_90;
              plVar12[0xe94b] = local_88;
              plVar12[0xe94c] = lStack_80;
              plVar12[0xe94d] = local_78;
              plVar12[0xe94e] = lStack_70;
              plVar12[0xe94f] = local_68;
              plVar12[0xe950] = lStack_60;
              plVar12[0xe951] = local_58;
              plVar12[0xe952] = lStack_50;
              plVar12[0xe953] = local_48;
              plVar12[0xe954] = lStack_40;
              plVar2 = (long *)plVar2[1];
              lVar11 = *plVar2;
              plVar12[0xe957] = (long)plVar2;
              plVar12[0xe956] = lVar11;
              *(long **)(*plVar2 + 8) = plVar12 + 0xe956;
              *plVar2 = (long)(plVar12 + 0xe956);
              __ptr = local_e0;
            }
          }
LAB_0013510f:
          uVar16 = uVar16 + 1;
        } while (uVar16 < local_f0);
      }
      free(__ptr);
      uVar16 = (int)uVar15 + 1;
      uVar15 = (ulong)uVar16;
    } while (uVar16 < local_f4);
  }
  else {
    do {
      plVar12 = plVar13;
      *(undefined1 *)(plVar3 + -1) = 1;
      plVar13 = (long *)*plVar12;
      plVar3 = plVar12;
    } while (plVar12 != plVar2);
    if (local_f4 != 0) goto LAB_00134e89;
  }
LAB_00135136:
  puVar4 = *(undefined8 **)(param_1 + 0x20);
  puVar5 = (undefined8 *)*puVar4;
  puVar7 = (undefined8 *)*puVar5;
  while (puVar6 = puVar7, puVar4 != puVar5) {
    if (*(char *)(puVar5 + -1) != '\0') {
      if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x30) != 0)) &&
         (pcVar1 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0xb0), pcVar1 != (code *)0x0)) {
        (*pcVar1)(DAT_012164a0,puVar5 + -0x15);
      }
      *(undefined1 *)(puVar5 + -0xe956) = 0;
      *(undefined1 *)(puVar5 + -1) = 0;
    }
    puVar7 = (undefined8 *)*puVar6;
    puVar5 = puVar6;
  }
LAB_0013530d:
  free(local_e8);
  return;
}


// ===== 001353b0 FUN_001353b0 =====

undefined8 FUN_001353b0(void)

{
  int iVar1;
  
  do {
    iVar1 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar1 != 0);
  DAT_01216970 = &DAT_01216970;
  DAT_01216978 = &DAT_01216970;
  DAT_01216980 = &DAT_01216980;
  DAT_01216988 = &DAT_01216980;
  FUN_00291830(&DAT_01216990,0);
  return 0;
}


// ===== 00135420 FUN_00135420 =====

undefined4 FUN_00135420(long param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  
  do {
    iVar1 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar1 != 0);
  uVar3 = 0;
  if (*(long *)(param_1 + 0x20) == 0) {
    pvVar2 = malloc(0x18);
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0x14;
    }
    else {
      *(undefined4 *)((long)pvVar2 + 0x10) = 0;
      *(void **)pvVar2 = pvVar2;
      *(void **)((long)pvVar2 + 8) = pvVar2;
      *(void **)(param_1 + 0x20) = pvVar2;
    }
  }
  FUN_00291830(&DAT_01216990,0);
  return uVar3;
}


// ===== 001354b0 FUN_001354b0 =====

undefined8 FUN_001354b0(long param_1,char param_2)

{
  undefined8 *puVar1;
  code *pcVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  int iVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  long *plVar9;
  undefined8 *puVar10;
  
  do {
    iVar6 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar6 != 0);
  puVar10 = *(undefined8 **)(param_1 + 0x20);
  if (puVar10 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)*puVar10;
    while (puVar10 != puVar1) {
      puVar8 = puVar1 + -0xe956;
      if (((DAT_012164a0 != 0) && (*(long *)(DAT_012164a0 + 0x30) != 0)) &&
         (pcVar2 = *(code **)(*(long *)(DAT_012164a0 + 0x30) + 0xb0), pcVar2 != (code *)0x0)) {
        (*pcVar2)(DAT_012164a0,puVar1 + -0x15);
      }
      puVar1 = (undefined8 *)*puVar1;
      *(undefined1 *)puVar8 = 0;
    }
    if (param_2 != '\0') {
      puVar10 = *(undefined8 **)(param_1 + 0x20);
      puVar1 = (undefined8 *)*puVar10;
      puVar8 = (undefined8 *)*puVar1;
      if (puVar10 != puVar1) {
        do {
          puVar7 = puVar8;
          puVar8 = (undefined8 *)puVar1[1];
          puVar7[1] = puVar8;
          *puVar8 = *puVar1;
          *puVar1 = 0;
          puVar1[1] = 0;
          *(int *)(puVar10 + 2) = *(int *)(puVar10 + 2) + -1;
          free(puVar1 + -0xe956);
          puVar8 = (undefined8 *)*puVar7;
          puVar1 = puVar7;
        } while (puVar10 != puVar7);
        puVar10 = *(undefined8 **)(param_1 + 0x20);
      }
      free(puVar10);
      *(undefined8 *)(param_1 + 0x20) = 0;
    }
    plVar9 = (long *)*DAT_01216970;
    plVar5 = DAT_01216970;
    if ((long **)DAT_01216970 != &DAT_01216970) {
      do {
        plVar3 = plVar9;
        plVar9 = plVar5 + -0x12;
        if (param_1 == *plVar9) {
          FUN_00134d20(plVar9);
          plVar4 = (long *)plVar5[1];
          *(long **)(*plVar5 + 8) = plVar4;
          *plVar4 = *plVar5;
          free(plVar9);
        }
        plVar9 = (long *)*plVar3;
        plVar5 = plVar3;
      } while ((long **)plVar3 != &DAT_01216970);
    }
  }
  FUN_00291830(&DAT_01216990,0);
  return 0;
}


// ===== 001356a0 FUN_001356a0 =====

int FUN_001356a0(char *param_1,char *param_2,uint param_3)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  char *pcVar6;
  float fVar7;
  undefined1 local_e8 [16];
  undefined1 local_d8 [16];
  undefined8 local_c8;
  undefined1 local_b8 [16];
  undefined1 local_a8 [16];
  undefined1 local_98 [16];
  undefined1 local_88 [16];
  undefined1 local_78 [16];
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  
  do {
    iVar3 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar3 != 0);
  pcVar6 = (char *)0x0;
  local_c8 = 0;
  local_e8 = (undefined1  [16])0x0;
  local_d8 = (undefined1  [16])0x0;
  local_b8 = (undefined1  [16])0x0;
  local_a8 = (undefined1  [16])0x0;
  local_98 = (undefined1  [16])0x0;
  local_88 = (undefined1  [16])0x0;
  local_78 = (undefined1  [16])0x0;
  local_68 = (undefined1  [16])0x0;
  local_58 = (undefined1  [16])0x0;
  local_48 = (undefined1  [16])0x0;
  if (((param_1 != (char *)0x0) && (*param_1 != '\x01')) && (*(long *)(param_1 + 0x20) == 0)) {
    pcVar6 = param_1 + -8;
  }
  iVar3 = 2;
  cVar2 = FUN_00133d10(pcVar6);
  if ((cVar2 != '\0') && (iVar3 = FUN_00133ed0(2,param_1,local_e8), iVar3 == 0)) {
    iVar3 = FUN_00134200(*(undefined8 *)(pcVar6 + 0x74aa0),0,local_c8,local_d8._8_4_,local_d8._12_4_
                         ,local_78,0x40);
    if (iVar3 == 0) {
      lVar5 = *(long *)(*(long *)(pcVar6 + 0x74aa0) + 0x256d8);
      if (((lVar5 == 0) || (*(undefined8 **)(lVar5 + 0x38) == (undefined8 *)0x0)) ||
         (pcVar1 = (code *)**(undefined8 **)(lVar5 + 0x38), pcVar1 == (code *)0x0)) {
        iVar3 = 3;
      }
      else {
        iVar3 = (*pcVar1)(lVar5,*(long *)(pcVar6 + 0x74aa0),local_b8,0x40);
        if (iVar3 == 0) {
          uVar4 = snprintf(param_2,(ulong)param_3,"%s %s",local_b8,local_78);
          if ((int)uVar4 < 0) {
            iVar3 = 0x11;
          }
          else if (param_3 <= uVar4) {
            iVar3 = 7;
          }
          goto LAB_00135769;
        }
      }
      if (1 < DAT_01216a78) {
        fVar7 = (float)FUN_002917b0(&DAT_01216a60);
        lVar5 = syscall(0xba);
        FUN_002340f0((double)(fVar7 * DAT_00298548),"%s:\t[tid %llu]\t[%.06fs - %s:%d]\t%s %d %d\n",
                     "ERROR",lVar5,"nvml_mig.c",0x6e0,"tsmigGetMigDeviceName",0x6e0,iVar3);
      }
    }
  }
LAB_00135769:
  FUN_00291830(&DAT_01216990,0);
  return iVar3;
}


// ===== 001358e0 FUN_001358e0 =====

undefined4 FUN_001358e0(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  do {
    iVar1 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar1 != 0);
  uVar2 = FUN_00134630(param_1,param_2,param_3);
  FUN_00291830(&DAT_01216990,0);
  return uVar2;
}


// ===== 00135950 FUN_00135950 =====

undefined4 FUN_00135950(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  do {
    iVar1 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar1 != 0);
  uVar2 = FUN_001344e0(param_1,param_2,param_3);
  FUN_00291830(&DAT_01216990,0);
  return uVar2;
}


// ===== 001359c0 FUN_001359c0 =====

undefined4 FUN_001359c0(long param_1,undefined4 param_2,undefined8 param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  
  do {
    iVar3 = FUN_00291820(&DAT_01216990,1,0);
  } while (iVar3 != 0);
  lVar1 = *(long *)(param_1 + 0x256d8);
  if (((lVar1 == 0) || (*(long *)(lVar1 + 0x30) == 0)) ||
     (pcVar2 = *(code **)(*(long *)(lVar1 + 0x30) + 0x20), pcVar2 == (code *)0x0)) {
    uVar4 = 3;
  }
  else {
    uVar4 = (*pcVar2)(lVar1,param_1,param_2,param_3,0);
  }
  FUN_00291830(&DAT_01216990,0);
  return uVar4;
}


