from setuptools import find_packages, setup

package_name = 'my_turtle_pkg'

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
    maintainer='maninder',
    maintainer_email='mani13jha1999@github.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "turtle_spawn_node = my_turtle_pkg.turtle_spawn_node:main",
            "turtle_catch_node = my_turtle_pkg.turtle_catch_node:main",
        ],
    },
)
