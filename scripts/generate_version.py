Import("env")
import subprocess
from datetime import datetime

def get_git_version():
    try:
        version = subprocess.check_output(
            ["git", "describe", "--tags", "--always", "--dirty"],
            stderr=subprocess.DEVNULL
        ).decode().strip()
    except:
        version = "unknown"
    return version

version = get_git_version()
now = datetime.now()

header_content = f'''
/* Auto-generated file. DO NOT EDIT */

#ifndef FW_VERSION_H
#define FW_VERSION_H

#define FW_VERSION "{version}"
#define FW_BUILD_DATE "{now.strftime("%Y-%m-%d")}"
#define FW_BUILD_TIME "{now.strftime("%H:%M:%S")}"

#endif
'''

with open("include/version.h", "w") as f:
    f.write(header_content)