## About

This repository presents a partial reproduction of the scenario presented by <a href="https://www.sciencedirect.com/science/article/pii/S0168169918302436" target="_blank">Mazon-Olivo et al. (2018)</a>.

## Clone

> clone this repo to your local machine using 

```shell
$ git clone `https://github.com/ddefb/PGIA7336`
```

## Setup

> install Heptagon/BZR on Linux

For run this project you need install the Heptagon/BZR and download the Sigali tool. The links below provide tutorials for doing this step:

- Tutorial 1 (<a href="http://heptagon.gforge.inria.fr/" target="_blank">English</a>) by <a href="http://heptagon.gforge.inria.fr/" target="_blank">INRIA</a> group;
- Tutorial 2 (<a href="https://jualabs.wordpress.com/2016/04/08/instalacao-do-heptagon-no-ubuntu-14-04/" target="_blank">Portuguese</a>) by <a href="https://www.jualabs.com" target="_blank">Juá Labs</a> group.

> install PIP on Linux

```shell
$ sudo apt-get install python-pip
```

> go to PGIA7336/P9/irrigation folder

```shell
$ cd ~/PGIA7336/P9/irrigation
```

> install python requeriments for this project

```shell
$ pip install -r requirements.txt 
```

## Run project

> activate Flask app

```shell
$ source bin/activate
```

> go to PGIA7336/P9/irrigation/app folder

```shell
$ cd ~/PGIA7336/P9/irrigation/app
```

> run the main_server.py file with the command:

```shell
$ python main_server.py
```

> run the command above to open app using mozilla firefox:

```shell 
$ /usr/bin/firefox http://127.0.0.1/5000
```
> or google chrome:

```shell 
$ /usr/bin/google-chrome http://127.0.0.1/5000
```

## Using webservice

Once the controller is generated, the webservice can be accessed by port 82.

> using mozilla firefox:

```shell 
$ /usr/bin/firefox http://127.0.0.1/8082
```

---

## License

[![License](http://img.shields.io/:license-mit-blue.svg?style=flat-square)](http://badges.mit-license.org)

- **[MIT license](http://opensource.org/licenses/mit-license.php)**
- Copyright 2018 © <a href="http://ddefb.me/" target="_blank">Diego Bezerra</a>.
