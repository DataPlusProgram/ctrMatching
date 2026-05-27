@echo off
cd /d "%~dp0"
python tools\generateEveryFuncConfig.py
splat split "executable_cfg.yaml"
pause
