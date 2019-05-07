/*
common.h



*/
#ifndef COMMON_H
#define COMMON_H

/*
Exit Codes
*/
#define DONE (0)
#define MALLOC_ERROR (1)
#define FILE_ERROR (2)




/*
Log
*/
#if LOG
FILE *logfile;
#define LOG_REDIRECT(F) do {\
  LOG_CLOSE();\
  LOG_OPEN(F);\
} while (0)
#define LOG_OPEN(F) do {\
  LOG_CLOSE();\
  if ((F) == stderr || (F) == stdout) {\
    logfile = F;\
  } else if (!(logfile = fopen(F, "w"))) {\
    fprintf(stderr, "Failed to open '%s' for logging.", F);\
    exit(FILE_ERROR);\
  }\
} while (0)
#define LOG_CLOSE() do {\
  if (logfile && logfile != stderr && logfile != stdout) {\
    fclose(logfile);\
    logfile = NULL;\
  }\
} while (0)
#define LOG_T(...) fprintf(logfile, __VA_ARGS__)
#define LOG_I(...) do {\
  fprintf(logfile, "[INFO]: "); fprintf(logfile, __VA_ARGS__);\
} while (0)
#define LOG_D(...) do {\
  fprintf(logfile, "[DEBUG]: "); fprintf(logfile, __VA_ARGS__);\
} while (0)
#define LOG_W(...) do {\
  fprintf(logfile, "[WARNING]: "); fprintf(logfile, __VA_ARGS__);\
} while (0)
#define LOG_E(...) do {\
  fprintf(logfile, "[ERROR]: "); fprintf(logfile, __VA_ARGS__);\
} while (0)
#else
#define LOG_OPEN(F)
#define LOG_CLOSE()
#define LOG_T(...)
#define LOG_I(...)
#define LOG_D(...)
#define LOG_W(...)
#define LOG_E(...)
#endif






#endif



