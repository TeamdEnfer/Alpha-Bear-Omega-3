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
<<<<<<< Updated upstream
    maintainer='tx',
    maintainer_email='txguimont@gmail.com',
    description='Package for the omega3 eating Alpha Bear',
=======
    maintainer='revixa',
    maintainer_email='7970411+Revixa1@users.noreply.github.com',
    description='TODO: Package description',
>>>>>>> Stashed changes
    license='GPL-3.0-only',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
<<<<<<< Updated upstream
            'leg_fr = alphabearomega3.leg_fr:main'
=======
            'big_bear_brain_master = alphabearomega3.big_bear_brain_master:main'
>>>>>>> Stashed changes
        ],
    },
)
