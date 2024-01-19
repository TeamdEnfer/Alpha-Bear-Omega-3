from setuptools import find_packages, setup

package_name = 'alphabearomega3'

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
    maintainer='tx',
    maintainer_email='txguimont@gmail.com',
    description='Package for the omega3 eating Alpha Bear',
    license='GPL-3.0-only',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'leg_fr = alphabearomega3.leg_fr:main'
        ],
    },
)
