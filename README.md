# Implementation of Automated-Embedded-System-calculating-Axial-Ration-of-Antenna

Introduction

This project is an Automated Testing System using Rotatory Probe Method to calculate Axial-Ratio of any given testing antenna. This system also computes sufficient parameters to generate Radiation power Pattern of Antenna. 
The accurate value of axial-ratio determines the Polarization of Transmitting antenna. Based on the type of polarization achieved in specific conditions using this testing system I have developed would be useful to derive computational and fabrication parameters of Microstrip Patch antenna used as Synthetic Aperture Radar (SAR) Sensor or Transceiver in Microwave Remote Sensing Satelites such as SAR satellites.

Hardware Testing Set-up 

1) Antenna Fixtures that can move to vary distance between transmiting and Receiving Antennas.
2) Transmitting Antenna : Helical Antenna ( Circular Polarization)
                          Dipole-Antenna and Loop Antenna for testing purpose
3) Receiving Antenna : Horn Antenna
4) Arduino Uno
5) TB6600 Stepper Motor Driver
6) NEMA 17 /NEMA 21 Stepper Motor
7) N9916A Fieldfox Spectrum Analyzer, Keysight Technology
8) SMA connectors and Ethernet Cable 

Softwares

1) Arduino IDE software
2) Processing Tool software
3) MATLAB

Rotatory Probe System/Method

This method is widely used to calculate different characateristics and parameters of transmitting antenna.
In this method,
1) The antenna that need to be tested or characterized is fixed on antenna fixture mechanism. This antenna is fed by a suitable feeding    technique and radiates Electromagnetic waves.
2) At Receiving end, Most common antenna used in this kind of scenario is Horn antenna due to its significant efficiency in terms of        Directivity and Gain.
3) Receiving antenna rotates a 360 degree full rotation step by step according to the resolution of stepper motor. Power measurement        instrument (N9916A in our case) measures the received power (dBm) value at each stepper motor step (0.9 degree or 1.8 degree).
4) This system controls the control parameters of steper motor that is rotating Receiving Horn antenna and records the received power      reading at every step automatically by proper feedback network established using software-hardware interfacing and communication        protocol.

Run speed_and_dir_control_stepper_motor.ino and it will rotate Horn antenna according to the parameters of speed,direction and degree rotation provided by user. However, User can also control these parameters via hardware switches provided in circuit diagram as shown in PDF.

Run automated_full_rotation.ino to achieve a complete rotation and interface with Measuring mechanism in order to calculate Receiving power .

Run controlling_interface_between_arduino_matlab.pde transmits and receives simultaneous data and control bits at port of user's laptop in order to make sure that both rotating and measuring mechanism don't overlap and feedback system works properly.

Run Matlab_code.m to fetch readings of received power in a generated .txt file. It also computes Axial-Ratio(AR) using the value of received power readings using in the equation.



