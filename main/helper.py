import subprocess
import os
def SourceScript(path):
    command=f"bash -c 'source {path} && env'"
    result=subprocess.check_output(command,shell=True, universal_newlines=True)
    #env_vars=dict(line.split("=",1) for line in result.splitlines())
    new_env={}
    for line in result.splitlines():
        if "=" in line:
            key,_,value=line.partition("=")
            new_env[key]=value
    os.environ.update(new_env)
