# minishell
> Разрешенные функции — readline, rl_clear_history, rl_on_new_line,  rl_replace_line, rl_redisplay, add_history,  printf, malloc, free, write, access, open, read,  close, fork, wait, waitpid, wait3, wait4, signal,  
sigaction, sigemptyset, sigaddset, kill, exit,  getcwd, chdir, stat, lstat, fstat, unlink, execve,  dup, dup2, pipe, opendir, readdir, closedir,  strerror, perror, isatty, ttyname, ttyslot, ioctl,  getenv, tcsetattr, tcgetattr, tgetent, tgetflag,  tgetnum, tgetstr, tgoto, tputs

> Задача — написать shell.

Ваш shell должен:

-   Показывать строку во время ожидания команды.
-	Иметь историю введенных команд.
-   Искать и запускать правильный файл исполнения (на основе переменной PATH или на основе относительного и абсолютного пути) как в bash.
-    Разрешено использование только одной глобальной переменной.
-   В нем должны быть реализованы следующие встроенные функции как в bash:  
    * `echo`, с опцией '-n'  
    * `cd`, который работает только с относительным и абсолютным путем.  
    * `pwd`, без опций  
    * `export`, без опций  
    * `unset`, без опций  
    * `env`, без опций  
    * `exit`, без опций
-   `'` и `"` должны работать как в bash. За исключением многострочных команд.
-   Перенаправления `<`, `>`, `<<`, `>>` должны работать как в bash. Исключение: для группы файловых дескрипторов, перенаправление можно не делать.
-   Пайпы `|` должны работать как в bash.
-   Переменные окружения (которые с `$`, за которым следуют символы) должны работать как в bash.
-   `$?` должен работать как в bash.
-   `ctrl-C`, `ctrl-D` и `ctrl-\` должны повторять поведение bash.

---
