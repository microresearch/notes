from __future__ import division
import os
from collections import namedtuple


_nt_cpu_temp = namedtuple('cputemp', 'temp critical')

def get_cpu_temp(fahrenheit=False):
    """Return temperatures expressed in Celsius for each physical CPU
    installed on the system as a list of namedtuples as in:

    >>> get_cpu_temp()
    [cputemp(name='atk0110', temp=32.0, max=60.0, critical=95.0)]
    """
    # http://www.mjmwired.net/kernel/Documentation/hwmon/sysfs-interface
    cat = lambda file: open(file, 'r').read().strip()
    base = '/sys/class/hwmon/'
    ls = sorted(os.listdir(base))
    assert ls, "%r is empty" % base
    ret = []
    for hwmon in ls:
        hwmon = os.path.join(base, hwmon)
        #        label = cat(os.path.join(hwmon, 'temp1_label'))
        #        assert 'cpu temp' in label.lower(), label
#        name = cat(os.path.join(hwmon, 'name'))
        temp = int(cat(os.path.join(hwmon, 'temp1_input'))) / 1000
        #        max_ = int(cat(os.path.join(hwmon, 'temp1_max'))) / 1000
        crit = int(cat(os.path.join(hwmon, 'temp1_crit'))) / 1000
        digits = (temp, crit)
        #       if fahrenheit:
        #          digits = [(x * 1.8) + 32 for x in digits]
        #        ret.append(_nt_cpu_temp(name, *digits))
        print digits
    return ret

get_cpu_temp()
