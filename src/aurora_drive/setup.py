import os
from setuptools import find_packages, setup
from glob import glob

package_name = 'aurora_drive'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob(os.path.join('launch', '*.launch.py'))),
        ('share/' + package_name + '/launch', glob(os.path.join('launch', '*.py'))),
        ('share/' + package_name + '/config', glob(os.path.join('config', '*.yaml'))),
        # description ディレクトリに合わせる
        ('share/' + package_name + '/description', glob(os.path.join('description', '*.xacro'))),
        ('share/' + package_name + '/world', glob(os.path.join('world', '*.world'))),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='fuga1129',
    maintainer_email='sakihama1129@icloud.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={'test': ['pytest']},
    entry_points={
    'console_scripts': [
        'ackermann_4wd_controller = aurora_drive.ackermann_4wd_controller:main',
        'odometry_4ws = aurora_drive.odometry_4ws:main',
        'ackermann_sim_controller = aurora_drive.ackermann_sim_controller:main',
        'aruco_marker_mapper = aurora_drive.aruco_marker_mapper:main',
        'aruco_map_builder = aurora_drive.aruco_map_builder:main',
    ],
},

)