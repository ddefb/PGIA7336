## About

This repository presents a partial reproduction of the scenario presented by <a href="https://www.usenix.org/conference/feedbackcomputing13/workshop-program/presentation/zhao" target="_blank">Zhao et al (2013)</a> in <a href="http://heptagon.gforge.inria.fr/pub/heptagon-manual.pdf" target="_blank">BZR language</a>.

## Clone

> clone this repo to your local machine using 

```shell
$ git clone `https://github.com/ddefb/PGIA7336`
```

## Setup

For run this project you need install the Heptagon/BZR and download the Sigali tool. The links below provide tutorials for doing this step:

- Tutorial 1 (<a href="http://heptagon.gforge.inria.fr/" target="_blank">English</a>) by <a href="http://heptagon.gforge.inria.fr/" target="_blank">INRIA</a> group;
- Tutorial 2 (<a href="https://jualabs.wordpress.com/2016/04/08/instalacao-do-heptagon-no-ubuntu-14-04/" target="_blank">Portuguese</a>) by <a href="https://jualabs.wordpress.com" target="_blank">Juá Labs</a> group.

## Build and run the binary file

> go to PGIA7336/P3 folder

```shell
$ cd ~/PGIA7336/P3
```

> for build each *.ept in each folder (oven, radiator, washing_machine), run the make command:

```shell
$ make
```

> for execute each binary file, run the command above:

> for oven:
```shell 
$ ./oven_sim
```
> or for radiator:
```shell 
$ ./radiator_sim
```
> or for washing_machine:
```shell 
$ ./washing_machine_sim
```

---

## License

[![License](http://img.shields.io/:license-mit-blue.svg?style=flat-square)](http://badges.mit-license.org)

- **[MIT license](http://opensource.org/licenses/mit-license.php)**
- Copyright 2018 © <a href="http://ddefb.me/" target="_blank">Diego Bezerra</a>.
