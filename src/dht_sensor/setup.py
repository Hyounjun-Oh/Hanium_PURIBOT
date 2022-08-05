import glob
import os

from setuptools import find_packages
from setuptools import setup

package_name = 'dht_sensor'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob.glob(os.path.join('launch', '*.launch.py')))
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Oh Hyounjun',
    maintainer_email='ohj_980918@naver.com',
    description='DHT sensor 데이터 받아오기',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'dht_pub = dht_sensor.dht_pub:main'
        ],
    },
)
