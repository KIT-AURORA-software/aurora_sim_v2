from setuptools import find_packages, setup

package_name = 'aurora_autonav'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='fuga1129',
    maintainer_email='sakihama1129@icloud.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'checkpoint_navigation_node = aurora_autonav.checkpoint_navigation_node:main',
            'checkpoin_geometry = aurora_autonav.checkpoint_geometry:main',
            'checkpoint_navigation_node_v2 = aurora_autonav.checkpoint_navigation_node_v2:main',
        ],
    },
)
